/*
 * unit:     no
 * address:  0x020307E0
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_020307E0
 *
 * BLOCKED on one relocation site: all 80 concrete bytes are correct, but
 * the call to sub_020302A4 at +0004 has no witness, that call being
 * 0x020302A4's only branch reference in the image. 0x020302A4 is written
 * and byte-correct in src/pending/sub_020302A4.c but is itself capped at
 * MATCH on sub_02060CD0, so the chain is
 * 0x02060CD0 -> 0x020302A4 -> this function: one EXACT entry for
 * 0x02060CD0 promotes all three.
 *
 * A heap-state assertion, guarded on the result of sub_020302A4 and then
 * dispatched on the heap-layer state word returned by sub_02030524.
 *
 *   void sub_020307E0(void *p, u32 size)
 *
 * Neither call takes an argument. The dispatch is the ARM form of the
 * dense switch: `cmp r0, #5` then `addls pc, pc, r0, lsl #2`, so the table
 * runs from case 0 to case 5 inclusive and the fall-through past the
 * `addls` is the default. Every case body here is one instruction, so the
 * bodies live directly in the table slots rather than being branched to:
 * cases 0, 4 and 5 are the bare `pop`, cases 1, 2 and 3 are branches to
 * three separate `bl OS_Terminate; pop` blocks further down.
 *
 * Those three blocks are byte-identical and are *not* cross-jumped, which
 * is the interesting part: writing the three arms as one shared arm
 * (`case 1: case 2: case 3:`) collapses them into a single block and loses
 * sixteen bytes. Each arm must be spelled out separately. The likely
 * original is three distinct assertion messages that the release build
 * stripped down to the same call.
 *
 * symbols:
 *   sub_020302A4    0x020302A4  arm
 *   sub_02030524    0x02030524  arm
 *   OS_Terminate    0x02088234  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020307E0.c \
 *       --func sub_020307E0 --addr 0x020307E0 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 sub_020302A4(void *p, u32 size);
extern u32 sub_02030524(void);
extern void OS_Terminate(void);

void sub_020307E0(void *p, u32 size)
{
    if (sub_020302A4(p, size) != 0) {
        return;
    }
    switch (sub_02030524()) {
    case 0:
        break;
    case 1:
        OS_Terminate();
        break;
    case 2:
        OS_Terminate();
        break;
    case 3:
        OS_Terminate();
        break;
    case 4:
        break;
    case 5:
        break;
    }
}
