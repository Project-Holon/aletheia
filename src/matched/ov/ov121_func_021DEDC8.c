/*
 * function: func_021DEDC8
 * address: 0x021DEDC8
 * packet: pkt_ov121_021DEDC8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Follower 021DEE14 is filed separately and verified.
 * symbols:
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE618 0x021DE618 thumb ov121
 */
extern int func_0203CEAC(int);
extern int func_0203CD98(void);
typedef unsigned int   u32;
extern void func_021DEEA4(u32 *p, void *f);
extern void func_021DE618(void);
void func_021DEDC8(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        if (func_0203CEAC(0)) *state = 1;
        else *state = 2;
        break;
    case 1:
        if (func_0203CD98() == 0) {
            *(int *)(p + 0x5c) = 0;
            *state = 2;
        }
        break;
    case 2:
        func_021DEEA4(a, func_021DE618);
        break;
    }
}
