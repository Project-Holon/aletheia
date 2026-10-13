/*
 * file:     unit_0689AD4C.c
 * function: func_0689AD4C
 * address:  0x0689AD4C
 * packet:   pkt_ov095_0689AD4C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_MAIN_GetRule  0x021B8588  thumb
 *   BTL_MAIN_GetFacingPos  0x021B8C5C  thumb
 *   BTL_MAIN_GetFrontEnemyPos  0x021B9A00  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_MAIN_GetRule(u32 a);
extern int WAZA_TOOL_GetFlag(u32 a, int b);
extern int BTL_MAIN_GetFrontEnemyPos(u32 a, u8 *p);
extern u8 BTL_MAIN_GetFacingPos(int a, u8 b);

typedef struct { u8 n; u8 pad[2]; u8 d[16]; } St;

void func_0689AD4C(St *st, u32 a, u32 b, u32 c)
{
    u8 x;

    if (BTL_MAIN_GetRule(a) == 2) {
        if (WAZA_TOOL_GetFlag(b, 0xb)) {
            if (BTL_MAIN_GetFrontEnemyPos(c, &x)) {
                st->d[st->n++] = x;
                st->d[st->n++] = BTL_MAIN_GetFacingPos(2, x);
            }
        }
    }
}
