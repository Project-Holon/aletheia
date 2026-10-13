/*
 * function: UNION_COMMAND_SendPartnerSelectA
 * address:  0x02173A04
 * packet:   pkt_ov012_02173A04
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *
 * Varargs function whose listing label (func_02173A06) sits after the
 * push {r0-r3} home area; ov019 calls it at 0x02173A04.
 */

typedef unsigned short u16;

struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);

int UNION_COMMAND_SendPartnerSelectA(int a, int b, int c, int d)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1401, 4, (u32)(&a));
}
