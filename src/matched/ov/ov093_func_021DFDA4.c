/*
 * function: func_021DFDA4
 * address:  0x021DFDA4
 * packet:   pkt_ov093_021DFDA4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   BTL_HANDLER_ITEM_PushUseItem  0x021DD044  thumb  ov093
 */
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
typedef signed char    s8;
extern int func_021D5D14(s8 *p, int i, int sign);
extern void BTL_HANDLER_ITEM_PushUseItem(void *a, void *b, int c);

void func_021DFDA4(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(0x46) == 0 && BTL_EVENT_GetVar(0x16) == 0xc) {
        if (func_021D5D14(func_021C7CF4((int *)b, c), 1, 1) != 0) {
            BTL_HANDLER_ITEM_PushUseItem((void *)a, (void *)b, c);
        }
    }
}
