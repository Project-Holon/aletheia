/*
 * function: func_021D15F0
 * address:  0x021D15F0
 * packet:   pkt_ov016_021D15F0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      taskMove (libdwcutil.TWL.HYB.a window.o)
 *
 * T6: 184 B vs 192. The object branches on the type test (`cmp r0,#5 /
 * bne / ldr r1,[pc,A] / b / ldr r1,[pc,B]`) while this build if-converts the
 * function-pointer select (`movne r1,...`), and that branch is the missing
 * 8 bytes; the object also keeps the 0 constant in r4 (needed across the
 * GetPosition call) where this build rematerialises immediates. Tried the
 * select as a `void (*fn)(void *)` local via ternary and via if/else in both
 * senses, as `void *` and as `unsigned long` with a cast at the call, as a
 * leading `fn = B` plus one if, as a switch, and with the call duplicated in
 * each arm: every spelling re-folds to 180 B, and no pin/flag cell matches.
 * U26: the object's `mov r4,#0` is the constant 0 held in a callee-saved register across the
 * func_021D5250 call (it is `mov r1,r4` for the idx argument and `mov r0,r4`/`mov r2,r4` for the
 * two zero arguments of func_021D7680).  Spelling that zero as a live local (`int z = 0;`, `z`
 * for all three) is folded straight back to immediate 0 by 1.1p1 - same 184 B / 130 diffs - so
 * the difference is mwcc 4.0.0.1025's rematerialisation policy, not a source shape.  Referencing
 * the same 0 through a helper or a cast does not survive either.
 *
 * symbols:
 *   func_021D5250  0x021D5250  arm  ov016
 *   func_021D1868  0x021D1868  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   func_021D7724  0x021D7724  arm  ov016
 *   func_021D17FC  0x021D17FC  arm  ov016
 *   func_021D16B0  0x021D16B0  arm  ov016
 *   g_021DE658     0x021DE658  data
 *   g_021DAA00     0x021DAA00  data
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    void *cellWin;
    void *cellChar;
    void *button[2];
    void *canv;
    void *task;
    u16 countWait;
    signed char count;
    signed char input;
    u8 type;
    u8 wait;
    u8 dark;
} MemWinT;

extern void func_021D5250(void *cell, int idx, int *x, int *y);
extern void func_021D1868(int y);
extern void *func_021D7680();
extern void func_021D7724();
extern void func_021D17FC(void *task);
extern void func_021D16B0(void *task);
extern MemWinT *g_021DE658;
extern u16 g_021DAA00[][2];

void func_021D15F0(void *task)
{
    int x;
    int y;

    func_021D5250(g_021DE658->cellWin, 0, &x, &y);
    y -= 12;
    if (y > g_021DAA00[g_021DE658->type][0]) {
        func_021D1868(y);
        return;
    }
    func_021D1868(g_021DAA00[g_021DE658->type][0]);
    g_021DE658->task = func_021D7680(0, g_021DE658->type == 5 ? func_021D17FC : func_021D16B0, 0, 0x78);
    func_021D7724(1, task);
}
