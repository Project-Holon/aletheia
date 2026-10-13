/*
 * function: func_021CB174
 * address: 0x021CB174
 * packet: pkt_ov093_021CB174
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: BTL_MAIN_GetEnemyLanePosFromWork forwards live r1/r2 to BTL_MAIN_GetEnemyLanePos and returns r0.
 * symbols:
 *   BTL_MAIN_GetEnemyLanePosFromWork 0x021B8C50 thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   BTL_SERVER_GetClientChecked 0x021BB85C thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 */
#include "../include/Obj09978.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u8 BTL_MAIN_GetEnemyLanePosFromWork(char **p, u32 v, int k);
extern void func_021B8E28(u8 *, u8, u8 *, u8 *);
extern u8 *BTL_SERVER_GetClientChecked(u8 *, unsigned int);
struct S2;
extern u32 func_021B9BF0(struct S2 *p, u32 i);
void *func_021CB174(u8 *p, unsigned int n, int k)
{
    u8 out[2];
    func_021B8E28(*(u8 * *)&((struct Obj09978 *)p)->f4, BTL_MAIN_GetEnemyLanePosFromWork(((struct Obj09978 *)p)->f4, n, k), out + 1, out);
    return (void *)func_021B9BF0(*(void **)(BTL_SERVER_GetClientChecked(*(u8 * *)&((struct Obj09978 *)p)->f0, out[1]) + 4), out[0]);
}
