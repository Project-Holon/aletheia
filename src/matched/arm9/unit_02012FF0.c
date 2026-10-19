/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: MSG_SPEED_SetSaveControl, MSG_SPEED_GetWait
 * address:  0x02012FF0
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
 * Battle setup global pointer setter and clamped index lookup into data_0209DFB0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012FF0.c \
 *       --addr 0x02012FF0 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *ptr_020A7298;
extern const signed char data_0209DFB0[];

struct Sub02008700Obj;
extern struct Sub02008700Obj *SYSTEM_DATA_GetConfig(void *sys);
extern unsigned int sub_02008374(int a0);

void MSG_SPEED_SetSaveControl(void *val)
{
    ptr_020A7298 = val;
}

signed char MSG_SPEED_GetWait(void)
{
    u32 val = sub_02008374((int)SYSTEM_DATA_GetConfig(ptr_020A7298));
    if (val >= 5) {
        val = 4;
    }
    return data_0209DFB0[val];
}
