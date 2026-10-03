/*
 * function: func_021F69E4
 * address: 0x021F69E4
 * packet: pkt_ov097_021F69E4
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056A0 0x020056A0 thumb
 *   func_021F6A08 0x021F6A08 thumb ov097
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_020056A0(void (*)(void), void *, u32);
extern void func_021F6A08(void);
void func_021F69E4(u8 *p) { *(void **)(p+4) = func_020056A0(func_021F6A08, p, 0); }
