/*
 * function: func_0203A748
 * address:  0x0203A748
 * packet:   pkt_0203A748
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203A67C  0x0203A67C  arm
 */

typedef unsigned int u32;

extern int *func_0203A67C(void);

int func_0203A748(u32 idx)
{
    int *p = func_0203A67C();
    if (p != 0) {
        char *base = (char *)*p;
        u32 off = ((idx << 24) >> 21);
        return *(int *)(base + off + 4);
    }
    return 0;
}
