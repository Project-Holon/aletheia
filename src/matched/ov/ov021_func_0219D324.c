/*
 * function: func_0219D324
 * address:  0x0219D324
 * packet:   pkt_ov021_0219D324
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0219C880  0x0219C880  thumb  ov021
 *   func_02050468  0x02050468  arm
 */

extern int func_0216DA30(int);
extern int func_0216D7A8(int, int);
extern unsigned short func_0216D598(int);
extern void func_0219C880(int *, int, unsigned int, unsigned int);
extern void func_02050468(int, unsigned int, int);

void func_0219D324(int *obj, int *rec)
{
    int h;
    unsigned int n;

    h = rec[0];
    if (func_0216DA30(h) == 0) {
        func_0219C880(obj, h, *(unsigned short *)(rec + 1), *((unsigned short *)(rec + 1) + 1));
        func_02050468(obj[1], *(unsigned short *)(rec + 1), 1);
        rec[0] = 0;
        return;
    }
    if ((unsigned short)func_0216D7A8(h, 0) != 0xFFFF) {
        n = *((unsigned short *)(rec + 1) + 1);
        if (n != func_0216D598(h)) {
            func_0219C880(obj, h, *(unsigned short *)(rec + 1), n);
        }
        func_02050468(obj[1], *(unsigned short *)(rec + 1), 1);
        rec[0] = 0;
    }
}
