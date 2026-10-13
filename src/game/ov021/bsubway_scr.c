/*
 * file:     bsubway_scr.c
 * unit:     yes
 * function: func_021C9924, func_021C9934, func_021C9B24, func_021C9B78, func_021C9BCC, func_021C9C54, func_021C9CAC, func_021C9D30, func_021C9D70, func_021C9DB0, func_021C9E8C, func_021C9F44, func_021C9FD0, func_021C9FFC, func_021CA048, func_021CA05C, func_021CA150, func_021CA164, func_021CA1E4, func_021CA210, func_021CA234, func_021CA238, func_021CA23C, func_021CA250, func_021CA258, func_021CA270, func_021CA2A4, func_021CA2CC, func_021CA2DC, func_021CA338, func_021CA3B4, func_021CA4C0, func_021CA544, func_021CA57C, func_021CA598, func_021CA5C4, func_021CB6DC, func_021CB700, func_021CB754, func_021CB7E8, func_021CB86C, func_021CB8AC, func_021CB914, func_021CB934, func_021CB9BC, func_021CB9E4, func_021CBBA0, func_021CBBAC, func_021CBBD0, func_021CBC14, func_021CBC94, func_021CBCC4, func_021CBD08, func_021CBD84, func_021CBD90, func_021CBED8, func_021CBEFC, func_021CBF38, func_021CBF98
 * address:  0x021C9924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * bsubway_scr.c __FILE__ anchors at 0x021C9934 and 0x021CA4C0; 0x021C9924 is called only from 0x021CA57C.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02012EE4  0x02012EE4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   d_021DE58C     0x021DE58C  data  ov021
 *   func_02008550  0x02008550  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200D868  0x0200D868  thumb
 *   func_0200D85C  0x0200D85C  thumb
 *   func_0200DA14  0x0200DA14  thumb
 *   func_0200DB44  0x0200DB44  thumb
 *   func_0200DAC4  0x0200DAC4  thumb
 *   func_0200D914  0x0200D914  thumb
 *   func_0200D884  0x0200D884  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_0200DA54  0x0200DA54  thumb
 *   func_0200DB80  0x0200DB80  thumb
 *   func_020130B4  0x020130B4  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200DB1C  0x0200DB1C  thumb
 *   func_0200DB08  0x0200DB08  thumb
 *   func_0200DAEC  0x0200DAEC  thumb
 *   func_0200DC08  0x0200DC08  thumb
 *   func_0200DA80  0x0200DA80  thumb
 *   d_021DACDC     0x021DACDC  data  a1
 *   func_0200DB60  0x0200DB60  thumb
 *   func_0200DEA8  0x0200DEA8  thumb
 *   func_02168AEC  0x02168AEC  thumb  ov010
 *   func_0200DBA0  0x0200DBA0  thumb
 *   func_0200DBF0  0x0200DBF0  thumb
 *   func_0200DC0C  0x0200DC0C  thumb
 *   func_0200DBFC  0x0200DBFC  thumb
 *   data_021DACD0  0x021DACD0  data
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_0200DC94  0x0200DC94  thumb
 *   func_0200DC50  0x0200DC50  thumb
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02012ED8  0x02012ED8  thumb
 *   data_021DAD24  0x021DAD24  data
 *   data_021DAD36  0x021DAD36  data
 *   data_021DAD70  0x021DAD70  data
 *   data_021DAD88  0x021DAD88  data
 *   data_021DADAC  0x021DADAC  data
 *   data_021DAE50  0x021DAE50  data
 *   func_0200B424  0x0200B424  thumb
 *   func_0200B5CC  0x0200B5CC  thumb
 *   func_0200BA38  0x0200BA38  thumb
 *   func_0200BA58  0x0200BA58  thumb
 *   func_0200BA68  0x0200BA68  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *   func_0200D87C  0x0200D87C  thumb
 *   func_0200D9E8  0x0200D9E8  thumb
 *   func_0200DA28  0x0200DA28  thumb
 *   func_0200DB30  0x0200DB30  thumb
 *   func_0200DE5C  0x0200DE5C  thumb
 *   func_0200DE64  0x0200DE64  thumb
 *   func_0200DE94  0x0200DE94  thumb
 *   func_0200DF40  0x0200DF40  thumb
 *   func_0200DF4C  0x0200DF4C  thumb
 *   func_0200DF58  0x0200DF58  thumb
 *   func_0200DF94  0x0200DF94  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0200ED54  0x0200ED54  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_02012124  0x02012124  thumb
 *   func_02012134  0x02012134  thumb
 *   func_020124AC  0x020124AC  thumb
 *   func_0201289C  0x0201289C  thumb
 *   ov007_id       0x00000007  data  a1
 *   ov100_id       0x00000064  data  a1
 *   ov214_id       0x000000D6  data  a1
 *   func_0201296C  0x0201296C  thumb
 *   func_02014184  0x02014184  thumb
 *   func_02014314  0x02014314  thumb
 *   func_0201433C  0x0201433C  thumb
 *   func_02014808  0x02014808  thumb
 *   func_02019ED4  0x02019ED4  thumb
 *   func_0201A354  0x0201A354  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0202B578  0x0202B578  thumb
 *   func_0202C0D0  0x0202C0D0  thumb
 *   func_02039338  0x02039338  arm
 *   func_02087BCC  0x02087BCC  arm
 *   func_021542C0  0x021542C0  thumb  ov007
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02158FE0  0x02158FE0  thumb  ov010
 *   func_02167AB0  0x02167AB0  thumb  ov010
 *   func_02167B00  0x02167B00  thumb  ov010
 *   func_02167B24  0x02167B24  thumb  ov010
 *   func_02167BFC  0x02167BFC  thumb  ov010
 *   func_02167CF4  0x02167CF4  thumb  ov010
 *   func_0216C538  0x0216C538  thumb  ov010
 *   func_0216C640  0x0216C640  thumb  ov010
 *   func_0216C6E8  0x0216C6E8  thumb  ov010
 *   func_0216C860  0x0216C860  thumb  ov010
 *   func_0216CB48  0x0216CB48  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A30B0  0x021A30B0  thumb  ov021
 *   func_021A3190  0x021A3190  thumb  ov021
 *   func_021A31A4  0x021A31A4  thumb  ov021
 *   data_021BB474  0x021BB474  data  ov214
 *   data_021BB6A4  0x021BB6A4  data  ov100
 *   func_021CD48C  0x021CD48C  thumb  ov021
 *   func_021D024C  0x021D024C  thumb  ov021
 *   func_021D028C  0x021D028C  thumb  ov021
 *   func_021EEE78  0x021EEE78  thumb  ov188
 *   func_021F37C0  0x021F37C0  thumb  ov052
 *   func_021F380C  0x021F380C  thumb  ov052
 *   func_021F388C  0x021F388C  thumb  ov052
 *   func_02167CB4  0x02167CB4  thumb  ov010
 *   func_02167B34  0x02167B34  thumb  ov010
 *   func_021CD688  0x021CD688  thumb  ov021
 *   func_021CD5A4  0x021CD5A4  thumb  ov021
 *   func_02167D00  0x02167D00  thumb  ov010
 *   func_0203D378  0x0203D378  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02167B18  0x02167B18  thumb  ov010
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0215A684  0x0215A684  thumb  ov010
 *   func_0215A690  0x0215A690  thumb  ov010
 *   func_02188C54  0x02188C54  thumb
 *   func_02190BE4  0x02190BE4  thumb
 *   func_02190C78  0x02190C78  thumb
 *   func_021909BC  0x021909BC  thumb
 *   func_0200DFB4  0x0200DFB4  thumb
 *   func_0216CE6C  0x0216CE6C  thumb  ov010
 *   func_0216D620  0x0216D620  thumb  ov010
 *   func_0216D5B4  0x0216D5B4  thumb  ov010
 *   d_021DADD0     0x021DADD0  data  a2
 *   d_021DAD48     0x021DAD48  data  a2
 *   d_021DAD5C     0x021DAD5C  data  a2
 *   d_021DAEBC     0x021DAEBC  data  a2
 *   d_021DADF8     0x021DADF8  data  a4
 *   data_021DAEBC  0x021DAEBC  data
 *   func_0200B6E0  0x0200B6E0  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_021681C8  0x021681C8  thumb  ov010
 *   d_021DB3D0  0x021DB3D0  data
 *   d_021DB3D8  0x021DB3D8  data
 *   d_021DB3E4  0x021DB3E4  data
 *   d_021DB3F4  0x021DB3F4  data
 *   func_02168878  0x02168878  thumb  ov010
 *   func_021688BC  0x021688BC  thumb  ov010
 *   func_021684E8  0x021684E8  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 */

#define NULL ((void *)0)
struct GameSystem;
struct GameData;
struct ScriptStream;
struct Task;
struct FieldMap;
struct VecFx32;
struct MapObj;
struct BsubwayScoreData;
struct BsubwayPlayData;
struct SaveControl;
struct MyStatus;
struct BsubwayRecordSrc;
struct BsubwayWifiRecordList;
struct GdsProfileSave;
struct Ov007ProcParam;
struct BsubwayWifiData;
struct ReturnLocation;
struct PartySelectParam;
struct ScreenHandle;
struct WifiRecordEntry;
struct Party;
struct PartyMon;
struct BattleSystem;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

typedef signed char    s8;

typedef int (*TaskFn)(void *task, int *state, void *work);

typedef signed int     s32;

#include "bsubway_scr_types.h"












/* Work area of the sub-screen task (fade out, run the screen, report whether it was cancelled). */
typedef struct ScreenTaskWork {
    void *script;
    u16 *result;
    u32 screen;
    u32 arg;
} ScreenTaskWork;

typedef struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

/* Seven-word entrance location record (zone, direction, position). */
typedef struct ReturnLocation {
    u32 word[7];
} ReturnLocation;

/* Parameter of the ov007 proc started by commands 103 to 105. */
typedef struct Ov007ProcParam {
    u32 mode;
    u16 *result;
} Ov007ProcParam;

/* Index of the record entry written by the progress record command. */
typedef enum BsubwayRecordNo {
    BSUBWAY_RECORD_NO_FIRST
} BsubwayRecordNo;

/* Spawn position of a record-list marker object (halfword pairs). */
typedef struct SpawnPos {
    s16 x;
    s16 reserved02;
    s16 y;
    s16 reserved06;
} SpawnPos;

/* One 0x10-byte marker object table entry. */
typedef struct SpawnEntry {
    u16 objCode;
    u16 thresholdNo;
    s16 x;
    u16 reserved06;
    s16 y;
    u16 param;
    u32 reserved0C;
} SpawnEntry;

/* Byte at +0x20 of a wifi record list entry. */
typedef struct WifiRecordFlags {
    u8 flag0 : 1;
    u8 lookSet : 1;
} WifiRecordFlags;

/* 0x10-byte NPC table entry; infoThird == 0 marks an unavailable entry. */
typedef struct NpcInfoEntry {
    u8 reserved00[0xa];
    u16 infoFirst;
    u16 infoSecond;
    u16 infoThird;
} NpcInfoEntry;

typedef struct TrainerNoRange {
    u16 minNo;
    u16 maxNo;
} TrainerNoRange;


extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct GameSystem *p);
extern void *func_020120F4(const struct GameSystem *p);
extern void *func_0215A5F4(void *p);
extern u16 func_02011330(struct ScriptStream *s);
extern u16 func_02159B10(void *a, void *b);
extern struct Task *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Task *p);
extern void *func_02188CB4(struct FieldMap *p);
extern u16 func_0216D5F8(void *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_0216D5E0(int a, int b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_0216D88C(const struct MapObj *a, struct VecFx32 *v);
extern void *func_02012EE4(GameData *gameData, BsubwayScrWork *work);
extern u8 *func_02012944(void *p);
extern void *func_02012EBC(struct GameData *p);
extern u8 func_02008550(const struct MyStatus *obj);
extern void *func_020071CC(struct SaveControl *ctrl, u32 id);
extern void func_0200D868(struct BsubwayPlayData *p, u32 v);
extern void func_0200D85C(struct BsubwayPlayData *p);
extern void func_0200DA14(struct BsubwayPlayData *p);
extern u32 func_0200DB44(struct BsubwayScoreData *p, u32 i);
extern u16 func_0200DAC4(struct BsubwayScoreData *p, u32 i);
extern void func_0200D914(struct BsubwayPlayData *p, u32 id, const void *src);
extern u32 func_0200D884(struct BsubwayPlayData *p, u32 id, void *out);
extern void *func_020127A4(void *p);
extern u16 func_0200DA54(struct BsubwayPlayData *p);
extern u16 func_0200DB80(struct BsubwayScoreData *p, u32 i);
extern int func_020130B4(int a0);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *m, u32 id, u32 v);
extern void func_0200DB1C(struct BsubwayScoreData *p, u32 i);
extern void func_0200DB08(struct BsubwayScoreData *p, u32 i, u16 v);
extern void func_0200DAEC(struct BsubwayScoreData *p, u32 i, u16 v);
extern u8 func_0200DC08(struct BsubwayScoreData *p);
extern void func_0200DA80(struct BsubwayScoreData *p, s32 v);
extern void func_0200DB60(struct BsubwayScoreData *p, u32 i);
extern void func_0200DEA8(u32 h, u8 *list, u8 n, u16 id);
extern u16 func_02168AEC(u16 a0);
extern u32 func_0200DBA0(struct BsubwayScoreData *p, s32 i, u32 op);
extern void func_0200DBF0(struct BsubwayScoreData *p);
extern u8 func_0200DC0C(struct BsubwayScoreData *p, u32 kind);
extern void func_0200DBFC(struct BsubwayScoreData *p);
extern void *func_0200BAC8(void *p);
extern void *func_0200BAF4(int a0, int a1);
extern void *func_02012934(const struct GameData *p);
extern int func_0209C0A4(int a, int b);
extern void func_0200DC94(struct BsubwayScoreData *p, const struct BsubwayRecordSrc *q);
extern void func_0200DC50(struct BsubwayScoreData *p, u32 which, const void *src);
extern int func_02158F58(int a0);
extern void *func_02158F54(void *p);
extern void *func_02012ED8(struct GameData *p);
extern u32 func_0201296C(const struct GameData *p);
extern u16 *func_02158FE0(void *a, void *b, unsigned int id);
extern void func_0215897C(void *h, void *task);
extern void func_02087BCC(u32 a);
extern u32 func_0200D87C(struct BsubwayPlayData *p);
extern u16 func_021A3050(u8 *p);
extern u16 func_02188C9C(u8 *p);
extern void func_02014184(ReturnLocation *out, u32 id, s16 n, u32 a, u32 b, u32 c);
extern void func_0201289C(struct GameData *p, const struct ReturnLocation *src);
extern void func_02014314(char *a0, int a1);
extern void func_0201433C(char *a0, int a1);
extern u32 func_021A30B0(u8 *p);
extern u16 func_021A3190(int i, int j);
extern void *func_02188C7C(unsigned char *p);
extern void *func_0216DE94(void *a, u32 id);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void func_021F37C0(void *a, int b, int c);
extern int func_021F380C(int a);
extern void func_021D024C(void *o, u32 v);
extern void func_021D028C(void *o, u32 v);
extern void func_0216E014(void *a, int *p, int b);
extern int func_0216DB4C(void *a0, int a1);
extern int func_021A31A4(int i, int v);
extern u32 func_0200BBA8(void *a);
extern void func_0216DAF8(void *o);
extern int func_0216D63C(char *a0, int a1);
extern void *func_0216CB48(u32 x, u32 v, u32 id);
extern struct BsubwayWifiRecordList *func_0200DF58(struct BsubwayWifiData *p, u32 heap);
extern u32 func_0200DF94(struct BsubwayWifiRecordList *b);
extern struct Task *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern int func_021542C0(int x, struct Ov007ProcParam *p);
extern u8 func_0200DE94(struct BsubwayWifiData *p);
extern u8 func_0200DE5C(struct BsubwayWifiData *p);
extern u8 func_0200DE64(struct BsubwayWifiData *p);
extern void *func_0216C860(void *a);
extern int func_0200DF40(struct BsubwayWifiData *p);
extern u8 func_0200DF4C(struct BsubwayWifiData *p);
extern void *func_0216C538(struct PartySelectParam *c, void *sys, u8 useOwn);
extern void *func_0216C640(BsubwayScrWork *work, u32 gameSystem, void *fieldMap);
extern void *func_0216C6E8(BsubwayScrWork *work, void *gameSystem, u32 idx, u16 id, u8 dir);
extern u32 func_02012134(u32 *p);
extern u32 func_0202B578(u32 *p);
extern void func_0202C0D0(u8 *p, u32 a);
extern void *func_0201A354(int a, int b);
extern int func_02019ED4(void *ctx, void *q);
extern u32 func_0200B5CC(void *a, u32 heap, u32 *dp, u32 id);
extern void func_0200BA58(void);
extern void func_021EEE78(void *p);
extern void func_0200BA68(void);
extern void func_020113D0(char *p, int val);
extern void func_0200B424(void);
extern void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void func_021F388C(int a);
extern u32 func_0201AA18(void *party);
extern void func_0200D9E8(struct BsubwayPlayData *p, s32 a, s32 b, s32 c);
extern void func_0200DA28(struct BsubwayPlayData *p);
extern void func_0200DB30(struct BsubwayScoreData *p, u32 i);
extern void func_02167B00(u32 a);
extern void func_02167AB0(void *p);
extern int func_02167B24(int a0);
extern u32 func_021CD48C(u32 a, void *b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_02167BFC(BsubwayScrWork *work, u32 cmd, u32 arg);
extern void func_02167CF4(BsubwayScrWork *work, u8 v);
extern u16 func_02039338(void);
extern void func_0200ED54(struct GdsProfileSave *l, u32 val);
extern void *func_0200ED48(void *p);
extern void func_0200FB38(void);
extern void func_02012124(struct GameSystem *p, u32 v);
extern u32 func_0200FB24(void);
extern u32 func_0200BA38(u32 v);
extern int func_02167CB4(BsubwayScrWork *work);
extern int func_02167B34(int a0);
extern u32 func_021CD688(u8 *p);
extern u32 func_021CD5A4(u32 *p);
extern int func_02167D00(BsubwayScrWork *work, u16 *out);
extern u32 func_0203D378(void);
extern void func_0203D7BC(u8 a0);
extern void func_02167B18(void *p);
extern int func_0203D1B4(void);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
extern void func_0215A684(int *p, unsigned short v);
extern int func_0215A690(char *a0);
extern u32 func_02188C54(u8 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct ScreenHandle *h);
extern int func_021909BC(void *a);
extern u32 func_0200DFB4(struct WifiRecordEntry *e);
extern void *func_0216CE6C(void *o, int x, int y, u16 d, u32 a, u32 b, u32 c, u32 e);
extern int func_0216D620(int a0, int a1, int a2);
extern void func_0216D5B4(void *h, u16 v);
extern u32 func_0200B6E0(void *a, u16 b, u32 c, u32 d, u32 e, u16 *state, u16 *sub);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201A954(struct Party *p, s32 capacity);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern struct BattleSystem *func_021681C8(void *gameSystem, void *party, u32 playMode, BtlInstTrainer *trainers, BtlInstTrainer *partner, int memberNum);
extern u8 func_02168878(BtlInstTrainer *trainer, u16 trainerNo, u8 memberNum, u16 *monsNo, u16 *itemNo, BtlInstDraw *draw, u16 heapId);
extern void *func_021688BC(BtlInstTrainer *trainer, int trainerNo, u16 heapId);
extern u32 func_021684E8(struct BattleMon *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap);
extern u32 func_020056EC(u32 max);
int func_021C9924(GameSystem *gameSystem);
BsubwayScrWork *func_021C9934(GameSystem *gameSystem, int resume, u32 playMode);
void func_021C9B24(GameSystem *gameSystem, BsubwayScrWork *work);
void func_021C9B78(BsubwayScrWork *work);
void func_021C9BCC(BsubwayScrWork *work);
void func_021C9C54(BsubwayScrWork *work, u32 unused);
void func_021C9CAC(BsubwayScrWork *work);
u32 func_021C9D30(const struct GameSystem *gameSystem);
void func_021C9D70(u32 unused, BsubwayScrWork *work);
u32 func_021C9DB0(BsubwayScrWork *work);
void func_021C9E8C(BsubwayScrWork *work);
u32 func_021C9F44(BsubwayScrWork *work, u32 unused);
int func_021C9FD0(BsubwayScrWork *work);
void func_021C9FFC(BsubwayScrWork *work, u32 unused);
int func_021CA048(BsubwayScrWork *work, u32 unused);
void func_021CA05C(BsubwayScrWork *work);
u32 func_021CA150(BsubwayScrWork *work, int i);
int func_021CA164(void *scoreData, int unused, int mode);
void func_021CA1E4(BsubwayScrWork *work);
void *func_021CA210(BsubwayScrWork *work);
u16 func_021CA234(BsubwayScrWork *work);
void func_021CA238(BsubwayScrWork *work, u16 winCount);
void func_021CA23C(BsubwayScrWork *work);
int func_021CA250(BsubwayScrWork *work);
void func_021CA258(BsubwayScrWork *work, u32 stage, u32 round);
int func_021CA270(u16 playMode);
int func_021CA2A4(const u16 *list, u16 value, u16 count);
u16 func_021CA2CC(u16 winCount);
void func_021CA2DC(BsubwayScrWork *work, u32 saveControl, int unused, u16 winCount);
void func_021CA338(BsubwayScrWork *work, u8 isAltRom);
void func_021CA3B4(BattleMon *mon, u32 pokeParam);
void func_021CA4C0(BsubwayScrWork *work, u32 unused, int slot);
int func_021CA544(u32 script, u32 scriptCtx);
int func_021CA57C(u32 script, u32 scriptCtx);
int func_021CA598(u32 script, u32 scriptCtx);
int func_021CA5C4(void *scriptCtx, u32 script);
int func_021CB6DC(void *task, void *script);
int func_021CB700(u32 unused, u32 script);
int func_021CB754(u32 unused, u32 script);
int func_021CB7E8(u32 unused, u32 script);
int func_021CB86C(u32 unused, u32 script);
int func_021CB8AC(void *task, int *rank, BsubwayScrWork **work);
void *func_021CB914(void *gameSystem, u32 script);
int func_021CB934(void *task, int *rank, ScreenTaskWork *taskWork);
void *func_021CB9BC(void *gameSystem, u32 script, u32 resultDst, u32 arg);
void func_021CB9E4(BsubwayScrWork *work, void *gameData, void *fieldMmdlSys, void *fieldMap);
u32 func_021CBBA0(u32 mapObj);
u32 func_021CBBAC(BsubwayScrWork *work, u32 idx);
void func_021CBBD0(BsubwayScrWork *work, u32 idx, u16 *infoFirst, u16 *infoSecond, u16 *infoThird);
int func_021CBC14(u32 unused, u32 script);
int func_021CBC94(u32 playMode);
int func_021CBCC4(void *fieldMap);
u32 func_021CBD08(BsubwayScrWork *work, int gameSystem);
void *func_021CBD84(void *work);
u16 func_021CBD90(BsubwayScrWork *work, u32 round, u32 stage, u32 line, u8 alt);
u8 func_021CBED8(BsubwayScrWork *work, BtlInstTrainer *trainer, u16 trainerNo, u8 memberNum, u16 *monsNo, u16 *itemNo, BtlInstDraw *draw, u16 heapId);
u8 func_021CBEFC(u32 trainerNo);
void func_021CBF38(BsubwayScrWork *work, BtlInstTrainer *trainer, u16 trainerNo, int useItem, BtlInstDraw *draw, u16 heapId);
u16 func_021CBF98(void *unused);
extern const char d_021DE58C[];
extern const u8 d_021DACDC[7][10];
extern const u8 data_021DACD0[];
extern u8 data_021BB474[];
extern u8 data_021BB6A4[];
extern char ov007_id[];
extern char ov100_id[];
extern char ov214_id[];
extern const u16 data_021DAD36[];
extern const u32 data_021DAD88[];
extern const VecFx32 data_021DAD70[];
extern const VecFx32 data_021DAE50[];
extern const u32 data_021DADAC[];
extern const u16 data_021DAD24[];
extern const SpawnPos d_021DADD0[];
extern const u16 d_021DAD48[];
extern const u16 d_021DAD5C[];
extern const SpawnEntry d_021DAEBC[];
extern const u32 d_021DADF8[];
extern const NpcInfoEntry data_021DAEBC[];
extern const TrainerNoRange d_021DB3D0[];
extern const TrainerNoRange d_021DB3D8[];
extern const TrainerNoRange d_021DB3E4[];
extern const TrainerNoRange d_021DB3F4[];






/*
 * Blocking site: the bl to func_02012EE4 at +0008 of this function.
 *
 * no listing carries scoreData func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and scoreData region hint cannot invent one.  Filing scoreData source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C9924(GameSystem *gameSystem)
{
    return (int)func_02012EE4(func_020120F4(gameSystem), 0);
}






BsubwayScrWork *func_021C9934(GameSystem *gameSystem, int resume, u32 playMode)
{
    GameData *gameData;
    void *myStatus;
    SaveControl *saveControl;
    BsubwayScrWork *work;
    int i;
    u32 trainerBase;
    u32 mode;
    u16 round;
    u8 saveByte;

    gameData = func_020120F4(gameSystem);
    myStatus = func_02012944(gameData);
    saveControl = func_02012EBC(gameData);
    work = func_02030734(4, 0x7EC, 1, d_021DE58C, 0x5f);
    work->heapId = 4;
    work->magic = 0x12345678;
    work->gameData = gameData;
    work->romCode = func_02008550(myStatus);
    work->playData = func_020071CC(saveControl, 0x39);
    work->scoreData = func_020071CC(saveControl, 0x3a);
    work->wifiData = func_020071CC(saveControl, 0x3b);
    func_0200D868(work->playData, 0);
    func_02012EE4(gameData, work);
    if (resume == 0) {
        work->playMode = playMode;
        work->memberNum = func_021CA270(work->playMode);
        for (i = 0; i < 4; i++)
            work->memberIndex[i] = 0xff;
        for (i = 0; i < 14; i++)
            work->trainerNo[i] = 0xffff;
        func_0200D85C(work->playData);
        func_0200DA14(work->playData);
        if (func_0200DB44(work->scoreData, work->playMode) == 1)
            func_021CA238(work, func_0200DAC4(work->scoreData, work->playMode));
        saveByte = work->playMode;
        func_0200D914(work->playData, 0, &saveByte);
    } else {
        work->playMode = func_0200D884(work->playData, 0, 0);
        work->memberNum = func_021CA270(work->playMode);
        if (func_0200D884(work->playData, 10, 0) != 0)
            func_021CA1E4(work);
        func_0200D884(work->playData, 5, work->memberIndex);
        func_0200D884(work->playData, 8, work->trainerNo);
        if (work->playMode == 2 || work->playMode == 7) {
            work->stateBits.partnerNo = (u8)func_0200D884(work->playData, 9, 0);
            func_0200D884(work->playData, 6, &work->partnerDraws[work->stateBits.partnerNo]);
            trainerBase = 0x12f;
            if (func_02008550((const struct MyStatus *)((u8 *)func_020127A4(gameData) + 0x20)) != 0)
                trainerBase -= 3;
            i = work->stateBits.partnerNo;
            func_021CBF38(work, &work->partners[i], trainerBase + i, func_0200D884(work->playData, 7, 0), &work->partnerDraws[i], work->heapId);
        }
        mode = work->playMode;
        if (func_0200DB44(work->scoreData, mode) == 1) {
            round = func_0200DA54(work->playData);
            func_021CA258(work, func_0200DB80(work->scoreData, mode), round);
        }
    }
    return work;
}






void func_021C9B24(GameSystem *gameSystem, BsubwayScrWork *work)
{
    if (work != 0) {
        if (work->partyCopy != 0) {
            func_020307B0(work->partyCopy);
            work->partyCopy = 0;
        }
        if (work->btlSetup != 0) {
            func_020130B4((int)(work->btlSetup));
            work->btlSetup = 0;
        }
        func_02082BCC(work, 0, 0x7EC);
        func_020307B0(work);
    }
    func_02012EE4(func_020120F4(gameSystem), 0);
}






/*
 * Remaps playMode 2/7 to 3/8, pushes it to the play data and refreshes winCount from the score data.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9B78(BsubwayScrWork *work)
{
    u8 commMode;

    if (work->playMode == 2)
        commMode = 3;
    else if (work->playMode == 7)
        commMode = 8;
    work->playMode = commMode;
    func_0200D914(work->playData, 0, &commMode);
    if (func_0200DB44(work->scoreData, work->playMode) == 1)
        func_021CA238(work, func_0200DAC4(work->scoreData, work->playMode));
    else
        func_021CA250(work);
}






/*
 * Pushes playMode, the memberIndex and trainerNo blocks and, for playMode 2/7, the selected partnerResult entry to the play data.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9BCC(BsubwayScrWork *work)
{
    u8 saveByte = work->playMode;

    func_0200D914(work->playData, 0, &saveByte);
    func_0200D914(work->playData, 5, work->memberIndex);
    func_0200D914(work->playData, 8, work->trainerNo);
    func_0200D868(work->playData, 1);
    if (work->playMode == 2 || work->playMode == 7) {
        saveByte = work->stateBits.partnerNo;
        func_0200D914(work->playData, 9, &saveByte);
        func_0200D914(work->playData, 6, &work->partnerDraws[work->stateBits.partnerNo]);
        func_0200D914(work->playData, 7, &work->partnerResult[work->stateBits.partnerNo]);
    }
}






/*
 * Classifies playMode into memberNum and reads two stats per slot into memberMonsNo and memberItemNo.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9C54(BsubwayScrWork *work, u32 unused)
{
    void *party;
    int i;
    u32 mon;

    work->memberNum = func_021CA270(work->playMode);
    func_0200D884(work->playData, 5, work->memberIndex);
    party = func_021CA210(work);
    for (i = 0; i < work->memberNum; i++) {
        mon = (u32)func_0201AB28(party, work->memberIndex[i]);
        work->memberMonsNo[i] = func_02017E1C((void *)mon, 5, 0);
        work->memberItemNo[i] = func_02017E1C((void *)mon, 6, 0);
    }
}






/*
 * Like 0x021C9BCC with a reset of the play data and without the trainerNo block.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9CAC(BsubwayScrWork *work)
{
    u8 saveByte = work->playMode;

    func_0200D914(work->playData, 0, &saveByte);
    func_0200DA14(work->playData);
    func_0200D914(work->playData, 5, work->memberIndex);
    func_0200D868(work->playData, 1);
    if (work->playMode == 2 || work->playMode == 7) {
        saveByte = work->stateBits.partnerNo;
        func_0200D914(work->playData, 9, &saveByte);
        func_0200D914(work->playData, 6, &work->partnerDraws[work->stateBits.partnerNo]);
        func_0200D914(work->playData, 7, &work->partnerResult[work->stateBits.partnerNo]);
    }
}






/*
 * Reads the play mode from the play data, clears the play data and resets the score data entry of that mode.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C9D30(const struct GameSystem *gameSystem)
{
    u32 saveControl = (u32)func_02012EBC((struct GameData *)func_020120F4(gameSystem));
    u32 playData = (u32)func_020071CC((struct SaveControl *)saveControl, 0x39);
    u32 scoreData = (u32)func_020071CC((struct SaveControl *)saveControl, 0x3a);
    u8 playMode = func_0200D884((struct BsubwayPlayData *)playData, 0, 0);

    func_0200DA14((struct BsubwayPlayData *)playData);
    func_0200DB1C((struct BsubwayScoreData *)scoreData, playMode);
    return playMode;
}






/*
 * Commits winCount for the current playMode and redraws.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9D70(u32 unused, BsubwayScrWork *work)
{
    u16 winCount = work->winCount;
    u8 playMode = work->playMode;
    u32 scoreData = (u32)work->scoreData;

    func_0200DB08((struct BsubwayScoreData *)scoreData, playMode, winCount);
    func_0200DAEC((struct BsubwayScoreData *)scoreData, playMode, winCount);
    func_021CA2DC(work, (u32)func_02012EBC(work->gameData), 1, winCount);
    func_0200DB1C(work->scoreData, playMode);
    func_0200DA14(work->playData);
}






/*
 * Picks a step amount from a 7x10 byte table by playMode and a clamped
 * counter, adds it to the record in scoreData and returns it.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C9DB0(BsubwayScrWork *work)
{
    int points;
    int row;
    int idx;
    u16 count;

    if (work->playMode == 4) {
        points = 0;
        if ((u16)func_0200D884(work->playData, 0xB, 0) == 1) {
            idx = (s8)func_0200DC08(work->scoreData);
            if (idx < 0)
                idx = 0;
            else if (idx >= 10)
                idx = 9;
            points = d_021DACDC[6][idx];
        } else {
            points = 5;
        }
    } else {
        points = 0;
        count = func_0200DB80(work->scoreData, work->playMode);
        switch (work->playMode) {
        case 0:
            row = 0;
            break;
        case 5:
            row = 1;
            points = 1;
            break;
        case 1:
            row = 2;
            break;
        case 6:
            row = 3;
            points = 1;
            break;
        case 2:
            row = 4;
            break;
        case 3:
            row = 4;
            break;
        case 7:
            row = 5;
            points = 1;
            break;
        case 8:
            row = 5;
            points = 1;
            break;
        case 4:
            row = 6;
            break;
        default:
            row = 0;
            break;
        }
        count = count - 1;
        if ((s16)count < 0)
            idx = 0;
        else if (count >= 10)
            idx = 9;
        else
            idx = count;
        if (work->stateBits.fixedBpMode) {
            if (points == 1)
                points = 30;
            else
                points = 10;
        } else {
            points = d_021DACDC[row][idx];
        }
    }
    if (points == 0)
        points = 1;
    func_0200DA80(work->scoreData, points);
    return points;
}






/*
 * Fills the trainerNo list with distinct draws: 14 for playMode 2, 3, 7, 8, else 7.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9E8C(BsubwayScrWork *work)
{
    u8 playMode = work->playMode;
    u16 stage = func_021CA2CC(func_021CA234(work));
    int i;
    u16 trainerNo;

    if (playMode == 2 || playMode == 3 || playMode == 7 || playMode == 8) {
        if (stage < work->partnerStage)
            stage = work->partnerStage;
        for (i = 0; i < 14; i++) {
            do {
                trainerNo = func_021CBD90(work, stage, (u8)(i / 2), playMode, (u8)(i & 1));
            } while (func_021CA2A4(work->trainerNo, trainerNo, i));
            work->trainerNo[i] = trainerNo;
        }
    } else {
        for (i = 0; i < 7; i++) {
            do {
                trainerNo = func_021CBD90(work, stage, (u8)i, work->playMode, 0);
            } while (func_021CA2A4(work->trainerNo, trainerNo, i));
            work->trainerNo[i] = trainerNo;
        }
    }
}






/*
 * Unless blocked, clamps each slot's selectPos id to 1..6, copies it into memberIndex and reloads the slot's two stats.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C9F44(BsubwayScrWork *work, u32 unused)
{
    void *party;
    u16 i;
    u32 mon;

    if (work->selectCancel != 0 || work->selectMode == 7 || work->selectMode == 8)
        return 0;
    party = func_021CA210(work);
    for (i = 0; i < work->memberNum; i++) {
        if (work->selectPos[i] - 1 >= 6)
            work->selectPos[i] = 1;
        work->memberIndex[i] = work->selectPos[i] - 1;
        mon = (u32)func_0201AB28(party, work->memberIndex[i]);
        work->memberMonsNo[i] = func_02017E1C((void *)mon, 5, 0);
        work->memberItemNo[i] = func_02017E1C((void *)mon, 6, 0);
    }
    return 1;
}






/*
 * Latches stateBits.winMaxReached once the play data count reaches 7.
 *
 * Addresses are Black-image addresses.
 */
int func_021C9FD0(BsubwayScrWork *work)
{
    if (work->stateBits.winMaxReached == 0) {
        if (func_0200DA54(work->playData) < 7)
            return 0;
        work->stateBits.winMaxReached = 1;
    }
    return 1;
}






/*
 * Commits winCount and the current playMode's level and redraws.
 *
 * Addresses are Black-image addresses.
 */
void func_021C9FFC(BsubwayScrWork *work, u32 unused)
{
    u8 playMode = work->playMode;
    u16 winCount = func_021CA234(work);

    func_0200DB08(work->scoreData, playMode, winCount);
    func_0200DAEC(work->scoreData, playMode, func_0200DAC4(work->scoreData, playMode));
    func_0200DB60(work->scoreData, playMode);
    func_021CA2DC(work, (u32)func_02012EBC(work->gameData), 1, winCount);
    func_0200DA14(work->playData);
}






int func_021CA048(BsubwayScrWork *work, u32 unused)
{
    work->stateBits.winMaxReached = 0;
    work->stateBits.fixedBpMode = 0;
    return (int)work;
}






/*
 * Draws the current page of the trainerNo list through 0x021CBED8; playMode 2, 3, 7, 8 draw two pages with the slot tags.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA05C(BsubwayScrWork *work)
{
    u32 round = func_0200DA54(work->playData);
    int i;
    u32 j;
    u16 monsNo[2];
    u16 itemNo[2];

    switch (work->playMode) {
    case 4:
        func_0200DEA8((u32)work->wifiData, (u8 *)work->trainers, round, work->heapId);
        return;
    case 2:
    case 3:
    case 7:
    case 8:
        i = 0;
        j = round * 2;
        func_021CBED8(work, &work->trainers[0], work->trainerNo[j], work->memberNum, 0, 0, 0, work->heapId);
        for (; i < work->memberNum; i++) {
            monsNo[i] = work->trainers[0].mons[i].species;
            itemNo[i] = work->trainers[0].mons[i].item;
        }
        func_021CBED8(work, &work->trainers[1], work->trainerNo[j + 1], work->memberNum, (u16 *)monsNo, (u16 *)itemNo, 0, work->heapId);
        return;
    }
    func_021CBED8(work, &work->trainers[0], work->trainerNo[round], work->memberNum, 0, 0, 0, work->heapId);
}






/*
 * Tail-calls into ov010 with trainerType of trainers[i].
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CA150(BsubwayScrWork *work, int i)
{
    return func_02168AEC(work->trainers[i].trainerType);
}






/*
 * Steps an arm9 object by mode (0, 3, 4) and reports whether it advanced.
 *
 * Addresses are Black-image addresses.
 */
int func_021CA164(void *scoreData, int unused, int mode)
{
    u8 rank = (int)func_0200DC08(scoreData);
    u32 streak;

    switch (mode) {
    case 0:
        return rank;
    case 3:
        func_0200DBA0(scoreData, 0, 2);
        if (rank == 10)
            return 0;
        func_0200DBF0(scoreData);
        return 1;
    case 4:
        streak = func_0200DC0C(scoreData, 3);
        if (rank == 1)
            return 0;
        if (streak >= data_021DACD0[rank - 1]) {
            func_0200DBFC(scoreData);
            func_0200DC0C(scoreData, 2);
            func_0200DBA0(scoreData, 0, 2);
            return 1;
        }
        return 0;
    }
    return 0;
}






/*
 * Releases partyCopy and allocates a fresh one from gameData.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA1E4(BsubwayScrWork *work)
{
    if (work->partyCopy != 0)
        func_020307B0(work->partyCopy);
    work->partyCopy = func_0200BAF4((int)func_0200BAC8(func_02012EBC(work->gameData)), 4);
}






/*
 * Returns the party of gameData unless the query on playData is set, then the cached partyCopy.
 *
 * Addresses are Black-image addresses.
 */
void *func_021CA210(BsubwayScrWork *work)
{
    if (func_0200D884(work->playData, 10, 0) == 0)
        return func_02012934(work->gameData);
    return work->partyCopy;
}






/*
 * Returns winCount.
 */
u16 func_021CA234(BsubwayScrWork *work)
{
    return work->winCount;
}






/*
 * Sets winCount.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA238(BsubwayScrWork *work, u16 winCount)
{
    work->winCount = winCount;
}






/*
 * Saturating increment of winCount.
 * Addresses are Black-image addresses.
 */
void func_021CA23C(BsubwayScrWork *work)
{
    u16 winCount = work->winCount;

    if (winCount < 0xffff)
        work->winCount = winCount + 1;
}






int func_021CA250(BsubwayScrWork *work)
{
    work->winCount = 0;
    return (int)work;
}





void func_021CA258(BsubwayScrWork *work, u32 stage, u32 round)
{
    u32 winCount = stage * 7;

    winCount += round;
    if (winCount > 0xffff)
        winCount = 0xffff;
    work->winCount = winCount;
}






int func_021CA270(u16 playMode)
{
    switch (playMode) {
    case 0:
    case 4:
    case 5:
        return 3;
    case 1:
    case 6:
        return 4;
    case 2:
    case 3:
    case 7:
    case 8:
        return 2;
    }
    return 0;
}






/*
 * Linear search of a halfword array.
 * Addresses are Black-image addresses.
 */
int func_021CA2A4(const u16 *list, u16 value, u16 count)
{
    u16 i;

    for (i = 0; i < count; i++) {
        if (value == list[i])
            return 1;
    }
    return 0;
}






u16 func_021CA2CC(u16 winCount)
{
    return (u16)func_0209C0A4(winCount, 7);
}






void func_021CA2DC(BsubwayScrWork *work, u32 saveControl, int unused, u16 winCount)
{
    u8 saveByte;

    switch (work->playMode) {
    case 0:
        func_021CA4C0(work, saveControl, 0);
        break;
    case 1:
        break;
    case 4:
        func_021CA4C0(work, saveControl, 1);
        saveByte = work->playMode;
        func_0200D914(work->playData, 0, &saveByte);
        saveByte = func_0200DA54(work->playData) + 1;
        func_0200D914(work->playData, 1, &saveByte);
        func_0200DC94(work->scoreData, (const struct BsubwayRecordSrc *)(work->playData));
        break;
    }
}






/*
 * Draws the three partnerDraws entries through 0x021CBED8 and stores each result byte in partnerResult.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA338(BsubwayScrWork *work, u8 isAltRom)
{
    int trainerBase = 300;
    int i;

    if (isAltRom)
        trainerBase += 3;
    for (i = 0; i < 3; i++)
        work->partnerResult[i] = func_021CBED8(work, &work->partners[i], trainerBase + i, work->memberNum,
                                               work->memberMonsNo, work->memberItemNo,
                                               &work->partnerDraws[i], work->heapId);
}






/*
 * Packs one party member into a 0x3c-byte slot: species/form, item, four moves with their PP-up bits, ids, stats and nickname.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA3B4(BattleMon *mon, u32 pokeParam)
{
    int i;

    mon->species = func_02017E1C((void *)pokeParam, 5, 0);
    mon->form = func_02017E1C((void *)pokeParam, 0x6f, 0);
    mon->item = func_02017E1C((void *)pokeParam, 6, 0);
    for (i = 0; i < 4; i++) {
        mon->moves[i] = func_02017E1C((void *)pokeParam, 0x36 + i, 0);
        mon->ppUps |= func_02017E1C((void *)pokeParam, 0x3e + i, 0) << (i * 2);
    }
    mon->lang = func_02017E1C((void *)pokeParam, 0xc, 0);
    mon->otId = func_02017E1C((void *)pokeParam, 7, 0);
    mon->pid = func_02017E1C((void *)pokeParam, 0, 0);
    mon->ivs = func_02017E1C((void *)pokeParam, 0xac, 0);
    for (i = 0; i < 6; i++)
        mon->ev[i] = func_02017E1C((void *)pokeParam, 0xd + i, 0);
    mon->ability = func_02017E1C((void *)pokeParam, 0xa, 0);
    mon->friendship = func_02017E1C((void *)pokeParam, 9, 0);
    func_02017E1C((void *)pokeParam, 0x74, (u32)mon->nick);
}





/*
 * Packs the three selected party members into a scratch buffer from bsubway_scr.c and hands it to the score data.
 *
 * Addresses are Black-image addresses.
 */
void func_021CA4C0(BsubwayScrWork *work, u32 unused, int slot)
{
    BattleMon *buf;
    int i;
    void *party;

    i = 0;
    buf = func_02030734((u16)(((u16)work->heapId & 0x7fff) | 0x8000), 0xb4, 0, d_021DE58C, 0x89a);
    func_02082BCC(buf, 0, 0xb4);
    party = func_021CA210(work);
    for (; i < 3; i++)
        func_021CA3B4(&buf[i], (u32)func_0201AB28(party, work->memberIndex[i]));
    func_0200DC50(work->scoreData, slot, buf);
    func_02082BCC(buf, 0, 0xb4);
    func_020307B0(buf);
}




int func_021CA544(u32 script, u32 scriptCtx)
{
    void *scriptWork = func_0215A5F4((void *)scriptCtx);
    u32 gameSystem, resume;

    func_02158F58((int)scriptWork);
    gameSystem = (u32)func_02158F54(scriptWork);
    resume = func_02011330((struct ScriptStream *)script);
    func_021C9934((GameSystem *)gameSystem, resume, func_02159B10((void *)script, (void *)scriptCtx));
    return 0;
}




int func_021CA57C(u32 script, u32 scriptCtx)
{
    void *scriptWork = func_0215A5F4((void *)scriptCtx);

    func_02158F58((int)scriptWork);
    func_021C9924(func_02158F54(scriptWork));
    return 0;
}




int func_021CA598(u32 script, u32 scriptCtx)
{
    void *scriptWork = func_0215A5F4((void *)scriptCtx);
    u32 gameSystem;

    func_02158F58((int)scriptWork);
    gameSystem = (u32)func_02158F54(scriptWork);
    func_021C9B24((GameSystem *)gameSystem, func_02012ED8(func_020120F4((const struct GameSystem *)gameSystem)));
    return 0;
}





/*
 * Script command dispatcher: reads a command id and two arguments from the
 * script, then runs one of 137 cases on the work area, the save blocks
 * 0x39/0x3A/0x3B and the result slot. Returns 1 when the case started a task
 * the script must wait for.  One 4376-byte function (0x021CA5C4..0x021CB6DC,
 * see layout/far_branch_functions.txt); every concrete byte matches.
 *
 * Shape notes (2026-10-01), all measured:
 * - The switch tree only reproduces with one more empty case label inside the
 *   0..113 jump table (any of 9, 10, 46..99, 102; its entry is the break, so
 *   the value is invisible).  BSUBWAY_SCR_CMD_NOP_A is that label (102).  Without it the top group becomes one 359..416
 *   table instead of compares for 358/359 and a 400..416 table.
 * - cmd, arg1, arg2 and resultWorkId are u16 (u16 returns): u32 makes the tree
 *   unsigned, and u32 arg1 truncates before each bitfield insert.
 * - The counter of BSUBWAY_SCR_CMD_SET_PROGRESS_RECORDS is an enum local: an int counter folds `recordNo + playRound + 1` and
 *   the loop's entry guard.
 * - BSUBWAY_SCR_CMD_GET_TRAINER_NO writes the result in each arm (cross-jumped tail leaves the
 *   `b` to the next instruction); BSUBWAY_SCR_CMD_START_COMM_CHECK_B sets startedTask after the call (it is
 *   still scheduled into the argument stores); the two SET_RETURN_LOCATION table cases read the table
 *   row through a pointer and pass its three words as separate arguments.
 *
 * Witnesses (closed 2026-10-02, gA2): func_021542C0 (ov007), func_02167AB0
 *   and func_02167CF4 (ov010) were seeded in layout/function_starts.txt and
 *   filed EXACT; data_021BB474 (ov214) and data_021BB6A4 (ov100) are
 *   hand-declared proc tables in layout/data_objects.txt, and
 *   attest_xwin_loaded() no longer counts ov021's own start at 0x021BB474
 *   as a third-overlay contest.
 */
int func_021CA5C4(void *scriptCtx, u32 script)
{
    VecFx32 playerPos;
    ReturnLocation playerLocation;
    VecFx32 npcPos;
    ReturnLocation tableLocation;
    ReturnLocation modeLocation;
    Ov007ProcParam procParam;
    u32 recordSlot;
    u16 firstA, firstB, firstC;
    u16 secondA, secondB, secondC;
    u16 thirdA, thirdB, thirdC;
    u8 byte11;
    u8 byte10;
    int startedTask;
    void *scriptWork;
    u32 gameSystem;
    u32 gameData;
    u32 saveControl;
    u32 eventFlags;
    BsubwayScrWork *work;
    u32 playData;
    u32 playMode;
    u32 scoreData;
    u32 wifiData;
    void *fieldMap;
    u16 arg1;
    u16 arg2;
    u16 resultWorkId;
    u16 *resultDst;
    u16 cmd;

    startedTask = 0;
    scriptWork = func_0215A5F4((void *)script);
    func_02158F58((int)scriptWork);
    gameSystem = (u32)func_02158F54(scriptWork);
    gameData = (u32)func_020120F4((const struct GameSystem *)gameSystem);
    saveControl = (u32)func_02012EBC((struct GameData *)gameData);
    eventFlags = func_0201296C((const struct GameData *)gameData);
    work = func_02012ED8((struct GameData *)gameData);
    playData = (u32)func_020071CC((struct SaveControl *)saveControl, 0x39);
    playMode = func_0200D884((struct BsubwayPlayData *)playData, 0, 0);
    scoreData = (u32)func_020071CC((struct SaveControl *)saveControl, 0x3a);
    wifiData = (u32)func_020071CC((struct SaveControl *)saveControl, 0x3b);
    fieldMap = func_0201210C((void *)gameSystem);
    cmd = func_02011330(scriptCtx);
    arg1 = func_02159B10(scriptCtx, (void *)script);
    arg2 = func_02159B10(scriptCtx, (void *)script);
    resultWorkId = func_02011330(scriptCtx);
    resultDst = func_02158FE0(scriptWork, (void *)gameData, resultWorkId);

    if (work == NULL && cmd >= 300)
        return startedTask;

    switch (cmd) {
    case BSUBWAY_SCR_CMD_GET_TRAIN_INDEX:
        *resultDst = func_021CBCC4(fieldMap);
        break;
    case BSUBWAY_SCR_CMD_RESET_SYSTEM:
        func_02087BCC(0);
        break;
    case BSUBWAY_SCR_CMD_CLEAR_PLAY_DATA:
        func_0200D85C((struct BsubwayPlayData *)playData);
        break;
    case BSUBWAY_SCR_CMD_GET_PLAY_DATA_STATE:
        *resultDst = func_0200D87C((struct BsubwayPlayData *)playData);
        break;
    case BSUBWAY_SCR_CMD_SET_RETURN_LOCATION_AT_PLAYER: {
        void *playerObj = func_02188CB4((void *)fieldMap);
        u32 dirIndex = func_021A3050(playerObj);
        int dirCode;
        func_021A3038(playerObj, (struct VecFx32 *)&playerPos);
        switch (dirIndex) {
        case 0:
            dirCode = 1;
            break;
        case 1:
            dirCode = 2;
            break;
        case 2:
            dirCode = 3;
            break;
        case 3:
            dirCode = 4;
            break;
        default:
            dirCode = 0;
            break;
        }
        func_02014184(&playerLocation, func_02188C9C(fieldMap), dirCode, playerPos.x, playerPos.y, playerPos.z);
        func_0201289C((struct GameData *)gameData, (const struct ReturnLocation *)(&playerLocation));
        func_02014314((char *)eventFlags, 0x966);
        break;
    }
    case BSUBWAY_SCR_CMD_CLEAR_RETURN_LOCATION_FLAG:
        func_0201433C((char *)eventFlags, 0x966);
        break;
    case BSUBWAY_SCR_CMD_GET_RECORD_WIN_COUNT:
        *resultDst = func_0200DAC4((struct BsubwayScoreData *)scoreData, arg1);
        if (*resultDst > 9999)
            *resultDst = 9999;
        break;
    case BSUBWAY_SCR_CMD_BEGIN_PLAY_GET_MODE:
        *resultDst = func_021C9D30((const struct GameSystem *)gameSystem);
        break;
    case BSUBWAY_SCR_CMD_GET_PLAYER_LOOK:
        *resultDst = func_021A3190(func_021A30B0(func_02188CB4((void *)fieldMap)), 0);
        break;
    case BSUBWAY_SCR_CMD_SET_NPC_DIRECTION: {
        void *npcObj = func_0216DE94(func_02188C7C((void *)fieldMap), arg1);
        if (npcObj != 0)
            func_0216DAC8(npcObj, arg2);
        break;
    }
    case BSUBWAY_SCR_CMD_GET_NEXT_ROUND_FROM_SAVE:
        *resultDst = func_0200DA54((struct BsubwayPlayData *)playData) + 1;
        break;
    case BSUBWAY_SCR_CMD_GET_NEXT_ROUND:
        *resultDst = func_0200DA54((struct BsubwayPlayData *)(work->playData));
        *resultDst += 1;
        break;
    case BSUBWAY_SCR_CMD_GET_SCORE_FLAG:
        if (data_021DAD36[arg1] == 11)
            *resultDst = 1;
        else
            *resultDst = func_0200DBA0((struct BsubwayScoreData *)scoreData, data_021DAD36[arg1], 0);
        break;
    case BSUBWAY_SCR_CMD_SET_SCORE_FLAG:
        if (data_021DAD36[arg1] != 11)
            func_0200DBA0((struct BsubwayScoreData *)scoreData, data_021DAD36[arg1], 1);
        break;
    case BSUBWAY_SCR_CMD_GET_SCORE_FLAG_CLEAR:
        *resultDst = func_0200DBA0((struct BsubwayScoreData *)scoreData, 10, 0);
        break;
    case BSUBWAY_SCR_CMD_SET_SCORE_FLAG_CLEAR:
        func_0200DBA0((struct BsubwayScoreData *)scoreData, 10, 1);
        break;
    case BSUBWAY_SCR_CMD_SET_TRAIN_SIGN_TABLE:
        func_021F37C0(fieldMap, data_021DAD88[arg1], (int)(&data_021DAD70[arg2]));
        break;
    case BSUBWAY_SCR_CMD_SET_TRAIN_DOOR_STATE:
        func_021D024C((void *)func_021F380C((int)fieldMap), arg1);
        break;
    case BSUBWAY_SCR_CMD_SET_TRAIN_DOOR_STATE_OTHER:
        func_021D028C((void *)func_021F380C((int)fieldMap), arg1);
        break;
    case BSUBWAY_SCR_CMD_GET_SAVED_PLAY_MODE:
        *resultDst = func_0200D884((struct BsubwayPlayData *)playData, 0, 0);
        break;
    case BSUBWAY_SCR_CMD_IS_MULTI_PLAY_MODE:
        *resultDst = 0;
        switch (arg1) {
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
            break;
        case 2:
        case 3:
        case 7:
        case 8:
            *resultDst = 1;
            break;
        }
        break;
    case BSUBWAY_SCR_CMD_SET_NPC_HEIGHT_AND_LOCK: {
        u32 height = arg2 << 16;
        void *npcObj = func_0216DE94(func_02188C7C((void *)fieldMap), arg1);
        if (npcObj != 0) {
            func_0216D88C(npcObj, &npcPos);
            npcPos.y = height;
            func_0216E014(npcObj, (int *)(&npcPos), func_0216D5F8(npcObj));
            func_0216DB4C(npcObj, 1);
        }
        break;
    }
    case BSUBWAY_SCR_CMD_UNLOCK_NPC: {
        void *npcObj = func_0216DE94(func_02188C7C((void *)fieldMap), arg1);
        if (npcObj != 0)
            func_0216DB4C(npcObj, 0);
        break;
    }
    case BSUBWAY_SCR_CMD_IS_NPC_PRESENT: {
        void *npcObj = func_0216DE94(func_02188C7C((void *)fieldMap), arg1);
        *resultDst = 0;
        if (npcObj != 0)
            *resultDst = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_GET_NPC_TRAIN_STATE: {
        void *npcObj = func_0216DE94(func_02188C7C((void *)fieldMap), arg1);
        *resultDst = 0;
        if (npcObj != 0)
            *resultDst = func_021CBBA0((u32)npcObj);
        break;
    }
    case BSUBWAY_SCR_CMD_GET_RANK:
        *resultDst = func_021CA164((void *)scoreData, gameSystem, 0);
        if ((s16)*resultDst <= 0)
            *resultDst = 1;
        break;
    case BSUBWAY_SCR_CMD_LOWER_RANK:
        *resultDst = func_021CA164((void *)scoreData, gameSystem, 3);
        break;
    case BSUBWAY_SCR_CMD_RAISE_RANK:
        *resultDst = func_021CA164((void *)scoreData, gameSystem, 4);
        break;
    case BSUBWAY_SCR_CMD_GET_SCORE_ROUND_VALUE:
        *resultDst = func_0200DB80((struct BsubwayScoreData *)scoreData, arg1);
        break;
    case BSUBWAY_SCR_CMD_GET_PARTNER_LOOK:
        *resultDst = func_021A31A4(func_02008550((const struct MyStatus *)((u8 *)func_020127A4((struct GameData *)gameData) + 0x20)) == 0 ? 1 : 0, 0);
        break;
    case BSUBWAY_SCR_CMD_IS_BATTLE_REC_SAVED: {
        u32 recordSys = (u32)func_0200BAC8((void *)saveControl);
        *resultDst = 0;
        if (func_0200BBA8((void *)recordSys) == 1)
            *resultDst = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_RESULT_FALSE_A:
        *resultDst = 0;
        break;
    case BSUBWAY_SCR_CMD_SET_TRAIN_SIGN_DEFAULT:
        func_021F37C0(fieldMap, 7, (int)data_021DAD70);
        break;
    case BSUBWAY_SCR_CMD_SET_NPC_ANIMATION: {
        void *npcObj = func_0216DE94(func_02188C7C((void *)fieldMap), arg1);
        if (npcObj != 0)
            func_0216D5E0((int)npcObj, arg2);
        break;
    }
    case BSUBWAY_SCR_CMD_RESET_NPC_ANIMATION: {
        void *npcObj = func_0216DE94(func_02188C7C((void *)fieldMap), arg1);
        if (npcObj != 0)
            func_0216DAF8(npcObj);
        break;
    }
    case BSUBWAY_SCR_CMD_START_NPC_TASK:
        func_0215897C(scriptWork, func_0216CB48(gameSystem, func_0216D63C(func_0216DE94(func_02188C7C((void *)fieldMap), arg1), 0), arg1));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_MODE_CLEARED:
        *resultDst = func_0200DB44((struct BsubwayScoreData *)scoreData, arg1);
        break;
    case BSUBWAY_SCR_CMD_IS_NPC_AVAILABLE: {
        u32 npcIndex = func_0216D63C(func_0216DE94(func_02188C7C((void *)fieldMap), arg1), 0);
        *resultDst = 0;
        if (func_021CBBAC(work, npcIndex) == 1)
            *resultDst = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_GET_NPC_INFO_FIRST:
        func_021CBBD0(work, func_0216D63C(func_0216DE94(func_02188C7C((void *)fieldMap), arg1), 0), &firstA, &firstB, &firstC);
        *resultDst = firstA;
        break;
    case BSUBWAY_SCR_CMD_GET_NPC_INFO_SECOND:
        func_021CBBD0(work, func_0216D63C(func_0216DE94(func_02188C7C((void *)fieldMap), arg1), 0), &secondA, &secondB, &secondC);
        *resultDst = secondB;
        break;
    case BSUBWAY_SCR_CMD_GET_NPC_INFO_THIRD:
        func_021CBBD0(work, func_0216D63C(func_0216DE94(func_02188C7C((void *)fieldMap), arg1), 0), &thirdA, &thirdB, &thirdC);
        *resultDst = thirdC;
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_RECORD_COUNT: {
        void *recordList = func_0200DF58((struct BsubwayWifiData *)wifiData, 4);
        *resultDst = func_0200DF94(recordList);
        func_020307B0(recordList);
        break;
    }
    case BSUBWAY_SCR_CMD_START_SCREEN_TASK: {
        u32 cancelFlag = 0;
        if (arg1 == 1)
            cancelFlag = 1;
        func_0215897C(scriptWork, func_021CB9BC((void *)gameSystem, script, (u32)resultDst, cancelFlag));
        startedTask = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_SET_RETURN_LOCATION_FROM_TABLE: {
        u16 tableIndex = func_021CBCC4(fieldMap);
        const VecFx32 *pos = &data_021DAE50[tableIndex];
        func_02014184(&tableLocation, data_021DADAC[tableIndex], 4, pos->x, pos->y, pos->z);
        func_0201289C((struct GameData *)gameData, (const struct ReturnLocation *)(&tableLocation));
        func_02014314((char *)eventFlags, 0x966);
        break;
    }
    case BSUBWAY_SCR_CMD_SET_SCORE_FLAG_FIRST:
        if (arg1 == 0)
            func_0200DBA0((struct BsubwayScoreData *)scoreData, 1, 2);
        else
            func_0200DBA0((struct BsubwayScoreData *)scoreData, 1, 1);
        break;
    case BSUBWAY_SCR_CMD_GET_SCORE_FLAG_FIRST:
        *resultDst = func_0200DBA0((struct BsubwayScoreData *)scoreData, 1, 0);
        break;
    case BSUBWAY_SCR_CMD_START_OV007_PROC_A:
        procParam.mode = 0;
        procParam.result = resultDst;
        func_0215897C(scriptWork, func_020124AC((void *)gameSystem, (u32)ov007_id, (u32 (*)(void *, u32))func_021542C0, (u32)(&procParam)));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_OV007_PROC_B:
        startedTask = 1;
        procParam.mode = 1;
        procParam.result = resultDst;
        func_0215897C(scriptWork, func_020124AC((void *)gameSystem, (u32)ov007_id, (u32 (*)(void *, u32))func_021542C0, (u32)(&procParam)));
        break;
    case BSUBWAY_SCR_CMD_START_OV007_PROC_C:
        procParam.mode = 2;
        procParam.result = resultDst;
        func_0215897C(scriptWork, func_020124AC((void *)gameSystem, (u32)ov007_id, (u32 (*)(void *, u32))func_021542C0, (u32)(&procParam)));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_101:
        *resultDst = func_0200DE94((struct BsubwayWifiData *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_FE:
        *resultDst = func_0200DE5C((struct BsubwayWifiData *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_SET_PLAY_DATA_BYTE_11:
        byte11 = arg1;
        func_0200D914((struct BsubwayPlayData *)playData, 11, &byte11);
        break;
    case BSUBWAY_SCR_CMD_GET_PLAY_DATA_BYTE_11:
        *resultDst = func_0200D884((struct BsubwayPlayData *)playData, 11, 0);
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_FF:
        *resultDst = func_0200DE64((struct BsubwayWifiData *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_START_PARTY_TASK:
        func_0215897C(scriptWork, func_0216C860((void *)gameSystem));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_103:
        *resultDst = func_0200DF40((struct BsubwayWifiData *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_FIELD_102:
        *resultDst = func_0200DF4C((struct BsubwayWifiData *)wifiData);
        break;
    case BSUBWAY_SCR_CMD_RESULT_FALSE_B:
        *resultDst = 0;
        break;
    case BSUBWAY_SCR_CMD_NOP_A:
    case BSUBWAY_SCR_CMD_NOP_B:
    case BSUBWAY_SCR_CMD_NOP_C:
        break;
    case BSUBWAY_SCR_CMD_RESULT_FALSE_C:
        *resultDst = 0;
        break;
    case BSUBWAY_SCR_CMD_SET_RETURN_LOCATION_FROM_MODE:
        if (playMode < 9) {
            const VecFx32 *pos = &data_021DAE50[playMode];
            func_02014184(&modeLocation, data_021DADAC[playMode], 4, pos->x, pos->y, pos->z);
            func_0201289C((struct GameData *)gameData, (const struct ReturnLocation *)(&modeLocation));
            func_02014314((char *)eventFlags, 0x966);
        }
        break;
    case BSUBWAY_SCR_CMD_START_PARTY_SELECT:
        {
            u8 useOwnParty = func_0200D884((struct BsubwayPlayData *)playData, 10, 0);
            func_0215897C(scriptWork, func_0216C538((struct PartySelectParam *)work, (void *)gameSystem, useOwnParty));
        }
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_SET_SELECTED_MEMBERS:
        *resultDst = func_021C9F44(work, gameSystem);
        break;
    case BSUBWAY_SCR_CMD_RESULT_FALSE_D:
        *resultDst = 0;
        break;
    case BSUBWAY_SCR_CMD_IS_WIN_MAX:
        if (func_021C9FD0(work) == 1)
            *resultDst = 1;
        else
            *resultDst = 0;
        break;
    case BSUBWAY_SCR_CMD_SET_LOSE_SCORE:
        func_021C9D70(gameSystem, work);
        break;
    case BSUBWAY_SCR_CMD_SET_CLEAR_SCORE:
        func_021C9FFC(work, gameSystem);
        break;
    case BSUBWAY_SCR_CMD_SAVE_REST_PLAY_DATA:
        func_021C9BCC(work);
        break;
    case BSUBWAY_SCR_CMD_CREATE_ROUND_TRAINERS:
        func_021CA05C(work);
        break;
    case BSUBWAY_SCR_CMD_GET_TRAINER_OBJ_CODE:
        *resultDst = func_021CA150(work, arg1);
        break;
    case BSUBWAY_SCR_CMD_START_ENCOUNTER_TASK:
        func_0215897C(scriptWork, func_0216C640(work, gameSystem, fieldMap));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_PLAY_MODE:
        *resultDst = work->playMode;
        break;
    case BSUBWAY_SCR_CMD_SET_FIXED_BP_MODE:
        work->stateBits.fixedBpMode = arg1;
        break;
    case BSUBWAY_SCR_CMD_GET_FIXED_BP_MODE:
        *resultDst = work->stateBits.fixedBpMode;
        break;
    case BSUBWAY_SCR_CMD_GET_BATTLE_POINTS:
        *resultDst = func_021C9DB0(work);
        break;
    case BSUBWAY_SCR_CMD_SET_PARTNER_NO:
        work->stateBits.partnerNo = arg1;
        break;
    case BSUBWAY_SCR_CMD_GET_PARTNER_NO:
        *resultDst = work->stateBits.partnerNo;
        break;
    case BSUBWAY_SCR_CMD_DRAW_TRAINER_NOS:
        func_021C9E8C(work);
        break;
    case BSUBWAY_SCR_CMD_GET_MEMBER_INDEX:
        *resultDst = work->memberIndex[arg1];
        break;
    case BSUBWAY_SCR_CMD_CLEAR_RECV_BUF:
        work->recvCount = 0;
        func_02082BCC(work->recvBuf, 0, 0x46);
        break;
    case BSUBWAY_SCR_CMD_START_PARTNER_TASK_A:
        func_0215897C(scriptWork, func_0216C6E8(work, (void *)gameSystem, arg1, arg2, 5));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_SAVE_PLAY_DATA_MEMBERS:
        func_021C9CAC(work);
        break;
    case BSUBWAY_SCR_CMD_LOAD_MEMBERS:
        func_021C9C54(work, gameSystem);
        break;
    case BSUBWAY_SCR_CMD_SET_PLAY_DATA_BYTE_10:
        byte10 = arg1;
        func_0200D914((struct BsubwayPlayData *)playData, 10, &byte10);
        break;
    case BSUBWAY_SCR_CMD_CHANGE_COMM_MULTI_MODE:
        func_021C9B78(work);
        break;
    case BSUBWAY_SCR_CMD_IS_UPPER_PLAY_MODE:
        if (playMode - 5 <= 3)
            *resultDst = 1;
        else
            *resultDst = 0;
        break;
    case BSUBWAY_SCR_CMD_SPAWN_FIELD_OBJECTS:
        func_021CB9E4(work, (void *)gameData, func_02188C7C((void *)fieldMap), fieldMap);
        break;
    case BSUBWAY_SCR_CMD_SET_STATE_FLAG8:
        work->stateBits.flag8 = arg1;
        break;
    case BSUBWAY_SCR_CMD_GET_STATE_FLAG8:
        *resultDst = work->stateBits.flag8;
        break;
    case BSUBWAY_SCR_CMD_IS_BATTLE_WON: {
        BtlSetup *setup = work->btlSetup;
        if (setup == NULL)
            *resultDst = 0;
        else if (setup->outcome == 1)
            *resultDst = 1;
        else
            *resultDst = 0;
        break;
    }
    case BSUBWAY_SCR_CMD_CLEAR_STATE_BITS:
        func_021CA048(work, gameSystem);
        break;
    case BSUBWAY_SCR_CMD_SET_PROGRESS_RECORDS: {
        BsubwayRecordNo recordNo = 0;
        u16 playRound = func_0200DA54((struct BsubwayPlayData *)playData);
        if (playRound != 0) {
            void *trainerCard = (void *)func_0202B578((u32 *)func_02012134((u32 *)gameSystem));
            playRound = recordNo + playRound + 1;
            for (; recordNo < playRound; recordNo++) {
                if (recordNo < 9 && recordNo != 0)
                    func_0202C0D0(trainerCard, recordNo);
            }
        }
        break;
    }
    case BSUBWAY_SCR_CMD_CREATE_PARTNERS:
        func_021CA338(work, func_02008550((const struct MyStatus *)((u8 *)func_020127A4((struct GameData *)gameData) + 0x20)) == 0 ? 1 : 0);
        break;
    case BSUBWAY_SCR_CMD_GET_MEMBER_MONS_NO:
        *resultDst = work->memberMonsNo[arg1];
        break;
    case BSUBWAY_SCR_CMD_SET_COMM_MODE:
        work->stateBits.commMode = arg1;
        break;
    case BSUBWAY_SCR_CMD_GET_COMM_MODE:
        *resultDst = work->stateBits.commMode;
        break;
    case BSUBWAY_SCR_CMD_CHECK_PARTY_REGULATION: {
        void *recordParty = NULL;
        u32 partySource;
        void *regulation;
        void *checkedParty;
        u32 checkResult;
        *resultDst = 0;
        partySource = func_0200D884((struct BsubwayPlayData *)playData, 10, 0);
        regulation = func_0201A354(func_021CBC94(playMode), 4);
        if (partySource == 1) {
            recordParty = func_0200BAF4((u32)func_0200BAC8((void *)saveControl), 4);
            checkedParty = recordParty;
        } else {
            checkedParty = func_02012934((void *)gameData);
        }
        checkResult = func_02019ED4(regulation, checkedParty);
        func_020307B0(regulation);
        if (recordParty != NULL)
            func_020307B0(recordParty);
        if (checkResult <= 1)
            *resultDst = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_LOAD_PARTY_COPY:
        func_021CA1E4(work);
        break;
    case BSUBWAY_SCR_CMD_GET_REGULATION_NO:
        *resultDst = func_021CBC94(playMode);
        break;
    case BSUBWAY_SCR_CMD_GET_MEMBER_NUM:
        *resultDst = func_021CA270(playMode);
        break;
    case BSUBWAY_SCR_CMD_CHECK_BATTLE_REC_SLOT:
        if (work->stateBits.btlRecState == 0) {
            work->stateBits.btlRecState = 1;
            if (func_0200B5CC((void *)saveControl, 4, &recordSlot, 0) == 1)
                work->stateBits.btlRecState = 2;
        }
        break;
    case BSUBWAY_SCR_CMD_GET_BATTLE_REC_EXISTS:
        if (work->stateBits.btlRecState == 1)
            *resultDst = 0;
        else
            *resultDst = 1;
        break;
    case BSUBWAY_SCR_CMD_SAVE_BATTLE_REC_FROM_SETUP:
        func_0200BA58();
        func_021EEE78((void *)work->btlSetup);
        func_0200BA68();
        break;
    case BSUBWAY_SCR_CMD_START_RESULT_MESSAGE:
        work->msgState = 0;
        work->msgSubState = 0;
        work->msgNumber = arg1;
        func_020113D0(scriptCtx, (int)func_021CBC14);
        work->stateBits.btlRecState = 2;
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_FREE_BATTLE_SETUP:
        if (work->btlSetup != 0) {
            func_0200B424();
            func_020130B4((int)work->btlSetup);
            work->btlSetup = 0;
        }
        break;
    case BSUBWAY_SCR_CMD_START_BATTLE_REC_PROC:
        func_02082BCC(&work->btlRecProcParam, 0, 0x18);
        work->btlRecProcParam.gameData = (GameData *)gameData;
        work->btlRecProcParam.mode = 1;
        work->btlRecProcParam.recordNo = 0;
        work->btlRecProcParam.subwayFlag = 1;
        work->btlRecProcParam.category = data_021DAD24[playMode];
        work->btlRecProcParam.winCount = func_021CA234(work);
        if (work->btlRecProcParam.winCount > 9999)
            work->btlRecProcParam.winCount = 9999;
        func_0215897C(scriptWork, func_02014808((char *)gameSystem, (int)fieldMap, (u32)ov214_id, (int)data_021BB474, (int)&work->btlRecProcParam, 0, 0));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_COMMIT_MODE_CLEAR:
        func_0200DA14((struct BsubwayPlayData *)playData);
        func_0200DB1C((struct BsubwayScoreData *)scoreData, playMode);
        break;
    case BSUBWAY_SCR_CMD_RELEASE_TRAIN_SIGN:
        func_021F388C((int)fieldMap);
        break;
    case BSUBWAY_SCR_CMD_GET_TRAINER_NO: {
        u32 playRound = func_0200DA54((struct BsubwayPlayData *)playData);
        switch (playMode) {
        case 2:
        case 3:
        case 7:
        case 8:
            *resultDst = work->trainerNo[playRound * 2 + arg1];
            break;
        case 0:
        case 1:
        case 4:
        case 5:
        case 6:
        default:
            *resultDst = work->trainerNo[playRound];
            break;
        }
        break;
    }
    case BSUBWAY_SCR_CMD_START_PARTNER_TASK_B:
        func_0215897C(scriptWork, func_0216C6E8(work, (void *)gameSystem, arg1, arg2, 6));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_ADD_BATTLE_TALLY: {
        BtlSetup *setup = work->btlSetup;
        if (setup != NULL) {
            u32 tallyFirst = setup->tally[0];
            u32 tallyLast = setup->tally[9];
            int monCount;
            void *btlParty = setup->parties[0];
            int monIndex;
            int sumBefore;
            int sumAfter;
            monCount = func_0201AA18(btlParty);
            sumBefore = 0;
            sumAfter = 0;
            for (monIndex = 0; monIndex < monCount; monIndex++) {
                void *partyMon = func_0201AB28(btlParty, monIndex);
                int valueBefore = func_02017E1C(partyMon, 0xa0, 0);
                int valueAfter = func_02017E1C(partyMon, 0xa1, 0);
                sumBefore += valueBefore;
                sumAfter += valueAfter;
            }
            func_0200D9E8((struct BsubwayPlayData *)playData, tallyLast, tallyFirst, (u16)(sumAfter - sumBefore));
        }
        break;
    }
    case BSUBWAY_SCR_CMD_SET_STATE_FLAG12:
        work->stateBits.flag12 = arg1;
        break;
    case BSUBWAY_SCR_CMD_GET_STATE_FLAG12:
        *resultDst = work->stateBits.flag12;
        break;
    case BSUBWAY_SCR_CMD_GET_PLAY_DATA_BYTE_10:
        *resultDst = func_0200D884((struct BsubwayPlayData *)playData, 10, 0);
        break;
    case BSUBWAY_SCR_CMD_NEXT_ROUND_GET_WIN_COUNT:
        func_0200DA28((struct BsubwayPlayData *)playData);
        func_021CA23C(work);
        *resultDst = func_021CA234(work);
        if (*resultDst > 9999)
            *resultDst = 9999;
        break;
    case BSUBWAY_SCR_CMD_GET_WIN_COUNT:
        *resultDst = func_021CA234(work);
        if (*resultDst > 9999)
            *resultDst = 9999;
        break;
    case BSUBWAY_SCR_CMD_COMMIT_FIRST_CLEAR:
        if (func_0200DB44((struct BsubwayScoreData *)scoreData, playMode) == 0) {
            func_0200DB30((struct BsubwayScoreData *)scoreData, playMode);
            func_0200DA14((struct BsubwayPlayData *)playData);
            func_021CA250(work);
        }
        break;
    case BSUBWAY_SCR_CMD_START_COMM_SESSION:
        if (work->stateBits.commMode == 1)
            func_02167B00((u32)work);
        else
            func_02167AB0(work);
        break;
    case BSUBWAY_SCR_CMD_START_COMM_CLOSE_TASK:
        func_0215897C(scriptWork, func_021CB914((void *)gameSystem, (u32)work));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_TIMING_SYNC:
        work->timingNo = arg1;
        work->resultWorkId = resultWorkId;
        func_02167B24(work->timingNo);
        func_020113D0(scriptCtx, (int)func_021CB700);
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_COMM_CHECK_A:
        work->commResultDst = resultDst;
        work->commTask = (void *)func_021CD48C((u32)func_02012944((void *)gameData), fieldMap, 2, 2, 4, 0, 2, 0);
        func_020113D0(scriptCtx, (int)func_021CB754);
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_COMM_CHECK_B:
        work->commResultDst = resultDst;
        work->commTask = (void *)func_021CD48C((u32)func_02012944((void *)gameData), fieldMap, 2, 2, 4, 1, 2, 0);
        startedTask = 1;
        func_020113D0(scriptCtx, (int)func_021CB7E8);
        break;
    case BSUBWAY_SCR_CMD_SEND_COMM_COMMAND:
        func_02167BFC(work, arg1, arg2);
        func_020113D0(scriptCtx, (int)func_021CB6DC);
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_START_COMM_RECEIVE:
        func_02167CF4(work, arg1);
        work->resultWorkId = resultWorkId;
        func_020113D0(scriptCtx, (int)func_021CB86C);
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_COMM_PLAYER_ID:
        *resultDst = func_02039338();
        break;
    case BSUBWAY_SCR_CMD_START_WIFI_PROC:
        func_02082BCC(&work->wifiProcParam, 0, 0x24);
        work->wifiProcParam.gameData = (GameData *)gameData;
        work->wifiProcParam.result = 11;
        func_0215897C(scriptWork, func_02014808((char *)gameSystem, (int)fieldMap, (u32)ov100_id, (int)data_021BB6A4, (int)&work->wifiProcParam, 0, 0));
        startedTask = 1;
        break;
    case BSUBWAY_SCR_CMD_GET_WIFI_PROC_RESULT:
        switch (work->wifiProcParam.result) {
        case 11:
            *resultDst = 0;
            break;
        case 12:
            *resultDst = 1;
            break;
        case 13:
            *resultDst = 2;
            break;
        default:
            *resultDst = 1;
            break;
        }
        break;
    case BSUBWAY_SCR_CMD_SET_PARTNER_PROFILE_ID:
        func_0200ED54(func_0200ED48((void *)saveControl), work->partnerMyStatus.id);
        break;
    case BSUBWAY_SCR_CMD_GET_LOOK_FIRST:
        *resultDst = func_021A3190(func_02039338() == 0 ? func_021A30B0(func_02188CB4((void *)fieldMap)) : work->partnerMyStatus.outfitVariant, 0);
        break;
    case BSUBWAY_SCR_CMD_GET_LOOK_SECOND:
        *resultDst = func_021A3190(func_02039338() == 0 ? work->partnerMyStatus.outfitVariant : func_021A30B0(func_02188CB4((void *)fieldMap)), 0);
        break;
    case BSUBWAY_SCR_CMD_CLEAR_SYSTEM_FLAG:
        func_0200FB38();
        break;
    case BSUBWAY_SCR_CMD_SET_SYSTEM_MODE:
        func_02012124((struct GameSystem *)gameSystem, 1);
        break;
    case BSUBWAY_SCR_CMD_IS_SYSTEM_FLAG_SET:
        *resultDst = 0;
        if (func_0200FB24() != 0)
            *resultDst = 1;
        break;
    case BSUBWAY_SCR_CMD_IS_BATTLE_REC_PLAYABLE: {
        BtlSetup *setup;
        *resultDst = 0;
        setup = work->btlSetup;
        if (setup != NULL && func_0200BA38(setup->recordMode) == 1)
            *resultDst = 1;
        break;
    }
    case BSUBWAY_SCR_CMD_NOP_END:
        break;
    }
    return startedTask;
}





/*
 * Task step: resolves the field's current map object and reports whether its fade has finished.
 *
 * Addresses are Black-image addresses.
 */
int func_021CB6DC(void *task, void *script)
{
    if (func_02167CB4(func_02012ED8(func_020120F4(func_02158F54(func_0215A5F4(script))))) == 1)
        return 1;
    return 0;
}





int func_021CB700(u32 unused, u32 script)
{
    void *gameData;
    BsubwayScrWork *work;
    void *scriptWork;
    u16 *resultDst;

    scriptWork = func_0215A5F4((void *)script);
    gameData = func_020120F4(func_02158F54(scriptWork));
    work = func_02012ED8(gameData);
    resultDst = func_02158FE0(scriptWork, gameData, work->resultWorkId);
    if (func_0200FB24() != 0) {
        *resultDst = 0;
        return 1;
    }
    if (func_02167B34(work->timingNo) == 1) {
        *resultDst = 1;
        return 1;
    }
    return 0;
}





int func_021CB754(u32 unused, u32 script)
{
    void *gameData, *saveControl;
    void *scriptWork;
    BsubwayScrWork *work;
    int commResult;
    u32 zero;

    scriptWork = func_0215A5F4((void *)script);
    func_02158F58((int)scriptWork);
    gameData = func_020120F4(func_02158F54(scriptWork));
    saveControl = func_02012EBC(gameData);
    func_0201296C(gameData);
    work = func_02012ED8(gameData);
    zero = 0;
    func_0200D884(func_020071CC(saveControl, 0x39), 0, 0);
    func_020071CC(saveControl, 0x3A);
    commResult = func_021CD688((u8 *)work->commTask);
    if (commResult != 0) {
        func_021CD5A4((u32 *)work->commTask);
        work->commTask = (void *)zero;
        switch (commResult) {
        case 1:
            *work->commResultDst = zero;
            return 1;
        case 2:
            *work->commResultDst = 1;
            return 1;
        case 4:
        default:
            *work->commResultDst = 2;
            return 1;
        }
    }
    return zero;
}





int func_021CB7E8(u32 unused, u32 script)
{
    void *gameData, *saveControl;
    void *scriptWork;
    BsubwayScrWork *work;
    int commResult;
    u32 zero;

    scriptWork = func_0215A5F4((void *)script);
    func_02158F58((int)scriptWork);
    gameData = func_020120F4(func_02158F54(scriptWork));
    saveControl = func_02012EBC(gameData);
    func_0201296C(gameData);
    work = func_02012ED8(gameData);
    zero = 0;
    func_0200D884(func_020071CC(saveControl, 0x39), 0, 0);
    func_020071CC(saveControl, 0x3A);
    commResult = func_021CD688((u8 *)work->commTask);
    if (commResult != 0) {
        func_021CD5A4((u32 *)work->commTask);
        work->commTask = (void *)zero;
        switch (commResult) {
        case 1:
            *work->commResultDst = zero;
            return 1;
        case 2:
        default:
            *work->commResultDst = 1;
            return 1;
        }
    }
    return zero;
}





int func_021CB86C(u32 unused, u32 script)
{
    void *gameData;
    void *scriptWork;
    BsubwayScrWork *work;
    u16 *resultDst;

    scriptWork = func_0215A5F4((void *)script);
    gameData = func_020120F4(func_02158F54(scriptWork));
    work = func_02012ED8(gameData);
    resultDst = func_02158FE0(scriptWork, gameData, work->resultWorkId);
    if (func_02167D00(work, resultDst) == 1)
        return 1;
    return 0;
}





/*
 * Task step: closes the message window, optionally resumes the field, then waits for the save to finish.
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 * The caller leaves the owner pointer in r0 for func_02167B18, so the extern
 * keeps one (ignored) parameter.
 *
 * Addresses are Black-image addresses.
 */
int func_021CB8AC(void *task, int *state, BsubwayScrWork **work)
{
    switch (*state) {
    case 0:
        if (func_0203D378() == 1)
            func_0203D7BC(0);
        if ((*work)->stateBits.commMode == 1)
            func_02167B18(*work);
        (*state)++;
        break;
    case 1:
        if (func_0203D378() == 1) {
            if (func_0203D1B4() <= 1) {
                func_0203CEAC(0);
                (*state)++;
            }
        } else {
            func_0203CEAC(0);
            (*state)++;
        }
        break;
    case 2:
        if (func_0203CDBC() == 1)
            return 1;
        break;
    }
    return 0;
}





/*
 * Starts the task 0x021CB8AC with a one-word work area holding the owner.
 *
 * Addresses are Black-image addresses.
 */
void *func_021CB914(void *gameSystem, u32 script)
{
    void *task = func_020122C0(gameSystem, 0, (TaskFn)func_021CB8AC, 4);
    *(u32 *)func_020124E8(task) = script;
    return task;
}





/*
 * Task step: fades out, runs the ov021 sub-screen on the arg member, stores whether it was cancelled in *result.
 *
 * Addresses are Black-image addresses.
 */
int func_021CB934(void *task, int *state, ScreenTaskWork *taskWork)
{
    func_0215A5F4(taskWork->script);
    switch (*state) {
    case 0:
        func_0215A684(taskWork->script, 8);
        (*state)++;
    case 1:
        if (func_0215A690(taskWork->script) == 1) {
            taskWork->screen = (u32)func_02190BE4((u16 *)func_02188C54(func_0201210C(func_0215A5DC(taskWork->script))), taskWork->arg);
            (*state)++;
        }
        break;
    case 2:
        switch (func_02190C78((struct ScreenHandle *)taskWork->screen)) {
        case 0:
            *taskWork->result = 0;
            (*state)++;
            break;
        case 2:
            break;
        default:
            *taskWork->result = 1;
            (*state)++;
            break;
        }
        break;
    case 3:
        func_021909BC((void *)taskWork->screen);
        return 1;
    }
    return 0;
}





void *func_021CB9BC(void *gameSystem, u32 script, u32 resultDst, u32 arg)
{
    void *task = func_020122C0(gameSystem, 0, (TaskFn)func_021CB934, 0x10);
    u32 *taskWork = func_020124E8(task);

    taskWork[0] = script;
    taskWork[1] = resultDst;
    taskWork[3] = arg;
    return task;
}





/*
 * Spawns the marker objects for playMode: in mode 4 up to five from the
 * 0x3B record list (newest first), otherwise every 0x021DAEBC entry whose
 * threshold equals the step count. The u16 accessor result held in a u32
 * local is what puts it in the top spill slot (a u16 or int local takes the
 * lowest). Unlabelled follower: 0x021CBBA0 (already filed).
 *
 * Addresses are Black-image addresses.
 */
void func_021CB9E4(BsubwayScrWork *work, void *gameData, void *fieldMmdlSys, void *fieldMap)
{
    int i;
    u16 objId;
    u32 zoneId;
    u8 playMode;
    const SpawnPos *spawnPos;
    u8 *recordList;
    u32 recordCount;
    u8 *recordEntry;
    u16 objCode;
    void *mapObj;
    u16 threshold;
    const SpawnEntry *spawnEntry;

    i = 0;
    zoneId = func_02188C9C(fieldMap);
    objId = 0x80;
    playMode = work->playMode;
    if (playMode == 4) {
        spawnPos = d_021DADD0;
        recordList = (u8 *)func_0200DF58(func_020071CC(func_02012EBC(gameData), 0x3B), (int)4);
        recordCount = func_0200DF94((struct BsubwayWifiRecordList *)recordList);
        if (recordCount != 0) {
            recordEntry = recordList + (recordCount - 1) * 0x22;
            while (recordCount != 0 && i < 5) {
                u32 lookIndex = func_0200DFB4((struct WifiRecordEntry *)recordEntry) % 10;
                if (((WifiRecordFlags *)(recordEntry + 0x20))->lookSet == 0)
                    objCode = d_021DAD48[lookIndex];
                else
                    objCode = d_021DAD5C[lookIndex];
                mapObj = func_0216CE6C(fieldMmdlSys, spawnPos->x, spawnPos->y, i % 4, objId, objCode, 2, zoneId);
                func_0216D620((int)mapObj, (u16)(recordCount - 1), 0);
                func_0216D5B4(mapObj, 5);
                recordEntry -= 0x22;
                i++;
                objId++;
                spawnPos++;
                recordCount--;
            }
        }
        func_020307B0(recordList);
        return;
    }
    spawnEntry = d_021DAEBC;
    threshold = func_0200DB80(work->scoreData, playMode);
    switch (playMode) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        threshold += 3;
        break;
    }
    while (spawnEntry->objCode != 0xFFFF) {
        if (threshold == d_021DADF8[spawnEntry->thresholdNo - 1]) {
            mapObj = func_0216CE6C(fieldMmdlSys, spawnEntry->x, spawnEntry->y, i % 4, objId, spawnEntry->objCode, 2, zoneId);
            func_0216D620((int)mapObj, (u16)i, 0);
            func_0216D620((int)mapObj, (u16)spawnEntry->param, 1);
            func_0216D5B4(mapObj, 5);
            if (objId < 0xFF)
                objId++;
        }
        spawnEntry++;
        i++;
    }
}





/*
 * Tail call into ov010 with a fixed second argument of 1 (unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CBBA0(u32 mapObj)
{
    return func_0216D63C((char *)mapObj, 1);
}





/*
 * Whether entry idx of the 16-byte table at 0x021DAEBC is available (never for kind 4; unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CBBAC(BsubwayScrWork *work, u32 idx)
{
    const NpcInfoEntry *entry = &data_021DAEBC[idx];

    if (work->playMode == 4)
        return 0;
    if (entry->infoThird != 0)
        return 1;
    return 0;
}





/*
 * Reads the three halfwords of table entry idx, or the empty triple (0, 0, 4) (unlabelled start).
 *
 * Addresses are Black-image addresses.
 */
void func_021CBBD0(BsubwayScrWork *work, u32 idx, u16 *infoFirst, u16 *infoSecond, u16 *infoThird)
{
    const NpcInfoEntry *entry = &data_021DAEBC[idx];

    if (work->playMode == 4) {
        *infoFirst = 0;
        *infoSecond = 0;
        *infoThird = 4;
        return;
    }
    if (entry->infoThird == 0) {
        *infoFirst = 0;
        *infoSecond = 0;
        *infoThird = 4;
        return;
    }
    *infoFirst = entry->infoFirst;
    *infoSecond = entry->infoSecond;
    *infoThird = entry->infoThird;
}





/*
 * Shows the playMode's message (20/21/22) with msgNumber capped at 9999 and reports whether it ended with 2 or 3.
 *
 * Addresses are Black-image addresses.
 */
int func_021CBC14(u32 unused, u32 script)
{
    void *gameData;
    BsubwayScrWork *work;
    int messageId;
    int number;
    int messageResult;

    gameData = func_020120F4(func_02158F54(func_0215A5F4((void *)script)));
    work = func_02012ED8(gameData);
    messageId = 20;
    number = work->msgNumber;
    switch (work->playMode) {
    case 0:
    case 4:
    case 5:
        break;
    case 1:
    case 6:
        messageId = 21;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        messageId = 22;
        break;
    }
    if (number > 9999)
        number = 9999;
    messageResult = func_0200B6E0(gameData, 4, messageId, number, 0, &work->msgState, &work->msgSubState);
    if (messageResult == 2 || messageResult == 3)
        return 1;
    return 0;
}





/*
 * Maps a kind 0..8 to the message id 20, 21 or 22.
 * Addresses are Black-image addresses.
 */
int func_021CBC94(u32 playMode)
{
    int id = 20;

    switch (playMode) {
    case 0:
    case 4:
    case 5:
        break;
    case 1:
    case 6:
        id = 21;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        id = 22;
        break;
    }
    return id;
}





/*
 * Maps the owner's mode 0x43..0x49 to a small index.
 *
 * Addresses are Black-image addresses.
 */
int func_021CBCC4(void *fieldMap)
{
    u16 zoneId = func_02188C9C(fieldMap);
    int trainIndex = 0;

    switch (zoneId) {
    case 0x43:
        trainIndex = 0;
        break;
    case 0x44:
        trainIndex = 5;
        break;
    case 0x45:
        trainIndex = 1;
        break;
    case 0x46:
        trainIndex = 6;
        break;
    case 0x47:
        trainIndex = 2;
        break;
    case 0x48:
        trainIndex = 7;
        break;
    case 0x49:
        trainIndex = 4;
        break;
    }
    return trainIndex;
}





/*
 * Builds a party list from the selected slots and runs the ov010 summary on it.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CBD08(BsubwayScrWork *work, int gameSystem)
{
    void *partyList = func_0201A920(0x8004);
    void *party = func_021CA210(work);
    int i;
    u32 result;

    func_0201A954(partyList, work->memberNum);
    for (i = 0; i < work->memberNum; i++)
        func_0201A98C(partyList, func_0201AB28(party, work->memberIndex[i]));
    result = (u32)func_021681C8((void *)gameSystem, partyList, work->playMode, work->trainers, &work->partners[work->stateBits.partnerNo], work->memberNum);
    func_020307B0(partyList);
    return result;
}




/*
 * Unlabelled leaf in ov021 (printed as a `.word` run at 0x021CBD84); the
 * matching byte at 0x021CBD8C is the pool word 0x0000074C.  Six-byte
 * accessor reached from ov010's func_0216CAD4 across the overlay pair.
 */
void *func_021CBD84(void *work)
{
    return (char *)work + 0x74c;
}





static inline u16 RandInRange(BsubwayScrWork *work, u32 tbl, u32 round)
{
    u16 span = ((const TrainerNoRange *)(tbl + round * 4))->maxNo - ((const TrainerNoRange *)(tbl + round * 4))->minNo + 1;
    return func_021CBF98(work) % span + ((const TrainerNoRange *)(tbl + round * 4))->minNo;
}





/*
 * Picks a battle-subway trainer id: the fixed boss ids on the boss round, otherwise a random id from the per-round range table of the line (normal or super, early or late stages).
 *
 * Each table arm calls the random-range helper with the table address cast to
 * an integer. A shared `const TrainerNoRange *tbl` local is a named variable and takes
 * the first callee-saved register (r4) ahead of the scaled index and the span;
 * per-arm calls leave the base as a short-lived load that colours after them
 * (r6, with round*4 in r4 and span in r5), and the arms' identical tails are
 * cross-jumped into one block. The integer base keeps `tbl + off` then `+2`
 * for hi instead of folding the field offset into a second pool word
 * (d_X + 2), and loads the base before the index shift. 0x0209C0A4 is
 * _s32_div_f, so the u16 % u16 modulo is signed (int promotion).
 *
 * Addresses are Black-image addresses.
 */
u16 func_021CBD90(BsubwayScrWork *work, u32 round, u32 stage, u32 line, u8 alt)
{
    int super;
    int boss;
    u16 id;

    id = 0;
    super = 0;
    boss = -1;

    switch (line) {
    case 5:
    case 6:
    case 7:
    case 8:
        super = 1;
        break;
    }

    if (stage == 6) {
        if (!super) {
            if (round == 2)
                boss = 0;
        } else {
            if (round == 6)
                boss = 1;
        }
    }

    if (boss != -1) {
        switch (line) {
        case 0:
        case 5:
            if (boss == 0)
                id = 0x132;
            else if (boss == 1)
                id = 0x133;
            break;
        case 1:
        case 6:
            if (boss == 0)
                id = 0x134;
            else if (boss == 1)
                id = 0x135;
            break;
        case 2:
        case 3:
        case 7:
        case 8:
            if (boss == 0) {
                if (alt == 0)
                    id = 0x137;
                else
                    id = 0x136;
            } else if (boss == 1) {
                if (alt == 0)
                    id = 0x139;
                else
                    id = 0x138;
            }
            break;
        }
    } else if (!super) {
        if (round >= 3)
            goto done;
        if (stage < 6) {
            id = RandInRange(work, (u32)d_021DB3D8, round);
            goto done;
        }
        if (round >= 2)
            goto done;
        id = RandInRange(work, (u32)d_021DB3D0, round);
    } else {
        if (round >= 4)
            goto randomId;
        if (stage < 6) {
            id = RandInRange(work, (u32)d_021DB3E4, round);
            goto done;
        }
        id = RandInRange(work, (u32)d_021DB3F4, round);
        goto done;
randomId:
        id = func_021CBF98(work) % 100 + 200;
    }
done:
    return id;
}





/*
 * Forwarder into ov010 that drops the first argument and returns its byte result.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021CBED8(BsubwayScrWork *work, BtlInstTrainer *trainer, u16 trainerNo, u8 memberNum, u16 *monsNo, u16 *itemNo, BtlInstDraw *draw, u16 heapId)
{
    return func_02168878(trainer, trainerNo, memberNum, monsNo, itemNo, draw, heapId);
}





/*
 * Maps a value to a bracket 3..31 in steps of 20.
 * Addresses are Black-image addresses.
 */
u8 func_021CBEFC(u32 trainerNo)
{
    if (trainerNo < 100)
        return 3;
    if (trainerNo < 120)
        return 6;
    if (trainerNo < 140)
        return 9;
    if (trainerNo < 160)
        return 12;
    if (trainerNo < 180)
        return 15;
    if (trainerNo < 200)
        return 18;
    if (trainerNo < 220)
        return 21;
    return 31;
}





/*
 * Builds the two battle-subway opponent mons in mons[] of the trainer record.
 *
 * Addresses are Black-image addresses.
 */
void func_021CBF38(BsubwayScrWork *work, BtlInstTrainer *trainer, u16 trainerNo, int useItem, BtlInstDraw *draw, u16 heapId)
{
    u8 iv;
    void *trainerData;
    int i;

    trainerData = func_021688BC(trainer, trainerNo, heapId);
    iv = func_021CBEFC(trainerNo);
    for (i = 0; i < 2; i++)
        func_021684E8(&trainer->mons[i], draw->ids[i], draw->otId, draw->pids[i], iv, i, useItem, heapId);
    func_020307B0(trainerData);
}





/*
 * A 16-bit random value: the arm9 random source scaled down by 0xFFFF.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021CBF98(void *unused)
{
    return func_020056EC(0xffffffff) / 0xffff;
}
