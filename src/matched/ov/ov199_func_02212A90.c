/*
 * function: WIFIBATTLEMATCH_SYS_HandlePartyCommand
 * address: 0x02212A90
 * packet: pkt_ov199_02212A90
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 02212AF6..02212AF8 is zero alignment padding.
 * symbols:
 *   WIFIBATTLEMATCH_SYS_SetStep 0x02213808 thumb ov199
 *   func_020307B0 0x020307B0 arm
 */
extern void WIFIBATTLEMATCH_SYS_SetStep(char *p, int value);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
int WIFIBATTLEMATCH_SYS_HandlePartyCommand(void *obj, int *command, int *ctx)
{
    if (ctx[7] == 1) {
        switch (command[8]) {
        case 0: WIFIBATTLEMATCH_SYS_SetStep(obj, 5); break;
        case 2: ctx[0x1c0 / 4] = 1; WIFIBATTLEMATCH_SYS_SetStep(obj, 0); break;
        }
    } else {
        switch (command[8]) {
        case 0: WIFIBATTLEMATCH_SYS_SetStep(obj, 5); break;
        case 1: ctx[0x220 / 4] = 1; WIFIBATTLEMATCH_SYS_SetStep(obj, 4); break;
        case 3: ctx[8] = 2; WIFIBATTLEMATCH_SYS_SetStep(obj, 1); break;
        }
    }
    if ((unsigned)(ctx[7] - 2) <= 1) func_020307B0((void *)command[0]);
    func_020307B0(command);
    return 1;
}
