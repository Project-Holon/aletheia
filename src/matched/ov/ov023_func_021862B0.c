/*
 * function: func_021862B0
 * address:  0x021862B0
 * packet:   pkt_ov023_021862B0
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201CE30  0x0201CE30  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 */

extern int func_0201CE30(void *h);
extern int func_020362DC(void);
extern void func_0201CE38(void *h);
extern void func_0201CE48(void *h);

int func_021862B0(char *p)
{
    int r = func_0201CE30(*(void **)(p + 0x16C));

    if (r == 1) {
        if (func_020362DC() & 1) {
            func_0201CE38(*(void **)(p + 0x16C));
        }
        return 0;
    }
    if (r == 2) {
        func_0201CE48(*(void **)(p + 0x16C));
        *(void **)(p + 0x16C) = 0;
        return 1;
    }
    return *(void **)(p + 0x16C) == 0;
}
