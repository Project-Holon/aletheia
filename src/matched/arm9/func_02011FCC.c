/*
 * function: func_02011FCC
 * address:  0x02011FCC
 * packet:   pkt_02011FB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct, MATCH-capped: all 144 concrete bytes reproduce, the four
 * remaining wildcards are call sites whose targets live in OTHER PACKETS and
 * have no witness outside this range:
 *
 *   +0034  bl func_02012380   -> pkt_02012380
 *   +003A  bl func_0202627C   -> pkt_0202627C
 *   +0052  bl func_0202B500   -> pkt_0202B500
 *   +0058  bl func_02021464   -> pkt_02021464
 *
 * Each reports `no witness outside 02011FCC..02012060`, i.e. the only branch
 * anywhere in the image reaching them is the call in this function, so the
 * `label` class cannot attest them and no cut frees them.  Blocking class:
 * label.  Nothing in this C changes when those packets are filed -- the file
 * graduates for free.
 *
 * Two spellings this function pinned down:
 *
 *  - The last guard is ONE conjunction, `a == 0 && b == 0 -> return 1`.  The
 *    equivalent disjunction (`a != 0 || b != 0 -> return 0`) makes mwcc pick
 *    the other arm as the fall-through and comes out four bytes of wrong
 *    layout: `bne #0x2012054` + `beq` + the two `movs r0` swapped, where the
 *    original branches BOTH tests to a shared out-of-line `movs r0,#0; pop`
 *    and falls through to `movs r0,#1`.
 *  - The state word at +0x0c is re-read from memory at each use rather than
 *    cached in a register, so it is spelled as the field every time.
 *
 * symbols:
 *   func_020120A4  0x020120A4  thumb
 *   func_02012A24  0x02012A24  thumb
 *   func_02035614  0x02035614  arm
 *   func_020129FC  0x020129FC  thumb
 *   func_020123D8  0x020123D8  thumb
 *   func_0201205C  0x0201205C  thumb
 *   func_02012380  0x02012380  thumb
 *   func_0202627C  0x0202627C  thumb
 *   func_02031330  0x02031330  arm
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A14  0x02028A14  thumb
 *   func_0202B500  0x0202B500  thumb
 *   func_02021464  0x02021464  thumb
 *   func_0200F7B8  0x0200F7B8  thumb
 */

extern void func_020120A4(char *p);
extern int func_02012A24(int h);
extern void func_02035614(int v);
extern int func_020129FC(int h);
extern void func_020123D8(char *p, int a, int b);
extern void func_0201205C(char *p);
struct T;
extern int func_02012380(void *p);
extern void func_0202627C(int v);
extern int func_02031330(int v);
extern void *func_02012A30(int h);
extern void func_02028A14(struct T *p);
extern void func_0202B500(int v);
extern void func_02021464(int h);
extern void func_0200F7B8(int v);

int func_02011FCC(char *p)
{
    func_020120A4(p);
    if (func_02012A24(*(int *)(p + 0x1c)) != 0)
        func_02035614(0x1e);
    if (func_020129FC(*(int *)(p + 0x1c)) == 0) {
        func_020123D8(p, *(int *)(p + 0x10), *(int *)(p + 0x14));
        func_0201205C(p);
        func_02012380(p);
        func_0202627C(*(int *)(p + 0x24));
    }
    *(int *)(p + 0xc) = func_02031330(*(int *)(p + 8));
    func_02028A14(func_02012A30(*(int *)(p + 0x1c)));
    func_0202B500(*(int *)(p + 0x2c));
    func_02021464(*(int *)(p + 0x1c));
    if (func_02012A24(*(int *)(p + 0x1c)) != 0)
        func_02035614(0x3c);
    if (*(int *)(p + 0xc) == 2 || *(int *)(p + 0xc) == 0)
        func_0200F7B8(0);
    if (*(int *)(p + 0xc) == 0 && *(int *)(p + 0x18) == 0)
        return 1;
    return 0;
}
