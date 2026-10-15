/*
 * function: VIEWER_MAIN_CheckInputHeld
 * address:  0x021C5008
 * packet:   pkt_ov111_021C5008
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   KEY_GetCont  0x0203630C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x3060];
    int mode;
} Work;

extern int TOUCHPANEL_GetCont(void);
extern unsigned int KEY_GetCont(void);

int VIEWER_MAIN_CheckInputHeld(Work *p)
{
    if (p->mode == 1) {
        if (TOUCHPANEL_GetCont()) {
            return 0;
        }
        if (KEY_GetCont()) {
            p->mode = 0;
            return 1;
        }
    } else {
        if (KEY_GetCont()) {
            return 0;
        }
        if (TOUCHPANEL_GetCont()) {
            p->mode = 1;
            return 0;
        }
    }
    return 0;
}
