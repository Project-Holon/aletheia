/*
 * file:     wipe_sub_p09.c
 * unit:     yes
 * function: func_02024464, func_02024498, func_020244D4, func_020244F0, func_020244F8, func_02024508, func_02024520, func_0202452C, func_02024530, func_02024534, func_02024570, func_02024584, func_02024598, func_020245A0, func_020245AC, func_020245D4, func_0202465C, func_020246C8, func_0202473C, func_02024768, func_020247A8, func_020247F0, func_02024810, func_02024838, func_02024888, func_020248D8, func_02024910, func_02024918, func_02024934, func_02024938, func_02024988, func_02024994, func_020249A0, func_020249B0, func_02024A20, func_02024ABC, func_02024DCC, func_02024DFC, func_02025154, func_020251D8, func_020251FC, func_020252A8
 * address:  0x02024464
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
 *   g_0209F724  0x0209F724  data
 *   g_0209F71C  0x0209F71C  data
 *   data_0209F734  0x0209F734  data
 *   func_02030734  0x02030734  arm
 *   func_02045B38  0x02045B38  arm
 *   str_020A746C   0x020A746C  data  a1
 *   tbl_0209F7AC   0x0209F7AC  data  a2
 *   Table_0209F7AC   0x0209F7AC  data
 *   func_0204581C    0x0204581C  arm
 *   func_02045C04    0x02045C04  arm
 *   func_02045CAC    0x02045CAC  arm
 *   g_tbl0   0x0209F7AC  data
 *   g_tbl1   0x0209F792  data
 *   g_0209F792  0x0209F792  data
 *   MI_CpuCopy8  0x02082D44  arm
 *   tbl_0209F784   0x0209F784  data  a1
 *   data_0209F7C8  0x0209F7C8  data
 *   MI_CpuFill8         0x02082BCC  arm
 *   func_020056A0       0x020056A0  thumb
 *   func_0203568C       0x0203568C  arm
 *   func_0201283C       0x0201283C  thumb
 *   func_02012BB0       0x02012BB0  thumb
 *   gInfoWin            0x0214693C  data
 *   infowin_File        0x020A7478  data
 *   func_0203CD98       0x0203CD98  arm
 *   func_0203D798       0x0203D798  arm
 *   func_0203D1B4       0x0203D1B4  arm
 *   func_0203D29C       0x0203D29C  arm
 *   func_0201058C       0x0201058C  thumb
 *   func_02026CA0       0x02026CA0  thumb
 *   d_0209F830          0x0209F830  data a4
 *   d_0209F834          0x0209F834  data a2
 *   d_0209F838          0x0209F838  data a4
 *   d_0209F840          0x0209F840  data a4
 *   d_0209F848          0x0209F848  data a4
 *   d_0209F852          0x0209F852  data a2
 *   d_0209F868          0x0209F868  data a4
 *   d_0209F870          0x0209F870  data a2
 *   func_020410D0       0x020410D0  arm
 *   func_020409B4       0x020409B4  arm
 *   func_02035630       0x02035630  arm
 *   OS_IsRunOnTwl       0x02085D3C  arm
 *   _s32_div_f          0x0209C0A4  arm
 *   func_020490F4       0x020490F4  arm
 *   func_0203FA08       0x0203FA08  arm
 *   func_02049B68       0x02049B68  arm
 *   func_02049658       0x02049658  arm
 *   ENV_SetResourceSet  0x02049238  arm
 *   func_02041300       0x02041300  arm
 *   func_0203F4CC       0x0203F4CC  arm
 */
#include "../../matched/include/Obj05795.h"

struct MsgBank;
struct Rec;
struct U16Vec;
struct Sub020071CCCtrl;
struct BigObj;
struct RtcTime;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;


typedef signed char    s8;
typedef signed int     s32;

struct Container {
    u8 pad[4];
    u16 arr[];
};


struct Data {
    u16 a;
    u16 b;
    u16 c[2];
};

struct Rec8 {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
};

struct Rec4 {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
};

struct Tbl {
    u16 f[12];
};

struct PmsWordSys {
    u32   heapId;
    void *msg[13];
};


struct Item {
    u8 bytes[8];
};

struct Obj02024838 {
    u8          pad[8];
    struct Item items[20];
};

struct PmsWordEntry {
    u32 f00;
    u16 word[2];
};

struct PmsWord {
    u32 flags;
    u32 f04;
    struct PmsWordEntry e[20];
};

typedef struct Group {
    const u16 *list;
    int count;
} Group;

struct InfoWin {
    u32 f00;
    u16 f04;
    u8  f06;
    u8  f07;
    u8  f08;
    u8  f09;
    u8  pad0A[2];
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u8  f1C;
    u8  f1D;
    u8  f1E;
    u8  f1F;
    u32 f20;
    void *f24;
};

struct Link {
    u8 pad00[0x65];
    u8 f65;
    u8 f66;
    u8 f67;
};

struct Cfg {
    u32 a;
    u32 b;
    u32 c;
};

struct Sel6 { u8 v[6]; };

struct Ofs6 { u16 v[6]; };

struct W {
    u16 scr[4];     /* +0x00 */
    struct Sel6 sel; /* +0x08 */
    u16 col[2];     /* +0x0E */
    struct Ofs6 ofs; /* +0x12 */
    u16 clk[10];    /* +0x1E */
};

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u16 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D478(void *s);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02030734(u32 heap, u32 size, int flag, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0204581C(struct U16Vec *vec);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, unsigned int id);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void *func_020056A0(void (*cb)(void *), void *work, u32 pri);
extern int func_0203568C(void);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02012BB0(const struct BigObj *p);
extern int   func_0203CD98(void);
extern void *func_0203D798(void);
extern int   func_0203D1B4(void);
extern u32 func_0203D29C(void);
extern u32 func_0201058C(void *key);
extern int   func_02026CA0(int *p);
extern int  func_02030EAC(void *a);
extern int  func_0203FB44(u32 a, u32 b, u32 c);
extern int  func_02040E78(u32 a, const void *b, u16 c, u16 d);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32   func_0203FA08(u32 a, u32 b, u32 c);
extern void  func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void  func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void  ENV_SetResourceSet(void *a);
extern void  func_02041300(u32 a, u16 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_0203F4CC(struct RtcTime *time);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020409B4(u32 a0);
extern u8 func_02035630(void);
extern int  OS_IsRunOnTwl(void);
int func_02024464(struct Rec4 *p, u16 a1);
u32 func_02024498(u32 a0, u32 a1, u16 a2);
u16 func_020244D4(void *obj, u32 idx);
u16 func_020244F0(void *obj, u32 idx);
u32 func_020244F8(struct Container *p, u32 idx);
u32 sub_02024508(u32 x);
u32 sub_02024520(u32 x);
int func_0202452C(const u16 *p);
unsigned int func_02024530(const u16 *p);
int func_02024534(const struct Data *p1, const struct Data *p2);
void sub_02024570(struct Rec8 *dst, const struct Rec8 *src);
u8 func_02024584(u32 i);
void func_02024598(void *p0, int p1, int p2);
void func_020245A0(u8 *p,unsigned i,u16 v);
void func_020245AC(struct Rec4 *p, u16 a1);
u32 func_020245D4(struct Rec4 *p, u32 a1);
u32 func_0202465C(struct Rec4 *p, u32 a1, u32 a2);
u32 func_020246C8(u16 *p, u32 mode, u32 flag);
u32 func_0202473C(u32 *p, u32 a);
s32 func_02024768(u32 v);
struct PmsWordSys *func_020247A8(u32 heapId);
void func_020247F0(char *p);
void func_02024810(char *p, int a1, int a2);
void func_02024838(u32 id, void *dest, u16 heap);
u16 func_02024888(u32 idx, u16 add);
int func_020248D8(u32 v, u32 *a1, u32 *a2);
void *func_02024910(char *p, int idx);
void func_02024918(struct Obj02024838 *p, s32 idx, const void *src);
u32 func_02024934(void);
void func_02024938(struct PmsWord *p);
void *func_02024988(int a0);
int func_02024994(const u32 *p, u32 idx);
void func_020249A0(int *p, int bit);
int func_020249B0(u32 a, u16 b);
void func_02024A20(u8 a0, u8 a1, void *a2, u16 heap);
void func_02024ABC(void);
int func_02024DCC(void);
void func_02024DFC(void);
void func_02025154(u32 base, u32 blk, u8 x, u8 y, u8 w, u8 h);
int func_020251D8(int a0, const void *a1, int a2);
void func_020251FC(u32 a, u32 b, u32 c);
void func_020252A8(void);
extern u16 g_0209F724[];
extern u8 g_0209F71C[];
extern const struct Tbl data_0209F734;
extern const char str_020A746C[];
extern const u16  tbl_0209F7AC[];
extern u16 Table_0209F7AC[];
extern u16 g_tbl0[];
extern u16 g_tbl1[];
extern u16 g_0209F792[];
extern const u8 tbl_0209F784[][2];
extern const Group data_0209F7C8[13];
extern struct InfoWin *gInfoWin;
extern const char infowin_File[];
extern const u16 d_0209F834[];
extern const u32 d_0209F840[];
extern const u16 d_0209F848[];
extern const u16 d_0209F852[][2];
extern const u32 d_0209F838[];
extern const struct Ofs6 d_0209F870;
extern const struct Sel6 d_0209F868;
extern const u16 d_0209F830[];





int func_02024464(struct Rec4 *p, u16 a1)
{
    u32 n = func_02024498(p->f00, p->f02, a1);
    u32 i;

    for (i = 0; i < n; i++) {
        if (*(u16 *)((char *)p + i * 2 + 4) == 0xffff) {
            return 0;
        }
    }
    return 1;
}




u32 func_02024498(u32 a0, u32 a1, u16 a2)
{
    struct MsgBank *arc = func_02045B38(0, 2, g_0209F724[a0], a2);
    void *str = func_02045EC0(arc, a1);
    u32 z;

    func_02045C04((struct Rec *)arc);
    z = func_0201D478(str);
    func_02045808((struct U16Vec *)str);

    return z;
}




u16 func_020244D4(void *obj, u32 idx)
{
    u16 val = ((u16 *)((char *)obj + 4))[idx];

    if (val == 0xffff) {
        return 0xffff;
    }
    return (u16)(val & (0xffff >> 5));
}



u16 func_020244F0(void *obj, u32 idx)
{
    return ((u16 *)((char *)obj + 4))[idx];
}





u32 func_020244F8(struct Container *p, u32 idx)
{
    return sub_02024508(p->arr[idx]);
}





/*
 * A sentinel-guarded bit test: 0xFFFF is treated as "unset" and reads as
 * bit 0, everything else reads back bit 11.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02024508.c \
 *       --func sub_02024508 --addr 0x02024508 --cc 1.1p1 --thumb
 */
u32 sub_02024508(u32 x)
{
    if (x == 0xFFFF) {
        return 0;
    }
    return ((s32)x >> 11) & 1;
}






/*
 * A plain bitmask, `& 0x7FF`. Immediately followed by two unlabelled
 * one-argument halfword accessors (`ldrh r0,[r0]`/`bx lr` and
 * `ldrh r0,[r0,#2]`/`bx lr`) that carry no push prologue and so are
 * invisible to disasm.py's sweep; not reproduced here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02024520.c \
 *       --func sub_02024520 --addr 0x02024520 --cc 1.1p1 --thumb
 */
u32 sub_02024520(u32 x)
{
    return x & 0x7FF;
}






/*
 * Unlabelled Thumb leaf in the ARM9 module: returns the first halfword.
 *
 * Addresses are Black-image addresses.
 */
int func_0202452C(const u16 *p)
{
    return *p;
}





/*
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 */
unsigned int func_02024530(const u16 *p) { return p[1]; }






int func_02024534(const struct Data *p1, const struct Data *p2)
{
    int i;

    if (p1->a != p2->a || p1->b != p2->b) {
        return 0;
    }

    for (i = 0; i < 2; i++) {
        if (p1->c[i] != p2->c[i]) {
            return 0;
        }
    }

    return 1;
}





/*
 * A plain 4-halfword struct copy.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02024570.c \
 *       --func sub_02024570 --addr 0x02024570 --cc 1.1p1 --thumb
 */
void sub_02024570(struct Rec8 *dst, const struct Rec8 *src)
{
    *dst = *src;
}





u8 func_02024584(u32 i)
{
    if (i < 7) {
        return g_0209F71C[i];
    }
    return 0;
}





void func_02024598(void *p0, int p1, int p2){ ((struct Obj05795 *)p0)->f0 = (unsigned short)p1; ((struct Obj05795 *)p0)->f2 = (unsigned short)p2; }




void func_020245A0(u8 *p,unsigned i,u16 v) {
    if(i<2) *(u16 *)(p+4+2*i)=v;
}





void func_020245AC(struct Rec4 *p, u16 a1)
{
    u32 n = func_02024498(p->f00, p->f02, a1);

    if (n < 2) {
        do {
            *(u16 *)((char *)p + n * 2 + 4) = 0xffff;
            n++;
        } while (n < 2);
    }
}





/*
 * pmsi_param.c's word-array validator: guards the (category, page) pair
 * against the per-category count, asks func_02024498 how many words the
 * page carries, and runs each word through the same two-arm check
 * func_020246C8 performs on a single word.
 *
 * THE LEVER that closed this (it was DIFF, 132 bytes against 136, for the
 * whole of the previous wave -- see docs/notes/func_020245D4.diff.c.txt):
 * BOTH arms of the two-arm check write the `ok = 0; goto ret;` tail out,
 * and the label `setfail` sits INSIDE THE FIRST ARM'S COPY.  That is the
 * mixed case of docs/idioms/two-arms-write-the-tail-out-and-the-third-
 * branches-back-into-one.md.  The original spends a conditional AND an
 * unconditional branch at +0x64/+0x66 (`bne <loop increment>; b <setfail>`)
 * exactly because the two arms did not cross-jump; every shape that shares
 * one copy behind a single label folds them into one inverted `beq`, loses
 * four bytes and shifts every later branch target.
 *
 * Equally load-bearing: the `!= 0` arm is written FIRST
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  With the
 * `== 0` arm first the two call sites swap and 17 bytes differ.
 *
 * `sel` must be a named local: the guard reads p->f02 once and the same
 * value is handed to func_02024498, which is what keeps r5 live across the
 * func_02024584 call.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020245D4.c \
 *       --func func_020245D4 --addr 0x020245D4 --thumb --cc 1.1p1
 */
u32 func_020245D4(struct Rec4 *p, u32 a1)
{
    u32 ok;
    u32 n;
    u32 i;
    u32 y, x;
    u32 sel;

    if (p->f00 >= 7) {
        goto fail;
    }
    sel = p->f02;
    if (sel >= func_02024584(p->f00)) {
        goto fail;
    }

    n = func_02024498(p->f00, sel, (u16)((a1 & 0x7FFF) | 0x8000));
    ok = 1;
    for (i = 0; i < n; i++) {
        struct Rec4 *q = (struct Rec4 *)((u16 *)p + i);

        if (sub_02024508(q->f04) != 0) {
            s32 v = sub_02024520(q->f04);

            if (v >= 1 && v < 11) {
                continue;
            }
setfail:
            ok = 0;
            goto ret;
        } else {
            if (func_020248D8(q->f04, &x, &y) != 0) {
                continue;
            }
            ok = 0;
            goto ret;
        }
    }
ret:
    return ok;
fail:
    return 0;
}





u32 func_0202465C(struct Rec4 *p, u32 a1, u32 a2)
{
    u32 ok = 1;
    u32 n;
    u32 i;

    if (p->f00 >= 7 || p->f02 >= (u32)func_02024584(p->f00)) {
        ok = 0;
        p->f00 = 0;
        p->f02 = 0;
    }

    n = func_02024498(p->f00, p->f02, (u16)((a2 & 0x7FFF) | 0x8000));
    if (n > 2) {
        n = 2;
    }
    for (i = 0; i < n; i++) {
        if (func_020246C8(&p->f04 + i, a1, 1) == 0) {
            ok = 0;
        }
    }
    return ok;
}





/*
 * pmsi_param.c's single-word validator (see docs/families/pmsi_param.h and
 * func_020245D4, which runs the same two-arm check over a word array).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 116/116, 1 byte out at +0x3E
 * for three waves, docs/notes/func_020246C8.diff.c.txt): the flag arm writes
 * the fail tail `ok = 0; *p = 0x6A1; goto done;` out after the range test,
 * like the flag == 0 arm does. The image's `blt` lands on an unconditional
 * `b bad` instead of on `bad` itself: a branch that jump threading did not
 * follow is a branch into a cross-jumped copy of a written-out tail, because
 * cross-jumping runs after threading. Falling into the shared `bad:` label
 * lets 1.1p1 thread the hop away.
 */
u32 func_020246C8(u16 *p, u32 mode, u32 flag)
{
    u32 ok = 1;
    u32 y, x;

    if (mode != 0) {
        if (*p == 0xFFFF) {
            return ok;
        }
    } else {
        if (*p == 0xFFFF) {
            *p = 0x6A1;
            return 0;
        }
    }

    if (sub_02024508(*p) != 0) {
        s32 v;

        if (flag != 0) {
            v = sub_02024520(*p);
            if (v >= 1 && v < 11) {
                goto done;
            }
            ok = 0;
            *p = 0x6A1;
            goto done;
        } else {
            ok = 0;
            *p = 0x6A1;
            goto done;
        }
    } else {
        if (func_02024768(*p) == 0) {
            if (func_020248D8(*p, &x, &y) != 0) {
                goto done;
            }
        }
    }
bad:
    ok = 0;
    *p = 0x6A1;
done:
    return ok;
}






/*
 * Clamp a counter to the range 1..10, with a mode argument that changes
 * only the zero case: called with `a == 0` and a zero field, the field is
 * reset to 1 and 0 is returned; called with `a != 0` a zero field is left
 * alone and 1 is returned outright, skipping the range check entirely.
 * Every other value goes through the same range test regardless of `a`.
 *
 * The `result` local has to be initialised before either branch reads
 * `*p` (docs/idioms/initialise-the-result-before-the-input-or-every-arm-
 * duplicates-the-return.md): that ordering, not the declaration order, is
 * what keeps the constant 1 resident in one register across both early
 * returns and the range check's shared exit, instead of each arm
 * rematerialising its own `movs r0, #k; bx lr`. The two early returns
 * (the `a != 0` zero case and the `a == 0` zero case) are written as
 * direct `return` statements and stay as separate tails; only the range
 * check's in-range case and the clamp's fallthrough share one exit block,
 * reached by a `goto` from the first and by falling into it from the
 * second, exactly as the original's single `blt` past the clamp and the
 * clamp's own fallthrough both land on one `adds r0, r2, #0; bx lr`.
 *
 * This is wordset.c's normaliser: src/pending/sub_0201EFFC.c calls it and
 * is promoted alongside this file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202473C.c \
 *       --func func_0202473C --addr 0x0202473C --cc 1.1p1 --thumb
 */
u32 func_0202473C(u32 *p, u32 a)
{
    u32 result = 1;
    s32 v;

    if (a != 0) {
        v = (s32)*p;
        if (v != 0) {
            goto range;
        }
        return result;
    }
    v = (s32)*p;
    if (v != 0) {
        goto range;
    }
    *p = result;
    return 0;

range:
    if (v < 1) {
        goto clamp;
    }
    if (v < 0xb) {
        goto end;
    }

clamp:
    *p = 1;
    result = 0;

end:
    return result;
}






/*
 * Blocked: data_0209F734 (a 12-halfword table) is named by exactly one pool word,
 * 0x020247A4, and that word is inside this function's own range once the
 * body compiles to its full 64 bytes; the `literal` class discards it. Every
 * concrete byte reproduces.
 */
s32 func_02024768(u32 v)
{
    struct Tbl b;
    u8 i;

    b = data_0209F734;
    for (i = 0; i < 12; i++) {
        if (v == b.f[i]) {
            return 1;
        }
    }
    return 0;
}






/*
 * pms_word.c: allocate the 0x38-byte word-message system and open its
 * thirteen message archives (ids from the u16 table at 0x0209F7AC).  The
 * heap id store sits inside the loop in the image, so it is inside the
 * loop here.  The r4/r5 swap of docs/notes/pkt_02024768.c.txt was the
 * declaration order: the counter is declared before the result pointer
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md),
 * found by tools/permuter.py and reduced to that one change.
 */
struct PmsWordSys *func_020247A8(u32 heapId)
{
    int i;
    struct PmsWordSys *p;

    p = func_02030734((u16)heapId, 0x38, 0, str_020A746C, 0x32);
    for (i = 0; i < 13; i++) {
        p->heapId = heapId;
        p->msg[i] = func_02045B38(0, 2, tbl_0209F7AC[i], heapId);
    }
    return p;
}






void func_020247F0(char *p)
{
    int i;
    for (i = 0; i < 0xd; i++)
        func_02045C04((struct Rec *)(*(int *)(p + 4 + i * 4)));
    func_020307B0(p);
}






void func_02024810(char *p, int a1, int a2)
{
    int x, y;
    func_020248D8(a1, (unsigned int *)(&x), (unsigned int *)(&y));
    func_02045CAC((struct MsgBank *)(*(int *)(p + 4 + x * 4)), y, (void *)a2);
}







/*
 * Loads one archived message/graphics entry into the caller's buffer.
 * The flat id is split by func_020248D8 into a bank index and an
 * entry index; the bank index selects an archive id out of the
 * halfword table at 0x0209F7AC, that archive is opened, the entry is
 * read into dest and the archive closed again.  The sentinel id
 * 0xffff means "nothing to load" and only clears dest.
 */
void func_02024838(u32 id, void *dest, u16 heap)
{
    u32 bank;
    u32 entry;

    if (id != 0xffff) {
        void *arc;

        func_020248D8(id, &bank, &entry);
        bank = Table_0209F7AC[bank];
        arc = func_02045B38(0, 2, bank, heap);
        func_02045CAC(arc, entry, dest);
        func_02045C04(arc);
    } else {
        func_0204581C(dest);
    }
}







u16 func_02024888(u32 idx, u16 add)
{
    u32 i;
    u16 sum;
    u16 k;

    for (i = 0; i < 0xD; i++) {
        if (idx == g_tbl0[i]) {
            k = 0;
            sum = 0;
            for (; k < i; k++) {
                sum = (u16)(sum + g_tbl1[k]);
            }
            return (u16)(sum + add);
        }
    }
    return 0xFFFF;
}








int func_020248D8(u32 v, u32 *a1, u32 *a2)
{
    u32 i;
    u32 sum;

    v &= 0x7ff;
    sum = 0;
    for (i = 0; i < 0xd; i++) {
        u16 n = g_0209F792[i];

        sum += n;
        if (v < sum) {
            *a1 = i;
            *a2 = v - (sum - n);
            return 1;
        }
    }
    return 0;
}






/*
 * Unlabelled Thumb leaf: address of the 8-byte entry idx of the table at p + 8.
 */
void *func_02024910(char *p, int idx)
{
    return p + 8 + idx * 8;
}







void func_02024918(struct Obj02024838 *p, s32 idx, const void *src)
{
    if (idx < 0 || idx >= 20) {
        return;
    }

    MI_CpuCopy8(src, &p->items[idx], 8);
}





/*
 * Save-table size callback: returns 0xA8, the size of the block whose
 * init is func_02024938.  Pointer word 0x02024935 at 0x0209DC00.
 */
u32 func_02024934(void)
{
    return 0xA8;
}





/*
 * pms_word.c: clear the flag words, seed all forty word slots to 0xFFFF,
 * then set the flag bit named by the first row of the 7 x 2 byte table at
 * 0x0209F784 whose kind is 2.  The table is a 2D array: `tbl[k][1]` is what
 * gives the image's second pool word 0x0209F785 (symbol + 1, indexed by
 * the same 2k), where a struct {kind, val} folds the +1 into the load
 * (docs/notes/pkt_02024938.c.txt).  k is unsigned (`blo`); the first two
 * loops count in int.
 */
void func_02024938(struct PmsWord *p)
{
    int i, j;
    u32 k;

    p->flags = 0;
    p->f04 = 0;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 2; j++)
            p->e[i].word[j] = 0xffff;
    }
    for (k = 0; k < 7; k++) {
        if (tbl_0209F784[k][0] == 2) {
            func_020249A0((int *)p, tbl_0209F784[k][1]);
            return;
        }
    }
}





void *func_02024988(int a0)
{
    return func_020071CC((struct Sub020071CCCtrl *)a0, 0x27);
}





int func_02024994(const u32 *p, u32 idx){return (*p >> idx) & 1;}





void func_020249A0(int *p, int bit)
{
    *p |= 1 << bit;
}






/*
 * Unlabelled arm9 leaf: true when a == b, or when the first of 13 halfword
 * groups that contains a also contains b. Filed as the relocation witness for
 * ov021 func_021D213C (wave A1).
 */
int func_020249B0(u32 a, u16 b)
{
    u32 i;
    int j, k;

    if (a == b) {
        return 1;
    }
    for (i = 0; i < 13; i++) {
        for (j = 0; j < data_0209F7C8[i].count; j++) {
            if (a == data_0209F7C8[i].list[j]) {
                for (k = 0; k < data_0209F7C8[i].count; k++) {
                    if (b == data_0209F7C8[i].list[k]) {
                        return 1;
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}






/*
 * note:     infowin constructor.  The heap id is u16: as u32 mwcc reuses r3
 *           for the allocator call instead of reloading the spilled home
 *           (17 bytes).  Found by tools/permuter.py --types.
 */
void func_02024A20(u8 a0, u8 a1, void *a2, u16 heap)
{
    gInfoWin = func_02030734(heap, 0x28, 0, infowin_File, 0x103);
    MI_CpuFill8(gInfoWin, 0, 0x28);
    gInfoWin->f06 = a0;
    gInfoWin->f07 = a1;
    func_020251FC(a0, a1, heap);
    gInfoWin->f24 = func_020056A0((void (*)(void *))func_02024DFC, gInfoWin, 1);
    gInfoWin->f20 = 0;
    gInfoWin->f1F = func_0203568C();
    if (a2 != 0) {
        gInfoWin->f0C = func_0201283C(a2);
        gInfoWin->f10 = func_02012BB0(a2);
    } else {
        gInfoWin->f0C = 0;
        gInfoWin->f10 = 0;
    }
    gInfoWin->f08 = 0;
    func_02024ABC();
    gInfoWin->f04 = 0x3f;
}






/*
 * note:     infowin per-frame state poll (the TCB-less update): clock tick,
 *           link/wireless state, then the dirty bits of +0x04.  Two shape
 *           facts carry the whole match: every flag update is spelled out
 *           (`f = (u16)(f | X)`, which reuses the tested load; `|=` re-reads
 *           it), and every clear mask is the u16 constant (the pool holds
 *           0x0000EFFF, not ~0x1000).
 */
void func_02024ABC(void)
{
    int flag = 0;
    u8 n = 0;
    struct Link *link = 0;
    u32 bits;
    int idx;

    if (gInfoWin == 0)
        return;

    func_020252A8();
    gInfoWin->f1E++;
    if (gInfoWin->f1E > 60) {
        u8 v = func_0203568C();
        if (gInfoWin->f1F != v) {
            gInfoWin->f1F = v;
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x20);
        }
        gInfoWin->f1E = 0;
    }

    if (func_0203CD98() == 1) {
        link = func_0203D798();
        n = func_0203D1B4();
        if (func_0203D29C() == 1)
            flag = 1;
    }

    if (n < 2 && flag == 0) {
        bits = func_0201058C((void *)gInfoWin->f0C);
        idx = 0;
        if (gInfoWin->f10 == 1 && func_02026CA0(&idx) != 0x1E) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x1000);
        } else {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xEFFF);
        }
        if (!(bits & 2)) {
            if (((gInfoWin->f04 & 0x200) ? 1 : 0) == 1) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 4);
                gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFDFF);
            }
        }
        if (bits & 0x3C) {
            if (bits & 0xC) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x800);
            } else if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 0) {
                gInfoWin->f08 = 0;
                gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
            }
        } else if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 1) {
            gInfoWin->f08 = 0;
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFBFF);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
        }
        if (bits & 0x3C0) {
            if (gInfoWin->f20 == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
                gInfoWin->f20 = 1;
            }
        } else if (gInfoWin->f20 != 0) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
            gInfoWin->f20 = 0;
        }
    } else if (link != 0) {
        if (link->f65 == 3) {
            if (((gInfoWin->f04 & 0x200) ? 1 : 0) == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 4);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x200);
            }
        } else if (((gInfoWin->f04 & 0x200) ? 1 : 0) == 1) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 4);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFDFF);
        }
        if (link->f65 == 0 || link->f65 == 4 || link->f65 == 5) {
            if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
                gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
                gInfoWin->f08 = 0;
            }
            if (link->f67 == 2) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x800);
            }
        } else if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 1) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFBFF);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
            gInfoWin->f08 = 0;
        }
        if (link->f65 == 1 || link->f65 == 2 || link->f65 == 6) {
            if (gInfoWin->f20 == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
                gInfoWin->f20 = 1;
            }
        } else if (gInfoWin->f20 != 0) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
            gInfoWin->f20 = 0;
        }
    }
}




int func_02024DCC(void)
{
    if (gInfoWin != 0) {
        func_02030EAC(gInfoWin->f24);
        func_0203FB44(gInfoWin->f06, gInfoWin->f00, 1 << 12);
        func_020307B0(gInfoWin);
        gInfoWin = 0;
        return 0;
    } else {
        return (int)gInfoWin;
    }
}





/*
 * note:     infowin redraw task (the TCB callback func_02024A20 registers):
 *           clock digits, battery/link/wireless icons, per dirty bit of
 *           +0x04.  Levers, in the order they closed it: tens use `/ 10`
 *           and ones `% 10` (the remainder comes back in r1); every access
 *           goes through the global (reloaded at each join); the two
 *           six-entry tables are struct copies (local initialised arrays);
 *           `k = (c) ? a : b` for all three tile selectors; the draw call
 *           in each arm of block 0x10; `done = 1` after the block-0 draw.
 */
void func_02024DFC(void)
{
    struct W buf;
    int done;
    int k;

    done = 0;
    if (gInfoWin == 0)
        return;

    if (gInfoWin->f04 & 1) {
        if (gInfoWin->f1D < 10) {
            buf.clk[0] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + 0xF);
            buf.clk[5] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + 0x1F);
        } else {
            buf.clk[0] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + (gInfoWin->f1D / 10 + 1));
            buf.clk[5] = buf.clk[0] + 0x10;
        }
        buf.clk[1] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + (gInfoWin->f1D % 10 + 1));
        k = (gInfoWin->f14 != 0) ? 11 : 15;
        buf.clk[2] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + k);
        buf.clk[3] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + (gInfoWin->f1C / 10 + 1));
        buf.clk[4] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + (gInfoWin->f1C % 10 + 1));
        buf.clk[6] = buf.clk[1] + 0x10;
        k = (gInfoWin->f14 != 0) ? 27 : 31;
        buf.clk[7] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + k);
        buf.clk[8] = buf.clk[3] + 0x10;
        buf.clk[9] = buf.clk[4] + 0x10;
        func_020410D0(gInfoWin->f06, 1, 0, 5, 2, (u32)buf.clk, 0, 0, 5, 2);
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 1;
    }

    if (gInfoWin->f04 & 4) {
        u8 sel = (gInfoWin->f04 & 0x200) ? 1 : 0;
        func_02025154(d_0209F834[sel], gInfoWin->f07, 9, 0, 3, 2);
        func_020251D8(6, &d_0209F840[sel], 2);
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 4;
    }

    if (gInfoWin->f04 & 8) {
        func_02025154(d_0209F848[gInfoWin->f20], gInfoWin->f07, 13, 0, 6, 2);
        func_020251D8(8, d_0209F852[gInfoWin->f20], 2);
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 8;
    }

    if (gInfoWin->f04 & 0x10) {
        func_02025154(0x20, gInfoWin->f07, 0x13, 0, 7, 2);
        if (gInfoWin->f04 & 0x800) {
            u8 t;
            u8 ph;
            if (func_02035630() == 0x1E)
                gInfoWin->f08 = gInfoWin->f08 + 2;
            else
                gInfoWin->f08 = gInfoWin->f08 + 1;
            if (gInfoWin->f08 >= 0x50)
                gInfoWin->f08 = 0;
            t = gInfoWin->f08 / 16;
            ph = gInfoWin->f08 % 16;
            if (t < 4) {
                int d;
                u8 c;
                d = ph - 8;
                if (d < 0)
                    d = -d;
                ph = 8 - d;
                c = ph * 13 / 8 + 6;
                buf.col[0] = (c << 5) | c | (c << 10);
                c = ph * 22 / 8 + 9;
                buf.col[1] = (c << 5) | c | (c << 10);
                func_020251D8(10, buf.col, 2);
            } else {
                func_020251D8(10, &d_0209F838[0], 2);
            }
        } else {
            u8 sel = (gInfoWin->f04 & 0x1400) ? 1 : 0;
            func_020251D8(10, &d_0209F838[sel], 2);
        }
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 0x10;
    }

    if (gInfoWin->f04 & 0x20) {
        u8 *sp8 = buf.sel.v;
        buf.ofs = d_0209F870;
        buf.sel = d_0209F868;
        if (OS_IsRunOnTwl()) {
            k = sp8[gInfoWin->f1F];
        } else {
            k = (gInfoWin->f1F == 5) ? 5 : 4;
        }
        buf.scr[0] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + buf.ofs.v[k]);
        buf.scr[2] = buf.scr[0] + 0x10;
        buf.scr[1] = buf.scr[0] + 0x400;
        buf.scr[3] = buf.scr[2] + 0x400;
        func_020410D0(gInfoWin->f06, 0x1C, 0, 2, 2, (u32)buf.scr, 0, 0, 2, 2);
        func_020251D8(13, d_0209F830, 1);
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 0x20;
    }

    if (done == 1)
        func_020409B4(gInfoWin->f06);
}





/*
 * note:     infowin tile-rect writer: fills a w*h u16 screen buffer with
 *           charbase + base + (pal << 12) + i + j*16 and hands it to
 *           func_020410D0.  x/y/w/h are u8 (the callee takes u8 w/h);
 *           `j * 16`, not `j << 4`, fixes the adds operand order.
 */
void func_02025154(u32 base, u32 blk, u8 x, u8 y, u8 w, u8 h)
{
    u16 buf[14];
    u8 i;
    u8 j;
    u32 p;
    struct InfoWin *q;

    i = 0;
    if (i < w) {
        p = base + (blk << 12);
        q = gInfoWin;
        do {
            for (j = 0; j < h; j++) {
                buf[j * w + i] = (u16)(q->f00 + (i + p + j * 16));
            }
            i++;
        } while (i < w);
    }
    func_020410D0(gInfoWin->f06, x, y, w, h, (u32)buf, 0, 0, w, h);
}





int func_020251D8(int a0, const void *a1, int a2)
{
    return func_02040E78(gInfoWin->f06, a1, a2 * 2, (a0 + (gInfoWin->f07 << 4)) * 2);
}





void func_020251FC(u32 a, u32 b, u32 c)
{
    void *env;
    u32 sel = 0;

    if (a > 3) {
        sel = 4;
    }

    env = func_020490F4(0x32, c);
    gInfoWin->f00 = func_0203FA08(a, 1 << 12, 1);
    func_02049B68(env, 0, sel, b << 5, 0x20, c);
    func_02049658(env, 1, a, gInfoWin->f00, 0, 0, c);
    ENV_SetResourceSet(env);
    func_02041300(a, (u16)(gInfoWin->f00 + 0xf), 0, 0, 0x20, 1, b);
    func_02041300(a, (u16)(gInfoWin->f00 + 0x1f), 0, 1, 0x20, 1, b);
    func_020409B4(a);
}





void func_020252A8(void)
{
    struct Cfg cfg;
    u32 v;

    func_0203F4CC((struct RtcTime *)(&cfg));
    v = cfg.c & 1;

    if (cfg.a != gInfoWin->f1D) {
        gInfoWin->f1D = cfg.a;
        if (gInfoWin->f1D >= 0xc) {
            gInfoWin->f18 = 1;
        } else {
            gInfoWin->f18 = 0;
        }
        gInfoWin->f04 |= 1;
    }

    if (cfg.b != gInfoWin->f1C) {
        gInfoWin->f1C = cfg.b;
        gInfoWin->f04 |= 1;
    }

    if (v != gInfoWin->f14) {
        gInfoWin->f14 = v;
        gInfoWin->f04 |= 1;
    }
}
