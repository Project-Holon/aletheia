/*
 * function: GFL_NET_DEVWIFI_GetLastErrorCode
 * address:  0x021552E8
 * packet:   pkt_ov009_021552E8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DWC_GetLastErrorEx  0x02059E38  arm
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 */

int DWC_GetLastErrorEx(int *a, int *b);
typedef unsigned int   u32;
void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
u32 GFL_NET_STATE_GetError(void);

int GFL_NET_DEVWIFI_GetLastErrorCode(void)
{
    int a, b, r;

    r = DWC_GetLastErrorEx(&a, &b);
    if (r != 0)
        GFL_NET_STATE_SetError(a, b, r, 0);
    if (r == 0)
        return 0;
    if (a == 0)
        return -10000;
    r = ((int *)GFL_NET_STATE_GetError())[3];
    if (r == 0)
        r = a;
    return r;
}
