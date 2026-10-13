/*
 * function: func_021BAFA8
 * address: 0x021BAFA8
 * packet: pkt_ov068_021BAFA8
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * blocker: ARM9 sole callers 0200837C, 020083B4, 020083D0,
 * 02008398, 02008430 lack outside witnesses; owner the integrator.
 * Interface evidence: each reads r0 pointer and r1 halfword input,
 * stores a masked bitfield to [r0], then bx lr. No ARM9 compile attempted.
 * Extent ends with two zero alignment bytes at 021BAFD6.
 * 2026-10-05: body byte-correct. The arm9 leaves 0200837C, 020083B4, 020083D0,
 * 02008398, 02008430 are now filed EXACT in src/matched/arm9/ (u16 bitfield
 * setters, `p->f = (unsigned short)v`). Needs the integrator to seed their
 * shards; then this goes EXACT.
 * symbols:
 *   CONFIG_SetTextSpeed 0x0200837C thumb
 *   CONFIG_SetBattleScene 0x020083B4 thumb
 *   CONFIG_SetBattleStyle 0x020083D0 thumb
 *   CONFIG_SetSoundMode 0x02008398 thumb
 *   CONFIG_SetButtonMode 0x02008430 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void CONFIG_SetTextSpeed(u16 *, unsigned int);
extern void CONFIG_SetBattleScene(u16 *, unsigned int);
extern void CONFIG_SetBattleStyle(u16 *, unsigned int);
extern void CONFIG_SetSoundMode(u16 *, unsigned int);
extern void CONFIG_SetButtonMode(u16 *, unsigned int);
void func_021BAFA8(u8 *p)
{
    CONFIG_SetTextSpeed(*(u16 **)(p + 8), p[0]);
    CONFIG_SetBattleScene(*(u16 **)(p + 8), p[1]);
    CONFIG_SetBattleStyle(*(u16 **)(p + 8), p[2]);
    CONFIG_SetSoundMode(*(u16 **)(p + 8), p[3]);
    CONFIG_SetButtonMode(*(u16 **)(p + 8), p[4]);
}
