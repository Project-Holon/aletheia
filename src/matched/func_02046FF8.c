/*
 * function: func_02046FF8
 * address:  0x02046FF8
 * packet:   pkt_02046FF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206E964  0x0206E964  arm
 *   func_02047260  0x02047260  arm
 *   func_020472F8  0x020472F8  arm
 *   func_02069FF8  0x02069FF8  arm
 *   func_0206A124  0x0206A124  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0206A00C  0x0206A00C  arm
 *   func_0206A12C  0x0206A12C  arm
 *
 * First guard exits through the shared epilogue at the end of the function
 * (a plain `return 0` there is if-converted and loses the branch).
 */

extern int func_0206E964(int x);
extern int func_02047260(int a, int *b, int *c);
extern int func_020472F8(int a, int *b);
extern void func_02069FF8(int a, int b, int c);
extern void func_0206A124(int a, int b);
extern void func_020862F0(int a, int b);
extern void func_0206A00C(int a, int b);
extern void func_0206A12C(int a, int b);

int func_02046FF8(int *self)
{
    int v8;
    int v4;
    int v0;
    int h;
    int p;

    h = self[1];
    p = func_0206E964(h);
    if (p == 0)
        goto fail;
    if (func_02047260(p, &v8, &v4) == 0)
        return 0;
    if (func_020472F8(p, &v0) == 0)
        return 0;
    func_02069FF8(p, v8, v4);
    func_0206A124(p, v0);
    func_020862F0(h, *(int *)(h + 8));
    func_0206A00C(p, 1);
    func_0206A12C(p, 1);
    return 1;
fail:
    return 0;
}
