/*
 * function: func_02207B68
 * address:  0x02207B68
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02207B68   0x02207B68  thumb
 *   func_02207DA0 0x02207DA0 thumb ov094

 *
 * lane O10 candidate
 */

extern void func_02207DA0(char *dst, char *src);

void func_02207B68(char *p, int i)
{
    func_02207DA0(p, p + 0x40 + (i << 7));
    *(int *)(p + (i << 7) + 0xb4) = 0;
}

