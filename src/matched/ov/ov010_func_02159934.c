/*
 * function: func_02159934
 * address: 0x02159934
 * packet: pkt_ov010_02159934
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x0215995E.
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02159204 0x02159204 thumb ov010
 *   func_0215897C 0x0215897C thumb ov010
 */
extern void *func_0215A5F4(void *);
extern void *func_0215A5DC(void *);
extern void *func_02159204(void *);
extern void func_0215897C(void *, void *);
int func_02159934(void *a, void *b)
{
    void *x = func_0215A5F4(b);
    void *t;
    func_0215A5DC(b);
    t = func_02159204(b);
    if (t == 0)
        return 1;
    func_0215897C(x, t);
    return 1;
}
