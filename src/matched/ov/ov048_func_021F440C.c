/*
 * function: GIMMICK_OBJ_ELBOARD_AddNoticeMessage
 * address:  0x021F440C
 * packet:   pkt_ov048_021F440C
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GIMMICK_OBJ_ELBOARD_AddMessage  0x021F3D38  thumb
 *   gElboardLayoutAnimIndex     0x021F50C4  data  a2
 *   gElboardLayoutTextureName     0x021F50EC  data  a4
 *   gElboardLayoutPaletteName     0x021F5108  data  a4
 */

typedef unsigned short u16;

extern void GIMMICK_OBJ_ELBOARD_AddMessage(int *p, int unused, int b, int *c);
extern u16 gElboardLayoutAnimIndex[];
extern int gElboardLayoutTextureName[];
extern int gElboardLayoutPaletteName[];

void GIMMICK_OBJ_ELBOARD_AddNoticeMessage(int *p, int *q, int i)
{
    struct { u16 a; int b, c, d, e, f, g; } s;

    s.a = gElboardLayoutAnimIndex[i];
    s.b = gElboardLayoutTextureName[i];
    s.c = gElboardLayoutPaletteName[i];
    s.d = 2;
    s.e = 0x26;
    s.f = q[3];
    s.g = 0;
    GIMMICK_OBJ_ELBOARD_AddMessage(p, (int)&s, 8, q);
}
