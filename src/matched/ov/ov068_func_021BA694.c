/*
 * function: func_021BA694
 * address:  0x021BA694
 * packet:   pkt_021BA694
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   APP_TASKMENU_WIN_ResetDecide  0x020282A4  thumb
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
extern void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);

void func_021BA694(u8 *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        APP_TASKMENU_WIN_ResetDecide((struct Obj *)(*(u32 *)(p + i * 4 + 0x34)));
        APP_TASKMENU_WIN_SetActive((struct Obj *)(*(u32 *)(p + i * 4 + 0x34)), 0);
    }
}
