/*
 * function: UNION_EFF_AddAnimObj
 * address: 0x0217F9DC
 * packet: pkt_ov019_0217F9DC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02180814 0x02180814 data ov019 a4
 *   func_02034714 0x02034714 arm
 *   UNION_EFF_GetFreeAnimObj 0x0217FB30 thumb ov019
 *   UNION_EFF_CreateAnimObj 0x0217FA10 thumb ov019
 */
#include "../include/Obj09420.h"

typedef unsigned int u32;
typedef unsigned short u16;
struct E { u32 a,b,c,d; u16 h; };
extern const char d_02180814[];
extern void func_02034714(const char *expr, u32 line, const char *file);
extern struct E *UNION_EFF_GetFreeAnimObj(struct E *p);
extern void UNION_EFF_CreateAnimObj(char *p, u32 *out, u32 a, u16 b);
void UNION_EFF_AddAnimObj(char *p, u32 a)
{
    struct E *e;
    if (((struct Obj09420 *)p)->f14 == 0) func_02034714(d_02180814,0,d_02180814);
    e=UNION_EFF_GetFreeAnimObj((struct E *)p);
    UNION_EFF_CreateAnimObj(p,(u32 *)e,a,((struct Obj09420 *)p)->f1C);
    (((struct Obj09420 *)p)->f1C)++;
}
