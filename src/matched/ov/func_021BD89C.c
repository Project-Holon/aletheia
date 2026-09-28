/*
 * function: func_021BD89C
 * address:  0x021BD89C
 * packet:   pkt_021BD89C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD868 0x021BD868  thumb  ov208
 *   func_021BD848 0x021BD848  thumb  ov208

 * Swaps in the cleared state flag and frees the handle at +0x30.
 */


extern int func_021BD868(char *);
extern void func_021BD848(char *, int);
extern void func_020061E4(int);

void func_021BD89C(char *p)
{
    int f = func_021BD868(p) == 0;

    func_021BD848(p, f);
    if (*(int *)(p + 0x30) != 0)
        func_020061E4(*(int *)(p + 0x30));
}

