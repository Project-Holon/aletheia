/*
 * function: B_PLIST_DRAW_PrintCenteredText
 * address: 0x0220C694
 * packet: pkt_ov198_0220C694
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 */
#include "../include/Obj08358.h"
#include "../include/Obj25143.h"
#include "../include/Obj25144.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
void B_PLIST_DRAW_PrintCenteredText(char *p, int i, int id)
{
    void *t;
    void *handle;
    void *f;
    u32 width;
    u32 font;
    s16 x;
    handle = *(void **)(p + 0x1F70 + i * 8);
    t = func_02045EC0(((struct Obj08358 *)p)->f1EA0, id);
    width = func_0201D304(t, ((struct Obj25143 *)(*(char * *)&((struct Obj08358 *)p)->f0))->fC, 0);
    font = ((struct Obj25144 *)(*(char * *)&((struct Obj08358 *)p)->f0))->fC;
    x = (s16)(((BMP_WIN_GetWidth(handle) << 3) - width) >> 1);
    f = ((struct Obj08358 *)p)->f1EAC;
    PRINTSYS_PrintQueColor(f, (u32)BMP_WIN_GetBmp(*(void **)(p + 0x1F70 + i * 8)), x, 5, (u32)t, font, 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}
