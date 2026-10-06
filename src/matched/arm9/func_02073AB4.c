/*
 * function: func_02073AB4
 * address:  0x02073AB4
 * packet:   pkt_02073AB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0014 PC24 func_02073B3C           -> unresolved: 02073B3C (arm, from header) has no witness outside 02073AB4..02073AD0
 *
 * symbols:
 *   func_02073B3C    0x02073B3C  arm
 *
 * Guards the call on bit 0 of the flags word at +0x2C, which the original reads
 * as a signed one-bit field (lsl #31 / asrs #31).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02073AB4.c \
 *       --func func_02073AB4 --addr 0x02073AB4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef struct {
    u32 unk00[0xb];
    int unk2c : 1;
} Obj02073AB4;

struct Obj;
extern void func_02073B3C(struct Obj *o);

void func_02073AB4(Obj02073AB4 *p)
{
    if (p->unk2c != 0) {
        func_02073B3C((struct Obj *)p);
    }
}
