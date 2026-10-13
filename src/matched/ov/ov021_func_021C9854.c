/*
 * function: FIELD_DOOR_ANIME_CloseTask
 * address:  0x021C9854
 * packet:   pkt_ov021_021C9854
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   FIELD_BUILDMODEL_GetFirstEntryInRect  0x0218C638  thumb  ov021
 *   FIELD_BUILDMODEL_PlayEntryAnim  0x0218C69C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_020061E4(u32);
extern int GFL_USE_GetSeSlot(u32);
extern int GFL_USE_IsSeSlotBusy(u32);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
typedef unsigned char  u8;
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern u32 FIELD_G3D_MAPPER_GetBuildModel(u8 *p);
extern int FIELD_BUILDMODEL_GetFirstEntryInRect(int a, int b, int c);
extern void FIELD_BUILDMODEL_PlayEntryAnim(unsigned char *p, int b, int i, int c);

int FIELD_DOOR_ANIME_CloseTask(u32 a, u32 *q, u32 *p)
{
    int v[3];
    int box[4];
    u32 h;
    u32 r;

    switch (q[0]) {
    case 0:
        if (p[4] == 0)
            func_020061E4(0x55D);
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((struct Obj00020 *)p[1]), (struct VecFx32 *)v);
        box[0] = v[2] - 0x10000;
        box[1] = v[2] + 0x10000;
        box[2] = v[0] - 0x10000;
        box[3] = v[0] + 0x10000;
        h = FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper((void *)p[1]));
        r = FIELD_BUILDMODEL_GetFirstEntryInRect(h, 4, (int)box);
        if (r != 0) {
            p[2] = r;
            FIELD_BUILDMODEL_PlayEntryAnim((unsigned char *)h, r, 2, 0);
        }
        q[0]++;
        break;
    case 1:
        if (p[4] == 0) {
            if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x55D)) == 0) {
                q[0]++;
            }
        } else {
            q[0]++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}
