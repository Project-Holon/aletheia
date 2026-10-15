/*
 * unit:     no
 * function: GAMESYSTEM_ReleaseSleepCheck
 * address:  0x020122B4
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
 */

typedef unsigned int   u32;
extern void UI_SetKeepAwakePred(const void *fn, u32 arg);
void GAMESYSTEM_ReleaseSleepCheck(void *o)
{
    UI_SetKeepAwakePred(0, 0);
}
