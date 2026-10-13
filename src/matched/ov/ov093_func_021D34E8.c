/*
 * function: BTL_CLIENT_StepPlayMonSimpleEffect
 * address:  0x021D34E8
 * packet:   pkt_ov093_021D34E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTL_MAIN_CheckSceneOff  0x021B8590  thumb  ov093
 *   func_021D3558  0x021D3558  thumb
 *   BTLV_CORE_StartViewEffect  0x021EA3B8  thumb  ov093
 *   BTLV_CORE_WaitViewEffect  0x021EA3D4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern unsigned int BTL_MAIN_CheckSceneOff(unsigned char *p);
extern int func_021D3558(u16 v);
extern void BTLV_CORE_StartViewEffect(char *ctx, int a, int b);
extern int BTLV_CORE_WaitViewEffect(u32 a);

int BTL_CLIENT_StepPlayMonSimpleEffect(u32 *a, int *b, u32 *c)
{
    u8 k;

    k = BTL_MAIN_GetViewPosOfSlot((u8 *)a[0], (u8)c[0]);
    if (*b == 0) {
        if (BTL_CLIENT_IsMainStepActive((u8 *)a) != 0) {
            return 1;
        }
        if (BTL_MAIN_CheckSceneOff((unsigned char *)a[0]) == 0) {
            if (func_021D3558((u16)c[1]) != 0) {
                return 1;
            }
        }
        BTLV_CORE_StartViewEffect((char *)a[0x15], k, (u16)c[1]);
        (*b)++;
    } else {
        if (BTLV_CORE_WaitViewEffect(a[0x15]) != 0) {
            return 1;
        }
    }
    return 0;
}
