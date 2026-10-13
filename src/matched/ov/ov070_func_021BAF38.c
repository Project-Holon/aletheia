/*
 * function: ITEMMENU_PrintPocketCount
 * address:  0x021BAF38
 * packet:   pkt_ov070_021BAF38
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F14C  0x0201F14C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201D304  0x0201D304  thumb
 *   ITEMMENU_PrintToWindow  0x021BB6E0  thumb  ov070
 *   ITEMMENU_FlushWindowAt  0x021BB724  thumb  ov070
 */
#include "../include/Obj01516.h"

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef signed short   s16;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct StrObj;
struct WordSet;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F14C(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void ITEMMENU_PrintToWindow(int p, u32 *obj, u32 str, u16 x, s16 y, u16 color);
extern void ITEMMENU_FlushWindowAt(void **p);

void ITEMMENU_PrintPocketCount(int p, int val)
{
    int r;

    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01516 *)p)->f504)), 0);
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj01516 *)p)->f51C), 0x8B, (void *)(((struct Obj01516 *)p)->f524));
    func_0201F14C((struct WordSet *)(((struct Obj01516 *)p)->f520), 0, val);
    func_0201F250((struct WordSet *)(((struct Obj01516 *)p)->f520), (void *)(((struct Obj01516 *)p)->f528), (void *)(((struct Obj01516 *)p)->f524));
    r = 0x60 - func_0201D304((struct StrObj *)(((struct Obj01516 *)p)->f528), *(int *)&((struct Obj01516 *)p)->f530, 0);
    ITEMMENU_PrintToWindow(p, (u32 *)(p + 0x504), ((struct Obj01516 *)p)->f528, (unsigned short)(r >> 1), 4, 0x3C40);
    ITEMMENU_FlushWindowAt((void **)(p + 0x504));
}
