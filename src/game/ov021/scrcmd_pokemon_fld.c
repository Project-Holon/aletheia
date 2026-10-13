/*
 * file:     scrcmd_pokemon_fld.c
 * unit:     yes
 * function: func_021B5B4C, func_021B5B8C, func_021B5BFC, func_021B5C80, func_021B5CE8, func_021B5DD0, func_021B5DF8, func_021B5EB8, func_021B5F24, func_021B5FB4, func_021B5FB8, func_021B6048, func_021B60F4, func_021B6124, func_021B6164, func_021B61E8, func_021B627C, func_021B62C8, func_021B631C, func_021B636C, func_021B63D4, func_021B647C, func_021B654C, func_021B6590, func_021B65D8, func_021B6628, func_021B66B8, func_021B6708, func_021B6850, func_021B6904, func_021B6934, func_021B69B0, func_021B69D8, func_021B6A78, func_021B6AA4, func_021B6AAC, func_021B6AB0, func_021B6AE0, func_021B6AFC, func_021B6B6C, func_021B6BDC, func_021B6D0C, func_021B6D30, func_021B6D64, func_021B6D98, func_021B6DC0, func_021B6DE4, func_021B6E0C, func_021B6E24, func_021B6E68, func_021B6EB0, func_021B6EE0, func_021B6F00, func_021B6F18, func_021B6F5C, func_021B6F88, func_021B6FE8, func_021B6FEC, func_021B6FF0, func_021B7020, func_021B7038, func_021B7068, func_021B707C, func_021B7080, func_021B7098, func_021B709C, func_021B70D4, func_021B70D8, func_021B716C, func_021B721C, func_021B72CC, func_021B7364, func_021B7390, func_021B73B8
 * address:  0x021B5B4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Takes the mystery gift kind handlers 021B6D0C..021B72CC (unit_021B6D0C.c, unit_021B6D30.c, unit_021B6D64.c, unit_021B6DC0.c) and the first three script commands of pdw_postman.c, 021B7364..021B73B8 (lane FXC3).
 * Split from scrcmd_c03center.c at 0x021B5B4C (lane FXC2, CL133: party and Pokemon script commands; the pokemon_fld.c file string d_021DE270 is first used by 021B6708; the cut address is the first command after the c03center camera turn).
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A07C  0x0215A07C  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_02012F08  0x02012F08  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200C11C  0x0200C11C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0200C2B0  0x0200C2B0  thumb
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0200C2D0  0x0200C2D0  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200CF08  0x0200CF08  thumb
 *   func_0200D298  0x0200D298  thumb
 *   func_0200D0F8  0x0200D0F8  thumb
 *   func_0200D2C4  0x0200D2C4  thumb
 *   func_0200CF54  0x0200CF54  thumb
 *   func_0200D2B0  0x0200D2B0  thumb
 *   d_021D98DC     0x021D98DC  data  a4
 *   d_021D9904     0x021D9904  data  a4
 *   d_021D992C     0x021D992C  data  a4
 *   func_0201891C  0x0201891C  thumb
 *   func_0215B500  0x0215B500  thumb  ov010
 *   func_0215A0E8  0x0215A0E8  thumb  ov010
 *   func_0202130C  0x0202130C  thumb
 *   func_020188AC  0x020188AC  thumb
 *   func_02018790  0x02018790  thumb
 *   func_021C5AAC  0x021C5AAC  thumb  ov021
 *   func_0215A2E4  0x0215A2E4  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02166C4C  0x02166C4C  thumb  ov010
 *   func_021CBFB0  0x021CBFB0  thumb  ov021
 *   func_021CC040  0x021CC040  thumb  ov021
 *   func_021CC060  0x021CC060  thumb  ov021
 *   func_021CC068  0x021CC068  thumb  ov021
 *   func_021CC500  0x021CC500  thumb  ov021
 *   func_0201292C  0x0201292C  thumb
 *   func_02007FA0  0x02007FA0  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_020081DC  0x020081DC  thumb
 *   func_020212B0  0x020212B0  thumb
 *   func_02012FD8  0x02012FD8  thumb
 *   func_0200E7BC  0x0200E7BC  thumb
 *   func_02158F7C  0x02158F7C  thumb ov010
 *   func_0200E740  0x0200E740  thumb
 *   func_0200E7AC  0x0200E7AC  thumb
 *   func_02045A98  0x02045A98  arm
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0202136C  0x0202136C  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_02009020  0x02009020  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_02008EAC  0x02008EAC  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017988  0x02017988  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02007A18  0x02007A18  thumb
 *   func_0201747C  0x0201747C  thumb
 *   func_0201AB48  0x0201AB48  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_020075B0  0x020075B0  thumb
 *   d_021DE270     0x021DE270  data   ov021  a1
 *   func_02007698  0x02007698  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020079BC  0x020079BC  thumb
 *   func_0201AB8C  0x0201AB8C  thumb
 *   func_02158F58  0x02158F58  thumb ov010
 *   func_02188D24  0x02188D24  thumb ov021
 *   func_021BB990  0x021BB990  thumb ov021
 *   ov055_id       0x00000037  data  a1
 *   d_021F45F0     0x021F45F0  data  ov055  a4
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   func_021690A4  0x021690A4  thumb  ov010
 *   func_02087C88  0x02087C88  arm
 *   func_0200A940  0x0200A940  thumb
 *   func_0200A8F8  0x0200A8F8  thumb
 *   func_0200A8C8  0x0200A8C8  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_0200A8AC  0x0200A8AC  thumb
 *   func_0201134C  0x0201134C  thumb
 *   func_0215A6D0  0x0215A6D0  thumb ov010
 *   func_0215A6C4  0x0215A6C4  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_0215A5D0  0x0215A5D0  thumb  ov010
 *   func_0215A7F0  0x0215A7F0  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_021854B0  0x021854B0  thumb  ov020
 *   func_0200A300  0x0200A300  thumb
 *   func_0200A338  0x0200A338  thumb
 *   func_021B7834  0x021B7834  thumb  ov021
 *   func_021B7864  0x021B7864  thumb  ov021
 *   func_021B785C  0x021B785C  thumb  ov021
 *   func_021B6D0C  0x021B6D0C  thumb  ov021
 *   func_021B6D30  0x021B6D30  thumb  ov021
 *   func_021B6D64  0x021B6D64  thumb  ov021
 *   func_021B6D98  0x021B6D98  thumb  ov021
 *   func_021B6DC0  0x021B6DC0  thumb  ov021
 *   func_021B6DE4  0x021B6DE4  thumb  ov021
 *   func_021B6E0C  0x021B6E0C  thumb  ov021
 *   func_021B6EB0  0x021B6EB0  thumb  ov021
 *   func_0216BF74  0x0216BF74  thumb  ov010
 *   d_021D9970     0x021D9970  data   ov021  a4
 *   func_0216D588  0x0216D588  thumb ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_02162744  0x02162744  thumb  ov010
 *   func_02157E9C  0x02157E9C  thumb  ov010
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EEC4  0x0201EEC4  thumb
 *   func_0201EED4  0x0201EED4  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF18  0x0200BF18  thumb
 *   func_0201F184  0x0201F184  thumb
 *   func_0204A298  0x0204A298  arm
 *   d_021D99D0     0x021D99D0  data   ov021  a1
 *   func_02007F68  0x02007F68  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_0200C278  0x0200C278  thumb
 *   d_021D99E8     0x021D99E8  data  a2
 *   d_021D99D4     0x021D99D4  data  a2
 *   func_021690D0  0x021690D0  thumb  ov010
 *   func_021690E0  0x021690E0  thumb  ov010
 *   d_021D99DE     0x021D99DE  data   ov021  a1
 */
#include "../arm9/script_vm_types.h"
#include "../ov010/fldmmdl_types.h"
#include "../ov010/script_work_types.h"
#include "scrcmd_pokemon_fld_types.h"

struct ScrcmdWork;
struct GameSystem;
struct GameData;
struct MiscSave;
struct WordSet;
struct ZukanSave;
struct FldTrade;
struct StoredNames;
struct Strbuf;
struct Party;
struct PartyMon;
struct BoxMon;
struct Mail;
struct MyStatus;
struct MysteryData;
struct MysteryDataEntry;
struct OSOwnerInfo;
struct FieldMap;
struct EventDataSystem;
struct PokemonParam;
struct MyItem;
struct IntrudeSave;
struct SaveControl;
struct PlayerWork;
struct ZukanWork;

/* One row of a count to value table; a row with limit 0 ends the table. */
typedef struct ThresholdEntry {
    u16 limit;
    u16 value;
} ThresholdEntry;

typedef signed int     s32;

/* Owner information from the firmware user settings (OS owner info). */
typedef struct OwnerInfo {
    u8 language;
    u8 color;
    u8 birthMonth;
    u8 birthDay;
    u8 nameAndComment[0x50];
} OwnerInfo;

typedef struct { int x, y, z; } Vec3;

/* One entry of a warp list placed in the script data (10 bytes); the first halfword 0xFFFF ends the list. */
typedef struct WarpEntry {
    u16 labelId;      /* 0x00: menu label message id */
    u16 mapId;        /* 0x02 */
    u16 gridX;        /* 0x04 */
    u16 gridY;        /* 0x06 */
    u16 gridZ;        /* 0x08 */
} WarpEntry;

typedef struct ScrcmdWork ScrcmdWork;

/* One row (8 bytes) of a key to value table loaded from an archive. */
typedef struct ScrcmdKeyValueEntry {
    u32 key;
    u32 value;
} ScrcmdKeyValueEntry;

#define SCRCMD_TABLE_ARC_ID          0xD0
#define SCRCMD_DELIVERY_OBJ_CODE     0x46
#define SCRCMD_HEAP_FLAG_TAIL        0x8000   /* allocate from the tail of the heap */

extern ScriptWork *func_0215A5F4(ScrcmdWork *work);
extern void *func_0215A5DC(void *a0);
extern struct GameData *func_0215A5E4(void *work);
extern u16 func_02159B10(void *, void *);
extern void *func_0201210C(const struct GameSystem *p);
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u16 *func_02159AE8(void *core, void *work);
extern void *func_0215A07C(int a, u16 *b, u16 *c);
extern void func_0215897C(void *vm, void *task);
extern int func_0215B4AC(void *a0, unsigned int a1, void **out);
extern struct MiscSave *func_02012F08(struct GameData *gameData);
extern u32 func_02017E1C(struct PokemonParam *mon, u32 paramId, u32 arg);
extern void func_0200C11C(struct MiscSave *p, u16 a, u32 b, u32 c, u32 d);
extern struct Party *func_02012934(const struct GameData *gameData);
extern int func_0201AA18(const struct Party *party);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_0200C2B0(struct MiscSave *p, u32 i, const u16 *src);
extern struct WordSet *func_02158F74(ScriptWork *scriptWork);
extern void func_0200C2D0(struct MiscSave *p, u32 i, u16 *dest);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern u16 func_0215A5CC(ScrcmdWork *work);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA38(struct ZukanSave *p);
extern u16 func_0200CF08(struct ZukanSave *p, u32 heap);
extern int func_0200D298(void *a0);
extern u16 func_0200D0F8(struct ZukanSave *p, u32 heap);
extern int func_0200D2C4(void *p, unsigned int heap);
extern u16 func_0200CF54(struct ZukanSave *p, u32 heap);
extern int func_0200D2B0(void *a0, int a1);
extern u32 func_0201891C(void *p, s32 v);
extern int func_0215B500(int a0, int a1);
extern void *func_0215A0E8(void *t, u16 *o1, u16 *o2, u8 c, u32 v);
extern u32 func_0202130C(u32 id);
extern u32 func_020188AC(void *p, int v);
extern u32 func_02018790(void *p);
extern int func_021C5AAC(void *a, int b, int c, int d);
extern int func_0215A2E4(int a, int b, int c, int d, int e, int f, unsigned short g);
extern void *func_020120F4(const struct GameSystem *p);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern void *func_02166C4C(void *a, void *b, void *c);
extern struct FldTrade *func_021CBFB0(u32 a, u32 b);
extern void func_021CC040(struct FldTrade *o);
extern u32 func_021CC060(struct FldTrade *p);
extern u32 func_021CC068(struct FldTrade *p);
extern void *func_021CC500(void *a, u32 b, u32 c);
extern struct MyItem *func_0201292C(const struct GameData *gameData);
extern u32 func_02007FA0(u8 *base, u32 id);
extern u32 func_020056EC(u32);
extern u16 *func_020081DC(void *, int, u16);
extern u16 func_020212B0(u16);
extern void *func_02012FD8(void **p);
extern void func_0200E7BC(struct StoredNames *o, int idx, void *mon);
extern u32 func_02158F7C(u8 *p);
extern u32 func_0200E740(const void *obj, u32 idx);
extern void *func_0200E7AC(void *obj, u32 idx);
extern u16 func_02045A98(void);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern u32 func_0201293C(const struct GameData *p);
extern u32 func_020173EC(void);
extern void func_02082D44(void *src, void *dst, u32 n);
extern u32 func_0202136C(u16 v);
extern struct Mail *func_02008FEC(void *sys);
extern void *func_02008F08(int a0);
extern int func_02009020(void *obj, int v);
extern void func_0200903C(struct Mail *arr, u32 unused, int i, const struct Mail *src);
extern void func_02008EAC(struct Mail *obj);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017988(void *p, u32 a);
extern void func_020185C4(void *mon);
extern struct BoxMon *func_02007A18(void **save, u32 box, u32 slot);
extern void *func_0201747C(struct BoxMon *p, u32 heap);
extern void func_0201AB48(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *func_020185F0(void *mon);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct BoxMon *src);
extern int func_02007698(void);
extern u32 func_02008530(const struct MyStatus *obj);
extern int func_020079BC(void **save, u32 box, u32 slot, int field, int arg);
extern u32 func_0201AB8C(struct Party *p, u32 i, u32 j, u32 heap);
extern ScriptFieldParam *func_02158F58(ScriptWork *scriptWork);
extern u32 func_02188D24(u8 *p);
extern int *func_021BB990(int, int *, const int *);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern void *func_0200A8A0(void *);
extern void *func_021690A4(int a0);
extern void func_02087C88(struct OSOwnerInfo *info);
extern int func_0200A940(void *, int, int, void *);
extern u32 func_0200A8F8(struct MysteryData *r, u32 index);
extern struct MysteryDataEntry *func_0200A8C8(struct MysteryData *r, u32 index);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct Strbuf *vec);
extern s32 func_0200A8AC(struct MysteryData *r);
extern u32 func_0201134C(struct ScriptVm *p);
extern void func_0215A6D0(void *p, u32 v);
extern u32 func_0215A6C4(void *p);
extern u32 func_02158F78(u8 *p);
extern u16 func_0215A5D0(void *);
extern void func_0215A7F0(void *p, int a, int b, int c, struct Strbuf *s0, void *s1);
extern void *func_02158F54(void *);
extern int func_021854B0(void *, void *, int, Vec3 *, int);
extern void *func_0200A300(void *a0, void *a1, void *a2);
extern void func_0200A338(void *h);
extern void *func_021B7834(void *a, int *out, void *buf);
extern u8 func_021B7864(void *a);
extern void func_021B785C(u8 *p, u32 i);
int func_021B6D0C(int giftKind, struct ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int func_021B6D30(int giftKind, MysteryGiftCard *card, struct ScrcmdWork *work);
int func_021B6D64(int giftKind, MysteryGiftCard *card, struct ScrcmdWork *work);
int func_021B6D98(int giftKind, struct ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int func_021B6DC0(int giftKind, ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
u16 func_021B6DE4(struct FieldMap *fieldMap, struct GameData *gameData);
u16 func_021B6E0C(struct FieldMap *fieldMap);
int func_021B6EB0(MysteryGiftCard *card, int giftType);
extern void func_0216BF74(void *a, int i, void *b);
extern u16 func_0216D588(Mmdl *mmdl);
extern MmdlSys *func_02188C7C(struct FieldMap *fieldMap);
extern int func_0216DD1C(MmdlSys *mmdlSys, Mmdl **mmdlOut, u32 *iterator);
extern u16 func_0216D598(Mmdl *mmdl);
extern struct EventDataSystem *func_02012844(const struct GameData *gameData);
extern MmdlHeader *func_02162740(struct EventDataSystem *eventData);
extern u16 func_02162744(struct EventDataSystem *eventData);
extern struct PokemonParam *func_02157E9C(const MysteryGiftCard *card, u32 heapId, struct GameData *gameData);
extern u32 func_0201A98C(struct Party *party, const struct PokemonParam *mon);
extern void func_0200CDE0(struct ZukanWork *zukan, struct PokemonParam *mon);
extern void func_0201F02C(struct WordSet *wordSet, u32 bufferId, struct MyStatus *myStatus);
extern void func_0201EEC4(struct WordSet *wordSet, u32 bufferId, u32 value);
extern void func_0201EED4(struct WordSet *wordSet, u32 bufferId, struct PokemonParam *mon);
extern void func_02007E50(struct MyItem *bag, u32 itemId, int count, u32 heapId);
extern void func_0201EF40(struct WordSet *wordSet, u32 bufferId, u32 value);
extern struct IntrudeSave *func_0200BE48(struct SaveControl *save);
extern void func_0200BF18(struct IntrudeSave *intrude, s32 flagId);
extern void func_0201F184(struct WordSet *wordSet, u32 bufferId, s32 value);
extern int func_0204A298(int arcId, int memberId, int unused, u32 heapId, u32 *sizeOut);
extern int func_02007F68(struct MyItem *bag, u32 itemId, u32 count, u32 heapId);
extern void func_0201EFA4(struct WordSet *wordSet, u32 bufferId, u32 number, u32 digits, u32 dispType, u32 code);
extern struct PlayerWork *func_020127A4(struct GameData *gameData);
extern u32 func_0200C278(struct MiscSave *miscSave, u32 amount);
Mmdl *func_021B6E24(struct FieldMap *fieldMap);
int func_021B6E68(struct GameData *gameData);
struct PokemonParam *func_021B6EE0(ScrcmdWork *work, MysteryGiftCard *card);
int func_021B6F00(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
void func_021B6F18(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int func_021B6F5C(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int func_021B6F88(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int func_021B6FE8(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int func_021B6FEC(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
void func_021B6FF0(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int func_021B7020(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int func_021B7038(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int func_021B7068(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int func_021B707C(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
void func_021B7080(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int func_021B7098(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card);
int func_021B709C(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int func_021B70D4(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work);
int func_021B70D8(struct ScriptVm *vm, ScrcmdWork *work);
int func_021B716C(struct ScriptVm *vm, ScrcmdWork *work);
int func_021B721C(struct ScriptVm *vm, ScrcmdWork *work);
int func_021B72CC(struct ScriptVm *vm, ScrcmdWork *work);
extern const u8 d_021D99D0[];
extern int func_021690D0(struct GameData *gameData);
extern int func_021690E0(struct GameData *gameData);
int func_021B7364(void *core, void *work);
int func_021B7390(u32 month, int day);
int func_021B73B8(void *core, void *work);
extern const u16 d_021D99E8[];
extern const u16 d_021D99D4[];
extern const u8 d_021D99DE[];
int func_021B5B4C(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B5B8C(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B5BFC(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B5C80(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B5CE8(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 func_021B5DD0(ThresholdEntry *table, int count);
int func_021B5DF8(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B5EB8(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B5F24(void *mon, int tutorKind);
int func_021B5FB4(int tutorKind);
int func_021B5FB8(void *mon, int tutorKind);
int func_021B6048(struct ScriptVm *vm, struct ScrcmdWork *work, int tutorKind, u8 *eligibleMask, u32 checkFriendship);
int func_021B60F4(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B6124(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B6164(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B61E8(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B627C(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B62C8(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B631C(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B636C(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 func_021B63D4(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B647C(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 func_021B654C(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 func_021B6590(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 func_021B65D8(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B6628(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 func_021B66B8(struct ScriptVm *vm, struct ScrcmdWork *work);
void func_021B6708(struct ScrcmdWork *work, int partySlot);
int func_021B6850(void *gameData, u16 species, u16 *boxOut, u16 *slotOut);
void func_021B6904(struct ScrcmdWork *work);
int func_021B6934(void *gameData);
int func_021B69B0(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 func_021B69D8(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B6A78(struct ScriptVm *vm, struct ScrcmdWork *work);
WarpEntry *func_021B6AA4(WarpEntry *table, u32 index);
void func_021B6AAC(u16 *labelId);
int func_021B6AB0(WarpEntry *table);
int func_021B6AE0(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 func_021B6AFC(struct ScriptVm *vm, struct ScrcmdWork *work);
u32 func_021B6B6C(struct ScriptVm *vm, struct ScrcmdWork *work);
int func_021B6BDC(struct ScriptVm *vm, struct ScrcmdWork *work);
extern u16 d_021D98DC[];
extern u16 d_021D9904[];
extern u16 d_021D992C[];
extern u8 d_021DE270[];
extern u8 ov055_id[];
extern const int d_021F45F0[];

/* Script command: open the party select screen. */
int func_021B5B4C(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 *selectedSlotOut = func_02159AE8(vm, work);
    u16 *resultOut = func_02159AE8(vm, work);
    void *scriptWork;

    func_02159B10(vm, work);
    scriptWork = func_0215A5F4(work);
    func_0215897C(scriptWork, func_0215A07C((int)func_0215A5DC(work), selectedSlotOut, resultOut));
    return 1;
}

/*
 * Script command: store the species, form, egg flag and gender of a party
 * member in the record of the misc save.
 *
 * Addresses are Black-image addresses.
 */
int func_021B5B8C(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *mon;
    struct MiscSave *miscSave;
    u16 species, form, isEgg, gender;

    if (func_0215B4AC(work, func_02159B10(vm, work), &mon) == 1) {
        miscSave = func_02012F08(func_0215A5E4(work));
        species = func_02017E1C(mon, 5, 0);
        form = func_02017E1C(mon, 0x6f, 0);
        isEgg = func_02017E1C(mon, 0x4c, 0);
        gender = func_02017E1C(mon, 0x6e, 0);
        func_0200C11C(miscSave, species, form, isEgg, gender);
    }
    return 0;
}

/* Script command: store the species of the non-egg party members in a record slot. */
int func_021B5BFC(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 species[6];
    void *gameData;
    unsigned int recordSlot;
    void *party;
    void *mon;
    int i;
    int j;
    int count;

    gameData = func_0215A5E4(work);
    party = func_02012934(gameData);
    recordSlot = func_02159B10(vm, work);
    for (i = 0; i < 6; i++)
        species[i] = 0;
    for (j = 0, count = 0; j < (int)func_0201AA18(party); j++) {
        mon = func_0201AB28(party, j);
        if (func_02017E1C(mon, 0x4C, 0) == 0)
            species[count++] = func_02017E1C(mon, 5, 0);
    }
    func_0200C2B0(func_02012F08(gameData), recordSlot, species);
    return 0;
}

/* Script command: put the species names of a record slot in the word set; the count goes to the result variable. */
int func_021B5C80(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *gameData;
    struct WordSet *wordSet;
    unsigned int recordSlot;
    u16 *countOut;
    int i;
    int count;
    u16 species[6];

    gameData = func_0215A5E4(work);
    wordSet = func_02158F74(func_0215A5F4(work));
    recordSlot = func_02159B10(vm, work);
    countOut = func_02159AE8(vm, work);
    func_0200C2D0(func_02012F08(gameData), recordSlot, species);
    for (i = 0, count = 0; i < 6; i++) {
        if (species[i] != 0) {
            func_0201EE60(wordSet, count, species[i]);
            count++;
        }
    }
    *countOut = count;
    return 0;
}

/*
 * Script command: read the six individual values of a party member. The
 * request picks the sum, the highest value or one of the six values.
 */
int func_021B5CE8(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 ivs[6];
    void *mon;
    u32 partySlot;
    u32 request;
    u16 *resultOut;
    u16 sum;
    u16 highest;
    u32 i;

    partySlot = func_02159B10(vm, work);
    request = func_02159B10(vm, work);
    resultOut = func_02159AE8(vm, work);
    if (func_0215B4AC(work, partySlot, &mon) == 0) {
        *resultOut = 0;
        return 0;
    }
    sum = 0;
    ivs[0] = func_02017E1C(mon, 0x46, 0);
    ivs[1] = func_02017E1C(mon, 0x47, 0);
    ivs[2] = func_02017E1C(mon, 0x48, 0);
    ivs[3] = func_02017E1C(mon, 0x49, 0);
    ivs[4] = func_02017E1C(mon, 0x4a, 0);
    ivs[5] = func_02017E1C(mon, 0x4b, 0);
    highest = 0;
    for (i = 0; i < 6; i++) {
        sum += ivs[i];
        if (highest < ivs[i]) {
            highest = ivs[i];
        }
    }
    switch (request) {
    case 0:
        *resultOut = sum;
        break;
    case 1:
        *resultOut = highest;
        break;
    case 2:
        *resultOut = ivs[0];
        break;
    case 3:
        *resultOut = ivs[1];
        break;
    case 4:
        *resultOut = ivs[2];
        break;
    case 5:
        *resultOut = ivs[3];
        break;
    case 6:
        *resultOut = ivs[4];
        break;
    case 7:
        *resultOut = ivs[5];
        break;
    }
    return 0;
}

/*
 * Returns the value of the first row whose limit is at least count (or of
 * the row with limit 0 that ends the table).
 * Unlabelled leaf (saves no lr), called by func_021B5DF8.
 * Addresses are Black-image addresses.
 */
u32 func_021B5DD0(ThresholdEntry *table, int count)
{
    int i;
    u32 limit;

    for (i = 0; ; i++) {
        limit = table[i].limit;
        if (limit == 0)
            return table[i].value;
        if (count <= (int)limit)
            return table[i].value;
    }
}

/*
 * Script command: Pokedex rating for one of three Pokedex kinds. The first
 * result variable gets the rating row (a fixed value when the kind is
 * complete), the second the Pokedex count.
 *
 * Case blocks are in source order 3, 2, 1; per-case stores to *ratingOut but a
 * single *countOut store after the switch is what spills countOut (register
 * pressure) and gives ratingOut r4.
 *
 * Case 3 reads d_021D98DC and case 1 d_021D992C (pool words in that order);
 * the earlier draft had the two swapped, which only the relocation check saw.
 *
 * Addresses are Black-image addresses.
 */
int func_021B5DF8(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 dexKind;
    u16 *ratingOut;
    u16 *countOut;
    u32 heapId;
    struct ZukanSave *zukan;
    u32 count;

    dexKind = func_02159B10(vm, work);
    ratingOut = func_02159AE8(vm, work);
    countOut = func_02159AE8(vm, work);
    heapId = func_0215A5CC(work);
    zukan = func_0200CA1C(func_0215A5E4(work));
    func_0200CA38(zukan);
    *ratingOut = 5;
    *countOut = 0;
    switch (dexKind) {
    case 3:
        count = func_0200CF54(zukan, heapId);
        if (func_0200D2B0(zukan, heapId) == 1)
            *ratingOut = 0x1e;
        else
            *ratingOut = func_021B5DD0((ThresholdEntry *)d_021D98DC, count);
        break;
    case 2:
        count = func_0200D0F8(zukan, heapId);
        if (func_0200D2C4(zukan, heapId) == 1)
            *ratingOut = 0xd;
        else
            *ratingOut = func_021B5DD0((ThresholdEntry *)d_021D9904, count);
        break;
    case 1:
        count = func_0200CF08(zukan, heapId);
        if (func_0200D298(zukan) == 1)
            *ratingOut = 0x32;
        else
            *ratingOut = func_021B5DD0((ThresholdEntry *)d_021D992C, count);
        break;
    default:
        return 0;
    }
    *countOut = count;
    return 0;
}

/* Script command: check whether the Pokedex of one kind is complete. */
int func_021B5EB8(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    struct ZukanSave *zukan;
    void *fieldMap;
    u16 *completeOut;

    zukan = func_0200CA1C(func_0215A5E4(work));
    fieldMap = func_0201210C(func_0215A5DC(work));
    completeOut = func_02159AE8(vm, work);
    switch (func_02159B10(vm, work)) {
    case 1:
        *completeOut = func_0200D298(zukan);
        break;
    case 3:
        *completeOut = func_0200D2B0(zukan, func_02188C84(fieldMap));
        break;
    case 2:
        *completeOut = func_0200D2C4(zukan, func_02188C84(fieldMap));
        break;
    }
    return 0;
}

/*
 * Move that the tutor of a starter group teaches to a Pokemon. Kind 0 is
 * the dragon tutor, kind 1 the group of the three older starter types and
 * kind 2 the group of the Unova starters.
 */
int func_021B5F24(void *mon, int tutorKind)
{
    switch (tutorKind) {
    case 1:
        if (func_0201891C(mon, 3))
            return 0x152;
        if (func_0201891C(mon, 4))
            return 0x133;
        if (func_0201891C(mon, 5))
            return 0x134;
        break;
    case 0:
        return 0x1b2;
    case 2:
        if (func_0201891C(mon, 0))
            return 0x208;
        if (func_0201891C(mon, 1))
            return 0x207;
        if (func_0201891C(mon, 2))
            return 0x206;
        break;
    }
    return 0x133;
}

/*
 * Friendship that a Pokemon needs for the tutor of a kind.
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B5FB4(int tutorKind)
{
    return 255;
}

/* Whether a Pokemon belongs to a group that the tutor of a kind teaches. */
int func_021B5FB8(void *mon, int tutorKind)
{
    switch (tutorKind) {
    case 1:
        if (func_0201891C(mon, 3))
            return 1;
        if (func_0201891C(mon, 4))
            return 1;
        if (func_0201891C(mon, 5))
            return 1;
        return 0;
    case 0:
        if (func_0201891C(mon, 6))
            return 1;
        return 0;
    case 2:
        if (func_0201891C(mon, 0))
            return 1;
        if (func_0201891C(mon, 1))
            return 1;
        if (func_0201891C(mon, 2))
            return 1;
        return 0;
    }
    return 0;
}

/*
 * Finds the party members that the tutor of a kind can teach (eligibleMask
 * gets one bit per member; with checkFriendship only members with enough
 * friendship count). Returns 1 when no member is in the group, 2 when none
 * has the friendship, else 0.
 */
int func_021B6048(struct ScriptVm *vm, struct ScrcmdWork *work, int tutorKind, u8 *eligibleMask, u32 checkFriendship)
{
    void *party;
    int partyCount;
    int i;
    int anyInGroup;
    int anyEligible;
    void *mon;
    u32 friendship;

    party = func_02012934(func_0215A5E4(work));
    partyCount = func_0201AA18(party);
    anyInGroup = 0;
    anyEligible = 0;
    *eligibleMask = anyInGroup;
    for (i = 0; i < partyCount; i++) {
        mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, 0x4c, 0) == 1)
            continue;
        if (func_021B5FB8(mon, tutorKind) == 0)
            continue;
        anyInGroup = 1;
        if (checkFriendship != 0) {
            friendship = func_02017E1C(mon, 9, 0);
            if (friendship < func_021B5FB4(tutorKind))
                continue;
        }
        anyEligible = 1;
        *eligibleMask = *eligibleMask | (u8)(1 << i);
    }
    if (anyInGroup == 0)
        return 1;
    if (anyEligible == 0)
        return 2;
    return 0;
}

/* Script command: tutor availability of the party for a kind (0 ok, 1 no group member, 2 no friendship). */
int func_021B60F4(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 tutorKind;
    u16 *resultOut;
    u32 eligibleMask;

    tutorKind = func_02159B10(vm, work);
    resultOut = func_02159AE8(vm, work);
    *resultOut = func_021B6048(vm, work, tutorKind, (u8 *)(&eligibleMask), 1);
    return 0;
}

/* Script command: move that the tutor of a kind teaches to one party member (0 when there is no such member). */
int func_021B6124(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 tutorKind;
    u32 partySlot;
    u16 *moveOut;
    void *mon;
    int moveId;

    tutorKind = func_02159B10(vm, work);
    partySlot = func_02159B10(vm, work);
    moveOut = func_02159AE8(vm, work);
    if (func_0215B4AC(work, partySlot, &mon) == 1)
        moveId = func_021B5F24(mon, tutorKind);
    else
        moveId = 0;
    *moveOut = moveId;
    return 0;
}

/*
 * Script command: can a party member learn the tutor move of a kind?
 * Result 0 yes, 1 not in the group, 2 not enough friendship, 3 knows the
 * move already.
 */
int func_021B6164(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 tutorKind;
    u32 partySlot;
    u16 *resultOut;
    void *mon;

    tutorKind = func_02159B10(vm, work);
    partySlot = func_02159B10(vm, work);
    resultOut = func_02159AE8(vm, work);
    *resultOut = 1;
    if (func_0215B4AC(work, partySlot, &mon) == 0)
        return 0;
    if (func_021B5FB8(mon, tutorKind) == 0) {
        *resultOut = 1;
    } else if (func_0215B500((int)mon, func_021B5F24(mon, tutorKind)) == 1) {
        *resultOut = 3;
    } else if (func_02017E1C(mon, 9, 0) < func_021B5FB4(tutorKind)) {
        *resultOut = 2;
    } else {
        *resultOut = 0;
    }
    return 0;
}

/*
 * Script command: let the player pick a party member for the tutor of a
 * kind. Starts the party select event unless no member qualifies.
 */
int func_021B61E8(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 tutorKind;
    u16 *selectedSlotOut;
    u16 *resultOut;
    void *scriptWork;
    void *gameSystem;
    u32 displayMoveId;
    u8 eligibleMask;

    tutorKind = func_02159B10(vm, work);
    selectedSlotOut = func_02159AE8(vm, work);
    resultOut = func_02159AE8(vm, work);
    scriptWork = func_0215A5F4(work);
    gameSystem = func_0215A5DC(work);
    if (func_021B6048(vm, work, tutorKind, &eligibleMask, 0)) {
        *selectedSlotOut = 0;
    } else {
        switch (tutorKind) {
        case 1:
            displayMoveId = 0xfffe;
            break;
        case 2:
            displayMoveId = 0xfffd;
            break;
        case 0:
            displayMoveId = 0x1b2;
            break;
        default:
            displayMoveId = 0xa5;
            break;
        }
        func_0215897C(scriptWork, func_0215A0E8(gameSystem, selectedSlotOut, resultOut, eligibleMask, displayMoveId));
    }
    return 1;
}

/* Script command: does any party member have the flag of value 0x97 set? */
int func_021B627C(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 *foundOut;
    void *party;
    u32 partyCount;
    u32 i;

    foundOut = func_02159AE8(vm, work);
    *foundOut = 0;
    party = func_02012934(func_0215A5E4(work));
    partyCount = func_0201AA18(party);
    for (i = 0; i < partyCount; i++) {
        if (func_02017E1C(func_0201AB28(party, i), 0x97, 0) != 0) {
            *foundOut = 1;
            break;
        }
    }
    return 0;
}

/* Script command: type of the signature move check of a party member (0xFFFF when it does not qualify). */
int func_021B62C8(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 *typeOut;
    u32 partySlot;
    u32 tmValue;
    void *mon;

    typeOut = func_02159AE8(vm, work);
    partySlot = func_02159B10(vm, work);
    tmValue = func_0202130C(0x151);
    if (func_0215B4AC(work, partySlot, &mon) == 0) {
        *typeOut = 0xFFFF;
    } else if (func_020188AC(mon, tmValue) == 0) {
        *typeOut = 0xFFFF;
    } else {
        *typeOut = func_02018790(mon);
    }
    return 0;
}

/* Script command: start a selection event with two script arguments and a result variable. */
int func_021B631C(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *scriptWork;
    void *gameSystem;
    u16 *resultOut;
    u32 firstArg;

    scriptWork = func_0215A5F4(work);
    gameSystem = func_0215A5DC(work);
    resultOut = func_02159AE8(vm, work);
    firstArg = func_02159B10(vm, work);
    func_0215897C(scriptWork, (void *)func_021C5AAC(gameSystem, (int)resultOut, firstArg, func_02159B10(vm, work)));
    return 1;
}

/* Script command: open the move select screen of a party member. */
int func_021B636C(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 *moveOut;
    u16 *resultOut;
    u16 partySlot;
    u16 mode;
    void *scriptWork;
    void *gameSystem;

    moveOut = func_02159AE8(vm, work);
    resultOut = func_02159AE8(vm, work);
    partySlot = func_02159B10(vm, work);
    mode = func_02159B10(vm, work);
    scriptWork = func_0215A5F4(work);
    gameSystem = func_0215A5DC(work);
    func_0215897C(scriptWork, (void *)func_0215A2E4((int)gameSystem, (int)func_0201210C(gameSystem), partySlot, (int)moveOut, (int)resultOut, mode == 0, mode));
    return 1;
}

/*
 * Script command: find the first egg in the party that is ready to hatch
 * and start its hatch event; the party index goes to the result variable.
 * Returns 1 when an event started.
 */
u32 func_021B63D4(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 *slotOut = func_02159AE8(vm, work);
    void *scriptWork = func_0215A5F4(work);
    void *gameSystem = func_0215A5DC(work);
    void *fieldMap = func_0201210C(gameSystem);
    void *gameData;
    void *party;
    int partyCount;
    int i;

    func_02188C84(fieldMap);
    gameData = func_020120F4(gameSystem);
    func_02012944(gameData);
    party = func_02012934(gameData);
    partyCount = func_0201AA18(party);
    for (i = 0; i < partyCount; i++) {
        void *mon = func_0201AB28(party, i);
        u32 isEgg = func_02017E1C(mon, 0x4c, 0);
        u32 isBadEgg = func_02017E1C(mon, 3, 0);
        u32 hatchCounter = func_02017E1C(mon, 9, 0);

        if (isEgg != 0 && isBadEgg == 0 && hatchCounter == 0) {
            func_0215897C(scriptWork, func_02166C4C(gameSystem, fieldMap, mon));
            *slotOut = i;
            return 1;
        }
    }
    return 0;
}

/*
 * Script command: compare a party member with the trade request. Result 0
 * fits, 1 egg, 2 wrong species, 3 wrong gender.
 */
int func_021B647C(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *gameSystem;
    void *gameData;
    u32 heapId;
    u16 *resultOut;
    u32 tradeId;
    u32 partySlot;
    void *mon;
    struct FldTrade *trade;
    u32 value;

    func_0215A5F4(work);
    gameSystem = func_0215A5DC(work);
    gameData = func_020120F4(gameSystem);
    heapId = func_02188C84(func_0201210C(gameSystem));
    resultOut = func_02159AE8(vm, work);
    tradeId = func_02159B10(vm, work);
    partySlot = func_02159B10(vm, work);
    mon = func_0201AB28(func_02012934(gameData), partySlot);
    trade = func_021CBFB0(heapId, tradeId);
    *resultOut = 0;
    if (*resultOut == 0 && func_02017E1C(mon, 0x4c, 0) == 1) {
        *resultOut = 1;
    }
    if (*resultOut == 0) {
        value = func_02017E1C(mon, 5, 0);
        if (value != func_021CC060(trade)) {
            *resultOut = 2;
        }
    }
    if (*resultOut == 0 && func_021CC068(trade) != 2) {
        value = func_02017E1C(mon, 0x6e, 0);
        if (value != func_021CC068(trade)) {
            *resultOut = 3;
        }
    }
    func_021CC040(trade);
    return 0;
}

/* Script command: start the trade event for a trade and a party slot. */
u32 func_021B654C(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *scriptWork = func_0215A5F4(work);
    void *gameSystem = func_0215A5DC(work);
    u32 tradeId = func_02159B10(vm, work);
    u32 partySlot = func_02159B10(vm, work);
    func_0215897C(scriptWork, func_021CC500(gameSystem, (u8)tradeId, (u8)partySlot));
    return 1;
}

/* Script command: pick a random entry of bag pocket 2 and return its value (0 when the pocket is empty). */
u32 func_021B6590(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u16 *valueOut = func_02159AE8(vm, work);
    void *bag = func_0201292C(func_0215A5E4(work));
    int pocket = 2;
    u32 itemCount = func_02007FA0(bag, 2);
    u32 randomIndex = func_020056EC(itemCount);
    u16 value;

    if (itemCount == 0)
        value = 0;
    else
        value = func_020212B0(*func_020081DC(bag, pocket, randomIndex));
    *valueOut = value;
    return 0;
}

/* Script command: store the name of a party member in a slot of the stored name save block. */
u32 func_021B65D8(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *gameData;
    void *nameStore;
    int partySlot;
    int nameSlot;

    func_0215A5F4(work);
    gameData = func_020120F4(func_0215A5DC(work));
    nameStore = func_02012FD8(gameData);
    gameData = func_02012934(gameData);
    partySlot = func_02159B10(vm, work);
    nameSlot = func_02159B10(vm, work);
    func_0200E7BC(nameStore, nameSlot, func_0201AB28(gameData, partySlot));
    return 0;
}

/*
 * Script command: put a stored name in the word set (the end-of-string
 * character alone when the slot is empty).
 *
 * The else arm zero is an array initialiser: `u16 s[1] = {0}` keeps &s in r6
 * for the call argument while the result store gets a fresh add sp.
 */
int func_021B6628(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *scriptWork;
    void *nameStore;
    u32 nameSlot;
    u32 wordSetIndex;
    void *tempBuffer;
    void *wordSet;

    scriptWork = func_0215A5F4(work);
    nameStore = func_02012FD8(func_020120F4(func_0215A5DC(work)));
    nameSlot = func_02159B10(vm, work);
    wordSetIndex = func_02159B10(vm, work);
    tempBuffer = (void *)func_02158F7C(scriptWork);
    wordSet = func_02158F74(scriptWork);
    if (func_0200E740(nameStore, nameSlot)) {
        func_02045924(tempBuffer, func_0200E7AC(nameStore, nameSlot));
    } else {
        u16 emptyName[1] = {0};
        emptyName[0] = func_02045A98();
        func_02045924(tempBuffer, emptyName);
    }
    func_0201EE0C(wordSet, wordSetIndex, tempBuffer, 0, 1, 2);
    return 0;
}

/*
 * Script command: handling of the player's own Reshiram. Operation 0 checks
 * that one is in the party, 1 moves it to the front of the party, 2 first
 * swaps the party member in the result variable with the one in the boxes.
 */
u32 func_021B66B8(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 operation = func_02159B10(vm, work);
    u16 *resultOut = func_02159AE8(vm, work);
    void *gameData = func_0215A5E4(work);

    switch (operation) {
    case 0:
        if (func_021B6934(gameData) < 0)
            *resultOut = 0;
        else
            *resultOut = 1;
        break;
    case 1:
        func_021B6904(work);
        break;
    case 2:
        func_021B6708(work, *resultOut);
        func_021B6904(work);
        break;
    }
    return 0;
}

/*
 * Swaps a party member with the player's boxed Reshiram (species 0x283). A
 * held mail goes to the mailbox and Shaymin takes its Land Forme.
 */
void func_021B6708(struct ScrcmdWork *work, int partySlot)
{
    void *gameData;
    void *party;
    u32 heapId;
    void *boxManager;
    void *mon;
    u32 monSize;
    void *mailSave;
    void *mail;
    int mailSlot;
    void *boxedPartyMon;
    u16 boxPos[2];

    gameData = func_0215A5E4(work);
    party = func_02012934(gameData);
    if (func_021B6850(gameData, 0x283, &boxPos[1], &boxPos[0]) == 0) {
        return;
    }
    heapId = func_0215A5CC(work);
    boxManager = (void *)func_0201293C(gameData);
    mon = func_02030734(heapId, func_020173EC(), 1, (const char *)d_021DE270, 0x4c7);
    monSize = func_020173EC();
    func_02082D44(func_0201AB28(party, partySlot), mon, monSize);
    if (func_0202136C(func_02017E1C(mon, 6, 0)) == 1) {
        mailSave = func_02008FEC(gameData);
        mail = func_02008F08(func_0215A5CC(work));
        mailSlot = func_02009020(mailSave, 0);
        func_02017E1C(mon, 0xa7, (u32)mail);
        func_02012944(gameData);
        if (mailSlot >= 0) {
            func_0200903C(mailSave, 0, mailSlot, mail);
        }
        func_02008EAC(mail);
        func_02017E40(mon, 0xa7, (u32)mail);
        func_02017E40(mon, 6, 0);
        func_020307B0(mail);
    }
    if (func_02017E1C(mon, 0xab, 0) == 0x1ec) {
        func_02017988(mon, 0);
        func_020185C4(mon);
    }
    boxedPartyMon = func_0201747C(func_02007A18(boxManager, boxPos[1], boxPos[0]), heapId);
    func_0201AB48(party, partySlot, boxedPartyMon);
    func_020307B0(boxedPartyMon);
    func_020075B0(boxManager, boxPos[1], boxPos[0], func_020185F0(mon));
    func_020307B0(mon);
}

/*
 * Looks for a box slot that holds a non-egg Pokemon of the species with
 * the trainer id of the player, starting at the box that the box manager
 * names; stores box and slot and returns 1 when found.
 */
int func_021B6850(void *gameData, u16 species, u16 *boxOut, u16 *slotOut)
{
    int startBox;
    int i;
    u32 trainerId;
    int slot;
    int box;
    void *myStatus;
    void *boxManager;

    func_02012934(gameData);
    myStatus = func_02012944(gameData);
    boxManager = (void *)func_0201293C(gameData);
    startBox = func_02007698();
    trainerId = func_02008530(myStatus);
    for (i = 0; i < 24; i++) {
        box = (i + startBox) % 24;
        for (slot = 0; slot < 30; slot++) {
            if (func_020079BC((void **)boxManager, box, slot, 0xa9, 0) != 0
                && trainerId == func_020079BC((void **)boxManager, box, slot, 7, 0)
                && species == func_020079BC((void **)boxManager, box, slot, 5, 0)
                && func_020079BC((void **)boxManager, box, slot, 0x4c, 0) == 0) {
                *boxOut = box;
                *slotOut = slot;
                return 1;
            }
        }
    }
    return 0;
}

/* Moves the player's own Reshiram of the party to the first party slot. */
void func_021B6904(struct ScrcmdWork *work)
{
    void *gameData;
    void *party;
    int partyIndex;

    gameData = func_0215A5E4(work);
    party = func_02012934(gameData);
    partyIndex = func_021B6934(gameData);
    if (partyIndex >= 0) {
        func_0201AB8C(party, partyIndex, 0, func_0215A5CC(work));
    }
}

/* Party index of the player's own Reshiram that is not an egg, or -1. */
int func_021B6934(void *gameData)
{
    void *party = func_02012934(gameData);
    void *myStatus = func_02012944(gameData);
    int partyCount = func_0201AA18(party);
    u32 trainerId = func_02008530(myStatus);
    int i;

    for (i = 0; i < partyCount; i++) {
        void *mon = func_0201AB28(party, i);

        if (trainerId == func_02017E1C(mon, 7, 0)
            && func_02017E1C(mon, 5, 0) == 0x283
            && func_02017E1C(mon, 0x4c, 0) == 0)
            return i;
    }
    return -1;
}

/*
 * Script command: start the sub process of overlay 55 with the map function
 * of the field map.
 *
 * d_021F45F0 is the ov055 proc table (ov055 is the overlay id passed to
 * func_021BB990), hence the ov055 token on its symbols: line.
 */
int func_021B69B0(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    func_021BB990((int)ov055_id, (int *)func_02188D24((u8 *)func_02158F58(func_0215A5F4(work))->fieldSystem), d_021F45F0);
    return 0;
}

/*
 * Script command: look up the entry of the mystery data for the owner's
 * birthday and the date, and put its text in the word set.
 */
u32 func_021B69D8(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *gameData = func_0215A5E4(work);
    u32 wordSetIndex = func_02159B10(vm, work);
    void *mysteryData;
    int entryIndex;
    int flags;
    void *entryText;
    void *date;
    void *wordSet;
    struct Strbuf *text;
    OwnerInfo owner;

    mysteryData = func_0200A8A0(func_02012EBC(gameData));
    date = func_021690A4((int)gameData);
    func_02087C88((struct OSOwnerInfo *)(&owner));
    entryIndex = func_0200A940(mysteryData, owner.birthMonth, owner.birthDay, date);
    flags = func_0200A8F8(mysteryData, entryIndex);
    flags = flags != 1;
    entryText = func_0200A8C8(mysteryData, entryIndex);
    wordSet = func_02158F74(func_0215A5F4(work));
    text = func_020457B0(8, 0x8001);
    func_02045924(text, (const u16 *)entryText);
    func_0201EE0C((struct WordSet *)wordSet, wordSetIndex, text, flags, 1, 2);
    func_02045808(text);
    return 0;
}

/* Script command: number of entries of the mystery data. */
int func_021B6A78(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    void *gameData;
    u16 *countOut;

    gameData = func_0215A5E4(work);
    countOut = func_02159AE8(vm, work);
    *countOut = func_0200A8AC(func_0200A8A0(func_02012EBC(gameData)));
    return 0;
}

/* Entry number index of a warp list. */
WarpEntry *func_021B6AA4(WarpEntry *table, u32 index)
{
    return table + index;
}

void func_021B6AAC(u16 *labelId)
{
}

/* Number of entries of a warp list (0 when the list has no end marker among the first 8). */
int func_021B6AB0(WarpEntry *table)
{
    int i;
    u16 *labelId;

    for (i = 0; i < 8; i++) {
        labelId = (u16 *)func_021B6AA4(table, i);
        func_021B6AAC(labelId);
        if (*labelId == 0xFFFF) {
            return i;
        }
    }
    return 0;
}

/*
 * Script command: keep the warp list that follows the command in the
 * script data for the next warp commands.
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int func_021B6AE0(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    func_0215A6D0(work, (u32)(vm->pc + func_0201134C(vm)));
    return 0;
}

/* Script command: add every warp of the list, except the current map, to the menu. */
u32 func_021B6AFC(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    WarpEntry *table = (WarpEntry *)func_0215A6C4(work);
    void *scriptWork = func_0215A5F4(work);
    int msgBuffer = func_02158F78(scriptWork);
    int tempBuffer = func_02158F7C(scriptWork);
    u16 currentMapId = func_0215A5D0(work);
    u32 entryCount = func_021B6AB0(table);
    u32 i = 0;

    for (; i < entryCount; i++) {
        WarpEntry *entry = func_021B6AA4(table, i);

        if (currentMapId != entry->mapId)
            func_0215A7F0(work, entry->labelId, 0xffff, i, (struct Strbuf *)msgBuffer, (void *)tempBuffer);
    }
    return 0;
}

/* Script command: warp to an entry of the warp list. */
u32 func_021B6B6C(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    u32 entryIndex = func_02159B10(vm, work);
    WarpEntry *table = (WarpEntry *)func_0215A6C4(work);

    func_0215A5D0(work);
    if (entryIndex < func_021B6AB0(table)) {
        const WarpEntry *entry = func_021B6AA4(table, entryIndex);
        void *scriptWork = func_0215A5F4(work);
        void *gameSystem = func_02158F54(scriptWork);
        void *fieldMap = func_0201210C(gameSystem);
        Vec3 position;
        u32 gridY = entry->gridY;
        u32 gridZ = entry->gridZ;
        u32 mapId = entry->mapId;
        u32 gridX = entry->gridX;

        position.x = gridX << 16;
        position.y = gridY << 16;
        position.z = gridZ << 16;
        func_0215897C(scriptWork, (void *)func_021854B0(gameSystem, fieldMap, mapId, &position, 1));
    }
    return 1;
}

/*
 * Script command: read the received mystery gift data and do the operation
 * of the mode on it: 0 whether a gift of a known kind is waiting, 1 to 3 and
 * 7 checks and queries of its kind, 4 hand it over, 5 and 6 queries on the
 * field map.
 */
int func_021B6BDC(struct ScriptVm *vm, struct ScrcmdWork *work)
{
    int mode;
    u16 *resultOut;
    void *gameData;
    void *giftHandle;
    u32 heapId;
    MysteryGiftCard *giftData;
    int giftKind;
    MysteryGiftCard cardBuffer;
    u32 giftIndex;

    mode = func_02159B10(vm, work);
    resultOut = func_02159AE8(vm, work);
    gameData = func_0215A5E4(work);
    heapId = func_0215A5CC(work);
    giftHandle = func_0200A300(func_02012EBC(gameData), 0, (void *)heapId);
    giftData = func_021B7834(giftHandle, (int *)(&giftIndex), &cardBuffer);
    giftKind = func_021B7864(giftHandle);
    if (giftKind != d_021D9970[giftKind].kind) {
        func_0200A338(giftHandle);
        return 0;
    }
    switch (mode) {
    case 0:
        if (giftKind != 0) {
            *resultOut = 1;
        } else {
            *resultOut = 0;
        }
        break;
    case 1:
        *resultOut = func_021B6D0C(giftKind, work, gameData, giftData);
        break;
    case 2:
        *resultOut = func_021B6D30(giftKind, giftData, work);
        break;
    case 3:
        *resultOut = func_021B6D64(giftKind, giftData, work);
        break;
    case 4:
        if (func_021B6D98(giftKind, work, gameData, giftData) == 1) {
            func_021B785C(giftHandle, giftIndex);
            if (func_021B6EB0(giftData, giftKind) == 1) {
                func_0216BF74(func_02012F08(gameData), 1, func_02012944(gameData));
            }
        }
        *resultOut = 0;
        break;
    case 5:
        *resultOut = func_021B6DE4(func_0201210C(func_0215A5DC(work)), gameData);
        break;
    case 6:
        *resultOut = func_021B6E0C(func_0201210C(func_0215A5DC(work)));
        break;
    case 7:
        *resultOut = func_021B6DC0(giftKind, work, gameData, giftData);
        break;
    }
    func_0200A338(giftHandle);
    return 0;
}


/* Asks the kind handler whether the player can take the gift. 0 when the kind has none. */
int func_021B6D0C(int giftKind, struct ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    MysteryGiftQueryFn canReceive = d_021D9970[giftKind].canReceive;

    if (card != 0 && canReceive != 0) {
        return canReceive(work, gameData, card);
    }
    return 0;
}


/* Fills the word set for the gift received message and returns its message id.
 * 7 when the kind has no handler. */
int func_021B6D30(int giftKind, MysteryGiftCard *card, struct ScrcmdWork *work)
{
    struct WordSet *wordSet;
    MysteryGiftMessageFn prepareMessage;

    wordSet = func_02158F74(func_0215A5F4(work));
    prepareMessage = d_021D9970[giftKind].prepareReceiveMessage;
    if (card != 0 && prepareMessage != 0) {
        return prepareMessage(wordSet, card, work);
    }
    return 7;
}


/* Fills the word set for the follow-up message of the gift and returns its
 * message id. 8 when the kind has no handler. */
int func_021B6D64(int giftKind, MysteryGiftCard *card, struct ScrcmdWork *work)
{
    struct WordSet *wordSet;
    MysteryGiftMessageFn prepareMessage;

    wordSet = func_02158F74(func_0215A5F4(work));
    prepareMessage = d_021D9970[giftKind].prepareFollowUpMessage;
    if (card != 0 && prepareMessage != 0) {
        return prepareMessage(wordSet, card, work);
    }
    return 8;
}

/* Puts the gift into the save through the kind handler. 1 when a handler ran. */
int func_021B6D98(int giftKind, struct ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    MysteryGiftReceiveFn receive = d_021D9970[giftKind].receive;

    if (card != 0 && receive != 0) {
        receive(work, gameData, card);
        return 1;
    }
    return 0;
}


/* Asks the kind handler which scene the script plays for the gift. 0 when the kind has none. */
int func_021B6DC0(int giftKind, ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    MysteryGiftQueryFn getReceiveType = d_021D9970[giftKind].getReceiveType;

    if (card != 0 && getReceiveType != 0) {
        return getReceiveType(work, gameData, card);
    }
    return 0;
}

/* Script command mode: object id of the delivery person on the map, found among
 * the loaded models first, then among the placement records of the zone. 0 when absent. */
u16 func_021B6DE4(struct FieldMap *fieldMap, struct GameData *gameData)
{
    Mmdl *mmdl;
    int objId;

    mmdl = func_021B6E24(fieldMap);
    if (mmdl != 0) {
        return func_0216D588(mmdl);
    }
    objId = func_021B6E68(gameData);
    if (objId >= 0) {
        return objId;
    }
    return 0;
}

/* Script command mode: 1 when a delivery person model is loaded on the map. */
u16 func_021B6E0C(struct FieldMap *fieldMap)
{
    return func_021B6E24(fieldMap) != 0 ? 1 : 0;
}

/* Finds the loaded model with the delivery person's object code. */
Mmdl *func_021B6E24(struct FieldMap *fieldMap)
{
    u32 iterator = 0;
    Mmdl *mmdl;
    MmdlSys *mmdlSys;

    mmdlSys = func_02188C7C(fieldMap);
    while (func_0216DD1C(mmdlSys, &mmdl, &iterator) == 1) {
        if (func_0216D598(mmdl) == SCRCMD_DELIVERY_OBJ_CODE)
            return mmdl;
    }
    return 0;
}

/*
 * Searches the placement records of the zone for the delivery person and
 * returns its object id, or -1. The return reads through a byte offset rather
 * than headers[i].objId: the subscript form lets the compiler CSE
 * headers + i*0x24 into one register (product in r2, ldrh r0,[r3]); the
 * byte-offset form keeps only the product live and loads ldrh r0,[r4,r3]
 * as the original does.
 */
int func_021B6E68(struct GameData *gameData)
{
    MmdlHeader *headers;
    int count;
    struct EventDataSystem *eventData;
    int i;

    eventData = func_02012844(gameData);
    headers = func_02162740(eventData);
    count = func_02162744(eventData);
    if (headers == 0 || count == 0) {
        return -1;
    }
    for (i = 0; i < count; i++) {
        if (headers[i].objCode == SCRCMD_DELIVERY_OBJ_CODE) {
            return *(u16 *)((u8 *)headers + i * sizeof(MmdlHeader));
        }
    }
    return -1;
}

/* TRUE for the Liberty Pass gift: an item card of item 0x23E with event number 0x7FE. */
int func_021B6EB0(MysteryGiftCard *card, int giftType)
{
    if (giftType != MYSTERY_GIFT_TYPE_ITEM) {
        return 0;
    }
    if (card->eventId != MYSTERY_GIFT_LIBERTY_PASS_EVENT) {
        return 0;
    }
    if (card->param == MYSTERY_GIFT_LIBERTY_PASS_ITEM) {
        return 1;
    }
    return 0;
}

/* Builds the gift Pokemon of a card in a heap block. The caller frees it. */
struct PokemonParam *func_021B6EE0(ScrcmdWork *work, MysteryGiftCard *card)
{
    return func_02157E9C(card, func_0215A5CC(work), func_0215A5E4(work));
}

/* Kind 1 canReceive: the party has room. */
int func_021B6F00(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    if (func_0201AA18(func_02012934(gameData)) < MYSTERY_GIFT_PARTY_MAX) {
        return 1;
    }
    return 0;
}

/* Kind 1 receive: adds the gift Pokemon to the party and registers it in the Pokedex. */
void func_021B6F18(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    struct Party *party;
    struct PokemonParam *mon;

    party = func_02012934(gameData);
    mon = func_021B6EE0(work, card);
    if (func_0201AA18(party) < MYSTERY_GIFT_PARTY_MAX && mon != 0) {
        func_0201A98C(party, mon);
        func_0200CDE0(func_0200CA1C(gameData), mon);
        func_020307B0(mon);
    }
}

/* Kind 1 getReceiveType: egg or Pokemon. */
int func_021B6F5C(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    struct PokemonParam *mon;
    int isEgg;

    mon = func_021B6EE0(work, card);
    if (mon == 0) {
        return MYSTERY_GIFT_RECEIVE_MON;
    }
    isEgg = func_02017E1C(mon, MYSTERY_GIFT_MON_PARAM_IS_EGG, 0);
    func_020307B0(mon);
    return isEgg == 1 ? MYSTERY_GIFT_RECEIVE_EGG : MYSTERY_GIFT_RECEIVE_MON;
}

/* Kind 1 prepareReceiveMessage: player name and Pokemon name; the egg message has no Pokemon name. */
int func_021B6F88(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work)
{
    struct PokemonParam *mon;
    struct MyStatus *myStatus;
    int messageId;

    myStatus = func_02012944(func_0215A5E4(work));
    mon = func_021B6EE0(work, card);
    messageId = MYSTERY_GIFT_MSG_MON_RECEIVED;
    func_0201F02C(wordSet, 0, myStatus);
    if (mon == 0) {
        func_0201EEC4(wordSet, 1, 0);
    } else {
        if (func_02017E1C(mon, MYSTERY_GIFT_MON_PARAM_IS_EGG, 0) == 1)
            messageId = MYSTERY_GIFT_MSG_EGG_RECEIVED;
        else
            func_0201EED4(wordSet, 1, mon);
        func_020307B0(mon);
    }
    return messageId;
}

/* Kind 1 prepareFollowUpMessage. */
int func_021B6FE8(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work)
{
    return MYSTERY_GIFT_MSG_MON_FOLLOW_UP;
}

/* Kind 2 canReceive: an item always fits. */
int func_021B6FEC(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    return 1;
}

/* Kind 2 receive: puts one of the item into the bag when the id is in range. */
void func_021B6FF0(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    u32 heapId;
    struct MyItem *bag;
    u16 itemId;

    heapId = func_0215A5CC(work);
    bag = func_0201292C(gameData);
    itemId = card->param;
    if (itemId != 0 && itemId <= MYSTERY_GIFT_ITEM_MAX) {
        func_02007E50(bag, itemId, 1, heapId);
    }
}

/* Kind 2 getReceiveType: the Liberty Pass or a plain item. */
int func_021B7020(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    if (func_021B6EB0(card, card->giftType) == 1) {
        return MYSTERY_GIFT_RECEIVE_LIBERTY_PASS;
    }
    return MYSTERY_GIFT_RECEIVE_ITEM;
}

/* Kind 2 prepareReceiveMessage: player name and item name. */
int func_021B7038(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work)
{
    struct MyStatus *myStatus;
    u16 itemId;

    myStatus = func_02012944(func_0215A5E4(work));
    itemId = card->param;
    func_0201F02C(wordSet, 0, myStatus);
    func_0201EF40(wordSet, 1, itemId);
    return MYSTERY_GIFT_MSG_ITEM_RECEIVED;
}

/* Kind 2 prepareFollowUpMessage: item name. */
int func_021B7068(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work)
{
    func_0201EF40(wordSet, 0, (u16)card->param);
    return MYSTERY_GIFT_MSG_ITEM_FOLLOW_UP;
}

/* Kind 3 canReceive: always. */
int func_021B707C(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    return 1;
}

/* Kind 3 receive: sets the obtained flag of the card in the intrude save. */
void func_021B7080(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    func_0200BF18(func_0200BE48(func_02012EBC(gameData)), card->param);
}

/* Kind 3 getReceiveType. */
int func_021B7098(ScrcmdWork *work, struct GameData *gameData, MysteryGiftCard *card)
{
    return MYSTERY_GIFT_RECEIVE_FLAG;
}

/* Kind 3 prepareReceiveMessage: player name and the flag id as a number. */
int func_021B709C(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work)
{
    struct GameData *gameData;
    struct MyStatus *myStatus;
    u32 flagId;

    gameData = func_0215A5E4(work);
    func_0200BE48(func_02012EBC(gameData));
    myStatus = func_02012944(gameData);
    flagId = card->param;
    func_0201F02C(wordSet, 0, myStatus);
    func_0201F184(wordSet, 1, flagId);
    return MYSTERY_GIFT_MSG_FLAG_RECEIVED;
}

/* Kind 3 prepareFollowUpMessage. */
int func_021B70D4(struct WordSet *wordSet, MysteryGiftCard *card, ScrcmdWork *work)
{
    return MYSTERY_GIFT_MSG_FLAG_FOLLOW_UP;
}

/* Script command: looks a key up in a key to value table and returns the
 * value in the result variable (0 when the key is not listed).
 * Arguments: key, table index, result variable. */
int func_021B70D8(struct ScriptVm *vm, ScrcmdWork *work)
{
    u32 i;
    u32 heapId;
    u32 key;
    u32 tableIndex;
    u16 *result;
    ScrcmdKeyValueEntry *table;
    u32 count;

    heapId = func_02188C84((struct FieldMap *)func_02158F58(func_0215A5F4(work))->fieldSystem);
    key = func_02159B10(vm, work);
    tableIndex = func_02159B10(vm, work);
    result = func_02159AE8(vm, work);
    table = (ScrcmdKeyValueEntry *)func_0204A298(SCRCMD_TABLE_ARC_ID, d_021D99D0[tableIndex], 0, (u16)((heapId & 0x7fff) | SCRCMD_HEAP_FLAG_TAIL), &count);
    count >>= 3;
    i = 0;
    *result = 0;
    for (i = 0; i < count; i++) {
        if (key == table[i].key) {
            *result = table[i].value;
            break;
        }
    }
    func_020307B0(table);
    return 0;
}

/* Script command: result 1 when the bag holds any item listed in a table
 * (the key column holds the item ids). Arguments: table index, result variable. */
int func_021B716C(struct ScriptVm *vm, ScrcmdWork *work)
{
    ScriptWork *scriptWork;
    struct GameData *gameData;
    struct MyItem *bag;
    u32 heapId;
    u32 tableIndex;
    u16 *result;
    u32 *table;
    u32 count;
    u32 i;

    scriptWork = func_0215A5F4(work);
    gameData = func_0215A5E4(work);
    heapId = func_02188C84((struct FieldMap *)func_02158F58(scriptWork)->fieldSystem);
    tableIndex = func_02159B10(vm, work);
    result = func_02159AE8(vm, work);
    bag = func_0201292C(gameData);
    table = (u32 *)func_0204A298(SCRCMD_TABLE_ARC_ID, d_021D99D0[tableIndex], 0, (u16)((heapId & 0x7fff) | SCRCMD_HEAP_FLAG_TAIL), &count);
    count >>= 3;
    *result = 0;
    for (i = 0; i < count; i++) {
        if (func_02007F68(bag, (u16)table[i * 2], 1, heapId)) {
            *result = 1;
            break;
        }
    }
    func_020307B0(table);
    return 0;
}

/*
 * Script command: looks a key up in a key to value table and registers the
 * value as a number in the word set. Arguments: key, table index, buffer id,
 * digit count.
 * The table byte d_021D99D0[tableIndex] is loaded ahead of the `str r0,[sp]`
 * that passes &count: that needs the table declared const, otherwise the load
 * may alias the stack store and is scheduled after it.
 */
int func_021B721C(struct ScriptVm *vm, ScrcmdWork *work)
{
    ScriptWork *scriptWork;
    u32 heapId;
    u32 key;
    u32 tableIndex;
    u32 bufferId;
    u32 digits;
    struct WordSet *wordSet;
    ScrcmdKeyValueEntry *table;
    u32 count;
    u32 i;

    scriptWork = func_0215A5F4(work);
    heapId = func_02188C84((struct FieldMap *)func_02158F58(scriptWork)->fieldSystem);
    key = func_02159B10(vm, work);
    tableIndex = func_02159B10(vm, work);
    bufferId = func_02159B10(vm, work);
    digits = func_02159B10(vm, work);
    wordSet = func_02158F74(scriptWork);
    table = (ScrcmdKeyValueEntry *)func_0204A298(SCRCMD_TABLE_ARC_ID, d_021D99D0[tableIndex], 0, (u16)((heapId & 0x7fff) | SCRCMD_HEAP_FLAG_TAIL), &count);
    count >>= 3;
    for (i = 0; i < count; i++) {
        if (key == table[i].key) {
            func_0201EFA4(wordSet, bufferId, table[i].value, digits, 0, 1);
            break;
        }
    }
    func_020307B0(table);
    return 0;
}

/*
 * Script command: looks a key up in a key to value table and adds the value to
 * the survey points of the misc save. Arguments: key, table index.
 * Same archive lookup as func_021B70D8 / func_021B716C; the const table byte
 * is scheduled ahead of the `str r0,[sp]` that passes &count (see func_021B721C).
 */
int func_021B72CC(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData;
    u32 heapId;
    u32 key;
    u32 tableIndex;
    ScrcmdKeyValueEntry *table;
    u32 count;
    u32 i;

    heapId = func_02188C84((struct FieldMap *)func_02158F58(func_0215A5F4(work))->fieldSystem);
    key = func_02159B10(vm, work);
    tableIndex = func_02159B10(vm, work);
    gameData = func_0215A5E4(work);
    func_020127A4(gameData);
    table = (ScrcmdKeyValueEntry *)func_0204A298(SCRCMD_TABLE_ARC_ID, d_021D99D0[tableIndex], 0, (u16)((heapId & 0x7fff) | SCRCMD_HEAP_FLAG_TAIL), &count);
    count >>= 3;
    for (i = 0; i < count; i++) {
        if (key == table[i].key) {
            func_0200C278(func_02012F08(gameData), table[i].value);
            break;
        }
    }
    func_020307B0(table);
    return 0;
}



/* Script command: return the gift of the given daily index (0 when out of range). */
int func_021B7364(void *core, void *work)
{
    u32 index;
    u16 *ret;

    index = func_02159B10(core, work);
    ret = func_02159AE8(core, work);
    if (index >= 11) {
        index = 0;
    }
    *ret = d_021D99E8[index];
    return 0;
}

/* TRUE when the month and day are one of the five special dates. */
int func_021B7390(u32 month, int day)
{
    u32 i;
    u16 date;

    date = (month << 8) | day;
    for (i = 0; i < 5; i++) {
        if (date == d_021D99D4[i]) {
            return 1;
        }
    }
    return 0;
}

/*
 * Script command: the daily gift index of today, 10 on a special date.
 * Addresses are Black-image addresses.
 */
int func_021B73B8(void *core, void *work)
{
    u16 *ret;
    struct GameData *gameData;
    u32 month;
    int day;

    ret = func_02159AE8(core, work);
    gameData = func_0215A5E4(work);
    month = func_021690D0(gameData);
    day = func_021690E0(gameData);
    if (func_021B7390(month, day) == 1)
        *ret = 10;
    else
        *ret = d_021D99DE[day % 10];
    return 0;
}
