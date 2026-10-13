/*
 * function: func_021DC738
 * address: 0x021DC738
 * packet: pkt_ov175_021DC738
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_021E2EF8 0x021E2EF8 data a1
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_021B9800 0x021B9800 thumb ov114
 */
#include "../include/Obj06575.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_021E2EF8[];
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern u8 *func_021B9800(int a, int b, int c);
void func_021DC738(char *p,unsigned heap)
{
    if(*(int *)&((struct Obj06575 *)p)->f121C!=0) func_02034714(d_021E2EF8,0,d_021E2EF8);
    ((struct Obj06575 *)p)->f12C=0;
    ((struct Obj06575 *)p)->f121C=func_021B9800(heap,func_0200853C((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(((struct Obj06575 *)p)->f8)),((struct Obj06575 *)p)->f10);
}
