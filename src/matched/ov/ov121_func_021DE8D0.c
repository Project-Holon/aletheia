/*
 * function: func_021DE8D0
 * address: 0x021DE8D0
 * packet: pkt_ov121_021DE8D0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02157E8C 0x02157E8C thumb ov010
 *   func_0203D210 0x0203D210 arm
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE618 0x021DE618 thumb ov121
 */
extern void func_02157E8C(void *);
extern unsigned func_0203D210(void);
typedef unsigned int   u32;
extern void func_021DEEA4(u32 *p, void *f);
extern void func_021DE618(void);
void func_021DE8D0(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_02157E8C(*(void **)(p + 0x79c));
        *state = 1;
        break;
    case 1:
        if (func_0203D210()) *state = 2;
        break;
    case 2:
        func_021DEEA4(a, func_021DE618);
        break;
    }
}
