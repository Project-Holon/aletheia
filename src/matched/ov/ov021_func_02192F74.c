/*
 * function: FIELD_MSGBG_SetupSysFrame
 * address:  0x02192F74
 * packet:   pkt_ov021_02192F74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm  arm9
 *   FIELD_MSGBG_SetupSysFrameBg  0x02192EE0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct W {
    u16 f00;
    u16 f02;
    u16 f04;
    u8  pad[0x16A];
    u8  f170;
} W;

extern void BG_SYS_FreeLayerBuf(u32 a);
extern void FIELD_MSGBG_SetupSysFrameBg(int a);

void FIELD_MSGBG_SetupSysFrame(W *w)
{
    if (w->f170 != 0) {
        w->f170 = 0;
        if (w->f04 == 0xFF) {
            BG_SYS_FreeLayerBuf(2);
            FIELD_MSGBG_SetupSysFrameBg(1);
            w->f04 = 2;
        } else {
            FIELD_MSGBG_SetupSysFrameBg(0);
        }
    }
}
