/*
 * function: func_021C4844
 * address: 0x021C4844
 * packet: pkt_ov127_021C4844
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: 2-byte zero alignment padding.
 * symbols:
 *   func_021C4818 0x021C4818 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef union { u32 raw; struct { u32 flag:1; u32 value:31; } bits; } Cell;
extern Cell func_021C4818(u8 *,u32,u32);
int func_021C4844(u8 *p, u16 x, u16 y) { Cell r=func_021C4818(p,x,y); if(r.raw==(u32)-1) return 1; return r.bits.flag; }
