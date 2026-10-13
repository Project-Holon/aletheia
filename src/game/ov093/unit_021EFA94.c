/*
 * file:     unit_021EFA94.c
 * function: func_021EFA94
 * address:  0x021EFA94
 * packet:   pkt_ov093_021EFA94
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 *
 * symbols:
 *   func_06898080  0x06898080  thumb
 *   func_021EFCE4  0x021EFCE4  thumb  ov093
 *   BTL_FIELD_ResetSlot  0x021EF83C  thumb  ov093
 */

typedef unsigned int u32;

extern void *func_021EFCE4(char *a, int b);
extern void func_06898080(u32 h);
extern void BTL_FIELD_ResetSlot(char *a, u32 b);

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
} S;

int func_021EFA94(S *a, u32 b)
{
    if (func_021EFCE4((char *)a, b) != 0) {
        if (a->t[b] != 0) {
            func_06898080(a->t[b]);
            a->t[b] = 0;
        }
        BTL_FIELD_ResetSlot((char *)a, b);
        return 1;
    }
    return 0;
}
