/*
 * function: GURU2_MAIN_ProcMain
 * address: 0x021DEA0C
 * packet: pkt_ov137_021DEA0C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGuru2MainStateTable 0x021E217C data a4
 *   GURU2_MAIN_UpdateCenterTransform 0x021E0570 thumb ov137
 *   GURU2_MAIN_UpdatePlayerRecords 0x021E07A4 thumb ov137
 *   GURU2_MAIN_Draw3D 0x021DF864 thumb ov137
 *   GURU2_MAIN_ClearTransferFlags 0x021DEA68 thumb ov137
 *   func_02030D28 0x02030D28 arm
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 */
#include "../include/Obj23742.h"
typedef unsigned char u8;
extern int (*const gGuru2MainStateTable[])(void *);
typedef unsigned int   u32;
struct Ctx;
extern void GURU2_MAIN_UpdateCenterTransform(u8 *p);
extern void GURU2_MAIN_UpdatePlayerRecords(char *p);
extern void GURU2_MAIN_Draw3D(u8 *p);
extern void GURU2_MAIN_ClearTransferFlags(char *p);
extern void func_02030D28(struct Ctx *c);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 func_0200FB24(void);
int GURU2_MAIN_ProcMain(int a, int b, int c, u8 *p)
{
    int result;
    do { result = gGuru2MainStateTable[*(int *)p](p); } while (result == 1);
    if (result == 2) return 1;
    GURU2_MAIN_UpdateCenterTransform(p);
    GURU2_MAIN_UpdatePlayerRecords((char *)p);
    GURU2_MAIN_Draw3D(p);
    GURU2_MAIN_ClearTransferFlags((char *)p);
    func_02030D28(((struct Obj23742 *)p)->fD98);
    if (WIPE_SYS_EndCheck() && func_0200FB24()) return 1;
    return 0;
}
