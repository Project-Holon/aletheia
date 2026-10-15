/*
 * function: IRCBATTLEMATCH_PrintPlayerMessage
 * address: 0x021BA454
 * packet: pkt_ov100_021BA454
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero alignment bytes at 0x021BA52E.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   func_02009A34 0x02009A34 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj01246.h"
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef signed short   s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Sub020097BCObj;
struct WordSet;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *);
void IRCBATTLEMATCH_PrintPlayerMessage(int text,int a) {
 if(((struct Obj01246 *)a)->f280==0) {
  int v=(int)BMP_WIN_Create((int)5,(int)1,(int)8,(int)18,4,13,0);
  ((struct Obj01246 *)a)->f280=v;
  BMP_WIN_MakeScreen((struct Cfg *)v);
  BMP_MENUWORK_DrawWindow((void *)(((struct Obj01246 *)a)->f280),0,(unsigned short)(((struct Obj01246 *)a)->f304),14);
 }
 BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01246 *)a)->f280)),255);
 MSGDATA_ReadString((struct MsgBank *)(((struct Obj01246 *)a)->f288),text,(void *)(((struct Obj01246 *)a)->f294));
 WORDSET_SetSlotNumber((struct WordSet *)(((struct Obj01246 *)a)->f28C),0,func_02009A34((struct Sub020097BCObj *)GAME_DATA_GetWifiList((const struct BigObj *)(**(int * *)&((struct Obj01246 *)a)->f244))),2,1,1);
 WORDSET_SetSlotNumber((struct WordSet *)(((struct Obj01246 *)a)->f28C),1,32,2,1,1);
 WORDSET_CopyTaggedText((struct WordSet *)(((struct Obj01246 *)a)->f28C),(void *)(((struct Obj01246 *)a)->f298),(void *)(((struct Obj01246 *)a)->f294));
 PRINTSYS_Print((void *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01246 *)a)->f280)),0,2,(void *)(((struct Obj01246 *)a)->f298),(void *)(((struct Obj01246 *)a)->f290));
 BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01246 *)a)->f280);
}
