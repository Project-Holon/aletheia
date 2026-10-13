/*
 * function: FIELD_DOOR_ANIME_SetOpenTask
 * address:  0x021C97B8
 * packet:   pkt_ov021_021C97B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
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

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
typedef unsigned char  u8;
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern u32 FIELD_G3D_MAPPER_GetBuildModel(u8 *p);
extern int FIELD_BUILDMODEL_GetFirstEntryInRect(int a, int b, int c);
extern void FIELD_BUILDMODEL_PlayEntryAnim(unsigned char *p, int b, int i, int c);

int FIELD_DOOR_ANIME_SetOpenTask(u32 a, u32 *q, u32 *p)
{
    int v[3];
    int box[4];
    u32 h;
    u32 r;

    switch (q[0]) {
    case 0:
        FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((struct Obj00020 *)p[1]), (struct VecFx32 *)v);
        box[0] = v[2] - 0x10000;
        box[1] = v[2] + 0x10000;
        box[2] = v[0] - 0x10000;
        box[3] = v[0] + 0x10000;
        h = FIELD_G3D_MAPPER_GetBuildModel((u8 *)FIELDMAP_GetG3dMapper((void *)p[1]));
        r = FIELD_BUILDMODEL_GetFirstEntryInRect(h, 4, (int)box);
        if (r != 0) {
            p[2] = r;
            FIELD_BUILDMODEL_PlayEntryAnim((unsigned char *)h, r, 1, 2);
        }
        q[0]++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
