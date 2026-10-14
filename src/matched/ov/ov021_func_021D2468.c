/*
 * function: SCRCMD_GetBirthdayMessageIds
 * address:  0x021D2468
 * packet:   pkt_ov021_021D2468
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008B08  0x02008B08  thumb
 *   FIELD_CLOCK_GetMonth  0x021690D0  thumb  ov010
 *   FIELD_CLOCK_GetDay  0x021690E0  thumb  ov010
 *   func_02008B94  0x02008B94  thumb
 *   func_02008B98  0x02008B98  thumb
 *   func_020056EC  0x020056EC  thumb
 *   gBirthdayTextIdTable     0x021DD6D0  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 h[31];
} Tbl;

extern Tbl gBirthdayTextIdTable;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
typedef unsigned char  u8;
struct Big;
struct Sub02008AECObj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008AECObj *func_02008B08(void *sys);
extern int FIELD_CLOCK_GetMonth(int a0);
extern int FIELD_CLOCK_GetDay(int a0);
extern u8 func_02008B94(const struct Sub02008AECObj *obj);
extern u8 func_02008B98(const struct Sub02008AECObj *obj);
extern u32 func_020056EC(u32 a);

int SCRCMD_GetBirthdayMessageIds(u32 a, u32 b)
{
    u32 x, y, z, v, w, k;
    u16 *p6, *p4, *p5;
    Tbl t;

    x = (u32)SCRCMD_WORK_GetGameData((void *)b); /* int-typed on purpose: pointer local changes codegen */
    y = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    p6 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    p4 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    p5 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    t = gBirthdayTextIdTable;
    z = (u32)func_02008B08(GAME_DATA_GetSaveControl((struct Big *)x));
    v = FIELD_CLOCK_GetMonth(x);
    w = FIELD_CLOCK_GetDay(x);
    k = func_02008B94((const struct Sub02008AECObj *)z);
    if (w == func_02008B98((const struct Sub02008AECObj *)z) && v == k) {
        *p6 = 0x34;
        *p4 = 0x53;
        *p5 = t.h[30];
    } else {
        u32 i = func_020056EC(y ? 0x1E : 0x16);
        *p6 = i + 0x16;
        *p4 = i + 0x35;
        *p5 = t.h[i];
    }
    return 0;
}
