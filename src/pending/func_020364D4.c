/*
 * unit:     no
 * function: func_020364D4
 * address:  0x020364D4
 * packet:   pkt_020363B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  02036568 has no witness outside this range
 */

extern int func_02036568(void *p);
extern int func_02036624(void *p, int v);
int func_020364D4(char *p)
{
    int d = func_02036568(p);
    *(short *)(p + 0xc) = (short)func_02036624(p, *(short *)(p + 0xc) + d);
    return d;
}
