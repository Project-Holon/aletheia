/*
 * function: func_0202F9F8
 * address:  0x0202F9F8
 * packet:   pkt_0202F9F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note:     re-verified 2026-09-21 (time_icon.c family wave): DIFF, 168 bytes compiled
 *           against the listing's 188-byte extent, 115 concrete bytes out.
 *
 * HEADER CORRECTION.  The prose block below says "PARKED AT MATCH.  Every concrete
 * byte is right".  That is NOT true of this file as it stands and has not been true
 * since at least 2026-09-20, when the status line was already set to DIFF.  The two
 * disagreed; the status line is the correct one and the prose is stale.  The real
 * residue is structural, not evidential: the compiled switch arms are in a different
 * order from the original's and one arm is missing the `movs r0, #0xb3` argument, so
 * the body is 20 bytes short.  The three unattested ABS32 sites described below are
 * real and would still cap the file, but they are the SECOND problem, not the first.
 * Fixing the arm order and the missing argument comes before any evidence work.
 *
 * Audio-state step: dispatch on the byte-pair state word the caller points
 * at and run one transition per arm, storing the next state through the same
 * pointer.  The dense switch runs from case 0 to case 4.
 *
 * PARKED AT MATCH.  Every concrete byte is right; three of the five ABS32
 * sites stay wildcarded because the addresses they name -- the state record
 * at 0x02146948/0x0214694C and the overlay-resident worker 0x021BD8E8 --
 * appear in no pool and carry no label anywhere else in the image, so
 * neither `literal` nor `label` reaches them and `data`/`string` refuse
 * them as well.  The other two pool words (0x021B68D8, 0x021BD574) resolve
 * on `label` as Thumb overlay code, and the call to func_020312CC resolves
 * on `label` x1.
 *
 * symbols:
 *   g_State         0x02146948  data
 *   g_State4        0x0214694C  data
 *   func_020312CC   0x020312CC  arm
 *   func_021BD8E8   0x021BD8E8  thumb
 *   func_021B68D8   0x021B68D8  thumb
 *   func_021BD574   0x021BD574  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202F9F8.c \
 *       --func func_0202F9F8 --addr 0x0202F9F8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct State {
    u16 f00;
    u8  f02;
    u8  f03;
    u32 f04;
};

extern struct State g_State;
extern char g_State4[];
extern void func_020312CC(u32 a, void *b, void *c);
extern void func_021BD8E8(void);
extern void func_021B68D8(void);
extern void func_021BD574(void);

int func_0202F9F8(void *unused, u32 *state)
{
    switch (*state) {
    case 0:
        func_020312CC(0x58, func_021BD8E8, g_State4);
        *state = 1;
        break;
    case 1:
        g_State.f00 = 0;
        g_State.f02 = 1;
        g_State.f03 = 0;
        g_State.f04 = 1;
        func_020312CC(0xB3, &g_State, func_021BD574);
        *state = 2;
        break;
    case 2:
        if (g_State.f03 != 0) {
            *state = 4;
            break;
        }
        g_State.f00 = 1;
        g_State.f03 = 0;
        func_020312CC(0xB3, func_021B68D8, func_021BD574);
        *state = 3;
        break;
    case 3:
        g_State.f00 = 2;
        g_State.f03 = 0;
        func_020312CC(0xB3, &g_State, func_021BD574);
        *state = 4;
        break;
    case 4:
        func_020312CC(0x58, func_021BD574, 0);
        *state = 0;
        break;
    }
    return 0;
}
