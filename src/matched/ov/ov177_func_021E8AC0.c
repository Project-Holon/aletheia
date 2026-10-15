/*
 * function: WIFIBATTLEMATCH_UTIL_SetSaveState
 * address:  0x021E8AC0
 * packet:   pkt_021E8AC0
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_02008DF0  0x02008DF0  thumb
 */

typedef unsigned int   u32;
struct Big;
struct Sub02008C20Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);

void WIFIBATTLEMATCH_UTIL_SetSaveState(int a, int b)
{
    int x;

    x = (int)func_02008C58(GAME_DATA_GetSaveControl((struct Big *)a));
    switch (b) {
    case 1:
    case 4:
        func_02008DF0((struct Sub02008C20Obj *)x, 0x12);
        break;
    case 0:
    case 3:
        func_02008DF0((struct Sub02008C20Obj *)x, 0x13);
        break;
    case 2:
        func_02008DF0((struct Sub02008C20Obj *)x, 0x14);
        break;
    }
    func_02008DF0((struct Sub02008C20Obj *)x, 0x11);
}
