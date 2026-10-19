/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: MSG_SPEED_GetSlowerWait, MSG_SPEED_GetFasterWait, MSG_SPEED_GetWaitForSpeed
 * address:  0x02013020
 * packet:   pkt_02012F08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ptr_020A7298  0x020A7298  data
 *   data_0209DFB0 0x0209DFB0  data
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 *   sub_02008374  0x02008374  thumb
 *
 * Mode mapping helpers calling clamped lookup MSG_SPEED_GetWaitForSpeed.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013020.c \
 *       --addr 0x02013020 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *ptr_020A7298;
extern const signed char data_0209DFB0[];

struct Sub02008700Obj;
extern struct Sub02008700Obj *SYSTEM_DATA_GetConfig(void *sys);
extern unsigned int sub_02008374(int a0);

signed char MSG_SPEED_GetWaitForSpeed(u32 idx);

signed char MSG_SPEED_GetSlowerWait(void)
{
    u32 val = sub_02008374((int)SYSTEM_DATA_GetConfig(ptr_020A7298));
    switch (val) {
    case 0:
        val = 1;
        break;
    case 1:
        val = 2;
        break;
    case 2:
        val = 3;
        break;
    }
    return MSG_SPEED_GetWaitForSpeed(val);
}

signed char MSG_SPEED_GetFasterWait(void)
{
    u32 val = sub_02008374((int)SYSTEM_DATA_GetConfig(ptr_020A7298));
    switch (val) {
    case 0:
        val = 4;
        break;
    case 1:
        val = 0;
        break;
    case 2:
        val = 1;
        break;
    }
    return MSG_SPEED_GetWaitForSpeed(val);
}

signed char MSG_SPEED_GetWaitForSpeed(u32 idx)
{
    if (idx >= 5) {
        idx = 4;
    }
    return data_0209DFB0[idx];
}
