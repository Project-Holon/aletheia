/*
 * function: func_021B9C08
 * address: 0x021B9C08
 * packet: pkt_ov133_021B9C08
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021B9C08(u8 *p, unsigned int index, void *object)
{
    void *text = func_02045EC0(((struct Obj00004 *)p)->f18D8, index);
    void *copy;
    PRINTSYS_QUE_Clear(((struct Obj00004 *)p)->f18E8);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00004 *)p)->f18EC), 15);
    if (object) {
        copy = STRBUF_Create(128, ((struct Obj00004 *)p)->f0);
        func_0201F250(object, copy, text);
        STRBUF_Delete(text);
        text = copy;
    }
    PRINTSYS_PrintQueColor(((struct Obj00004 *)p)->f18E8, (u32)BMP_WIN_GetBmp(((struct Obj00004 *)p)->f18EC), 2, 2, (u32)text, (u32)(((struct Obj00004 *)p)->f18E4), 1088);
    STRBUF_Delete(text);
    *(int *)&((struct Obj00004 *)p)->f18CC = 1;
}
