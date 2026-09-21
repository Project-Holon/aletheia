/*
 * function: func_0203B52C
 * address:  0x0203B52C
 * packet:   pkt_0203B52C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-21 (family wave 4): MATCH, 10 of 11 sites
 *           resolved, one remaining.  Was 9 of 11.
 *
 * Blocked at MATCH on ONE site.  All 168 concrete bytes are correct (the
 * callback call takes func_0203D650's return value in r0, which is why the
 * function pointer is loaded into r1).
 *
 * THE EARLIER HEADER MISREAD BOTH OPEN SITES AS STRINGS.  Neither +0x0098
 * nor +0x00a0 is a module-name string: both are CODE addresses handed to
 * func_0203AD80 as the reporting call's identifier tag (the same shape as
 * func_0203B038's 0x0203B018 and func_0203B5D4's 0x0203B52C).  Respelt
 * `arm` and passed as `(void *)`:
 *
 *   +0x0098  0x0203B4DC  RESOLVED `matched x1` -- src/matched/func_0203B4DC.c
 *                        is an EXACT entry covering exactly that address.
 *   +0x00a0  0x0203B40C  STILL UNRESOLVED, and this one cannot be fixed.
 *
 * Why 0x0203B40C is a real dead end: it is NOT a function start.  It is
 * INTERIOR to func_0203B390 (extent 0x0203B390..0x0203B448), landing on the
 * `bl func_02037928` at +0x7C of that function -- the entry point of its
 * alternate arm.  So `sole-ref/code` refuses it by its documented rule (an
 * offset into a function is not a start), `matched` refuses it (an EXACT
 * entry attests the range's own start address, not an interior offset), and
 * `label` refuses it (disasm.py traces no label there).  Filing
 * func_0203B390 EXACT was done in this same wave and does NOT unstick this
 * site -- confirmed by re-running match.py one afterwards.  `literal` also
 * refuses: the only pool word naming 0x0203B40C image-wide is the one at
 * +0x00a0 inside this very range.
 *
 * Blocking class: none available, interior-code address with no outside
 * pool word.  Nothing short of a change to the sole-ref/code rule (allowing
 * an interior offset into an EXACT-covered extent) would close it.
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_020393D0  0x020393D0  arm
 *   func_020393A8  0x020393A8  arm
 *   func_0203AD80  0x0203AD80  arm
 *   func_020399EC  0x020399EC  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_0203D650  0x0203D650  arm
 *   g_021469DC     0x021469DC  data
 *   func_0203B4DC  0x0203B4DC  arm
 *   unk_0203B40C   0x0203B40C  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B52C.c \
 *       --func func_0203B52C --addr 0x0203B52C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32  g_021469DC;
extern void func_0203B4DC(void);
extern void unk_0203B40C(void);

extern void *func_0203D798(void);
extern u32   func_020393D0(void);
extern u32   func_020393A8(void);
extern void  func_0203AD80(u32 ctx, void *tag, u32 val, u32 line);
extern u32   func_020399EC(void);
extern u32   func_02039ACC(void);
extern u32   func_0203D650(void);

struct Slot {
    u8  pad_00[0x2c];
    u32 f2c;
};

void func_0203B52C(struct Slot *p)
{
    func_0203D798();
    if (func_020393D0() != 0)
        return;
    if (func_020393A8() == 0) {
        func_0203AD80(g_021469DC, (void *)func_0203B4DC, 0, 0x297);
        return;
    }
    if (func_020399EC() == 0)
        return;
    if (func_02039ACC() == 0)
        return;
    if (p->f2c != 0) {
        ((void (*)(u32))p->f2c)(func_0203D650());
        p->f2c = 0;
    }
    func_0203AD80(g_021469DC, (void *)unk_0203B40C, 0, 0x2a6);
}
