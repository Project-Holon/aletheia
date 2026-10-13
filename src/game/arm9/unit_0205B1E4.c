/*
 * file:     unit_0205B1E4.c
 * unit:     yes
 * function: func_0205B1E4, func_0205B264, func_0205B2F8
 * address:  0x0205B1E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0205B264 0x0205B264 arm
 *   func_0217AA20 0x0217AA20 arm
 *   func_0217A950 0x0217A950 arm
 *   func_021656A0 0x021656A0 arm
 *   func_02164EE0 0x02164EE0 arm
 *   func_02165088 0x02165088 arm
 *   func_02165204 0x02165204 arm
 *   func_02165478 0x02165478 arm
 *   func_02165560 0x02165560 arm
 *   func_0205C2E4 0x0205C2E4 arm
 *   SOCL_CalmDown   0x0215ED60  arm
 *   SOC_Cleanup     0x0215FA90  arm
 *   SOCLiConfigPtr  0x021A1CD8  data  ov009
 */
extern int func_0205B264(void);
extern void func_0217AA20(void);
extern void func_0217A950(void);
extern int func_021656A0(void);
extern void func_02164EE0(void);
extern void func_02165088(void);
extern void func_02165204(void);
extern void func_02165478(void);
extern void func_02165560(void);
extern void func_0205C2E4(int error);
extern int SOCL_CalmDown(void);
extern int SOC_Cleanup(void);
int func_0205B1E4(unsigned char *phase);
int DisConnectAP(void);
int func_0205B2F8(void);
extern void *SOCLiConfigPtr;


/*
 * sdk:      DWCi_AC_CloseNetwork (close.o)
 */
int func_0205B1E4(unsigned char *phase)
{
    int result;

    if (*phase <= 10) {
        result = func_0205B264();
        if (result == 1) {
            *phase = 0;
            return 1;
        } else if (result == -1) {
            *phase = 0x12;
            return 1;
        }
    } else if (*phase == 14) {
        func_0217AA20();
        func_0217A950();
        *phase = 12;
    } else if (*phase < 0x12) {
        if (func_0205B2F8() == 1)
            *phase = 10;
    }
    return 0;
}


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


/*
 * sdk:      CloseSocket (libdwcac.TWL.HYB.a close.o, static)
 */
int func_0205B2F8(void)
{
    int result;

    if (SOCLiConfigPtr == 0)
        return 1;
    if (SOCL_CalmDown() != 0)
        return 0;
    result = SOC_Cleanup();
    if (result == 0 || result == -39)
        return 1;
    return 0;
}
