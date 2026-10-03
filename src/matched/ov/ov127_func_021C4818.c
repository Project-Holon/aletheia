/*
 * function: func_021C4818
 * address: 0x021C4818
 * packet: pkt_ov127_021C4818
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C600C 0x021C600C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef union { u32 raw; struct { u32 flag:1; u32 value:31; } bits; } Cell;
extern Cell d_021C600C;
Cell func_021C4818(u8 *p, u32 x, u32 y)
{
 Cell r = d_021C600C;
 if (*(u16 *)p > x && *(u16 *)(p+2) > y) r=*(Cell *)(*(u32 *)(p+4) + (x + *(u16 *)p*y)*4);
 return r;
}
