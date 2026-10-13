/*
 * function: BTLV_GAUGE_StartHpChangeInstant
 * address:  0x02207B68
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_GAUGE_StartHpChangeInstant   0x02207B68  thumb
 *   BTLV_GAUGE_StartHpChange 0x02207DA0 thumb ov094

 *
 * lane O10 candidate
 */

struct S;
extern void BTLV_GAUGE_StartHpChange(void *obj, struct S *q, int n);

void BTLV_GAUGE_StartHpChangeInstant(char *p, int i, int n)
{
    BTLV_GAUGE_StartHpChange(p, (struct S *)(p + 0x40 + (i << 7)), n);
    *(int *)(p + (i << 7) + 0xb4) = 0;
}

