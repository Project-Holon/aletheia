/*
 * file:     ui_p01.c
 * unit:     yes
 * function: func_02034E24, func_02034EF8, func_02034F5C, func_02034F74, func_02034F84, func_02034FA0
 * address:  0x02034E24
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734    0x02030734  arm
 *   MI_CpuFill8      0x02082BCC  arm
 *   func_02035EE8    0x02035EE8  arm
 *   func_020357E0    0x020357E0  arm
 *   PM_GetBackLight  0x0208BFD0  arm
 *   func_0203516C    0x0203516C  arm
 *   unk_021469BC     0x021469BC  data
 *   s_UiFile         0x020A7984  data
 *   sub_020352DC  0x020352DC  arm
 *   sub_020360A8  0x020360A8  arm
 *   sub_02035A60  0x02035A60  arm
 *   sub_0203545C  0x0203545C  arm
 *   sub_020356A0  0x020356A0  arm
 *   sub_0203630C  0x0203630C  arm
 *   sub_02035544  0x02035544  arm
 *   g_02034F5C_Ptr  0x021469BC  data
 *   func_02034EF8   0x02034EF8  arm
 *   func_02034F74 0x02034F74 arm
 */
struct AreaCtx;
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

typedef unsigned short u16;

struct AreaCtx {
    u32 unk00;
    u32 unk04;
    void (*fn)(u32);
    u32  arg;
    u8   unk10[0x29];
    u8   inhibit;
    u8   unk3A[4];
    u8   frames;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void *func_02035EE8(u32 heap);
extern void *func_020357E0(u32 heap);
extern void  PM_GetBackLight(u32 *top, u32 *bottom);
extern void  func_0203516C(u32 x);
extern void sub_020352DC(void);
extern void sub_020360A8(void);
extern void sub_02035A60(void);
extern void sub_0203545C(void);
extern void sub_020356A0(int a0);
extern unsigned int sub_0203630C(void);
extern void sub_02035544(u32 x);
extern void func_02034EF8(struct AreaCtx *p);
void sub_02034F5C(void);
asm void func_02034F74(void);
void sub_02034E24(u32 heap, u8 mode);
asm void func_02034F84(unsigned long x);
void func_02034FA0(unsigned char *p, unsigned char flags);
extern struct UiCtx *unk_021469BC;
extern const char s_UiFile[];
extern void *g_02034F5C_Ptr;



/*
 * BLOCKER (re-derived after 0x020357E0 was filed in pkt_020357E0): the
 * two capped sites this file used to name -- func_02035EE8 and
 * func_020357E0 -- both resolve now (`matched`), and 9 of the 10
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
 * The constructor for the 0x44-byte UI context src/pending/sub_02034F5C.c
 * tail-calls through: allocate and zero it, fill the two sub-objects at +0
 * and +4 from the same heap, seed the fixed +0x3c / +0x3d / +0x3f bytes,
 * publish it at 0x021469BC, and stash the mode argument at +0x40.
 *
 * Note this is a different translation unit from the rest of pkt_02034978:
 * the debug file string here is "ui.c" at 0x020A7984, not the
 * "gf_overlay.c" at 0x020A7970 that sub_0203499C and sub_02034BB0 use.  The
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
void sub_02034E24(u32 heap, u8 mode)
{
    struct UiCtx *p;
    u32 a;
    u32 b;

    p = func_02030734(heap, sizeof(struct UiCtx), 0, s_UiFile, 58);
    MI_CpuFill8(p, 0, sizeof(struct UiCtx));

    p->unk00 = func_02035EE8(heap);
    p->unk04 = func_020357E0(heap);

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



/*
 * One tick of the main loop the areaman singleton drives: bump the frame
 * counter at +0x3e, run the five per-frame services in order, then, only
 * when both pad bits 0x30c are held and the +0x39 inhibit byte is clear,
 * fire the registered callback at +8 with its argument at +0xc and hand 0
 * to sub_02035544.
 *
 * The callback null test and the sub_02035544 call are one block: the `beq`
 * over the `blx` lands on the `mov r0, #0` that sets up the last call, so
 * sub_02035544 runs whether or not a callback was installed.
 *
 * PARKED AT MATCH.  Every concrete byte is right.  All five per-frame
 * services it calls are reached from this one site only, so each needs to be
 * EXACT in the manifest before its `bl` resolves on `matched`:
 *
 *   0x020352DC, 0x020360A8, 0x02035A60, 0x0203545C, 0x020356A0
 *
 * Of those, 0x0203545C is the blocker that cannot be cleared from inside
 * this territory: src/pending/sub_0203545C.c is byte-correct but capped on
 * PM_GoSleepMode (0x0208C154), which the whole image calls exactly once,
 * from that function.  0x02035A60 and 0x020360A8 are byte-correct too
 * (src/pending/) and capped on their own single-caller callees 0x020358A0
 * and 0x02035F38.  So this function stays MATCH until the 0x02035000 block
 * is finished bottom-up, and even then only if PM_GoSleepMode acquires a
 * second call site.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02034EF8.c \
 *       --func sub_02034EF8 --addr 0x02034EF8 --cc 1.1p1 --arm
 */
void sub_02034EF8(struct AreaCtx *p)
{
    p->frames++;

    sub_020352DC();
    sub_020360A8();
    sub_02035A60();
    sub_0203545C();
    sub_020356A0((int)p);

    if ((sub_0203630C() & 0x30C) == 0x30C && p->inhibit == 0) {
        if (p->fn != 0) {
            p->fn(p->arg);
        }
        sub_02035544(0);
    }
}


/*
 * A tail call, `ldr r3,[pc]`/`bx r3`, passing one argument through: the
 * value of a global pointer, dereferenced once.
 *
 * Every concrete byte matches; neither the global pointer nor the callee
 * (both single-use, so far, in this ROM) has a witness outside this one
 * function, so both ABS32 sites stay unresolved under the honesty rule.
 * The tool also reports the original's listing extent as 40 bytes against
 * this function's 24: the territory ends at 0x02034FA0 with no further
 * label, so `disasm.py`'s extent runs into an unlabelled follower the
 * same way docs/MATCHING.md's "two missing labels" section describes.
 * That follower is outside this file's scope.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02034F5C.c \
 *       --func sub_02034F5C --addr 0x02034F5C --cc 1.1p1 --arm
 */
void sub_02034F5C(void)
{
    func_02034EF8(g_02034F5C_Ptr);
}

asm void func_02034F74(void)
{
    ldrb r2, [r0, #0x38]
    orr r1, r2, r1
    strb r1, [r0, #0x38]
    bx lr
}



asm void func_02034F84(unsigned long x)
{
    ldr r2, =0x021469BC
    mov r1, r0
    ldr r0, [r2]
    ldr ip, =func_02034F74
    bx ip
}


void func_02034FA0(unsigned char *p, unsigned char flags)
{
    p[0x38] &= (unsigned char)~flags;
}
