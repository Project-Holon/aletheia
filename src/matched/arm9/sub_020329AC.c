/*
 * function: sub_020329AC
 * address:  0x020329AC
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02032A9C  0x02032A9C  arm
 *   func_020332FC  0x020332FC  arm
 *   func_02033BAC  0x02033BAC  arm
 *   func_02033BF0  0x02033BF0  arm
 *   func_02034F84  0x02034F84  arm
 *   func_02034FB8  0x02034FB8  arm
 *
 * savedata.c.  Walks every record of the save table and reports two running
 * totals through the caller's two out-parameters: the nominal size of every
 * record, and the size actually accounted for.  A record 0x020332FC says is
 * not resident is pumped through the seven-argument step function at
 * 0x02032A9C until it stops answering 0, and a step that answers 2 drops
 * that record's contribution to the second total to zero.
 *
 * The four scratch cells the step function writes through are stack locals
 * whose addresses are taken, which is why the frame is 0x24 bytes with the
 * first three outgoing stack arguments at the bottom; per
 * docs/idioms/local-declaration-order-is-stack-order.md the first declared
 * of the four sits highest, at sp+0x20, and the fourth at sp+0x14, matching
 * the order they are passed in.  The fourth is deliberately not initialised:
 * the original zeroes only three of the four.
 *
 * The outer loop is a do/while, not a for: the bound is recomputed by a call
 * at the bottom of every iteration and the compiler has no way to rotate an
 * unknown bound, so the test really is written after the body.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020329AC.c \
 *       --func sub_020329AC --addr 0x020329AC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct SaveBackup {
    u8 pad00[0x2C];
    u32 unk2C;
};

extern u32 func_02032A9C(struct SaveBackup *p, u32 id, u32 mode, u32 *a,
                         u32 *b, u32 *c, u32 *d);
extern u32 func_020332FC(struct SaveBackup *p, u32 id);
struct Obj02033BF0;
extern u32 func_02033BAC(u8 *p, u32 i);
extern u32 func_02033BF0(struct Obj02033BF0 *p);
extern void func_02034F84(u32 bit);
extern void func_02034FB8(u32 bit);

void sub_020329AC(struct SaveBackup *p, u32 *total, u32 *nominal)
{
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 size;
    u32 i;
    u32 r;

    i = 0;
    func_02034F84(1);

    *total = 0;
    *nominal = 0;
    a = 0;
    b = 0;
    c = 0;

    do {
        size = func_02033BAC((u8 *)p->unk2C, i);
        *nominal = *nominal + size;

        if (func_020332FC(p, i) == 0) {
            do {
                r = func_02032A9C(p, i, 1, &a, &b, &c, &d);
                if (r == 2) {
                    size = 0;
                }
            } while (r == 0);
        }

        *total = *total + size;
        i++;
    } while (i < func_02033BF0((struct Obj02033BF0 *)p->unk2C));

    func_02034FB8(1);
}
