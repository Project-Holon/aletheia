/*
 * function: func_02206A58
 * address:  0x02206A58
 * packet:   pkt_ov094_02206A58
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F86E0  0x021F86E0  thumb  ov094
 */

typedef unsigned short u16;
extern int func_021F86E0(void);
extern void func_020215BC(int a, u16 *b, int c, int d, u16 e);

void func_02206A58(char *p)
{
    if (*(int *)(p + 0x23c) == 1)
        func_020215BC(func_021F86E0(), (u16 *)(p + 0x284), 1, 0x20, 0x20);
}
