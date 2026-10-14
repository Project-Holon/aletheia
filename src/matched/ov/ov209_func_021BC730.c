/*
 * function: ZUKAN_LIST_RequestFade
 * address: 0x021BC730
 * packet: pkt_ov209_021BC730
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056BC 0x020056BC thumb
 *   PALANM_RequestFade 0x0202173C thumb
 */
#include "../include/Obj00088.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_020056BC(void);
extern int PALANM_RequestFade(void *, u16, u16, short, u8, u8, u16, void *);
void ZUKAN_LIST_RequestFade(char *p, u8 a, u8 b)
{
    void *ctx;
    ctx = (void *)func_020056BC();
    PALANM_RequestFade(((struct Obj00088 *)p)->fC, 1, 0xBFFF, -14, a, b, 0, ctx);
    ctx = (void *)func_020056BC();
    PALANM_RequestFade(((struct Obj00088 *)p)->fC, 2, 0xFFEF, -14, a, b, 0, ctx);
    ctx = (void *)func_020056BC();
    PALANM_RequestFade(((struct Obj00088 *)p)->fC, 4, 0xF878, -14, a, b, 0, ctx);
    ctx = (void *)func_020056BC();
    PALANM_RequestFade(((struct Obj00088 *)p)->fC, 8, 0xBFFF, -14, a, b, 0, ctx);
}
