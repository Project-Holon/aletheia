/*
 * function: func_021C2B5C
 * address:  0x021C2B5C
 * packet:   pkt_ov021_021C2B5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fade-out state step: start the fade, then wait for it to finish.
 */

typedef unsigned int u32;

struct Obj;
struct Ctx;

extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
typedef signed int     s32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);

int func_021C2B5C(void *t, int *st)
{
    func_0201210C(func_020124E4(t));
    switch (*st) {
    case 0:
        func_0204E720(4, 0x10, 0, -1);
        (*st)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}
