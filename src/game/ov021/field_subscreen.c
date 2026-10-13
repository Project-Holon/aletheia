/*
 * file:     field_subscreen.c
 * unit:     yes
 * function: func_021A0CF4, func_021A0D44, func_021A0D68, func_021A0E58, func_021A0EB0, func_021A0ED4, ov021_func_021A0EE4, func_021A0F30, func_021A0F40, func_021A0F7C, func_021A0F90, func_021A0F94, func_021A0FA0, func_021A0FA8, func_021A0FB4, ov021_func_021A0FE8, ov021_func_021A1050, func_021A10C0, func_021A10D4, ov021_func_021A10E0, func_021A1138, func_021A1144, func_021A117C, func_021A1190, func_021A119C, ov021_func_021A11A8, ov021_func_021A1244, func_021A1288, func_021A1298, func_021A12A4, func_021A12BC, func_021A12D4, func_021A1358, func_021A136C, func_021A1388, func_021A139C, func_021A13C0, ov021_func_021A13E4, func_021A13F8, func_021A1404, func_021A1410, func_021A141C, func_021A1428, func_021A1448, func_021A145C, func_021A1468, func_021A1474, func_021A1480, func_021A14A0, func_021A14B4, func_021A14C0, func_021A14CC, func_021A14EC, func_021A1500, func_021A150C, func_021A1518, func_021A1524, func_021A1530, func_021A153C, func_021A1548, func_021A1554, func_021A1560, func_021A1584, func_021A1590
 * address:  0x021A0CF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes field_3dbg_p01.c (021A10D4), unit_021A1144.c and the 22 mode glue functions 021A1428..021A1590 of field_3dbg.c (lane FXC3: one file from the field_subscreen.c anchor to the first field_3dbg.c anchor 021A15A4).
 * Split from field_fog.c (CL110): __FILE__ anchor field_subscreen.c at 0x021A0CF4; ends at field_3dbg.c (0x021A10D4, certain cut).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 *   d_021DDE48  0x021DDE48  data  ov021
 *   d_021D872C  0x021D872C  data  a4
 *   d_021D8738     0x021D8738  data
 *   func_02189A2C  0x02189A2C  thumb  ov021
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   d_021D8734  0x021D8734  data  a4
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_020090E0  0x020090E0  thumb
 *   func_02013D20  0x02013D20  thumb
 *   func_02013D00  0x02013D00  thumb
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_021D3270  0x021D3270  thumb  ov021
 *   func_02193060  0x02193060  thumb  ov021
 *   func_020414EC  0x020414EC  arm
 *   func_021902A4  0x021902A4  thumb  ov021
 *   func_02009208  0x02009208  thumb
 *   func_02009200  0x02009200  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02012204  0x02012204  thumb
 *   func_02012210  0x02012210  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021F279C  0x021F279C  thumb  ov029
 *   abs_id_1d      0x0000001D  data
 *   func_021F27D8  0x021F27D8  thumb  ov029
 *   func_021F2984  0x021F2984  thumb  ov029
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F29D8  0x021F29D8  thumb  ov029
 *   func_021F2980 0x021F2980 thumb ov029
 *   func_021F2994  0x021F2994  thumb  ov029
 *   func_021F2848  0x021F2848  thumb  ov029
 *   func_021A8840  0x021A8840  thumb  ov021
 *   func_0217D160  0x0217D160  thumb  ov018
 *   func_0217D1C0  0x0217D1C0  thumb  ov018
 *   func_0217D3AC  0x0217D3AC  thumb  ov018
 *   func_0217D4DC  0x0217D4DC  thumb  ov018
 *   func_021F00C8  0x021F00C8  thumb  ov030
 *   abs_id_1e      0x0000001E  data
 *   func_021E0118  0x021F0118  thumb  ov030
 *   func_021F0114  0x021F0114  thumb  ov030
 *   func_021F00F8  0x021F00F8  thumb  ov030
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   func_020414AC  0x020414AC  arm
 *   func_0204152C  0x0204152C  arm
 *   func_02043598  0x02043598  arm
 *   func_021A836C  0x021A836C  thumb  ov021
 *   func_021A8B18  0x021A8B18  thumb  ov021
 *   func_02024A20  0x02024A20  thumb
 *   func_021A8AFC  0x021A8AFC  thumb  ov021
 *   d_021D8708     0x021D8708  data  a4
 *   func_02024DCC  0x02024DCC  thumb
 *   func_021A84BC  0x021A84BC  thumb  ov021
 *   func_020403F4  0x020403F4  arm
 *   func_021A85B4  0x021A85B4  thumb  ov021
 *   func_02024ABC  0x02024ABC  thumb
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A8E10  0x021A8E10  thumb  ov021
 *   func_021A8E20  0x021A8E20  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049658  0x02049658  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_021D3244  0x021D3244  thumb  ov021
 *   ov031_func_021EFEC0  0x021EFEC0  thumb  ov031
 *   abs_id_1f      0x0000001F  data
 *   func_021EFFE8  0x021EFFE8  thumb  ov031
 *   func_0217394C  0x0217394C  thumb  ov012
 *   func_021F0054  0x021F0054  thumb  ov031
 *   func_021F00D4  0x021F00D4  thumb  ov031
 *   func_0217CFE4  0x0217CFE4  thumb  ov018
 *   func_021F2234  0x021F2234  thumb  ov032
 *   abs_id_20      0x00000020  data
 *   func_022022FC  0x021F22FC  thumb  ov032
 *   func_021F2344 0x021F2344 thumb ov032
 *   func_021F23F8 0x021F23F8 thumb ov032
 *   func_021F2404 0x021F2404 thumb ov032
 *   func_021F000C  0x021F000C  thumb  ov033
 *   abs_id_21      0x00000021  data
 *   func_02210124  0x021F0124  thumb  ov033
 *   func_021F0174 0x021F0174 thumb ov033
 *   func_021F05A4 0x021F05A4 thumb ov033
 *   func_021EFEC0  0x021EFEC0  thumb  ov034
 *   abs_id_22      0x00000022  data
 *   func_021EFF34  0x021EFF34  thumb  ov034
 *   func_021EFF5C  0x021EFF5C  thumb  ov034
 *   func_021EFFB4  0x021EFFB4  thumb  ov034
 *   func_021F0044  0x021F0044  thumb  ov034
 *   func_021F0058  0x021F0058  thumb  ov034
 *   func_021F00BC  0x021F00BC  thumb  ov034
 *   func_021F00F0  0x021F00F0  thumb  ov034
 *   func_021F0108  0x021F0108  thumb  ov034
 *   func_021F009C  0x021F009C  thumb  ov034
 *   ov035_func_021EFEC0  0x021EFEC0  thumb  ov035
 *   abs_id_23      0x00000023  data
 *   func_021EFF3C 0x021EFF3C thumb ov035
 *   func_021EFF2C  0x021EFF2C  thumb  ov035
 */
#include "field_subscreen_types.h"

#define FIELD_SUBSCREEN_MODE_CGEAR      0   /* C-Gear panel (needs the C-Gear in the save) */
#define FIELD_SUBSCREEN_MODE_NO_CGEAR   5   /* fallback when there is no C-Gear */
#define FIELD_SUBSCREEN_MODE_NONE       0xB /* "previous mode" given to the first init */

#define FIELD_SUBSCREEN_STATE_RUN           0
#define FIELD_SUBSCREEN_STATE_FADE_OUT      1
#define FIELD_SUBSCREEN_STATE_FADE_OUT_WAIT 2
#define FIELD_SUBSCREEN_STATE_HALT          3
#define FIELD_SUBSCREEN_STATE_FADE_IN       4
#define FIELD_SUBSCREEN_STATE_FADE_IN_WAIT  5

struct BgTemplate;
struct FieldMenu;
struct MenuLayoutInfo;
struct ArchiveHandle;
struct FieldVReq;

#define FIELD_SUBSCREEN_MODE_MENU   1
#define FIELD_SUBSCREEN_MODE_CGEAR_CALLBACK 8

/* Overlay ids 30 and 31 are absolute symbols: the original loads them with a
 * literal pool word, a plain 30 or 31 would be a mov immediate. */
#define FIELD_SUBSCREEN_OVERLAY_NO_GEAR ((int)abs_id_1e)
#define FIELD_SUBSCREEN_OVERLAY_UNION   ((int)abs_id_1f)

typedef signed int     s32;

/* One row (0x1C bytes) of the mode table. */
typedef struct FieldSubscreenMode {
    void (*init)(FieldSubscreen *work, u32 prevMode);
    void (*update)(FieldSubscreen *work, s32 isFieldIdle);
    void (*updateNoTransition)(FieldSubscreen *work, s32 isFieldIdle);
    int (*checkRequest)(FieldSubscreen *work, u32 mode);
    void (*exit)(FieldSubscreen *work);
    u32 reserved14;
    u32 reserved18;
} FieldSubscreenMode;

u32 func_021F2980(u32 a);
u32 func_021A10D4(FieldSubscreen *work);
extern int func_021F2994(int *cgear);
extern u32 func_021F2848(u32, u32);
u32 ov021_func_021A10E0(FieldSubscreen *work, u32 active);
/* Unprototyped on purpose: the caller passes the work pointer as a third argument; a two-parameter prototype changes the bytes. */
int func_021F29D8();
extern void *func_020120F8(void *gameSystem);
extern u16 func_02012AC8(void *playerLocation);
extern void *func_0201296C(void *gameData);
extern void *func_021F00C8(void *cgearSave, FieldSubscreen *work, void *gameSystem);
extern void func_021E0118(void *noGear);
extern void func_021F0114(void *noGear);
extern void func_021F00F8(void *noGear);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *template, u32 type);
extern void func_02040588(u8 bgId, u8 visible);
extern void func_020414AC(u32 bgId);
extern void func_0204152C(int bgId, u16 value);
extern void func_02043598(u32 planeMask, u32 enable);
extern struct FieldMenu *func_021A836C(u16 heapId, u16 subHeapId, FieldSubscreen *parent, void *fieldMap, int slideIn);
extern u32 func_021A8B18(void *gameData, void *eventWork, u32 zoneId);
extern void func_02024A20(u8 bgId, u8 paletteId, void *gameData, u16 heapId);
extern void func_021A8AFC(int heapId, int slideIn);
extern int func_02024DCC(void);
extern void func_021A84BC(struct FieldMenu *menu);
extern void func_020403F4(u32 bgId);
extern u32 func_021A85B4(struct FieldMenu *menu);
extern void func_02024ABC(u32 value);
extern void func_021A8840(struct FieldMenu *menu);
extern u32 func_021A0F90(FieldSubscreen *work);
extern u32 func_021A8E10(struct FieldMenu *menu);
extern void func_021A8E20(struct FieldMenu *menu, u32 buttonId);
extern struct ArchiveHandle *func_020490F4(unsigned int archiveId, unsigned int heapId);
extern void func_02049BDC(struct ArchiveHandle *handle, u32 fileId, u32 type, u32 offset, u32 srcOffset, u32 size, u32 heapId);
extern void func_02049658(struct ArchiveHandle *handle, u32 fileId, u32 bgId, u32 offset, u32 size, u32 mode, u32 heapId);
extern void func_02049990(struct ArchiveHandle *handle, u32 fileId, u32 bgId, u32 x, u32 y, u32 width, u32 height, u32 heapId);
extern void func_02049238(struct ArchiveHandle *handle);
extern void func_021D3244(struct FieldVReq *vreq, int index, u8 value);
extern void *ov031_func_021EFEC0(void *gameSystem);
extern void func_021EFFE8(void *unionPanel);
extern int func_0217394C(void *gameSystem);
extern void func_021F0054(void *unionPanel, int isFieldIdle);
extern void func_021F00D4(void *unionPanel, int isFieldIdle);
extern void *func_0217CFE4(void *gameSystem);
extern void func_0217D160(void *intrudePanel);
extern void func_0217D1C0(void *intrudePanel, int isFieldIdle);
extern void func_0217D3AC(void *intrudePanel);
extern void *func_0217D4DC(void *intrudePanel, int mode, FieldSubscreen *work);
extern const struct BgTemplate d_021D8708;
void func_021A1144(FieldSubscreen *work);
void func_021A117C(FieldSubscreen *work);
void func_021A1190(FieldSubscreen *work);
void func_021A119C(FieldSubscreen *work);
void ov021_func_021A11A8(FieldSubscreen *work, u32 prevMode);
void ov021_func_021A1244(FieldSubscreen *work);
void func_021A1288(FieldSubscreen *work);
void func_021A1298(FieldSubscreen *work);
u32 func_021A12A4(FieldSubscreen *work);
void func_021A12BC(FieldSubscreen *work, u32 buttonId);
void func_021A12D4(FieldSubscreen *work, u32 heapId);
void *func_021A1358(FieldSubscreen *work);
void func_021A136C(FieldSubscreen *work);
void func_021A1388(FieldSubscreen *work);
void func_021A139C(FieldSubscreen *work, u32 isFieldIdle);
void func_021A13C0(FieldSubscreen *work, u32 isFieldIdle);
void ov021_func_021A13E4(FieldSubscreen *work);
void func_021A13F8(FieldSubscreen *work);
void func_021A1404(FieldSubscreen *work, int isFieldIdle);
void func_021A1410(FieldSubscreen *work);
void *func_021A141C(FieldSubscreen *work, int mode);
extern void *func_021F2234(void *gameSystem, void *work);
extern void func_022022FC(void *beaconView);
extern int func_021F2344(void *beaconView);
extern int func_021F23F8(void *beaconView);
extern int func_021F2404(void *beaconView);
extern void *func_021F000C(u32 heapId, u32 owner, void *work, void *fieldSystem);
extern void func_02210124(void *dowsing);
extern int func_021F0174(void *dowsing);
extern int func_021F05A4(void *dowsing);
extern void *func_021EFEC0(void *gameSystem, u32 heapId);
extern void func_021EFF34(void *report);
extern void func_021EFF5C(void *report);
extern void func_021EFFB4(void *report);
extern int func_021F0044(void *report);
extern void func_021F0058(void *report);
extern void func_021F00BC(void *report);
extern int func_021F00F0(void *report);
extern void func_021F0108(void *report);
extern unsigned func_021F009C(void *report);
extern void *ov035_func_021EFEC0(void *work, void *gameSystem, u32 heapId);
extern int func_021EFF3C(void *powerOnoff);
extern void func_021EFF2C(void *powerOnoff);
void func_021A1428(FieldSubscreen *work);
void func_021A1448(FieldSubscreen *work);
int func_021A145C(FieldSubscreen *work);
int func_021A1468(FieldSubscreen *work);
int func_021A1474(FieldSubscreen *work);
void func_021A1480(FieldSubscreen *work);
void func_021A14A0(FieldSubscreen *work);
int func_021A14B4(FieldSubscreen *work);
int func_021A14C0(FieldSubscreen *work);
void func_021A14CC(FieldSubscreen *work);
void func_021A14EC(FieldSubscreen *work);
void func_021A1500(FieldSubscreen *work);
void func_021A150C(FieldSubscreen *work);
int func_021A1518(FieldSubscreen *work);
void func_021A1524(FieldSubscreen *work);
void func_021A1530(FieldSubscreen *work);
int func_021A153C(FieldSubscreen *work);
void func_021A1548(FieldSubscreen *work);
int func_021A1554(FieldSubscreen *work);
void func_021A1560(FieldSubscreen *work);
int func_021A1584(FieldSubscreen *work);
void func_021A1590(FieldSubscreen *work);
extern unsigned char abs_id_20[];
extern unsigned char abs_id_21[];
extern unsigned char abs_id_22[];
extern unsigned char abs_id_23[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int func_02189A2C(void *fieldMap);
extern void func_0202208C(void *screen, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 heapId);
extern u32 func_020221A4(void);
extern void *func_02188C80(void *fieldMap);
extern u16 func_02188C9C(void *fieldMap);
extern void *func_020120F4(void *gameSystem);
extern void *func_02012EBC(void *gameData);
extern void *func_02009210(void *cgearSaveBase);
extern u32 func_020090E0(void *cgearSave);
extern u32 func_02013D20(void);
extern u32 func_02013D00(u32);
extern struct FieldVReq *func_02188E30(void *fieldMap);
extern void func_021D3270(struct FieldVReq *vreq, int a, int b, int c, int d, int e);
extern void func_02193060(u32);
extern void func_020414EC(u32 i);
extern void func_021902A4(u32, u32);
extern u8 func_02009208(void *cgearSave);
extern void func_02009200(void *cgearSave, u32 commState);
extern u32 func_0201214C(void *gameSystem);
extern u32 func_02012204(void *gameSystem);
extern void func_02012210(void *gameSystem);
extern int func_02034AC4(int);
extern void *func_021F279C(void *cgearSave, FieldSubscreen *work, void *gameSystem, int showPowerOff);
extern void *func_021F27D8(void *cgearSave, FieldSubscreen *work, void *gameSystem, void (*callback)(int), u32 callbackArg, u32 commState);
extern void func_021F2984(void *cgear);
extern void func_02034A5C(int);
void func_021A0FA0(FieldSubscreen *work, int result);
void ov021_func_021A0FE8(FieldSubscreen *work);
void ov021_func_021A1050(FieldSubscreen *work);
u32 ov021_func_021A0EE4(FieldSubscreen *work, u32 mode);

extern u8 d_021DDE48[];
extern const FieldSubscreenMode d_021D872C[];
extern unsigned char abs_id_1d[];
extern unsigned char abs_id_1e[];
extern unsigned char abs_id_1f[];

/*
 * Mode table d_021D872C: one FieldSubscreenMode row per mode, 0x1C bytes each.
 * The matching pool entries are the table address plus the field offset, so
 * every access is written as d_021D872C[mode].field.
 */
FieldSubscreen *func_021A0CF4(u32 heapId, void *fieldMap, u32 mode)
{
    FieldSubscreen *work;
    u32 resolved;

    work = (FieldSubscreen *)func_02030734((u16)heapId, sizeof(FieldSubscreen), 1, (const char *)d_021DDE48, 0x13c);
    work->state = FIELD_SUBSCREEN_STATE_RUN;
    work->heapId = heapId;
    work->cgear = 0;
    work->fieldMap = fieldMap;
    resolved = ov021_func_021A0EE4(work, mode);
    work->mode = resolved;
    work->nextMode = resolved;
    d_021D872C[resolved].init(work, FIELD_SUBSCREEN_MODE_NONE);
    return work;
}

u8 func_021A0D44(FieldSubscreen *work)
{
    u32 mode = work->mode;
    d_021D872C[mode].exit(work);
    func_020307B0(work);
    return mode;
}

void func_021A0D68(FieldSubscreen *work)
{
    switch (work->state) {
    case FIELD_SUBSCREEN_STATE_RUN:
        d_021D872C[work->mode].update(work, func_02189A2C(work->fieldMap) == 0);
        break;
    case FIELD_SUBSCREEN_STATE_FADE_OUT:
        func_0202208C((void *)4, 0, 0, 0, 1, 1, work->heapId);
        work->state = FIELD_SUBSCREEN_STATE_FADE_OUT_WAIT;
        break;
    case FIELD_SUBSCREEN_STATE_FADE_OUT_WAIT:
        if (func_020221A4() == 1) {
            d_021D872C[work->mode].exit(work);
            d_021D872C[work->nextMode].init(work, work->mode);
            work->mode = work->nextMode;
            work->state = FIELD_SUBSCREEN_STATE_FADE_IN;
        }
        break;
    case FIELD_SUBSCREEN_STATE_HALT:
        break;
    case FIELD_SUBSCREEN_STATE_FADE_IN:
        func_0202208C((void *)4, 1, 1, 0, 1, 1, work->heapId);
        work->state = FIELD_SUBSCREEN_STATE_FADE_IN_WAIT;
        break;
    case FIELD_SUBSCREEN_STATE_FADE_IN_WAIT:
        if (func_020221A4() == 1) {
            work->state = FIELD_SUBSCREEN_STATE_RUN;
        }
        d_021D872C[work->mode].update(work, func_02189A2C(work->fieldMap) == 0);
        break;
    }
}

void func_021A0E58(FieldSubscreen *work)
{
    s32 busy;

    switch (work->state) {
    case FIELD_SUBSCREEN_STATE_RUN:
        if (d_021D872C[work->mode].updateNoTransition != 0) {
            busy = func_02189A2C(work->fieldMap);
            d_021D872C[work->mode].updateNoTransition(work, busy == 0);
        }
        break;
    case FIELD_SUBSCREEN_STATE_FADE_OUT:
    case FIELD_SUBSCREEN_STATE_FADE_OUT_WAIT:
    case FIELD_SUBSCREEN_STATE_HALT:
    case FIELD_SUBSCREEN_STATE_FADE_IN:
    case FIELD_SUBSCREEN_STATE_FADE_IN_WAIT:
        break;
    }
}

int func_021A0EB0(FieldSubscreen *work, u32 mode)
{
    if (work->state == FIELD_SUBSCREEN_STATE_RUN && d_021D872C[work->mode].checkRequest != 0)
        return d_021D872C[work->mode].checkRequest(work, mode);
    return 0;
}

int func_021A0ED4(FieldSubscreen *work)
{
    if (work->state == FIELD_SUBSCREEN_STATE_RUN) {
        return 1;
    }
    return 0;
}

/* Maps the requested mode to the mode that can run: the C-Gear request falls
 * back to the no-C-Gear mode when the save has no C-Gear. */
u32 ov021_func_021A0EE4(FieldSubscreen *work, u32 mode)
{
    void *gameData;
    u32 zoneId;
    void *cgearSave;
    if (mode == FIELD_SUBSCREEN_MODE_CGEAR) {
        gameData = func_020120F4(func_02188C80(work->fieldMap));
        zoneId = func_02188C9C(work->fieldMap);
        if (func_02013D20() != 0 || func_02013D00(zoneId) != 0)
            return FIELD_SUBSCREEN_MODE_NO_CGEAR;
        cgearSave = func_02009210(func_02012EBC(gameData));
        if (func_020090E0(cgearSave) == 0)
            return FIELD_SUBSCREEN_MODE_NO_CGEAR;
    }
    return mode;
}

int func_021A0F30(FieldSubscreen *work, u32 mode)
{
    work->nextMode = ov021_func_021A0EE4(work, mode);
    work->state = FIELD_SUBSCREEN_STATE_FADE_OUT;
    return 1;
}

void func_021A0F40(FieldSubscreen *work, u32 mode)
{
    u32 resolved = ov021_func_021A0EE4(work, mode);
    d_021D872C[work->mode].exit(work);
    work->nextMode = resolved;
    d_021D872C[resolved].init(work, work->mode);
    work->mode = work->nextMode;
    work->state = FIELD_SUBSCREEN_STATE_RUN;
}

int func_021A0F7C(FieldSubscreen *work, u32 mode, void (*callback)(int), u32 callbackArg)
{
    work->callback = callback;
    work->callbackArg = callbackArg;
    work->nextMode = ov021_func_021A0EE4(work, mode);
    work->state = FIELD_SUBSCREEN_STATE_FADE_OUT;
    return 1;
}

u32 func_021A0F90(FieldSubscreen *work)
{
    return work->mode;
}

int func_021A0F94(FieldSubscreen *work)
{
    if (work != 0) {
        return work->panelResult;
    }
    return 0;
}

void func_021A0FA0(FieldSubscreen *work, int result)
{
    if (work == 0)
        return;
    work->panelResult = result;
}

void func_021A0FA8(FieldSubscreen *work)
{
    func_021A0FA0(work, 0);
}

void func_021A0FB4(FieldSubscreen *work, u32 heapId)
{
    func_021D3270(func_02188E30(work->fieldMap), 1, 0, 0, 0, 0);
    func_02193060(0);
    func_020414EC(1);
    func_021902A4(1, heapId);
}

void ov021_func_021A0FE8(FieldSubscreen *work)
{
    void *gameSystem;
    void *cgearSave;
    u32 cgearPowered, commState;
    gameSystem = func_02188C80(work->fieldMap);
    cgearSave = func_02009210(func_02012EBC(func_020120F4(gameSystem)));
    func_02034AC4((int)abs_id_1d);
    cgearPowered = func_02009208(cgearSave);
    commState = func_0201214C(gameSystem);
    work->cgear = func_021F279C(cgearSave, work, gameSystem, commState == 1 && cgearPowered == 0);
    func_02009200(cgearSave, commState);
    if (func_02012204(gameSystem) != 0)
        func_02012210(gameSystem);
}

void ov021_func_021A1050(FieldSubscreen *work)
{
    void *gameSystem;
    void *cgearSaveBase;
    void *cgearSave;
    u32 commState;
    gameSystem = func_02188C80(work->fieldMap);
    cgearSaveBase = func_02012EBC(func_020120F4(gameSystem));
    func_02034AC4((int)abs_id_1d);
    commState = func_0201214C(gameSystem);
    cgearSave = func_02009210(cgearSaveBase);
    work->cgear = func_021F27D8(cgearSave, work, func_02188C80(work->fieldMap), work->callback, work->callbackArg, commState);
    func_02009200(cgearSave, commState);
    if (func_02012204(gameSystem) != 0)
        func_02012210(gameSystem);
    work->mode = 0;
    work->nextMode = 0;
}

void func_021A10C0(FieldSubscreen *work)
{
    func_021F2984(work->cgear);
    func_02034A5C((int)abs_id_1d);
}

u32 func_021A10D4(FieldSubscreen *work) { return func_021F2980((u32)work->cgear); }

u32 ov021_func_021A10E0(FieldSubscreen *work, u32 active)
{
    u32 gameSystem, savedValue;
    if (active != 0) {
        gameSystem = (u32)func_02188C80(work->fieldMap);
        savedValue = (u32)func_02009210(func_02012EBC(func_020120F4((void *)gameSystem)));
        if (func_02012204((void *)gameSystem) != 0) {
            if (func_0201214C((void *)gameSystem) != 0) {
                func_02012210((void *)gameSystem);
            } else if (func_021F2994((int *)work->cgear) != 0) {
                func_02009200((void *)savedValue, 0);
                func_02012210((void *)gameSystem);
            }
        }
    }
    return func_021F2848((u32)work->cgear, active);
}

int func_021A1138(FieldSubscreen *work, int button)
{
    return func_021F29D8(work->cgear, button, work);
}

/*
 * Mode glue of the field sub-screen (field_subscreen.c): the init, update and
 * exit functions that rows of the mode table d_021D872C point to, and the
 * accessors other files call on the running mode. Modes in this file:
 *   1 start menu (field_menu.c), 2 Union Room panel (overlay 31),
 *   3 Entralink panel (intrude_subdisp.c), 5 panel shown while the save has
 *   no C-Gear (overlay 30).
 * Mode 0 (C-Gear) and mode 8 (C-Gear with callback) are in field_subscreen.c.
 */

/* Mode 5 init: loads overlay 30 and creates the panel from the C-Gear save. */
void func_021A1144(FieldSubscreen *work)
{
    void *cgearSave;

    func_02034AC4(FIELD_SUBSCREEN_OVERLAY_NO_GEAR);
    cgearSave = func_02009210(func_02012EBC(func_020120F4(func_02188C80(work->fieldMap))));
    work->cgear = func_021F00C8(cgearSave, work, func_02188C80(work->fieldMap));
}

/* Mode 5 exit. */
void func_021A117C(FieldSubscreen *work)
{
    func_021E0118(work->cgear);
    func_02034A5C(FIELD_SUBSCREEN_OVERLAY_NO_GEAR);
}

/* Mode 5 slot at table offset 0x14: calls the panel's empty hook. */
void func_021A1190(FieldSubscreen *work) { func_021F0114(work->cgear); }

/* Mode 5 update. */
void func_021A119C(FieldSubscreen *work) { func_021F00F8(work->cgear); }

/* Mode 1 init: sets up the lower screen BG and the start menu, and the info
 * window when the menu layout is not 1. The menu slides in when the previous
 * mode was the C-Gear or one of modes 2 to 6. */
void ov021_func_021A11A8(FieldSubscreen *work, u32 prevMode)
{
    void *gameSystem;
    u32 zoneId;
    void *gameData;
    void *eventWork;
    u32 slideIn;

    gameSystem = func_02188C80(work->fieldMap);
    zoneId = func_02012AC8(func_020120F8(gameSystem));
    gameData = func_020120F4(gameSystem);
    eventWork = func_0201296C(gameData);
    slideIn = 0;
    if (prevMode == FIELD_SUBSCREEN_MODE_CGEAR || prevMode - 2 <= 4)
        slideIn = 1;
    func_0203FCA0(4, &d_021D8708, 0);
    func_02040588(4, 1);
    func_020414AC(4);
    func_0204152C(4, 0);
    func_02043598(0x10, 1);
    work->cgear = (void *)func_021A836C(0x70, work->heapId, work, work->fieldMap, slideIn);
    if (func_021A8B18(gameData, eventWork, zoneId) != 1)
        func_02024A20(4, 0xe, gameData, work->heapId);
    func_021A8AFC(work->heapId, slideIn);
}

/* Mode 1 exit. */
void ov021_func_021A1244(FieldSubscreen *work)
{
    void *gameSystem;
    u32 zoneId;
    void *gameData;

    gameSystem = func_02188C80(work->fieldMap);
    zoneId = func_02012AC8(func_020120F8(gameSystem));
    gameData = func_020120F4(gameSystem);
    if (func_021A8B18(gameData, func_0201296C(gameData), zoneId) != 1)
        func_02024DCC();
    func_021A84BC((struct FieldMenu *)work->cgear);
    func_020403F4(4);
}

/* Mode 1 update. */
void func_021A1288(FieldSubscreen *work)
{
    func_02024ABC(func_021A85B4((struct FieldMenu *)work->cgear));
}

/* Mode 1 update outside transitions. */
void func_021A1298(FieldSubscreen *work) { func_021A8840((struct FieldMenu *)work->cgear); }

/* Button the start menu has selected; 0 when the menu is not the running mode. */
u32 func_021A12A4(FieldSubscreen *work)
{
    if (func_021A0F90(work) != FIELD_SUBSCREEN_MODE_MENU) {
        return 0;
    }
    return func_021A8E10((struct FieldMenu *)work->cgear);
}

/* Selects a button of the start menu when it is the running mode. */
void func_021A12BC(FieldSubscreen *work, u32 buttonId)
{
    if (func_021A0F90(work) == FIELD_SUBSCREEN_MODE_MENU)
        func_021A8E20((struct FieldMenu *)work->cgear, buttonId);
}

/*
 * Loads the lower screen backdrop (palette, tiles and tile map from archive
 * 0x47) and shows layer 1 of the field request block.
 * Lever: func_020490F4 takes (id, heap); passing heapId as its second argument
 * is what gives heapId its register before the constant's.
 */
void func_021A12D4(FieldSubscreen *work, u32 heapId)
{
    struct ArchiveHandle *archive = func_020490F4(0x47, heapId);
    func_02049BDC(archive, 0, 0, 0x140, 0x140, 0x20, heapId);
    func_02049658(archive, 3, 1, 0x64, 0, 0, heapId);
    func_02049990(archive, 0xf, 1, 0, 0x64, 0, 0, heapId);
    func_02049238(archive);
    func_021D3270(func_02188E30(work->fieldMap), 1, 0, 0, 0, -6);
    func_021D3244(func_02188E30(work->fieldMap), 1, 1);
}

/* Panel handle of the running C-Gear mode (mode 0 or 8); 0 for other modes. */
void *func_021A1358(FieldSubscreen *work)
{
    if (work->mode == FIELD_SUBSCREEN_MODE_CGEAR || work->mode == FIELD_SUBSCREEN_MODE_CGEAR_CALLBACK)
        return work->cgear;
    return 0;
}

/* Mode 2 init: loads overlay 31 and creates the Union Room panel. */
void func_021A136C(FieldSubscreen *work)
{
    func_02034AC4(FIELD_SUBSCREEN_OVERLAY_UNION);
    work->cgear = ov031_func_021EFEC0(func_02188C80(work->fieldMap));
}

/* Mode 2 exit. */
void func_021A1388(FieldSubscreen *work)
{
    func_021EFFE8(work->cgear);
    func_02034A5C(FIELD_SUBSCREEN_OVERLAY_UNION);
}

/* Mode 2 update: the panel takes touch input only while the Union Room link runs. */
void func_021A139C(FieldSubscreen *work, u32 isFieldIdle)
{
    void *gameSystem = func_02188C80(work->fieldMap);
    if (isFieldIdle == 1 && func_0217394C(gameSystem) == 0)
        isFieldIdle = 0;
    func_021F0054(work->cgear, isFieldIdle);
}

/* Mode 2 update outside transitions. */
void func_021A13C0(FieldSubscreen *work, u32 isFieldIdle)
{
    void *gameSystem = func_02188C80(work->fieldMap);
    if (isFieldIdle == 1 && func_0217394C(gameSystem) == 0)
        isFieldIdle = 0;
    func_021F00D4(work->cgear, isFieldIdle);
}

/* Mode 3 init: creates the Entralink panel (the overlay is already loaded). */
void ov021_func_021A13E4(FieldSubscreen *work)
{
    work->cgear = func_0217CFE4(func_02188C80(work->fieldMap));
}

/* Mode 3 exit. */
void func_021A13F8(FieldSubscreen *work)
{
    func_0217D160(work->cgear);
}

/* Mode 3 update. */
void func_021A1404(FieldSubscreen *work, int isFieldIdle)
{
    func_0217D1C0(work->cgear, isFieldIdle);
}

/* Mode 3 update outside transitions: redraws the panel. */
void func_021A1410(FieldSubscreen *work)
{
    func_0217D3AC(work->cgear);
}

/* Mode 3 request check: the panel's touch selection may start an event. */
void *func_021A141C(FieldSubscreen *work, int mode)
{
    return func_0217D4DC(work->cgear, mode, work);
}

/*
 * Glue of four rows of the field sub-screen mode table (modes 4, 6, 7, 9).
 * Each function forwards to the panel overlay loaded for that mode; the panel
 * handle lives in work->cgear. The overlay id is an absolute symbol, so it is
 * passed through a pointer cast.
 */

/* Mode 4 (beacon view, overlay 0x20) init: load the overlay and create the panel. */
void func_021A1428(FieldSubscreen *work)
{
    func_02034AC4((int)abs_id_20);
    work->cgear = func_021F2234(func_02188C80(work->fieldMap), work);
}

/* Mode 4 exit: delete the beacon view panel and unload its overlay. */
void func_021A1448(FieldSubscreen *work)
{
    func_022022FC(work->cgear);
    func_02034A5C((int)abs_id_20);
}

/* Mode 4 update. */
int func_021A145C(FieldSubscreen *work) { return func_021F2344(work->cgear); }

/* Mode 4 update outside transitions. */
int func_021A1468(FieldSubscreen *work) { return func_021F23F8(work->cgear); }

/* Mode 4 request check. */
int func_021A1474(FieldSubscreen *work) { return func_021F2404(work->cgear); }

/* Mode 6 (dowsing, overlay 0x21) init: load the overlay and create the panel. */
void func_021A1480(FieldSubscreen *work)
{
    func_02034AC4((int)abs_id_21);
    work->cgear = func_021F000C(0x70, work->heapId, work, work->fieldMap);
}

/* Mode 6 exit: delete the dowsing panel and unload its overlay. */
void func_021A14A0(FieldSubscreen *work)
{
    func_02210124(work->cgear);
    func_02034A5C((int)abs_id_21);
}

/* Mode 6 update. */
int func_021A14B4(FieldSubscreen *work) { return func_021F0174(work->cgear); }

/* Mode 6 update outside transitions. */
int func_021A14C0(FieldSubscreen *work) { return func_021F05A4(work->cgear); }

/* Mode 7 (save report, overlay 0x22) init: load the overlay and create the panel. */
void func_021A14CC(FieldSubscreen *work)
{
    func_02034AC4((int)abs_id_22);
    work->cgear = func_021EFEC0(func_02188C80(work->fieldMap), work->heapId);
}

/* Mode 7 exit: delete the report panel and unload its overlay. */
void func_021A14EC(FieldSubscreen *work)
{
    func_021EFF34(work->cgear);
    func_02034A5C((int)abs_id_22);
}

/* Mode 7 update: show the panel objects once the print queue is idle. */
void func_021A1500(FieldSubscreen *work)
{
    func_021EFF5C(work->cgear);
}

/* Mode 7 update outside transitions: windows and texts of the panel. */
void func_021A150C(FieldSubscreen *work)
{
    func_021EFFB4(work->cgear);
}

/* Report panel: true once its windows are shown (state 3). Called by the report event. */
int func_021A1518(FieldSubscreen *work)
{
    return func_021F0044(work->cgear);
}

/* Report panel: read the save counters and reset the progress bar. */
void func_021A1524(FieldSubscreen *work)
{
    func_021F0058(work->cgear);
}

/* Report panel: start the saving animation. */
void func_021A1530(FieldSubscreen *work)
{
    func_021F00BC(work->cgear);
}

/* Report panel: true when the saving animation has run to its end. */
int func_021A153C(FieldSubscreen *work)
{
    return func_021F00F0(work->cgear);
}

/* Report panel: stop the saving animation (the save failed). */
void func_021A1548(FieldSubscreen *work)
{
    func_021F0108(work->cgear);
}

/* Report panel: true when the first counter reached a third of the second one. */
int func_021A1554(FieldSubscreen *work)
{
    return func_021F009C(work->cgear);
}

/* Mode 9 (power on/off, overlay 0x23) init: load the overlay and create the panel. */
void func_021A1560(FieldSubscreen *work)
{
    func_02034AC4((int)abs_id_23);
    work->cgear = ov035_func_021EFEC0(work, func_02188C80(work->fieldMap), 0x70);
}

/* Mode 9 update. */
int func_021A1584(FieldSubscreen *work) { return func_021EFF3C(work->cgear); }

/* Mode 9 exit: delete the power on/off panel and unload its overlay. */
void func_021A1590(FieldSubscreen *work)
{
    func_021EFF2C(work->cgear);
    func_02034A5C((int)abs_id_23);
}
