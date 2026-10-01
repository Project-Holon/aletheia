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
 *   func_020437D4 0x020437D4 arm
 *   func_02040B1C 0x02040B1C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020437D4(const void *);
extern void func_02040B1C(u8, const void *, u32, u32);
extern void func_020061E4(int);
extern int func_02006254(int);
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
        if (*(volatile u8 *)(p + 0x20) > 1) {
            p[0x20] = 0;
            p[0x21]++;
            a = *(volatile u8 *)(p + 0x21);
            *(volatile u8 *)0x0400004c = a | (a << 4);
            if (*(volatile u8 *)(p + 0x21) >= 15) p[0xd]++;
        }
        break;
    case 2:
        func_02040B1C(p[0xb], func_020437D4(*(void **)(p + 4)), 0x900, *(u32 *)(p + 0x1c));
        p[0xd]++;
        break;
    case 3:
        p[0x20]++;
        if (*(volatile u8 *)(p + 0x20) > 1) {
            p[0x20] = 0;
            p[0x21]--;
            a = *(volatile u8 *)(p + 0x21);
            *(volatile u8 *)0x0400004c = a | (a << 4);
            if (*(volatile u8 *)(p + 0x21) == 0) p[0xd]++;
        }
        break;
    case 4:
        if (p[0xa] == 0) G2_BG2Mosaic(0);
        else G2_BG3Mosaic(0);
        p[0xd]++;
        break;
    case 5:
        if (func_02006254(0x54e) == 0) p[0xd]++;
        break;
    default:
        return 1;
    }
    return 0;
}
