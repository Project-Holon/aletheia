# `volatile` on a pointer-typed struct member is ignored, qualify the pointed-to struct instead

summary: mwcc 1.1p1 forwards a store to a following load of the same member
even when the member is spelled `struct Node * volatile next`; the same member
declared `volatile int`, or reached through a `volatile struct Node *`, keeps
the load.

Found in: `docs/notes/func_020583CC.c.txt` (0x020583CC)

A re-read of a link field right after writing it is a common shape in these
list routines:

```
str r2, [r1]        /* node->next = NULL */
ldr r2, [r1]        /* node->prev = node->next, a real second load */
str r2, [r1, #4]
```

The obvious way to keep that load is to mark the member volatile. It does not
work. These three probes, same flags, same compiler:

```c
struct A { volatile int a;          int b; };  void qA(struct A *p){ p->a=0; p->b=p->a; }
struct B { int * volatile a;        int *b; };  void qB(struct B *p){ p->a=0; p->b=p->a; }
struct F { struct F *a;          struct F *b; };
void qF(volatile struct F *p){ p->a=0; p->b=p->a; }
```

give

```
qA   mov r1,#0 ; str r1,[r0] ; ldr r1,[r0] ; str r1,[r0,#4]   /* load kept */
qB   mov r1,#0 ; str r1,[r0] ;              str r1,[r0,#4]   /* load gone  */
qF   mov r1,#0 ; str r1,[r0] ; ldr r1,[r0] ; str r1,[r0,#4]   /* load kept */
```

so the qualifier is honoured on an `int` member and on a whole struct reached
through a volatile-qualified pointer, and dropped on a member whose own type is
a pointer. A `typedef struct N *NP; volatile NP a;` behaves like `qB`, so it is
the member's pointee-ness and not the declarator spelling that decides.

The practical consequence for a linked-list routine is that the struct stays
ordinary and the *parameter* carries the qualifier:

```c
struct Node { volatile struct Node *next; volatile struct Node *prev; };
void push_front(struct List *list, volatile struct Node *node) { ... }
```

Watch the direction, though: volatile is normally reached for to stop `stm`
folding or to force a reload, and here it also changes nothing about
if-conversion, which is a separate decision. In `func_02058380`, whose header
carries the older `struct Node * volatile next` spelling, the qualifier is
doing nothing at all; that file is `EXACT` for other reasons and the volatile
markers in it should not be read as evidence.
