/*
 * function: BTL_MAIN_StepClientsSolo
 * address:  0x021B83F4
 * packet:   pkt_ov093_021B83F4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_Update  0x021BAB9C  thumb  ov093
 *   BTL_CLIENT_RunTick  0x021CD97C  thumb  ov093
 *   BTL_CLIENT_GetCursor  0x021CDD94  thumb  ov093
 *   func_021E908C  0x021E908C  thumb  ov093
 */
#include "../include/Obj13269.h"

extern int BTL_SERVER_Update(int a);
extern int BTL_CLIENT_RunTick(int);
extern void BTL_CLIENT_GetCursor(char *p, int *o);
extern void func_021E908C(char *p);

int BTL_MAIN_StepClientsSolo(int a)
{
    int i, found = 0;
    char *p = (char *)a;
    BTL_SERVER_Update(((struct Obj13269 *)p)->f8);
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x10) != 0 &&
            BTL_CLIENT_RunTick(*(int *)(p + i * 4 + 0x10)) != 0) {
            BTL_CLIENT_GetCursor((char *)(*(int *)(p + i * 4 + 0x10)), (int *)((int)(p + 0x448)));
            found = 1;
        }
    }
    func_021E908C((char *)(((struct Obj13269 *)p)->f4));
    return found;
}
