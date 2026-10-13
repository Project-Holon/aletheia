/*
 * function: func_021C7430
 * address: 0x021C7430
 * packet: pkt_ov136_021C7430
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C7F04 0x021C7F04 data a1
 *   GAME_DATA_GetMyItem  0x0201292C  thumb  arm9
 *   GAME_DATA_GetMyParty  0x02012934  thumb  arm9
 */
#include "../include/Obj03837.h"
#include "../include/Obj06531.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021C7F04[];
extern void *func_02030734(u32, u32, int, const char *, u16);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern void *func_0200CA1C(void *a);
void func_021C7430(u8 *p, int a, u16 b, u16 c)
{
    u8 *q = func_02030734(0x65, 0x98, 1, d_021C7F04, 0x529);
    ((struct Obj03837 *)q)->f0 = GAME_DATA_GetMyParty(**(void ** *)&((struct Obj06531 *)p)->f4);
    ((struct Obj03837 *)q)->f4 = GAME_DATA_GetMyItem(**(void ** *)&((struct Obj06531 *)p)->f4);
    ((struct Obj03837 *)q)->f8 = ((struct Obj06531 *)p)->f0;
    ((struct Obj03837 *)q)->f38 = 0;
    ((struct Obj03837 *)q)->f34 = a;
    ((struct Obj03837 *)q)->f44 = b;
    ((struct Obj03837 *)q)->f5C = c;
    ((struct Obj03837 *)q)->f18 = (u32)func_0200CA1C(**(void ** *)&((struct Obj06531 *)p)->f4);
    *(u8 * *)&((struct Obj06531 *)p)->f10 = q;
}
