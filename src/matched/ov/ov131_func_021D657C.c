/*
 * function: P_STATUS_ProcExit
 * address: 0x021D657C
 * packet: pkt_ov131_021D657C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STATUS_ExitWork 0x021D4418 thumb ov131
 *   GAME_DATA_Delete 0x02012704 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj01255.h"
#include "../include/Obj23132.h"
typedef unsigned char u8;
struct Proc;
extern int P_STATUS_ExitWork(char *p);
extern void GAME_DATA_Delete(u8 *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int P_STATUS_ProcExit(struct Proc *handle, int unused, int mode, char *p)
{
    if (!P_STATUS_ExitWork(p)) return 0;
    if (!mode) {
        GAME_DATA_Delete(*(u8 * *)&((struct Obj23132 *)(*(char * *)&((struct Obj01255 *)p)->f8))->f8);
        func_020307B0(*(void **)*(char * *)&((struct Obj01255 *)p)->f8);
        func_020307B0(((struct Obj01255 *)p)->f8);
    }
    func_020315D4(handle);
    GFL_HEAP_DeleteChecked(0x42);
    return 1;
}
