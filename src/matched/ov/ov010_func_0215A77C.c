/*
 * function: func_0215A77C
 * address:  0x0215A77C
 * packet:   pkt_ov010_0215A77C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02190A20  0x02190A20  thumb  ov021
 */
#include "../include/Obj00005.h"
#include "../include/Obj18799.h"

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k[8];
} Q;

typedef struct {
    unsigned short id;
    unsigned short pad[15];
    int pad20;
} P;

extern void func_02082BCC(void *, int, int);
extern void func_02082A7C(int, void *, int);
typedef unsigned int   u32;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern int func_02190A20(int, int);

void func_0215A77C(unsigned short *p, unsigned short a, unsigned short b,
                   unsigned short c, unsigned short d, int e, int f, int g,
                   int h)
{
    char *base = *(char * *)&((struct Obj00005 *)p)->f20;
    Q *q = (Q *)(base + 0x34);

    func_02082BCC(q, 0, 0xa0);
    ((struct Obj18799 *)base)->f34 = a;
    q->b = b;
    q->c = c;
    q->d = d;
    q->e = e;
    q->f = f;
    q->g = g;
    q->i = h;
    func_02082A7C(0, (char *)q + 0x20, 0x80);
    if (q->i == 0) {
        q->h = 1;
        q->i = (int)func_02045B38(0, 3, 0x80 + 0x86, *p);
    }
    q->j = func_02190A20(0x20, *p);
}
