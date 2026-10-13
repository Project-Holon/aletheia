/*
 * file:     field_player.c
 * unit:     yes
 * function: func_021A2E50, func_021A2E90, func_021A2EB8, func_021A2F20, func_021A2F48, func_021A2F54, func_021A2F60, func_021A2F6C, func_021A2F8C, func_021A2F98, func_021A2FA4, func_021A2FB0, func_021A2FD0, func_021A2FE4, func_021A3038, func_021A3044, func_021A3050, func_021A305C, func_021A3068, func_021A3074, func_021A3080, func_021A308C, func_021A3098, func_021A30A4, func_021A30B0, func_021A30BC, func_021A30C8, func_021A3128, func_021A3190, func_021A31A4, func_021A31D0, func_021A3208, func_021A3220, func_021A322C, func_021A3238, func_021A3244, func_021A3250, func_021A32A8, func_021A330C, func_021A3364, func_021A3460, func_021A3484, func_021A34EC, func_021A34F8, func_021A3504, func_021A3524, func_021A3550, func_021A356C, func_021A3584, func_021A35A0, func_021A35BC, func_021A35E0, func_021A35F0, func_021A35FC, func_021A3624, func_021A3644, func_021A3664, func_021A3674, func_021A3680, func_021A368C, func_021A3698, func_021A36A4, func_021A36B0, func_021A36BC, func_021A36C8, func_021A36D4, func_021A36E0
 * address:  0x021A2E50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A2E8C (d_021DDEA8 "field_player.c"); wrapper layer that forwards to core (+4), grid (+8) and nogrid (+C) objects.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   d_021DDEA8     0x021DDEA8  data  a4
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02012A90  0x02012A90  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02012AD4  0x02012AD4  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_02012ABC  0x02012ABC  thumb
 *   func_0219E2F4  0x0219E2F4  thumb
 *   func_02012AA4  0x02012AA4  thumb
 *   func_021C0CA4  0x021C0CA4  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021BB3C4  0x021BB3C4  thumb
 *   func_0219E664  0x0219E664  thumb
 *   data_021D890C  0x021D890C  data
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_0219E634  0x0219E634  thumb
 *   func_0219E570  0x0219E570  thumb
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_021B7C38  0x021B7C38  thumb  ov021
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_021AB5AC  0x021AB5AC  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB310  0x021AB310  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_021A36E4  0x021A36E4  thumb  ov021
 *   func_021A3810  0x021A3810  thumb  ov021
 *   func_021A3818  0x021A3818  thumb  ov021
 *   func_021A3898  0x021A3898  thumb  ov021
 *   func_021A38A4  0x021A38A4  thumb  ov021
 *   func_021A3920  0x021A3920  thumb  ov021
 *   func_021A392C  0x021A392C  thumb  ov021
 *   func_021A3938  0x021A3938  thumb  ov021
 *   func_021A394C  0x021A394C  thumb  ov021
 *   func_021A395C  0x021A395C  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A3968  0x021A3968  thumb  ov021
 *   func_021A396C  0x021A396C  thumb  ov021
 *   func_021A3970  0x021A3970  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3980  0x021A3980  thumb  ov021
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A3990  0x021A3990  thumb  ov021
 *   func_021A3994  0x021A3994  thumb  ov021
 *   func_021A39E4  0x021A39E4  thumb  ov021
 *   func_021A3A10  0x021A3A10  thumb  ov021
 *   func_021A3A20  0x021A3A20  thumb  ov021
 *   func_021A3A3C  0x021A3A3C  thumb  ov021
 *   func_021A3AB8  0x021A3AB8  thumb  ov021
 *   func_021A3AD0  0x021A3AD0  thumb  ov021
 *   func_021A3AD4  0x021A3AD4  thumb  ov021
 *   func_021A3CB0  0x021A3CB0  thumb  ov021
 *   func_021A3CC0  0x021A3CC0  thumb  ov021
 *   func_021A3CE8  0x021A3CE8  thumb  ov021
 *   func_021A4140  0x021A4140  thumb  ov021
 *   func_021A41A8  0x021A41A8  thumb  ov021
 *   func_021A41B0  0x021A41B0  thumb  ov021
 *   func_021A53D0  0x021A53D0  thumb  ov021
 *   func_021A548C  0x021A548C  thumb  ov021
 *   func_021A54A0  0x021A54A0  thumb  ov021
 *   func_021A54B4  0x021A54B4  thumb  ov021
 *   func_021A5738  0x021A5738  thumb  ov021
 *   func_021A575C  0x021A575C  thumb  ov021
 *   func_021A5764  0x021A5764  thumb  ov021
 *   func_021A5768  0x021A5768  thumb  ov021
 *   func_021A5778  0x021A5778  thumb  ov021
 *   func_021A5880  0x021A5880  thumb  ov021
 *   func_021A5920  0x021A5920  thumb  ov021
 *   func_021A5928  0x021A5928  thumb  ov021
 *   func_021A5964  0x021A5964  thumb  ov021
 *   func_021A596C  0x021A596C  thumb  ov021
 *   func_021A59DC  0x021A59DC  thumb  ov021
 *   func_021A59EC  0x021A59EC  thumb  ov021
 *   func_021A5A00  0x021A5A00  thumb  ov021
 *   func_021A5A0C  0x021A5A0C  thumb  ov021
 *   func_021A5A18  0x021A5A18  thumb  ov021
 *   func_021A5A24  0x021A5A24  thumb  ov021
 *   func_021A5A30  0x021A5A30  thumb  ov021
 *   func_021A5A34  0x021A5A34  thumb  ov021
 */
#include "field_player_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;

/* A grid position or fixed point vector (three words). */
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} FieldPlayerLocationPos;

/* A rail location as a pair of words. */
typedef struct {
    s32 a;
    s32 b;
} FieldPlayerRailLocation;

struct GameData;
struct FieldG3dMapper;
struct FieldNogridMapper;

extern u32 func_020307B0(void *work);
extern void *func_02030734(u32 heapId, u32 size, int align, const char *file, u16 line);
extern void func_0216D88C(const Mmdl *mmdl, VecFx32 *pos);
extern void func_02012A90(struct PlayerWork *playerWork, const FieldPlayerLocationPos *pos);
extern u16 func_0216D5F8(const Mmdl *mmdl);
extern void func_02012AD4(struct PlayerWork *playerWork, int dir);
extern u32 func_02188CFC(FieldMap *fieldMap);
extern void func_02012ABC(struct PlayerWork *playerWork, u8 moveForm);
extern void func_0219E2F4(const Mmdl *mmdl, void *railLocation);
extern void func_02012AA4(struct PlayerWork *playerWork, const void *railLocation);
extern int func_021C0CA4(FieldPlayerGrid *grid, int a, int b, int c);
extern struct FieldG3dMapper *func_02188C98(FieldMap *fieldMap);
extern int func_021AB0D4(struct FieldG3dMapper *g3dMapper, FieldPlayerLocationPos *pos);
extern struct FieldNogridMapper *func_02188C5C(FieldMap *fieldMap);
extern u32 func_021BB3C4(struct FieldNogridMapper *mapper, void *railLocation);
extern int func_0219E664(const Mmdl *mmdl, u32 dir, void *railLocation);
extern struct MmdlSys *func_02188C7C(FieldMap *fieldMap);
extern void *func_0216DDC0(struct MmdlSys *mmdlSys, u32 gridX, u32 gridZ, u32 mask);
extern void func_0219E634(const Mmdl *mmdl, void *railLocation);
extern u32 func_0219E570(struct MmdlSys *mmdlSys, void *railLocation, u32 flag);
extern u8 *func_0216DDDC(struct MmdlSys *mmdlSys, u32 gridX, u32 gridZ, s32 posY, s32 limit, u32 mask);
extern u16 func_0216D83C(const Mmdl *mmdl);
extern u16 func_0216D854(const Mmdl *mmdl);
extern u16 func_0216D86C(const Mmdl *mmdl);
extern int func_021641E8(int dir);
extern int func_021641F8(int dir);
extern void func_02164280(int gridX, int gridZ, int *vecPos);
extern void *func_021BB480(struct FieldNogridMapper *mapper);
extern void func_021B7D38(void *railMan, s16 *railLocation, int *pos);
extern void func_0219E784(const Mmdl *mmdl, u32 dir, s16 *offset);
extern int func_021B7C38(void *railMan);
extern void func_0207CCA4();
extern int func_021AB5AC(unsigned long a, unsigned long b);
extern int func_021AB11C(u32 attr);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB310(u16 id);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern void *func_0201296C(struct GameData *gameData);
extern u32 func_020142E8(void *eventWork, s32 flagId);

extern FieldPlayerCore *func_021A36E4(struct PlayerWork *playerWork, FieldMap *fieldMap, const VecFx32 *pos, u32 sex, u16 heapId);
extern void func_021A3810(FieldPlayerCore *core);
extern void func_021A3818(FieldPlayerCore *core);
extern void func_021A3898(FieldPlayerCore *core, VecFx32 *out);
extern void func_021A38A4(FieldPlayerCore *core, VecFx32 *pos);
extern u16 func_021A3920(FieldPlayerCore *core);
extern void func_021A392C(FieldPlayerCore *core, int dir);
extern int func_021A3938(FieldPlayerCore *core, u32 objCode);
extern void func_021A394C(FieldPlayerCore *core);
extern FieldMap *func_021A395C(FieldPlayerCore *core);
extern Mmdl *func_021A3960(FieldPlayerCore *core);
extern u32 func_021A3968(FieldPlayerCore *core);
extern void func_021A396C(FieldPlayerCore *core, u32 stepPhase);
extern u32 func_021A3970(FieldPlayerCore *core);
extern u32 func_021A3974(FieldPlayerCore *core);
extern void func_021A3980(FieldPlayerCore *core, u32 formCode);
extern u32 func_021A398C(FieldPlayerCore *core);
extern struct GameSystem *func_021A3990(FieldPlayerCore *core);
extern struct PlayerWork *func_021A3994(FieldPlayerCore *core);
extern int func_021A39E4(FieldPlayerCore *core);
extern int func_021A3A10(FieldPlayerCore *core);
extern int func_021A3A20(FieldPlayerCore *core);
extern int func_021A3A3C(FieldPlayerCore *core);
extern u16 func_021A3AB8(FieldPlayerCore *core, u32 keys);
extern void func_021A3AD0(FieldPlayerCore *core, u32 rideEffect);
extern u32 func_021A3AD4(FieldPlayerCore *core);
extern FieldPlayerCore *func_021A3CB0(FieldPlayerCore *core, u32 mask);
extern int func_021A3CC0(FieldPlayerCore *core);
extern void func_021A3CE8(FieldPlayerCore *core);

extern FieldPlayerGrid *func_021A4140(FieldPlayerCore *core, u32 heapId);
extern void func_021A41A8(FieldPlayerGrid *grid);
extern void func_021A41B0(FieldPlayerGrid *grid, u32 a, u32 b, u32 c);
extern void func_021A53D0(FieldPlayerGrid *grid);
extern int func_021A548C(FieldPlayerGrid *grid);
extern int func_021A54A0(FieldPlayerGrid *grid);
extern void func_021A54B4(FieldPlayerGrid *grid);
extern void func_021A5738(FieldPlayerGrid *grid, int a);
extern void func_021A575C(FieldPlayerGrid *grid);
extern u32 func_021A5764(FieldPlayerGrid *grid);
extern int func_021A5768(FieldPlayerGrid *grid, u32 a);
extern int func_021A5778(FieldPlayerGrid *grid);

extern FieldPlayerNogrid *func_021A5880(FieldPlayerCore *core, int heapId);
extern void func_021A5920(FieldPlayerNogrid *nogrid);
extern void func_021A5928(FieldPlayerNogrid *nogrid, int a);
extern void func_021A5964(FieldPlayerNogrid *nogrid);
extern void func_021A596C(FieldPlayerNogrid *nogrid, u32 a, u32 b);
extern int func_021A59DC(FieldPlayerNogrid *nogrid);
extern u32 func_021A59EC(FieldPlayerNogrid *nogrid);
extern void func_021A5A00(FieldPlayerNogrid *nogrid, void *a);
extern void func_021A5A0C(FieldPlayerNogrid *nogrid, void *a);
extern int func_021A5A18(FieldPlayerNogrid *nogrid, u32 a, void *b);
extern void func_021A5A24(FieldPlayerNogrid *nogrid);
extern u32 func_021A5A30(FieldPlayerNogrid *nogrid);
extern void func_021A5A34(FieldPlayerNogrid *nogrid);

void func_021A3038(FieldPlayer *player, VecFx32 *out);
Mmdl *func_021A3074(FieldPlayer *player);
u32 func_021A3098(FieldPlayer *player);
void func_021A3364(FieldPlayer *player, int dir, int *out);
void func_021A3460(FieldPlayer *player, s16 *gridX, s16 *gridY, s16 *gridZ);

extern int d_021DDEA8;
extern const FieldPlayerFormRow data_021D890C[];

/*
 * Addresses are Black-image addresses.
 */
FieldPlayer *func_021A2E50(struct PlayerWork *playerWork, FieldMap *fieldMap, const VecFx32 *pos, u32 sex, u16 heapId)
{
    FieldPlayer *player = func_02030734(heapId, 0x10, 1, (const char *)&d_021DDEA8, 0x4C);

    player->fieldMap = fieldMap;
    player->core = func_021A36E4(playerWork, fieldMap, pos, sex, heapId);
    return player;
}

int func_021A2E90(FieldPlayer *player)
{
    if (player->grid != 0) {
        func_021A41A8(player->grid);
    }
    if (player->nogrid != 0) {
        func_021A5920(player->nogrid);
    }
    func_021A3810(player->core);
    return func_020307B0(player);
}

void func_021A2EB8(FieldPlayer *player)
{
    u8 gridPos[12];
    u8 railLocation[8];
    struct PlayerWork *playerWork = func_021A3994(player->core);
    Mmdl *mmdl = func_021A3960(player->core);

    func_0216D88C(mmdl, (VecFx32 *)gridPos);
    func_02012A90(playerWork, (const FieldPlayerLocationPos *)gridPos);
    func_02012AD4(playerWork, func_0216D5F8(mmdl));
    if (func_02188CFC(player->fieldMap) == 0) {
        func_02012ABC(playerWork, 0);
        return;
    }
    func_0219E2F4(mmdl, railLocation);
    func_02012AA4(playerWork, railLocation);
    func_02012ABC(playerWork, 1);
}

int func_021A2F20(FieldPlayer *player, int a, int b, int c)
{
    int pushed = 0;

    if (func_02188CFC(player->fieldMap) == 0)
        pushed = func_021C0CA4(player->grid, a, b, c);
    return pushed;
}

void func_021A2F48(FieldPlayer *player, u32 mask)
{
    func_021A3CB0(player->core, mask);
}

int func_021A2F54(FieldPlayer *player)
{
    return func_021A3CC0(player->core);
}

void func_021A2F60(FieldPlayer *player)
{
    func_021A3CE8(player->core);
}

void func_021A2F6C(FieldPlayer *player)
{
    if (func_02188CFC(player->fieldMap) == 0)
        func_021A53D0(player->grid);
    else
        func_021A5A34(player->nogrid);
}

void func_021A2F8C(FieldPlayer *player, u32 rideEffect)
{
    func_021A3AD0(player->core, rideEffect);
}

u32 func_021A2F98(FieldPlayer *player)
{
    return func_021A3AD4(player->core);
}

u16 func_021A2FA4(FieldPlayer *player, u32 keys)
{
    return func_021A3AB8(player->core, keys);
}

u32 func_021A2FB0(FieldPlayer *player)
{
    if (func_02188CFC(player->fieldMap) == 0) {
        return func_021A5778(player->grid);
    }
    return func_021A59DC(player->nogrid);
}

void func_021A2FD0(FieldPlayer *player)
{
    func_021A3CB0(player->core, 1);
    func_021A3CE8(player->core);
}

void func_021A2FE4(FieldPlayer *player)
{
    if (func_02188CFC(player->fieldMap) == 0) {
        if (func_021A548C(player->grid) == 1) {
            func_021A396C(player->core, 2);
            return;
        }
        if (func_021A54A0(player->grid) == 1) {
            func_021A396C(player->core, 2);
            return;
        }
    } else {
        if (func_021A59EC(player->nogrid) == 1) {
            func_021A396C(player->core, 2);
            return;
        }
    }
    func_021A3818(player->core);
}

void func_021A3038(FieldPlayer *player, VecFx32 *out)
{
    func_021A3898(player->core, out);
}

void func_021A3044(FieldPlayer *player, VecFx32 *pos)
{
    func_021A38A4(player->core, pos);
}

u16 func_021A3050(FieldPlayer *player)
{
    return func_021A3920(player->core);
}

void func_021A305C(FieldPlayer *player, int dir)
{
    func_021A392C(player->core, dir);
}

FieldMap *func_021A3068(FieldPlayer *player)
{
    return func_021A395C(player->core);
}

Mmdl *func_021A3074(FieldPlayer *player)
{
    return func_021A3960(player->core);
}

u32 func_021A3080(FieldPlayer *player)
{
    return func_021A3968(player->core);
}

u32 func_021A308C(FieldPlayer *player)
{
    return func_021A3970(player->core);
}

u32 func_021A3098(FieldPlayer *player)
{
    return func_021A3974(player->core);
}

void func_021A30A4(FieldPlayer *player, u32 formCode)
{
    func_021A3980(player->core, formCode);
}

u32 func_021A30B0(FieldPlayer *player)
{
    return func_021A398C(player->core);
}

struct GameSystem *func_021A30BC(FieldPlayer *player)
{
    return func_021A3990(player->core);
}

u32 func_021A30C8(FieldPlayer *player)
{
    u32 attr;

    if (func_02188CFC(player->fieldMap) == 0) {
        FieldPlayerLocationPos pos;
        struct FieldG3dMapper *g3dMapper = func_02188C98(player->fieldMap);

        func_021A3038(player, (VecFx32 *)&pos);
        attr = func_021AB0D4(g3dMapper, &pos);
    } else if (func_02188CFC(player->fieldMap) == 1) {
        FieldPlayerRailLocation location;
        Mmdl *mmdl = func_021A3074(player);
        struct FieldNogridMapper *mapper = func_02188C5C(player->fieldMap);

        func_0219E2F4(mmdl, &location);
        attr = func_021BB3C4(mapper, &location);
    }
    return attr;
}

u32 func_021A3128(FieldPlayer *player, u32 dir)
{
    u32 attr;
    u8 frontPos[12];
    u8 railLocation[8];

    if (func_02188CFC(player->fieldMap) == 0) {
        struct FieldG3dMapper *g3dMapper = func_02188C98(player->fieldMap);

        func_021A3364(player, dir, (int *)frontPos);
        attr = func_021AB0D4(g3dMapper, (FieldPlayerLocationPos *)frontPos);
    } else if (func_02188CFC(player->fieldMap) == 1) {
        Mmdl *mmdl = func_021A3074(player);
        struct FieldNogridMapper *mapper = func_02188C5C(player->fieldMap);

        func_0219E664(mmdl, dir, railLocation);
        attr = func_021BB3C4(mapper, railLocation);
    }
    return attr;
}

/* Model code of avatar form slot formSlot in the row for sex. */
u16 func_021A3190(int sex, int formSlot)
{
    return data_021D890C[sex].entries[formSlot].objCode;
}

/* Model code of the entry of row sex whose form code is formCode, else the hero model. */
int func_021A31A4(int sex, int formCode)
{
    const FieldPlayerFormEntry *entry;
    int slot;

    slot = 0;
    entry = data_021D890C[sex].entries;
    for (; slot < FIELD_PLAYER_AVATAR_FORM_COUNT; slot++, entry++) {
        if (entry->formCode == formCode)
            return entry->objCode;
    }
    return FIELD_PLAYER_OBJ_CODE_HERO;
}

/* Form slot whose model code is objCode in either row, else FIELD_PLAYER_AVATAR_FORM_COUNT. */
int func_021A31D0(u16 objCode)
{
    int sex;
    int slot;
    const FieldPlayerFormEntry *entry;

    for (sex = 0; sex < 2; sex++) {
        entry = data_021D890C[sex].entries;
        for (slot = 0; slot < FIELD_PLAYER_AVATAR_FORM_COUNT; slot++) {
            if (entry->objCode == objCode)
                return slot;
            entry++;
        }
    }
    return FIELD_PLAYER_AVATAR_FORM_COUNT;
}

/* 0 while the form code is 2 or 3 (surf, dive), else 1. */
int func_021A3208(FieldPlayer *player)
{
    switch (func_021A3098(player)) {
    case 2:
    case 3:
        return 0;
    }
    return 1;
}

void func_021A3220(FieldPlayer *player, u32 objCode)
{
    func_021A3938(player->core, objCode);
}

void func_021A322C(FieldPlayer *player)
{
    func_021A394C(player->core);
}

int func_021A3238(FieldPlayer *player)
{
    return func_021A3A20(player->core);
}

int func_021A3244(FieldPlayer *player)
{
    return func_021A3A3C(player->core);
}

/*
 * func_0216DDC0 forwards r0-r3 to func_0216DD60, so it takes four
 * arguments; the fourth is the literal 0 whose register the compiler also
 * uses as the v[0] index.
 */
void func_021A3250(FieldPlayer *player)
{
    s16 v[8];
    struct MmdlSys *mmdlSys = func_02188C7C(player->fieldMap);

    if (func_02188CFC(player->fieldMap) == 0) {
        func_021A3460(player, &v[2], &v[1], &v[0]);
        func_0216DDC0(mmdlSys, v[2], v[0], 0);
        return;
    }
    func_0219E634(func_021A3960(player->core), &v[3]);
    func_0219E570(mmdlSys, &v[3], 0);
}

void func_021A32A8(FieldPlayer *player, u32 limit)
{
    s16 v[8];
    struct MmdlSys *mmdlSys = func_02188C7C(player->fieldMap);

    if (func_02188CFC(player->fieldMap) == 0) {
        func_021A3460(player, &v[2], &v[1], &v[0]);
        func_0216DDDC(mmdlSys, v[2], v[0], v[1] << 16, limit, 0);
        return;
    }
    func_0219E634(func_021A3960(player->core), &v[3]);
    func_0219E570(mmdlSys, &v[3], 0);
}

void func_021A330C(FieldPlayer *player, u32 dir, s16 *gridX, s16 *gridY, s16 *gridZ)
{
    Mmdl *mmdl = func_021A3074(player);

    if (func_02188CFC(player->fieldMap) == 0) {
        *gridX = func_0216D83C(mmdl);
        *gridY = func_0216D854(mmdl);
        *gridZ = func_0216D86C(mmdl);
        *gridX = *gridX + func_021641E8(dir);
        *gridZ = *gridZ + func_021641F8(dir);
    }
}

void func_021A3364(FieldPlayer *player, int dir, int *out)
{
    int railPos[3];
    s16 drawOffset[3];
    s16 location[4];
    s16 gridX;
    s16 gridY;
    s16 gridZ;
    Mmdl *mmdl;
    void *railMan;
    int unitScale;

    mmdl = func_021A3960(player->core);
    if (func_02188CFC(player->fieldMap) == 0) {
        func_021A330C(player, dir, &gridX, &gridY, &gridZ);
        func_02164280(gridX, gridZ, out);
        out[1] = gridY << 16;
        return;
    }
    railMan = func_021BB480(func_02188C5C(player->fieldMap));
    func_0219E2F4(mmdl, location);
    func_021B7D38(railMan, location, railPos);
    func_0219E784(mmdl, dir, drawOffset);
    unitScale = func_021B7C38(railMan);
    out[0] = railPos[0] + (int)(((long long)drawOffset[0] * unitScale + 0x800) >> 12);
    out[1] = railPos[1] + (int)(((long long)drawOffset[1] * unitScale + 0x800) >> 12);
    out[2] = railPos[2] + (int)(((long long)drawOffset[2] * unitScale + 0x800) >> 12);
}

void func_021A3460(FieldPlayer *player, s16 *gridX, s16 *gridY, s16 *gridZ)
{
    func_021A330C(player, func_0216D5F8(func_021A3074(player)), gridX, gridY, gridZ);
}

void func_021A3484(FieldPlayer *player, int dir, s32 *out)
{
    s16 offset[4];
    s32 offsetX;
    s32 offsetY;
    s32 offsetZ;
    Mmdl *mmdl = func_021A3960(player->core);

    if (func_02188CFC(player->fieldMap) == 0) {
        s32 dz;

        out[1] = 0;
        out[0] = func_021641E8(dir);
        dz = func_021641F8(dir);
        out[0] = out[0] << 16;
        out[2] = dz << 16;
        func_0207CCA4(out, out);
        return;
    }
    func_0219E784(mmdl, dir, offset);
    offsetZ = offset[2];
    offsetY = offset[1];
    offsetX = offset[0];
    out[0] = offsetX;
    out[1] = offsetY;
    out[2] = offsetZ;
}

int func_021A34EC(FieldPlayer *player)
{
    return func_021A3A10(player->core);
}

int func_021A34F8(FieldPlayer *player)
{
    return func_021A39E4(player->core);
}

int func_021A3504(FieldPlayer *player, int a, int b)
{
    int formCode = func_021A3098(player);

    if (formCode == 2 || formCode == 3)
        return 0;
    return func_021AB5AC(a, b);
}

int func_021A3524(FieldPlayer *player, int attrA, int attrB)
{
    int formCode = func_021A3098(player);

    if (func_021AB11C(attrA) != 0 || formCode != 2)
        return 0;
    return func_021AB310(func_021AB0F0(attrB));
}

void func_021A3550(FieldPlayer *player, int a)
{
    if (func_02188CFC(player->fieldMap) == 0)
        func_021A5738(player->grid, a);
}

void func_021A356C(FieldPlayer *player)
{
    if (func_02188CFC(player->fieldMap) == 0)
        func_021A575C(player->grid);
}

int func_021A3584(FieldPlayer *player)
{
    if (func_02188CFC(player->fieldMap) == 0) {
        return func_021A5764(player->grid);
    }
    return 0;
}

void func_021A35A0(FieldPlayer *player, int a)
{
    if (func_02188CFC(player->fieldMap) == 0)
        func_021A5768(player->grid, a);
}

int func_021A35BC(FieldPlayer *player)
{
    if (func_020142E8(func_0201296C(func_020120F4(func_021A30BC(player))), 0x963) != 0)
        return 1;
    return 0;
}

void func_021A35E0(FieldPlayer *player, u32 heapId)
{
    player->grid = func_021A4140(player->core, heapId);
}

void func_021A35F0(FieldPlayer *player, u32 a, u32 b, u32 c)
{
    func_021A41B0(player->grid, a, b, c);
}

void func_021A35FC(FieldPlayer *player, u16 *gridX, u16 *gridY, u16 *gridZ)
{
    Mmdl *mmdl = func_021A3960(player->core);

    *gridX = func_0216D83C(mmdl);
    *gridY = func_0216D854(mmdl);
    *gridZ = func_0216D86C(mmdl);
}

int func_021A3624(FieldPlayer *player)
{
    if (func_02188CFC(player->fieldMap) == 0) {
        if (func_021A54A0(player->grid) == 1) {
            return 1;
        }
    }
    return 0;
}

void func_021A3644(FieldPlayer *player)
{
    if (func_02188CFC(player->fieldMap) == 0 && func_021A54A0(player->grid) == 1)
        func_021A54B4(player->grid);
}

void func_021A3664(FieldPlayer *player, u32 heapId)
{
    player->nogrid = func_021A5880(player->core, heapId);
}

void func_021A3674(FieldPlayer *player, u32 a, u32 b)
{
    func_021A596C(player->nogrid, a, b);
}

void func_021A3680(FieldPlayer *player, int a)
{
    func_021A5928(player->nogrid, a);
}

void func_021A368C(FieldPlayer *player)
{
    func_021A5964(player->nogrid);
}

u32 func_021A3698(FieldPlayer *player)
{
    return func_021A59EC(player->nogrid);
}

u32 func_021A36A4(FieldPlayer *player)
{
    return func_021A5A30(player->nogrid);
}

void func_021A36B0(FieldPlayer *player, void *a)
{
    func_021A5A00(player->nogrid, a);
}

void func_021A36BC(FieldPlayer *player, void *a)
{
    func_021A5A0C(player->nogrid, a);
}

int func_021A36C8(FieldPlayer *player, u32 a, void *b)
{
    return func_021A5A18(player->nogrid, a, b);
}

void func_021A36D4(FieldPlayer *player, u32 unused)
{
    func_021A5A24(player->nogrid);
}

FieldPlayerGrid *func_021A36E0(FieldPlayer *player)
{
    return player->grid;
}
