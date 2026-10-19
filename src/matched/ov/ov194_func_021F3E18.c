/*
 * function: NAMEIN_GRAPHIC_PrintMonMsg
 * address: 0x021F3E18
 * packet: pkt_ov194_021F3E18
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WORDSET_SetSlotMonSpeciesName 0x0201EE84 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj02532.h"
typedef unsigned int   u32;
struct WordSet;
extern void WORDSET_SetSlotMonSpeciesName(struct WordSet *p, u32 i, void *mon);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct PrintSys;
struct U16Vec;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void STRBUF_Delete(struct U16Vec *vec);
void NAMEIN_GRAPHIC_PrintMonMsg(char *p,int value,void *mon) {
    int text,window;
    WORDSET_SetSlotMonSpeciesName(((struct Obj02532 *)p)->f18,0,mon);
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02532 *)p)->f14)),((struct Obj02532 *)p)->f20);
    text=(int)func_02045EC0((struct MsgBank *)(((struct Obj02532 *)p)->f0),value);
    WORDSET_CopyTaggedText((struct WordSet *)(*(int *)&((struct Obj02532 *)p)->f18),((struct Obj02532 *)p)->f1C,(void *)text);
    window=((struct Obj02532 *)p)->f10;
    PRINTSYS_PrintQue((struct PrintSys *)window,(int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02532 *)p)->f8),0,0,(void *)(*(int *)&((struct Obj02532 *)p)->f1C),((struct Obj02532 *)p)->f4);
    ((struct Obj02532 *)p)->fC=1;
    STRBUF_Delete((struct U16Vec *)text);
}
