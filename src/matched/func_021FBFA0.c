/*
 * function: func_021FBFA0
 * address:  0x021FBFA0
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FBFA0   0x021FBFA0  thumb
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_02200140 0x02200140 thumb ov094

 *
 * lane O10 candidate
 */

extern int  func_021F8694(void);
extern void func_02200140(int a, int b, int c);

int func_021FBFA0(int a, char *b)
{
    func_02200140(func_021F8694(), *(int *)(b + 0xe0), *(int *)(b + 0xdc));
    return *(int *)(b + 0x23c);
}

