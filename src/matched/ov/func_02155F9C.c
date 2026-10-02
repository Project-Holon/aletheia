/*
 * function: func_02155F9C
 * address:  0x02155F9C
 * packet:   pkt_02155F9C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02156CAC  0x02156CAC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj { int f00; int f04; int f08; } Obj;
extern Obj *func_02156CAC(int a, int b, int c);

Obj *func_02155F9C(int a0, int a1, int a2)
{
    int t4;
    Obj *p;

t4 = a0 + 0;
a1 = *(int *)((char *)t4 + 0x3c);
a2 = *(int *)((char *)t4 + 0x1c);
a0 = 4;
    p = func_02156CAC(a0, a1, a2);
loc_02155FAA:
a1 = *(int *)((char *)t4 + 0x28);
*(Obj **)((char *)t4 + 0x2c) = p;
p->f00 = a1;
    return p;}
