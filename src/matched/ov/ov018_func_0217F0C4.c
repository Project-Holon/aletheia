/*
 * function: INTRUDE_SUBDISP_StartTownBlink
 * address: 0x0217F0C4
 * packet: pkt_ov018_0217F0C4
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
void INTRUDE_SUBDISP_StartTownBlink(u8 *p)
{
    int i;
    p[0x115] = 0;
    p[0x114] = 1;
    for (i = 0; i < 7; i++) func_0204B6F4(((void **)p)[23 + i], 6, 1);
    func_0204B6F4(((void **)p)[31], 6, 1);
}
