/*
 * function: func_021BDEF0
 * address: 0x021BDEF0
 * packet: pkt_ov172_021BDEF0
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008510 0x02008510 thumb
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj02216.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct StrObj;
struct U16Vec;
extern void *func_02008510(void *a, int tag);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(u32 owner, void *b, short y, u32 c, void *d, u32 e, u32 f);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_021BDEF0(u8 *p, char *a, u32 b)
{
    void *s;
    int x;
    s = func_02008510(a, ((struct Obj02216 *)p)->f0);
    x = (0x60 - (u8)func_0201D304(s, ((struct Obj02216 *)p)->f1C8, 0)) / 2;
    PRINTSYS_PrintQueColor(((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x + 1, 1, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    PRINTSYS_PrintQueColor(((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x - 1, 1, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    PRINTSYS_PrintQueColor(((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x, 2, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    PRINTSYS_PrintQueColor(((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x, 0, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    PRINTSYS_PrintQueColor(((struct Obj02216 *)p)->f1D0, BMP_WIN_GetBmp((struct Descriptor *)b), x, 1, s, ((struct Obj02216 *)p)->f1C8, 0x3c00);
    STRBUF_Delete(s);
}
