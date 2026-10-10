/*
 * file:     fld_trade_p01.c
 * unit:     yes
 * function: func_021CBFB0, func_021CC040, func_021CC060, func_021CC068, func_021CC070, func_021CC098, func_021CC23C, func_021CC38C, func_021CC390, func_021CC500, func_021CC544, func_021CC570, func_021CC5D8, func_021CC614, func_021CC6A8, func_021CC6FC, func_021CC720, func_021CC7B4, func_021CC810, func_021CC8B0, func_021CC8DC, func_021CC9A4, func_021CCA00, func_021CCB98, func_021CCBE0, func_021CCC50, func_021CCCC4, func_021CCCE4, func_021CCDF8, func_021CCE48, func_021CCEB8, func_021CCEE4, func_021CCEFC, func_021CCF48, func_021CCF54, func_021CCF60, func_021CCF7C, func_021CCFC0, func_021CCFD8, func_021CCFE4, func_021CCFF8, func_021CD004, func_021CD038
 * address:  0x021CBFB0
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
 *   func_02030734  0x02030734  arm
 *   func_02048F88  0x02048F88  arm
 *   func_0200846C  0x0200846C  thumb
 *   func_020084A0  0x020084A0  thumb
 *   func_02045A38  0x02045A38  arm
 *   func_02045808  0x02045808  arm
 *   func_020084D4  0x020084D4  thumb
 *   func_0200854C  0x0200854C  thumb
 *   d_021DE59C  0x021DE59C  data  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201862C  0x0201862C  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0202F190  0x0202F190  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020146F8  0x020146F8  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0201AB48  0x0201AB48  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0201B2B0  0x0201B2B0  thumb
 *   ov119_id       0x00000077  data  a1
 *   ov195_id       0x000000C3  data  a1
 *   d_021E75A8     0x021E75A8  data  a4
 *   d_02208C40     0x02208C40  data  ov195  a4
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0216C204  0x0216C204  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02014840  0x02014840  thumb
 *   d_021DE5A8     0x021DE5A8  data
 *   ov107_id       0x0000006B  data
 *   d_021F6D78     0x021F6D78  data  ov107
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C1A4  0x0200C1A4  thumb
 *   func_0200C184  0x0200C184  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0216530C  0x0216530C  thumb  ov010
 *   func_02165534  0x02165534  thumb  ov010
 *   func_021653C4  0x021653C4  thumb  ov010
 *   func_021656A0  0x021656A0  thumb  ov010
 *   func_021656D0  0x021656D0  thumb  ov010
 *   func_0216573C  0x0216573C  thumb  ov010
 *   func_02165604  0x02165604  thumb  ov010
 *   func_02165634  0x02165634  thumb  ov010
 *   func_0216566C  0x0216566C  thumb  ov010
 *   func_02010F18  0x02010F18  thumb
 *   func_02010F7C  0x02010F7C  thumb
 *   func_02010F40  0x02010F40  thumb
 *   func_02010F8C  0x02010F8C  thumb
 *   func_021F5340  0x021F5340  thumb  ov083
 *   func_02034714  0x02034714  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   d_021DE5BC  0x021DE5BC  data  a1
 *   d_021DE5C0  0x021DE5C0  data  ov021
 *   func_0201D83C  0x0201D83C  thumb
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_021CD1AC  0x021CD1AC  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021DB404     0x021DB404  data  a2
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_02027694  0x02027694  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0202769C  0x0202769C  thumb
 *   func_020276A0  0x020276A0  thumb
 *   func_02027698  0x02027698  thumb
 *   d_021DB40C  0x021DB40C  data
 *   func_0202136C  0x0202136C  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_02190A28  0x02190A28  thumb  ov021
 *   func_02190938  0x02190938  thumb  ov021
 *   d_021DB414     0x021DB414  data  a4
 *   d_021DB42C     0x021DB42C  data  ov021  a4
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_021909E4  0x021909E4  thumb  ov021
 *   func_02020D0C  0x02020D0C  thumb
 *   func_021CD184  0x021CD184  thumb  ov021
 *   func_02020298  0x02020298  thumb
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_02190E74  0x02190E74  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_02190708  0x02190708  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 */
#include "../../matched/include/Obj20247.h"
#include "../../matched/include/Obj20248.h"
#include "../../matched/include/Obj01219.h"
#include "../../matched/include/Obj18350.h"
#include "../../matched/include/Obj18351.h"
#include "../../matched/include/Obj06097.h"
#include "../../matched/include/Obj09731.h"
#include "../../matched/include/Obj04293.h"
#include "../../matched/include/Obj09732.h"
#include "../../matched/include/Obj07588.h"
#include "../../matched/include/Obj18357.h"
#include "../../matched/include/Obj18358.h"
#include "../../matched/include/Obj18359.h"
#include "../../matched/include/Obj18361.h"

struct U16Vec;
struct Sub0200852CObj;
struct MsgBank;
struct Rec;
struct Mon;
struct Personal;
struct BigObj;
struct Blk37;
struct Ctx;
struct Evt;
struct Party;
struct PartyMon;
struct Desc;
struct Obj_021CC390;
struct Big;
struct Blk34;
struct Bank;
struct GfFont;
struct Obj_021CCA00;
struct WordSet;
struct Handle;
struct Pair;
struct Fx;
struct Obj2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Obj_021CC390 {
    u16 f0;
    u8 pad2[2];
    u32 f4;
    void *f8;
    void *fC;
    void *f10;
} Obj_021CC390;

typedef unsigned long long u64;

typedef struct {
    u32 f00;
    u32 species;    /* 0x04 */
    u32 level;      /* 0x08 */
    u32 f0C;
    u32 f10[6];     /* 0x10..0x24: fields 0x46..0x4b */
    u32 sel;        /* 0x28 */
    u32 f2C;
    u32 f30;
    u32 id;         /* 0x34 */
    u32 f38[5];     /* 0x38..0x48: fields 0x13..0x17 */
    u32 f4C;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5C;
    u32 f60;
    u32 f64;
    u32 f68;
} Spec;

typedef struct {
    void *sys;      /* 0x00 */
    void *f4;       /* 0x04 */
    void *f8;       /* 0x08 */
    u8 fC;          /* 0x0C */
    u8 fD;          /* 0x0D */
    u8 padE[2];
    Obj_021CC390 *obj;       /* 0x10 */
    u8 f14[0x30];   /* 0x14 */
    void *f44;
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
} Work_021CC23C;

typedef struct {
    void *a;
    void *b;
    u16 h8;
    u8 bA;
    u8 bB;
    u32 fC;
    u32 f10;
} Req_021CC390;

typedef struct Task {
    void *f0;
    void *f4;
    void *f8;
    u8 fC;
    u8 fD;
    u8 padE[0x58 - 0xE];
    u32 f58;
} Task;

typedef struct Rec {
    u8 f0;
    u8 pad1[3];
    void *f4;
} Rec;

typedef struct {
    u8 pad0[0x14];
    u8 *pc;
} ScriptVM;

typedef signed short s16;

typedef signed char s8;

typedef struct Obj_021CC720 {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u8 padE[2];
    u32 f10;
    u32 f14;
    u32 f18;
    u8 pad1C[0xb8 - 0x1c];
    u32 fB8;
    u8 padBC[0xc4 - 0xbc];
} Obj_021CC720;

typedef struct Obj_021CC7B4 {
    u8 pad0[0x18];
    u32 f18;
    u8 pad1C[0xb8 - 0x1c];
    u32 fB8;
    u8 padBC[0xc1 - 0xbc];
    u8 fC1;
} Obj_021CC7B4;

typedef struct Obj_021CC810 {
    u8 pad0[0xa4];
    u32 fA4;
    u8 padA8[0xbc - 0xa8];
    u32 fBC;
    u8 fC0;
    u8 fC1;
} Obj_021CC810;

typedef struct Obj_021CC8B0 {
    u8 pad0[0x10];
    u32 f10;
    u32 f14;
    u8 pad18[0xbc - 0x18];
    u32 fBC;
} Obj_021CC8B0;

typedef struct {
    u32 f0;
    void *f4;
    void *f8;
    u16 heap;
    u16 padE[(0x7C - 0xE) / 2];
    u16 f7C;
    u16 f7E;
    u16 f80[6];
    u16 f8C[6];
} Obj_021CC8DC;

typedef signed int s32;

typedef struct {
    u16 x;
    u16 y;
    u16 f4;
    u16 f6;
} Pos;

typedef struct {
    u32 f0;
    void *f4;
    void *f8;
    u16 heap;
    u16 padE;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C[6];
    u32 f34[6];
    u32 pad4C[(0x7C - 0x4C) / 4];
    u16 f7C;
    u16 f7E;
    u16 f80[6];
    u16 f8C[6];
} Obj_021CCA00;

typedef struct {
    u16 x;
    u16 y;
    u16 alt;
    u16 h6;
} IconPos;

typedef struct {
    u8 pad0[4];
    void *party[2];     /* 0x04 */
    u16 hC;             /* 0x0C */
    u8 padE[0x18 - 0xe];
    void *sys;          /* 0x18 */
    u8 pad1C[0x4c - 0x1c];
    void *icon[2][6];   /* 0x4C */
    u8 pad7C[0x98 - 0x7c];
    u16 h98;
    u16 h9A;
    u16 h9C;
} Work_021CCCE4;

typedef struct {
    void *f0;
    u8 pad4[8];
    u16 hC;
    u8 padE[0xa0 - 0xe];
    void *fA0;
    void *fA4;
    void *fA8;
} Work_021CCEB8;

typedef struct {
    int pad[4];
    int f10;
} Info;

typedef struct {
    u8 pad0[0xa4];
    void *fA4;
    void *fA8;
    u8 padAC[4];
    void *fB0;
    void *fB4;
} Work_021CCBE0;

extern void *func_02030734(u16 heap, u32 size, u32 clear, const char *file, u32 line);
extern void *func_02048F88(u32 archive_id, u32 member, u32 heap, u32 mode, u32 *size_out);
extern void *func_0200846C(int a0);
extern void func_020084A0(struct Sub0200852CObj *);
extern void func_02045A38(struct U16Vec *, u16 *, u32);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_0200854C(int, u32);
extern u32 func_020307B0(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201862C(u32 id, u16 species, u16 level, u8 a3, u8 a4, int a5);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *mon, u32 field, u32 v);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u8 *func_02012944(void *p);
extern void func_0202F190(void *mon, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_020185C4(void *mon);
extern u32 func_02017E1C(void *obj, u32 key, u32 off);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_0201AB48(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *func_0200CA1C(void *p);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj_021CC390 *p);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *p);
extern int func_0216C204(void *a, u8 *b);
extern void func_0215897C(void *a, void *b);
extern void *func_0215A5E4(void *a0);
extern void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *p);
extern u8 func_0200C1A4(struct Blk34 *p);
extern u32 func_0200C184(struct Blk34 *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void func_0216530C(void *a0);
extern void func_02165534(void *a0);
extern void func_021653C4(void);
extern void func_021656A0(void);
extern void func_021656D0(u8 a);
extern void func_0216573C(void);
extern void func_02165604(void);
extern void func_02165634(void *a0);
extern void func_0216566C(void);
extern u8 func_02010F18(void);
extern void *func_02010F7C(u32 heap);
extern void func_02010F40(u16 v, void *p);
extern void func_02010F8C(void *p);
extern void *func_021F5340(void *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0204B1CC(struct Bank *bank);
extern int func_0219049C(u8 *p);
extern void func_021CD1AC(Work_021CCBE0 *w);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_0201AA18(void *p);
extern u32 func_020185F0(void *p);
extern u32 func_0201BA68(void *mon);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *h);
extern void func_0204A8D4(u32 v);
extern void func_0204AFD8(u32 v);
extern u32 func_0204ADA4(u32 v);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern struct Obj_021CCA00 *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B6F4(struct Obj_021CCA00 *o, u32 v, u32 flag);
extern void func_0204B3DC(struct Obj_021CCA00 *p, unsigned int v);
extern void func_0204B3B4(struct Obj_021CC390 *p);
extern u32 func_02027694(void);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_0202769C(u32 a);
extern u32 func_020276A0(u32 a);
extern u32 func_02027698(void);
extern u32 func_0202136C(u16 v);
extern u32 func_02188C54(u8 *p);
extern int func_021904B0(u32 a, u32 b);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_021904C8(struct Rec *a0);
extern u32 func_02190A28(const struct Pair *arr, int n, u32 c, u16 d);
extern struct Handle *func_02190938(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u32 g, u32 h, u32 i);
extern int func_021909BC(void *a);
extern int func_021909E4(struct Handle *h);
extern u32 func_02020D0C(u8 *p);
extern void func_021CD184(void *p, u32 sel);
extern void func_02020298(struct Obj_021CC390 *obj, u8 a, u8 b, u8 c);
extern struct Obj2 *func_02190F64(struct Fx *a, u32 b);
extern int func_02190E40(u32 a);
extern u32 func_02190E74(u32, u32, u32, u32);
extern u32 func_02190EF0(u32 *p);
extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
extern int func_02190728(void *a);
Obj_021CC390 *func_021CBFB0(u32 a, u32 b);
void func_021CC040(Obj_021CC390 *o);
u32 func_021CC060(u8 *p);
u32 func_021CC068(u8 *p);
void *func_021CC070(u32 file, u32 index);
void func_021CC098(void *sys, u16 b, void *mon, Spec *d, u32 e);
void func_021CC23C(int obj);
void func_021CC38C(void *p);
int func_021CC390(void *a, u32 *state, Work_021CC23C *w);
void *func_021CC500(void *a, u32 b, u32 c);
int func_021CC544(void *task, void *p);
int func_021CC570(u32 unused, u32 a);
int func_021CC5D8(ScriptVM *vm, void *ctx);
int func_021CC614(u32 a, u32 b);
int func_021CC6A8(void *vm, void *ctx);
int func_021CC6FC(u32 a, u32 b, u32 c, u32 d);
Obj_021CC720 *func_021CC720(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
u32 func_021CC7B4(Obj_021CC7B4 *p, u32 *out);
int func_021CC810(Obj_021CC810 *p);
u32 func_021CC8B0(Obj_021CC8B0 *p, u32 *out);
void func_021CC8DC(Obj_021CC8DC *p);
void func_021CC9A4(u8 *p);
void func_021CCA00(Obj_021CCA00 *p);
void func_021CCB98(u8 *p);
void func_021CCBE0(u8 *s, int flag);
void func_021CCC50(u8 *p);
int func_021CCCC4(u32 a);
void func_021CCCE4(Work_021CCCE4 *w);
void func_021CCDF8(u8 *p);
void func_021CCE48(u8 *s, int flag);
void func_021CCEB8(Work_021CCEB8 *w);
int func_021CCEE4(u32 a);
void func_021CCEFC(u8 *p);
void func_021CCF48(u8 *p);
u32 func_021CCF54(u8 *p);
void func_021CCF60(void *a, u32 sel);
void func_021CCF7C(void *p, int k);
void func_021CCFC0(Work_021CCBE0 *w);
void func_021CCFD8(u8 *p);
int func_021CCFE4(u32 a, u32 b);
int func_021CCFF8(u8 *p);
void func_021CD004(Work_021CCBE0 *w);
void func_021CD038(Work_021CCBE0 *w);
extern const char d_021DE59C[];
extern const u8 ov119_id[];
extern const u8 ov195_id[];
extern u8 d_021E75A8[];
extern u8 d_02208C40[];
extern const char d_021DE5A8[];
extern const u8 d_021F6D78[];
extern u8 ov107_id[];
extern const char d_021DE5BC[];
extern const char d_021DE5C0[];
extern Pos d_021DB404;
extern const IconPos d_021DB40C;
extern u8 d_021DB414[];
extern u8 d_021DB42C[];



Obj_021CC390 *func_021CBFB0(u32 a, u32 b)
{
    Obj_021CC390 *p;
    int r;
    char buf[0x100];

    p = func_02030734((u16)a, 0x14, 1, d_021DE59C, 0x5d);
    p->f0 = (u16)a;
    p->f4 = b;
    p->f8 = func_02048F88(0xa5, b, (u16)a, 0, (u32 *)0x6c);
    p->fC = func_02030734((u16)a, 0xdc, 0, d_021DE59C, 0x65);
    p->f10 = (void *)func_0200846C(a);
    func_020084A0((struct Sub0200852CObj *)p->f10);
    r = (int)func_021CC070(a, ((struct Obj20247 *)(p->f8))->f68);
    func_02045A38((struct U16Vec *)r, (u16 *)buf, 0x80);
    func_02045808((struct U16Vec *)r);
    func_020084D4((int)p->f10, buf);
    func_0200854C((int)p->f10, ((struct Obj20248 *)(p->f8))->f50);
    return p;
}



/*
 * Frees the three buffers held by a battle-subway mon object and then the object itself.
 *
 * Addresses are Black-image addresses.
 */
void func_021CC040(Obj_021CC390 *o)
{
    func_020307B0(o->f8);
    func_020307B0(o->fC);
    func_020307B0(o->f10);
    func_020307B0(o);
}



/*
 * Follows the pointer at +0x8, then loads the 32-bit word at +0x5c of its target.
 */
u32 func_021CC060(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj01219 *)p)->f8;

    return ((struct Obj18350 *)q)->f5C;
}



/*
 * Follows the pointer at +0x8, then loads the 32-bit word at +0x60 of its target.
 */
u32 func_021CC068(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj01219 *)p)->f8;

    return ((struct Obj18351 *)q)->f60;
}



/*
 * Opens message bank 0x23 for a given file, fetches one string and closes the bank.
 *
 * Addresses are Black-image addresses.
 */
void *func_021CC070(u32 file, u32 index)
{
    void *bank = func_02045B38(0, 2, 0x23, (u16)file);
    void *s = func_02045EC0(bank, index);
    func_02045C04(bank);
    return s;
}



void func_021CC098(void *sys, u16 b, void *mon, Spec *d, u32 e)
{
    u32 pid;
    u32 s;
    u32 x;
    u32 v[3];

    pid = func_0201862C(d->id, d->species, d->level, d->f30, 0, 0);
    func_02017588(mon, d->species, d->f0C, d->id, 0xFFFFFFFF, pid);
    func_02017E40(mon, 0x6F, d->level);
    func_021CC23C((int)mon);
    s = (u32)func_021CC070(b, d->f64);
    func_02017E40(mon, 0x73, s);
    func_02045808((struct U16Vec *)s);
    func_02017E40(mon, 0x46, d->f10[0]);
    func_02017E40(mon, 0x47, d->f10[1]);
    func_02017E40(mon, 0x48, d->f10[2]);
    func_02017E40(mon, 0x49, d->f10[3]);
    func_02017E40(mon, 0x4A, d->f10[4]);
    func_02017E40(mon, 0x4B, d->f10[5]);
    x = (u32)func_0201ADE4((u16)d->species, (u16)d->level, b);
    v[0] = func_0201AE1C((const struct Personal *)x, 0x1A);
    v[1] = func_0201AE1C((const struct Personal *)x, 0x1B);
    v[2] = func_0201AE1C((const struct Personal *)x, 0x1C);
    func_0201AE14((void *)x);
    switch (d->sel) {
    case 0:
        break;
    case 1:
        v[0] = v[1];
        break;
    case 2:
        v[0] = v[2];
        break;
    }
    func_02017E40(mon, 0xA, v[0]);
    func_02017E40(mon, 0x70, d->f2C);
    func_02017E40(mon, 0x13, d->f38[0]);
    func_02017E40(mon, 0x14, d->f38[1]);
    func_02017E40(mon, 0x15, d->f38[2]);
    func_02017E40(mon, 0x16, d->f38[3]);
    func_02017E40(mon, 0x17, d->f38[4]);
    func_02017E40(mon, 0x6, d->f4C);
    s = (u32)func_021CC070(b, d->f68);
    func_02017E40(mon, 0x8D, s);
    func_02045808((struct U16Vec *)s);
    func_02017E40(mon, 0x9A, d->f50);
    func_02017E40(mon, 0xC, d->f58);
    func_0202F190(mon, 1, (u32)func_02012944(sys), 0x7532, b);
    func_021CC23C((int)mon);
    func_020185C4(mon);
}






/*
 * Straight unrolled key list: 33 calls to func_02017E1C(obj, key, 0).
 * EXACT* only because the follower at 0x021CC38C (`bx lr`) is an unlabelled
 * leaf, so the inferred extent runs long into its padding; report, not seeded.
 */
void func_021CC23C(int obj)
{
    func_02017E1C((void *)obj, 0, 0);
    func_02017E1C((void *)obj, 5, 0);
    func_02017E1C((void *)obj, 0x6f, 0);
    func_02017E1C((void *)obj, 6, 0);
    func_02017E1C((void *)obj, 7, 0);
    func_02017E1C((void *)obj, 8, 0);
    func_02017E1C((void *)obj, 9, 0);
    func_02017E1C((void *)obj, 0xa, 0);
    func_02017E1C((void *)obj, 0x6e, 0);
    func_02017E1C((void *)obj, 0x70, 0);
    func_02017E1C((void *)obj, 0xb, 0);
    func_02017E1C((void *)obj, 0xc, 0);
    func_02017E1C((void *)obj, 0xd, 0);
    func_02017E1C((void *)obj, 0xe, 0);
    func_02017E1C((void *)obj, 0xf, 0);
    func_02017E1C((void *)obj, 0x10, 0);
    func_02017E1C((void *)obj, 0x11, 0);
    func_02017E1C((void *)obj, 0x12, 0);
    func_02017E1C((void *)obj, 0x13, 0);
    func_02017E1C((void *)obj, 0x14, 0);
    func_02017E1C((void *)obj, 0x15, 0);
    func_02017E1C((void *)obj, 0x16, 0);
    func_02017E1C((void *)obj, 0x17, 0);
    func_02017E1C((void *)obj, 0x18, 0);
    func_02017E1C((void *)obj, 0x46, 0);
    func_02017E1C((void *)obj, 0x47, 0);
    func_02017E1C((void *)obj, 0x48, 0);
    func_02017E1C((void *)obj, 0x49, 0);
    func_02017E1C((void *)obj, 0x4a, 0);
    func_02017E1C((void *)obj, 0x4b, 0);
    func_02017E1C((void *)obj, 0x9a, 0);
    func_02017E1C((void *)obj, 0x9e, 0);
    func_02017E1C((void *)obj, 0x95, 0);
}





void func_021CC38C(void *p)
{
}






/*
 * Five-step task callback (*state 0..4) that builds a mon through
 * func_021CC098, starts the ov119 and ov195 tasks and frees its work.
 *
 * Blocked (MATCH, every concrete byte right), three sites:
 *  - the pooled words 0x00000077 and 0x000000C3 are overlay ids (ov119_id,
 *    ov195_id) passed to func_020146F8's third argument; func_020146F8 is
 *    not in match.py's OVERLAY_ID_CONSUMERS and no pool word outside this
 *    range holds either value (same blocker as pending ov021_func_021CD348
 *    and ov021_func_021C5A54).
 *  - func_021CC38C is an unlabelled 4-byte leaf (`bx lr`, then 00 00
 *    padding) in ov021: `void func_021CC38C(void *p) {}`. Not filed here
 *    because the overlay ids cap this function at MATCH regardless; file it
 *    as pkt_ov021_021CC38C together with the id fix.
 * d_021E75A8 resolves only without its ov119 token (sole-ref on re-run).
 *
 * Addresses are Black-image addresses.
 */
int func_021CC390(void *a, u32 *state, Work_021CC23C *w)
{
    void *sys = w->sys;
    void *f4 = w->f4;
    void *f8 = w->f8;
    void *h = func_0201210C(sys);
    void *m = func_0201AB28(f8, w->fD);
    Obj_021CC390 *o;
    void *t;
    void *box;
    u32 sel;
    u32 r;
    Req_021CC390 *q;

    switch (*state) {
    case 0:
        o = func_021CBFB0(4, w->fC);
        w->obj = o;
        func_021CC098(f4, 4, o->fC, o->f8, w->fC);
        func_021CC23C((int)w->obj->fC);
        func_021CC38C(w->obj->f8);
        *state = 1;
        break;
    case 1:
        t = func_0201210C(sys);
        w->f44 = f4;
        w->f50 = func_02012944(f4);
        w->f48 = m;
        w->f54 = w->obj->f10;
        w->f4C = w->obj->fC;
        func_02012374(a, func_020146F8(sys, (int)t, (int)ov119_id, (int)d_021E75A8, (int)w->f14));
        *state = 2;
        break;
    case 2:
        func_0201AB48(f8, w->fD, w->obj->fC);
        box = func_0200CA1C(f4);
        func_0200CFA0(box, w->obj->fC);
        func_0200CDE0(box, w->obj->fC);
        *state = 4;
        break;
    case 3:
        r = func_0201B2B0(f8, m, 1, 0, func_02012984(f4), &sel, 4);
        if (r != 0) {
            q = func_02030734(4, 0x14, 0, d_021DE59C, 0x1F0);
            q->a = f4;
            q->b = f8;
            q->h8 = r;
            q->bA = w->fD;
            q->bB = sel;
            q->fC = 1;
            q->f10 = 0;
            w->f58 = q;
            func_02012374(a, func_020146F8(sys, (int)h, (int)ov195_id, (int)d_02208C40, (int)q));
        }
        *state = 4;
        break;
    case 4:
        if (w->f58 != 0)
            func_020307B0(w->f58);
        func_021CC040(w->obj);
        return 1;
    }
    return 0;
}






void *func_021CC500(void *a, u32 b, u32 c)
{
    void *t;
    void *x;
    void *h;
    Task *p;

    t = func_020120F4(a);
    x = func_02012934(t);
    h = func_020122C0(a, 0, (void *)func_021CC390, 0x5c);
    p = func_020124E8(h);
    p->f0 = a;
    p->f4 = t;
    p->f8 = x;
    p->fC = b;
    p->fD = c;
    p->f58 = 0;
    return h;
}






/*
 * Task step: hands the field's current map object to ov010 func_0215897C with a lookup through func_0216C204.
 *
 * Addresses are Black-image addresses.
 */
int func_021CC544(void *task, void *p)
{
    void *a = func_0215A5F4(p);
    void *b = func_0215A5DC(p);
    func_0215897C(a, (void *)func_0216C204((void *)b, (u8 *)func_0201210C(b)));
    return 1;
}






/*
 * Launches overlay 0x6B (107) over an 8-byte record with the ov107 process
 * table at 0x021F6D78, parks the result in the script slot.
 *
 * MATCH, bytes exact. Blocker: the two pooled ABS32 words ov107_id (0x6B)
 * and d_021F6D78 (ov107 data, contested/no witness) have no witness, and
 * func_02014840 is not in match.py OVERLAY_ID_CONSUMERS, so the overlay-id
 * class refuses both. Dropping the ov107 token (data a4) does not help.
 */
int func_021CC570(u32 unused, u32 a)
{
    void *s;
    void *sys;
    void *v;
    void *x;
    Rec *r;

    s = func_0215A5F4((void *)a);
    sys = func_0215A5DC((void *)a);
    v = func_0215A5E4((void *)a);
    x = func_0201210C((void *)sys);
    r = func_02030734(4, 8, 0, d_021DE5A8, 0x44);
    r->f0 = 0;
    r->f4 = v;
    func_0215897C(s, func_02014840(sys, (int)x, (u32)ov107_id, (int)d_021F6D78, (int)r, 0, (int)r));
    return 1;
}






/*
 * Script command: reads a mode byte and a result variable, then stores one of two values from the save-data block selected by the mode.
 *
 * Addresses are Black-image addresses.
 */
int func_021CC5D8(ScriptVM *vm, void *ctx)
{
    u8 mode;
    u16 *dst;
    void *p;

    mode = *vm->pc;
    vm->pc++;
    dst = func_02159AE8(vm, ctx);
    p = func_0200C0F0(func_02012EBC(func_0215A5E4(ctx)));

    switch (mode) {
    case 0:
        *dst = func_0200C1A4(p);
        break;
    case 1:
        *dst = func_0200C184(p);
        break;
    }
    return 0;
}






/*
 * func_020120F4 takes the func_0215A5DC result as its argument (r0 still
 * holds it at the bl), as it does at every other caller; declaring it
 * void(void) was what shuffled the whole register assignment.
 */
int func_021CC614(u32 a, u32 b)
{
    u32 sel;
    u32 v;
    void *t;

    sel = func_02159B10((void *)a, (void *)b);
    v = func_02159B10((void *)a, (void *)b);
    t = func_0215A5DC((void *)b);
    func_020120F4(t);
    func_0201210C((void *)t);
    func_0215A5F4((void *)b);
    switch (sel) {
    case 0:
        func_0216530C((void *)v);
        break;
    case 1:
        func_02165534((void *)v);
        break;
    case 2:
        func_021653C4();
        break;
    case 3:
        func_021656A0();
        break;
    case 4:
        func_021656D0(v);
        break;
    case 5:
        func_0216573C();
        break;
    case 6:
        func_02165604();
        break;
    case 7:
        func_02165634((void *)v);
        break;
    case 8:
        func_0216566C();
        break;
    }
    return 0;
}






/*
 * Script command: stores the current value of func_02010F18 in one variable and whether it changes away from 0x30 after a func_02010F40 round trip in another.
 *
 * Addresses are Black-image addresses.
 */
int func_021CC6A8(void *vm, void *ctx)
{
    u16 *a = func_02159AE8(vm, ctx);
    u16 *b = func_02159AE8(vm, ctx);
    void *p;

    *a = func_02010F18();
    if (*a != 0x30) {
        p = func_02010F7C(0x8015);
        func_02010F40(*a, p);
        func_02010F8C(p);
        *b = (func_02010F18() != 0x30) ? 1 : 0;
    } else {
        *b = 0;
    }
    return 0;
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CC6FC(u32 a, u32 b, u32 c, u32 d)
{
func_0215897C(func_0215A5F4((void *)b), func_021F5340(func_0215A5DC((void *)b)));
return 1;
}






Obj_021CC720 *func_021CC720(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap)
{
    Obj_021CC720 *p;

    if (b == 0 || c == 0)
        func_02034714(d_021DE5BC, 0, d_021DE5BC);
    p = func_02030734(heap, 0xc4, 1, d_021DE5C0, 0xd3);
    p->f0 = a;
    p->f4 = b;
    p->f8 = c;
    p->fC = heap;
    p->f10 = d;
    p->f14 = e;
    p->f18 = (u32)func_0204B100(0x20, 0xa, p->fC);
    p->fB8 = (u32)func_0201D7EC(0x17, 3, 0, 0, p->fC);
    func_021CCEB8((Work_021CCEB8 *)p);
    func_021CC8DC((Obj_021CC8DC *)p);
    func_021CCA00((Obj_021CCA00 *)p);
    func_021CCC50((u8 *)p);
    func_021CCCE4((Work_021CCCE4 *)p);
    return p;
}






u32 func_021CC7B4(Obj_021CC7B4 *p, u32 *out)
{
    u32 r;

    r = func_021CC8B0((Obj_021CC8B0 *)p, out);
    if (p->fC1 != 1)
        func_02034714(d_021DE5BC, 0, d_021DE5BC);
    func_021CCDF8((u8 *)p);
    func_021CCCC4((u32)p);
    func_021CCB98((u8 *)p);
    func_021CC9A4((u8 *)p);
    func_021CCEE4((u32)p);
    func_0201D83C((void *)p->fB8);
    func_0204B1CC((struct Bank *)p->f18);
    func_020307B0(p);
    return r;
}





/*
 * Task state machine on the byte at +0xc0. The inner switch on an unsigned
 * result (cases 2, -2, -1) is what gives the compare order 2, -2, -1 and
 * the dead second -1 test.
 */
int func_021CC810(Obj_021CC810 *p)
{
    u32 r;

    switch (p->fC0) {
    case 0:
        func_021CCFC0((Work_021CCBE0 *)p);
        func_021CCFE4((u32)p, 3);
        p->fC0 = p->fC0 + 1;
        break;
    case 1:
        if (func_021CCFF8((u8 *)p) == 1) {
            func_021CCEFC((u8 *)p);
            p->fC0 = p->fC0 + 1;
        }
        break;
    case 2:
        if (func_0219049C((u8 *)p->fA4) == 1) {
            r = func_021CCF54((u8 *)p);
            if (r == -1)
                break;
            func_021CCF48((u8 *)p);
            func_021CD1AC((Work_021CCBE0 *)p);
            func_021CCFD8((u8 *)p);
            switch (r) {
            case 2:
            case -2:
                p->fBC = 2;
                p->fC0 = p->fC0 + 1;
                break;
            case -1:
                break;
            default:
                p->fBC = r;
                p->fC0 = p->fC0 + 1;
                break;
            }
        }
        break;
    default:
        p->fC1 = 1;
        return 1;
    }
    return 0;
}





u32 func_021CC8B0(Obj_021CC8B0 *p, u32 *out)
{
    u32 m;

    *out = 0;
    m = p->fBC;
    if (m == 0 && p->f10 == 1)
        *out = 1;
    else if (m == 1 && p->f14 == 1)
        *out = 1;
    return p->fBC;
}





void func_021CC8DC(Obj_021CC8DC *p)
{
    void *arc;
    int i;
    int n;

    arc = func_020490F4(7, p->heap);
    p->f7C = func_0204ACEC(arc, func_0201BC3C(), 0, 0x60, p->heap);
    p->f7E = func_0204AF28(arc, func_0201BC40(), func_0201BCB4(), p->heap);
    n = func_0201AA18(p->f4);
    for (i = 0; i < n; i++) {
        p->f80[i] = func_0204A6C8(arc, func_0201BA68((void *)func_020185F0(func_0201AB28(p->f4, i))), 0, 0, p->heap);
    }
    if (p->f8 != 0) {
        n = func_0201AA18(p->f8);
        for (i = 0; i < n; i++) {
            p->f8C[i] = func_0204A6C8(arc, func_0201BA68((void *)func_020185F0(func_0201AB28(p->f8, i))), 0, 0, p->heap);
        }
    }
    func_02049238(arc);
}





void func_021CC9A4(u8 *p)
{
    int i;
    int n;

    if (((struct Obj06097 *)p)->f8) {
        n = func_0201AA18(((struct Obj06097 *)p)->f8);
        for (i = 0; i < n; i++)
            func_0204A8D4(*(u16 *)(p + i * 2 + 0x8c));
    }
    n = func_0201AA18(((struct Obj06097 *)p)->f4);
    for (i = 0; i < n; i++)
        func_0204A8D4(*(u16 *)(p + i * 2 + 0x80));
    func_0204AFD8(((struct Obj06097 *)p)->f7E);
    func_0204ADA4(((struct Obj06097 *)p)->f7C);
}





void func_021CCA00(Obj_021CCA00 *p)
{
    Pos pos = d_021DB404;
    int n1;
    int n2;
    int i;
    void *mon;
    u32 s;
    u32 f;
    u32 e;
    u32 r;

    n1 = func_0201AA18(p->f4);
    for (i = 0; i < n1; i++) {
        pos.x = i * 0x28 + 0x18;
        p->f1C[i] = (u32)func_0204B294((void *)p->f18, p->f80[i], p->f7C, p->f7E, &pos, 0, p->heap);
        mon = func_0201AB28(p->f4, i);
        s = func_02017E1C(mon, 5, 0);
        f = func_02017E1C(mon, 0x6f, 0);
        e = (func_02017E1C(mon, 0xab, 0) == 0x28a) ? 1 : 0;
        r = func_0201BB5C(s, f, func_02017E1C(mon, 0x6e, 0), e);
        func_0204B6F4((struct Obj_021CCA00 *)p->f1C[i], (u8)r, 1);
        func_0204B3DC((struct Obj_021CCA00 *)p->f1C[i], 0);
    }
    if (p->f8 != 0) {
        n2 = func_0201AA18(p->f8);
        for (i = 0; i < n2; i++) {
            pos.x = i * 0x28 + 0x18;
            p->f34[i] = (u32)func_0204B294((void *)p->f18, p->f8C[i], p->f7C, p->f7E, &pos, 0, p->heap);
            mon = func_0201AB28(p->f8, i);
            s = func_02017E1C(mon, 5, 0);
            f = func_02017E1C(mon, 0x6f, 0);
            e = (func_02017E1C(mon, 0xab, 0) == 0x28a) ? 1 : 0;
            r = func_0201BB5C(s, f, func_02017E1C(mon, 0x6e, 0), e);
            func_0204B6F4((struct Obj_021CCA00 *)p->f34[i], (u8)r, 1);
            func_0204B3DC((struct Obj_021CCA00 *)p->f34[i], 0);
        }
    }
}





void func_021CCB98(u8 *p)
{
    int i;
    int n;

    n = func_0201AA18(((struct Obj09731 *)p)->f4);
    for (i = 0; i < n; i++)
        func_0204B3B4(*(void **)(p + i * 4 + 0x1c));
    if (((struct Obj09731 *)p)->f8) {
        n = func_0201AA18(((struct Obj09731 *)p)->f8);
        for (i = 0; i < n; i++)
            func_0204B3B4(*(void **)(p + i * 4 + 0x34));
    }
}






void func_021CCBE0(u8 *s, int flag)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(void **)(s + i * 4 + 0x1c) != 0)
            func_0204B3DC((struct Obj_021CCA00 *)(*(void **)(s + i * 4 + 0x1c)), 0);
        if (*(void **)(s + i * 4 + 0x34) != 0)
            func_0204B3DC((struct Obj_021CCA00 *)(*(void **)(s + i * 4 + 0x34)), 0);
    }
    if (flag == 0) {
        for (i = 0; i < 6; i++) {
            if (*(void **)(s + i * 4 + 0x1c) != 0)
                func_0204B3DC((struct Obj_021CCA00 *)(*(void **)(s + i * 4 + 0x1c)), 1);
        }
    } else if (flag == 1) {
        for (i = 0; i < 6; i++) {
            if (*(void **)(s + i * 4 + 0x34) != 0)
                func_0204B3DC((struct Obj_021CCA00 *)(*(void **)(s + i * 4 + 0x34)), 1);
        }
    }
}






void func_021CCC50(u8 *p)
{
    void *h;
    u32 a;
    u32 b;

    h = func_020490F4(0x53, ((struct Obj04293 *)p)->fC);
    ((struct Obj04293 *)p)->f98 = func_0204AC18(h, func_02027694(), 0, 0xc0, 0, 1, ((struct Obj04293 *)p)->fC);
    a = func_0202769C(1);
    b = func_020276A0(1);
    ((struct Obj04293 *)p)->f9A = func_0204AF28(h, a, b, ((struct Obj04293 *)p)->fC);
    ((struct Obj04293 *)p)->f9C = func_0204A6C8(h, func_02027698(), 0, 0, ((struct Obj04293 *)p)->fC);
    func_02049238(h);
}






int func_021CCCC4(u32 a)
{
func_0204A8D4(*(u16 *)((u8 *)((a + 156))));
func_0204AFD8(*(u16 *)((u8 *)((a + 154))));
return func_0204ADA4(*(u16 *)((u8 *)((a + 152))));
}






/*
 * Creates the party icon sprites for both sides: one per non-empty slot, at x = 0x20 + 0x28 * slot, flagged for the alternate form, into the +0x4C and +0x64 handle arrays.
 *
 * The alternate-form flag is an if/else storing 1 or 0 into pos.alt, not a
 * ternary: the ternary version (114 bytes out) left the second party count in
 * a register and rematerialised &pos; the if/else spills both counts and
 * keeps &pos hoisted in each loop, as the original does.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCCE4(Work_021CCCE4 *w)
{
    IconPos pos = d_021DB40C;
    int n0;
    int n1;
    int i;
    u32 species;

    n0 = func_0201AA18(w->party[0]);
    for (i = 0; i < n0; i++) {
        species = func_02017E1C(func_0201AB28(w->party[0], i), 6, 0);
        if (species != 0) {
            if (func_0202136C(species) == 1) {
                pos.alt = 1;
            } else {
                pos.alt = 0;
            }
            pos.x = i * 0x28 + 0x20;
            w->icon[0][i] = (struct Obj_021CC390 *)func_0204B294(w->sys, w->h9C, w->h98, w->h9A, &pos, 0, w->hC);
            func_0204B3DC((struct Obj_021CCA00 *)(w->icon[0][i]), 0);
        }
    }
    if (w->party[1] != 0) {
        n1 = func_0201AA18(w->party[1]);
        for (i = 0; i < n1; i++) {
            species = func_02017E1C(func_0201AB28(w->party[1], i), 6, 0);
            if (species != 0) {
                if (func_0202136C(species) == 1) {
                pos.alt = 1;
            } else {
                pos.alt = 0;
            }
                pos.x = i * 0x28 + 0x20;
                w->icon[1][i] = (struct Obj_021CC390 *)func_0204B294(w->sys, w->h9C, w->h98, w->h9A, &pos, 0, w->hC);
                func_0204B3DC((struct Obj_021CCA00 *)(w->icon[1][i]), 0);
            }
        }
    }
}






void func_021CCDF8(u8 *p)
{
    int i;
    int n;

    n = func_0201AA18(((struct Obj09732 *)p)->f4);
    for (i = 0; i < n; i++) {
        if (*(void **)(p + i * 4 + 0x4c))
            func_0204B3B4(*(void **)(p + i * 4 + 0x4c));
    }
    if (((struct Obj09732 *)p)->f8) {
        n = func_0201AA18(((struct Obj09732 *)p)->f8);
        for (i = 0; i < n; i++) {
            if (*(void **)(p + i * 4 + 0x64))
                func_0204B3B4(*(void **)(p + i * 4 + 0x64));
        }
    }
}






void func_021CCE48(u8 *s, int flag)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(void **)(s + i * 4 + 0x4c) != 0)
            func_0204B3DC((struct Obj_021CCA00 *)(*(void **)(s + i * 4 + 0x4c)), 0);
        if (*(void **)(s + i * 4 + 0x64) != 0)
            func_0204B3DC((struct Obj_021CCA00 *)(*(void **)(s + i * 4 + 0x64)), 0);
    }
    if (flag == 0) {
        for (i = 0; i < 6; i++) {
            if (*(void **)(s + i * 4 + 0x4c) != 0)
                func_0204B3DC((struct Obj_021CCA00 *)(*(void **)(s + i * 4 + 0x4c)), 1);
        }
    } else if (flag == 1) {
        for (i = 0; i < 6; i++) {
            if (*(void **)(s + i * 4 + 0x64) != 0)
                func_0204B3DC((struct Obj_021CCA00 *)(*(void **)(s + i * 4 + 0x64)), 1);
        }
    }
}






/*
 * Fetches three handles for the work block: an ov021 object, a 0x54 sub-entry of it, and the record for the work's id.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCEB8(Work_021CCEB8 *w)
{
    void *o = (void *)func_02188C54(w->f0);
    w->fA8 = (void *)func_021904B0((u32)o, 0x54);
    w->fA4 = o;
    w->fA0 = func_0201EC64(w->hC);
}






int func_021CCEE4(u32 a)
{
func_0201ED04((struct WordSet *)(*(u32 *)((u8 *)((a + 160)))));
return func_021904C8((struct Rec *)(*(u32 *)((u8 *)((a + 168)))));
}






void func_021CCEFC(u8 *p)
{
    void *r;

    r = (void *)func_02190A28((const struct Pair *)d_021DB414, 3, ((struct Obj07588 *)p)->fA8, ((struct Obj07588 *)p)->fC);
    ((struct Obj07588 *)p)->fAC = func_02190938((u16 *)(((struct Obj07588 *)p)->fA4), d_021DB42C, (u32)r, 0, 0,
        (u32)func_021CCF60, (u32)func_021CCF7C, (u32)p);
}






/*
 * Tail call on the word at +0xac.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCF48(u8 *p)
{
    func_021909BC((void *)(((struct Obj18357 *)p)->fAC));
}






u32 func_021CCF54(u8 *p)
{
    return func_021909E4((struct Handle *)(((struct Obj18358 *)p)->fAC));
}






/*
 * Dispatches on a selector below two to func_021CD184, otherwise to func_021CD1AC, on the object from func_02020D0C.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCF60(void *a, u32 sel)
{
    void *p = (void *)func_02020D0C(a);
    if (sel < 2)
        func_021CD184(p, sel);
    else
        func_021CD1AC((Work_021CCBE0 *)p);
}






void func_021CCF7C(void *p, int k)
{
    Info *i = (Info *)func_02020D0C(p);

    if (k == 0 && i->f10 == 1) {
        func_02020298(p, 1, 0, 2);
        return;
    }
    if (k == 1) {
        func_02020298(p, 1, 0, 2);
        return;
    }
    func_02020298(p, 1, 0, 2);
}






/*
 * Builds the +0xB0 handle of the work block from its +0xA4 object and +0xA8 entry.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCFC0(Work_021CCBE0 *w)
{
    w->fB0 = func_02190F64(w->fA4, (u32)w->fA8);
}






/*
 * Tail call on the word at +0xb0.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCFD8(u8 *p)
{
    func_02190E40(((struct Obj18359 *)p)->fB0);
}






int func_021CCFE4(u32 a, u32 b)
{
return func_02190E74(*(u32 *)((u8 *)((a + 176))), 0, 0, b);
}






int func_021CCFF8(u8 *p)
{
    return func_02190EF0((u32 *)(((struct Obj18361 *)p)->fB0));
}






/*
 * Creates the +0xB4 handle of the work block once, from its +0xA4 object and +0xA8 entry.
 *
 * Addresses are Black-image addresses.
 */
void func_021CD004(Work_021CCBE0 *w)
{
    if (w->fB4 == 0)
        w->fB4 = func_02190708(w->fA4, (u32)w->fA8, 1, 2, 0x1e, 6);
}




/*
 * Releases the +0xB4 handle of the work block if it is set and clears it.
 *
 * Addresses are Black-image addresses.
 */
void func_021CD038(Work_021CCBE0 *w)
{
    if (w->fB4 != 0) {
        func_02190728((void *)w->fB4);
        w->fB4 = 0;
    }
}
