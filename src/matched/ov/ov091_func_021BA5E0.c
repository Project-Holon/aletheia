/*
 * function: func_021BA5E0
 * address: 0x021BA5E0
 * packet: pkt_ov091_021BA5E0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: arm9 0x020182A0 has no outside witness; tu --suggest-split cannot cut it free.
 * Verified blocker C (one --thumb, no region, EXACT, 8 bytes):
 * typedef unsigned char u8; typedef unsigned short u16;
 * extern void func_020182A8(void *,u16,u8);
 * void func_020182A0(void *p,u16 move,u8 slot) { func_020182A8(p,move,slot); }
 * symbols: func_020182A8 0x020182A8 thumb
 * Extent ends with two bytes alignment padding.
 * symbols:
 *   func_020181F4 0x020181F4 thumb
 *   func_020182A0 0x020182A0 thumb
 
 * 2026-10-05 (D8 lane 15): 020182A0 now filed EXACT as src/matched/arm9/func_020182A0.c.
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020181F4(void *,u16,u32);
extern void func_020182A0(void *,u16,u32);
void func_021BA5E0(u8 *p, void *q, u32 slot) { u8 *s=*(u8 **)(p+0x280); if (*(u32 *)(s+0x34)==5 || *(u32 *)(s+0x34)==8) func_020181F4(q,*(u16 *)(s+0x46),slot); else func_020182A0(q,*(u16 *)(s+0x46),slot); }
