/*
 * function: func_021F5D4C
 * address: 0x021F5D4C
 * packet: pkt_ov215_021F5D4C
 * region: ov215
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj08424.h"

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern unsigned int func_02049658(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
extern void func_020498F4(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern void ARC_TOOL_DeleteHandle(void *);
typedef unsigned int   u32;
extern void func_020409B4(u32 index);

void func_021F5D4C(int unused, char *p)
{
    void *h = func_020490F4(189, ((struct Obj08424 *)p)->f0);
    func_02049B68(h, 3, 0, 0, 32, ((struct Obj08424 *)p)->f0);
    func_02049658(h, 5, 2, 0, 0, 0, ((struct Obj08424 *)p)->f0);
    func_020498F4(h, 4, 2, 0, 0, 0, ((struct Obj08424 *)p)->f0);
    ARC_TOOL_DeleteHandle(h);
    func_020409B4(2);
}
