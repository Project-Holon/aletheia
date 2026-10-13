/*
 * function: BTL_SERVER_CompareFlowOutput
 * address:  0x021BB570
 * packet:   pkt_ov093_021BB570
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_RunBattleStart  0x021BBB60  thumb  ov093
 *   BTL_SERVER_FLOW_ResetInitState  0x021BBC34  thumb  ov093
 *   BTL_SERVER_FLOW_StartTurn  0x021BBC44  thumb  ov093
 *   BTL_SERVER_FLOW_ResetInitStateAfterChange  0x021BBD80  thumb  ov093
 *   BTL_SERVER_FLOW_StartAfterPokeChange  0x021BBD8C  thumb  ov093
 *   BTL_SERVER_FLOW_ResetInitStateAfterSelect  0x021BBD20  thumb  ov093
 *   BTL_SERVER_FLOW_StartAfterPokeSelect  0x021BBD2C  thumb  ov093
 *   func_0203EFC8  0x0203EFC8  arm
 */
#include "../include/Obj03190.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_SERVER_FLOW_RunBattleStart(u8 *);
extern void BTL_SERVER_FLOW_ResetInitState(u8 *);
extern int BTL_SERVER_FLOW_StartTurn(u8 *, int);
extern void BTL_SERVER_FLOW_ResetInitStateAfterChange(u8 *);
extern int BTL_SERVER_FLOW_StartAfterPokeChange(u8 *, int);
extern void BTL_SERVER_FLOW_ResetInitStateAfterSelect(u8 *);
extern int BTL_SERVER_FLOW_StartAfterPokeSelect(u8 *, int);
typedef signed int     s32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);

int BTL_SERVER_CompareFlowOutput(u8 *p, int sel, void *data, u32 n)
{
    u32 *s = *(u32 * *)&((struct Obj03190 *)p)->fCB0;

    s[0] = 0;
    s[1] = 0;
    switch (sel) {
    case 4:
        BTL_SERVER_FLOW_RunBattleStart(*(u8 * *)&((struct Obj03190 *)p)->f44);
        break;
    case 1:
        BTL_SERVER_FLOW_ResetInitState(*(u8 * *)&((struct Obj03190 *)p)->f44);
        BTL_SERVER_FLOW_StartTurn(*(u8 * *)&((struct Obj03190 *)p)->f44, (int)(p + 0xb4));
        break;
    case 2:
        BTL_SERVER_FLOW_ResetInitStateAfterChange(*(u8 * *)&((struct Obj03190 *)p)->f44);
        BTL_SERVER_FLOW_StartAfterPokeChange(*(u8 * *)&((struct Obj03190 *)p)->f44, (int)(p + 0xb4));
        break;
    case 3:
        BTL_SERVER_FLOW_ResetInitStateAfterSelect(*(u8 * *)&((struct Obj03190 *)p)->f44);
        BTL_SERVER_FLOW_StartAfterPokeSelect(*(u8 * *)&((struct Obj03190 *)p)->f44, (int)(p + 0xb4));
        break;
    }
    s = *(u32 * *)&((struct Obj03190 *)p)->fCB0;
    if (s[0] == n && func_0203EFC8((const u8 *)(s + 2), data, n) == 0)
        return 0;
    return 1;
}
