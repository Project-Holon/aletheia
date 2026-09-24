/*
 * function: func_021FA108
 * address:  0x021FA108
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FA108   0x021FA108  thumb
 *   func_021F8684 0x021F8684 thumb ov094
 *   func_021F70F0 0x021F70F0 thumb ov094

 *
 * lane O10 candidate
 */

extern int  func_021F8684(void);
extern void func_021F70F0(int a, char *b, char *c);

int func_021FA108(int a, char *b)
{
    *(int *)(b + 0x284) = 1;
    func_021F70F0(func_021F8684(), b + 0x288, b + 0x294);
    return *(int *)(b + 0x23c);
}

