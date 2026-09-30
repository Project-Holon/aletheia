/*
 * function: func_021DE7BC
 * address: 0x021DE7BC
 * packet: pkt_ov121_021DE7BC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02157938 0x02157938 thumb ov010
 *   func_0203D210 0x0203D210 arm
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE618 0x021DE618 thumb ov121
 */
extern int func_02157938(int);
extern unsigned func_0203D210(void);
extern void func_021DEEA4(void *, void *);
extern void func_021DE618(void);
void func_021DE7BC(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_02157938(*(int *)(p + 0x798));
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
