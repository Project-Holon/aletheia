/*
 * function: func_021BC274
 * address: 0x021BC274
 * packet: pkt_ov223_021BC274
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BC2CA is zero alignment; no follower.
 * symbols:
 *   func_021B9D4C 0x021B9D4C thumb ov223
 *   func_021BA2B4 0x021BA2B4 thumb ov223
 *   func_021BB964 0x021BB964 thumb ov223
 *   func_021B9C58 0x021B9C58 thumb ov223
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 */
#include "../include/Obj00738.h"
extern void func_021B9C58(char *);
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_021B9A8C(char *p);
extern void func_020061E4(u32 a);
extern void func_021B9D4C(char *);
struct Main;
extern void func_021BA2B4(struct Main *p);
extern void func_021BB964(char *);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
int func_021BC274(char *p,unsigned *state)
{
    func_021B9C58(p);
    func_021B9D4C(p); func_021BA2B4((struct Main *)p); func_021BB964(p);
    switch(*state) {
    case 0: FADE_Start(12,0,16,2); (*state)++; break;
    case 1: if(!FADE_IsActive()) { ((struct Obj00738 *)p)->f10=0; return 11; } break;
    }
    (((struct Obj00738 *)p)->f10)++;
    return 10;
}
