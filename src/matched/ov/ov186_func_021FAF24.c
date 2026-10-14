/*
 * function: func_021FAF24
 * address: 0x021FAF24
 * packet: pkt_ov186_021FAF24
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_BTN_DATA_GetRowField 0x021FB7B0 thumb ov186
 *   func_02034714 0x02034714 arm
 *   d_02200D18 0x02200D18 data a1
 */
#include "../include/Obj02900.h"
extern int BR_BTN_DATA_GetRowField(void *p, int i);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern char d_02200D18[];
int func_021FAF24(char *ctx, int kind)
{
    int result;
    switch (kind) {
    case 0: result = BR_BTN_DATA_GetRowField((void *)(((struct Obj02900 *)ctx)->fC), 5); break;
    case 1: result = BR_BTN_DATA_GetRowField((void *)(((struct Obj02900 *)ctx)->fC), 6); break;
    case 2: result = BR_BTN_DATA_GetRowField((void *)(((struct Obj02900 *)ctx)->fC), 7); break;
    case 5: result = BR_BTN_DATA_GetRowField((void *)(((struct Obj02900 *)ctx)->fC), 9); break;
    case 6: result = BR_BTN_DATA_GetRowField((void *)(((struct Obj02900 *)ctx)->fC), 10); break;
    case 3: result = BR_BTN_DATA_GetRowField((void *)(((struct Obj02900 *)ctx)->fC), 8); break;
    case 4: result = BR_BTN_DATA_GetRowField((void *)(((struct Obj02900 *)ctx)->fC), 2); break;
    case 7: result = BR_BTN_DATA_GetRowField((void *)(((struct Obj02900 *)ctx)->fC), 11); break;
    case 8: result = BR_BTN_DATA_GetRowField((void *)(((struct Obj02900 *)ctx)->fC), 0); break;
    case 9: result = BR_BTN_DATA_GetRowField((void *)(((struct Obj02900 *)ctx)->fC), 1); break;
    default: result = 0; func_02034714(d_02200D18, 0, d_02200D18); break;
    }
    return result;
}
