/*
 * function: MANUAL_CATEGORY_DrawOption
 * address:  0x021BBD74
 * packet:   pkt_021BBD74
 * region:   ov225
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a graphics record: releases the p+0x24 handle, sizes the p+0x18
 * resource through BMP_WIN_GetBmp, resolves a slot word, and submits a
 * seven-argument call before marking p+0x30 and repointing the slot.
 *
 * symbols:
 *   PRINTSYS_QUE_Clear    0x0201C6EC  thumb
 *   BMP_WIN_GetBmp    0x02045770  arm
 *   BMP_Clear    0x02043B5C  arm
 *   func_02045EC0    0x02045EC0  arm
 *   PRINTSYS_PrintQueColor    0x0201C724  thumb
 *   STRBUF_Delete    0x02045808  arm
 *   MANUAL_CATEGORY_UpdateOptionSlots    0x021BBD28  thumb  ov225
 *   func_021B9E80    0x021B9E80  thumb  ov225
 */
#include "../include/Obj02267.h"
#include "../include/Obj26324.h"
#include "../include/Obj26325.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct U16Vec;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void MANUAL_CATEGORY_UpdateOptionSlots(u8 *p);
extern void func_021B9E80(char *p, unsigned id);

void MANUAL_CATEGORY_DrawOption(char *p)
{
    void *r;

    PRINTSYS_QUE_Clear(((struct Obj02267 *)p)->f24);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj02267 *)p)->f18), 0);
    r = func_02045EC0(((struct Obj26324 *)(*(char * *)&((struct Obj02267 *)p)->f4))->f20,
                      *(u16 *)(*(char * *)&((struct Obj02267 *)p)->f0 + (((struct Obj02267 *)p)->f8 << 2) + 6));
    PRINTSYS_PrintQueColor(((struct Obj02267 *)p)->f24, (u32)BMP_WIN_GetBmp(((struct Obj02267 *)p)->f18),
                  4, 6, (u32)r, ((struct Obj26325 *)(*(char * *)&((struct Obj02267 *)p)->f4))->fC, 0x440);
    STRBUF_Delete(r);
    ((struct Obj02267 *)p)->f30 = 1;
    MANUAL_CATEGORY_UpdateOptionSlots((u8 *)p);
    func_021B9E80(((struct Obj02267 *)p)->f4,
                  *(u16 *)(*(char * *)&((struct Obj02267 *)p)->f0 + (((struct Obj02267 *)p)->f8 << 2) + 4));
}
