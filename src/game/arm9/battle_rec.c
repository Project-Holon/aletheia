/*
 * file:     battle_rec.c
 * unit:     yes
 * function: func_0200B2A4, func_0200B348, func_0200B358, func_0200B364, func_0200B368, func_0200B37C, func_0200B394, func_0200B3A4, func_0200B3A8, func_0200B3AC, func_0200B3B0, func_0200B3C8, func_0200B3DC, func_0200B400, func_0200B424, func_0200B438, func_0200B440, func_0200B448, func_0200B45C, func_0200B480, func_0200B490, func_0200B4B8, func_0200B4E0, func_0200B570, func_0200B5A4, func_0200B5CC, func_0200B67C, func_0200B6E0, func_0200B784, func_0200B7D8, func_0200B888, func_0200B8AC, func_0200B900, func_0200B908, func_0200B910, func_0200B91C, func_0200B928, func_0200B934, func_0200B938, func_0200B98C, func_0200BA38, func_0200BA44, func_0200BA58, func_0200BA68, func_0200BA78, func_0200BA80, func_0200BAC8, func_0200BAD4, sub_0200BAF4, func_0200BB58, func_0200BBA8, func_0200BBC8, func_0200BBD8, func_0200BBEC, func_0200BBFC, func_0200BC10, func_0200BC20, func_0200BC2C, func_0200BC4C, func_0200BC88, func_0200BCA0, func_0200BCA8, func_0200BCB8, func_0200BCD8, func_0200BCEC, func_0200BD48, func_0200BD98, func_0200BDA0, func_0200BDB0, func_0200BDBC, func_0200BDC4, func_0200BDE4, func_0200BDF8, func_0200BDFC, func_0200BE00, func_0200BE24, func_0200BE48, func_0200BE54, func_0200BE6C, func_0200BE84, func_0200BF08, func_0200BF10, func_0200BF18, func_0200BF54, func_0200BF70, func_0200BF78, func_0200BF94, func_0200BFA4, func_0200C054, func_0200C058, func_0200C0E8, func_0200C0F0, func_0200C0FC, func_0200C104, func_0200C10C, func_0200C11C, func_0200C164, func_0200C184, func_0200C18C, func_0200C1A4, func_0200C1B0, func_0200C1C4, func_0200C1C8, func_0200C1DC, func_0200C1E0, func_0200C1F4, func_0200C1F8, func_0200C20C, func_0200C210, func_0200C224, func_0200C22C, func_0200C234, func_0200C248, func_0200C258, func_0200C274, func_0200C278, func_0200C29C, func_0200C2B0, func_0200C2D0, func_0200C2F0, func_0200C308, func_0200C31C, func_0200C324, func_0200C32C, func_0200C334, func_0200C33C, func_0200C344, func_0200C34C, func_0200C358, func_0200C364, func_0200C37C, func_0200C384, func_0200C38C, func_0200C39C, func_0200C3B0, func_0200C3B8, func_0200C3C0, func_0200C3E0, func_0200C3EC
 * address:  0x0200B2A4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200B1F8   0x0200B1F8  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0201AB28   0x0201AB28  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_0200B254   0x0200B254  thumb
 *   func_0200B3DC_File  0x020A71C4  data
 *   func_020307B0   0x020307B0  arm
 *   gObj_0214616C   0x0214616C  data
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_0203F2FC   0x0203F2FC  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0200B784_Table  0x0209DDCC  data
 *   MI_CpuFill8          0x02082BCC  arm
 *   func_0203F37C  0x0203F37C  arm
 *   func_0203F328  0x0203F328  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   d_0209DDCC 0x0209DDCC data
 *   sub_02034AC4   0x02034AC4  arm
 *   ov188_id       0x000000BC  data  a1
 *   sub_02034A5C   0x02034A5C  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045F5C  0x02045F5C  arm
 *   func_02045C04  0x02045C04  arm
 *   sub_0201747C   0x0201747C  thumb
 *   sub_02017E88   0x02017E88  thumb
 *   sub_0201A920   0x0201A920  thumb
 *   sub_0201A954   0x0201A954  thumb
 *   sub_0201A98C   0x0201A98C  thumb
 *   sub_0200BBEC   0x0200BBEC  thumb
 *   sub_02017550  0x02017550  thumb
 *   sub_0201AA18  0x0201AA18  thumb
 *   sub_0201AB28  0x0201AB28  thumb
 *   sub_020185F4  0x020185F4  thumb
 *   sub_0200BAD4  0x0200BAD4  thumb
 *   func_021763BC   0x021763BC  thumb
 *   GX_GetBankForLCDC  0x02045A98  arm
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_02008654  0x02008654  thumb
 *   _ull_mul       0x0209C054  arm
 *   g_02146170     0x02146170  data  a8
 *   func_02045EC0    0x02045EC0  arm
 *   func_02045A38    0x02045A38  arm
 *   func_02045808    0x02045808  arm
 *   memset           0x02082BCC  arm
 */
#include "../../matched/include/Obj07120.h"

struct Rec1E;
struct BattleRec;
struct Struct_0200B37C;
struct Sub020071CCCtrl;
struct Ctrl;
struct Sub020072A4Ctrl;
struct Sub020073D8Ctrl;
struct Big;
struct Sub02007324Ctrl;
struct Mon;
struct MsgBank;
struct MsgData;
struct Party;
struct PartyMon;
struct Rec;
struct Sav;
struct Grp330;
struct Ent88;
struct PlayTime;
struct U16Vec;
struct Blk34;
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned short u16;

struct Rec2FC {
    u8 unk000[0x2FC];
};

struct Rec94 {
    s32 unk00;
    s32 unk04[32];
    u8  unk84[0x10];
};

struct Struct_0200B37C {
    int header;
    int entries[32];
};

struct QRec {
    u16 unk00[0x0C];
    u8  unk18[0x0C];
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u8  unk2A;
    u8  unk2B;
    u8  unk2C[0x0C];
    u8  unk38[8];
    u16 unk40;
    u16 unk42;
};

struct Ent70 {
    u8  unk00[4];
    u16 f04_0 : 2;
    u16 f04_2 : 1;
    u16 f04_3 : 13;
    u16 unk06;
    u8  unk08[0x24];
    u32 f2C_0 : 30;
    u32 f2C_30 : 1;
    u32 f2C_31 : 1;
    u8  f30_0 : 1;
    u8  f30_1 : 2;
    u8  f30_3 : 5;
    u8  unk31[0x3F];
};

struct Grp2A4 {
    struct Ent70 ent[6];
    u32 unk2A0;
};

struct RecC4 {
    u8  unk0000[0xC3C];
    struct Grp2A4 unkC3C[4];
    u8  unk16CC[0x10C];
    u16 unk17D8;
    u16 unk17DA;
    u16 unk17DC;
    u16 unk17DE;
};

struct BattleRec {
    u8  unk00[0x80];
    struct QRec unk80;
    struct RecC4 unkC4;
};

typedef unsigned long long u64;

struct Ent88 {
    u32 unk00[0x22];
};

struct Grp330 {
    struct Ent88 ent[6];
};

struct Rec35C {
    struct Grp330 unk000;
    u8 unk330[0x14];
    u8 unk344[0x18];
};

struct Payload {
    u32 unk00[0x37];
};

struct Slot {
    u32 unk00;
    struct Payload unk04;
    u32 unkE0;
};

struct Obj {
    struct Slot slot[2];
    u32 unk1C8;
    u8  unk1CC[0x358 - 0x1CC];
    u16 unk358;
};

typedef struct {
    int active;
    u8 data[0xDC];
    u32 count;
} E;

struct Blk32 {
    u8 unk000[0x1CC];
};

struct Rec1B0_0200BDBC {
    u8  unk00[0x0C];
    u16 unk0C;
    u16 unk0E;
    u8  unk10[0x1A0 - 0x10];
    u8  unk1A0;
    u8  unk1A1[0x0F];
};

typedef struct {
    u16 f00[9];
    u8  f12;
} Slot;

typedef struct {
    u8   unk000[0x10];
    Slot slot[20];
} Rec;

struct Rec1B0_0200BF08 {
    u8  unk000[0x1A0];
    u8  unk1A0;
    u8  unk1A1[2];
    u8  unk1A3;
    u32 unk1A4;
    unsigned long long unk1A8;
};

typedef struct {
    u8  pad00[0x14];
    u32 f14;
    u8  pad18[0x20 - 0x18];
    u8  f20[0x12];
    u8  f32[0x12];
    u8  f44;
    u8  f45;
    u8  f46;
    u8  f47;
    u8  f48;
    u8  f49;
} Obj;

struct Ent58 {
    u16 v[6];
};

struct Bits0A {
    u8 f0 : 6;
    u8 f6 : 1;
    u8 f7 : 1;
};

union U64Pair {
    unsigned long long q;
    struct {
        u32 lo;
        u32 hi;
    } w;
};

struct Blk34 {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    struct Bits0A unk0A;
    u8  unk0B;
    u8  unk0C[8];
    u32 f14_0  : 28;
    u32 f14_28 : 4;
    u32 unk18;
    u32 unk1C;
    u16 unk20[9];
    u16 unk32[9];
    u8  unk44;
    u8  unk45;
    u8  unk46;
    u8  unk47[3];
    u16 unk4A[3];
    union U64Pair unk50;
    struct Ent58 unk58[8];
    u32 unkB8[8];
    u32 unkD8;
    u32 unkDC;
    volatile u16 unkE0;
    u16 unkE2;
};

extern void func_0200B1F8(struct Rec1E *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0200B254(struct Rec1E *p, int id, u8 n, s32 value);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern void  func_02082A90(void *dest, const void *src, u32 size);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern u32 func_0203F2FC(const u8 *p, u32 len);
extern u32  func_020072CC(void *save, u32 id, u32 heap, void *buf, u32 size);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern u32 func_0200725C(void *save, u32 id, u32 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void *func_02012EBC(struct Big *p);
extern void func_02007324(struct Sub02007324Ctrl *ctrl, u32 id, u32 heap, u32 a, u32 b);
extern void  func_02012E4C(u8 *a, u32 c);
extern int func_02012E7C(char *p, int a1);
extern void func_0200734C(struct Sub02007324Ctrl *ctrl, u32 id);
extern void func_0203F37C(void *p, u32 size, u32 seed);
extern void func_0203F328(u16 *p, u32 size, u32 seed);
extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_020271CC(void *a, u32 id);
extern void func_02017550(struct Sav *p);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201A954(struct Party *p, s32 capacity);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void *func_020185F4(void *a);
extern u32   func_02017E88(void *e, u32 a, u32 b);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern int sub_02034AC4(s32 handle);
extern void sub_02034A5C(s32 handle);
extern struct Party *sub_0201A920(u32 heap);
extern void sub_0201A954(struct Party *p, s32 capacity);
extern u32 sub_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 sub_02017E88(void *p, u32 id, u32 v);
extern void *sub_0201747C(struct Mon *p, u32 heap);
extern void *sub_0200BBEC(void *base, u32 i, u32 j);
extern void sub_02017550(struct Sav *p);
extern u32 sub_0201AA18(void *p);
extern void *sub_0201AB28(void *p, u32 idx);
extern void *sub_020185F4(void *p);
extern void sub_0200BAD4(struct Grp330 *p, u32 g, u32 i, const struct Ent88 *src);
extern void func_021763BC(void *p);
extern u16 GX_GetBankForLCDC(void);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern u8 func_02008654(const struct PlayTime *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern void func_02045808(struct U16Vec *vec);
extern void *memset(void *dst, int c, u32 n);
void func_0200B2A4(int a0, int a1);
void func_0200B348(struct Rec2FC *p);
void *func_0200B358(void *sys);
u32 func_0200B364(void);
void func_0200B368(struct Rec94 *p);
void func_0200B37C(struct Struct_0200B37C *p);
s32 *func_0200B394(struct Rec94 *p, s32 value);
s32 *func_0200B3A4(struct Rec94 *p, u32 b);
u8 *func_0200B3A8(struct Rec94 *p, u32 a1);
s32 func_0200B3AC(struct Rec94 *p);
void func_0200B3B0(struct Rec94 *dest, void *sys);
void func_0200B3C8(void *sys, const struct Rec94 *src);
void *func_0200B3DC(u32 heap);
void func_0200B400(u32 heap);
void func_0200B424(void);
void func_0200B438(void *p);
u32 func_0200B440(void);
void func_0200B448(struct BattleRec *p);
u32 func_0200B45C(void);
void func_0200B480(void);
void func_0200B490(void);
void func_0200B4B8(void);
u32 func_0200B4E0(void *a, struct BattleRec *b, u32 heap, u32 *d, u32 id);
u32 func_0200B570(void *a, u16 heap, u32 *dp, u32 id);
struct BattleRec *func_0200B5A4(void *a, u32 heap, u32 *dp, u32 id);
u32 func_0200B5CC(void *a, u32 heap, u32 *dp, u32 id);
u32 func_0200B67C(void *a, struct BattleRec *b, u32 c, u16 *state, u16 e);
u32 func_0200B6E0(void *a, u16 b, u32 c, u32 d, u32 e, u16 *state, u16 *sub);
void func_0200B784(u16 mode, s32 *sides, s32 *members);
void func_0200B7D8(void *h, struct QRec *q, const struct RecC4 *src, u32 mode, u32 e);
u32 func_0200B888(void *a, struct BattleRec *b);
u32 func_0200B8AC(void *a, struct BattleRec *b);
void func_0200B900(void *a, u32 b, u32 c);
void func_0200B908(void *a, u32 b, u32 c);
struct BattleRec *func_0200B910(void);
u8 *func_0200B91C(void);
u8 *func_0200B928(void);
u8 *func_0200B934(struct BattleRec *p);
void func_0200B938(const void *a, const void *b, const void *c);
u64 func_0200B98C(u8 *p, int selector, int index);
u32 func_0200BA38(u32 v);
void func_0200BA44(struct RecC4 *p);
void func_0200BA58(void);
void func_0200BA68(void);
u32 func_0200BA78(void);
void func_0200BA80(struct Rec35C *p);
void *func_0200BAC8(void *p);
void func_0200BAD4(struct Grp330 *p, u32 g, u32 i, const struct Ent88 *src);
void *sub_0200BAF4(int a0, int a1);
void func_0200BB58(u8 *a0, u8 *a1);
u32 func_0200BBA8(void *a);
void func_0200BBC8(struct Obj *p, u32 v);
void func_0200BBD8(struct Obj *p, int v);
void *func_0200BBEC(void *base, u32 i, u32 j);
u32 func_0200BBFC(struct Obj *p, u32 mask);
void func_0200BC10(struct Obj *p);
void func_0200BC20(struct Obj *p);
struct Payload *func_0200BC2C(struct Obj *p, s32 i);
void func_0200BC4C(struct Obj *p, s32 i, const struct Payload *src);
void func_0200BC88(struct Obj *p, s32 i);
u32 func_0200BCA0(struct Obj *p);
u32 func_0200BCA8(struct Obj *p, u32 i);
u32 func_0200BCB8(struct Obj *p);
u32 func_0200BCD8(struct Obj *p, u32 i);
void func_0200BCEC(struct Obj *p, s32 a, s32 b);
void func_0200BD48(E *e, u32 add);
u32 func_0200BD98(void);
void func_0200BDA0(struct Blk32 *p);
void *func_0200BDB0(void *sys);
u32 func_0200BDBC(void);
void func_0200BDC4(struct Rec1B0_0200BDBC *p);
void func_0200BDE4(struct Rec1B0_0200BDBC *p);
u16 func_0200BDF8(struct Rec1B0_0200BDBC *p);
u16 func_0200BDFC(struct Rec1B0_0200BDBC *p);
void func_0200BE00(struct Rec1B0_0200BDBC *p, s32 v);
void func_0200BE24(struct Rec1B0_0200BDBC *p, s32 v);
u16 *func_0200BE48(void *sys);
void func_0200BE54(void *sys, const u16 *src);
void func_0200BE6C(void *sys, u16 *dest);
void func_0200BE84(Rec *p, Slot *q);
void func_0200BF08(struct Rec1B0_0200BF08 *p, u32 v);
u8 func_0200BF10(struct Rec1B0_0200BF08 *p);
void func_0200BF18(struct Rec1B0_0200BF08 *p, s32 id);
void func_0200BF54(struct Rec1B0_0200BF08 *p, u8 *dest, u32 n);
u32 func_0200BF70(struct Rec1B0_0200BF08 *p);
u32 func_0200BF78(struct Rec1B0_0200BF08 *p);
unsigned long long func_0200BF94(struct Rec1B0_0200BF08 *p);
u64 func_0200BFA4(u8 *p, void *q, u32 mode);
u32 func_0200C054(void);
void func_0200C058(Obj *p);
void *func_0200C0E8(void *sys);
void *func_0200C0F0(void *sys);
void func_0200C0FC(struct Blk34 *p, u32 i, u8 v);
u8 func_0200C104(struct Blk34 *p, u32 i);
void func_0200C10C(struct Blk34 *p);
void func_0200C11C(struct Blk34 *p, u16 a, u32 b, u32 c, u32 d);
void func_0200C164(const struct Blk34 *p, u32 *a, u32 *b, u32 *c, u32 *d);
u32 func_0200C184(struct Blk34 *p);
void func_0200C18C(struct Blk34 *p, u32 v);
u8 func_0200C1A4(struct Blk34 *p);
void func_0200C1B0(struct Blk34 *p, u32 v);
u32 func_0200C1C4(struct Blk34 *p);
u32 func_0200C1C8(struct Blk34 *p);
u32 func_0200C1DC(struct Blk34 *p);
u32 func_0200C1E0(struct Blk34 *p);
u16 *func_0200C1F4(struct Blk34 *p);
void func_0200C1F8(struct Blk34 *p, const u16 *src);
u16 *func_0200C20C(struct Blk34 *p);
void func_0200C210(struct Blk34 *p, const u16 *src);
u8 func_0200C224(struct Blk34 *p);
void func_0200C22C(struct Blk34 *p, u8 v);
u32 func_0200C234(struct Blk34 *p, u32 bit);
void func_0200C248(struct Blk34 *p, u32 bit);
u32 func_0200C258(struct Blk34 *p);
u32 func_0200C274(struct Blk34 *p);
u32 func_0200C278(struct Blk34 *p, u32 v);
u32 func_0200C29C(struct Blk34 *p, u32 v);
void func_0200C2B0(struct Blk34 *p, u32 i, const u16 *src);
void func_0200C2D0(struct Blk34 *p, u32 i, u16 *dest);
void func_0200C2F0(struct Blk34 *p, u32 i, u8 v);
u8 func_0200C308(struct Blk34 *p, u32 i);
u8 func_0200C31C(struct Blk34 *p);
void func_0200C324(struct Blk34 *p, u8 v);
u8 func_0200C32C(struct Blk34 *p);
void func_0200C334(struct Blk34 *p, u8 v);
int func_0200C33C(struct Blk34 *p, u32 i);
void func_0200C344(struct Blk34 *p, u8 i, u8 v);
u16 func_0200C34C(struct Blk34 *p, u32 i);
void func_0200C358(struct Blk34 *p, u32 i, int v);
void func_0200C364(struct Blk34 *p, u8 i, int v);
unsigned long long func_0200C37C(struct Blk34 *p);
void func_0200C384(struct Blk34 *p, u32 lo, u32 hi);
void func_0200C38C(struct Blk34 *p, s32 i, u32 v);
u32 func_0200C39C(struct Blk34 *p, s32 i);
u16 func_0200C3B0(struct Blk34 *p);
void func_0200C3B8(struct Blk34 *p, u16 v);
void func_0200C3C0(struct Blk34 *p, u16 v);
u8 func_0200C3E0(struct Blk34 *p);
void func_0200C3EC(struct Blk34 *p, u32 v);
extern const char func_0200B3DC_File[];
extern struct BattleRec *gObj_0214616C;
extern const u16 func_0200B784_Table[];
extern const u16 func_0200B98C_Table[];
extern const u16 d_0209DDCC[];
extern char ov188_id[];
extern u64 g_02146170;










/*
 * Rebuild the four per-slot fields for every entry the accessor count reports;
 * the count is a call, so it is re-evaluated on the loop back-edge, and the
 * third argument of every accumulate call is truncated to u8.
 */
void func_0200B2A4(int a0, int a1)
{
    int i;

    func_0200B1F8((struct Rec1E *)a0);
    for (i = 0; i < (int)func_0201AA18((void *)a1); i++) {
        int obj = (int)func_0201AB28((void *)a1, i);

        if (func_02017E1C((void *)obj, 0xa9, 0) != 0) {
            func_0200B254((struct Rec1E *)a0, 0, i, func_02017E1C((void *)obj, 5, 0));
            func_0200B254((struct Rec1E *)a0, 1, i, func_02017E1C((void *)obj, 0x6f, 0));
            func_0200B254((struct Rec1E *)a0, 2, i, func_02017E1C((void *)obj, 6, 0) != 0);
            func_0200B254((struct Rec1E *)a0, 3, i, func_02017E1C((void *)obj, 0x6e, 0));
        }
    }
}










/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 52 bytes, 0x0200B348..0x0200B37C, 4 functions, none of which carries a
 * label in the generated listing.
 *
 * func_0200B364 returns 0x94 and func_0200B368 clears 0x94 bytes and then
 * writes -1 into the first word, which is the "a block file opens with a
 * function returning its own size, and the constructor clears exactly that"
 * shape this range keeps producing.  The -1 is free: the compiler already
 * has 0x94 in a register for the fill and reaches -1 with `subs r4, #0x95`.
 *
 * This unit starts at 0x0200B348 rather than at the end of
 * src/matched/unit_0200ADB8.c because of a near miss between them:
 * func_0200B2A4, 162 bytes, which walks a list and pushes four fields of each
 * entry into the record through func_0200B254.  Every instruction is
 * reproduced and the size is right; what differs is that the original keeps
 * the constant 0 alive in r7 for the whole loop (it gets there as a copy of
 * the loop counter's initial value) and therefore rematerialises `(u8)i`
 * before each of the four calls, where this source has one register less in
 * play, common-subexpression-eliminates `(u8)i` into r5 and rematerialises
 * the 0 instead.  The two are the same eighteen instructions per iteration in
 * a different order with every register renumbered.
 *
 * This unit stops at 0x0200B37C because of a near miss there; see
 * src/matched/unit_0200B394.c for what it is.
 */
void func_0200B348(struct Rec2FC *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Rec2FC));
}










void *func_0200B358(void *sys)
{
    return func_020071CC(sys, 0x2F);
}










u32 func_0200B364(void)
{
    return sizeof(struct Rec94);
}










void func_0200B368(struct Rec94 *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Rec94));
    p->unk00 = -1;
}









void func_0200B37C(struct Struct_0200B37C *p)
{
    int i;
    p->header = -1;
    for (i = 0; i < 32; i++) {
        p->entries[i] = 0;
    }
}









/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200B3B0, func_0200B3C8, func_0200B3DC
 *
 * 108 bytes, 0x0200B394..0x0200B400, 7 functions, four of which carry no
 * label in the generated listing.
 *
 * alias: 0x020A71C4 spells "battle_rec.c", the third original source file
 * name recovered by this project, attested by the `string` class off the
 * terminator of "regulation.c" at 0x020A71C2.  The constructor at 0x0200B3DC
 * allocates 0x2000 bytes at line 0x67 and hands them to func_0200B448, which
 * is the first function of the next packet.
 *
 * Near miss, and the reason this unit starts at 0x0200B394 rather than
 * 0x0200B37C: func_0200B37C, 24 bytes, which writes -1 into the first word
 * and then fills a 32-entry array with 0..31.  The original carries one more
 * instruction than any spelling tried here, an `adds r2, r3, #0` that copies
 * the loop counter before the body and lets the increment be scheduled ahead
 * of the store, and it initialises the counter before the -1 store rather
 * than after.  Five loop spellings (for, while, do/while, a separate value
 * variable, a hoisted array pointer) all produce the same eleven
 * instructions in the other order, so the difference is a register the
 * original had a reason to spend and this source does not give it.  Nineteen
 * bytes differ and the size is right to the padding.
 */
s32 *func_0200B394(struct Rec94 *p, s32 value)
{
    func_0200B37C((struct Struct_0200B37C *)p);
    p->unk00 = value;
    return p->unk04;
}








s32 *func_0200B3A4(struct Rec94 *p, u32 b)
{
    return p->unk04;
}








u8 *func_0200B3A8(struct Rec94 *p, u32 a1)
{
    return p->unk84;
}








s32 func_0200B3AC(struct Rec94 *p)
{
    return p->unk00;
}








void func_0200B3B0(struct Rec94 *dest, void *sys)
{
    func_02082A90(dest, func_020071CC(sys, 0x30), sizeof(struct Rec94));
}








void func_0200B3C8(void *sys, const struct Rec94 *src)
{
    func_02082A90(func_020071CC(sys, 0x30), src, sizeof(struct Rec94));
}








void *func_0200B3DC(u32 heap)
{
    void *p = func_02030734(heap, 0x2000, 1, func_0200B3DC_File, 0x67);

    func_0200B448(p);
    return p;
}









/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 72 bytes, 0x0200B400..0x0200B448, 4 functions, three of which carry no
 * label in the generated listing: the last three save nothing or nothing but
 * r4, so the range arrives as a run of `.word`s.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * alias: this continues "battle_rec.c", whose constructor func_0200B3DC is
 * the last function of src/matched/unit_0200B394.c and is what func_0200B400
 * calls.  The object it builds is hung off the single global at 0x0214616C,
 * the same one src/matched/unit_0200B900.c reads.
 *
 * func_0200B400 frees the old object before building the new one and clears
 * the global in between, which is a guard the source wrote rather than dead
 * code: the store of NULL is inside the `if`, and the fresh pointer is
 * assigned unconditionally afterwards.  The address of the global is
 * materialised twice, once for the test and free and once for the final
 * store, because the pool word is reloaded after the call rather than kept
 * in the callee-saved register that already holds it.
 *
 * func_0200B440 returns 0x18A4 out of its own pool word, which is the
 * "a block file opens with a function returning its own size" shape this
 * region keeps producing, except that here the size belongs to whatever the
 * next file allocates rather than to the 0x2000 buffer above it.
 */
void func_0200B400(u32 heap)
{
    if (gObj_0214616C != 0) {
        func_020307B0(gObj_0214616C);
        gObj_0214616C = 0;
    }
    gObj_0214616C = func_0200B3DC(heap);
}









void func_0200B424(void)
{
    func_020307B0(gObj_0214616C);
    gObj_0214616C = 0;
}









void func_0200B438(void *p)
{
    func_020307B0(p);
}









u32 func_0200B440(void)
{
    return 0x18A4;
}









/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200B4B8
 *
 * 152 bytes, 0x0200B448..0x0200B4E0, 5 functions, three of which carry no
 * label in the generated listing.
 *
 * alias: this continues "battle_rec.c"; func_0200B448 is the buffer clear the
 * constructor func_0200B3DC calls, and the object is the 0x18A4-byte record
 * at 0x0214616C that src/matched/unit_0200B400.c allocates and
 * src/matched/unit_0200B938.c publishes.
 *
 * Two things are worth recording.
 *
 *  - func_0200B490 and func_0200B4B8 are the same four instructions of
 *    checksum arithmetic as func_0200B938, but as **tail calls**, and that
 *    changes the callee's arity.  A tail call needs r3 for the branch target,
 *    so the fourth argument func_0200B938 passes cannot be passed here: the
 *    `ldrh r3` that loads the halfword is overwritten by the `ldr r3, [pc]`
 *    that loads func_0200B900's address.  The callee is therefore declared
 *    with three parameters in this file and with four in
 *    src/matched/unit_0200B900.c, and both are right, because nothing in
 *    func_0200B900 reads its arguments.  A four-argument call here compiles
 *    to `push {r3, lr}` / `bl` / `pop` and is eight bytes longer.
 *  - the length 0x17DC is reached as `subs r1, #0xc4` off the 0x18A0 the
 *    halfword load already needed, and 0x18A0 itself is a pool word rather
 *    than a `movs`, so the file spends one pool word where func_0200B938
 *    spends none for the same value.  That is a consequence of the tail call
 *    having no register to spare, not of the source.
 */
void func_0200B448(struct BattleRec *p)
{
    MIi_CpuClear32(0, p, sizeof(struct BattleRec));
}








u32 func_0200B45C(void)
{
    if (func_0203F2FC((const u8 *)(&gObj_0214616C->unkC4), sizeof(gObj_0214616C->unkC4))
        != 0) {
        return 1;
    }
    return 0;
}









void func_0200B480(void)
{
    func_0200B448(gObj_0214616C);
}









void func_0200B490(void)
{
    u16 v = gObj_0214616C->unkC4.unk17DC;

    func_0200B900(&gObj_0214616C->unkC4, 0x17DC, v + ((v ^ 0xFFFF) << 16));
}









void func_0200B4B8(void)
{
    u16 v = gObj_0214616C->unkC4.unk17DC;

    func_0200B908(&gObj_0214616C->unkC4, 0x17DC, v + ((v ^ 0xFFFF) << 16));
}









/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 236 bytes, 0x0200B4E0..0x0200B5CC, 3 functions, all three of which carry a
 * label in the generated listing.
 *
 * alias: inside "battle_rec.c"; see src/matched/unit_0200B394.c for how the
 * name at 0x020A71C4 is attested and src/matched/unit_0200B448.c for the
 * 0x18A4-byte record these work on.
 *
 * func_0200B4E0 loads a saved battle record and classifies the result into
 * the caller's status word: 0 when the block is absent, 3 when the load
 * failed, 0 again when the record's own check rejects it, 2 when the second
 * check does, and 1 when it is good.  Every arm writes the status and returns
 * 1, and the last arm shares its `movs r0, #1` between the store and the
 * return, which is the compiler reusing one constant and not two statements.
 *
 * The address of the checksummed sub-record is a named local, not
 * `&b->unkC4` written out at each of the three uses: with the local the base
 * is formed once as `adds r0, #0xc4` and the field offset 0x17DC is the
 * register operand, and written inline the compiler folds 0xC4 + 0x17DC into
 * one pool word of 0x18A0 and then subtracts 0xC4 back off it, which is two
 * instructions more.
 *
 * This range stops at 0x0200B5CC and src/matched/unit_0200B5CC.c starts
 * there, because func_0200B888 and func_0200B8AC are each called exactly
 * twice in the image, once from func_0200B4E0 and once from func_0200B5CC;
 * one range holding both pairs has no witness left for either and caps at
 * MATCH with every byte right.  Cut between them, each file is the other's
 * witness.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md. *
 */
u32 func_0200B4E0(void *a, struct BattleRec *b, u32 heap, u32 *d, u32 id)
{
    struct RecC4 *r;
    u16 v;

    *d = func_020072CC(a, id, heap, b, 0x2000);
    func_020072A4(a, id);
    if (*d == 0) {
        *d = 0;
        return 1;
    }
    if (*d != 1) {
        *d = 3;
        return 1;
    }
    r = &b->unkC4;
    v = r->unk17DC;
    func_0200B900(r, 0x17DC, v + ((v ^ 0xFFFF) << 16));
    if (func_0200B888(a, b) == 1) {
        *d = 0;
        return 1;
    }
    if (func_0200B8AC(a, b) == 0) {
        *d = 2;
        return 1;
    }
    *d = 1;
    return 1;
}








u32 func_0200B570(void *a, u16 heap, u32 *dp, u32 id)
{
    if (gObj_0214616C != 0) {
        func_0200B448(gObj_0214616C);
    } else {
        func_0200B400(heap);
    }
    return func_0200B4E0(a, gObj_0214616C, heap, dp, id);
}








struct BattleRec *func_0200B5A4(void *a, u32 heap, u32 *dp, u32 id)
{
    struct BattleRec *p = func_0200B3DC(heap);

    func_0200B4E0(a, p, heap, dp, id);
    return p;
}







/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 176 bytes, 0x0200B5CC..0x0200B67C, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "battle_rec.c".  The same classification func_0200B4E0 does,
 * over a record the save system already holds rather than one just read, and
 * with a `func_020072A4` release on every path instead of only on entry.  See
 * src/matched/unit_0200B4E0.c for why the two are separate files. *
 */
u32 func_0200B5CC(void *a, u32 heap, u32 *dp, u32 id)
{
    struct BattleRec *p;
    struct RecC4 *r;
    u16 v;

    *dp = func_0200725C(a, id, heap);
    p = func_020073D8(a, id, 0);
    if (*dp == 0) {
        *dp = 0;
        func_020072A4(a, id);
        return 0;
    }
    if (*dp != 1) {
        *dp = 3;
        func_020072A4(a, id);
        return 0;
    }
    r = &p->unkC4;
    v = r->unk17DC;
    func_0200B900(r, 0x17DC, v + ((v ^ 0xFFFF) << 16));
    if (func_0200B888(a, p) == 1) {
        *dp = 0;
        func_020072A4(a, id);
        return 0;
    }
    if (func_0200B8AC(a, p) == 0) {
        *dp = 2;
        func_020072A4(a, id);
        return 0;
    }
    *dp = 1;
    func_020072A4(a, id);
    return 1;
}






/*
 * 264 bytes, 0x0200B67C..0x0200B784, 2 functions, both labelled.  Every
 * concrete byte reproduces.
 *
 * What held it open, and what closed it.  Two call targets have exactly one
 * caller in the whole image and that caller is here:
 *
 *   0x02007324  reached only from 0x0200B6A6, inside func_0200B67C
 *   0x0200B7D8  reached only from 0x0200B71A, inside func_0200B6E0
 *
 * Shrinking the range to one function keeps the call that needs the witness in
 * it, which is the limit `docs/MATCHING.md` states for the cut remedy, so no
 * image class could carry either site.  Both are now `matched`:
 * 0x02007324 is src/matched/unit_02007324.c and 0x0200B7D8 is
 * src/matched/unit_0200B7D8.c, two EXACT entries proved byte for byte against
 * the original over ranges this file does not touch.  Pulling either function
 * across the boundary into this range is no longer needed, and would have been
 * wrong anyway: the two belong to different original files.
 *
 * alias: inside "battle_rec.c"; the two steps of the record-save state machine
 * that func_0200B4E0 and func_0200B5CC read back.
 *
 * Three things cost time here.
 *
 *  - func_02012EBC is declared with **one** parameter, not four.  The call
 *    leaves r1 through r3 holding this function's own second, third and fourth
 *    arguments, which reads like a four-argument call and is not one: declaring
 *    four parameters keeps `b` live from the entry and the whole of
 *    func_0200B6E0's case 0 is then allocated the other way round, with the two
 *    sub-record pointers sharing registers with `b` instead of with `a`.  Seven
 *    bytes, and none of them in the arithmetic.  src/matched/unit_0200C9EC.c
 *    declares the same extern with one parameter.
 *  - inside case 0 the two sub-record pointers have to be assigned
 *    `q = &p->unk80;` first and `r = &p->unkC4;` second.  The second assignment
 *    is the last use of `p`, so it takes over `p`'s register and the first one
 *    gets the copy; writing them the other way round swaps which of the two is
 *    the `adds rD, rP, #0` and is five bytes.
 *  - the state word is read with `switch (*state)` over the constants 0 and 1,
 *    which is the `cmp #0` / `beq` / `cmp #1` / `beq` / `b` chain the original
 *    has; an `if` / `else if` inverts the first test.
 */
u32 func_0200B67C(void *a, struct BattleRec *b, u32 c, u16 *state, u16 e)
{
    void *h = func_02012EBC(a);
    u32 r;

    switch (*state) {
    case 0:
        func_02007324(h, c, e, (u32)gObj_0214616C, 0x2000);
        func_02012E4C(a, c);
        (*state)++;
        break;
    case 1:
        r = func_02012E7C(a, c);
        if (r == 2 || r == 3) {
            func_0200734C(h, c);
            return r;
        }
        break;
    }
    return 0;
}






u32 func_0200B6E0(void *a, u16 b, u32 c, u32 d, u32 e, u16 *state, u16 *sub)
{
    void *h;
    struct BattleRec *p;
    struct QRec *q;
    struct RecC4 *r;
    u16 v;

    h = func_02012EBC(a);

    switch (*state) {
    case 0:
        p = gObj_0214616C;
        if (p == 0) {
            return 3;
        }
        q = &p->unk80;
        r = &p->unkC4;
        func_0200B7D8(h, q, r, c, d);
        q->unk28 = 0xE281;
        q->unk40 = func_0203F1FC((const u8 *)q, 0x38);
        r->unk17D8 = 0xE281;
        func_0200BA44(r);
        v = r->unk17DC;
        func_0200B908(r, 0x17DC, v + ((v ^ 0xFFFF) << 16));
        *sub = 0;
        (*state)++;
        break;
    case 1:
        return func_0200B67C(a, gObj_0214616C, e, sub, b);
    }
    return 0;
}







/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 84 bytes, 0x0200B784..0x0200B7D8, one function, which carries a label in the
 * generated listing.
 *
 * alias: inside "battle_rec.c"; the team-layout lookup the record builder at
 * 0x0200B7D8 calls.  It walks a 0x29-entry `u16` table of mode ids at
 * 0x0209DDCC, and the indices 0x10..0x13 and 0x16 are the multi
 * battle modes, which get four sides of three; everything else gets two sides
 * of six.  Indices 0x14 and 0x15 fall back into the search rather than
 * answering, which is the pair of exit-valued entries in the jump table.
 *
 * The switch is written with `case 0x14:` and `case 0x15:` as empty arms even
 * though they do nothing, because without them the labels the compiler sees
 * are not dense and it emits a compare chain instead of the seven-entry
 * `.hword` table the original has.  See
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *
 * This is a file of its own rather than part of the range that follows it
 * because 0x0209DDCC is named by exactly two literal pool words in the whole
 * image, this function's and func_0200B7D8's, so a range holding both has no
 * witness left.  Cut between them and this one is attested by the other's
 * pool word.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  The cut
 * does not save func_0200B7D8, which is the only caller of this function and
 * therefore cannot be split away from it and attested at the same time; it is
 * parked in src/pending/unit_0200B7D8.c.
 */
void func_0200B784(u16 mode, s32 *sides, s32 *members)
{
    s32 i;

    for (i = 0; i < 0x29; i++) {
        if (mode == func_0200B784_Table[i]) {
            switch (i) {
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
            case 0x16:
                *sides = 4;
                *members = 3;
                return;
            case 0x14:
            case 0x15:
                break;
            }
        }
    }
    *sides = 2;
    *members = 6;
}







/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 176 bytes, 0x0200B7D8..0x0200B888, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "battle_rec.c".  It builds the 0x44-byte battle header out of
 * the party records that live at +0xC3C of the 0x17E0-byte second half of the
 * record.  The layout, four sides of three or two of six, comes from
 * func_0200B784, and the group stride 0x2A4 is six 0x70-byte entries plus a
 * word.  An entry is skipped when either of two bits is set, and those two
 * bitfield reads are the only evidence in the image for those field widths.
 *
 * The destination byte packs a five bit field into the low seven bits and a
 * two bit field at bit 7, where only one of the two bits survives the `strb`.
 * That truncation is in the original and is reproduced rather than corrected;
 * the explicit `& 0x7F` on a field that is already five bits wide is what puts
 * the `movs r1, #0x7f` / `ands` pair there, and dropping it loses four bytes.
 *
 * This range starts at 0x0200B7D8 rather than at func_0200B784, which is its
 * only caller, because 0x0209DDCC is named by exactly two literal pool words
 * in the whole image: this function's at 0x0200B880 and func_0200B784's at
 * 0x0200B7D4.  One range holding both has no witness for the table at all.
 * Cut between them and each pool word attests the other file.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.  The call
 * to func_0200B784 survives the cut because three overlay branches reach that
 * address from outside this region.
 */
void func_0200B7D8(void *h, struct QRec *q, const struct RecC4 *src, u32 mode,
                   u32 e)
{
    s32 nsides;
    s32 nmembers;
    u16 kind;
    s32 i;
    s32 j;
    s32 k;

    k = 0;
    MI_CpuFill8(q, 0, sizeof(struct QRec));
    kind = func_0200B784_Table[mode];
    func_0200B784(kind, &nsides, &nmembers);
    for (i = 0; i < nsides; i++) {
        for (j = 0; j < nmembers; j++) {
            const struct Ent70 *t = &src->unkC3C[i].ent[j];

            if (t->f2C_30 == 0 && t->f04_2 == 0) {
                q->unk00[k] = t->unk06;
                q->unk18[k] = (u8)((t->f30_3 & 0x7F) | (t->f30_1 << 7));
            }
            k++;
        }
    }
    q->unk24 = e;
    q->unk26 = kind;
    q->unk2B = 100;
}







/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 120 bytes, 0x0200B888..0x0200B900, 2 functions, both of which carry a label
 * in the generated listing.
 *
 * alias: inside "battle_rec.c"; the two validity checks src/matched/
 * unit_0200B4E0.c and unit_0200B5CC.c run over a loaded record, and the reason
 * those two are separate files.
 *
 * 0xE281 is the record's magic, stamped into both halves by func_0200B6E0 and
 * into the 0x44-byte header's +0x28 by func_0200B938.  func_0200B888 answers
 * "this record is NOT stamped", so its result is 1 on failure; func_0200B8AC
 * answers "this record is whole", checking the magic in both halves and then
 * both checksums.
 *
 * Both take a first parameter they never read.  func_0200B888 reaches the
 * 0x17D8 field of the second half as one folded offset 0x189C off the record
 * pointer, because the source names the field through the record rather than
 * through a local, while func_0200B8AC needs a local for the sub-record and so
 * carries 0x17D8 in a register instead; the difference is two instructions and
 * is a statement about the source rather than about the value.
 *
 * The two checksum comparisons each bind the call result to a local before
 * comparing, which is what puts it in `cmp`'s left slot; written inline the
 * operand order flips and the entry is two bytes out.  See
 * docs/idioms/cmp-operand-order-names-the-temporary.md.
 */
u32 func_0200B888(void *a, struct BattleRec *b)
{
    struct QRec *q = &b->unk80;

    if (b->unkC4.unk17D8 != 0xE281 || q->unk28 != 0xE281) {
        return 1;
    }
    return 0;
}






u32 func_0200B8AC(void *a, struct BattleRec *b)
{
    struct RecC4 *r = &b->unkC4;
    struct QRec *q = &b->unk80;
    u16 sum;

    if (r->unk17D8 != 0xE281 || q->unk28 != 0xE281) {
        return 0;
    }
    sum = func_0203F1FC((const u8 *)q, 0x38);
    if (sum != q->unk40) {
        return 0;
    }
    sum = func_0203F1FC((const u8 *)r, 0x17DC);
    if (sum == r->unk17DC) {
        return 1;
    }
    return 0;
}







/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200B928, func_0200B934
 *
 * 56 bytes, 0x0200B900..0x0200B938, 6 functions, none of which carries a
 * label in the generated listing.
 *
 * Four accessors on the single object whose address lives at 0x0214616C and
 * two forwarders to a pair of ARM routines.  The three pool words holding
 * 0x0214616C inside this range are not its only ones: seven literal pools in
 * the image hold that address, so the `literal` class keeps a witness outside
 * whatever is compared.
 *
 * The two forwarders are written with their parameters declared and **not**
 * passed on, and that is a property of the codegen rather than a claim about
 * the callees.  This front end only emits the pool-word tail call
 * `ldr r3, [pc, #0]; bx r3` when there is no argument register to set up; a
 * call that names its arguments, even when every one of them is already in
 * the right register, comes out as `push {r3, lr}; blx; pop {r3, pc}`, which
 * is four instructions and eight bytes wrong.  The callers do pass four
 * arguments through func_0200B900 (func_0200B938 sets r0 through r3 before
 * the `bl`), so the forwarding is real and is simply not expressible here.
 * See docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 */
void func_0200B900(void *a, u32 b, u32 c)
{
    func_0203F37C(a, b, c);
}







void func_0200B908(void *a, u32 b, u32 c)
{
    func_0203F328(a, b, c);
}







struct BattleRec *func_0200B910(void)
{
    return gObj_0214616C;
}







u8 *func_0200B91C(void)
{
    return (u8 *)&gObj_0214616C->unkC4;
}







u8 *func_0200B928(void)
{
    return (u8 *)&gObj_0214616C->unk80;
}







u8 *func_0200B934(struct BattleRec *p)
{
    return (u8 *)&p->unk80;
}






/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 84 bytes, 0x0200B938..0x0200B98C, one function, which carries a label in
 * the generated listing.
 *
 * The publisher of the battle record: three copies into the single object at
 * 0x0214616C and then a checksum word handed to func_0200B900.  The object is
 * 0x18A4 bytes, which is what func_0200B440 in src/matched/unit_0200B400.c
 * returns, so the record is pinned from both ends: 0x80 + 0x44 + 0x17E0 is
 * exactly 0x18A4.
 *
 * The word handed over is `v + ((v ^ 0xFFFF) << 16)`, spelled with `+` and
 * not with `|`: the two halves cannot overlap and this compiler emits `adds`
 * for the one and `orrs` for the other.  The length 0x17DC is rematerialised
 * as `subs r1, r6, #4` off the 0x17E0 that is still live from the second
 * copy, which is the compiler reusing a value rather than a second constant
 * in the source.
 *
 * The range stops at 0x0200B98C because of a near miss there; see
 * src/matched/unit_0200BA38.c. *
 */
void func_0200B938(const void *a, const void *b, const void *c)
{
    u16 v;

    MI_CpuCopy8(b, &gObj_0214616C->unk80, sizeof(gObj_0214616C->unk80));
    MI_CpuCopy8(c, &gObj_0214616C->unkC4, sizeof(gObj_0214616C->unkC4));
    MI_CpuCopy8(a, gObj_0214616C->unk00, sizeof(gObj_0214616C->unk00));
    v = gObj_0214616C->unkC4.unk17DC;
    func_0200B900(&gObj_0214616C->unkC4, 0x17DC, v + ((v ^ 0xFFFF) << 16));
}






/*
 * A record field getter: selector picks the field, the result is 64-bit.
 * Callers: ov183 0x021DD228, 0x021DD25C, 0x021DEE7C, 0x021DF838 and others.
 */
u64 func_0200B98C(u8 *p, int selector, int index)
{
    int i;
    u16 v;
    switch (selector) {
    case 0:
        v = ((u16 *)p)[index];
        if (v > 0x289)
            return 0;
        return v;
    case 1:
        return (p + index)[0x18] & 0x7f;
    case 2:
        v = *(u16 *)(p + 0x24);
        if (v > 9999)
            return 9999;
        return v;
    case 3:
        for (i = 0; i < 41; i++) {
            if (*(u16 *)(p + 0x26) == d_0209DDCC[i])
                return i;
        }
        return 0;
    case 4:
        return *(u64 *)(p + 0x38);
    case 5:
        return p[0x2a];
    case 6:
        return ((p + index)[0x18] & 0x80) >> 7;
    case 7:
        return p[0x2b];
    }
    return 0;
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 32 bytes, 0x0200BA38..0x0200BA58, 2 functions, one of which carries a
 * label in the generated listing.
 *
 * func_0200BA44 stamps the record's own checksum into its last halfword, and
 * 0x17DC is both the length checksummed and the store's offset, so the
 * compiler holds it in one register and the store is a register-offset
 * `strh`; 0x17DC is far past the 62-byte reach of the immediate form anyway.
 *
 * Near miss, and the reason this range starts at 0x0200BA38: func_0200B98C,
 * 172 bytes, an eight-case dispatcher returning `long long`.  Every case, the
 * jump table and the three pool words reproduce; what does not is one
 * instruction in the `case 3` table search.  The original keeps the loop
 * index in r2 and copies it into r0 to return it (`adds r0, r2, #0`), where
 * every spelling tried here allocates the index to r0 directly and drops the
 * copy, which is two bytes short and moves the four later table entries.
 * Nine shapes were compiled and ranked: the table as a named `const u16 *`
 * local declared before and after the compared value, the comparison in both
 * operand orders, `while` against `for`, a `continue` form, the index at
 * function scope and at case scope, and the compared field as `u16` and
 * `u32`.  All nine are 168 bytes against the original's 172 and the ranking
 * is flat, so the missing copy is not reachable from the source shape.  Same
 * class as the near misses at 0x0200B2A4 and 0x0200B37C.
 *
 * Near miss, and the reason this range stops at 0x0200BA58: func_0200BA58 and
 * func_0200BA68, eight bytes of tail call each.  Both reproduce every
 * instruction but hold their argument in a pool word rather than in a `movs`,
 * and 0xBC fits a `movs` immediate, so the argument cannot be an integer
 * literal.  Both are now matched on their own: src/matched/arm9/
 * func_0200BA58.c and func_0200BA68.c. *
 */
u32 func_0200BA38(u32 v)
{
    if (v <= 100) {
        return 1;
    }
    return 0;
}





void func_0200BA44(struct RecC4 *p)
{
    p->unk17DC = func_0203F1FC((const u8 *)p, 0x17DC);
}



/*
 * Loads overlay 188 (0xBC): a Thumb tail call to the ARM loader through
 * `ldr r3; bx r3`.  The id is a pool word, so it is the overlay-id symbol,
 * not an integer literal (0xBC would fit a movs).  Filed as the call witness
 * for the ov021 script dispatcher 0x021CA5C4 (also unblocks the pending
 * ov187 0x0220B164 and ov199 0x022132C4).
 */
void func_0200BA58(void)
{
    sub_02034AC4((u32)ov188_id);
}



/*
 * Unloads overlay 188 (0xBC), the pair of func_0200BA58: a Thumb tail call
 * to the ARM unloader through `ldr r3; bx r3`, the id as the overlay-id
 * symbol.  Filed as the call witness for the ov021 script dispatcher
 * 0x021CA5C4 (also unblocks the pending ov187 0x0220B164 and ov199
 * 0x022132C4).
 */
void func_0200BA68(void)
{
    sub_02034A5C((u32)ov188_id);
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 80 bytes, 0x0200BA78..0x0200BAC8, 2 functions, one of which carries a
 * label in the generated listing.
 *
 * The size getter and the constructor of a 0x35C-byte record: six 0x88-byte
 * entries, then 0x14 bytes at +0x330 that a resource read fills.  The two
 * agree, which is what pins the entry size: 6 * 0x88 is 0x330.
 *
 * The entry is declared as an array of words rather than of bytes, because
 * func_0200BAD4 in src/matched/unit_0200BAD4.c copies one with an eight-byte
 * stepped `ldm`/`stm` loop; a one-aligned declaration gives a byte loop
 * instead.  See docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * The range stops at 0x0200BAC8 because of func_0200BAC8, an eight-byte tail
 * call whose pool word names 0x020271CC and which nothing else in the image
 * branches to or holds a pointer to, so the `label` and `literal` classes are
 * both empty and no cut helps.  It is now matched on its own, as are the
 * other two: src/matched/arm9/func_0200BAC8.c, func_0200BA58.c and
 * func_0200BA68.c. *
 */
u32 func_0200BA78(void)
{
    return sizeof(struct Rec35C);
}





void func_0200BA80(struct Rec35C *p)
{
    u32 i;
    void *h;

    MI_CpuFill8(p, 0, sizeof(struct Rec35C));
    for (i = 0; i < 6; i++) {
        func_02017550((struct Sav *)&p->unk000.ent[i]);
    }
    h = func_02045B38(0, 2, 9, 1);
    if (h != 0) {
        func_02045F5C(h, 6, (u16 *)p->unk330, sizeof(p->unk330));
        func_02045C04(h);
    }
}






/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void *func_0200BAC8(void *p)
{
    return func_020071CC(p, 0x31);
}






/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 30 bytes, 0x0200BAD4..0x0200BAF4, one function, which carries no label in
 * the generated listing.
 *
 * One 0x88-byte entry assigned into a two-dimensional array: the outer stride
 * is 0x330 and the inner 0x88, and the copy is an inline counted `ldm`/`stm`
 * loop of 17 iterations, which is 0x88 divided by eight.  The eight-byte step
 * is what says the entry is word aligned; declared as a byte array the same
 * assignment becomes a `ldrb`/`strb` loop of 0x88 iterations.  See
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * It is a range of its own because the function on either side of it is a
 * near miss: func_0200BAC8 before it, which has no witness for 0x020271CC,
 * and func_0200BAF4 after it, which is fifteen bytes of register numbering.
 * Its only caller, func_0200BB58, is therefore outside this range and is what
 * attests it. *
 */
void func_0200BAD4(struct Grp330 *p, u32 g, u32 i, const struct Ent88 *src)
{
    p[g].ent[i] = *src;
}





/*
 * packet line: 100 bytes, 7 of 7 relocations resolved by label
 *
 * Closed 2026-09-22 by tools/permuter.py (--mode anneal, 823 compiles).
 * The lever: the (a1 & 0x7fff) | 0x8000 mask is NOT a loop-invariant local
 * hoisted above the loop.  It is recomputed inside the loop body, after the
 * sub_02017E88 test result is bound to its own local.  Hoisting it (the
 * shape every earlier pass wrote) swaps r6 and r7 across the whole body:
 * five instructions, 5 concrete bytes out, which --explain reports as
 * r6->r7 x3 / r7->r6 x2.  Recomputing it inside gives the mask value the
 * later first-definition point the allocator needs to leave h in r6.
 *
 * `i` is u32, not int: the loop bound at +0x0058 is `blo`, not `blt`.
 * The failing test `break`s out of the loop (beq to the epilogue at
 * +0x005A), it does not `continue`.
 */
void *sub_0200BAF4(int a0, int a1)
{
    void *h;
    u32 i;

    h = sub_0201A920(a1);
    sub_0201A954(h, 6);
    for (i = 0; i < 6; i++) {
        void *p = sub_0200BBEC((void *)a0, 0, i);
        int ok = sub_02017E88(p, 0xa9, 0);
        int v  = (a1 & 0x7fff) | 0x8000;

        if (ok == 0) {
            break;
        }
        p = sub_0201747C(p, (u16)v);
        sub_0201A98C(h, p);
        func_020307B0(p);
    }
    return h;
}





/*
 * Clear the six 0x88-byte slots of a0, then walk a1's list.  The bound of the
 * second loop is a call - sub_0201AA18(a1) is re-invoked at the bottom of
 * every iteration and its result compared against the counter (`cmp r5, r0`
 * right after the `bl`), and the entry test is the peeled copy of that same
 * call, which is exactly how mwcc lowers `for (i = 0; i < f(a1); i++)`.
 */
void func_0200BB58(u8 *a0, u8 *a1)
{
    u32 i;
    u32 k = 0;

    for (i = 0; i < 6; i++)
        sub_02017550((struct Sav *)(a0 + i * 0x88));

    for (i = 0; i < (u32)sub_0201AA18(a1); i++)
        sub_0200BAD4((struct Grp330 *)a0, k, i, sub_020185F4(sub_0201AB28(a1, i)));
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 30 bytes, 0x0200BBA8..0x0200BBC8, one function, which carries a label in
 * the generated listing.
 *
 * Whether entry zero of the record is present.  The result is a local
 * initialised to 0 and set to 1 inside the `if`, not a `return 1` /
 * `return 0` pair: there is one epilogue and the arm is a single `movs`.
 *
 * func_0200BBEC, which it calls, is the first function of
 * src/matched/unit_0200BBC8.c; the other caller of that address is
 * func_0200BAF4 at 0x0200BB1E, and that call is what attests it here.
 *
 * func_0200BAF4 itself is a near miss.  Its 100 bytes reproduce in size and
 * in every instruction, and fifteen bytes differ, all of them register
 * numbers: the original keeps the id parameter in r5 and the loop counter in
 * r4, where this source coalesces the two into r4 because the counter is born
 * after the id dies.  Twenty shapes were tried, five declaration orders for
 * the three locals crossed with two statement orders, plus four forms that
 * give the counter a live range reaching back past the id's last use; the
 * best is fifteen and the ranking is flat between fifteen and twenty-eight. *
 */
u32 func_0200BBA8(void *a)
{
    u32 r = 0;

    if (func_02017E88(func_0200BBEC(a, 0, 0), 0xA9, 0) != 0) {
        r = 1;
    }
    return r;
}





/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200BC10, func_0200BC20, func_0200BC2C, func_0200BC4C,
 *           func_0200BC88, func_0200BCA0, func_0200BCA8, func_0200BCB8,
 *           func_0200BCD8, func_0200BCEC
 *
 * 384 bytes, 0x0200BBC8..0x0200BD48, 14 functions, none of which carries a
 * label in the generated listing: not one of them saves lr, so the whole
 * range arrives as a run of `.word`s between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * The object is two 0xE4-byte slots at +0x000, each an in-use word, a
 * 0xDC-byte payload and a word behind it, plus a flag word at +0x1C8.  That
 * is 0x1CC bytes and it is exactly what func_0200BD98 in
 * src/matched/unit_0200BD98.c returns as the size of the save block with id
 * 0x32, so the record is pinned from both ends.  The halfword of bits at
 * +0x358 that func_0200BBC8, func_0200BBD8 and func_0200BBFC reach is past
 * that end and therefore belongs to some other object the same file also
 * serves; it is declared here as one struct only because nothing in the range
 * distinguishes the two.  The three sizes are pinned by the three
 * `ldm`/`stm` copies and agree: 0x1B pairs plus a word is the 0xDC payload
 * func_0200BC4C stores, and 0x1C pairs plus a word is the whole 0xE4 slot
 * func_0200BCEC swaps through a stack temporary.  See
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; both copies are
 * eight-byte stepped, which is what says the payload is word aligned rather
 * than a byte array.
 *
 * func_0200BBEC belongs to a different object: it is pure address arithmetic
 * over a 0x330-byte record holding six 0x88-byte entries, and it is here only
 * because the file it was written in also holds the accessors above.  Its one
 * caller in this region, func_0200BBA8, is outside this range.
 *
 * Every guard in the file that ends in a shared exit is written as one
 * conjunction rather than as a run of early returns, which is what gives the
 * single epilogue the original has; see
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md.
 */
void func_0200BBC8(struct Obj *p, u32 v)
{
    p->unk358 |= (u16)v;
}




void func_0200BBD8(struct Obj *p, int v)
{
    p->unk358 &= ~v;
}




void *func_0200BBEC(void *base, u32 i, u32 j)
{
    return (u8 *)base + i * 0x330 + j * 0x88;
}




u32 func_0200BBFC(struct Obj *p, u32 mask)
{
    if ((p->unk358 & mask) != 0) {
        return 1;
    }
    return 0;
}




void func_0200BC10(struct Obj *p)
{
    if (p->unk1C8 != 1) {
        p->unk1C8 = 1;
    }
}




void func_0200BC20(struct Obj *p)
{
    p->unk1C8 = 0;
}




struct Payload *func_0200BC2C(struct Obj *p, s32 i)
{
    if (i < 0 || i >= 2 || p->slot[i].unk00 != 1) {
        i = 0;
    }
    return &p->slot[i].unk04;
}




void func_0200BC4C(struct Obj *p, s32 i, const struct Payload *src)
{
    if (i >= 0 && i < 2 && p->slot[i].unk00 != 1) {
        p->slot[i].unk04 = *src;
        p->slot[i].unk00 = 1;
        p->slot[i].unkE0 = 0;
    }
}




void func_0200BC88(struct Obj *p, s32 i)
{
    if (i >= 0 && i < 2 && p->slot[i].unk00 == 1) {
        p->slot[i].unk00 = 0;
    }
}




u32 func_0200BCA0(struct Obj *p)
{
    return p->unk1C8;
}




u32 func_0200BCA8(struct Obj *p, u32 i)
{
    if (i >= 2) {
        return 0;
    }
    return p->slot[i].unk00;
}




u32 func_0200BCB8(struct Obj *p)
{
    s32 i;
    u32 n = 0;

    for (i = 0; i < 2; i++) {
        if (p->slot[i].unk00 == 1) {
            n++;
        }
    }
    return n;
}




u32 func_0200BCD8(struct Obj *p, u32 i)
{
    if (i >= 2) {
        return 0;
    }
    return p->slot[i].unkE0;
}




void func_0200BCEC(struct Obj *p, s32 a, s32 b)
{
    struct Slot tmp;

    if (a >= 0 && a < 2 && b >= 0 && b < 2) {
        tmp = p->slot[a];
        p->slot[a] = p->slot[b];
        p->slot[b] = tmp;
    }
}




/*
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 func_021C3378
 * (wave A1, lane 13).
 */
void func_0200BD48(E *e, u32 add)
{
    int i;
    u64 v;

    for (i = 0; i < 2; i++) {
        if (e[i].active == 1) {
            v = (u64)e[i].count + add;
            if (v > 0xFFFFFFFF)
                v = 0xFFFFFFFF;
            e[i].count = v;
        }
    }
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 36 bytes, 0x0200BD98..0x0200BDBC, 3 functions, none of which carries a
 * label in the generated listing.
 *
 * The size, constructor and lookup of the save block with id 0x32.  0x1CC is
 * exactly 2 * 0xE4 + 4, which is the two-slot record the accessors of
 * src/matched/unit_0200BBC8.c reach through a slot stride of 0xE4 and a flag
 * word at +0x1C8, so this is that object's header and the range immediately
 * before it is its accessor set.
 *
 * Both of the last two functions are bare tail calls, which is why neither
 * has a prologue and why each spends a literal pool word on its callee: see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  The constructor does
 * nothing but clear the block, so there is no field this file pins.
 */
u32 func_0200BD98(void)
{
    return sizeof(struct Blk32);
}




void func_0200BDA0(struct Blk32 *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Blk32));
}



void *func_0200BDB0(void *sys)
{
    return func_020071CC(sys, 0x32);
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200BDFC, func_0200BE00, func_0200BE24
 *
 * 140 bytes, 0x0200BDBC..0x0200BE48, 7 functions, five of which carry no
 * label in the generated listing.
 *
 * A 0x1B0-byte record: func_0200BDBC returns its size and func_0200BDC4
 * clears exactly that many bytes, which is the block-file opening this region
 * keeps producing.  The constructor then seeds the byte at +0x1A0 with 0x30
 * and reaches it by subtracting 0x10 from the size it already has in a
 * register rather than materialising 0x1A0 again; that is the compiler's
 * doing and not a second constant in the source.
 *
 * func_0200BDE4 hands the first sixteen bytes to func_021763BC, which lives
 * in overlay address space.  The call is attested because ov019's generated
 * listing carries a `func_` label at 0x021763BC and branches elsewhere in the
 * image reach it; see "Callees that live in an overlay" in docs/MATCHING.md.
 *
 * func_0200BE00 and func_0200BE24 are the same clamped adder over two
 * neighbouring `u16` counters, and the ceiling 999 arrives from a literal
 * pool in each of them because it does not fit a Thumb immediate.  The
 * increment has to be written `p->f += v` with a **signed** parameter: the
 * comparison is a signed `ble`, and spelling the store as
 * `p->f = p->f + (u16)v` adds the truncation pair the store already does for
 * free.
 */
u32 func_0200BDBC(void)
{
    return sizeof(struct Rec1B0_0200BDBC);
}




void func_0200BDC4(struct Rec1B0_0200BDBC *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Rec1B0_0200BDBC));
    func_0200BDE4(p);
    p->unk1A0 = 0x30;
}



void func_0200BDE4(struct Rec1B0_0200BDBC *p)
{
    MI_CpuFill8(p, 0, 0x10);
    func_021763BC(p);
}



u16 func_0200BDF8(struct Rec1B0_0200BDBC *p)
{
    return p->unk0C;
}



u16 func_0200BDFC(struct Rec1B0_0200BDBC *p)
{
    return p->unk0E;
}



void func_0200BE00(struct Rec1B0_0200BDBC *p, s32 v)
{
    if (p->unk0C + v > 999) {
        p->unk0C = 999;
    } else {
        p->unk0C += v;
    }
}



void func_0200BE24(struct Rec1B0_0200BDBC *p, s32 v)
{
    if (p->unk0E + v > 999) {
        p->unk0E = 999;
    } else {
        p->unk0E += v;
    }
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * 60 bytes, 0x0200BE48..0x0200BE84, 3 functions, one of which carries no
 * label in the generated listing.
 *
 * The lookup of the save block with id 0x35 and the two directions of an
 * eight halfword copy in and out of it.  Both loops count **down** from 8
 * with `subs`/`bne` and no compare at all, which a `for (i = 0; i < 8; i++)`
 * does not produce: that spelling keeps the induction variable and costs a
 * `cmp` and a `blt`.  `for (i = 8; i != 0; i--)` over an unsigned counter is
 * what gives the original's six instruction body, and so does the equivalent
 * `do`/`while (--i != 0)`.
 */
u16 *func_0200BE48(void *sys)
{
    return func_020071CC(sys, 0x35);
}




void func_0200BE54(void *sys, const u16 *src)
{
    u16 *d = func_0200BE48(sys);
    u32 i;

    for (i = 8; i != 0; i--) {
        *d++ = *src++;
    }
}




void func_0200BE6C(void *sys, u16 *dest)
{
    const u16 *s = func_0200BE48(sys);
    u32 i;

    for (i = 8; i != 0; i--) {
        *dest++ = *s++;
    }
}




/*
 * A 20-entry table of 20-byte records at p+0x10 (not at p: p+0x10..p+0x1A0
 * is exactly 20 * 0x14, and p+0x1A0 is the byte func_0200BF08 of
 * src/matched/unit_0200BF08.c sets).  Insert a copy of *q into the first
 * record whose `f00[8] == 0`, else drop the oldest record and append.
 *
 * The record is `u16 f00[9]; u8 f12;` -- 19 bytes rounded to 20 by its
 * two-byte alignment, which is why `*s = *q;` is a 10-iteration ldrh/strh
 * loop and not a five-word ldm/stm pair: an align-2 aggregate has no
 * four-byte move to use.  `f00[8]` is the free-slot marker and it is what
 * the scan loop tests at [slot+0x10].
 *
 * Declaration order decides the register plan here, and it is not the
 * order the statements run in: with `u16 stamp;` declared before
 * `Slot *s = p->slot;` the same body compiles to the same 130 bytes with a
 * different allocation (p in r5, q in r4, the cursor demoted to the
 * scratch r2, 47 bytes out).  Declaring `s` first makes the cursor's live
 * range start before the GX_GetBankForLCDC call, so it earns a
 * callee-saved register (p -> r6, q -> r5, cursor -> r4) and the whole
 * prologue lines up.  See docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *
 * GX_GetBankForLCDC takes no arguments and returns the u16 bank mask
 * (src/calib/gx_getbankforlcdc.c); the `blx` is a Thumb -> ARM call, so
 * the symbol is declared `arm`.
 *
 * EXACT*: the listing's extent for 0x0200BE84 runs to 0x0200BFA4 because
 * the seven functions at 0x0200BF08..0x0200BFA4 save no lr and carry no
 * label; the compared range is the 130 bytes of this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200BE84.c \
 *       --func func_0200BE84 --addr 0x0200BE84 --cc 1.1p1 --thumb
 */
void func_0200BE84(Rec *p, Slot *q)
{
    Slot *s = p->slot;
    u16 stamp;
    int i;

    stamp = GX_GetBankForLCDC();

    for (i = 0; i < 8; i++) {
        if (stamp == q->f00[i]) {
            break;
        }
    }
    if (i == 8) {
        return;
    }
    if (q->f12 >= 0x12) {
        return;
    }
    for (i = 0; i < 20; i++, s++) {
        if (s->f00[8] == 0) {
            *s = *q;
            return;
        }
    }
    for (i = 1; i < 20; i++) {
        p->slot[i - 1] = p->slot[i];
    }
    p->slot[19] = *q;
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           func_0200BF70, func_0200BF78, func_0200BF94
 *
 * 156 bytes, 0x0200BF08..0x0200BFA4, 7 functions, none of which carries a
 * label in the generated listing.
 *
 * The tail of the 0x1B0-byte record whose size getter and constructor are
 * src/matched/unit_0200BDBC.c: a byte at +0x1A0, a two-byte bitmap at +0x1A1,
 * a clamped counter at +0x1A4 and a `u64` at +0x1A8, which is 0x1B0 exactly.
 * func_0200BF94 is the tell for the last of those: it returns +0x1A8 in r0
 * and +0x1AC in r1, which is one 64-bit value and not two out-parameters.
 * See docs/idioms/long-long-aligns-to-four.md.
 *
 * func_0200BF18 sets one bit of the bitmap for an id in 0x21..0x26, and the
 * index arithmetic is signed: `lsrs #0x1F` / `lsls #0x1D` / `subs` /
 * `rors #0x1D` is `% 8` on a signed value, exactly as in
 * src/matched/sub_0200A6BC.c, and `& 7` would have been a two-instruction
 * `movs`/`ands`.  The two range tests branch to one exit, so they are one
 * conjunction rather than two early returns.
 *
 * The base address 0x1A1 arrives from a literal pool in both functions that
 * touch the bitmap, because a register-offset `ldrb`/`strb` has no immediate
 * at all; that is the forced case of
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md
 * and not evidence of a second object.
 */
void func_0200BF08(struct Rec1B0_0200BF08 *p, u32 v)
{
    p->unk1A0 = v;
}



u8 func_0200BF10(struct Rec1B0_0200BF08 *p)
{
    return p->unk1A0;
}



void func_0200BF18(struct Rec1B0_0200BF08 *p, s32 id)
{
    s32 n = id - 0x21;

    if (n >= 0 && id <= 0x26) {
        p->unk1A1[n / 8] |= (u8)(1 << (n % 8));
    }
}



void func_0200BF54(struct Rec1B0_0200BF08 *p, u8 *dest, u32 n)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        dest[i] = p->unk1A1[i];
    }
}



u32 func_0200BF70(struct Rec1B0_0200BF08 *p)
{
    return p->unk1A4;
}



u32 func_0200BF78(struct Rec1B0_0200BF08 *p)
{
    if (p->unk1A4 < 99999) {
        p->unk1A4++;
    }
    return p->unk1A4;
}



unsigned long long func_0200BF94(struct Rec1B0_0200BF08 *p)
{
    return p->unk1A8;
}




/*
 * battle_rec.c, 0x0200BFA4..0x0200C058: the play-clock accumulator and the
 * unlabelled 4-byte follower func_0200C054 (`return 0xEC;`, a size getter).
 *
 * func_0200BFA4 converts the h:m:s clock at q to seconds and, by mode,
 * latches it (0), adds the elapsed delta into the u64 at +0x1A8 (1), or
 * returns that total plus the delta without storing it (2).  What closed it
 * after docs/notes/pkt_0200BFA4.c.txt (79 out, 4 bytes short):
 *   - the three clock fields are u64 LOCALS: the image zeroes the high half
 *     (`movs r4, #0`) right after the first call and keeps four stack
 *     words, which a u32 t[3] never gives;
 *   - the sum is written minutes first, `mm * 60 + hh * 3600 + ss` (the
 *     _ull_mul calls follow source order);
 *   - mode 2 returns `total + (v - g)`, not `total - g` (the four missing
 *     bytes were that add).
 *
 * Integrator: seed 0x0200C054 (unlabelled follower, member of this unit).
 */
u64 func_0200BFA4(u8 *p, void *q, u32 mode)
{
    u64 hh, mm, ss;
    u64 v;

    hh = func_0200864C(q);
    mm = func_02008650(q);
    ss = func_02008654(q);
    v = mm * 60 + hh * 3600 + ss;

    switch (mode) {
    case 0:
        g_02146170 = v;
        break;
    case 1:
        ((struct Obj07120 *)p)->f1A8 = ((struct Obj07120 *)p)->f1A8 + (v - g_02146170);
        break;
    case 2:
        return ((struct Obj07120 *)p)->f1A8 + (v - g_02146170);
    }
    return ((struct Obj07120 *)p)->f1A8;
}




u32 func_0200C054(void)
{
    return 0xEC;
}




void func_0200C058(Obj *p)
{
    void *a;
    void *b;
    void *c;

    memset(p, 0, 0xec);
    func_0200C10C((struct Blk34 *)p);
    p->f14 &= 0xf0000000;
    a = func_02045B38(0, 3, 0x2f, 0x8007);
    b = func_02045EC0(a, 0x151);
    func_02045A38(b, (u16 *)p->f20, 9);
    func_02045808(b);
    c = func_02045EC0(a, 0x159);
    func_02045A38(c, (u16 *)p->f32, 9);
    func_02045808(c);
    func_02045C04(a);
    p->f44 = 0;
    p->f46 = 0;
    p->f47 = 0xff;
    p->f48 = 0xff;
    p->f49 = 0xff;
}




/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 *           func_0200C10C, func_0200C11C, func_0200C164, func_0200C184,
 *           func_0200C18C, func_0200C1A4, func_0200C1B0, func_0200C1C4,
 *           func_0200C1C8, func_0200C1DC, func_0200C1E0, func_0200C1F4,
 *           func_0200C1F8, func_0200C20C, func_0200C210, func_0200C224,
 *           func_0200C22C, func_0200C234, func_0200C248, func_0200C258,
 *           func_0200C274, func_0200C278, func_0200C29C, func_0200C2B0,
 *           func_0200C2D0, func_0200C2F0, func_0200C308, func_0200C31C,
 *           func_0200C324, func_0200C32C, func_0200C334, func_0200C33C,
 *           func_0200C344, func_0200C34C, func_0200C358, func_0200C364,
 *           func_0200C37C, func_0200C384, func_0200C38C, func_0200C39C,
 *           func_0200C3B0, func_0200C3B8, func_0200C3C0, func_0200C3E0,
 *           func_0200C3EC
 *
 * 780 bytes, 0x0200C0E8..0x0200C3F4, 49 functions, forty-four of which carry
 * no label in the generated listing: the file is almost entirely accessors
 * and none of them saves lr.
 *
 * The object is the save block with id 0x34: func_0200C0F0 is the whole of
 * its lookup, `func_020071CC(sys, 0x34)`, and func_0200C0E8 is a wrapper
 * that forwards to it.  The layout below is read off the accessors and is
 * self-consistent to the byte from +0x00 to +0xE2; nothing here returns
 * sizeof, because the size getter of this block belongs to whatever file
 * precedes it, so the tail past +0xE2 is not pinned.
 *
 * Three things in it cost real time.
 *
 *  - func_0200C164 takes a **const** pointer, and that is the whole
 *    difference between it and the twelve-byte-longer version.  Its three
 *    bitfield reads come out of one `ldrb` in the original, and through a
 *    non-const pointer this compiler reloads the byte before each of the two
 *    later ones, because the intervening `str` through a `u32 *` may alias
 *    it.  See docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md.
 *  - func_0200C3C0 goes the other way and reads +0xE0 twice, once for the
 *    compare and once for the subtraction, with the address recomputed each
 *    time.  Nothing that leaves the field ordinary reproduces that: the
 *    compiler folds the two reads into one under every spelling of the
 *    branch, the arms, the cast and the pointer.  Declaring the field
 *    `volatile` is what keeps both reads, and it costs nothing in the getter
 *    and setter on either side of it, which touch it once each.
 *  - the pair at +0x50 is one `u64` read back as two words, the union of
 *    docs/idioms/long-long-aligns-to-four.md: func_0200C37C returns the
 *    64-bit value and func_0200C384 stores the two halves from two register
 *    arguments.
 */
void *func_0200C0E8(void *sys)
{
    return func_0200C0F0(sys);
}




void *func_0200C0F0(void *sys)
{
    return func_020071CC(sys, 0x34);
}




void func_0200C0FC(struct Blk34 *p, u32 i, u8 v)
{
    p->unk0C[i] = v;
}



u8 func_0200C104(struct Blk34 *p, u32 i)
{
    return p->unk0C[i];
}



void func_0200C10C(struct Blk34 *p)
{
    MI_CpuFill8(p->unk0C, 0, sizeof(p->unk0C));
}



void func_0200C11C(struct Blk34 *p, u16 a, u32 b, u32 c, u32 d)
{
    p->unk08 = a;
    p->unk0A.f0 = b;
    p->unk0A.f6 = c;
    p->unk0A.f7 = (d == 1);
}



void func_0200C164(const struct Blk34 *p, u32 *a, u32 *b, u32 *c, u32 *d)
{
    *a = p->unk08;
    *b = p->unk0A.f0;
    *c = p->unk0A.f6;
    *d = p->unk0A.f7;
}



u32 func_0200C184(struct Blk34 *p)
{
    return p->f14_0;
}



void func_0200C18C(struct Blk34 *p, u32 v)
{
    p->f14_0 = v;
}



u8 func_0200C1A4(struct Blk34 *p)
{
    return p->f14_28;
}



void func_0200C1B0(struct Blk34 *p, u32 v)
{
    p->f14_28 = v;
}



u32 func_0200C1C4(struct Blk34 *p)
{
    return p->unk18;
}



u32 func_0200C1C8(struct Blk34 *p)
{
    if (p->unk18 < 99999) {
        p->unk18++;
    }
    return p->unk18;
}



u32 func_0200C1DC(struct Blk34 *p)
{
    return p->unk1C;
}



u32 func_0200C1E0(struct Blk34 *p)
{
    if (p->unk1C < 99999) {
        p->unk1C++;
    }
    return p->unk1C;
}



u16 *func_0200C1F4(struct Blk34 *p)
{
    return p->unk20;
}



void func_0200C1F8(struct Blk34 *p, const u16 *src)
{
    func_02045A38((struct U16Vec *)src, p->unk20, 9);
}



u16 *func_0200C20C(struct Blk34 *p)
{
    return p->unk32;
}



void func_0200C210(struct Blk34 *p, const u16 *src)
{
    func_02045A38((struct U16Vec *)src, p->unk32, 9);
}



u8 func_0200C224(struct Blk34 *p)
{
    return p->unk44;
}



void func_0200C22C(struct Blk34 *p, u8 v)
{
    p->unk44 = v;
}



u32 func_0200C234(struct Blk34 *p, u32 bit)
{
    return (p->unk04 & (1 << bit)) != 0;
}



void func_0200C248(struct Blk34 *p, u32 bit)
{
    p->unk04 |= 1 << bit;
}



u32 func_0200C258(struct Blk34 *p)
{
    u32 n = 0;
    u32 v;

    for (v = p->unk04; v != 0; v >>= 1) {
        if (v & 1) {
            n++;
        }
    }
    return n;
}



u32 func_0200C274(struct Blk34 *p)
{
    return p->unk00;
}



u32 func_0200C278(struct Blk34 *p, u32 v)
{
    if (v > 9999999) {
        p->unk00 = 9999999;
    } else {
        p->unk00 += v;
    }
    if (p->unk00 > 9999999) {
        p->unk00 = 9999999;
    }
    return p->unk00;
}



u32 func_0200C29C(struct Blk34 *p, u32 v)
{
    if (p->unk00 < v) {
        p->unk00 = 0;
    } else {
        p->unk00 -= v;
    }
    return p->unk00;
}



void func_0200C2B0(struct Blk34 *p, u32 i, const u16 *src)
{
    s32 j;

    for (j = 0; j < 6; j++) {
        p->unk58[i].v[j] = src[j];
    }
}



void func_0200C2D0(struct Blk34 *p, u32 i, u16 *dest)
{
    s32 j;

    for (j = 0; j < 6; j++) {
        dest[j] = p->unk58[i].v[j];
    }
}



void func_0200C2F0(struct Blk34 *p, u32 i, u8 v)
{
    p->unk45 |= (u8)(v << (i * 2));
}



u8 func_0200C308(struct Blk34 *p, u32 i)
{
    return (u8)((p->unk45 >> (i * 2)) & 3);
}



u8 func_0200C31C(struct Blk34 *p)
{
    return p->unk45;
}



void func_0200C324(struct Blk34 *p, u8 v)
{
    p->unk45 = v;
}



u8 func_0200C32C(struct Blk34 *p)
{
    return p->unk46;
}



void func_0200C334(struct Blk34 *p, u8 v)
{
    p->unk46 = v;
}



int func_0200C33C(struct Blk34 *p, u32 i)
{
    return p->unk47[i];
}



void func_0200C344(struct Blk34 *p, u8 i, u8 v)
{
    p->unk47[i] = v;
}



u16 func_0200C34C(struct Blk34 *p, u32 i)
{
    return p->unk4A[i];
}



void func_0200C358(struct Blk34 *p, u32 i, int v)
{
    p->unk4A[i] = v;
}



void func_0200C364(struct Blk34 *p, u8 i, int v)
{
    u32 n = p->unk4A[i];

    n += v;
    if (n > 0xFFFF) {
        n = 0xFFFF;
    }
    p->unk4A[i] = n;
}



unsigned long long func_0200C37C(struct Blk34 *p)
{
    return p->unk50.q;
}



void func_0200C384(struct Blk34 *p, u32 lo, u32 hi)
{
    p->unk50.w.lo = lo;
    p->unk50.w.hi = hi;
}



void func_0200C38C(struct Blk34 *p, s32 i, u32 v)
{
    if (i < 8) {
        p->unkB8[i] = v;
    }
}



u32 func_0200C39C(struct Blk34 *p, s32 i)
{
    if (i >= 8) {
        return 0;
    }
    return p->unkB8[i];
}



u16 func_0200C3B0(struct Blk34 *p)
{
    return p->unkE0;
}



void func_0200C3B8(struct Blk34 *p, u16 v)
{
    p->unkE0 = v;
}



void func_0200C3C0(struct Blk34 *p, u16 v)
{
    if (v <= p->unkE0) {
        p->unkE0 = p->unkE0 - v;
    } else {
        p->unkE0 = 0;
    }
}



u8 func_0200C3E0(struct Blk34 *p)
{
    return p->unkDC;
}



void func_0200C3EC(struct Blk34 *p, u32 v)
{
    p->unkDC = v;
}
