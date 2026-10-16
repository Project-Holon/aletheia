/*
 * function: MICTEST_Main
 * address:  0x02183CCC
 * packet:   pkt_02183CCC
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MICTEST_IsStepDone   0x02183D40  thumb
 *   MICTEST_RunStepMachine   0x02183D1C  thumb
 *   MICTEST_UpdateActors   0x02183FA0  thumb
 *   MICTEST_BgNoop   0x021841F4  thumb
 *   MICTEST_UpdateMic   0x0218441C  thumb
 *   TCB_Main   0x02030D28  arm
 *
 * Gate on p+0x130, then run the four init/teardown helpers and the
 *   word at p+0x144 through TCB_Main.
 */
#include "../include/Obj23813.h"


extern int MICTEST_IsStepDone(unsigned int *p);
extern void MICTEST_RunStepMachine(int *p);
extern void MICTEST_UpdateActors(void **p);
extern void MICTEST_BgNoop(char *);
extern void MICTEST_UpdateMic(int *p);
struct Ctx;
extern void TCB_Main(struct Ctx *c);

int MICTEST_Main(int a, int b, int c, char *p)
{
    if (MICTEST_IsStepDone((unsigned int *)(p + 0x130)))
        return 1;
    MICTEST_RunStepMachine((int *)(p + 0x130));
    MICTEST_UpdateActors((void **)p);
    MICTEST_BgNoop(p + 0xE4);
    MICTEST_UpdateMic((int *)(p + 0xF8));
    TCB_Main((struct Ctx *)(((struct Obj23813 *)p)->f144));
    return 0;
}
