/*
 * function: BOX2_UI_RefreshBoxHeader
 * address: 0x021ED9C8
 * packet: pkt_ov170_021ED9C8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021EFD1C 0x021EFD1C data a4
 *   BOX2_MAIN_WrapOffset 0x021DEB14 thumb ov170
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb ov170
 *   BOX2_UI_UploadSlotChar 0x021EDB64 thumb ov170
 *   BMP_OAM_SetPos 0x0202590C thumb
 *   BOX2_SEQ_DrawMonName 0x021EB874 thumb ov170
 */
#include "../include/Obj00000.h"
typedef struct { short x, y; int b, c, d, e; short f, g; } Desc;
extern const Desc d_021EFD1C;
extern unsigned char BOX2_MAIN_WrapOffset(unsigned char *p, int a);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_UI_UploadSlotChar(char *, int, int);
typedef signed short   s16;
struct Grid;
extern void BMP_OAM_SetPos(struct Grid *g, s16 x, s16 y);
extern void BOX2_SEQ_DrawMonName(char **, unsigned, int);
void BOX2_UI_RefreshBoxHeader(char *p)
{
    Desc t;
    Desc base = d_021EFD1C;
    short i;
    int a, y;
    for (i = 0; i < 6; i++) {
        a = BOX2_MAIN_WrapOffset((unsigned char *)p, (signed char)(i - 1));
        t = base;
        y = i * 0x22;
        t.y += (short)y;
        BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2d, t.x, t.y, 0);
        BOX2_UI_UploadSlotChar(p, a, i + 0x2d);
        BMP_OAM_SetPos(*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C + i * 8 + 0xc), 0x13c, y + 2);
        BOX2_SEQ_DrawMonName((char **)p, a, i + 1);
    }
}
