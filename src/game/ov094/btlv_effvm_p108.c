/*
 * file:     btlv_effvm_p108.c
 * unit:     yes
 * function: func_0220778C, func_0220785C, func_0220793C, func_02207960
 * address:  0x0220778C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02207F6C 0x02207F6C thumb ov094
 *   func_022082FC 0x022082FC thumb ov094
 *   func_022080F4 0x022080F4 thumb ov094
 *   func_02208268 0x02208268 thumb ov094
 *   func_02208420 0x02208420 thumb ov094
 *   func_02208550 0x02208550 thumb ov094
 *   func_021F8720 0x021F8720 thumb ov094
 *   func_02208650 0x02208650 thumb ov094
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_02208B10 0x02208B10 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   func_02208D38 0x02208D38 thumb ov094
 *   func_022079C0  0x022079C0  thumb  ov094
 *   func_02030EAC  0x02030EAC  arm
 *   d_0220AAB4     0x0220AAB4  data   ov094  a2
 */
#include "../../matched/include/Obj00974.h"

struct Obj;
struct Node;
typedef struct {
    void *f40, *f44, *f48, *f4c, *f50, *f54;
    unsigned int f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
    char pad[0x40];
} Entry;

typedef struct { char pad[0x40]; Entry entries[8]; } Work;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct E {
    void *f00;
    char p04[0x0c];
    void *f10;
    char p14[0x30];
    int f44, f48, f4c, f50, f54, f58, f5c, f60, f64;
    char p68[8];
    u32 lo : 3;
    u32 b3 : 1;
    u32 mid : 12;
    u32 mode : 4;
    u32 hi : 12;
    char p74[8];
    void *f7c;
} E;

typedef struct O { char pad[0x40]; E e[8]; } O;

typedef unsigned char  u8;

typedef struct {
    short x;
    short y;
} Pt;

typedef struct {
    unsigned int lo : 3;
    unsigned int b3 : 1;
} Bf;

extern void func_0204A8D4(unsigned int);
extern void func_0204AFD8(unsigned int);
extern void func_0204B3B4(struct Obj *p);
extern int func_02207F6C(int n, int target, int delta, int *cur, u8 x, int speed);
extern void func_022082FC(O *, int, int);
extern void func_022080F4(O *, E *, void *);
extern void func_02208268(O *, E *);
extern void func_02208420(O *, E *, int);
extern void func_02208550(O *, E *);
extern int func_021F8720(void);
extern void func_02208650(O *, E *);
extern void *func_021F86D4(void);
extern void func_02208B10(void *h, struct E *e);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern int func_02208D38(int a, int b, int c);
extern void func_022079C0(char *p, int i, Pt *pt);
extern void func_02030EAC(struct Node *n);
void func_0220778C(Work *p, int i);
void func_0220785C(O *o, int unused, int idx, void *data);
void func_0220793C(char *p);
void func_02207960(char *p, int i);
extern const Pt d_0220AAB4;

/*
 * extent: two zero bytes at 0220785A align the next function.
 * lever: indexed entries in the owning structure retain per-field bases;
 *   a raw offset or cast Entry array caches the element and is 138/144 bytes.
 */
void func_0220778C(Work *p, int i)
{
    if (p->entries[i].f40 == 0)
        return;
    func_0204A8D4(p->entries[i].f58);
    func_0204A8D4(p->entries[i].f60);
    func_0204A8D4(p->entries[i].f68);
    func_0204A8D4(p->entries[i].f70);
    func_0204AFD8(p->entries[i].f5c);
    func_0204AFD8(p->entries[i].f64);
    func_0204AFD8(p->entries[i].f6c);
    func_0204AFD8(p->entries[i].f74);
    func_0204B3B4(p->entries[i].f40);
    func_0204B3B4(p->entries[i].f44);
    func_0204B3B4(p->entries[i].f48);
    func_0204B3B4(p->entries[i].f4c);
    func_0204B3B4(p->entries[i].f54);
    p->entries[i].f40 = 0;
    p->entries[i].f44 = 0;
    p->entries[i].f48 = 0;
    p->entries[i].f4c = 0;
    p->entries[i].f54 = 0;
    if ((i & 1) == 0) {
        func_0204A8D4(p->entries[i].f78);
        func_0204AFD8(p->entries[i].f7c);
    }
    if (p->entries[i].f50 != 0) {
        func_0204B3B4(p->entries[i].f50);
        p->entries[i].f50 = 0;
    }
}

void func_0220785C(O *o, int unused, int idx, void *data)
{
    func_02207F6C(o->e[idx].f4c, o->e[idx].f48, 0, &o->e[idx].f50, 6, 1);
    func_022082FC(o, idx, 0);
    if (o->e[idx].f10 != 0) {
        func_02207F6C(o->e[idx].f58, o->e[idx].f54, 0, &o->e[idx].f64, 10, 1);
        func_022082FC(o, idx, 1);
    }
    func_022080F4(o, &o->e[idx], data);
    func_02208268(o, &o->e[idx]);
    func_02208420(o, &o->e[idx], o->e[idx].f48);
    func_02208550(o, &o->e[idx]);
    if (o->e[idx].f44 != 0 && func_021F8720() == 0)
        func_02208650(o, &o->e[idx]);
    o->e[idx].b3 = 1;
    o->e[idx].mode = 2;
    o->e[idx].f7c = func_02030DA8(func_021F86D4(), (void (*)(void *, void *))func_02208B10, &o->e[idx], 0);
}


/*
 * lane O10 candidate
 */
void func_0220793C(char *p)
{
    int a = ((struct Obj00974 *)p)->f48;
    int b = ((struct Obj00974 *)p)->f4C;

    if (b < 0x30)
        ((struct Obj00974 *)p)->f78 = (unsigned int)func_02208D38(a << 8, b, 0x30) >> 8;
    else
        ((struct Obj00974 *)p)->f78 = (unsigned int)func_02208D38(a, b, 0x30);
}


void func_02207960(char *p, int i)
{
    char *q = p + 0xb0;
    int o = i * 128;
    void *t;

    if (((Bf *)(q + o))->b3) {
        Pt pt = d_0220AAB4;

        if (i & 1)
            pt.x *= -1;
        func_022079C0(p, i, &pt);
        ((Bf *)(q + o))->b3 = 0;
    }
    t = *(void **)(p + o + 0xbc);
    if (t != 0) {
        func_02030EAC(t);
        *(int *)(p + o + 0xbc) = 0;
    }
}
