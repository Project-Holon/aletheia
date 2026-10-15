/*
 * function: func_021BE61C
 * address: 0x021BE61C
 * packet: pkt_ov204_021BE61C
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   INTRO_MSG_PrintText 0x021BF23C thumb ov204
 *   INTRO_MSG_UpdatePrint 0x021BF2F4 thumb ov204
 *   INTRO_G3D_SetSlotMepachi 0x021BF7CC thumb ov204
 *   INTRO_MSG_GetPrintState 0x021BF2E0 thumb ov204
 */
#include "../include/Obj05529.h"
extern void INTRO_MSG_PrintText(char *p, void *a, int flag);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int INTRO_MSG_UpdatePrint(char *a);
extern void INTRO_G3D_SetSlotMepachi(u8 *p, u8 index, int flag);
extern u32 INTRO_MSG_GetPrintState(u8 *p);
int func_021BE61C(char *p, int *state, unsigned *q)
{
    unsigned index = q[0];
    unsigned other = q[1];
    switch (*state) {
    case 0:
        INTRO_MSG_PrintText(((struct Obj05529 *)p)->f18, (void *)index, q[2]);
        ++*state;
        break;
    case 1:
        if (INTRO_MSG_UpdatePrint(((struct Obj05529 *)p)->f18) != 0) {
            INTRO_G3D_SetSlotMepachi(((struct Obj05529 *)p)->f8, other, 1);
            return 1;
        }
        switch (INTRO_MSG_GetPrintState(((struct Obj05529 *)p)->f18)) {
        case 1:
            INTRO_G3D_SetSlotMepachi(((struct Obj05529 *)p)->f8, other, 1);
            state[1] = 0;
            break;
        case 0:
            INTRO_G3D_SetSlotMepachi(((struct Obj05529 *)p)->f8, other, state[1] % 12 < 6 ? 1 : 0);
            state[1]++;
            break;
        case 2:
            break;
        }
        break;
    }
    return 0;
}
