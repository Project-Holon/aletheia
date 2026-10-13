/*
 * function: func_021D4438
 * address: 0x021D4438
 * packet: pkt_ov093_021D4438
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u32 *d_021F3B88;
extern int POKE_REGULATION_GetDataSize(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
u8 func_021D4438(u32 a) { u32 r; r=POKE_REGULATION_GetDataSize(); return func_0203D3F8(*d_021F3B88,255,0x102,r,a,0,1,1); }
