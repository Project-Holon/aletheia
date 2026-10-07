/*
 * file:     unit_021BF050_p21.c
 * unit:     yes
 * function: func_021C19A8, func_021C19DC, func_021C1A14, func_021C1A30
 * address:  0x021C19A8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_021C27E8 0x021C27E8 thumb ov099
 *   func_021C2864 0x021C2864 thumb ov099
 *   func_021BE6E4 0x021BE6E4 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021BB42C  0x021BB42C  thumb  ov099
 *   func_021BB4D0  0x021BB4D0  thumb  ov099
 *   func_021BB4EC  0x021BB4EC  thumb  ov099
 *   func_021C1C70  0x021C1C70  thumb  ov099
 *   func_021BF29C  0x021BF29C  thumb  ov099
 *   func_021B98F0  0x021B98F0  thumb  ov099
 *   func_021C205C  0x021C205C  thumb  ov099
 *   func_021C1C64  0x021C1C64  thumb  ov099
 */
#include "../../matched/include/Obj00008.h"

typedef unsigned char u8;

typedef unsigned int u32_021C19A8;

typedef unsigned short u16;

typedef unsigned long  u32_021C19DC;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef unsigned long  u32_021C1A14;

typedef int BOOL;

typedef unsigned long  u32_021C1A30;

extern void func_021C24A4(char *,int);
extern void func_021C27E8(void *,int);
extern void func_021C2864(void *,int);
extern void func_021BE6E4(char *);
extern void func_021C27E0(void *);
extern void func_021BB42C(void *p, int v);
extern void func_021BB4D0(char *p);
extern void func_021BB4EC(void *p);
extern void func_021C1C70(char *p);
extern void func_021BF29C(char *p);
extern void func_021B98F0(void *p);
extern void func_021C205C(u8 *p, int v);
extern u8 func_021C1C64(char *p);
void func_021C19A8(char *p);
void func_021C19DC(char *p, int v);
void func_021C1A14(char *p, int b, void *c);
void func_021C1A30(u8 *p, int v);

void func_021C19A8(char *p){func_021C24A4(p,127);func_021C27E8(((struct Obj00008 *)p)->f8,*(u8 *)(*(u32_021C19A8 *)&((struct Obj00008 *)p)->f248+0x46));func_021C2864(((struct Obj00008 *)p)->f8,*(u8 *)(*(u32_021C19A8 *)&((struct Obj00008 *)p)->f248+0x46));func_021BE6E4(p);func_021C27E0(((struct Obj00008 *)p)->f8);}


/*
 * The ordered teardown of the block: five one-argument steps on p, the re-arm
 * of the 0x274-offset sub-object, and finally func_021C205C with the selector.
 */
void func_021C19DC(char *p, int v)
{
    func_021BB42C(p, v);
    func_021BB4D0(p);
    func_021BB4EC(p);
    func_021C1C70(p);
    func_021BF29C(p);
    func_021B98F0(p + 0x274);
    func_021C205C((u8 *)p, v);
}


/*
 * When the byte 0x8ED bytes in matches, hands the block and the third argument on.
 */
void func_021C1A14(char *p, int b, void *c)
{
    if (b == func_021C1C64(p)) {
        func_021C19DC(p, (int)c);
    }
}


/*
 * When the byte 0x8EF bytes in is set, hands the block and the selector to
 * func_021C19DC.  The selector is live into the call, which is why the image
 * materialises the 0x8EF constant in r2 rather than r1.
 */
void func_021C1A30(u8 *p, int v)
{
    if (p[0x8EF] != 0) {
        func_021C19DC((char *)p, v);
    }
}
