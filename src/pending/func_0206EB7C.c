/*
 * function: func_0206EB7C
 * address:  0x0206EB7C
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  no evidence class for the PC24 to func_0206EE60 at +0x34: the only
 *           branch anywhere in the image to 0x0206EE60 is this one, so
 *           `label` refuses it and nothing else attests it. Filing 0x0206EE60
 *           (940 B, still OPEN in this packet) as EXACT promotes this file to
 *           EXACT with no change to the C. --suggest-split offers nothing:
 *           single function, the one site's only witness is inside the range.
 *
 * symbols:
 *   func_0206EE60    0x0206EE60  arm
 *
 * Clamps a 20.12 fixed-point cursor into [0, (count<<12)-1] and forwards.
 *
 * Shape note that cost the previous two passes: the callee takes FOUR
 * arguments and the caller's own first argument is the FOURTH, not the first
 * (the image's `mov r3, r0` at 0x0206EB80 is that argument being parked in
 * r3 before r0 is reloaded with the table pointer). Written as a three-
 * argument forward of r0 the compiler lands at 56 bytes against 60.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206EB7C.c \
 *       --func func_0206EB7C --addr 0x0206EB7C --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef signed int s32;

typedef struct { u32 unk00; u32 unk04; u32 *p08; } Cur;

extern void func_0206EE60(u32 *tab, u32 b, s32 c, void *a);

void func_0206EB7C(void *a, Cur *c, u32 b)
{
    s32 t;
    s32 lim;
    u32 *tab;

    tab = c->p08;
    lim = (s32)((u32)((u16 *)tab)[2] << 12);
    t = (s32)c->unk00;
    if (t >= lim) {
        t = lim - 1;
    } else if (t < 0) {
        t = 0;
    }
    func_0206EE60(tab, b, t, a);
}
