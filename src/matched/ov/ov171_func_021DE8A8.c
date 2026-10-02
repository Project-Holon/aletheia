/*
 * function: func_021DE8A8
 * address: 0x021DE8A8
 * packet: pkt_ov171_021DE8A8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   func_021DE960 0x021DE960 thumb ov171
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   d_021DED24 0x021DED24 data a4
 */
typedef unsigned int u32;
extern int func_02035C08(const void *);
extern int func_021DE960(char *);
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern const char d_021DED24[];
int func_021DE8A8(char *p)
{
    int result = func_02035C08(d_021DED24);
    if (result == -1) {
        result = func_021DE960(p);
        if (result == 0xFF) {
            if (func_0203633C() & 0x220) return 0;
            if (func_0203633C() & 0x110) return 1;
            if (func_020362DC() & 1) return 4;
            if (func_020362DC() & 2) return 3;
            return (func_020362DC() & 0x400) ? 2 : 0xFF;
        }
    }
    return result;
}
