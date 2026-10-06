/*
 * file:     unit_02060FA4_p02.c
 * unit:     yes
 * function: func_02060FEC, func_02061048, func_020610A0, func_020610B4, func_020610E0, func_02061118, func_02061124, func_02061158, func_02061184
 * address:  0x02060FEC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02060FA4  0x02060FA4  arm
 *   func_02060FEC  0x02060FEC  arm
 */
#include "../../matched/include/Obj04082.h"

struct Obj;
struct Heap;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Heap {
    u32          cur;    /* +0x00 */
    u32          limit;  /* +0x04 */
    struct Node *head;   /* +0x08 */
};

struct Node {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct H {
    u8          pad_00[0x24];
    struct Heap h24;     /* +0x24 */
};

extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void func_02082A7C(int a, int b, int c);
unsigned int func_02061048(unsigned int *p, unsigned int a, unsigned int b);
void func_020610A0(void *p0);
void func_020610B4(int *p);
extern struct Obj *func_02060FA4(struct Obj *o, u32 a1, u32 a2);
extern void func_0206074C(void *heap);
extern u32 func_02060FEC(struct Heap *h, u32 size, u32 align);
void *func_020610E0(void *mem, u32 size, u32 opt);
void func_02061118(void *heap);
unsigned int func_02061124(char *p, int n, int v);
void func_02061158(void *p, int flags);



u32 func_02060FEC(struct Heap *h, u32 size, u32 align)
{
    u32 amask = align - 1;
    u32 p = (amask + h->cur) & ~amask;
    u32 e = size + p;
    u32 sz;

    if (e > h->limit) {
        return 0;
    }

    sz = e - h->cur;
    if ((u8)((u32 *)h)[-1] & 1) {
        MIi_CpuClear32(0, (void *)h->cur, sz);
    }

    h->cur = e;
    return p;
}


unsigned int func_02061048(unsigned int *p, unsigned int a, unsigned int b)
{
    unsigned int v = (p[1] - a) & ~(b - 1);
    unsigned int r2;
    unsigned char c;
    if (v < p[0])
        return 0;
    r2 = p[1] - v;
    c = (unsigned char)p[-1];
    if (c & 1)
        func_02082A7C(0, (int)v, (int)r2);
    p[1] = v;
    return v;
}



void func_020610A0(void *p0){ ((struct Obj04082 *)p0)->f24 = (int)((struct Obj04082 *)p0)->f18; ((struct Obj04082 *)p0)->f2C = (int)0; }


void func_020610B4(int *p)
{
    int *q = (int *)p[0xb];
    if (q != 0) {
        do {
            q[2] = p[7];
            q = (int *)q[3];
        } while (q != 0);
    }
    p[0xa] = p[7];
}



/*
 * Frame-heap create guard (twin of 0x02060C5C): word-align both ends of the
 * block, refuse anything under 0x30 bytes, else hand (start, end, opt) to
 * func_02060FA4.  Two levers closed the old 2-register residue of
 * docs/notes/pkt_020610E0.c.txt: the third parameter is passed straight
 * through in r2 (which is why `end - start` lands in r3), and the end sum is
 * spelled size + mem (`add r1, r1, r0`).
 */
void *func_020610E0(void *mem, u32 size, u32 opt)
{
    u32 end = (size + (u32)mem) & ~3u;
    u32 start = ((u32)mem + 3) & ~3u;
    if (start > end || end - start < 0x30)
        return 0;
    return func_02060FA4((void *)start, end, opt);
}


void func_02061118(void *heap){ func_0206074C(heap); }


unsigned int func_02061124(char *p, int n, int v)
{
    if (n == 0)
        n = 1;
    n = (n + 3) & ~3;
    p += 0x24;
    if (v >= 0)
        return func_02060FEC((struct Heap *)p, (unsigned int)n, (unsigned int)v);
    else
        return func_02061048((unsigned int *)p, (unsigned int)n, (unsigned int)-v);
}


void func_02061158(void *p, int flags)
{
    if (flags & 1)
        func_020610A0(p);
    if (flags & 2)
        func_020610B4(p);
}



int func_02061184(struct H *h, u32 a1)
{
    struct Node *p;
    u32 saved = h->h24.cur;

    p = (struct Node *)func_02060FEC(&h->h24, 0x10, 4);
    if (p == 0) {
        return 0;
    }

    p->unk_00 = a1;
    p->unk_04 = saved;
    p->unk_08 = h->h24.limit;
    p->unk_0c = (u32)h->h24.head;
    h->h24.head = p;
    return 1;
}
