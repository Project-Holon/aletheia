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

extern int func_020124E4();
extern u32 func_0201210C(u32);
extern u32 func_0204E720(u32, u32, u32, u32);
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
