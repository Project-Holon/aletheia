/*
 * function: EVENT_BATTLE_REC_SAVE_ProcExit
 * address:  0x02154CC8
 * packet:   pkt_02154CA0
 * region:   ov008
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   func_0203133C  0x0203133C  arm
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */
#include "../include/Obj18645.h"

typedef unsigned char u8;

typedef unsigned int   u32;
struct Proc;
extern u32 func_0200FB24(void);
extern void GFL_NET_ERR_RequestScreen(void);
struct S020314B8;
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);

int EVENT_BATTLE_REC_SAVE_ProcExit(void *a0, int a1, char *a2, int *a3)
{
    if (((struct Obj18645 *)a2)->f14 == 1) {
        if (func_0200FB24() != 0)
            GFL_NET_ERR_RequestScreen();
    }
    func_0203133C((struct S020314B8 *)*a3);
    func_020315D4(a0);
    GFL_HEAP_DeleteChecked(0x76);
    return 1;
}
