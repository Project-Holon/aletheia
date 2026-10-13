/*
 * function: G3D_UTIL_FreeUnitResources
 * address:  0x020482B4
 * packet:   pkt_02047E88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02046F50   0x02046F50  arm
 *   func_020470D0   0x020470D0  arm
 *   func_02046EFC   0x02046EFC  arm
 *
 * Tear down one row of the array: for each of the slot record's +0x18
 * elements (starting at the +0x16 index) that is not null, clear the
 * matching byte of the owner's second array (base + index), then run
 * func_02046F50 with mode 2 and, only when it answers exactly one,
 * func_020470D0, and finally func_02046EFC on the element either way.
 *
 * The same signed count and `blt` back edge as G3D_UTIL_LoadUnitResourcesFromArchive, and the same
 * re-read of the owner's element pointer per iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_UTIL_FreeUnitResources.c \
 *       --func G3D_UTIL_FreeUnitResources --addr 0x020482B4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u8  pad_00[0x16];
    u16 unk_16;
    u16 unk_18;
};

struct Owner {
    u32  unk_00;
    u8  *unk_04;
};

struct Tagged;
extern u32 func_02046F50(struct Tagged *p, u32 sel);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);

void G3D_UTIL_FreeUnitResources(struct Owner *owner, u32 index)
{
    struct Slot *slot = (struct Slot *)((u8 *)owner + index * 8);
    u16 count = slot->unk_18;
    u16 base = slot->unk_16;
    int i;

    for (i = 0; i < count; i++) {
        u32 v = ((u32 *)owner->unk_00)[base + i];

        if (v != 0) {
            owner->unk_04[base + i] = 0;

            if (func_02046F50((struct Tagged *)v, 2) == 1)
                func_020470D0((u32 *)v);

            func_02046EFC((struct Tagged *)v);
        }
    }
}
