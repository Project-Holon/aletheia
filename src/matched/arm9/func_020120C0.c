/*
 * function: GAMESYSTEM_CallFieldProc
 * address:  0x020120C0
 * packet:   pkt_020120B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           ov021_id (21) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 * evidence: FieldMapProcData lies in the windows of ov021 (data) and ov114 (bss),
 *           so the ov021 hint needs outside support.  The same call passes
 *           ov021_id (0x15, attested `overlay_id`) and this pointer to the
 *           proc system: GAMESYSTEM_CallProc -> PROCSYS_Push -> PROCSYS_PushInternal ->
 *           PROCSYS_NewProc stores the id at Proc+4 and the pointer at Proc+0
 *           (ProcData), and PROCSYS_StepProc loads overlay Proc+4
 *           (func_02034AC4) before it calls any ProcData callback.  So ov021
 *           is resident whenever the pointer is dereferenced.  Independently,
 *           ov021's bytes at 0x021D359C are three Thumb pointers
 *           0x02187F01/0x02187FD1/0x02187FE9, each a func_ label in
 *           ov021's own listing (init/main/end), while ov114 holds bss there.
 *           With the hint the site attests as `data_table` from ov021's bytes.
 *
 * symbols:
 *   GAMESYSTEM_CallProc     0x020120B4  thumb
 *   ov021_id          0x00000015  data
 *   FieldMapProcData       0x021D359C  data  ov021
 *
 * Four arguments, and the first is the same object twice: the pool words are
 * a small constant 0x15 (an absolute linker symbol, not a literal - see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md, 21 is
 * an overlay id) and the overlay-space address 0x021D359C.  GAMESYSTEM_CallProc
 * itself only reads r0, which is why its ten-byte body says nothing about
 * this call's arity.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_CallFieldProc.c \
 *       --func GAMESYSTEM_CallFieldProc --addr 0x020120C0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct IcaAnime {
    u8  pad00[0x08];
    u32 f8;
};

extern u8 ov021_id[];
extern u8 FieldMapProcData;
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *ov, void *p2);

void GAMESYSTEM_CallFieldProc(struct IcaAnime *p)
{
    GAMESYSTEM_CallProc(p, (u32)ov021_id, &FieldMapProcData, p);
}
