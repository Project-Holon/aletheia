/*
 * function: func_02208D24
 * address:  0x02208D24
 * packet:   pkt_ov094_02208D24
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern int func_0200F300(void);
extern void func_02005DE4(void *p);

void func_02208D24(int a)
{
    if (func_0200F300() != 1)
        func_02005DE4((void *)a);
}
