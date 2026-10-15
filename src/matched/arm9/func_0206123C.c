/*
 * function: NNSi_FndAllocBlockFromHeap
 * address:  0x0206123C
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_FndPopFreeBlock   0x02061224  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *
 * A 64-byte allocate-or-fetch helper: it hands the address of the object's
 * field at +0x24 to NNSi_FndPopFreeBlock, and if that returns non-null clears the
 * block it belongs to with MIi_CpuClear32(0, p, o->unk28).
 *
 * Two source shapes are load-bearing and both were measured against the bytes:
 *
 * 1. The guard must be written positively -- `if (p != 0) { ... }` -- not as
 *    an early `if (p == 0) return 0;`.  With the early return mwccarm 1.1p1
 *    hoists the `ldr r2, [r5, #0x28]` (the size) below the `beq` and the file
 *    is five sites wrong; with the body inside the arm the load is issued
 *    between the flag load and the mask, exactly as the original does.  See
 *    docs/idioms/a-guard-whose-arm-can-carry-the-body-is-not-predicated.md.
 * 2. The size has to reach the call through a named local (`u32 size;
 *    size = o->unk28;`) rather than as the call's third argument written out
 *    at the call site: the local pins the load above the mask test, and
 *    nothing else in the function moves once both loads are in that order.
 *
 * The `and r0, r0, #0xff` before the `tst r0, #1` is the u8 narrowing of the
 * flag field; the field itself is a word (a plain `ldr`, not an `ldrb`), so
 * the cast is in the source, and `((u8)o->unk20) & 1` is the spelling that
 * keeps both instructions -- `(o->unk20 & 0xff) & 1` folds the mask away and
 * costs four bytes.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_FndAllocBlockFromHeap.c \
 *       --func NNSi_FndAllocBlockFromHeap --addr 0x0206123C --arm --cc 1.1p1
 *   EXACT, 64 bytes, 2 relocation sites, all 2 resolved.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big0206123C {
    u32 w[8];
    u32 unk20;
    u32 unk24;
    u32 unk28;
};

extern void *NNSi_FndPopFreeBlock(int **p);
extern void MIi_CpuClear32(u32 val, void *dst, u32 size);

void *NNSi_FndAllocBlockFromHeap(struct Big0206123C *o)
{
    u32 size;
    void *p = NNSi_FndPopFreeBlock((int **)(&o->unk24));

    if (p != 0) {
        size = o->unk28;
        if (((u8)o->unk20) & 1) {
            MIi_CpuClear32(0, p, size);
        }
    }
    return p;
}
