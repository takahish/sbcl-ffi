#include <stdlib.h>
#include <stdio.h>

struct c_struct
{
  int x;
  char *s;
};

struct c_struct *c_function (i, s, r, a)
     int i;
     char *s;
     struct c_struct *r;
     int a[10];
{
  int j;
  struct c_struct *r2;

  printf("i = %d\n", i);
  printf("s = %s\n", s);
  printf("r->x = %d\n", r->x);
  printf("r->s = %s\n", r->s);
  for (j = 0; j < 10; j++) printf("a[%d] = %d.\n", j, a[j]);

  r2 = (struct c_struct *) malloc (sizeof(struct c_struct));
  r2->x = i + 5;
  r2->s = "a C string";

  return(r2);
};

int main(void)
{
  struct c_struct ar = {20, "a Lisp string"};
  int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  struct c_struct *r2;

  r2 = c_function(5, "another Lisp string", &ar, a);

  printf("r2->x = %d\n", r2->x);
  printf("r2->s = %s\n", r2->s);

  return 0;
}
