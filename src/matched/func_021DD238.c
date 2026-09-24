/*
 * function: func_021DD238
 * address:  0x021DD238
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020355D8  0x020355D8  arm  arm9
 *
 * Enable the pooled object when it reports zero.
 */

extern void func_020355D8(int);
extern int func_020260F0(void *);
extern void func_020260F4(void *, int);

void func_021DD238(char *p)
{
    func_020355D8(0);
    if (func_020260F0(*(void **)(*(char **)(p + 0x2c) + 0x70)) == 0)
        func_020260F4(*(void **)(*(char **)(p + 0x2c) + 0x70), 1);
}

