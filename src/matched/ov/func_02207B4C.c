/*
 * function: func_02207B4C
 * address:  0x02207B4C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02207B4C   0x02207B4C  thumb
 *   func_02207DA0 0x02207DA0 thumb ov094

 *
 * lane O10 candidate
 */

struct S;
extern void func_02207DA0(void *obj, struct S *q, int n);

void func_02207B4C(char *p, int i, int n)
{
    func_02207DA0(p, (struct S *)(p + 0x40 + (i << 7)), n);
    *(int *)(p + (i << 7) + 0xb4) = 1;
}

