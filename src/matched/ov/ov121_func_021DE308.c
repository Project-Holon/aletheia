/*
 * function: func_021DE308
 * address: 0x021DE308
 * packet: pkt_ov121_021DE308
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DEEAC 0x021DEEAC thumb ov121
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE618 0x021DE618 thumb ov121
 *   func_021DE61C 0x021DE61C thumb ov121
 *   func_021DE6F8 0x021DE6F8 thumb ov121
 *   func_021DE690 0x021DE690 thumb ov121
 *   func_021DE958 0x021DE958 thumb ov121
 *   func_021DEDC8 0x021DEDC8 thumb ov121
 *   func_021DE70C 0x021DE70C thumb ov121
 *   func_021DE7BC 0x021DE7BC thumb ov121
 *   func_021DE830 0x021DE830 thumb ov121
 *   func_021DE8D0 0x021DE8D0 thumb ov121
 */
extern int func_021DEEAC(int *p, int value);
extern void func_021DEEA4(void *, void *);
extern void func_021DE618(void);
extern void func_021DE61C(void *, int *, char *);
extern void func_021DE6F8(int, int, char *);
extern void func_021DE690(void *, int *, char *), func_021DE958(void *, int *, char *), func_021DEDC8(void *, int *, char *);
extern void func_021DE70C(void *, int *, char *), func_021DE7BC(void *, int *, char *), func_021DE830(void *, int *, char *), func_021DE8D0(void *, int *, char *);
void func_021DE308(char *p, unsigned action)
{
    switch (action) {
    case 1:
        if (func_021DEEAC((int *)p, (int)func_021DE618)) func_021DEEA4(p, func_021DE61C);
        break;
    case 3:
        if (func_021DEEAC((int *)p, (int)func_021DE6F8)) func_021DEEA4(p, func_021DE690);
        break;
    case 4:
        if (func_021DEEAC((int *)p, (int)func_021DE618)) func_021DEEA4(p, func_021DE958);
        break;
    case 5:
        if (func_021DEEAC((int *)p, (int)func_021DE958)) *(int *)(p + 0x76c) = 1;
        break;
    case 6: func_021DEEA4(p, func_021DEDC8); break;
    case 7: func_021DEEA4(p, func_021DE70C); break;
    case 9: func_021DEEA4(p, func_021DE7BC); break;
    case 10: func_021DEEA4(p, func_021DE830); break;
    case 12: func_021DEEA4(p, func_021DE8D0); break;
    case 0: func_021DEEA4(p, func_021DE618); break;
    }
}
