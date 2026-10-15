/*
 * function: func_0221025C
 * address: 0x0221025C
 * packet: pkt_ov198_0221025C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220EA68 0x0220EA68 thumb ov198
 *   func_0220BE2C 0x0220BE2C thumb ov198
 *   B_PLIST_ANM_UpdateByMode 0x0220B848 thumb ov198
 *   func_02210BFC 0x02210BFC thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0220EA68(char *,u32),B_PLIST_ANM_UpdateByMode(u8 *,u32),func_02210BFC(u8 *,int);
extern int func_0220BE2C(char *,int);
int func_0221025C(u8 *p) { func_0220EA68((char *)p,p[0x2180]);func_0220BE2C((char *)p,p[0x2180]);B_PLIST_ANM_UpdateByMode(p,p[0x2180]);func_02210BFC(p,p[0x2180]);if(p[0x2180]==2)return 5;return 6; }
