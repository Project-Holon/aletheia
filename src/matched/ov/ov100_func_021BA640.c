/*
 * function: IRCBATTLEMATCH_ExitWindowSystem
 * address:  0x021BA640
 * packet:   pkt_ov100_021BA640
 * region:   ov100
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void BG_SYS_Delete(void);
extern void BMP_WIN_Exit(void);
void IRCBATTLEMATCH_ExitWindowSystem(int a0) { BG_SYS_Delete(); BMP_WIN_Exit(); }
