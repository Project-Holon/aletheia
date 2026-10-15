/*
 * function: FIELD_MENU_SetScrolledOut
 * address:  0x021A8DD8
 * packet:   pkt_ov021_021A8DD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_FillScrollArea  0x02040618  arm
 *   CLACT_SetSurfacePos  0x0204B09C  arm
 */

typedef short s16;

typedef struct {
    s16 x;
    s16 y;
} P;

typedef struct {
    char pad0[0xfc];
    s16 hfc;
    char pad2[0x120 - 0xfe];
    int f120;
} S;

typedef unsigned int   u32;
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void CLACT_SetSurfacePos(int a, int b, P *c);

void FIELD_MENU_SetScrolledOut(S *s)
{
    P v;
    s->hfc = 0xc0;
    BG_SYS_FillScrollArea(5, 3, -0xc0);
    BG_SYS_FillScrollArea(6, 3, -0xc5);
    v.x = 0;
    v.y = 0xc0;
    CLACT_SetSurfacePos(s->f120, 0, &v);
}
