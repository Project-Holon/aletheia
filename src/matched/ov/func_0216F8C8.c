/*
 * function: TRCARD_SYS_ScrCmdStartFieldProc
 * address:  0x0216F8C8
 * packet:   pkt_0216F8C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SP_POKE_GIMMICK_UpdatePairB  0x021F385C  thumb  ov059
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void SP_POKE_GIMMICK_UpdatePairB(void *);

int TRCARD_SYS_ScrCmdStartFieldProc(int a0, int a1)
{
    SP_POKE_GIMMICK_UpdatePairB((void *)GAMESYSTEM_GetFieldMap((void *)SCRCMD_WORK_GetGameSystem((void *)a1)));
    return 0;
}
