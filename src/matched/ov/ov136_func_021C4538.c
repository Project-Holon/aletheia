/*
 * function: MAILSYS_UpdateInputMode
 * address: 0x021C4538
 * packet: pkt_ov136_021C4538
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021C458E..021C4590 zero alignment padding.
 * symbols:
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   KEY_GetCont 0x0203630C arm
 */
typedef unsigned char u8;
extern int TOUCHPANEL_GetCont(void);
extern unsigned int KEY_GetCont(void);
int MAILSYS_UpdateInputMode(u8 *p)
{
    if (p[0xA] == 0) {
        if (TOUCHPANEL_GetCont()) return 0;
        if (KEY_GetCont()) {
            if (*(void (**)(void *))(p + 0x3C)) (*(void (**)(void *))(p + 0x3C))(p);
            p[0xA] = 1;
            return 1;
        }
    } else {
        if (KEY_GetCont()) return 0;
        if (TOUCHPANEL_GetCont()) {
            if (*(void (**)(void *))(p + 0x40)) (*(void (**)(void *))(p + 0x40))(p);
            p[0xA] = 0;
            return 0;
        }
    }
    return 0;
}
