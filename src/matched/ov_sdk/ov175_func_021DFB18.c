/*
 * function: scSetReportIntention
 * address:  0x021DFB18
 * packet:   pkt_021DFB18
 * region:   ov175
 * status:   EXACT
 * symbols:
 *   sciInterfaceSetConnectionId  0x021DF948  arm
 *   sciWsSetReportIntention  0x021E0A7C  arm
 */
int sciInterfaceSetConnectionId(int *ctx, int a1);
int sciWsSetReportIntention(int *ctx, int x, char *p, char *q,
                  int a, int b, int c, int d, int e, int f);

int scSetReportIntention(int *ctx, int a1, int a2, int a3,
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
    sciInterfaceSetConnectionId(ctx, a1);
    return sciWsSetReportIntention(ctx, ctx[0x13], (char *)ctx + 0x5c, (char *)ctx + 0x84,
                        a2, a3, a4, a5, a6, a7);
}
