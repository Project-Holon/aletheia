/*
 * function: func_021DCDB8
 * address:  0x021DCDB8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Allocate 76 bytes, keep the handle, then configure it.
 */

extern int func_02021518(int);
extern void func_0202155C(int, int, int, int);

void func_021DCDB8(char *p)
{
    int v = func_02021518(0x4c);

    *(int *)(*(char **)(p + 0x2c) + 0x6c) = v;
    func_0202155C(*(int *)(*(char **)(p + 0x2c) + 0x6c), 0, 0x200, 0x4c);
}

