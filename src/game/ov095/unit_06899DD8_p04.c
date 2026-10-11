/*
 * file:     unit_06899DD8_p04.c
 * unit:     yes
 * function: func_06899E2C, func_06899E48, func_06899E68, func_06899ED0, func_06899F28, func_06899F64
 * address:  0x06899E2C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D8434  0x021D8434  thumb
 *   func_0689A030  0x0689A030  thumb  ov095
 *   func_0689A76C  0x0689A76C  thumb  ov095
 *   func_0689A84C  0x0689A84C  thumb  ov095
 *   func_0689A988 0x0689A988 thumb ov095
 *   func_0689A878 0x0689A878 thumb ov095
 *   func_0689ABA0  0x0689ABA0  thumb  ov095
 *   func_0689AB48  0x0689AB48  thumb  ov095
 */
#include "../../matched/include/Obj07909.h"
#include "../../matched/include/Obj21887.h"
#include "../../matched/include/Obj07912.h"
#include "../../matched/include/Obj21889.h"
#include "../../matched/include/Obj07913.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef int (*SlotFn)(void *, void *);

typedef struct Slot {
    SlotFn f0;
    SlotFn f1;
    void *arg;
    int data;
} Slot;

typedef struct Obj {
    u8 pad0[0x20];
    Slot tab[4];
    int n;
    u8 pad64[4];
    void *f68;
    void *f6c;
    void *f70;
    u8 pad74[8];
    void *f7c;
    u8 pad80[11];
    u8 f8b;
    u8 pad8c[5];
    u8 f91;
    u8 pad92[6];
    u32 f98;
} Obj;

extern int func_0689A030(void *, void *);
extern int func_0689A76C(void *, void *);
extern int func_0689A84C(void *, void *);
extern int func_0689A988(void *, void *);
extern int func_0689A878(void *, void *);
extern int func_0689ABA0(void *, void *);
extern int func_0689AB48(void *, void *);
extern void func_021D8434(void *);

void func_06899E2C(Obj *p);
void func_06899E48(Obj *p, SlotFn a, SlotFn b);
int func_06899E68(Obj *q);
void func_06899ED0(Obj *o, void *a, u8 b, u8 c, void *d);
void func_06899F00(Obj *o, void *a, u8 b, void *c);
u32 func_06899F28(Obj *p);
void func_06899F40(Obj *p, void *a, void *b);
void func_06899F64(Obj *s, u8 *a, void *b);

void func_06899E2C(Obj *p) {
    int i;
    u32 zero;
    unsigned char *q;
    zero = 0;
    for (i = 0; i < 4; i++) {
        q = (unsigned char *)p + i * 16;
        ((struct Obj07909 *)q)->f20 = zero;
        ((struct Obj07909 *)q)->f24 = zero;
        ((struct Obj07909 *)q)->f28 = zero;
        ((struct Obj07909 *)q)->f2C = zero;
    }
    ((struct Obj21887 *)p)->f60 = zero;
}

void func_06899E48(Obj *p, SlotFn a, SlotFn b) {
    int i = p->n++;
    Slot *e = &p->tab[i];
    e->f0 = a;
    e->f1 = b;
    e->arg = p;
    e->data = 0;
}

int func_06899E68(Obj *q)
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

void func_06899ED0(Obj *o, void *a, u8 b, u8 c, void *d)
{
    o->f6c = a;
    o->f70 = d;
    o->f98 = 0;
    o->f8b = b;
    o->f91 = c;
    func_06899E48(o, func_0689A030, func_0689A76C);
}

void func_06899F00(Obj *o, void *a, u8 b, void *c)
{
    o->f6c = a;
    o->f70 = c;
    o->f98 = 0;
    o->f8b = b;
    func_06899E48(o, func_0689A030, func_0689A84C);
}

u32 func_06899F28(Obj *p) {
    if (func_06899E68(p)) return p->f98;
    return 0;
}

void func_06899F40(Obj *p, void *a, void *b) {
    p->f6c = a;
    p->f70 = b;
    p->f98 = 0;
    p->f68 = (void *)func_0689A988;
    func_06899E48(p, func_0689A878, func_0689A988);
}

void func_06899F64(Obj *s, u8 *a, void *b)
{
    s->f98 = 0;
    s->f7c = a;
    s->f70 = b;
    s->f68 = (void *)func_0689ABA0;
    func_021D8434(b);
    func_021D8434(a + 0x18);
    func_021D8434(a + 0x1c);
    func_06899E48(s, func_0689AB48, func_0689ABA0);
}
