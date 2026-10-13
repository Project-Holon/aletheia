/*
 * function: BTL_CLIENT_StepTransformMon
 * address:  0x021D28AC
 * packet:   pkt_ov093_021D28AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_MAIN_GetViewPosOfPoke  0x021B8DC0  thumb  ov093
 *   BTL_POKEPARAM_Transform  0x021D6C50  thumb  ov093
 *   func_021EA8B4  0x021EA8B4  thumb  ov093
 *   func_021EA8D4  0x021EA8D4  thumb  ov093
 */
#include "../include/Obj03693.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern unsigned char BTL_MAIN_GetViewPosOfPoke(unsigned char *p, void *a, unsigned int b);
struct Unk021D6C50;
extern int BTL_POKEPARAM_Transform(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern void func_021EA8B4(char *ctx, u32 a, u32 b);
extern int func_021EA8D4(u32 *p);

int BTL_CLIENT_StepTransformMon(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 *a = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj03693 *)p)->f4, (u8)c[0]);
        u8 *b = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj03693 *)p)->f4, (u8)c[1]);
        int d = (int)BTL_MAIN_GetViewPosOfPoke(((struct Obj03693 *)p)->f0, ((struct Obj03693 *)p)->f4, (u8)c[0]);
        int e = (int)BTL_MAIN_GetViewPosOfPoke(((struct Obj03693 *)p)->f0, ((struct Obj03693 *)p)->f4, (u8)c[1]);
        BTL_POKEPARAM_Transform((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b);
        func_021EA8B4(((struct Obj03693 *)p)->f54, d, e);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA8D4(((struct Obj03693 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}
