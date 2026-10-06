/*
 * function: func_021F9A6C
 * address:  0x021F9A6C
 * packet:   pkt_021F9A6C
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203133C  0x0203133C  arm
 *   func_020307B0  0x020307B0  arm
 */

struct S020314B8;
extern void func_0203133C(struct S020314B8 *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021F9A6C(int *p)
{
    func_0203133C((struct S020314B8 *)p[0]);
    func_020307B0(p);
}
