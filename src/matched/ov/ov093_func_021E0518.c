/*
 * function: HAND_WAZA_CamouflageChangeType
 * address:  0x021E0518
 * packet:   pkt_ov093_021E0518
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetFieldSituationType  0x021C8174  thumb  ov093
 *   BTLV_CORE_PackByteTwice  0x021E8CF0  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13504.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_GetFieldSituationType(int *p);
extern u16 BTLV_CORE_PackByteTwice(int c);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetTypePair(void *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_CamouflageChangeType(int a, int *b, int c)
{
    int t;
    u16 v;
    char *p;

    if (c == BTL_EVENT_GetVar(3)) {
        switch (BTL_SERVER_FLOW_GetFieldSituationType(b)) {
        case 1: case 2: case 3: case 8: case 9: case 15:
            t = 4;
            break;
        case 4: case 14:
        default:
            t = 0;
            break;
        case 10:
            t = 5;
            break;
        case 0: case 5:
            t = 0xb;
            break;
        case 6: case 11: case 12:
            t = 0xa;
            break;
        case 7: case 13:
            t = 0xe;
            break;
        }
        v = BTLV_CORE_PackByteTwice(t);
        if (v != BTL_POKEPARAM_GetTypePair(BTL_SERVER_FLOW_GetPokeParam(b, c))) {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x14, c);
            ((struct Obj13504 *)p)->f4 = v;
            ((struct Obj13504 *)p)->f6 = c;
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        }
    }
}
