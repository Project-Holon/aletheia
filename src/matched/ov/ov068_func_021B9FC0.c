/*
 * function: OPTION_MENU_UpdateSprites
 * address:  0x021B9FC0
 * packet:   pkt_ov068_021B9FC0
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   CLACT_DrawSystem  0x0204A600  arm
 */
#include "../include/Obj09869.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void CLACT_SetActorAnimIndex(int a0, int a1);
extern void CLACT_DrawSystem(void);

void OPTION_MENU_UpdateSprites(u8 *p)
{
    int i;
    u16 t;

    t = (((struct Obj09869 *)p)->f50)++;
    if (t > 0x60) {
        ((struct Obj09869 *)p)->f50 = 0;
    }
    for (i = 2; i < 13; i++) {
        CLACT_SetActorAnimIndex(*(u32 *)(p + i * 4 + 0x18), (u16)(((struct Obj09869 *)p)->f50 / 12));
    }
    CLACT_DrawSystem();
}
