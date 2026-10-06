/*
 * file:     zonedata_p17.c
 * unit:     yes
 * function: func_02014698, func_020146F8, func_02014728, func_02014758, func_020147B0, func_02014808, func_02014840, func_02014878
 * address:  0x02014698
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
 *   func_020144DC  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02014628  0x02014628  thumb
 *   ov091_id        0x0000005B  data
 *   ov131_id        0x00000083  data
 *   g_021BED00      0x021BED00  data
 *   g_021DC800      0x021DC800  data
 */
struct Ctx;
struct IcaAnime;
struct Evt;
struct Desc;
struct Obj;
typedef unsigned int u32;

typedef struct {
    int   f00;
    int   f04;
    int   f08;
    int   f0c;
    int   f10;
    void (*f14)(void *);
    void *f18;
} S;

typedef unsigned char u8;

extern int func_020144DC(int a0, int a1);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern void *func_020145CC(void *a0);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02014628(void *obj, u32 *mode, u32 *p);
extern u32 func_020307B0(void *p);
u32 func_02014698(void *obj, u32 *mode, u32 *args);
void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
void *func_02014728(char *a0, int a1, int a2, int a3, int a4);
int func_02014758(int a0, int *a1, S *a2);
int func_020147B0(int a0, int *a1, S *a2);
void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
u32 func_02014878(u32 a0, u32 *mode, u32 *p);
extern u8   ov091_id[];
extern u8   ov131_id[];


/*
 * The step function func_02014728 installs (argsize 0x14, args p[0]..p[4]),
 * one stage per call on *mode.  Closed in wave 13: the earlier goto/label
 * spelling (docs/notes/func_02014698.c.txt, one byte out) was the wrong
 * shape.  Written plainly -- every arm carries its own `(*mode)++; break;`
 * and case 2 is `if (poll() == 0) (*mode)++;` -- the compiler cross-jumps
 * the repeated increments itself, and that leaves case 2's tail jump on
 * case 1's `b inc` block exactly as the image has it.
 */
u32 func_02014698(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[0];

    switch (*mode) {
    case 0:
        func_02012374(obj, (struct Evt **)func_020144DC(a0, args[1]));
        (*mode)++;
        break;
    case 1:
        func_020120B4((struct IcaAnime *)a0, args[2], (void *)args[3], (void *)args[4]);
        (*mode)++;
        break;
    case 2:
        if (func_020120F0((const struct Ctx *)a0) == 0) {
            (*mode)++;
        }
        break;
    case 3:
        func_02012374(obj, func_020145CC((void *)a0));
        (*mode)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}


void *func_020146F8(char *a0, int a1, int a2, int a3, int a4)
{
    void *r = func_020122C0(a0, 0, (void *)((int)func_02014628), 0x14);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a4;
    return r;
}


void *func_02014728(char *a0, int a1, int a2, int a3, int a4)
{
    void *r = func_020122C0(a0, 0, (void *)((int)func_02014698), 0x14);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a4;
    return r;
}


/*
 * A three-state step machine over a descriptor `a2`.  State 0 forwards five
 * of the descriptor's leading words (four in registers, the fifth on the
 * stack) to func_020146F8 and hands the result to func_02012374, then bumps
 * the counter.  State 1 calls the descriptor's own callback slot (+0x14) with
 * the pointer at +0x18.  State 2 frees the +0x18 pointer and returns 1.  The
 * `*a1 = *a1 + 1` in state 1 is a separate arm in the source; the compiler
 * cross-jumps it onto state 0's increment, which is why the listing shows the
 * state-1 arm branching backwards into state 0's tail.
 *
 * EXACT*: the compared extent runs four bytes past the body into the next
 * function's alignment pad (the follower at 0x020147B0 saves lr, so its label
 * exists and the extent is only the pad - no byte of it differs).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014758.c \
 *       --func func_02014758 --addr 0x02014758 --cc 1.1p1 --thumb
 */
int func_02014758(int a0, int *a1, S *a2)
{
    switch (*a1) {
    case 0:
        func_02012374((struct Evt *)a0, func_020146F8((char *)a2->f00, a2->f04, a2->f08, a2->f0c,
                                        a2->f10));
        *a1 = *a1 + 1;
        break;
    case 1:
        if (a2->f14 != 0) {
            a2->f14(a2->f18);
        }
        *a1 = *a1 + 1;
        break;
    case 2:
        if (a2->f18 != 0) {
            func_020307B0(a2->f18);
        }
        return 1;
    }
    return 0;
}


/*
 * Byte-for-byte the twin of func_02014758 (same 86-byte shape, same three
 * states) with func_020146F8 replaced by func_02014728.  The only other
 * difference is the literal pool holding 0x020307B0: 0x02014758's pool is
 * reachable with `blx 0x20307b0`'s 26-bit reach, this one needs no change.
 *
 * EXACT*: the compared extent runs into the four-byte alignment pad before
 * the next labelled function; no byte of the body differs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020147B0.c \
 *       --func func_020147B0 --addr 0x020147B0 --cc 1.1p1 --thumb
 */
int func_020147B0(int a0, int *a1, S *a2)
{
    switch (*a1) {
    case 0:
        func_02012374((struct Evt *)a0, func_02014728((char *)a2->f00, a2->f04, a2->f08, a2->f0c,
                                        a2->f10));
        *a1 = *a1 + 1;
        break;
    case 1:
        if (a2->f14 != 0) {
            a2->f14(a2->f18);
        }
        *a1 = *a1 + 1;
        break;
    case 2:
        if (a2->f18 != 0) {
            func_020307B0(a2->f18);
        }
        return 1;
    }
    return 0;
}


/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT.
 */
void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    void *r = func_020122C0(a0, 0, (void *)((int)func_02014758), 0x1c);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a4;
    p[5] = a5;
    p[6] = a6;
    return r;
}


/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT.
 */
void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    void *r = func_020122C0(a0, 0, (void *)((int)func_020147B0), 0x1c);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a4;
    p[5] = a5;
    p[6] = a6;
    return r;
}


/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov091_id (91) and ov131_id (131) resolve as `overlay_id` (a
 *           layout overlay index, loaded by a pc-relative load of this
 *           function, reaching the id register of a known overlay loader),
 *           which was the last blocker.
 *
 * A six-state machine on obj->f1e.  Every concrete byte matches: 152 of 152
 * against the listing extent, the two relocation sites that are attestable
 * (both calls) resolve as `label`, and both 0x021BED00/0x021DC800 pool words
 * resolve as `literal`; only the two small pooled words stay wildcarded.
 *
 * The small pooled words are the SDK's FS_OVERLAY_ID() shape (see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): a
 * value that mwccarm materialises with `movs` for any literal in 0..255, and
 * therefore cannot be written as a number - the source passes an address the
 * linker resolved to 91 / 131, and is declared here as a symbol of that
 * absolute value.
 *
 * Two levers mattered, both from the wave-r6 list:
 *   * the switch value is read once into a local before the dispatch
 *     (`ldr r1, [r4]` before `cmp r1, #5`), which is what puts p[0] in r0;
 *   * a case that ends in "return 0" must `break` instead, so every arm
 *     shares the one epilogue at 0x020148FC instead of duplicating it.
 * The state-2 arm is three statements - `if (v == 0) { *mode = 5; break; }`,
 * `if (v == 1) { ...; *mode = 3; break; }` and a trailing `*mode = 5;` - and
 * only that spelling reproduces the arm's out-of-line `movs r0, #5` block at
 * 0x020148D2 with the second test as `bne` rather than `beq`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014878.c \
 *       --func func_02014878 --addr 0x02014878 --cc 1.1p1 --thumb
 */
u32 func_02014878(u32 a0, u32 *mode, u32 *p)
{
    u32 v = p[0];

    switch (*mode) {
    case 0:
        func_020120B4((struct IcaAnime *)v, (u32)ov091_id, (void *)0x021BED00, (void *)p[2]);
        *mode = 1;
        break;
    case 1:
        if (func_020120F0((const struct Ctx *)v) != 0)
            break;
        *mode = 2;
        break;
    case 2:
        if (*(u32 *)(p[2] + 0x40) == 0) {
            *mode = 5;
            break;
        }
        if (*(u32 *)(p[2] + 0x40) == 1) {
            *(u8 *)(p[3] + 0xf) = (u8)*(u32 *)(p[2] + 0x3c);
            *mode = 3;
            break;
        }
        *mode = 5;
        break;
    case 3:
        func_020120B4((struct IcaAnime *)v, (u32)ov131_id, (void *)0x021DC800, (void *)p[3]);
        *mode = 4;
        break;
    case 4:
        if (func_020120F0((const struct Ctx *)v) != 0)
            break;
        *(u32 *)(p[2] + 0x3c) = *(u8 *)(p[3] + 0xf);
        *mode = 0;
        break;
    case 5:
        return 1;
    default:
        break;
    }
    return 0;
}
