#include <stdio.h>
#include <assert.h>


typedef int keyType;
typedef int valType;

typedef struct _node{
  keyType key;
  valType val;
  /* char *children; */
} node;

typedef struct _lsm{
  size_t block_size = 100; /*This is the number of nodes each block can hold.*/
  int k = 2;   /*The LSM tree grows in dimension k.*/
  size_t next_empty = 0; 
  size_t node_size = sizeof(node); 
  char *block = malloc(block_size*node_size);  
  FILE *disk_fp; 
} lsm;

/* on exit, write partial buffer to disk on file and meta data */


node* get_node(keyType key, lsm* tree){
  /* search the buffer for this item */
  sprintf('searching level 1\n');
  for (i = 0; i < tree.block_size; i++){
    if (tree.block[i].key == key){
      return tree.block[i];
    }
  }

  /* search through the file on disk for this item */
  sprintf('opening file\n');
  tree.disk_fp  = fopen('disk_storage.txt', 'rb+');
  /* QUESTION: How does the void pointer in fread work? */
  node *file_data;
  size_t noe;
  fread(noe, sizeof(size_t), 1, tree.disk_fp);
  fread(file_data, sizeof(node), noe, tree.disk_fp);

  sprintf('searching level 2\n');
  for(i = 0; i < sizeof(file_data); i++){
    if (file_data[i].key == key){
      return file_data[i];
      }
  }
  /* If it does not find the given key, it will return NULL */ 
  return NULL; 
} 

int put(keyType key, valType val, lsm* tree){
  if(tree.next_empty == tree.block_size){
    /* sort the block & write it to the next level */
    /* QUESTION: Implement the sort algorithm */ 
  } else{
    node n; 
    n.key = key; 
    n.val = val;
    tree.block[tree.next_empty] = n
  }
  return 0; 
} 


int update(keyType key, valType val, lsm* tree){
  /* search buffer, search disk, update value  */ 
  node n = get_node(key, tree);
  assert(n != NULL);
  n.val = val; 
  /* re-sort array */ 
  /* TODO: Implement search */
  return 1;
} 

char* merge_sort(char *block){
  /* Given an unsorted char array containing nores , this returns 
     a char array sorted by key using merge sort */
  assert(block != NULL); 
  
  /**/
}

char* merge(){
  
}


int main() 
{
  printf( "I am alive!  Beware.\n" );
  getchar();
  return 0;
}

