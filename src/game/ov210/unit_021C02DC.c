/*
 * file:     unit_021C02DC.c
 * unit:     yes
 * function: func_021C02DC, func_021C0384
 * address:  0x021C02DC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_021B7754 0x021B7754 thumb ov067
 *   func_021B7A10 0x021B7A10 thumb ov067
 *   func_021B7A4C 0x021B7A4C thumb ov067
 *   func_02049238 0x02049238 arm
 *   func_021B79E4 0x021B79E4 thumb ov067
 *   func_02045EC0 0x02045EC0 arm
 *   d_021C0C70 0x021C0C70 data a4
 *   func_021BCEF4 0x021BCEF4 thumb ov210
 *   d_021C0C48 0x021C0C48 data a4
 */
#include "../../matched/include/Obj04623.h"
#include "../../matched/include/Obj04624.h"

struct S;
struct Tmpl;
struct MsgBank;
typedef unsigned short u16;

typedef struct Template { unsigned char prefix[24]; unsigned char zero, count; unsigned short offset; unsigned words[2]; void *ctx; } Template;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern struct S *func_021B7754(struct Tmpl *tmpl, unsigned int heap);
extern void func_021B7A10(unsigned char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int index);
extern void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void func_02049238(void *);
extern void func_021B79E4(char *ctx, unsigned first, unsigned second);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u16 func_021BCEF4(int a0, int a1);
void func_021C02DC(char *ctx);
void func_021C0384(char *ctx);
extern const Template d_021C0C70;
extern const Template d_021C0C48;

void func_021C02DC(char *ctx)
{
    void *archive = func_020490F4(159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0C70;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    ((struct Obj04623 *)ctx)->f1E0 = func_021B7754((struct Tmpl *)(&config), 123);
    ((struct Obj04623 *)ctx)->f2AC = config.count;
    func_021B7A10(((struct Obj04623 *)ctx)->f1E0, (unsigned int)archive, 97, 0, 0);
    func_021B7A4C(((struct Obj04623 *)ctx)->f1E0, archive, 73, 2, 3);
    func_02049238(archive);
    for (i = 0; i < 26; i++) { func_021B79E4(((struct Obj04623 *)ctx)->f1E0, 0, i); ((void **)(ctx + 0x1e4))[i] = func_02045EC0(((struct Obj04623 *)ctx)->f1D0, i + 51); }
}

void func_021C0384(char *ctx)
{
    void *archive = func_020490F4(159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0C48;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    ((struct Obj04624 *)ctx)->f1E0 = func_021B7754((struct Tmpl *)(&config), 123);
    ((struct Obj04624 *)ctx)->f2AC = config.count;
    func_021B7A10(((struct Obj04624 *)ctx)->f1E0, (unsigned int)archive, 97, 0, 0);
    func_021B7A4C(((struct Obj04624 *)ctx)->f1E0, archive, 73, 2, 3);
    func_02049238(archive);
    for (i = 0; i <= 16; i++) { func_021B79E4(((struct Obj04624 *)ctx)->f1E0, 0, i); ((void **)(ctx + 0x1e4))[i] = func_02045EC0(((struct Obj04624 *)ctx)->f1D0, func_021BCEF4((int)ctx, i)); }
}
