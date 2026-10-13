/*
 * function: GF_OVERLAY_GetRamRange
 * address:  0x02034DC4
 * packet:   pkt_02034978
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FS_LoadOverlayInfo  0x02078D34  arm
 *
 * Reports the RAM footprint of an overlay: on success the load address goes
 * to the first out-parameter and the one-past-the-end address (load address
 * plus the image and bss sizes) to the second, and the function answers 1.
 * A failed header read answers 0 and touches neither.
 *
 * The literal 0 is kept in a callee-saved register across the call because
 * both the `target` argument and the failure return need it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_GetRamRange.c \
 *       --func GF_OVERLAY_GetRamRange --addr 0x02034DC4 --cc 1.1p1 --arm
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

int GF_OVERLAY_GetRamRange(u32 id, u32 *start, u32 *end)
{
    struct OverlayInfo info;
    u32 addr;

    if (FS_LoadOverlayInfo(&info, 0, id) == 0) {
        return 0;
    }

    addr = info.ram_address;
    *start = addr;
    *end = addr + (info.ram_size + info.bss_size);
    return 1;
}
