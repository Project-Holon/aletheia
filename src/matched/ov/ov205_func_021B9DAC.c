/*
 * function: SAVE_SCREEN_DeleteNoticeBackground
 * address: 0x021B9DAC
 * packet: pkt_ov205_021B9DAC
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BMP_WIN_Exit(void); extern void BG_SYS_Delete(void);
void SAVE_SCREEN_DeleteNoticeBackground(void) { BMP_WIN_Exit();BG_SYS_Delete(); }
