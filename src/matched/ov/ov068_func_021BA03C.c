/*
 * function: OPTION_MENU_ReadInput
 * address:  0x021BA03C
 * packet:   pkt_ov068_021BA03C
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Touch and key input to a command code in p[0].
 *
 * symbols:
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetCont  0x0203630C  arm
 *   func_020355C4  0x020355C4  arm
 *   func_020355D8  0x020355D8  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

typedef unsigned int u32;

extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern u32  KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);

void OPTION_MENU_ReadInput(int *p)
{
    int x;
    int y;
    u32 trg;
    u32 cont;
    int d;

    p[0] = 0;
    if (TOUCHPANEL_GetPointTrg((u32 *)(&x), (u32 *)(&y))) {
        p[0] = 3;
        p[1] = x;
        p[2] = y;
        p[5] = x;
        p[6] = y;
        p[7] = 1;
    } else if (TOUCHPANEL_GetPointCont((u32 *)(&x), (u32 *)(&y)) && p[7] != 0) {
        d = y - p[2];
        if (d < 0)
            d = -d;
        if (d >= 1) {
            p[0] = 1;
            p[3] = x - p[5];
            p[4] = y - p[6];
            p[5] = x;
            p[6] = y;
        }
    } else {
        p[7] = 0;
    }
    trg = KEY_GetTrg();
    cont = KEY_GetCont();
    if (trg != 0 && func_020355C4() == 1 && (trg & 0xc02) == 0) {
        func_020355D8(0);
        p[0] = 0xe;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return;
    }
    if (trg & 0x40) {
        p[0] = 4;
        return;
    }
    if (trg & 0x80) {
        p[0] = 5;
        return;
    }
    if (trg & 0x20) {
        p[0] = 7;
        return;
    }
    if (trg & 0x10) {
        p[0] = 6;
        return;
    }
    if (cont & 0x40) {
        p[0] = 0xa;
        return;
    }
    if (cont & 0x80) {
        p[0] = 0xb;
        return;
    }
    if (trg & 1) {
        p[0] = 8;
        return;
    }
    if (trg & 2) {
        func_020355D8(0);
        p[0] = 9;
        return;
    }
    if (trg & 0x800) {
        func_020355D8(0);
        p[0] = 0xc;
        return;
    }
    if (trg & 0x400) {
        func_020355D8(0);
        p[0] = 0xd;
    }
}
