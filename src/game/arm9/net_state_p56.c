/*
 * file:     net_state_p56.c
 * unit:     yes
 * function: func_0203D650, func_0203D668, func_0203D680
 * address:  0x0203D650
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
 *   file_020A7CF8  0x020A7CF8  data
 */
#include "../../matched/include/Obj15989.h"
#include "../../matched/include/Obj15990.h"

typedef unsigned char u8;

typedef unsigned int  u32;

extern void *func_0203D788(void);
extern void func_02034714(const char *file, u32 line, const char *msg);
u32 func_0203D650(void);
void func_0203D668(u32 v);
u32 func_0203D680(void);
extern const char file_020A7CA0[];
extern const char file_020A7CF8[];



/*
 * Returns the word at +0x34c of the net context, or 0 when there is none.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D650.c \
 *       --func func_0203D650 --addr 0x0203D650 --arm --cc 1.1p1
 */
u32 func_0203D650(void)
{
    u8 *p = func_0203D788();

    return p != 0 ? ((struct Obj15989 *)p)->f34C : 0;
}



/*
 * Stores the argument at +0x34c of the net context, when there is one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D668.c \
 *       --func func_0203D668 --addr 0x0203D668 --arm --cc 1.1p1
 */
void func_0203D668(u32 v)
{
    u8 *p = func_0203D788();

    if (p != 0) {
        ((struct Obj15990 *)p)->f34C = v;
    }
}


/*
 * Returns the net context's +0x60 byte, reporting through func_02034714 with
 * the source file at 0x020A7CA0 ("net.c") and line 0x593 (1427) when the byte
 * is past 8.  The guard is unsigned (`bls`), so the comparison is
 * `> 8` against an unsigned char.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D680.c \
 *       --func func_0203D680 --addr 0x0203D680 --cc 1.1p1 --arm
 */
u32 func_0203D680(void)
{
    u8 *p = func_0203D788();

    if (p[0x60] > 8)
        func_02034714(file_020A7CA0, 0x593, file_020A7CF8);
    return p[0x60];
}
