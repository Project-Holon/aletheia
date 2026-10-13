/*
 * function: OPTION_MENU_ExitButtons
 * address:  0x021BA410
 * packet:   pkt_021BA410
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOUCHBAR_Delete  0x021B639C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../include/Obj20641.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void TOUCHBAR_Delete(void *a);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void func_02082BCC(void *p, u32 a, u32 b);

void OPTION_MENU_ExitButtons(u8 *p)
{
    int i;

    TOUCHBAR_Delete(((struct Obj20641 *)p)->f8);
    for (i = 0; i < 2; i++) {
        STRBUF_Delete((struct U16Vec *)(*(u32 *)(p + i * 0xc + 0x1c)));
        APP_TASKMENU_WIN_Delete((u8 *)(*(u32 *)(p + i * 4 + 0x34)));
    }
    func_02082BCC(p, 0, 0x44);
}
