/*
 * file:     btlv_effvm_p70.c
 * unit:     yes
 * function: func_022003C4, func_022003EC, func_0220041C, func_02200468, func_02200494, func_022004BC, func_0220055C, func_022005C4
 * address:  0x022003C4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022019F4 0x022019F4 thumb ov094
 *   func_02017100  0x02017100  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020172AC  0x020172AC  thumb
 *   func_020160CC  0x020160CC  thumb
 *   sub_02016028   0x02016028  thumb
 *   func_02015F2C  0x02015F2C  thumb
 *   func_02201894  0x02201894  thumb  ov094
 *   func_02015C30  0x02015C30  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_02015C60  0x02015C60  thumb
 *   func_02015C78  0x02015C78  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   func_022018A8  0x022018A8  thumb  ov094
 *   func_02016394  0x02016394  thumb
 *   func_021F8710  0x021F8710  thumb  ov094
 */
#include "../../matched/include/Obj12226.h"
#include "../../matched/include/Obj12228.h"

struct Stats;
typedef unsigned int u32;

typedef struct {
    int pad00;              /* 0x00 */
    void *obj;              /* 0x04 */
} Work_022003EC;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x40];
    int f44;                /* 0x44 */
    char pad48[0x14];
} Entry_0220041C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_0220041C e[14];            /* 0x008 */
} Work_0220041C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_02200468;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200468 e[14];            /* 0x008 */
} Work_02200468;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    u32 flags;              /* 0x4c */
    char pad50[0x0c];
} Entry_022004BC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_022004BC e[14];            /* 0x008 */
} Work_022004BC;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_0220055C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_0220055C e[14];            /* 0x008 */
} Work_0220055C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 9;    /* 0x4c */
    unsigned int f9 : 1;
    unsigned int hi : 22;
    char pad50[0x0c];
} Entry_022005C4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_022005C4 e[14];            /* 0x008 */
} Work_022005C4;

extern int func_022019F4(char *p, int key);
extern void func_02017100(void *p, struct Stats *out, u32 lvl);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_020172AC(int a0, int a1);
extern int func_020160CC(void *h);
extern void sub_02016028(void *h, u32 n);
extern void func_02015F2C(void *h, int idx, void (*fn)(int), int v);
extern void func_02201894(int i);
extern void func_022018A8(Work_022004BC *w, Vec *out, int key);
extern void func_02015C30(void *p, u32 *out);
extern void func_02015C60(void *p, u32 *out);
extern void func_02015C48(void *p, u32 *src);
extern void func_02015C78(void *p, u32 *src);
extern void func_02015EA0(void *h);
extern int func_021F8710(void);
extern void func_02016394(void *h, int flag);
int func_022003C4(char *p, int key);
void func_022003EC(Work_022003EC *w, void *p, int *a, int flags);
int func_0220041C(Work_0220041C *w, int key, int n);
void func_02200468(Work_02200468 *w, int key);
int func_02200494(char *p, int key);
void func_022004BC(Work_022004BC *w, int key);
void func_0220055C(Work_0220055C *w, int key, int mode);
int func_022005C4(Work_022005C4 *w, int key);


/*
 * lane O10 candidate
 */
int func_022003C4(char *p, int key)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12226 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12226 *)e)->f44;
}


void func_022003EC(Work_022003EC *w, void *p, int *a, int flags)
{
    int v = 1;

    if (flags & 1)
        v = 0;
    func_02017100(p, (struct Stats *)a, v);
    func_020172AC((int)w->obj, func_02017E1C(p, 0, 0));
}


/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical (one prints MATCH*); blocked on 0x020160CC, an
 * unfiled unlabelled ARM9 Thumb leaf (Ilias's) with no witness outside this
 * range. Verified C for it (EXACT, `one --thumb`, no --region, cc 1.1p1,
 * -O4,p; packet pkt_020160CC, 64 B extent):
 *
 *   typedef unsigned short u16;
 *   typedef struct { char pad[0x28]; u16 *p28; } S;
 *   u16 func_020160CC(S *s) { return *s->p28; }
 *
 * The extern here takes `int` as return type (u16 not needed at the caller).
 */
int func_0220041C(Work_0220041C *w, int key, int n)
{
    int r = 0;
    int i = func_022019F4((char *)w, key);

    if (i == -1)
        return 0;
    if (w->e[i].h == 0)
        return 0;
    if (n < func_020160CC(w->e[i].h)) {
        sub_02016028(w->e[i].h, n);
        r = 1;
        w->e[i].f44 = r;
    }
    return r;
}


void func_02200468(Work_02200468 *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    func_02015F2C(w->e[idx].h, idx, func_02201894, 1);
}


int func_02200494(char *p, int key)
{
    int i = func_022019F4(p, key);
    char *e;

    if (i == -1)
        return 0;
    e = p + i * 0x5c;
    if (((struct Obj12228 *)e)->f8 == 0)
        return 0;
    return ((struct Obj12228 *)e)->f4C;
}


/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical; blocked on 0x02015C60, an unfiled unlabelled ARM9
 * Thumb leaf (Ilias's) with no witness outside this range. Verified C for it
 * (EXACT, `one --thumb`, no --region, cc 1.1p1, -O4,p; packet pkt_02015C60,
 * 64 B extent, out-direction twin of func_02015C78):
 *
 *   typedef unsigned int u32;
 *   void func_02015C60(void *p, u32 *out)
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x11C);
 *       out[1] = *(u32 *)((char *)p + 0x120);
 *       out[2] = *(u32 *)((char *)p + 0x124);
 *   }
 */
void func_022004BC(Work_022004BC *w, int key)
{
    Vec want;
    Vec cur;
    Vec off;
    int i = func_022019F4((char *)w, key);

    if (i == -1)
        return;
    if (w->e[i].h == 0)
        return;
    func_022018A8(w, &want, key);
    func_02015C30(w->e[i].h, (u32 *)(&cur));
    func_02015C60(w->e[i].h, (u32 *)(&off));
    w->e[i].flags &= ~0x40;
    if (want.x == cur.x && want.y == cur.y && want.z == cur.z
        && off.x == 0 && off.y == 0 && off.z == 0)
        return;
    w->e[i].flags |= 0x40;
    off.x = 0;
    off.y = 0;
    off.z = 0;
    func_02015C48(w->e[i].h, (u32 *)(&want));
    func_02015C78(w->e[i].h, (u32 *)(&off));
    func_02015EA0(w->e[i].h);
}


/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 *   0220055C..022005C2). Every concrete byte matches (MATCH*, the extent's 2 extra bytes
 *   are the pad); only the final bl relocation stays wildcarded.
 *   Verified C (match.py one, --thumb, no --region, dsi/1.1p1 -O4,p), EXACT, 28 bytes:
 *
 *     typedef struct { char pad[0x140]; unsigned int lo : 30; unsigned int f : 1;
 *                      unsigned int hi : 1; } S;
 *     void func_02016394(S *s, int f)        // 0x02016394
 *     {
 *         s->f = f;
 *     }
 *
 * lever: each arm of the result switch writes `f = 1` out in its own inner switch
 *   (`switch (key) { case 3: case 4: f = 1; break; }`), so the case-1 copy is
 *   cross-jumped into a `b` after threading and the key == 3 beq keeps pointing at it
 *   (a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.md); a
 *   shared `set:` label lets the beq be threaded straight to `f = 1` (2 bytes out), and
 *   `key == 3 || key == 4` folds to a range test.
 */
void func_0220055C(Work_0220055C *w, int key, int mode)
{
    int f = 0;
    int i;

    i = func_022019F4((char *)w, key);
    if (i == -1)
        return;
    if (w->e[i].h == 0)
        return;
    if (mode == 1) {
        switch (func_021F8710()) {
        case 0:
        case 3:
            break;
        case 1:
            switch (key) {
            case 3:
            case 4:
                f = 1;
                break;
            }
            break;
        case 2:
            switch (key) {
            case 2:
            case 5:
            case 6:
                f = 1;
                break;
            }
            break;
        }
    }
    func_02016394(w->e[i].h, f);
}


int func_022005C4(Work_022005C4 *w, int key)
{
    int i = func_022019F4((char *)w, key);
    int r;

    if (i == -1)
        return 0;
    if (w->e[i].h == 0)
        return 0;
    if (w->e[i].f9)
        r = 1;
    else
        r = 0;
    w->e[i].f9 = 0;
    return r;
}
