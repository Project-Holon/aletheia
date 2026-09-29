/*
 * function: func_02200D68
 * address:  0x02200D68
 * packet:   pkt_ov094_02200D68
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_02015FBC  0x02015FBC  thumb
 */
typedef unsigned char u8;

extern int func_022019F4(char *p, int key);
extern void func_021F89BC(void *o);
extern int func_021F9260(void *m, int *out);
extern void func_02015FBC(char *p, u8 v);

void func_02200D68(void *o, char *q)
{
    char *p = *(char **)q;
    int i = func_022019F4(p, *(int *)(q + 4));
    char *e;
    int off;
    int r;

    if (i == -1) {
        func_021F89BC(o);
        return;
    }
    e = p + 8;
    off = i * 0x5C;
    if (*(int *)(e + off) == 0) {
        func_021F89BC(o);
        return;
    }
    if (*(int *)(q + 0x50) != *(u8 *)(p + *(int *)(q + 4) + 0x596)) {
        func_021F89BC(o);
        return;
    }
    r = func_021F9260(q + 0x14, (int *)(q + 8));
    func_02015FBC(*(char **)(e + off), *(int *)(q + 8) >> 12);
    if (r == 1)
        func_021F89BC(o);
}
