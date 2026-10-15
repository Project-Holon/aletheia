/*
 * unit: yes
 * function: MYSTERY_NET_IsHandler, MYSTERY_NET_GetBuffer, MYSTERY_NET_GetBufferSize, MYSTERY_NET_IsEqual, MYSTERY_NET_FlagExit, MYSTERY_NET_OnNdAsyncDone, MYSTERY_NET_MarkNdDone
 * address: 0x021DEEAC
 * packet: pkt_ov121_021DEEAC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DFC00 0x021DFC00 data a4
 */
#include "../include/Obj22922.h"
extern int d_021DFC00[];
void MYSTERY_NET_MarkNdDone(void);
int MYSTERY_NET_IsHandler(int *p, int value)
{
    return *p == value;
}
void *MYSTERY_NET_GetBuffer(char *p)
{
    return p + 0x14;
}
int MYSTERY_NET_GetBufferSize(void)
{
    return 0x20;
}
int MYSTERY_NET_IsEqual(int a, int b)
{
    return a == b;
}
void MYSTERY_NET_FlagExit(char *p)
{
    ((struct Obj22922 *)p)->f5C = 1;
}
void MYSTERY_NET_OnNdAsyncDone(int a, int b)
{
    d_021DFC00[1] = 1;
    d_021DFC00[3] = b;
    MYSTERY_NET_MarkNdDone();
}
void MYSTERY_NET_MarkNdDone(void)
{
    d_021DFC00[0] = 1;
}
