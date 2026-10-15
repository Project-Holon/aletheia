/*
 * function: BR_CODEIN_ProfileSetupSprite
 * address: 0x021E0840
 * packet: pkt_ov183_021E0840
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   func_02034714 0x02034714 arm
 *   d_021E3978 0x021E3978 data ov183
 */
#include "../include/Obj00143.h"
struct Triple { int a, b, c; };
extern int BR_RES_GetSprite(void *, int, struct Triple *);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern char d_021E3978[];
void BR_CODEIN_ProfileSetupSprite(char *p)
{
    struct Triple t;
    if (!BR_RES_GetSprite(((struct Obj00143 *)p)->f344, 11, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    ((struct Obj00143 *)p)->f260 = t.c;
    ((struct Obj00143 *)p)->f26C = t.b;
    ((struct Obj00143 *)p)->f284 = t.a;
    if (!BR_RES_GetSprite(((struct Obj00143 *)p)->f344, 12, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    ((struct Obj00143 *)p)->f268 = t.c;
    ((struct Obj00143 *)p)->f274 = t.b;
    ((struct Obj00143 *)p)->f28C = t.a;
    if (!BR_RES_GetSprite(((struct Obj00143 *)p)->f344, 6, &t)) func_02034714(d_021E3978, 0, d_021E3978);
    *(int *)&((struct Obj00143 *)p)->f264 = t.c;
    *(int *)&((struct Obj00143 *)p)->f270 = t.b;
    *(int *)&((struct Obj00143 *)p)->f288 = t.a;
}
