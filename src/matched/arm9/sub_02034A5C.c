/*
 * function: GF_OVERLAY_Unload
 * address:  0x02034A5C
 * packet:   pkt_02034978
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   func_02034D60  0x02034D60  arm
 *   func_02034CBC  0x02034CBC  arm
 *   func_02034D08  0x02034D08  arm
 *   GF_OVERLAY_ReleaseSlot   0x02034A3C  arm
 *
 * Release the registration a handle owns.  -1 is the "no handle" value and
 * returns at once; otherwise the handle is resolved to its area index
 * (func_02034D60), which selects the eight-byte registration table
 * (func_02034CBC) and its live length (func_02034D08), and the first
 * entry whose state word at +4 is 1 and whose handle at +0 is the one asked
 * for is handed to GF_OVERLAY_ReleaseSlot.  At most one entry matches, so the scan
 * returns rather than breaking.
 *
 * The second field load is spelled off the table base with the scaled index
 * (`ldreq r1, [r5, r3, lsl #3]`) rather than off the entry pointer already
 * in r2: writing both halves of the condition against the same `&table[i]`
 * local costs a `ldr r1, [r2]` instead and is a byte difference.
 *
 * The PC24 at +0x50 (GF_OVERLAY_ReleaseSlot) has no `label` witness: the `bl` at
 * 0x02034AAC inside this function is 0x02034A3C's only reference anywhere
 * in the image.  It resolves on class `matched` now that
 * src/matched/GF_OVERLAY_ReleaseSlot.c is EXACT, which in turn waited on
 * src/matched/FS_UnloadOverlay.c and src/matched/unit_02079164.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_Unload.c \
 *       --func GF_OVERLAY_Unload --addr 0x02034A5C --cc 1.1p1 --arm
 */

typedef signed int   s32;
typedef unsigned int u32;

struct Registration {
    s32 handle;
    s32 state;
};

typedef unsigned char  u8;
extern void *func_02034CBC(int i);
extern int func_02034D60(u32 id);
extern u8 func_02034D08(int i);
struct Obj02034A3C;
extern void GF_OVERLAY_ReleaseSlot(struct Obj02034A3C *p);

void GF_OVERLAY_Unload(s32 handle)
{
    s32 area;
    struct Registration *table;
    s32 count;
    s32 i;

    if (handle == -1) {
        return;
    }

    area = func_02034D60(handle);
    table = func_02034CBC(area);
    count = func_02034D08(area);

    for (i = 0; i < count; i++) {
        if (table[i].state == 1 && handle == table[i].handle) {
            GF_OVERLAY_ReleaseSlot((struct Obj02034A3C *)(&table[i]));
            return;
        }
    }
}
