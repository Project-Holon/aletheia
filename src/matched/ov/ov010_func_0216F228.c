/*
 * function: TRCARD_SYS_ExitMinimal
 * address:  0x0216F228
 * packet:   pkt_ov010_0216F228
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */
#include "../include/Obj19151.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020307B0(void *p);
struct Proc;
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);

int TRCARD_SYS_ExitMinimal(void *a, int b, int c, char *d)
{
    func_020307B0(((struct Obj19151 *)d)->f18);
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(0x26);
    return 1;
}
