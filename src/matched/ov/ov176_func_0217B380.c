/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_SelectMenuPhase
 * address:  0x0217B380
 * packet:   pkt_ov176_0217B380
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8AA0  0x021E8AA0  thumb  ov177
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuMain  0x0217B3C0  thumb  ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse  0x0217B4A0  thumb  ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_MenuExtra  0x0217B6AC  thumb  ov176
 */
#include "../include/Obj24404.h"

extern void func_021E8AA0(int *p, int v);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuMain(int p, unsigned *state, int *q);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse(int p, unsigned *state, int *q);
extern void BATTLE_CHAMPIONSHIP_FLOW_MenuExtra(int p, unsigned *state, int *q);

void BATTLE_CHAMPIONSHIP_FLOW_SelectMenuPhase(int a, int b, int *p)
{
    switch (((struct Obj24404 *)p)->f14) {
    case 0:
        func_021E8AA0((int *)a, (int)BATTLE_CHAMPIONSHIP_FLOW_MenuMain);
        break;
    case 1:
        func_021E8AA0((int *)a, (int)BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse);
        break;
    case 2:
        func_021E8AA0((int *)a, (int)BATTLE_CHAMPIONSHIP_FLOW_MenuExtra);
        break;
    }
}