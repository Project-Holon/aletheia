/*
 * function: func_021B9874
 * address:  0x021B9874
 * packet:   pkt_ov088_021B9874
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct (72 bytes, all concrete bytes agree).  6 of 8 sites
 * resolve; the 2 open ones are a tool refusal, not a byte diff.
 *
 * Measured 2026-10-01 (lane L3):
 *   - d_02184904 is not ov009 data: it is the descriptor handed to the
 *     loader together with ov168_id (0xA8 = 168), so it lives in the
 *     overlay being loaded.  With the `ov168` hint it resolves as
 *     sole-ref/data (docs/idioms/a-loaded-overlay-descriptor-needs-the-
 *     loaders-id-as-its-data-hint.md).  Fixed below.
 *   - ov088_id (0x58) and ov168_id (0xA8), declared `data a1`, still
 *     refuse: the only class that reaches a pooled overlay id is
 *     `overlay_id`, and it needs the first call after the load to be an
 *     OVERLAY_ID_CONSUMERS entry.  The call here is func_020312F8 (EXACT,
 *     src/matched/arm9/func_020312F8.c), which forwards r0 as r1 of
 *     sub_020314DC(g_02146990, id, desc, arg); neither 0x020312F8 nor
 *     0x020314DC is in the table (its proc-system sibling 0x020312CC ->
 *     0x020314F4 is).  sole-ref/self refuses because 0x58 and 0xA8 are not
 *     in a data section; no other class starts an object there.
 *   - Same blocker as func_02183C50 (ov168), noted in
 *     docs/notes/recursive-match-unblocker-ov209-021A-B.c.txt.
 *   - Unblock needs a tools/match.py change (add 0x020312F8 with id
 *     register 0, after reading sub_020314DC to confirm it reaches
 *     FS_LoadOverlay).  Lanes may not edit tools/, so this stays MATCH.
 *
 * symbols:
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_020312F8  0x020312F8  arm
 *   d_021BD66C     0x021BD66C  data  a4
 *   d_021BD974     0x021BD974  data  a4
 *   d_02184904     0x02184904  data  a4  ov168
 *   ov088_id       0x00000058  data  a1
 *   ov168_id       0x000000A8  data  a1
 */

typedef unsigned int u32;

extern void func_020315D4(int a);
extern void func_020306F0(int a);
extern void func_020312F8(void *a, void *b, int c);
extern char d_021BD66C[];
extern char d_021BD974[];
extern char d_02184904[];
extern char ov088_id[];
extern char ov168_id[];

int func_021B9874(int a0, int a1, int a2, int *a3)
{
    int t = a3[1];

    func_020315D4(a0);
    func_020306F0(0x16);
    if (t == 0) {
        func_020312F8(ov088_id, d_021BD66C, 0);
    } else if (t == 2) {
        func_020312F8(ov088_id, d_021BD974, 0);
    } else if (t == 3) {
        func_020312F8(ov168_id, d_02184904, 0);
    }
    return 1;
}
