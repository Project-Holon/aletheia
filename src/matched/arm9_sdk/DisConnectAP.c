/*
 * function: DisConnectAP
 * address:  0x0205B264
 * packet:   pkt_0205B264
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021656A0 0x021656A0 arm
 *   func_02164EE0 0x02164EE0 arm
 *   func_02165088 0x02165088 arm
 *   func_02165204 0x02165204 arm
 *   func_02165478 0x02165478 arm
 *   func_02165560 0x02165560 arm
 *   func_0205C2E4 0x0205C2E4 arm
 */

extern int func_021656A0(void);
extern void func_02164EE0(void);
extern void func_02165088(void);
extern void func_02165204(void);
extern void func_02165478(void);
extern void func_02165560(void);
extern void func_0205C2E4(int error);

int DisConnectAP(void)
{
    switch (func_021656A0()) {
    case 0:
        return 1;
    case 1:
        func_02164EE0();
        break;
    case 3:
        func_02165088();
        break;
    case 6:
        func_02165204();
        break;
    case 9:
        func_02165478();
        break;
    case 12:
        func_02165560();
        break;
    case 11:
        func_0205C2E4(0);
        return -1;
    }
    return 0;
}
