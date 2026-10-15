/*
 * function: STA_ACT_EFFECT_StartSystem
 * address: 0x021F9EDC
 * packet: pkt_ov132_021F9EDC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   func_020056BC 0x020056BC thumb
 *   PARTICLE_SetupSystem 0x02051230 arm
 */
#include "../include/Obj10535.h"
#include "../include/Obj14089.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);
extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);
extern unsigned func_020056BC(void);
extern void PARTICLE_SetupSystem(void *, void *, unsigned, unsigned);
char *STA_ACT_EFFECT_StartSystem(char *p, u32 a)
{
    char *q = 0;
    void *v;
    u8 i;
    u8 j;
    for (i = 0; i < 8; i++) if (*(int *)(p + i * 0x4848 + 4) == 0) q = (p + 4) + i * 0x4848;
    j = 0;
    ((struct Obj10535 *)q)->f4804 = (void *)PARTICLE_CreateSystemDefault((int)(q + 4), 0x4800, 0, ((struct Obj14089 *)p)->f0);
    v = (void *)PARTICLE_LoadArchiveMember(47, a, ((struct Obj14089 *)p)->f0);
    PARTICLE_SetupSystem(((struct Obj10535 *)q)->f4804, v, 0, func_020056BC());
    for (; j < 4; j++) *(int *)(q + j * 16 + 0x4808) = 0;
    ((struct Obj10535 *)q)->f0 = 1;
    return q;
}
