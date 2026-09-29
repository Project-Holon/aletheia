/*
 * function: func_02201234
 * address:  0x02201234
 * packet:   pkt_ov094_02201234
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
 *   func_02200108  0x02200108  thumb  ov094
 *   func_02015F2C  0x02015F2C  thumb
 *   func_02201718  0x02201718  thumb  ov094
 */
typedef unsigned char u8;

extern int func_022019F4(char *p, int key);
extern void func_021F89BC(void *o);
extern int func_021F9260(void *m, int *out);
extern void func_02200108(char *p, int key, int x);
extern void func_02015F2C(void *a, int i, void (*fn)(int), int one);
extern void func_02201718(int i);

void func_02201234(void *o, char *q)
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
    if (*(int *)(q + 0x50) != *(u8 *)(p + *(int *)(q + 4) + 0x5A4)) {
        func_021F89BC(o);
        return;
    }
    r = func_021F9260(q + 0x14, (int *)(q + 8));
    func_02200108(p, *(int *)(q + 4), *(int *)(q + 8) >> 12);
    if (r == 1) {
        func_02015F2C(*(void **)(e + off), i, func_02201718, 1);
        func_021F89BC(o);
    }
}
