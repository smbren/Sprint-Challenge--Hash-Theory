#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  Answer *answer = malloc(sizeof(Answer));

  HashTable *ht = create_hash_table(16);

  // YOUR CODE HERE
  //populate hashtable using input weights with the weight as the key and the index as the value
  for(int i = 0; i < length; i++) {

    int weight = weights[i];
    int index = i;

    hash_table_insert(ht, weight, index);

  }

  //check each weight minus the weight limit
  for(int j = 0; j < length; j++) {

    int weight = weights[j];
    int index = (limit - weight);

    //if the weight minus the weight limit exists in the ht, the higher index is index_1, and the lower index is index_2 
    if( ht->storage[index] != NULL) {

      int value1 = hash_table_retrieve(ht, weight);
      int value2 = hash_table_retrieve(ht, index);

      if(value1 > value2) {

        answer->index_1 = value1;
        answer->index_2 = value2;
        return answer;

      } else {
        answer->index_1 = value2;
        answer->index_2 = value1;
        return answer;
      }

    } 

  }

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("{%d, %d}\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}
#endif
