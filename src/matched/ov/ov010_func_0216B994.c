/*
 * function: FIELD_G3D_MAP_AreMissionTargetsAtGoal
 * address:  0x0216B994
 * packet:   pkt_ov010_0216B994
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3D_MAP_GetMissionTargetIds  0x0216BB90  thumb  ov010
 *   FIELD_G3D_MAP_GetMissionTargetCount  0x0216BB80  thumb  ov010
 *   FIELD_G3D_MAP_GetMissionGoal  0x0216BBB4  thumb  ov010
 *   FIELD_G3D_MAP_GetTallyTotal  0x0216B970  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void FIELD_G3D_MAP_GetMissionTargetIds(int index, u8 *out);
extern int FIELD_G3D_MAP_GetMissionTargetCount(int index);
extern int FIELD_G3D_MAP_GetMissionGoal(int index);
extern u32 FIELD_G3D_MAP_GetTallyTotal(const u16 *p, int index);

int FIELD_G3D_MAP_AreMissionTargetsAtGoal(int c, int vm)
{
    int i;
    u8 buf[4];
    int n;
    u32 lim;

    FIELD_G3D_MAP_GetMissionTargetIds(vm, buf);
    n = (u8)FIELD_G3D_MAP_GetMissionTargetCount(vm);
    lim = FIELD_G3D_MAP_GetMissionGoal(vm);
    for (i = 0; i < n; i++) {
        if (FIELD_G3D_MAP_GetTallyTotal((const u16 *)c, buf[i]) < lim) {
            return 0;
        }
    }
    return 1;
}
