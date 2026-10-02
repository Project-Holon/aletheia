/*
 * function: func_021589D0
 * address:  0x021589D0
 * packet:   pkt_021589D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E8  0x020124E8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
extern void *func_020124E8(struct Obj *p);

int func_021589D0(int a0)
{
    void *p;

    p = func_020124E8((struct Obj *)a0);
loc_021589D6:
a0 = *(int *)p;
    return a0;}
