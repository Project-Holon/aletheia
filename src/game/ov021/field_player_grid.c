/*
 * file:     field_player_grid.c
 * unit:     yes
 * function: func_021A4140, func_021A41A8, func_021A41B0, func_021A4224, func_021A4254, func_021A428C, func_021A43D8, func_021A4444, func_021A448C, func_021A44BC, func_021A44C8, func_021A4544, func_021A4598, func_021A4664, func_021A4698, func_021A46F0, func_021A4768, func_021A47B4, func_021A482C, func_021A4890, func_021A48A4, func_021A48C8, func_021A491C, func_021A4960, func_021A4994, func_021A4A74, func_021A4AA8, func_021A4B00, func_021A4B54, func_021A4B98, func_021A4C1C, func_021A4C50, func_021A4CA8, func_021A4CF4, func_021A4D8C, func_021A4D90, func_021A4DC0, func_021A4E78, func_021A4E9C, func_021A4ED8, func_021A4F04, func_021A4F0C, func_021A4F50, func_021A4F58, func_021A4FA8, func_021A5010, func_021A5014, func_021A5044, func_021A50BC, func_021A50E0, func_021A511C, func_021A5148, func_021A51A4, func_021A51A8, func_021A51D8, func_021A5204, func_021A5228, func_021A5264, func_021A5304, func_021A530C, func_021A5318, func_021A5328, func_021A5334, func_021A5340, func_021A5354, func_021A5360, func_021A536C, func_021A5378, func_021A5390, func_021A53A4, func_021A53BC, func_021A53D0, func_021A5408, func_021A5458, func_021A548C, func_021A54A0, func_021A54B4, func_021A550C, func_021A552C, func_021A5538, func_021A55A8, func_021A55DC, func_021A55FC, func_021A5610, func_021A5630, func_021A569C, func_021A56C0, func_021A56F4, func_021A5708, func_021A5728, func_021A572C, func_021A5738, func_021A575C, func_021A5764, func_021A5768, func_021A5778, func_021A5788, func_021A57C0, func_021A5810
 * address:  0x021A4140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A41A0 (d_021DDECC "field_player_grid.c"); 021A4140 is the grid constructor.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   d_021DDECC     0x021DDECC  data  ov021  a4
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   d_021D8A00     0x021D8A00  data  ov021  a4
 *   d_021D8A0C     0x021D8A0C  data  ov021  a4
 *   d_021D89F4     0x021D89F4  data  ov021  a4
 *   d_021D8A2C     0x021D8A2C  data  a4
 *   func_0202E83C  0x0202E83C  thumb
 *   func_02164208  0x02164208  thumb  ov010
 *   func_021AB158  0x021AB158  thumb  ov021
 *   func_021AB164  0x021AB164  thumb  ov021
 *   func_021AB170  0x021AB170  thumb  ov021
 *   func_021AB17C  0x021AB17C  thumb  ov021
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0219F7CC  0x0219F7CC  thumb  ov021
 *   func_021AB140  0x021AB140  thumb  ov021
 *   func_021AB404  0x021AB404  thumb  ov021
 *   func_021AB410  0x021AB410  thumb  ov021
 *   func_021AB328  0x021AB328  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021AB44C  0x021AB44C  thumb  ov021
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DCE8  0x0216DCE8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_021AB41C  0x021AB41C  thumb  ov021
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_02163994  0x02163994  thumb  ov010
 *   func_021AB2DC  0x021AB2DC  thumb  ov021
 *   func_0216E5B0  0x0216E5B0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB348  0x021AB348  thumb  ov021
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_021640B0  0x021640B0  thumb  ov010
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   data_021D89EC  0x021D89EC  data  a4
 *   d_021D8A24  0x021D8A24  data  a2
 *   func_02012844  0x02012844  thumb
 *   func_02162564  0x02162564  thumb  ov010
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626B8  0x021626B8  thumb  ov010
 *   func_021A3898  0x021A3898  thumb  ov021
 *   func_021A3920  0x021A3920  thumb  ov021
 *   func_021A395C  0x021A395C  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3998  0x021A3998  thumb  ov021
 *   func_021A39AC  0x021A39AC  thumb  ov021
 *   func_021A3A20  0x021A3A20  thumb  ov021
 *   func_021A3AA0  0x021A3AA0  thumb  ov021
 *   func_021A3AB8  0x021A3AB8  thumb  ov021
 *   func_021A3AC4  0x021A3AC4  thumb  ov021
 *   func_021A3CB0  0x021A3CB0  thumb  ov021
 *   func_021A3CC0  0x021A3CC0  thumb  ov021
 *   func_021A3CE8  0x021A3CE8  thumb  ov021
 */
#include "field_player_grid_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;
typedef signed int s32;

/* Animation command bases for func_02197E7C(dir, base). */
#define FIELD_PLAYER_GRID_ACMD_STAND            0x00
#define FIELD_PLAYER_GRID_ACMD_WALK             0x0C
#define FIELD_PLAYER_GRID_ACMD_RUN              0x10
#define FIELD_PLAYER_GRID_ACMD_DASH             0x14
#define FIELD_PLAYER_GRID_ACMD_BLOCKED          0x1C
#define FIELD_PLAYER_GRID_ACMD_TURN             0x24
#define FIELD_PLAYER_GRID_ACMD_HOP              0x34
#define FIELD_PLAYER_GRID_ACMD_LEDGE_JUMP       0x38
#define FIELD_PLAYER_GRID_ACMD_RUN_SLOPE_UP     0x4C
#define FIELD_PLAYER_GRID_ACMD_RUN_SPECIAL      0x58
#define FIELD_PLAYER_GRID_ACMD_CYCLE_SPECIAL    0x9B
#define FIELD_PLAYER_GRID_ACMD_RUN_SPECIAL_SLOPE_UP 0xA3
#define FIELD_PLAYER_GRID_ACMD_WALK_SLOPE_UP    0xA7

#define FIELD_PLAYER_GRID_SE_BLOCKED            0x55A
#define FIELD_PLAYER_GRID_SE_LEDGE_JUMP         0x55E

/* Status bits the forced move sets on the model: pause direction and bit 4. */
#define FIELD_PLAYER_GRID_MMDL_PAUSE_BITS       (MMDL_STABIT_PAUSE_DIR | 0x0010)
#define FIELD_PLAYER_GRID_MMDL_STEP_END_BITS    (MMDL_MOVEBIT_MOVE_END | MMDL_MOVEBIT_JUMP_END)

/* Step kind the core stores (FieldPlayerCore.stepKind). */
#define FIELD_PLAYER_GRID_STEP_KIND_NONE        0
#define FIELD_PLAYER_GRID_STEP_KIND_WALK        1
#define FIELD_PLAYER_GRID_STEP_KIND_RUN         2

/* Tile sound by attribute mask (d_021D8A00, d_021D8A0C). */
typedef struct FieldPlayerGridAttrSound {
    u32 attrMask;
    int soundId;
    s16 repeatWalk;         /* frames between repeats, on foot */
    s16 repeatCycle;        /* the same while cycling */
} FieldPlayerGridAttrSound;

/* Tile sound by attribute predicate (d_021D89F4, d_021D8A2C). */
typedef struct FieldPlayerGridCallbackSound {
    int (*isTile)(u16 attrKind);
    u16 soundId;
    s8 repeatWalk;
    s8 repeatCycle;
    u8 season;              /* 4 for every season */
} FieldPlayerGridCallbackSound;

typedef int (*FieldPlayerGridForcedMoveFunc)(FieldPlayerGrid *grid, int dir);

extern u32 func_020307B0(void *memory);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020061E4(u32 soundId);
extern void func_0216D5E0(Mmdl *mmdl, int dir);
extern void func_0216D88C(Mmdl *mmdl, VecFx32 *out);
extern u16 func_0216D5F8(Mmdl *mmdl);
extern u16 func_0216D83C(Mmdl *mmdl);
extern u16 func_0216D854(Mmdl *mmdl);
extern u16 func_0216D86C(Mmdl *mmdl);
extern int func_021641E8(int dir);
extern int func_021641F8(int dir);
extern int func_021AB11C(u32 attr);
extern u16 func_021AB0F0(u32 attr);
extern void *func_020120F4(void *gameSystem);
extern void *func_02188C80(FieldMap *fieldMap);
extern void func_0216D85C(Mmdl *mmdl, int y);
extern void func_0216D89C(Mmdl *mmdl, const VecFx32 *pos);
extern int func_0216D3CC(Mmdl *mmdl);
extern MmdlSys *func_0216D67C(Mmdl *mmdl);
extern u16 func_0216D608(Mmdl *mmdl);
extern void *func_02188CD0(FieldMap *fieldMap);
extern int func_02163E34(Mmdl *mmdl, VecFx32 *pos, int *outAttr);
extern u16 func_021AB0F8(u32 attr);
extern int func_0202E83C(void *gameSystem);
extern void func_02164208(int dir, VecFx32 *pos, int amount);
extern int func_021AB158(u16 attrKind);
extern int func_021AB164(u16 attrKind);
extern int func_021AB170(u16 attrKind);
extern int func_021AB17C(u16 attrKind);
extern void func_0216D4B4(Mmdl *mmdl);
extern int func_0219F7CC(Mmdl *mmdl, u32 frame);
extern int func_021AB140(int attrKind);
extern int func_021AB404(int attrKind);
extern int func_021AB410(int attrKind);
extern int func_021AB328(int attrKind);
extern int func_02197E7C(int dir, int acmdBase);
extern void func_0216D410(Mmdl *mmdl, int acmd);
extern int func_021AB44C(u16 attrKind);
extern int func_0216DB4C(Mmdl *mmdl, int flag);
extern int func_0216DCE8(Mmdl *mmdl, int flag);
extern void func_0216D568(Mmdl *mmdl, u32 bits);
extern int func_02163E58(Mmdl *mmdl, VecFx32 *pos, int *outHeight);
extern void func_0216D570(Mmdl *mmdl, u32 bits);
extern int func_021AB41C(u16 attrKind);
extern void func_021AC528(Mmdl *mmdl, void *effectCtrl);
extern int func_02163994(Mmdl *mmdl, int gridX, int gridY, int gridZ, u32 dir);
extern int func_021AB2DC(u16 attrKind);
extern int func_0216E5B0(MmdlSys *mmdlSys, const VecFx32 *pos);
extern void func_0216D674(Mmdl *mmdl, u16 drawStatus);
extern u32 func_0216D7DC(Mmdl *mmdl);
extern int func_021AB348(u32 attrKind);
extern int func_02164010(Mmdl *mmdl);
extern int func_021640B0(Mmdl *mmdl);
extern int func_02163F10(Mmdl *mmdl);
extern void func_0216D550(Mmdl *mmdl, u32 bits);
extern void func_0216D548(Mmdl *mmdl, u32 bits);
extern void *func_02012844(void *gameData);
extern int func_02162564(void *eventData, const VecFx32 *pos);
extern void *func_021625CC(void *eventData, unsigned index);
extern int func_021626B8(void *connect, int dir);
extern void func_021A3898(FieldPlayerCore *core, VecFx32 *out);
extern u16 func_021A3920(FieldPlayerCore *core);
extern FieldMap *func_021A395C(FieldPlayerCore *core);
extern Mmdl *func_021A3960(FieldPlayerCore *core);
extern void func_021A3964(FieldPlayerCore *core, u32 form);
extern u32 func_021A3974(FieldPlayerCore *core);
extern void func_021A3998(FieldPlayerCore *core);
extern void func_021A39AC(FieldPlayerCore *core, int a);
extern int func_021A3A20(FieldPlayerCore *core);
extern int func_021A3AA0(FieldPlayerCore *core);
extern u16 func_021A3AB8(FieldPlayerCore *core, u32 keys);
extern void func_021A3AC4(FieldPlayerCore *core, u32 keys);
extern int func_021A3CB0(FieldPlayerCore *core, u32 mask);
extern int func_021A3CC0(FieldPlayerCore *core);
extern void func_021A3CE8(FieldPlayerCore *core);

FieldPlayerGrid *func_021A4140(FieldPlayerCore *core, u32 heapId);
void func_021A41A8(FieldPlayerGrid *grid);
void func_021A41B0(FieldPlayerGrid *grid, u32 keyTrigger, u32 keyHeld, u32 dashAllowed);
void func_021A4224(FieldPlayerGrid *grid, int result, const FieldPlayerGridMoveRequest *request);
int func_021A4254(FieldPlayerGrid *grid, u32 dir);
int func_021A428C(FieldPlayerGrid *grid, int unused, VecFx32 *pos, int lookAhead, int season);
void func_021A43D8(FieldPlayerGrid *grid, int result, int dir);
int func_021A4444(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request);
int func_021A448C(FieldPlayerGrid *grid, int dir);
void func_021A44BC(FieldPlayerGrid *grid);
int func_021A44C8(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request);
int func_021A4544(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A4598(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A4664(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A4698(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A46F0(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request);
int func_021A4768(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A47B4(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A482C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A4890(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A48A4(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A48C8(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request);
int func_021A491C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A4960(int attrKind);
int func_021A4994(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A4A74(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A4AA8(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A4B00(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request);
int func_021A4B54(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A4B98(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A4C1C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A4C50(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A4CA8(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request);
void func_021A4CF4(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request);
void func_021A4D8C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A4D90(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A4DC0(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A4E78(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A4E9C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A4ED8(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A4F04(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A4F0C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A4F50(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A4F58(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A4FA8(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request);
void func_021A5010(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A5014(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A5044(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A50BC(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A50E0(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A511C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A5148(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request);
void func_021A51A4(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A51A8(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A51D8(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A5204(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
void func_021A5228(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request);
int func_021A5264(FieldPlayerGrid *grid, Mmdl *mmdl, u32 dir, int *outAttr);
void func_021A5304(FieldPlayerGrid *grid, u32 mask);
void func_021A530C(FieldPlayerGrid *grid, u32 mask);
int func_021A5318(FieldPlayerGrid *grid, u32 mask);
void func_021A5328(FieldPlayerGrid *grid);
void func_021A5334(FieldPlayerGrid *grid);
int func_021A5340(FieldPlayerGrid *grid);
void func_021A5354(FieldPlayerGrid *grid);
void func_021A5360(FieldPlayerGrid *grid);
void func_021A536C(FieldPlayerGrid *grid);
void func_021A5378(FieldPlayerGrid *grid, int on);
int func_021A5390(FieldPlayerGrid *grid);
void func_021A53A4(FieldPlayerGrid *grid, int on);
int func_021A53BC(FieldPlayerGrid *grid);
void func_021A53D0(FieldPlayerGrid *grid);
int func_021A5408(FieldPlayerGrid *grid);
int func_021A5458(FieldPlayerGrid *grid, int unused);
int func_021A548C(FieldPlayerGrid *grid);
int func_021A54A0(FieldPlayerGrid *grid);
void func_021A54B4(FieldPlayerGrid *grid);
void func_021A550C(FieldPlayerGrid *grid);
u32 func_021A552C(FieldPlayerGrid *grid);
int func_021A5538(FieldPlayerGrid *grid);
int func_021A55A8(FieldPlayerGrid *grid, u32 dir, int skip);
int func_021A55DC(int attrKind);
int func_021A55FC(int attrKind);
int func_021A5610(FieldPlayerGrid *grid);
u32 func_021A5630(FieldPlayerGrid *grid);
int func_021A569C(FieldPlayerGrid *grid, Mmdl *mmdl, int dir, int *outAttr);
u32 func_021A56C0(FieldPlayerGrid *grid, u32 unused1, u32 unused2);
void func_021A56F4(FieldPlayerGrid *grid);
void func_021A5708(FieldPlayerGrid *grid);
FieldPlayerCore *func_021A5728(FieldPlayerGrid *grid);
Mmdl *func_021A572C(FieldPlayerGrid *grid);
void func_021A5738(FieldPlayerGrid *grid, int keepFrame);
void func_021A575C(FieldPlayerGrid *grid);
u32 func_021A5764(FieldPlayerGrid *grid);
int func_021A5768(FieldPlayerGrid *grid, u32 landed);
int func_021A5778(FieldPlayerGrid *grid);
int func_021A5788(FieldPlayerGrid *grid, int dir, int *outAttr);
int func_021A57C0(FieldPlayerGrid *grid, int dir);
int func_021A5810(FieldPlayerGrid *grid, int dir);

extern u8 d_021DDECC[];
extern FieldPlayerGridAttrSound d_021D8A00[];
extern FieldPlayerGridAttrSound d_021D8A0C[];
extern FieldPlayerGridCallbackSound d_021D89F4[];
extern FieldPlayerGridCallbackSound d_021D8A2C[];
extern FieldPlayerGridForcedMoveFunc const data_021D89EC[];
extern const u16 d_021D8A24[4];

FieldPlayerGrid *func_021A4140(FieldPlayerCore *core, u32 heapId)
{
    FieldPlayerGrid *grid;

    grid = func_02030734(heapId, 0x20, 1, (const char *)d_021DDECC, 0x17D);
    grid->core = core;
    grid->fieldMap = func_021A395C(core);
    grid->soundId = FIELD_PLAYER_GRID_SOUND_NONE;
    func_021A5354(grid);
    switch (func_021A3974(grid->core)) {
    case FIELD_PLAYER_AVATAR_FORM_SURF:
        func_021A3CB0(grid->core, 4);
        func_021A3CE8(grid->core);
        break;
    case FIELD_PLAYER_AVATAR_FORM_DIVE:
        func_021A3CB0(grid->core, 0x100);
        func_021A3CE8(grid->core);
        break;
    }
    return grid;
}


void func_021A41A8(FieldPlayerGrid *grid)
{
    func_020307B0(grid);
}


void func_021A41B0(FieldPlayerGrid *grid, u32 keyTrigger, u32 keyHeld, u32 dashAllowed)
{
    FieldPlayerGridMoveRequest request;
    u32 dir;
    int result;

    dir = func_021A3AB8(grid->core, keyHeld);
    if (func_021A4254(grid, dir) == 1) {
        func_021A3CC0(grid->core);
        if (func_021A55A8(grid, dir, 0) == 0) {
            request.keyTrigger = keyTrigger;
            request.keyHeld = keyHeld;
            request.dir = dir;
            request.dashAllowed = dashAllowed;
            request.isDash = 0;
            result = func_021A4444(grid, &request);
            func_021A4224(grid, result, &request);
            func_021A4CA8(grid, result, &request);
            func_021A43D8(grid, result, dir);
        }
    }
}


void func_021A4224(FieldPlayerGrid *grid, int result, const FieldPlayerGridMoveRequest *request)
{
    grid->lastResult = result;
    func_021A3AC4(grid->core, request->keyHeld);
    func_021A536C(grid);
    func_021A530C(grid, FIELD_PLAYER_GRID_FLAG_SPECIAL_WALK);
    if (result == FIELD_PLAYER_GRID_RESULT_WALK)
        func_021A5360(grid);
    grid->hopLanded = 0;
}


int func_021A4254(FieldPlayerGrid *grid, u32 dir)
{
    Mmdl *mmdl = func_021A3960(grid->core);

    if (func_0216D3CC(mmdl) == 1)
        return 1;
    if (dir != FIELD_PLAYER_GRID_DIR_NONE && grid->state == FIELD_PLAYER_GRID_STATE_BLOCKED && dir != func_0216D5F8(mmdl))
        return 1;
    return 0;
}


/*
 * Picks a tile sound from two 12-byte-record tables (attribute-mask table,
 * then predicate-callback table), 0x546 meaning none, and plays it with a
 * repeat counter. lookAhead selects the second table pair (the tile ahead).
 * d_021D8A2C carries no ov021 token: with it the hint reads as contested.
 */
int func_021A428C(FieldPlayerGrid *grid, int unused, VecFx32 *pos, int lookAhead, int season)
{
    int repeatLimit;
    int soundId;
    int attr;
    int mode;
    FieldPlayerGridAttrSound *attrSound;
    FieldPlayerGridCallbackSound *callbackSound;
    u32 attrBits;

    soundId = FIELD_PLAYER_GRID_SOUND_NONE;
    repeatLimit = 0;
    mode = 0;
    if (func_021A3974(grid->core) == FIELD_PLAYER_AVATAR_FORM_CYCLE) {
        mode = 2;
    } else if (func_021A5318(grid, FIELD_PLAYER_GRID_FLAG_SPECIAL_WALK) != 0) {
        mode = 1;
    }
    if (mode == 0) {
        grid->soundId = FIELD_PLAYER_GRID_SOUND_NONE;
        grid->soundRepeat = 0;
    }
    if (func_02163E34(func_021A3960(grid->core), pos, &attr) == 1) {
        attrBits = func_021AB0F8(attr);
        if (lookAhead == 0) {
            attrSound = d_021D8A00;
        } else {
            attrSound = d_021D8A0C;
        }
        for (; attrSound->attrMask != 0; attrSound++) {
            if (attrSound->attrMask & attrBits) {
                soundId = attrSound->soundId;
                if (mode == 1) {
                    repeatLimit = attrSound->repeatWalk;
                } else if (mode == 2) {
                    repeatLimit = attrSound->repeatCycle;
                }
                break;
            }
        }
        if (soundId == FIELD_PLAYER_GRID_SOUND_NONE) {
            callbackSound = d_021D89F4;
            if (lookAhead != 0) {
                callbackSound = d_021D8A2C;
            }
            for (; callbackSound->isTile != 0; callbackSound++) {
                if (callbackSound->isTile((u16)attr) == 1 && (callbackSound->season == 4 || callbackSound->season == season)) {
                    soundId = callbackSound->soundId;
                    if (mode == 1) {
                        repeatLimit = callbackSound->repeatWalk;
                    } else if (mode == 2) {
                        repeatLimit = callbackSound->repeatCycle;
                    }
                    break;
                }
            }
        }
        if (soundId == FIELD_PLAYER_GRID_SOUND_NONE) {
            if (lookAhead == 1) {
                grid->soundRepeat = 0;
            }
        } else if (mode != 0) {
            if (grid->soundId != soundId) {
                grid->soundRepeat = 0;
            }
            if (grid->soundRepeat != 0 && grid->soundRepeat < repeatLimit) {
                soundId = FIELD_PLAYER_GRID_SOUND_NONE;
            }
            if (grid->soundRepeat >= repeatLimit) {
                grid->soundRepeat = 0;
            }
            grid->soundId = soundId;
            grid->soundRepeat = grid->soundRepeat + 1;
        }
        if (soundId != FIELD_PLAYER_GRID_SOUND_NONE) {
            func_020061E4(soundId);
            return 1;
        }
    }
    return 0;
}


void func_021A43D8(FieldPlayerGrid *grid, int result, int dir)
{
    VecFx32 pos;
    Mmdl *mmdl;
    u32 season;

    if (result != FIELD_PLAYER_GRID_RESULT_WALK) {
        grid->soundId = FIELD_PLAYER_GRID_SOUND_NONE;
        grid->soundRepeat = 0;
        return;
    }
    mmdl = func_021A3960(grid->core);
    season = func_0202E83C(func_02188C80(grid->fieldMap));
    func_0216D88C(mmdl, &pos);
    if (func_021A428C(grid, result, &pos, 0, season) == 0) {
        func_02164208(dir, &pos, 0x10000);
        func_021A428C(grid, result, &pos, 1, season);
    }
}


int func_021A4444(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request)
{
    int result;

    result = FIELD_PLAYER_GRID_RESULT_NONE;
    switch (func_021A3974(grid->core)) {
    case FIELD_PLAYER_AVATAR_FORM_NORMAL:
        result = func_021A44C8(grid, request);
        break;
    case FIELD_PLAYER_AVATAR_FORM_CYCLE:
        result = func_021A48C8(grid, request);
        break;
    case FIELD_PLAYER_AVATAR_FORM_SURF:
    case FIELD_PLAYER_AVATAR_FORM_DIVE:
        result = func_021A4B00(grid, request);
        break;
    }
    return result;
}


int func_021A448C(FieldPlayerGrid *grid, int dir)
{
    int curDir = func_0216D5F8(func_021A3960(grid->core));

    if (dir == FIELD_PLAYER_GRID_DIR_NONE)
        return 0;
    if (dir != curDir && grid->state != FIELD_PLAYER_GRID_STATE_WALK && grid->state != FIELD_PLAYER_GRID_STATE_BLOCKED)
        return 2;
    return 1;
}


/* Tail-call thunk: the core's current action check. */
void func_021A44BC(FieldPlayerGrid *grid)
{
    func_021A3AA0(grid->core);
}


int func_021A44C8(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl;
    int result;

    mmdl = func_021A3960(grid->core);
    result = FIELD_PLAYER_GRID_RESULT_NONE;
    if (func_021A5610(grid) == 1 || func_021A53BC(grid) == 1) {
        return func_021A46F0(grid, request);
    }
    switch (grid->state) {
    case FIELD_PLAYER_GRID_STATE_STAND:
        result = func_021A4544(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_WALK:
        result = func_021A4598(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_TURN:
        result = func_021A4664(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_BLOCKED:
        result = func_021A4698(grid, mmdl, request);
        break;
    }
    return result;
}


int func_021A4544(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (func_0216D3CC(mmdl) == 1) {
        if (request->dir != FIELD_PLAYER_GRID_DIR_NONE) {
            if (request->dir != func_0216D5F8(mmdl) && request->isDash == 0) {
                if ((request->dashAllowed & 1) == 0) {
                    return FIELD_PLAYER_GRID_RESULT_TURN;
                }
                if ((2 & request->keyHeld) == 0) {
                    return FIELD_PLAYER_GRID_RESULT_TURN;
                }
            }
            return func_021A4598(grid, mmdl, request);
        }
        return FIELD_PLAYER_GRID_RESULT_STAND;
    }
    return FIELD_PLAYER_GRID_RESULT_NONE;
}


/*
 * Twin of func_021A4B98 with an extra tile-class check (ids
 * classed 0..3 by func_021AB158/164/170/17C) that returns 5.
 */
int func_021A4598(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int attr;
    u32 hitFlags;
    u16 attrKind;
    u32 attrBits;
    int ledgeDir;

    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return func_021A4544(grid, mmdl, request);
    }
    hitFlags = func_021A5264(grid, mmdl, request->dir, &attr);
    if (request->isDash == 1 && hitFlags != 0 && !(hitFlags & 0x10)) {
        hitFlags = 0;
    }
    if (attr != -1) {
        attrKind = func_021AB0F0(attr);
        attrBits = func_021AB0F8(attr);
        if (hitFlags & 2) {
            ledgeDir = FIELD_PLAYER_GRID_DIR_NONE;
            if (func_021AB158(attrKind)) {
                ledgeDir = 0;
            } else if (func_021AB164(attrKind)) {
                ledgeDir = 1;
            } else if (func_021AB170(attrKind)) {
                ledgeDir = 2;
            } else if (func_021AB17C(attrKind)) {
                ledgeDir = 3;
            }
            if (ledgeDir != FIELD_PLAYER_GRID_DIR_NONE && ledgeDir == request->dir) {
                return FIELD_PLAYER_GRID_RESULT_LEDGE_JUMP;
            }
        }
        if (hitFlags == 0) {
            if (!(attrBits & 2)) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
            if (request->isDash == 1) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
        }
    }
    return FIELD_PLAYER_GRID_RESULT_BLOCKED;
}


int func_021A4664(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (func_0216D3CC(mmdl) == 0)
        return FIELD_PLAYER_GRID_RESULT_NONE;
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE)
        return func_021A4544(grid, mmdl, request);
    return func_021A4598(grid, mmdl, request);
}


int func_021A4698(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    u32 curDir = func_0216D5F8(mmdl);

    if (request->dir != FIELD_PLAYER_GRID_DIR_NONE && request->dir != curDir) {
        func_0216D4B4(mmdl);
        return func_021A4598(grid, mmdl, request);
    }
    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return func_021A4544(grid, mmdl, request);
    }
    return func_021A4598(grid, mmdl, request);
}


int func_021A46F0(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl = func_021A3960(grid->core);
    int result = FIELD_PLAYER_GRID_RESULT_NONE;

    switch (grid->state) {
    case FIELD_PLAYER_GRID_STATE_STAND:
        result = func_021A4768(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_WALK:
        result = func_021A47B4(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_TURN:
        result = func_021A4664(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_BLOCKED:
        result = func_021A4698(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_HOLD:
        result = func_021A482C(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_HOP:
    case FIELD_PLAYER_GRID_STATE_HOP_AIR:
        result = func_021A4890(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_HOP_FALL:
        result = func_021A48A4(grid, mmdl, request);
        break;
    }
    return result;
}


int func_021A4768(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (func_0216D3CC(mmdl) == 1) {
        if (request->dir != FIELD_PLAYER_GRID_DIR_NONE) {
            u32 curDir = func_0216D5F8(mmdl);
            if (request->dir != curDir && request->isDash == 0) {
                return FIELD_PLAYER_GRID_RESULT_TURN;
            }
            return func_021A47B4(grid, mmdl, request);
        }
        return func_021A482C(grid, mmdl, request);
    }
    return FIELD_PLAYER_GRID_RESULT_NONE;
}


int func_021A47B4(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int attr;
    u32 hitFlags;

    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return func_021A4768(grid, mmdl, request);
    }
    hitFlags = func_021A569C(grid, mmdl, request->dir, &attr);
    if (attr != -1) {
        if (hitFlags & 0x100) {
            if (!(hitFlags & 0xFFFFFEFF)) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
        } else if (func_021AB11C(attr) == 0) {
            func_021A53A4(grid, 1);
            return FIELD_PLAYER_GRID_RESULT_HOP;
        }
    }
    return FIELD_PLAYER_GRID_RESULT_BLOCKED;
}


int func_021A482C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        if (func_021A5390(grid) == 0) {
            func_021A56F4(grid);
        }
        if (grid->holdEffectPending == 1) {
            if (func_0219F7CC(mmdl, grid->holdFrames) != 0) {
                grid->holdEffectPending = 0;
            }
        }
        grid->holdFrames = grid->holdFrames + 1;
        if (grid->holdFrames == 60) {
            func_021A5708(grid);
            func_021A53A4(grid, 1);
            return FIELD_PLAYER_GRID_RESULT_HOP;
        }
    } else {
        func_021A5708(grid);
        return func_021A47B4(grid, mmdl, request);
    }
    return FIELD_PLAYER_GRID_RESULT_HOLD;
}


int func_021A4890(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (func_0216D3CC(mmdl) == 1) {
        return FIELD_PLAYER_GRID_RESULT_HOP_FALL;
    }
    return FIELD_PLAYER_GRID_RESULT_HOP_AIR;
}


int func_021A48A4(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (func_021A56C0(grid, (u32)mmdl, (u32)request) == 1) {
        func_021A54B4(grid);
        func_021A53A4(grid, 0);
        return FIELD_PLAYER_GRID_RESULT_STAND;
    }
    return FIELD_PLAYER_GRID_RESULT_HOP_FALL;
}


int func_021A48C8(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl = func_021A3960(grid->core);
    int result = FIELD_PLAYER_GRID_RESULT_NONE;

    switch (grid->state) {
    case FIELD_PLAYER_GRID_STATE_STAND:
        result = func_021A491C(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_WALK:
        result = func_021A4994(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_TURN:
        result = func_021A4A74(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_BLOCKED:
        result = func_021A4AA8(grid, mmdl, request);
        break;
    }
    return result;
}


int func_021A491C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (func_0216D3CC(mmdl) == 1) {
        if (request->dir != FIELD_PLAYER_GRID_DIR_NONE) {
            u32 curDir = func_0216D5F8(mmdl);
            if (request->dir != curDir && request->isDash == 0) {
                return FIELD_PLAYER_GRID_RESULT_TURN;
            }
            return func_021A4994(grid, mmdl, request);
        }
        return FIELD_PLAYER_GRID_RESULT_STAND;
    }
    return FIELD_PLAYER_GRID_RESULT_NONE;
}


int func_021A4960(int attrKind)
{
    if (func_021AB140(attrKind) != 0 || func_021AB404(attrKind) != 0 || func_021AB410(attrKind) != 0 || func_021AB328(attrKind) != 0)
        return 1;
    return 0;
}


/*
 * Twin of func_021A4598; the final attribute test also consults
 * func_021A4960 on the tile id.
 */
int func_021A4994(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int attr;
    u32 hitFlags;
    u16 attrKind;
    u32 attrBits;
    int ledgeDir;

    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return func_021A491C(grid, mmdl, request);
    }
    hitFlags = func_021A5264(grid, mmdl, request->dir, &attr);
    if (request->isDash == 1 && hitFlags != 0 && !(hitFlags & 0x10)) {
        hitFlags = 0;
    }
    if (attr != -1) {
        attrKind = func_021AB0F0(attr);
        attrBits = func_021AB0F8(attr);
        if (hitFlags & 2) {
            ledgeDir = FIELD_PLAYER_GRID_DIR_NONE;
            if (func_021AB158(attrKind)) {
                ledgeDir = 0;
            } else if (func_021AB164(attrKind)) {
                ledgeDir = 1;
            } else if (func_021AB170(attrKind)) {
                ledgeDir = 2;
            } else if (func_021AB17C(attrKind)) {
                ledgeDir = 3;
            }
            if (ledgeDir != FIELD_PLAYER_GRID_DIR_NONE && ledgeDir == request->dir) {
                return FIELD_PLAYER_GRID_RESULT_LEDGE_JUMP;
            }
        }
        if (hitFlags == 0) {
            if (!(attrBits & 2) && func_021A4960(attrKind) == 0) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
            if (request->isDash == 1) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
        }
    }
    return FIELD_PLAYER_GRID_RESULT_BLOCKED;
}


int func_021A4A74(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (func_0216D3CC(mmdl) == 0)
        return FIELD_PLAYER_GRID_RESULT_NONE;
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE)
        return func_021A491C(grid, mmdl, request);
    return func_021A4994(grid, mmdl, request);
}


int func_021A4AA8(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    u32 curDir = func_0216D5F8(mmdl);

    if (request->dir != FIELD_PLAYER_GRID_DIR_NONE && request->dir != curDir) {
        func_0216D4B4(mmdl);
        return func_021A4994(grid, mmdl, request);
    }
    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return func_021A491C(grid, mmdl, request);
    }
    return func_021A4994(grid, mmdl, request);
}


int func_021A4B00(FieldPlayerGrid *grid, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl = func_021A3960(grid->core);
    int result = FIELD_PLAYER_GRID_RESULT_NONE;

    switch (grid->state) {
    case FIELD_PLAYER_GRID_STATE_STAND:
        result = func_021A4B54(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_WALK:
        result = func_021A4B98(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_TURN:
        result = func_021A4C1C(grid, mmdl, request);
        break;
    case FIELD_PLAYER_GRID_STATE_BLOCKED:
        result = func_021A4C50(grid, mmdl, request);
        break;
    }
    return result;
}


int func_021A4B54(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (func_0216D3CC(mmdl) == 1) {
        if (request->dir != FIELD_PLAYER_GRID_DIR_NONE) {
            u32 curDir = func_0216D5F8(mmdl);
            if (request->dir != curDir && request->isDash == 0) {
                return FIELD_PLAYER_GRID_RESULT_TURN;
            }
            return func_021A4B98(grid, mmdl, request);
        }
        return FIELD_PLAYER_GRID_RESULT_STAND;
    }
    return FIELD_PLAYER_GRID_RESULT_NONE;
}


int func_021A4B98(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int attr;
    u32 hitFlags;

    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return func_021A4B54(grid, mmdl, request);
    }
    hitFlags = func_021A5264(grid, mmdl, request->dir, &attr);
    if (request->isDash == 1 && hitFlags != 0 && !(hitFlags & 0x10)) {
        hitFlags = 0;
    }
    if (attr != -1) {
        u32 attrBits;
        func_021AB0F0(attr);
        attrBits = func_021AB0F8(attr);
        if (hitFlags == 0) {
            if (attrBits & 2) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
            if (request->isDash == 1) {
                return FIELD_PLAYER_GRID_RESULT_WALK;
            }
        }
    }
    return FIELD_PLAYER_GRID_RESULT_BLOCKED;
}


int func_021A4C1C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    if (func_0216D3CC(mmdl) == 0)
        return FIELD_PLAYER_GRID_RESULT_NONE;
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE)
        return func_021A4B54(grid, mmdl, request);
    return func_021A4B98(grid, mmdl, request);
}


int func_021A4C50(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    u32 curDir = func_0216D5F8(mmdl);

    if (request->dir != FIELD_PLAYER_GRID_DIR_NONE && request->dir != curDir) {
        func_0216D4B4(mmdl);
        return func_021A4B98(grid, mmdl, request);
    }
    if (func_0216D3CC(mmdl) == 0) {
        return FIELD_PLAYER_GRID_RESULT_NONE;
    }
    if (request->dir == FIELD_PLAYER_GRID_DIR_NONE) {
        return func_021A4B54(grid, mmdl, request);
    }
    return func_021A4B98(grid, mmdl, request);
}


void func_021A4CA8(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request)
{
    switch (func_021A3974(grid->core)) {
    case FIELD_PLAYER_AVATAR_FORM_NORMAL:
        func_021A4CF4(grid, result, request);
        return;
    case FIELD_PLAYER_AVATAR_FORM_CYCLE:
        func_021A4FA8(grid, result, request);
        return;
    case FIELD_PLAYER_AVATAR_FORM_SURF:
    case FIELD_PLAYER_AVATAR_FORM_DIVE:
        func_021A5148(grid, result, request);
        break;
    }
}


void func_021A4CF4(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl = func_021A3960(grid->core);

    switch (result) {
    case FIELD_PLAYER_GRID_RESULT_NONE: func_021A4D8C(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_STAND: func_021A4D90(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_WALK: func_021A4DC0(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_TURN: func_021A4E78(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_BLOCKED: func_021A4E9C(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_LEDGE_JUMP: func_021A4ED8(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_HOLD: func_021A4F04(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_HOP: func_021A4F0C(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_HOP_AIR: func_021A4F50(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_HOP_FALL: func_021A4F58(grid, mmdl, request); break;
    }
}


/* Unlabelled leaf (no lr save), filed because it blocks the caller's MATCH. */
void func_021A4D8C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
}


void func_021A4D90(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int dir = request->dir;

    if (dir == FIELD_PLAYER_GRID_DIR_NONE)
        dir = func_0216D5F8(mmdl);
    func_0216D410(mmdl, func_02197E7C(dir, FIELD_PLAYER_GRID_ACMD_STAND));
    grid->state = FIELD_PLAYER_GRID_STATE_STAND;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
}


void func_021A4DC0(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    VecFx32 pos;
    int attr;
    u32 acmdBase;
    int checkSlope = 1;

    if (request->isDash == 1) {
        acmdBase = FIELD_PLAYER_GRID_ACMD_DASH;
        checkSlope = 0;
    } else if ((request->dashAllowed & 1) && (request->keyHeld & 2)) {
        if (func_021A3A20(grid->core) == 0) {
            acmdBase = FIELD_PLAYER_GRID_ACMD_RUN;
        } else {
            acmdBase = FIELD_PLAYER_GRID_ACMD_RUN_SPECIAL;
            func_021A5304(grid, FIELD_PLAYER_GRID_FLAG_SPECIAL_WALK);
            func_021A3898(grid->core, &pos);
            if (func_02163E34(mmdl, &pos, &attr) != 0) {
                if (func_021AB44C(func_021AB0F0(attr)) != 0) {
                    acmdBase = FIELD_PLAYER_GRID_ACMD_WALK;
                    checkSlope = 0;
                    func_021A530C(grid, FIELD_PLAYER_GRID_FLAG_SPECIAL_WALK);
                }
            }
        }
    } else {
        acmdBase = FIELD_PLAYER_GRID_ACMD_WALK;
    }
    if (checkSlope == 1) {
        if (func_021A57C0(grid, request->dir) == 1) {
            switch (acmdBase) {
            case FIELD_PLAYER_GRID_ACMD_RUN: acmdBase = FIELD_PLAYER_GRID_ACMD_RUN_SLOPE_UP; break;
            case FIELD_PLAYER_GRID_ACMD_RUN_SPECIAL: acmdBase = FIELD_PLAYER_GRID_ACMD_RUN_SPECIAL_SLOPE_UP; break;
            case FIELD_PLAYER_GRID_ACMD_WALK: acmdBase = FIELD_PLAYER_GRID_ACMD_WALK_SLOPE_UP; break;
            }
        }
    }
    func_0216D410(mmdl, func_02197E7C(request->dir, acmdBase));
    grid->state = FIELD_PLAYER_GRID_STATE_WALK;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_WALK);
}


void func_021A4E78(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    func_0216D410(mmdl, func_02197E7C(request->dir, FIELD_PLAYER_GRID_ACMD_TURN));
    grid->state = FIELD_PLAYER_GRID_STATE_TURN;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_RUN);
}


void func_021A4E9C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    func_0216D410(mmdl, func_02197E7C(request->dir, FIELD_PLAYER_GRID_ACMD_BLOCKED));
    grid->state = FIELD_PLAYER_GRID_STATE_BLOCKED;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
    if (func_021A5810(grid, request->dir) == 0)
        func_020061E4(FIELD_PLAYER_GRID_SE_BLOCKED);
}


void func_021A4ED8(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    func_0216D410(mmdl, func_02197E7C(request->dir, FIELD_PLAYER_GRID_ACMD_LEDGE_JUMP));
    grid->state = FIELD_PLAYER_GRID_STATE_WALK;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_WALK);
    func_020061E4(FIELD_PLAYER_GRID_SE_LEDGE_JUMP);
}


void func_021A4F04(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    grid->state = FIELD_PLAYER_GRID_STATE_HOLD;
}


void func_021A4F0C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    u32 dir = request->dir;

    if (dir == FIELD_PLAYER_GRID_DIR_NONE) {
        dir = func_021A5630(grid);
    }
    func_0216D410(mmdl, func_02197E7C(dir, FIELD_PLAYER_GRID_ACMD_HOP));
    func_0216DB4C(mmdl, 1);
    func_0216DCE8(mmdl, 1);
    func_0216D568(mmdl, MMDL_MOVEBIT_SHOAL_SET);
    grid->state = FIELD_PLAYER_GRID_STATE_HOP;
}


void func_021A4F50(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    grid->state = FIELD_PLAYER_GRID_STATE_HOP_AIR;
}


/*
 * The function returns int: pos.y when the height is already at or under the
 * limit, 7 (the new state) otherwise. The only caller (func_021A4CF4, case 9)
 * discards the value. Returning pos.y on the early path ties the cross-block
 * pos.y value to r0 (the return register), so the block-2 constant 0x8000 goes
 * to r1 and the subtract reads `subs r0, r0, r1`; the void form colours the
 * constant first into r0 and gives `subs r0, r1, r0` (three earlier rounds,
 * dozens of spellings). Leaving the final `return 7` out recolours the 7 to r1.
 * See docs/idioms/a-value-returned-on-the-early-path-precolours-its-register-to-r0.md.
 */
int func_021A4F58(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    Mmdl *playerMmdl = func_021A3960(grid->core);
    VecFx32 pos;
    int groundHeight;

    func_0216D88C(playerMmdl, &pos);
    func_02163E58(playerMmdl, &pos, &groundHeight);
    if (pos.y > groundHeight) {
        pos.y -= 0x8000;
        if (pos.y < groundHeight) {
            pos.y = groundHeight;
            func_0216D570(playerMmdl, MMDL_MOVEBIT_SHOAL_SET);
            grid->hopLanded = 1;
        }
        func_0216D89C(playerMmdl, &pos);
        grid->state = FIELD_PLAYER_GRID_STATE_HOP_FALL;
        return 7;
    }
    return pos.y;
}


void func_021A4FA8(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl = func_021A3960(grid->core);

    switch (result) {
    case FIELD_PLAYER_GRID_RESULT_NONE: func_021A5010(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_STAND: func_021A5014(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_WALK: func_021A5044(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_TURN: func_021A50BC(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_BLOCKED: func_021A50E0(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_LEDGE_JUMP: func_021A511C(grid, mmdl, request); break;
    }
}


void func_021A5010(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
}


void func_021A5014(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int dir = request->dir;

    if (dir == FIELD_PLAYER_GRID_DIR_NONE)
        dir = func_0216D5F8(mmdl);
    func_0216D410(mmdl, func_02197E7C(dir, FIELD_PLAYER_GRID_ACMD_STAND));
    grid->state = FIELD_PLAYER_GRID_STATE_STAND;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
}


void func_021A5044(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int attr;
    u32 acmdBase;
    int checkSlope = 1;

    if (request->isDash == 1) {
        acmdBase = FIELD_PLAYER_GRID_ACMD_DASH;
        checkSlope = 0;
    } else {
        acmdBase = FIELD_PLAYER_GRID_ACMD_DASH;
        if (func_021A5788(grid, FIELD_PLAYER_GRID_DIR_NONE, &attr) == 1) {
            if (func_021AB41C(func_021AB0F0(attr)) == 1) {
                acmdBase = FIELD_PLAYER_GRID_ACMD_CYCLE_SPECIAL;
                func_021AC528(mmdl, func_02188CD0(grid->fieldMap));
            }
        }
    }
    if (checkSlope == 1) {
        if (func_021A57C0(grid, request->dir) == 1) {
            if (acmdBase == FIELD_PLAYER_GRID_ACMD_DASH) {
                acmdBase = FIELD_PLAYER_GRID_ACMD_RUN;
            }
        }
    }
    func_0216D410(mmdl, func_02197E7C(request->dir, acmdBase));
    grid->state = FIELD_PLAYER_GRID_STATE_WALK;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_WALK);
}


void func_021A50BC(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    func_0216D410(mmdl, func_02197E7C(request->dir, FIELD_PLAYER_GRID_ACMD_TURN));
    grid->state = FIELD_PLAYER_GRID_STATE_TURN;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_RUN);
}


void func_021A50E0(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    func_0216D410(mmdl, func_02197E7C(request->dir, FIELD_PLAYER_GRID_ACMD_BLOCKED));
    grid->state = FIELD_PLAYER_GRID_STATE_BLOCKED;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
    if (func_021A5810(grid, request->dir) == 0)
        func_020061E4(FIELD_PLAYER_GRID_SE_BLOCKED);
}


void func_021A511C(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    func_0216D410(mmdl, func_02197E7C(request->dir, FIELD_PLAYER_GRID_ACMD_LEDGE_JUMP));
    grid->state = FIELD_PLAYER_GRID_STATE_WALK;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_WALK);
    func_020061E4(FIELD_PLAYER_GRID_SE_LEDGE_JUMP);
}


void func_021A5148(FieldPlayerGrid *grid, u32 result, FieldPlayerGridMoveRequest *request)
{
    Mmdl *mmdl = func_021A3960(grid->core);

    switch (result) {
    case FIELD_PLAYER_GRID_RESULT_NONE: func_021A51A4(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_STAND: func_021A51A8(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_WALK: func_021A51D8(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_TURN: func_021A5204(grid, mmdl, request); return;
    case FIELD_PLAYER_GRID_RESULT_BLOCKED: func_021A5228(grid, mmdl, request); break;
    }
}


void func_021A51A4(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
}


void func_021A51A8(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int dir = request->dir;

    if (dir == FIELD_PLAYER_GRID_DIR_NONE)
        dir = func_0216D5F8(mmdl);
    func_0216D410(mmdl, func_02197E7C(dir, FIELD_PLAYER_GRID_ACMD_STAND));
    grid->state = FIELD_PLAYER_GRID_STATE_STAND;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
}


void func_021A51D8(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    int acmdBase = (request->isDash == 1) ? FIELD_PLAYER_GRID_ACMD_DASH : FIELD_PLAYER_GRID_ACMD_RUN;

    func_0216D410(mmdl, func_02197E7C(request->dir, acmdBase));
    grid->state = FIELD_PLAYER_GRID_STATE_WALK;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_WALK);
}


void func_021A5204(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    func_0216D410(mmdl, func_02197E7C(request->dir, FIELD_PLAYER_GRID_ACMD_TURN));
    grid->state = FIELD_PLAYER_GRID_STATE_TURN;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_RUN);
}


void func_021A5228(FieldPlayerGrid *grid, Mmdl *mmdl, FieldPlayerGridMoveRequest *request)
{
    func_0216D410(mmdl, func_02197E7C(request->dir, FIELD_PLAYER_GRID_ACMD_BLOCKED));
    grid->state = FIELD_PLAYER_GRID_STATE_BLOCKED;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
    if (func_021A5810(grid, request->dir) == 0)
        func_020061E4(FIELD_PLAYER_GRID_SE_BLOCKED);
}


int func_021A5264(FieldPlayerGrid *grid, Mmdl *mmdl, u32 dir, int *outAttr)
{
    VecFx32 pos;
    int gridZ;
    int gridY;
    int hitFlags;
    int stepX;
    stepX = func_0216D83C(mmdl);
    gridY = func_0216D854(mmdl);
    gridZ = func_0216D86C(mmdl);
    stepX = (short)(stepX + func_021641E8(dir));
    hitFlags = (short)(gridZ + func_021641F8(dir));
    stepX = func_02163994(mmdl, stepX, gridY, hitFlags, dir);
    func_0216D88C(mmdl, &pos);
    func_02164208(dir, &pos, 0x10000);
    if (func_02163E34(mmdl, &pos, outAttr) == 0) {
        *outAttr = -1;
    }
    if (stepX & 2) {
        if (func_021AB2DC(func_021AB0F0(*outAttr)) == 1) {
            if (func_0216E5B0(func_0216D67C(mmdl), &pos) == 1) {
                stepX &= ~2;
            }
        }
    }
    return stepX;
}


void func_021A5304(FieldPlayerGrid *grid, u32 mask)
{
    grid->flags = (mask | grid->flags);
}


void func_021A530C(FieldPlayerGrid *grid, u32 mask)
{
    grid->flags = ((~mask) & grid->flags);
}


int func_021A5318(FieldPlayerGrid *grid, u32 mask)
{
    if (grid->flags & mask)
        return 1;
    return 0;
}


void func_021A5328(FieldPlayerGrid *grid)
{
    func_021A5304(grid, FIELD_PLAYER_GRID_FLAG_FORCED_MOVE);
}


void func_021A5334(FieldPlayerGrid *grid)
{
    func_021A530C(grid, FIELD_PLAYER_GRID_FLAG_FORCED_MOVE);
}


int func_021A5340(FieldPlayerGrid *grid)
{
    int isForced = 1;

    if (func_021A5318(grid, FIELD_PLAYER_GRID_FLAG_FORCED_MOVE) == 0)
        isForced = 0;
    return isForced;
}


void func_021A5354(FieldPlayerGrid *grid)
{
    func_021A5304(grid, FIELD_PLAYER_GRID_FLAG_NO_FORCED_MOVE);
}


void func_021A5360(FieldPlayerGrid *grid)
{
    func_021A530C(grid, FIELD_PLAYER_GRID_FLAG_NO_FORCED_MOVE);
}


void func_021A536C(FieldPlayerGrid *grid)
{
    func_021A530C(grid, FIELD_PLAYER_GRID_FLAG_STEP_PENDING);
}


void func_021A5378(FieldPlayerGrid *grid, int on)
{
    if (on == 1)
        func_021A5304(grid, FIELD_PLAYER_GRID_FLAG_HOLD);
    else
        func_021A530C(grid, FIELD_PLAYER_GRID_FLAG_HOLD);
}


int func_021A5390(FieldPlayerGrid *grid)
{
    if (func_021A5318(grid, FIELD_PLAYER_GRID_FLAG_HOLD) != 0) {
        return 1;
    }
    return 0;
}


void func_021A53A4(FieldPlayerGrid *grid, int on)
{
    if (on == 1)
        func_021A5304(grid, FIELD_PLAYER_GRID_FLAG_HOP);
    else
        func_021A530C(grid, FIELD_PLAYER_GRID_FLAG_HOP);
}


int func_021A53BC(FieldPlayerGrid *grid)
{
    if (func_021A5318(grid, FIELD_PLAYER_GRID_FLAG_HOP) != 0) {
        return 1;
    }
    return 0;
}


void func_021A53D0(FieldPlayerGrid *grid)
{
    Mmdl *mmdl;
    int dir;

    if (grid->state == FIELD_PLAYER_GRID_STATE_BLOCKED) {
        mmdl = func_021A3960(grid->core);
        dir = func_0216D5F8(mmdl);
        func_0216D4B4(mmdl);
        func_0216D5E0(mmdl, dir);
        func_0216D674(mmdl, 0);
        func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
    }
}


int func_021A5408(FieldPlayerGrid *grid)
{
    Mmdl *mmdl;
    u32 dir;

    switch (grid->state) {
    case FIELD_PLAYER_GRID_STATE_STAND:
        break;
    case FIELD_PLAYER_GRID_STATE_WALK:
        return 0;
    case FIELD_PLAYER_GRID_STATE_TURN:
    case FIELD_PLAYER_GRID_STATE_BLOCKED:
        mmdl = func_021A572C(grid);
        dir = func_0216D5F8(mmdl);
        func_0216D4B4(mmdl);
        func_0216D5E0(mmdl, dir);
        func_0216D674(mmdl, 0);
        func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
        break;
    }
    return 1;
}


int func_021A5458(FieldPlayerGrid *grid, int unused)
{
    int attrKind = func_0216D7DC(func_021A3960(grid->core));

    if (func_021A5318(grid, FIELD_PLAYER_GRID_FLAG_NO_FORCED_MOVE) == 0 && func_021AB348(func_021AB0F0(attrKind)) == 1)
        return 1;
    return 0;
}


int func_021A548C(FieldPlayerGrid *grid)
{
    if (func_021A5458(grid, FIELD_PLAYER_GRID_DIR_NONE) != 0) {
        return 1;
    }
    return 0;
}


int func_021A54A0(FieldPlayerGrid *grid)
{
    if (func_021A53BC(grid) == 1) {
        return 1;
    }
    return 0;
}


void func_021A54B4(FieldPlayerGrid *grid)
{
    VecFx32 pos;
    Mmdl *mmdl = func_021A3960(grid->core);

    func_0216DB4C(mmdl, 0);
    func_0216DCE8(mmdl, 0);
    func_0216D568(mmdl, FIELD_PLAYER_GRID_MMDL_STEP_END_BITS);
    func_02164010(mmdl);
    func_0216D88C(mmdl, &pos);
    func_0216D85C(mmdl, (s16)((pos.y >> 4) / 4096));
    func_021640B0(mmdl);
    func_02163F10(mmdl);
}


void func_021A550C(FieldPlayerGrid *grid)
{
    if (func_021A5340(grid) == 1) {
        func_0216D550(func_021A3960(grid->core), FIELD_PLAYER_GRID_MMDL_PAUSE_BITS);
        func_021A5334(grid);
    }
}


u32 func_021A552C(FieldPlayerGrid *grid)
{
    func_021A550C(grid);

    return 0x0;
}


int func_021A5538(FieldPlayerGrid *grid)
{
    int attr;
    Mmdl *mmdl = func_021A3960(grid->core);
    u32 dir = func_0216D608(mmdl);

    if (func_021A5264(grid, mmdl, dir, &attr) != 0) {
        func_021A550C(grid);
        func_021A5354(grid);
        func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_NONE);
        return 0;
    }
    func_021A5328(grid);
    func_0216D410(mmdl, func_02197E7C(dir, FIELD_PLAYER_GRID_ACMD_RUN));
    func_0216D548(mmdl, FIELD_PLAYER_GRID_MMDL_PAUSE_BITS);
    grid->state = FIELD_PLAYER_GRID_STATE_WALK;
    func_021A3964(grid->core, FIELD_PLAYER_GRID_STEP_KIND_WALK);
    return 1;
}


int func_021A55A8(FieldPlayerGrid *grid, u32 dir, int skip)
{
    if (skip == 0) {
        if (data_021D89EC[func_021A5458(grid, dir)](grid, dir) == 1)
            return 1;
    }
    func_021A5334(grid);
    return 0;
}


int func_021A55DC(int attrKind)
{
    if (func_021AB404(attrKind) == 1 || func_021AB410(attrKind) == 1)
        return 1;
    return 0;
}


int func_021A55FC(int attrKind)
{
    if (func_021AB404(attrKind) == 1) {
        return 1;
    }
    return 0;
}


int func_021A5610(FieldPlayerGrid *grid)
{
    int attr;

    func_021A5788(grid, FIELD_PLAYER_GRID_DIR_NONE, &attr);
    if (func_021A55FC(func_021AB0F0(attr)) == 1)
        return 1;
    return 0;
}


u32 func_021A5630(FieldPlayerGrid *grid)
{
    int attr;
    u16 dirTable[4];
    u16 tries;
    u32 dir;
    u16 *nextDir = dirTable;

    dirTable[0] = d_021D8A24[0];
    dirTable[1] = d_021D8A24[1];
    dirTable[2] = d_021D8A24[2];
    dirTable[3] = d_021D8A24[3];
    dir = func_021A3920(grid->core);
    tries = 0;
    do {
        if (func_021A5788(grid, dir, &attr) == 1) {
            if (func_021A55DC(func_021AB0F0(attr)) == 0) {
                if (func_021AB11C(attr) == 0) {
                    return dir;
                }
            }
        }
        tries = tries + 1;
        dir = nextDir[dir];
    } while (tries < 4);
    return FIELD_PLAYER_GRID_DIR_NONE;
}


int func_021A569C(FieldPlayerGrid *grid, Mmdl *mmdl, int dir, int *outAttr)
{
    int hitFlags = func_021A5264(grid, mmdl, dir, outAttr);

    if (func_021A55DC(func_021AB0F0(*outAttr)) == 1)
        hitFlags |= 0x100;
    return hitFlags;
}


u32 func_021A56C0(FieldPlayerGrid *grid, u32 unused1, u32 unused2)
{
    Mmdl *mmdl = func_021A3960(grid->core);
    VecFx32 pos;
    int groundHeight;

    func_0216D88C(mmdl, &pos);
    func_02163E58(mmdl, &pos, &groundHeight);
    if (pos.y <= groundHeight)
        return 1;
    return 0;
}


void func_021A56F4(FieldPlayerGrid *grid)
{
    func_021A5378(grid, 1);
    func_021A39AC(grid->core, 7);
}


void func_021A5708(FieldPlayerGrid *grid)
{
    grid->holdFrames = 0;
    grid->holdEffectPending = 0;
    func_021A53A4(grid, 0);
    func_021A5378(grid, 0);
    func_021A3998(grid->core);
}


FieldPlayerCore *func_021A5728(FieldPlayerGrid *grid)
{
    return grid->core;
}


/* Tail-call thunk: the model of the core. */
Mmdl *func_021A572C(FieldPlayerGrid *grid)
{
    return func_021A3960(grid->core);
}


void func_021A5738(FieldPlayerGrid *grid, int keepFrame)
{
    u16 savedFrames;

    if (func_021A5390(grid) == 1) {
        savedFrames = grid->holdFrames;
        func_021A5708(grid);
        if (keepFrame == 1) {
            grid->holdFrames = savedFrames;
            grid->holdEffectPending = 1;
        }
    }
}


/* Tail-call thunk: forwards to func_021A550C with no argument change. */
void func_021A575C(FieldPlayerGrid *grid)
{
    func_021A550C(grid);
}


u32 func_021A5764(FieldPlayerGrid *grid)
{
    return grid->hopLanded;
}


int func_021A5768(FieldPlayerGrid *grid, u32 landed)
{
    if (landed == 1) {
        grid->hopLanded = 1;
        return (int)grid;
    }
    grid->hopLanded = 0;
    return (int)grid;
}


int func_021A5778(FieldPlayerGrid *grid)
{
    if (grid->state == FIELD_PLAYER_GRID_STATE_BLOCKED) {
        return 1;
    }
    return 0;
}


int func_021A5788(FieldPlayerGrid *grid, int dir, int *outAttr)
{
    VecFx32 pos;

    func_021A3898(grid->core, &pos);
    if (dir != FIELD_PLAYER_GRID_DIR_NONE)
        func_02164208(dir, &pos, 0x10000);
    return func_02163E34(func_021A3960(grid->core), &pos, outAttr);
}


int func_021A57C0(FieldPlayerGrid *grid, int dir)
{
    Mmdl *mmdl;
    int curHeight;
    VecFx32 pos;
    int destHeight;

    mmdl = func_021A3960(grid->core);
    func_0216D88C(mmdl, &pos);
    curHeight = pos.y;
    func_02164208(dir, &pos, 0x10000);
    if (func_02163E58(mmdl, &pos, &destHeight) == 1) {
        if (curHeight < destHeight) {
            return 1;
        }
        if (curHeight > destHeight) {
            return 2;
        }
    }
    return 0;
}


int func_021A5810(FieldPlayerGrid *grid, int dir)
{
    Mmdl *mmdl;
    void *eventData;
    int connectIndex;
    VecFx32 pos;

    mmdl = func_021A3960(grid->core);
    eventData = func_02012844(func_020120F4(func_02188C80(grid->fieldMap)));
    func_0216D88C(mmdl, &pos);
    func_02164208(dir, &pos, 0x10000);
    connectIndex = func_02162564(eventData, &pos);
    if (connectIndex == 0xffff) {
        return 0;
    }
    if (func_021626B8(func_021625CC(eventData, (u16)connectIndex), dir)) {
        return 1;
    }
    return 0;
}
