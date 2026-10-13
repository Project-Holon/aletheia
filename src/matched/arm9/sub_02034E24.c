/*
 * function: sub_02034E24
 * address:  0x02034E24
 * packet:   pkt_02034978
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * BLOCKER (re-derived after 0x020357E0 was filed in pkt_020357E0): the
 * two capped sites this file used to name -- KEY_Create and
 * TOUCHPANEL_Create -- both resolve now (`matched`), and 9 of the 10
 * relocation sites are closed.  The single remaining one is
 *
 *   +00CC ABS32 s_UiFile  0x020A7984 (data, declared in symbols)
 *          -> no witness outside 02034E24..02034EF8
 *
 * 0x020A7984 is a string whose only pool word in the image is inside this
 * function's own extent, and attest_string() refuses it: the bytes before
 * it are not a NUL run that fixes its start.  No cut exists inside a
 * single function section, so --suggest-split offers nothing.  It
 * graduates the same way every own-pool string does: when some other
 * matched function happens to pool 0x020A7984, or when the string area's
 * neighbours are attested.
 *
 * symbols:
 *   func_02030734    0x02030734  arm
 *   MI_CpuFill8      0x02082BCC  arm
 *   KEY_Create    0x02035EE8  arm
 *   TOUCHPANEL_Create    0x020357E0  arm
 *   PM_GetBackLight  0x0208BFD0  arm
 *   func_02034F84    0x02034F84  arm
 *   func_0203516C    0x0203516C  arm
 *   unk_021469BC     0x021469BC  data
 *   s_UiFile         0x020A7984  data
 *
 * The constructor for the 0x44-byte UI context src/pending/sub_02034F5C.c
 * tail-calls through: allocate and zero it, fill the two sub-objects at +0
 * and +4 from the same heap, seed the fixed +0x3c / +0x3d / +0x3f bytes,
 * publish it at 0x021469BC, and stash the mode argument at +0x40.
 *
 * Note this is a different translation unit from the rest of pkt_02034978:
 * the debug file string here is "ui.c" at 0x020A7984, not the
 * "gf_overlay.c" at 0x020A7970 that GF_OVERLAY_Init and GF_OVERLAY_CheckRangeFree use.  The
 * boundary between the two units falls between 0x02034DC4 and 0x02034E24.
 *
 * The two mode tests are sequential `if`s, not an if/else chain: mode 0 only
 * caches the backlight state, mode 1 caches it and then runs the two extra
 * services.  Each PM_GetBackLight call gets its own stack slot, the later
 * declaration at the lower address.
 *
 * PARKED AT MATCH.  Every concrete byte is right.  Three relocation sites
 * have no witness:
 *
 *   0x02035EE8 and 0x020357E0 are each called from exactly this one place in
 *   the image, so `label` has nothing outside the range to offer.  Both are
 *   in this territory and both unstick as soon as they are themselves EXACT
 *   (class `matched`).
 *
 *   0x020A7984, the file string "ui.c", is the harder one.  It has exactly
 *   one pool word image-wide, this function's own, so `literal` discards its
 *   only witness; and `string` will not take it either, because the run
 *   before it is the one-byte "0" at 0x020A7980 whose NUL is followed by two
 *   bytes of alignment padding, so the terminator does not fix where this
 *   string starts.  Same shape as
 *   docs/idioms/a-string-after-a-data-table-has-no-witness.md.  Nothing in
 *   this packet can create that witness; it needs a second allocation site
 *   in ui.c, most plausibly in an overlay.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02034E24.c \
 *       --func sub_02034E24 --addr 0x02034E24 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct UiCtx {
    void *unk00;
    void *unk04;
    u8    pad08[0x33];
    u8    backlight;
    u8    unk3C;
    u8    unk3D;
    u8    pad3E;
    u8    unk3F;
    u8    mode;
    u8    pad41[3];
};

extern struct UiCtx *unk_021469BC;
extern const char s_UiFile[];

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void *KEY_Create(u32 heap);
extern void *TOUCHPANEL_Create(u32 heap);
extern void  PM_GetBackLight(u32 *top, u32 *bottom);
extern void  func_02034F84(u32 x);
extern void  func_0203516C(u32 x);

void sub_02034E24(u32 heap, u8 mode)
{
    struct UiCtx *p;
    u32 a;
    u32 b;

    p = func_02030734(heap, sizeof(struct UiCtx), 0, s_UiFile, 58);
    MI_CpuFill8(p, 0, sizeof(struct UiCtx));

    p->unk00 = KEY_Create(heap);
    p->unk04 = TOUCHPANEL_Create(heap);

    p->unk3C = 0;
    p->unk3D = 0x3C;
    unk_021469BC = p;
    p->mode = mode;
    p->unk3F = 5;

    if (mode == 0) {
        PM_GetBackLight(0, &a);
        p->backlight = a;
    }
    if (mode == 1) {
        PM_GetBackLight(0, &b);
        p->backlight = b;
        func_02034F84(0x10);
        func_0203516C(4);
    }
}
