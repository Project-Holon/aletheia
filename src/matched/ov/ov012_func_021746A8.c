/*
 * function: UNION_SCENE_StepWarpToZone97AtSeat
 * address:  0x021746A8
 * packet:   pkt_ov012_021746A8
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
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} P;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
typedef unsigned short u16;
extern void *EVENT_MAPCHANGE_CreateWarpEvent(void *p, int unused, int a, const int *q, u16 s, int t);

int UNION_SCENE_StepWarpToZone97AtSeat(int a, int b, int c, int d, int e, int *out, u8 *cnt)
{
    P s;
    int z;

    if (*cnt == 0) {
        s.a = (int)((GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())) * 16 + 0x58) << 12);
        z = 0;
        s.b = z;
        s.c = 0x26 << 14;
        *out = (int)EVENT_MAPCHANGE_CreateWarpEvent((void *)a, c, 0x97, (const int *)(&s), z, z);
    } else {
        return 1;
    }
    *cnt = *cnt + 1;
    return z;
}
