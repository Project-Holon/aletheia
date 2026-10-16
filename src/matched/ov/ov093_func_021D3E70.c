/*
 * function: BTL_CLIENT_IsStatItemUsable
 * address:  0x021D3E70
 * packet:   pkt_ov093_021D3E70
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlClientItemStatChecks  0x021EFF94  data  ov093  a1
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 *   BTL_POKEPARAM_CanChangeStatStage  0x021D5D14  thumb  ov093
 *   BTL_POKEPARAM_GetCritStage  0x021D5F14  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 a;
    u8 b;
} Pair;

extern Pair gBtlClientItemStatChecks[];
typedef signed char    s8;
struct UtilWork;
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern int BTL_POKEPARAM_CanChangeStatStage(s8 *p, int i, int sign);
extern u8 BTL_POKEPARAM_GetCritStage(struct UtilWork *p);

int BTL_CLIENT_IsStatItemUsable(void *s, void *m)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (BTL_CALC_GetMonParamWithHeap(s, gBtlClientItemStatChecks[i].a) != 0 && BTL_POKEPARAM_CanChangeStatStage(m, gBtlClientItemStatChecks[i].b, 1) != 0)
            return 1;
    }
    if (BTL_CALC_GetMonParamWithHeap(s, 0x24) != 0 && BTL_POKEPARAM_GetCritStage(m) == 0)
        return 1;
    return 0;
}
