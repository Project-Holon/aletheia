/*
 * function: B_BAG_MAIN_CreateWindows
 * address: 0x0220B150
 * packet: pkt_ov197_0220B150
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Declaring the table pointer before the counter restores r4/r5 allocation.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   d_0220DA68 0x0220DA68 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern const u8 d_0220DA68[];
void B_BAG_MAIN_CreateWindows(char *p,u8 unused) { const u8 *q; u32 i; q=d_0220DA68; for(i=0;i<35;i++,q+=6) *(u32 *)(p+i*8+0x28)=BMP_WIN_Create(q[0],q[1],q[2],q[3],q[4],q[5],1); }
