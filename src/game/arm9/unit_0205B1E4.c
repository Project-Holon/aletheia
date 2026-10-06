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
extern void func_021656A0(void);
extern void func_02164EE0(void);
extern void func_02165088(void);
extern void func_02165204(void);
extern void func_02165478(void);
extern void func_02165560(void);
extern void func_0205C2E4(int error);
extern int SOCL_CalmDown(void);
extern int SOC_Cleanup(void);
int func_0205B1E4(unsigned char *phase);
asm int DisConnectAP(void);
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


asm int DisConnectAP(void)
{
    stmfd sp!, {r4, lr}
    bl func_021656A0
    cmp r0, #0xc
    addls pc, pc, r0, lsl #2
    b loc_default

    b case_0
    b case_1
    b loc_default
    b case_3
    b loc_default
    b loc_default
    b case_6
    b loc_default
    b loc_default
    b case_9
    b loc_default
    b case_11
    b case_12

case_0:
    mov r0, #1
    ldmfd sp!, {r4, pc}

case_1:
    bl func_02164EE0
    b loc_default

case_3:
    bl func_02165088
    b loc_default

case_6:
    bl func_02165204
    b loc_default

case_9:
    bl func_02165478
    b loc_default

case_12:
    bl func_02165560
    b loc_default

case_11:
    mov r4, #0
    mov r0, r4
    bl func_0205C2E4
    sub r0, r4, #1
    ldmfd sp!, {r4, pc}

loc_default:
    mov r0, #0
    ldmfd sp!, {r4, pc}
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
