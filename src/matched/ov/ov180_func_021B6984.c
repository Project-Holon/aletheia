/*
 * function: func_021B6984
 * address:  0x021B6984
 * packet:   pkt_ov180_021B6984
 * region:   ov180
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 2026-10-05: the callee MCSS_Del takes a second argument (r1 = the field value tested); the caller passes it.
 *
 * symbols:
 *   MCSS_Del  0x02015BA4  thumb
 */

extern void MCSS_Del(void *sys, void *obj);

void func_021B6984(char *p)
{
    int v = *(int *)(p + 0x1c);

    if (v != 0) {
        MCSS_Del((void *)(*(int *)(p + 0x18)), (void *)v);
        *(int *)(p + 0x1c) = 0;
    }
}
