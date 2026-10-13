/*
 * function: G3D_UTIL_LoadUnitResources
 * address:  0x02048120
 * packet:   pkt_02048120
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02048120_File  0x020A7EB8  data
 *   func_02046DB8       0x02046DB8  arm
 *   G3D_SYSTEM_CreateResourcePath       0x02046E90  arm
 *   func_02046C94       0x02046C94  arm
 *   func_02046CE0       0x02046CE0  arm
 *   func_02030734       0x02030734  arm
 *   func_02048F60       0x02048F60  arm
 *   ARC_TOOL_LoadMemberFromPath       0x02048F9C  arm
 *
 * Load one row of resources for the 3D utility rig.  The 8-byte slot at
 * `rig + index * 8` names a run of the handle array at `rig->f00`: the u16 at
 * +0x18 is the count and the u16 at +0x16 is the first index.  Each element is
 * described by a 0xc-byte record in `desc->f00`, whose +8 word selects the
 * source:
 *
 *   0  a plain archive member by id            (func_02046DB8)
 *   1  the same id through the second table    (G3D_SYSTEM_CreateResourcePath)
 *   2  a heap-allocated node wrapping a member read by archive id
 *   3  the same, with the member read by path
 *
 * The heap id is the u16 at `rig + 0x200 + 0x16`, re-read at every use, and
 * `rig->f00` is re-read once per iteration because func_02046CE0 may store
 * through it.  The __FILE__ argument is "g3d_util.c" at 0x020A7EB8.
 *
 * The two __LINE__ values are 342 and 355; the image hoists 355 out of the
 * loop as one pool word and derives 342 from it with `sub r0, r0, #0xd`,
 * spilling the result once
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 *
 * The rig's config base (`rig + 0x200`) must NOT be a named local: binding it
 * to one schedules `add r8, fp, #0x200` ahead of the empty-row guard, where
 * the image computes it after the `pople`.  Spelled as a re-evaluated inline
 * accessor the compiler sinks it below the guard and the whole 312 bytes
 * match.  Declaration order of the remaining locals is slotno/out/i/rec,
 * which is what puts them in r4/r5/r6/r7
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * Probed once under `../2.0/sp2` on the one-instruction scheduling residue:
 * 340 bytes, 290 out -- not a pinned file, the fix is the C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_LoadUnitResources.c \
 *       --func G3D_UTIL_LoadUnitResources --addr 0x02048120 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u8  pad_00[0x16];
    u16 unk_16;
    u16 unk_18;
};

struct Rec {
    u32 unk_00;
    u16 unk_04;
    u8  pad_06[2];
    u32 unk_08;
};

struct Rig {
    u32 unk_00;
};

struct Desc {
    struct Rec *unk_00;
};

extern const char func_02048120_File[];

static inline struct Slot *rig_cfg(struct Rig *rig)
{
    return (struct Slot *)((u8 *)rig + 0x200);
}

struct S02046CE0;
extern void *func_02046DB8(u32 a0, u32 a1);
extern void *G3D_SYSTEM_CreateResourcePath(u32 a0, u32 a1);
extern int func_02046C94(void);
extern void func_02046CE0(struct S02046CE0 *out, u32 *tag);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern void *ARC_TOOL_LoadMemberFromPath(const char *path, u32 a, u32 heap);

void G3D_UTIL_LoadUnitResources(struct Rig *rig, u32 index, struct Desc *desc)
{
    struct Slot *slot = (struct Slot *)((u8 *)rig + index * 8);
    int count = slot->unk_18;
    u32 base = slot->unk_16;
    u32 slotno;
    u32 *out;
    int i;
    struct Rec *rec;
    void *node;

    for (i = 0; i < count; i++) {
        out = (u32 *)rig->unk_00;
        slotno = base + i;
        rec = &desc->unk_00[i];

        switch (rec->unk_08) {
        case 0:
            out[slotno] = (u32)func_02046DB8(rec->unk_00, rec->unk_04);
            break;
        case 1:
            out[slotno] = (u32)G3D_SYSTEM_CreateResourcePath(rec->unk_00, rec->unk_04);
            break;
        case 2:
            node = func_02030734(rig_cfg(rig)->unk_16, func_02046C94(), 0,
                                 func_02048120_File, 342);
            func_02046CE0(node,
                          (u32 *)((u32)func_02048F60(rec->unk_00, rec->unk_04,
                                             rig_cfg(rig)->unk_16)));
            out[slotno] = (u32)node;
            break;
        case 3:
            node = func_02030734(rig_cfg(rig)->unk_16, func_02046C94(), 0,
                                 func_02048120_File, 355);
            func_02046CE0(node,
                          (u32 *)((u32)ARC_TOOL_LoadMemberFromPath((const char *)rec->unk_00, rec->unk_04,
                                             rig_cfg(rig)->unk_16)));
            out[slotno] = (u32)node;
            break;
        }
    }
}
