/*
 * file:     wih_dwc.c
 * unit:     yes
 * function: sub_02010158, func_020101D4, func_0201034C, sub_02010360, func_020103E4, func_0201042C, func_02010444, func_0201045C, sub_02010498, sub_020104F8, func_0201054C, func_0201057C, func_0201058C, func_02010794, func_020107CC, sub_020107FC, func_02010848, func_02010864, func_02010884, func_02010888, func_0201088C, func_020108C4, func_02010904, func_02010934, func_0201093C, func_02010964, func_02010994, func_020109B8, func_020109E0, func_02010A04, func_02010A3C, sub_02010A5C, func_02010AC4
 * address:  0x02010158
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * wih_dwc.c: the wireless/DWC helper unit, with net_err.c's error window in
 * front and net_save.c's save task at the end.  The wih_dwc state is one
 * global (g_021461E0): the 0x328-byte context object and a 0xA00-byte buffer.
 *
 * symbols:
 *   func_0202EB0C  0x0202EB0C  thumb
 *   g_0214617C     0x0214617C  data
 *   tbl_0209DEB0   0x0209DEB0  data  a2
 *   tbl_0209DED0   0x0209DED0  data  a2
 *   G2_GetBG1ScrPtr   0x0207DFB4  arm
 *   G2_GetBG1CharPtr  0x0207E24C  arm
 *   MIi_CpuClear16    0x02082A48  arm
 *   func_02043754     0x02043754  arm
 *   func_0201EC64     0x0201EC64  thumb
 *   func_0201D7EC     0x0201D7EC  thumb
 *   func_02045B38     0x02045B38  arm
 *   func_0201EFA4     0x0201EFA4  thumb
 *   func_02045EC0     0x02045EC0  arm
 *   func_020457B0     0x020457B0  arm
 *   func_0201F250     0x0201F250  thumb
 *   func_0201C7D0     0x0201C7D0  thumb
 *   func_02045808     0x02045808  arm
 *   func_02045C04     0x02045C04  arm
 *   func_0201D83C     0x0201D83C  thumb
 *   func_0201ED04     0x0201ED04  thumb
 *   func_020437AC     0x020437AC  arm
 *   g_021461E0     0x021461E0  data
 *   sWihDwc        0x020A7240  data
 *   sWihDwcFile    0x020A7244  data
 *   func_02034714  0x02034714  arm
 *   func_0203D7C8  0x0203D7C8  arm
 *   func_0205D010  0x0205D010  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_0217963C  0x0217963C  thumb  ov014
 *   ov015_id       0x0000000F  data
 *   func_0203D7FC  0x0203D7FC  arm
 *   func_02034A5C  0x02034A5C  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0203F004  0x0203F004  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_0203D798  0x0203D798  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203CF10  0x0203CF10  arm
 *   func_0205D01C  0x0205D01C  arm
 *   func_02178098  0x02178098  thumb  ov014
 *   func_0205FAA8  0x0205FAA8  arm
 *   func_0203CD98     0x0203CD98  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   func_02177B80     0x02177B80  thumb  ov014
 *   sub_0202E8D8      0x0202E8D8  thumb
 *   s0x020A725C       0x020A725C  data
 *   d_020A7250        0x020A7250  data
 *   func_02030734     0x02030734  arm
 *   func_020399A8     0x020399A8  arm
 *   func_02039C68     0x02039C68  arm
 *   func_020307B0     0x020307B0  arm
 *   func_0200FB24     0x0200FB24  thumb
 *   func_02012E08     0x02012E08  thumb
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   sub_020124F4   0x020124F4  thumb
 *   sub_02012EBC   0x02012EBC  thumb
 *   sub_02009448   0x02009448  thumb
 *   sub_020092EC   0x020092EC  thumb
 *   ov115_id       0x00000073  data  a1
 *   ov123_id       0x0000007B  data  a1
 *   d_021D6338     0x021D6338  data  ov115
 *   d_021DA9A8     0x021DA9A8  data  ov123
 *   d_021D654C     0x021D654C  data  ov115
 *   func_020312CC  0x020312CC  arm
 *   func_0200F7B8  0x0200F7B8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef signed short   s16;

struct Bmp;
struct GfFont;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct U16Vec;
struct WordSet;
struct Link;
struct Entry;
struct Obj0203159C;
struct Big;
struct Sub02009448Obj;
struct Sub02009210Obj;

/* net_err.c module state at 0x0214617C (only the fields used here) */
struct NetErrBlock {
    u32 id;
    u32 unk4;
    u32 unk8;
    u32 reason;     /* error code, 0x3EE..0x3F7 are mapped to message ids */
};

struct NetErr {
    u8 unk00[0x48];
    struct NetErrBlock blk;     /* +0x48 */
    u8 f58;
    u8 f59;
    u8 f5A;
    u8 pad5B[5];
    u32 f60;
};

/* one 0xC0-byte record the ov014 receive callback queues */
struct WihRec {
    u8 unk00[0xA];
    u16 fA;
    u8 name[0x20];      /* +0x0C */
    u16 f2C;
    u8 unk2E[0x92];
};

/* the 0xA00-byte buffer behind the global's second word */
struct WihBuf {
    u8 unk000[0x600];
    u8 f600[0x40];
    u8 slot[3][0x100];  /* +0x640 */
    u8 pad940[0xC0];
};

/* the 0x328-byte context object func_02010360 allocates */
struct WihObj {
    struct WihRec rec[4];
    void *f300;
    struct WihBuf *f304;
    u8 pad308[4];
    u16 f30C;
    u16 f30E;
    u16 f310;
    u16 f312;
    u16 f314;
    u16 f316;
    s32 f318;
    s32 f31C;
    s32 f320;
    s32 f324;
};

/* the global at 0x021461E0 */
struct WihCtx {
    struct WihObj *obj;
    struct WihBuf *buf;
};

struct WihInfo {
    int kind;          /* +0x00 */
    u8  rest[0x3C];    /* +0x04 */
};

/* the connection state block func_0203D798 returns (fields used here) */
struct WihNetState {
    u8 unk00[0x62];
    u8 f62;
    u8 unk63[4];
    u8 f67;
};

/* the 0x14-byte net_save.c task object */
struct WihTask {
    void (*f0)(u32 arg);
    u32 f4;
    void (*f8)(struct WihTask *p);
    u32 fC;
    s32 f10;
};

struct SaveRecA {
    void *sys;
    u32 f4;
    u32 f8;
    u32 fC;
    void *buf;
};

struct SaveRecB {
    void *sys;
    void *buf;
    u16 heapId;
    u8 pad[2];
};

struct SaveRecC {
    void *sys;
    u32 f4;
    u32 f8;
};

/* the 0x1D8-byte net_save.c save task record */
struct SaveCtx {
    struct SaveRecA a;      /* +0x00 */
    u32 f14;
    u8 pad18[4];
    u32 f1C;
    u8 pad20[8];
    struct SaveRecC c;      /* +0x28 */
    u8 pad34[0x10];
    void *sys;              /* +0x44 */
    struct SaveRecB b;      /* +0x48 */
    u32 f54;
    u32 f58;
    u8 buf5C[0x174];
    u16 heapId;             /* +0x1D0 */
    u8 pad1D2[2];
    u32 state;              /* +0x1D4 */
};

extern u32 func_0202EB0C(void);
extern u16 *G2_GetBG1ScrPtr(void);
extern u8  *G2_GetBG1CharPtr(void);
extern void MIi_CpuClear16(u16 data, void *dst, u32 size);
extern struct Bmp *func_02043754(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_0203D7C8(u32 heap, u32 size, const char *file, u16 line);
extern u32  func_0205D010(void);
extern int func_02034AC4(int id);
extern void func_0217963C(u32 v);
extern void func_0203D7FC(void *p);
extern void func_02034A5C(int handle);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern u32 func_0203F004(const u8 *s);
extern s32 func_0203EFC8(const void *a, const void *b, u32 n);
extern void *func_0203D798(void);
extern int  func_0203D1B4(void);
extern u32 func_0203CF10(u32 a);
extern u8   func_02178098(u8 i);
extern int  func_0205D01C(void *buf, struct WihRec *rec, struct WihInfo *out);
extern void func_0205FAA8(u8 *p, u32 v);
extern int  func_0203CD98(void);
extern void OS_GetMacAddress(u8 *mac);
extern u8 func_02177B80(int i);
extern int sub_0202E8D8(char *a0, int a1, char *a2);
extern void *func_02030734(u32 a, u32 b, int c, const char *file, u16 line);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *ctx, u32 id, u32 size);
extern u32 func_020307B0(void *p);
extern u32  func_0200FB24(void);
extern void func_02012E08(u32 handle);
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern int func_02012DAC(u32 handle);
extern int  func_02012DD0(u32 handle);
extern u32  func_020056EC(u32 v);
extern void  func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(void *obj, u32 size, u32 heap);
extern void  func_02082BCC(void *dst, int val, unsigned n);
extern void *sub_020124F4(u16 heap);
extern void *sub_02012EBC(struct Big *p);
extern struct Sub02009448Obj *sub_02009448(void *sys);
extern u8 sub_020092EC(const struct Sub02009210Obj *obj);
extern void func_020312CC(u32 ovl, const void *proc, void *arg);
extern u32 func_0200F7B8(u32 a0);
extern int func_020053EC(void);
extern int func_02034F5C(int a);
extern int func_02005BC0(int a);
extern int func_020065FC(int a);

u32 sub_02010158(struct NetErrBlock *obj, u32 a);
void func_020101D4(u32 a0, u32 a1);
int func_0201034C(void);
struct WihObj *sub_02010360(int idx, void *heap);
void func_020103E4(struct WihObj *p);
void func_0201042C(void);
void func_02010444(void);
void func_0201045C(const void *src);
void sub_02010498(void);
int sub_020104F8(struct WihRec *obj);
int func_0201054C(const struct WihRec *obj);
u32 func_0201057C(const struct WihRec *rec);
u32 func_0201058C(void *key);
void func_02010794(u32 heap);
void func_020107CC(void);
int sub_020107FC(void *key);
u16 func_02010848(void);
void func_02010864(u32 v);
void func_02010884(void);
void func_02010888(struct WihTask *p, void (*f)(struct WihTask *p));
struct WihTask *func_0201088C(u32 heap, u32 a1);
struct WihTask *func_020108C4(u32 heap, u32 a1, void (*cb)(u32 arg), u32 arg);
u32 func_02010904(struct WihTask *p);
void func_02010934(struct WihTask *p);
void func_0201093C(struct WihTask *p);
void func_02010964(struct WihTask *p);
void func_02010994(struct WihTask *p);
void func_020109B8(struct WihTask *p);
void func_020109E0(struct WihTask *p);
void func_02010A04(struct WihTask *p);
void func_02010A3C(struct WihTask *p);
int sub_02010A5C(void *a0);
int func_02010AC4(u32 a0, u32 a1, u32 a2, struct SaveCtx *ctx);
extern struct NetErr g_0214617C;
extern const u16 tbl_0209DEB0[];
extern const u16 tbl_0209DED0[];
extern struct WihCtx g_021461E0;
extern u8 sWihDwc;
extern u8 sWihDwcFile[];
extern u8 ov015_id[];
extern u8 s0x020A725C;
extern u8 d_020A7250[];
extern u8 ov115_id[];
extern u8 ov123_id[];
extern u8 d_021D6338[];
extern u8 d_021DA9A8[];
extern u8 d_021D654C[];


/*
 * net_err.c's error-code mapper: the reason code of the module's error block
 * (0x3EE..0x3F7) maps to a fixed message id; anything else indexes one of two
 * sixteen-entry u16 tables by the module's +0x60 error number, picked by
 * func_0202EB0C().  The case 0x3F7 arm shares case 0x3EE's block.
 */
/*
 * The error-code mapper of net_err.c: a reason code at obj+0xc (obj is the
 * 16-byte block the module keeps at 0x0214617C+0x48) in 0x3EE..0x3F7 maps to
 * a fixed message id; anything else indexes one of two sixteen-entry u16
 * tables by the module's +0x60 error number, picked by func_0202EB0C().
 * Wave 13: the earlier DIFF note read the pools as 0x0202617C / 0x020109B0 /
 * 0x020109D0; the words are 0x0214617C / 0x0209DEB0 / 0x0209DED0, and the
 * case 0x3F7 arm shares case 0x3EE's block (both table slots 0x12).
 */
u32 sub_02010158(struct NetErrBlock *obj, u32 a)
{
    u32 v;

    switch (obj->reason) {
    case 0x3ee:
    case 0x3f7:
        return 0xd;
    case 0x3f1:
        return 0x28;
    case 0x3f2:
    case 0x3f3:
    case 0x3f4:
    case 0x3f5:
    case 0x3f6:
        return 0xe;
    case 0x3f0:
        return 0x28;
    }
    if (func_0202EB0C() != 0) {
        v = g_0214617C.f60;
        if (v >= 0x10) {
            return 0xb;
        }
        return tbl_0209DED0[v];
    }
    v = g_0214617C.f60;
    if (v >= 0x10) {
        return 0xb;
    }
    return tbl_0209DEB0[v];
}


/*
 * Draws net_err.c's error window: tiles BG1's screen with a running
 * character index, clears the character block to 0x7777, builds a surface,
 * a window object and a palette, picks the message (0x40 for a1 == 1; the
 * mapped error code from sub_02010158 or the stored +0x60 code in link
 * modes 1/2/6; else message 1, or 0 unless a0 == 1), prints it and frees
 * everything.  The non-link arm's message index is the same variable as the
 * constant 1 its two calls pass (idx = 1 kept unless a0 != 1).
 */
void func_020101D4(u32 a0, u32 a1)
{
    struct NetErr *g = &g_0214617C;
    u16 *scr;
    void *surf;
    void *obj;
    s32 x;
    void *arc;
    u32 idx;
    void *k;
    void *buf;
    s32 y;
    void *pal;
    u16 *res;
    u16 c;

    res = G2_GetBG1ScrPtr();
    scr = res;
    c = 0x20;
    for (y = 4; y < 0x14; y++) {
        for (x = 1; x < 0x1f; x++) {
            scr[y * 0x20 + x] = c;
            c = (u16)(c + 1);
        }
    }
    MIi_CpuClear16(0x7777, G2_GetBG1CharPtr() + 0x400, 0x3c00);
    surf = func_02043754(G2_GetBG1CharPtr() + 0x400, 0x1e, 0x10, 0x20, 1);
    obj = func_0201EC64(1);
    pal = func_0201D7EC(0x17, 0, 0, 0, 1);

    if (a1 == 1) {
        arc = func_02045B38(0, 2, 0xe8, 1);
        idx = 0x40;
    } else {
        u8 m = g->f59;

        if (m == 1 || m == 2 || m == 6) {
            func_0201EFA4(obj, 0, g->blk.id, 5, 2, 1);
            arc = func_02045B38(0, 2, 0xe8, 1);
            if (g->f5A != 0) {
                idx = g->f60;
                g->f5A = 0;
            } else {
                idx = sub_02010158(&g->blk, g->f60);
            }
        } else {
            func_0201EFA4(obj, 0, g->f58, 5, 2, 1);
            arc = func_02045B38(0, 2, 0x52, 1);
            idx = 1;
            if (a0 != 1) {
                idx = 0;
            }
        }
    }

    k = func_02045EC0(arc, idx);
    buf = func_020457B0(0x189, 1);
    func_0201F250(obj, buf, k);
    func_0201C7D0(surf, 0, 0, buf, pal, 0x1167);
    func_02045808(buf);
    func_02045808(k);
    func_02045C04(arc);
    func_0201D83C(pal);
    func_0201ED04(obj);
    func_020437AC(surf);
}


int func_0201034C(void)
{
    int t0 = func_020053EC();
    int t1 = func_02034F5C(t0);
    int t2 = func_02005BC0(t1);
    int t3 = func_020065FC(t2);

    return t3;
}


/*
 * wih_dwc.c constructor: allocates the 0x328-byte object (line 0x49), stores
 * the index at +0x310, allocates a second buffer sized by func_0205D010
 * (line 0x4C) into +0x300, registers func_0201045C as the ov014 receive
 * callback, publishes the object in the global and copies the global's
 * second word into +0x304.  func_020103E4 is its destructor.
 */
/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * note:     rewritten 2026-09-23 (wave 14): every concrete byte right, 11 of
 *           12 relocation sites resolved.
 *
 *           Thumb leaf in ov014 (wih.c): 0x0217963C decodes as
 *           `ldr r1,[pc,#8]; ldr r2,[r1]; ldr r1,[pc,#8]; str r0,[r2,r1];
 *           bx lr`, a setter of word +0x1E88 of the object behind 0x021797A8
 *           (the same shape as the labelled func_02179628 just before it,
 *           which sets +0x1E84).  asm/overlays/ov014.s prints it as .word
 *           data, so attest_overlay_label() has no label to accept.  SEED
 *           REQUEST for the integrator: `ov014 0x0217963C thumb`, evidence
 *           the bl at arm9 0x020103B6 (this function) and 0x020103FE
 *           (func_020103E4).  Once seeded, 0x020103FE is an outside witness
 *           for this file and 0x020103B6 for func_020103E4: both go EXACT
 *           with no C change.
 *
 * wih_dwc.c constructor: allocates the 0x328-byte object (line 0x49), stores
 * the index at +0x310, allocates a second buffer sized by func_0205D010
 * (line 0x4C) into +0x300, registers func_0201045C as the ov014 receive
 * callback, publishes the object in the global and copies the global's
 * second word into +0x304.  func_020103E4 is its destructor.
 * Two readings corrected from the previous file: the pool word is
 * 0x021461E0 (not 0x020461E0), and 0x0201045D is the Thumb address of
 * func_0201045C, a function pointer, not data.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02010360.c \
 *       --func sub_02010360 --addr 0x02010360 --thumb
 */
struct WihObj *sub_02010360(int idx, void *heap)
{
    struct WihObj *p;

    if (idx > 4) {
        func_02034714((const char *)(&sWihDwc), 0, (const char *)(&sWihDwc));
    }
    if (g_021461E0.obj != 0) {
        func_02034714((const char *)(&sWihDwc), 0, (const char *)(&sWihDwc));
    }
    p = func_0203D7C8((u32)heap, 0x328, (const char *)sWihDwcFile, 0x49);
    p->f310 = idx;
    p->f300 = func_0203D7C8((u32)heap, func_0205D010(), (const char *)sWihDwcFile, 0x4C);
    func_0217963C((u32)func_0201045C);
    g_021461E0.obj = p;
    p->f304 = g_021461E0.buf;
    func_02034AC4((int)ov015_id);
    return p;
}


/*
 * wih_dwc.c teardown, the counterpart of sub_02010360.  func_0217963C is an
 * unlabelled ov014 Thumb setter.
 */
/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 *           address in overlay space: two overlays overlap it (ov009, ov014)
 *           and NEITHER carries a func_ label there (ov009 decodes it as
 *           `moveq r0, #1` in the middle of a function, ov014 has the data
 *           word 0x680A4902).  attest_overlay_label() needs part 1 of the
 *           rule, a label in the overlay's own listing, so the site has no
 *           witness outside this range and no cut can give it one: the only
 *           branch to 0x0217963C in the image is the pair at 0x020103B6 and
 *           0x020103FE, and both are inside this packet.  `matched` cannot
 *           reach it either (0x0217963C is not matched).
 *           2026-09-23 (wave 14): 0x0217963C is an unlabelled ov014 Thumb
 *           setter (`ldr r1,[pc,#8]; ldr r2,[r1]; ldr r1,[pc,#8]; str r0,
 *           [r2,r1]; bx lr`), printed as .word data.  SEED REQUEST: `ov014
 *           0x0217963C thumb`; the two bl sites then witness each other and
 *           this file and sub_02010360 go EXACT unchanged.
 *
 * "wih_dwc.c" teardown, the counterpart of func_02010360 (same packet):
 * both guard on the same pointer at 0x021461E0 being null before running
 * the 0x020A7240-argument call, both take the same (p, 0, p) argument
 * triple, and both end by clearing that pointer again.  The pool word is
 * the address of the four zero bytes immediately before the "wih_dwc.c"
 * string at 0x020A7244 - the file anchor the packet reports.
 *
 * The last call's argument arrives from a pool word holding 0x0000000F, not
 * from a `movs`, so it is a symbol rather than an integer: see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.  The
 * pool words on either side of this function (0x020103E0 and 0x02010428)
 * both hold 0x0F, and func_02034AC4 - the sibling entry point in
 * src/pending/unit_0200BA58.c - takes the same kind of value, so this is
 * the same linker-defined id, spelled ov015_id here.  It is `literal`-
 * attested by 0x020103E0, which is outside this function's range.
 *
 * The call at 0x0217963C is a branch into overlay space (it is why the
 * listing prints it as .inst.w "outside this region").  Its argument is a
 * literal zero, and that same zero is what the store at +0x30 writes: mwcc
 * materialises it once, keeps it in r4 across both func_0203D7FC calls and
 * stores it, which is the `movs r4, #0` beside the `movs r0, #0`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020103E4.c \
 *       --func func_020103E4 --addr 0x020103E4 --cc 1.1p1 --thumb
 *   MATCH, 72 bytes, 7 relocation sites, 6 resolved, 1 wildcard:
 *     +001A THM_CALL func_0217963C - unresolved, no outside witness.
 */
void func_020103E4(struct WihObj *p)
{
    if (g_021461E0.obj == 0) {
        func_02034714((const char *)(&sWihDwc), 0, (const char *)(&sWihDwc));
    }
    func_0217963C(0);
    func_0203D7FC(p->f300);
    func_0203D7FC(p);
    g_021461E0.obj = 0;
    func_02034A5C((int)ov015_id);
}


/*
 * Two mirror-image functions: set and clear the flag halfword at +0x30C of
 * the context object.
 */
/*
 * Two mirror-image four-word functions: set and clear one flag halfword of
 * entry 0xC3 in a table reached through the pointer variable at 0x0214617C's
 * neighbour, 0x021461E0.  0x021461E0 is a plain literal pool word (the same
 * address is loaded by nine other functions in this file's neighbourhood, at
 * 0x020103D4, 0x02010420 and so on), so it needed no relocation resolution,
 * the same situation documented in src/matched/sub_0200F800.c for 0x0214617C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201042C.c \
 *       --addr 0x0201042C --thumb
 */
void func_0201042C(void)
{
    struct WihObj *o = g_021461E0.obj;

    if (o != 0) {
        o->f30C = 1;
    }
}


void func_02010444(void)
{
    struct WihObj *o = g_021461E0.obj;

    if (o != 0) {
        o->f30C = 0;
    }
}


/*
 * wih_dwc.c: append one 0xC0-byte record to the four-slot table at the head
 * of the context object, guarded on the capacity at +0x310 and the fill
 * index at +0x316.  sub_02010360 hands this function's address to the ov014
 * setter, so it is a receive callback.  MI_CpuCopy8 takes three arguments.
 */
void func_0201045C(const void *src)
{
    struct WihObj *o = g_021461E0.obj;

    if (o->f310 != 0 && o->f316 < o->f310 && o->f316 < 4) {
        MI_CpuCopy8(src, &o->rec[o->f316], 0xC0);
        g_021461E0.obj->f316 = g_021461E0.obj->f316 + 1;
    }
}


/*
 * Per-frame countdown of the four timers at +0x318..+0x324 (the real
 * prologue is at 0x02010498).
 */
/*
 *           function_starts.txt line 337 seeds this leaf at 0x0201049C (4 bytes
 *           too high); the real prologue and byte-exact fit are at 0x02010498,
 *           per docs/notes/unit_0201045C.c.txt.
 * blocked:  +005C ABS32 g_021461E0 : unresolved: no address for 'g_021461E0':
 *           not in the symbols: block, not an address-bearing name, not in
 *           layout/symbols_sdk.json
 */
void sub_02010498(void)
{
    struct WihObj *o = g_021461E0.obj;

    if (o != 0 && o->f30C != 0)
        return;
    if (o == 0)
        return;
    if (o->f318 > 0)
        o->f318 = o->f318 - 1;
    o = g_021461E0.obj;
    if (o->f31C > 0)
        o->f31C = o->f31C - 1;
    o = g_021461E0.obj;
    if (o->f320 > 0)
        o->f320 = o->f320 - 1;
    o = g_021461E0.obj;
    if (o->f324 > 0)
        o->f324 = o->f324 - 1;
}


/*
 * Three 0x100-byte slots at +0x640 of the buffer behind the context's +0x304;
 * the first slot with a positive func_0203F004 whose func_0203EFC8 against
 * the record's name returns zero makes the function return 1.  func_0203EFC8
 * takes THREE arguments, the third is the result of func_0203F004 (kept in
 * r2).  `i` must be initialised before `q`, and the loop-body local `n` must
 * be declared inside the loop.
 */
/*
 * Three 0x100-byte slots at +0x640 of the object hanging off +0x304 of the
 * global at 0x021461E0 (the same global func_0201045C reads); the first slot
 * with a positive func_0203F004 whose func_0203EFC8 against obj+0xC returns
 * zero makes the function return 1.
 *
 * Three spellings the previous pass (docs/notes/pkt_0201045C.c.txt) did not
 * have, and each is needed:
 *
 *  1. the pool word is 0x021461E0, not 0x020461E0, and it holds a POINTER,
 *     not the object: the original does one `ldr r1, [r7]` and then
 *     `ldr r1, [r1, r0]` with r0 = 0x304.  Reading it as `**` costs an extra
 *     dereference at both sites.  It is the same global func_0201045C reads.
 *  2. func_0203EFC8 takes THREE arguments, and the third is the result of
 *     func_0203F004.  That is what the otherwise pointless `adds r2, r0, #0`
 *     at 0x02010518 is: r2 is set right after the first call and is still
 *     live, unwritten, at the `blx` to func_0203EFC8 twenty-four bytes
 *     later.  Two arguments plus a named local for the comparison folds the
 *     copy away (80 bytes); a function-scope or volatile local gives it a
 *     stack home (`str r0, [sp]` / `ldr r0, [sp]`) instead of r2.  The local
 *     must be declared inside the loop body.
 *     docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md
 *  3. `i` must be initialised before `q`: the original opens
 *     `movs r4, #0` then `adds r6, #0xc`, and writing the loop as a plain
 *     `for (i = 0; ...)` after `u8 *q = obj + 0xC;` emits those two the
 *     other way round.  That swap is the last two bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020104F8.c \
 *       --func sub_020104F8 --addr 0x020104F8 --cc 1.1p1 --thumb
 */
int sub_020104F8(struct WihRec *obj)
{
    int i = 0;
    u8 *q = obj->name;

    for (; i < 3; i++) {
        u8 *slot = g_021461E0.obj->f304->slot[i];
        int n = func_0203F004(slot);

        if (n > 0) {
            slot = g_021461E0.obj->f304->slot[i];
            if (func_0203EFC8(slot, q, n) == 0)
                return 1;
        }
    }
    return 0;
}


/*
 * Three gates on one record then `return 1`; all false paths share the single
 * `return 0` at the bottom.  The compare is against the 8 bytes at
 * 0x020A7250, func_0203EFC8 is a memcmp-shaped helper whose zero means equal.
 */
/*
 * Three gates on one object then `return 1`.  All three false paths share the
 * single `return 0` at the bottom, which is what puts the `bne`/`beq` on the
 * shared epilogue instead of inlining two `movs r0, #0`: the source is a nest
 * of three `if`s with one `return 1` inside and one `return 0` after them.
 * The compare is against the 8 bytes at 0x020A7250, a cast address constant
 * (no relocation), and `func_0203EFC8` is a memcmp-shaped helper whose zero
 * means equal.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201054C.c \
 *       --func func_0201054C --addr 0x0201054C --cc 1.1p1 --thumb
 */
int func_0201054C(const struct WihRec *obj)
{
    if (obj->fA == 8) {
        if (func_0203EFC8(d_020A7250, obj->name, 8) != 0) {
            if ((obj->f2C & 0x10) == 0) {
                return 1;
            }
        }
    }
    return 0;
}


/*
 * A boolean test of bit 0x10 of the halfword at +0x2C of a record.
 */
/*
 * Sixteen bytes: a boolean test of bit 0x10 of a halfword field at +0x2C of
 * its argument.  The functions on both sides of it are not matched yet, so
 * it is a file of its own, the same situation documented for
 * src/matched/unit_02011F24.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201057C.c \
 *       --func func_0201057C --addr 0x0201057C --cc 1.1p1
 */
u32 func_0201057C(const struct WihRec *rec)
{
    if (rec->f2C & 0x10) {
        return 1;
    }
    return 0;
}


/*
 * wih_dwc.c per-frame status poll: returns a flag word (bit 1 always set)
 * built from the lookup in sub_020107FC, the connection state byte +0x67
 * and slot count +0x62 of the func_0203D798 state block, the ov014 per-slot
 * state (0x14..0x1B, 9), then drains the 0xC0-byte record queue that
 * func_0201045C fills, arming the four countdowns at +0x318..+0x324 that
 * sub_02010498 decrements (600 or 400 frames), and finally derives bits
 * 0x40..0x200 from those countdowns.  func_0205D01C's third argument is a
 * 0x40-byte out record whose first word is the switch key; the switch has
 * explicit empty arms for 7 and 9 so the 13-entry halfword table exists.
 */
/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 *           unlabelled Thumb function in ov014 (wih.c); asm/overlays/ov014.s
 *           prints 0x02178098 as .word data (0x680B4909), and this call is
 *           the only branch to it in the image.  SEED REQUEST: `ov014
 *           0x02178098 thumb`, evidence the bl at arm9 0x020105E8.  Every
 *           other site resolves and every concrete byte matches (520 of 520).
 *
 * wih_dwc.c per-frame status poll: returns a flag word (bit 1 always set)
 * built from the lookup in sub_020107FC, the connection state byte +0x67
 * and slot count +0x62 of the func_0203D798 context, the ov014 per-slot
 * state (0x14..0x1B, 9), then drains the 0xC0-byte record queue that
 * func_0201045C fills, arming the four countdowns at +0x318..+0x324 that
 * sub_02010498 decrements (600 or 400 frames), and finally derives bits
 * 0x40..0x200 from those countdowns.
 *
 * Two declaration facts close it: func_0205D01C's third argument is a
 * 0x40-byte out record whose first word is the switch key (the frame is
 * sub sp,#0x60 plus the r3 pad; an `int *` gives sub sp,#0x24), and the
 * switch has explicit empty arms for 7 and 9 so the 13-entry halfword table
 * exists (docs/idioms/empty-switch-arms-are-what-make-the-table.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201058C.c \
 *       --func func_0201058C --addr 0x0201058C --thumb
 */
u32 func_0201058C(void *key)
{
    u32 flags = 0;
    struct WihNetState *st = func_0203D798();
    int i;
    int j;
    struct WihRec *rec;
    struct WihInfo info;
    u8 s;

    if (g_021461E0.obj == 0)
        return flags;

    if (sub_020107FC(key) != -1)
        flags |= 8;
    if (st->f67 == 2 && func_0203D1B4() > 1)
        flags |= 4;

    for (i = 0; i < st->f62; i++) {
        if (func_0203CF10(i) != 0) {
            s = func_02178098(i);
            if (s >= 0x14 && s <= 0x1B)
                flags |= 0x10;
            else if (s == 9)
                flags |= 0x20;
        }
    }

    for (j = 0; j < g_021461E0.obj->f316; j++) {
        rec = &g_021461E0.obj->rec[j];
        if (sub_020104F8(rec)) {
            g_021461E0.obj->f318 = 600;
        } else if (func_0201054C(rec)) {
            g_021461E0.obj->f31C = 600;
        } else if (func_0205D01C(g_021461E0.obj->f300, rec, &info)) {
            switch (info.kind) {
            case 0: case 1: case 2: case 3:
            case 10: case 11: case 12:
                g_021461E0.obj->f318 = 600;
                break;
            case 4: case 5: case 6: case 8:
                g_021461E0.obj->f31C = 600;
                break;
            case 7: case 9:
                break;
            }
        } else if (rec->fA != 0) {
            if (func_0201057C(rec) == 0)
                g_021461E0.obj->f320 = 400;
            else
                g_021461E0.obj->f324 = 400;
        }
    }

    if (g_021461E0.obj->f318 > 0)
        flags |= 0x40;
    if (g_021461E0.obj->f31C > 0)
        flags |= 0x80;
    if (g_021461E0.obj->f320 > 0)
        flags |= 0x100;
    if (g_021461E0.obj->f324 > 0)
        flags |= 0x200;
    if (g_021461E0.obj->f30E != 0)
        g_021461E0.obj->f30E = g_021461E0.obj->f30E - 1;

    if (flags == 0) {
        g_021461E0.obj->f312 = 0;
    } else if (g_021461E0.obj->f314 != 0 && g_021461E0.obj->f30E == 0) {
        g_021461E0.obj->f312 = g_021461E0.obj->f314;
        g_021461E0.obj->f30E = 400;
        g_021461E0.obj->f314 = 0;
    }
    g_021461E0.obj->f316 = 0;
    return flags | 2;
}


/*
 * wih_dwc.c: (re)build the second field of the global.  The guard fires when
 * the pointer is ALREADY set (a re-initialisation warning).  The allocator
 * takes a heap id, a size, a __FILE__ string and a line number.
 */
/*
 * wih_dwc.c: (re)build the second field of the object at 0x021461E0.  The
 * guard is the same file-name call the rest of this file makes - here the
 * polarity is inverted, so it fires when the pointer is ALREADY set (a
 * re-initialisation warning rather than an uninitialised one).
 *
 * The tail calls func_0203D7C8(heap, 0xA00, "wih_dwc.c", 0x1C0), which is the
 * debug/allocator shape this SDK uses: a heap ID, a size, a __FILE__
 * string and a line number.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010794.c \
 *       --func func_02010794 --addr 0x02010794 --cc 1.1p1 --thumb
 */
void func_02010794(u32 heap)
{
    if (g_021461E0.buf != 0) {
        func_02034714((const char *)(&sWihDwc), 0, (const char *)(&sWihDwc));
    }
    g_021461E0.buf = func_0203D7C8(heap, 0xA00, (const char *)sWihDwcFile, 0x1C0);
}


/*
 * wih_dwc.c: the sibling of func_02010794, same guard on the buffer (here it
 * fires when it is unset); the field is re-read afterwards.  The tail is
 * func_0205FAA8(buf + 0x600, 0).
 */
/*
 * wih_dwc.c: the sibling of func_02010794 in the same packet - same guard on
 * the +0x04 field of the object at 0x021461E0, same file-name call, and the
 * field is re-read afterwards (a second pool load), so the callee is allowed
 * to have set it.  The tail is func_0205FAA8(f4 + 0x600, 0).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020107CC.c \
 *       --func func_020107CC --addr 0x020107CC --cc 1.1p1 --thumb
 *
 *           and no branch anywhere else in the image reaches that address -
 *           this function is its only caller - so the site has no witness
 *           outside the compared range and no cut can give it one (shrinking
 *           the range to this one function keeps the call inside it).  The
 *           target is not in an EXACT manifest entry either, so the `matched`
 *           class does not reach it.  Byte-correct as it stands.
 */
void func_020107CC(void)
{
    if (g_021461E0.buf == 0) {
        func_02034714((const char *)(&sWihDwc), 0, (const char *)(&sWihDwc));
    }
    func_0205FAA8(g_021461E0.buf->f600, 0);
}


/*
 * wih_dwc.c: find the first of 16 slots whose ov014 state is 0x20 and whose
 * func_0203CF10 record sub_0202E8D8 accepts against (key, own MAC address);
 * -1 when none, or when func_0203CD98 reports the layer inactive.  The guard
 * is a wrapping `if` (it branches forward over the whole body to the shared
 * -1 exit) and the two loop tests are joined by &&.
 */
/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 *           unlabelled Thumb function in ov014 (wih.c); asm/overlays/ov014.s
 *           prints 0x02177B80 as .word data (0x680B4909, `ldr r1,[pc,#0x24];
 *           ldr r3,[r1]`...), and this call is the only branch to it in the
 *           image.  SEED REQUEST: `ov014 0x02177B80 thumb`, evidence the bl at
 *           arm9 0x0201081A.  Once labelled, `sole-ref/code` (or `label`, if a
 *           second referrer turns up in ov014) can carry the site.
 *           The MATCH is also starred: the listing extent runs to 0x02010888
 *           over three unlabelled leaves, filed as src/matched/unit_02010848.c.
 *
 * wih_dwc.c: find the first of 16 slots whose ov014 state is 0x20 and whose
 * func_0203CF10 record func_0202E8D8 accepts against (key, own MAC address);
 * -1 when none, or when func_0203CD98 reports the layer inactive.  The
 * closing lever over docs/notes/pkt_020107CC.c.txt was the wrapping `if`
 * instead of an early return (the original's guard branches forward over
 * the whole body to the shared -1 exit) plus the two loop tests joined by &&.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020107FC.c \
 *       --func sub_020107FC --addr 0x020107FC --thumb
 */
int sub_020107FC(void *key)
{
    u8 mac[8];
    int i;

    if (func_0203CD98() != 0) {
        func_0203D798();
        OS_GetMacAddress(mac);
        for (i = 0; i < 0x10; i++) {
            if (func_02177B80(i) == 0x20 && sub_0202E8D8((void *)func_0203CF10(i), (int)key, (char *)mac) != 0) {
                return i;
            }
        }
    }
    return -1;
}


/*
 * Three unlabelled leaves: a getter of the halfword at +0x312 of the context
 * object (0 when there is none), a raising setter of the halfword at +0x314
 * (only upward, and only below 4; the first compare is signed, the bound
 * unsigned, so the parameter is u32 and the field is compared as int), and
 * an empty function.
 */
/*
 * wih_dwc.c: three unlabelled leaves after sub_020107FC (whose listing extent
 * runs to 0x02010888 because none of them saves lr): a getter of the halfword
 * at +0x312 of the object behind 0x021461E0 (0 when there is none), a raising
 * setter of the halfword at +0x314 (only upward, and only below 4; the first
 * compare is signed, the bound unsigned, so the parameter is u32 and the
 * field is compared as int), and an empty function.  func_02010888
 * (src/matched/func_02010888.c) follows.
 *
 * SEED REQUEST for the integrator: arm9 0x02010848 thumb, 0x02010864 thumb,
 * 0x02010884 thumb (witness: this unit).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02010848.c \
 *       --addr 0x02010848 --thumb
 */
u16 func_02010848(void)
{
    if (g_021461E0.obj != 0)
        return g_021461E0.obj->f312;
    return 0;
}


void func_02010864(u32 v)
{
    struct WihObj *o = g_021461E0.obj;

    if (o != 0 && (int)o->f314 < (int)v && v < 4)
        o->f314 = v;
}


void func_02010884(void)
{
}


/*
 * Stores the step callback at the task's +8 field.
 */
/*
 * Stores the value at the object's +8 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010888.c \
 *       --func func_02010888 --addr 0x02010888 --thumb --cc 1.1p1
 */
void func_02010888(struct WihTask *p, void (*f)(struct WihTask *p))
{
    p->f8 = f;
}


/*
 * net_save.c task constructors for the 0x14-byte task object, its poll, and
 * the eight-byte tail-call stub func_02010934 (a tail call into the ARM
 * function 0x020307B0).  Both constructors end with the same two statements:
 * the debug allocator func_02030734(heap, 0x14, 1, "net_save.c", line)
 * (0x020A725C is two bytes into the "net_save.c" string at 0x020A7258) and
 * func_02010888(p, func_0201093C).  func_02010904 calls the callback with
 * the object in r0, then tests func_0200FB24()'s result; that call has no
 * argument of its own (r0 still holds the callback's return value).  The
 * two `return 1` arms are written separately and the +0x08 load is re-read
 * after the calls.
 */
/*
 * The whole range 0x0201088C..0x0201093C: two constructors for the same
 * 0x14-byte object, its destructor-or-poll, and the eight-byte tail-call
 * stub that sits between them and func_0201093C.
 *
 *   func_0201088C   allocator + one stored field (+0x0C)
 *   func_020108C4   allocator + three stored fields (+0x00, +0x04, +0x0C)
 *   func_02010904   fire the +0x08 callback, then two liveness tests
 *   (0x02010934)    `ldr r3, [pc, #0]; bx r3; .word func_020307B0`
 *
 * The stub is a real function: `ov119` at 0x021E0C5C and `ov137` at
 * 0x021DF696 both `bl` it.  It carries no label because it has no prologue
 * (disasm.py only labels a function that saves lr), so it is written here as
 * the tail call it is - a void function whose body is one call to the ARM
 * function 0x020307B0 with the object passed through in r0, which is what
 * puts the pool word and the `bx r3` there and what makes the unit's extent
 * end at 0x0201093C.  Since then seeded as a start in
 * layout/function_starts.txt (both callers set r0 to the object at +0xEF8 /
 * their own field before the bl), so the listing labels it func_02010934.
 *
 * Both constructors end with the same two statements: the SDK debug
 * allocator func_02030734(heap, 0x14, 1, "net_save.c", line) - 0x020A725C is
 * two bytes into the "net_save.c" string at 0x020A7258, so the file anchor is
 * net_save.c - and then func_02010888(p, func_0201093C), which stores the
 * callback into +0x08.  The two pool words per constructor are the file
 * string and that callback address with its Thumb bit, 0x0201093D.
 *
 * func_02010904 calls the callback with the object in r0, then tests
 * func_0200FB24()'s result.  That call is left with no argument of its own:
 * r0 still holds whatever the callback returned, which is what the original
 * does and what a no-argument call in the source produces.  The two `return
 * 1` arms are written separately (two `movs r0, #1` epilogues in the
 * original) and the +0x08 load is re-read after the calls.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201088C.c \
 *       --addr 0x0201088C --thumb
 */
struct WihTask *func_0201088C(u32 heap, u32 a1)
{
    struct WihTask *p;

    p = func_02030734(heap, 0x14, 1, (const char *)&s0x020A725C, 0x75);
    p->fC = a1;
    func_02039C68((struct Link *)func_020399A8(), 0x71, 8);
    func_02010888(p, func_0201093C);
    return p;
}


struct WihTask *func_020108C4(u32 heap, u32 a1, void (*cb)(u32 arg), u32 arg)
{
    struct WihTask *p;

    p = func_02030734(heap, 0x14, 1, (const char *)&s0x020A725C, 0x87);
    p->f0 = cb;
    p->f4 = arg;
    p->fC = a1;
    func_02039C68((struct Link *)func_020399A8(), 0x71, 8);
    func_02010888(p, func_0201093C);
    return p;
}


u32 func_02010904(struct WihTask *p)
{
    if (p->f8 != 0)
        p->f8(p);
    if (func_0200FB24() != 0) {
        if (p->fC != 0)
            func_02012E08(p->fC);
        return 1;
    }
    if (p->f8 == 0)
        return 1;
    return 0;
}

void func_02010934(struct WihTask *p)
{
    func_020307B0(p);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201093C.c \
 *       --func func_0201093C --addr 0x0201093C --thumb --cc 1.1p1
 */
void func_0201093C(struct WihTask *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x71, 8) != 0) {
        func_02012DAC(p->fC);
        func_02010888(p, func_02010964);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010964.c \
 *       --func func_02010964 --addr 0x02010964 --thumb --cc 1.1p1
 */
void func_02010964(struct WihTask *p)
{
    if (func_02012DD0(p->fC) == 1) {
        func_02039C68((struct Link *)func_020399A8(), 0x72, 8);
        p->f10 = func_020056EC(0x3c);
        func_02010888(p, func_02010994);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010994.c \
 *       --func func_02010994 --addr 0x02010994 --thumb --cc 1.1p1
 */
void func_02010994(struct WihTask *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x72, 8) != 0) {
        func_02010888(p, func_020109B8);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020109B8.c \
 *       --func func_020109B8 --addr 0x020109B8 --thumb --cc 1.1p1
 */
void func_020109B8(struct WihTask *p)
{
    s32 v = p->f10 - 1;

    p->f10 = v;
    if (v < 0) {
        func_02039C68((struct Link *)func_020399A8(), 0x73, 8);
        func_02010888(p, func_020109E0);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020109E0.c \
 *       --func func_020109E0 --addr 0x020109E0 --thumb --cc 1.1p1
 */
void func_020109E0(struct WihTask *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x73, 8) != 0) {
        func_02010888(p, func_02010A04);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010A04.c \
 *       --func func_02010A04 --addr 0x02010A04 --thumb --cc 1.1p1
 */
void func_02010A04(struct WihTask *p)
{
    if (p->f0 != 0) {
        p->f0(p->f4);
    }
    if (func_02012DD0(p->fC) == 2) {
        p->fC = 0;
        func_02039C68((struct Link *)func_020399A8(), 0x74, 8);
        func_02010888(p, func_02010A3C);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010A3C.c \
 *       --func func_02010A3C --addr 0x02010A3C --thumb --cc 1.1p1
 */
void func_02010A3C(struct WihTask *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x74, 8) != 0) {
        func_02010888(p, 0);
    }
}


int sub_02010A5C(void *a0)
{
    struct SaveCtx *p;
    void *sys;

    func_0203064C(1, 0x67, 0x78000);
    p = func_0203159C(a0, 0x1d8, 0x67);
    func_02082BCC(p, 0, 0x1d8);
    p->heapId = 0x67;
    sys = sub_020124F4(0x67);
    p->sys = sys;
    if (sub_020092EC((const struct Sub02009210Obj *)sub_02009448(sub_02012EBC(sys))) != 0) {
        p->state = 1;
        p->f54 = 1;
    } else {
        p->state = 0;
        p->f54 = 0;
    }
    return 1;
}


/*
 * The net_save.c save task's per-frame step (state word at +0x1D4): case 0
 * starts overlay 0x73's proc 0x021D6338 on the record, case 1 starts overlay
 * 0x7B's proc on +0x48 unless +0x1C says finished, case 2 hands off to
 * func_0200F7B8(0), case 3 restarts overlay 0x73 with proc 0x021D654C on +0x28
 * or ends the task.  d_021DA9A8 lies in the windows of several overlays; the
 * ov123 hint is supported by the proc table bytes there (three Thumb
 * pointers into ov123).
 */
/*
 * history:  was MATCH on evidence only (every concrete byte matched).  Wave 17:
 *           the pooled overlay ids 0x73 / 0x7B (ov115_id, ov123_id) now
 *           resolve as `overlay_id` (id argument of func_020312CC).  Two
 *           ABS32 sites are left, the overlay-resident proc pointers
 *           0x021D6338 / 0x021D654C, whose only other pool words sit in
 *           func_02010C34's pool (0x02010D84..), which disasm.py prints as
 *           Thumb code, so the literal index misses them.  Seeding those
 *           pools as .word, or a matched referrer, would close both.
 *           Seed round 10: both words are ov115 proc tables (three Thumb
 *           function pointers each, 0x021D6338 -> func_021D4BFC/4CE4/4D10,
 *           0x021D654C -> func_021D603C/6104/60D4), loaded with overlay id
 *           0x73 = ov115, not ov021 (docs/sessions/2026-09-23/reports/
 *           wave17_evidence.md).  ov115 declares both starts in
 *           layout/data_objects.txt and the symbols lines carry the ov115
 *           token.  0x021D654C resolves as sole-ref/data (ov115 is the only
 *           overlay with a start there).  0x021D6338 resolves as
 *           sole-ref/self on the ov115 hint; ov021's listing also starts a
 *           block there, so sole-ref/data refuses the contested hint, and the
 *           choice rests on the hint plus the overlay_id 0x73 site in this
 *           same function.  EXACT, seed round 10.
 * evidence: d_021DA9A8 lies in the windows of ov016, ov021, ov123, ov125
 *           and ov175, so the ov123 hint needs outside support.  Case 1
 *           passes ov123_id (0x7B, attested `overlay_id`) and this pointer
 *           in one func_020312CC call; func_020314F4 -> func_02031538 stores
 *           the id at Proc+4 and the pointer at Proc+0 (ProcData), and
 *           func_020315F0 loads overlay Proc+4 (func_02034AC4) before it
 *           calls any ProcData callback.  So ov123 is resident whenever the
 *           pointer is dereferenced.  Independently, ov123's bytes at
 *           0x021DA9A8 are three Thumb pointers 0x021DA479/0x021DA54D/
 *           0x021DA5D1, each a func_ label in ov123's own listing, while
 *           ov125 has bss there and ov016/ov021/ov175 hold non-pointer
 *           words.  With the hint the site attests as `sole-ref` in ov123.
 *
 * The net_save.c save task's per-frame step (the task record of
 * sub_02010A5C; state word at +0x1D4): case 0 starts overlay 0x73's proc
 * 0x021D6338 on the record, case 1 starts overlay 0x7B's proc on +0x48
 * unless +0x1C says finished, case 2 hands off to func_0200F7B8(0), case 3
 * restarts overlay 0x73 with proc 0x021D654C on +0x28 or ends the task.
 * Wave 13: the earlier DIFF read both small pool words as distinct symbols
 * and the size argument as 0x1A8; they are the arguments (0x73, proc, arg).
 */
int func_02010AC4(u32 a0, u32 a1, u32 a2, struct SaveCtx *ctx)
{
    switch (ctx->state) {
    case 0:
        ctx->a.sys = ctx->sys;
        ctx->a.f4 = 0;
        ctx->a.f8 = 1;
        ctx->a.fC = 0x32;
        ctx->a.buf = ctx->buf5C;
        func_020312CC((u32)ov115_id, d_021D6338, ctx);
        ctx->state += 1;
        break;
    case 1:
        if (ctx->f1C == 1) {
            ctx->state = 4;
            break;
        }
        ctx->b.sys = ctx->sys;
        ctx->b.heapId = ctx->heapId;
        ctx->b.buf = ctx->buf5C;
        func_020312CC((u32)ov123_id, d_021DA9A8, &ctx->b);
        ctx->state += 1;
        break;
    case 2:
        if (ctx->f54 == 1) {
            ctx->state = 4;
            break;
        }
        func_0200F7B8(0);
        ctx->state += 1;
        break;
    case 3:
        if (func_0203CD98() == 0 || ctx->f58 == 1) {
            ctx->f14 = 1;
            ctx->state = 0;
            break;
        }
        ctx->c.sys = ctx->sys;
        ctx->c.f4 = 0;
        ctx->c.f8 = 1;
        func_020312CC((u32)ov115_id, d_021D654C, &ctx->c);
        ctx->state += 1;
        break;
    default:
        return 1;
    }
    return 0;
}
