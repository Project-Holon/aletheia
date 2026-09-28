/*
 * function: func_021B83F4
 * address:  0x021B83F4
 * packet:   pkt_ov093_021B83F4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BAB9C  0x021BAB9C  thumb  ov093
 *   func_021CD97C  0x021CD97C  thumb  ov093
 *   func_021CDD94  0x021CDD94  thumb  ov093
 *   func_021E908C  0x021E908C  thumb  ov093
 */

extern void func_021BAB9C(int);
extern int func_021CD97C(int);
extern void func_021CDD94(int, int);
extern void func_021E908C(int);

int func_021B83F4(int a)
{
    int i, found = 0;
    char *p = (char *)a;
    func_021BAB9C(*(int *)(p + 8));
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x10) != 0 &&
            func_021CD97C(*(int *)(p + i * 4 + 0x10)) != 0) {
            func_021CDD94(*(int *)(p + i * 4 + 0x10), (int)(p + 0x448));
            found = 1;
        }
    }
    func_021E908C(*(int *)(p + 4));
    return found;
}
