#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int initial, extra;

  fprintf(stdout, "How many scores do you want initiall?: ");
  if (scanf("%d", &initial) != 1 || initial <= 0) {
    fprintf(stderr, "Invalid number.\n");

    return 1;
  }

  int *scores = malloc(initial * sizeof(int));

  if (scores == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    return 1;
  }

  for (int i = 0; i < initial; i++) {
    fprintf(stdout, "Enter score %d: ", i + 1);
    if(scanf("%d", &scores[i]) != 1) {
      fprintf(stdout, "Invalid output.\n");
      free(scores);
      return 1;
    }
  }

  fprintf(stdout, "How many additional scores?: ");
  if(scanf("%d", &extra) != 1 || extra < 0) {
    fprintf(stdout, "Invalid number.\n");
    free(scores);
    return 0;
  }

  int *temp = realloc(scores, (initial + extra) * sizeof(int));
  if(temp == NULL && extra > 0) {
    fprintf(stdout, "Memory resizing failed.\n");
    free(scores);
    return 1;
  }

  scores = temp;

  for (int i = initial; i < initial + extra; i++) {
    fprintf(stdout, "Enter score%d: ", i + 1);
    if (scanf("%d", &scores[i]) != 1) {
      fprintf(stdout, "Invalid input.\n");
      free(scores);
      return 1;
    }
  }

  fprintf(stdout, "\nAll scores: \n");
  for(int i = 0; i < initial + extra; i++) {
    fprintf(stdout, "%d\n", scores[i]);
  }

  free(scores);

  return 0;
}
