/*
 * function: BTL_ABILITY_FlowerGiftRevertFormOnFactorChange
 * address:  0x021D8F84
 * packet:   pkt_ov093_021D8F84
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_ABILITY_IsCherrim  0x021D8E00  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_ABILITY_ChangeCherrimForm  0x021D8E7C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_ABILITY_IsCherrim(void *a, int b);
extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_ABILITY_ChangeCherrimForm(int u, void *a, u32 b, u32 c, u8 d);

void BTL_ABILITY_FlowerGiftRevertFormOnFactorChange(int u, int a, int b, int *p)
{
    int t;

    if (*p != 0 && BTL_ABILITY_IsCherrim((void *)a, b) != 0) {
        if (b == BTL_EVENT_GetVar(2)) {
            t = BTL_EVENT_GetVar(0x10);
            if (t != BTL_EVENT_GetFactorKey((void *)u))
                BTL_ABILITY_ChangeCherrimForm(u, (void *)a, b, 0, 0);
        }
    }
}
