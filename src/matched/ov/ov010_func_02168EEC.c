/*
 * function: func_02168EEC
 * address:  0x02168EEC
 * packet:   pkt_ov010_02168EEC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_0203F49C  0x0203F49C  arm
 *   func_02168F54  0x02168F54  thumb
 *   func_02008BE0  0x02008BE0  thumb
 *   func_02169068  0x02169068  thumb
 *   func_02169004  0x02169004  thumb
 */

struct Big;
struct Sub02008AECSession;
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern void func_0203F49C(int *, int *);
extern int func_02168F54(int *, int *, int *, int *, int *);
extern void func_02008BE0(int *, unsigned int);
extern void func_02169068(int, int, int *);
extern void func_02169004(int, int);

void func_02168EEC(int a)
{
    int A[4];
    int B[3];
    int y;
    int x;
    int *p = (int *)func_02008B14(func_02012EBC((struct Big *)a));
    if (*p == 0)
        return;
    func_0203F49C(A, B);
    if (func_02168F54(p, A, B, &y, &x) == 0)
        return;
    if (x == 0 && y != 0)
        return;
    if (x != 0) {
        func_02008BE0(p, x);
        func_02169068(a, x, B);
    }
    if (y != 0)
        func_02169004(a, y);
}
