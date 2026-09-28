/*
 * function: func_021DFB18
 * address:  0x021DFB18
 * packet:   pkt_021DFB18
 * region:   ov175
 * status:   EXACT
 * symbols:
 *   func_021DF948  0x021DF948  arm
 *   func_021E0A7C  0x021E0A7C  arm
 */
int func_021DF948(int *ctx, int a1);
int func_021E0A7C(int *ctx, int x, char *p, char *q,
                  int a, int b, int c, int d, int e, int f);

int func_021DFB18(int *ctx, int a1, int a2, int a3,
                  int a4, int a5, int a6, int a7)
{
    if (ctx == 0)
        return 2;
    if (a3 == 0)
        return 2;
    if (a4 == 0)
        return 2;
    if (ctx[0x14] == 0)
        return 3;
    func_021DF948(ctx, a1);
    return func_021E0A7C(ctx, ctx[0x13], (char *)ctx + 0x5c, (char *)ctx + 0x84,
                        a2, a3, a4, a5, a6, a7);
}
