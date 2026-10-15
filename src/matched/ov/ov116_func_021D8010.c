/*
 * function: WIFI_BSUBWAY_GRAPHIC_PrintMessage
 * address: 0x021D8010
 * packet: pkt_ov116_021D8010
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj22630.h"
typedef unsigned short u16;
typedef unsigned u32;
struct Rec3;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(u32,int,int,u32,u32,u32,u32,int,u16,int);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
#define I(k) (*(u32 *)((char *)p+(k)))
void WIFI_BSUBWAY_GRAPHIC_PrintMessage(void *p,u32 a) {
 if(I(0x9a4)!=0) {PRINTSYS_PrintStreamDelete((void *)I(0x9a4)); I(0x9a4)=0;}
 MSGDATA_ReadString((struct MsgBank *)I(0x990),a,(void *)I(0x99c));
 func_0201F250((struct WordSet *)I(0x994),(void *)I(0x9a0),(void *)I(0x99c));
 BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)I(0x97c))),15);
 GF_FONT_SetTextColor(1,2,15);
 I(0x9a4)=(u32)PRINTSYS_PrintStream(I(0x97c),0,0,I(0x9a0),I(0x998),MSG_SPEED_GetWait(),I(0x9a8),2,((struct Obj22630 *)p)->f4,15);
 func_0201F73C((void *)I(0x97c),1,(u16)I(0x984),13);
 BMP_WIN_TransferChars((struct Descriptor *)I(0x97c));
}
