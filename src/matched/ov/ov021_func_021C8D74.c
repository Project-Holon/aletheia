/*
 * function: func_021C8D74
 * address:  0x021C8D74
 * packet:   pkt_ov021_021C8D74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021ABE8C  0x021ABE8C  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021AD598  0x021AD598  thumb  ov021
 *   func_021C8E14  0x021C8E14  thumb  ov021
 */

extern int func_02188CD0(int a);
struct T;
extern int func_021ABE8C(struct T *a, int id);
extern void func_021ABE30(int a, int *b, int c);
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021AD598(int a, int b, int *c);
extern void func_021C8E14(int *p);

void func_021C8D74(int *p)
{
    int buf[3];
    int v;
    int r5;

    if (p[5] != 0) {
        r5 = func_02188CD0(p[1]);
        v = 9;
        if (func_021ABE8C((struct T *)r5, v) == 0) {
            func_021ABE30(r5, &v, 1);
        }
        func_021A3038((unsigned char *)p[2], (struct VecFx32 *)buf);
        func_021AD598(r5, 0, buf);
        func_021C8E14(p);
        p[5] = 0;
        p[6] = 0;
    }
}
