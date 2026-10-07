/*
 * file:     btl_server_p150.c
 * unit:     yes
 * function: func_021D1708, func_021D171C
 * address:  0x021D1708
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
 *   func_021D13A4 0x021D13A4 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 *   func_021B86DC 0x021B86DC thumb ov093
 *   func_021F878C 0x021F878C thumb ov094
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021D185C 0x021D185C thumb ov093
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021EA600 0x021EA600 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 */
#include "../../matched/include/Obj00066.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags;

extern u32 func_021D13A4(void *);
extern void func_021B916C(u8 *p, u32 x);
extern u16 func_021B86DC(void **p);
extern void func_021F878C(u32 a);
extern u8 func_021B904C(u8 *p, int k);
extern unsigned short func_021BA020(char *p, int i);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void func_021F7998(u32 a);
extern void func_021D185C(void *, int, int);
extern int func_021F7EB4(void);
extern void func_021EA600(char *p);
extern int func_021EA710(u32 *p);
int func_021D1708(u8 *p, int *state);
int func_021D171C(u8 *p, int *state, void *a2);

/*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 */
int func_021D1708(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D171C(p, state, q);
    return 1;
}

/*
 * lever: the 0x1B2 bit5 test is a byte bitfield, preserving the shift pair.
 */
int func_021D171C(u8 *p, int *state, void *a2)
{
    u32 mode;
    int idx;
    switch (*state) {
    case 0:
        if (((Flags *)p)->flag != 0) return 1;
        mode = func_021D13A4(p);
        func_021B916C(((struct Obj00066 *)p)->f0, mode);
        if (mode == 1) func_021F878C(func_021B86DC(((struct Obj00066 *)p)->f0));
        if (mode <= 1) {
            idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
            func_021F7F58(func_021BA020(((struct Obj00066 *)p)->f0, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            func_021D185C(p, mode, 0);
            *state = 1;
        } else return 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EA600(((struct Obj00066 *)p)->f54);
            *state = 2;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0) {
            idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
            if (idx == func_021B904C(((struct Obj00066 *)p)->f0, 1)) return 1;
            func_021F7998(0x271);
            *state = 3;
        }
        break;
    case 3:
        if (func_021F7EB4() == 0) {
            mode = func_021D13A4(p);
            idx = func_021B904C(((struct Obj00066 *)p)->f0, 1);
            func_021F7F58(func_021BA020(((struct Obj00066 *)p)->f0, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            func_021D185C(p, mode, 1);
            *state = 4;
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            func_021EA600(((struct Obj00066 *)p)->f54);
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0) return 1;
        break;
    }
    return 0;
}
