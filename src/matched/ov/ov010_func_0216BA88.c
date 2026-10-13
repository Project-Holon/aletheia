/*
 * function: FIELD_G3D_MAP_GetMissionShortfall
 * address:  0x0216BA88
 * packet:   pkt_ov010_0216BA88
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200E394  0x0200E394  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C32C  0x0200C32C  thumb
 *   FIELD_G3D_MAP_GetMissionTargetIds  0x0216BB90  thumb  ov010
 *   FIELD_G3D_MAP_GetMissionTargetCount  0x0216BB80  thumb  ov010
 *   FIELD_G3D_MAP_GetMissionGoal  0x0216BBB4  thumb  ov010
 *   FIELD_G3D_MAP_GetTallyTotal  0x0216B970  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0200E394(void *a0);
extern void *func_0200C0E8(void *sys);
struct Blk34;
extern u8 func_0200C32C(struct Blk34 *p);
extern void FIELD_G3D_MAP_GetMissionTargetIds(int index, u8 *out);
extern int FIELD_G3D_MAP_GetMissionTargetCount(int index);
extern int FIELD_G3D_MAP_GetMissionGoal(int index);
extern u32 FIELD_G3D_MAP_GetTallyTotal(const u16 *p, int index);

u16 FIELD_G3D_MAP_GetMissionShortfall(int c)
{
    int i;
    u8 buf[4];
    int n;
    u32 lim;
    u32 best;
    void *r7;
    int r4;

    r7 = func_0200E394((void *)c);
    r4 = func_0200C32C(func_0200C0E8((void *)c));
    lim = FIELD_G3D_MAP_GetMissionGoal(r4);
    n = (u8)FIELD_G3D_MAP_GetMissionTargetCount(r4);
    FIELD_G3D_MAP_GetMissionTargetIds(r4, buf);
    best = 1009998;
    for (i = 0; i < n; i++) {
        u32 v = FIELD_G3D_MAP_GetTallyTotal(r7, buf[i]);
        if (v < best) {
            best = v;
        }
    }
    return lim - best;
}
