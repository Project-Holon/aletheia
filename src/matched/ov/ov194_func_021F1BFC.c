/*
 * function: NAMEIN_GRAPHIC_UpdateCursor
 * address: 0x021F1BFC
 * packet: pkt_ov194_021F1BFC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wD7 lane05): the third parameter is dead after the switch; the source reuses it
 *   for the address of the Vec2 scratch (`rect = &v;`), which keeps that address in r7 across both
 *   CLACT_AddActorSurfacePos calls (idiom a-dead-stack-parameter-reassigned-to-a-locals-address-keeps-a-callee-saved-register).
 *   Parameter declared `const void *` so no casts are needed.
 * symbols:
 *   NAMEIN_GRAPHIC_SetupCursor 0x021F1A1C thumb ov194
 *   NAMEIN_GRAPHIC_FadeCellColor 0x021F1D58 thumb ov194
 *   func_020355C4 0x020355C4 arm
 *   func_02040804 0x02040804 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   d_021F5780 0x021F5780 data a4 ov194
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Rect { int left, top, right, bottom; } Rect;
struct Vec2 { s16 x, y; };
struct Obj;
extern u32 d_021F5780[];
extern void NAMEIN_GRAPHIC_SetupCursor(char *p, int mode, const Rect *rect, int flag, int selected);
extern int NAMEIN_GRAPHIC_FadeCellColor(u16 *out, u16 *phase, u32 step, u32 row, u8 idx, u16 a, u16 b);
extern u8 func_020355C4(void);
extern u32 func_02040804(u32 layer);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void NAMEIN_GRAPHIC_UpdateCursor(char *p, int sel, const void *rect)
{
    struct Vec2 v;
    u32 d, c;
    int i;
    if (*(u32 *)(p + 0x98) != 0) {
        u16 *a, *b;
        switch (*(u32 *)(p + 0x94)) {
        case 0:
            break;
        case 1:
            d = 2;
            c = (u16)d_021F5780[0];
            break;
        case 2:
            d = 3;
            c = 0x1999;
            if ((*(u16 *)(p + 0x80))++ > 10) {
                if (func_020355C4() == 0)
                    NAMEIN_GRAPHIC_SetupCursor(p, 1, rect, *(int *)(p + 0x9C), sel);
                else
                    NAMEIN_GRAPHIC_SetupCursor(p, 0, rect, *(int *)(p + 0x9C), sel);
            }
            break;
        }
        a = (u16 *)p;
        a += 0x20;
        b = (u16 *)p;
        b += 0x30;
        for (i = 0; i < 16; i++)
            NAMEIN_GRAPHIC_FadeCellColor(a + i, b + i, c, d, i, ((u16 *)p)[i], ((u16 *)p)[i + 0x10]);
    }
    rect = &v;
    v.x = *(u16 *)(p + 0xAC);
    v.y = *(u16 *)(p + 0xAE);
    v.y = v.y - (s16)(func_02040804(2) << 3);
    CLACT_AddActorSurfacePos(*(struct Obj **)(p + 0xA4), rect, 0);
    v.x = *(u16 *)(p + 0xB0);
    v.y = *(u16 *)(p + 0xB2);
    v.y = v.y - (s16)(func_02040804(2) << 3);
    CLACT_AddActorSurfacePos(*(struct Obj **)(p + 0xA8), rect, 0);
    if (*(int *)(p + 0xA0) != sel) {
        if (func_020355C4() == 0)
            NAMEIN_GRAPHIC_SetupCursor(p, 1, (const Rect *)(p + 0x84), *(int *)(p + 0x9C), sel);
        else
            NAMEIN_GRAPHIC_SetupCursor(p, 0, (const Rect *)(p + 0x84), *(int *)(p + 0x9C), sel);
    }
}
