/*
 * file:     unit_021D8434.c
 * unit:     yes
 * function: func_021D8434, func_021D8444, func_021D8454, func_021D845C, func_021D8470, func_021D8484, func_021D84F0, func_021D84F8, func_021D8510, func_021D8538, func_021D8548, func_021D8564, func_021D85B0, func_021D85C0, func_021D85F4, func_021D8678
 * address:  0x021D8434
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F0710     0x021F0710  data   ov093  a4
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6F0C  0x021D6F0C  thumb  ov093
 *   d_021F0E74     0x021F0E74  data  ov093
 *   func_021D732C 0x021D732C thumb ov093
 *   func_021D7040 0x021D7040 thumb ov093
 *   func_021D7404 0x021D7404 thumb ov093
 *   func_021D7438 0x021D7438 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   d_021F08C0 0x021F08C0 data ov093 a4
 *   func_021D7AF0 0x021D7AF0 thumb ov093
 *   func_021C82B8 0x021C82B8 thumb ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C8120  0x021C8120  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../matched/include/Obj07807.h"

struct Node;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

union B { u32 word; struct { u32 kind:4; u32 rest:28; } bits; };

typedef enum { MASK=15 } Mask;

typedef struct
{
    unsigned int x : 4;
} S021D8454;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Ent { u32 key; u32 (*fn)(u32 *); };

extern int func_021D59B4(u8 *p, int k);
extern u8 func_021D5440(u8 *p);
struct Node *func_021D6F0C(int id, u32 key, int pri, u32 sub_pri, u8 sub, u32 f8, u16 f16);
extern struct Node *func_021D732C(int id, int sub);
extern void func_021D7040(struct Node *n);
extern void func_021D7404(u32 sub, int kind);
extern int func_021D7438(int,int);
extern int func_021D58A8(u8 *,int);
extern int func_021D7AF0(u32);
extern int func_021C82B8(int,int);
int func_021D775C(int a);
int func_021C7D00(u8 *p, int b);
u8 *func_021C8120(u8 *p, int b);
u8 func_021C7F68(int *p, int b, u8 *out);
void func_021C88B4(void *a, int k, int b);
void *func_021C88A4(char *p, int a, int b);
void func_021C88C8(void *a, void *b);
void func_021D8434(u32 *p);
void func_021D8444(u32 *p);
unsigned int func_021D8454(S021D8454 *p);
void func_021D845C(u32 *p);
void func_021D8470(u32 *p);
void *func_021D8484(void *a);
unsigned int func_021D84F0(unsigned int a, unsigned int b);
int func_021D84F8(u32 *p);
void func_021D8510(void *p);
void func_021D8538(void *p);
void func_021D8548(void *p);
void func_021D8564(int a, int b);
u16 func_021D85B0(u8 *p);
int func_021D85C0(int a,u32 b);
u8 *func_021D85E8(u32 *p);
void func_021D85F4(void *a, int b, int c);
extern struct Ent d_021F0E74[0x9e];
extern u8 d_021F08C0[];

/*
 * follower: Two zero alignment bytes.
 * lever: Enum mask preserves the contradictory clear-and-mask operations;
 * placing the mask first in the final AND selects the original register.
 */
void func_021D8434(u32 *p) { Mask mask=MASK; *p=mask & (*p & ~15); }

void func_021D8444(u32 *p) { *p = (*p & ~15) | 7; }


unsigned int func_021D8454(S021D8454 *p)
{
    return p->x;
}

/*
 * follower: Two zero alignment bytes.
 */
void func_021D845C(u32 *p) { *p = ((*p & ~15) | 8) & 15; }

void func_021D8470(u32 *p) { *p = ((*p & ~15) | 9) & 15; }


void *func_021D8484(void *a)
{
    u16 k = func_021D59B4(a, 0x10);
    u32 i;
    u32 t;
    u32 f8;
    u8 sub;
    int pri;
    u32 loc;

    for (i = 0; i < 0x9e; i++) {
        if (k == d_021F0E74[i].key) {
            t = func_021D85B0(a);
            sub = func_021D5440(a);
            f8 = d_021F0E74[i].fn(&loc);
            pri = func_021D84F8(&loc);
            return func_021D6F0C(4, k, pri, t, sub, f8, loc);
        }
    }
    return 0;
}

unsigned int func_021D84F0(unsigned int a, unsigned int b)
{
    return (a << 16) | b;
}

int func_021D84F8(u32 *p) { u16 n = *p >> 16; if (n == 0) n = 5; *p &= 65535; return n; }

void func_021D8510(void *p) { int n = func_021D5440(p); void *a; while ((a=func_021D732C(4,n)) != 0) { func_021D7040(a); } }

void func_021D8538(void *p) { func_021D7404(func_021D5440(p),4); }

void func_021D8548(void *p) { if (!func_021D7438(func_021D5440(p),4)) func_021D8484(p); }


void func_021D8564(int a, int b)
{
    int sa = func_021D5440((u8 *)a);
    int sb = func_021D5440((u8 *)b);
    void *x = func_021D732C(4, sa);
    void *y = func_021D732C(4, sb);

    if (x != 0)
        func_021D7040(x);
    if (y != 0)
        func_021D7040(y);
    func_021D8484((void *)a);
    func_021D8484((void *)b);
}

u16 func_021D85B0(u8 *p) { return func_021D58A8(p,12); }

int func_021D85C0(int a,u32 b) { if (func_021D7AF0(b)) return 1; a=func_021C82B8(a,1)!=0; return a; }

u8 *func_021D85E8(u32 *p) { *p=2; return d_021F08C0; }


void func_021D85F4(void *a, int b, int c)
{
    void *r;
    void *v;
    int w;
    u32 i;
    u8 *p;

    if (c != func_021D775C(2))
        return;
    r = (void *)func_021C7D00((u8 *)b, c);
    v = (void *)func_021C8120((u8 *)b, 6);
    w = func_021C7F68((int *)b, (u16)((u32)r | 0x100), (u8 *)((int)v));
    if (w == 0)
        return;
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4((char *)b, 0xe, c);
    ((struct Obj07807 *)p)->f4 = 1;
    ((struct Obj07807 *)p)->fC = -1;
    ((struct Obj07807 *)p)->fE = 1;
    ((struct Obj07807 *)p)->fF = w;
    for (i = 0; i < (u32)w; i++)
        *(u8 *)(p + 0x10 + i) = ((u8 *)v)[i];
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
}


extern int d_021F0710[];
int *func_021D8678(int *p);

int *func_021D8678(int *p)
{
    *p = 1;
    return d_021F0710;
}
