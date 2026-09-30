/*
 * function: func_021DE690
 * address: 0x021DE690
 * packet: pkt_ov121_021DE690
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020103E4 0x020103E4 thumb
 *   func_0203CEAC 0x0203CEAC arm
 *   func_021DEED0 0x021DEED0 thumb ov121
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE618 0x021DE618 thumb ov121
 */
extern void func_020103E4(void *);
extern int func_0203CEAC(int);
extern void func_021DEED0(void);
extern void func_021DE618(void);
extern void func_021DEEA4(void *, void *);
void func_021DE690(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_020103E4(*(void **)(p + 0x10));
        *(int *)(p + 0x10) = 0;
        *state = 1;
        break;
    case 1:
        if (func_0203CEAC((int)func_021DEED0)) *state = 2;
        else *state = 3;
        break;
    case 2:
        if (*(int *)(p + 0x5c)) {
            *(int *)(p + 0x5c) = 0;
            *state = 3;
        }
        break;
    case 3:
        func_021DEEA4(a, func_021DE618);
        break;
    }
}
