/*
 * file:     field_gimmick.c
 * unit:     yes
 * function: func_021BE1DC, func_021BE218, func_021BE258, func_021BE288
 * address:  0x021BE1DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from entrance_camera.c and fld_exp_obj.c at 0x021BE1DC (lane FXC, CL117c and CL124: the field gimmick overlay load and unload and the gimmick dispatch helpers; no __FILE__ anchor).
 * Split from field_place_name.c at 0x021BDC94 (lane SP3, __FILE__ anchors, certain cut).
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3AC  0x0200B3AC  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   d_021D9D98     0x021D9D98  data  a4
 *   d_021D9CBC     0x021D9CBC  data  a4
 *   func_02034A5C  0x02034A5C  arm
 *   d_021D9BE0     0x021D9BE0  data  ov021  a4
 *   d_021D9E74  0x021D9E74  data
 */

typedef signed int s32;

struct FieldMap;
struct GameSystem;
struct GameData;
struct GimmickWork;
typedef struct FieldMap FieldMap;

extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern s32 func_0200B3AC(struct GimmickWork *gimmick);
extern int func_02034AC4(int overlayId);
extern void func_02034A5C(int overlayId);

void func_021BE1DC(FieldMap *fieldMap);
void func_021BE218(FieldMap *fieldMap);
void func_021BE258(struct FieldMap *fieldMap);
int func_021BE288(struct FieldMap *fieldMap, int gimmickId);

/* Overlay id of each gimmick (0 = none), and the per gimmick init, exit and run callbacks. */
extern void *d_021D9D98[];
extern void (*d_021D9E74[])(struct FieldMap *fieldMap);
extern void (*d_021D9CBC[])(FieldMap *);

/* Field gimmick setup: loads the gimmick overlay of the save and calls its init. */
void func_021BE1DC(FieldMap *fieldMap)
{
    int gimmickId;

    gimmickId = func_0200B3AC(func_02012EC4(func_020120F4(func_02188C80(fieldMap))));
    if (gimmickId != -1) {
        if (d_021D9D98[gimmickId] != 0) {
            func_02034AC4((int)d_021D9D98[gimmickId]);
        }
        d_021D9CBC[gimmickId](fieldMap);
    }
}

extern void (*d_021D9BE0[])(FieldMap *);

/* Field gimmick exit: calls the gimmick exit and unloads its overlay. */
void func_021BE218(FieldMap *fieldMap)
{
    int gimmickId;

    gimmickId = func_0200B3AC(func_02012EC4(func_020120F4(func_02188C80(fieldMap))));
    if (gimmickId != -1) {
        if (d_021D9BE0[gimmickId] != 0) {
            d_021D9BE0[gimmickId](fieldMap);
        }
        if (d_021D9D98[gimmickId] != 0) {
            func_02034A5C((int)d_021D9D98[gimmickId]);
        }
    }
}

/*
 * Runs the callback of the field gimmick that is active on the map.
 */
void func_021BE258(struct FieldMap *fieldMap)
{
    int gimmickId;

    gimmickId = func_0200B3AC(func_02012EC4(func_020120F4(func_02188C80(fieldMap))));
    if (gimmickId != -1 && d_021D9E74[gimmickId] != 0)
        d_021D9E74[gimmickId](fieldMap);
}

int func_021BE288(struct FieldMap *fieldMap, int gimmickId)
{
    if (gimmickId == func_0200B3AC(func_02012EC4(func_020120F4(func_02188C80(fieldMap))))) {
        return 1;
    }
    return 0;
}
