/*
 * function: func_0204FFFC
 * address:  0x0204FFFC
 * packet:   pkt_0204FFFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0204F5A8  0x0204F5A8  arm
 *   func_0204ED24  0x0204ED24  arm
 *   func_02033C9C  0x02033C9C  arm
 *   func_020307B0  0x020307B0  arm
 *
 * billboard_act.c teardown.  The two-byte residue of the earlier notes
 * (the loaded entry word landing in r0 instead of r1) was the callee's
 * arity: func_0204F5A8 takes TWO arguments, and the second is the entry's
 * first word, which the image loads straight into r1 for the compare and
 * then passes on.  EXACT* because the unlabelled 8-byte getter at
 * 0x02050080 (`ldr r0,[r0,#4]; bx lr`, blx'd from ov021) follows the pool.
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct BbActEntry {
    u32 f00;
    u32 rest[9];
};

struct BbActSys {
    u16 f00;
    u16 f02;
    void *f04;
    u32 f08;
    void *f0C;
    u16 f10;
    u16 f12;
    void *f14;
    struct BbActEntry *f18;
    u16 f1C;
    u16 f1E;
    void *f20;
};

extern void func_0204F5A8(void *board, u32 idx);
extern void func_0204ED24(void *board);
extern u32 func_02033C9C(void *a);
extern u32 func_020307B0(void *p);

void func_0204FFFC(struct BbActSys *o)
{
    int i;

    for (i = 0; i < o->f1C; i++) {
        if (o->f18[i].f00 != 0xFFFF) {
            func_0204F5A8(o->f04, o->f18[i].f00);
        }
    }
    func_02033C9C(o->f20);
    func_020307B0(o->f18);
    func_02033C9C(o->f14);
    func_020307B0(o->f0C);
    func_0204ED24(o->f04);
    func_020307B0(o);
}

