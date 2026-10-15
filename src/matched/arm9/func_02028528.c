/*
 * function: PRINTSYS_CTRL_IsInputCont
 * address:  0x02028528
 * packet:   pkt_02028484
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT

 *
 * symbols:
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   KEY_GetCont  0x0203630C  arm
 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);

u32 PRINTSYS_CTRL_IsInputCont(u32 a)
{
    u32 r = 0;

    if (a == 0) {
        r = 1;
    }

    if (a & 2) {
        if (KEY_GetCont() & 3) {
            r = 1;
        }
    }

    if (a & 4) {
        if (TOUCHPANEL_GetCont() != 0) {
            r = 1;
        }
    }

    return r;
}
