/*
 * function: ISS_ROAD_SYS_HasPlayerMoved
 * address:  0x0202B254
 * region:   arm9
 * packet:   pkt_0202B230
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Compares the 12 bytes at +0xc against the record func_02012AA0 returns from
 * the pointer at +8, then copies the record over them either way, and reports
 * whether they differed.
 *
 * The guard has to be written as a conjunction of equalities over subscripts:
 * `if (s[0] == d[0] && s[1] == d[1] && s[2] == d[2]) differ = 0; else differ = 1;`
 * Each test then branches *away* to the shared "1" block and the "0" block falls
 * through, which is the original's shape (movs r3,#0; b over; movs r3,#1).  The
 * disjunction of inequalities - `differ = (s[0] != d[0]) || ...` - is the same
 * value but emits the last test with the opposite polarity and an inline
 * `movs r3,#1`, five bytes away; the ternary spelling of the same conjunction
 * keeps the polarity but moves the copy, and loses the match.
 *
 * Closes the blocker of src/pending/ISS_ROAD_SYS_UpdateVolume.c, and through it
 * src/pending/ISS_ROAD_SYS_Update.c and src/pending/ISS_SYS_UpdateRoad.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ROAD_SYS_HasPlayerMoved.c \
 *       --func ISS_ROAD_SYS_HasPlayerMoved --addr 0x0202B254 --thumb --cc 1.1p1
 */
#include "../include/Obj03001.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct S {
    u32 a;
    u32 b;
    u32 c;
};

struct Rec44;
struct Vec12;
extern struct Vec12 *func_02012AA0(struct Rec44 *p);

u32 ISS_ROAD_SYS_HasPlayerMoved(u8 *p)
{
    u32 *s = (u32 *)func_02012AA0((struct Rec44 *)(((struct Obj03001 *)p)->f8));
    int differ;

    if (s[0] == ((struct Obj03001 *)p)->fC && s[1] == ((struct Obj03001 *)p)->f10 &&
        s[2] == ((struct Obj03001 *)p)->f14) {
        differ = 0;
    } else {
        differ = 1;
    }
    *(struct S *)(p + 0xc) = *(struct S *)s;
    return (u32)differ;
}
