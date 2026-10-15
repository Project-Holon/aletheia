/*
 * function: GAMESYSTEM_RegisterSleepCheck
 * address:  0x020122A4
 * packet:   pkt_020122A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UI_SetKeepAwakePred  0x02035064  arm
 *   GAMESYSTEM_IsSleepBlocked  0x02012264  thumb
 *
 * Two instructions and a two word pool: the first argument is the address of
 * GAMESYSTEM_IsSleepBlocked tagged as a Thumb function pointer (the pool word is 0x02012265,
 * odd), the second is the caller's own argument, and the tail call is
 * `UI_SetKeepAwakePred(fn, arg)` with UI_SetKeepAwakePred an ARM function.  Declaring the
 * pointer as `GAMESYSTEM_IsSleepBlocked` rather than writing the literal 0x02012265 is what
 * gets the odd word out of the compiler; GAMESYSTEM_IsSleepBlocked's own manifest entry is
 * what attests it (`matched x1`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_RegisterSleepCheck.c \
 *       --func GAMESYSTEM_RegisterSleepCheck --addr 0x020122A4 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void UI_SetKeepAwakePred(const void *fn, u32 arg);
extern int GAMESYSTEM_IsSleepBlocked(int a0, int a1, int a2, int a3);

void GAMESYSTEM_RegisterSleepCheck(u32 arg)
{
    UI_SetKeepAwakePred((const void *)GAMESYSTEM_IsSleepBlocked, arg);
}
