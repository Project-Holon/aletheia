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
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   PRINTSYS_PrintStreamGetWaitKind  0x0201CE34  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   FIELD_MSGBG_KeyWaitCheckSkip  0x02193228  thumb  ov021
 *   FIELD_MSGBG_KeyWaitCheckAdvance  0x02193260  thumb  ov021
 *   FIELD_MSGBG_KeyWaitGetAuto  0x0219320C  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_MSGBG_StreamSetSpeed  0x021932A0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern u32 PRINTSYS_PrintStreamGetWaitKind(void *p);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
extern int FIELD_MSGBG_KeyWaitCheckSkip(u8 *p);
extern int FIELD_MSGBG_KeyWaitCheckAdvance(u8 *p, u32 q);
extern u8 FIELD_MSGBG_KeyWaitGetAuto(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void FIELD_MSGBG_StreamSetSpeed(u32 a, int f);

int FIELD_MSGBG_MsgStreamMain(u32 *p)
{
    int r = PRINTSYS_PrintStreamGetState((void *)p[1]);

    switch (r) {
    case 0:
        if (FIELD_MSGBG_KeyWaitCheckSkip((u8 *)(p[2] + 0x160)) != 0) {
            FIELD_MSGBG_StreamSetSpeed(p[1], 1);
        } else {
            FIELD_MSGBG_StreamSetSpeed(p[1], 0);
        }
        break;
    case 1:
        if (FIELD_MSGBG_KeyWaitCheckAdvance((u8 *)(p[2] + 0x160), PRINTSYS_PrintStreamGetWaitKind((void *)p[1])) != 0) {
            if (FIELD_MSGBG_KeyWaitGetAuto((u8 *)(p[2] + 0x160)) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x547);
            }
            PRINTSYS_PrintStreamReleasePause((void *)p[1]);
            r = 0;
            FIELD_MSGBG_StreamSetSpeed(p[1], 0);
        }
        break;
    case 2:
        break;
    }
    return r;
}
