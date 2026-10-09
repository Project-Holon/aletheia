/*
 * file:     net_state_p41.c
 * unit:     yes
 * function: func_0203D5AC, func_0203D5D4, func_0203D5EC, func_0203D610
 * address:  0x0203D5AC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj11374.h"
#include "../../matched/include/Obj11375.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef signed int     s32;

extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern struct Entry *func_0203996C(s32 idx);
extern void func_0203A458(u8 *a0, u32 a1);
void func_0203D5AC(int a, int b);
u32 func_0203D5D4(void);
u32 func_0203D5EC(void);
u32 func_0203D610(void);


/*
 * PROMOTED from src/pending/.  The `bl` to 0x0203A458 was this file's last
 * open site; it now resolves as `matched` against that function's own EXACT
 * shard entry, so the cap is gone.
 *
 * Sets the net context's +0x67 byte to the argument (after forcing the
 * context through func_0203D788), then updates the channel with
 * func_0203996C(0xff) and func_0203A458.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D5AC.c \
 *       --func func_0203D5AC --addr 0x0203D5AC --arm --cc 1.1p1
 */
void func_0203D5AC(int a, int b)
{
    u8 *p;

    func_0203D788();
    p = func_0203D798();
    p[0x67] = (u8)a;
    func_0203A458((u8 *)func_0203996C(0xff), a);
}



/*
 * Returns the byte at +0x67 of the net context, or 0 when there is none.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D5D4.c \
 *       --func func_0203D5D4 --addr 0x0203D5D4 --arm --cc 1.1p1
 */
u32 func_0203D5D4(void)
{
    u8 *p = func_0203D798();

    return p != 0 ? p[0x67] : 0;
}



/*
 * Calls the net context's +0x44 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D5EC.c \
 *       --func func_0203D5EC --addr 0x0203D5EC --arm --cc 1.1p1
 */
u32 func_0203D5EC(void)
{
    u8 *p = func_0203D788();

    if (((struct Obj11374 *)p)->f44 == 0) {
        return 0;
    }
    return ((u32 (*)(u32)) * (u32 *)(p + 0x44))(((struct Obj11374 *)p)->f34C);
}



/*
 * Calls the net context's +0x40 callback with its +0x34c argument, or
 * returns 0 when no callback is installed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D610.c \
 *       --func func_0203D610 --addr 0x0203D610 --arm --cc 1.1p1
 */
u32 func_0203D610(void)
{
    u8 *p = func_0203D788();

    if (((struct Obj11375 *)p)->f40 == 0) {
        return 0;
    }
    return ((u32 (*)(u32)) * (u32 *)(p + 0x40))(((struct Obj11375 *)p)->f34C);
}
