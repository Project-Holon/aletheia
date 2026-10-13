/*
 * function: func_02205010
 * address:  0x02205010
 * packet:   pkt_02205010
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj08347.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_020409B4(u32 index);

void func_02205010(int a, char *b)
{
    void *h = func_020490F4(0xb6, ((struct Obj08347 *)b)->f2);

    func_02049B68(h, 3, 0, 0, 0x20, ((struct Obj08347 *)b)->f2);
    func_02049658(h, 5, 2, 0, 0, 0, ((struct Obj08347 *)b)->f2);
    func_020498F4(h, 4, 2, 0, 0, 0, ((struct Obj08347 *)b)->f2);
    ARC_TOOL_DeleteHandle(h);
    func_020409B4(2);
}
