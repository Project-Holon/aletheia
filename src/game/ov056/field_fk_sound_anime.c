/*
 * file:     field_fk_sound_anime.c
 * unit:     yes
 * function: func_021F3E94, func_021F3ECC, func_021F3F30, func_021F3F7C, func_021F3F94, func_021F3FB8, func_021F4004, func_021F401C, func_021F4040, func_021F408C, func_021F40A0, func_021F4224
 * address:  0x021F3E94
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C654  0x0218C654  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   d_021F4284     0x021F4284  data  a4
 *   func_0218C6F4  0x0218C6F4  thumb  ov021
 *   func_02028A7C  0x02028A7C  thumb
 *   d_021F425C  0x021F425C  data  ov056  a4
 *   func_0201296C  0x0201296C  thumb
 *   func_020143CC  0x020143CC  thumb
 *   func_02028B50  0x02028B50  thumb
 *   func_02030734  0x02030734  arm
 *   func_02011510  0x02011510  thumb
 *   func_02082D44  0x02082D44  arm
 *   d_021F4400  0x021F4400  data  ov056  a1
 *   func_02011558  0x02011558  thumb
 *   sub_020307B0   0x020307B0  arm
 *   func_02011608  0x02011608  thumb
 *   func_020115EC  0x020115EC  thumb
 *   func_02011610  0x02011610  thumb
 *   func_02011660  0x02011660  thumb
 *   func_02011638  0x02011638  thumb
 *   func_021F423C  0x021F423C  thumb  ov056
 *   sub_020061E4  0x020061E4  thumb
 */
#include "../../matched/include/Obj07669.h"
#include "../../matched/include/Obj07670.h"

struct Ctx;
struct BigObj;
struct SoundSys2;
struct IcaAnime;
struct Obj11244;
struct Rec12;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short   s16;

typedef struct {
    u32 f0;
    u32 f4;
    u16 f8;
    s16 fa;
    int fc;
} S3ECC;

typedef struct {
    u16 *f0;
    u16 f4;
    u32 f8;
    int fc;
} S3F30;

typedef signed int     s32;

extern u32 func_02188C98(u8 *p);
extern u32 func_0218DC6C(u8 *p);
extern int func_0218C654(int a, int b, int c);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *p);
extern int func_0218C6F4(unsigned char *p, int b, int id);
extern void func_02028A7C(struct SoundSys2 *s, u32 id);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020143CC(u32 a, u32 b);
extern void func_02028B50(u8 *p, int a0);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02011510(u16 heap, u32 b, u32 c, u32 d);
extern void func_02082D44(void *dst, void *src, int n);
extern void func_02011558(struct IcaAnime *p);
extern u32 sub_020307B0(void *p);
extern u32 func_02011608(struct Obj11244 *p);
extern void func_020115EC(struct IcaAnime *p, s32 v);
extern u32 func_02011610(struct IcaAnime *p, struct Rec12 *dst);
extern u32 func_02011660(struct IcaAnime *p, struct Rec12 *dst);
extern u32 func_02011638(struct IcaAnime *p, struct Rec12 *dst);
extern void func_021F423C(u8 *p, u32 idx);
extern void sub_020061E4(u32 a);
void func_021F3E94(void *unused, u8 *b, u8 *c);
void func_021F3EC8(void *unused, u8 *b, u8 *c);
void func_021F3ECC(int a, int b, S3ECC *c);
void func_021F3F30(int a, int b, S3F30 *c);
void func_021F3F7C(void *a, void *b, u8 *c);
void func_021F3F94(void *a, void *b, u8 *c);
void func_021F3FB8(int a, int b, S3F30 *c);
void func_021F4004(void *a, void *b, u8 *c);
void func_021F401C(void *a, void *b, u8 *c);
u32 *func_021F4040(void *a, u32 b, u32 c, u32 d, u16 e);
void func_021F408C(struct IcaAnime **pp);
int func_021F40A0(int *p);
void func_021F4224(u8 *p, u32 idx);
extern u8 d_021F4284[];
extern int d_021F425C[];
extern char d_021F4400[];


/*
 * note:     first entry of the callback triple at 0x021F4364
 *           {0x021F3E95, 0x021F3EC9, 0x021F3ECD}; r0 is unused. The second
 *           entry, func_021F3EC8, is an unlabelled empty callback (bx lr)
 *           right after the lead's pool, then 2 bytes of padding.
 */
void func_021F3E94(void *unused, u8 *b, u8 *c)
{
    u32 r;

    r = func_0218DC6C((u8 *)func_02188C98(b));
    *(int *)(c + 0x4) = func_0218C654((int)r, 0, (int)d_021F4284);
    *(u32 *)(c + 0x0) = r;
    *(u32 *)(c + 0xC) = func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx *)func_02188C80(b)));
}


void func_021F3EC8(void *unused, u8 *b, u8 *c)
{
}


void func_021F3ECC(int a, int b, S3ECC *c)
{
    int i;
    int r;

    i = 0;
    r = func_0218C6F4((unsigned char *)c->f0, c->f4, 0);
    for (; i < 2; i++) {
        if (r == d_021F425C[i]) {
            func_02028A7C((struct SoundSys2 *)c->fc, 0x743);
            c->f8 = 1;
            c->fa = 0x1f;
            break;
        }
    }
    if (c->f8 != 0) {
        c->fa = c->fa - 1;
        if (c->fa <= 0) {
            func_02028A7C((struct SoundSys2 *)c->fc, 0x76e);
            c->f8 = 0;
            c->fa = 0;
        }
    }
}


void func_021F3F30(int a, int b, S3F30 *c)
{
    int r5;

    r5 = (int)func_020120F4(func_02188C80((void *)b));
    c->f8 = func_0201296C((const struct BigObj *)r5);
    c->fc = func_02012A30((const struct BigObj *)r5);
    c->f0 = (u16 *)func_020143CC(c->f8, 0x4001);
    if (*c->f0 == 0) {
        func_02028A7C((struct SoundSys2 *)c->fc, 0x756);
        c->f4 = 0;
        return;
    }
    c->f4 = 1;
}


void func_021F3F7C(void *a, void *b, u8 *c)
{
    if (*(u16 *)(c + 4) == 0) {
        func_02028B50(*(u8 **)(c + 0xc), 0x756);
    }
}


void func_021F3F94(void *a, void *b, u8 *c)
{
    if (*(u16 *)(((struct Obj07669 *)c)->f0) != 0 && ((struct Obj07669 *)c)->f4 == 0) {
        func_02028B50((u8 *)(((struct Obj07669 *)c)->fC), 0x756);
        ((struct Obj07669 *)c)->f4 = 1;
    }
}


void func_021F3FB8(int a, int b, S3F30 *c)
{
    int r5;

    r5 = (int)func_020120F4(func_02188C80((void *)b));
    c->f8 = func_0201296C((const struct BigObj *)r5);
    c->fc = func_02012A30((const struct BigObj *)r5);
    c->f0 = (u16 *)func_020143CC(c->f8, 0x4001);
    if (*c->f0 == 0) {
        func_02028A7C((struct SoundSys2 *)c->fc, 0x7ef);
        c->f4 = 0;
        return;
    }
    c->f4 = 1;
}


void func_021F4004(void *a, void *b, u8 *c)
{
    if (*(u16 *)(c + 4) == 0) {
        func_02028B50(*(u8 **)(c + 0xc), 0x7ef);
    }
}


void func_021F401C(void *a, void *b, u8 *c)
{
    if (*(u16 *)(((struct Obj07670 *)c)->f0) != 0 && ((struct Obj07670 *)c)->f4 == 0) {
        func_02028B50((u8 *)(((struct Obj07670 *)c)->fC), 0x7ef);
        ((struct Obj07670 *)c)->f4 = 1;
    }
}


/*
 * Allocates a 0x1C-byte record from heap e, fills word 0 from
 * func_02011510(e, b, c, d) and copies 0x12 bytes of a into it at +8.
 * The u16 heap e is re-read with ldrh from its stack slot before each call,
 * so both callees take it as u16 (see
 * a-u16-stack-parameter-reloaded-per-call-means-u16-callee-parameters.md);
 * with u32 callee parameters e stayed in r5 and c/d spilled.
 */
u32 *func_021F4040(void *a, u32 b, u32 c, u32 d, u16 e)
{
    u32 *r;

    r = func_02030734(e, 0x1c, 1, d_021F4400, 0x4d);
    r[1] = 0;
    r[0] = func_02011510(e, b, c, d);
    func_02082D44(a, r + 2, 0x12);
    return r;
}


/*
 * extent:   EXACT* covers only the 2-byte alignment pad at 0x021F409E;
 *           the follower 0x021F40A0 is separately matched (pkt_021F40A0).
 */
void func_021F408C(struct IcaAnime **pp)
{
    func_02011558(*pp);
    sub_020307B0(pp);
}


/*
 * Unblocked (2026-09-26 recursive MATCH unblocker, arm9 0x0200..0x0202):
 *   both wildcarded relocations are now `matched`.
 *   - func_02011608: EXACT, src/matched/func_02011608.c (pkt_02011608).
 *   - func_02011660: already an EXACT member of the game_unit
 *     src/matched/unit_02011610.c (pkt_020113F0); that unit's `function:`
 *     header now lists all three copies, so the manifest covers 0x02011660.
 *   All 23 relocations resolve; EXACT* because the extent runs to the next
 *   unlabelled follower.
 */
int func_021F40A0(int *p)
{
    int flag;
    int a[3], b[3], c[3];
    int x = func_02011608((struct Obj11244 *)p[0]) << 12;

    if (x <= p[1]) {
        flag = 1;
        p[1] = x - 0x1000;
    } else {
        flag = 0;
    }
    func_020115EC((struct IcaAnime *)p[0], p[1]);
    func_02011610((struct IcaAnime *)p[0], (struct Rec12 *)a);
    func_02011660((struct IcaAnime *)p[0], (struct Rec12 *)b);
    func_02011638((struct IcaAnime *)p[0], (struct Rec12 *)c);
    if (a[0] == 0x1000) func_021F4224((u8 *)p, 0); else if (a[0] == 0x2000) func_021F423C((u8 *)p, 0);
    if (a[1] == 0x1000) func_021F4224((u8 *)p, 1); else if (a[1] == 0x2000) func_021F423C((u8 *)p, 1);
    if (a[2] == 0x1000) func_021F4224((u8 *)p, 2); else if (a[2] == 0x2000) func_021F423C((u8 *)p, 2);
    if (b[0] == 0x1000) func_021F4224((u8 *)p, 3); else if (b[0] == 0x2000) func_021F423C((u8 *)p, 3);
    if (b[1] == 0x1000) func_021F4224((u8 *)p, 4); else if (b[1] == 0x2000) func_021F423C((u8 *)p, 4);
    if (b[2] == 0x1000) func_021F4224((u8 *)p, 5); else if (b[2] == 0x2000) func_021F423C((u8 *)p, 5);
    if (c[0] == 0x1000) func_021F4224((u8 *)p, 6); else if (c[0] == 0x2000) func_021F423C((u8 *)p, 6);
    if (c[1] == 0x1000) func_021F4224((u8 *)p, 7); else if (c[1] == 0x2000) func_021F423C((u8 *)p, 7);
    if (c[2] == 0x1000) func_021F4224((u8 *)p, 8); else if (c[2] == 0x2000) func_021F423C((u8 *)p, 8);
    p[1] += 0x1000;
    return flag;
}


void func_021F4224(u8 *p, u32 idx)
{
    u16 v = *(u16 *)(p + idx * 2 + 8);

    if (v != 0xffff) {
        sub_020061E4(v);
    }
}
