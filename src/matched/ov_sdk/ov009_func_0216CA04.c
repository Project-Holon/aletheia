/*
 * function: DWC_AddMatchKeyString
 * address:  0x0216CA04
 * packet:   pkt_ov009_0216CA04
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_AddMatchKeyString (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * notes:    closed by DWC_Free's hidden third argument (size 0), see the w4 note.
 *
 * symbols:
 *   strcmp                0x020948E0 arm
 *   DWCi_GetNewMatchKey                0x02173AD8 arm   ov009
 *   func_0205A1B0                0x0205A1B0 arm
 *   strlen                0x0209477C arm
 *   func_0205A16C                0x0205A16C arm
 *   DWCi_StopMatch                0x0216EB68 arm   ov009
 *   strcpy                0x02094798 arm
 *   qr2_register_keyA                0x0219D158 arm   ov009
 *   g_021AAA40                   0x021AAA40 data
 *   g_021AAA44                   0x021AAA44 data
 *   g_021AAA41                   0x021AAA41 data
 *   g_021AAA42                   0x021AAA42 data
 *   g_021AAA48                   0x021AAA48 data
 *
 * lane T5 (2026-09-30).  PIN LEVER: the DWC object was built with a 2.0-tree
 * compiler, not dsi/1.1p1.  Under `--cc 2.0/base` (also 2.0/sp1, 2.0/sp1p2) the
 * whole register allocation matches the image from +0004 to +0x2C
 * (movs r6,r1 / mov r5,r2 / mov r7,r0 / cmp r7,#0x64 / sub r2,r7,#0x64 /
 * mul r3,r2,r0) and the residue drops from 133 to 42 concrete bytes; every dsi
 * compiler and every flag set tried gives 133.  Residue under 2.0/base is a
 * single redundant instruction in the tail argument set-up, 304 vs 300 bytes:
 *   +00FC  image `mov r0, r7` then `ldr r1, [r8, r4]`  | ours `mov r0, r8`
 *          then `ldr r1, [r0, r4]` then `mov r0, r7`   (one extra register copy,
 *          and the 12-word pool shifts +4 from +0114 on).
 * Measured flat under 2.0/base: explicit struct-member spelling of the tail two
 * statements, an element-pointer local (&g_021AAA40[index]) in three positions,
 * the call before the value store, a keyString local, and an all-element-pointer
 * body (8 spellings) - 42, 42, 50, 55, 103, 131, 140, 147 bytes.
 *
 * lane U10 (2026-09-30).  Pin confirmed and made the header's compiler field:
 * ../2.0/base.  All ten tools/mwccarm/mwccarm/2.0 subdirectories (base, sp1,
 * sp1p2, sp1p5, sp1p6, sp1p7, sp2, sp2p2, sp2p3, sp2p4) compile this source
 * byte-identically, 304 B / 42 concrete diffs against the image's 300; every
 * one of the nine dsi front ends gives 300 B / 133.  So the register
 * allocation from +0004 to +0x2C is the 2.0 tree's and the row is 2.0-pinned
 * on its own bytes; the object's stamp (4.0.0.1025) has no build in the tree.
 * RESIDUE (not closed, 4 bytes, 42 concrete diffs): every one of those 42 is
 * a pool displacement that moved with the extra instruction.  The body is the
 * image's instruction for instruction except one redundant copy at +00FC:
 *   image  +00FC `mov r0, r7`   +0104 `ldr r1, [r8, r4]`
 *   ours   +00FC `mov r0, r8`   +0104 `ldr r1, [r0, r4]`   +0108 `mov r0, r7`
 * i.e. this front end hoists a copy of the keyString base into r0 and folds
 * the load onto it, where the image hoists the keyID copy and loads straight
 * off r8.  19 spellings this lane, all 304/42: the call spelled with
 * g_021AAA40[index].keyString; a char *ks local assigned after the store; a
 * char *ks = KEYSTR(index) hoisted above the store; an element-pointer local
 * for the store and one for both the store and the call; a char *v temp for
 * valueSrc; a char **pv pointer for the value store; (volatile char **) on the
 * value store; two nested blocks; (char *) casts on both the store and the
 * load; a u8 k = keyID local; KEYSTR(keyID - 0x64) instead of KEYSTR(index);
 * the call before the store; the comma operator; (char *)valueSrc.  The role
 * of the last statement's load argument is exact: replacing it with a
 * non-load (w8/w9) yields 300 B / 7 diffs, i.e. the whole 4-byte gap is that
 * one hoisted copy.  DWC_AddMatchKeyInt (0x0216C8DC, same object, same tail
 * shape) moves 296/134 -> 300/50 under the same pin and parks on the same
 * class of residue, so this is the object's front end, not this body.
 * Verified with:
 *   python tools/match.py one --src src/pending/ov_sdk/ov009_func_0216CA04.c \
 *       --func DWC_AddMatchKeyString --addr 0x0216CA04 --region ov009 --arm \
 *       --lang c99 --cc ../2.0/base
 *
 * lane W8 (2026-09-30).  Re-confirmed both pins on the current source, no
 * spelling changes.  Under the wave brief's dsi/1.1p1 it stays 300 B / 133
 * concrete diffs and the whole gap is the allocator's global-CSE of the
 * shared zero into a callee-saved register (mov r4,#0 at +0014, reused by the
 * +005C return and the +00A0 strh), which rolls keyID/keyString/valueSrc/index
 * up one register.  That is the documented front-end wall
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md
 * (the twin 0x0216C8DC parks on the same wall).  Under ../2.0/base the
 * allocation is the image's from +0004 to +0x2C and the lone residue is the
 * tail base copy at +00FC, unchanged from the T5/U10 notes; ../2.0/sp2
 * measures the same 304 B / 42.  Parked: the C is right, both front ends put
 * one extra/scheduling instruction in the tail that no source lever reaches.
 *
 * lane W8 #2 (2026-10-01).  Re-verified on the current source under both pins:
 * dsi/1.1p1 -> 300 B / 133 concrete (the shared-zero hoist, idiom
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md);
 * ../2.0/base -> 304 B / 42 concrete, every one a pool displacement from the
 * single +00FC `mov r0,r8`.  The +00FC copy is our front end materialising the
 * g_021AAA40 base in r0 to address the call's keyString load (`ldr r1,[r0,r4]`)
 * and then moving keyID into r0, where the image addresses straight off r8.
 * Filed as docs/idioms/a-front-end-hoists-a-base-copy-to-fold-an-argument-load.md.
 * No new source lever; parked unchanged.
 *
 * lane03 (2026-10-01): the dsi/1.1p1 shared-zero hoist is a USE COUNT: the body
 * has five literal zeros (four `return 0` and the KEYF2 strh). Replacing any
 * one of the five with a non-zero literal drops the hoist and leaves 1 B (the
 * altered literal itself), so the 1.1p1 body is right and needs one fewer
 * zero literal. Measured inert: `return keyID` on the new-key path (173 B, the
 * image has `moveq r0,#0`), a shared `fail:` label for any one return (296 B,
 * 1.1p1 does not duplicate the return block), enum-typed/(E) zero on the strh.
 *
 * w3 lane16 (2026-10-01): 1.1p1 is the object's compiler (six dwc_match.o
 * siblings EXACT on 1.1p1, five of them DIFF on ../2.0/base). The 1.1p1 hoist
 * counts BLOCKS holding a zero, not uses: 5 blocks hoist, 4 do not (6 uses in
 * 4 blocks: no hoist; a second zero in an existing block: still hoists).
 * Compare zeros do not count. Inert: house string.h strlen/strcpy (+strcmp),
 * void *value field, casts/enum/static const/inline/local for each zero site,
 * (u16)/0L/(char)/!1/keyID-keyID (all fold early), braces, nesting, else-if,
 * ternary condition, test after the if/else. goto-sharing two returns drops
 * the hoist (strcmp-fail -> new-key return: 300 B / 21 B, layout only) but
 * 1.1p1 never predicates or duplicates a shared return, so the image's five
 * private zero sites need a fifth zero that is not a literal at pool time.
 *
 * w4 (2026-10-01): EXACT on dsi/1.1p1 (the ../2.0/base pin was wrong). Closed
 * by a hidden call argument: DWC_Free takes a third `u32 size` (as in the
 * matched arm9 callers, e.g. func_0205A200) and the call passes 0. That zero
 * argument shares r2 with the KEYF2 strh zero, which stops 1.1p1 from hoisting
 * a shared zero into r4 (toy test: any zero use reachable from the strh in a
 * scratch register breaks the hoist). The image leaves r2 = 0 live into the call.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstGameMatchKeyData {
    u8 keyID;
    u8 f1;
    u16 f2;
    char *keyString;
    char *value;
};

extern struct DWCstGameMatchKeyData g_021AAA40[154];

#define KEYID(i)  (g_021AAA40[i].keyID)
#define KEYF1(i)  (g_021AAA40[i].f1)
#define KEYF2(i)  (g_021AAA40[i].f2)
#define KEYSTR(i) (g_021AAA40[i].keyString)
#define KEYVAL(i) (g_021AAA40[i].value)

extern int strcmp(const char *s1, const char *s2);
extern u8 DWCi_GetNewMatchKey(void);
extern void func_0205A1B0(int name, void *ptr, u32 size);
extern int strlen(const u8 *s);
extern void *func_0205A16C(int name, u32 size);
extern void DWCi_StopMatch(int error, int errorCode);
extern char *strcpy(char *dst, const char *src);
extern void qr2_register_keyA(int keyid, char *key);

u8 DWC_AddMatchKeyString(u8 keyID, char *keyString, char *valueSrc)
{
    int index;

    if (keyString == 0 || valueSrc == 0)
        return 0;
    if (keyID >= 0x64 && KEYID(keyID - 0x64) != 0) {
        if (KEYSTR(keyID - 0x64) != 0 && strcmp(KEYSTR(keyID - 0x64), keyString) != 0)
            return 0;
    } else {
        keyID = DWCi_GetNewMatchKey();
        if (keyID == 0)
            return 0;
    }
    index = keyID - 0x64;
    KEYID(index) = keyID;
    KEYF1(index) = 1;
    KEYF2(index) = 0;
    if (KEYSTR(index) != 0)
        func_0205A1B0(4, KEYSTR(index), 0);
    KEYSTR(index) = func_0205A16C(4, strlen((const u8 *)keyString) + 1);
    if (KEYSTR(index) == 0) {
        DWCi_StopMatch(9, -80001);
        return 0;
    }
    strcpy(KEYSTR(index), keyString);
    KEYVAL(index) = valueSrc;
    qr2_register_keyA(keyID, KEYSTR(index));
    return keyID;
}
