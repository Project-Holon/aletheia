/*
 * function: func_021A4F58
 * address:  0x021A4F58
 * packet:   pkt_ov021_021A4F58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The function returns int: v.y when the height is already at or under the
 * limit, 7 (the new state) otherwise. The only caller (func_021A4CF4, case 9)
 * discards the value. Returning v.y on the early path ties the cross-block
 * v.y value to r0 (the return register), so the block-2 constant 0x8000 goes
 * to r1 and the subtract reads `subs r0, r0, r1`; the void form colours the
 * constant first into r0 and gives `subs r0, r1, r0` (three earlier rounds,
 * dozens of spellings). Leaving the final `return 7` out recolours the 7 to r1.
 * See docs/idioms/a-value-returned-on-the-early-path-precolours-its-register-to-r0.md.
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 */
#include "../include/Obj00262.h"

typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A4F58;

void *func_021A3960(unsigned char *p);
struct Actor;
struct VecFx32;
void func_0216D88C(const struct Actor *h, struct VecFx32 *v);
void func_02163E58(void *h, Vec021A4F58 *v, int *lim);
char *func_0216D570(char *p, u32 v);
void func_0216D89C(void *h, Vec021A4F58 *v);

int func_021A4F58(u32 *p, void *a1, u32 a2)
{
    void *h = func_021A3960(*(unsigned char * *)&((struct Obj00262 *)p)->fC);
    Vec021A4F58 v;
    int lim;

    func_0216D88C(h, (struct VecFx32 *)&v);
    func_02163E58(h, &v, &lim);
    if (v.y > lim) {
        v.y -= 0x8000;
        if (v.y < lim) {
            v.y = lim;
            func_0216D570(h, 0x8000);
            p[7] = 1;
        }
        func_0216D89C(h, &v);
        p[0] = 7;
        return 7;
    }
    return v.y;
}
