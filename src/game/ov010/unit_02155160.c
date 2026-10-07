/*
 * file:     unit_02155160.c
 * unit:     yes
 * function: func_02155160, func_0215518C, func_02155200, func_02155224, func_02155244, func_02155328
 * address:  0x02155160
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
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02019CA0  0x02019CA0  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0201BA34  0x0201BA34  thumb
 *   func_0201A9C8  0x0201A9C8  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02012950  0x02012950  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009D1C  0x02009D1C  thumb
 *   func_02009BB8  0x02009BB8  thumb
 *   func_02009B80  0x02009B80  thumb
 *   d_0216FED8     0x0216FED8  data  ov010  a1
 *   d_0216FEDC     0x0216FEDC  data  a1
 */
struct BigObj;
struct Party;
struct PartyMon;
struct Rec534;
struct Entry;
struct Link;
struct Rec44;
struct Sub020097BCObj;
struct Sub24;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Ctx_0215518C {
    void *f00;
    u8 pad04[0x34];
    void *f38;
    u8 pad3c[0x10];
    void *f4c;
};

typedef signed int     s32;

struct Ctx_02155224 {
    u8 pad00[0x38];
    void *f38;
    void *f3c[4];
};

struct Info {
    u8 pad00[0x22];
    u8 f22;
};

struct Ctx_02155244 {
    u8 pad00[0x78];
    u8 b78[4];
    u8 pad7c[0x0c];
    struct Info *f88;
    u8 pad8c[0x40];
    int fcc;
};

typedef struct { u8 v[2]; } Map2;

typedef struct { u8 v[4]; } Map4;

struct Slot {
    void *list;
    void *mon;
    u8 pad08[8];
};

struct Ctx_02155328 {
    u8 pad00[0x3c];
    void *f3c[4];
    u8 pad4c[0x2c];
    u8 b78[4];
    u8 pad7c[0x0c];
    struct Info *f88;
    struct Slot slot[4];
};

extern u32 func_0201AA18(void *list);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_02019CA0(void *p, u32 v);
extern void *func_0200BAC8(void *p);
extern void *func_020120F4(const struct Ctx_0215518C *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void *func_0200BAF4(int a, int b);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern u32 func_020307B0(void *p);
extern void func_0201BA34(void *p);
extern u32 func_0201A9C8(struct Party *p, s32 idx);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u32 func_0201283C(const struct BigObj *p);
extern int func_02009D1C(struct Sub020097BCObj *obj, struct Sub0200852CObj *p, u32 *out);
extern void func_02009BB8(struct Sub020097BCObj *obj, int i, int a, int b, int c);
extern void func_02009B80(struct Sub020097BCObj *obj, int i);
void func_02155160(void *list);
void func_0215518C(int mode, struct Ctx_0215518C *ctx);
void func_02155200(void *list);
void func_02155224(struct Ctx_02155224 *ctx);
void func_02155244(struct Ctx_02155244 *ctx, void *party);
void func_02155328(struct Ctx_02155328 *ctx, void *party);
extern const Map2 d_0216FED8;
extern const Map4 d_0216FEDC;


void func_02155160(void *list)
{
    int i;

    for (i = 0; i < (int)func_0201AA18(list); i++)
        func_02019CA0(func_0201AB28(list, i), 50);
}


/*
 * Rebuilds the list at +0x38: either from the party list at +0 (skipping
 * entries whose field 0x4c is set) or from a fresh six-slot list, then
 * refreshes it. func_0200BAC8 is a tail-calling wrapper whose result is
 * used here, so this unit declares it returning a value.
 */
void func_0215518C(int mode, struct Ctx_0215518C *ctx)
{
    int t;
    void *e;
    int i;
    void *list;
    void *h;
    t = (int)func_0200BAC8(ctx->f4c);
    if (mode == 0) {
        list = func_02012934(func_020120F4(ctx->f00));
        for (i = 0; i < (int)func_0201AA18(list); i++) {
            e = func_0201AB28(list, i);
            if (func_02017E1C(e, 0x4c, 0) == 0)
                func_0201A98C(ctx->f38, e);
        }
    } else {
        h = func_0200BAF4(t, 4);
        func_0201AC2C(h, ctx->f38);
        func_020307B0(h);
    }
    func_0201BA34(ctx->f38);
    func_02155160(ctx->f38);
}


/*
 * Trims a list to its first three entries by removing entry 3 until only three remain.
 */
void func_02155200(void *list)
{
    int i;
    int n;

    n = func_0201AA18(list);
    for (i = 3; i < n; i++)
        func_0201A9C8(list, 3);
}


/*
 * Trims the list at +0x38 and the four lists at +0x3c to three entries each.
 */
void func_02155224(struct Ctx_02155224 *ctx)
{
    int i;

    func_02155200(ctx->f38);
    for (i = 0; i < 4; i++)
        func_02155200(ctx->f3c[i]);
}


void func_02155244(struct Ctx_02155244 *ctx, void *party)
{
    int sel;
    int count;
    int out;
    int i;
    int t;
    u32 v;
    void *mon;

    sel = 0;
    if (ctx->f88->f22 == 0) {
        sel = sel - 1;
        count = 2;
    } else {
        v = ctx->b78[func_0203D1A4((struct Link *)((u32)func_020399A8()))];
        if (v < 2) {
            t = 1;
        } else {
            v -= 2;
            t = 3;
        }
        t = t - v;
        for (i = 0; i < 4; i++) {
            if (t == ctx->b78[i]) {
                sel = i;
                break;
            }
        }
        count = 4;
    }

    for (i = 0; i < count; i++) {
        mon = func_02012950(party, i);
        if (i != func_0203D1A4((struct Link *)((u32)func_020399A8())) && mon != 0
            && func_02009D1C((void *)func_0201283C(party), mon, (u32 *)(&out)) != 0) {
            if (i == sel) {
                func_02009B80((struct Sub020097BCObj *)func_0201283C(party), out);
            } else if (ctx->fcc == 0) {
                func_02009BB8((struct Sub020097BCObj *)func_0201283C(party), out, 1, 0, 0);
            } else if (ctx->fcc == 1) {
                func_02009BB8((struct Sub020097BCObj *)func_0201283C(party), out, 0, 1, 0);
            } else {
                func_02009B80((struct Sub020097BCObj *)func_0201283C(party), out);
            }
        }
    }
}


/*
 * Binds each party slot's list (+0x3c) and party member into the 16-byte
 * slot records at +0x8c, indexed through the position byte at +0x78,
 * remapped through a small constant table when the local player is not
 * on the first side. The two tables are the unit's rodata copied into
 * locals ({1, 0} at 0x0216FED8, {2, 3, 0, 1} at 0x0216FEDC).
 *
 * The ABS32 to 0x0216FED8 resolves as sole-ref/data since
 * overlay_data_structure() ends each extent at its last instruction's real
 * length (func_0216FEAC ends in the 2-byte pop at 0x0216FED6).
 */
void func_02155328(struct Ctx_02155328 *ctx, void *party)
{
    Map4 m4;
    Map2 m2;
    int i;

    if (ctx->f88->f22 != 0) {
        if (ctx->b78[func_0203D1A4((struct Link *)((u32)func_020399A8()))] < 2) {
            for (i = 0; i < 4; i++) {
                ctx->slot[ctx->b78[i]].list = ctx->f3c[i];
                ctx->slot[ctx->b78[i]].mon = func_02012950(func_020120F4(party), i);
            }
        } else {
            i = 0;
            m4 = d_0216FEDC;
            for (; i < 4; i++) {
                ctx->slot[m4.v[ctx->b78[i]]].list = ctx->f3c[i];
                ctx->slot[m4.v[ctx->b78[i]]].mon = func_02012950(func_020120F4(party), i);
            }
        }
    } else {
        if (func_0203D1A4((struct Link *)((u32)func_020399A8())) == 0) {
            for (i = 0; i < 2; i++) {
                ctx->slot[ctx->b78[i]].list = ctx->f3c[i];
                ctx->slot[ctx->b78[i]].mon = func_02012950(func_020120F4(party), i);
            }
        } else {
            i = 0;
            m2 = d_0216FED8;
            for (; i < 2; i++) {
                ctx->slot[m2.v[ctx->b78[i]]].list = ctx->f3c[i];
                ctx->slot[m2.v[ctx->b78[i]]].mon = func_02012950(func_020120F4(party), i);
            }
        }
    }
}
