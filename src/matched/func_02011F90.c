/*
 * function: func_02011F90
 * address:  0x02011F90
 * packet:   pkt_02011F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122B4  0x020122B4  thumb
 *   func_02012258  0x02012258  thumb
 *   func_0202B4F0  0x0202B4F0  thumb
 *   func_02012704  0x02012704  thumb
 *   func_02026250  0x02026250  thumb
 *   func_02013A48  0x02013A48  thumb
 *
 * Teardown: two calls on the object itself, then three on its words at +0x2c,
 * +0x1c and +0x24, then a final no-argument call.  Every callee resolves on its
 * own manifest entry or on a label outside the range, so the file is EXACT up to
 * the two bytes of section padding after the pop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011F90.c \
 *       --func func_02011F90 --addr 0x02011F90 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void func_020122B4(void *o);
extern void func_02012258(void *o);
extern void func_0202B4F0(u32 v);
extern void func_02012704(u32 v);
extern void func_02026250(u32 v);
extern void func_02013A48(void);

void func_02011F90(u32 *o)
{
    func_020122B4(o);
    func_02012258(o);
    func_0202B4F0(o[0xb]);
    func_02012704(o[7]);
    func_02026250(o[9]);
    func_02013A48();
}
