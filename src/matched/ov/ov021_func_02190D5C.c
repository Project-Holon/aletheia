/*
 * function: FIELD_MSGBG_MsgStreamMain
 * address:  0x02190D5C
 * packet:   pkt_ov021_02190D5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE34  0x0201CE34  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   FIELD_MSGBG_KeyWaitCheckSkip  0x02193228  thumb  ov021
 *   FIELD_MSGBG_KeyWaitCheckAdvance  0x02193260  thumb  ov021
 *   FIELD_MSGBG_KeyWaitGetAuto  0x0219320C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   FIELD_MSGBG_StreamSetSpeed  0x021932A0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32 func_0201CE30(void *p);
extern u32 func_0201CE34(void *p);
extern void func_0201CE38(void *p);
extern int FIELD_MSGBG_KeyWaitCheckSkip(u8 *p);
extern int FIELD_MSGBG_KeyWaitCheckAdvance(u8 *p, u32 q);
extern u8 FIELD_MSGBG_KeyWaitGetAuto(u8 *p);
extern void func_020061E4(u32 a);
extern void FIELD_MSGBG_StreamSetSpeed(u32 a, int f);

int FIELD_MSGBG_MsgStreamMain(u32 *p)
{
    int r = func_0201CE30((void *)p[1]);

    switch (r) {
    case 0:
        if (FIELD_MSGBG_KeyWaitCheckSkip((u8 *)(p[2] + 0x160)) != 0) {
            FIELD_MSGBG_StreamSetSpeed(p[1], 1);
        } else {
            FIELD_MSGBG_StreamSetSpeed(p[1], 0);
        }
        break;
    case 1:
        if (FIELD_MSGBG_KeyWaitCheckAdvance((u8 *)(p[2] + 0x160), func_0201CE34((void *)p[1])) != 0) {
            if (FIELD_MSGBG_KeyWaitGetAuto((u8 *)(p[2] + 0x160)) == 0) {
                func_020061E4(0x547);
            }
            func_0201CE38((void *)p[1]);
            r = 0;
            FIELD_MSGBG_StreamSetSpeed(p[1], 0);
        }
        break;
    case 2:
        break;
    }
    return r;
}
