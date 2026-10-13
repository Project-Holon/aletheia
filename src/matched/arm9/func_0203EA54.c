/*
 * function: GFL_NET_LOWER_DATA_IsSendFinished
 * address:  0x0203EA54
 * packet:   pkt_0203EA54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469F4      0x021469F4  data
 */

typedef struct { char pad[0x30]; int state; } Obj;
extern Obj *g_021469F4;
int GFL_NET_LOWER_DATA_IsSendFinished(void)
{
    if (g_021469F4 == 0)
        return 0;
    return g_021469F4->state;
}
