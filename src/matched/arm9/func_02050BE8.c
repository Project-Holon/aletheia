/*
 * function: PARTICLE_Main
 * address:  0x02050BE8
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_Main.c \
 *       --func PARTICLE_Main --addr 0x02050BE8 --cc 1.1p1 --arm
 *
 * symbols:
 *   PARTICLE_CountSystems  0x02051504  arm
 *   PARTICLE_DrawAllSystems  0x02051534  arm
 *   PARTICLE_UpdateAllSystems  0x02051574  arm
 */

extern int PARTICLE_CountSystems(void);
extern int PARTICLE_DrawAllSystems(void);
extern int PARTICLE_UpdateAllSystems(void);

void PARTICLE_Main(void)
{
    if (PARTICLE_CountSystems() == 0)
        return;
    PARTICLE_DrawAllSystems();
    PARTICLE_UpdateAllSystems();
}
