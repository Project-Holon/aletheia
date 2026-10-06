/*
 * file:     backup_system_p01.c
 * unit:     yes
 * function: func_020316C8, func_0203174C, func_0203192C, FSi_ConvertStringSjisToUnicode, func_0203195C, func_02031994, func_020319A4, func_020319C0
 * address:  0x020316C8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py and a merge lane from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_020819B8  0x020819B8  arm
 *   func_02033534  0x02033534  arm
 *   str_020A7848   0x020A7848  data
 *   g_02146994     0x02146994  data
 *   func_02033908  0x02033908  arm
 *   func_02033BF8  0x02033BF8  arm
 *   func_02033410  0x02033410  arm
 *   func_020319C0  0x020319C0  arm
 *   func_02034714  0x02034714  arm
 *   str_020A7858   0x020A7858  data
 *   str_020A7868   0x020A7868  data
 *   func_0203174C  0x0203174C  arm
 *   func_02034F84  0x02034F84  arm
 *   func_020335AC  0x020335AC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02034FB8  0x02034FB8  arm
 *   func_02031FE0  0x02031FE0  arm
 *   func_02032688  0x02032688  arm
 *   func_02032CD0  0x02032CD0  arm
 *   func_02031EE8  0x02031EE8  arm
 *   func_02031EF8  0x02031EF8  arm
 *   func_02031EAC  0x02031EAC  arm
 *   func_020335E8  0x020335E8  arm
 *   func_02033B68  0x02033B68  arm
 *   func_02033BAC  0x02033BAC  arm
 *   func_02031F94  0x02031F94  arm
 *   func_020319A4  0x020319A4  arm
 *   func_02031ECC  0x02031ECC  arm
 *   func_020336A4           0x020336A4  arm
 *   sub_02033C00  0x02033C00  arm
 */
#include "../../matched/include/Obj15875.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct SaveBackup {
    u8  pad00[0x0C];
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u8  unk18;
    u8  unk19;
    u8  pad1A[2];
    u8  unk1C;
    u8  pad1D[11];
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u8  unk38[0x108];
    u32 unk140;
    u32 unk144;
};

struct SaveMain {
    u32 unk000;
    u8 crcTable[0x200];
    u32 unk204;
    u32 unk208;
    u16 unk20C;
};

extern struct SaveMain *g_02146994;

extern const char str_020A7848[];

extern void *func_02030734(u16 heap, u32 size, int align, const char *file,
                         u16 line);

extern void func_02082A7C(u32 a, void *p, u32 n);

struct MATHCRC16Table;

extern void func_020819B8(struct MATHCRC16Table *table, u16 poly);

extern int func_02033534(u32 a);

struct In {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
};

struct Blk {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u8  pad10[0x1c - 0x10];
    u8  f1c;
    u8  f1d;
    u8  pad1e[0x24 - 0x1e];
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u8  pad38[0x138 - 0x38];
    u32 f138;
    u32 f13c;
    u32 f140;
};

struct Obj02033410;

extern void *func_02033908(u16 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

struct Obj02033BF0;

extern u32 func_02033BF8(struct Obj02033BF0 *p);

extern void func_02033410(struct Obj02033410 *p, u32 val);

extern void func_020319C0(u8 *p);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern const u8 str_020A7858[];

extern const u8 str_020A7868[];

#include "../../matched/include/Obj06929.h"

struct Blk;

struct In;

extern struct Blk *func_0203174C(const struct In *in, u32 heap, u32 c, u32 d, u32 e);

extern u32 func_020307B0(void *p);

extern void func_020339B4(int *p);

u32 func_0203192C(void *a, void *b);

asm void FSi_ConvertStringSjisToUnicode(void);

void func_0203195C(u8 *p);

#include "../../matched/include/Obj11324.h"

extern u32 func_02033B68(u8 *p, u32 i);

struct T;

extern void func_020339D0(u32 a, struct T *sb);

#include "../../matched/include/Obj01020.h"

#include "../../matched/include/Obj02604.h"

extern void  func_02034F84(u32 a);

struct SaveBackup;

extern u32 func_020335AC(u32 a, u32 b, u32 c, u32 d);

extern void func_02034FB8(u32 v);

struct Save;

extern int func_02031FE0(struct Save *o, u32 a1, u32 a2, u32 a3);

extern int func_02032688(struct Save *o, int a1, int a2);

struct Save_02032CD0;

extern int func_02032CD0(struct Save_02032CD0 *p, u32 *out);

#include "../../matched/include/Obj08815.h"

#include "../../matched/include/Obj15878.h"

#include "../../matched/include/Obj15879.h"

#include "../../matched/include/Obj03443.h"

#include "../../matched/include/Obj08816.h"

struct SaveBackup;

u32 func_02031EAC(u32 *p, u32 sel);

int func_02031ECC(int p0);

int func_02031EE8(int p0, int p1);

u32 func_02031EF8(void *p, void *buf, u32 sel);

void func_02031F94(int *p, int v);

#include "../../matched/include/Obj16793.h"

#include "../../matched/include/Obj08817.h"

#include "../../matched/include/Obj08818.h"

#include "../../matched/include/Obj15881.h"

#include "../../matched/include/Obj08819.h"

struct Obj020332FC;

typedef struct Save Save;

struct Save {
    u8   pad00[0x2c];
    u8  *f2c;
    u32  f30;
    u8  *f34;
    u8   pad38[0x108];
    u32  f140;
};

extern int func_02031EE8(int p0, int p1);

extern u32 func_02031EF8(void *p, void *buf, u32 sel);

extern u32 func_02031EAC(u32 *p, u32 sel);

extern int func_020335E8(u32 a0, u32 a1, u32 a2, void (*a3)(void));

extern u32   func_02033B68(u8 *tbl, u32 idx);

extern u32   func_02033BAC(u8 *tbl, u32 idx);

extern void func_02031F94(int *p, int v);

extern void func_02034F84(u32 bit);

int func_02031FE0(Save *self, u32 heap, u32 mode, u32 gen);

int func_02032688(Save *self, int mode, int arg3);

extern u32 func_02033BAC(u8 *p, u32 i);

extern void func_02034FB8(u32 bit);

extern u32 func_020319A4(u8 *p, u32 id);

extern int func_02031ECC(int p0);

struct Obj0203335C;

struct SaveBackup;

typedef struct Save_02032CD0 Save_02032CD0;

struct Save_02032CD0 {
    u32  f00;
    u32  f04;
    u8   pad08[0xc];
    u32  f14;
    u8   f18;
    u8   f19;
    u8   pad1A[0x12];
    u8  *f2c;
    u8   pad30[0x114];
    u32  f144;
    u32  f148;
    u32  f14c;
    u32  f150;
};

extern void func_02034714(const char *file, u32 line, const char *msg);

int func_02032CD0(Save_02032CD0 *p, u32 *out);

struct Obj020332FC {
    char pad[0x138];
    u32 *slots;
};

struct Obj0203335C {
    char pad[0x2c];
    void *unk2c;
    char pad30[0x108];
    u32 *slots;
};

#include "../../matched/include/Obj11327.h"

struct Obj02033410 {
    char pad[0x2c];
    void *unk2c;
    char pad30[0x108];
    u32 *slots;
    u32  nbytes;
};

#include "../../matched/include/Obj15882.h"

int func_02033534(u32 a);

u32 func_020335AC(u32 a, u32 b, u32 c, u32 d);

int func_020335E8(u32 a0, u32 a1, u32 a2, void (*a3)(void));

void func_020336A4(void);

extern void func_020336A4(void);

#include "../../matched/include/Obj01312.h"

struct Save;

struct Save_020339B4;

extern void *func_02030734(u16 a, u32 b, int c, const char *d, unsigned short e);

void *func_02033908(u16 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

#include "../../matched/include/Obj11330.h"

#include "../../matched/include/Obj11331.h"

typedef struct T {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
} T;

struct Src { u32 id; void *fn; u32 w08; };

struct Dst { u32 id; u32 size; u32 offset; };

struct Save_020339B4 {
    struct Src *src;   /* +0x00 */
    u32 count;         /* +0x04 */
    u32 f08;           /* +0x08 */
    u32 f0c;           /* +0x0c */
    u32 f10;           /* +0x10 */
    struct Dst *dst;   /* +0x14 */
    u32 f18;           /* +0x18 */
};

void func_020339B4(int *p);

void func_020339D0(u32 a, T *sb);

u32 func_02033B68(u8 *p, u32 i);

u32 func_02033BAC(u8 *p, u32 i);

struct Obj02033BF0 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
};

struct AreaMan {
    u16 unk00;
    u16 unk02;
    u32 *guard;
    u32 unk08;
    u8 bits[1];
};

struct AreaMan *sub_02033C00(u32 size, u16 heap);

struct Struct_020344C8;

struct Struct_020344C8 {
    u8 pad[2];
    u16 count;
    u32 unk_4;
    void *ptr;
    u8 data[];
};

#include "../../matched/include/Obj11332.h"

struct AreaMan;

extern struct AreaMan *sub_02033C00(u32 size, u16 heap);

/*
 * Blocked at MATCH on the `label`/`matched` classes: all 124 concrete bytes
 * of the body reproduce and 6 of 7 relocation sites resolve, but
 * func_02033534 (PC24 at +0x6c) has exactly one branch reference image-wide
 * and it is this call, so the site has no witness outside 020316C8..0203174C
 * and no cut frees it.  Filing 0x02033534 as an EXACT manifest entry promotes
 * this file with no change to the C.
 *
 * backup_system.c: the one-time allocation of the 0x210-byte save block.
 * The first parameter is narrowed to 16 bits at function entry (the split
 * `lsl r0, r0, #0x10` / `lsr r0, r0, #0x10` pair); written with the mask
 * folded into the call site.
 * The file string is at 0x020A7848 ("backup_system.c", pool word at
 * 0x02031744) and __LINE__ = 0xdf.  The second size argument 0x1100 - 0xdf
 * is spelled as the subtraction because 0x1021 is not an ARM-encodable
 * immediate and mwcc had 0xdf live in a register from the allocator's line
 * argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020316C8.c \
 *       --func func_020316C8 --addr 0x020316C8 --cc 1.1p1 --arm
 */
void func_020316C8(u32 a0, u32 a1, u32 a2)
{
    struct SaveMain *p = func_02030734((u16)a0, 0x210, 0, str_020A7848, 0xdf);

    g_02146994 = p;
    func_02082A7C(0, p, 0x210);
    func_020819B8((struct MATHCRC16Table *)g_02146994->crcTable, 0x1100 - 0xdf);
    g_02146994->unk204 = a1;
    p = g_02146994;
    p->unk208 = a2;
    g_02146994->unk000 = func_02033534((u32)p);
}

/*
 * backup_system.c.  The save-block constructor; its already-matched caller
 * src/matched/func_0203192C.c fixes the five-argument signature.  The
 * allocator func_02030734 takes (heap, size, align, __FILE__, __LINE__)
 * with the line on the stack: 0x10e, 0x125 and 0x131.  0x154 is the block
 * size, kept live in sb, and the second assert's line 0x116 is derived from
 * it as `sub r1, sb, #0x3e` and the last allocation's 0x131 as
 * `add r0, sb, #0x130`
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 * The `in` parameter must be `const`: without it an unrelated store may
 * alias the fields and the compiler reloads them, 151 concrete bytes out at
 * the same 480
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md).
 * The heap id is narrowed per call site because the callee prototypes take
 * `u16`; a `(u16)heap` cast in the body is CSEd into one register instead.
 * The two size roundings are the `((n + k) >> s) << t` shape written out,
 * with the `tst`/`addne` correction being the low-bit remainder test the
 * front end derives from `+ 2` / `& 0xf`.
 */
struct Blk *func_0203174C(const struct In *in, u32 heap, u32 c, u32 d, u32 e)
{
    struct Blk *b;
    u32 n;
    void *tbl;

    if (g_02146994 == 0)
        func_02034714(str_020A7848, 0x10c, (const char *)str_020A7858);

    b = (struct Blk *)func_02030734(heap, 0x154, 1, str_020A7848, 0x10e);
    b->f00 = in->f08;
    b->f04 = in->f0c;
    b->f08 = in->f10;
    b->f0c = in->f14;

    if (c != 0 && d < b->f08)
        func_02034714(str_020A7848, 0x154 - 0x3e, (const char *)str_020A7868);

    b->f140 = in->f04 << 1;
    if ((in->f04 & 1) != 0)
        b->f140 = b->f140 + 2;

    n = in->f04 + 2;
    b->f13c = (n >> 4) << 2;
    if ((n & 0xf) != 0)
        b->f13c = b->f13c + 4;

    b->f138 = (u32)func_02030734(heap, b->f13c, 1, str_020A7848,
                                 0x125);
    tbl = func_02033908((u16)heap, in->f00, in->f04, b->f08, 0x10, 4, b->f140);
    b->f2c = (u32)tbl;
    b->f30 = func_02033BF8(tbl);
    if (c != 0) {
        b->f34 = c;
        b->f1d = 0;
    } else {
        b->f34 = (u32)func_02030734(heap, b->f08, 1, str_020A7848,
                                    0x131);
        b->f1d = 1;
    }
    b->f1c = 0;
    b->f28 = 0;
    b->f24 = 0;
    if (e == 1)
        func_020319C0((u8 *)b);
    else
        func_02033410((struct Obj02033410 *)b, 1);
    return b;
}

/*
 * backup_system.c.  A one-line forwarder: its two arguments go straight
 * through to 0x0203174C together with three zero/one flags, the fifth landing
 * on the stack.  The two zero arguments cost a single `mov r2, #0` plus the
 * `mov r3, r2` copy the compiler makes instead of a second move, and the `1`
 * is materialised into `ip` because an ARM `str` has no immediate form.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203192C.c \
 *       --func func_0203192C --addr 0x0203192C --cc 1.1p1 --arm
 */
u32 func_0203192C(void *a, void *b)
{
    return (u32)func_0203174C(a, (u32)b, 0, 0, 1);
}

asm void FSi_ConvertStringSjisToUnicode(void)
{
    stmfd sp!, {r3, lr}
    ldr ip, [sp, #8]
    str ip, [sp]
    bl func_0203174C
    ldmfd sp!, {r3, pc}
}

/*
 * A four-store teardown of one record: release the object at +0x2c, the one
 * at +0x138 unconditionally, the one at +0x34 only when the byte at +0x1d is
 * exactly 1, then the record itself.  The release callee is the overruled
 * SDK address 0x020307B0 (layout/symbols_sdk.txt calls it ENV_SetResourceSet,
 * the game code proves otherwise); it is already matched, which is what
 * attests the three PC24 sites.  0x020339B4, the +0x2c argument's own
 * destructor, was matched in the same wave and attests the fourth.
 *
 * The leaf follower at 0x02031994 (a two-field getter, no prologue) carries
 * no label, so the inferred extent from this address runs long: EXACT*.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203195C.c \
 *       --func func_0203195C --addr 0x0203195C --arm --cc 1.1p1
 */
void func_0203195C(u8 *p)
{
    func_020339B4((int *)(((struct Obj06929 *)p)->f2C));
    func_020307B0(((struct Obj06929 *)p)->f138);
    if (p[0x1d] == 1) {
        func_020307B0(((struct Obj06929 *)p)->f34);
    }
    func_020307B0(p);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031994.c \\
 *       --func func_02031994 --addr 0x02031994 --arm --cc 1.1p1
 */
u32 func_02031994(u8 *p, u32 *out)
{
    *out = ((struct Obj11324 *)p)->f30;
    return ((struct Obj11324 *)p)->f34;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020319A4.c \\
 *       --func func_020319A4 --addr 0x020319A4 --arm --cc 1.1p1
 */
u32 func_020319A4(u8 *p, u32 id)
{
    return func_02033B68(*(u8 * *)&((struct Obj01020 *)p)->f2C, id) + ((struct Obj01020 *)p)->f34;
}

/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020319C0.c \\
 *       --func func_020319C0 --addr 0x020319C0 --arm --cc 1.1p1
 */
void func_020319C0(u8 *p)
{
    func_020339D0(((struct Obj02604 *)p)->f34, (struct T *)*(u32 *)&((struct Obj02604 *)p)->f2C);
    func_02033410((struct Obj02033410 *)p, 1);
}
