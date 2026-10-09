/*
 * file:     btl_server_p09.c
 * unit:     yes
 * function: func_021BCB14, func_021BCB68, func_021BCB98, func_021BCC50, func_021BCCE0
 * address:  0x021BCB14
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BCAAC  0x021BCAAC  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C859C 0x021C859C thumb ov093
 *   func_021BCEEC 0x021BCEEC thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021B86E4 0x021B86E4 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021C0780 0x021C0780 thumb ov093
 *   func_021BCEFC 0x021BCEFC thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021BC418 0x021BC418 thumb ov093
 *   func_021BC568 0x021BC568 thumb ov093
 *   func_021BCFAC 0x021BCFAC thumb ov093
 *   func_021BDE98 0x021BDE98 thumb ov093
 *   func_021CB730 0x021CB730 thumb ov093
 *   func_021BD708 0x021BD708 thumb ov093
 *   func_021BDC98 0x021BDC98 thumb ov093
 *   func_021BDA00 0x021BDA00 thumb ov093
 *   func_021BD584 0x021BD584 thumb ov093
 *   func_021BD3E8 0x021BD3E8 thumb ov093
 *   func_021C54BC 0x021C54BC thumb ov093
 *   func_021C60EC 0x021C60EC thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021BCF70 0x021BCF70 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C85B8 0x021C85B8 thumb ov093
 */
#include "../../matched/include/Obj00309.h"

struct Unk021D62A8;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u8 *a; u32 b, c; u8 d0; u8 flag; u16 pad; } E;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S;

typedef struct { u32 a; u32 b, c; u8 d0; u8 flag; u16 pad; } E_021BCB68;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E_021BCB68 e[4]; } S_021BCB68;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E_021BCB68 e[6]; E_021BCB68 t; } S_021BCB98;

typedef union {
    struct { u32 type:4, select:3, move:16, arg:8, rest:1; } full;
    struct { u32 type:4, select:3, move:3, rest:22; } small;
} Action;

typedef struct { u8 *a; Action b; u32 c; u8 d, processed; u16 pad; } E_021BCCE0;

extern E *func_021BCAAC(S *p, u8 x, u32 i);
extern u8 func_021D5440(u8 *p);
extern int func_021B9A24(u32 a, u32 b);
extern int func_021D5B68(void *m);
extern void func_021C859C(u8 *);
extern int func_021BCEEC(void *, u8);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021B86E4(unsigned int **p);
extern u8 func_021D69AC(u8 *, int);
extern void func_021C0780(u8 *, u8 *, int, u8);
extern void func_021BCEFC(u8 *, u8 *, u32);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern u32 func_021B8588(void **p);
extern void func_021BC418(u8 *, int, int);
extern void func_021BC568(u8 *);
extern int func_021BCFAC(u8 *, u8 *);
extern void func_021BDE98(u8 *, u8 *, Action *, u32);
extern int func_021CB730(u8 *, u8 *, u16, u8, u8);
extern int func_021BD708(u8 *, u8 *, int, int);
extern void func_021BDC98(u8 *p, u8 *a, u8 v);
extern int func_021BDA00(u8 *);
extern int func_021BD584(u8 *, u8 *);
extern void func_021BD3E8(u8 *, u8 *);
extern void func_021C54BC(u8 *, u8 *);
extern void func_021C60EC(u8 *p, u8 *a, u32 n);
extern u32 func_021CC8D8(void *, int);
extern void func_021BCF70(u8 *, u8 *, u32);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C85B8(u8 *);
E *func_021BCB14(S *p, u8 x, u32 y);
int func_021BCB68(S_021BCB68 *p, E_021BCB68 *cur);
int func_021BCB98(S_021BCB98 *p, E_021BCB68 *cur, int start);
void func_021BCC50(S_021BCB98 *p, E_021BCB68 *cur);
u32 func_021BCCE0(u8 *p, E_021BCCE0 *e);


E *func_021BCB14(S *p, u8 x, u32 y)
{
    E *e = func_021BCAAC(p, x, 0);
    while (e) {
        if (func_021B9A24(y, func_021D5440(e->a)) && func_021D5B68(e->a) == 0)
            return e;
        e = func_021BCAAC(p, x, (u8)(func_021BCB68((S_021BCB68 *)p, (E_021BCB68 *)e) + 1));
    }
    return 0;
}




/*
 * unlabelled leaf (push {r3, r4}); filed as the blocker of func_021BCB14.
 */
int func_021BCB68(S_021BCB68 *p, E_021BCB68 *cur)
{
    int i;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (&p->e[i] == cur)
            return (u8)i;
    }
    return n;
}





int func_021BCB98(S_021BCB98 *p, E_021BCB68 *cur, int start)
{
    int a = -1;
    int b = -1;
    int i;
    int n = p->n;
    for (i = start; i < n; i++) {
        if (&p->e[i] == cur) {
            a = i;
            break;
        }
    }
    for (; start < n; start++) {
        if (p->e[start].flag == 0) {
            b = start;
            break;
        }
    }
    if (a >= 0 && b >= 0 && a > b) {
        p->t = *cur;
        for (i = a; i > b; i--)
            p->e[i] = p->e[i - 1];
        p->e[b] = p->t;
        return b;
    }
    return -1;
}





void func_021BCC50(S_021BCB98 *p, E_021BCB68 *cur)
{
    int i;
    int idx = -1;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (&p->e[i] == cur) {
            idx = i;
            break;
        }
    }
    if (idx < 0)
        return;
    p->t = *cur;
    for (i = idx; i < p->n - 1; i++)
        p->e[i] = p->e[i + 1];
    p->e[i] = p->t;
}



/*
 * interface: CC8D8's own matched source returns one-word struct Lock;
 *   this caller treats all r0 bits as a raw u32, copies r0 to r6 at 021BCEA4,
 *   and forwards r6 unchanged in r1 at 021BCEB6 to CC95C (str r1,[r0]).
 *   CC8D8 returns the entire pre-mutation 32-bit word. No bit is interpreted,
 *   narrowed or changed; both line arguments and all arities are preserved.
 *   Matched BD708 uses this same scalar interface. Struct diagnostic run03
 *   adds 8 frame bytes; byte score is not the payload/effect equivalence proof.
 * lever: Union views preserve bits7..22 for the full move field and bits7..9
 *   for case3; arg is bits23..30. Wrapping arithmetic is never signed.
 * semantics: Packed word widths derive from listing shift pairs; all fields
 *   unsigned, no signed arithmetic or asserted external selector bounds.
 */
u32 func_021BCCE0(u8 *p, E_021BCCE0 *e)
{
    u8 *a;
    Action b;
    u32 lock;
    if (e->processed == 0) {
        a = e->a;
        b = e->b;
        func_021C859C(p);
        e->processed = 1;
        if (((struct Obj00309 *)p)->f14 == 5 && b.full.type != 4) goto end;
        if (func_021D5B68(a) != 0) goto end;
        if (b.full.type != 6 && func_021BCEEC(p + 0x1ab8, func_021D5440(a)) == 0) goto end;
        if (func_021D62C4((struct Unk021D62A8 *)a, 0x21) != 0) {
            if (b.full.type != 4 || func_021B86E4((unsigned int **)(*(u8 * *)&((struct Obj00309 *)p)->f4)) != 2) {
                if (func_021D69AC(a, 3) != 0) func_021C0780(p, a, 3, 0);
                goto end;
            }
        }
        func_021BCEFC(p, a, e->b.full.type);
        func_021D5FC0((struct UtilWork *)a, 0);
        switch (b.full.type) {
        case 6:
            if (func_021B8588(((struct Obj00309 *)p)->f4) == 3) func_021BC418(p, e->d, (u8)b.full.select);
            break;
        case 1:
            if (p[0x1fe8] == 0) {
                func_021BC568(p);
                p[0x1fe8] = 1;
            }
            ((struct Obj00309 *)p)->f1F78 = func_021BCFAC(p, a);
            func_021BDE98(p, a, &b, e->c & 0x3fffff);
            break;
        case 2:
            if (func_021CB730(p, a, (u16)b.full.move, (u8)b.full.arg, (u8)b.full.select) == 1) {
                if (func_021BD708(p, a, 1, 1)) ((struct Obj00309 *)p)->f14 = 5;
            }
            break;
        case 3:
            func_021BDC98(p, a, (u8)b.small.move);
            func_021BDA00(p);
            break;
        case 4:
            if (func_021BD584(p, a)) ((struct Obj00309 *)p)->f14 = 5;
            break;
        case 8:
            ((struct Obj00309 *)p)->f14 = 4;
            break;
        case 5:
            func_021BD3E8(p, a);
            break;
        case 7:
            func_021C54BC(p, a);
            break;
        case 0:
        default:
            break;
        }
        if (b.full.type == 1 || b.full.type == 2) {
            func_021D5FC0((struct UtilWork *)a, 1);
            func_021C60EC(p, a, 0);
        }
        lock = func_021CC8D8(p + 0x1d74, 0x83b);
        func_021BCF70(p, a, b.full.type);
        func_021CC95C((u32 *)(p + 0x1d74), lock, 0x83d);
    end:
        func_021C85B8(p);
        return b.full.type;
    }
    return 0;
}
