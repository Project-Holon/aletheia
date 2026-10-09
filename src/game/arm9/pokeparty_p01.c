/*
 * file:     pokeparty_p01.c
 * unit:     yes
 * function: func_02019A50, func_02019A7C, func_02019A9C, func_02019ABC, func_02019B04, func_02019B44, func_02019B58, func_02019B64, func_02019B94, func_02019BA4, func_02019C38, func_02019C54, func_02019C7C, func_02019C90, func_02019CA0, func_02019CE0, func_02019CF8, func_02019D00, func_02019D30, func_02019D58, func_02019D84, func_02019DA4, func_02019E54, func_02019ED4, func_02019FD0, func_0201A090, func_0201A26C, func_0201A2A8, func_0201A30C, func_0201A354, func_0201A364, func_0201A374, func_0201A3F4, func_0201A468, func_0201A48C, func_0201A4A0, func_0201A4B4, func_0201A4D4, func_0201A570, func_0201A59C, func_0201A5FC, func_0201A858, func_0201A918, func_0201A920, func_0201A948, func_0201A954, func_0201A98C, func_0201A9C8, func_0201AA14, func_0201AA18, func_0201AA1C, func_0201AA50, func_0201AA88, func_0201AAD4, func_0201AB08, func_0201AB18, func_0201AB28, func_0201AB34, func_0201AB48, func_0201AB8C, func_0201AC2C, func_0201AC44, func_0201AC80, func_0201ACC4, func_0201ACDC, func_0201AD0C, func_0201AD18, func_0201AD40, func_0201AD58, func_0201AD88, func_0201ADA4, func_0201ADD0, func_0201ADE4, func_0201AE14, func_0201AE1C, func_0201AF6C, func_0201AF80, func_0201AFD4, func_0201B038, func_0201B100, func_0201B170, func_0201B220, func_0201B25C, func_0201B268, func_0201B280, func_0201B28C, func_0201B2B0, func_0201B718, func_0201B764, func_0201B774, func_0201B7A0, func_0201B7B4, func_0201B7EC, func_0201B818, func_0201B850, func_0201B920, func_0201B970, func_0201B9F0, func_0201BA34, func_0201BA68, func_0201BABC, func_0201BB5C, func_0201BBE8, func_0201BC3C, func_0201BC40, func_0201BC78, func_0201BCB4, func_0201BCEC, func_0201BD28, func_0201BDB4, sub_0201BEB8, sub_0201BF44, sub_0201BF58, func_0201C020, func_0201C0BC, func_0201C158, func_0201C184, func_0201C1BC, func_0201C1C8, func_0201C1D8, func_0201C1E8, func_0201C1F4, func_0201C284, func_0201C314, func_0201C328, func_0201C3C0, func_0201C41C, func_0201C440, func_0201C450, func_0201C4C0, func_0201C4C8, func_0201C4DC, func_0201C4E4
 * address:  0x02019A50
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
 *   gMsgBank   0x020A7370  data
 *   gNameBuf   0x021462F0  data
 *   _s32_div_f           0x0209C0A4  arm
 *   func_02019B04_Table  0x0209E324  data
 *   func_02048F4C  0x02048F4C  arm
 *   gWordBuf       0x02146398  data
 *   gBlockOrder  0x0209E3A4  data
 *   g_02146270   0x02146270  data
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02018584  0x02018584  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   sub_0209E280_Map  0x0209E280  data
 *   d_0209E42C 0x0209E42C data a2
 *   func_0200AE54   0x0200AE54  thumb
 *   func_0200AFD4   0x0200AFD4  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201AA50   0x0201AA50  thumb
 *   func_02048F60  0x02048F60  arm
 *   func_0201EFA4   0x0201EFA4  thumb
 *   func_020457B0   0x020457B0  arm
 *   func_02045CAC   0x02045CAC  arm
 *   func_0201F250   0x0201F250  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02030734 0x02030734  arm
 *   func_02045808 0x02045808  arm
 *   func_02045B38 0x02045B38  arm
 *   tbl_0209E444  0x0209E444  data
 *   func_02045C04   0x02045C04  arm
 *   func_020307B0   0x020307B0  arm
 *   g_0209E424      0x0209E424  data
 *   sub_0201A920_File  0x020A7304  data
 *   sub_0201AB8C_File  0x020A7304  data
 *   sub_020071CC  0x020071CC  thumb
 *   g_0214652C  0x0214652C  data
 *   sub_0201ADE4_File  0x020A7310  data
 *   func_0204A39C  0x0204A39C  arm
 *   _ull_mul       0x0209C054  arm
 *   func_0203F0A8  0x0203F0A8  arm
 *   func_02020FE4   0x02020FE4  thumb
 *   func_02011410   0x02011410  thumb
 *   s_shinka_check_c 0x020A7330 data  a1
 *   g_020A7320      0x020A7320  data  a2
 *   g_020A7322      0x020A7322  data  a2
 *   g_020A7324      0x020A7324  data  a2
 *   g_020A732A      0x020A732A  data  a2
 *   func_020490F4  0x020490F4  arm
 *   func_0204932C  0x0204932C  arm
 *   g_0209E45C     0x0209E45C  data
 *   func_0201B850  0x0201B850  thumb
 *   g_0209E465     0x0209E465  data  a1
 *   g_0209E462     0x0209E462  data
 *   func_02013E4C   0x02013E4C  thumb
 *   func_02011014   0x02011014  thumb
 *   g_0209E474  0x0209E474  data
 *   gWazaTool   0x02146530  data
 *   g_02146534  0x02146534  data
 *   sub_0201C328_File  0x020A7340  data
 *   g_02146558         0x02146558  data
 *   sub_0201C450_File   0x020A734C  data
 *   func_0201DE00  0x0201DE00  thumb
 *   func_0201DE18  0x0201DE18  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_020870D0  0x020870D0  arm
 *   func_0201C974  0x0201C974  thumb
 *   func_0201D7C4  0x0201D7C4  thumb
 */
#include "../../matched/include/Obj06868.h"
#include "../../matched/include/Obj11261.h"
#include "../../matched/include/Obj15718.h"
#include "../../matched/include/Obj15719.h"
#include "../../matched/include/Obj17207.h"
#include "../../matched/include/Obj17208.h"

#define REG_DISPCNT      (*(volatile u32 *)0x04000000)
#define REG_DB_DISPCNT   (*(volatile u32 *)0x04001000)
#define OBJ_MAPPING_MASK 0x300010
struct MsgData;
struct Personal;
struct Reg;
struct MsgBank;
struct WordSet;
struct U16Vec;
struct Rec_0201A4D4;
struct Sav;
struct Sub020071CCCtrl;
struct ArcFile;
struct Bmp;
struct PrintCtx;
struct Waza;
typedef unsigned short u16;

typedef unsigned int   u32;

struct Mon_02019A50 {
    u32 unk00;
};

struct BlockA {
    u16 species;
};

typedef signed char    s8;

typedef unsigned char  u8;

struct Mon_02019C38 {
    u32 unk00;
    u16 flags;
    u16 unk06;
    u8  block[0x80];
};

struct Memo {
    u16 b;
    u16 a;
    u8  obj[0x10];
};

struct RecDC {
    u32 unk00[0x37];
};

typedef signed int     s32;

typedef unsigned long long u64;

struct Ctx {
    struct MsgBank *bank;
    u8 pad04[0x30];
    u8 f34;
};

struct PartyMon {
    u32 w[0x37];
};

struct Party_0201A4D4 {
    s32 capacity;
    s32 count;
    struct PartyMon mon[6];
    u8  unk530;
};

typedef u32 (*Predicate)(void *entry);

struct Party_0201AB28 {
    u32 unk00;
    u32 count;
    struct PartyMon mon[6];
};

struct Rec534 {
    u32 unk000[0x14D];
};

struct Personal_0201AE1C {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08;
    u8  unk09;
    u16 ev0 : 2;
    u16 ev1 : 2;
    u16 ev2 : 2;
    u16 ev3 : 2;
    u16 ev4 : 2;
    u16 ev5 : 2;
    u16 unk0A_12 : 1;
    u16 unk0A_13 : 3;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u8  unk12;
    u8  unk13;
    u8  unk14;
    u8  unk15;
    u8  unk16;
    u8  unk17;
    u8  unk18;
    u8  unk19;
    u8  unk1A;
    u8  unk1B;
    u16 unk1C;
    u16 unk1E;
    u8  unk20;
    u8  unk21_0 : 6;
    u8  unk21_6 : 1;
    u8  unk21_7 : 1;
    u16 unk22;
    u16 unk24;
    u16 unk26;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
};

struct Personal_0201AFD4 {
    u8  unk00[0x1C];
    u16 unk1C;
    u8  unk1E[2];
    u8  unk20;
    u8  unk21[0x1B];
};

struct EvoRow_0201B2B0 {
    u16 method;
    u16 param;
    u16 target;
};

struct EvoRow_0201B70C {
    u16 method;
    u16 param;
    u16 species;
};

struct EvoTable {
    struct EvoRow_0201B70C rows[7];
    u16 unk2A;
};

struct Rec_0201A4D4 {
    u32 unk00;
    s32 unk04;
    u8  unk08[1];
};

struct Waza {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u8  unk04;
    u8  unk05;
    s8  unk06;
    u8  lo : 4;
    u8  hi : 4;
    u16 unk08;
    u8  unk0A;
    u8  unk0B;
    u8  unk0C;
    u8  unk0D;
    u8  unk0E;
    u8  unk0F;
    u16 unk10;
    s8  unk12;
    s8  unk13;
    u8  unk14;
    u8  unk15[3];
    s8  unk18[3];
    u8  unk1B[3];
    u8  pad1E[2];
    u32 unk20;
};

struct WazaTool {
    struct Waza **recs;
    u16 *vals;
    s32 count;
};

typedef short          s16;

union Packed {
    struct {
        u16 a : 4;
        u16 b : 6;
        u16 c : 6;
    } f;
    s16 v;
};

union Ticks {
    u64 v;
    struct {
        u32 lo;
        u32 hi;
    } w;
};

struct PrintSys_0201C450 {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8  unk06;
    u8  unk07;
    union Ticks unk08;
    void *unk10;
    void *unk14;
};

struct Rec_0201B7B4 {
    u32 unk00;
    u32 pad04a : 20;
    s32 kind   : 4;
    u32 pad04b : 8;
    u32 pad08;
    u16 pad0C;
    u16 unk0E;
};

struct PrintSys_0201C4E4 {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8  unk06;
    u8  unk07lo : 4;
    u8  unk07hi : 4;
    u64 unk08;
    struct Rec_0201B7B4 *unk10;
    u16 *unk14;
    u8  buf[4];
};

extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32 func_0201F448(const u16 *a, const u16 *b);
extern void *func_020185F0();
extern u32   func_02017E88(void *p, u32 id, u32 v);
extern void  func_02017E64(void *p, u32 id, u32 v);
extern void  func_02048F4C(void *a, u32 b, u32 c);
extern u32  func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32  func_02018584(u16 a, u16 b, u16 v);
extern void func_020185C4(void *p);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern u32 func_0200AFD4(struct Reg *p, u32 id, s32 n);
extern u32 func_0201AA18(void *p);
extern void MI_CpuFill8(void *dst, u8 v, u32 n);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_0201AA50(void *p);
extern void *func_02048F60(unsigned int archive_id, unsigned int member, unsigned int heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern void func_02045808(struct U16Vec *vec);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec_0201A4D4 *rec);
extern u32 func_020307B0(void *p);
extern void MIi_CpuClearFast(u32 value, void *dest, u32 size);
extern void func_02017528(struct Sav *p);
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_02049578(struct ArcFile *handle, u32 x);
extern void *func_0204960C(void *handle, void *x);
extern void func_020495F4(struct ArcFile *arc, u32 size, void *dst);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u32   func_0203F0A8(void);
extern u32   func_02020FE4(u32 id, u32 sel, u16 heap);
extern u32   func_02011410(u32 tz);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void func_0201B850(void *mon, const s8 *tbl, int a2, u16 a3);
extern u32 func_02013E4C(u32 id);
extern int func_02011014(int a0);
extern u8  func_0201C158(u32 move, u32 ppUp);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32  func_020490A8(u32 kind, u32 member);
extern int func_0201BD28(int, int);
extern void func_020457A0(u16 stamp);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u32 heap);
extern void  func_0201DE00(u8 *r, u8 *g, u8 *b);
extern u32   func_0201DE18(u32 r, u32 g, u32 b);
extern void  func_0201DD78(u32 r, u32 g, u32 b);
extern u64   func_020870D0(void);
extern u16 *func_0201C974(struct PrintCtx *c, u16 *p, u32 f);
extern void *func_0201D7C4(struct PrintSys_0201C4E4 *p, void *q);
void func_02019A50(u16 *p, u32 size, u32 seed);
u16 func_02019A7C(u32 *s);
u16 func_02019A9C(const u16 *p, u32 size);
u32 func_02019ABC(struct Mon_02019A50 *p);
u32 func_02019B04(u32 a, u32 b, u32 n);
s8 func_02019B44(u32 a, u32 n);
void func_02019B58(void *p);
void func_02019B64(void *p);
void func_02019B94(u32 a, void *b);
u32 func_02019BA4(u32 a, u32 i);
u32 func_02019BBC(u32 item);
void *func_02019C38(struct Mon_02019C38 *p, u32 pid, u32 n);
void *func_02019C54(u32 a, u32 b);
u32 func_02019C7C(void *h);
u32 func_02019C90(u16 a, u16 b, u32 k);
void func_02019CA0(void *p, u32 v);
void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
unsigned int func_02019CF8(unsigned int item);
u32 func_02019D00(u32 id);
u32 func_02019D30(u16 a, u16 n);
int func_02019D58(u16 a, int b);
int func_02019D84(unsigned short value);
int func_02019DA4(void *a0, void *a1);
int func_02019E54(u32 a0, u32 a1, u32 a2);
int sub_02019ED4(void *ctx, void *q);
int func_02019FD0(void *a0, void *a1, u32 *a2);
int func_0201A090(void *rules, void *party, u32 *mask);
u32 func_0201A26C(void *a0, u32 a1);
void func_0201A2A8(void *a0, void *a1);
void func_0201A30C(void *a0, void *a1, u32 c);
void *func_0201A354(int a, int b);
void func_0201A364(int a, unsigned int b);
void *func_0201A374(u8 *a0, u32 a1, u32 *a2, u32 a3, u16 a4);
void *func_0201A3F4(const u8 *a0, u32 a1, u32 *a2, u32 a3, u16 a4);
void *func_0201A468(u8 *a0, int a1, struct Ctx *c);
void *func_0201A48C(u8 *a0, int a1, struct Ctx *c);
void *func_0201A4A0(u8 *a0, int a1, struct Ctx *c);
void *func_0201A4B4(u8 *a0, int a1, struct Ctx *c);
u8 *func_0201A4D4(u8 *a0, u32 a1, u16 a2, u32 a3);
void func_0201A570(void *a0);
int func_0201A59C(void *a0, void *a1, void *a2);
int func_0201A5FC(void *a0, void *a1, u8 *a2, char *a3, u32 *a4);
int func_0201A858(u8 *a);
int func_0201A918(void);
struct Party_0201A4D4 *sub_0201A920(u32 heap);
void sub_0201A948(struct Party_0201A4D4 *p);
void sub_0201A954(struct Party_0201A4D4 *p, s32 capacity);
u32 sub_0201A98C(struct Party_0201A4D4 *p, const struct PartyMon *src);
u32 sub_0201A9C8(struct Party_0201A4D4 *p, s32 idx);
u32 sub_0201AA14(void *p);
u32 sub_0201AA18(void *p);
u32 sub_0201AA1C(void *p);
u32 sub_0201AA50(void *p);
u32 sub_0201AA88(void *p);
u32 sub_0201AAD4(void *p);
u32 sub_0201AB08(void *p);
u32 sub_0201AB18(void *p);
void *sub_0201AB28(void *p, u32 idx);
u32 sub_0201AB34(void *p, u32 idx);
void sub_0201AB48(struct Party_0201AB28 *p, u32 idx, const struct PartyMon *src);
u32 sub_0201AB8C(struct Party_0201AB28 *p, u32 i, u32 j, u32 heap);
void sub_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
u32 sub_0201AC44(struct Rec_0201A4D4 *p, u32 target);
u32 sub_0201AC80(void *p);
int sub_0201ACC4(void *p, u32 pos);
void sub_0201ACDC(void *p, u32 pos, u32 mode);
void *sub_0201AD0C(void *sys);
u32 sub_0201AD18(void *p);
u32 sub_0201AD40(void *p);
u32 sub_0201AD58(void *p, Predicate pred);
void sub_0201AD88(u32 heap);
void sub_0201ADA4(u32 a, int b, void *c);
void sub_0201ADD0(u32 a, int b, void *c);
void *sub_0201ADE4(u32 a, int b, u32 c);
void sub_0201AE14(void *p);
u32 sub_0201AE1C(const struct Personal_0201AE1C *p, u32 field);
u32 sub_0201AF6C(u32 v);
u16 *sub_0201AF80(u32 heap, u16 *countOut);
u32 sub_0201AFD4(u32 species, s32 form);
void sub_0201B038(void *party);
void sub_0201B100(void *party, s32 amount);
void sub_0201B170(void *party);
u32 sub_0201B220(void *party);
u32 sub_0201B25C(void *a);
u32 sub_0201B268(void *mon);
u32 sub_0201B280(void *a);
u32 sub_0201B28C(void *mon);
u32 sub_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
void *sub_0201B70C(u32 heap);
u32 sub_0201B718(void *a, u32 id, u32 row, u32 field);
void sub_0201B764(u32 id, void *dest);
u32 sub_0201B774(void *mon, u32 move);
void func_0201B7A0(void *a0, int a1, int a2, u16 a3);
void func_0201B7B4(void *a0, int a1, u16 a2, u16 a3);
void func_0201B7EC(void *a0, int a1, u16 a2);
void func_0201B818(void *a0, int a1, u16 a2);
void sub_0201B850(void *mon, const s8 *tbl, int a2, u16 a3);
u8 sub_0201B920(void *mon, u32 slot);
u32 sub_0201B970(void *mon, u32 slot, u32 amount);
void sub_0201B9F0(void *mon);
void sub_0201BA34(void *party);
u32 sub_0201BA68(void *mon);
u32 sub_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
u32 sub_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
u32 sub_0201BBE8(void *mon);
int func_0201BC3C(void);
int func_0201BC40(void);
int func_0201BC78(void);
int func_0201BCB4(void);
int func_0201BCEC(void);
u32 sub_0201BD28(u16 id, u32 field);
u32 sub_0201BDB4(const struct Waza *p, u32 id);
u32 sub_0201BEB8(u16 id, u32 bit);
u32 sub_0201BF44(const struct Waza *p, u32 bit);
s16 sub_0201BF58(u16 id);
u8 sub_0201C020(u16 id);
u8 sub_0201C0BC(u16 id, u32 idx, s32 *out);
u8 sub_0201C158(u16 move, u32 ppUp);
u32 sub_0201C184(int id);
u32 sub_0201C1BC(u16 move);
u8 sub_0201C1C8(u16 p);
u16 sub_0201C1D8(u16 p);
int func_0201C1E8(int a);
u32 sub_0201C1F4(u16 id);
u32 sub_0201C284(u16 id);
u32 sub_0201C314(u16 p);
void sub_0201C328(s32 n, u32 heap);
void sub_0201C3C0(void);
u32 sub_0201C408(void);
void sub_0201C41C(void *arg);
u32 sub_0201C440(void *p);
void *sub_0201C450(u16 n, u32 heap);
void sub_0201C4C0(struct PrintSys_0201C450 *p);
void sub_0201C4C8(struct PrintSys_0201C450 *p, u32 v);
void sub_0201C4DC(struct PrintSys_0201C450 *p, u32 lo, u32 hi);
u32 func_0201C4E4(struct PrintSys_0201C4E4 *ps);
extern void *gMsgBank;
extern u16   gNameBuf[];
extern const s8 func_02019B04_Table[][5];
extern u32   gWordBuf[];
extern const u8 gBlockOrder[32][4];
extern struct Memo g_02146270;
extern u16 sub_0209E280_Map[];
extern const unsigned short d_0209E42C[];
extern u8 tbl_0209E444[];
extern const u8 g_0209E424[6];
extern const char sub_0201A920_File[];
extern const char sub_0201AB8C_File[];
extern void *g_0214652C;
extern const char sub_0201ADE4_File[];
extern u8 s_shinka_check_c[];
extern const u16 g_020A7320[1];
extern const u16 g_020A7322[1];
extern const u16 g_020A7324[3];
extern const u16 g_020A732A[3];
extern const s8 g_0209E45C[];
extern const s8 g_0209E465[];
extern const s8 g_0209E462[];
extern const u8 g_0209E474[];
extern struct WazaTool *gWazaTool;
extern struct Waza g_02146534;
extern const char sub_0201C328_File[];
extern void *g_02146558;
extern const char sub_0201C450_File[];






/*
 * The three primitives the whole save record in this region is protected
 * with.  func_02019A7C is one step of the linear congruential generator
 * `s = s * 0x41C64E6D + 0x6073` returning the middle halfword of the new
 * state, func_02019A50 XOR masks a byte range with that stream halfword by
 * halfword, and func_02019A9C is the plain halfword sum used as the checksum.
 *
 * func_02019A50 opens `push {r0, r1, r2, r3}` and closes `pop {r3}` /
 * `add sp, #0x10` / `bx r3`, which is what taking the address of a register
 * parameter costs on this front end; see
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md.  The
 * seed is passed by value and updated in place through that home slot, so a
 * caller's seed is never modified, which is what lets func_02018D34 mask the
 * same area twice with the same seed to undo itself.
 *
 * func_02019A7C carries no label in the generated listing.
 */
void func_02019A50(u16 *p, u32 size, u32 seed)
{
    u32 i = 0;
    u32 n = size >> 1;

    if (n != 0) {
        u32 *s = &seed;

        do {
            p[i] ^= func_02019A7C(s);
            i++;
        } while (i < n);
    }
}






u16 func_02019A7C(u32 *s)
{
    *s = *s * 0x41C64E6D + 0x6073;
    return (u16)(*s >> 16);
}






u16 func_02019A9C(const u16 *p, u32 size)
{
    u16 sum = 0;
    u32 i = 0;
    u32 n = size >> 1;

    if (n != 0) {
        do {
            sum = (u16)(sum + p[i]);
            i++;
        } while (i < n);
    }
    return sum;
}






/*
 * "Is the name in substruct C still the species' default name": it renders the
 * species name for substruct A's species id into the shared 0x20 halfword
 * buffer at 0x021462F0 and compares it with substruct C's own name, returning
 * 1 when they are equal.  func_02019388 (src/matched/sub_02019388.c) calls it
 * from ids 0x73 and 0x74 and stores the result in substruct B +0x10 bit 31,
 * which is the bit func_02018E34 reads back as id 0x75.  Those two calls are
 * the only references to this address in the image.
 *
 * The result local is declared before the two substruct fetches, which is what
 * puts `movs r5, #0` in front of the first call rather than after the second.
 *
 * The message bank at 0x020A7370 is a global pointer, so its address is a
 * build property and has to be re-derived for a White build rather than
 * copied; the 0x20 is a halfword count and the species id is data, so nothing
 * else here is version specific.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019ABC.c \
 *       --addr 0x02019ABC --thumb
 */
u32 func_02019ABC(struct Mon_02019A50 *p)
{
    u32 r = 0;
    struct BlockA *a = (struct BlockA *)func_02019C38((struct Mon_02019C38 *)p, p->unk00, 0);
    void *c = func_02019C38((struct Mon_02019C38 *)p, p->unk00, 2);

    func_02045F5C(gMsgBank, a->species, gNameBuf, 0x20);
    if (func_0201F448(gNameBuf, c) == 0) {
        r = 1;
    }
    return r;
}






/*
 * Scales b by a per (a, n) table entry of -1, 0 or 1; the multipliers are
 * 0x5A and 0x6E, which are 90 and 110 percent. Both arms are written out in
 * full and the compiler cross jumps their common muls/truncate/divide tail
 * into one block that the missing default branches past, which is
 * docs/idioms/switch-arms-tail-merge.md; hoisting the multiplication out of
 * the switch puts the default branch to that block instead of past it and
 * costs eight bytes.
 *
 * The table at 0x0209E324 is witnessed by the pool word of the neighbouring
 * leaf sub_02019B44.c (seeded via layout/function_starts.txt), and this
 * file's own pool word witnesses it for that one: the unit_02005DF8 /
 * unit_02005E30 pairwise treatment.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019B04.c \
 *       --addr 0x02019B04 --thumb
 */
u32 func_02019B04(u32 a, u32 b, u32 n)
{
    s8 v;

    if (n >= 6) {
        return b;
    }
    v = func_02019B04_Table[a][n - 1];
    switch (v) {
    case 1:
        b = (u16)((u16)(b * 0x6E) / 100);
        break;
    case -1:
        b = (u16)((u16)(b * 0x5A) / 100);
        break;
    }
    return b;
}






/*
 * The unlabelled leaf whose pool word is the second image-wide reference to
 * the table at 0x0209E324; traced via layout/function_starts.txt. Its pool
 * word witnesses the table for unit_02019B04.c and vice versa.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_02019B44.c \
 *       --func func_02019B44 --addr 0x02019B44
 */
s8 func_02019B44(u32 a, u32 n)
{
    return func_02019B04_Table[a][n - 1];
}






/*
 *           func_02019BBC
 *
 * The first five of the seven functions between func_02019ABC and the cache
 * helper at 0x02019C54.  The range stops at 0x02019C38 on purpose: the two
 * functions after it, func_02019C38 and func_02019C54, each reach a data
 * object through a pool word that is the object's only reference in the whole
 * image (0x0209E3A4 at 0x02019C50 and 0x02146274 at 0x02019C78), so the
 * `literal` class has no outside witness for either and both cap at MATCH
 * however they are written.  Cutting in front of them leaves these five
 * clean.
 *
 * func_02019B58 reaches func_020185F0, which src/matched/unit_020185F0.c
 * proves is an empty `bx lr`, and then calls func_02019B64 with whatever r0
 * holds, with no register saved across the first call.  That only compiles
 * from a declaration in which func_020185F0 returns a value, so this unit
 * declares it `void *func_020185F0(void)` and passes the result straight on;
 * declaring it `void` the way unit_020185F0.c does forces a callee-saved
 * register and a four byte longer prologue.  The two declarations disagree,
 * and the image cannot say which one the original header carried, because an
 * empty function's return value is unobservable.
 *
 * func_02019B94 is docs/idioms/tail-call-is-a-pool-word-and-bx.md: it permutes
 * three arguments into an ARM callee at 0x02048F4C and has no prologue at all.
 *
 * func_02019BBC is the plate-to-type table of ids 0xAE and 0xAF of
 * func_02018E34: sixteen consecutive item ids from 0x12A map to sixteen type
 * ids and everything else to 0.  The switch value arrives as a pool word
 * rather than a `subs` immediate only because 0x12A does not fit the eight bit
 * form, so it is an ordinary constant and not the linker symbol of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * VERSION SENSITIVITY: func_02019BBC's sixteen case labels are item ids and
 * its sixteen results are type ids, and func_02019B64 passes id 5 (species)
 * and id 0x74 (the name) of the record.  None of them is a version flag and
 * there is no exclusive-species table here, but the item ids 0x12A..0x139 are
 * content numbering and are the values to re-read first for a White build.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019B58.c \
 *       --addr 0x02019B58 --thumb
 */
void func_02019B58(void *p)
{
    func_02019B64(func_020185F0());
}






void func_02019B64(void *p)
{
    u32 s = func_02017E88(p, 5, 0);

    func_02045F5C(gMsgBank, s, gNameBuf, 0x20);
    func_02017E64(p, 0x74, (u32)gNameBuf);
}






void func_02019B94(u32 a, void *b)
{
    func_02048F4C(b, 0x11, a);
}






u32 func_02019BA4(u32 a, u32 i)
{
    func_02019B94(a, gWordBuf);
    return gWordBuf[i];
}






u32 func_02019BBC(u32 item)
{
    switch (item) {
    case 0x12A: return 9;
    case 0x12B: return 10;
    case 0x12C: return 12;
    case 0x12D: return 11;
    case 0x12E: return 14;
    case 0x12F: return 1;
    case 0x130: return 3;
    case 0x131: return 4;
    case 0x132: return 2;
    case 0x133: return 13;
    case 0x134: return 6;
    case 0x135: return 5;
    case 0x136: return 7;
    case 0x137: return 15;
    case 0x138: return 16;
    case 0x139: return 8;
    }
    return 0;
}







/*
 * note:     28 bytes including its pool word, one function
 * note:     re-verified 2026-09-21: EXACT.  The MATCH cap was lifted by the
 *           sole-ref widening of 2026-09-21, not by any edit to the C:
 *           the data address this file reaches now attests as
 *           sole-ref/data.  Promoted from src/pending/ unchanged.
 *
 * The substruct permuter the whole poke_tool.c field machinery reaches every
 * block through: bits 13 to 17 of the personality word select one of 32
 * orderings, and the ordering's n-th byte is the offset of the n-th 0x20 byte
 * substruct inside the 0x80 byte block area at +0x08, so the table at
 * 0x0209E3A4 is 32 rows of four offsets drawn from 0x00, 0x20, 0x40 and 0x60.
 * src/matched/sub_02019388.c, src/matched/unit_020188B4.c and
 * src/pending/sub_02018E34.c all index through it, and ov188 calls it eight
 * more times.
 *
 * Why it WAS capped (historical, resolved 2026-09-21): the one relocation is an ABS32 against the table at
 * 0x0209E3A4, and a scan of every word in all 242 regions finds exactly one
 * occurrence of that address, the pool word at 0x02019C50 inside this
 * function.  The `literal` class discards its only witness under the honesty
 * rule and no cut helps, because the range cannot be made smaller than the one
 * function that holds the pool word.  The `matched` class never applies to
 * data (docs/MATCHING.md, "The matched class"), so this is the same shape as
 * src/matched/sub_02013FA8.c's private table and not the same shape as
 * sub_02018E34's runtime helper.  It closes the day anything else in the image
 * names 0x0209E3A4, or the day the table itself is a matched data entry.
 *
 * The neighbour func_02019C54, which is the one-entry memo in front of this
 * function, has no such site and was cut off into
 * src/matched/unit_02019C54.c rather than left capped with it
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md is the same
 * remedy applied to a data reference).
 *
 * What pinned the source: the mask is written `(pid & 0x3E000) >> 13` and not
 * `(pid >> 13) & 0x1F`.  The first is the `movs #0x3E` / `lsls #0xC` / `ands`
 * / `lsrs #0xD` the original has; the second folds to a `lsrs` and an `ands`
 * against a pooled 0x1F.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/sub_02019C38.c \
 *       --addr 0x02019C38 --thumb
 */
void *func_02019C38(struct Mon_02019C38 *p, u32 pid, u32 n)
{
    return &p->block[gBlockOrder[(pid & 0x3E000) >> 13][n]];
}






/*
 * A one-entry memo: the (a, b) key pair at 0x02146270 and the 0x10 byte
 * object built for it at 0x02146274, rebuilt through sub_0201ADA4
 * (src/matched/unit_0201ADA4.c) only when the key changes.  func_02019C90 in
 * src/matched/unit_02019C7C.c is its only caller.
 *
 * Two things pin the source.
 *
 * The guard is one `||` expression rather than two ifs, which is what puts
 * both stores and the call in one block, per
 * docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md; and the
 * arm that falls through the first `bne` is the second half of the
 * disjunction, not the body.
 *
 * The two pool words 0x02146270 and 0x02146274 are one symbol and an addend,
 * per docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 * Declared as two symbols, 0x02146274 would need a witness of its own and the
 * only word in the image that holds it is the one under test.
 *
 * The neighbour func_02019C38 at the head of this packet is byte-correct but
 * MATCH-capped on its private table and is parked in
 * src/pending/sub_02019C38.c; this range is cut to exclude it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02019C54.c \
 *       --addr 0x02019C54 --thumb
 */
void *func_02019C54(u32 a, u32 b)
{
    if (a != g_02146270.a || b != g_02146270.b) {
        g_02146270.b = (u16)b;
        g_02146270.a = (u16)a;
        sub_0201ADA4(a, b, g_02146270.obj);
    }
    return g_02146270.obj;
}






/*
 * func_02019CE0 carries no label in the generated listing: it saves r3 and r4
 * but not lr, so disasm.py's prologue sweep never fires on it and its 24 bytes
 * arrive as a run of .word between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  It is one
 * struct assignment: 27 ldm/stm pairs of eight bytes plus a trailing word is
 * 0xDC bytes, and the eight byte step is what says the record is at least four
 * aligned, which is docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * The range stops at 0x02019CF8, which is an eight byte tail call whose pool
 * word names 0x02019BBC.  That address carries no func_ label and no other
 * pool word in the image holds it, so neither the label nor the literal class
 * can attest it and the stub cannot be matched from either side.
 */
u32 func_02019C7C(void *h)
{
    if (func_0201AE1C(h, 0x1B) != 0) {
        return 2;
    }
    return 1;
}






u32 func_02019C90(u16 a, u16 b, u32 k)
{
    return func_0201AE1C(func_02019C54(a, b), k);
}






void func_02019CA0(void *p, u32 v)
{
    u32 a = func_02017E1C(p, 5, 0);
    u32 b = func_02017E1C(p, 0x6F, 0);

    func_02017E40(p, 8, func_02018584((u16)a, (u16)b, (u16)v));
    func_020185C4(p);
}






void func_02019CE0(const struct RecDC *src, struct RecDC *dest)
{
    *dest = *src;
}








/*
 * Plain forwarder to func_02019BBC (ldr r3, =target; bx r3).  Callee of
 * ov170 func_021DD718.
 */
unsigned int func_02019CF8(unsigned int item)
{
    return func_02019BBC(item);
}








/*
 * Neither carries a label in the generated listing.  func_02019D00
 * is a dense switch over 0x74..0x77 whose four arms each return a constant,
 * and the `subs r0, #0x74` in front of the `cmp`/`bhi` is the compiler's
 * normalisation of the range rather than anything the source wrote; see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *
 * The range stops at 0x02019D58.  The two unlabelled search loops after it,
 * at 0x02019D58 and 0x02019D84, reproduce every concrete byte but read
 * halfword tables at 0x0209E280 and 0x0209E42C, and each of those addresses
 * appears in exactly one literal pool in the whole image, the one under test,
 * so the literal class discards its only witness and no cut helps.
 */
u32 func_02019D00(u32 id)
{
    switch (id) {
    case 0x74:
        return 1;
    case 0x75:
        return 2;
    case 0x76:
        return 3;
    case 0x77:
        return 4;
    }
    return 0;
}








u32 func_02019D30(u16 a, u16 n)
{
    if (a != 0x28A) {
        if ((s32)n >= (s32)func_02019C90(a, n, 0x20)) {
            n = 0;
        }
        return n;
    }
    if (n >= 2) {
        n = 0;
    }
    return n;
}







/*
 * note:     re-verified 2026-09-21: EXACT*.  The MATCH cap was lifted by the
 *           sole-ref widening of 2026-09-21, not by any edit to the C:
 *           the data address this file reaches now attests as
 *           sole-ref/data.  Promoted from src/pending/ unchanged.
 */
int func_02019D58(u16 a, int b)
{
    u16 i;

    if (b != 0) {
        for (i = 0; i < 4; i++)
            if (sub_0209E280_Map[i] == a)
                return 0;
    }
    return b;
}






/*
 * Witness leaf for ov119 func_021DD0CC: membership test in a 12 entry u16 table.
 */
int func_02019D84(unsigned short value)
{
    unsigned i;
    for (i = 0; i < 12; i++) {
        if (value == d_0209E42C[i])
            return 1;
    }
    return 0;
}








/*
 * A stat comparison against a threshold picked by selector 4 of the first
 * argument: selector 5 (one over the limit) and 6 (under it) are both
 * rejected with 2, and the tail reports 0x20 for the presence flag, 4 or
 * 0x40 for the two range checks, and 1 when there is no object at all.  The
 * two comparisons are signed, which is what `ble`/`bge` says.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02019DA4.c \
 *       --func func_02019DA4 --addr 0x02019DA4 --cc 1.1p1 --thumb
 */
int func_02019DA4(void *a0, void *a1)
{
    u16 v5 = (u16)func_02017E1C(a1, 5, 0);
    u16 v6 = (u16)func_02017E1C(a1, 6, 0);
    int m;
    int s;
    int t;
    int r;

    if (a0 == 0)
        return 1;

    m = func_0200AE54(a0, 4);
    s = func_0200AE54(a0, 5);
    t = func_02017E1C(a1, 0x9E, 0);

    switch (s) {
    case 1:
        if (m > t)
            return 2;
        break;
    case 2:
        if (m < t)
            return 2;
        break;
    }

    r = 0;
    if (func_02017E1C(a1, 0x4C, 0) != 0)
        return 0x20;
    if (func_0200AFD4(a0, 9, v5) != 0)
        return 4;
    if (func_0200AFD4(a0, 0xA, v6) != 0)
        r = 0x40;
    return r;
}









/*
 * Maps a flag word to a small code: the four bits 2, 4, 0x20 and 0x40 all
 * answer 5 (one disjunction, so they share a single exit), then 8, 0x10,
 * 0x100, 0x80 and 1 each answer their own code and zero answers 0.  The
 * query is answered through two stack words whose addresses are passed to
 * func_0201A5FC, and the caller's second and third registers are forwarded
 * unchanged, so the query takes five arguments.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02019E54.c \
 *       --func func_02019E54 --addr 0x02019E54 --cc 1.1p1 --thumb
 */
int func_02019E54(u32 a0, u32 a1, u32 a2)
{
    u64 q;
    u32 r;

    if (a0 == 0)
        return 0;

    func_0201A5FC((void *)a0, (void *)a1, (u8 *)a2, (char *)(&q), &r);
    if (r == 0)
        return 0;

    if ((r & 2) || (r & 4) || (r & 0x20) || (r & 0x40))
        return 5;
    if (r & 8)
        return 2;
    if (r & 0x10)
        return 3;
    if (r & 0x100)
        return 1;
    if (r & 0x80)
        return 7;
    if (r & 1)
        return 4;
    return 0;
}









/*
 * EXACT*: the inferred extent runs 2 bytes past the 250-byte body because the
 * follower at 0x02019FD0 has no lr-saving prologue and so carries no label.
 * No byte differs.
 *
 * The party "is this team legal for the rule set" check.  It reads each
 * member's species (id 5) and form (id 0x9E) into two parallel u16[6] stack
 * arrays, zeroes the species of any member func_02019DA4 rejects, then runs an
 * O(n^2) duplicate-species scan that zeroes the worse of each colliding pair
 * (worse = the larger form value) and decrements a running count.  If the
 * surviving count is below what func_0200AE54(ctx, 2) requires it answers 4;
 * otherwise the answer is 0 or 1 from func_0201A59C.
 *
 * Two layout tells pin the frame:
 *   - the 12-byte MI_CpuFill8 buffer is declared LAST, not first: the later
 *     declarator gets the lower stack address, which is what puts `pad` at
 *     sp+0x10 and `species` at sp+0x28
 *     (docs/idioms/local-declaration-order-is-stack-order.md).
 *   - the outer scan loop assigns its counter before its bound (`i = 0;`
 *     then `lim = n - 1;`), or the `movs r0,#0` and the `subs r0,r0,#1`
 *     swap places
 *     (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 *
 * VERSION SENSITIVITY: party ids 5 and 0x9E and the rule-set keys 7 and 2 are
 * content numbering; the team size 6 is the array bound and is structural.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_02019ED4.c \
 *       --func sub_02019ED4 --addr 0x02019ED4 --cc 1.1p1 --thumb
 */
int sub_02019ED4(void *ctx, void *q)
{
    u16 species[6];
    u16 form[6];
    u8 pad[12];
    int n;
    int cnt;
    int i;
    int j;
    int lim;
    int r;

    n = func_0201AA18(q);
    cnt = n;
    MI_CpuFill8(pad, 0, 12);
    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(q, i);

        species[i] = (u16)func_02017E1C(mon, 5, 0);
        form[i] = (u16)func_02017E1C(mon, 0x9E, 0);
        if (func_02019DA4(ctx, mon) != 0) {
            species[i] = 0;
            cnt--;
        }
    }

    if ((int)func_0200AE54(ctx, 7) == 0 && n > 1) {
        i = 0;
        lim = n - 1;
        for (; i < lim; i++) {
            for (j = i + 1; j < n; j++) {
                if (species[i] == species[j] && species[i] != 0) {
                    if (form[i] > form[j]) {
                        species[i] = 0;
                    } else {
                        species[j] = 0;
                    }
                    cnt--;
                }
            }
        }
    }

    if (cnt < (int)func_0200AE54(ctx, 2)) {
        return 4;
    }

    r = 0;
    if (func_0201A59C(ctx, q, 0) != 1) {
        r = 1;
    }
    return r;
}









/*
 * EXACT* note: the 190 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A08E before the next labelled function at 0x0201A090.
 *
 * The same stat comparison as func_02019DA4, but it reports into the third
 * argument's word with or-bits instead of returning a code: bit 1 for a
 * selector 5 record above the threshold or a selector 6 one below it, bit 2
 * for the range check, bit 6 for the second one, and the return value stays 1
 * unless a bit was set.  The `*a2 |= 2; r = 0;` pair is written out in both
 * arms and the compiler cross-jumps them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02019FD0.c \
 *       --func func_02019FD0 --addr 0x02019FD0 --cc 1.1p1 --thumb
 */
int func_02019FD0(void *a0, void *a1, u32 *a2)
{
    u16 v5 = (u16)func_02017E1C(a1, 5, 0);
    u16 v6 = (u16)func_02017E1C(a1, 6, 0);
    int r = 1;
    int m;
    int s;
    int t;

    if (a0 == 0)
        return r;

    m = func_0200AE54(a0, 4);
    s = func_0200AE54(a0, 5);
    t = func_02017E1C(a1, 0x9E, 0);

    switch (s) {
    case 1:
        if (m > t) {
            r = 0;
            *a2 |= 2;
        }
        break;
    case 2:
        if (m < t) {
            r = 0;
            *a2 |= 2;
        }
        break;
    }

    if (func_0200AFD4(a0, 9, v5) != 0) {
        if (func_02017E1C(a1, 0x4C, 0) == 0) {
            r = 0;
            *a2 |= 4;
        }
    }
    if (func_0200AFD4(a0, 0xA, v6) != 0) {
        r = 0;
        *a2 |= 0x40;
    }
    return r;
}








/*
 * poke_tool.c (wave 13): the party legality check against a rule set.
 * Three parallel six-entry u16 arrays (species, item, form) are collected
 * from the non-egg members; the rule set's queries 2 (minimum count),
 * 7 (duplicate species allowed), 8 (duplicate items allowed) and 0xB/0xC (a
 * required species/form) set bits 0x01/0x08/0x10/0x80 of *mask and the
 * error codes 4/2/3/7, a failing member check gives 5, and when nothing
 * failed func_0201A59C decides between 0 and 1.
 *
 * WHAT CLOSED IT (docs/notes/func_0201A090.c.txt: 478 against 476, err
 * spilled to sp+8 with a six-register push): the arrays are indexed plainly,
 * `species[i]` -- the note's invented `j = i * 2; species[j >> 1]` was the
 * source of the `lsls/bics` fixups; the compiler itself CSEs `i * 2` into
 * the sp+8 slot.  Then the permuter (hill, one mutation) found the last
 * lever: in the duplicate-item test the mask update comes BEFORE the error
 * code (`*mask |= 0x10; err = 3;`), the opposite of the species test.  That
 * order is what keeps err in r7 for the whole function.
 *
 * EXACT* only because of the two-byte alignment pad at 0x0201A26A; the
 * follower 0x0201A26C is its own labelled EXACT entry.
 */
int func_0201A090(void *rules, void *party, u32 *mask)
{
    u16 species[6];
    u16 item[6];
    u16 form[6];
    int i;
    int total;
    int n;
    int err;
    void *mon;
    int k;
    int want_s, want_f;

    n = 0;
    err = 0;
    if (rules == 0)
        return 0;
    for (i = 0; i < 6; i++) {
        species[i] = 0;
        form[i] = 0;
        item[i] = 0;
    }
    total = func_0201AA50(party);
    if (total < (int)func_0200AE54(rules, 2)) {
        *mask |= 1;
        err = 4;
    }
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, i);
        if (func_02019FD0(rules, mon, mask) == 0)
            err = 5;
        if (func_02017E1C(mon, 0x4c, 0) == 0) {
            species[i] = func_02017E1C(mon, 5, 0);
            item[i] = func_02017E1C(mon, 6, 0);
            form[i] = func_02017E1C(mon, 0x6f, 0);
            n += func_02017E1C(mon, 0x9e, 0);
        }
    }
    if ((int)func_0200AE54(rules, 7) == 0 && total > 1) {
        for (i = 0; i < 5; i++) {
            for (k = i + 1; k < 6; k++) {
                if (species[i] == species[k] && species[i] != 0) {
                    err = 2;
                    *mask |= 8;
                }
            }
        }
    }
    if ((int)func_0200AE54(rules, 8) == 0 && total > 1) {
        for (i = 0; i < 5; i++) {
            for (k = i + 1; k < 6; k++) {
                if (item[i] == item[k] && species[i] != 0 && item[i] != 0) {
                    *mask |= 0x10;
                    err = 3;
                }
            }
        }
    }
    want_s = (int)func_0200AE54(rules, 0xb);
    want_f = (int)func_0200AE54(rules, 0xc);
    i = 0;
    if (want_s != 0 && total > 1) {
        for (i = 0; i < 6; i++) {
            if (want_s == species[i] && want_f == form[i])
                break;
        }
    }
    if (i == 6) {
        *mask |= 0x80;
        err = 7;
    }
    if (err == 0 && func_0201A59C(rules, party, 0) == 0)
        err = 1;
    return err;
}








/*
 * Picks the smaller (or larger, per selector 5) of a value read from the
 * object and the caller's second argument, with the selector 3 / 4 / 5 arms
 * emitted as a compare chain and the default falling through to the caller's
 * value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A26C.c \
 *       --func func_0201A26C --addr 0x0201A26C --cc 1.1p1 --thumb
 */
u32 func_0201A26C(void *a0, u32 a1)
{
    u32 v = func_0200AE54(a0, 4);
    u32 w = func_0200AE54(a0, 5);

    switch (w) {
    case 3:
        if (a1 > v)
            return v;
        break;
    case 4:
        return v;
    case 5:
        if (a1 < v)
            return v;
        break;
    }
    return a1;
}








/*
 * EXACT* note: the 98 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A30A before the next labelled function at 0x0201A30C.
 *
 * Sweeps the records of the second argument and rewrites those whose 0xA9
 * flag is set and whose recomputed value disagrees with what the first
 * argument's own query returns.  The value from before the loop is a spilled
 * local, so it is re-read from the frame at the one place it is used.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A2A8.c \
 *       --func func_0201A2A8 --addr 0x0201A2A8 --cc 1.1p1 --thumb
 */
void func_0201A2A8(void *a0, void *a1)
{
    u32 v = func_0200AE54(a0, 4);
    int i;

    for (i = 0; i < (int)func_0201AA18(a1); i++) {
        void *e = func_0201AB28(a1, i);

        if (func_02017E1C(e, 0xA9, 0) != 0) {
            u32 w = func_02017E1C(e, 0x9E, 0);

            if (func_0201A26C(a0, w) != w)
                func_02019CA0(e, v);
        }
    }
}








/*
 * EXACT* note: the 70 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A352, then two unlabelled 12-byte argument-shuffling tail-call thunks at 0x0201A354 (calls 0x02048F60 with (0x69, a, b)) and 0x0201A364 (calls 0x02048F4C with (b, 0x69, a)), each followed by its own pool word, before the next labelled function at 0x0201A374.
 *
 * Guarded sweep over a record array: only when the object reports state zero
 * does it walk the records and act on those whose 0xA9 flag is set.  The
 * bound is re-evaluated at the bottom of the loop, so it stays a call in the
 * condition.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A30C.c \
 *       --func func_0201A30C --addr 0x0201A30C --cc 1.1p1 --thumb
 */
void func_0201A30C(void *a0, void *a1, u32 c)
{
    int i;

    if (func_0200AE54(a0, 0x11) != 0)
        return;

    for (i = 0; i < (int)func_0201AA18(a1); i++) {
        void *e = func_0201AB28(a1, i);

        if (func_02017E1C(e, 0xA9, 0) != 0)
            func_02019B58(e);
    }
}








/*
 * Witness leaf for ov021 func_021B574C and func_021B57CC.
 */
void *func_0201A354(int a, int b)
{
    return func_02048F60(0x69, a, b);
}








/*
 * Unlabelled Thumb argument-shuffling tail-call thunk: func_02048F4C(b, 0x69, a).
 */
void func_0201A364(int a, unsigned int b)
{
    func_02048F4C((void *)b, 0x69, a);
}







/*
 * Load one 0x40-byte sprite record whose mode word is chosen from the pair of
 * bytes at a0+2/+3: (1,6) selects 6, equal bytes select 7, a byte above 1
 * with 6 following selects 8 and anything else 9.  Both palette fields are
 * stamped through func_0201EFA4, the record is allocated against a4, its
 * slots are filled from *a2 through func_02045CAC and the pair is bound by
 * func_0201F250.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A374.c \
 *       --func func_0201A374 --addr 0x0201A374 --cc 1.1p1 --thumb
 */
void *func_0201A374(u8 *a0, u32 a1, u32 *a2, u32 a3, u16 a4)
{
    u32 mode;
    void *p;

    if (a0[2] == 1 && a0[3] == 6) {
        mode = 6;
    } else if (a0[2] == a0[3]) {
        mode = 7;
    } else if (a0[2] > 1 && a0[3] == 6) {
        mode = 8;
    } else {
        mode = 9;
    }
    func_0201EFA4((struct WordSet *)a1, 0, a0[2], 1, 0, 1);
    func_0201EFA4((struct WordSet *)a1, 1, a0[3], 1, 0, 1);
    p = func_020457B0(0x40, a4);
    func_02045CAC((struct MsgBank *)(*a2), mode, (void *)a3);
    func_0201F250((struct WordSet *)a1, p, (void *)a3);
    return p;
}







/*
 * poke_tool.c tail (wave 13), the twin of func_0201A374: pick the sprite
 * record's mode from the format byte at a0+5 (0 -> 6, 4 -> 0xb, 1 -> 0xd,
 * 2 -> 0xc, 3 -> 0xe, 5 -> 0xf, anything else 6; an if chain in that order,
 * the image tests it in source order), stamp the byte at a0+4 through
 * func_0201EFA4, allocate the 0x40-byte record against a4, fill it from *a2
 * and bind it with func_0201F250.
 *
 * WHAT CLOSED IT (docs/notes/pkt_0201A3F4.c.txt: 8 bytes out, the byte at
 * a0+4 loaded after the two outgoing stack stores instead of before): the
 * record parameter is `const u8 *`.  A load through a const pointer may move
 * above the stores to the outgoing-argument area; through a plain pointer it
 * may not.  Same lever as func_02050C30 and func_02051838 this wave.
 *
 * EXACT* because the follower at 0x0201A468 (a leaf that scans 0x52 bytes
 * from +0xa and tail-calls 0x02045EC0) carries no label.
 */
void *func_0201A3F4(const u8 *a0, u32 a1, u32 *a2, u32 a3, u16 a4)
{
    u32 mode;
    void *p;

    if (a0[5] == 0) {
        mode = 6;
    } else if (a0[5] == 4) {
        mode = 0xb;
    } else if (a0[5] == 1) {
        mode = 0xd;
    } else if (a0[5] == 2) {
        mode = 0xc;
    } else if (a0[5] == 3) {
        mode = 0xe;
    } else if (a0[5] == 5) {
        mode = 0xf;
    } else {
        mode = 6;
    }
    func_0201EFA4((struct WordSet *)a1, 0, a0[4], 3, 0, 1);
    p = func_020457B0(0x40, a4);
    func_02045CAC((struct MsgBank *)(*a2), mode, (void *)a3);
    func_0201F250((struct WordSet *)a1, p, (void *)a3);
    return p;
}



void *func_0201A468(u8 *a0, int a1, struct Ctx *c)
{
    int i;
    u32 k;

    for (i = 0; i < 0x52; i++) {
        if (a0[i + 0xA] != 0)
            break;
    }
    k = 0x10;
    if (i != 0x52)
        k = 0x11;
    return func_02045EC0(c->bank, k);
}



void *func_0201A48C(u8 *a0, int a1, struct Ctx *c)
{
    u32 k = 0x12;

    if (a0[8] != 1)
        k = 0x13;
    return func_02045EC0(c->bank, k);
}



void *func_0201A4A0(u8 *a0, int a1, struct Ctx *c)
{
    u32 k = 0x14;

    if (a0[9] != 1)
        k = 0x15;
    return func_02045EC0(c->bank, k);
}



void *func_0201A4B4(u8 *a0, int a1, struct Ctx *c)
{
    u32 k;
    u8 v = c->f34;

    if (v == 1) {
        k = 0x16;
    } else {
        k = 0x17;
        if (v != 0)
            k = 0x16;
    }
    return func_02045EC0(c->bank, k);
}







/*
 * Wave 17 lane untried_small. What closed it (from 6 halfwords out): the heap
 * id parameter a2 is u16. The image homes it to the stack and reloads it for
 * every use (the allocator's first argument included); declared u32 it stays
 * in r2 and is copied, which was the whole parameter-homing residue.
 */
u8 *func_0201A4D4(u8 *a0, u32 a1, u16 a2, u32 a3)
{
    u8 *v7;
    u32 v10;
    int i;
    u32 f;

    v7 = (u8 *)func_02030734(a2, 0x38, 1, (const char *)0x020A72F0, 0x312);
    ((struct Obj06868 *)v7)->f0 = (u32)func_02045B38(0, 2, 0xa5, a2);
    v10 = (u32)func_020457B0(0x40, a2);
    f = ((struct Obj15718 *)a0)->fAB;
    if (f == 2)
        ((struct Obj06868 *)v7)->f34 = a3;
    else
        ((struct Obj06868 *)v7)->f34 = f;
    for (i = 0; i < 6; i++) {
        int off = i * 4;
        u8 *q = v7 + off;

        ((struct Obj11261 *)q)->f4 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06868 *)v7)->f0), i);
        ((struct Obj11261 *)q)->f1C =
            ((u32 (*)(u8 *, u32, u8 *, u32, u32))
                 (*(u32 *)(tbl_0209E444 + off)))(a0, a1, v7, v10, a2);
    }
    func_02045808((struct U16Vec *)v10);
    return v7;
}







/*
 * EXACT* note: the 42 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A59A before the next labelled function at 0x0201A59C.
 *
 * Six records of 0x20 bytes, each with a pair of ARM calls at +4 and +0x1C,
 * then the object's first word through the ARM at 0x02045C04 and the object
 * itself through 0x020307B0.  The loop index is a signed int, so the bound
 * test is `blt` and no truncation appears.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A570.c \
 *       --func func_0201A570 --addr 0x0201A570 --cc 1.1p1 --thumb
 */
void func_0201A570(void *a0)
{
    int i;

    for (i = 0; i < 6; i++) {
        func_02045808((struct U16Vec *)(*(u32 *)((char *)a0 + i * 4 + 4)));
        func_02045808((struct U16Vec *)(*(u32 *)((char *)a0 + i * 4 + 0x1C)));
    }
    func_02045C04((struct Rec_0201A4D4 *)(((struct Obj15719 *)a0)->f0));
    func_020307B0(a0);
}







/*
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201A59C.c \
 *       --func func_0201A59C --addr 0x0201A59C --cc 1.1p1 --thumb
 */
int func_0201A59C(void *a0, void *a1, void *a2)
{
    char buf[6];

    buf[0] = g_0209E424[0];
    buf[1] = g_0209E424[1];
    buf[2] = g_0209E424[2];
    buf[3] = g_0209E424[3];
    buf[4] = g_0209E424[4];
    buf[5] = g_0209E424[5];

    if (func_0201A858((u8 *)buf) != 0) {
        do {
            if (func_0201A5FC(a0, a1, (u8 *)buf, a2, 0) == 1) {
                return 1;
            }
        } while (func_0201A858((u8 *)buf) != 0);
    }

    return 0;
}







/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A5FC.c  *       --func func_0201A5FC --addr 0x0201A5FC --cc 1.1p1 --thumb
 */
int func_0201A5FC(void *a0, void *a1, u8 *a2, char *a3, u32 *a4)
{
    u8 count = 0;
    u32 arr5c[6] = {0};
    u32 arr44[6] = {0};
    u32 arr2c[6] = {0};
    u8 i;
    int flag;
    u32 acc;
    void *p;
    u32 v18;
    u32 v14;
    u32 v10;
    u8 n;
    u8 j;
    u32 v6;
    u32 k1;
    u8 k;
    u32 k2;
    u32 r;
    int found;

    acc = 0;
    v10 = (u32)(int)func_0200AE54(a0, (int)6);

    if (a3 != 0)
        *a3 = 0;
    if (a4 != 0)
        *a4 = 0;

    for (i = 0; i < 6; i++) {
        if (a2[i] == 0)
            continue;
        n = (u8)(a2[i] - 1);
        if ((int)n >= (int)func_0201AA18(a1))
            continue;
        p = func_0201AB28(a1, n);
        v18 = func_02017E1C(p, 5, 0);
        v6 = func_02017E1C(p, 6, 0);
        v14 = (u32)func_0201A26C(a0, func_02017E1C(p, 0x9e, 0));
        r = func_02019DA4(a0, p);
        if (r != 0) {
            if (a4 != 0)
                *a4 |= r;
            continue;
        }
        flag = 1;
        for (j = 0; j < count; j++) {
            if ((int)func_0200AE54(a0, (int)7) == 0 && v18 == arr5c[j]) {
                flag = 0;
                if (a4 != 0)
                    *a4 |= 8;
                break;
            }
            if ((int)func_0200AE54(a0, (int)8) == 0 && v6 != 0 && v6 == arr2c[j]) {
                flag = 0;
                if (a4 != 0)
                    *a4 |= 0x10;
                break;
            }
        }
        if (flag == 0)
            continue;
        if (v10 != 0 && (u32)(acc + v14) > v10) {
            if (a4 != 0)
                *a4 |= 0x100;
            continue;
        }
        if (a3 != 0)
            a3[count] = (char)(n + 1);
        arr5c[count] = v18;
        arr44[count] = func_02017E1C(p, 0x6f, 0);
        arr2c[count] = v6;
        acc = (u16)(acc + (u16)v14);
        count = (u8)(count + 1);
        if ((int)count < (int)func_0200AE54(a0, (int)3))
            continue;
        if (a4 != 0 && count < 6 && a2[count] != 0)
            *a4 |= 1;
        break;
    }

    if ((int)count >= (int)func_0200AE54(a0, (int)2)) {
        k1 = (u32)(int)func_0200AE54(a0, (int)0xb);
        found = 1;
        if (k1 != 0) {
            k2 = (u32)(int)func_0200AE54(a0, (int)0xc);
            found = 0;
            for (k = 0; k < count; k++) {
                if (k1 == arr5c[k] && k2 == arr44[k]) {
                    found = 1;
                    break;
                }
            }
        }
        if (found == 1)
            return 1;
        if (a4 != 0)
            *a4 |= 0x80;
    } else {
        if (a4 != 0)
            *a4 |= 1;
    }
    return 0;
}







/*
 * A base-7 odometer with a distinctness test: six nested counters (a[0]
 * outermost) over 0..6, and the innermost body returns 1 as soon as all six
 * values differ.  The entry `a[5]++` is the source's own first statement, not
 * a loop increment.
 *
 * The fifteen `!=` tests are one conjunction: every `cmp` in the listing
 * branches to the same increment block (0x0201A8B8) on equality, which is the
 * "guard chain sharing one exit block" spelling, not a chain of ifs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A858.c \
 *       --func func_0201A858 --addr 0x0201A858 --cc 1.1p1 --thumb
 */
int func_0201A858(u8 *a)
{
    a[5]++;
    while (a[0] <= 6) {
        while (a[1] <= 6) {
            while (a[2] <= 6) {
                while (a[3] <= 6) {
                    while (a[4] <= 6) {
                        while (a[5] <= 6) {
                            if (a[0] != a[1] && a[0] != a[2] &&
                                a[0] != a[3] && a[0] != a[4] &&
                                a[0] != a[5] && a[1] != a[2] &&
                                a[1] != a[3] && a[1] != a[4] &&
                                a[1] != a[5] && a[2] != a[3] &&
                                a[2] != a[4] && a[2] != a[5] &&
                                a[3] != a[4] && a[3] != a[5] &&
                                a[4] != a[5]) {
                                return 1;
                            }
                            a[5]++;
                        }
                        a[5] = 1;
                        a[4]++;
                    }
                    a[4] = 1;
                    a[3]++;
                }
                a[3] = 1;
                a[2]++;
            }
            a[2] = 1;
            a[1]++;
        }
        a[1] = 1;
        a[0]++;
    }
    return 0;
}






/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
int func_0201A918(void)
{
    return 0x534;
}







/*
 *           sub_0201A9C8
 *
 * pokeparty.c: the container's constructor, its initialiser, and the add and
 * remove operations.  The allocation at 0x0201A930 names the file itself, the
 * string at 0x020A7304 being "pokeparty.c"; the line numbers 65 (here) and
 * 382 (src/matched/unit_0201AB48.c) put these two ranges in one original
 * source file with about three hundred lines between them.
 *
 * The container is 0x534 bytes: a capacity at +0x00, a live count at +0x04,
 * six 0xDC byte records from +0x08, and one byte at +0x530.  Two independent
 * things say the last byte is a member rather than padding: the initialiser
 * stores zero into it, and it reaches it with `subs r0, r7, #4` off the
 * pooled 0x534, then a register-offset `strb`, because 0x530 is far past the
 * byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  Writing
 * `sizeof(struct Party)` for the clear and the allocation is what puts that
 * one constant in the pool for both uses.
 *
 * sub_0201A948 is the six-slot spelling of sub_0201A954 and is a bare tail
 * call, three instructions and a pool word
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * sub_0201A98C's guard is an early return on the full container: the
 * conditional branch is taken into the body, so the fall-through arm is the
 * failure the source wrote first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0201A9C8 compacts the array by copying each record down one slot, and
 * its loop bound re-reads `p->count` on every iteration rather than caching
 * it, which is visible as the `ldr`/`subs #1` pair inside the loop.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201A920.c \
 *       --addr 0x0201A920 --thumb
 */
struct Party_0201A4D4 *sub_0201A920(u32 heap)
{
    struct Party_0201A4D4 *p = (struct Party_0201A4D4 *)func_02030734(heap, sizeof(struct Party_0201A4D4), 0,
                                                   sub_0201A920_File, 65);

    sub_0201A948(p);
    return p;
}







void sub_0201A948(struct Party_0201A4D4 *p)
{
    sub_0201A954(p, 6);
}



void sub_0201A954(struct Party_0201A4D4 *p, s32 capacity)
{
    s32 i;

    MIi_CpuClearFast(0, p, sizeof(struct Party_0201A4D4));
    p->capacity = capacity;
    p->count = 0;
    p->unk530 = 0;
    for (i = 0; i < 6; i++) {
        func_02017528((struct Sav *)(&p->mon[i]));
    }
}



u32 sub_0201A98C(struct Party_0201A4D4 *p, const struct PartyMon *src)
{
    if (p->count >= p->capacity) {
        return 0;
    }
    p->mon[p->count] = *src;
    sub_0201ACDC(p, p->count, 1);
    p->count = p->count + 1;
    return 1;
}



u32 sub_0201A9C8(struct Party_0201A4D4 *p, s32 idx)
{
    s32 i;

    for (i = idx; i < p->count - 1; i++) {
        p->mon[i] = p->mon[i + 1];
    }
    func_02017528((struct Sav *)(&p->mon[i]));
    p->count = p->count - 1;
    return 1;
}




/*
 * A whole translation unit, matched as one byte range.
 *
 * Two plain word getters, four bytes each: the object's first word and the
 * word at +4.  Both are called from sub_0201AA1C (0x0201AA1C, still open)
 * and sub_0201AA18 is also called from the unit at 0x0201AC2C, which is
 * where the concrete relocations against it are attested from.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA14.c \
 *       --addr 0x0201AA14 --thumb
 */
u32 sub_0201AA14(void *p)
{
    return ((struct Obj17207 *)p)->f0;
}




u32 sub_0201AA18(void *p)
{
    return ((struct Obj17208 *)p)->f4;
}




/*
 *           sub_0201AB08, sub_0201AB18
 *
 * Four counters over the 0xDC-byte-record array container of
 * src/matched/unit_0201AB28.c and src/matched/unit_0201AC2C.c, plus the two
 * predicate-passing wrappers in front of the search routine sub_0201AD58.
 * Each counter walks 0 to sub_0201AA18(p) and tests one or two fields of the
 * entry through the getter func_02017E1C.
 *
 * The two sixteen-byte functions at 0x0201AB08 and 0x0201AB18 are not linker
 * veneers, which is what their shape suggests at first: they are ordinary
 * Thumb tail calls (docs/idioms/tail-call-is-a-pool-word-and-bx.md) whose
 * second argument is the address of a function, so each carries two pool
 * words, one for the predicate and one for the callee.  Neither carries a
 * label in the generated listing, so they arrive there as a run of `.word`s
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the second
 * one is this unit's unlabelled follower.
 *
 * Three of the four counters declare the loop index before the running
 * count, which is the only thing that puts the index in r4 and the count in
 * r5 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 * the initialising assignments stay in the original's order, count first,
 * and are unaffected.  sub_0201AA50 is the exception and wants the other
 * order, because there the element count lives in r7 rather than on the
 * stack.
 *
 * sub_0201AA50 really does call sub_0201AB28 twice with the same arguments
 * and drops the first result.  A call is never dead-code eliminated by this
 * front end, so the discarded one is in the source; it is not a scheduling
 * artefact of the surviving call.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA1C.c \
 *       --addr 0x0201AA1C --thumb
 */
u32 sub_0201AA1C(void *p)
{
    s32 i;
    u32 n = 0;
    s32 count;

    count = sub_0201AA18(p);
    for (i = 0; i < count; i++) {
        void *entry = sub_0201AB28(p, i);

        if (func_02017E1C(entry, 0x4C, 0) != 1) {
            n++;
        }
    }
    return n;
}




u32 sub_0201AA50(void *p)
{
    u32 n = 0;
    s32 count;
    s32 i;

    count = sub_0201AA18(p);
    for (i = 0; i < count; i++) {
        sub_0201AB28(p, i);
        if (sub_0201AD18(sub_0201AB28(p, i)) != 0) {
            n++;
        }
    }
    return n;
}




u32 sub_0201AA88(void *p)
{
    s32 i;
    u32 n = 0;
    s32 count;

    count = sub_0201AA18(p);
    for (i = 0; i < count; i++) {
        void *entry = sub_0201AB28(p, i);
        u32 a = func_02017E1C(entry, 0x4C, 0);
        u32 b = func_02017E1C(entry, 3, 0);

        if (a == 1 && b == 0) {
            n++;
        }
    }
    return n;
}




u32 sub_0201AAD4(void *p)
{
    s32 i;
    u32 n = 0;
    s32 count;

    count = sub_0201AA18(p);
    for (i = 0; i < count; i++) {
        void *entry = sub_0201AB28(p, i);

        if (func_02017E1C(entry, 3, 0) == 1) {
            n++;
        }
    }
    return n;
}




u32 sub_0201AB08(void *p)
{
    return sub_0201AD58(p, sub_0201AD18);
}




u32 sub_0201AB18(void *p)
{
    return sub_0201AD58(p, sub_0201AD40);
}





/*
 * A whole translation unit, matched as one byte range.
 *
 * sub_0201AB28 is the index calculator this whole neighbourhood shares: an
 * entry of an array of 0xDC-byte records starting eight bytes into the
 * object.  sub_0201AB34 looks the entry up and, if it is non-null (in
 * practice it always is; the check reads as a defensive null guard rather
 * than a reachable branch), tail-hands it to sub_0201AD18 (0x0201AC2C..,
 * still open at the time of writing but pinned as an extern here since a
 * `label` witness for it exists outside this range).
 *
 * Immediately in front of sub_0201AB28, at 0x0201AB08..0x0201AB28, are two
 * back to back linker long-branch veneers (`ldr r1,[pc,#4]; ldr r3,[pc,#8];
 * bx r3` plus two pool words each) that this file does not claim; see
 * docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md
 * for the general shape, though here both are Thumb-encoded stubs rather
 * than the ARM long-branch form.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AB28.c \
 *       --addr 0x0201AB28 --thumb
 */
void *sub_0201AB28(void *p, u32 idx)
{
    return (u8 *)p + 8 + idx * 0xDC;
}





u32 sub_0201AB34(void *p, u32 idx)
{
    void *entry = sub_0201AB28(p, idx);

    if (entry != 0) {
        return sub_0201AD18(entry);
    }
    return 0;
}





/*
 * pokeparty.c: the store-at-index and swap-two-indices operations on the
 * party container, an array of 0xDC byte records eight bytes into the object
 * with a running count at +0x04.  The file name is the image's own: the debug
 * allocator call in sub_0201AB8C passes 0x020A7304, which spells
 * "pokeparty.c", and its neighbours in the string area are
 * "poke_regulation.c" and "poke_personal.c".
 *
 * Both functions copy a whole record with a plain struct assignment, which
 * this front end inlines as a counted `ldm`/`stm` loop of 27 eight-byte steps
 * plus a trailing word rather than as a call
 * (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md).  The record is
 * declared as an array of `u32` and not of `u8` for exactly that reason: a
 * one-aligned declaration gives a byte loop of 0xDC iterations, the same
 * shape with completely different bytes.
 *
 * sub_0201AB48 reads field 0xA9 (the "slot is occupied" derived id, see
 * src/pending/sub_02018E34.c) out of the destination slot before the copy and
 * out of the source after it, and adds the difference to the count, so the
 * count stays right whether the write fills an empty slot or overwrites a
 * full one.
 *
 * Two spellings in sub_0201AB48 are load bearing and neither is obvious.  The
 * destination of the copy is written as byte arithmetic,
 * `(u8 *)p + idx * sizeof(rec) + 8`, while the getter's argument is the
 * ordinary `&p->mon[idx]`: written the same way twice the compiler common
 * subexpression eliminates them and keeps the finished address in a
 * callee-saved register across both calls, which is four bytes short.  What
 * the original keeps alive across the calls is the *product*, and only two
 * differently associated address expressions produce that.  And the second
 * getter's result is not bound to a local: `a - func_02017E1C(...)` puts the
 * `subs` at the call, where the original has it, while a named `b` sinks it
 * past the copy loop (the mirror of
 * docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * sub_0201AB8C swaps two slots through a heap-allocated temporary of exactly
 * one record, then swaps the two slots' 0x1B-keyed side values through
 * sub_0201ACC4 / sub_0201ACDC (src/matched/unit_0201AC2C.c).  It returns 0
 * unconditionally.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AB48.c \
 *       --addr 0x0201AB48 --thumb
 */
void sub_0201AB48(struct Party_0201AB28 *p, u32 idx, const struct PartyMon *src)
{
    u32 a = func_02017E1C(&p->mon[idx], 0xA9, 0);
    u32 d = a - func_02017E1C((void *)src, 0xA9, 0);

    *(struct PartyMon *)((u8 *)p + idx * sizeof(struct PartyMon) + 8) = *src;
    p->count += d;
}



u32 sub_0201AB8C(struct Party_0201AB28 *p, u32 i, u32 j, u32 heap)
{
    u32 a;
    u32 b;
    struct PartyMon *tmp = (struct PartyMon *)func_02030734(heap, sizeof(struct PartyMon), 0,
                                                           sub_0201AB8C_File, 382);

    *tmp = p->mon[i];
    p->mon[i] = p->mon[j];
    p->mon[j] = *tmp;
    func_020307B0(tmp);
    a = sub_0201ACC4(p, i);
    b = sub_0201ACC4(p, j);
    sub_0201ACDC(p, i, b);
    sub_0201ACDC(p, j, a);
    return 0;
}




/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201ACDC, sub_0201AD0C, sub_0201AD18, sub_0201AD40,
 *           sub_0201AD58
 *
 * Nine functions over a 0xDC-byte-record array container (the same array
 * sub_0201AB28, in unit_0201AB28.c, indexes), all going through
 * func_02017E1C, a getter keyed by a small id constant (0x4C, 0xA0, 5), that
 * this file leaves as an unresolved extern because its own definition is
 * still open elsewhere in the image.
 *
 * sub_0201AC2C copies the whole 0x534-byte container by value; declaring the
 * two pointers `(const struct Rec534 *src, struct Rec534 *dst)`, in that
 * argument order, is what gets the `ldm`/`stm` loop's read and write sides
 * right (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; the record
 * is declared as a `u32` array so it is four-aligned rather than one-aligned,
 * which is what selects the register loop over a byte loop).
 *
 * sub_0201AC44 and sub_0201AC80 both walk the record array with a signed
 * loop counter (the original's `blt`/`ble` fix that, not `blo`/`bls`), the
 * first hunting for one whose entry's id-5 getter matches a target and
 * returning whether the loop ran out, the second counting entries that pass
 * one predicate and fail a second.  sub_0201AC80's `s32 n, i, count` layout
 * matters for register allocation, not just its value:
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md is
 * the general rule and it is `i` declared before `n` here, `count`
 * initialised to zero on the same line as `i`.
 *
 * sub_0201ACC4 is a plain bit test on a byte 0x530 into the object.
 * sub_0201ACDC sets or clears one bit of the same byte depending on a mode
 * argument; writing the two branches as `x = x | mask` / `x = x & ~mask`
 * over a double array-indexed expression (not a named pointer hoisted above
 * the `if`) is what keeps the address computation inside each arm instead of
 * being shared ahead of the branch.
 *
 * sub_0201AD0C is a 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * sub_020071CC (declared and used the same way in
 * src/matched/unit_0200E884.c) with a literal id of 0x1A.
 *
 * sub_0201AD18 and sub_0201AD40 are both single-guard wrappers around
 * func_02017E1C.  sub_0201AD18's `a != 1 && b != 0` failing to `return 0` is
 * the guard-chain-shares-one-exit-block shape
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md)
 * applied to a genuine conjunction rather than the more common early-return
 * failure chain: writing it as `a == 1 || b == 0` and returning 0 for that
 * case, which reads more naturally, does not reproduce the byte where the
 * shared block sits, because with only two operands the last one gets the
 * idiom's special direct-result treatment
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md) and
 * the observed shape has both comparisons branching to one identical exit,
 * which only the `&&`-guards-the-good-path phrasing produces.
 *
 * sub_0201AD58 is a linear search over the record array taking a function
 * pointer predicate, returning the index of the first match or the count if
 * none matched; `s32 i` declared before `s32 n = sub_0201AA18(p)` is again
 * the register-order tell.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AC2C.c \
 *       --addr 0x0201AC2C --thumb
 */
void sub_0201AC2C(const struct Rec534 *src, struct Rec534 *dst)
{
    *dst = *src;
}






u32 sub_0201AC44(struct Rec_0201A4D4 *p, u32 target)
{
    s32 i;

    for (i = 0; i < p->unk04; i++) {
        void *entry = &p->unk08[i * 0xDC];

        if (func_02017E1C(entry, 5, 0) == target) {
            break;
        }
    }
    if (i == p->unk04) {
        return 0;
    }
    return 1;
}






u32 sub_0201AC80(void *p)
{
    s32 n = sub_0201AA18(p);
    s32 i, count = 0;

    for (i = 0; i < n; i++) {
        void *entry = sub_0201AB28(p, i);

        if (func_02017E1C(entry, 0xA0, 0)) {
            if (!func_02017E1C(entry, 0x4C, 0)) {
                count++;
            }
        }
    }
    return count;
}






int sub_0201ACC4(void *p, u32 pos)
{
    u8 b = ((u8 *)p)[0x530];

    if (b & (1u << pos)) {
        return 1;
    }
    return 0;
}






void sub_0201ACDC(void *p, u32 pos, u32 mode)
{
    if (mode == 1) {
        ((u8 *)p)[0x530] = ((u8 *)p)[0x530] | (1u << pos);
    } else {
        ((u8 *)p)[0x530] = ((u8 *)p)[0x530] & (0xFFu - (1u << pos));
    }
}






void *sub_0201AD0C(void *sys)
{
    return sub_020071CC(sys, 0x1A);
}






u32 sub_0201AD18(void *p)
{
    u32 a = func_02017E1C(p, 0x4C, 0);
    u32 b = func_02017E1C(p, 0xA0, 0);

    if (a != 1 && b != 0) {
        return 1;
    }
    return 0;
}






u32 sub_0201AD40(void *p)
{
    u32 r = 0;

    if (func_02017E1C(p, 0x4C, 0) != 1) {
        r = 1;
    }
    return r;
}






u32 sub_0201AD58(void *p, Predicate pred)
{
    s32 i;
    s32 n = sub_0201AA18(p);

    for (i = 0; i < n; i++) {
        void *entry = sub_0201AB28(p, i);

        if (pred(entry)) {
            return i;
        }
    }
    return n;
}






/*
 * The lazy constructor for the static handle at 0x0214652C that
 * src/matched/unit_0201ADA4.c and src/matched/unit_0201ADD0.c thread every
 * call through: allocates a 0x10 byte object out of the heap named by the
 * parameter the first time it is asked and does nothing afterwards.
 *
 * The `adds r1, r0, #0` that moves the parameter out of r0 sits in front of
 * the guard's own load rather than inside the `if`, which is what the
 * parameter being live across the test costs; it is not an argument set-up
 * for a call that happens later.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AD88.c \
 *       --addr 0x0201AD88 --thumb
 */
void sub_0201AD88(u32 heap)
{
    if (g_0214652C == 0) {
        g_0214652C = func_020490F4(0x10, heap);
    }
}






/*
 * A three-parameter wrapper: calls sub_0201AFD4(a, b) (0x0201AFD4, still
 * open) and threads its result through two handler calls keyed off a static
 * handle at 0x0214652C, then hands the third parameter off to a third
 * handler with a literal id of 0x3C.  Kept as its own file rather than
 * merged with the neighbouring sub_0201ADD0/sub_0201ADE4
 * (src/matched/unit_0201ADD0.c) because both of those call sub_0201AFD4 as
 * well; one range holding all three calls has none of them attested and
 * caps at MATCH (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 * With this function alone, the other two callers are outside the range and
 * carry the `label` evidence.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADA4.c \
 *       --addr 0x0201ADA4 --thumb
 */
void sub_0201ADA4(u32 a, int b, void *c)
{
    u32 r = sub_0201AFD4(a, b);

    r = func_02049578(g_0214652C, r);
    func_0204960C(g_0214652C, (void *)r);
    func_020495F4(g_0214652C, 0x3C, c);
}






/*
 * A whole translation unit, matched as one byte range.
 *
 * sub_0201ADD0 is a second, smaller wrapper around sub_0201AFD4 (see
 * src/matched/unit_0201ADA4.c for why it is not merged with that file); here
 * the result goes straight to one handler call with a literal id of 0x12.
 *
 * sub_0201ADE4 constructs an object from the debug allocator,
 * func_02030734(heap, size, zero, file, tag), with the __FILE__
 * argument an ABS32 into the packed string area rather than a locally
 * emitted string (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).
 * The string is "poke_personal.c" at 0x020A7310, attested by the `string`
 * class off the terminator of "pokeparty.c" just before it; both sit in the
 * same run of Pokemon-data file names as "poke_tool.c", "poke_regulation.c"
 * and "shinka_check.c" starting at 0x020A72E4, which is the strongest single
 * clue to this packet's subsystem: species/personal-data records, not the
 * WCM/NHTTP wireless code the neighbouring packets' sdk_calls hint at.  It
 * then forwards to sub_0201ADA4 (src/matched/unit_0201ADA4.c) and returns the
 * newly allocated object.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADD0.c \
 *       --addr 0x0201ADD0 --thumb
 */
void sub_0201ADD0(u32 a, int b, void *c)
{
    u32 r = sub_0201AFD4(a, b);

    func_02048F4C(c, 0x12, r);
}






void *sub_0201ADE4(u32 a, int b, u32 c)
{
    void *obj = func_02030734(c, 0x3C, 0, sub_0201ADE4_File, 0x76);

    sub_0201ADA4(a, b, obj);
    return obj;
}






/*
 * poke_personal.c's record destructor: four bytes of code and one pool word,
 * a tail call with no argument set-up at all
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  It abuts
 * src/matched/unit_0201ADD0.c on the left, whose sub_0201ADE4 carries the
 * "poke_personal.c" file string.
 *
 * This file used to hold the whole middle of poke_personal.c
 * (0x0201AE14..0x0201AFD4: this destructor, the 44 field getter, the
 * placeholder-ability predicate and the form-table loader).  It was cut into
 * three so that the 44 field getter, which the whole poke_* region reads the
 * personal record through, gets a manifest entry of its own instead of being
 * an interior function with no attestable address
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  The other two
 * pieces are src/matched/sub_0201AE1C.c and src/matched/unit_0201AF6C.c; the
 * C in all three is unchanged, only the file boundaries moved, and no
 * relocation crosses a new boundary.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AE14.c \
 *       --addr 0x0201AE14 --thumb
 */
void sub_0201AE14(void *p)
{
    func_020307B0(p);
}






/*
 * poke_personal.c's 44 field getter over the 0x3C byte personal record, cut
 * out of src/matched/unit_0201AE14.c so that it has a manifest entry of its
 * own.  The bytes and the C are unchanged; only the file boundary moved.
 *
 * Why it is its own file: the manifest records one entry per unit at the
 * unit's start address, so while this function sat in the middle of
 * unit_0201AE14.c the address 0x0201AE1C had no entry, was not an address the
 * `matched` evidence class could attest, and read as still open to every
 * consumer that asked the manifest what the record layer covers
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  It has high
 * fan-in: it is the field selector the whole poke_* region reads the personal
 * record through, so it is exactly the address that wants an entry.
 *
 * Splitting costs nothing here: sub_0201AE14 (the record destructor, four
 * bytes of code and a pool word) keeps the start address and therefore keeps
 * its entry, sub_0201AF6C and sub_0201AF80 move into
 * src/matched/unit_0201AF6C.c which starts at the address of the first of
 * them, and this function holds no relocation at all, so no cut can take a
 * witness away from anybody.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * The 44 case ids are an interface rather than content: they are the field
 * selector the whole region uses, and src/matched/sub_02018A7C.c reads the
 * same record through ids of its own.  The field offsets are structure and
 * will not move; the ids will not either unless a field is added, which is
 * exactly the kind of thing a version diff does, so the map below is the thing
 * to check against IRAO rather than any single number.  No constant in this
 * function is a content id.
 *
 * ---------------------------------------------------------------------------
 * THE FIELD MAP, from the jump table
 * ---------------------------------------------------------------------------
 * The table at 0x0201AE2E is 44 signed halfwords and every one of them names a
 * real body, so the source has case labels 0 through 43 with no gaps
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md).  The bodies
 * are emitted in the source's order, which here is also the numeric order,
 * even though the offsets they read are not monotonic: id 9 reads +0x22 and id
 * 36 reads +0x09, both out of sequence.
 *
 *    0.. 5  +0x00..+0x05  the six base stats
 *    6, 7   +0x06, +0x07  the two types
 *    8      +0x08
 *    9      +0x22
 *   10..15  +0x0A bits 0..11, six 2 bit fields: the six effort yields
 *   16      +0x0A bit 12, one bit
 *   17..19  +0x0C, +0x0E, +0x10  three held item ids
 *   20..29  +0x12..+0x1B  ten bytes
 *   30, 31  +0x1C, +0x1E  the form table base and its companion; +0x1C is the
 *                         same field src/matched/unit_0201AFD4.c reads
 *   32      +0x20         the form count, also read by unit_0201AFD4.c
 *   33      +0x21 bits 0..5
 *   34, 35  +0x21 bit 6, bit 7
 *   36      +0x09
 *   37, 38  +0x24, +0x26
 *   39..43  +0x28..+0x38  five words
 *
 * Two shapes in there are readings of the declaration rather than of the code.
 * The 2 bit and 1 bit extractions at +0x0A are `lsls`/`lsrs` pairs whose width
 * is neither 8, 16 nor 32, so they are bitfields and nothing else
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md); the
 * container has to be `u16` for the load to be a `ldrh`, and `u8` at +0x21 for
 * it to be a `ldrb`.  And the two bytes at +0x20 and +0x21 each cost an
 * `adds r0, #0x20` first, which is only the byte immediate's reach of 31
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md); the halfword at +0x22
 * needs none, because `ldrh` reaches 62.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/sub_0201AE1C.c \
 *       --addr 0x0201AE1C --thumb
 */
u32 sub_0201AE1C(const struct Personal_0201AE1C *p, u32 field)
{
    switch (field) {
    case 0:  return p->unk00;
    case 1:  return p->unk01;
    case 2:  return p->unk02;
    case 3:  return p->unk03;
    case 4:  return p->unk04;
    case 5:  return p->unk05;
    case 6:  return p->unk06;
    case 7:  return p->unk07;
    case 8:  return p->unk08;
    case 9:  return p->unk22;
    case 10: return p->ev0;
    case 11: return p->ev1;
    case 12: return p->ev2;
    case 13: return p->ev3;
    case 14: return p->ev4;
    case 15: return p->ev5;
    case 16: return p->unk0A_12;
    case 17: return p->unk0C;
    case 18: return p->unk0E;
    case 19: return p->unk10;
    case 20: return p->unk12;
    case 21: return p->unk13;
    case 22: return p->unk14;
    case 23: return p->unk15;
    case 24: return p->unk16;
    case 25: return p->unk17;
    case 26: return p->unk18;
    case 27: return p->unk19;
    case 28: return p->unk1A;
    case 29: return p->unk1B;
    case 30: return p->unk1C;
    case 31: return p->unk1E;
    case 32: return p->unk20;
    case 33: return p->unk21_0;
    case 34: return p->unk21_6;
    case 35: return p->unk21_7;
    case 36: return p->unk09;
    case 37: return p->unk24;
    case 38: return p->unk26;
    case 39: return p->unk28;
    case 40: return p->unk2C;
    case 41: return p->unk30;
    case 42: return p->unk34;
    case 43: return p->unk38;
    }
    return 0;
}




/*
 * The tail of poke_personal.c: the "is this a placeholder ability id"
 * predicate and the form-table loader.  Cut out of
 * src/matched/unit_0201AE14.c together with src/matched/sub_0201AE1C.c so
 * that the 44 field getter at 0x0201AE1C gets a manifest entry of its own
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).  The C is
 * unchanged; only the file boundary moved.  This file still starts at the
 * address of its own first function, so it loses no entry by the same rule:
 * sub_0201AF80 was already an interior function of unit_0201AE14.c.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Three content constants live here and every one of them is a number the
 * game's data, not its structure, decides:
 *
 *   0x29C (668)  sub_0201AF80's archive member id, the form table.  It is the
 *                index of one member inside the handle at 0x0214652C, so it
 *                moves if the archive is repacked; IRAO is expected to share
 *                the packing but this is the first thing to re-read.
 *   999          sub_0201AF80's "no entry" sentinel in that form table.  It is
 *                a species-space sentinel, not a count, and it is what the
 *                entry count is measured against.
 *   0, 0xFE,0xFF sub_0201AF6C's three accepted ids.  The callers (0x02017D00,
 *                0x0201860E, 0x020186AE, 0x020186FE, 0x02018718) all feed it a
 *                value read out of the personal record, so these are content
 *                ids in the same space as the record's own fields.
 *
 * ---------------------------------------------------------------------------
 * THE TWO FUNCTIONS
 * ---------------------------------------------------------------------------
 * sub_0201AF6C is a disjunction and not a conjunction.  The `beq` from the
 * first test lands on the `movs r0, #1` that the second test's `bhi` falls
 * through to, and the `movs r0, #0` is out of line behind it; written
 * `if (v != 0 && v - 0xFE > 1) return 0;` every byte is still right and the
 * two exit blocks come out in the opposite order
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md,
 * docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0201AF80 narrows the byte length the archive hands back to a halfword
 * count with a single `lsls #0xf` / `lsrs #0x10` pair.  The amounts are
 * unequal, so it is a cast folded with a shift and not a bitfield: 32 - 16 is
 * the width and 15 - 16 is the shift, i.e. `(u16)(len >> 1)`
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * Writing `(u16)(len / 2)` costs a second pair.  The counter's zero is a copy
 * of the accumulator's (`adds r2, r5, #0`), which is what says the
 * accumulator is assigned first
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AF6C.c \
 *       --addr 0x0201AF6C --thumb
 */
u32 sub_0201AF6C(u32 v)
{
    if (v == 0 || v - 0xFE <= 1) {
        return 1;
    }
    return 0;
}






u16 *sub_0201AF80(u32 heap, u16 *countOut)
{
    u32 len;
    u16 *tab;
    u16 count;
    u16 n;
    u16 i;

    count = 0;
    tab = func_0204A39C(g_0214652C, 0x29C, 0, heap, &len);
    n = (u16)(len >> 1);
    if (countOut != 0) {
        for (i = 0; i < n; i++) {
            if (tab[i] != 999) {
                count++;
            }
        }
        *countOut = count;
    }
    return tab;
}






/*
 * The species-to-form resolver the three wrappers in
 * src/matched/unit_0201ADA4.c and src/matched/unit_0201ADD0.c open with: it
 * reads the 0x3C byte personal record for the species out of the archive
 * handle at 0x0214652C and, when the record has a form table and the
 * requested form is inside it, answers with the form's own species-like id.
 *
 * VERSION SENSITIVITY: the guard rejects exactly the two ids 650 and 651,
 * which are the egg and bad-egg entries src/pending/sub_02018E34.c's field
 * map already names, and it spells them as a 16 bit range test.  They are
 * content ids rather than structure offsets, so they are the first thing to
 * re-read for a Pokemon White build; nothing else in this function is
 * version dependent.
 *
 * The test is written `(u16)(species + 0xFD76) > 1`, not `species - 650`:
 * 0x28A does not fit an 8 bit immediate either way, and only the positive
 * unsigned 16 bit spelling of the complement keeps the constant in the pool
 * where the original has it
 * (docs/idioms/out-of-range-immediate-subtract-costs-a-pool-word.md).
 *
 * The three tests in the tail are one disjunction guarding `return species`,
 * not the conjunction guarding the computed answer that the semantics
 * suggest: written the other way round every byte is still right but the two
 * exit blocks are emitted in the opposite order, because the block the source
 * writes inside the `if` is the one that comes first
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md and
 * docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The record's halfword at +0x1C is reached with a plain `ldrh [r0, #0x1c]`
 * while its byte at +0x20 costs an `add r0, sp, #0x20` first, which is only
 * the byte immediate's reach of 31 and not a second pointer
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AFD4.c \
 *       --addr 0x0201AFD4 --thumb
 */
u32 sub_0201AFD4(u32 species, s32 form)
{
    struct Personal_0201AFD4 rec;

    if ((u16)(species + 0xFD76) <= 1) {
        return 0;
    }
    func_0204960C(g_0214652C, (void *)func_02049578(g_0214652C, species));
    func_020495F4(g_0214652C, 0x3C, &rec);
    if (rec.unk1C == 0 || rec.unk20 <= form || form == 0) {
        return species;
    }
    return (u16)(rec.unk1C + form - 1);
}





/*
 * note:     EXACT* only for the two bytes of alignment padding at
 *           0x0201B0FE.  The rare random event that seeds party record
 *           field 0x97 (see docs/notes/sub_0201B038.c.txt for the draws and
 *           the version-sensitive constants 0x4000/0x8000/0xC000, 7, 0xF3,
 *           content values rather than addresses).  Closed in wave 16: the
 *           packed byte is built as `w = v; w |= (u8)(v << 4);` (the copy is
 *           the image's `adds r3, r0, #0` before the orrs), and the last two
 *           truncations are written inside the call argument, which lets the
 *           final lsls/lsrs pair straddle the argument set-up.
 */
void sub_0201B038(void *party)
{
    u32 mask;
    u32 r;
    u32 slot;
    void *mon;
    u32 v;
    u32 w;
    u32 n;

    n = sub_0201AA18(party);
    r = (u16)((u64)func_0203F0A8() * 0x10000 >> 32);
    mask = sub_0201B220(party);
    if (r == 0x4000 || r == 0x8000 || r == 0xC000) {
        do {
            slot = func_0203F0A8();
            if (n != 0) {
                slot = (u32)(((u64)slot * n) >> 32);
            }
            mon = sub_0201AB28(party, slot);
        } while (func_02017E1C(mon, 5, 0) == 0
                 || func_02017E1C(mon, 0x4C, 0) != 0);
        if ((mask & (1 << slot)) != 0) {
            return;
        }
        do {
            v = (u8)((u64)func_0203F0A8() * 0x100 >> 32);
        } while ((v & 7) == 0);
        if ((v & 0xF0) != 0) {
            v = v & 7;
        }
        w = v; w |= (u8)(v << 4);
        func_02017E40(mon, 0x97, (u8)((u8)(w & 0xF3) + 1));
    }
}





/*
 * A whole translation unit, matched as one byte range.
 *
 * The two writers of the packed byte field id 0x97 that
 * src/matched/unit_0201B220.c reads: sub_0201B100 counts its low nibble down
 * across the whole party, and sub_0201B170 spreads it to the neighbouring
 * slots one time in three.
 *
 * sub_0201B100 walks every occupied slot, clears the low nibble outright when
 * the amount to subtract is larger than it or larger than 4, subtracts it
 * otherwise, and forces 0x10 when the whole byte comes out zero so that the
 * high nibble stays distinguishable from "never set".  sub_0201B170 copies a
 * slot's byte into the slot before and the slot after it whenever theirs has
 * no high nibble, and advances the index an extra step when it wrote forwards
 * so that a value cannot propagate down the party in one pass.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id.  What is content shaped:
 *
 *   4      sub_0201B100's threshold: an amount above it always clears the
 *          nibble instead of subtracting, so it is a rule about the field's
 *          range rather than about its layout.
 *   0x10   the value written when the subtraction leaves zero, i.e. the low
 *          nibble empty and the high nibble at one.
 *   3      sub_0201B170's odds, one call in three.
 *   0xF, 0xF0   the two nibble masks, the field's own layout.
 *   0x97, 5   party record ids in src/matched/sub_02018DB4.c's space.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B170's odds are a 64 bit multiply and not a modulo:
 * `(u64)rand() * 3 >> 32` puts the answer in the `_ull_mul` call's **r1**, and
 * the `movs r1, #0` in front of the call is the draw's high half rather than a
 * second argument.  See
 * docs/idioms/random-below-n-is-a-64-bit-multiply-high.md.
 *
 * It has no `last` variable.  The original loads the count once, tests it,
 * decrements it and spills the result, which reads like `last = n - 1` written
 * after an `if (n > 0)` guard; it is not.  It is `if (i < n - 1)` inside the
 * loop, with `n - 1` hoisted into the loop preheader by the compiler, which is
 * why the decrement lands after the loop's own entry guard rather than before
 * it.  Writing the guard and the local out by hand costs six bytes.
 *
 * sub_0201B100's two arms are not spelled the same way.  The masking arm is a
 * compound assignment, `v &= 0xF0`, and the subtracting arm carries an explicit
 * `(u8)` cast; written with the cast on both, the two truncations cross-jump
 * into one block that both arms branch to and the function is four bytes
 * short.  That is
 * docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md
 * seen on a local rather than on a field: the compound form is the one that
 * does not materialise a fresh truncation.
 *
 * Both loop counters are signed, and in sub_0201B100 the amount and the
 * extracted nibble are signed too: the comparisons are `blt` and `ble`, not
 * `blo` and `bls`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B100.c \
 *       --addr 0x0201B100 --thumb
 */
void sub_0201B100(void *party, s32 amount)
{
    s32 n;
    void *mon;
    s32 i;
    u8 v;
    s32 low;

    n = sub_0201AA18(party);
    for (i = 0; i < n; i++) {
        mon = sub_0201AB28(party, i);
        if (func_02017E1C(mon, 5, 0) == 0) {
            continue;
        }
        v = (u8)func_02017E1C(mon, 0x97, 0);
        low = v & 0xF;
        if (low == 0) {
            continue;
        }
        if (low < amount || amount > 4) {
            v &= 0xF0;
        } else {
            v = (u8)(v - (u8)amount);
        }
        if (v == 0) {
            v = 0x10;
        }
        func_02017E40(mon, 0x97, v);
    }
}





void sub_0201B170(void *party)
{
    s32 i;
    void *mon;
    void *other;
    u8 v;
    s32 n;

    n = sub_0201AA18(party);
    if ((u32)((u64)func_0203F0A8() * 3 >> 32) != 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        mon = sub_0201AB28(party, i);
        if (func_02017E1C(mon, 5, 0) == 0) {
            continue;
        }
        v = (u8)func_02017E1C(mon, 0x97, 0);
        if ((v & 0xF) == 0) {
            continue;
        }
        if (i != 0) {
            other = sub_0201AB28(party, i - 1);
            if ((func_02017E1C(other, 0x97, 0) & 0xF0) == 0) {
                func_02017E40(other, 0x97, v);
            }
        }
        if (i < n - 1) {
            other = sub_0201AB28(party, i + 1);
            if ((func_02017E1C(other, 0x97, 0) & 0xF0) == 0) {
                func_02017E40(other, 0x97, v);
                i++;
            }
        }
    }
}





/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_0201B28C
 *
 * Five readers of one packed byte field, id 0x97 of the party record, whose
 * two nibbles are written by the loop at 0x0201B0DC in the same file.
 *
 * sub_0201B220 answers a bitmask of the party slots whose field is non zero,
 * one bit per slot, and is the value the code at 0x0201B056 tests before it
 * writes a new one.  sub_0201B268 asks whether the low nibble is set and
 * sub_0201B28C whether the high nibble is set and the low one is not;
 * sub_0201B25C and sub_0201B280 are their two-instruction wrappers over
 * func_020185F0.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x97 is a party record id in
 * src/matched/sub_02018DB4.c's space, and the two nibble masks 0xF and 0xF0
 * are the field's own layout.  What is worth re-reading for IRAO is the
 * meaning rather than the numbers: the field is a counter in the low nibble
 * and a flag set in the high one, and a version that widened either would
 * change all five of these functions and the writer at 0x0201B0DC together.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B220 assigns the mask before it asks for the party count, which is
 * what keeps the zero a `movs` in the prologue and lets the loop index take a
 * second `movs` after the call rather than a pool word
 * (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 * Its shift is truncated to a byte at the use, `mask |= (u8)(1 << i)`, which is
 * the cast placement docs/MATCHING.md pins for sub_0200A6BC: held in a `u8`
 * temporary instead, the truncation cannot sink and the tail of the loop comes
 * out with every register moved.
 *
 * sub_0201B28C reads the field into a `u8` local and tests it twice, so the
 * constant is the `tst`'s first operand and the field its second; sub_0201B268
 * tests the call result directly and gets the other operand order.  That one
 * byte is the only difference between the two shapes, and it is the same tell
 * docs/idioms/cmp-operand-order-names-the-temporary.md records for `cmp`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B220.c \
 *       --addr 0x0201B220 --thumb
 */
u32 sub_0201B220(void *party)
{
    s32 i;
    u32 mask;
    s32 n;

    mask = 0;
    n = sub_0201AA18(party);
    for (i = 0; i < n; i++) {
        if (func_02017E1C(sub_0201AB28(party, i), 0x97, 0) != 0) {
            mask |= (u8)(1 << i);
        }
    }
    return mask;
}





u32 sub_0201B25C(void *a)
{
    return sub_0201B268(func_020185F0(a));
}





u32 sub_0201B268(void *mon)
{
    u32 r;

    r = 0;
    if ((func_02017E88(mon, 0x97, 0) & 0xF) != 0) {
        r = 1;
    }
    return r;
}





u32 sub_0201B280(void *a)
{
    return sub_0201B28C(func_020185F0(a));
}





u32 sub_0201B28C(void *mon)
{
    u32 r;
    u8 v;

    r = 0;
    v = (u8)func_02017E88(mon, 0x97, 0);
    if ((v & 0xF) == 0 && (v & 0xF0) != 0) {
        r = 1;
    }
    return r;
}





/*
 * note:     wave 18 (2026-09-24): EXACT* (the listing extent includes the
 *           12-byte unlabelled follower at 0x0201B70C, src/matched/
 *           unit_0201B70C.c).  Closed by the heap id's width: the seventh
 *           parameter is a u16 and func_02020FE4 takes its third argument
 *           as a u16.  With both u32 the gate's `ldr r2, [sp, #0x68]` is
 *           hoisted above the pidHigh store (12 bytes out); u16 on the
 *           parameter alone breaks the size, u16 on both keeps the load
 *           behind the store as in the image.  func_02020FE4 masks the id to
 *           fifteen bits and ORs in 0x8000 (a temporary-heap id), and
 *           src/matched/unit_02007CB0.c already declares that parameter u16.
 *
 * shinka_check.c (the string at 0x020A7330), the evolution checker: the
 * egg/everstone gate, then the 0x2A-byte evolution record (seven six-byte
 * rows, sub_0201B764) walked under a switch on the context (0 level up,
 * 1 trade, 2 and 3 item use); the first row that fires gives the target
 * species and its method goes to *methodOut (method 15 writes 15 and gives
 * no species).  docs/notes/sub_0201B2B0.c.txt holds the method map and the
 * history.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201B2B0.c \
 *       --func sub_0201B2B0 --addr 0x0201B2B0 --cc 1.1p1 --thumb
 */
u32 sub_0201B2B0(void *party, void *mon, u32 context, u32 param,
                 u8 timezone, u32 *methodOut, u16 heap)
{
    u32 dummy;
    u32 a3c;
    u32 a38;
    u32 a34;
    u32 pid;
    struct EvoRow_0201B2B0 *table;
    u16 species;
    u16 held;
    u16 friendship;
    u16 pidHigh;
    u8  level;
    u8  beauty;
    int i;
    u16 result;
    u8  holdEffect;
    struct EvoRow_0201B2B0 *row;
    u32 j;

    result = 0;
    if (func_02017E1C(mon, 0x4C, 0) != 0) {
        return result;
    }
    species = func_02017E1C(mon, 5, 0);
    held = func_02017E1C(mon, 6, 0);
    pid = func_02017E1C(mon, 0, 0);
    beauty = func_02017E1C(mon, 0x14, 0);
    pidHigh = (pid & 0xFFFF0000) >> 16;
    holdEffect = func_02020FE4(held, 1, heap);
    if (species != 0x40 && holdEffect == 0x40 && context != 3) {
        return result;
    }
    if (methodOut == 0) {
        methodOut = &dummy;
    }
    i = 0;
    table = func_02030734(heap, 0x2A, 0, (const char *)s_shinka_check_c, 0x6A);
    sub_0201B764(species, table);

    switch (context) {
    case 0:
        level = func_02017E1C(mon, 0x9E, i);
        friendship = func_02017E1C(mon, 9, i);
        for (i = 0; i < 7; i++) {
            row = &table[i];
            switch (row->method) {
            case 1:
                if (friendship >= 220) {
                    result = row->target;
                }
                break;
            case 2:
                if (func_02011410(timezone) == 0 && friendship >= 220) {
                    result = row->target;
                }
                break;
            case 3:
                if (func_02011410(timezone) == 1 && friendship >= 220) {
                    result = row->target;
                }
                break;
            case 4:
                if (row->param <= level) {
                    result = row->target;
                }
                break;
            case 9:
                if (row->param <= level) {
                    a34 = func_02017E1C(mon, 0xA2, 0);
                    if (a34 > func_02017E1C(mon, 0xA3, 0)) {
                        result = row->target;
                    }
                }
                break;
            case 10:
                if (row->param <= level) {
                    a38 = func_02017E1C(mon, 0xA2, 0);
                    if (a38 == func_02017E1C(mon, 0xA3, 0)) {
                        result = row->target;
                    }
                }
                break;
            case 11:
                if (row->param <= level) {
                    a3c = func_02017E1C(mon, 0xA2, 0);
                    if (a3c < func_02017E1C(mon, 0xA3, 0)) {
                        result = row->target;
                    }
                }
                break;
            case 12:
                if (row->param <= level && pidHigh % 10 < 5) {
                    result = row->target;
                }
                break;
            case 13:
                if (row->param <= level && pidHigh % 10 >= 5) {
                    result = row->target;
                }
                break;
            case 14:
                if (row->param <= level) {
                    result = row->target;
                }
                break;
            case 15:
                *methodOut = 15;
                break;
            case 16:
                if (row->param <= beauty) {
                    result = row->target;
                }
                break;
            case 19:
                if (func_02011410(timezone) == 0 && held == row->param) {
                    result = row->target;
                }
                break;
            case 20:
                if (func_02011410(timezone) == 1 && held == row->param) {
                    result = row->target;
                }
                break;
            case 21:
                if (sub_0201B774(mon, row->param) == 1) {
                    result = row->target;
                }
                break;
            case 22:
                if (party != 0 && sub_0201AC44(party, row->param) == 1) {
                    result = row->target;
                }
                break;
            case 23:
                if (func_02017E1C(mon, 0x6E, 0) == 0 && row->param <= level) {
                    result = row->target;
                }
                break;
            case 24:
                if (func_02017E1C(mon, 0x6E, 0) == 1 && row->param <= level) {
                    result = row->target;
                }
                break;
            case 25:
                for (j = 0; j < 3; j++) {
                    if (param == g_020A7324[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            case 26:
                for (j = 0; j < 1; j++) {
                    if (param == g_020A7322[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            case 27:
                for (j = 0; j < 1; j++) {
                    if (param == g_020A7320[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            case 28:
                for (j = 0; j < 3; j++) {
                    if (param == g_020A732A[j]) {
                        result = row->target;
                        break;
                    }
                }
                break;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    case 1:
        for (i = 0; i < 7; i++) {
            row = &table[i];
            switch (row->method) {
            case 5:
                result = row->target;
                break;
            case 6:
                if (held == row->param) {
                    result = row->target;
                }
                break;
            case 7:
                if (func_02020FE4((u16)func_02017E1C((void *)param, 6, 0), 1, heap) != 0x40) {
                    if ((func_02017E1C(mon, 0xAB, 0) == 588
                         && func_02017E1C((void *)param, 0xAB, 0) == 616)
                     || (func_02017E1C((void *)param, 0xAB, 0) == 588
                         && func_02017E1C(mon, 0xAB, 0) == 616)) {
                        result = row->target;
                    }
                }
                break;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    case 2:
    case 3:
        for (i = 0; i < 7; i++) {
            row = &table[i];
            if (row->method == 8 && param == row->param) {
                result = row->target;
            }
            if (row->method == 0x11 && func_02017E1C(mon, 0x6E, 0) == 0 && param == row->param) {
                result = row->target;
            }
            if (row->method == 0x12 && func_02017E1C(mon, 0x6E, 0) == 1 && param == row->param) {
                result = row->target;
            }
            if (result != 0) {
                *methodOut = row->method;
                break;
            }
        }
        break;
    }
    func_020307B0(table);
    return result;
}





/*
 * A whole translation unit, matched as one byte range.
 *
 * shinka_check.c's data layer: the four small routines the evolution checker
 * at 0x0201B2B0 reads its per-species evolution table through, plus the "does
 * this Pokemon already know that move" predicate one of its arms needs.
 *
 * All three archive routines name the same narc member kind, 0x13, the way
 * src/matched/unit_0201BD28.c's waza_tool.c names 0x15 and
 * src/matched/unit_0201ADD0.c's poke_personal.c names 0x12.  The record is
 * 0x2C bytes: seven six byte rows and a trailing halfword, and the three
 * halfwords of a row are what sub_0201B718's three arm switch selects between,
 * which is how the row layout is readable at all.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   0x13   the archive member kind for the evolution table.  A kind rather
 *          than a species id, so it moves only if the archive set is
 *          repacked, but it is content in the sense that nothing in the code
 *          derives it.
 *   7      the number of evolution rows per species, as the 0x2C byte record
 *          size fixes it.  A White build that gave a species an eighth
 *          evolution would change this record size and every one of these
 *          four functions with it.
 *   0x36, 0x3A   sub_0201B774's move id range: the four move slots of the
 *          party record, in src/matched/sub_02018DB4.c's id space.  Structure
 *          rather than content, but listed because the loop bound is written
 *          as the literal 0x3A and not as "0x36 + 4".
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B70C and sub_0201B764 are tail calls and nothing else, eight bytes
 * of code and a pool word each
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  Neither could pass a
 * fourth argument even if it wanted to, because r3 carries the target
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md); sub_0201B764
 * passes exactly three and is at the limit.
 *
 * sub_0201B718's switch is a `cmp`/`beq` chain and not a jump table even
 * though its three labels are dense from zero, which is the count and not the
 * density deciding it
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md records the
 * opposite direction for a seven label switch).  The record's address is held
 * in r6 across the call because it is passed to it, so `case 0` reaches the
 * row with a register offset off r6 while `case 1` and `case 2` rebuild
 * `sp + 2` and `sp + 4`: that is the member offset, not a second pointer.
 *
 * sub_0201B774 keeps its answer in a stack slot carved out by the `r3` of the
 * prologue's `push`, and the third argument's zero is common
 * subexpression eliminated into r7 for the whole loop, which is why the
 * literal has to stay a literal at the call site rather than becoming a named
 * local.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B70C.c \
 *       --addr 0x0201B70C --thumb
 */
void *sub_0201B70C(u32 heap)
{
    return func_020490F4(0x13, heap);
}





u32 sub_0201B718(void *a, u32 id, u32 row, u32 field)
{
    struct EvoTable t;

    func_0204932C(a, id, &t);
    switch (field) {
    case 0:
        return t.rows[row].method;
    case 1:
        return t.rows[row].param;
    case 2:
        return t.rows[row].species;
    }
    return 0;
}





void sub_0201B764(u32 id, void *dest)
{
    func_02048F4C(dest, 0x13, id);
}





u32 sub_0201B774(void *mon, u32 move)
{
    u32 found;
    s32 i;

    found = 0;
    for (i = 0x36; i < 0x3A; i++) {
        if (move == func_02017E1C(mon, i, 0)) {
            found = 1;
            break;
        }
    }
    return found;
}





/*
 *           at 0x0201B7B0, inside the compared range; every concrete byte is
 *           right.
 *
 * A three-byte-stride table entry is handed to func_0201B850 along with the
 * caller's own third and fourth arguments.  Those two are forwarded
 * unchanged - they are already in r2/r3 - so no instruction moves them, and
 * that is also why the call is a real `bl` rather than a tail call: a Thumb
 * tail call spends r3 on the target address, so a four-argument call cannot
 * be one.  The 3 is lsls #1 plus adds; the table pointer is this function's
 * own pool word at 0x0201B7B0.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201B7A0.c \
 *       --func func_0201B7A0 --addr 0x0201B7A0 --cc 1.1p1 --thumb
 */
void func_0201B7A0(void *a0, int a1, int a2, u16 a3)
{
    func_0201B850(a0, &g_0209E45C[a1 * 3], a2, a3);
}









/*
 * Three bytes are built one selector at a time - selectors 0x3C, 0x3D, 0x3E
 * - and the three-byte buffer is then handed to func_0201B850 along with
 * the caller's own second and fourth arguments.  No literal pool: the only
 * pointers are the two call targets.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201B7B4.c \
 *       --func func_0201B7B4 --addr 0x0201B7B4 --cc 1.1p1 --thumb
 */
void func_0201B7B4(void *a0, int a1, u16 a2, u16 a3)
{
    u8 buf[3];
    int i;

    for (i = 0; i < 3; i++) {
        buf[i] = (u8)func_02020FE4(a1, (u16)(i + 0x3C), a3);
    }
    func_0201B850(a0, (const s8 *)buf, a2, a3);
}









/*
 * shinka_check.c.  The coin-flip sibling of func_0201B7A0 / func_0201B818:
 * on an even draw below 2, hand the fixed row g_0209E465 to func_0201B850.
 *
 * The `movs r1,#0 / lsls r1,r1,#1 / lsrs r0,r0,#31 / orrs` run that four
 * waves read as a scheduling tie of two u32 shifts is the high word of a
 * 64-bit product: the draw widened to u64, times 2, shifted right 32 (the
 * random-below-N idiom, docs/idioms/random-below-n-is-a-64-bit-multiply-high.md,
 * with N = 2).  The zero high half is shifted left by one and ORed with the
 * low half's carry-out bit; the compiler emits the two halves in that order,
 * which is the order no u32 spelling could reach.  `% 2 == 0` gives the
 * `tst` against 1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201B7EC.c \
 *       --func func_0201B7EC --addr 0x0201B7EC --cc 1.1p1 --thumb
 */
void func_0201B7EC(void *a0, int a1, u16 a2)
{
    if ((u32)((u64)func_0203F0A8() * 2 >> 32) % 2 == 0) {
        func_0201B850(a0, g_0209E465, a1, a2);
    }
}









/*
 * was-blocked: 0209E462.  The `literal` class still refuses it -- the only
 *           pool word in the image holding 0x0209E462 is this function's own,
 *           at 0x0201B84C, inside the compared range.  The site resolves as
 *           `sole-ref` instead, so the entry is EXACT and not MATCH.
 *
 * for (i = 0; i < count(a0); i++) func_0201B850(entry(a0, i), &g_0209E462,
 * a1, a2); - the entry pointer the loop computes is what feeds the second
 * call's first argument, which is why no `r0 = a0` copy appears in front of
 * it (the returned r0 is already the argument), and the bound is
 * re-evaluated at the bottom of the loop so it stays a call in the
 * condition.  The table pointer is this function's own pool word at
 * 0x0201B84C, behind the C0 46 alignment filler at 0x0201B84A.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201B818.c \
 *       --func func_0201B818 --addr 0x0201B818 --cc 1.1p1 --thumb
 */
void func_0201B818(void *a0, int a1, u16 a2)
{
    int i;

    for (i = 0; i < (int)func_0201AA18(a0); i++) {
        func_0201B850(func_0201AB28(a0, i), g_0209E462, a1, a2);
    }
}









/*
 * Applies an EV/stat-like gain to party record id 9, scaled by a per-band
 * table the caller supplies.  The species read (id 0xAB) gates the whole
 * body: species 0 and species 650 both return early.
 *
 * The band index `idx` doubles as the literal zero argument of the three
 * func_02017E1C reads, which is why it is a named u8 initialised before the
 * species call rather than three separate `0` literals; and the two
 * increments must be spelled `idx++` (post-increment), not `idx = idx + 1`,
 * or the compiler proves idx is still 0 at the first band test and folds it
 * to `movs r5, #1`, costing the `adds/lsls/lsrs` triple.
 *
 * The function returns void: an `int` return adds a `movs r0, #0` before the
 * epilogue.
 *
 * VERSION SENSITIVITY: 650 is a species id and 0xAB / 6 / 9 / 0x96 / 0x98 are
 * party-record ids; both are content numbering and should be re-read for a
 * White build.  0x35 is the value func_02020FE4 returns for one particular
 * kind and is content numbering too.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_0201B850.c \
 *       --func sub_0201B850 --addr 0x0201B850 --cc 1.1p1 --thumb
 *   python tools/match.py tu --src src/matched/sub_0201B850.c \
 *       --addr 0x0201B850 --thumb
 */
void sub_0201B850(void *mon, const s8 *tbl, int a2, u16 a3)
{
    int t;
    u32 species;
    u32 kind;
    int cur;
    int n;
    u8 idx;

    t = func_02013E4C(a2);
    idx = 0;
    species = (u16)func_02017E1C(mon, 0xAB, 0);
    if (species == 0 || species == 650) {
        return;
    }
    kind = (u8)func_02020FE4((u16)func_02017E1C(mon, 6, idx), 1, a3);
    cur = func_02017E1C(mon, 9, idx);

    if (cur >= 100) {
        idx++;
    }
    if (cur >= 200) {
        idx++;
    }
    n = tbl[idx];
    if (n > 0) {
        if (func_02017E1C(mon, 0x98, 0) == 11) {
            n = n + 1;
        }
    }
    if (t != 0 && n > 0) {
        if (t == (int)func_02017E1C(mon, 0x96, 0)) {
            n = n + 1;
        }
    }
    if (n > 0 && kind == 0x35) {
        n = n * 150 / 100;
    }
    cur = cur + func_02011014(n);
    if (cur < 0) {
        cur = 0;
    }
    if (cur > 255) {
        cur = 255;
    }
    func_02017E40(mon, 9, cur);
    return;
}









/*
 * A single function, matched as a byte range because the function after it is
 * a near miss and a committed range has to be EXACT end to end.
 *
 * pokeparty.c's "is this move slot short of PP" predicate: 78 bytes, three
 * reads of the party record and one call into the PP table.
 *
 * The three ids it reads are three parallel runs of the record's id space,
 * one per move slot: 0x36 + slot is the move, 0x3A + slot its current PP and
 * 0x3E + slot its PP ups.  src/matched/unit_0201C158.c turns the last two of
 * those into the slot's maximum, and the answer is whether the current PP is
 * below it.
 *
 * It stands alone rather than inside a unit with its neighbours because
 * sub_0201B970, which sits immediately after it, is a documented near miss
 * (docs/notes/sub_0201B970.c.txt) and a range cannot be committed while any
 * part of it is short of EXACT.  Its own single caller, sub_0201B9F0 at
 * 0x0201BA18, is parked in src/pending/unit_0201B9F0.c and resolves this
 * address through the `matched` class off this entry.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x36, 0x3A and 0x3E are party
 * record ids in src/matched/sub_02018DB4.c's space, and the three are written
 * out as three separate literals rather than derived from one base, so a
 * version that inserted a field into that id space would move all three
 * independently.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The function has two epilogues and only the second truncates the result.
 * That is what says the early exit returns the result *variable* while it is
 * still provably zero rather than the literal zero: `return 0;` would be a
 * `movs r0, #0` where the original copies r5, and a shared exit would need the
 * two tests to be one conjunction, which they cannot be because the second one
 * depends on the first's call
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * The result variable is therefore wider than the return type: declared `u8`
 * it needs no truncation at the tail and the function is two bytes short.
 *
 * The third id is built by advancing r7 in place (`adds r7, #0x3e` over the
 * register that held the slot), which is the last use of the slot number and
 * not a separate pointer.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_0201B920.c \
 *       --func sub_0201B920 --addr 0x0201B920 --cc 1.1p1
 */
u8 sub_0201B920(void *mon, u32 slot)
{
    u16 move;
    u8 pp;
    u8 ppUp;
    u32 r;

    r = 0;
    move = (u16)func_02017E1C(mon, slot + 0x36, 0);
    if (move == 0) {
        return r;
    }
    pp = (u8)func_02017E1C(mon, slot + 0x3A, 0);
    ppUp = (u8)func_02017E1C(mon, slot + 0x3E, 0);
    if (pp < func_0201C158(move, ppUp)) {
        r = 1;
    }
    return r;
}









/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`id = slot;` before `id = slot + 0x3A;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * pokeparty.c.  Restore PP to one move slot: read the move (0x36 + slot),
 * its current PP (0x3A + slot) and its PP ups (0x3E + slot), ask
 * sub_0201C158 for the slot's maximum, and if the slot is short either fill
 * it (amount 0x7F) or add `amount` and clamp at the maximum.
 *
 * The last register copy (`adds r2, r4, #0` ahead of func_02017E40, the new
 * PP kept in r4 where the old one lived) is the compound assignment
 * `pp += (u8)amount`: the spelled-out `pp = (u8)(pp + (u8)amount)` starts a
 * new value that coalesces straight into the argument register (wave 15;
 * docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-
 * the-cached-load.md is the same lever on a field).  sub_0201C158 returns a
 * u8, so `max` is u8 (wave 14).  The dead store `id = slot` is the image's
 * `str r0, [sp]` before the add.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201B970.c \
 *       --func sub_0201B970 --addr 0x0201B970 --thumb
 */
u32 sub_0201B970(void *mon, u32 slot, u32 amount)
{
    u16 move;
    u32 id;
    u8  pp;
    u32 ppUp;
    u8  max;

    move = (u16)func_02017E1C(mon, slot + 0x36, 0);
    if (move == 0) {
        return 0;
    }
    id = slot + 0x3A;
    pp = (u8)func_02017E1C(mon, id, 0);
    ppUp = func_02017E1C(mon, slot + 0x3E, 0);
    max = sub_0201C158(move, (u8)ppUp);
    if (pp < max) {
        if (amount == 0x7F) {
            pp = max;
        } else {
            pp += (u8)amount;
            if (pp > max) {
                pp = max;
            }
        }
        func_02017E40(mon, id, pp);
        return 1;
    }
    return 0;
}









/*
 * A whole translation unit, matched as one byte range.
 *
 * pokeparty.c's healer: sub_0201B9F0 restores one Pokemon (current HP to its
 * maximum, status to zero, and every move slot that is short of PP back to
 * full), and sub_0201BA34 runs it over every occupied slot of a party.
 * sub_0201BA34 is the packet's only entry point, reached from 0x02011062.
 *
 * Both of its calls into the neighbouring functions resolve, and the second one
 * is the interesting one.  0x0201B920 is covered by src/matched/
 * unit_0201B920.c, so the `matched` class would carry it on its own;
 * 0x0201B970 is a near miss (docs/notes/sub_0201B970.c.txt) and has no matched
 * entry at all, and the only `bl` to it inside arm9_main is the one in this
 * file.  What attests it is an overlay: ov118 branches to 0x0201B970 at
 * 0x021BE4D0, and to 0x0201B920 at 0x021BDF2A, and those are real instructions
 * outside the compared range, which is exactly what the `label` class asks for
 * once it reads branches from the whole image rather than from arm9 alone.
 * The two functions here would otherwise have had to be split apart or parked.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id.  0x7F is the "fill the slot" sentinel
 * sub_0201B970 tests for and has to stay in step with it; 4 is the move slot
 * count written out as the loop bound; 0xA9, 0xA0, 0xA1 and 0x9D are party
 * record ids in src/matched/sub_02018DB4.c's space.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The id 0xA1 read is used directly as the id 0xA0 write's third argument with
 * nothing bound to a local, so the result reaches r2 straight out of r0; this
 * is the site where the inline spelling is the right one
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 *
 * sub_0201B9F0's `for` runs 0 to 3 with no entry guard, because the compiler
 * can see the bound; the 0x7F is hoisted into r6 in front of the loop and the
 * index's zero is set before the two writes that precede it.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0201B9F0.c \
 *       --addr 0x0201B9F0 --thumb
 */
void sub_0201B9F0(void *mon)
{
    s32 i;

    func_02017E40(mon, 0xA0, func_02017E1C(mon, 0xA1, 0));
    func_02017E40(mon, 0x9D, 0);
    for (i = 0; i < 4; i++) {
        if (sub_0201B920(mon, i) == 1) {
            sub_0201B970(mon, i, 0x7F);
        }
    }
}









void sub_0201BA34(void *party)
{
    s32 n;
    s32 i;
    void *mon;

    n = sub_0201AA18(party);
    for (i = 0; i < n; i++) {
        mon = sub_0201AB28(party, i);
        if (func_02017E1C(mon, 0xA9, 0) != 0) {
            sub_0201B9F0(mon);
        }
    }
}









/*
 * A whole translation unit, matched as one byte range.
 *
 * The graphics index of a Pokemon: sub_0201BA68 unpacks the four values that
 * decide it out of the record and sub_0201BABC turns them into a member number
 * of archive 7.  The pair that follows them, sub_0201BB5C and sub_0201BBE8, is
 * the same index arithmetic over a different table and is parked in
 * src/pending/unit_0201BB5C.c because that table has no witness; the cut
 * between the two pairs is what lets this half land
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * sub_0201BA68 brackets its four reads with func_02017DBC and func_02017DE4,
 * which is the pair the region uses around a run of raw field reads; that is
 * why the reads here are func_02017E88 and not the func_02017E1C of
 * src/matched/sub_02018A7C.c.  The fourth read is written inline as the call's
 * fourth argument rather than bound to a local, which is what puts it in r3
 * with the other three already in place.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Four content constants, and the index arithmetic that ties them together is
 * itself a statement about how the sprite archive is packed:
 *
 *   490    the species whose egg has a graphic of its own.  Every other
 *          species shares one egg graphic.
 *   650    the index the ordinary egg occupies, so 651 is that species' egg;
 *          the same 650/651 pair src/matched/unit_0201AFD4.c rejects as
 *          species ids.
 *   7      the first member of archive 7 that belongs to a species, and the
 *          stride is two members per index.
 *   1311   the member the alternate forms start at, which is 652 * 2 + 7, i.e.
 *          immediately after the two egg indices.  A White build with a
 *          different species count would move this number and only this one.
 *   0x1F, 0x20, 0x23   the three personal-record attributes func_02019C90
 *          answers: the form block's first index, the form count, and the flag
 *          that says the forms are not drawn separately.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The `case 1` arm binds the archive query to a local before assigning the
 * gender.  Written inline, `gender = 1;` is hoisted in front of the `blx` and
 * six bytes come out in the wrong order; the named local is what pins the
 * order, the same way
 * docs/idioms/cmp-operand-order-names-the-temporary.md pins a comparison.
 *
 * `case 2`'s `gender = 0;` and `case 1`'s failure arm are one block, reached
 * by a `b` whose displacement is zero: the source writes the statement out in
 * both arms and the compiler cross-jumps the two copies
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).  The switch
 * is a `cmp`/`beq` chain rather than a table, because three labels are too few
 * for mwccarm to build one
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md, the other side of
 * the density rule).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201BA68.c \
 *       --addr 0x0201BA68 --thumb
 */
u32 sub_0201BA68(void *mon)
{
    u32 save;
    u32 species;
    u32 form;
    u32 gender;
    u32 r;

    save = func_02017DBC(mon);
    species = func_02017E88(mon, 5, 0);
    form = func_02017E88(mon, 0x6F, 0);
    gender = func_02017E88(mon, 0x6E, 0);
    r = sub_0201BABC(species, form, gender, func_02017E88(mon, 0x4C, 0));
    func_02017DE4(mon, save);
    return r;
}









u32 sub_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg)
{
    u32 first;
    u32 hidden;
    u32 count;
    u32 idx;
    u32 ok;

    idx = species * 2 + 7;
    if (isEgg != 0) {
        idx = (u32)((species == 490 ? 1 : 0) + 650) * 2 + 7;
    } else if (form != 0) {
        first = func_02019C90((u16)species, 0, 0x1F);
        hidden = func_02019C90((u16)species, 0, 0x23);
        count = func_02019C90((u16)species, 0, 0x20);
        if (form >= count) {
            form = 0;
        }
        if (hidden == 0 && form != 0) {
            idx = (first + form - 1) * 2 + 1311;
        }
    }
    switch (gender) {
    case 0:
        break;
    case 1:
        ok = func_020490A8(7, idx + 1);
        gender = 1;
        if (ok == 0) {
            gender = 0;
        }
        break;
    case 2:
        gender = 0;
        break;
    }
    return idx + gender;
}









/*
 * note:     224 bytes, two functions
 *
 * The nibble-table twin of src/matched/unit_0201BA68.c: the same egg and
 * alternate-form index arithmetic, indexing a packed table of two four bit
 * values per entry instead of an archive.  sub_0201BBE8 unpacks the four
 * inputs out of a Pokemon record, bracketed by the func_02017DBC /
 * func_02017DE4 pair, and hands them over.
 *
 * The index is the same logical number unit_0201BA68.c computes, one step
 * short of it: there the answer is `n * 2 + 7`, a member of archive 7, here it
 * is `n` itself, and the alternate-form case reaches it as `first + form +
 * 651` where the other reaches `(first + form - 1) * 2 + 1311`.  1311 is
 * 652 * 2 + 7, so the two agree.
 *
 * ---------------------------------------------------------------------------
 * WHY IT WAS CAPPED (HISTORY)
 * ---------------------------------------------------------------------------
 * NO LONGER CAPPED (re-verified 2026-09-22).  The pool word at 0x0201BBE4 is
 * still the only word in the image that holds 0x0209E474, so the `literal`
 * class does discard its only witness.  What closed it is the sole-ref
 * widening of 2026-09-21: 0x0209E474 is 4-aligned and starts a recognised
 * data object, so the site now resolves as `sole-ref` and the unit is EXACT.
 * The old "WHY IT IS CAPPED" reading below is kept only as history.
 *
 * The cut between this pair and sub_0201BA68/sub_0201BABC is what let those
 * two land EXACT.  sub_0201BB5C is reached only from 0x0201BC34, inside this
 * range, so that call is the `local` class and needs no evidence.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   490    the species whose egg has an entry of its own.
 *   650    the ordinary egg's index, so 651 is that species' egg; 651 again is
 *          the base the alternate-form block is counted from.
 *   0x1F, 0x20, 0x23   the three personal-record attributes func_02019C90
 *          answers: the form block's first index, the form count, and the
 *          "not drawn separately" flag.
 *   0x0209E474  the table itself, one packed byte per index.  Its contents are
 *          content and are not reproduced here.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The two returns are unequal shift pairs, not bitfields: `lsls #0x14` /
 * `lsrs #0x18` is `(u8)(x >> 4)`, because 32 - 24 is the width and 20 - 24 is
 * the shift, and the low half's equal pair is a plain `(u8)`
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * The mask has to be written out as well as the cast; `x >> 4` on its own
 * loses the `ands`.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_0201BB5C.c \
 *       --addr 0x0201BB5C --thumb
 */
u32 sub_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg)
{
    u32 first;
    u32 hidden;
    u32 count;
    u32 idx;

    idx = species;
    if (isEgg != 0) {
        idx = (species == 490 ? 1 : 0) + 650;
    } else if (form != 0) {
        first = func_02019C90((u16)species, 0, 0x1F);
        hidden = func_02019C90((u16)species, 0, 0x23);
        count = func_02019C90((u16)species, 0, 0x20);
        if (form >= count) {
            form = 0;
        }
        if (hidden == 0 && form != 0) {
            idx = first + form + 651;
        }
    }
    if (half != 0) {
        return (u8)((g_0209E474[idx] & 0xF0) >> 4);
    }
    return (u8)(g_0209E474[idx] & 0xF);
}









u32 sub_0201BBE8(void *mon)
{
    u32 save;
    u32 species;
    u32 form;
    u32 gender;
    u32 isEgg;

    save = func_02017DBC(mon);
    species = func_02017E88(mon, 5, 0);
    form = func_02017E88(mon, 0x6F, 0);
    gender = func_02017E88(mon, 0x6E, 0);
    isEgg = func_02017E88(mon, 0x4C, 0);
    func_02017DE4(mon, save);
    return sub_0201BB5C(species, form, gender, isEgg);
}









/*
 *           func_0201BCEC
 *
 * Five leaves after func_0201BBE8.  The first returns 0.  The other four read
 * the OBJ character mapping bits of DISPCNT (bit 4, 1D mapping, and bits
 * 20..21, the 1D boundary) for the main engine (0x04000000) or the sub engine
 * (0x04001000) and turn the 32/64/128 KB boundary into a shift: 2/4/6 and
 * 1/3/5, with the unlisted 256 KB case falling into a separate default that
 * repeats the last value.  Seeded from ov208 0x021C5304, 0x021C531E,
 * 0x021C5324 (func_021C52F0) and ov021 0x021CC8EA, 0x021CC906, 0x021CC90C.
 *
 * Addresses are Black-image addresses.
 */
int func_0201BC3C(void)
{
    return 0;
}









int func_0201BC40(void)
{
    switch (REG_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 2;
    case 0x100010: return 4;
    case 0x200010: return 6;
    default:       return 6;
    }
}









int func_0201BC78(void)
{
    switch (REG_DB_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 2;
    case 0x100010: return 4;
    case 0x200010: return 6;
    default:       return 6;
    }
}









int func_0201BCB4(void)
{
    switch (REG_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 1;
    case 0x100010: return 3;
    case 0x200010: return 5;
    default:       return 5;
    }
}









int func_0201BCEC(void)
{
    switch (REG_DB_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 1;
    case 0x100010: return 3;
    case 0x200010: return 5;
    default:       return 5;
    }
}









/*
 * waza_tool.c: the cached single-field read of a move record, and the 32 case
 * getter it ends in.
 *
 * sub_0201BD28 finds the move's record in the cache the constructor in
 * src/matched/unit_0201C328.c builds, loading it through func_02048F4C if the
 * slot it picks is empty or is holding a different move, and falls back to
 * the single record buffer at 0x02146534 when the cache has not been built.
 * The slot search, the "cache full, reuse the last slot" fixup and the load
 * are the same three blocks sub_0201C1F4 and sub_0201C020 repeat for their
 * own records.
 *
 * sub_0201BDB4 has to stay in this file.  The `bl` at 0x0201BDA6 is the only
 * branch to it anywhere in the image, so split off it would have no witness
 * at all; kept here the site is the `local` class and needs none
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md, read the
 * other way round).
 *
 * The getter is an ordinary dense switch: `cmp #0x1F` / `bhi` and a table of
 * 32 signed halfword displacements
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md).  Two things
 * the table says that the C has to repeat exactly:
 *
 *   * entry 29 points at the default body, so id 29 has no case label at all.
 *     It is a gap in the middle of the range and not an empty arm, which is
 *     the distinction docs/idioms/empty-switch-arms-are-what-make-the-table.md
 *     draws;
 *   * the arms are emitted in source order, and that order is not the numeric
 *     order: id 28 is written between 15 and 16, and the three three-way
 *     groups (16, 19, 22), (17, 20, 23) and (18, 21, 24) share one body each.
 *
 * The three grouped bodies index byte arrays at +0x15, +0x18 and +0x1B with a
 * run-time index, so the middle one costs a `movs`/`ldrsb` register-offset
 * pair rather than an immediate load, which is the only thing that says that
 * field is signed (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Ids 4 and 7 answer a substitute value for one particular stored value,
 * 0x64 for 0x65 and 0 for 6; both reach the function's shared `bx lr` with
 * the loaded value still in r0, which is what says the source returns the
 * value in the ordinary path rather than assigning a result variable.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201BD28.c \
 *       --addr 0x0201BD28 --thumb
 */
u32 sub_0201BD28(u16 id, u32 field)
{
    struct Waza *rec;
    s32 i;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (gWazaTool->vals[i] == 0) {
                gWazaTool->vals[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == gWazaTool->vals[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            gWazaTool->vals[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    return sub_0201BDB4(rec, field);
}









u32 sub_0201BDB4(const struct Waza *p, u32 id)
{
    u32 v;

    switch (id) {
    case 0:  return p->unk00;
    case 1:  return p->unk01;
    case 2:  return p->unk02;
    case 3:  return p->unk03;
    case 4:
        v = p->unk04;
        if (v == 0x65) {
            return 0x64;
        }
        return v;
    case 5:  return p->unk05;
    case 6:  return p->unk06;
    case 7:
        v = p->unk0E;
        if (v == 6) {
            return 0;
        }
        return v;
    case 8:  return p->hi;
    case 9:  return p->lo;
    case 10: return p->unk0F;
    case 11: return p->unk08;
    case 12: return p->unk0A;
    case 13: return p->unk0B;
    case 14: return p->unk0C;
    case 15: return p->unk0D;
    case 28: return p->unk10;
    case 16: case 19: case 22:
        return p->unk15[id - 16];
    case 17: case 20: case 23:
        return p->unk18[id - 17];
    case 18: case 21: case 24:
        return p->unk1B[id - 18];
    case 25:
        if (p->unk12 > 0) {
            return p->unk12;
        }
        return 0;
    case 30:
        if (p->unk12 < 0) {
            return -p->unk12;
        }
        return 0;
    case 26:
        if (p->unk13 > 0) {
            return p->unk13;
        }
        return 0;
    case 31:
        if (p->unk13 < 0) {
            return -p->unk13;
        }
        return 0;
    case 27: return p->unk14;
    }
    return 0;
}







u32 sub_0201BEB8(u16 id, u32 bit)
{
    struct Waza *rec;
    s32 i;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (gWazaTool->vals[i] == 0) {
                gWazaTool->vals[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == gWazaTool->vals[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            gWazaTool->vals[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    return sub_0201BF44(rec, bit);
}







u32 sub_0201BF44(const struct Waza *p, u32 bit)
{
    u32 r = 1;

    if ((p->unk20 & (1 << bit)) != 0) {
        return r;
    }
    r = 0;
    return r;
}







s16 sub_0201BF58(u16 id)
{
    struct Waza *rec;
    s32 i;
    union Packed u;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (gWazaTool->vals[i] == 0) {
                gWazaTool->vals[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == gWazaTool->vals[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            gWazaTool->vals[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    if (rec->unk0B != 0) {
        u.f.a = rec->unk0B;
        u.f.b = rec->unk0C;
        u.f.c = rec->unk0D;
    }
    return u.v;
}







/*
 * waza_tool.c: two more readers over a move record, each with its own copy of
 * the cache lookup src/matched/unit_0201BD28.c and
 * src/matched/unit_0201C1F4.c also carry.  sub_0201C020 counts how many of
 * the three bytes at +0x15 are set; sub_0201C0BC hands one of the three
 * signed bytes at +0x18 back through an out-parameter, or zero when the
 * matching +0x15 byte is clear.
 *
 * The +0x18 read is a `movs`/`ldrsb` register-offset pair because the index
 * is a run-time value and Thumb has no immediate-offset `ldrsb`, which is
 * also the only evidence that the field is signed where its +0x15 neighbour
 * is not (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C020.c  *       --addr 0x0201C020 --thumb
 */
u8 sub_0201C020(u16 id)
{
    struct Waza *rec;
    s32 i;
    u32 k;
    u32 n;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (gWazaTool->vals[i] == 0) {
                gWazaTool->vals[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == gWazaTool->vals[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            gWazaTool->vals[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    n = 0;
    for (k = 0; k < 3; k++) {
        if (rec->unk15[k] != 0) {
            n++;
        }
    }
    return (u8)n;
}







u8 sub_0201C0BC(u16 id, u32 idx, s32 *out)
{
    struct Waza *rec;
    s32 i;
    u8 v;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (gWazaTool->vals[i] == 0) {
                gWazaTool->vals[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == gWazaTool->vals[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            gWazaTool->vals[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    v = rec->unk15[idx];
    if (v != 0) {
        *out = rec->unk18[idx];
    } else {
        *out = 0;
    }
    return v;
}







/*
 * waza_tool.c: the effective PP calculation, a four-entry id translation and
 * one more named field read.
 *
 * sub_0201C158 is the function src/pending/sub_02018E34.c's field map calls
 * for ids 0x42 to 0x45: base PP (field 5 of the move record, through
 * src/matched/unit_0201BD28.c) plus base * 20 * ppUp / 100, with ppUp clamped
 * to 3 and every intermediate truncated to u8.  The two `muls` are one
 * expression and their order is the source's: the clamped count multiplies
 * the already-scaled base, not the other way round
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md).
 *
 * The clamp compares unsigned (`bls`) while the division calls _s32_div_f,
 * so the count is an unsigned parameter and the product is cast to `int`
 * before the divide; written unsigned throughout, every concrete byte is
 * still right and the call goes to _u32_div_f instead, which is a different
 * address and a DIFF.
 *
 * sub_0201C184 is a sparse four-case switch, which this front end lowers as a
 * binary search rather than a table: `> 0xF1`, then `< 0xF0`, then the two
 * equality tests.  The bodies are still emitted in source order, so the arms
 * are written 0xF0, 0xF1, 0xC9, 0x102 even though the comparisons are in
 * value order, and the value is signed: the two range tests are `bgt`/`blt`,
 * so the parameter is `int` and not `u32`.  0x102 arrives from a pool word because it is past the 255 a
 * `movs` immediate reaches.
 *
 * VERSION SENSITIVITY: 0xF0, 0xF1, 0xC9 and 0x102 are content ids (moves or
 * items), not offsets.  They are expected to be the same in Pokemon White,
 * which shares Black's numbering, but they are the constants to re-read first
 * if a White build diverges here.
 *
 * sub_0201C1BC is an unlabelled tail call, three instructions and two pool
 * words (docs/idioms/tail-call-is-a-pool-word-and-bx.md), reading field 1.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C158.c \
 *       --addr 0x0201C158 --thumb
 */
u8 sub_0201C158(u16 move, u32 ppUp)
{
    u8 base;

    if (ppUp > 3) {
        ppUp = 3;
    }
    base = (u8)sub_0201BD28(move, 5);
    return (u8)(base + (u8)((int)(ppUp * (base * 20)) / 100));
}







u32 sub_0201C184(int id)
{
    switch (id) {
    case 0xF0:  return 2;
    case 0xF1:  return 1;
    case 0xC9:  return 4;
    case 0x102: return 3;
    }
    return 0;
}







u32 sub_0201C1BC(u16 move)
{
    return sub_0201BD28(move, 1);
}






/*
 * A whole translation unit, matched as one byte range.
 *
 * Two truncating wrappers around sub_0201BD28 (0x0201BD28, still open, a
 * getter dispatched by a small id constant), one narrowing the result to a
 * byte for id 0, the other to a halfword for id 3.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C1C8.c \
 *       --addr 0x0201C1C8 --thumb
 */
u8 sub_0201C1C8(u16 p)
{
    return (u8)sub_0201BD28(p, 0);
}






u16 sub_0201C1D8(u16 p)
{
    return (u16)sub_0201BD28(p, 3);
}






/*
 * Tail call with argument 2. Filed as the witness for ov094 func_021F7C2C.
 */
int func_0201C1E8(int a)
{
    return func_0201BD28(a, 2);
}






/*
 * waza_tool.c: two predicates over a move record, "is field 4 equal to 0x65"
 * and "is field 0x0E equal to 6", which are the same two special values
 * src/matched/unit_0201BD28.c's getter substitutes for at ids 4 and 7.
 *
 * Both carry their own copy of that file's cache lookup rather than calling
 * it: the slot search, the "cache full, reuse the last slot" fixup, the
 * func_02048F4C load and the not-yet-built fallback to 0x02146534 are written
 * out again in each.  The duplication is in the source, not an inlining
 * decision: sub_0201BD28 is a real function with eight callers, and the
 * bodies here reach the record directly instead of going through its
 * 32 case getter.
 *
 * VERSION SENSITIVITY: 0x65 and 6 are content ids of the move table, not
 * offsets.  They are expected to be identical in Pokemon White but are the
 * constants to re-read first if a White build diverges.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C1F4.c \
 *       --addr 0x0201C1F4 --thumb
 */
u32 sub_0201C1F4(u16 id)
{
    struct Waza *rec;
    s32 i;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (gWazaTool->vals[i] == 0) {
                gWazaTool->vals[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == gWazaTool->vals[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            gWazaTool->vals[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    if (rec->unk04 == 0x65) {
        return 1;
    }
    return 0;
}






u32 sub_0201C284(u16 id)
{
    struct Waza *rec;
    s32 i;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (gWazaTool->vals[i] == 0) {
                gWazaTool->vals[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == gWazaTool->vals[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            gWazaTool->vals[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    if (rec->unk0E == 6) {
        return 1;
    }
    return 0;
}





/*
 * A boolean wrapper around sub_0201BD28 (see src/matched/unit_0201C1C8.c),
 * id 3 again, this time reduced to 0/1 rather than truncated to a halfword.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C314.c \
 *       --addr 0x0201C314 --thumb
 */
u32 sub_0201C314(u16 p)
{
    if (sub_0201BD28(p, 3) == 0) {
        return 0;
    }
    return 1;
}





/*
 * waza_tool.c: the module's constructor, its destructor, its "is it up"
 * predicate, and (folded back in this run) sub_0201C41C, which resets
 * something with 0xFFFF and hands func_02043678's result to the static at
 * 0x02146558.  sub_0201C41C used to be cut out into src/pending/sub_0201C41C.c
 * because its one call, to func_020457A0, had no witness anywhere in the
 * image; func_020457A0 is now EXACT in src/matched/sub_020457A0.c, giving the
 * `matched` class a witness, so the range folds back into one unit.  The file
 * name is the image's own, 0x020A7340 spelling "waza_tool.c" between
 * "shinka_check.c" and "printsys.c".
 *
 * The module object at 0x02146530 is three words: an array of `n` pointers to
 * 0x24 byte records, an array of `n` halfwords, and `n` itself.  Each of the
 * four allocations passes a different __LINE__, and the four values 577, 578,
 * 579 and 584 are visible in the bytes as one pool word holding 577 and three
 * `adds r0, r0, #k` off it, which is what fixes both the line numbers and the
 * order of the statements.  577 is too large for a `movs` immediate, so the
 * first one is a pool word rather than a relocation
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md is the
 * case where it is the other way round).
 *
 * sub_0201C408 is an unlabelled follower: eight halfwords with no prologue
 * sitting between two literal pools, which the listing prints as `.word` data
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Its `!= 0`
 * arm is the fall-through, so the source returns 1 first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C328.c \
 *       --addr 0x0201C328 --thumb
 */
void sub_0201C328(s32 n, u32 heap)
{
    s32 i;

    if (gWazaTool != 0) {
        return;
    }
    gWazaTool = (struct WazaTool *)func_02030734(heap, sizeof(struct WazaTool), 0,
                                                sub_0201C328_File, 577);
    gWazaTool->recs = (struct Waza **)func_02030734(heap, n * sizeof(void *), 0,
                                             sub_0201C328_File, 578);
    gWazaTool->vals = (u16 *)func_02030734(heap, n * sizeof(u16), 0,
                                           sub_0201C328_File, 579);
    gWazaTool->count = n;
    for (i = 0; i < n; i++) {
        gWazaTool->recs[i] = func_02030734(heap, 0x24, 0, sub_0201C328_File, 584);
        gWazaTool->vals[i] = 0;
    }
}





void sub_0201C3C0(void)
{
    s32 i;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            func_020307B0(gWazaTool->recs[i]);
        }
        func_020307B0(gWazaTool->vals);
        func_020307B0(gWazaTool->recs);
        func_020307B0(gWazaTool);
        gWazaTool = 0;
    }
}





u32 sub_0201C408(void)
{
    if (gWazaTool != 0) {
        return 1;
    }
    return 0;
}





void sub_0201C41C(void *arg)
{
    func_020457A0(0xFFFF);
    g_02146558 = func_02043678(2, 2, 0x20, (u32)arg);
}





/*
 * A 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), swapping its own
 * parameter into the callee's second argument slot and passing the literal
 * 0x400 as the first: `sub_0201C450(0x400, p)`.  sub_0201C450 (0x0201C450)
 * is a bigger constructor with an inline division-by-multiplication trick
 * and is left as an unresolved extern; only its address is needed here.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C440.c \
 *       --addr 0x0201C440 --thumb
 */
u32 sub_0201C440(void *p)
{
    return (u32)sub_0201C450(0x400, (u32)p);
}





/*
 * The head of printsys.c: the module constructor and three accessors on the
 * object it builds.  The file identity is in the image, the same way
 * src/matched/unit_0201D69C.c recovers gf_font.c: the constructor loads
 * 0x020A734C as the debug allocator's __FILE__ argument and the bytes there
 * spell "printsys.c", with "waza_tool.c" ending at 0x020A734B so the `string`
 * class carries the address.  The __LINE__ argument is 287.
 *
 * The constructor was a documented two-byte near miss and this is what closed
 * it: the field at +8 is one `u64`, not two `u32`.  Written as two words the
 * whole function is right except that the pool constant 0x1130 arrives in r1
 * instead of r2; assigning it to a 64 bit field makes the compiler take the
 * other scratch register, because the high half comes from the register that
 * already holds zero.  See
 * docs/idioms/a-u64-field-store-picks-a-different-scratch-register.md.
 *
 * sub_0201C4DC writes the two halves of that u64 separately, which is what
 * fixes the field as a union of the 64 bit value and a two-word struct rather
 * than a plain `u64` (docs/idioms/long-long-aligns-to-four.md is why +8 is a
 * legal offset for it at all).
 *
 * The size the constructor allocates is (u16)(n + 0x1C) rounded up to a
 * multiple of four and then + 0x18, and the rounding is a `while (v % 4)` loop
 * over a `u16` local: the signed `lsrs #31` / `lsls #30` / `subs` / `rors #30`
 * quartet is `% 4` on the promoted int, exactly as src/matched/sub_0200A6BC.c
 * records for `% 8`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C450.c \
 *       --addr 0x0201C450 --thumb
 */
void *sub_0201C450(u16 n, u32 heap)
{
    u16 v = n + 0x1C;
    struct PrintSys_0201C450 *p;

    while (v % 4 != 0) {
        v++;
    }
    p = func_02030734(heap, v + 0x18, 0, sub_0201C450_File, 287);
    p->unk04 = n;
    p->unk08.v = 0x1130;
    p->unk10 = 0;
    p->unk14 = 0;
    ((u8 *)p)[7] = ((u8 *)p)[7] & ~0xFu;
    ((u8 *)p)[7] = ((u8 *)p)[7] & ~0xF0u;
    p->unk06 = 0;
    p->unk00 = 0;
    p->unk02 = n;
    return p;
}





void sub_0201C4C0(struct PrintSys_0201C450 *p)
{
    func_020307B0(p);
}




void sub_0201C4C8(struct PrintSys_0201C450 *p, u32 v)
{
    ((u8 *)p)[7] = (((u8 *)p)[7] & ~0xF0u) | (u8)((u8)v << 4);
}




void sub_0201C4DC(struct PrintSys_0201C450 *p, u32 lo, u32 hi)
{
    p->unk08.w.lo = lo;
    p->unk08.w.hi = hi;
}





static inline u16 Wrap(struct PrintSys_0201C4E4 *ps, u16 o)
{
    u16 r = o;

    if (r >= ps->unk04)
        r = 0;
    return r;
}




/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = (u8 *)ps;` before `base = (u8 *)ps + 0x18;`). Game code has no
 * line table, so these were stand-ins. The plain single assignment gives
 * EXACT in --lang c99 and --lang c: the output bytes do not change. Older
 * text in this header that asks for the double assignment is superseded.
 *
 * printsys.c: the per-frame print pump.  Bumps the frame counter at +6,
 * saves the current text colour, applies the head request's colour when its
 * 4-bit kind is 0 or 2, then runs glyphs through func_0201C974 until the
 * string ends or the tick budget at +8 (func_020870D0 is OS_GetTick) runs
 * out.  On string end it pops the request (func_0201D7C4) and moves the
 * glyph cursor to the next record's text in the byte ring at +0x18,
 * wrapping twice at the ring size.  Restores the colour and reports idle.
 *
 * The last five bytes closed on the SHAPE OF THE INLINE WRAP HELPER: it
 * copies its parameter into a named local, conditionally zeroes the local
 * and returns it (`u16 r = o; if (r >= size) r = 0; return r;`).  The
 * early-return spelling (`if (o >= size) return 0; return o;`) truncates
 * `off + 0x1C` in place and hoists the ring-size load between the two
 * shifts; the named-local spelling keeps the image's
 * `lsls r0, r7 / lsrs r1, r0 / ldrh r0, [r5, #4]` order.  History in
 * docs/notes/sub_0201C4E4.c.txt.
 */
u32 func_0201C4E4(struct PrintSys_0201C4E4 *ps)
{
    u16 cap;
    u8  col[3];
    u32 stop;
    u16 saved;
    u32 rr;
    u32 bb;
    u8 *base;
    u32 r;
    u32 g;
    u32 b;
    u32 go;
    u32 gg;
    u32 off;
    u16 o;
    u64 t0;

    stop = 0;
    ps->unk06 = (u8)(ps->unk06 + 1);
    if (ps->unk10 == 0) {
        return 1;
    }
    func_0201DE00(&col[2], &col[1], &col[0]);
    saved = (u16)(((col[2] & 0x1F) << 10) | ((col[1] & 0x1F) << 5) |
                  (col[0] & 0x1F));
    go = 0;
    if (ps->unk10->kind == 0 || ps->unk10->kind == 2) {
        r = (u8)((ps->unk10->unk0E >> 10) & 0x1F);
        g = (u8)((ps->unk10->unk0E >> 5) & 0x1F);
        b = (u8)(ps->unk10->unk0E & 0x1F);
        go = 1;
    }
    if (go != 0) {
        if (func_0201DE18(r, g, b) != 0) {
            func_0201DD78(r, g, b);
        }
    }
    t0 = func_020870D0();
    if (ps->unk10 != 0) {
        base = (u8 *)ps + 0x18;
        do {
            if (ps->unk10->kind == 1) {
                rr = (u8)((ps->unk10->unk0E >> 10) & 0x1F);
                gg = (u8)((ps->unk10->unk0E >> 5) & 0x1F);
                bb = (u8)(ps->unk10->unk0E & 0x1F);
                if (func_0201DE18(rr, gg, bb) != 0) {
                    func_0201DD78(rr, gg, bb);
                }
                ps->unk10->kind = 2;
            }
            while (ps->unk14[0] != 0xFFFF) {
                ps->unk14 = func_0201C974((struct PrintCtx *)ps->unk10, ps->unk14, 1);
                if (func_020870D0() - t0 > ps->unk08) {
                    stop = 1;
                    break;
                }
            }
            if (ps->unk14[0] == 0xFFFF) {
                off = (u16)((u8 *)ps->unk10 - base);
                ps->unk10 = func_0201D7C4(ps, ps->unk10);
                if (ps->unk10 != 0) {
                    o = Wrap(ps, off + 0x1C);
                    o = Wrap(ps, o + 4);
                    ps->unk14 = (u16 *)((u8 *)ps + 0x18 + o);
                }
            }
        } while (stop == 0 && ps->unk10 != 0);
    }
    func_0201DD78((u8)((saved >> 10) & 0x1F), (u8)((saved >> 5) & 0x1F),
                  (u8)(saved & 0x1F));
    if (ps->unk10 != 0) {
        ps->unk02 = (u16)((u8 *)ps->unk14 - ((u8 *)ps + 0x18));
        return 0;
    }
    ps->unk00 = 0;
    ps->unk02 = ps->unk04;
    ps->unk07lo = 0;
    return 1;
}
