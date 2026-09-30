/*
 * function: func_0216CA04
 * address:  0x0216CA04
 * packet:   pkt_ov009_0216CA04
 * region:   ov009
 * compiler: ../2.0/base
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  one redundant instruction at +00FC (4 bytes; every one of the 42 concrete diffs is a
 *           pool displacement that moved with it). Image `mov r0,r7 / ldr r1,[r8,r4]`; ours
 *           `mov r0,r8 / ldr r1,[r0,r4] / mov r0,r7`. This front end hoists a copy of the keyString
 *           base into r0 and folds the last load onto it. Pin is ../2.0/base (all ten 2.0 subtrees
 *           304 B/42; all nine dsi front ends 300 B/133; object stamp 4.0.0.1025). 19 spellings in
 *           the notes below, all 304/42. Re-checked this wave under ../2.0/base: 42 concrete.
 *
 * sdk:      DWC_AddMatchKeyString (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * notes:    near miss, one register-allocation residue: the image never hoists a zero
 *           constant (returns are mov r0,#0, the strh zero is mov r2,#0, index in r4,
 *           keyID r7, keyString r6, valueSrc r5); this source hoists r4=0 after the
 *           first test and shifts every register by one. About 20 attempts.
 *
 * symbols:
 *   func_020948E0                0x020948E0 arm
 *   func_02173AD8                0x02173AD8 arm   ov009
 *   func_0205A1B0                0x0205A1B0 arm
 *   func_0209477C                0x0209477C arm
 *   func_0205A16C                0x0205A16C arm
 *   func_0216EB68                0x0216EB68 arm   ov009
 *   func_02094798                0x02094798 arm
 *   func_0219D158                0x0219D158 arm   ov009
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
 *       --func func_0216CA04 --addr 0x0216CA04 --region ov009 --arm \
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

extern int func_020948E0(const char *s1, const char *s2);
extern u8 func_02173AD8(void);
extern void func_0205A1B0(int name, void *ptr);
extern u32 func_0209477C(const char *s);
extern void *func_0205A16C(int name, u32 size);
extern void func_0216EB68(int error, int errorCode);
extern char *func_02094798(char *dst, const char *src);
extern void func_0219D158(int keyid, char *key);

u8 func_0216CA04(u8 keyID, char *keyString, char *valueSrc)
{
    int index;

    if (keyString == 0 || valueSrc == 0)
        return 0;
    if (keyID >= 0x64 && KEYID(keyID - 0x64) != 0) {
        if (KEYSTR(keyID - 0x64) != 0 && func_020948E0(KEYSTR(keyID - 0x64), keyString) != 0)
            return 0;
    } else {
        keyID = func_02173AD8();
        if (keyID == 0)
            return 0;
    }
    index = keyID - 0x64;
    KEYID(index) = keyID;
    KEYF1(index) = 1;
    KEYF2(index) = 0;
    if (KEYSTR(index) != 0)
        func_0205A1B0(4, KEYSTR(index));
    KEYSTR(index) = func_0205A16C(4, func_0209477C(keyString) + 1);
    if (KEYSTR(index) == 0) {
        func_0216EB68(9, -80001);
        return 0;
    }
    func_02094798(KEYSTR(index), keyString);
    KEYVAL(index) = valueSrc;
    func_0219D158(keyID, KEYSTR(index));
    return keyID;
}
