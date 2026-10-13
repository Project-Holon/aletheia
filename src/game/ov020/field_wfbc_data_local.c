/*
 * file:     field_wfbc_data_local.c
 * unit:     yes
 * function: func_02186090, func_0218609C, func_021860B8, func_021860D4, func_021861BC, func_021861F4, func_0218625C, func_02186278, func_021862A8, func_02186470, func_021864DC, func_02186520, func_02186538, func_02186670, func_021866F8, func_02186748, func_02186764, func_02186770, func_0218677C, func_021867A8, func_021867B0, func_021867B4, func_021867C4, func_02186804, func_02186818, func_0218682C, func_02186830, func_0218683C, func_02186844, func_0218684C, func_02186854, func_02186878, func_02186898, func_021868A0, func_021868B8, func_021869AC, func_021869B0, func_021869B8, func_021869BC, func_021869D0, func_021869D4, func_021869D8, func_021869DC, func_021869E0, func_02186A2C, func_02186A58, func_02186AC8, func_02186B08, func_02186B2C, func_02186B60, func_02186B84, func_02186BA8, func_02186BB8, func_02186BE0, func_02186BE4, func_02186C44, func_02186CC4, func_02186D48, func_02186E94, func_02186EB8, func_02187000, func_02187098, func_021870C4, func_021871F8, func_0218741C, func_0218748C, func_02187508, func_021875B8
 * address:  0x02186090
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

struct GameData;
struct Location;
struct PlayerWork;
struct MsgData;
struct Strbuf;
struct MyStatus;
struct ArcHandle;
struct FieldMap;
struct FieldWfbc;
struct GameSystem;
struct RtcDate;
struct GameEvent;
struct WordSet;
struct Mmdl;
struct VecFx32;
struct FieldMsgHandle;
struct ScrcmdWork;
struct FieldYesNoHandle;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Location { u32 v[7]; };

typedef short GridCoord;

typedef signed int     s32;

typedef unsigned long long u64;
#include "../ov010/script_work_types.h"
#include "../ov021/field_wfbc_types.h"
extern void *func_020127A4(struct GameData *p);
struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
u32 func_020307B0(void *p);
void func_02045808(struct Strbuf *vec);
u32 func_02045C04(struct MsgData *rec);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u16 func_0216D588(const struct Mmdl *mmdl);
extern void func_02161E78(WfbcPerson *person);
extern u32 func_02008530(const struct MyStatus *obj);
extern u32 func_020056EC(u32 n);
extern int func_02161E84(const WfbcPerson *person);
u8 func_0200855C(const struct MyStatus *obj);
int func_021584F4(int a, int b);
extern int func_02161ECC(const WfbcPerson *person);
extern u16 func_02012AC8(const struct PlayerWork *p);
extern WfbcData *func_020127C4(struct GameData *gameData);
extern u16 *func_020127E0(struct GameData *gameData);
extern WfbcDailyState *func_020127F0(struct GameData *gameData);
extern int func_02013DE0(u16 id);
extern void func_02161E60(WfbcData *data, int mode);
extern void func_02161EEC(u16 *itemSlots);
extern void func_0216E618(MmdlHeader *header, u16 gridX, u16 gridZ, int direction);
extern u16 func_02045A98(void);
extern const void *func_020084F4(const void *p);
extern void func_02082D44(const void *src, void *dst, u32 size);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0204932C(struct ArcHandle *arc, u32 member, void *dst);
extern void func_02049238(void *p);
extern void *func_02049250(struct ArcHandle *arc, unsigned int member,
                           unsigned int heap);
extern ScriptWork *func_0215A5F4(struct ScrcmdWork *work);
extern ScriptFieldParam *func_02158F58(ScriptWork *scriptWork);
extern void *func_02188C98(void *fieldSystem);
extern FieldWfbc *func_0218DC70(void *fieldWfbcOwner);
extern struct GameData *func_0215A5E4(struct ScrcmdWork *work);
extern void *func_02188CB4(void *fieldSystem);
extern void *func_02188C7C(void *fieldSystem);
extern int func_021A3460(void *player, GridCoord *outX, GridCoord *outY, GridCoord *outZ);
extern struct Mmdl *func_0216DDC0(void *mmdlSystem, int gridX, int gridZ, int unused);
extern void func_02193B40(FieldWfbc *wfbc, u32 personIndex);
extern int func_02193BE4(FieldWfbc *wfbc, u32 personIndex);
extern void func_02193BC4(FieldWfbc *wfbc, u32 personIndex);
extern void *func_02158F74(ScriptWork *scriptWork);
extern unsigned int func_02159B10(ScriptVm *vm, struct ScrcmdWork *work);
extern u16 func_0215A5CC(struct ScrcmdWork *work);
extern void func_02193B68(FieldWfbc *wfbc, void *wordSet, int npcId, int bufIndex, int heapId);
extern u16 *func_02159AE8(ScriptVm *vm, struct ScrcmdWork *work);
extern void func_02193904(FieldWfbc *wfbc);
extern FieldWfbcPeople *func_0219390C(FieldWfbc *wfbc, u32 personIndex);
extern WfbcNpcRecord *func_02193C00(FieldWfbcPeople *people);
extern WfbcPerson *func_02193C04(FieldWfbcPeople *people);
extern int func_021938F4(FieldWfbc *wfbc);
extern struct GameSystem *func_02188C80(void *fieldSystem);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
void *func_02012934(const struct GameData *p);
u32 func_0201AA18(void *a);
void func_0203F4E4(struct RtcDate *date);
void *func_0201AB28(void *a, u32 i);
u32 func_02017E1C(void *p, u32 id, u32 v);
extern unsigned char func_0219391C(FieldWfbc *wfbc);
extern struct GameSystem *func_0215A5DC(struct ScrcmdWork *work);
extern void *func_0201210C(const struct GameSystem *gameSystem);
extern void func_0215897C(ScriptWork *scriptWork, void *event);
u16 func_02188C84(void *fieldSystem);
u32 func_02188C54(void *fieldSystem);
void *func_02012138(const struct GameSystem *gameSystem);
void *func_02158344(void *eventWork);
void *func_02158434(void *eventWork);
struct GameEvent *func_020122C0(struct GameSystem *gameSystem, void *parent, void *proc, u32 workSize);
void *func_020124E8(struct GameEvent *p);
struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
struct WordSet *func_0201EC64(u32 heap);
WfbcData *func_020127D0(struct GameData *gameData, u32 index);
void func_0216D88C(const struct Mmdl *mmdl, struct VecFx32 *out);
int func_021620A0(void *returnList);
void func_02162048(void *returnList, int personIndex, int mode);
int func_0216208C(void *returnList, int personIndex);
u16 func_0216209C(void *returnList);
int func_02161E4C(WfbcData *data, int personIndex, unsigned mode);
void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);
void *func_02012944(struct GameData *gameData);
void func_02161F90(void *returnList, WfbcData *ownData, WfbcData *cityData, void *playerBlock, u16 personIndex, u16 heapId);
int func_02193B20(FieldWfbc *wfbc, u32 personIndex);
void func_0216CF2C(struct Mmdl *mmdl);
u32 func_0201ED04(struct WordSet *p);
extern void func_02045CAC(struct MsgData *bank, u32 index, struct Strbuf *dest);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern struct FieldMsgHandle *func_0219129C(int msgBgSys, int speed, int *playerPos, struct Strbuf *message, u32 c, u32 d);
extern u32 func_02191388(struct FieldMsgHandle *handle);
extern u32 func_020362DC(void);
extern struct FieldYesNoHandle *func_02190BE4(int msgBgSys, u32 b);
extern int func_02190C78(struct FieldYesNoHandle *h);
extern int func_021909BC(struct FieldYesNoHandle *handle);
extern int func_021912D8(struct FieldMsgHandle *handle);
extern int func_021912F8(struct FieldMsgHandle *handle);
extern int func_0219131C(struct FieldMsgHandle *handle);
int func_02186090(const struct Mmdl *mmdl);
void func_0218609C(WfbcData *data);
void func_021860B8(WfbcData *data);
void func_021860D4(WfbcData *data, const struct MyStatus *myStatus, int heapSeed);
int func_021861BC(WfbcData *data);
void func_021861F4(WfbcData *data, const struct MyStatus *myStatus);
int func_0218625C(WfbcData *data);
int func_02186278(const WfbcData *data, int which);
void func_021862A8(struct GameData *gameData, int days, u32 heapSeed);
void func_02186470(struct GameData *gameData);
void func_021864DC(u8 *data);
void func_02186520(WfbcData *data, const struct MyStatus *myStatus, WfbcPerson *person);
MmdlHeader *func_02186538(WfbcData *data, int which, int heapSeed);
void func_02186670(const WfbcData *data, WfbcListEntry *entries, u16 *entryCount, int page, u16 heapId);
void func_021866F8(WfbcPerson *person);
void func_02186748(WfbcPerson *person);
void func_02186764(WfbcPerson *person);
int func_02186770(const WfbcPerson *person);
void func_0218677C(WfbcPerson *person, const struct MyStatus *myStatus);
int func_021867A8(const WfbcPerson *person);
int func_021867B0(const WfbcPerson *person);
int func_021867B4(const WfbcPerson *person);
WfbcNpcData *func_021867C4(int fileId, int heapId);
void func_02186804(WfbcNpcData *npcData);
void func_02186818(WfbcNpcData *npcData, u32 fileId);
WfbcNpcRecord *func_0218682C(WfbcNpcData *npcData);
WfbcPosition *func_02186830(WfbcNpcData *npcData, int cityType, unsigned int heapId);
void func_0218683C(WfbcPosition *positions);
WfbcPosition *func_02186844(WfbcPosition *positions, int index);
WfbcPosition *func_0218684C(WfbcPosition *positions, int index);
int func_02186854(const u16 *itemSlots);
int func_02186878(u16 *itemSlots, u16 itemId, int slot);
u16 func_02186898(const u16 *itemSlots, int slot);
int func_021868A0(const u16 *itemSlots, int slot);
MmdlHeader *func_021868B8(u16 *itemSlots, int which, int cityType, int heapSeed);
u16 func_021869AC(const WfbcDailyState *dailyState);
void func_021869B0(WfbcDailyState *dailyState);
u16 func_021869B8(const WfbcDailyState *dailyState);
void func_021869BC(WfbcDailyState *dailyState);
u16 func_021869D0(const WfbcDailyState *dailyState);
void func_021869D4(WfbcDailyState *dailyState, u16 value);
u16 func_021869D8(const WfbcDailyState *dailyState);
void func_021869DC(WfbcDailyState *dailyState, u16 counter);
WfbcNpcRecord *func_021869E0(const WfbcData *data, int limit, WfbcNpcData *npcData, int *outNpcId);
int func_02186A2C(const WfbcData *data, int nth);
int func_02186A58(const WfbcData *data, int npcId);
void func_02186AC8(WfbcData *data, const struct MyStatus *myStatus, WfbcPerson *person, int setParent);
int func_02186B08(const WfbcPerson *list);
WfbcPerson *func_02186B2C(WfbcPerson *list, const WfbcPerson *person);
WfbcPerson *func_02186B60(WfbcPerson *list);
void func_02186B84(WfbcPerson *person, int npcId, const struct MyStatus *myStatus, int mood, int setParent);
int func_02186BA8(const WfbcPerson *person);
int func_02186BB8(WfbcPerson *person, int delta);
void func_02186BE0(WfbcPerson *person, int mood);
int func_02186BE4(ScriptVm *vm, struct ScrcmdWork *work);
int func_02186C44(ScriptVm *vm, struct ScrcmdWork *work);
int func_02186CC4(ScriptVm *vm, struct ScrcmdWork *work);
int func_02186D48(ScriptVm *vm, struct ScrcmdWork *work);
int func_02186E94(ScriptVm *vm, struct ScrcmdWork *work);
int func_02186EB8(ScriptVm *vm, struct ScrcmdWork *work);
int func_02187000(ScriptVm *vm, struct ScrcmdWork *work);
int func_02187098(ScriptVm *vm, struct ScrcmdWork *work);
struct GameEvent *func_021870C4(struct GameSystem *gameSystem, void *fieldSystem);
int func_021871F8(struct GameEvent *event, int *state, WfbcTalkEvent *talk);
void func_0218741C(WfbcTalkEvent *talk, int messageSlot, int *state, int nextState);
void func_0218748C(WfbcTalkEvent *talk, int messageSlot, int *state, int yesStateId, u16 noStateId);
int func_02187508(WfbcTalkEvent *talk);
int func_021875B8(WfbcTalkEvent *talk);
extern const char d_02187EB4[];
extern const MmdlHeader d_02187DBC;
extern const MmdlHeader d_02187DE0;
extern u16 d_02187E04[];

/*
 * extent: two zero alignment bytes after the return.
 */
int func_02186090(const struct Mmdl *mmdl)
{
    return func_0216D588(mmdl) - 0x80;
}

void func_0218609C(WfbcData *data)
{
    int i;
    for (i = 0; i < 10; i++)
        func_02161E78(&data->people[i]);
}

void func_021860B8(WfbcData *data)
{
    int i;
    for (i = 0; i < 10; i++)
        func_02161E78(&data->backPeople[i]);
}

void func_021860D4(WfbcData *data, const struct MyStatus *myStatus, int heapSeed)
{
    int i;
    int j;
    int roll;
    WfbcNpcRecord *npcRecord;
    int remaining;
    int setParent;
    int npcId;
    WfbcPerson *person;
    WfbcNpcData *npcData;
    int mood;

    data->isValid = 1;
    i = 0;
    data->cityType = 0;
    remaining = 0x1CE;
    data->playerId = func_02008530(myStatus);
    npcData = func_021867C4(0, (u16)((heapSeed & 0x7FFF) | 0x8000));
    func_0218682C(npcData);
    for (i = 0; i < 10; i++) {
        roll = func_020056EC(remaining);
        person = func_02186B60(data->people);
        npcRecord = func_021869E0(data, roll, npcData, &npcId);
        if (data->cityType == 0) {
            mood = npcRecord->initialMoodType0;
            setParent = 1;
        } else {
            mood = npcRecord->initialMoodType1;
            setParent = 0;
        }
        func_02186B84(person, (u8)npcId, myStatus, (u16)mood, setParent);
        remaining -= npcRecord->weight;
    }
    for (j = 0; j < 3; j++) {
        roll = func_020056EC(remaining);
        person = func_02186B60(data->backPeople);
        npcRecord = func_021869E0(data, roll, npcData, &npcId);
        func_02186B84(person, (u8)npcId, myStatus, 0, setParent);
        remaining -= npcRecord->weight;
    }
    func_02186804(npcData);
}

int func_021861BC(WfbcData *data)
{
    WfbcPerson *people;
    int i;
    if (data->isValid == 1 && data->cityType >= 2)
        return 0;
    i = 0;
    people = data->people;
    for (; i < 10; i++)
        if (func_02161E84(&people[i]) == 0)
            return 0;
    return 1;
}

void func_021861F4(WfbcData *data, const struct MyStatus *myStatus)
{
    int i;

    if (data->isValid > 1)
        data->isValid = 1;
    if (data->isValid == 0 && data->cityType != 2)
        data->cityType = 2;
    if (data->isValid == 1 && data->cityType >= 2) {
        int version = func_0200855C(myStatus);
        if (func_021584F4((u8)version, func_02008530(myStatus)) == 0x15)
            data->cityType = 0;
        else
            data->cityType = 1;
    }
    for (i = 0; i < 10; i++)
        func_021866F8(&data->people[i]);
}

int func_0218625C(WfbcData *data)
{
    if (data->isValid == 0)
        return 0;
    if (func_021861BC(data) != 0)
        return 1;
    return 0;
}

int func_02186278(const WfbcData *data, int which)
{
    const WfbcPerson *people;
    int i;
    int count;
    if (which == 0)
        people = data->people;
    else
        people = data->backPeople;
    count = 0;
    for (i = 0; i < 10; i++)
        if (func_02161ECC(&people[i]))
            count++;
    return count;
}

/*
 * 2026-10-04 (wD3 lane 15): DIFF, 456 bytes (right size), 200 diff bytes, all from one cause. The original spills the
 * func_02012AC8 result (id) to [sp,#0x14] at once and loads it later for the u16 shift (id16 at sp24); this draft
 * keeps id in r7, so every later slot is one word lower (frame 0x2c vs 0x30). Control flow, the qq/items3 double store
 * and all calls match. Tried: id16, qq, items3 as named locals (current), compiler hoist of (u16)id (slots wrong),
 * u16 callee param for func_02186878 (extra mov). Next: find what makes id spill (a second use of id, decl order).
 *
 * Note 2026-10-05 (wD4 lane12): MATCH, all 456 bytes. Keys: no qq/id16
 * locals (base + 0xF8 and the id conversion are compiler loop hoists, which
 * spills id at once); func_02013DE0 takes u16 and gets id directly; p is set
 * inside the if; the item base is a named items = base + 8 assigned after
 * i = 0; the second loop uses base + 8 + off (hoisted copy-add at sp+0x2c);
 * the random third argument goes through a u16 local v; q[t%3] reads
 * (q + 4)[t % 3]. Only blocker: arm9 callee 0x02013DE0 had no label; filed
 * src/matched/arm9/func_02013DE0.c (EXACT). EXACT once that has a shard.
 */
void func_021862A8(struct GameData *gameData, int days, u32 heapSeed)
{
    char *base;
    char *items;
    u16 *itemSlots;
    WfbcDailyState *dailyState;
    u32 zoneId;
    u32 backCount;
    int moodDelta;
    char *person;
    int offset;
    int i;
    int j;
    WfbcNpcData *npcData;
    WfbcNpcRecord *npcRecord;
    u32 weightSum;
    u32 pick;

    zoneId = func_02012AC8(func_020127A4(gameData));
    base = (char *)func_020127C4(gameData);
    itemSlots = func_020127E0(gameData);
    dailyState = func_020127F0(gameData);
    if (days <= 0) {
        days = 1;
    }
    if (days > 21) {
        days = 21;
    }
    backCount = func_02186278((WfbcData *)base, 1);
    j = 0;
    moodDelta = (j - 5) * days;
    i = 0;
    items = base + 8;
    for (; i < 10; i++) {
        if (func_02161ECC((WfbcPerson *)(items + i * 0x18)) != 0) {
            int reachedZero;
            person = base + i * 0x18;
            person[0xb] = 7;
            reachedZero = func_02186BB8((WfbcPerson *)(items + i * 0x18), moodDelta);
            if (reachedZero != 0 && backCount + j >= 10) {
                func_02186BE0((WfbcPerson *)(items + i * 0x18), 1);
            } else if (reachedZero != 0) {
                if (func_02013DE0(zoneId) == 0) {
                    func_02186B2C((WfbcPerson *)(base + 0xF8), (WfbcPerson *)(items + i * 0x18));
                    func_02161E78((WfbcPerson *)(items + i * 0x18));
                } else {
                    person[0xb] = 1;
                }
                j++;
            }
        }
    }
    i = 0;
    func_02161E60((WfbcData *)base, 0);
    func_02161EEC(itemSlots);
    npcData = func_021867C4(0, (u16)((heapSeed & 0x7FFF) | 0x8000));
    if (((WfbcData *)base)->cityType == 1) {
        for (i = 0; i < 10; i++) {
            char *entry = base + 8 + i * 0x18;
            if (func_02161ECC((WfbcPerson *)entry) != 0) {
                func_02186818(npcData, *(u8 *)(base + i * 0x18 + 9));
                npcRecord = func_0218682C(npcData);
                if ((u16)func_020056EC(100) < npcRecord->giftChance) {
                    u16 slot = func_020056EC(10);
                    func_02186878(itemSlots, npcRecord->giftItemId, slot);
                }
            }
        }
        i = 0;
        backCount = func_02186278((WfbcData *)base, 0);
        if (backCount != 0) {
            weightSum = 0;
            pick = func_020056EC(backCount * 3);
            for (j = 0; j < 10; j++) {
                offset = j * 0x18;
                if (func_02161ECC((WfbcPerson *)(base + 8 + offset)) != 0) {
                    weightSum += 3;
                    if (weightSum > pick) {
                        func_02186818(npcData, *(u8 *)(base + offset + 9));
                        npcRecord = func_0218682C(npcData);
                        func_021869D4(dailyState, (npcRecord->requestIds)[pick % 3]);
                        func_021869DC(dailyState, npcRecord->giftItemId);
                        break;
                    }
                }
            }
        }
    }
    func_02186804(npcData);
}

/*
 * note: 2026-10-05 (wD9r lane166): EXACT. The tests use the items local (items + i * 0x18), the body
 *   calls spell the address again as base + 8 + i * 0x18, as in the matched siblings ov010 02161DC4
 *   and ov020 021862A8 (a = p + 8 for the tests, p + 8 + i * 0x18 for the result). The second spelling
 *   is a separate invariant in the if body; LICM probably hoists it before the (u16)id conversion, so the
 *   items web is a late temp that interferes with id and takes r4 (a0 r4, id r5 as in the image).
 */
void func_02186470(struct GameData *gameData)
{
    char *backPeople;
    u32 zoneId;
    char *base;
    char *items;
    u16 key;
    int i;

    zoneId = func_02012AC8(func_020127A4(gameData));
    base = (char *)func_020127C4(gameData);
    i = 0;
    backPeople = base + 0xF8;
    items = base + 8;
    key = zoneId;
    for (; i < 10; i++) {
        if (func_02161ECC((WfbcPerson *)(items + i * 0x18)) != 0 && func_02186BA8((WfbcPerson *)(items + i * 0x18)) != 0 && func_02013DE0(key) == 0) {
            func_02186B2C((WfbcPerson *)backPeople, (WfbcPerson *)(base + 8 + i * 0x18));
            func_02161E78((WfbcPerson *)(base + 8 + i * 0x18));
        }
    }
    func_02161E60((WfbcData *)base, 0);
}

static inline void FIELD_WFBC_DATA_LOCAL_ClearFlagBits(u8 *flags, unsigned int mask)
{
    unsigned int value = *flags;
    value &= ~mask;
    *flags = value;
}

/*
 * extent: 66 bytes of code followed by two zero alignment bytes.
 * Lever: the inline helper holds the loaded byte in a full-width unsigned
 * local before clearing its bits; the constant argument stays positive
 * and is hoisted to a spill instead of folding to the byte complement.
 */
void func_021864DC(u8 *data)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (func_02161ECC((WfbcPerson *)(data + 8 + i * 0x18)) &&
            (*(u8 *)((unsigned int)data + i * 0x18 + 0xb) & 2)) {
            func_02186BB8((WfbcPerson *)(data + 8 + i * 0x18), 3);
            FIELD_WFBC_DATA_LOCAL_ClearFlagBits((u8 *)((unsigned int)data + i * 0x18 + 0xb), 2);
        }
    }
}

void func_02186520(WfbcData *data, const struct MyStatus *myStatus, WfbcPerson *person)
{
    if (data->cityType == 0)
        func_02186AC8(data, myStatus, person, 1);
    else
        func_02186AC8(data, myStatus, person, 0);
}

MmdlHeader *func_02186538(WfbcData *data, int which, int heapSeed)
{
    int count;
    MmdlHeader *headers;
    WfbcNpcData *npcData;
    WfbcPosition *positions;
    int heapId;
    int total;
    int i;
    WfbcPerson *people;
    WfbcNpcRecord *npcRecord;
    MmdlHeader *header;
    MmdlHeader proto;

    heapId = (u16)((heapSeed & 0x7FFF) | 0x8000);
    total = func_02186278(data, which);
    if (total == 0)
        return 0;
    if (which == 0)
        people = data->people;
    else
        people = data->backPeople;
    headers = func_02030734(heapId, total * 0x24, 1, d_02187EB4, 0x2E3);
    count = 0;
    npcData = func_021867C4(0, heapId);
    positions = func_02186830(npcData, data->cityType, heapId);
    i = 0;
    proto = d_02187DBC;
    for (; i < 10; i++) {
        if (func_02161ECC(&people[i])) {
            header = &headers[count];
            *header = proto;
            func_02186818(npcData, func_021867B0(&people[i]));
            npcRecord = func_0218682C(npcData);
            header->objId = func_021867B0(&people[i]) + 0x80;
            header->objCode = npcRecord->objCode;
            header->moveCode = 3;
            if (which == 0) {
                if (data->cityType == 0)
                    header->eventId = npcRecord->eventIds[1];
                else
                    header->eventId = npcRecord->eventIds[0];
            } else {
                if (data->cityType == 0)
                    header->eventId = npcRecord->eventIds[3];
                else
                    header->eventId = npcRecord->eventIds[2];
            }
            func_0216E618(header, positions[i].x, positions[i].z, 0);
            count++;
        }
    }
    func_0218683C(positions);
    func_02186804(npcData);
    return headers;
}

void func_02186670(const WfbcData *data, WfbcListEntry *entries, u16 *entryCount, int page, u16 heapId)
{
    unsigned total;
    unsigned limit;
    int first;
    int num;
    int i;
    WfbcNpcData *npcData;
    WfbcNpcRecord *npcRecord;
    const char *pageBase;

    total = func_02186278(data, 0);
    first = page * 2;
    limit = first + 2;
    if (limit > total)
        limit = total;
    num = limit - first;
    i = 0;
    npcData = func_021867C4(0, heapId);
    npcRecord = func_0218682C(npcData);
    *entryCount = 0;
    if (num > 0) {
        pageBase = (const char *)data + first * 0x18;
        do {
            func_02186818(npcData, (u8)pageBase[i * 0x18 + 9]);
            entries[*entryCount].entryId = npcRecord->listEntryId;
            entries[*entryCount].param = npcRecord->listEntryParam;
            *entryCount = *entryCount + 1;
            i++;
        } while (i < num);
    }
    func_02186804(npcData);
}

void func_021866F8(WfbcPerson *person)
{
    int i;
    int found;
    u16 eosChar;

    eosChar = func_02045A98();
    if (person->npcId >= 0x1e)
        func_02161E78(person);
    if (person->mood > 0x64)
        func_02161E78(person);
    if (person->hasParent != 0) {
        found = 0;
        for (i = 0; i < 8; i++) {
            if (eosChar == person->parentName[i])
                found = 1;
        }
        if (found == 0)
            func_02161E78(person);
    }
}

/*
 * Lever: raw-byte flag test, then bitfield assignment for the bics clear.
 */
void func_02186748(WfbcPerson *person) { if (person->flags.all & 4) { func_02186BB8(person, 10); person->flags.bits.gift = 0; } }

/*
 * Clear bit 0 of the byte at +3.
 *
 * Addresses are Black-image addresses.
 */
void func_02186764(WfbcPerson *person)
{
person->flags.bits.arrival = 0;
}

/*
 * Test: is bit 0 of the byte at +3 set.
 *
 * Addresses are Black-image addresses.
 */
int func_02186770(const WfbcPerson *person)
{
return (person->flags.all & 1) != 0;
}

/*
 * Follower 021867A8 is already filed separately; 020084F4 returns its unchanged incoming r0.
 */
void func_0218677C(WfbcPerson *person, const struct MyStatus *myStatus) { person->hasParent = 1; person->parentId = func_02008530(myStatus); func_02082D44(func_020084F4(myStatus), person->parentName, 16); }

/*
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of func_02186D48 (ov020).
 */
int func_021867A8(const WfbcPerson *person)
{
    return person->hasParent;
}

/*
 * Follower 021867B4 is already filed separately.
 */
int func_021867B0(const WfbcPerson *person) { return person->npcId; }

int func_021867B4(const WfbcPerson *person)
{
    return person->mood <= 20;
}

WfbcNpcData *func_021867C4(int fileId, int heapId)
{
    WfbcNpcData *npcData = func_02030734(heapId, 0x38, 1, (const char *)&d_02187EB4, 0x448);

    npcData->arc = func_020490F4(0x9a, heapId);
    func_0204932C(npcData->arc, fileId, &npcData->record);
    npcData->fileId = fileId;
    return npcData;
}

void func_02186804(WfbcNpcData *npcData) { func_02049238(npcData->arc); func_020307B0(npcData); }

void func_02186818(WfbcNpcData *npcData, u32 fileId) { func_0204932C(npcData->arc, fileId, &npcData->record); npcData->fileId = fileId; }

WfbcNpcRecord *func_0218682C(WfbcNpcData *npcData)
{
    return &npcData->record;
}

WfbcPosition *func_02186830(WfbcNpcData *npcData, int cityType, unsigned int heapId)
{
    return func_02049250(npcData->arc, cityType + 0x22, heapId);
}

/*
 * Follower 02186844 is already filed separately.
 */
void func_0218683C(WfbcPosition *positions) { func_020307B0(positions); }

/*
 * Unlabelled leaf: address of the i-th two-byte pair of a table.
 *
 * Addresses are Black-image addresses.
 */
WfbcPosition *func_02186844(WfbcPosition *positions, int index)
{
    return &positions[index];
}

WfbcPosition *func_0218684C(WfbcPosition *positions, int index)
{
    return &positions[index + 10];
}

int func_02186854(const u16 *itemSlots) { int i; int count; count = 0; for (i = 0; i < 10; i++) { if (itemSlots[i] != 0xFFFF) count++; } return count; }

int func_02186878(u16 *itemSlots, u16 itemId, int slot) { if (itemSlots[slot] == 0xFFFF) { itemSlots[slot] = itemId; return 1; } return 0; }

u16 func_02186898(const u16 *itemSlots, int slot)
{
    return itemSlots[slot];
}

int func_021868A0(const u16 *itemSlots, int slot) { if (itemSlots[slot] != 0xFFFF) return 1; return 0; }

MmdlHeader *func_021868B8(u16 *itemSlots, int which, int cityType, int heapSeed)
{
    MmdlHeader *headers;
    WfbcNpcData *npcData;
    WfbcPosition *positions;
    WfbcPosition *position;
    int heapId;
    int total;
    int count;
    MmdlHeader *header;
    int i;
    MmdlHeader proto;

    if (which != 0)
        return 0;
    if (cityType == 0)
        return 0;
    heapId = (u16)((heapSeed & 0x7FFF) | 0x8000);
    total = func_02186854(itemSlots);
    count = 0;
    headers = func_02030734(heapId, total * 0x24, 1, d_02187EB4, 0x561);
    npcData = func_021867C4(0, heapId);
    positions = func_02186830(npcData, cityType, heapId);
    i = 0;
    proto = d_02187DE0;
    for (; i < 10; i++) {
        if (func_021868A0(itemSlots, i)) {
            position = func_0218684C(positions, i);
            header = &headers[count];
            *header = proto;
            header->objId = i + 0xa0;
            header->eventId = func_02186898(itemSlots, i);
            header->eventFlag = i + 0xaa0;
            func_0216E618(header, position->x, position->z, 0);
            count++;
        }
    }
    func_0218683C(positions);
    func_02186804(npcData);
    return headers;
}

u16 func_021869AC(const WfbcDailyState *dailyState)
{
    return dailyState->counter;
}

void func_021869B0(WfbcDailyState *dailyState)
{
    dailyState->counter++;
}

u16 func_021869B8(const WfbcDailyState *dailyState)
{
    return dailyState->value;
}

void func_021869BC(WfbcDailyState *dailyState)
{
    if (dailyState->value < 0x2710)
        dailyState->value += 10;
}

u16 func_021869D0(const WfbcDailyState *dailyState)
{
    return dailyState->value;
}

void func_021869D4(WfbcDailyState *dailyState, u16 value)
{
    dailyState->value = value;
}

u16 func_021869D8(const WfbcDailyState *dailyState)
{
    return dailyState->counter;
}

void func_021869DC(WfbcDailyState *dailyState, u16 counter)
{
    dailyState->counter = counter;
}

WfbcNpcRecord *func_021869E0(const WfbcData *data, int limit, WfbcNpcData *npcData, int *outNpcId)
{
    WfbcNpcRecord *npcRecord;
    int i;
    u32 weightSum;
    int npcId;

    weightSum = 0;
    npcRecord = func_0218682C(npcData);
    for (i = 0; i < 30; i++) {
        npcId = func_02186A2C(data, i);
        func_02186818(npcData, npcId);
        weightSum += npcRecord->weight;
        if (weightSum > limit) {
            *outNpcId = npcId;
            return npcRecord;
        }
    }
    return npcRecord;
}

int func_02186A2C(const WfbcData *data, int nth) { int i; int count; count = 0; for (i = 0; i < 30; i++) { if (func_02186A58(data, i) == 0) { if (count == nth) return i; count++; } } return 0; }

int func_02186A58(const WfbcData *data, int npcId)
{
    int i;
    const WfbcPerson *backPeople;
    const WfbcPerson *people;

    i = 0;
    people = data->people;
    for (; i < 10; i++) {
        if (func_02161ECC(&people[i]) != 0 && data->people[i].npcId == npcId)
            return 1;
    }
    i = 0;
    backPeople = data->backPeople;
    for (; i < 10; i++) {
        if (func_02161ECC(&backPeople[i]) != 0 && data->backPeople[i].npcId == npcId)
            return 1;
    }
    return 0;
}

void func_02186AC8(WfbcData *data, const struct MyStatus *myStatus, WfbcPerson *person, int setParent)
{
    WfbcPerson *front;

    if (func_02186B08(data->people) == 1) {
        func_02186B2C(data->backPeople, &data->people[9]);
        func_02161E78(&data->people[9]);
    }
    front = data->people;
    front = func_02186B2C(front, person);
    if (setParent != 0)
        func_0218677C(front, myStatus);
}

int func_02186B08(const WfbcPerson *list) { int i; for (i = 0; i < 10; i++) { if (func_02161ECC(&list[i]) == 0) return 0; } return 1; }

/*
 * Lever: unsigned index scaling retains separate source/destination multiplies.
 */
WfbcPerson *func_02186B2C(WfbcPerson *list, const WfbcPerson *person) { int i; for (i = 9; i > 0; i--) func_02082D44(&list[(u32)(i - 1)], &list[(u32)i], 24); func_02082D44(person, list, 24); return list; }

WfbcPerson *func_02186B60(WfbcPerson *list)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (func_02161ECC(&list[i]) == 0)
            return &list[i];
    }
    return list;
}

/*
 * lever: assign the low bitfield before the byte fields; a later bitfield store changes scheduling.
 */
void func_02186B84(WfbcPerson *person, int npcId, const struct MyStatus *myStatus, int mood, int setParent)
{
    person->isPresent = 1;
    person->npcId = npcId;
    person->flags.all = 7;
    person->mood = mood;
    if (setParent) func_0218677C(person, myStatus);
}

/*
 * extent: two trailing zero alignment bytes.
 */
int func_02186BA8(const WfbcPerson *person)
{
    if (person->mood == 0) return 1;
    return 0;
}

int func_02186BB8(WfbcPerson *person, int delta)
{
    int reachedZero;
    int sum;
    reachedZero = 0;
    sum = person->mood + delta;
    if (sum > 100) person->mood = 100;
    else if (sum < 0) { person->mood = 0; reachedZero = 1; }
    else person->mood += (u8)delta;
    return reachedZero;
}

void func_02186BE0(WfbcPerson *person, int mood)
{
    person->mood = mood;
}

int func_02186BE4(ScriptVm *vm, struct ScrcmdWork *work)
{
    ScriptFieldParam *fieldParam;
    FieldWfbc *wfbc;
    void *player;
    void *mmdlSystem;
    int personIndex;
    GridCoord frontGrid[3];

    fieldParam = func_02158F58(func_0215A5F4(work));
    wfbc = func_0218DC70(func_02188C98(fieldParam->fieldSystem));
    player = func_02188CB4(fieldParam->fieldSystem);
    mmdlSystem = func_02188C7C(fieldParam->fieldSystem);
    func_021A3460(player, &frontGrid[2], &frontGrid[1], &frontGrid[0]);
    personIndex = func_02186090(func_0216DDC0(mmdlSystem, frontGrid[2], frontGrid[0], 0));
    func_02193B40(wfbc, personIndex);
    return 0;
}

int func_02186C44(ScriptVm *vm, struct ScrcmdWork *work)
{
    ScriptFieldParam *fieldParam;
    FieldWfbc *wfbc;
    WfbcDailyState *dailyState;
    void *player;
    void *mmdlSystem;
    int personIndex;
    GridCoord frontGrid[3];

    fieldParam = func_02158F58(func_0215A5F4(work));
    wfbc = func_0218DC70(func_02188C98(fieldParam->fieldSystem));
    dailyState = func_020127F0(func_0215A5E4(work));
    player = func_02188CB4(fieldParam->fieldSystem);
    mmdlSystem = func_02188C7C(fieldParam->fieldSystem);
    func_021A3460(player, &frontGrid[2], &frontGrid[1], &frontGrid[0]);
    personIndex = func_02186090(func_0216DDC0(mmdlSystem, frontGrid[2], frontGrid[0], 0));
    if (func_02193BE4(wfbc, personIndex) != 0) {
        func_02193BC4(wfbc, personIndex);
        func_021869B0(dailyState);
    }
    return 0;
}

int func_02186CC4(ScriptVm *vm, struct ScrcmdWork *work)
{
    ScriptWork *scriptWork;
    ScriptFieldParam *fieldParam;
    FieldWfbc *wfbc;
    void *player;
    void *mmdlSystem;
    void *wordSet;
    int bufIndex;
    int heapId;
    GridCoord frontGrid[3];

    scriptWork = func_0215A5F4(work);
    fieldParam = func_02158F58(scriptWork);
    wfbc = func_0218DC70(func_02188C98(fieldParam->fieldSystem));
    player = func_02188CB4(fieldParam->fieldSystem);
    mmdlSystem = func_02188C7C(fieldParam->fieldSystem);
    wordSet = func_02158F74(scriptWork);
    bufIndex = func_02159B10(vm, work);
    heapId = func_0215A5CC(work);
    func_021A3460(player, &frontGrid[2], &frontGrid[1], &frontGrid[0]);
    func_02193B68(wfbc, wordSet, func_02186090(func_0216DDC0(mmdlSystem, frontGrid[2], frontGrid[0], 0)), bufIndex, heapId);
    return 0;
}

int func_02186D48(ScriptVm *vm, struct ScrcmdWork *work)
{
    int personIndex;
    int mmdlId;
    WfbcPerson *person;
    WfbcNpcRecord *npcRecord;
    FieldWfbcPeople *fieldPerson;
    struct Mmdl *personMmdl;
    FieldWfbc *wfbc;
    struct GameData *gameData;
    WfbcData *data;
    void *player;
    void *mmdlSystem;
    WfbcDailyState *dailyState;
    int query;
    u16 *result;
    ScriptWork *scriptWork;
    ScriptFieldParam *fieldParam;
    GridCoord frontGrid[3];

    scriptWork = func_0215A5F4(work);
    gameData = func_0215A5E4(work);
    data = func_020127C4(gameData);
    query = func_02159B10(vm, work);
    result = func_02159AE8(vm, work);
    if (query == 3) {
        *result = func_02186278(data, 0);
    } else {
    fieldParam = func_02158F58(scriptWork);
    wfbc = func_0218DC70(func_02188C98(fieldParam->fieldSystem));
    player = func_02188CB4(fieldParam->fieldSystem);
    mmdlSystem = func_02188C7C(fieldParam->fieldSystem);
    dailyState = func_020127F0(gameData);
    func_021A3460(player, &frontGrid[2], &frontGrid[1], &frontGrid[0]);
    personMmdl = func_0216DDC0(mmdlSystem, frontGrid[2], frontGrid[0], 0);
    if (personMmdl != 0) {
        personIndex = func_02186090(personMmdl);
        mmdlId = func_0216D588(personMmdl);
        func_02193904(wfbc);
        fieldPerson = func_0219390C(wfbc, personIndex);
        if (fieldPerson != 0) {
            npcRecord = func_02193C00(fieldPerson);
            person = func_02193C04(fieldPerson);
        }
    }
    switch (query) {
    case 0:
        *result = npcRecord->queryValue;
        break;
    case 1:
        *result = func_021867B4(person);
        break;
    case 2:
        *result = func_021867A8(person);
        break;
    case 3:
        break;
    case 4:
        *result = func_021869AC(dailyState);
        break;
    case 5:
        *result = func_021869B8(dailyState);
        break;
    case 6:
        if (func_021938F4(wfbc) == 0)
            *result = 0;
        else
            *result = 1;
        break;
    case 7:
        *result = func_021869D8(dailyState);
        break;
    case 8:
        *result = func_021869D0(dailyState);
        break;
    case 9:
        *result = personIndex;
        break;
    case 10:
        *result = func_02193BE4(wfbc, personIndex);
        break;
    case 11:
        *result = mmdlId;
        break;
    }
    }
    return 0;
}

/*
 * extent: two trailing zero alignment bytes.
 * interface: 020127F0's body loads only r0, forwarding r0 through 0200A864/0200A898.
 */
int func_02186E94(ScriptVm *vm, struct ScrcmdWork *work)
{
    func_021869BC(func_020127F0(func_020120F4(func_02188C80(func_02158F58(func_0215A5F4(work))->fieldSystem))));
    return 0;
}

int func_02186EB8(ScriptVm *vm, struct ScrcmdWork *work)
{
    void *s;
    void *w;
    void *b;
    u16 *f0;
    u16 *f1;
    u16 *f2;
    u32 n;
    int key;
    int d[4];
    u32 i;
    void *e;
    int v5, v92, v93, v94, v96, v4c, v8f, v90, v91;

    (void *)func_0215A5F4((struct ScrcmdWork *)(((void *)work)));
    s = (void *)func_0215A5E4((struct ScrcmdWork *)(((void *)work)));
    (u8 *)func_020127C4((struct GameData *)(s));
    w = (void *)(int)func_020127F0((struct GameData *)((int)s));
    b = func_02012934(s);
    f0 = func_02159AE8((ScriptVm *)(((void *)vm)), (struct ScrcmdWork *)(((void *)work)));
    f1 = func_02159AE8((ScriptVm *)(((void *)vm)), (struct ScrcmdWork *)(((void *)work)));
    f2 = func_02159AE8((ScriptVm *)(((void *)vm)), (struct ScrcmdWork *)(((void *)work)));
    n = func_0201AA18(b);
    key = func_021869D0((const WfbcDailyState *)(w));
    func_0203F4E4((struct RtcDate *)d);
    *f0 = 0;
    *f1 = 0;
    *f2 = 0xFFFF;
    for (i = 0; i < n; i++) {
        e = func_0201AB28(b, i);
        v5 = func_02017E1C(e, 5, 0);
        v92 = func_02017E1C(e, 0x92, 0);
        v93 = func_02017E1C(e, 0x93, 0);
        v94 = func_02017E1C(e, 0x94, 0);
        v96 = func_02017E1C(e, 0x96, 0);
        v4c = func_02017E1C(e, 0x4c, 0);
        v8f = func_02017E1C(e, 0x8f, 0);
        v90 = func_02017E1C(e, 0x90, 0);
        v91 = func_02017E1C(e, 0x91, 0);
        if (v5 == key && v4c == 0 && v96 == 0x33 && v8f + v91 + v90 == 0) {
            *f0 = 1;
            if (*f2 == 0xFFFF)
                *f2 = i;
            if (v92 == d[0] && v93 == d[1] && v94 == d[2]) {
                *f1 = 1;
                *f2 = i;
            }
        }
    }
    return 0;
}

int func_02187000(ScriptVm *vm, struct ScrcmdWork *work)
{
    ScriptWork *scriptWork;
    ScriptFieldParam *fieldParam;
    FieldWfbc *wfbc;
    void *player;
    void *mmdlSystem;
    u16 *result;
    int messageOffset;
    int personIndex;
    GridCoord frontGrid[3];

    scriptWork = func_0215A5F4(work);
    fieldParam = func_02158F58(scriptWork);
    wfbc = func_0218DC70(func_02188C98(fieldParam->fieldSystem));
    player = func_02188CB4(fieldParam->fieldSystem);
    mmdlSystem = func_02188C7C(fieldParam->fieldSystem);
    func_02158F74(scriptWork);
    result = func_02159AE8(vm, work);
    messageOffset = func_02159B10(vm, work);
    func_021A3460(player, &frontGrid[2], &frontGrid[1], &frontGrid[0]);
    personIndex = func_02186090(func_0216DDC0(mmdlSystem, frontGrid[2], frontGrid[0], 0));
    messageOffset = (u16)(messageOffset - 1);
    if (func_0219391C(wfbc) == 0)
        *result = messageOffset + (personIndex * 4 + 1);
    else
        *result = messageOffset + (personIndex * 4 + 9);
    return 0;
}

int func_02187098(ScriptVm *vm, struct ScrcmdWork *work)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    scriptWork = func_0215A5F4(work);
    gameSystem = func_0215A5DC(work);
    func_0215897C(scriptWork, func_021870C4(gameSystem, func_0201210C(gameSystem)));
    return 1;
}

struct GameEvent *func_021870C4(struct GameSystem *gameSystem, void *fieldSystem)
{
    int heapId;
    int msgBgSys;
    struct GameData *gameData;
    void *returnList;
    struct GameEvent *event;
    void *player;
    GridCoord frontGrid[3];
    WfbcTalkEvent *work;
    FieldWfbc *wfbc;
    void *mmdlSystem;
    struct Mmdl *personMmdl;
    int personIndex;
    FieldWfbcPeople *personRecord;

    heapId = func_02188C84(fieldSystem);
    msgBgSys = func_02188C54(fieldSystem);
    gameData = func_020120F4(gameSystem);
    returnList = func_02158344(func_02012138(gameSystem));
    if (returnList == 0)
        return 0;
    returnList = func_02158434(returnList);
    event = func_020122C0(gameSystem, 0, func_021871F8, 0x58);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldSystem = fieldSystem;
    work->msgBuf = func_020457B0(0x100, heapId);
    work->tmpBuf = func_020457B0(0x100, heapId);
    work->msgData = func_02045B38(0, 3, 0x142, heapId);
    work->wordSet = func_0201EC64(heapId);
    work->msgBgSys = msgBgSys;
    work->returnList = returnList;
    work->firstTalk = 1;
    work->heapId = (heapId & 0x7FFF) | 0x8000;
    work->ownData = func_020127D0(gameData, 1);
    work->cityData = func_020127D0(gameData, 0);
    wfbc = func_0218DC70(func_02188C98(fieldSystem));
    player = func_02188CB4(fieldSystem);
    mmdlSystem = func_02188C7C(fieldSystem);
    func_020127F0(func_020120F4(gameSystem));
    func_021A3460(player, &frontGrid[2], &frontGrid[1], &frontGrid[0]);
    personMmdl = func_0216DDC0(mmdlSystem, frontGrid[2], frontGrid[0], 0);
    func_0216D88C(personMmdl, (struct VecFx32 *)work->playerPos);
    personIndex = func_02186090(personMmdl);
    personRecord = func_0219390C(wfbc, personIndex);
    work->wfbcRuntime = wfbc;
    work->personRecord = personRecord;
    work->personMmdl = personMmdl;
    work->personIndex = personIndex;
    return event;
}

/*
 * The step callback func_021870C4 registers (func_020122C0's third
 * argument) for the 0x58-byte work block it fills.
 */
int func_021871F8(struct GameEvent *event, int *state, WfbcTalkEvent *talk)
{
    if (func_02158344(func_02012138(talk->gameSystem)) == 0 && talk->firstTalk != 0)
        *state = 0x11;

    switch (*state) {
    case 0:
        func_021620A0(talk->returnList);
        func_02162048(talk->returnList, talk->personIndex, 0);
        *state = 1;
        break;
    case 1:
        if (func_0216208C(talk->returnList, talk->personIndex) == 0)
            break;
        if (func_0216209C(talk->returnList) == 0)
            *state = 3;
        else
            *state = 2;
        break;
    case 2:
        func_0218741C(talk, 0, state, 0x11);
        break;
    case 3:
        if (talk->ownData->cityType != talk->cityData->cityType)
            *state = 5;
        else
            *state = 4;
        break;
    case 4:
        func_0218741C(talk, 1, state, 0x11);
        break;
    case 5:
        if ((unsigned int)func_02186278(talk->ownData, 0) >= 10) {
            *state = 6;
            break;
        }
        if (func_02161E4C(talk->ownData, talk->personIndex, 2) != 0)
            *state = 6;
        else
            *state = 7;
        break;
    case 6:
        func_0218741C(talk, 2, state, 0x11);
        break;
    case 7:
        func_0218748C(talk, 3, state, 9, 8);
        break;
    case 8:
        func_0218741C(talk, 4, state, 0x11);
        break;
    case 9:
        func_021620A0(talk->returnList);
        func_02162048(talk->returnList, talk->personIndex, 1);
        *state = 10;
        break;
    case 10:
        if (func_0216208C(talk->returnList, talk->personIndex) == 0)
            break;
        if (func_0216209C(talk->returnList) == 2)
            *state = 12;
        else
            *state = 11;
        break;
    case 11:
        talk->firstTalk = 0;
        func_0218741C(talk, 5, state, 0x11);
        break;
    case 12:
        func_0218741C(talk, 7, state, 0xd);
        func_021620A0(talk->returnList);
        func_02162048(talk->returnList, talk->personIndex, 2);
        talk->firstTalk = 0;
        break;
    case 13:
        func_0204E720(1, 0, 0x10, 0);
        *state = 14;
        break;
    case 14:
        if (func_0204E804() != 0)
            break;
        func_02161F90(talk->returnList, talk->ownData, talk->cityData, func_02012944(func_020120F4(talk->gameSystem)), talk->personIndex, talk->heapId);
        func_02193B20(talk->wfbcRuntime, talk->personIndex);
        func_0216CF2C(talk->personMmdl);
        func_0204E720(1, 0x10, 0, 0);
        *state = 15;
        break;
    case 15:
        if (func_0204E804() != 0)
            break;
        *state = 0x11;
        break;
    case 16:
        if (func_02187508(talk) == 0)
            break;
        if (talk->answerYes)
            *state = talk->yesState;
        else
            *state = talk->noState;
        break;
    case 17:
        if (func_021875B8(talk) == 0)
            break;
        func_02045808(talk->msgBuf);
        func_02045808(talk->tmpBuf);
        func_02045C04(talk->msgData);
        func_0201ED04(talk->wordSet);
        return 1;
    }
    return 0;
}

void func_0218741C(WfbcTalkEvent *talk, int messageSlot, int *state, int nextState)
{
    int zero;

    func_02045CAC(talk->msgData,
                  (u16)(messageSlot + (d_02187E04[talk->cityData->cityType] + talk->personIndex * 8)),
                  talk->tmpBuf);
    func_0201F250(talk->wordSet, talk->msgBuf, talk->tmpBuf);
    zero = 0;
    talk->msgHandle = func_0219129C(talk->msgBgSys, 2, talk->playerPos, talk->msgBuf, zero, zero);
    *state = 0x10;
    talk->yesState = nextState;
    talk->msgState = 0;
    talk->answerYes = 1;
    talk->askYesNo = 0;
}

void func_0218748C(WfbcTalkEvent *talk, int messageSlot, int *state, int yesStateId, u16 noStateId)
{
    int zero;

    func_02045CAC(talk->msgData,
                  (u16)(messageSlot + (d_02187E04[talk->cityData->cityType] + talk->personIndex * 8)),
                  talk->tmpBuf);
    func_0201F250(talk->wordSet, talk->msgBuf, talk->tmpBuf);
    zero = 0;
    talk->msgHandle = func_0219129C(talk->msgBgSys, 2, talk->playerPos, talk->msgBuf, zero, zero);
    *state = 0x10;
    talk->yesState = yesStateId;
    talk->noState = noStateId;
    talk->msgState = 0;
    talk->answerYes = 1;
    talk->askYesNo = 1;
}

int func_02187508(WfbcTalkEvent *talk)
{
    int answer;

    switch (talk->msgState) {
    case 0:
        if (func_02191388(talk->msgHandle) == 0)
            break;
        talk->msgState = talk->msgState + 1;
        break;
    case 1:
        if ((func_020362DC() & 0xf3) == 0)
            break;
        if (talk->askYesNo == 0)
            talk->msgState = 4;
        else
            talk->msgState = 2;
        break;
    case 2:
        talk->yesNoHandle = func_02190BE4(talk->msgBgSys, 0);
        talk->msgState = talk->msgState + 1;
        break;
    case 3:
        answer = func_02190C78(talk->yesNoHandle);
        if (answer == 2)
            break;
        if (answer == 0)
            talk->answerYes = 1;
        else
            talk->answerYes = 0;
        talk->msgState = 4;
        func_021909BC(talk->yesNoHandle);
        talk->yesNoHandle = 0;
        break;
    case 4:
        func_021912D8(talk->msgHandle);
        talk->msgState = talk->msgState + 1;
        break;
    case 5:
        if (func_021912F8(talk->msgHandle) != 0) {
            talk->msgHandle = 0;
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * lever: duplicate the zero store in both arms to retain the original branch stub.
 * regargs: high r2/r3 rows are conservative SDK-depth flags in owner callee 0219131C.
 * interface: 0219131C forwards them to 02045808 -> 020307B0 only; 0203046C
 * overwrites r2/r3, while 02030164's 0202FBAC overwrites r2 and no path reads incoming r3.
 */
int func_021875B8(WfbcTalkEvent *talk)
{
    if (talk->msgHandle != 0) {
        if (talk->msgState == 5) {
            if (func_021912F8(talk->msgHandle) == 0) return 0;
            talk->msgHandle = 0;
        } else {
            func_0219131C(talk->msgHandle);
            talk->msgHandle = 0;
        }
    }
    if (talk->yesNoHandle != 0) {
        func_021909BC(talk->yesNoHandle);
        talk->yesNoHandle = 0;
    }
    return 1;
}
