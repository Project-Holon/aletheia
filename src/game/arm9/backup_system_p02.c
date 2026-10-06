/*
 * file:     backup_system_p02.c
 * unit:     yes
 * function: func_020319F0, func_02031AE0, func_02031B8C, func_02031BB4, func_02031C04, func_02031C10, func_02031C30, func_02031DC0, func_02031E68
 * address:  0x020319F0
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
 *   func_02033534  0x02033534  arm
 *   str_020A7848   0x020A7848  data
 *   g_02146994     0x02146994  data
 *   func_02033908  0x02033908  arm
 *   func_020319C0  0x020319C0  arm
 *   func_02034714  0x02034714  arm
 *   func_02034F84  0x02034F84  arm
 *   func_02033200  0x02033200  arm
 *   func_020335AC  0x020335AC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02034FB8  0x02034FB8  arm
 *   func_02031FE0  0x02031FE0  arm
 *   func_02032688  0x02032688  arm
 *   func_02032CD0  0x02032CD0  arm
 *   func_020331A4  0x020331A4  arm
 *   sub_02032970   0x02032970  arm
 *   func_02031EE8  0x02031EE8  arm
 *   func_02031EF8  0x02031EF8  arm
 *   func_02031EAC  0x02031EAC  arm
 *   func_020335E8  0x020335E8  arm
 *   func_02033B68  0x02033B68  arm
 *   func_02033BAC  0x02033BAC  arm
 *   func_02031F94  0x02031F94  arm
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

extern void func_020319C0(u8 *p);

extern void func_02034714(const char *expr, u32 line, const char *file);

#include "../../matched/include/Obj06929.h"

struct Blk;

struct In;

extern u32 func_020307B0(void *p);

extern void func_020339B4(int *p);

#include "../../matched/include/Obj11324.h"

extern u32 func_02033B68(u8 *p, u32 i);

struct T;

extern void func_020339D0(u32 a, struct T *sb);

#include "../../matched/include/Obj01020.h"

#include "../../matched/include/Obj02604.h"

struct Job {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad_0c[0x10];
    u8  f1c;
};

extern void  func_02034F84(u32 a);

struct SaveBackup;

extern u32 func_02033200(struct SaveBackup *p, u32 id);

extern u32 func_020335AC(u32 a, u32 b, u32 c, u32 d);

extern void func_02034FB8(u32 v);

struct State {
    u32 f00;
    u32 f04;
    u8  pad08[0x14];
    u8  f1c;
};

struct Save;

extern int func_02031FE0(struct Save *o, u32 a1, u32 a2, u32 a3);

extern int func_02032688(struct Save *o, int a1, int a2);

extern void func_02032970(struct SaveBackup *p, u32 flag);

extern void func_020331D0(struct SaveBackup *p);

struct Save_02032CD0;

extern int func_02032CD0(struct Save_02032CD0 *p, u32 *out);

extern void func_020331A4(struct SaveBackup *p, u32 result, u32 flag);

void func_02031B8C(u8 *p);

int func_02031BB4(u32 a0);

#include "../../matched/include/Obj08815.h"

struct Obj {
    u32  f00;
    u32  f04;
    u8   pad08[0x16];
    u8   f1e;
    u8   f1f;
    u32 *f20;
    u8   pad24[4];
    u32  f28;
};

extern void sub_02032970(struct SaveBackup *p, u32 flag);

void func_02031C10(u8 *a, u8 *b, u32 v);

typedef struct Obj02031DC0 {
    u32 f00;
    u32 f04;
    u8  pad08[0x14];
    u8  f1c;
} Obj02031DC0;

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
 * Erase the whole backup device in 0x1000-byte pages.  A 0x1000-byte scratch
 * page is allocated on the heap named by the u16 second argument (the
 * __FILE__ is "backup_system.c" at 0x020A7848 and the __LINE__ is 0x1e8),
 * filled with 0xff by func_02082A7C, and written over every page of the
 * device: the job's +8 word is the total length, its +0 word the destination
 * base, and the device handle comes from the +0x208 field of the object
 * behind the global at 0x02146994, re-read once per page along with the base.
 *
 * The literal 1 is materialised ONCE into r4 and reused as the second
 * argument of the first func_02033200 call
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md);
 * the second call's 2 is its own `mov`.  The 0x1000 page size is materialised
 * twice, once for the allocation and once into callee-saved r8 for the loop,
 * because the fill call in between clobbers it.
 *
 * The lengths compare unsigned (`bls`/`blo`), so a zero-length device skips
 * the loop entirely; the +4 word is a second length whose inequality with
 * +0 triggers an extra func_02033200(obj, 2) pass before the fill.
 *
 * Declaration order is one/off/page, which is what shares r4 between the
 * literal 1 and the loop cursor and leaves r5 for the scratch page
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 * page-first gives the exact same 240 bytes with r4 and r5 swapped, 12 out.
 * The heap id is a u32 parameter truncated at the call site, not a u16
 * parameter: the explicit `(u16)` is what produces the `lsl`/`lsr` pair at
 * +0x0008/+0x0018, and a u16 parameter folds it to a single `mov` for 236.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020319F0.c \
 *       --func func_020319F0 --addr 0x020319F0 --cc 1.1p1 --arm
 */
int func_020319F0(struct Job *job, u32 heap)
{
    u32 one;
    u32 off;
    void *page;

    page = func_02030734((u16)heap, 0x1000, 0, str_020A7848, 0x1e8);

    one = 1;
    func_02034F84(one);
    func_02033200((struct SaveBackup *)job, one);
    if (job->f00 != job->f04)
        func_02033200((struct SaveBackup *)job, 2);

    func_02082A7C(0xFFFFFFFF, page, 0x1000);

    for (off = 0; off < job->f08; off += 0x1000)
        func_020335AC(off + job->f00, (u32)page, 0x1000, g_02146994->unk208);

    func_020307B0(page);
    func_020319C0((u8 *)job);
    job->f1c = 0;
    func_02034FB8(1);
    return 1;
}

/*
 * Dispatch one step of the object's state machine: if the manager global's
 * front object is unarmed the call reports 4 immediately; otherwise the
 * object is either re-armed (its two queue cursors agree) or advanced, and
 * the call's status is dispatched through the dense switch that runs from
 * case 0 to case 4.  The armed transition stamps the progress byte at +0x1c.
 *
 * Two spellings were load-bearing in reaching EXACT, both worth keeping:
 *   - if/else polarity: the unequal arm is written first so it becomes the
 *     fall-through arm and the equal arm goes out of line at +0x40;
 *   - the case order 1, 2, 3, 0, 4: mwcc lays the arm bodies out in source
 *     order and the original's case-0 body sits after case 3's, at +0x90.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031AE0.c \
 *       --func func_02031AE0 --addr 0x02031AE0 --cc 1.1p1 --arm
 */
int func_02031AE0(struct State *o, u32 a1)
{
    u32 r;

    if (g_02146994->unk000 == 0)
        return 4;

    if (o->f00 != o->f04)
        r = func_02031FE0((struct Save *)o, a1, 0, 0);
    else
        r = func_02032688((struct Save *)o, 0, 0);

    switch (r) {
    case 1:
        o->f1c = 1;
        return 1;
    case 2:
        o->f1c = 1;
        return 2;
    case 3:
        return 3;
    case 0:
        return 0;
    case 4:
        return 4;
    }
    return 4;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031B8C.c \\
 *       --func func_02031B8C --addr 0x02031B8C --arm --cc 1.1p1
 */
void func_02031B8C(u8 *p)
{
    if (*(u32 *)(*(u32 *)0x02146994) != 0) {
        func_02032970((struct SaveBackup *)p, 1);
    }
}

/*
 * Blocked at MATCH on the `label`/`matched` classes: 75 of 76 bytes
 * reproduce and the only unresolved site is the PC24 at +0x24 to
 * func_02032CD0, whose single branch reference image-wide is this call, so
 * there is no witness outside 02031BB4..02031C04.  Filing 0x02032CD0 as an
 * EXACT manifest entry promotes this file with no change to the C.
 *
 * 0x02031BB4 is called from 0x02031B88 (the same packet's neighbour) and the
 * stack slot it hands func_02032CD0 is the pushed r3 scratch word, so the
 * local's address is taken but its value is never read here.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02031BB4.c \
 *       --func func_02031BB4 --addr 0x02031BB4 --cc 1.1p1 --arm
 */
int func_02031BB4(u32 a0)
{
    int r;
    u32 v;

    if (g_02146994->unk000 == 0)
        return 3;
    r = func_02032CD0((struct Save_02032CD0 *)a0, &v);
    if (r != 0 && r != 1)
        func_020331A4((struct SaveBackup *)a0, r, 1);
    return r;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031C04.c \\
 *       --func func_02031C04 --addr 0x02031C04 --arm --cc 1.1p1
 */
void func_02031C04(struct SaveBackup *a0)
{
    func_020331D0(a0);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031C10.c \\
 *       --func func_02031C10 --addr 0x02031C10 --arm --cc 1.1p1
 */
void func_02031C10(u8 *a, u8 *b, u32 v)
{
    ((struct Obj08815 *)a)->f20 = v;
    a[0x1e] = 0;
    a[0x1f] = 2;
    b[0x1e] = 0;
    b[0x1f] = 2;
}

/*
 * Drive a two-copy save through func_02032CD0 (the write state machine),
 * one step per call, on the state byte at q+0x1E: open a generation on `p`
 * (sub_02032970), write `p`, copy its generation word to *q->f20 and open one
 * on `q`, write `q` (on failure also report it against `p` when p's two
 * area words differ), finish `p` if its two area words differ, then finish
 * `q`, answering 3 when p's result byte says so.  Both objects are the same
 * save-record type (both go to func_02032CD0 and func_020331A4).
 * Wave 11, 2026-09-23.
 *
 * The one lever the 2026-09-21 lanes named and did not reach: case 4 is
 * written with the UNEQUAL test first and the bare `q->f1e++` in the `else`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  That moves the
 * `state = s + 1` block out of line (0x02031D78) and lets case 1's
 * `state++; break;` share case 4's `b 0x02031C70`.  All four func_02032CD0
 * result tests are negated (`r != 0 && r != 1`), per the note.
 */
int func_02031C30(struct Obj *q, struct Obj *p)
{
    u32 tmp;
    int r;

    switch (q->f1e) {
    case 0:
        sub_02032970((struct SaveBackup *)p, 1);
        q->f1e++;
        break;
    case 1:
        r = func_02032CD0((struct Save_02032CD0 *)p, &tmp);
        if (r != 0 && r != 1) {
            func_020331A4((struct SaveBackup *)p, r, 1);
            if (r == 3)
                return 3;
            q->f1e++;
            break;
        }
        if (tmp == 1)
            q->f1e++;
        break;
    case 2:
        *q->f20 = p->f28;
        sub_02032970((struct SaveBackup *)q, 0);
        q->f1e++;
        break;
    case 3:
        r = func_02032CD0((struct Save_02032CD0 *)q, &tmp);
        if (r != 0 && r != 1) {
            func_020331A4((struct SaveBackup *)q, r, 1);
            if (p->f00 != p->f04)
                func_020331A4((struct SaveBackup *)p, r, 1);
            return 3;
        }
        if (tmp == 1)
            q->f1e++;
        break;
    case 4:
        if (p->f00 != p->f04) {
            r = func_02032CD0((struct Save_02032CD0 *)p, &tmp);
            if (r != 0 && r != 1) {
                func_020331A4((struct SaveBackup *)p, r, 0);
                p->f1f = r;
                q->f1e++;
            }
        } else {
            q->f1e++;
        }
        break;
    case 5:
        r = func_02032CD0((struct Save_02032CD0 *)q, &tmp);
        if (r != 0 && r != 1) {
            func_020331A4((struct SaveBackup *)q, r, 1);
            if (p->f1f == 3)
                r = 3;
            return r;
        }
        break;
    }
    return 0;
}

/*
 * Drive one step of the object's state machine.  The engine pointer is read
 * through the global at 0x02146994 twice (`ldr ip,[pc]; ldr ip,[ip]; cmp`),
 * so the declaration is a `u32 *` and a null engine reports 4 without
 * touching anything.  The object's +0x00 and +0x04 words then pick which of
 * the two engine entry points runs - different words take func_02031FE0 with
 * the object, the first argument, a hard 1 and the third argument, equal
 * words take func_02032688 - and that call's status picks the arm: 1 and 2
 * also set the +0x1C byte, 0/3/4 report themselves and anything above 4
 * reports 4.
 *
 * The case labels are NOT in numeric order in the source.  Written
 * `case 0: return 0; case 1: ... case 2: ... case 3: return 3; case 4:
 * return 4;` the five arms come out in the table's own order and the
 * function is 8 bytes of DIFF (every arm's body is 8 bytes early, case 0's
 * body lands first instead of just before case 4's).  mwccarm emits the
 * bodies in the order the labels are written, so the source order here is
 * 1, 2, 3, 0, 4 - which is what reproduces the listing: the table's entry 0
 * branches past the three arms to 0x02031E4C.
 *
 * EXACT* rather than EXACT: the byte comparison passes at all 168 bytes (164
 * of code plus the pool word for 0x02146994) and all three sites resolve,
 * but the listing's next label is beyond 0x02031E68, where the follower at
 * 0x02031E68 (`ldr r0,[r0,#0x144]; bx lr`) has no func_ entry point, so the
 * inferred extent runs long.  Report the unlabelled follower rather than
 * edit layout/function_starts.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031DC0.c \
 *       --func func_02031DC0 --addr 0x02031DC0 --cc 1.1p1 --arm
 */
int func_02031DC0(Obj02031DC0 *a0, u32 a1, u32 a2)
{
    int st;

    if (g_02146994->unk000 == 0)
        return 4;
    if (a0->f00 != a0->f04)
        st = func_02031FE0((struct Save *)a0, a1, 1, a2);
    else
        st = func_02032688((struct Save *)a0, 1, a2);
    switch (st) {
    case 1:
        a0->f1c = 1;
        return 1;
    case 2:
        a0->f1c = 1;
        return 2;
    case 3:
        return 3;
    case 0:
        return 0;
    case 4:
        return 4;
    }
    return 4;
}

int func_02031E68(const char *ptr)
{
    return *(const int *)&((struct Obj15878 *)ptr)->f144;
}
