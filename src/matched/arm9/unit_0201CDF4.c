/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201CDF4
 * packet:   pkt_0201C974
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PRINTSYS_SplitWait, PRINTSYS_PrintStreamStop, PRINTSYS_PrintStreamRun, PRINTSYS_PrintStreamGetState,
 *           PRINTSYS_PrintStreamGetWaitKind, PRINTSYS_PrintStreamReleasePause, PRINTSYS_PrintStreamDelete
 *
 * PRINTSYS_SplitWait splits a signed delta into a sign-magnitude pair of output
 * bytes: byte[1]=1 and byte[0]=the value when it is non-negative, byte[1]=
 * the absolute value and byte[0]=0 when it is negative.  The two branches
 * store to the two bytes in opposite order from each other, which is what
 * the original does and is not an artefact of how it is written.
 *
 * PRINTSYS_PrintStreamStop, PRINTSYS_PrintStreamRun and PRINTSYS_PrintStreamReleasePause are three single-bit
 * operations on a byte at offset 0x22 of an object: set bit 0 (written
 * through a redundant clear-then-set, `(x & ~1) | 1`, rather than a plain
 * `x |= 1`, which is what the bytes show), clear bit 0, and set bit 2 with
 * a plain OR.  All three read and write the field through two separate
 * `((u8 *)p)[0x22]` expressions rather than a named pointer local, which is
 * what keeps the load address and the store address computed independently
 * the way the original does it.
 *
 * PRINTSYS_PrintStreamGetState and PRINTSYS_PrintStreamGetWaitKind are the two four-byte word getters this
 * neighbourhood keeps reusing (the same shape as
 * src/matched/unit_0201AA14.c's pair); disasm.py's prologue sweep does not
 * label either of them, since a two-instruction leaf saves nothing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), so both were
 * read directly out of the `.word` run the listing prints between
 * PRINTSYS_PrintStreamRun and PRINTSYS_PrintStreamReleasePause.
 *
 * PRINTSYS_PrintStreamDelete frees and clears an owned pointer at offset 0x10 if it is
 * non-null.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CDF4.c \
 *       --addr 0x0201CDF4 --thumb
 *
 * symbols:
 *   TCBL_DeleteTask  0x02031194  arm
 */
#include "../include/Obj17219.h"
#include "../include/Obj17220.h"

typedef unsigned char u8;
typedef unsigned int u32;

void PRINTSYS_SplitWait(int v, u8 *out)
{
    if (v >= 0) {
        out[1] = 1;
        out[0] = (u8)v;
    } else {
        out[1] = (u8)(-v);
        out[0] = 0;
    }
}

void PRINTSYS_PrintStreamStop(void *p)
{
    ((u8 *)p)[0x22] = (((u8 *)p)[0x22] & ~1u) | 1u;
}

void PRINTSYS_PrintStreamRun(void *p)
{
    ((u8 *)p)[0x22] = ((u8 *)p)[0x22] & ~1u;
}

u32 PRINTSYS_PrintStreamGetState(void *p)
{
    return ((struct Obj17219 *)p)->f0;
}

u32 PRINTSYS_PrintStreamGetWaitKind(void *p)
{
    return ((struct Obj17220 *)p)->f4;
}

void PRINTSYS_PrintStreamReleasePause(void *p)
{
    ((u8 *)p)[0x22] = ((u8 *)p)[0x22] | 4u;
}

struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);

struct Rec3 {
    u32 pad[4];
    void *unk10;
};

void PRINTSYS_PrintStreamDelete(struct Rec3 *p)
{
    if (p->unk10 != 0) {
        TCBL_DeleteTask(p->unk10);
        p->unk10 = 0;
    }
}
