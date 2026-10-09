/*
 * file:     unit_02064D70_p07.c
 * unit:     yes
 * function: func_02065878, func_020659D4
 * address:  0x02065878
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02065438  0x02065438  arm
 *   func_0206615C  0x0206615C  arm
 *   func_02067B50  0x02067B50  arm
 *   func_02067B64  0x02067B64  arm
 *   func_020663D0  0x020663D0  arm
 *   func_02066620  0x02066620  arm
 *   func_020664CC  0x020664CC  arm
 *   func_02066380  0x02066380  arm
 *   g_02147B88     0x02147B88  data  a4
 *   g_020A81F8     0x020A81F8  data  a4
 *   g_020A1B38     0x020A1B38  data  a2
 */
struct G2dOamState;
struct Obj02065878;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed   short s16;

typedef unsigned int   u32;

typedef int            fx32;

struct Obj02065878 {
    u8   pad_00[0x30];
    void *unk_30;
    u8   pad_34[4];
    int  unk_38;
    u8   pad_3c[4];
    fx32 unk_40;
    fx32 unk_44;
    s16  unk_48;
    s16  unk_4a;
    u16  unk_4c;
    u16  unk_4e;
};

struct B8802065878 {
    u8  pad_00[8];
    int unk_08;
};

struct Scr02065878 {
    u8  pad_00[4];
    int unk_04;
};

struct Cmd020659D4 {
    int  unk_00;
    u8   pad_04[4];
    int  unk_08;
    u8   pad_0c[4];
    fx32 unk_10;
    fx32 unk_14;
    s16  unk_18;
    s16  unk_1a;
    u16  unk_1c;
    u16  unk_1e;
};

struct B88020659D4 {
    u8  pad_00[8];
    int unk_08;
};

extern void  func_02065438(void *a);
extern void func_0206615C(void);
extern u32 func_02067B50(const struct G2dOamState *p);
extern u32 func_02067B64(const struct G2dOamState *p);
extern void  func_020663D0(fx32 x, fx32 y, fx32 z);
extern void  func_02066620(fx32 sn, fx32 cs);
extern void  func_020664CC(fx32 sx, fx32 sy, fx32 sz);
extern void  func_02066380(int a);
void func_02065878(struct Obj02065878 *c);
void func_020659D4(struct Cmd020659D4 *c);
extern struct B8802065878 g_02147B88;
extern struct Scr02065878 g_020A81F8;
extern s16 g_020A1B38[];


static inline void Draw(struct Obj02065878 *c, void *a)
{
    int r;
    r = !(c->unk_38 == -1);
    if (r != 0) {
        g_020A81F8.unk_04 = c->unk_38;
        func_02065438(a);
        g_020A81F8.unk_04 = -1;
    } else {
        func_02065438(a);
    }
}


/*
 * The plain draw of one cell actor with its inline transform record, the
 * sibling of src/matched/func_02066080.c (record at +0x30 here, laid out
 * exactly as struct DrawCmd of docs/families/cluster_02064B68.h shifted by
 * 0x30: handle +0x30, alternate-surface id +0x38, scale +0x40/+0x44,
 * translate +0x48/+0x4a, angle +0x4c, flags +0x4e).  The draw itself is an
 * inline bracket: with a surface id other than -1 the id is published in
 * g_020A81F8+4 around func_02065438 and reset to -1 afterwards.  The
 * bracket is written out twice in the image (untransformed early exit and
 * the transformed tail), which is what an inline helper gives.
 *
 * Pinned to ../2.0/sp2: the image rematerialises the -1 (`mvn r0, #0` for
 * the compare, `mvn r1, #0` for the reset) and keeps a MATERIALISED boolean
 * (`movne r0, #1` / `moveq r0, #0` / `cmp r0, #0`) in front of each bracket.
 * THE LEVER is the spelling of that boolean: `r = !(c->unk_38 == -1);`.
 * Under the pin, `c->unk_38 != -1` (as an inline return, a named local, a
 * ternary, `!!(...)` or an if/else pair of assignments) folds the test into
 * a branch and is 324 bytes against 348; `r = 0; if (...) r = 1;` is size-
 * exact but 36 out; only the negated equality is EXACT.  Under dsi/1.1p1
 * every spelling is 308..340 bytes.
 */
void func_02065878(struct Obj02065878 *c)
{
    void *a = c->unk_30;

    if (c->unk_4e == 0) {
        Draw(c, a);
        return;
    }

    func_0206615C();

    if ((c->unk_4e & 8) != 0) {
        int x, y;

        y = c->unk_4a;
        x = c->unk_48;

        if (func_02067B50((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            x = -x;
        if (func_02067B64((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            y = -y;

        func_020663D0(x << 12, y << 12, 0);
    }

    if ((c->unk_4e & 4) != 0) {
        int i = c->unk_4c >> 4;

        func_02066620(g_020A1B38[i * 2], g_020A1B38[i * 2 + 1]);
    }

    if ((c->unk_4e & 2) != 0)
        func_020664CC(c->unk_40, c->unk_44, 0x1000);

    Draw(c, a);
    func_02066380(1);
}


void func_020659D4(struct Cmd020659D4 *c)
{
    int a;

    if (c->unk_08 == 0)
        return;

    a = c->unk_00;
    func_0206615C();

    if ((c->unk_1e & 8) != 0) {
        int x, y;

        y = c->unk_1a;
        x = c->unk_18;

        if (func_02067B50((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            x = -x;
        if (func_02067B64((const struct G2dOamState *)g_02147B88.unk_08) != 0)
            y = -y;

        func_020663D0(x << 12, y << 12, 0);
    }

    if ((c->unk_1e & 4) != 0) {
        int i = c->unk_1c >> 4;

        func_02066620(g_020A1B38[i * 2], g_020A1B38[i * 2 + 1]);
    }

    if ((c->unk_1e & 2) != 0)
        func_020664CC(c->unk_10, c->unk_14, 0x1000);

    func_02065878((struct Obj02065878 *)a);
    func_02066380(1);
}
