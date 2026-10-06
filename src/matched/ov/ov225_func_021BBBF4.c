/*
 * function: func_021BBBF4
 * address: 0x021BBBF4
 * packet: pkt_ov225_021BBBF4
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020499D4 0x020499D4 arm
 */
#include "../include/Obj05575.h"
#include "../include/Obj26316.h"
#include "../include/Obj26317.h"
#include "../include/Obj26318.h"
#include "../include/Obj26319.h"
#include "../include/Obj26320.h"
#include "../include/Obj26321.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
void func_021BBBF4(char *p)
{
    func_02049B68((void *)(((struct Obj26316 *)(*(char * *)&((struct Obj05575 *)p)->f4))->f24), 0, 4, 0, 64, ((struct Obj26317 *)(*(char * *)&((struct Obj05575 *)p)->f4))->f4);
    func_02049658((void *)(((struct Obj26318 *)(*(char * *)&((struct Obj05575 *)p)->f4))->f24), 2, 4, 0, 0, 0, ((struct Obj26319 *)(*(char * *)&((struct Obj05575 *)p)->f4))->f4);
    func_020499D4((void *)(((struct Obj26320 *)(*(char * *)&((struct Obj05575 *)p)->f4))->f24), 6, 4, 0, 0, 0, 0, ((struct Obj26321 *)(*(char * *)&((struct Obj05575 *)p)->f4))->f4);
}
