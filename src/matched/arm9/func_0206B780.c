/*
 * function: NNSi_G3dFuncSbc_NOP
 * address:  0x0206B780
 * packet:   pkt_0206AF08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Calls the callback at +0x0C when it is set, handing it the object itself
 * (which is why the pointer is loaded into r1 and never r0), then bumps the
 * counter at +0x00.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G3dFuncSbc_NOP.c \
 *       --func NNSi_G3dFuncSbc_NOP --addr 0x0206B780 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef struct Obj0206B780 Obj0206B780;
struct Obj0206B780 {
    u32   unk00;
    u32   unk04;
    u32   unk08;
    void (*unk0c)(void *);
};

void NNSi_G3dFuncSbc_NOP(Obj0206B780 *p)
{
    if (p->unk0c != 0) {
        p->unk0c(p);
    }
    p->unk00++;
}
