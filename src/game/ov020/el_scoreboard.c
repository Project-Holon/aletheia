/*
 * file:     el_scoreboard.c
 * unit:     yes
 * function: func_021875F4, func_02187684, func_0218768C, func_021876B0, func_021876E0, func_0218774C, func_021877A8, func_02187808, func_02187860, func_02187884, func_021878C0, func_02187914, func_02187938, func_0218793C, func_0218794C, func_02187A10, func_02187A38, func_02187B38, func_02187BBC, func_02187C20, func_02187CCC, func_02187CEC, func_02187CFC, func_02187D20, func_02187D24, func_02187D28, func_02187D30, func_02187D40, func_02187D54, func_02187D74, func_02187D94
 * address:  0x021875F4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012870  0x02012870  thumb
 *   func_0201284C  0x0201284C  thumb
 *   func_02014068  0x02014068  thumb
 *   func_020128C0  0x020128C0  thumb
 *   func_02014204  0x02014204  thumb
 *   func_02013C50  0x02013C50  thumb
 *   func_02013FEC 0x02013FEC thumb
 *   func_02012894 0x02012894 thumb
 *   func_020127A4 0x020127A4 thumb
 *   func_02012B28 0x02012B28 thumb
 *   func_02012B2C 0x02012B2C thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045A38  0x02045A38  arm
 *   func_02008F08  0x02008F08  thumb
 *   func_02008F88  0x02008F88  thumb
 *   func_02008FA0  0x02008FA0  thumb
 *   func_02008FA8  0x02008FA8  thumb
 *   func_02008FB4  0x02008FB4  thumb
 *   func_02008FBC  0x02008FBC  thumb
 *   func_02008FD8  0x02008FD8  thumb
 *   func_02008FC4  0x02008FC4  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   d_02187DA4  0x02187DA4  data  ov020  a4
 *   d_02187DAC  0x02187DAC  data  ov020  a4
 *   d_02187DB4  0x02187DB4  data  ov020  a4
 *   func_02012EBC 0x02012EBC thumb
 *   func_0201AD0C 0x0201AD0C thumb
 *   func_02012984 0x02012984 thumb
 *   func_02008B14 0x02008B14 thumb
 *   func_0216A358 0x0216A358 thumb ov010
 *   func_02030734 0x02030734 arm
 *   d_02187EA0 0x02187EA0 data ov020 a1
 *   func_0216D588  0x0216D588  thumb
 *   func_02161E78 0x02161E78 thumb ov010
 *   func_02008530  0x02008530  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_02161E84 0x02161E84 thumb ov010
 *   func_0200855C  0x0200855C  thumb
 *   func_021584F4  0x021584F4  thumb  ov010
 *   func_02161ECC 0x02161ECC thumb ov010
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_020127E0  0x020127E0  thumb
 *   func_020127F0  0x020127F0  thumb
 *   func_02013DE0  0x02013DE0  thumb
 *   func_02161E60  0x02161E60  thumb
 *   func_02161EEC  0x02161EEC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0216E618  0x0216E618  thumb  ov010
 *   d_02187EB4     0x02187EB4  data  ov020  a1
 *   d_02187DBC     0x02187DBC  data  ov020  a4
 *   func_02045A98  0x02045A98  arm
 *   func_020084F4 0x020084F4 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204932C  0x0204932C  arm
 *   func_02049238 0x02049238 arm
 *   func_02049250  0x02049250  arm
 *   d_02187DE0     0x02187DE0  data  ov020  a4
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_02193B40  0x02193B40  thumb  ov021
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02193BE4  0x02193BE4  thumb  ov021
 *   func_02193BC4  0x02193BC4  thumb  ov021
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02193B68  0x02193B68  thumb  ov021
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02193904  0x02193904  thumb  ov021
 *   func_0219390C  0x0219390C  thumb  ov021
 *   func_02193C00  0x02193C00  thumb  ov021
 *   func_02193C04  0x02193C04  thumb  ov021
 *   func_021938F4  0x021938F4  thumb  ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0219391C  0x0219391C  thumb  ov021
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0201210C 0x0201210C thumb
 *   func_0215897C 0x0215897C thumb ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02158434  0x02158434  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021620A0  0x021620A0  thumb  ov010
 *   func_02162048  0x02162048  thumb  ov010
 *   func_0216208C  0x0216208C  thumb  ov010
 *   func_0216209C  0x0216209C  thumb  ov010
 *   func_02161E4C  0x02161E4C  thumb  ov010
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02012944  0x02012944  thumb
 *   func_02161F90  0x02161F90  thumb  ov010
 *   func_02193B20  0x02193B20  thumb  ov021
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0219129C  0x0219129C  thumb  ov021
 *   d_02187E04     0x02187E04  data  ov020  a2
 *   func_02191388  0x02191388  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_021912F8  0x021912F8  thumb  ov021
 *   func_0219131C 0x0219131C thumb ov021
 *   func_0216FC4C  0x0216FC4C  thumb  ov010
 *   func_0216FAB4  0x0216FAB4  thumb  ov010
 *   d_02187EDC     0x02187EDC  data  ov020  a4
 *   func_02061CA4 0x02061CA4 arm
 *   d_02187ECC 0x02187ECC data ov020 a4
 *   func_020124EC  0x020124EC  thumb
 *   func_0202E8B8  0x0202E8B8  thumb
 *   func_02043658 0x02043658 arm
 *   func_02188DA0 0x02188DA0 thumb ov021
 *   func_02043534 0x02043534 arm
 *   func_0204047C 0x0204047C arm
 *   func_020414AC 0x020414AC arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   d_02187E58     0x02187E58  data  ov020
 *   d_02187E28     0x02187E28  data  ov020
 *   d_02187E38     0x02187E38  data  ov020
 *   func_02062A98  0x02062A98  arm
 *   func_02040E78  0x02040E78  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_02062B30  0x02062B30  arm
 *   func_020409E0  0x020409E0  arm
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0207D658  0x0207D658  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_0207D534  0x0207D534  arm
 *   func_0209BE04  0x0209BE04  arm
 *   func_0209CE10  0x0209CE10  arm
 *   func_0209C77C  0x0209C77C  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   func_0202E8A4  0x0202E8A4  thumb
 *   func_02040588  0x02040588  arm
 *   func_02188DB0  0x02188DB0  thumb  ov021
 *   func_02189A50 0x02189A50 thumb ov021
 */

struct ArcHandle;
struct GameEvent;
struct TexKey;
struct BgTemplate;
struct DispConfig;
struct DispVram;
struct NitroFileHeader;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

#include "el_scoreboard_types.h"
u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049238(void *p);
extern void *func_02049250(struct ArcHandle *arc, unsigned int member,
                           unsigned int heap);
u16 func_02188C84(u8 *p);
struct GameEvent *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct GameEvent *p);
extern u32 func_020362DC(void);
extern int func_0216FC4C(void);
extern int func_0216FAB4(void *file, const char *texName, void *extra, const char *plttName, u32 a4, u16 a5, u16 a6, u16 a7, u16 heap, struct TexKey *out);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern u32 *func_020124EC(struct GameEvent *p);
extern u8 func_0202E8B8(int);
extern u32 func_02043658(void);
extern void func_02188DA0(void);
extern void func_02043534(u32 planes);
extern void func_0204047C(int idx, unsigned short val);
extern void func_020414AC(int a);
void func_020433E0(const struct DispVram *c);
void func_0203F8F4(u16 heapId);
void func_0203FC28(struct DispConfig *cfg);
void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020403F4(unsigned int i);
extern void func_0203F9B4(void);
s32 func_02062A98(struct NitroFileHeader *file, void **out);
void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
s32 func_02062A4C(struct NitroFileHeader *file, void **out);
void func_02040B1C(int index, const void *src, u32 size, u32 tile);
int func_02062B30(void *file, void **out);
void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);
void func_0207D658(u32 addr, int plane, int brightness);
void func_0207D63C(u32 addr, int plane1, int plane2, int ev1, int ev2);
void func_0207D534(volatile u16 *reg, int brightness);
u32 func_0209BE04(u32 x);
u32 func_0209CE10(u32 a, u32 b);
u32 func_0209C77C(u32 a, u32 b);
u32 func_0209C95C(u32 a, u32 b);
u32 func_0209CB8C(u32 a, u32 b);
u32 func_0209C494(u32 x);
u8 func_0202E8A4(u8 x);
void func_02040588(unsigned char which, unsigned char enable);
void func_02188DB0(u8 *a);
extern void func_02189A50(char *p, int v);
ElLamp *func_021875F4(void *archive, const char *texName, const char *plttName, u32 texFormat, ElTexParams loadParams);
void func_02187684(ElLamp *lamp);
void func_0218768C(ElLamp *lamp);
void func_021876B0(ElLampPaletteRef *paletteRef, int tick);
int func_021876E0(void *eventTask, int *state, ElScoreboardWork *work);
void *func_0218774C(void *gameSystem, void *fieldMap, u8 shownSeason, u8 targetSeason);
void *func_021877A8(void *gameSystem, void *fieldMap, u8 shownSeason, u8 targetSeason, ElScoreboardCallback finishCallback, int finishCallbackArg);
void *func_02187808(void *p, u8 shownSeason, u8 targetSeason);
void func_02187860(ElScoreboardWork *work);
void func_02187884(ElScoreboardWork *work);
void func_021878C0(ElScoreboardWork *work);
void func_02187914(ElScoreboardWork *work);
void func_02187938(ElScoreboardWork *work);
void func_0218793C(ElScoreboardWork *work);
void func_0218794C(int season, int heapId);
void func_02187A10(ElScoreboardWork *work, int state);
void func_02187A38(const ElScoreboardWork *work, int state);
void func_02187B38(ElScoreboardWork *work, int state);
int func_02187BBC(ElScoreboardWork *work, int state);
void func_02187C20(ElScoreboardWork *work, int *statePtr, int state);
void func_02187CCC(ElScoreboardWork *work, int *statePtr);
void func_02187CEC(ElScoreboardWork *work);
void func_02187CFC(ElScoreboardWork *work);
u32 func_02187D20(ElScoreboardWork *work);
u32 func_02187D24(ElScoreboardWork *work);
void func_02187D28(ElScoreboardWork *work);
int func_02187D30(ElScoreboardWork *work);
int func_02187D40(ElScoreboardWork *work);
int func_02187D54(ElScoreboardWork *work);
int func_02187D74(ElScoreboardWork *work);
void func_02187D94(ElScoreboardWork *work);
extern int d_02187EDC;
extern int d_02187ECC[];
extern char d_02187E58[];
extern char d_02187E28[];
extern char d_02187E38[];

ElLamp *func_021875F4(void *archive, const char *texName, const char *plttName, u32 texFormat, ElTexParams loadParams)
{
    ElTexResult loaded;
    ElLamp *lamp;

    lamp = func_02030734(((u16 *)&loadParams)[4], 0x1c, 1, (const char *)&d_02187EDC, 0x19c);
    lamp->flags = 0;
    lamp->texIndex = func_0216FC4C() - 1;
    lamp->plttIndex = func_0216FC4C() - 1;
    lamp->texVram = -1;
    lamp->plttVram = (char *)-1;
    if (func_0216FAB4(archive, texName, 0, plttName, texFormat, ((u16 *)&loadParams)[0], ((u16 *)&loadParams)[2], 0xC40, ((u16 *)&loadParams)[4], (struct TexKey *)(&loaded)) != 0) {
        lamp->texAddr = loaded.texAddr;
        lamp->plttSlot = loaded.plttSlot;
        lamp->texVram = loaded.texVram;
        lamp->texIndex = loaded.texIndex;
        lamp->plttIndex = loaded.plttIndex;
        lamp->plttVram = (char *)loaded.plttVram;
        lamp->tick = 0;
    }
    return lamp;
}

void func_02187684(ElLamp *lamp) { func_020307B0(lamp); }

/*
 * lever: capture the base in a local before filling the stack pair, preserving the original r3 load.
 */
void func_0218768C(ElLamp *lamp)
{
    ElLampPaletteRef pair;
    char *base;
    lamp->tick++;
    base = lamp->plttVram;
    if (base != (char *)-1) {
        pair.index = lamp->plttSlot;
        pair.base = base;
        func_021876B0(&pair, lamp->tick);
    }
}

void func_021876B0(ElLampPaletteRef *paletteRef, int tick)
{
    func_02061CA4((void *)1, (u32)(paletteRef->base + (u16)paletteRef->index * 8), d_02187ECC[(tick & 31) / 8], 8);
}

int func_021876E0(void *eventTask, int *state, ElScoreboardWork *work)
{
    switch (*state) {
    case 0: func_02187CEC(work); break;
    case 1: case 3: break;
    case 2: func_02187A10(work, *state); break;
    case 4: func_02187A10(work, *state); break;
    case 5: func_02187CFC(work); return 1;
    }
    if (func_020362DC() & 1) { if (func_02187D20(work) == 0) func_02187D28(work); }
    work->stateTimer = work->stateTimer + 1;
    func_02187CCC(work, state);
    return 0;
}

/*
 * shownSeason must be u8 (as in the twin func_02187808): with an int the scheduler
 * hoists its spilled reload above the strb of targetSeason.
 */
void *func_0218774C(void *gameSystem, void *fieldMap, u8 shownSeason, u8 targetSeason)
{
    void *eventTask = func_020122C0(gameSystem, 0, func_021876E0, 0x28);
    ElScoreboardWork *work = func_020124E8(eventTask);
    u32 *statePtr = func_020124EC(eventTask);
    work->gameSystem = gameSystem; work->fieldMap = fieldMap; work->heapId = func_02188C84((u8 *)fieldMap); work->mode = 0; work->finished = 0;
    work->targetSeason = targetSeason; work->shownSeason = func_0202E8B8(shownSeason); work->finishCallback = 0; work->finishCallbackArg = 0;
    func_02187C20(work, (int *)statePtr, 0);
    return eventTask;
}

void *func_021877A8(void *gameSystem, void *fieldMap, u8 shownSeason, u8 targetSeason, ElScoreboardCallback finishCallback, int finishCallbackArg)
{
    void *eventTask = func_020122C0(gameSystem, 0, func_021876E0, 0x28);
    ElScoreboardWork *work = func_020124E8(eventTask);
    u32 *statePtr = func_020124EC(eventTask);
    work->gameSystem = gameSystem; work->fieldMap = fieldMap; work->heapId = func_02188C84((u8 *)fieldMap); work->mode = 0; work->finished = 0;
    work->targetSeason = targetSeason; work->shownSeason = func_0202E8B8(shownSeason); work->finishCallback = finishCallback; work->finishCallbackArg = finishCallbackArg;
    func_02187C20(work, (int *)statePtr, 0);
    return eventTask;
}

/*
 * Standalone scoreboard (no field map): create the event task with a 0x28-byte
 * work area, fill it and enter state 0. shownSeason must be u8: with an int
 * (targetSeason either int or u8) the scheduler hoists the spilled reload
 * above the strb of targetSeason.
 */
void *func_02187808(void *gameSystem, u8 shownSeason, u8 targetSeason)
{
    void *eventTask = func_020122C0(gameSystem, 0, func_021876E0, 0x28);
    ElScoreboardWork *work = func_020124E8(eventTask);
    void *stateNum = func_020124EC(eventTask);

    work->gameSystem = gameSystem;
    work->fieldMap = 0;
    work->heapId = 4;
    work->mode = 1;
    work->finished = 0;
    work->targetSeason = targetSeason;
    work->shownSeason = func_0202E8B8(shownSeason);
    work->finishCallback = 0;
    work->finishCallbackArg = 0;
    func_02187C20(work, stateNum, 0);
    return eventTask;
}

void func_02187860(ElScoreboardWork *work)
{
    switch (func_02187D20(work)) {
    case 0: func_02187884(work); break;
    case 1: func_021878C0(work); break;
    }
}

void func_02187884(ElScoreboardWork *work)
{
    int planes;
    planes = func_02043658();
    func_02188DA0();
    func_02043534(planes);
    func_0204047C(0, 1);
    func_0204047C(3, 0);
    func_0204047C(1, 3);
    func_0204047C(2, 3);
    func_020414AC(3);
}

void func_021878C0(ElScoreboardWork *work)
{
    func_020433E0((const struct DispVram *)d_02187E58);
    func_0203F8F4(work->heapId);
    func_0203FC28((struct DispConfig *)d_02187E28);
    func_0203FCA0(3, (const struct BgTemplate *)d_02187E38, 0);
    func_0204047C(0, 1);
    func_0204047C(3, 0);
    func_0204047C(1, 3);
    func_0204047C(2, 3);
    func_020414AC(3);
}

void func_02187914(ElScoreboardWork *work)
{
    switch (func_02187D20(work)) {
    case 0: func_02187938(work); break;
    case 1: func_0218793C(work); break;
    }
}

void func_02187938(ElScoreboardWork *work)
{
}

/*
 * \n * symbols:\n *   func_020403F4  0x020403F4  arm\n *   func_0203F9B4  0x0203F9B4  arm\n
 */
void func_0218793C(ElScoreboardWork *work)
{
    func_020403F4(3);
    func_0203F9B4();
}

void func_0218794C(int season, int heapId)
{
    int *palFile;
    int *charFile;
    int *screenFile;
    void *archive;
    void *member;
    int palIdx, charIdx, screenIdx;

    switch (season) {
    default:
    case 0:
        palIdx = 0; charIdx = 1; screenIdx = 2;
        break;
    case 1:
        palIdx = 3; charIdx = 4; screenIdx = 5;
        break;
    case 2:
        palIdx = 6; charIdx = 7; screenIdx = 8;
        break;
    case 3:
        palIdx = 9; charIdx = 10; screenIdx = 11;
        break;
    }
    archive = func_020490F4(0x97, heapId);
    member = func_02049250(archive, palIdx, heapId);
    func_02062A98(member, (void **)(&palFile));
    func_02040E78(3, (void *)palFile[3], 0x20, 0);
    func_020307B0(member);
    member = func_02049250(archive, charIdx, heapId);
    func_02062A4C(member, (void **)(&charFile));
    func_02040B1C(3, (const void *)charFile[5], charFile[4], 0);
    func_020307B0(member);
    member = func_02049250(archive, screenIdx, heapId);
    func_02062B30(member, (void **)(&screenFile));
    func_020409E0(3, screenFile + 3, screenFile[2], 0);
    func_020307B0(member);
    func_02049238(archive);
}

void func_02187A10(ElScoreboardWork *work, int state)
{
    switch (func_02187D20(work)) {
    case 0: func_02187A38(work, state); break;
    case 1: func_02187B38(work, state); break;
    }
}

/*
 * Blend fade on the main engine (BLDCNT 0x04000050) plus the sub engine's
 * master brightness (0x0400106C), driven by the ratio o->0x18 / o->0x1c.
 * The object pointer is `const char *`: through a const pointer mwcc lets the
 * loads after the G2x_SetBlendAlpha_ call ignore the outgoing stack-argument
 * store, so that store is scheduled last (+0x7E). With a plain `char *` it
 * moves up to +0x78 (8 bytes out); const casts on the loads alone do not.
 */
void func_02187A38(const ElScoreboardWork *work, int state)
{
    int alpha;

    if (state == 2) {
        func_0207D658(0x04000050, 8,
            (int)(16.0f * ((float)work->stateTimer / (float)work->stateDuration) + -16.0f));
    } else if (state == 4) {
        if (work->shownSeason == work->targetSeason) {
            alpha = (int)(16.0f * ((float)work->stateTimer / (float)work->stateDuration));
            func_0207D63C(0x04000050, 8, 0x11, 16 - alpha, alpha);
            func_0207D534((volatile u16 *)0x0400106C,
                (int)(16.0f * ((float)work->stateTimer / (float)work->stateDuration) + -16.0f));
        } else {
            func_0207D658(0x04000050, 8,
                (int)(0.0f - 16.0f * ((float)work->stateTimer / (float)work->stateDuration)));
        }
    }
}

void func_02187B38(ElScoreboardWork *work, int state)
{
    u32 elapsed, ratio;

    if (state == 2) {
        elapsed = func_0209BE04(work->stateTimer);
        ratio = func_0209BE04(work->stateDuration);
        ratio = func_0209CE10(elapsed, ratio);
        ratio = func_0209C77C(0x41800000, ratio);
        ratio = func_0209C95C(0xC1800000, ratio);
        func_0207D658(0x04000050, 8, func_0209C494(ratio));
    } else if (state == 4) {
        elapsed = func_0209BE04(work->stateTimer);
        ratio = func_0209BE04(work->stateDuration);
        ratio = func_0209CE10(elapsed, ratio);
        ratio = func_0209C77C(0x41800000, ratio);
        ratio = func_0209CB8C(0, ratio);
        func_0207D658(0x04000050, 8, func_0209C494(ratio));
    }
}

int func_02187BBC(ElScoreboardWork *work, int state)
{
    switch (state) {
    case 0:
        state = 1;
        break;
    case 1:
        state = 2;
        break;
    case 2:
        if (func_02187D30(work) == 1)
            state = 3;
        break;
    case 3:
        if (func_02187D30(work) == 1 || func_02187D24(work) == 1)
            state = 4;
        break;
    case 4:
        if (func_02187D30(work) == 1) {
            state = 5;
            if (work->targetSeason != work->shownSeason)
                state = 1;
        }
        break;
    case 5:
        break;
    }
    return state;
}

void func_02187C20(ElScoreboardWork *work, int *statePtr, int state)
{
    switch (state) {
    case 0:
        func_02187860(work);
        break;
    case 1:
        work->shownSeason = func_0202E8A4(work->shownSeason);
        func_0218794C(work->shownSeason, work->heapId);
        break;
    case 2:
        func_02040588(3, 1);
        func_02040588(0, 0);
        func_0207D534((volatile u16 *)0x0400006C, 0);
        func_0207D658(0x04000050, 8, -16);
        work->stateDuration = func_02187D40(work);
        break;
    case 3:
        work->stateDuration = func_02187D74(work);
        break;
    case 4:
        work->stateDuration = func_02187D54(work);
        if (func_02187D20(work) == 0 && work->shownSeason == work->targetSeason) {
            func_02188DB0((u8 *)work->fieldMap);
            func_02040588(3, 1);
            func_02187D94(work);
        }
        break;
    case 5:
        break;
    }
    *statePtr = state;
    work->stateTimer = 0;
}

void func_02187CCC(ElScoreboardWork *work, int *statePtr)
{
    int newState;
    newState = func_02187BBC(work, *statePtr);
    if (*statePtr != newState) func_02187C20(work, statePtr, newState);
}

/* Tells the field map that the scoreboard is up (setter in ov021). */
void func_02187CEC(ElScoreboardWork *work)
{
    void *fieldMap;
    fieldMap = work->fieldMap;
    if (fieldMap != 0) func_02189A50(fieldMap, 1);
}

/* Clears the field map flag, then runs the mode-specific teardown. */
void func_02187CFC(ElScoreboardWork *work)
{
    func_02040588(3, 0);
    if (work->fieldMap != 0) func_02189A50(work->fieldMap, 0);
    func_02187914(work);
}

u32 func_02187D20(ElScoreboardWork *work)
{
    return work->mode;
}

u32 func_02187D24(ElScoreboardWork *work)
{
    return work->finished;
}

void func_02187D28(ElScoreboardWork *work)
{
    work->finished = 1;
}

int func_02187D30(ElScoreboardWork *work)
{
    if (work->stateDuration < work->stateTimer)
        return 1;
    return 0;
}

int func_02187D40(ElScoreboardWork *work)
{
    if (func_02187D20(work) == 1) return 30;
    return 10;
}

int func_02187D54(ElScoreboardWork *work)
{
    if (func_02187D20(work) == 1) return 60;
    if (work->shownSeason == work->targetSeason) return 20;
    return 10;
}

int func_02187D74(ElScoreboardWork *work)
{
    if (func_02187D20(work) == 1) return 120;
    if (work->shownSeason == work->targetSeason) return 60;
    return 30;
}

void func_02187D94(ElScoreboardWork *work)
{
    if (work->finishCallback)
        work->finishCallback(work->finishCallbackArg);
}
