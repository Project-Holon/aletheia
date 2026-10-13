/*
 * unit:     yes
 * function: HAND_WAZA_StoredPowerAddPowerPerStage, HAND_WAZA_AddHeavySlam
 * address:  0x021E7080
 * packet:   pkt_ov093_021E7080
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the bonus is a compound add onto the fetched value
 *           (`t = get(0x30); t += sum * 0x14; set(0x30, t);`): it copies sum
 *           into r1 and multiplies by 0x14 held in r0 like the image; every
 *           single-expression spelling (`t + sum * 0x14`, an inline helper,
 *           a narrow or enum multiplier local) multiplies in the constant's
 *           register and is 4 bytes short.  HAND_WAZA_AddHeavySlam is the unlabelled
 *           12-byte store-and-return leaf after the pool (twin of
 *           ov093_func_021E7164.c's HAND_WAZA_AddEchoedVoice).
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F2404     0x021F2404  data  ov093  a1
 *   d_021F2654     0x021F2654  data  ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern const u8 d_021F2404[7];
extern int d_021F2654[];

void HAND_WAZA_StoredPowerAddPowerPerStage(int x, int a, int c)
{
    void *m;
    int sum;
    u32 i;
    int v;
    int t;

    if (c == BTL_EVENT_GetVar(3)) {
        m = BTL_SERVER_FLOW_GetPokeParam((int *)a, c);
        sum = 0;
        for (i = 0; i < 7; i++) {
            v = func_021D59B4(m, d_021F2404[i]) - 6;
            if (v > 0) {
                sum += v;
            }
        }
        if (sum != 0) {
            t = BTL_EVENT_GetVar(0x30);
            t += sum * 0x14;
            BTL_EVENT_OverwriteVar(0x30, t);
        }
    }
}

int *HAND_WAZA_AddHeavySlam(int *p)
{
    *p = 1;
    return d_021F2654;
}
