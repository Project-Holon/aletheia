/*
 * function: func_021ED55C
 * address:  0x021ED55C
 * packet:   pkt_ov170_021ED55C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020260F0 0x020260F0 thumb
 *   func_021EC000 0x021EC000 thumb
 */

extern int func_020260F0(void *);
extern void func_021EC000(char *p, int i, int v);

void func_021ED55C(char **p, int flag)
{
    if (flag == 1) {
        if (func_020260F0(*(void **)(p[11] + 0x70)) == 1)
            func_021EC000(p[11], 4, 1);
    } else {
        func_021EC000(p[11], 4, 0);
    }
}
