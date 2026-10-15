/*
 * function: WIFIBATTLEMATCH_NET_CompStepJ
 * address: 0x021D8E30
 * packet: pkt_ov175_021D8E30
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_NET_SetupRegSprite 0x021D98E4 thumb ov175
 *   WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone 0x021D9A08 thumb ov175
 *   WIFIBATTLEMATCH_NET_DeleteCompSprite 0x021D99F4 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepL 0x021D8FA8 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepI 0x021D8CF0 thumb ov175
 */
#include "../include/Obj00013.h"
typedef unsigned long u32;
extern void func_021E8738(int *p, int a, int b, int c);
extern void func_021E8AB4(u32, u32);
extern void func_021E8AA0(int *p, int v);
extern int func_021E8844(const int *p);
extern void func_021E8AB8(u32);
extern void WIFIBATTLEMATCH_NET_SetupRegSprite(u32 *p, int mode);
extern int WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone(char *);
extern void WIFIBATTLEMATCH_NET_DeleteCompSprite(char *);
extern void WIFIBATTLEMATCH_NET_CompStepL(u32 sys, int *state, char *ctx);
extern void WIFIBATTLEMATCH_NET_CompStepI(u32 sys, int *state, char *p);
void WIFIBATTLEMATCH_NET_CompStepJ(u32 sys, int *state, char *ctx)
{
    int result;
    switch (*state) {
    case 0:
        func_021E8738((int *)(((struct Obj00013 *)ctx)->f2C), ((struct Obj00013 *)ctx)->f14, 0x4e, 1);
        *state = 3;
        func_021E8AB4(sys, 1);
        break;
    case 1:
        WIFIBATTLEMATCH_NET_SetupRegSprite((u32 *)ctx, 0);
        *state = 2;
        break;
    case 2:
        result = WIFIBATTLEMATCH_NET_IsCompSpriteAnimDone(ctx);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteCompSprite(ctx);
            switch (result) {
            case 0: func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepL); break;
            case 1: func_021E8AA0((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepI); break;
            }
        }
        break;
    case 3:
        if (func_021E8844((const int *)(((struct Obj00013 *)ctx)->f2C))) func_021E8AB8(sys);
        break;
    }
}
