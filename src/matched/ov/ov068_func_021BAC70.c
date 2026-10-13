/*
 * function: OPTION_MENU_SelectChoiceAtTouch
 * address:  0x021BAC70
 * packet:   pkt_ov068_021BAC70
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gOptionMenuChoices     0x021BB704  data  ov068  a4
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   OPTION_MENU_IsPointInRect  0x021BB508  thumb  ov068
 *   OPTION_MENU_SelectChoice  0x021BAFD8  thumb  ov068
 *   OPTION_MENU_ApplySoundMode  0x021BACF4  thumb  ov068
 */
#include "../include/Obj13141.h"

typedef unsigned char u8;
typedef signed char   s8;
typedef signed short  s16;
typedef unsigned int  u32;

typedef struct {
    u8  pad[0x10];
    s16 f10;
    s16 f12;
    s16 f14;
    s16 f16;
} Ent;

extern Ent gOptionMenuChoices[];
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern int  OPTION_MENU_IsPointInRect(int *rect, void *b);
extern void OPTION_MENU_SelectChoice(u8 *p, int i);
extern void OPTION_MENU_ApplySoundMode(u8 *p, u32 a, u32 b);

void OPTION_MENU_SelectChoiceAtTouch(u8 *p, void *b)
{
    int i;
    int r[4];
    int x;
    int y;

    for (i = 0; i < 11; i++) {
        Ent *e = &gOptionMenuChoices[i];

        y = ((struct Obj13141 *)p)->f34 + e->f12;
        x = e->f10;
        r[1] = y;
        r[0] = x;
        r[3] = y + e->f16;
        r[2] = x + e->f14;
        if (y >= 0x18 && y <= 0xa8 && r[3] >= 0x18 && r[3] <= 0xa8) {
            if (OPTION_MENU_IsPointInRect(r, b)) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                OPTION_MENU_SelectChoice(p + 0x44, i);
                OPTION_MENU_ApplySoundMode(p, ((struct Obj13141 *)p)->f47, 0);
                return;
            }
        }
    }
}
