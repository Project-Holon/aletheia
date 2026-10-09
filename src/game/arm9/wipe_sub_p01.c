/*
 * file:     wipe_sub_p01.c
 * unit:     yes
 * function: func_02021728, func_02021730, func_0202173C, func_02021848, func_02021930, func_02021944, func_02021984, func_020219C4, func_02021A84, func_02021B18, func_02021B2C, func_02021B4C, func_02021B6C, func_02021BC8, func_02021C20, func_02021CA8, func_02021D50, func_02021ED8, func_02021EE4, func_02021F08, func_02021F3C, func_02021F64, func_02021FD8, func_02022004, func_02022040, func_0202208C, func_02022174, func_020221A4, func_020221B8, func_02022224, func_02022230, func_0202223C, func_02022268, func_020222A8, func_020222CC
 * address:  0x02021728
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EAC   0x02030EAC  arm
 *   func_020862F0   0x020862F0  arm
 *   func_0207E3D0   0x0207E3D0  arm
 *   func_0207E468   0x0207E468  arm
 *   func_0207E51C   0x0207E51C  arm
 *   func_0207E5D0   0x0207E5D0  arm
 *   func_0207F308   0x0207F308  arm
 *   func_0207F394   0x0207F394  arm
 *   func_0207F428   0x0207F428  arm
 *   func_0207F47C   0x0207F47C  arm
 *   func_0207F4C4   0x0207F4C4  arm
 *   func_0207F560   0x0207F560  arm
 *   func_0207F5B0   0x0207F5B0  arm
 *   func_0207F5C8   0x0207F5C8  arm
 *   func_0207F65C   0x0207F65C  arm
 *   func_0207F6A8   0x0207F6A8  arm
 *   func_0207F6C0   0x0207F6C0  arm
 *   func_0207F754   0x0207F754  arm
 *   g_021467A4                0x021467A4  data
 *   CARD_GetBackupSectorSize  0x0204E6E0  arm
 *   _s32_div_f                0x0209C0A4  arm
 *   func_020226A0             0x020226A0  thumb
 *   func_020223C0             0x020223C0  thumb
 *   func_02022458             0x02022458  thumb
 *   func_020225F4             0x020225F4  thumb
 *   func_02022430             0x02022430  thumb
 *   func_02022390             0x02022390  thumb
 *   func_02022640             0x02022640  thumb
 *   func_02022340  0x02022340  thumb
 *   func_020222EC  0x020222EC  thumb
 *   func_020224DC  0x020224DC  thumb
 *   func_02023B48  0x02023B48  thumb
 *   g_021468E4     0x021468E4  data
 *   func_0207D534  0x0207D534  arm
 */
#include "../../matched/include/Obj06878.h"
#include "../../matched/include/Obj08779.h"
#include "../../matched/include/Obj15732.h"

struct Chan02021984;
struct S02021944;
struct S02021A84;
struct S020219C4;
struct Node;
struct C02021C20;
struct S;
struct Sub;
struct Slots;
struct Mode;
struct TextObj;
struct Cluster;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct Sub {
    u32   f00;
    u32   f04;
    s32   f08;
    u32   f0C;
    u32   f10;
    u32   f14;
    void *f18;
    void *f1C;
    u32   f20;
    u16   f24;
    u16   f26;
    u32   f28;
    void *f2C;
};


struct G {
    u8          pad00[4];
    void       *f04;
    void       *f08;
    void       *f0C;
    void       *f10;
    struct Sub  f14;
    struct Sub  f44;
    u8          f74[0x18];
    u8          f8C[0xC0];
    u16         f14C;
    u8          f14E;
    u8          f14F;
    u16         f150;
};

typedef signed   short s16;

typedef signed   char  s8;

typedef struct {
    u16 *src;
    u16 *dst;
    u32 f8;
    u32 fc;
    u32 f10;
} PalAnmChan;

typedef struct {
    PalAnmChan ch[14];
    u16 a_mode : 2;
    u16 a_big  : 14;
    u16 b_lo : 14;
    u16 b_x  : 1;
    u16 b_hi : 1;
    u8  latch;
} PalAnmObj;

struct S02021944 {
    char pad[0x11a];
    u16 lo : 14;
    u16 hi : 2;
};

struct Chan02021984 {
    u32 f0;
    u32 f4;
    u32 f8;
};

struct S020219C4 {
    u16 f0;
    u16 lo  : 6;
    u16 mid : 5;
    u16 hi  : 5;
    u16 val  : 15;
    u16 flag : 1;
    u16 step : 5;
    u16 copy : 6;
    u16 pad6 : 5;
};

struct S02021A84 {
    char pad[0x118];
    u16 a_mode : 2;
    u16 a_big  : 14;
    u16 b_lo : 14;
    u16 b_x  : 1;
    u16 b_hi : 1;
    u8  latch;
};

struct Obj02021B18 {
    u8  pad0[0x118];
    u16 lo : 2;
    u16 hi : 14;
    u16 pad11a;
    u8  flag;       /* +0x11c */
};

struct S02021B6C {
    u8 pad0[0xe];
    u16 cap : 6;
    u16 padE : 10;
    u16 pad10[1];
    u16 pad12a : 5;
    u16 cur : 6;
    u16 pad12b : 5;
};

struct S02021B6C_hdr {
    u16 pad118a : 2;
    u16 flags118 : 14;
};

struct S02021BC8 {
    u8  *p0;
    u8  *p1;
    u16  f8;
    u16  fA;
    u16  field0xc;
};

struct C02021C20 {
    u16 f0;
    u16 lo6 : 6;
    u16 weight : 5;
    u16 hi : 5;
    u16 target : 15;
    u16 sign : 1;
};

struct S {
    u16 f0;
    u16 lo6 : 6;
    u16 cur : 5;
    u16 max : 5;
    u16 dir : 15;
    u16 sign : 1;
    u16 step : 5;
};

struct Chan {
    u32 f0;
    void *f4;
    u32 f8;
    u32 fc;
    u32 f10;
};

struct S02021D50 {
    struct Chan ch[14];
    u16 a_mode : 2;
    u16 a_big  : 14;
    u16 b_lo : 14;
    u16 b_x  : 1;
    u16 b_hi : 1;
};

struct Obj02021EE4 {
    u8  pad0[0x11a];
    u16 lo  : 15;
    u16 top : 1;
};

struct Obj02021F08 {
    u8  pad0[0x118];
    u16 a_mode : 2;
    u16 a_big  : 14;
};

typedef struct {
    u16 *a;
    u16 *b;
    int pad[3];
} Slot;

struct Rgb555 {
    u16 r : 5;
    u16 g : 5;
    u16 b : 5;
    u16 pad : 1;
};

struct Chan02021FD8 {
    u16 *src;
    u16 *dst;
    u32 f8;
    u32 fc;
    u32 f10;
};

struct G021468E4 {
    u8  pad[0x10];
    u16 f10;
};

extern void func_02030DA8(void *ctx, void (*fn)(void *, PalAnmObj *), PalAnmObj *p, s32 pri);
extern void func_02030EAC(struct Node *n);
extern void func_020862F0(void *a, u32 b);
extern void func_0207E3D0(void *a, u32 b, u32 c);
extern void func_0207E468(void *a, u32 b, u32 c);
extern void func_0207E51C(void *a, u32 b, u32 c);
extern void func_0207E5D0(void *a, u32 b, u32 c);
extern void func_0207F308(void);
extern void func_0207F394(void *a, u32 b, u32 c);
extern void func_0207F428(void);
extern void func_0207F47C(void);
extern void func_0207F4C4(void *a, u32 b, u32 c);
extern void func_0207F560(void);
extern void func_0207F5B0(void);
extern void func_0207F5C8(void *a, u32 b, u32 c);
extern void func_0207F65C(void);
extern void func_0207F6A8(void);
extern void func_0207F6C0(void *a, u32 b, u32 c);
extern void func_0207F754(void);
extern u32   CARD_GetBackupSectorSize(void);
extern void func_020226A0(u8 *p);
extern void func_020223C0(u32 mode, struct Mode *p);
extern void func_02022458(struct Slots *p);
extern u32 func_020225F4(struct TextObj *obj, u32 value);
extern void  func_02022430(void *sub, u32 a, u32 b, s32 c, u32 d, u32 e,
                           u32 f, void *g, void *h, u32 i, void *j);
extern void func_02022390(u32 *obj, void *arg);
extern void func_02022640(struct Sub *s);
extern u32 func_02022340(struct Cluster *p, void *top, void *bottom);
extern void func_020222EC(struct G *g);
extern void func_020224DC(struct Slots *p, u32 idx);
extern u32 func_02023B48(u32 kind, void *win);
extern void func_0207D534(volatile u16 *reg, int brightness);
int func_02021728(char *p, int i);
int func_02021730(char *p, int i);
int func_0202173C(PalAnmObj *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
int func_02021848(PalAnmObj *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
u8 func_02021930(u32 val, int bit);
void func_02021944(struct S02021944 *p, int a1);
void func_02021984(s32 idx, struct Chan02021984 *c, u16 *pv);
void func_020219C4(struct S020219C4 *s, u16 f0, s32 a, u8 b, u8 c, u16 d);
void func_02021A84(void *a, struct S02021A84 *p);
void sub_02021B18(struct Obj02021B18 *o);
void func_02021B2C(u8 *p);
void func_02021B4C(u8 *p);
void func_02021B6C(u8 *p, u32 idx, u32 arg);
void func_02021BC8(u8 *p, u32 idx, u32 arg);
void func_02021C20(u16 *src, u16 *dst, struct C02021C20 *c, u32 count);
void func_02021CA8(u8 *p, u32 idx, struct S *s);
void func_02021D50(struct S02021D50 *p);
u32 func_02021ED8(const char *ptr);
void sub_02021EE4(struct Obj02021EE4 *o, int v);
void func_02021F08(struct Obj02021F08 *o, int v);
u16 func_02021F3C(Slot *s, int idx, int which, u16 pos);
void func_02021F64(u16 *src, u16 *dst, u32 count, int weight, u16 color);
void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
void func_02022004(struct Chan02021FD8 *a0, u32 a1, u16 m, u8 a3, u16 a4);
void func_02022040(u16 *pal, int n, const u8 *table);
void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
void func_02022174(void);
u32 func_020221A4(void);
void func_020221B8(void);
u32 func_02022224(void *win);
void func_02022230(u32 which);
void func_0202223C(u32 a, u32 color);
void func_02022268(u32 color);
void func_020222A8(u32 a);
void func_020222CC(u32 which, int brightness);
extern struct G g_021467A4;
extern struct G021468E4 g_021468E4;








int func_02021728(char *p, int i)
{
    return *(int *)(p + i * 0x14);
}








/*
 * Unlabelled Thumb leaf in the ARM9 module: word field of a 0x14-byte strided
 * array.
 *
 * Addresses are Black-image addresses.
 */
int func_02021730(char *p, int i)
{
    return *(int *)(p + i * 0x14 + 4);
}









/*
 * Palette-animation engine (palanm.c). For each of the fourteen channels
 * whose bit is set in `mask` and not yet
 * set in p->a_big: narrow the colour to the channel's
 * width (func_02021984, through the address of `col`, which is why all
 * four register parameters are pushed), initialise the channel's
 * animation sub-object at +0xC, mark the channel (func_02021944), run it
 * once (func_02021BC8, 0x10 for channels 0..3, 0x100 for 4..0xD) and
 * restore `col`. If any channel started, OR the mask into a_big and, when the tick
 * is not registered yet (b_x), set b_x, a_mode = 1, clear the latch and
 * register func_02021A84 with func_02030DA8 at priority -2. Returns 1 when
 * a channel started.
 *
 * Written fresh in wave 20 (lane palanm_fresh). The 33-byte residue of
 * earlier waves (the entry `str r3, [sp, #8]` sliding behind the stack
 * parameter copies) closes with the parameter types read from the callee:
 * `step` is narrow (s16 here; u16 and s8 give the same bytes), and b, c,
 * d are u8, u8, u16 both here and in the func_020219C4 prototype (its own
 * matched body). The narrow step's home store is then emitted at the
 * front of the prologue
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 * With u32 b, c, d in the prototype the same source is 236 bytes.
 * func_020219C4 is declared with six parameters: the caller passes six and
 * the callee's seventh (never read) is whatever sits at [sp, #8].
 */
int func_0202173C(PalAnmObj *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx)
{
    u16 keep = col;
    int ret = 0;
    u8 i;

    for (i = 0; i < 14; i++) {
        if (func_02021930(mask, i) == 1 && func_02021930(p->a_big, i) == 0) {
            func_02021984(i, (struct Chan02021984 *)(&p->ch[i]), &col);
            func_020219C4((struct S020219C4 *)(&p->ch[i].fc), col, step, b, c, d);
            func_02021944((struct S02021944 *)p, i);
            if (i >= 4) {
                func_02021BC8((u8 *)p, i, 0x100);
            } else {
                func_02021BC8((u8 *)p, i, 0x10);
            }
            col = keep;
            ret = 1;
        }
    }
    if (ret == 1) {
        p->a_big |= mask;
        if (p->b_x == 0) {
            p->b_x = 1;
            p->a_mode = 1;
            p->latch = 0;
            func_02030DA8(ctx, (void (*)(void *, PalAnmObj *))func_02021A84, p, -2);
        }
    }
    return ret;
}









/*
 * Palette-animation engine (palanm.c). For each of the fourteen channels
 * whose bit is set in `mask`: narrow the colour to the channel's
 * width (func_02021984, through the address of `col`, which is why all
 * four register parameters are pushed), initialise the channel's
 * animation sub-object at +0xC, mark the channel (func_02021944), run it
 * once (func_02021BC8, 0x10 for channels 0..3, 0x100 for 4..0xD) and
 * restore `col`. If any channel started, store the mask to a_big and, when the tick
 * is not registered yet (b_x), set b_x, a_mode = 1, clear the latch and
 * register func_02021A84 with func_02030DA8 at priority -2. Returns 1 when
 * a channel started.
 *
 * Written fresh in wave 20 (lane palanm_fresh). The 33-byte residue of
 * earlier waves (the entry `str r3, [sp, #8]` sliding behind the stack
 * parameter copies) closes with the parameter types read from the callee:
 * `step` is narrow (s16 here; u16 and s8 give the same bytes), and b, c,
 * d are u8, u8, u16 both here and in the func_020219C4 prototype (its own
 * matched body). The narrow step's home store is then emitted at the
 * front of the prologue
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 * With u32 b, c, d in the prototype the same source is 236 bytes.
 * func_020219C4 is declared with six parameters: the caller passes six and
 * the callee's seventh (never read) is whatever sits at [sp, #8].
 */
int func_02021848(PalAnmObj *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx)
{
    u16 keep = col;
    int ret = 0;
    u8 i;

    for (i = 0; i < 14; i++) {
        if (func_02021930(mask, i) == 1) {
            func_02021984(i, (struct Chan02021984 *)(&p->ch[i]), &col);
            func_020219C4((struct S020219C4 *)(&p->ch[i].fc), col, step, b, c, d);
            func_02021944((struct S02021944 *)p, i);
            if (i >= 4) {
                func_02021BC8((u8 *)p, i, 0x100);
            } else {
                func_02021BC8((u8 *)p, i, 0x10);
            }
            col = keep;
            ret = 1;
        }
    }
    if (ret == 1) {
        p->a_big = mask;
        if (p->b_x == 0) {
            p->b_x = 1;
            p->a_mode = 1;
            p->latch = 0;
            func_02030DA8(ctx, (void (*)(void *, PalAnmObj *))func_02021A84, p, -2);
        }
    }
    return ret;
}









u8 func_02021930(u32 val, int bit)
{
    u8 ret;

    if (val & (1 << bit)) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}









void func_02021944(struct S02021944 *p, int a1)
{
    if (func_02021930(p->lo, a1) == 1)
        return;
    p->lo |= 1 << a1;
}





/*
 * Narrows *pv to the channel's own bit width. The width is an 8-bit field of
 * the channel record's word at +8: bits[5:13) for channels 0..3 and
 * bits[9:17) for 4..0xD. The mask is not built with a shift -- the original
 * really does accumulate `1 << n` in a u16 loop, so the source has to be
 * written as the loop, not as `(1 << w) - 1`.
 *
 * Three spellings are load-bearing. The `(u8)` narrowing of the width is
 * applied AFTER the if/else, not inside each arm, so both arms share the
 * `lsrs r4, r0, #0x18` (the shared-exit idiom). `w` is u32, not u8, or the
 * narrowing costs a second shift pair. And the do-while guard must be
 * spelled `if (n < w)` against the already-zeroed counter, not `if (w != 0)`
 * or `if (0 < w)`: only that form emits the original's `bls`, the others
 * emit `beq` -- a single byte, and the last one left in this function.
 *
 * EXACT* only: 62 bytes compiled, listing extent 64; the extra halfword at
 * 0x020219C2 is alignment padding, not an unlabelled follower.
 */
void func_02021984(s32 idx, struct Chan02021984 *c, u16 *pv)
{
    u32 t;
    u16 m;
    u8 n;
    u32 w;

    if (idx < 4) {
        t = c->f8 << 0x13;
    } else {
        t = c->f8 >> 9 << 0x18;
    }
    w = t >> 0x18;

    m = 0;
    n = 0;
    if (n < w) {
        do {
            m = (u16)(m + (u16)(1 << n));
            n++;
        } while (n < w);
    }

    *pv = *pv & m;
}





/*
 * Seven-argument initialiser for one 8-byte animation slot (the `+0xc`
 * sub-object of the 0x14-byte per-channel record; both callers, 0x0202173E
 * and 0x0202184A, pass `p + idx*0x14 + 0xc`). Arguments 5..7 arrive on the
 * caller's stack (visible as `add r5,sp,#0x10` with a bare `push {r4-r7}`
 * and no frame). Argument 7 is never read.
 *
 * Halfword layout of the slot:
 *   +0x00  u16 f0            (= arg2, stored whole)
 *   +0x02  lo:6, mid:5, hi:5
 *   +0x04  val:15, flag:1
 *   +0x06  step:5, copy:6, pad:5
 *
 * The narrow parameter types are load-bearing, not cosmetic. Args 5 and 6
 * are read with `ldrb [r5]` / `ldrh [r5,#4]` off the stack-arg area, which
 * only happens when they are declared u8 / u16; and arg 4 must be u8 (not
 * u32 or u16), or the 5-bit bitfield store costs an extra u16-truncation
 * shift pair -- 8 bytes over 192, and the whole tail shifts with it.
 */
void func_020219C4(struct S020219C4 *s, u16 f0, s32 a, u8 b, u8 c, u16 d)
{
    u8 n;

    if (a < 0) {
        n = (u8)((a < 0 ? -a : a) + 2);
        if (n > 0x10) {
            n = 0x10;
        }
        s->step = n;
        s->lo = 0;
    } else {
        s->step = 2;
        s->lo = (u16)a;
    }

    s->f0 = f0;
    s->mid = b;
    s->hi = c;
    s->val = d;
    s->copy = s->lo;

    if (b < c) {
        s->flag = 0;
    } else {
        s->flag = 1;
    }
}





/*
 * Per-frame tick on the slot header at p+0x118. Two halfword bitfields sit
 * there, each `lo:14, hi:2` (the +0x11A one is the field func_02021944
 * sets bits in), followed by a u8 latch at p+0x11C.
 *
 * If the latch is set, the tick is a teardown: clear the latch, clear both
 * lo fields and bit 14 of the +0x11A one, and call out through 0x02030EAC.
 * Otherwise, when the low two bits of the +0x118 field read 1 (the "running"
 * mode), copy that field's 14 bits over the +0x11A field, step all fourteen
 * channels (func_02021B2C for 0..3, func_02021B4C for 4..0xD), and when the
 * +0x118 field has drained to zero, clear bit 14 of +0x11A and call out.
 *
 * EXACT* only: the compiled function is 148 bytes and correct throughout;
 * the listing's 168-byte extent runs on past the literal pool at 0x02021B10
 * into an unlabelled leaf at 0x02021B18 (`movs r0,#0x46; lsls r0,#2;
 * ldrh r2,[r0,r5]; ... strb r2,[r0,r1]; bx lr` -- a no-lr-saving accessor,
 * so disasm.py never labelled it). Worth seeding into
 * layout/function_starts.txt; reported rather than edited here.
 */
void func_02021A84(void *a, struct S02021A84 *p)
{
    if (p->latch == 1) {
        p->latch = 0;
        p->b_lo = 0;
        p->a_big = 0;
        p->b_x = 0;
        func_02030EAC(a);
        return;
    }

    if (p->a_mode != 1) {
        return;
    }

    p->b_lo = p->a_big;
    func_02021B2C((u8 *)p);
    func_02021B4C((u8 *)p);
    if (p->a_big == 0) {
        p->b_x = 0;
        func_02030EAC(a);
    }
}





/*
 * An unlabelled leaf (saves no lr, see docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  Reads the 14-bit field
 * above the low two bits of the halfword at +0x118 and, when it is
 * non-zero, sets the byte at +0x11c to 1.
 *
 * The `lsls #0x10 / lsrs #0x12` pair is the unequal-shift narrowing form
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md):
 * a u16 truncation folded with a >> 2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02021B18.c \
 *       --func sub_02021B18 --addr 0x02021B18 --cc 1.1p1 --thumb
 */
void sub_02021B18(struct Obj02021B18 *o)
{
    if (o->hi)
        o->flag = 1;
}





void func_02021B2C(u8 *p)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        func_02021B6C(p, i, 0x10);
    }
}






void func_02021B4C(u8 *p)
{
    u8 i;

    for (i = 4; i < 0xE; i++) {
        func_02021B6C(p, i, 0x100);
    }
}






void func_02021B6C(u8 *p, u32 idx, u32 arg)
{
    struct S02021B6C_hdr *hdr = (struct S02021B6C_hdr *)(p + 0x118);

    if (func_02021930(hdr->flags118, idx) == 0) {
        return;
    }

    {
        struct S02021B6C *s = (struct S02021B6C *)(p + idx * 0x14);

        if (s->cur < s->cap) {
            s->cur = s->cur + 1;
        } else {
            s->cur = 0;
            func_02021BC8(p, idx, arg);
        }
    }
}






void func_02021BC8(u8 *p, u32 idx, u32 arg)
{
    u32 i;
    struct S02021BC8 *s = (struct S02021BC8 *)(p + idx * 0x14);

    for (i = 0; i < 0x10; i++) {
        if (func_02021930(s->field0xc, (u16)i)) {
            u32 off = (i * arg) * 2;
            func_02021C20((u16 *)(s->p0 + off),
                          (u16 *)(s->p1 + off),
                          (struct C02021C20 *)((u8 *)s + 0xc),
                          arg);
        }
    }

    func_02021CA8(p, (u8)idx, (struct S *)((u8 *)s + 0xc));
}






/*
 * palanm.c: the per-pixel RGB555 blend loop.  Each channel of src[i] moves
 * weight/16 of the way toward the matching channel of the anim sub-object's
 * 15-bit target colour; the result is written to dst[i].
 *
 * Closed in wave 13 by the shape func_0202EA40 (blink_palanm.c) proved the
 * same day: the source pixel and the target are u16 LOCALS (an `int` pixel
 * is 20 bytes out), the channel extractions are written inline in each
 * blend rather than bound to sb/sg/sr locals, and the pack is
 * `r | ((b << 10) | (g << 5))` -- the channel ORed last is the one the
 * compiler evaluates first, which is the image's red, blue, green order.
 * The earlier 69-byte reading (int px, t/w/sb/sg/sr locals) is in
 * docs/notes/func_02021C20.c.txt.
 */
void func_02021C20(u16 *src, u16 *dst, struct C02021C20 *c, u32 count)
{
    u32 i;
    u16 a;
    u16 t;
    s32 r;
    s32 g;
    s32 b;

    for (i = 0; i < count; i++) {
        a = src[i];
        t = c->target;
        r = (u8)((a & 0x1f) + ((((t & 0x1f) - (a & 0x1f)) * c->weight) >> 4));
        b = (u8)(((a >> 10) & 0x1f) + (((((t >> 10) & 0x1f) - ((a >> 10) & 0x1f)) * c->weight) >> 4));
        g = (u8)(((a >> 5) & 0x1f) + (((((t >> 5) & 0x1f) - ((a >> 5) & 0x1f)) * c->weight) >> 4));
        dst[i] = (u16)(r | ((b << 10) | (g << 5)));
    }
}





/*
 * Steps or clears one slider on the record at `s`. The halfword at s+2 is
 * three fields: lo6:6, cur:5, max:5. When cur has already reached max, the
 * function instead toggles bit `idx` of the 14-bit flag field at p[0x118]
 * bits[2:16) (pool word 0xFFFF0003 preserves the low two bits) and returns,
 * doing nothing at all if that bit was already clear. Otherwise the sign bit
 * of the halfword at s+4 picks the direction and s->step (5 bits at s+6) the
 * amount: cur moves up and is clamped down to max, or down and clamped up to
 * max, and is written back through pool word 0xFFFFF83F.
 *
 * Three things the earlier note (docs/notes/func_02021CA8.c.txt) left open,
 * all settled here:
 *   - the write target in blocks 2a/2b really is `cur` (bits[6:11)), which
 *     is what 0xFFFFF83F clears; the note's own "re-check before trusting
 *     this paragraph" was right to doubt the bits[11:16) reading.
 *   - blocks 2a and 2b each carry their own copy of the read-mask-or-store
 *     writeback. Factoring it out after the if/else costs a register and the
 *     `pop {r4,r5}` grows to `pop {r3,r4,r5,r6}`.
 *   - the value sign-extended at the top of each arm is `(s16)s->cur`, the
 *     already-extracted 5-bit field, NOT a fresh s16 read of the raw
 *     halfword at s+2. Both spell `lsls #0x10; asrs #0x10`, but reading the
 *     raw halfword keeps it live in a fifth register across the whole
 *     function and was the last 105 bytes of the diff; using the field
 *     lets the compiler re-derive it and closes the function outright.
 * The p[0x118] flag field is the same bits[2:16) register func_02021B6C
 * uses, as the note suspected.
 */
void func_02021CA8(u8 *p, u32 idx, struct S *s)
{
    u32 bit;
    u32 flags;
    s32 v;

    if (s->cur == s->max) {
        bit = 1 << idx;
        flags = ((u32)((struct Obj08779 *)p)->f118 << 0x10) >> 0x12;
        if (flags & bit) {
            ((struct Obj08779 *)p)->f118 =
                (u16)((((struct Obj08779 *)p)->f118 & 0xFFFF0003)
                      | (((flags ^ (u16)bit) << 0x12) >> 0x10));
        }
        return;
    }

    if (!s->sign) {
        v = (s16)((s16)s->cur + (s32)s->step);
        if (v > (s32)s->max) {
            v = (s16)s->max;
        }
        ((struct Obj06878 *)s)->f2 =
            (u16)((((struct Obj06878 *)s)->f2 & 0xFFFFF83F)
                  | (((u32)(u16)v << 0x1b) >> 0x15));
    } else {
        v = (s16)((s16)s->cur - (s32)s->step);
        if (v < (s32)s->max) {
            v = (s16)s->max;
        }
        ((struct Obj06878 *)s)->f2 =
            (u16)((((struct Obj06878 *)s)->f2 & 0xFFFFF83F)
                  | (((u32)(u16)v << 0x1b) >> 0x15));
    }
}





/*
 * The apply pass of the slot object: walks the 14 channel records and pushes
 * each one's current value out through the graphics-engine setter that the
 * channel index selects (a dense 14-entry halfword switch table at
 * 0x02021DBA). Runs only when the +0x11A field's top bit is set or the
 * +0x118 field's mode is 1.
 *
 * Two types are load-bearing. `i` must be u32 for the switch's own range
 * guard to come out `cmp #0xd; bhi` (signed makes it a `bgt`/`bhi` pair),
 * but the loop's own bound must be compared signed -- `(int)i < 14` -- or
 * the back edge is `bhs` where the original has `bge`. And the bit index
 * handed to func_02021930 is truncated, `(u16)i`, which is the
 * `lsls #0x10 / lsrs #0x10` pair at +0x3E.
 *
 * The final `if` re-reads p->b_lo out of memory rather than reusing the
 * value just stored; testing p->a_big instead loses the reload.
 *
 * EXACT* only: 392 bytes compiled and correct throughout. The listing's
 * 532-byte extent runs past the literal pool at 0x02021ED0 into a run of
 * unlabelled leaf accessors starting at 0x02021EE4 (none saves lr, so
 * disasm.py never labelled them; the first is
 * `movs r1,#0x46; lsls r1,#2; ldrh r0,[r0,r1]; lsls #0x10; lsrs #0xc;
 * bx lr`). Worth seeding into layout/function_starts.txt; reported rather
 * than edited here.
 */
void func_02021D50(struct S02021D50 *p)
{
    struct Chan *c;
    u32 k;
    u32 i;

    if (p->b_hi == 0 && p->a_mode != 1) {
        return;
    }

    k = 0x2000;
    for (i = 0; (int)i < 14; i++) {
        if (p->b_hi == 0) {
            if (p->ch[i].f4 == 0) {
                continue;
            }
            if (func_02021930(p->b_lo, (u16)i) == 0) {
                continue;
            }
        }
        c = &p->ch[i];
        func_020862F0(c->f4, c->f8);
        switch (i) {
        case 0:
            func_0207E3D0(c->f4, 0, c->f8);
            break;
        case 1:
            func_0207E468(c->f4, 0, c->f8);
            break;
        case 2:
            func_0207E51C(c->f4, 0, c->f8);
            break;
        case 3:
            func_0207E5D0(c->f4, 0, c->f8);
            break;
        case 4:
            func_0207F308();
            func_0207F394(c->f4, 0, c->f8);
            func_0207F428();
            break;
        case 5:
            func_0207F308();
            func_0207F394(c->f4, k, c->f8);
            func_0207F428();
            break;
        case 6:
            func_0207F308();
            func_0207F394(c->f4, 0x4000, c->f8);
            func_0207F428();
            break;
        case 7:
            func_0207F308();
            func_0207F394(c->f4, 0x6000, c->f8);
            func_0207F428();
            break;
        case 8:
            func_0207F5B0();
            func_0207F5C8(c->f4, 0, c->f8);
            func_0207F65C();
            break;
        case 9:
            func_0207F5B0();
            func_0207F5C8(c->f4, k, c->f8);
            func_0207F65C();
            break;
        case 10:
            func_0207F5B0();
            func_0207F5C8(c->f4, 0x4000, c->f8);
            func_0207F65C();
            break;
        case 11:
            func_0207F5B0();
            func_0207F5C8(c->f4, 0x6000, c->f8);
            func_0207F65C();
            break;
        case 12:
            func_0207F47C();
            func_0207F4C4(c->f4, 0, c->f8);
            func_0207F560();
            break;
        case 13:
            func_0207F6A8();
            func_0207F6C0(c->f4, 0, c->f8);
            func_0207F754();
            break;
        }
    }

    p->b_lo = p->a_big;
    if (p->b_lo == 0) {
        p->a_mode = 0;
    }
}






u32 func_02021ED8(const char *ptr)
{
    u16 v = ((struct Obj15732 *)ptr)->f118;
    return (u32)(v << 16) >> 18;
}






/*
 * EXACT*: the inferred extent ran to 0x02021F64 because the next function,
 * at 0x02021F08, saves no lr and so carries no label.  0x02021F08 is an
 * unlabelled follower and wants seeding into layout/function_starts.txt.
 *
 * An unlabelled leaf setter (saves no lr).  Writes the top bit of the
 * halfword at +0x11a from the low bit of the argument.  The pool words are
 * plain literals: 0x0000011A (the offset, past the Thumb ldrh immediate
 * reach of +62, see docs/idioms/thumb-immediate-reach-costs-an-adds.md) and
 * 0xFFFF7FFF (the clear mask), neither a relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02021EE4.c \
 *       --func sub_02021EE4 --addr 0x02021EE4 --cc 1.1p1 --thumb
 */
void sub_02021EE4(struct Obj02021EE4 *o, int v)
{
    o->top = (u16)v;
}





/*
 * An unlabelled leaf (push {r3, r4} for alignment only, no lr save), newly
 * seeded as the follower of sub_02021EE4.  Arms the palette-animation
 * header at +0x118: sets the 2-bit mode field from the low bit of the
 * argument and then turns on all fourteen channel bits above it.
 *
 * The header halfword is the same `a_mode:2, a_big:14` pair func_02021A84
 * and func_02021D50 use.  The two pool words are plain literals, not
 * relocations: 0xFFFF0003 is the a_big clear mask and 0x0000FFFC the
 * all-ones a_big value written back, exactly the `<< 2` bitfield insert.
 *
 * EXACT*: 52 bytes compiled (44 of code plus the two pool words at
 * 0x02021F34/0x02021F38), against a 92-byte inferred extent that runs on
 * into the unlabelled `.word` run before func_02021F64.
 *
 * The `(v & 1)` is narrowed to u16 before the field store (`lsls #0x10 /
 * lsrs #0x10` at +0x10), which is what an `int` argument masked into a
 * 2-bit u16 bitfield produces; a u16 parameter loses the pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021F08.c \
 *       --func func_02021F08 --addr 0x02021F08 --cc 1.1p1 --thumb
 */
void func_02021F08(struct Obj02021F08 *o, int v)
{
    o->a_mode = (u16)(v & 1);
    o->a_big = 0x3FFF;
}





/*
 * Witness leaf for ov071 func_021B6C7C (tiny unlabelled arm9 leaf).
 */
u16 func_02021F3C(Slot *s, int idx, int which, u16 pos)
{
    if (which == 1) {
        return s[idx].a[pos];
    }
    if (which == 0) {
        return s[idx].b[pos];
    }
    return 0;
}





/*
 * A per-pixel RGB555 alpha-blend loop, same family as func_02021C20 and
 * func_02021BC8: each channel of src[i] is pulled toward the corresponding
 * channel of `color` by `weight`/16 and the three results repacked into
 * dst[i].  `color` is the fifth argument and arrives on the caller's stack
 * (the entry `add r0,sp,#0x20; ldrh r0,[r0]`).
 *
 * No relocations: the function calls nothing and reads no globals.
 *
 * EXACT*, not EXACT: the next function has no label, so the inferred extent
 * runs two bytes long (116 vs the 114 compiled, the difference being the
 * alignment halfword at 0x02021FD6).
 *
 * Two levers, both recorded in docs/notes/func_02021F64.c.txt:
 *   - the per-pixel channels must be read through a bitfield pointer into
 *     src[i] itself, ((struct Rgb555 *)&src[i])->r, not through a value-copy
 *     union: the copy spills the pixel to a stack slot the image never uses.
 *   - `weight` is a SIGNED int.  As u32 the products (t - s) * weight become
 *     unsigned and the three `>> 4` compile to `lsrs`; the image has `asrs`
 *     at +0x3E, +0x4A and +0x54.  That signedness was the whole residue.
 */
void func_02021F64(u16 *src, u16 *dst, u32 count, int weight,
                   u16 color)
{
    u16 i;
    int tr = ((struct Rgb555 *)&color)->r;
    int tg = ((struct Rgb555 *)&color)->g;
    int tb = ((struct Rgb555 *)&color)->b;

    for (i = 0; i < count; i++) {
        int sr = ((struct Rgb555 *)&src[i])->r;
        int sg = ((struct Rgb555 *)&src[i])->g;
        int sb = ((struct Rgb555 *)&src[i])->b;
        int rb = sb + ((tb - sb) * weight >> 4);
        int rr = sr + ((tr - sr) * weight >> 4);
        int rg = sg + ((tg - sg) * weight >> 4);

        dst[i] = (u16)(rr | (rg << 5) | (rb << 10));
    }
}




/*
 * Thin forwarding wrapper: picks channel `idx` out of the 0x14-byte record
 * array, advances both of its pointers by `c` halfwords, and hands them to
 * the RGB555 blend loop at 0x02021F64 (see docs/notes/func_02021F64.c.txt --
 * that function is still a documented DIFF, so this wrapper's own
 * relocation is attested by the `label` class, not by a matched entry).
 * Arguments 5 and 6 arrive on the caller's stack and must be u8 / u16, which
 * is what makes them `ldrb [r5]` and `ldrh [r5, #4]`.
 *
 * EXACT* only: 42 bytes compiled, the listing extent is 44 -- the two extra
 * bytes are the `00 00` alignment halfword at 0x02022002, not a follower.
 */
void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count,
                   u8 weight, u16 color)
{
    func_02021F64(p[idx].src + c, p[idx].dst + c, count, weight, color);
}




void func_02022004(struct Chan02021FD8 *a0, u32 a1, u16 m, u8 a3, u16 a4)
{
    u32 i = 0;

    if (m == 0) {
        return;
    }
    do {
        if (m & 1) {
            func_02021FD8(a0, a1, (u16)i, 0x10, a3, a4);
        }
        m = (u16)(m >> 1);
        i += 0x10;
    } while (m != 0);
}




void func_02022040(u16 *pal, int n, const u8 *table)
{
    int i;
    int r, g, b;
    u8 v;

    for (i = 0; i < n; i++) {
        r = *pal & 0x1f;
        g = (*pal >> 5) & 0x1f;
        b = (*pal >> 10) & 0x1f;
        v = table[(r * 76 + g * 151 + b * 29) >> 8];
        *pal = (v << 10) | (v << 5) | v;
        pal++;
    }
}




/*
 * The setup entry point of the dual-screen window/text cluster whose object
 * lives at 0x021467A4, the same fixed object func_020226A0 zero-fills in five
 * sub-ranges (0x00/0x14, 0x14/0x30, 0x44/0x30, 0x74/0x18, 0x8C/0xC0) and the
 * one func_0202223C/func_02022268 read the sentinel colour out of at +0x150.
 * It divides its sixth argument by CARD_GetBackupSectorSize(), clears the
 * object, runs two configuration calls, then builds the two screens with the
 * same eleven-argument builder func_02022430: sub-object +0x14 with the
 * second argument and mode 0, sub-object +0x44 with the third argument and
 * mode 1, both sharing the buffers at +0x8C and +0x74 and the object the
 * fifth call returned.  It then publishes the two sub-objects through the
 * slots at +0x04 and +0x08, and for each of the two delegate pointers at
 * +0x0C and +0x10 that is non-null it runs func_02022640 on the matching
 * sub-object and sets the byte flag at +0x14E / +0x14F.
 *
 * Graduated in wave 20B.  It was parked at MATCH only because five of its
 * callees had no branch reference anywhere in the image except the ones in
 * this function, so the `label` class had no witness outside the compared
 * range.  All five are now EXACT manifest entries in pkt_02022174
 * (func_020223C0, func_02022458, func_020225F4, func_02022430,
 * func_02022640), and every one of those sites resolves on the `matched`
 * class.  g_021467A4 resolves on `literal`, CARD_GetBackupSectorSize,
 * _s32_div_f, func_020226A0 and func_02022390 on `label`.
 *
 * Near miss worth keeping: the division had to be written as a self-recompute,
 *   n = (s32)p6;  n = n / (s32)CARD_GetBackupSectorSize();
 * The single-expression form `(s32)p6 / (s32)CARD_GetBackupSectorSize()`
 * compiles the call first and then rematerialises p6 out of its incoming
 * stack slot into r0, two bytes shorter and a whole-function shift; the
 * original loads p6 into a callee-saved register in the prologue shuffle and
 * only then calls.  See
 * docs/idioms/a-self-recompute-pins-an-operand-before-the-other-side-calls.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202208C.c  *       --func func_0202208C --addr 0x0202208C --cc 1.1p1 --thumb
 */
void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7)
{
    s32    n;
    struct G *g;
    void  *obj;

    n = (s32)p6;
    n = n / (s32)CARD_GetBackupSectorSize();
    g = &g_021467A4;
    func_020226A0((u8 *)g);
    func_020223C0((u32)p1, (struct Mode *)g);
    func_02022458((struct Slots *)g->f74);
    obj = (void *)func_020225F4((struct TextObj *)g, p4);
    func_02022430(&g->f14, p2, p5, n, 0, 0, 0,
                  g->f8C, g->f74, p7, obj);
    func_02022430(&g->f44, p3, p5, n, 0, 0, 1,
                  g->f8C, g->f74, p7, obj);
    g->f14C = 1;
    func_02022390((u32 *)(&g->f04), &g->f14);
    func_02022390((u32 *)(&g->f08), &g->f44);
    if (g->f0C != 0) {
        func_02022640((struct Sub *)(&g->f14));
        g->f14E = 1;
    }
    if (g->f10 != 0) {
        func_02022640((struct Sub *)(&g->f44));
        g->f14F = 1;
    }
}




/*
 * Per-frame poll for the dual-screen text cluster at 0x021467A4: while the
 * cluster is live (the u16 at +0x14C non-zero) it steps both sub-objects and,
 * when the stepper reports 1, runs the completion handler on the cluster.
 *
 * The +0x14C read costs its own pool word because 0x14C is far past the
 * ldrh immediate reach; it is g_021467A4 + 0x140 with a +0xC displacement,
 * one symbol and not a second object, see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * The follower at 0x020221A4 is a separate leaf function with fan-in 111 and
 * is deliberately NOT folded into a unit here; it keeps its own entry, see
 * docs/idioms/a-unit-attests-only-its-own-start-address.md.  EXACT* is the
 * inferred extent running into that follower, not a byte difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022174.c \
 *       --func func_02022174 --addr 0x02022174 --cc 1.1p1 --thumb
 */
void func_02022174(void)
{
    struct G *g;

    g = &g_021467A4;
    if (g_021467A4.f14C != 0) {
        if (func_02022340((struct Cluster *)g, &g->f14, &g->f44) == 1)
            func_020222EC(g);
    }
}




/*
 * "Is the dual-screen text cluster idle?", the image's most-called predicate
 * on this object (fan-in 111, mostly from overlay script code): it reports 1
 * when the live counter at +0x14C is zero.  It is a leaf that saves no lr, so
 * disasm.py never labels it and it prints as an anonymous run between two
 * literal pools; see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * It deliberately does not share a file with func_02022174 above it: a unit
 * records only its start address, and this address has 111 call sites that
 * need a manifest entry here.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020221A4.c \
 *       --func func_020221A4 --addr 0x020221A4 --cc 1.1p1 --thumb
 */
u32 func_020221A4(void)
{
    if (g_021467A4.f14C == 0)
        return 1;
    return 0;
}




/*
 * Shutdown of the dual-screen text cluster, the counterpart of func_0202208C.
 * It drops both entries of the callback block at +0x74, forces each live screen
 * into state 2, unpublishes both sub-objects through the same func_02022390
 * slot writer the setup used, clears the live counter and the two delegate
 * flags at +0x14C/+0x14E/+0x14F, and releases the object.
 *
 * Every pool word here is g_021467A4 with a different displacement (+0x74,
 * +0x00, +0x04, +0x14, +0x08, +0x44, +0x140), one symbol and not seven
 * objects; see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020221B8.c \
 *       --func func_020221B8 --addr 0x020221B8 --cc 1.1p1 --thumb
 */
void func_020221B8(void)
{
    func_020224DC((struct Slots *)g_021467A4.f74, 0);
    func_020224DC((struct Slots *)g_021467A4.f74, 1);
    if (g_021467A4.f04 != 0)
        g_021467A4.f14.f0C = 2;
    if (g_021467A4.f08 != 0)
        g_021467A4.f44.f0C = 2;
    func_02022390((u32 *)(&g_021467A4.f04), &g_021467A4.f14);
    func_02022390((u32 *)(&g_021467A4.f08), &g_021467A4.f44);
    g_021467A4.f14C = 0;
    g_021467A4.f14E = 0;
    g_021467A4.f14F = 0;
    func_020226A0((u8 *)(&g_021467A4));
}




/*
 * A two-instruction forwarder (fan-in 22) that pins the first argument of
 * func_02023B48 to zero and passes the caller's window pointer through as the
 * second.  Tail calls in this compiler are always a pool word and a `bx`,
 * never a displacement branch, because every function gets its own section;
 * see docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * EXACT* is the extent walk running into the second forwarder at 0x02022230,
 * which is an unlabelled leaf with its own callers and keeps its own file.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022224.c \
 *       --func func_02022224 --addr 0x02022224 --cc 1.1p1 --thumb
 */
u32 func_02022224(void *win)
{
    return func_02023B48(0, win);
}




/*
 * The companion forwarder to func_02022224: it passes the caller's engine
 * selector straight through to func_020222CC and supplies the unused second
 * argument as zero.  Same pool-word-and-`bx` tail call shape.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022230.c \
 *       --func func_02022230 --addr 0x02022230 --cc 1.1p1 --thumb
 */
void func_02022230(u32 which)
{
    func_020222CC(which, 0);
}




/*
 * Maps two sentinel colour values (0xFFFF, "read back the last value
 * written"; 0x7FFF, "white") to two hardware-register-friendly constants
 * and forwards to func_020222CC, which selects one of two hardware
 * addresses from its first argument and ignores the colour entirely
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-
 * leftovers.md; func_020222CC's own file spells this out).
 *
 * The sentinel readback is `g_021468E4.f10`, a halfword sixteen bytes into
 * a fixed object.  Writing it as `*(u16 *)(0x021468E4 + 0x10)` folds the
 * base and the offset into a single pool word (a plain integer constant
 * has no reason not to), which does not reproduce the original's separate
 * `ldr r1, [pc]; ldrh r1, [r1, #0x10]`.  Declaring the object as an extern
 * struct and taking a real relocation on its base keeps the offset in the
 * instruction encoding instead, matching
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-
 * the-load-reach.md.  The base address is attested by ten other literal
 * pools in the image.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202223C.c \
 *       --func func_0202223C --addr 0x0202223C --cc 1.1p1 --thumb
 */
void func_0202223C(u32 a, u32 color)
{
    if (color == 0xFFFF) {
        color = g_021468E4.f10;
    }
    if (color == 0x7FFF) {
        color = 0x10;
    } else {
        color = ~(u32)0xF;
    }
    func_020222CC(a, color);
}




/*
 * Same sentinel-mapping shape as func_0202223C.c, but read-modify-write:
 * it substitutes the sentinel readback the same way, maps the result to
 * one of the same two hardware constants, forwards it to both of
 * func_020222CC's hardware selections (0 and 1), and then stores the
 * *pre-mapping* colour back into the same halfword field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022268.c \
 *       --func func_02022268 --addr 0x02022268 --cc 1.1p1 --thumb
 */
void func_02022268(u32 color)
{
    u32 mapped;

    if (color == 0xFFFF) {
        color = g_021468E4.f10;
    }
    if (color == 0x7FFF) {
        mapped = 0x10;
    } else {
        mapped = ~(u32)0xF;
    }
    func_020222CC(0, mapped);
    func_020222CC(1, mapped);
    g_021468E4.f10 = color;
}




void func_020222A8(u32 a)
{
    u32 *p = &a;

    func_0207E3D0(p, 0, 2);
    func_0207E468(p, 0, 2);
}




/*
 * Selects one of two hardware register addresses (0x0400006C, 0x0400106C:
 * the master brightness registers of the two DS display engines) from its
 * first argument and passes it to func_0207D534 together with the second
 * argument, the brightness level, which stays in r1 untouched (an argument
 * passed through a register must be named in the C).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020222CC.c \
 *       --func func_020222CC --addr 0x020222CC --cc 1.1p1 --thumb
 */
void func_020222CC(u32 which, int brightness)
{
    if (which == 0) {
        func_0207D534((volatile u16 *)0x0400006C, brightness);
    } else {
        func_0207D534((volatile u16 *)0x0400106C, brightness);
    }
}
