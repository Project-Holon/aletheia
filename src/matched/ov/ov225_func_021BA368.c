/*
 * function: MANUAL_COMMON_DrawTouchbarContinue
 * address: 0x021BA368
 * packet: pkt_ov225_021BA368
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 178 compiled bytes followed by two zero alignment bytes at 021BA41A.
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   MANUAL_COMMON_UpdateTouchbarSlots 0x021BA240 thumb ov225
 */
#include "../include/Obj02561.h"
#include "../include/Obj26162.h"
#include "../include/Obj26163.h"
#include "../include/Obj26164.h"
#include "../include/Obj26165.h"
#include "../include/Obj26166.h"
#include "../include/Obj26167.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;struct Descriptor;struct CharBuf;struct WordSet;struct U16Vec;struct MsgBank;
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern struct WordSet *WORDSET_CreateDefault(u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void WORDSET_SetSlotNumber(struct WordSet *,u32,u32,u32,u32,u32);
extern void WORDSET_CopyTaggedText(struct WordSet *,void *,void *);
extern void PRINTSYS_PrintQueColor(void *,u32,u32,u32,u32,u32,u16);
extern void STRBUF_Delete(struct U16Vec *);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void MANUAL_COMMON_UpdateTouchbarSlots(char *);
void MANUAL_COMMON_DrawTouchbarContinue(char *p)
{
    struct WordSet *words;
    struct U16Vec *str;
    void *slot;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj26162 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f18);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj02561 *)p)->f14),0);
    words=WORDSET_CreateDefault(((struct Obj26163 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f4);
    slot=func_02045EC0(*(struct MsgBank * *)&((struct Obj26164 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f1C,4);
    str=STRBUF_Create(16,((struct Obj26165 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f4);
    WORDSET_SetSlotNumber(words,0,((struct Obj02561 *)p)->fD+1,1,0,1);
    WORDSET_SetSlotNumber(words,1,((struct Obj02561 *)p)->fC,1,0,1);
    WORDSET_CopyTaggedText(words,str,slot);
    PRINTSYS_PrintQueColor(((struct Obj26166 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f18,(u32)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj02561 *)p)->f14),32,4,(u32)str,((struct Obj26167 *)(*(char * *)&((struct Obj02561 *)p)->f0))->fC,0x3c40);
    STRBUF_Delete(str);STRBUF_Delete(slot);WORDSET_Delete(words);
    ((struct Obj02561 *)p)->f1C=1;MANUAL_COMMON_UpdateTouchbarSlots(p);
}
