/*
 * function: func_021D89A8
 * address: 0x021D89A8
 * packet: pkt_ov119_021D89A8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008FEC 0x02008FEC thumb
 *   func_02009020 0x02009020 thumb
 */
struct Sub02008F80Obj;
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern int func_02009020(void *obj, int v);

int func_021D89A8(char *p)
{
    void *o = func_02008FEC(*(void **)(p + 0x82C));
    int r = 0;
    if (func_02009020(o, 0) == -1)
        r = 1;
    return r;
}
