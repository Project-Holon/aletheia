/*
 * function: func_021BB2B4
 * address: 0x021BB2B4
 * packet: pkt_ov217_021BB2B4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021BB910 0x021BB910 thumb ov217
 *   func_021BBA00 0x021BBA00 thumb ov217
 *   func_021BC5A8 0x021BC5A8 thumb ov217
 *   func_021BC580 0x021BC580 thumb ov217
 *   func_021BB934 0x021BB934 thumb ov217
 *   func_021BC6D0 0x021BC6D0 thumb ov217
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021BB91C(void *p);
extern void func_021BB910(unsigned char *a0, u32 a1);
extern u32 func_021BBA00(u32 a0, u32 a1);
typedef unsigned char  u8;
extern void func_021BC5A8(u8 *a0, int a1);
extern void func_021BC580(char *p, int i);
extern void func_021BB934(u8 *a0, u32 a1);
extern u32 func_021BC6D0(void *p);

void func_021BB2B4(char *p)
{
    u32 keys = KEY_GetTrg();
    int st = TOUCHPANEL_HitTrg(p + 0x58);
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 9);
        return;
    }
    if (st == 0) {
        func_021BBA00((u32)p, 0);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_021BB934((u8 *)p, 1);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 12);
        return;
    }
    if (func_021BC6D0(p) != 0 || (keys & 2) || st == 1) {
        func_021BBA00((u32)p, 1);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 11);
        func_021BB910((unsigned char *)p, 2);
    }
}
