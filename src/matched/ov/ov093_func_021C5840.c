/*
 * function: func_021C5840
 * address: 0x021C5840
 * packet: pkt_ov093_021C5840
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
void func_021C5840(u8 *p, u32 count, int *v, u8 **a, int flag)
{
    u8 low = 0;
    u8 high = 0;
    u32 i;
    u8 list[3];
    for (i = 0; i < count; i++) {
        if (v[i] > 3) high++;
        if (v[i] < 3) low++;
    }
    if (flag) {
        if (high) {
            u8 n = 0;
            for (i = 0; i < count; i++) {
                if (v[i] > 3) list[n++] = BTL_POKEPARAM_GetPokeId(a[i]);
            }
            switch (high) {
            case 1: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 6, list[0], 0xffff0000); break;
            case 2: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 9, list[0], list[1], 0xffff0000); break;
            case 3: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 12, list[0], list[1], list[2], 0xffff0000); break;
            }
        }
        if (low) {
            u8 n;
            i = 0;
            n = 0;
            for (; i < count; i++) {
                if (v[i] < 3) list[n++] = BTL_POKEPARAM_GetPokeId(a[i]);
            }
            switch (low) {
            case 1: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 15, list[0], 0xffff0000); break;
            case 2: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 18, list[0], list[1], 0xffff0000); break;
            case 3: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 21, list[0], list[1], list[2], 0xffff0000); break;
            }
        }
    } else {
        if (high) BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, 78, 0xffff0000);
        else if (low) BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, 79, 0xffff0000);
    }
}
