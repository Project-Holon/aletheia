/*
 * function: func_021EDFC4
 * address: 0x021EDFC4
 * packet: pkt_ov093_021EDFC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021EE030,021EE050,021EE05E,021EE08E,021EE0AE,021EE0BC reread counters after stores; 021EDFFC,021EE0D2 hardware registers.
 * symbols:
 *   BMP_GetPixels 0x020437D4 arm
 *   func_02040B1C 0x02040B1C arm
 *   GFL_USE_IsSeqPlaying  0x02006254  thumb  arm9
 */
#include "../include/Obj00623.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bmp;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_020061E4(u32 a);
extern int GFL_USE_IsSeqPlaying(u32 a);
static inline void G2_BG2Mosaic(int enable)
{
    if (enable) *(volatile u16 *)0x0400000c |= 0x40;
    else *(volatile u16 *)0x0400000c &= ~0x40;
}
static inline void G2_BG3Mosaic(int enable)
{
    if (enable) *(volatile u16 *)0x0400000e |= 0x40;
    else *(volatile u16 *)0x0400000e &= ~0x40;
}
int func_021EDFC4(u8 *p)
{
    u8 a;
    switch (p[0xd]) {
    case 0:
        *(volatile u8 *)0x0400004c = 0;
        if (p[0xa] == 0) G2_BG2Mosaic(1);
        else G2_BG3Mosaic(1);
        p[0x20] = 0;
        p[0x21] = 0;
        func_020061E4(0x54e);
        p[0xd]++;
        break;
    case 1:
        p[0x20]++;
        if (*(volatile u8 *)&((struct Obj00623 *)p)->f20 > 1) {
            p[0x20] = 0;
            p[0x21]++;
            a = *(volatile u8 *)&((struct Obj00623 *)p)->f21;
            *(volatile u8 *)0x0400004c = a | (a << 4);
            if (*(volatile u8 *)&((struct Obj00623 *)p)->f21 >= 15) p[0xd]++;
        }
        break;
    case 2:
        func_02040B1C(p[0xb], BMP_GetPixels(((struct Obj00623 *)p)->f4), 0x900, ((struct Obj00623 *)p)->f1C);
        p[0xd]++;
        break;
    case 3:
        p[0x20]++;
        if (*(volatile u8 *)&((struct Obj00623 *)p)->f20 > 1) {
            p[0x20] = 0;
            p[0x21]--;
            a = *(volatile u8 *)&((struct Obj00623 *)p)->f21;
            *(volatile u8 *)0x0400004c = a | (a << 4);
            if (*(volatile u8 *)&((struct Obj00623 *)p)->f21 == 0) p[0xd]++;
        }
        break;
    case 4:
        if (p[0xa] == 0) G2_BG2Mosaic(0);
        else G2_BG3Mosaic(0);
        p[0xd]++;
        break;
    case 5:
        if (GFL_USE_IsSeqPlaying(0x54e) == 0) p[0xd]++;
        break;
    default:
        return 1;
    }
    return 0;
}
