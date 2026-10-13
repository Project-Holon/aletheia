/*
 * file:     scrcmd_proc_fld.c
 * unit:     yes
 * function: func_021B3158, func_021B3258, func_021B331C, func_021B3350, func_021B3370, func_021B3470, func_021B34F4, func_021B3568, func_021B35A4, func_021B3834, func_021B385C, func_021B38E0, func_021B39C4, func_021B3A64, func_021B3B04, func_021B3B14, func_021B3B84, func_021B3BD8, func_021B3C58, func_021B3C78, func_021B3CFC, func_021B3D60, func_021B3DEC, func_021B3F00, func_021B3F3C, func_021B3FA0, func_021B40A8, func_021B40D4, func_021B41AC, func_021B4264, func_021B42D0, func_021B43EC, func_021B44CC, func_021B4510, func_021B45A0, func_021B468C, func_021B46FC, func_021B4710, func_021B4714, func_021B4804, func_021B4878, func_021B4894, func_021B4918, func_021B4984, func_021B49EC, func_021B4AA4, func_021B4BA4, func_021B4BEC, func_021B4C14, func_021B4C34, func_021B4C54, func_021B4C98, func_021B4CDC, func_021B4D14, func_021B4D60, func_021B4E58, func_021B4E9C, func_021B4EE0, func_021B4F1C, func_021B4F68, func_021B4FB0, func_021B5008, func_021B503C, func_021B5094, func_021B50D0, func_021B50F8, func_021B5128, func_021B5154, func_021B5190, func_021B51BC, func_021B52A4, func_021B52E0, func_021B52FC, func_021B536C, func_021B538C, func_021B53A4, func_021B53BC, func_021B542C, func_021B5498, func_021B54D4, func_021B54FC, func_021B5528, func_021B55C8, func_021B55F0, func_021B5610, func_021B5650, func_021B568C
 * address:  0x021B3158
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021B30C8  0x021B30C8  thumb  ov021
 *   func_0218FE50  0x0218FE50  thumb  ov021
 *   func_02193060  0x02193060  thumb  ov021
 *   func_0218F9C4  0x0218F9C4  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_0218F878  0x0218F878  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021D9738     0x021D9738  data   ov021  a4
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C258 0x0200C258 thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0200C274  0x0200C274  thumb
 *   func_0200DABC  0x0200DABC  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0200823C  0x0200823C  thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020200CC 0x020200CC thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_0203630C 0x0203630C arm
 *   func_020362DC 0x020362DC arm
 *   func_0201CE38 0x0201CE38 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02008DAC  0x02008DAC  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0200C29C  0x0200C29C  thumb
 *   func_0200DA98  0x0200DA98  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02020234  0x02020234  thumb
 *   func_0201FDA0  0x0201FDA0  thumb
 *   func_0201FEBC  0x0201FEBC  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_020310C4  0x020310C4  arm
 *   d_021D9440     0x021D9440  data   ov021  a4
 *   func_02021288  0x02021288  thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_020212B0 0x020212B0 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201F898 0x0201F898 thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201F81C 0x0201F81C thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   func_0201102C 0x0201102C thumb
 *   func_02045C04 0x02045C04 arm
 *   d_021D946C 0x021D946C data
 *   d_021D95DE 0x021D95DE data
 *   d_021DE1A8 0x021DE1A8 data
 *   d_021DE164     0x021DE164  data  a4
 *   d_021D9430     0x021D9430  data  a1
 *   func_02186670 0x02186670 thumb ov020
 *   func_0201F868  0x0201F868  thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0203101C 0x0203101C arm
 *   func_02031140 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045808 0x02045808 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_020414EC 0x020414EC arm
 *   func_0204047C 0x0204047C arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_02049F78 0x02049F78 arm
 *   func_02049E74 0x02049E74 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021D96E0     0x021D96E0  data   ov021  a2
 *   d_021D96E8     0x021D96E8  data   ov021  a2
 *   d_021D96F0     0x021D96F0  data   ov021  a2
 *   d_021D96F8     0x021D96F8  data   ov021  a2
 *   d_021D9700     0x021D9700  data   ov021  a2
 *   func_0204B100  0x0204B100  arm
 *   func_0204B22C  0x0204B22C  arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   d_021DE18C    0x021DE18C data ov021 a4
 *   d_021DE170    0x021DE170 data ov021 a4
 *   func_020450F0 0x020450F0 arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F73C 0x0201F73C thumb
 *   d_021D945C    0x021D945C data a4
 *   func_0201F91C 0x0201F91C thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02020D0C 0x02020D0C thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_020437DC 0x020437DC arm
 *   func_02007F68 0x02007F68 thumb
 *   func_020202FC 0x020202FC thumb
 *   func_0204B404 0x0204B404 arm
 *   func_0202020C  0x0202020C  thumb
 *   func_0201EF6C  0x0201EF6C  thumb
 *   func_0201F14C  0x0201F14C  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CD10  0x0201CD10  thumb
 *   func_0203633C 0x0203633C arm
 *   func_02041300  0x02041300  arm
 *   d_021D9654     0x021D9654  data  a4
 *   func_02012138  0x02012138  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021896F4  0x021896F4  thumb  ov021
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201283C  0x0201283C  thumb
 *   func_02009CE4  0x02009CE4  thumb
 *   func_02009A34  0x02009A34  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020124AC  0x020124AC  thumb
 *   abs_id_6       0x00000006  data
 *   func_02154C20  0x02154C20  thumb  ov006
 *   abs_id_4       0x00000004  data
 *   func_021542C0  0x021542C0  thumb  ov004
 *   abs_id_01        0x00000001  data
 *   func_02154694  0x02154694  thumb  ov001
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BB58  0x0200BB58  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_0200BBFC  0x0200BBFC  thumb
 *   func_02014840  0x02014840  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DE220     0x021DE220  data  a1
 *   ov170_id       0x000000AA  data  a1
 *   d_021EF78C     0x021EF78C  data  ov170  a4
 *   func_021CD2A4  0x021CD2A4  thumb  ov021
 *   func_02011290  0x02011290  thumb
 *   func_0215898C  0x0215898C  thumb  ov010
 *   func_0215F8A8  0x0215F8A8  thumb  ov010
 *   func_02009210  0x02009210  thumb
 *   func_020090D8  0x020090D8  thumb
 *   func_02168BBC  0x02168BBC  thumb  ov010
 *   func_020146F8  0x020146F8  thumb
 *   abs_id_DB      0x000000DB  data
 *   d_02185F0C     0x02185F0C  data  ov219  a4
 *   func_021C5BD0  0x021C5BD0  thumb  ov021
 *   func_021D30B8  0x021D30B8  thumb  ov021
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AA0A0  0x021AA0A0  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012A44  0x02012A44  thumb
 *   func_0216EFCC  0x0216EFCC  thumb  ov010
 *   func_0216E95C  0x0216E95C  thumb  ov010
 *   func_021AAB48  0x021AAB48  thumb  ov021
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D488  0x0200D488  thumb
 *   func_0215E440  0x0215E440  thumb  ov010
 *   func_0215E2B8  0x0215E2B8  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02005728  0x02005728  thumb
 *   d_021DE234     0x021DE234  data  a1
 *   d_021D98D0     0x021D98D0  data  a2
 *   func_0218F0F8  0x0218F0F8  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_02159168  0x02159168  thumb  ov010
 *   func_02159144  0x02159144  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_0218F818  0x0218F818  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_02011330  0x02011330  thumb
 *   func_0201134C  0x0201134C  thumb
 *   func_0218F900  0x0218F900  thumb  ov021
 *   func_02048F4C  0x02048F4C  arm
 *   func_0218FA40  0x0218FA40  thumb  ov021
 *   func_021D2D50  0x021D2D50  thumb  ov021
 *   func_020124E4  0x020124E4  thumb
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   func_0218E17C  0x0218E17C  thumb  ov021
 *   func_021F36C8  0x021F36C8  thumb  ov056
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   ov56_id        0x00000038  data  a1
 *   g_021F4344     0x021F4344  data  ov056  a4
 *   g_021F4374     0x021F4374  data  ov056  a4
 *   g_021F438C     0x021F438C  data  ov056  a4
 *   g_021F435C     0x021F435C  data  ov056  a4
 */

#include "scrcmd_proc_fld_types.h"
#include "fieldmap_types.h"

struct Ctx;
struct MsgBank;
struct Blk1AC;
struct Blk34;
struct Cfg;
struct Descriptor;
struct Obj;
struct PrintSys;
struct Rec;
struct Rec3;
struct Sub02008C20Obj;
struct Tcbl;
struct WordSet;
struct Slot;
struct U16Vec;
struct S02031140;
struct Sub0204A9D0;
struct Bank;
struct CharBuf;
struct Src;
struct Bmp;
struct StrObj;
struct Vec2;
struct Sub020097BCObj;
struct BigObj;
struct Pair;
struct Desc;
struct Big;
struct Blk37;
struct Sub02008700Obj;
struct ScriptVm;
struct Sub020090B0Obj;
struct Sub02009210Obj;
struct Blk38;
struct Stream;
struct Cursor;
struct ScrcmdWork;
struct Blk021D2D50;

/* Six enable flags handed to the field region object. */
typedef struct LayerFlags {
    u32 flag[6];
} LayerFlags;

typedef signed char    s8;

/* Argument block of the field events that take the field map (ov006 / ov004 callbacks). */
typedef struct FieldEventArgs {
    void *fieldMap;
    u32 reserved;
} FieldEventArgs;

/* 0x2C-byte work block built here and handed to the ov170 process. */
typedef struct Ov170EventWork {
    void *gameData;         /* 0x00 */
    u32 boxManager;         /* 0x04 */
    void *party;            /* 0x08: replaced by a heap copy when kind is 4 */
    u32 myItem;             /* 0x0c */
    u8 *myStatus;           /* 0x10 */
    u32 extraData;          /* 0x14: heap block only when kind is 4 */
    u32 saveStateA;         /* 0x18 */
    u32 saveStateB;         /* 0x1c */
    u32 reserved20;         /* 0x20 */
    u32 kind;               /* 0x24: hand-off kind, 4 copies the party */
    u16 result;             /* 0x28: written by the ov170 process, 1 means success */
    u16 reserved2A;         /* 0x2a */
} Ov170EventWork;

/* 0xc-byte record passed alongside it. */
typedef struct Ov170EventHandoff {
    void *gameData;                 /* 0x00 */
    unsigned short *resultVar;      /* 0x04: script variable that receives the flag */
    Ov170EventWork *work;           /* 0x08 */
} Ov170EventHandoff;

/* One wild encounter entry: species and form in 4 bytes. */
typedef struct EncounterSlot {
    u16 species : 11;
    u16 form : 5;
    u16 reserved;
} EncounterSlot;

/* 0xE8-byte encounter table record filled by func_0215E2B8. */
typedef struct EncounterRecord {
    u8  reserved00[5];
    u8  hasSetA;
    u8  hasSetB;
    u8  reserved07[0xc0 - 7];
    EncounterSlot setA[5];
    EncounterSlot setB[5];
} EncounterRecord;

/* Field region record read from archive 0xA3 (0x2C bytes). */
typedef struct FieldRegionRecord {
    u16 areaWidth;
    u16 areaHeight;
    u32 areaFlags;
    VecFx32 origin;
    LayerFlags layers;
} FieldRegionRecord;

/* Field region parameter block (0x48 bytes) handed to the field region object. */
typedef struct FieldRegionParam {
    u32 reserved00[3];
    VecFx32 origin;         /* 0x0c */
    u32 reserved18[3];
    u16 areaWidth;          /* 0x24 */
    u16 areaHeight;         /* 0x26 */
    u32 areaFlags;          /* 0x28 */
    u32 reserved2C;
    LayerFlags layers;      /* 0x30: six layer enable flags */
} FieldRegionParam;

/* Custom event record built from eight script values. */
typedef struct CustomEventParam {
    u16 eventId;            /* 0x00 */
    u16 eventKind;          /* 0x02 */
    u16 mapX;               /* 0x04 */
    u16 mapY;               /* 0x06 */
    u16 mapZ;               /* 0x08 */
    u16 reserved0A;         /* 0x0a */
    u16 facing;             /* 0x0c */
    u8 kind;                /* 0x0e */
    u8 kindCopy;            /* 0x0f */
    u32 scriptId;           /* 0x10 */
    u32 reserved14;         /* 0x14 */
} CustomEventParam;

typedef enum { B_FALSE, B_TRUE } Bool;

extern void *func_0215A5F4(void *p);
extern void *func_02158FB4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C58(void *a);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_021B30C8(u32 *p, u32 b, void *h);
extern int func_0218FE50(u8 *a);
extern void func_02193060(u32 a);
extern void func_0218F9C4(u8 *p, u8 *src, u16 v);
extern int func_0218EC60(u32 a);
extern void func_0218F1AC(u8 *p, u32 v);
extern void func_0218F05C(unsigned char *a);
extern void func_0218F878(u8 *a);
extern u32 func_020307B0(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void *func_02012F08(int *p);
extern int func_0200C258(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0200C274(struct Blk34 *p);
extern u16 func_0200DABC(struct Blk1AC *p);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern u32 func_02007E3C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_0200823C(u32 a);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern s32 func_020200CC(struct Obj *o);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern void func_0201CE38(void *);
extern void func_020061E4(u32 a);
extern u32 func_0200C29C(struct Blk34 *p, u32 v);
extern void func_0200DA98(struct Blk1AC *p, u16 v);
extern u32 func_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_02041B6C(u32 a);
extern void func_02020234(u8 *p);
extern u32 func_0201FDA0(const void *a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_0201FEBC(u8 *p);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_02021288(u32 id);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int func_020212B0(u32 a);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201F81C(int, int);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern u32 func_0201102C(u32 v);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02186670(char *base, char *out, u16 *cnt, int n, u16 id);
extern u32 func_0201F868(void *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_02031140(struct S02031140 *p);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_020414EC(u32 i);
extern void func_0204047C(int idx, unsigned short val);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern unsigned func_02020E60(unsigned a, unsigned b);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204ADEC(u32 a, u32 b, u32 c);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *, unsigned int);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern u32 func_0201C440(void *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_0201F91C(struct Slot *s);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02020D0C(u8 *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
extern void func_0201F14C(struct WordSet *p, u32 i, u32 v);
extern signed char func_02012FFC(void);
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern unsigned int func_0203633C(void);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02012138(const struct Ctx *p);
extern int func_021896F4(void *p);
extern u32 func_02009CE4(struct Sub020097BCObj *obj);
extern u32 func_0201283C(const struct BigObj *p);
extern void *func_0215A5E4(void *a0);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern void func_0215897C(void *a, void *b);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern int func_02154C20(int x, struct Pair *p);
extern int func_021542C0(int x, struct Pair *p);
extern void *func_02154694(void *p, int a);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *p);
extern void func_0200BB58(u8 *a0, u8 *a1);
extern u32 func_02159B10(void *c, void *vm);
extern void *func_0200CA1C(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u32 func_0201293C(const struct BigObj *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
extern void *func_0200BAF4(int a0, int a1);
extern u32 func_0200BBFC(struct Obj *p, u32 mask);
extern void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021CD2A4(u32 a, u32 b, u32 x, u32 c, u32 d);
extern void *func_0215F8A8(void *p, int a1);
extern void func_0215898C(int a, int b);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_020090D8(struct Sub020090B0Obj *obj, u8 value);
extern void *func_02168BBC(void *a, void *b);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void *func_021C5BD0(void *a, u32 b, u32 c);
extern void *func_021D30B8(void *, u16 *);
extern void *func_02158F54(void *p);
extern int func_02158F58(int a0);
extern u32 func_02188CE8(u8 *p);
extern u32 func_021AA0A0(u32 a, u32 b, u32 c, u32 d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u32 func_02012A44(const struct BigObj *p);
extern u8 func_0216EFCC(int i);
extern void *func_0216E95C(void *sys, u32 arg, u32 heap);
extern u16 func_021AAB48(char *p);
extern void *func_0200D418(void *sys);
extern u8 func_0200D488(struct Blk38 *p, u32 i);
extern void func_0215E440(void *sys, u8 which);
extern int func_0215E2B8(EncounterRecord *r, void *h, u32 k, u32 x);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_02005728(u32 range);
extern u32 func_02159168(u32);
extern u32 func_02188C5C(u8 *p);
extern u32 func_02188CFC(u8 *p);
extern int func_0218F0F8(u8 *a);
extern u32 func_021BB260(u32, u32);
extern void func_02159144(int n);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void func_0218F818(u8 *a);
extern void func_0218EC54(u8 *p);
extern u16 func_02011330(struct ScriptVm *vm);
extern u32 func_0201134C(struct ScriptVm *vm);
extern void func_0218F900(u8 *a, void *p, int n);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_0218FA40(u8 *p, u16 v);
extern void *func_021D2D50(void *a, struct Blk021D2D50 *src);
extern void *func_020124E4(struct Obj *p);
extern void *func_021F36C0(void *a, u8 *b, u32 c);
extern u32 func_021F36C8(u32 idx);
extern void func_0218E17C(u32 *p, u32 v);
extern u32 func_02188D24(u8 *p);
extern int *func_021BB990(int a, int *d, const int *c);
int func_021B3158(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void func_021B3258(int ctx, ShopWork *a, int b, int c);
void func_021B331C(ShopWork *w, int b);
u32 func_021B3350(ShopWork *w);
void func_021B3370(ShopWork *w);
void func_021B3470(ShopWork *p);
u8 func_021B34F4(ShopWork *p);
void func_021B3568(ShopWork *w, u32 b);
int func_021B35A4(u32 a, ShopWork *p, u32 c, u8 d);
u32 func_021B3834(ShopItem *items, int n);
void func_021B385C(ShopWork *p, int idx, int mode, int val, int arg);
void func_021B38E0(ShopWork *p, int a, int b, int c);
void func_021B39C4(ShopWork *p, int idx);
void func_021B3A64(ShopWork *p, int i);
void func_021B3B04(ShopWork *w);
int func_021B3B14(ShopWork *p, int a);
void func_021B3B84(ShopWork *p);
void func_021B3BD8(ShopWork *p);
void func_021B3C58(ShopWork *w);
void func_021B3C78(ShopWork *p);
void func_021B3CFC(ShopWork *w);
void func_021B3D60(ShopWork *w, u32 b);
void func_021B3DEC(ShopWork *w);
void func_021B3F00(ShopWork *w);
void func_021B3F3C(ShopWork *w);
void func_021B3FA0(ShopWork *w);
void func_021B40A8(ShopWork *w);
void func_021B40D4(ShopWork *w);
void func_021B41AC(ShopWork *w, u16 b);
void func_021B4264(ShopWork *w, u32 b);
void func_021B42D0(ShopWork *w, u32 a, u32 b);
void func_021B43EC(ShopWork *w);
void func_021B44CC(void *a, u32 b, int c, int d, u32 e, u32 f, u16 g);
void func_021B4510(u8 *p, int a, u8 b);
void func_021B45A0(u32 ctx, int a, u8 b);
void func_021B468C(u32 a, u32 idx);
void func_021B46FC(ShopWork *w);
int func_021B4710(void);
void func_021B4714(ShopWork *p, u32 sel, u32 c, u32 d);
void func_021B4804(ShopWork *w, u32 a);
void func_021B4878(u32 a);
void func_021B4894(ShopWork *w, u32 b);
void func_021B4918(ShopWork *w, u32 a, u16 b, u32 c, u16 d);
void func_021B4984(ShopWork *w, u32 a, u32 b, u32 c);
int func_021B49EC(s16 *p, int max, int key);
int func_021B4AA4(ShopWork *w);
void func_021B4BA4(int i);
int func_021B4BEC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B4C14(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B4C34(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B4C54(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B4C98(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B4CDC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
void func_021B4D14(volatile Ov170EventHandoff *handoff);
int func_021B4D60(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B4E58(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B4E9C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B4EE0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B4F1C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B4F68(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B4FB0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B5008(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B503C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B5094(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B50D0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B50F8(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B5128(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B5154(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
u16 func_021B5190(u16 *values, u16 count, u16 value);
int func_021B51BC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B52A4(void *fieldMap, void *fieldRegion);
int func_021B52E0(void **eventWork);
int func_021B52FC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B536C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B538C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B53A4(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B53BC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B542C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B5498(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B54D4(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B54FC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B5528(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B55C8(void *event);
int func_021B55F0(void *event);
int func_021B5610(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B5650(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B568C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern const LayerFlags d_021D9738;
extern const u8 d_021D9440[];
extern u8 d_021D946C[];
extern u8 d_021D95DE[];
extern u16 *d_021DE1A8[];
extern ShopItem *d_021DE164[];
extern u8 d_021D9430[];
extern const ShopActorPlacement d_021D96E0;
extern const ShopActorPlacement d_021D96E8;
extern const ShopActorPlacement d_021D96F0;
extern const ShopActorPlacement d_021D96F8;
extern const ShopActorPlacement d_021D9700;
extern ShopWindowTemplate *d_021DE18C[];
extern ShopWindowTemplate *d_021DE170[];
extern u32 d_021D945C[];
extern const ShopMaskRect d_021D9654[];
extern u8 abs_id_6[];
extern u8 abs_id_4[];
extern u8 abs_id_01[];
extern const char d_021DE220[];
extern char ov170_id[];
extern const u8 d_021EF78C[];
extern u8 abs_id_DB[];
extern u8 d_02185F0C[];
extern const char d_021DE234[];
extern const u16 d_021D98D0[];
extern u8 ov56_id[];
extern u32 g_021F4344[];
extern u32 g_021F4374[];
extern u32 g_021F438C[];
extern u32 g_021F435C[];






/*
 * Task callback armed by func_021B2FD8; steps the 0x214-byte work block it
 * allocated.
 *
 * Addresses are Black-image addresses.
 */
int func_021B3158(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    ShopTask **slot;
    ShopTask *task;
    void *gameSystem;
    void *fieldMap;
    void *fieldRegion;
    LayerFlags layers;

    slot = func_02158FB4(func_0215A5F4(cmdWork));
    task = *slot;
    gameSystem = func_0215A5DC(cmdWork);
    fieldMap = func_0201210C((void *)gameSystem);
    fieldRegion = func_02188C58(fieldMap);
    switch (task->state) {
    case 0:
        func_0218F0A8(fieldRegion);
        task->state++;
        break;
    case 1:
        if (func_0218F0E8(fieldRegion) == 0) {
            task->state++;
        }
        break;
    case 2:
        func_021B30C8((u32 *)task, (u32)fieldMap, fieldRegion);
        task->state++;
        break;
    case 3:
        if (func_0218FE50(fieldRegion) == 0) {
            task->state++;
            task->shop.state = 0;
            func_02193060(0);
        }
        break;
    case 4:
        if (func_021B35A4((u32)gameSystem, &task->shop, task->shopKind, task->shopVariant)) {
            task->state++;
        }
        break;
    case 5:
        layers = d_021D9738;
        func_0218F9C4(fieldRegion, (u8 *)(&layers), 8);
        task->state++;
        task->subState = 0;
        break;
    case 6:
        if (func_0218FE50(fieldRegion) == 0) {
            func_0218EC60((u32)fieldRegion);
            func_0218F1AC(fieldRegion, task->fieldRegionArg);
            func_0218F05C(fieldRegion);
            func_0218F878(fieldRegion);
            func_02193060(1);
            task->state++;
        }
        break;
    case 7:
        func_020307B0(*slot);
        return 1;
    }
    return 0;
}






void func_021B3258(int gameSystem, ShopWork *shop, int shopKind, int shopVariant)
{
    void *gameData = func_020120F4((void *)gameSystem);
    int tableKind;

    func_02012944(gameData);
    shop->isTmShop = 0;
    shopKind = func_021B3B14(shop, shopKind);
    tableKind = shopKind;
    switch (tableKind) {
    case 255:
        func_02012F08(gameData);
        func_021B38E0(shop, tableKind, shopVariant, func_0200C258());
        break;
    case 254:
        func_021B39C4(shop, 0);
        shop->usesBattlePoints = 1;
        break;
    case 253:
        shop->usesBattlePoints = 1;
        shop->isTmShop = 1;
        func_021B39C4(shop, 1);
        break;
    case 247:
    case 248:
    case 249:
    case 250:
    case 251:
        func_021B3A64(shop, tableKind);
        break;
    default:
        func_021B38E0(shop, tableKind, shopVariant, 0);
        break;
    }
    func_021B331C(shop, shop->usesBattlePoints);
    func_021B3BD8(shop);
    func_021B3FA0(shop);
    func_021B3F00(shop);
    func_021B40D4(shop);
    func_021B43EC(shop);
}





void func_021B331C(ShopWork *shop, int usesBattlePoints)
{
    if (usesBattlePoints == 1) {
        shop->priceFormat = func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0xd);
    } else {
        shop->priceFormat = func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0xc);
    }
    shop->soldOutText = func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0xe);
}




u32 func_021B3350(ShopWork *shop)
{
    if (shop->usesBattlePoints == 0) {
        return func_0200C274((struct Blk34 *)(shop->moneyData));
    } else {
        return func_0200DABC((struct Blk1AC *)(shop->battlePointData));
    }
}








void func_021B3370(ShopWork *shop)
{
    u32 money;
    u32 ownedCount;
    u32 price;

    money = func_021B3350(shop);
    ownedCount = func_02007FB8((u8 *)(shop->bagData), shop->itemId, shop->heapId);
    if (func_02007E3C((u8 *)(shop->bagData), shop->itemId, 1, shop->heapId) == 0) {
        func_021B4714(shop, 10, shop->itemId, 0);
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_LIST_RESUME;
        return;
    }
    price = shop->price;
    if (money < price) {
        if (shop->usesBattlePoints == 0) {
            func_021B4714(shop, 3, shop->itemId, 0);
        } else {
            func_021B4714(shop, 0x10, shop->itemId, 0);
        }
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_LIST_RESUME;
    } else if (money >= price && money < price * 2) {
        func_021B4804(shop, shop->isTmShop);
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_YESNO_OPEN;
    } else if (shop->isTmShop == 0) {
        func_021B4714(shop, 4, shop->itemId, 0);
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_QUANTITY_ENTER;
        shop->maxQuantity = money / shop->price;
        if (shop->maxQuantity > 99) {
            shop->maxQuantity = 99;
        }
        if (shop->maxQuantity + ownedCount > func_0200823C(shop->itemId)) {
            shop->maxQuantity = func_0200823C(shop->itemId) - ownedCount;
        }
    } else {
        func_021B4804(shop, shop->isTmShop);
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_YESNO_OPEN_NOICON;
    }
}









void func_021B3470(ShopWork *shop)
{
    void *window;
    int selection;
    ShopWork *row;

    if (func_0201C6B4(shop->printSys) == 0) {
        return;
    }
    if (shop->introShown == 0) {
        window = (void *)shop->windows[SHOP_WIN_LIST];
        func_02045334(window);
        func_02045374(window);
        func_020409B4(func_02045730(window));
        shop->introShown = shop->introShown + 1;
    }
    selection = func_020200CC(shop->listMenu);
    if (selection == -1) {
        return;
    }
    if (selection == -2) {
        shop->state = SHOP_STATE_EXIT;
        return;
    }
    /* stand-in: the row is reached as base + selection * 8 plus the field offset */
    row = (ShopWork *)((char *)shop + selection * 8);
    shop->itemId = row->items[0].itemId;
    shop->price = row->items[0].price;
    shop->quantity = 1;
    func_021B3370(shop);
}









u8 func_021B34F4(ShopWork *shop)
{
    int printState = func_0201CE30(shop->messagePrinter);

    if (printState == 2) {
        func_0201CE48(shop->messagePrinter);
        return shop->nextState;
    }
    if (printState == 0) {
        if ((func_0203630C() & 1) || (func_0203630C() & 2)) {
            func_0201CE5C(shop->messagePrinter, 0);
        }
    } else if (printState == 1) {
        if ((func_020362DC() & 1) || (func_020362DC() & 2)) {
            func_0201CE38(shop->messagePrinter);
            func_020061E4(1351);
        }
    }
    return shop->state;
}









void func_021B3568(ShopWork *shop, u32 cost)
{
    if (shop->usesBattlePoints == 0) {
        func_0200C29C((struct Blk34 *)(shop->moneyData), cost);
        func_02008DAC((struct Sub02008C20Obj *)(shop->recordData), 0x16, cost);
    } else {
        func_0200DA98((struct Blk1AC *)(shop->battlePointData), cost);
        func_02008DAC((struct Sub02008C20Obj *)(shop->recordData), 0x22, cost);
    }
    func_02008DF0((struct Sub02008C20Obj *)(shop->recordData), 0x15);
}









/*
 * Addresses are Black-image addresses.
 */
int func_021B35A4(u32 gameSystem, ShopWork *shop, u32 shopKind, u8 shopVariant)
{
    int selection;
    void *printSys;

    switch (shop->state) {
    case SHOP_STATE_INIT:
        func_021B3258(gameSystem, shop, shopKind, shopVariant);
        (shop->state)++;
        break;
    case SHOP_STATE_LIST_POLL:
        func_021B3470(shop);
        break;
    case SHOP_STATE_QUANTITY_ENTER:
        func_021B41AC(shop, shop->itemId);
        func_021B42D0(shop, shop->quantity, shop->price);
        func_0204B3DC((struct Obj *)shop->quantityArrowActor, 1);
        shop->state = SHOP_STATE_QUANTITY_STEP;
        break;
    case SHOP_STATE_QUANTITY_STEP:
        shop->state = func_021B4AA4(shop);
        break;
    case SHOP_STATE_LIST_RESUME:
        func_021B4BA4(0);
        func_02045374((struct Cfg *)(shop->windows[SHOP_WIN_LIST]));
        func_02045374((struct Cfg *)(shop->windows[SHOP_WIN_DESCRIPTION]));
        func_02041B6C(1);
        func_0204B3DC((struct Obj *)shop->quantityArrowActor, 0);
        func_02020234((u8 *)(shop->listMenu));
        shop->state = SHOP_STATE_LIST_POLL;
        break;
    case SHOP_STATE_YESNO_OPEN:
        func_021B4BA4(1);
        func_02045374((struct Cfg *)(shop->windows[SHOP_WIN_LIST]));
        func_0204B3DC((struct Obj *)shop->quantityArrowActor, 0);
        shop->yesNoMenu = func_0201FDA0(d_021D9440, 1, 9, 0, shop->heapId);
        if (shop->isTmShop != 1) {
            func_021B41AC(shop, shop->itemId);
        }
        shop->state = SHOP_STATE_YESNO_POLL;
        break;
    case SHOP_STATE_YESNO_OPEN_NOICON:
        func_021B4BA4(1);
        func_02045374((struct Cfg *)(shop->windows[SHOP_WIN_LIST]));
        func_0204B3DC((struct Obj *)shop->quantityArrowActor, 0);
        shop->yesNoMenu = func_0201FDA0(d_021D9440, 1, 9, 0, shop->heapId);
        shop->state = SHOP_STATE_YESNO_POLL;
        break;
    case SHOP_STATE_YESNO_POLL:
        selection = func_0201FEBC((u8 *)(shop->yesNoMenu));
        if (selection == -1) {
        } else if (selection == 0) {
            shop->state = SHOP_STATE_PURCHASE;
            func_021B4BA4(1);
            func_02020234((u8 *)(shop->listMenu));
            func_02045374((struct Cfg *)(shop->windows[SHOP_WIN_LIST]));
            func_02041B6C(1);
        } else if (selection == -2) {
            shop->state = SHOP_STATE_LIST_RESUME;
        }
        break;
    case SHOP_STATE_PURCHASE:
        func_020061E4(0x655);
        func_021B4714(shop, 9, shop->itemId, *(s16 *)&shop->quantity > 1);
        func_021B3568(shop, shop->price * *(s16 *)&shop->quantity);
        func_021B40D4(shop);
        func_02007E50((u8 *)(shop->bagData), shop->itemId, shop->quantity, shop->heapId);
        shop->state = SHOP_STATE_MESSAGE_WAIT;
        shop->nextState = SHOP_STATE_BONUS_ITEM;
        break;
    case SHOP_STATE_BONUS_ITEM:
        if (shop->itemId == 4 && *(s16 *)&shop->quantity >= 10) {
            func_021B4714(shop, 15, shop->itemId, *(s16 *)&shop->quantity > 1);
            func_02007E50((u8 *)(shop->bagData), 12, 1, shop->heapId);
            func_02008DF0((struct Sub02008C20Obj *)(shop->recordData), 0x1F);
            shop->state = SHOP_STATE_MESSAGE_WAIT;
            shop->nextState = SHOP_STATE_LIST_RESUME;
        } else {
            shop->state = SHOP_STATE_LIST_RESUME;
        }
        break;
    case SHOP_STATE_MESSAGE_WAIT:
        shop->state = func_021B34F4(shop);
        break;
    case SHOP_STATE_EXIT:
        func_021B46FC(shop);
        func_021B3F3C(shop);
        func_021B40A8(shop);
        func_021B3C58(shop);
        func_021B3B04(shop);
        func_021B3B84(shop);
        return 1;
    }
    func_0201C4E4((struct PrintSys *)(shop->printSys));
    printSys = shop->printSys;
    if (shop->printerBusy != 0 && func_0201C6C4((struct PrintSys *)printSys, (void *)((u32)func_02045770((struct Descriptor *)shop->listWindow))) == 0) {
        func_02045334((struct Descriptor *)shop->listWindow);
        shop->printerBusy = 0;
    }
    func_020310C4((struct Tcbl *)(shop->tcbList));
    func_020310C4((struct Tcbl *)(shop->tcbList));
    return 0;
}









u32 func_021B3834(ShopItem *items, int count)
{
    u32 result = func_02021288(items[0].itemId);
    int i;

    for (i = 0; i < count; i++) {
        func_02021288(items[i].itemId);
    }
    return result;
}








void func_021B385C(ShopWork *shop, int slotIndex, int isTmShop, int itemId, int msgBank)
{
    if (isTmShop == 1) {
        func_0201EFA4(shop->wordSet, 0, itemId - 327, 2, 2, 1);
        func_0201EF34(shop->wordSet, 1, func_020212B0((u16)itemId));
        func_0201F250(shop->wordSet, shop->textBuffer, shop->cancelText);
        func_0201F898((struct Slot *)((char *)shop->itemSlots + slotIndex * 8), (u32)(shop->textBuffer), slotIndex, shop->heapId);
    } else {
        func_0201F878((struct Slot *)((char *)shop->itemSlots + slotIndex * 8), msgBank, itemId, slotIndex, shop->heapId);
    }
}








/*
 * Spill slots: the image puts the tableIndex*4 offset at sp+4, msgBank at sp+8, itemCount at sp+0xc.
 * A single-def offset local is folded into a compiler temporary, and temps
 * take slots above every spilled local; the second (redundant) assignment in
 * the flag arm keeps off a real local, and declaration order (itemCount, msgBank, ..., tableOffset;
 * last declared lowest) gives the image layout.
 */
void func_021B38E0(ShopWork *shop, int shopKind, int shopVariant, int tierIndex)
{
    int itemCount;
    void *msgBank = func_02045B38(0, 2, 54, shop->heapId);
    int tableIndex;
    int row;
    int itemId;
    ShopWork *rowBase;
    int tableOffset;

    if (shopKind == 0xff) {
        tableIndex = d_021D946C[tierIndex];
    } else {
        tableIndex = shopVariant + 6;
    }
    tableOffset = tableIndex * 4;
    if (func_02021288(**(u16 **)((char *)d_021DE1A8 + tableOffset))) {
        shop->isTmShop = 1;
        tableOffset = tableIndex * 4;
    }
    itemCount = d_021D95DE[tableIndex];
    shop->itemSlots = func_0201F81C(itemCount + 1, shop->heapId);
    for (row = 0; row < itemCount; row++) {
        itemId = (*(u16 **)((char *)d_021DE1A8 + tableOffset))[row];
        func_021B385C(shop, row, shop->isTmShop, itemId, (int)msgBank);
        /* stand-in: the row is reached as base + row * 8 plus the field offset */
        rowBase = (ShopWork *)((char *)shop + row * 8);
        rowBase->items[0].itemId = itemId;
        rowBase->items[0].price = func_0201102C(func_02020FE4((void *)itemId, 0, shop->heapId));
    }
    shop->itemCount = row;
    func_021B3834(shop->items, shop->itemCount);
    func_0201F878((struct Slot *)((char *)shop->itemSlots + row * 8), (u32)(shop->shopMsgBank), 11, -2, shop->heapId);
    func_02045C04(msgBank);
}








void func_021B39C4(ShopWork *shop, int tableIndex)
{
    int row;
    ShopItem *table;
    u32 msgBank;
    int itemCount;

    row = 0;
    msgBank = (u32)func_02045B38(0, 2, 0x36, shop->heapId);
    table = d_021DE164[tableIndex];
    itemCount = d_021D9430[tableIndex];
    shop->itemSlots = func_0201F81C(itemCount + 1, shop->heapId);
    for (; row < itemCount; row++) {
        func_021B385C(shop, row, shop->isTmShop, table[row].itemId, msgBank);
        shop->items[row].itemId = table[row].itemId;
        shop->items[row].price = table[row].price;
    }
    shop->itemCount = row;
    func_0201F878((struct Slot *)((char *)shop->itemSlots + row * 8), (u32)shop->shopMsgBank, 0xb, -2, shop->heapId);
    func_02045C04((struct Rec *)msgBank);
}








void func_021B3A64(ShopWork *shop, int kind)
{
    int row = 0;
    void *msgBank = func_02045B38(0, 2, 54, shop->heapId);

    func_02186670((char *)shop->shopTable, (char *)shop->items, &shop->itemCount, kind - 247, shop->heapId);
    shop->itemSlots = func_0201F81C(shop->itemCount + 1, shop->heapId);
    for (; row < shop->itemCount; row++) {
        func_021B385C(shop, row, shop->isTmShop, shop->items[row].itemId, (int)msgBank);
    }
    func_0201F878((struct Slot *)((char *)shop->itemSlots + row * 8), (u32)(shop->shopMsgBank), 11, -2, shop->heapId);
    func_02045C04(msgBank);
}








/*
 * Unlabelled leaf (tail-call stub), called from func_021B35A4.
 *
 * Addresses are Black-image addresses.
 */
void func_021B3B04(ShopWork *shop)
{
    func_0201F868(shop->itemSlots);
}








int func_021B3B14(ShopWork *shop, int shopKind)
{
    shop->shopMsgBank = func_02045B38(0, 3, 423, shop->heapId);
    shop->itemMsgBank = func_02045B38(0, 2, 53, shop->heapId);
    shop->wordSet = func_0201EC64(shop->heapId);
    shop->textBuffer = func_020457B0(200, shop->heapId);
    shop->tcbList = func_0203101C(shop->heapId, shop->heapId, 32, 32);
    shop->cancelText = func_02045EC0(shop->shopMsgBank, 29);
    return shopKind;
}








void func_021B3B84(ShopWork *shop)
{
    func_02031140(shop->tcbList);
    func_0201ED04(shop->wordSet);
    func_02045808(shop->cancelText);
    func_02045808(shop->textBuffer);
    func_02045808(shop->soldOutText);
    func_02045808(shop->priceFormat);
    func_02045C04(shop->shopMsgBank);
    func_02045C04(shop->itemMsgBank);
}








void func_021B3BD8(ShopWork *shop)
{
    void *archive;

    *(volatile u16 *)0x04000050 = 0;
    archive = func_020490F4(54, shop->heapId);
    func_02049B68(archive, 1, 0, 0, 96, shop->heapId);
    func_02049658(archive, 0, 2, 100, 0, 0, shop->heapId);
    func_02049990(archive, 2, 2, 0, 100, 0, 0, shop->heapId);
    func_02049238(archive);
    func_0201F5BC(1, 228, 9, 0, shop->heapId);
    func_020414EC(1);
    func_0204047C(2, 1);
}








void func_021B3C58(ShopWork *shop)
{
    func_020414EC(1);
    func_020414EC(2);
    func_0204047C(2, 0);
    func_02193060(1);
}








void func_021B3C78(ShopWork *shop)
{
    void *archive = func_020490F4(54, shop->heapId);

    shop->arrowCharRes = (u32)func_0204AC18(archive, 10, 0, 0, 0, 1, shop->heapId);
    shop->cursorPlttRes = (u32)func_0204A6C8(archive, 7, 0, 0, shop->heapId);
    shop->arrowPlttRes = (u32)func_0204A6C8(archive, 4, 0, 0, shop->heapId);
    shop->cursorCellRes = (u32)func_0204AF28(archive, 8, 9, shop->heapId);
    shop->arrowCellRes = (u32)func_0204AF28(archive, 5, 6, shop->heapId);
    func_02049238(archive);
}








void func_021B3CFC(ShopWork *shop)
{
    shop->iconCharRes = (u32)func_0204AC18(shop->iconArchive, func_02020E60(1, 2), 0, 0x20, 0, 1, shop->heapId);
    shop->iconPlttRes = (u32)func_0204A6C8(shop->iconArchive, func_02020E60(1, 1), 0, 0, shop->heapId);
    shop->iconCellRes = (u32)func_0204AF28(shop->iconArchive, 1, 0, shop->heapId);
}







void func_021B3D60(ShopWork *shop, u32 itemId)
{
    u32 plttData;
    u32 charData;
    u32 charBuf;
    u32 plttBuf;

    if (itemId <= 0x272) {
        charBuf = (u32)func_02049F78((void *)(shop->iconArchive), func_02020E60(itemId, 2), (u32)(&charData), shop->heapId);
        plttBuf = (u32)func_02049E74((void *)(shop->iconArchive), func_02020E60(itemId, 1), 0, (u32)(&plttData), shop->heapId);
        func_0204ADEC(shop->iconCharRes, charData, 1);
        func_0204A9D0(shop->iconPlttRes, (struct Sub0204A9D0 *)plttData);
        func_020307B0((void *)charBuf);
        func_020307B0((void *)plttBuf);
        func_0204B3DC((struct Obj *)shop->iconActor, 1);
    } else {
        func_0204B3DC((struct Obj *)shop->iconActor, 0);
    }
}







void func_021B3DEC(ShopWork *shop)
{
    shop->cursorActor = (int)func_0204B294((void *)shop->cellSystem, shop->cursorPlttRes, shop->arrowCharRes,
                                        shop->cursorCellRes, &d_021D96E0, 0, shop->heapId);
    shop->arrowUpActor = (int)func_0204B294((void *)shop->cellSystem, shop->arrowPlttRes, shop->arrowCharRes,
                                        shop->arrowCellRes, &d_021D96E8, 0, shop->heapId);
    shop->arrowDownActor = (int)func_0204B294((void *)shop->cellSystem, shop->arrowPlttRes, shop->arrowCharRes,
                                        shop->arrowCellRes, &d_021D96F0, 0, shop->heapId);
    shop->quantityArrowActor = (int)func_0204B294((void *)shop->cellSystem, shop->arrowPlttRes, shop->arrowCharRes,
                                        shop->arrowCellRes, &d_021D96F8, 0, shop->heapId);
    func_0204B92C((struct Obj *)shop->quantityArrowActor, 1);
    shop->iconActor = (int)func_0204B294((void *)shop->cellSystem, shop->iconPlttRes, shop->iconCharRes,
                                        shop->iconCellRes, &d_021D9700, 0, shop->heapId);
    func_0204B3DC((struct Obj *)shop->arrowUpActor, 0);
    func_0204B3DC((struct Obj *)shop->arrowDownActor, 0);
    func_0204B3DC((struct Obj *)shop->quantityArrowActor, 0);
}







void func_021B3F00(ShopWork *shop)
{
    shop->cellSystem = func_0204B100(5, 1, shop->heapId);
    func_0204B22C((struct Bank *)(shop->cellSystem), 1);
    func_021B3C78(shop);
    shop->iconArchive = func_020490F4(0x19, shop->heapId);
    func_021B3CFC(shop);
    func_021B3DEC(shop);
}







void func_021B3F3C(ShopWork *shop)
{
    func_0204AFD8((u32)(shop->iconCellRes));
    func_0204AFD8((u32)(shop->arrowCellRes));
    func_0204AFD8((u32)(shop->cursorCellRes));
    func_0204A8D4((u32)(shop->iconPlttRes));
    func_0204A8D4((u32)(shop->arrowPlttRes));
    func_0204A8D4((u32)(shop->cursorPlttRes));
    func_0204ADA4((u32)(shop->iconCharRes));
    func_0204ADA4((u32)(shop->arrowCharRes));
    func_02049238(shop->iconArchive);
    func_0204B1CC(shop->cellSystem);
}







void func_021B3FA0(ShopWork *shop)
{
    ShopWindowTemplate **templates;
    ShopWindowTemplate *template;
    int i;
    u32 headerText;
    u32 window;

    templates = d_021DE18C;
    if (shop->usesBattlePoints != 1) {
        templates = d_021DE170;
    }
    for (i = 0; i < SHOP_WIN_COUNT; i++) {
        template = templates[i];
        shop->windows[i] = func_020450F0((u8)template->bgId, template->x, template->y, template->width, template->height, (u8)template->paletteNum, 1);
    }
    headerText = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0x14);
    func_0201C7D0((void *)((u32)func_02045770((struct Descriptor *)shop->windows[SHOP_WIN_HEADER])), 0, 0, (void *)headerText, (void *)(shop->fontInfo), 0x3C4F);
    func_02045808((struct U16Vec *)headerText);
    shop->listWindow = shop->windows[SHOP_WIN_LIST];
    shop->printerBusy = 0;
    shop->printSys = (void *)func_0201C440((void *)(shop->heapId));
    if (shop->usesBattlePoints == 1) {
        window = shop->windows[SHOP_WIN_MONEY];
        func_02045334((struct Descriptor *)window);
        func_02045374((struct Cfg *)window);
        func_020409B4(func_02045730((struct Descriptor *)window));
    } else {
        window = shop->windows[SHOP_WIN_HEADER];
        func_02045334((struct Descriptor *)window);
        func_02045374((struct Cfg *)window);
        func_020409B4(func_02045730((struct Descriptor *)window));
        window = shop->windows[SHOP_WIN_MONEY];
        func_02045334((struct Descriptor *)window);
        func_02045374((struct Cfg *)window);
        func_020409B4(func_02045730((struct Descriptor *)window));
    }
}







void func_021B40A8(ShopWork *shop)
{
    int i;

    func_0201C6EC((struct PrintSys *)(shop->printSys));
    func_0201C4C0((struct PrintSys *)(shop->printSys));
    for (i = 0; i < SHOP_WIN_COUNT; i++) {
        func_020452E8((struct Descriptor *)(shop->windows[i]));
    }
}







void func_021B40D4(ShopWork *shop)
{
    u32 formatText, expandedText, bitmap, window;

    if (shop->usesBattlePoints == 1) {
        formatText = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0x16);
        expandedText = (u32)func_020457B0(10, shop->heapId);
        func_0201EFA4((struct WordSet *)(shop->wordSet), 0, func_0200DABC((struct Blk1AC *)(shop->battlePointData)), 4, 1, 1);
    } else {
        formatText = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0x15);
        expandedText = (u32)func_020457B0(10, shop->heapId);
        func_0201EFA4((struct WordSet *)(shop->wordSet), 0, func_0200C274((struct Blk34 *)(shop->moneyData)), 7, 1, 1);
    }
    func_0201F250((struct WordSet *)(shop->wordSet), (void *)expandedText, (void *)formatText);
    bitmap = (u32)func_02045770((struct Descriptor *)shop->windows[SHOP_WIN_MONEY]);
    func_02043B5C((struct CharBuf *)bitmap, 0);
    func_0201C7D0((void *)bitmap, 0, 0, (void *)expandedText, (void *)(shop->fontInfo), 0x3C4F);
    window = shop->windows[SHOP_WIN_MONEY];
    func_02045334((struct Descriptor *)window);
    func_02045374((struct Cfg *)window);
    func_020409B4(func_02045730((struct Descriptor *)window));
    func_02045808((struct U16Vec *)expandedText);
    func_02045808((struct U16Vec *)formatText);
}







/*
 * The spilled second parameter is a u16 (func_021B3370 passes a u16 field
 * to func_02007FB8 in the same slot): as u32 its entry spill
 * `str r1, [sp, #8]` lands after the `lsls` instead of before it.
 *
 * Addresses are Black-image addresses.
 */
void func_021B41AC(ShopWork *shop, u16 itemId)
{
    u32 formatText, expandedText, bitmap, window;

    formatText = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0x17);
    expandedText = (u32)func_020457B0(0x14, shop->heapId);
    func_0201F73C((void *)(shop->windows[SHOP_WIN_OWNED]), 2, 0xE4, 9);
    func_0201EFA4((struct WordSet *)(shop->wordSet), 0, func_02007FB8((u8 *)(shop->bagData), itemId, shop->heapId), 3, 0, 1);
    func_0201F250((struct WordSet *)(shop->wordSet), (void *)expandedText, (void *)formatText);
    bitmap = (u32)func_02045770((struct Descriptor *)shop->windows[SHOP_WIN_OWNED]);
    func_02043B5C((struct CharBuf *)bitmap, 0xF);
    func_0201C7D0((void *)bitmap, 0, 0, (void *)expandedText, (void *)(shop->fontInfo), 0x44F);
    window = shop->windows[SHOP_WIN_OWNED];
    func_02045334((struct Descriptor *)window);
    func_02045374((struct Cfg *)window);
    func_020409B4(func_02045730((struct Descriptor *)window));
    func_02045808((struct U16Vec *)expandedText);
    func_02045808((struct U16Vec *)formatText);
}







void func_021B4264(ShopWork *shop, u32 itemId)
{
    u32 bitmap;
    u32 text;
    u32 window;

    bitmap = (u32)func_02045770((struct Descriptor *)shop->windows[SHOP_WIN_DESCRIPTION]);
    func_02043B5C((struct CharBuf *)bitmap, 0);
    if (itemId <= 0x272) {
        text = (u32)func_02045EC0((struct MsgBank *)(shop->itemMsgBank), itemId);
        func_0201C7D0((void *)bitmap, 0, 0, (void *)text, (void *)(shop->fontInfo), 0x3C40);
        func_02045808((struct U16Vec *)text);
    }
    window = shop->windows[SHOP_WIN_DESCRIPTION];
    func_02045334((struct Descriptor *)window);
    func_02045374((struct Cfg *)window);
    func_020409B4(func_02045730((struct Descriptor *)window));
}







void func_021B42D0(ShopWork *shop, u32 quantity, u32 price)
{
    u32 quantityFormat, totalFormat, text, bitmap, window;

    quantityFormat = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), 0x18);
    totalFormat = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), d_021D945C[shop->usesBattlePoints]);
    text = (u32)func_020457B0(0x14, shop->heapId);
    bitmap = (u32)func_02045770((struct Descriptor *)shop->windows[SHOP_WIN_QUANTITY]);
    func_02043B5C((struct CharBuf *)bitmap, 0xF);
    func_0201F73C((void *)(shop->windows[SHOP_WIN_QUANTITY]), 2, 0xE4, 9);
    func_0201EFA4((struct WordSet *)(shop->wordSet), 0, quantity, 2, 0, 1);
    func_0201F250((struct WordSet *)(shop->wordSet), (void *)text, (void *)quantityFormat);
    func_0201C7D0((void *)bitmap, 0, 0, (void *)text, (void *)(shop->fontInfo), 0x44F);
    func_0201EFA4((struct WordSet *)(shop->wordSet), 0, quantity * price, 7, 1, 1);
    func_0201F250((struct WordSet *)(shop->wordSet), (void *)text, (void *)totalFormat);
    if (shop->usesBattlePoints == 0) {
        func_0201C7D0((void *)bitmap, 0x23, 0, (void *)text, (void *)(shop->fontInfo), 0x44F);
    } else {
        func_0201C7D0((void *)bitmap, 0x1D, 0, (void *)text, (void *)(shop->fontInfo), 0x44F);
    }
    window = shop->windows[SHOP_WIN_QUANTITY];
    func_02045334((struct Descriptor *)window);
    func_02045374((struct Cfg *)window);
    func_020409B4(func_02045730((struct Descriptor *)window));
    func_02045808((struct U16Vec *)text);
    func_02045808((struct U16Vec *)totalFormat);
    func_02045808((struct U16Vec *)quantityFormat);
}







/*
 * Builds a 0x34-byte list template on the stack (layout as read by
 * func_0201FF30) and creates the list object from it.
 */
void func_021B43EC(ShopWork *shop)
{
    ShopListTemplate listTemplate;

    listTemplate.items = shop->itemSlots;
    listTemplate.cursorMoveFunc = (void *)func_021B468C;
    if (shop->isTmShop == 0) {
        listTemplate.printFunc = (void *)func_021B4510;
    } else {
        listTemplate.printFunc = (void *)func_021B45A0;
    }
    listTemplate.window = shop->windows[SHOP_WIN_LIST];
    listTemplate.count = func_0201F91C(shop->itemSlots);
    listTemplate.visibleRows = 7;
    listTemplate.headerX = 0;
    listTemplate.itemX = 0;
    listTemplate.cursorX = 0;
    listTemplate.fgColor = 8;
    listTemplate.shadowColor = 0xC;
    listTemplate.bgColor = 0;
    listTemplate.cursorColor = 0xD;
    listTemplate.lineSpacing = 0;
    listTemplate.cursorType = 0;
    listTemplate.reservedBits = 1;
    listTemplate.flagBits = 0;
    listTemplate.cancelable = 1;
    listTemplate.userData = shop;
    listTemplate.cursorSpriteX = 0xC;
    listTemplate.cursorSpriteY = 0x10;
    listTemplate.reserved24 = 0;
    listTemplate.activeWindowRef = &shop->listWindow;
    listTemplate.printSys = shop->printSys;
    listTemplate.fontInfo = shop->fontInfo;
    shop->listMenu = func_0201FF30((struct Src *)(&listTemplate), 0, 0, shop->heapId);
}






void func_021B44CC(void *printSys, u32 bitmap, int x, int y, u32 text, u32 fontInfo, u16 colorBits)
{
    if (y <= 8) {
        func_0201C7D0((void *)bitmap, x, y, (void *)text, (void *)fontInfo, colorBits);
    } else {
        func_0201C724(printSys, bitmap, (s16)x, (s16)y, text, fontInfo, (u32)colorBits);
    }
}






/*
 * Twin of func_021B45A0 (its else arm alone). The u8 third parameter is
 * what keeps the reload of its spill slot just before the last call; as u32
 * the reload is hoisted above the hi - lo subtraction. The first parameter
 * is forwarded untouched to func_02020D0C.
 *
 * Addresses are Black-image addresses.
 */
void func_021B4510(u8 *listMenu, int row, u8 y)
{
    ShopWork *shop;
    u32 textWidth;
    int windowWidth;

    shop = (ShopWork *)func_02020D0C(listMenu);
    if (row != -2) {
        func_0201EFA4((struct WordSet *)(shop->wordSet), 1, shop->items[row].price, 5, 0, 1);
        func_0201F250((struct WordSet *)(shop->wordSet), (void *)(shop->textBuffer), (void *)(shop->priceFormat));
        textWidth = func_0201D304((struct StrObj *)(shop->textBuffer), shop->fontInfo, 0);
        windowWidth = func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)shop->windows[SHOP_WIN_LIST])));
        func_021B44CC((void *)(shop->printSys), (u32)func_02045770((struct Descriptor *)shop->windows[SHOP_WIN_LIST]), windowWidth - textWidth, y,
                      (u32)shop->textBuffer, shop->fontInfo, 0x31A0);
    }
}






/*
 * The u8 third parameter (a list-cursor callback's on-init flag) is what
 * moves the reload of its spill slot to just before the last call; as int or
 * u32 the reload is hoisted above the hi - lo subtraction.
 */
void func_021B45A0(u32 listMenu, int row, u8 y)
{
    ShopWork *shop;
    u32 textWidth;
    int windowWidth;

    shop = (ShopWork *)func_02020D0C((void *)listMenu);
    if (row != -2) {
        if (func_02007F68((u8 *)(shop->bagData), shop->items[row].itemId, 1, shop->heapId) != 0) {
            textWidth = func_0201D304((struct StrObj *)(shop->soldOutText), shop->fontInfo, 0);
            windowWidth = func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)shop->windows[SHOP_WIN_LIST])));
            func_021B44CC((void *)(shop->printSys), (u32)func_02045770((struct Descriptor *)shop->windows[SHOP_WIN_LIST]), windowWidth - textWidth, y,
                          (u32)shop->soldOutText, shop->fontInfo, 0x31A0);
        } else {
            func_0201EFA4((struct WordSet *)(shop->wordSet), 1, shop->items[row].price, 5, 1, 1);
            func_0201F250((struct WordSet *)(shop->wordSet), (void *)(shop->textBuffer), (void *)(shop->priceFormat));
            textWidth = func_0201D304((struct StrObj *)(shop->textBuffer), shop->fontInfo, 0);
            windowWidth = func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)shop->windows[SHOP_WIN_LIST])));
            func_021B44CC((void *)(shop->printSys), (u32)func_02045770((struct Descriptor *)shop->windows[SHOP_WIN_LIST]), windowWidth - textWidth, y,
                          (u32)shop->textBuffer, shop->fontInfo, 0x31A0);
        }
    }
}






void func_021B468C(u32 listMenu, u32 row)
{
    u16 cursorPos[4];
    ShopWork *shop;
    ShopItem *items;

    shop = (ShopWork *)func_02020D0C((void *)listMenu);
    func_020202FC((struct Obj *)listMenu, &cursorPos[1], &cursorPos[0]);
    cursorPos[2] = 0xAC;
    cursorPos[3] = cursorPos[0] * 16 + 0x16;
    func_0204B404((struct Obj *)(shop->cursorActor), (const struct Vec2 *)(&cursorPos[2]), 0);
    if (row < 0x28) {
        items = shop->items;
        func_021B4264(shop, items[row].itemId);
        func_021B3D60(shop, items[row].itemId);
    } else {
        func_021B4264(shop, 0xFFFF);
        func_021B3D60(shop, 0xFFFF);
    }
}






void func_021B46FC(ShopWork *shop)
{
    u16 scrollPos;
    u16 cursorPos;

    func_0202020C((struct Obj *)(shop->listMenu), &scrollPos, &cursorPos);
}





/*
 * Untraced blob: constant zero return.
 *
 * Addresses are Black-image addresses.
 */
int func_021B4710(void)
{
    return 0;
}





void func_021B4714(ShopWork *shop, u32 messageId, u32 itemId, u32 plural)
{
    u32 isPlural;
    u32 messageText;
    u32 window;

    if (messageId == 9 && plural != 0)
        isPlural = 1;
    else
        isPlural = 0;
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)shop->windows[SHOP_WIN_MESSAGE])), 0xf);
    func_0201F73C((void *)(shop->windows[SHOP_WIN_MESSAGE]), 0, 0xe4, 9);
    func_0201EF6C((struct WordSet *)(shop->wordSet), 0, itemId, isPlural, 0);
    func_0201F14C((struct WordSet *)(shop->wordSet), 1, func_02020FE4((void *)itemId, 5, shop->heapId));
    messageText = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), messageId);
    func_0201F250((struct WordSet *)(shop->wordSet), (void *)(shop->textBuffer), (void *)messageText);
    func_02045808((struct U16Vec *)messageText);
    shop->messagePrinter = func_0201CD10(shop->windows[SHOP_WIN_MESSAGE], 0, 0, (u32)shop->textBuffer,
                                        shop->fontInfo, func_02012FFC(),
                                        (u32)shop->tcbList, 0, shop->heapId, 0xffff,
                                        (u32)func_021B4710);
    window = shop->windows[SHOP_WIN_MESSAGE];
    func_02045334((struct Descriptor *)window);
    func_02045374((struct Cfg *)window);
    func_020409B4(func_02045730((struct Descriptor *)window));
}





void func_021B4804(ShopWork *shop, u32 isTmShop)
{
    if (shop->isTmShop == 1) {
        if (shop->usesBattlePoints == 1) {
            func_021B4984(shop, 8, shop->itemId, shop->price);
        } else {
            func_021B4984(shop, 7, shop->itemId, shop->price);
        }
    } else {
        if (shop->usesBattlePoints == 1) {
            func_021B4918(shop, 6, shop->itemId, shop->price, shop->quantity);
        } else {
            func_021B4918(shop, 5, shop->itemId, shop->price, shop->quantity);
        }
    }
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021B4878(u32 window)
{
func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)window)), 15);
    func_0201F73C((void *)window, 0, 228, 9);
}




void func_021B4894(ShopWork *shop, u32 messageId)
{
    u32 messageText;
    u32 window;

    messageText = (u32)func_02045EC0((struct MsgBank *)(shop->shopMsgBank), messageId);
    func_0201F250((struct WordSet *)(shop->wordSet), (void *)(shop->textBuffer), (void *)messageText);
    func_02045808((struct U16Vec *)messageText);
    shop->messagePrinter = func_0201CD10(shop->windows[SHOP_WIN_MESSAGE], 0, 0, (u32)shop->textBuffer,
                                        shop->fontInfo, func_02012FFC(), (u32)shop->tcbList, 0,
                                        shop->heapId, 0xFFFF, 0);
    window = shop->windows[SHOP_WIN_MESSAGE];
    func_02045334((struct Descriptor *)window);
    func_02045374((struct Cfg *)window);
    func_020409B4(func_02045730((struct Descriptor *)window));
}




/*
 * The spilled third parameter is narrow (u16 here; s16/u8 give the same
 * bytes): as u32/int its entry spill `str r2, [sp, #8]` lands after the
 * `lsls` instead of before it.
 *
 * Addresses are Black-image addresses.
 */
void func_021B4918(ShopWork *shop, u32 messageId, u16 itemId, u32 price, u16 quantity)
{
    func_021B4878(shop->windows[SHOP_WIN_MESSAGE]);
    func_0201EF6C((struct WordSet *)(shop->wordSet), 0, itemId, 0, 0);
    func_0201EFA4((struct WordSet *)(shop->wordSet), 1, quantity, 2, 0, 1);
    func_0201EFA4((struct WordSet *)(shop->wordSet), 2, quantity * price, 7, 0, 1);
    func_021B4894(shop, messageId);
}




void func_021B4984(ShopWork *shop, u32 messageId, u32 itemId, u32 price)
{
    func_021B4878(shop->windows[SHOP_WIN_MESSAGE]);
    func_0201EFA4((struct WordSet *)(shop->wordSet), 0, itemId - 327, 2, 2, 1);
    func_0201EF34((struct WordSet *)(shop->wordSet), 1, func_020212B0(itemId));
    func_0201EFA4((struct WordSet *)(shop->wordSet), 2, price, 5, 0, 1);
    func_021B4894(shop, messageId);
}




int func_021B49EC(s16 *value, int maxValue, int step)
{
    int oldValue = *value;
    switch (step) {
    case -1:
        *value = oldValue - 1;
        if (*value <= 0) *value = maxValue;
        if (*value == oldValue) return 0;
        return 2;
    case -10:
        *value = oldValue - 10;
        if (*value <= 0) *value = 1;
        if (*value == oldValue) return 0;
        return 2;
    case 1:
        *value = oldValue + 1;
        if (*value > maxValue) *value = 1;
        if (*value == oldValue) return 0;
        return 1;
    case 10:
        *value = oldValue + 10;
        if (*value > maxValue) *value = maxValue;
        if (*value == oldValue) return 0;
        return 1;
    }
    return 0;
}




int func_021B4AA4(ShopWork *shop)
{
    if (func_0203633C() & 0x40) {
        if (func_021B49EC((s16 *)&shop->quantity, (u16)shop->maxQuantity, 1) != 0) {
            func_020061E4(0x548);
            func_021B42D0(shop, shop->quantity, shop->price);
        }
    } else if (func_0203633C() & 0x80) {
        if (func_021B49EC((s16 *)&shop->quantity, (u16)shop->maxQuantity, -1) != 0) {
            func_020061E4(0x548);
            func_021B42D0(shop, shop->quantity, shop->price);
        }
    } else if (func_0203633C() & 0x20) {
        if (func_021B49EC((s16 *)&shop->quantity, (u16)shop->maxQuantity, -10) != 0) {
            func_020061E4(0x548);
            func_021B42D0(shop, shop->quantity, shop->price);
        }
    } else if (func_0203633C() & 0x10) {
        if (func_021B49EC((s16 *)&shop->quantity, (u16)shop->maxQuantity, 10) != 0) {
            func_020061E4(0x548);
            func_021B42D0(shop, shop->quantity, shop->price);
        }
    }
    if (func_020362DC() & 1) {
        func_020061E4(0x54C);
        func_021B4804(shop, shop->isTmShop);
        shop->nextState = SHOP_STATE_YESNO_OPEN_NOICON;
        return SHOP_STATE_MESSAGE_WAIT;
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        return SHOP_STATE_LIST_RESUME;
    }
    return SHOP_STATE_QUANTITY_STEP;
}




/*
 * d_021D9654 is a const table of 16-byte {x, y, w, h} records (two of them
 * in the listing: {0,12,32,12}, {0,12,32,6}). Without const the loads for
 * the register arguments cannot pass the first stack-argument store and
 * are issued after it; func_02041300's u8 parameters follow the ldrb reads
 * of its stack arguments (as in src/matched/arm9/func_0201F628.c).
 * Addresses are Black-image addresses.
 */
void func_021B4BA4(int i)
{
    func_02041300(1, 0, d_021D9654[i].x, d_021D9654[i].y, d_021D9654[i].w, d_021D9654[i].h, 0);
}




int func_021B4BEC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = func_0215A5DC(cmdWork);
    u16 *resultVar = func_02159AE8(vm, cmdWork);

    *resultVar = func_021896F4((void *)func_02012138(gameSystem));
    return 1;
}




int func_021B4C14(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
*func_02159AE8(vm, cmdWork) = func_02009CE4((struct Sub020097BCObj *)func_0201283C(func_0215A5E4(cmdWork)));
return 0;
}




int func_021B4C34(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
*func_02159AE8(vm, cmdWork) = func_02009A34((struct Sub020097BCObj *)func_0201283C(func_0215A5E4(cmdWork)));
return 0;
}




int func_021B4C54(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FieldEventArgs args;
    void *scriptWork;
    void *gameSystem;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    args.fieldMap = func_0201210C(gameSystem);
    args.reserved = 0;
    func_0215897C(scriptWork, func_020124AC(gameSystem, (u32)abs_id_6, (void *)func_02154C20, (u32)(&args)));
    return 1;
}




int func_021B4C98(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FieldEventArgs args;
    void *scriptWork;
    void *gameSystem;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    args.fieldMap = func_0201210C(gameSystem);
    args.reserved = 0;
    func_0215897C(scriptWork, func_020124AC(gameSystem, (u32)abs_id_4, (void *)func_021542C0, (u32)(&args)));
    return 1;
}




/*
 * 2026-10-02: closed by seeding ov001 0x02154694 (Thumb tail-call thunk to
 * func_0215466C, filed as ov001_func_02154694.c). Old note: it sat inside ov001 pool_02154690
 * (ldr r3,[pc]; bx r3; .word func_0215466C+1) so sole-ref/code finds no func_ label;
 * abs_id_01 is the overlay id 1 that func_020124AC loads (not an OVERLAY_ID_CONSUMER).
 *
 * Addresses are Black-image addresses.
 */
int func_021B4CDC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_0215897C(scriptWork, func_020124AC(gameSystem, (u32)abs_id_01, (u32 (*)(void *, u32))func_02154694, (u32)func_0201210C(gameSystem)));
    return 1;
}




void func_021B4D14(volatile Ov170EventHandoff *handoff)
{
    u32 resultFlag;
    u32 result;
    Ov170EventWork *work;

    if (handoff->work->kind == 4) {
        func_0200BB58(func_0200BAC8(func_02012EBC((struct Big *)handoff->gameData)), (u8 *)handoff->work->party);
    }
    work = handoff->work;
    if (work->kind == 4) {
        func_020307B0(work->party);
    }
    result = handoff->work->result;
    if (result == 0 || result != 1)
        resultFlag = 0;
    else
        resultFlag = 1;
    *handoff->resultVar = resultFlag;
    func_020307B0(handoff->work);
}




/*
 * Script command: builds a 0x2C-byte work (save handles, the hand-off kind
 * at +0x24) and a 12-byte hand-off record, then launches overlay 0xAA
 * (ov170) over them through func_02014840 with the func_021B4D14 callback
 * and parks the task in the script's slot.  Same shape as the ov010
 * pending func_0215C7E0.
 *
 * The new work block is assigned to the first parameter (vm) and then
 * read through the typed pointer work: with an independent local, work and
 * the save handle gameData swap r4/r5 whatever the declaration order
 * (docs/idioms/reassigning-a-parameter-to-the-callee-result-keeps-its-
 * register.md).
 *
 * Blocker (MATCH, every concrete byte right, 24 of 25 sites resolved): the
 * pool word 0x000000AA (ov170_id, +0xF0) has no witness.  It is the
 * overlay-id argument (r2) of func_02014840, which is not in
 * OVERLAY_ID_CONSUMERS; func_02014840 (EXACT, arm9) stores its a2 as
 * p[2] of the item func_020122C0 creates, the same shape as the
 * func_02012444 case ov000 func_021542C0's header describes.  Adding
 * 0x02014840 with register 2 to OVERLAY_ID_CONSUMERS (integrator's call,
 * after reading the item's state machine) would resolve it.  ov021 holds
 * one other 0xAA pool word (0x021D5598), yet match.py still reports no
 * witness: a small overlay-id value resolves only through that consumer
 * table, so no cut helps.
 *
 * Addresses are Black-image addresses.
 */
int func_021B4D60(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;
    void *gameData;
    void *saveControl;
    void *saveStateSource;
    void *fieldMap;
    unsigned short *resultVar;
    u32 kind;
    Ov170EventHandoff *handoff;
    void *saveBlock;
    Ov170EventWork *work;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_020120F4(gameSystem);
    saveControl = func_02012EBC(gameData);
    saveStateSource = func_0200CA1C(gameData);
    fieldMap = func_0201210C(gameSystem);
    resultVar = func_02159AE8(vm, cmdWork);
    kind = func_02159B10(vm, cmdWork);
    vm = func_02030734(4, 0x2c, 0, d_021DE220, 0x7c);
    work = (Ov170EventWork *)vm;
    work->gameData = gameData;
    work->boxManager = func_0201293C(gameData);
    work->party = func_02012934(gameData);
    work->myItem = (u32)func_0201292C(gameData);
    work->myStatus = func_02012944(gameData);
    work->saveStateA = (u32)func_0200873C(saveControl);
    work->saveStateB = func_0200CA38(saveStateSource);
    work->kind = kind;
    work->extraData = 0;
    if (kind == 4) {
        saveBlock = func_0200BAC8(saveControl);
        work->party = func_0200BAF4((int)saveBlock, 4);
        work->extraData = func_0200BBFC(saveBlock, 3);
    }
    handoff = func_02030734(4, 0xc, 0, d_021DE220, 0x90);
    handoff->gameData = gameData;
    handoff->resultVar = resultVar;
    handoff->work = work;
    func_0215897C(scriptWork, func_02014840(gameSystem, (int)fieldMap, (u32)ov170_id, (int)d_021EF78C, (int)work, (int)((void *)func_021B4D14), (int)handoff));
    return 1;
}




int func_021B4E58(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;
    void *fieldMap;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    fieldMap = func_0201210C(gameSystem);
    func_0215897C(scriptWork, (void *)func_021CD2A4((u32)gameSystem, (u32)fieldMap, 0, 5, (u32)func_02159AE8(vm, cmdWork)));
    return 1;
}




int func_021B4E9C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;
    void *fieldMap;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    fieldMap = func_0201210C(gameSystem);
    func_0215897C(scriptWork, (void *)func_021CD2A4((u32)gameSystem, (u32)fieldMap, 0, 6, (u32)func_02159AE8(vm, cmdWork)));
    return 1;
}




int func_021B4EE0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    void *gameSystem = func_0215A5DC(cmdWork);

    func_0201210C(gameSystem);
    func_0215898C((int)scriptWork, (int)func_0215F8A8(gameSystem, func_02159B10(vm, cmdWork)));
    func_02011290(vm);
    return 1;
}




int func_021B4F1C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 saveBlock;
    u32 eventArg;
    void *scriptWork;
    void *gameSystem;

    saveBlock = (u32)func_02009210(func_02012EBC(func_0215A5E4(cmdWork)));
    eventArg = func_02159B10(vm, cmdWork);
    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_020090D8((struct Sub020090B0Obj *)saveBlock, 1);
    func_0215897C(scriptWork, func_02168BBC(gameSystem, (void *)eventArg));
    return 1;
}




int func_021B4F68(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem;
    void *scriptWork;
    void *fieldMap;

    gameSystem = func_0215A5DC(cmdWork);
    scriptWork = func_0215A5F4(cmdWork);
    fieldMap = func_0201210C(gameSystem);
    func_0215897C(scriptWork, func_020146F8(gameSystem, (int)fieldMap, (int)abs_id_DB, (int)d_02185F0C, (int)func_020120F4(gameSystem)));
    return 1;
}




int func_021B4FB0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    void *gameSystem;
    u32 flag;
    unsigned short *resultVar;
    u32 flagBool;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    func_02012EBC(func_020120F4(gameSystem));
    func_0201210C(gameSystem);
    flag = func_02159B10(vm, cmdWork);
    resultVar = func_02159AE8(vm, cmdWork);
    if (flag == 0 || flag != 1)
        flagBool = 0;
    else
        flagBool = 1;
    func_0215897C(scriptWork, func_021C5BD0(gameSystem, flagBool, (u32)resultVar));
    return 1;
}




int func_021B5008(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem = func_0215A5DC(cmdWork);
    void *scriptWork = func_0215A5F4(cmdWork);

    func_0215897C(scriptWork, func_021D30B8(gameSystem, func_02159AE8(vm, cmdWork)));
    return 1;
}




int func_021B503C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork;
    u32 eventParam0;
    u32 eventParam1;
    u32 eventParam2;

    scriptWork = func_0215A5F4(cmdWork);
    eventParam0 = func_02159B10(vm, cmdWork);
    eventParam1 = func_02159B10(vm, cmdWork);
    eventParam2 = func_02159B10(vm, cmdWork);
    func_02158F54(scriptWork);
    func_0215897C(scriptWork, (void *)func_021AA0A0(func_02188CE8((u8 *)(((u32 *)func_02158F58((int)scriptWork))[1])), eventParam0, (u8)eventParam1, eventParam2));
    return 1;
}




int func_021B5094(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    void *gameSystem = func_0215A5DC(cmdWork);

    func_0215897C(scriptWork, (void *)func_021BE92C(gameSystem, (int)func_0201210C(gameSystem), 0, 0, 1, 0, 0));
    return 1;
}




/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int func_021B50D0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 flagValue = func_02012A44(func_0215A5E4(cmdWork));
    u16 *resultVar = func_02159AE8(vm, cmdWork);

    *resultVar = func_0216EFCC(flagValue);
    return 0;
}




int func_021B50F8(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    void *gameSystem = func_0215A5DC(cmdWork);

    func_0215897C(scriptWork, func_0216E95C(gameSystem, (u32)func_0201210C(gameSystem), 4));
    return 1;
}




int func_021B5128(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *fieldMap = func_0201210C(func_0215A5DC(cmdWork));
    u16 *resultVar = func_02159AE8(vm, cmdWork);

    *resultVar = func_021AAB48((char *)func_02188CE8(fieldMap));
    return 0;
}




int func_021B5154(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameData = func_0215A5E4(cmdWork);
    u32 flagBlock = (u32)func_0200D418(func_02012EBC(gameData));
    u8 flagIndex = func_02159B10(vm, cmdWork);

    if (func_0200D488((struct Blk38 *)flagBlock, flagIndex) == 0) {
        func_0215E440(gameData, flagIndex);
    }
    return 0;
}




u16 func_021B5190(u16 *values, u16 count, u16 value)
{
    int i;

    for (i = 0; i < count; i++) {
        if (value == values[i]) {
            return count;
        }
    }
    values[count] = value;
    return count + 1;
}




/*
 * func_0215E2B8 clears and fills a 0xE8-byte record (its own memset size).
 *
 * Addresses are Black-image addresses.
 */
int func_021B51BC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    EncounterRecord record;
    u32 season;
    u16 tableIndex;
    void *archive;
    u16 *resultVar;
    void *gameData;
    u16 *speciesList;
    u16 slot;
    u16 count;

    count = 0;
    gameData = func_0215A5E4(cmdWork);
    resultVar = func_02159AE8(vm, cmdWork);
    season = func_02012984(gameData);
    archive = func_020490F4(0x7e, 0x8015);
    speciesList = func_02030734(0x8015, 0x78, 1, d_021DE234, 0xf8);
    for (tableIndex = 0; tableIndex < 6; tableIndex++) {
        if (func_0215E2B8(&record, archive, d_021D98D0[tableIndex], season)) {
            if (record.hasSetA) {
                for (slot = 0; slot < 5; slot++) {
                    count = func_021B5190(speciesList, count, record.setA[slot].species);
                }
            }
            if (record.hasSetB) {
                for (slot = 0; slot < 5; slot++) {
                    count = func_021B5190(speciesList, count, record.setB[slot].species);
                }
            }
        }
    }
    *resultVar = speciesList[func_02005728(count)];
    func_020307B0(speciesList);
    func_02049238(archive);
    return 0;
}




int func_021B52A4(void *fieldMap, void *fieldRegion)
{
func_0218F878(fieldRegion);
if (func_0218F0F8(fieldRegion) != 0) {
    func_0218F05C(fieldRegion);
}
if (func_02188CFC(fieldMap) == 1) {
    func_021BB260(func_02188C5C(fieldMap), 1);
}
return func_02159168(0);
}




int func_021B52E0(void **eventWork)
{
    void *fieldMap = func_0201210C(eventWork[0]);

    func_021B52A4(fieldMap, func_02188C58(fieldMap));
    return 1;
}




int func_021B52FC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *gameSystem;
    void *fieldMap;
    void *fieldRegion;

    gameSystem = func_0215A5DC(cmdWork);
    fieldMap = func_0201210C(gameSystem);
    fieldRegion = func_02188C58(fieldMap);
    func_02159144(0);
    if (func_0218F0F8(fieldRegion) != 0) {
        func_0218F0A8(fieldRegion);
        fieldRegion = func_0215A5F4(cmdWork);
        func_0215897C(fieldRegion, func_020122C0(gameSystem, 0, (void *)func_021B55C8, 0));
        if (func_02188CFC(fieldMap) == 1) {
            func_021BB260(func_02188C5C(fieldMap), 0);
        }
    } else {
        func_0218F818(fieldRegion);
    }
    return 1;
}




int func_021B536C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *fieldMap = func_0201210C(func_0215A5DC(cmdWork));

    func_021B52A4(fieldMap, func_02188C58(fieldMap));
    return 0;
}




int func_021B538C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
func_0218EC54(func_02188C58(func_0201210C(func_0215A5DC(cmdWork))));
return 0;
}




int func_021B53A4(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
func_0218EC60((u32)func_02188C58(func_0201210C(func_0215A5DC(cmdWork))));
return 0;
}




int func_021B53BC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FieldRegionParam param;
    void *fieldRegion;

    fieldRegion = func_02188C58(func_0201210C(func_0215A5DC(cmdWork)));
    param.areaWidth = func_02011330(vm);
    param.areaHeight = func_02011330(vm);
    param.areaFlags = func_0201134C(vm);
    param.origin.x = func_0201134C(vm);
    param.origin.y = func_0201134C(vm);
    param.origin.z = func_0201134C(vm);
    param.layers.flag[0] = 0;
    param.layers.flag[1] = 1;
    param.layers.flag[2] = 1;
    param.layers.flag[3] = 1;
    param.layers.flag[4] = 0;
    param.layers.flag[5] = 1;
    func_0218F900(fieldRegion, &param, func_02011330(vm));
    return 0;
}




int func_021B542C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    FieldRegionRecord record;
    FieldRegionParam param;
    void *fieldRegion;
    int memberIndex;
    int regionIndex;

    fieldRegion = func_02188C58(func_0201210C(func_0215A5DC(cmdWork)));
    memberIndex = func_02011330(vm);
    regionIndex = func_02011330(vm);
    func_02048F4C(&record, 0xa3, memberIndex);
    param.areaWidth = record.areaWidth;
    param.areaHeight = record.areaHeight;
    param.areaFlags = record.areaFlags;
    param.origin = record.origin;
    param.layers = record.layers;
    func_0218F900(fieldRegion, &param, regionIndex);
    return 0;
}




int func_021B5498(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    LayerFlags layers;
    void *fieldRegion = func_02188C58(func_0201210C(func_0215A5DC(cmdWork)));
    u16 regionIndex = func_02011330(vm);

    layers.flag[0] = 1;
    layers.flag[1] = 1;
    layers.flag[2] = 1;
    layers.flag[3] = 1;
    layers.flag[4] = 1;
    layers.flag[5] = 1;
    func_0218F9C4(fieldRegion, (u8 *)&layers, regionIndex);
    return 0;
}




int func_021B54D4(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
func_0218FA40(func_02188C58(func_0201210C(func_0215A5DC(cmdWork))), func_02011330(vm));
return 0;
}




int func_021B54FC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    void *gameSystem = func_0215A5DC(cmdWork);

    func_0215897C(scriptWork, func_020122C0(gameSystem, 0, func_021B55F0, 0));
    return 1;
}




int func_021B5528(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int arg0 = func_02159B10(vm, cmdWork);
    int arg1 = func_02159B10(vm, cmdWork);
    int arg2 = func_02159B10(vm, cmdWork);
    int arg3 = func_02159B10(vm, cmdWork);
    int arg4 = func_02159B10(vm, cmdWork);
    int arg5 = func_02159B10(vm, cmdWork);
    int arg6 = func_02159B10(vm, cmdWork);
    int arg7 = func_02159B10(vm, cmdWork);
    void *scriptWork;
    void *gameSystem;
    CustomEventParam param;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    param.eventId = arg0;
    param.eventKind = arg1;
    param.scriptId = arg2;
    param.kindCopy = arg3;
    param.kind = arg3;
    param.reserved14 = 0;
    param.mapX = arg4;
    param.mapY = arg5;
    param.mapZ = arg6;
    param.reserved0A = 0;
    param.facing = arg7;
    func_0215897C(scriptWork, func_021D2D50(gameSystem, (struct Blk021D2D50 *)(&param)));
    return 1;
}




int func_021B55C8(void *event)
{
    u8 *fieldRegion = func_02188C58(func_0201210C(func_020124E4(event)));

    if (func_0218F0E8(fieldRegion) == 0) {
        func_0218F818(fieldRegion);
        return 1;
    }
    return 0;
}




int func_021B55F0(void *event)
{
    int busy = func_0218FE50(func_02188C58(func_0201210C(func_020124E4(event))));

    return busy != 0 ? B_FALSE : B_TRUE;
}




int func_021B5610(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    void *gameSystem = func_0215A5DC(cmdWork);
    u8 *fieldMap = func_0201210C(gameSystem);
    unsigned int slotNumber = func_02159B10(vm, cmdWork);

    func_0215897C(scriptWork, func_021F36C0(gameSystem, fieldMap, (u16)(slotNumber - 1)));
    return 1;
}




/*
 * func_021F36C8 is the ov056 slot-table lookup (src/matched/ov/ov056_func_021F36C8.c).
 */
int func_021B5650(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *fieldMap = func_0201210C(func_0215A5DC(cmdWork));
    unsigned int slotNumber = func_02159B10(vm, cmdWork);
    u32 *fieldRegion = func_02188C58(fieldMap);

    func_0218E17C(fieldRegion, func_021F36C8((u16)(slotNumber - 1)));
    return 0;
}




int func_021B568C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    int regionTable = func_02188D24(func_0201210C(func_0215A5DC(cmdWork)));

    switch (func_02159B10(vm, cmdWork)) {
    case 0:
        break;
    case 1:
        func_021BB990((int)ov56_id, (int *)regionTable, (const int *)g_021F4344);
        break;
    case 2:
        func_021BB990((int)ov56_id, (int *)regionTable, (const int *)g_021F4374);
        break;
    case 3:
        func_021BB990((int)ov56_id, (int *)regionTable, (const int *)g_021F438C);
        break;
    case 4:
        func_021BB990((int)ov56_id, (int *)regionTable, (const int *)g_021F435C);
        break;
    }
    return 0;
}
