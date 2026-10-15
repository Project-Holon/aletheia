/*
 * function: BTLV_CORE_StartMoveMenuForEntry
 * address:  0x021E9808
 * packet:   pkt_ov093_021E9808
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BOX2_SEQ_StatePmVoiceMenuD  0x021E9848  thumb  ov093
 *   BTLV_CORE_SetStep  0x021E9728  thumb  ov093
 *   BTLV_CORE_StepMoveMenu  0x021E9884  thumb  ov093
 */
#include "../include/Obj06281.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BOX2_SEQ_StatePmVoiceMenuD(void *a, u32 *b, int c);
struct QU;
extern void BTLV_CORE_SetStep(struct QU *p, u32 v);
extern int BTLV_CORE_StepMoveMenu(char *p);

void BTLV_CORE_StartMoveMenuForEntry(char *p, u32 *q, int c)
{
    u32 v = *q;

    ((struct Obj06281 *)p)->fBC = v;
    ((struct Obj06281 *)p)->fC0 = BTL_POKEPARAM_GetPokeId((u8 *)v);
    *(u32 * *)&((struct Obj06281 *)p)->f170 = q;
    ((struct Obj06281 *)p)->fB8 = c;
    BOX2_SEQ_StatePmVoiceMenuD(((struct Obj06281 *)p)->f180, q, c);
    BTLV_CORE_SetStep((struct QU *)p, (u32)BTLV_CORE_StepMoveMenu);
}
