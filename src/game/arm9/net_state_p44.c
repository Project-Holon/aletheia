/*
 * file:     net_state_p44.c
 * unit:     yes
 * function: func_0203D6BC, func_0203D6CC, func_0203D700, func_0203D720, func_0203D754
 * address:  0x0203D6BC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_02034714  0x02034714  arm
 *   file_020A7CA0  0x020A7CA0  data
 *   file_020A7D2C  0x020A7D2C  data
 */
#include "../../matched/include/Obj15991.h"
#include "../../matched/include/Obj11377.h"
#include "../../matched/include/Obj11378.h"
#include "../../matched/include/Obj11379.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

extern u8 *func_0203D788(void);
extern void func_02034714(const char *file, u32 line, const char *msg);
extern struct Entry *func_020399A8(void);
u32 func_0203D6BC(void);
u32 func_0203D6CC(void);
void func_0203D700(void);
void func_0203D720(u32 a);
void func_0203D754(u32 a);
extern const char file_020A7CA0[];
extern const char file_020A7D2C[];



/*
 * Returns the byte at +0x61 of the net context.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D6BC.c \
 *       --func func_0203D6BC --addr 0x0203D6BC --arm --cc 1.1p1
 */
u32 func_0203D6BC(void)
{
    return func_0203D788()[0x61];
}



/*
 * Halfword getter for the null-test sibling of func_0203D680: reports through
 * func_02034714 at line 0x5B1 (1457) when func_0203D788 comes back null, then
 * reads +0x6C from it regardless.  The null test is the `movs r4, r0` /
 * `bne` pair, so the result is kept in a local that the tail still
 * dereferences rather than being re-requested.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D6CC.c  *       --func func_0203D6CC --addr 0x0203D6CC --cc 1.1p1 --arm
 */
u32 func_0203D6CC(void)
{
    u8 *p = func_0203D788();

    if (p == 0)
        func_02034714(file_020A7CA0, 0x5B1, file_020A7D2C);
    return ((struct Obj15991 *)p)->f6C;
}



/*
 * Calls the net context's +0x30 callback with its +0x34c argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D700.c \
 *       --func func_0203D700 --addr 0x0203D700 --arm --cc 1.1p1
 */
void func_0203D700(void)
{
    u8 *p = func_0203D788();

    if (((struct Obj11377 *)p)->f30 != 0) {
        ((void (*)(u32)) * (u32 *)(p + 0x30))(((struct Obj11377 *)p)->f34C);
    }
}



/*
 * Calls the net context's +0x28 callback with the func_020399A8 result,
 * the argument and the context's +0x34c value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D720.c \
 *       --func func_0203D720 --addr 0x0203D720 --arm --cc 1.1p1
 */
void func_0203D720(u32 a)
{
    u8 *p = func_0203D788();

    if (((struct Obj11378 *)p)->f28 == 0) {
        return;
    }
    ((void (*)(u32, u32, u32)) * (u32 *)(p + 0x28))(
        (u32)func_020399A8(), a, ((struct Obj11378 *)p)->f34C);
}



/*
 * Calls the net context's +0x24 callback with the func_020399A8 result,
 * the argument and the context's +0x34c value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D754.c \
 *       --func func_0203D754 --addr 0x0203D754 --arm --cc 1.1p1
 */
void func_0203D754(u32 a)
{
    u8 *p = func_0203D788();

    if (((struct Obj11379 *)p)->f24 == 0) {
        return;
    }
    ((void (*)(u32, u32, u32)) * (u32 *)(p + 0x24))(
        (u32)func_020399A8(), a, ((struct Obj11379 *)p)->f34C);
}
