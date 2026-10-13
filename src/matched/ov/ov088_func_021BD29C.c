/*
 * function: SAVE_CONTROL_INTR_Delete
 * address:  0x021BD29C
 * packet:   pkt_ov088_021BD29C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020351F8  0x020351F8  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int   u32;
extern void func_020351F8(u32 a, u32 b);
extern u32 func_020307B0(void *p);

void SAVE_CONTROL_INTR_Delete(void *p)
{
    func_020351F8(0, 0);
    func_020307B0(p);
}
