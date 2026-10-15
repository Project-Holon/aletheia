/*
 * function: WIFIBATTLEMATCH_SYS_HandleMatchCommand
 * address: 0x0221290C
 * packet: pkt_ov199_0221290C
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: case 4 stores the flag and falls through to case 0's shared call.
 * symbols:
 *   WIFIBATTLEMATCH_SYS_SetStep 0x02213808 thumb ov199
 *   func_02034714 0x02034714 arm
 *   func_020307B0 0x020307B0 arm
 *   d_02213D00 0x02213D00 data a1 ov199
 */
typedef unsigned int   u32;
extern void WIFIBATTLEMATCH_SYS_SetStep(char *p, int value);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *p);
extern const char d_02213D00[];
int WIFIBATTLEMATCH_SYS_HandleMatchCommand(void *obj, int *command, int *ctx)
{
    switch (command[0]) {
    case 0: ctx[7] = 2; break;
    case 1: ctx[7] = 3; break;
    case 2: break;
    case 3: ctx[7] = 3; break;
    }
    switch (command[1]) {
    case 1: WIFIBATTLEMATCH_SYS_SetStep(obj, 2); break;
    case 2: WIFIBATTLEMATCH_SYS_SetStep(obj, 6); break;
    case 3: ctx[0x220 / 4] = 1; WIFIBATTLEMATCH_SYS_SetStep(obj, 4); break;
    case 4: ctx[9] = 1;
    case 0: WIFIBATTLEMATCH_SYS_SetStep(obj, 7); break;
    default: func_02034714(d_02213D00, 0, d_02213D00); break;
    }
    func_020307B0(command);
    return 1;
}
