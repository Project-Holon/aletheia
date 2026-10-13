/*
 * function: BTL_POKEPARAM_ReplaceMove
 * address: 0x021D5734
 * packet: pkt_ov093_021D5734
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_ReplaceMoveSlot 0x021D51DC thumb ov093
 */
typedef unsigned char u8;
struct S;
extern void BTL_POKEPARAM_ReplaceMoveSlot(struct S *p, unsigned int a, unsigned int b, unsigned int c);
typedef unsigned int u32;
typedef unsigned short u16;
void BTL_POKEPARAM_ReplaceMove(u8 *p, u8 i, u16 a, u8 b, u32 c)
{ BTL_POKEPARAM_ReplaceMoveSlot((void *)((u32)p + 0x104 + i * 14), a, b, c); }
