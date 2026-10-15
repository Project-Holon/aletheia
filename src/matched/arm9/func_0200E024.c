/*
 * function: SYMBOL_SAVE_UpdateChecksum
 * address:  0x0200E024
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203F2FC  0x0203F2FC  arm
 *   func_0203F328  0x0203F328  arm
 *
 * The 0x84C-byte save block's commit, and the second instance of the
 * 0x02FFFC3C idiom (see src/matched/unit_02008C58.c, which is the same block
 * 0x1E0 bytes smaller): the shared word is read TWICE and the two reads are not
 * commoned up, which is a `volatile` read and nothing else, and the two halves
 * are combined as `a << 8 | b`.
 *
 * The write at +0x84E is followed by a readback test against 0 and a store of 1
 * if it came back 0 -- the field is volatile all the way through, which is why
 * the `ldrh` is not folded away.  The checksum pair is the same shape as the
 * one in unit_02008C58.c: func_0203F2FC computes it over (obj, 0x84C) and
 * func_0203F328 writes it back with the +0x84E halfword as the high word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_UpdateChecksum.c \
 *       --func SYMBOL_SAVE_UpdateChecksum --addr 0x0200E024 --cc 1.1p1 --thumb
 */
#include "../include/Obj00318.h"

typedef unsigned short u16;
typedef unsigned int   u32;

typedef unsigned char  u8;
extern u32 func_0203F2FC(const u8 *p, u32 len);
extern void func_0203F328(u16 *p, u32 size, u32 seed);

#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)

void SYMBOL_SAVE_UpdateChecksum(void *obj)
{
    u32 a = unk_02FFFC3C;
    u32 b = unk_02FFFC3C;

    ((struct Obj00318 *)obj)->f84E = a << 8 | b;
    if (((struct Obj00318 *)obj)->f84E == 0) {
        ((struct Obj00318 *)obj)->f84E = 1;
    }
    ((struct Obj00318 *)obj)->f84C = func_0203F2FC(obj, 0x84c);
    func_0203F328(obj, 0x84c,
                  ((struct Obj00318 *)obj)->f84C +
                  (((struct Obj00318 *)obj)->f84E << 16));
}
