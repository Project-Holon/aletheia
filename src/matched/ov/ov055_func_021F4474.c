/*
 * function: CROWD_UpdateChatter
 * address:  0x021F4474
 * packet:   pkt_ov055_021F4474
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   FIELDMAP_GetTimeZone  0x02189A38  thumb  ov021
 *   FIELDMAP_IsEventActive  0x02189A2C  thumb  ov021
 *   CROWD_OpenChatterSlot  0x021F4530  thumb  ov055
 *   CROWD_UpdateChatterSlot  0x021F4574  thumb  ov055
 *   CROWD_CloseChatterSlot  0x021F45A4  thumb  ov055
 *   _u32_div_f     0x0209C2B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_020056EC(u32 v);
extern int FIELDMAP_GetTimeZone(int a);
extern int FIELDMAP_IsEventActive(int *a);
extern void CROWD_OpenChatterSlot(u16 *p, u32 a, u32 b, u32 c, u32 d);
extern void CROWD_UpdateChatterSlot(u16 *p, u32 x);
extern void CROWD_CloseChatterSlot(u16 *p, u32 x);

void CROWD_UpdateChatter(s16 *a, s16 *b, int *c)
{
    int i;
    u32 rnd;
    int x;
    u8 *q;

    i = 0;
    rnd = func_020056EC(0);
    x = FIELDMAP_GetTimeZone((int)c);
    if (FIELDMAP_IsEventActive(c) == 0) {
        a[0] = a[0] + 1;
        if (a[0] >= a[1]) {
            CROWD_OpenChatterSlot((u16 *)((u8 *)a + 0x10 + ((u32 *)a)[1] * 8), ((u32 *)a)[3], ((u32 *)a)[2],
                          ((u8 *)b)[0x16], ((u8 *)b)[0x17]);
            a[0] = i;
            ((u32 *)a)[1] = (((u32 *)a)[1] + 1) & 0xf;
            a[1] = 0x10 + rnd % b[x];
        }
        i = 0;
        q = (u8 *)a + 0x10;
        for (; i < 16; i++) {
            CROWD_UpdateChatterSlot((u16 *)(q + i * 8), ((u32 *)a)[3]);
        }
    } else {
        q = (u8 *)a + 0x10;
        for (i = 0; i < 16; i++) {
            CROWD_CloseChatterSlot((u16 *)(q + i * 8), ((u32 *)a)[3]);
        }
    }
}
