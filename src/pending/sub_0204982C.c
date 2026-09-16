/*
 * unit:     no
 * function: sub_0204982C
 * address:  0x0204982C
 * packet:   pkt_0204968C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02062A00       0x02062A00  arm
 *   DC_FlushRange       0x020862F0  arm
 *   g_020A135C          0x020A135C  data
 *   ENV_SetResourceSet  0x020307B0  arm
 *
 * Byte-correct, capped at MATCH. Blocked on: g_020A135C (0x020A135C) is named
 * by exactly one word in the whole image, the pool word at 0x02049898 inside
 * this function, so the `literal` class has no witness outside the compared
 * range, and being plain data it has no other class available. The range is a
 * single function, so there is no cut to make. It needs a second reference
 * somewhere in the image, which does not exist, or an attested data
 * definition at 0x020A135C. The other three relocations resolve.
 *
 * This is the DMA-flush variant of src/matched/sub_0204968C.c: the same
 * func_02062A00 lookup (the sibling of func_02062A4C), the same "a size of
 * zero means the object's own size at +0x10" rule, then a `DC_FlushRange`
 * over the object's buffer and a dispatch through the five-entry function
 * table at 0x020A135C indexed by the second argument.
 *
 * The buffer pointer is read from the caller-owned local twice, once for the
 * flush and once for the dispatch, because the call between them may write
 * through the pointer the local holds.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204982C.c \
 *       --func sub_0204982C --addr 0x0204982C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Res {
    u8 pad_00[0x10];
    u32 unk_10;
    u32 unk_14;
};

extern s32 func_02062A00(void *buf, struct Res **out);
extern void DC_FlushRange(u32 addr, u32 size);
extern void (*g_020A135C[])(u32 addr, u32 a1, u32 size);
extern void ENV_SetResourceSet(void *p);

u32 sub_0204982C(void *buf, u32 kind, u32 a2, u32 size)
{
    struct Res *res;

    if (func_02062A00(buf, &res) != 0) {
        if (size == 0) {
            size = res->unk_10;
        }
        DC_FlushRange(res->unk_14, size);
        g_020A135C[kind](res->unk_14, a2, size);
    }

    ENV_SetResourceSet(buf);
    return size;
}
