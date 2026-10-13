/*
 * function: func_021DF984
 * address: 0x021DF984
 * packet: pkt_ov137_021DF984
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   d_021E1EA4 0x021E1EA4 data a4
 */
typedef unsigned short u16;
struct DispVram;extern const struct DispVram d_021E1EA4;
extern void BG_SYS_SetVramBanks(const struct DispVram *);extern void BMP_WIN_Init(u16);
void func_021DF984(char *p){BG_SYS_SetVramBanks(&d_021E1EA4);BMP_WIN_Init(114);}
