/*
 * unit:     no
 * address:  0x020302A4
 * packet:   pkt_0202FC48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * function: sub_020302A4
 *
 * BLOCKED on one relocation site: all 160 concrete bytes are correct, but
 * the call to sub_02060CD0 at +0054 has no witness. 0x02060CD0 (the
 * expanded-heap resize primitive in the NNS-shaped library block around
 * 0x02060000) has exactly one branch reference in the image and it is this
 * call; the neighbouring 0x02060CA0 used by sub_02030098 has four and
 * resolves fine. No cut exists inside a single function section, so
 * --suggest-split offers nothing. An EXACT entry for 0x02060CD0 promotes
 * this file unchanged, and promoting it in turn unblocks
 * src/pending/sub_020307E0.c, whose only unresolved site is this function.
 *
 * Resize in place: the realloc of this heap layer.
 *
 *   u32 sub_020302A4(void *p, u32 size)
 *
 * The block header is the same 0x1c bytes sub_02030098 reserves, so the
 * heap id is `((u16 *)p)[-14]` and the address handed to the expanded-heap
 * routines is p - 0x1c. The new request is size + 0x1c, and it is written
 * twice rather than bound to a local: the compiler recomputes `add r1, r8,
 * #0x1c` for the comparison instead of keeping the value the call already
 * needed, which is what a second occurrence of the expression looks like.
 *
 * sub_02060F90 returns the block's current size, sub_02060CD0 does the
 * resize and returns a size-shaped answer. The two failure tests differ by
 * direction, and that is the whole point of the branch:
 *
 *   growing  (old < new):  failure is a zero answer      -> code 4
 *   shrinking(old >= new): failure is the size unchanged -> code 5
 *
 * Both arms then do the same two things, set the result code and clear the
 * return value, and the compiler cross-jumps them into the shared
 * `moveq r1, r2` / `strheq r0, [r4, #0xe]`; they must be written out in
 * each arm (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 * The zero reused for the cleared result is the same register the
 * `error = 0` store just used.
 *
 * The two early failures share one `mov r0, #0` / `pop` epilogue reached
 * by branch, which needs an explicit `goto`: written as plain `return 0;`
 * the compiler predicates them inline as `movhs r0, #0` / `pophs` instead.
 *
 * symbols:
 *   g_EnvModule     0x02146954  data
 *   sub_0202FBAC    0x0202FBAC  arm
 *   sub_02060CD0    0x02060CD0  arm
 *   sub_02060F90    0x02060F90  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020302A4.c \
 *       --func sub_020302A4 --addr 0x020302A4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct EnvEntry {
    void *ptr00;
    u32 field04;
    u32 field08;
    u16 field0c;
    u8  field0e;
};

struct EnvModule {
    struct EnvEntry *entries;
    u8 *ids;
    u16 count;
    u16 field0a;
    u16 field0c;
    u16 error;
};

struct HeapBlock {
    u16 heapId;
    u16 magic;
    char name[0x12];
    u16 tag;
    u32 field18;
};

extern struct EnvModule g_EnvModule;
extern void *sub_0202FBAC(u32 idx);
extern u32 sub_02060CD0(void *arena, void *block, u32 size);
extern u32 sub_02060F90(void *block);

u32 sub_020302A4(void *p, u32 size)
{
    struct HeapBlock *hdr;
    void *arena;
    u32 oldSize;
    u32 ret;
    u32 ok;

    hdr = (struct HeapBlock *)((char *)p - 0x1c);
    if (hdr->heapId >= g_EnvModule.count) {
        g_EnvModule.error = 2;
        goto fail;
    }
    arena = sub_0202FBAC(hdr->heapId);
    if (arena == 0) {
        g_EnvModule.error = 3;
        goto fail;
    }
    oldSize = sub_02060F90(hdr);
    ret = sub_02060CD0(arena, hdr, size + 0x1c);
    g_EnvModule.error = 0;
    ok = 1;
    if (oldSize < size + 0x1c) {
        if (ret == 0) {
            g_EnvModule.error = 4;
            ok = 0;
        }
    } else {
        if (ret == oldSize) {
            g_EnvModule.error = 5;
            ok = 0;
        }
    }
    return ok;

fail:
    return 0;
}
