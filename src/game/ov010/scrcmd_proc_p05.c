/*
 * file:     scrcmd_proc_p05.c
 * unit:     yes
 * function: func_0215C7E0, func_0215C870, func_0215C89C, func_0215C95C, func_0215CA64, func_0215CAB4, func_0215CB08, func_0215CBF0, func_0215CC38, func_0215CC4C, func_0215CCE8, func_0215CD3C, func_0215CD80, func_0215CDB8, func_0215CDF0, func_0215CE70, func_0215CE98, func_0215CEBC, func_0215CEE8, func_0215CF00, func_0215CF54, func_0215CF84, func_0215CFB4, func_0215CFD8, func_0215CFFC, func_0215D034, func_0215D06C, func_0215D0A4, func_0215D0D4, func_0215D110, func_0215D14C, func_0215D198, func_0215D1E4, func_0215D2A4
 * address:  0x0215C7E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02014840  0x02014840  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215C7C4  0x0215C7C4  thumb  ov010
 *   d_021728F0     0x021728F0  data  a1
 *   ov136_id       0x00000088  data
 *   d_021C78A4     0x021C78A4  data  ov136  a1
 *   func_020307B0  0x020307B0  arm
 *   func_0216F940  0x0216F940  thumb  ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02012934 0x02012934 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0216F948 0x0216F948 thumb ov010
 *   func_0216F918 0x0216F918 thumb ov010
 *   func_02014808 0x02014808 thumb
 *   ov173_id 0x000000AD data
 *   d_021B81D0 0x021B81D0 data ov173 a4
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B58  0x02012B58  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02175FB4  0x02175FB4  thumb  ov011
 *   func_0215840C  0x0215840C  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02175648  0x02175648  thumb  ov011
 *   func_0215C63C  0x0215C63C  thumb  ov010
 *   d_021BA758     0x021BA758  data  ov099  a1
 *   ov071_id       0x00000047  data
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_02161B90  0x02161B90  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   ov174_id       0x000000AE  data
 *   d_021B74A0     0x021B74A0  data  a1 ov174
 *   func_02165344  0x02165344  thumb  ov010
 *   ov221_id       0x000000DD  data
 *   ov222_id       0x000000DE  data
 *   ov224_id       0x000000E0  data
 *   d_021BA1A4     0x021BA1A4  data  ov221  a4
 *   d_021BA250     0x021BA250  data  ov222  a4
 *   d_021B9BF8     0x021B9BF8  data  ov224  a4
 *   ov223_id       0x000000DF  data
 *   d_021BC8C4     0x021BC8C4  data  ov223
 *   func_020124AC  0x020124AC  thumb
 *   func_02154438  0x02154438  thumb  ov002
 *   ov002_id       0x00000002  data
 *   func_021543BC  0x021543BC  thumb  ov003
 *   ov003_id       0x00000003  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   ov037_id       0x00000025  data
 *   func_021F36E8 0x021F36E8 thumb ov037
 *   func_021F3724 0x021F3724 thumb ov037
 *   func_021F3768  0x021F3768  thumb  ov037
 *   func_021F3800 0x021F3800 thumb ov037
 *   func_02188D50  0x02188D50  thumb
 *   func_021C3400  0x021C3400  thumb  ov021
 *   func_021C32F4 0x021C32F4 thumb ov021
 *   func_021C335C  0x021C335C  thumb
 *   func_0200BDB0  0x0200BDB0  thumb
 *   func_021C3204 0x021C3204 thumb ov021
 *   func_021C3270 0x021C3270 thumb ov021
 *   func_021C340C  0x021C340C  thumb
 *   func_021C34C4  0x021C34C4  thumb
 *   func_021C34F8 0x021C34F8 thumb ov021
 *   func_02017E1C 0x02017E1C thumb
 *   func_021C341C 0x021C341C thumb ov021
 *   func_021C3490 0x021C3490 thumb ov021
 *   func_021C34B4 0x021C34B4 thumb ov021
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021BE92C  0x021BE92C  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_02172900     0x02172900  data
 */
#include "../../matched/include/Obj04131.h"
#include "../../matched/include/Obj17693.h"
#include "../../matched/include/Obj17694.h"
#include "../../matched/include/Obj17695.h"

struct Ctx;
struct Rec;
struct BigObj;
struct Big;
struct Out;
struct Desc;
struct Evt;
struct Obj;
struct Blk37;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Relearn {
    void *mon;          /* 0x00 */
    void *sess;         /* 0x04 */
    u32 f08;            /* 0x08 */
    void *sys;          /* 0x0C */
    void *moves;        /* 0x10 */
    u8 pad14[5];
    u8 f19;             /* 0x19 */
} Relearn;

typedef struct Name20 {
    u16 s[20];
} Name20;

typedef struct Profile16 {
    u32 w[4];
} Profile16;

typedef struct Rec28 {
    u8 data[0x28];
} Rec28;

typedef struct LinkState {
    u8 pad00[0x86];
    u16 self : 3;       /* 0x086 */
    u16 rest : 13;
    u8 pad88[0x1AC - 0x88];
    Rec28 recs[1];      /* 0x1AC */
} LinkState;

typedef struct ProfileWork {
    void *sys;          /* 0x00 */
    Name20 name;        /* 0x04 */
    Profile16 profile;  /* 0x2C */
    u8 slot;            /* 0x3C */
    u8 remote;          /* 0x3D */
    u8 pad3E[2];
} ProfileWork;

typedef struct Box8_0215CAB4 {
    u16 v;              /* 0x00 */
    u16 pad02;
    void *sys;          /* 0x04 */
} Box8_0215CAB4;

typedef struct Box8_0215CB08 {
    void *sys;          /* 0x00 */
    u32 v;              /* 0x04 */
} Box8_0215CB08;

typedef struct Req {
    void *sys;          /* 0x00 */
    u32 one;            /* 0x04 */
    u32 flag;           /* 0x08 */
    u32 kind;           /* 0x0C */
} Req;

typedef signed int     s32;

typedef struct { u32 a; u32 b; } Arg;

typedef struct { u32 pad[15]; u32 f3c; } O8;

typedef struct { u8 pad[15]; u8 fF; } OC;

typedef struct {
    void *f0;
    void *f4;
    O8 *f8;
    OC *fC;
    u16 *f10;
} Ctx_0215D1E4;

typedef struct {
    void *f00;
    u32 pad04[2];
    u32 f0c;
    u32 pad10[9];
    u32 f34;
    u32 f38;
    u32 f3c;
} A;

typedef struct {
    void *f00;
    u32 f04;
    u32 f08;
    u8 f0c;
    u8 f0d;
    u8 f0e;
    u8 f0f;
    u8 f10;
    u8 pad11[7];
    u32 f18;
} B;

typedef struct {
    void *f0;
    u32 f4;
    A *f8;
    B *fC;
    u32 f10;
} Ctx_0215D2A4;

extern void *func_0215A5F4(void *vm);
extern void *func_0215A5DC(void *vm);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void func_0215897C(void *p, void *v);
extern void func_0215C7C4(struct Rec *r);
extern int func_020307B0();
extern int func_0216F940();
extern u32 func_02159B10(void *c, void *vm);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *list, u32 i);
extern u8 *func_02012944(void *p);
extern u16 *func_0216F948(void *mon, u32 heap);
extern void *func_0216F918(u32 heap);
extern void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern u8 func_02012B58(const struct BigObj *p);
extern u8 func_0215841C(void *p);
extern int func_02175FB4(u8 *p);
extern Name20 *func_0215840C(LinkState *s, int idx);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_02175648(void *sv, struct Out *o);
extern void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
extern void *func_02158F50(void *p);
extern void *func_02161B90(void *p, void *a1, int kind, int sub, int flag);
extern void *func_0215A5E4(void *vm);
extern void func_02165344(void);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void func_02154438(s32 a, s32 *b);
extern void func_021543BC(void);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void func_021F36C0(unsigned int a0, int a1, int a2);
extern void func_021F36E8(void *, int);
extern void func_021F3724(unsigned int a0, int a1);
extern void func_021F3768(unsigned int a0, unsigned short **a1);
extern void func_021F3800(unsigned int a0);
extern void *func_02188D50(void *a0);
extern int func_021C3400(void *a);
extern void func_021C32F4(unsigned int *, unsigned int);
extern void func_021C335C(void **p);
extern void *func_0200BDB0(void *);
extern void func_021C3204(unsigned int *, unsigned int, unsigned int);
extern void func_021C3270(unsigned int *, unsigned int, unsigned int);
extern int func_021C340C();
extern u8 func_021C34C4(void **p);
extern void *func_021C34F8(void *, unsigned int);
extern unsigned int func_02017E1C(void *, unsigned int, unsigned int);
extern int func_021C341C(unsigned int *, unsigned int);
extern int func_021C3490(void **,int);
extern int func_021C34B4(void **,int);
extern void *func_021BE8D4(void *, void *, int, int);
extern void *func_021BE92C(void *, void *, int, int, int, int, int);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *func_020145CC(void *);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA38(struct Blk37 *p);
extern u32 func_0201AA18(void *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
/* * Script command: allocates two 8-byte records (a work holding the * system's word, then a hand-off holding the work and one script word), * launches overlay 0x88 over them with the func_0215C7C4 callback and * parks the result in the script's slot. * * 2026-10-05 (wave D9): EXACT. d_021C78A4 resolves once its symbols line carries the ov136 token (the overlay the function loads); func_0215C7C4 has its own witness. */ int func_0215C7E0(void *c, void *vm);
int func_0215C870(int a0, int a1);
/* * Script command: opens the ov071 process on a 0x40-byte work. When the * current link record is usable (another player's slot, flagged, and * marked at +0x922) the work takes that player's name and profile; * otherwise it is filled from the local player. The chosen slot index * (0 for the local player) is stored at +0x3C. * * MATCH, bytes exact (2026-09-28 tree_ov010_4; lever: one `idx` local * set in both arms, which is what keeps the r6 zero). Three wildcards: * ov011 0x02175FB4 is an unlabelled leaf (`ldrb r0, [r0, #0x10]; bx lr`), * and the pooled 0x47 (ov071_id) and 0x021BA758 (the ov071 process * template) only reach an overlay loader through func_0215C63C, so no * class attests them. * * 2026-10-05 (wave D9): d_021BA758 now resolves with the ov099 token on its symbols line (`data ov099 a1`; other covering overlays stay contested or unresolved). Only ov071_id remains: it reaches func_0215C63C, which is not in match.py OVERLAY_ID_CONSUMERS (forwards r2 to func_020120B4 r1); a data token on the id line does not help. Needs the consumer entry (tools), not C. */ int func_0215C95C(void *c, void *vm);
/* * Script command: reads two words and stores func_02161B90's result * (over the system and the script's cell) in the script's slot. */ int func_0215CA64(void *c, void *vm);
/* * Script command: reads one halfword and the system, boxes them in an * 8-byte record and opens overlay 0xAE over it. * * Bytes exact. * * 2026-10-05 (wave D9): EXACT. The ov174 token on the d_021B74A0 data line (the * proc table lives in ov174, which this function loads) gave the witness; the * ov174_id word then resolved through the overlay_id walk. Source unchanged. */ int func_0215CAB4(void *c, void *vm);
/* * Script command: reads a mode (0-2) and a word; unless the mode is 2 * calls func_02165344, then boxes the system object (and the word) in a * hand-off record and opens overlay 0xDD, 0xDE or 0xE0 over it through * func_0215C63C. * * MATCH, bytes exact. Blockers: the three overlay ids (ABS32 0xDD, 0xDE, * 0xE0) have no witness: `overlay_id` would carry them, but func_0215C63C * (which forwards its r2 to func_020120B4's r1) is not in match.py's * OVERLAY_ID_CONSUMERS. d_021BA250 (ov222) and d_021B9BF8 (ov224) are * contested hints that resolve once the function loads those overlays * through an overlay_id site. d_021BA1A4 (ov221) already resolves. * * 2026-10-05 (wave D9): re-tried overlay tokens on the contested hints; they stay contested because the id sites do not attest. Residue is the three id words (ov221_id, ov222_id, ov224_id) reaching func_0215C63C, which is not in OVERLAY_ID_CONSUMERS; add that consumer (r2 -> func_020120B4 r1) and the hints resolve. Not fixable in C. */ int func_0215CB08(void *c, void *vm);
/* * Script command: reads one word from the script stream, boxes it in a * 4-byte hand-off record and opens overlay 0xDF over it. * * 2026-10-05 (D9 lane 02): d_021BC8C4 resolves with the ov223 token (the overlay it points into) on its data line; ov223_id resolves as an overlay id word. * * 2026-10-05 (wave D8): ov223_id and d_021BC8C4 are data with no witness; not fixable in C. Source re-read against the listing, unchanged. */ int func_0215CBF0(void *c, void *vm);
int func_0215CC38(int a0, int a1);
/* * Script command: reads a kind (0xF-0x13 mapped to 0-4) and a flag (0/1), * builds a four-word request on the stack and launches func_02154438 * (ov002) through func_020124AC, parking the result in the script's slot. */ int func_0215CC4C(void *c, void *vm);
/* * The ov003 callback 0x021543BC (unlabelled leaf, formerly the blocker) is * matched in pkt_ov003_021543BC and attests as matched. */ int func_0215CCE8(void *a, void *b);
int func_0215CD3C(void *a, void *b);
int func_0215CD80(void *a, void *b);
int func_0215CDB8(void *a, void *b);
int func_0215CDF0(void *a, void *b);
int func_0215CE70(void *a, void *b);
/* * unblocked: func_021C3400 (ov021, unlabelled leaf) was matched bottom-up * and filed as pkt_021C3400; the `ov021` token then resolves the site as * `matched, overlay`. Extent runs 36 bytes against 34 compiled: the * unlabelled follower. */ int func_0215CE98(int a0, int a1);
int func_0215CEBC(void *a, void *b);
int func_0215CEE8(int a0, int a1);
int func_0215CF00(void *a, void *b);
int func_0215CF54(void *a, void *b);
int func_0215CF84(void *a, void *b);
int func_0215CFB4(int a0, int a1);
int func_0215CFD8(int a0, int a1);
/* * interface: func_021C34F8 has two observed inputs. Its full ov021 body * and 0200BCA8/0200BC2C read r0/r1 only; legacy trailing r2/r3 are omitted. */ int func_0215CFFC(void *a, void *b);
int func_0215D034(void *a, void *b);
int func_0215D06C(void *a, void *b);
int func_0215D0A4(void *a, void *b);
int func_0215D0D4(void *a,void *b);
int func_0215D110(void *a,void *b);
int func_0215D14C(void *a, void *b);
int func_0215D198(void *x);
int func_0215D1E4(void *a, u32 *st, Ctx_0215D1E4 *c);
void *func_0215D2A4(void *a, u32 b, u32 c);
extern const char d_021728F0[];
extern const u8 d_021C78A4[];
extern u8 ov136_id[];
extern const u8 d_021B81D0[];
extern u8 ov173_id[];
extern const u8 d_021BA758[];
extern u8 ov071_id[];
extern const u8 d_021B74A0[];
extern u8 ov174_id[];
extern const u8 d_021BA1A4[];
extern const u8 d_021BA250[];
extern const u8 d_021B9BF8[];
extern u8 ov221_id[];
extern u8 ov222_id[];
extern u8 ov224_id[];
extern const u8 d_021BC8C4[];
extern u8 ov223_id[];
extern u8 ov002_id[];
extern char ov003_id[];
extern char ov037_id[];
extern const char d_02172900[];




/*
 * Script command: allocates two 8-byte records (a work holding the
 * system's word, then a hand-off holding the work and one script word),
 * launches overlay 0x88 over them with the func_0215C7C4 callback and
 * parks the result in the script's slot.
 *
 * 2026-10-05 (wave D9): EXACT. d_021C78A4 resolves once its symbols line carries the ov136 token (the overlay the function loads); func_0215C7C4 has its own witness.
 */
int func_0215C7E0(void *c, void *vm)
{
    void *slot;
    void *sys;
    void *w;
    void *x;
    u32 *a;
    u32 *b;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    w = func_020120F4(sys);
    x = func_0201210C(sys);
    a = func_02030734(4, 8, 0, d_021728F0, 0x14F);
    b = func_02030734(4, 8, 0, d_021728F0, 0x150);
    a[0] = (u32)w;
    b[0] = (u32)a;
    b[1] = (u32)func_02159AE8(c, vm);
    func_0215897C(slot, func_02014840(sys, (int)x, (u32)ov136_id, (int)d_021C78A4, (int)a, (int)((void *)func_0215C7C4), (int)b));
    return 1;
}




int func_0215C870(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj04131 *)((char *)t4))->f0;
a0 = ((struct Obj04131 *)a0)->f1A;
    if (a0 == 0) goto loc_0215C880;
loc_0215C87C:
    if (a0 == 1) goto loc_0215C884;
loc_0215C880:
a1 = 0;
    goto loc_0215C886;
loc_0215C884:
a1 = 1;
loc_0215C886:
a0 = ((struct Obj04131 *)t4)->f4;
*(u16 *)&((struct Obj04131 *)((char *)a0))->f0 = a1;
a0 = ((struct Obj04131 *)((char *)t4))->f0;
a0 = ((struct Obj04131 *)a0)->f10;
    a0 = func_020307B0(a0);
loc_0215C892:
a0 = ((struct Obj04131 *)((char *)t4))->f0;
    a0 = func_0216F940(a0);
loc_0215C898:
    return a0;}




static inline void init_record(Relearn *r, void *mon, void *sess, void *sys, void *moves)
{
    enum One { ONE = 1 } one;
    r->mon = mon;
    r->sess = sess;
    r->f08 = 0;
    r->sys = sys;
    r->moves = moves;
    one = ONE;
    r->f19 = one;
}



/*
 * lever: enum one assigned immediately before the f19 store in the inline
 * record initializer separates it from the constant return and selects r0.
 */
int func_0215C89C(void *c, void *vm)
{
    void *slot;
    void *sys;
    void *w;
    void *x;
    u32 a;
    u32 idx;
    void *mon;
    void *sess;
    void *moves;
    Relearn *r;
    u32 *h;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    w = func_020120F4(sys);
    x = func_0201210C(sys);
    a = (u32)func_02159AE8(c, vm);
    idx = func_02159B10(c, vm);
    mon = func_0201AB28(func_02012934(w), idx);
    sess = func_02012944(w);
    moves = func_0216F948(mon, 4);
    r = func_0216F918(4);
    init_record(r, mon, sess, sys, moves);
    h = func_02030734(4, 8, 0, d_021728F0, 0x19B);
    h[0] = (u32)r;
    h[1] = a;
    func_0215897C(slot, func_02014808(sys, (int)x, (u32)ov173_id, (int)d_021B81D0, (int)r, (int)((void *)func_0215C870), (int)h));
    return 1;
}




/*
 * Script command: opens the ov071 process on a 0x40-byte work. When the
 * current link record is usable (another player's slot, flagged, and
 * marked at +0x922) the work takes that player's name and profile;
 * otherwise it is filled from the local player. The chosen slot index
 * (0 for the local player) is stored at +0x3C.
 *
 * MATCH, bytes exact (2026-09-28 tree_ov010_4; lever: one `idx` local
 * set in both arms, which is what keeps the r6 zero). Three wildcards:
 * ov011 0x02175FB4 is an unlabelled leaf (`ldrb r0, [r0, #0x10]; bx lr`),
 * and the pooled 0x47 (ov071_id) and 0x021BA758 (the ov071 process
 * template) only reach an overlay loader through func_0215C63C, so no
 * class attests them.
 *
 * 2026-10-05 (wave D9): d_021BA758 now resolves with the ov099 token on its symbols line (`data  ov099  a1`; other covering overlays stay contested or unresolved). Only ov071_id remains: it reaches func_0215C63C, which is not in match.py OVERLAY_ID_CONSUMERS (forwards r2 to func_020120B4 r1); a data token on the id line does not help. Needs the consumer entry (tools), not C.
 */
int func_0215C95C(void *c, void *vm)
{
    void *sys;
    void *p;
    void *q;
    ProfileWork *w;
    LinkState *st;
    u8 idx;

    sys = func_0215A5DC(vm);
    p = (void *)func_02012138(sys);
    q = func_020120F4(sys);
    func_0215A5F4(vm);
    st = (LinkState *)func_02158344((int)p);
    w = func_02030734(4, sizeof(ProfileWork), 1, d_021728F0, 0x1BC);
    if (st != 0 && st->self != func_02012B58(q)
        && func_02175FB4((u8 *)(&st->recs[func_0215841C(q)])) == 1
        && ((u8 *)st)[0x922] == 1) {
        idx = func_0215841C(q);
        w->name = *func_0215840C(st, idx);
        w->profile = *(Profile16 *)((u8 *)st + 0x914);
        w->remote = 1;
    } else {
        func_0200BE48(func_02012EBC(q));
        func_02175648(q, (struct Out *)(&w->profile));
        idx = 0;
        w->remote = 0;
    }
    w->sys = sys;
    w->slot = idx;
    func_0215C63C(c, vm, (u32)ov071_id, d_021BA758, w, 0, 0);
    return 1;
}




/*
 * Script command: reads two words and stores func_02161B90's result
 * (over the system and the script's cell) in the script's slot.
 */
int func_0215CA64(void *c, void *vm)
{
    void *slot;
    void *sys;
    u32 a;
    u32 b;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    a = func_02159B10(c, vm);
    b = func_02159B10(c, vm);
    func_0215897C(slot, func_02161B90(sys, func_02158F50(slot), a, b, 0));
    return 1;
}




/*
 * Script command: reads one halfword and the system, boxes them in an
 * 8-byte record and opens overlay 0xAE over it.
 *
 * Bytes exact.
 *
 * 2026-10-05 (wave D9): EXACT. The ov174 token on the d_021B74A0 data line (the
 * proc table lives in ov174, which this function loads) gave the witness; the
 * ov174_id word then resolved through the overlay_id walk. Source unchanged.
 */
int func_0215CAB4(void *c, void *vm)
{
    u16 v;
    Box8_0215CAB4 *b;

    v = func_02159B10(c, vm);
    b = func_02030734(4, 8, 1, d_021728F0, 0x205);
    b->v = v;
    b->sys = func_0215A5E4(vm);
    func_0215C63C(c, vm, (u32)ov174_id, d_021B74A0, b, 0, 0);
    return 1;
}




/*
 * Script command: reads a mode (0-2) and a word; unless the mode is 2
 * calls func_02165344, then boxes the system object (and the word) in a
 * hand-off record and opens overlay 0xDD, 0xDE or 0xE0 over it through
 * func_0215C63C.
 *
 * MATCH, bytes exact. Blockers: the three overlay ids (ABS32 0xDD, 0xDE,
 * 0xE0) have no witness: `overlay_id` would carry them, but func_0215C63C
 * (which forwards its r2 to func_020120B4's r1) is not in match.py's
 * OVERLAY_ID_CONSUMERS. d_021BA250 (ov222) and d_021B9BF8 (ov224) are
 * contested hints that resolve once the function loads those overlays
 * through an overlay_id site. d_021BA1A4 (ov221) already resolves.
 *
 * 2026-10-05 (wave D9): re-tried overlay tokens on the contested hints; they stay contested because the id sites do not attest. Residue is the three id words (ov221_id, ov222_id, ov224_id) reaching func_0215C63C, which is not in OVERLAY_ID_CONSUMERS; add that consumer (r2 -> func_020120B4 r1) and the hints resolve. Not fixable in C.
 */
int func_0215CB08(void *c, void *vm)
{
    void *sys;
    void *sub;
    u32 mode;
    u32 v;
    Box8_0215CB08 *b;
    void **w;

    sys = func_020120F4(func_0215A5DC(vm));
    sub = func_02012944(sys);
    mode = func_02159B10(c, vm);
    v = func_02159B10(c, vm);
    if (mode != 2) {
        func_02165344();
    }
    switch (mode) {
    case 0:
        b = func_02030734(4, 8, 1, d_021728F0, 0x22B);
        b->sys = sys;
        b->v = v;
        func_0215C63C(c, vm, (u32)ov221_id, d_021BA1A4, b, 0, 0);
        break;
    case 1:
        b = func_02030734(4, 8, 1, d_021728F0, 0x233);
        b->sys = sys;
        b->v = v;
        func_0215C63C(c, vm, (u32)ov222_id, d_021BA250, b, 0, 0);
        break;
    case 2:
        w = func_02030734(4, 4, 1, d_021728F0, 0x23C);
        *w = sub;
        func_0215C63C(c, vm, (u32)ov224_id, d_021B9BF8, w, 0, 0);
        break;
    }
    return 1;
}




/*
 * Script command: reads one word from the script stream, boxes it in a
 * 4-byte hand-off record and opens overlay 0xDF over it.
 *
 * 2026-10-05 (D9 lane 02): d_021BC8C4 resolves with the ov223 token (the overlay it points into) on its data line; ov223_id resolves as an overlay id word.
 *
 * 2026-10-05 (wave D8): ov223_id and d_021BC8C4 are data with no witness; not fixable in C. Source re-read against the listing, unchanged.
 */
int func_0215CBF0(void *c, void *vm)
{
    u32 v;
    u32 *w;

    v = (u32)func_02159AE8(c, vm);
    w = func_02030734(4, 8, 1, d_021728F0, 0x254);
    w[0] = v;
    func_0215C63C(c, vm, (u32)ov223_id, d_021BC8C4, w, 0, 0);
    return 1;
}




int func_0215CC38(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215CC42:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CC48:
a0 = 1;
    return a0;}




/*
 * Script command: reads a kind (0xF-0x13 mapped to 0-4) and a flag (0/1),
 * builds a four-word request on the stack and launches func_02154438
 * (ov002) through func_020124AC, parking the result in the script's slot.
 */
int func_0215CC4C(void *c, void *vm)
{
    void *slot;
    void *sys;
    u32 kind;
    u32 flag;
    u32 k;
    u32 f;
    Req r;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    kind = func_02159B10(c, vm);
    flag = func_02159B10(c, vm);
    switch (kind) {
    case 0xF:
        k = 0;
        break;
    case 0x10:
        k = 1;
        break;
    case 0x11:
        k = 2;
        break;
    case 0x12:
        k = 3;
        break;
    case 0x13:
        k = 4;
        break;
    }
    switch (flag) {
    case 0:
        f = 0;
        break;
    case 1:
        f = 1;
        break;
    }
    r.sys = func_0201210C(sys);
    r.one = 1;
    r.flag = f;
    r.kind = k;
    func_0215897C(slot, func_020124AC(sys, (u32)ov002_id, (void *)func_02154438, (u32)(&r)));
    return 1;
}




/*
 * The ov003 callback 0x021543BC (unlabelled leaf, formerly the blocker) is
 * matched in pkt_ov003_021543BC and attests as matched.
 */
int func_0215CCE8(void *a, void *b)
{
    Arg arg;
    void *t = func_0215A5F4(b);
    void *h = func_0215A5DC(b);
    u32 k = !func_02159B10(a, b) ? 1 : 2;
    arg.a = (u32)func_0201210C(h);
    arg.b = k;
    func_0215897C(t, func_020124AC(h, (u32)ov003_id, (void *)func_021543BC, (u32)(&arg)));
    return 1;
}




int func_0215CD3C(void *a, void *b)
{
    void *h = func_0215A5DC(b);
    u16 *p = func_02159AE8(a, b);
    u16 *q = func_02159AE8(a, b);
    func_02034AC4((u32)ov037_id);
    func_021F36C0((unsigned int)h, *p, *q);
    func_02034A5C((u32)ov037_id);
    return 0;
}




int func_0215CD80(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    int v = func_02159B10(a, b);
    func_02034AC4((int)ov037_id);
    func_021F36E8(p, v);
    func_02034A5C((int)ov037_id);
    return 0;
}



int func_0215CDB8(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    int v = func_02159B10(a, b);
    func_02034AC4((int)ov037_id);
    func_021F3724((unsigned int)p, v);
    func_02034A5C((int)ov037_id);
    return 0;
}



int func_0215CDF0(void *a, void *b)
{
    unsigned short *v[8];
    void *h = func_0215A5DC(b);
    v[0] = func_02159AE8(a, b);
    v[1] = func_02159AE8(a, b);
    v[2] = func_02159AE8(a, b);
    v[3] = func_02159AE8(a, b);
    v[4] = func_02159AE8(a, b);
    v[5] = func_02159AE8(a, b);
    v[6] = func_02159AE8(a, b);
    v[7] = func_02159AE8(a, b);
    func_02034AC4((u32)ov037_id);
    func_021F3768((unsigned int)h, v);
    func_02034A5C((u32)ov037_id);
    return 0;
}



int func_0215CE70(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    func_02034AC4((int)ov037_id);
    func_021F3800((unsigned int)p);
    func_02034A5C((int)ov037_id);
    return 0;
}



/*
 * unblocked: func_021C3400 (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021C3400; the `ov021` token then resolves the site as
 *   `matched, overlay`.  Extent runs 36 bytes against 34 compiled: the
 *   unlabelled follower.
 */
int func_0215CE98(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215CEA0:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CEA8:
    v2 = func_0201210C(v1);
loc_0215CEAC:
    a0 = func_021C3400(func_02188D50(v2));
loc_0215CEB0:
loc_0215CEB4:
((struct Obj17693 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}



int func_0215CEBC(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    void *q = func_02012934(func_0215A5E4(b));
    func_021C32F4(func_02188D50(func_0201210C(p)), (unsigned int)q);
    return 0;
}



int func_0215CEE8(int a0, int a1)
{
    void *v0;
    void *v1;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215CEF0:
    v1 = func_0201210C(v0);
loc_0215CEF4:
    func_021C335C((void **)func_02188D50(v1));
loc_0215CEF8:
loc_0215CEFC:
a0 = 0;
    return a0;}



int func_0215CF00(void *a, void *b)
{
    void *t = func_0215A5F4(b);
    unsigned short *v = func_02159AE8(a, b);
    void *p = func_0215A5E4(b);
    void *h = func_0215A5DC(b);
    void *s = func_0201210C(h);
    func_02012934(p);
    func_0200BDB0(func_02012EBC(p));
    func_0215897C(t, func_0215D2A4(h, (u32)s, (u32)v));
    return 1;
}



int func_0215CF54(void *a, void *b)
{
    int v = func_02159B10(a, b);
    void *q = func_02012934(func_0215A5E4(b));
    func_021C3204(func_02188D50(func_0201210C(func_0215A5DC(b))), (unsigned int)q, v);
    return 0;
}



int func_0215CF84(void *a, void *b)
{
    int v = func_02159B10(a, b);
    void *q = func_02012934(func_0215A5E4(b));
    func_021C3270(func_02188D50(func_0201210C(func_0215A5DC(b))), v, (unsigned int)q);
    return 0;
}



int func_0215CFB4(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215CFBC:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CFC4:
    v2 = func_0201210C(v1);
loc_0215CFC8:
    a0 = func_021C340C(func_02188D50(v2));
loc_0215CFCC:
loc_0215CFD0:
((struct Obj17694 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}



int func_0215CFD8(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215CFE0:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CFE8:
    v2 = func_0201210C(v1);
loc_0215CFEC:
    a0 = func_021C34C4((void **)func_02188D50(v2));
loc_0215CFF0:
loc_0215CFF4:
((struct Obj17695 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}



/*
 * interface: func_021C34F8 has two observed inputs. Its full ov021 body
 * and 0200BCA8/0200BC2C read r0/r1 only; legacy trailing r2/r3 are omitted.
 */
int func_0215CFFC(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    void *q = func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(b))), v);
    *p = func_02017E1C(q, 5, 0);

    return 0;
}



int func_0215D034(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    void *q = func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(b))), v);
    *p = func_02017E1C(q, 111, 0);

    return 0;
}



int func_0215D06C(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    void *q = func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(b))), v);
    *p = func_02017E1C(q, 110, 0);

    return 0;
}



int func_0215D0A4(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    *p = func_021C341C(func_02188D50(func_0201210C(func_0215A5DC(b))), v);

    return 0;
}


int func_0215D0D4(void *a,void *b)
{
 u16 *p = func_02159AE8(a,b);
 int i = func_02159B10(a,b);
 void **q = func_02188D50(func_0201210C(func_0215A5DC(b)));
 func_021C34F8(q,i);
 *p = func_021C3490(q,i);
 return 0;
}


int func_0215D110(void *a,void *b)
{
 u16 *p = func_02159AE8(a,b);
 int i = func_02159B10(a,b);
 void **q = func_02188D50(func_0201210C(func_0215A5DC(b)));
 func_021C34F8(q,i);
 *p = func_021C34B4(q,i);
 return 0;
}



int func_0215D14C(void *a, void *b)
{
    int f;
    u16 *p;
    void *r;
    void *s = func_02188D50(func_0201210C(func_0215A5DC(b)));
    p = func_02159AE8(a, b);
    f = func_02159B10(a, b);
    r = func_021C34F8(s, func_02159B10(a, b));
    if (f == 0)
        *p = func_0215D198(r);
    else
        *p = 0;
    return 0;
}



int func_0215D198(void *x)
{
    int a = func_02017E1C(x, 5, 0);
    int b = func_02017E1C(x, 0x6e, 0);
    if (a == 0x20 || a == 0x1d) {
        a = 0;
        if (func_02017E1C(x, 0x75, 0) == 0)
            return a;
    }
    switch (b) {
    case 2:
    default: return 0;
    case 0: return 1;
    case 1: return 2;
    }
}



int func_0215D1E4(void *a, u32 *st, Ctx_0215D1E4 *c)
{
    u32 s = *st;
    void *p0 = c->f0;
    switch (s) {
    case 0:
        func_02012374(a, func_021BE8D4(p0, c->f4, 0, 0));
        *st = 1;
        break;
    case 1:
        func_02012374(a, (struct Evt **)func_020144DC((int)p0, (int)c->f4));
        c->f8->f3c = c->fC->fF;
        *st = 2;
        break;
    case 2:
        func_02012374(a, func_02014910(p0, (int)c->f4, (int)c->f8, (int)c->fC));
        *st = 3;
        break;
    case 3:
        func_02012374(a, func_020145CC(p0));
        *st = 4;
        break;
    case 4:
        func_02012374(a, func_021BE92C(p0, c->f4, 0, 0, 1, 0, 0));
        *st = 5;
        break;
    case 5:
        *c->f10 = c->f8->f3c;
        func_020307B0(c->f8);
        func_020307B0(c->fC);
        return 1;
    }
    return 0;
}



void *func_0215D2A4(void *a, u32 b, u32 c)
{
    void *r7 = func_020120F4(a);
    void *v = func_02012934(r7);
    u32 w = (u32)func_0200CA1C(r7);
    A *x = func_02030734(4, 0x98, 0, d_02172900, 0x22B);
    B *y;
    Ctx_0215D2A4 *ctx;
    void *h;
    x->f00 = v;
    x->f34 = 0x12;
    x->f38 = 0;
    x->f3c = 0;
    y = func_02030734(4, 0x28, 0, d_02172900, 0x232);
    y->f00 = x->f00;
    y->f04 = x->f0c;
    y->f08 = (u32)r7;
    y->f0c = 1;
    y->f0e = func_0201AA18(v);
    y->f0d = 0;
    y->f10 = 0;
    y->f0f = 0;
    y->f18 = func_0200CA38((struct Blk37 *)w);
    h = func_020122C0(a, 0, (void *)func_0215D1E4, 0x14);
    ctx = func_020124E8(h);
    ctx->f0 = a;
    ctx->f4 = b;
    ctx->f8 = x;
    ctx->fC = y;
    ctx->f10 = c;
    return h;
}
