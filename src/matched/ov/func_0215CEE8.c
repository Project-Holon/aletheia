/*
 * function: SCRCMD_PROC_DeclineDaycareEgg
 * address:  0x0215CEE8
 * packet:   pkt_0215CEE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetSodateya  0x02188D50  thumb
 *   SODATEYA_DeclineEgg  0x021C335C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetSodateya(void *a0);
extern void SODATEYA_DeclineEgg(void **p);

int SCRCMD_PROC_DeclineDaycareEgg(int a0, int a1)
{
    void *v0;
    void *v1;

a0 = a1 + 0;
    v0 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0215CEF0:
    v1 = GAMESYSTEM_GetFieldMap(v0);
loc_0215CEF4:
    SODATEYA_DeclineEgg((void **)FIELDMAP_GetSodateya(v1));
loc_0215CEF8:
loc_0215CEFC:
a0 = 0;
    return a0;}
