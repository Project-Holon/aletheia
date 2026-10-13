/*
 * function: PMi_CallPostExitCallbackAndReset
 * address: 0x027315E0
 * packet: pkt_twl_027315E0
 * region: twl
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/twl/unit_02731590.c and filed here.
 *
 * symbols:
 *   PMi_PostExitCallbackList 0x02732FAC data
 *   PMi_ExecuteList 0x0208C7E0 arm
 *   GX_DispOff 0x0207D42C arm
 *   OS_SpinWaitSysCycles 0x02087A04 arm
 *   func_0208BC8C 0x0208BC8C arm
 *   OS_DisableInterrupts 0x02087988 arm
 *   func_02082658 0x02082658 arm
 *   MI_StopAllNDma 0x0272FD18 arm
 *   PMi_FinalizeDebugger 0x02731500 arm
 *   OSi_DisableInterruptsAndHalt 0x020882C0 arm
 */

typedef struct PMiGenCallbackInfo PMiGenCallbackInfo;
extern void PMi_ExecuteList(PMiGenCallbackInfo *listp);
extern PMiGenCallbackInfo *PMi_PostExitCallbackList;
typedef unsigned int u32;

/* power-off sequence (callbacks, wait three ticks, request until the status word reads zero, shutdown calls) */
typedef unsigned short u16;
void GX_DispOff(void);
void OS_SpinWaitSysCycles(u32 n);
int func_0208BC8C(u32 cmd, u32 a, u16 *buf);
void OS_DisableInterrupts(void);
void func_02082658(void);
void MI_StopAllNDma(void);
void PMi_FinalizeDebugger(void);
void OSi_DisableInterruptsAndHalt(void);

void PMi_CallPostExitCallbackAndReset(int flag)
{
    u32 cmd;
    int i;
    int sel;
    u16 buf;

    PMi_ExecuteList(PMi_PostExitCallbackList);
    GX_DispOff();
    *(volatile u32 *)0x04001000 &= ~0x10000;
    *(volatile u16 *)0x04000204 |= 0x8000;
    for (i = 0; i < 3; i++) {
        u32 t = *(volatile u32 *)0x02FFFC3C;
        while (t == *(volatile u32 *)0x02FFFC3C)
            OS_SpinWaitSysCycles(0x32);
    }
    sel = (flag != 0);
    for (;;) {
        cmd = sel ? 0x14 : 0x13;
        if (*(volatile u32 *)0x02FFF684 == 1) {
            cmd = 0x14;
            *(volatile u32 *)0x02000300 = 0;
        }
        if (func_0208BC8C(cmd, 0, &buf) != 0) {
            do {
                OS_SpinWaitSysCycles(0x51D23);
            } while (func_0208BC8C(cmd, 0, &buf) != 0);
        }
        if (buf == 0)
            break;
        OS_SpinWaitSysCycles(0x51D23);
    }
    OS_DisableInterrupts();
    func_02082658();
    MI_StopAllNDma();
    PMi_FinalizeDebugger();
    OSi_DisableInterruptsAndHalt();
}
