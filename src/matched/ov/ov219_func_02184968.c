/*
 * function: BEACON_DETAIL_CreateBmpWin
 * address: 0x02184968
 * packet: pkt_ov219_02184968
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;struct CharBuf;struct Cfg;
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void *BMP_WIN_GetBmp(struct Descriptor*);
extern void BMP_Clear(struct CharBuf*,u8);
extern void BMP_WIN_MakeScreen(struct Cfg*);
u32 BEACON_DETAIL_CreateBmpWin(const u8 *p,int flag){u32 q;q=BMP_WIN_Create(p[0],p[1],p[2],p[3],p[4],p[5],1);BMP_Clear((struct CharBuf*)BMP_WIN_GetBmp((struct Descriptor*)q),15);if(flag==1)BMP_WIN_MakeScreen((struct Cfg*)q);return q;}
