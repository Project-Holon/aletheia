/*
 * packet: pkt_ov186_021FFEA8
 * function: BR_POKESEARCH_CreateBackButton
 * address: 0x021FFEA8
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   gBrPokeSearchAssertString 0x02200DAC data a1
 */
#include "../include/Obj04590.h"
typedef struct Request { unsigned short x, y, id; unsigned char flag, pad; } Request;
typedef unsigned int   u32;
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern int BR_RES_GetSprite(void *, unsigned, void *);
extern void *func_021FB378(void *, int, int, int, int, int, int, int, void *, unsigned short);
extern void *MI_CpuFill8(void *, int, unsigned);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char gBrPokeSearchAssertString[];
void BR_POKESEARCH_CreateBackButton(char *p)
{
    Request req;
    int info[3];
    int a = BR_RES_GetFont(*(char * *)&((struct Obj04590 *)p)->f28);
    int b = BR_RES_GetMsgData(*(char * *)&((struct Obj04590 *)p)->f28);
    MI_CpuFill8(&req, 0, 8);
    req.x = 0x50; req.y = 0xa8; req.id = 0; req.flag = 1;
    if (!BR_RES_GetSprite(((struct Obj04590 *)p)->f28, 6, info))
        func_02034714(gBrPokeSearchAssertString, 0, gBrPokeSearchAssertString);
    ((struct Obj04590 *)p)->f2C = func_021FB378(&req, 4, 0x60, 1, ((struct Obj04590 *)p)->f34, ((struct Obj04590 *)p)->f38, a, b, info, ((struct Obj04590 *)p)->f24);
}
