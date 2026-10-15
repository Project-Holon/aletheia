/*
 * function: PLIST_MESSAGE_CloseWindow
 * address: 0x021BB7A4
 * packet: pkt_ov091_021BB7A4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Descriptor;
struct PrintSys;
extern void TIME_ICON_Delete(u8 *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
void PLIST_MESSAGE_CloseWindow(void *p,u32 *s) { if(s[0]!=4) { if(s[13]!=0) {TIME_ICON_Delete((u8 *)s[13]);s[13]=0;} BMP_MENUWORK_DrawWindowBorder((void *)s[1],1); BMP_WIN_Delete((struct Descriptor *)s[1]); PRINTSYS_QUE_Clear((struct PrintSys *)s[10]); s[0]=4; } }
