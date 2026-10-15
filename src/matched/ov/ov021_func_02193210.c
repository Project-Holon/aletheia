/*
 * function: FIELD_MSGBG_KeyWaitGetCharWait
 * address:  0x02193210
 * packet:   pkt_ov021_02193210
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   MSG_SPEED_GetWaitForSpeed  0x02013080  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern signed char MSG_SPEED_GetWaitForSpeed(u32 idx);
extern signed char MSG_SPEED_GetWait(void);

u32 FIELD_MSGBG_KeyWaitGetCharWait(u8 *p)
{
    if (*p != 0)
        return MSG_SPEED_GetWaitForSpeed(1);
    return MSG_SPEED_GetWait();
}
