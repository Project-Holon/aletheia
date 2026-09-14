/*
 * function: sub_02034AC4
 * address:  0x02034AC4
 * packet:   pkt_02034978
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   sub_02034BB0       0x02034BB0  arm
 *   func_02034D60      0x02034D60  arm
 *   func_02034CBC      0x02034CBC  arm
 *   func_02034D08      0x02034D08  arm
 *   sub_02034714       0x02034714  arm
 *   FS_LoadOverlay     0x02079264  arm
 *   FS_SetDefaultDMA   0x0207AC64  arm
 *   s_FileName         0x020A7970  data
 *   s_Expr0            0x020A7980  data
 *
 * Load an overlay and take a slot for it.  -1 is the "no overlay" handle and
 * succeeds trivially; otherwise the overlay is validated (sub_02034BB0), its
 * owning table picked by the region of its load address (func_02034D60 ->
 * func_02034CBC / func_02034D08), and the first free registration entry
 * claimed.  A full table is the GF_ASSERT(0) at gf_overlay.c:267 and a 0
 * return.  The load itself runs with the filesystem's default DMA channel
 * disabled for the two RAM windows that need it.
 *
 * This is the file's own name: the assert's file string at 0x020A7970 reads
 * "gf_overlay.c", which is what identifies this translation unit.
 *
 * PARKED AT MATCH.  Every concrete byte is right.  Three of the ten
 * relocation sites have no witness and none can be created:
 *
 *   0x02079264 (FS_LoadOverlay) and 0x0207AC64 (FS_SetDefaultDMA) are each
 *   reached from exactly one place in the whole image, the `bl`s in this
 *   function.  Both are TwlSDK libfs entry points that nothing else in this
 *   ROM calls, so `label` has no outside branch to offer and `matched` would
 *   need an EXACT manifest entry for SDK library code.
 *
 *   0x02034BB0 (src/matched/sub_02034BB0.c, EXACT) is likewise called only
 *   from here, so it resolves on `matched` only once its manifest entry is
 *   written; that still leaves the two FS sites.
 *
 * A tu over 0x02034AC4..0x02034CBC would make the sub_02034BB0 site `local`
 * but cannot touch the FS pair, so the combined range stays MATCH and
 * nothing is gained.  This unsticks only if an overlay turns up that calls
 * FS_LoadOverlay or FS_SetDefaultDMA of its own.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02034AC4.c \
 *       --func sub_02034AC4 --addr 0x02034AC4 --cc 1.1p1 --arm
 */

typedef signed int   s32;
typedef unsigned int u32;

struct Registration {
    s32 handle;
    s32 state;
};

extern const char s_FileName[];
extern const char s_Expr0[];

extern int                  sub_02034BB0(s32 handle);
extern int                  func_02034D60(s32 handle);
extern struct Registration *func_02034CBC(int which);
extern int                  func_02034D08(int which);
extern void                 sub_02034714(const char *file, u32 line, const char *expr);
extern int                  FS_LoadOverlay(u32 target, s32 handle);
extern s32                  FS_SetDefaultDMA(s32 channel);

int sub_02034AC4(s32 handle)
{
    int which;
    s32 dma = -1;
    struct Registration *table;
    int count;
    int i;
    struct Registration *entry;
    int ok;

    if (handle == dma) {
        return 1;
    }

    if (sub_02034BB0(handle) == 0) {
        return 0;
    }

    which = func_02034D60(handle);
    table = func_02034CBC(which);
    count = func_02034D08(which);

    for (i = 0; i < count; i++) {
        entry = &table[i];
        if (entry->state == 0) {
            entry->state = 1;
            entry->handle = handle;
            break;
        }
    }

    if (i >= count) {
        sub_02034714(s_FileName, 267, s_Expr0);
        return 0;
    }

    if (which == 1 || which == 2) {
        dma = FS_SetDefaultDMA(-1);
    }
    handle = FS_LoadOverlay(0, handle);
    if (which == 1 || which == 2) {
        FS_SetDefaultDMA(dma);
    }
    ok = 0;
    if (handle != 0) {
        ok = 1;
    }
    return ok;
}
