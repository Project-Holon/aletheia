/*
 * function: func_021BC610
 * address:  0x021BC610
 * packet:   pkt_ov093_021BC610
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-05 (wave P4 lane S1, pengy share): DIFF, 600 B vs 612 B, 254 B differ.
 * Structure now matches: both loops, the 9-way switch on the kind (cases 1, 5, 7
 * written as separate r5 = 0 copies give the three b stubs), the shared
 * func_021B9BF0 tail (case 3 does its call then goto inc, the label sits after the
 * default arm's call), the lock lines (0x678 - 0x38, 0x678, 0x68A, 0x68A + 3), the
 * word-c bitfield and spill slots. Residue: in the first loop the original has q in
 * r6 and the r5 counter in r5, the compile has them swapped (every declaration
 * order, block scope, opt_lifetimes off tried); as a consequence the second loop
 * keeps l*16 in r1 instead of r6 and merges the second e[l].b.kind test into the first.
 * Tried and worse: raw byte-offset second read (620 B), ternary argument (q spilled),
 * a local arg x (cnt moves to r6).
 *
 * 2026-10-05 (wave P4 lane S1b): DIFF, 612 B (size now equals the original), 18 B differ.
 * Only residue: first loop, q is r5 and the counter r6 (original q r6, counter r5).
 * New: the second e[l].b.kind read of the original is a real reload; it comes out
 * when the second read goes through a second 16-byte struct view E2 ((E2 *)e)[l]
 * (4 other spellings merge: element pointer, inline helper, copy of b, switch).
 * E2 is a duplicate struct type: integrator decides if that is a human form or a
 * stand-in. Also the final or-chain written (k & m) | ((m + 1) | (sub part | slot part)).
 * Pragmas (all six, on the 612 B draft): none closes the colour swap; opt_lifetimes off
 * gives 152 B differ at 620 B, scheduling off and peephole off change nothing.
 * Tried and no change: slot as one function-level variable shared by both loops
 * (262 B), slot declared before q (533 B), q held as u32 (same).
 *
 * symbols:
 *   func_021BB85C  0x021BB85C  thumb  ov093
 *   func_021BB8A8  0x021BB8A8  thumb  ov093
 *   func_021BB8B0  0x021BB8B0  thumb  ov093
 *   func_021D83E0  0x021D83E0  thumb  ov093
 *   func_021D8454  0x021D8454  thumb  ov093
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021BC8EC  0x021BC8EC  thumb  ov093
 *   func_021BC948  0x021BC948  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021BC874  0x021BC874  thumb  ov093
 *   func_021C6350  0x021C6350  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 rest : 9; } B;
typedef struct { u32 lo : 13; u32 f : 3; u32 g : 6; u32 h : 3; u32 rest : 7; } C;
typedef struct { u8 *a; B b; u32 c; u8 d; u8 e; u8 f; } E;
typedef struct { u32 x; void *m; } Q;
typedef struct { u8 *a; B b; u32 c; u8 d; u8 e; u8 f; } E2;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[6]; } S;

extern Q *func_021BB85C(u32 p, u8 i);
extern u8 func_021BB8A8(u8 *p, u8 i);
extern B func_021BB8B0(u8 *p, u8 i, u8 j);
extern int func_021D83E0(B *p);
extern u32 func_021D8454(B *p);
extern u8 func_021B9AB0(u8 k);
extern u8 *func_021B9BF0(void *m, u8 i);
extern void *func_021B86B8(void *p);
extern int func_021BC8EC(u8 *p, u32 x, u8 *a);
extern u16 func_021BC948(u8 *p, u8 *x, int flag);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021CC95C(void *lock, u32 v, int line);
extern void func_021BC874(E *e, u32 n);
extern u8 func_021C6350(u8 *p, u8 *a);

u8 func_021BC610(S *p, u8 *o, E *e)
{
    u8 cnt;
    u32 k;
    u8 *a;
    u32 lock;
    u8 i;
    u8 j;
    u8 n;
    u32 flag;
    u8 l;
    Q *q;
    E *r;

    flag = 0;
    for (i = 0, cnt = 0; i < 4; i++) {
        q = func_021BB85C(*(u32 *)p, i);
        if (q != 0) {
            n = func_021BB8A8(o, i);
            u8 r5 = 0;
            for (j = 0; j < n; j++) {
                r = &e[cnt];
                u32 t;
                r->b = func_021BB8B0(o, i, j);
                if (func_021D83E0(&r->b) != 0)
                    break;
                t = func_021D8454(&r->b) & 0xff;
                switch (t) {
                case 6:
                    r5 = func_021B9AB0(r->b.sub);
                    r->a = func_021B9BF0(q->m, r5);
                    flag = 1;
                    break;
                case 3:
                    r->a = func_021B9BF0(q->m, r->b.sub);
                    goto inc;
                default:
                    r->a = func_021B9BF0(q->m, r5);
                inc:
                    r5++;
                    break;
                }
                r->d = i;
                r->e = 0;
                r->f = 0;
                cnt++;
            }
        }
    }
    for (l = 0; l < cnt; l++) {
        u32 m = 0x1FFF;
        u8 r5;
        u32 sub;
        lock = func_021CC8D8((u8 *)p + 0x1d74, 0x678 - 0x38);
        r = &e[l];
        a = e[l].a;
        switch (r->b.kind) {
        case 4:
            if (func_021B86B8(*(void **)((u8 *)p + 4)) == 0 && r->d == 1) {
                r5 = 0;
            } else {
                r5 = 4;
            }
            break;
        case 3:
            r5 = 3;
            break;
        case 2:
            r5 = 2;
            break;
        case 6:
            r5 = 1;
            break;
        case 7:
            r5 = 0;
            break;
        case 5:
            r5 = 0;
            break;
        case 1:
            r5 = 0;
            break;
        case 0:
            *(u32 *)&r->c = 0x01002000;
            continue;
        case 8:
            continue;
        default:
            r5 = 0;
            break;
        }
        if (r->b.kind == 1) {
            u16 id;
            if (((E2 *)e)[l].b.kind == 1)
                id = ((E2 *)e)[l].b.id;
            else
                id = 0;
            sub = func_021BC8EC((u8 *)p, id, a);
        } else if (r->b.kind == 5 || r->b.kind == 7) {
            sub = 7;
        } else {
            sub = 0;
        }
        k = func_021BC948((u8 *)p, a, 1);
        func_021CC95C((u8 *)p + 0x1d74, lock, 0x678);
        r->c = (k & m) | ((m + 1) | (((sub & 0x3f) << 16) | ((r5 & 7) << 22)));
    }
    func_021BC874(e, cnt);
    if (flag == 0) {
        for (i = 0; i < cnt; i++) {
            r = &e[i];
            if (r->b.kind == 1 || r->b.kind == 5) {
                u32 lock = func_021CC8D8((u8 *)p + 0x1d74, 0x68A);
                u32 v = func_021C6350((u8 *)p, r->a);
                r->c = (r->c & 0xFFFF1FFF) | ((v & 7) << 13);
                func_021CC95C((u8 *)p + 0x1d74, lock, 0x68A + 3);
            }
        }
        func_021BC874(e, cnt);
    }
    return cnt;
}
