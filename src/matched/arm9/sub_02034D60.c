/*
 * function: GF_OVERLAY_GetArea
 * address:  0x02034D60
 * packet:   pkt_02034978
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FS_LoadOverlayInfo           0x02078D34  arm
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 *
 * Maps an overlay id onto the areaman table index that owns it: the
 * overlay header's ram_address (+4) inside 0x01000000..0x02000000 is
 * table 1, inside the arm9_autoload1_main_twl window (its base up to
 * base + 0x4000) is table 2, anything else is 0.  The two range guards
 * are sequential, so each `hs` arm carries its own epilogue.
 *
 * Shape notes:
 *  - `id = info.ram_address;` reuses the parameter; a fresh local puts
 *    the load in r1 and shifts every compare by a register.
 *  - The window base is the linker region symbol cast to an integer.  The
 *    image pools 0x02FE0000 in r1 and derives the bound with
 *    `add r0, r1, #0x4000`.  A literal base (any spelling) colours base
 *    r0 / bound r1 (5 out); the symbol kept as a pointer gives the right
 *    registers but folds base + 0x4000 into a second relocated pool word
 *    (104 bytes).  Only the integer cast keeps both the add and the
 *    colouring (u32 and unsigned long both EXACT).  Same region symbol as
 *    src/matched/GFL_USE_VBlankHandler.c and src/matched/GFL_HEAP_InitSystemHeap.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_GetArea.c \
 *       --func GF_OVERLAY_GetArea --addr 0x02034D60 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct OverlayInfo {
    u32 id;
    u32 ram_address;
    u32 ram_size;
    u32 bss_size;
    u32 sinit_init;
    u32 sinit_init_end;
    u32 file_id;
    u32 compressed;
    u32 unk20;
    u32 unk24;
    u32 unk28;
};

extern int FS_LoadOverlayInfo(struct OverlayInfo *info, u32 target, u32 id);
extern const unsigned char SDK_AUTOLOAD_MAIN_TWL_START[];

int GF_OVERLAY_GetArea(u32 id)
{
    struct OverlayInfo info;
    u32 lo;

    FS_LoadOverlayInfo(&info, 0, id);

    id = info.ram_address;
    if (id <= 0x02000000 && id >= 0x01000000) {
        return 1;
    }
    lo = (u32)SDK_AUTOLOAD_MAIN_TWL_START;
    if (id <= lo + 0x4000 && id >= lo) {
        return 2;
    }
    return 0;
}
