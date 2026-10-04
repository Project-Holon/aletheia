/*
 * function: func_021C8FB8
 * address:  0x021C8FB8
 * packet:   pkt_ov021_021C8FB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, u32 *p);
extern void func_020061E4(u32 id);
void func_021C8FB8(u32 a, u32 *out)
{
    u32 *r = (u32 *)func_021AC1AC(a);
    *out = r[0];
    func_021AC1CC(a, &r[1]);
    func_020061E4(0x6a2);
}
