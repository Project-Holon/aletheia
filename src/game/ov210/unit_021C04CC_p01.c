/*
 * file:     unit_021C04CC_p01.c
 * unit:     yes
 * function: func_021C04CC, func_021C0550
 * address:  0x021C04CC
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
 *   d_021C0CC0 0x021C0CC0 data a4
 *   func_021B796C 0x021B796C thumb ov067
 *   func_02045808 0x02045808 arm
 */
#include "../../matched/include/Obj06699.h"
#include "../../matched/include/Obj14683.h"

struct S;
struct Tmpl;
struct U16Vec;
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
extern void func_021B796C(struct S *s);
extern void func_02045808(struct U16Vec *vec);
void func_021C04CC(char *ctx);
void func_021C0550(int p);
extern const Template d_021C0CC0;

void func_021C04CC(char *ctx)
{
    void *archive = func_020490F4(159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0CC0;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    ((struct Obj06699 *)ctx)->f1E0 = func_021B7754((struct Tmpl *)(&config), 123);
    ((struct Obj06699 *)ctx)->f2AC = config.count;
    func_021B7A10(((struct Obj06699 *)ctx)->f1E0, (unsigned int)archive, 98, 0, 0);
    func_021B7A4C(((struct Obj06699 *)ctx)->f1E0, archive, 73, 2, 3);
    func_02049238(archive);
    for (i = 0; i < 14; i++) func_021B79E4(((struct Obj06699 *)ctx)->f1E0, 0, i);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C0550(int p)
{
    unsigned i;

    func_021B796C((struct S *)(((struct Obj14683 *)p)->f1E0));
    ((struct Obj14683 *)p)->f1E0 = 0;
    for (i = 0; i < 0x32; i++) {
        int *q = (int *)(p + i * 4);

        if (q[0x79] != 0) {
            func_02045808((struct U16Vec *)q[0x79]);
            q[0x79] = 0;
        }
    }
}
