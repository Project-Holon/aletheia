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
 *
 * symbols:
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb  arm9
 */

extern int func_0200F300(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);

void func_02208D24(int a)
{
    if (func_0200F300() != 1)
        GFL_USE_SetBgmPlayerParam((void *)a);
}
