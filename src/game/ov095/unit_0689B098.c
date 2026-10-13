/*
 * file:     unit_0689B098.c
 * unit:     yes
 * function: func_0689B098, func_0689B0D4
 * address:  0x0689B098
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   BTL_MAIN_GetRule  0x021B8588  thumb
 *   func_021B8D8C  0x021B8D8C  thumb
 *   func_021B99E0  0x021B99E0  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTL_CALC_GetCurseTargetKind  0x021D80A8  thumb
 *   BTL_ACTION_SetFight  0x021D82D0  thumb
 *   func_0689AE34 0x0689AE34 thumb ov095
 *   func_0689B354  0x0689B354  thumb  ov095
 */
#include "../../matched/include/Obj00409.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 pad : 7;
    u32 id : 16;
    u32 rest : 9;
} Q;

extern void func_0689AE34(u8 *list, u8 n, int unused, u8 *s);
extern void func_0689B354(u8 *p, u8 *s);
extern int BTL_MAIN_GetRule(u32 a);
extern u32 BTL_POKEPARAM_GetPokeId(u32 a);
extern void func_021B8D8C(u32 a, u32 b, u32 c);
extern u8 *func_021B99E0(void);
extern void BTL_ACTION_SetFight(Q *q, u16 id, u8 c);
extern u8 WAZA_TOOL_GetParam(u16 id, int k);
extern u8 BTL_CALC_GetCurseTargetKind(u32 a);
void func_0689B098(u8 *p, u8 *s);
u8 func_0689B0CC(u8 *p);
int func_0689B0D4(int unused, u8 *s);


/*
 * trailing: unlabelled byte accessor at 0x0689B0CC, followed by alignment padding.
 */
void func_0689B098(u8 *p, u8 *s)
{
    if (p[0] != 0) {
        func_0689AE34(p + 3, p[0], 0, s);
    } else if (p[2] == 1) {
        func_0689AE34(p + 3, p[1], 1, s);
    } else {
        func_0689AE34(p + 3, p[1], 2, s);
    }
}


u8 func_0689B0CC(u8 *p)
{
    return p[0x89];
}


int func_0689B0D4(int unused, u8 *s)
{
    u8 c;

    func_0689B354(s + 0x80, s);
    if (BTL_MAIN_GetRule(*(u32 *)&((struct Obj00409 *)s)->fA0) == 2) {
        c = 6;
        if (s[0x80] != 0) {
            func_021B8D8C(*(u32 *)&((struct Obj00409 *)s)->fA0, *(u32 *)&((struct Obj00409 *)s)->fA4,
                          BTL_POKEPARAM_GetPokeId(*(u32 *)&((struct Obj00409 *)s)->f6C));
            c = func_021B99E0()[4];
        }
        BTL_ACTION_SetFight(*(Q * *)&((struct Obj00409 *)s)->f70, (*(Q * *)&((struct Obj00409 *)s)->f70)->id, c);
        s[0x89] = 1;
    }
    func_0689B098(s + 0x80, s);
    s[0x89] = 0;
    s[0x8a] = WAZA_TOOL_GetParam((*(Q * *)&((struct Obj00409 *)s)->f70)->id, 0x1b);
    if ((*(Q * *)&((struct Obj00409 *)s)->f70)->id == 0xae)
        s[0x8a] = BTL_CALC_GetCurseTargetKind(*(u32 *)&((struct Obj00409 *)s)->f6C);
    return 1;
}
