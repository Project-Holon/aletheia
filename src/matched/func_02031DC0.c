/*
 * function: func_02031DC0
 * address:  0x02031DC0
 * packet:   pkt_02031C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   g_02146994    0x02146994  data
 *   func_02031FE0 0x02031FE0  arm
 *   func_02032688 0x02032688  arm
 *
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj02031DC0 {
    u32 f00;
    u32 f04;
    u8  pad08[0x14];
    u8  f1c;
} Obj02031DC0;

extern u32 *g_02146994;

extern int func_02031FE0(Obj02031DC0 *o, u32 a1, u32 flag, u32 a2);
extern int func_02032688(Obj02031DC0 *o, u32 flag, u32 a2);

int func_02031DC0(Obj02031DC0 *a0, u32 a1, u32 a2)
{
    int st;

    if (*g_02146994 == 0)
        return 4;
    if (a0->f00 != a0->f04)
        st = func_02031FE0(a0, a1, 1, a2);
    else
        st = func_02032688(a0, 1, a2);
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
