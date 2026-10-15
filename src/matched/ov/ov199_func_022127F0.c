/*
 * function: WIFIBATTLEMATCH_SYS_HandleRuleCommand
 * address: 0x022127F0
 * packet: pkt_ov199_022127F0
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_SYS_SetStepDone 0x0221380C thumb ov199
 *   WIFIBATTLEMATCH_SYS_SetStep 0x02213808 thumb ov199
 *   func_02034714 0x02034714 arm
 *   func_020307B0 0x020307B0 arm
 *   d_02213D00 0x02213D00 data a1 ov199
 */
typedef unsigned int   u32;
extern void WIFIBATTLEMATCH_SYS_SetStepDone(unsigned char *p);
extern void WIFIBATTLEMATCH_SYS_SetStep(char *p, int value);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *p);
extern const char d_02213D00[];
int WIFIBATTLEMATCH_SYS_HandleRuleCommand(void *obj, int *command, int *ctx)
{
    switch (command[2]) {
    case 0: WIFIBATTLEMATCH_SYS_SetStepDone(obj); break;
    case 1: ctx[7] = 0; WIFIBATTLEMATCH_SYS_SetStep(obj, 4); break;
    case 2: ctx[7] = 1; WIFIBATTLEMATCH_SYS_SetStep(obj, 2); break;
    case 3: ctx[7] = 1; WIFIBATTLEMATCH_SYS_SetStep(obj, 6); break;
    case 4: ctx[7] = 1; WIFIBATTLEMATCH_SYS_SetStep(obj, 8); break;
    default: func_02034714(d_02213D00, 0, d_02213D00); break;
    }
    func_020307B0(command);
    return 1;
}
