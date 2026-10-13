/*
 * function: GAMESYSTEM_Exit
 * address:  0x02011F90
 * packet:   pkt_02011F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_ReleaseSleepCheck  0x020122B4  thumb
 *   GAMESYSTEM_ReleaseSleepCallback  0x02012258  thumb
 *   ISS_SYS_Delete  0x0202B4F0  thumb
 *   GAME_DATA_Delete  0x02012704  thumb
 *   func_02026250  0x02026250  thumb
 *   ZONEDATA_Exit  0x02013A48  thumb
 *
 * Teardown: two calls on the object itself, then three on its words at +0x2c,
 * +0x1c and +0x24, then a final no-argument call.  Every callee resolves on its
 * own manifest entry or on a label outside the range, so the file is EXACT up to
 * the two bytes of section padding after the pop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_Exit.c \
 *       --func GAMESYSTEM_Exit --addr 0x02011F90 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void GAMESYSTEM_ReleaseSleepCheck(void *o);
extern void GAMESYSTEM_ReleaseSleepCallback(void *o);
extern void ISS_SYS_Delete(unsigned char *p);
extern void GAME_DATA_Delete(unsigned char *p);
extern void func_02026250(void *obj);
extern void ZONEDATA_Exit(void);

void GAMESYSTEM_Exit(u32 *o)
{
    GAMESYSTEM_ReleaseSleepCheck(o);
    GAMESYSTEM_ReleaseSleepCallback(o);
    ISS_SYS_Delete((unsigned char *)o[0xb]);
    GAME_DATA_Delete((unsigned char *)o[7]);
    func_02026250((void *)o[9]);
    ZONEDATA_Exit();
}
