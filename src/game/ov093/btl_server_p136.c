/*
 * file:     btl_server_p136.c
 * unit:     yes
 * function: func_021CED4C, func_021CEDC0
 * address:  0x021CED4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E9CE0  0x021E9CE0  thumb  ov093
 *   func_021CE0BC  0x021CE0BC  thumb  ov093
 *   func_021E9B14  0x021E9B14  thumb  ov093
 *   func_021E9B20  0x021E9B20  thumb  ov093
 *   func_021CE150  0x021CE150  thumb  ov093
 *   func_021CEA94  0x021CEA94  thumb  ov093
 *   func_021CE3C8  0x021CE3C8  thumb  ov093
 *   func_021CF8D4 0x021CF8D4 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021E9A78 0x021E9A78 thumb ov093
 *   func_021CEE98 0x021CEE98 thumb ov093
 *   func_021CEEA8 0x021CEEA8 thumb ov093
 *   func_021D8394 0x021D8394 thumb ov093
 *   func_021CF220 0x021CF220 thumb ov093
 *   func_021CE4D0 0x021CE4D0 thumb ov093
 */
#include "../../matched/include/Obj05199.h"
#include "../../matched/include/Obj03194.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021E9CE0(u8 *p, u8 a, u8 b);
extern int func_021CE0BC(u8 *p, void *q);
extern void func_021E9B14(unsigned int *p);
extern int func_021E9B20(u8 *p);
extern void func_021CE150(u8 *p, void *q);
extern int func_021CEA94(u8 *p, u32 *state);
extern int func_021CE3C8(u8 *p, int *state);
extern u32 func_021CF8D4(u8 *, void *, u8 *, u16 *);
extern u8 func_021D5440(u8 *p);
extern void func_021E9A78(char *, const u8 *, int, int, u8 *);
extern u32 func_021CEE98(u8 *);
extern u32 func_021CEEA8(u8 *);
extern void func_021D8394(void *, u8, u32);
extern u32 func_021CF220(u8 *p, int *st);
extern int func_021CE4D0(u8 *p, u32 *st);
u32 func_021CED4C(u8 *p, s32 *st);
u32 func_021CEDC0(u8 *p, int *st);


u32 func_021CED4C(u8 *p, s32 *st)
{
    u32 r;
    switch (*st) {
    case 0:
        func_021E9CE0((u8 *)(((struct Obj05199 *)p)->f54), p[0x1b0], p[0x1b1]);
        *st = *st + 1;
        break;
    case 1:
        r = 0;
        if (func_021CE0BC(p, 0) != 0) {
            func_021E9B14((unsigned int *)(((struct Obj05199 *)p)->f54));
            *st = 2;
            return r;
        }
        if (func_021E9B20((u8 *)(((struct Obj05199 *)p)->f54)) != 0) {
            func_021CE150(p, (void *)((u32)func_021CEA94));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(((struct Obj05199 *)p)->f54)) != 0) {
            func_021CE150(p, (void *)((u32)func_021CE3C8));
        }
        break;
    }
    return 0;
}


u32 func_021CEDC0(u8 *p, int *st)
{
    u8 a;
    u16 b;
    u32 r, n;
    switch (*st) {
    case 0:
        r = 0;
        if ((u8)func_021CF8D4(p, ((struct Obj03194 *)p)->f8, &a, &b) != 4 ||
            a == func_021D5440(((struct Obj03194 *)p)->f8)) r = 1;
        func_021E9A78(*(char * *)&((struct Obj03194 *)p)->f54, p + 0x184, p[0x11d], r, p + 0x190);
        ++*st;
        break;
    case 1:
        r = 0;
        if (func_021CE0BC(p, 0)) {
            func_021E9B14((unsigned int *)(*(u32 *)&((struct Obj03194 *)p)->f54));
            *st = 2;
            return r;
        }
        if (func_021E9B20((u8 *)(*(u32 *)&((struct Obj03194 *)p)->f54))) {
            if (func_021CEE98(p + 0x190) == 0) {
                n = func_021CEEA8(p + 0x190);
                if (n < 6) {
                    func_021D8394(((struct Obj03194 *)p)->fC, p[0x11d], n);
                    func_021CE150(p, (void *)((u32)func_021CF220));
                    break;
                }
            }
            func_021CE150(p, (void *)((u32)func_021CE4D0));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(*(u32 *)&((struct Obj03194 *)p)->f54))) func_021CE150(p, (void *)((u32)func_021CE3C8));
        break;
    }
    return 0;
}
