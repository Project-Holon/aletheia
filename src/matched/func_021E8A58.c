/*
 * function: func_021E8A58
 * address:  0x021E8A58
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE008  0x021EE008  thumb  ov170
 *
 * Restart the sequence counter one below the queue length and
 *   return 0x61.
 */


extern int func_020260E0(int);
extern void func_021EE008(char *, int, int);
int func_021E8A58(char *p)
{
    func_021EE008(p, func_020260E0(*(int *)(*(int *)(p + 0x2c) + 0x70)) - 1, 1);
    return 0x61;
}
