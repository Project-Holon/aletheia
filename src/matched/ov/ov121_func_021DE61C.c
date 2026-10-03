/*
 * function: func_021DE61C
 * address: 0x021DE61C
 * packet: pkt_ov121_021DE61C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CBAC 0x0203CBAC arm
 *   func_02043598 0x02043598 arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02010360 0x02010360 thumb
 *   func_0203D010 0x0203D010 arm
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE6F8 0x021DE6F8 thumb ov121
 *   d_021DFABC 0x021DFABC data a4
 */
extern void func_0203CBAC(void *, unsigned, unsigned);
typedef unsigned int   u32;
extern void func_02043598(u32 mask, u32 enable);
extern int func_0203CD98(void);
extern void func_0203D34C(unsigned, unsigned);
extern void *func_02010360(int, unsigned short);
extern void func_0203D010(void);
extern void func_021DEEA4(u32 *p, void *f);
extern void func_021DE6F8(int, int, char *);
extern unsigned d_021DFABC[];
void func_021DE61C(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_0203CBAC(d_021DFABC, 0, (unsigned)p);
        func_02043598(0x10, 0);
        *state = 1;
        break;
    case 1:
        if (func_0203CD98()) {
            func_0203D34C(1, *(unsigned short *)(p + 0x58));
            *(void **)(p + 0x10) = func_02010360(4, *(unsigned short *)(p + 0x58));
            func_0203D010();
            *state = 2;
        }
        break;
    case 2:
        func_02043598(0x10, 1);
        func_021DEEA4(a, func_021DE6F8);
        break;
    }
}
