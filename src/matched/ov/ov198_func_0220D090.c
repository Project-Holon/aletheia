/*
 * function: func_0220D090
 * address:  0x0220D090
 * packet:   pkt_0220D090
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
  * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 */
#include "../include/Obj02533.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
struct StrObj;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);

void func_0220D090(char *p, int a1, int a2)
{
    u32 handle;
    void *t;
    u16 w;

    handle = *(u32 *)(p + 0x1f70 + a1 * 8);
    if (a2 == 0) {
        u32 f;

        t = func_02045EC0(((struct Obj02533 *)p)->f1EA0, 0x3c);
        w = func_0201D304((struct StrObj *)((u32)t), *(u32 *)(((struct Obj02533 *)p)->f0 + 0xc), 0);
        w = (BMP_WIN_GetWidth((void *)handle) << 3) - w;
        f = ((struct Obj02533 *)p)->f1EAC;
        PRINTSYS_PrintQueColor((void *)f,
                      (u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + 0x1f70 + a1 * 8)), (s16)w, 0,
                      (u32)t, *(u32 *)(((struct Obj02533 *)p)->f0 + 0xc), 0x2120);
        *(u8 *)(p + a1 * 8 + 0x1f74) = 1;
        STRBUF_Delete(t);
    } else {
        void *t2;
        u32 h;
        u32 f;
        u16 w0;
        u16 w2;

        t2 = func_02045EC0(((struct Obj02533 *)p)->f1EA0, 0x3e);
        h = (u32)STRBUF_Create(8, *(u16 *)(((struct Obj02533 *)p)->f0 + 0x10));
        func_0201EFA4(((struct Obj02533 *)p)->f1EA4, 0, a2, 3, 0, 1);
        func_0201F250(((struct Obj02533 *)p)->f1EA4, (void *)h, t2);
        w0 = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj02533 *)p)->f0 + 0xc), 0);
        w2 = (BMP_WIN_GetWidth((void *)handle) << 3) - w0;
        f = ((struct Obj02533 *)p)->f1EAC;
        PRINTSYS_PrintQueColor((void *)f,
                      (u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + 0x1f70 + a1 * 8)), (s16)w2, 0,
                      h, *(u32 *)(((struct Obj02533 *)p)->f0 + 0xc), 0x2120);
        *(u8 *)(p + a1 * 8 + 0x1f74) = 1;
        STRBUF_Delete(t2);
        STRBUF_Delete((void *)h);
    }
}
