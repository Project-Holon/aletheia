/*
 * function: func_02163D04
 * address:  0x02163D04
 * packet:   pkt_ov010_02163D04
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Whether an object of `kind` may stand on the w x h cells from pos: any
 * missing or blocked cell refuses, then the kind's two attribute tests
 * (tables d_021714A0 and d_02171490) on the origin and the first cell.
 * Size-exact, 6 bytes out: the per-row `cur = row` copy runs its ldm
 * through r3 and stm through r2 where the image has them the other way
 * (a block-scope `cur` and swapped declarations are flat). Levers so far:
 * the refusal as the outer if with `return 1` last, the step expressions
 * in the for headers, the table call's argument in a local, `found`
 * declared first. Permuter seed 9605 (anneal 500) found nothing below 6.
 *
 * symbols:
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 *   func_0216D91C  0x0216D91C  thumb  ov010
 *   func_0216D924  0x0216D924  thumb  ov010
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   d_021714A0     0x021714A0  data
 *   d_02171490     0x02171490  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef int (*AttrTest)(u16 attr);

extern int func_0216DCB4(void *m);
extern u32 func_0216D91C(void *m);
extern u32 func_0216D924(void *m);
extern int func_02163E34(void *m, const VecFx32 *pos, u32 *attr);
extern int func_021AB11C(u32 attr);
extern u32 func_0216D7DC(void *m);
extern u16 func_021AB0F0(u32 attr);
extern const AttrTest d_021714A0[];
extern const AttrTest d_02171490[];

int func_02163D04(void *m, u32 kind, VecFx32 pos)
{
    int found;
    VecFx32 row;
    VecFx32 cur;
    u32 attr;
    u32 first;
    u8 i;
    u32 h;
    u8 j;
    u32 w;
    u16 a;

    if (func_0216DCB4(m) == 0) {
        found = 0;
        w = func_0216D91C(m);
        h = func_0216D924(m);
        row = pos;
        for (i = 0; i < h; i++, row.z -= 0x10000) {
            cur = row;
            for (j = 0; j < w; j++, cur.x += 0x10000) {
                if (func_02163E34(m, &cur, &attr) == 0)
                    return 1;
                if (func_021AB11C(attr) == 1)
                    return 1;
                if (found == 0) {
                    first = attr;
                    found = 1;
                }
            }
        }
        a = func_021AB0F0(func_0216D7DC(m));
        if (d_021714A0[kind](a) == 1)
            return 1;
        if (d_02171490[kind](func_021AB0F0(first)) == 1)
            return 1;
        return 0;
    }
    return 1;
}
