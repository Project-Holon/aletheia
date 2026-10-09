/*
 * file:     unit_06899DD8_p04.c
 * unit:     yes
 * function: func_06899E2C, func_06899E48, func_06899E68
 * address:  0x06899E2C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj07909.h"
#include "../../matched/include/Obj21887.h"

typedef unsigned int u32;

typedef struct Entry { void *a; void *b; void *self; u32 zero; } Entry;

typedef struct Q_06899E48 { u32 pad[8]; Entry entries[4]; int count; } Q_06899E48;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Slot {
    int (*f0)(void *, int);
    int (*f1)(void *, int);
    int arg;
    int data;
} Slot;

typedef struct Q_06899E68 {
    u8 pad[0x20];
    Slot tab[4];
    int n;
} Q_06899E68;

void func_06899E2C(unsigned char *p);
void func_06899E48(Q_06899E48 *p, void *a, void *b);
int func_06899E68(Q_06899E68 *q);

void func_06899E2C(unsigned char *p) {
 int i;
 u32 zero;
 unsigned char *q;
 zero=0;
 for(i=0;i<4;i++) {
  q=p+i*16;
  ((struct Obj07909 *)q)->f20=zero;
  ((struct Obj07909 *)q)->f24=zero;
  ((struct Obj07909 *)q)->f28=zero;
  ((struct Obj07909 *)q)->f2C=zero;
 }
 ((struct Obj21887 *)p)->f60=zero;
}

/*
 * Queue storage has four 16-byte entries, as cleared by func_06899E2C.
 */
void func_06899E48(Q_06899E48 *p, void *a, void *b) {
 int i = p->count++;
 Entry *e = &p->entries[i];
 e->a=a;
 e->b=b;
 e->self=p;
 e->zero=0;
}


/*
 * Slot table of four 16-byte entries at +0x20 with a count at +0x60 (see
 * func_06899E48, which pushes an entry, and func_06899E2C, which clears
 * them).  Services the newest entry.
 */
int func_06899E68(Q_06899E68 *q)
{
    Slot *e;
    int done;

    if (q->n != 0) {
    e = &q->tab[q->n - 1];
    if (e->f0 != 0) {
        if (e->f0(&e->data, e->arg) != 0) {
            e->f0 = 0;
            e->data = 0;
        }
        done = 0;
    } else if (e->f1 != 0) {
        if (e->f1(&e->data, e->arg) != 0) {
            e->f1 = 0;
            done = 1;
        } else {
            done = 0;
        }
    } else {
        done = 1;
    }
    if (done) {
        e->f0 = 0;
        e->f1 = 0;
        e->arg = 0;
        e->data = 0;
        q->n--;
    }
    return 0;
    }
    return 1;
}
