/*
 * function: func_021B74F8
 * address: 0x021B74F8
 * packet: pkt_ov173_021B74F8
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02006238 0x02006238 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E9C 0x02005E9C thumb
 */
extern int func_02006238(void);
extern void func_020061E4(unsigned int);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void func_02005D90(unsigned int, unsigned int);
extern int func_02005F38(void);
extern void func_02005E9C(void);
int func_021B74F8(unsigned int state)
{
    switch (state) {
    case 1: return func_02006238();
    case 2: return func_02006238();
    case 3: func_020061E4(0x56b); break;
    case 4:
        func_02005DE4((void *)1);
        func_02005E64();
        func_02005D90(0x515, 0xffff);
        break;
    case 5:
        if (func_02005F38() == 0) {
            func_02005E9C();
            func_02005DE4(0);
        } else {
            return 1;
        }
        break;
    }
    return 0;
}
