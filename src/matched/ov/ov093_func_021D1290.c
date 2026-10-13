/*
 * function: func_021D1290
 * address: 0x021D1290
 * packet: pkt_ov093_021D1290
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the 0x1B2 bit5 test is a byte bitfield, not a shifted integer mask.
 * symbols:
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021D13A4 0x021D13A4 thumb ov093
 *   BTL_MAIN_IsMultiMode 0x021B86C8 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 *   BTL_MAIN_GetWinBgm 0x021B86DC thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 */
#include "../include/Obj00066.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags;
extern u8 func_021B904C(u8 *p, int k);
extern int func_021D13A4(void *);
struct H;
struct L;
extern int BTL_MAIN_IsMultiMode(unsigned char **p);
extern void func_021B916C(u8 *p, u32 x);
extern u16 BTL_MAIN_GetWinBgm(void **p);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern void GFL_USE_CancelChangeAndPlayBgm(u16, u16);
extern void GFL_USE_FadeOutBgm(u32);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
int func_021D1290(u8 *p, int *state, void *a2)
{
    int idx;
    int mode;
    u8 flag;
    u16 msg;
    switch (*state) {
    case 0:
        if (((Flags *)p)->flag != 0)
            return 1;
        idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
        mode = func_021D13A4(p);
        flag = BTL_MAIN_IsMultiMode((unsigned char **)(*(u8 * *)&((struct Obj00066 *)p)->f0));
        func_021B916C(((struct Obj00066 *)p)->f0, mode);
        switch (mode) {
        case 1: msg = flag != 0 ? 0x31 : 0x30; break;
        case 0: msg = flag != 0 ? 0x33 : 0x32; break;
        case 2: msg = flag != 0 ? 0x35 : 0x34; break;
        default: return 1;
        }
        func_021EAF18((struct L *)(p + 0x58), 1, msg);
        func_021EAF50((struct L *)(p + 0x58), idx);
        if (flag != 0)
            func_021EAF50((struct L *)(p + 0x58), func_021B904C(((struct Obj00066 *)p)->f0, 1));
        func_021EA614(((struct Obj00066 *)p)->f54, (struct H *)(p + 0x58));
        if (mode == 1) {
            GFL_USE_CancelChangeAndPlayBgm(BTL_MAIN_GetWinBgm(((struct Obj00066 *)p)->f0), 0xFFFF);
            (*state)++;
        } else {
            GFL_USE_FadeOutBgm(0x1E);
            *state += 2;
        }
        break;
    case 1:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0)
            return 1;
        break;
    case 2:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0)
            (*state)++;
        break;
    case 3:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            return 1;
        }
        break;
    }
    return 0;
}
