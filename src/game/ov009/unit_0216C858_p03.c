/*
 * file:     unit_0216C858_p03.c
 * unit:     yes
 * function: func_0216CA04, func_0216CB30, func_0216CB90, func_0216CC28, func_0216CD8C, DWCi_ConnectToAnybodyAsync
 * address:  0x0216CA04
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02059F38  0x02059F38  arm
 *   func_0219F058  0x0219F058  arm  ov009
 *   func_0219E120  0x0219E120  arm  ov009
 *   func_02175FB8  0x02175FB8  arm  ov009
 *   func_0216B908  0x0216B908  arm  ov009
 *   func_02175EB4  0x02175EB4  arm  ov009
 *   func_0216B838  0x0216B838  arm  ov009
 *   func_02175F1C  0x02175F1C  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_0217601C  0x0217601C  arm  ov009
 *   func_0217653C  0x0217653C  arm  ov009
 *   func_02173B18  0x02173B18  arm  ov009
 *   func_0216F388  0x0216F388  arm  ov009
 *   func_02195E60  0x02195E60  arm  ov009
 *   func_02195E40  0x02195E40  arm  ov009
 *   func_0219AEB4  0x0219AEB4  arm  ov009
 *   func_0219B540  0x0219B540  arm  ov009
 *   func_02173E30  0x02173E30  arm  ov009
 *   func_0219B1AC  0x0219B1AC  arm  ov009
 *   func_0219B134  0x0219B134  arm  ov009
 *   func_0219B170  0x0219B170  arm  ov009
 *   func_02176ABC  0x02176ABC  arm  ov009
 *   func_0219B490  0x0219B490  arm  ov009
 *   func_02174AA0  0x02174AA0  arm  ov009
 *   func_02174C2C  0x02174C2C  arm  ov009
 *   func_02174C30  0x02174C30  arm  ov009
 *   func_02174C34  0x02174C34  arm  ov009
 *   func_02174CF0  0x02174CF0  arm  ov009
 *   func_02174CF8  0x02174CF8  arm  ov009
 *   func_02174D04  0x02174D04  arm  ov009
 *   func_02174D28  0x02174D28  arm  ov009
 *   func_02174ED0  0x02174ED0  arm  ov009
 *   DWC_Free                0x0205A1B0  arm
 *   func_0216FAD4           0x0216FAD4  arm  ov009
 *   DWC_Alloc               0x0205A16C  arm
 *   MI_CpuCopy8             0x02082D44  arm
 *   func_0216F5FC           0x0216F5FC  arm  ov009
 *   func_02175560           0x02175560  arm  ov009
 *   func_0219EC74           0x0219EC74  arm  ov009
 *   func_02173D9C           0x02173D9C  arm  ov009
 *   func_0216F20C           0x0216F20C  arm  ov009
 *   func_0216F770           0x0216F770  arm  ov009
 *   func_02174058           0x02174058  arm  ov009
 *   g_021AAA20              0x021AAA20  data
 *   g_021A2044              0x021A2044  data
 */
#include "../../matched/include/G_NNThinkGlobal.h"

#define KEYID(i)  (g_021AAA40[i].keyID)
#define KEYF1(i)  (g_021AAA40[i].f1)
#define KEYF2(i)  (g_021AAA40[i].f2)
#define KEYSTR(i) (g_021AAA40[i].keyString)
#define KEYVAL(i) (g_021AAA40[i].value)
struct SBServer;
struct qr2_implementation_s;
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

typedef struct DWCstMatchControl {
    char pad0[4];
    void **gt2Socket;
    char pad8[8];
    void *qr2;
    char pad14[0x5d4 - 0x14];
    unsigned short qr2MatchType;
    char pad5d6[2];
    int qr2NNFinishCount;
    char pad5dc[0x684 - 0x5dc];
    char *gameName;
    char *secretKey;
} DWCstMatchControl;

extern int func_020948E0(const char *s1, const char *s2);
extern u8 func_02173AD8(void);
extern void func_0205A1B0(int name, void *ptr, u32 size);
extern int func_0209477C(const u8 *s);
extern void *func_0205A16C(int name, u32 size);
extern void func_0216EB68(int error, int errorCode);
extern char *func_02094798(char *dst, const char *src);
extern void func_0219D158(int keyid, char *key);
extern int func_02175F3C(void);
extern int func_02059F38(void);
extern int func_0219F058(int a, int b);
extern int func_0219E120(struct SBServer *server, char *key, int idefault);
extern unsigned char func_02175FB8(void);
extern int func_0216B908(void);
extern int func_02175EB4(void);
extern unsigned char func_0216B838(void);
extern void  func_02175F1C(int a0);
extern void  func_02175F4C(int a0);
extern void  func_02082BCC(void *p, int v, int n);
extern void  func_0217601C(void);
extern void  func_0217653C(void);
extern void  func_02173B18(void);
extern int   func_0216F388(int a0);
extern int func_02195E60(const int *p);
extern unsigned short func_02195E40(const unsigned short *p);
extern int func_0219AEB4(void **qrec, int s, int boundport, char *gamename, char *secret_key,
                         int ispublic, int natnegotiate, void *server_key_callback,
                         void *player_key_callback, void *team_key_callback,
                         void *key_list_callback, void *playerteam_count_callback,
                         void *adderror_callback, void *userdata);
extern void func_0219B540(struct qr2_implementation_s *qrec);
extern int func_02173E30(int error);
extern void func_0219B1AC(void *qrec, void *cb);
extern void func_0219B134(void *qrec, void *cb);
extern void func_0219B170(void *qrec, void *cb);
extern void func_02176ABC(void);
extern void func_0219B490(void *qrec);
extern void func_02174AA0(int keyid, void *outbuf);
extern void func_02174C2C();
extern void func_02174C30();
extern void func_02174C34(int keytype, void *keybuffer);
extern int func_02174CF0();
extern void func_02174CF8();
extern void func_02174D04();
extern void func_02174D28(int cookie);
extern void func_02174ED0(char *data, int len);
extern void DWC_Free(int name, void *ptr, unsigned long size);
extern int func_0216FAD4(char *filter, int profileID, unsigned char numEntry, unsigned char matchType, unsigned char hostState);
extern void *DWC_Alloc(int name, unsigned long size);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern void func_0216F5FC(unsigned char matchType, unsigned char numEntry, void *callback, void *param);
extern void func_02175560(void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
extern void *func_0219EC74(char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int maxConcUpdates, int queryVersion, int lanBrowse, void *callback, void *instance);
extern int func_02173D9C(int error);
extern int func_0216F20C(int status);
extern int func_0216F770(int profileID);
extern void func_02174058(void *sb, int reason, void *server);
/* * sdk: DWC_GetMatchIntValue (libdwcmatch.TWL.HYB.a(dwc_match.o)) */ int func_0216CB30(int a, int b, int c);
/* * sdk: DWC_GetSuspendMatch (dwc_match.o) */ int func_0216CB90(void);
/* * DWCi_MatchInit (dwc_match.o): seed the match parameter block returned by * func_02175F3C(), every field through a fresh getter call. The +0x5f0/+0x5f4 * pair is the one place a local reuses one getter result. */ int func_0216CC28(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
/* * notes: the three callback stubs (0x02174C2C PlayerKey, 0x02174C30 TeamKey, 0x02174CF0 Count) were seeded and catalogued by w7_nm from this function's ABS32 pool words * * sdk: DWCi_QR2Startup (libdwcmatch.TWL.HYB.a(dwc_match.o)) */ int func_0216CD8C(int profileID);
void DWCi_ConnectToAnybodyAsync(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
extern struct DWCstGameMatchKeyData g_021AAA40[154];
extern struct NNThinkGlobal g_021AAA20;
extern char g_021A2044[];




/*
 * sdk:      DWC_AddMatchKeyString (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * notes:    closed by DWC_Free's hidden third argument (size 0), see the w4 note.
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
        func_0205A1B0(4, KEYSTR(index), 0);
    KEYSTR(index) = func_0205A16C(4, func_0209477C((const u8 *)keyString) + 1);
    if (KEYSTR(index) == 0) {
        func_0216EB68(9, -80001);
        return 0;
    }
    func_02094798(KEYSTR(index), keyString);
    KEYVAL(index) = valueSrc;
    func_0219D158(keyID, KEYSTR(index));
    return keyID;
}




/*
 * sdk:      DWC_GetMatchIntValue (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
int func_0216CB30(int a, int b, int c)
{
    int t;

    if (func_02175F3C() == 0 || func_02059F38() != 0) {
        return c;
    }
    t = func_0219F058(*(int *)(func_02175F3C() + 0x5e0), a);
    if (t != 0) {
        c = func_0219E120((struct SBServer *)t, (char *)b, c);
    }
    return c;
}




/*
 * sdk:      DWC_GetSuspendMatch (dwc_match.o)
 */
int func_0216CB90(void)
{
    int bNew = -1;
    unsigned int bitmap;

    if (!func_02175F3C())
        return 0;
    if (!func_02175FB8())
        return 0;
    bitmap = *(unsigned int *)(func_02175F3C() + 0x1c);
    bitmap &= func_0216B908();
    if (!func_02175EB4())
        bitmap &= ~(1 << func_0216B838());
    if ((bitmap ^ func_0216B908()) == 0)
        bNew = 1;
    else if ((bitmap & func_0216B908()) == 0)
        bNew = 0;
    if (bNew != -1)
        *(int *)(func_02175F3C() + 0x28) = bNew == 1;
    return *(int *)(func_02175F3C() + 0x28);
}




/*
 * DWCi_MatchInit (dwc_match.o): seed the match parameter block returned by
 * func_02175F3C(), every field through a fresh getter call.  The +0x5f0/+0x5f4
 * pair is the one place a local reuses one getter result.
 */
int func_0216CC28(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    char *q;

    func_02175F1C(a0);
    *(int *)(func_02175F3C() + 0x0) = a1;
    *(int *)(func_02175F3C() + 4) = a2;
    *(int *)(func_02175F3C() + 8) = a3;
    *(int *)(func_02175F3C() + 0x10) = 0;
    *(int *)(func_02175F3C() + 0x5d8) = 0;
    *(unsigned short *)(func_02175F3C() + 0x5d4) = 0;
    *(int *)(func_02175F3C() + 0x5e0) = 0;
    func_02175F4C(0);
    *(char *)(func_02175F3C() + 0x19) = 0;
    *(int *)(func_02175F3C() + 0x678) = 0;
    *(int *)(func_02175F3C() + 0x684) = a4;
    *(int *)(func_02175F3C() + 0x688) = a5;
    *(int *)(func_02175F3C() + 0x68c) = a6;
    *(int *)(func_02175F3C() + 0x690) = a7;
    func_02082BCC((void *)(func_02175F3C() + 0x694), 0, 0x40);
    *(int *)(func_02175F3C() + 0x6d4) = 0;
    *(int *)(func_02175F3C() + 0x770) = 0;
    *(int *)(func_02175F3C() + 0x774) = 0;
    *(int *)(func_02175F3C() + 0x780) = 0;
    *(int *)(func_02175F3C() + 0x784) = 0;
    *(int *)(func_02175F3C() + 0x788) = 0;
    *(int *)(func_02175F3C() + 0x78c) = 0;
    *(int *)(func_02175F3C() + 0x790) = 0;
    *(char *)(func_02175F3C() + 0x794) = 0;
    *(int *)(func_02175F3C() + 0x798) = 0;
    *(char *)(func_02175F3C() + 0x15) = 0;
    *(char *)(func_02175F3C() + 0x16) = 0;
    q = (char *)func_02175F3C();
    *(int *)(q + 0x5f0) = 0;
    *(int *)(q + 0x5f4) = 0;
    *(int *)(func_02175F3C() + 0x7c8) = 0;
    *(int *)(func_02175F3C() + 0x7d4) = 1;
    *(char *)(func_02175F3C() + 0x7b5) = 0;
    *(char *)(func_02175F3C() + 0x7b6) = 0;
    *(int *)(func_02175F3C() + 0x7b0) = 0;
    func_0217601C();
    func_0217653C();
    func_02173B18();
    return func_0216F388(0);
}




/*
 * notes:    the three callback stubs (0x02174C2C PlayerKey, 0x02174C30 TeamKey, 0x02174CF0 Count) were seeded and catalogued by w7_nm from this function's ABS32 pool words
 *
 * sdk:      DWCi_QR2Startup (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
int func_0216CD8C(int profileID)
{
    int i;
    int qr2Error;

    if (((DWCstMatchControl *)func_02175F3C())->qr2 != 0)
        return 0;
    for (i = 0; i < 1; i++) {
        qr2Error = func_0219AEB4(&((DWCstMatchControl *)func_02175F3C())->qr2,
                                 func_02195E60(*((DWCstMatchControl *)func_02175F3C())->gt2Socket),
                                 func_02195E40(*((DWCstMatchControl *)func_02175F3C())->gt2Socket),
                                 ((DWCstMatchControl *)func_02175F3C())->gameName,
                                 ((DWCstMatchControl *)func_02175F3C())->secretKey,
                                 1, 1,
                                 func_02174AA0, func_02174C2C, func_02174C30,
                                 func_02174C34, func_02174CF0, func_02174CF8,
                                 0);
        if (qr2Error == 0)
            break;
        func_0219B540(((DWCstMatchControl *)func_02175F3C())->qr2);
        ((DWCstMatchControl *)func_02175F3C())->qr2 = 0;
        if (qr2Error != 3 || i == 0) {
            func_02173E30(qr2Error);
            return qr2Error;
        }
    }
    ((DWCstMatchControl *)func_02175F3C())->qr2NNFinishCount = 0;
    ((DWCstMatchControl *)func_02175F3C())->qr2MatchType = 0;
    func_0219B1AC(((DWCstMatchControl *)func_02175F3C())->qr2, func_02174D04);
    func_0219B134(((DWCstMatchControl *)func_02175F3C())->qr2, func_02174D28);
    func_0219B170(((DWCstMatchControl *)func_02175F3C())->qr2, func_02174ED0);
    func_02176ABC();
    func_0219B490(((DWCstMatchControl *)func_02175F3C())->qr2);
    return qr2Error;
}


void DWCi_ConnectToAnybodyAsync(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, unsigned char *connectionUserData, void *attemptParam)
{
    int sbError;
    unsigned long addFilterLenMax;
    char filter[511];

    if (g_021AAA20.addFilter != 0) {
        DWC_Free(4, g_021AAA20.addFilter, 0);
        g_021AAA20.addFilter = 0;
    }
    if (addFilter != 0) {
        addFilterLenMax = 0x1ff - func_0216FAD4(filter, -1, 32, 3, 3) - func_0209477C((const u8 *)g_021A2044);
        g_021AAA20.addFilter = DWC_Alloc(4, addFilterLenMax);
        if (g_021AAA20.addFilter == 0) {
            func_0216EB68(9, -80001);
            return;
        }
        MI_CpuCopy8(addFilter, g_021AAA20.addFilter, addFilterLenMax);
        (g_021AAA20.addFilter + addFilterLenMax)[-1] = 0;
    }
    func_0216F5FC(0, numEntry, matchedCallback, matchedParam);
    *(void **)(func_02175F3C() + 0x778) = newClientCallback;
    *(void **)(func_02175F3C() + 0x77c) = newClientParam;
    *(void **)(func_02175F3C() + 0x780) = evalCallback;
    *(void **)(func_02175F3C() + 0x784) = evalParam;
    *(int *)(func_02175F3C() + 0x7b0) = topology;
    func_02175560(attemptCallback, connectionUserData, attemptParam);
    func_02175F4C(0x16);
    if (*(void **)(func_02175F3C() + 0x5e0) == 0) {
        *(void **)(func_02175F3C() + 0x5e0) = func_0219EC74(*(char **)(func_02175F3C() + 0x684), *(char **)(func_02175F3C() + 0x684), *(char **)(func_02175F3C() + 0x688), 0, 20, 1, 0, func_02174058, 0);
    }
    if (*(void **)(func_02175F3C() + 0x5e0) == 0) {
        if (func_02173D9C(5))
            return;
    }
    func_0216F20C(3);
    if (*(void **)(func_02175F3C() + 0x10) == 0) {
        if (func_0216CD8C(*(int *)(func_02175F3C() + 0x678)))
            return;
    } else {
        func_0219B490(*(void **)(func_02175F3C() + 0x10));
    }
    sbError = func_0216F770(*(int *)(func_02175F3C() + 0x678));
    func_02173D9C(sbError);
}
