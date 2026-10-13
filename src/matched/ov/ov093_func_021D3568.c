/*
 * function: BTL_CLIENT_CmdSwapViewPositions
 * address:  0x021D3568
 * packet:   pkt_ov093_021D3568
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   func_021EA3E8  0x021EA3E8  thumb  ov093
 *   func_021EA3F8  0x021EA3F8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern void func_021EA3E8(void *ctx, int a, int b, u32 c);
extern int func_021EA3F8(int a);

int BTL_CLIENT_CmdSwapViewPositions(u32 *a, int *b, u32 *c)
{
    int x;
    int y;

    if (*b == 0) {
        if (BTL_CLIENT_IsMainStepActive((u8 *)a) != 0) {
            return 1;
        }
        x = BTL_MAIN_GetViewPosOfSlot((u8 *)a[0], (u8)c[0]);
        y = BTL_MAIN_GetViewPosOfSlot((u8 *)a[0], (u8)c[1]);
        func_021EA3E8((void *)a[0x15], x, y, (u16)c[2]);
        (*b)++;
    } else {
        if (func_021EA3F8(a[0x15]) != 0) {
            return 1;
        }
    }
    return 0;
}
