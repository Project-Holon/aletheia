/*
 * function: UNION_MAIN_StepPlayEffectAtSeat
 * address:  0x02174654
 * packet:   pkt_ov012_02174654
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   EVENT_MAPCHANGE_CreateWarpEvent  0x02184D38  thumb  ov020
 */

typedef unsigned char u8;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void *EVENT_MAPCHANGE_CreateWarpEvent(void *p, int unused, int a, const int *q, u16 s, int t);

int UNION_MAIN_StepPlayEffectAtSeat(int a, int b, int c, int d, int e, int *out, u8 *cnt)
{
    int v[3];
    int z = 0;

    if (*cnt == 0) {
        v[0] = (GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle())) * 16 + 0x58) << 12;
        v[1] = 0;
        v[2] = 0x98000;
        *out = (int)EVENT_MAPCHANGE_CreateWarpEvent((void *)a, c, 0x96, v, 0, 0);
    } else {
        return 1;
    }
    (*cnt)++;
    return z;
}
