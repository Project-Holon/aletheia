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
 * 2026-10-05: the callee func_02015BA4 takes a second argument (r1 = the field value tested); the caller passes it.
 *
 * symbols:
 *   func_02015BA4  0x02015BA4  thumb
 */

extern void func_02015BA4(int, int);

void func_021B6984(char *p)
{
    int v = *(int *)(p + 0x1c);

    if (v != 0) {
        func_02015BA4(*(int *)(p + 0x18), v);
        *(int *)(p + 0x1c) = 0;
    }
}
