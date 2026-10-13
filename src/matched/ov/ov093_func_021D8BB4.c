/*
 * function: HAND_TOKUSEI_SpeedBoostOnTurnEnd
 * address:  0x021D8BB4
 * packet:   pkt_ov093_021D8BB4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_SpeedBoostOnTurnEnd(int u, int a, int k)
{
    u32 *r;

    if (k == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam((int *)a, k), 0) != 0) {
            r = BTL_SERVER_FLOW_AllocCmdRecord((void *)a, 14, k);
            r[0] |= 2 << 22;
            r[1] = 5;
            ((u8 *)r)[0xf] = 1;
            ((u8 *)r)[0x10] = k;
            ((u8 *)r)[0xc] = 1;
            BTL_SERVER_FLOW_CommitCmdRecord((void *)a, r);
        }
    }
}
