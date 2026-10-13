/*
 * function: func_0220CCF0
 * address:  0x0220CCF0
 * packet:   pkt_0220CCF0
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022110D4 0x022110D4 thumb
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
#include "../include/Obj01582.h"
#include "../include/Obj25155.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int   func_022110D4(u8 *p, int i);
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

void func_0220CCF0(char *p, int i)
{
    char *elem;
    void *t;
    void *t2;
    u32 y;
    u32 h;
    u8 b;
    u8 c;
    u32 d;
    u32 e;
    u32 x;

    elem = (char *)(p + 4) + func_022110D4((u8 *)p, i) * 0x4c;
    t = func_02045EC0(((struct Obj01582 *)p)->f1EA0, 0x30);
    x = ((struct Obj01582 *)p)->f1EAC;
    y = (u32)BMP_WIN_GetBmp(((struct Obj01582 *)p)->f2000);
    PRINTSYS_PrintQueColor((void *)x, y, 0, 0, (u32)t, *(u32 *)(((struct Obj01582 *)p)->f0 + 0xc), 0x3dc0);
    ((struct Obj01582 *)p)->f2004 = 1;
    STRBUF_Delete(t);
    t2 = func_02045EC0(((struct Obj01582 *)p)->f1EA0, 0x31);
    h = (u32)STRBUF_Create(8, *(u16 *)(((struct Obj01582 *)p)->f0 + 0x10));
    func_0201EFA4(((struct Obj01582 *)p)->f1EA4, 0, ((struct Obj25155 *)elem)->fE, 3, 0, 1);
    func_0201F250(((struct Obj01582 *)p)->f1EA4, (void *)h, t2);
    b = func_0201D304((struct StrObj *)h, *(u32 *)(((struct Obj01582 *)p)->f0 + 0xc), 0);
    c = (BMP_WIN_GetWidth(((struct Obj01582 *)p)->f1FB8) << 3) - b;
    d = ((struct Obj01582 *)p)->f1EAC;
    e = (u32)BMP_WIN_GetBmp(((struct Obj01582 *)p)->f1FB8);
    PRINTSYS_PrintQueColor((void *)d, e, c, 0, h, *(u32 *)(((struct Obj01582 *)p)->f0 + 0xc), 0x2120);
    ((struct Obj01582 *)p)->f1FBC = 1;
    STRBUF_Delete(t2);
    STRBUF_Delete((void *)h);
}
