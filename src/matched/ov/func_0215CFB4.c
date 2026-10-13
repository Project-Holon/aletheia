/*
 * function: SCRCMD_PROC_GetDaycareMonCount
 * address:  0x0215CFB4
 * packet:   pkt_0215CFB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetSodateya  0x02188D50  thumb
 *   SODATEYA_GetPokemonCount  0x021C340C  thumb
 */
#include "../include/Obj17694.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetSodateya(void *a0);
extern int SODATEYA_GetPokemonCount();

int SCRCMD_PROC_GetDaycareMonCount(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215CFBC:
a0 = t5 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0215CFC4:
    v2 = GAMESYSTEM_GetFieldMap(v1);
loc_0215CFC8:
    a0 = SODATEYA_GetPokemonCount(FIELDMAP_GetSodateya(v2));
loc_0215CFCC:
loc_0215CFD0:
((struct Obj17694 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}
