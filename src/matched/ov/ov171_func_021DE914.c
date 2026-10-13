/*
 * function: func_021DE914
 * address: 0x021DE914
 * packet: pkt_ov171_021DE914
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_021DE960 0x021DE960 thumb ov171
 *   KEY_GetRepeat 0x0203633C arm
 *   KEY_GetTrg 0x020362DC arm
 *   d_021DED24 0x021DED24 data a4
 */
typedef unsigned int u32;
extern int TOUCHPANEL_HitTrg(const void *);
extern int func_021DE960(char *);
extern unsigned int KEY_GetRepeat(void);
extern u32 KEY_GetTrg(void);
extern const char d_021DED24[];
int func_021DE914(char *p)
{
    int result = TOUCHPANEL_HitTrg(d_021DED24);
    if (result != 3) {
        result = func_021DE960(p);
        if (result == 0xFF) {
            if (KEY_GetRepeat() & 0x220) return 0;
            if (KEY_GetRepeat() & 0x110) return 1;
            if (KEY_GetTrg() & 2) return 3;
            return 0xFF;
        }
    }
    return result;
}
