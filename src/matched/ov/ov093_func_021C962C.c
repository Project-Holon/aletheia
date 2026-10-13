/*
 * function: func_021C962C
 * address:  0x021C962C
 * packet:   pkt_ov093_021C962C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C96B4  0x021C96B4  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   func_021C96C4  0x021C96C4  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_POKEPARAM_SetTypes  0x021D66B0  thumb  ov093
 *   BTLV_CORE_BytesEqual  0x021E8DA8  thumb  ov093
 *   BTLV_CORE_GetHighByte  0x021E8CFC  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021C96B4(int a, u8 b);
extern u8 *func_021B9934(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int func_021C96C4(int a);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_POKEPARAM_SetTypes(u8 *p, int n);
extern int BTLV_CORE_BytesEqual(int a);
extern u8 BTLV_CORE_GetHighByte(int v);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);

typedef struct { u32 w; u16 h4; u8 b6; u8 b7; } Ent;

int func_021C962C(int p, const Ent *e)
{
    int a;

    if (func_021C96B4(p + 0x1ab8, e->b6)) {
        a = (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b6);
        if (BTL_POKEPARAM_IsFainted((void *)a) == 0 && func_021C96C4(BTL_POKEPARAM_GetSpecies((void *)a)) == 0) {
            BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x16, e->b6, e->h4);
            BTL_POKEPARAM_SetTypes((void *)a, e->h4);
            if (e->b7 == 0 && BTLV_CORE_BytesEqual(e->h4))
                BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x380, e->b6, BTLV_CORE_GetHighByte(e->h4), 0xffff0000);
            return 1;
        }
    }
    return 0;
}
