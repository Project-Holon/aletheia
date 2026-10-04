/*
 * function: sub_02016028
 * address:  0x02016028
 * packet:   pkt_02015F2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 * status:   EXACT*
 *
 * symbols:
 *   func_020627D8  0x020627D8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02016984  0x02016984  thumb
 *   func_0206469C  0x0206469C  arm
 *
 * Reconfigures the object: derives a value from func_020627D8 on field
 * +0x28 and a caller-supplied flag truncated to 16 bits (the explicit
 * lsls/lsrs #0x10 pair in the original is exactly that narrowing cast in
 * the callee, not something the caller is trusted to have done), releases
 * the handle at +0x98 through func_020307B0 if one is set, calls
 * func_02016984(a, 1), passes the derived value into func_0206469C on the
 * member at +0x34, then clears bit 0 of the word at +0x144.
 *
 * Every concrete byte matches; func_02016984 (0x02016984, later in this
 * same packet, not yet matched) is called from exactly this one site in
 * the whole ROM, so that relocation stays unresolved under the honesty
 * rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02016028.c \
 *       --func sub_02016028 --addr 0x02016028 --cc 1.1p1
 *
 * The `matched` class does not reach it: func_02016984 is not matched, so
 * no EXACT entry covers that address. Closes to EXACT the day it is
 * matched, or gets a second caller elsewhere in the image.
 */
#include "../include/Obj02301.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct AnimBank;
struct AnimSequence;
struct Obj0206469C;
extern struct AnimSequence *func_020627D8(struct AnimBank *bank, u32 idx);
extern void func_020307B0(void *p);
extern void func_02016984(char *a0, int a1);
extern void func_0206469C(struct Obj0206469C *o, void *bank);

void sub_02016028(void *a, u32 flag)
{
    u8 *p = (u8 *)a;
    u32 value = (u32)func_020627D8((struct AnimBank *)(((struct Obj02301 *)p)->f28), (u16)flag);

    if (((struct Obj02301 *)p)->f98 != 0) {
        func_020307B0((void *)(((struct Obj02301 *)p)->f98));
    }

    func_02016984(a, 1);
    func_0206469C((struct Obj0206469C *)(p + 0x34), (void *)value);
    ((struct Obj02301 *)p)->f144 &= ~1u;
}
