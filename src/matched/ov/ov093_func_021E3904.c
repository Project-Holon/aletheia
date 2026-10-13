/*
 * function: HAND_WAZA_MagnitudeOnWazaStart
 * address:  0x021E3904
 * packet:   pkt_ov093_021E3904
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gMagnitudeRows  0x021F2878  data   a1
 *   gMagnitudeRowsPower  0x021F2879  data   a1
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern u32 BTL_CALC_Random(u32 range);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern u8 gMagnitudeRows[];
extern u8 gMagnitudeRowsPower[];

void HAND_WAZA_MagnitudeOnWazaStart(int u, void *p, int key, int *o)
{
    u8 i;
    u8 v;
    u8 *q;
    if (key == BTL_EVENT_GetVar(2)) {
        v = BTL_CALC_Random(100);
        for (i = 0; i < 7; i++) {
            if (v < gMagnitudeRows[i * 2])
                break;
        }
        *o = gMagnitudeRowsPower[i * 2];
        q = BTL_SERVER_FLOW_AllocCmdRecord(p, 4, key);
        BTL_SERVER_FLOW_InitMsgRecord(q + 4, 1, (u16)(i + 0x68));
        BTL_SERVER_FLOW_CommitCmdRecord(p, q);
    }
}
