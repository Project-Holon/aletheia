/*
 * function: func_02164010
 * address:  0x02164010
 * packet:   pkt_ov010_02164010
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D88C  0x0216D88C  thumb
 *   func_0216D55C  0x0216D55C  thumb
 *   func_0216DB68  0x0216DB68  thumb
 *   func_0216D570  0x0216D570  thumb
 *   func_0216D568  0x0216D568  thumb
 *   func_02163E58  0x02163E58  thumb
 *   func_0216D89C  0x0216D89C  thumb
 *   func_0216D854  0x0216D854  thumb
 *   func_0216D818  0x0216D818  thumb
 *   func_0216D85C  0x0216D85C  thumb
 */

typedef short s16;
typedef struct { int v[3]; } Vec3;

struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *p);
extern int func_0216D55C(int a, int b);
extern int func_0216DB68(int a);
extern void func_0216D570(int a, int b);
extern void func_0216D568(int a, int b);
extern int func_02163E58(int a, Vec3 *p, int *out);
extern void func_0216D89C(int a, Vec3 *p);
extern int func_0216D854(int a);
extern void func_0216D818(int a, int b);
extern void func_0216D85C(int a, int b);

int func_02164010(int a)
{
    Vec3 cur;
    Vec3 next;
    int out;
    int r;

    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&cur);
    next = cur;
    if (func_0216D55C(a, 0x2000) != 0)
        return 0;
    if (func_0216DB68(a) == 1) {
        func_0216D570(a, 0x1000);
        return 0;
    }
    r = func_02163E58(a, &next, &out);
    if (r == 1) {
        cur.v[1] = out;
        func_0216D89C(a, &cur);
        func_0216D818(a, func_0216D854(a));
        func_0216D85C(a, (s16)((out >> 4) / 4096));
        func_0216D570(a, 0x1000);
    } else {
        func_0216D568(a, 0x1000);
    }
    return r;
}
