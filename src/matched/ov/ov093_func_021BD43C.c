/*
 * function: BTL_SERVER_FLOW_ShiftPokes
 * address:  0x021BD43C
 * packet:   pkt_ov093_021BD43C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   BTL_MAIN_GetClientTrainerIndex  0x021B8BEC  thumb  ov093
 *   func_021BD4D4  0x021BD4D4  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_SetTurnFlag  0x021D5FC0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern char *func_021B9AEC(char *p, int i);
extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *p, u32 k, u8 n);
extern void func_021BD4D4(u8 *p, int a, int b);
struct S2;
extern void func_021B9C10(u32 *p, int a, int b);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *p);
struct UtilWork;
extern void BTL_POKEPARAM_SetTurnFlag(struct UtilWork *p, u32 n);

void BTL_SERVER_FLOW_ShiftPokes(u8 *p, int i, u8 a, u8 b, int c)
{
    char *s = func_021B9AEC(*(char * *)&((struct Obj00003 *)p)->f8, i);
    int x = BTL_MAIN_GetClientTrainerIndex(*(u8 * *)&((struct Obj00003 *)p)->f4, i, a);
    int y = BTL_MAIN_GetClientTrainerIndex(*(u8 * *)&((struct Obj00003 *)p)->f4, i, b);
    u8 *q;
    u8 *r;
    func_021BD4D4(p + 0x1ab8, x, y);
    func_021B9C10((u32 *)s, a, b);
    if (c == 0) {
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x44, i, x, y);
        q = (u8 *)func_021B9BF0((struct S2 *)s, a);
        r = (u8 *)func_021B9BF0((struct S2 *)s, b);
        if (!BTL_POKEPARAM_IsFainted(q)) BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)q, 0xc);
        if (!BTL_POKEPARAM_IsFainted(r)) BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)r, 0xc);
    }
}
