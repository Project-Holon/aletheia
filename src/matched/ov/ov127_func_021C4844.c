/*
 * function: WF2DMAP_MAP_IsCellBlocked
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
 *   WF2DMAP_MAP_GetCell 0x021C4818 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef union { u32 raw; struct { u32 flag:1; u32 value:31; } bits; } Cell;
extern Cell WF2DMAP_MAP_GetCell(u8 *,u32,u32);
int WF2DMAP_MAP_IsCellBlocked(u8 *p, u16 x, u16 y) { Cell r=WF2DMAP_MAP_GetCell(p,x,y); if(r.raw==(u32)-1) return 1; return r.bits.flag; }
