/*
 * function: func_021B7F38
 * address:  0x021B7F38
 * packet:   pkt_021B7F38
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * BLOCKER: register allocation, ~120 concrete bytes.  The original keeps
 * `p` in r5 and the loop index in r4 across both loops; every spelling
 * tried (int/u16 index, while/do-for, count-up from 0, explicit cursor)
 * makes mwcc place `p` in r4 and the index in r5 instead, which then
 * cascades through both loops.  Length 216 == original 216.  Two ABS32
 * sites (the two 24-byte row tables at 0x021B821C / 0x021B8234) stay
 * wildcarded for lack of an outside witness.
 *
 * note 2026-10-05: new reading closed 86 of 146 differing bytes (60 left, 216 B == 216 B).
 *  (1) the random value n = (u16)func_020056EC(4) is a real spilled local: the last
 *  call takes n + 4 (not i + 4); that gives the [sp] slot and the 0x20 frame.
 *  (2) slot read and store written `*(int *)(p + i * 4 + 0x9048)` share one i*4 and
 *  reload the pool word: first loop now exact.
 *  Residue: n and a swap stack slots (orig n at [sp], a at [sp+4]); in the second loop the
 *  original keeps r6 = i*4 and recomputes p + r6 for the store, ours keeps r6 = p + i*4 with
 *  the 0x9048 pool word in the same register; y in the original is an int (asrs r7 once,
 *  `subs r7,#0x18` with no re-extension) and local.a = a is written in each arm, local.b = y
 *  once after the join. Making y an int flips p/i to r4/r5 and moves y to ip (tried with
 *  and without a in each arm). Not closed.
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   func_021B74B4  0x021B74B4  thumb
 *   func_021B75E8  0x021B75E8  thumb
 *   func_021B75A4  0x021B75A4  thumb
 *   func_021B7488  0x021B7488  thumb
 *   tbl_021B821C   0x021B821C  data  ov180
 *   tbl_021B8234   0x021B8234  data  ov180
 */

typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct S24 {
    u16 a;
    u16 b;
    u32 c;
    int d;
    int e;
    int f;
    u16 g;
    u16 h;
};

extern int func_020056EC(int);
extern int func_021B74B4(char *, int);
extern void func_021B75E8(char *, int);
extern int func_021B75A4(char *, struct S24 *);
extern void func_021B7488(char *, int, u16);
extern struct S24 tbl_021B821C;
extern struct S24 tbl_021B8234;

void func_021B7F38(char *p)
{
    u16 i;
    u16 n;

    for (i = 9; i < 0x21; i++) {
        if (*(int *)(p + i * 4 + 0x9048) != 0) {
            if (func_021B74B4(p, i) != 1)
                func_021B75E8(p, i);
        }
    }

    n = (u16)func_020056EC(4);
    if (n >= 2)
        return;

    for (i = 9; i < 0x21; i++) {
        if (*(int *)(p + i * 4 + 0x9048) == 0) {
            s16 a = (s16)func_020056EC(0x100);
            s16 y = (s16)func_020056EC(0xd8);
            struct S24 local;

            if (y < 0xc0)
                local = tbl_021B821C;
            else {
                local = tbl_021B8234;
                y -= 0x18;
            }
            local.a = a;
            local.b = y;
            *(int *)(p + i * 4 + 0x9048) = func_021B75A4(p, &local);
            func_021B7488(p, i, n + 4);
            return;
        }
    }
}
