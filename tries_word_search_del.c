#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trienode{
  struct trienode* child[26];
  int end;
}node;


node* get_node()
{
  node* new=(node*)malloc(sizeof(node));
  new->end=0;
  int i=0;
  for(i=0;i<26;i++)
  {
    new->child[i]=NULL;
  }
  return new;
}



node* insert(node *trie, char *key)
{
  int i=0;node* root=trie;
  while(key[i])
  {
    int in=key[i]-'a';
    if(root->child[in]==NULL)
      root->child[in]=get_node();
    root=root->child[in];
    i++;
  }
  printf("inserted");
  root->end=1;
  return trie;
}


void display(node* root,char* s,int level)
{
  if(root->end==1)
  {
    s[level]='\0';
    printf("%s\n", s);
  }
  int i=0;
  while(i<26)
  {
    if(root->child[i]!=NULL)
    {
      s[level]=i+'a';
      display(root->child[i],s,level+1);
    }
    i++;
  }
}

void search_prefix(node* root,char* s)
{
  int i=0;char c[26];
  while(s[i])
  {
    int in=s[i]-'a';
    c[i]=s[i];
    if(root->child[in]==NULL)
    {
      printf("Not found\n");
      return;
    }
    root=root->child[in];
    i++;
  }
  display(root,c,i);
}


int check(node* root)
{
  int i=0;int count=0;
  for(i=0;i<26;i++)
  {
    if(root->child[i]!=NULL)
      count++;
  }
  return count;
}


node* delete(node* root,char* key,int depth)
{
  if(root==NULL)
    return;
  if(depth==strlen(key))
  {
    if(root->end)
      root->end=0;
    if(check(root)==0)
    {
      free(root);
      root=NULL;
    }
    return root;
  }
  int in=key[depth]-'a';
  root->child[in]=delete(root->child[in],key,depth+1);

  if(check(root)==0 && root->end==0)
  {
    free(root);
    root=NULL;
  }
  return root;
}

int main()
{
  node* root=get_node();char s[26];
  printf("\n");
  root=insert(root,"abcde");
  root=insert(root,"bcda");
  root=insert(root,"abcdef");
  root=insert(root,"abcdfgh");
  root=insert(root,"abdef");
	display(root,s,0);
  printf("\n\n");
  search_prefix(root,"ab");
  root=delete(root,"abcdef",0);
  printf("\n\n\n after deleteion\n");
  display(root,s,0);
  return 0;
} 




 //program implement tries
//stores word of lower case letters
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// struct stack
// {
//   struct trienode *m;
//   int index;
// };
// struct trienode
// {
//    struct trienode* child[26];
//    int endofword;
// };
// struct trienode *getnode();
// void insert(struct trienode *, char *);
// void display(struct trienode*);
// void delete_trie(struct trienode*,char*);
// int search(struct trienode *,char *);
// int check(struct trienode *);
// void push(struct trienode*,int);
// struct stack pop();
// char word[100];
// int length;
// int top;
// struct stack s[100];//stack
//  int main()
//  {
//   struct trienode *root;
//   char key[100];
//   int ch,k;
//  //length=0;
//   root=getnode();
//   while(1)
//   {
//     printf("\n1. Insert..");
//     printf("\n2. Delete..");
//     printf("\n3. Search..");
//     printf("\n4. Display..");
//     scanf("%d",&ch);
//     switch(ch)
//     {
//       case 1: printf("Enter word..\n");
//               scanf("%s",key);
//               insert(root,key);
//               break;
//     case 2: printf("Enter the word for deletion..\n");
//                scanf("%s",key);
//                top=0;
//                delete_trie(root,key);
//                break;
//        case 3: printf("Enter the word to search..\n");
//                scanf("%s",key);
//                k=search(root,key);
//                if(k)
//                  printf("\nWord found..\n");
//                else
//                  printf("\nNot found..\n");
//                break;

//         case 4:length=0;
//                display(root);
//     }
//   }
//  }
  
// struct trienode *getnode()
//   {
//     int i;
//     struct trienode *temp;
//     temp=(struct trienode*)malloc(sizeof(struct trienode));
//     for(i=0;i<26;i++)
//       temp->child[i]=NULL;
//      temp->endofword=0;
//     return temp;
//   }

//   void insert(struct trienode *root, char *key)
//   {
//      struct trienode *curr;
//      int i,index;

//      curr=root;
//      for(i=0;key[i]!='\0';i++)
//      {
//        index=key[i]-'a';
//        if(curr->child[index]==NULL)
//           curr->child[index]=getnode();
//        curr=curr->child[index];
//     }
//     curr->endofword=1;
//   }

//   void display(struct trienode *curr)
//   {
//     int i,j;
//     for(i=0;i<26;i++)
//     {
//       if(curr->child[i]!=NULL)
//       {
//          word[length++]=i+97;
//          if(curr->child[i]->endofword==1)//if end of word
//          {
//            printf("\n");//print word 
//            for(j=0;j<length;j++)
//              printf("%c",word[j]);
//          }
//         display(curr->child[i]);
//       }
//     }
//     length--;
//     return ;
//  }

//   int search(struct trienode * root,char *key)
//   {

//   int i,index;
//    struct trienode *curr;
//    curr=root;

//    for(i=0;key[i]!='\0';i++)
//    {
//      index=key[i]-'a';
//      if(curr->child[index]==NULL)
//         return 0;
//       curr=curr->child[index];
//     }
//     if(curr->endofword==1)
//        return 1;
//    return 0;
//   }


//  void delete_trie(struct trienode *root,char *key)
//   {
//     int i,j,index,k;
//     struct trienode* curr,*temp;
//     struct stack x;
//     curr=root;
    
//     for(i=0;key[i]!='\0';i++)
//     {
//       index=key[i]-'a';
//       if(curr->child[index]==NULL)
//       {
//          printf("Key not found\n");
//          return;
//       }
//       push(curr,index);
//       curr=curr->child[index];
//     }
//       curr->endofword=0;
//       push(curr,-1);
//       while(1)
//       {
//          x=pop();
//          if(x.index!=-1)
//            x.m->child[x.index]=NULL;
//          if(x.m==root)
//            break;
//          k=check(x.m); 
//          if((k>=1)||(x.m->endofword==1))
//             break;
//          else
//            free(x.m);
//       }
//     return;
//   }

//   int check(struct trienode *x)
//   {
//     int i;
//     int count=0;
//     for(i=0;i<26;i++)
//     {
//       if(x->child[i]!=NULL)
//         count++;
//     }
//    return count;
//  }

//   void push(struct trienode *x,int k)
//   {
//     ++top;
//     s[top].m=x;
//     s[top].index=k;
//   } 

//   struct stack pop()
//   {
//     struct stack temp;
//     temp=s[top--];
//     return temp;
//   }
