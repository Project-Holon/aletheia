/*
 * file:     particle.c
 * unit:     yes
 * function: func_0204FE94, func_0204FFFC, func_02050080, func_02050084, func_02050088, func_020500A0, func_020500B8, func_020500F0, func_02050238, func_02050278, func_02050304, func_02050330, func_02050340, func_02050468, func_020504D8, func_02050550, func_020506B8, func_02050738, func_02050790, func_020507A0, func_020507D0, func_020507F0, func_02050804, func_0205082C, func_02050848, func_0205085C, func_02050880, func_02050894, func_020508C4, func_020508D8, func_020508EC, func_02050920, func_02050944, func_02050984, func_020509E0, func_020509E8, func_02050A00, func_02050A58, func_02050A70, func_02050B14, func_02050B80, func_02050BE8, func_02050C04, func_02050C30, func_02050DB8, func_02050ED4, func_02050F1C, func_02050F4C, func_02050F7C, func_02050FAC, func_02050FDC, func_0205100C, func_0205103C, func_0205106C, func_0205109C, func_020510CC, func_020510FC, func_0205112C, func_0205115C, func_0205118C, func_020511BC, func_020511EC, func_0205121C, func_02051230, func_02051360, func_02051380, func_02051394, func_020513F8, func_02051414, func_020514F4, func_02051504, func_02051534, func_02051574, func_020515B4, func_020515CC, func_02051614, func_02051620, func_02051630, func_02051640, func_02051648, func_02051758
 * address:  0x0204FE94
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734     0x02030734  arm
 *   func_0204EBD4     0x0204EBD4  arm
 *   func_02033C00     0x02033C00  arm
 *   sBillboardAct     0x020A7FB0  data
 *   gBillboardActTpl  0x020A155C  data  a4
 *   func_0204F5A8  0x0204F5A8  arm
 *   func_0204ED24  0x0204ED24  arm
 *   func_02033C9C  0x02033C9C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02033CA8  0x02033CA8  arm
 *   func_0204EF58  0x0204EF58  arm
 *   func_0204F10C  0x0204F10C  arm
 *   func_0204F150  0x0204F150  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_0203422C  0x0203422C  arm
 *   func_0204F428  0x0204F428  arm
 *   func_0204F720  0x0204F720  arm
 *   func_0204F66C  0x0204F66C  arm
 *   func_0204F764  0x0204F764  arm
 *   func_0204F794  0x0204F794  arm
 *   func_020473D8  0x020473D8  arm
 *   func_0204F2B4  0x0204F2B4  arm
 *   func_0204F344  0x0204F344  arm
 *   func_020473EC   0x020473EC  arm
 *   func_0204F2CC   0x0204F2CC  arm
 *   DWCi_LSTlErase 0x0204F7DC arm
 *   g_02146A84     0x02146A84  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_02146A88      0x02146A88  data
 *   pkt_02050A70_File 0x020A7FC0  data
 *   g_020A7FC0     0x020A7FC0  data
 *   g_020A1590     0x020A1590  data
 *   g_020A1584     0x020A1584  data
 *   g_020A1578     0x020A1578  data
 *   g_020A15A8     0x020A15A8  data
 *   func_02052DC8  0x02052DC8  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02051620  0x02051620  arm
 *   func_0206168C  0x0206168C  arm
 *   func_020621FC  0x020621FC  arm
 *   func_02061824  0x02061824  arm
 *   func_02062594  0x02062594  arm
 *   func_02048AC4  0x02048AC4  arm
 *   func_02048F60  0x02048F60  arm
 *   func_02046BFC  0x02046BFC  arm
 *   func_02046C10  0x02046C10  arm
 *   func_0206164C  0x0206164C  arm
 *   func_02061808  0x02061808  arm
 *   func_02052A50  0x02052A50  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02051A3C  0x02051A3C  arm
 *   func_02051A54  0x02051A54  arm
 *   func_02051AA0  0x02051AA0  arm
 *   func_02051AB8  0x02051AB8  arm
 *   func_020528A8  0x020528A8  arm
 *   func_020528BC  0x020528BC  arm
 *   func_020528D0  0x020528D0  arm
 *   func_02052984  0x02052984  arm
 *   g_020A159C      0x020A159C  data
 *   g_02148B4C      0x02148B4C  data
 *   g_02148B98      0x02148B98  data
 *   g_02148C08      0x02148C08  data
 *   func_020467EC   0x020467EC  arm
 *   func_02046858   0x02046858  arm
 *   func_02046AFC   0x02046AFC  arm
 *   func_02046B40   0x02046B40  arm
 *   func_020479D8   0x020479D8  arm
 *   func_02048AD0   0x02048AD0  arm
 *   func_020526A8   0x020526A8  arm
 *   func_0206A9DC   0x0206A9DC  arm
 *   func_0206AA0C   0x0206AA0C  arm
 *   func_0206DB80   0x0206DB80  arm
 *   MI_Copy36B      0x02082B60  arm
 *   MTX_Identity33_ 0x0207ADC4  arm
 *   func_020524C8 0x020524C8 arm
 *   func_0205250C  0x0205250C  arm
 *   func_02048A24  0x02048A24  arm
 */
#include "../../matched/include/Obj11450.h"
#include "../../matched/include/Obj02611.h"
#include "../../matched/include/Obj02015.h"
#include "../../matched/include/Obj08867.h"
#include "../../matched/include/Obj06991.h"
#include "../../matched/include/Obj06992.h"
#include "../../matched/include/Obj11453.h"
#include "../../matched/include/Obj11454.h"
#include "../../matched/include/Obj16154.h"
#include "../../matched/include/Obj16155.h"
#include "../../matched/include/Obj16156.h"
#include "../../matched/include/Obj16157.h"
#include "../../matched/include/Obj11455.h"
#include "../../matched/include/Obj16158.h"
#include "../../matched/include/Obj11456.h"
#include "../../matched/include/Obj16160.h"
#include "../../matched/include/Obj16161.h"
#include "../../matched/include/Obj16163.h"
#include "../../matched/include/Obj16164.h"
#include "../../matched/include/Obj01319.h"
#include "../../matched/include/Obj02319.h"
#include "../../matched/include/Obj06994.h"
#include "../../matched/include/Obj11458.h"
#include "../../matched/include/Obj08873.h"
#include "../../matched/include/Obj01197.h"

struct AreaMan;
struct Tagged;
struct Ent;
struct Owner;
struct S14;
struct Cmd;
struct Dst648;
struct Src648;
struct Node;
struct Head;
struct Light;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Blob28 { u32 w[7]; };

struct Sys {
    u16   f00;
    u16   f02;
    void *f04;
    u32   f08;
    void *f0C;
    u16   f10;
    u16   f12;
    void *f14;
    void *f18;
    u16   f1C;
    u16   f1E;
    void *f20;
};

struct BbActEntry {
    u32 f00;
    u32 rest[9];
};

struct BbActSys_0204FE94 {
    u16 f00;
    u16 f02;
    void *f04;
    u32 f08;
    void *f0C;
    u16 f10;
    u16 f12;
    void *f14;
    struct BbActEntry *f18;
    u16 f1C;
    u16 f1E;
    void *f20;
};

struct BbActSlot { u16 id; u16 pad; u32 val; };

struct BbActRec { u32 f00; u8 b4; u8 b5; u8 b6; u8 b7; u32 type; };

struct BbActSys_02050084 {
    u16 f00;
    u16 f02;
    void *f04;
    u32 f08;
    struct BbActSlot *f0C;
    u16 f10;
    u16 f12;
    struct AreaMan *f14;
};

typedef signed int     s32;

typedef signed short   s16;

struct Vec3 { s32 a, b, c; };

struct BbActEntry_02050340 {
    u32   f00;
    u16   f04;
    u16   f06;
    u32   f08;
    u16   f0C;
    u16   f0E;
    u16   f10;
    u16   f12;
    u32   f14;
    u32   f18;
    u16   f1C;
    u16   f1E;
    u32   f20;
    u32   f24;
};

struct BbActDesc {          /* 0x24 bytes */
    u16 slot;               /* 0x00 */
    s16 v12;                /* 0x02 */
    s16 v14;                /* 0x04 */
    u8  k;                  /* 0x06 */
    u8  pad07;
    u32 flag;               /* 0x08 */
    u32 w;                  /* 0x0c */
    struct Vec3 pos;        /* 0x10 */
    u32 f1c;                /* 0x1c */
    u32 f20;                /* 0x20 */
};

struct BbActSys_02050340 {
    u16 f00;
    u16 f02;
    void *f04;
    u32 f08;
    struct BbActSlot *f0C;
    u16 f10;
    u16 f12;
    void *f14;
    struct BbActEntry_02050340 *f18;
    u16 f1C;
    u16 f1E;
    u32 f20;
};

struct BbActEntry_02050468 { u32 f00; u8 pad[0x24]; };

struct BbActSys_02050468 {
    u16 f00;
    u16 f02;
    void *f04;
    u8  pad_08[0x10];
    struct BbActEntry_02050468 *f18;
    u16 f1C;
    u16 f1E;
    void *f20;
};

typedef struct Cmd {
    u16 a : 14;
    u16 b : 1;
    u16 c : 1;
    u16 f02;
} Cmd;

struct Ent {
    u32   f00;
    u16   f04;
    u16   f06;
    u32 **f08;
    u16   f0c;
    u16   f0e;
    u16   f10;
    u16   f12;
    u16   f14;
    u16   f16;
    u32   f18;
    u8    pad_1C[4];
    void (*f20)(struct Owner *o, int i, u32 a);
    u32   f24;
};

struct Rec8 {
    u16 f00;
    u16 f02;
    u32 f04;
};

struct Owner {
    u32  f00;
    u32  f04;
    void (*f08)(u32 a0, u32 a1, u32 a2, u32 a3);
    u8  *f0c;
    u8   pad_10[8];
    struct Ent *f18;
    u16  f1C;
};

typedef struct tagLISTCB {
    void *head;
    void *tail;
} LISTCB;

typedef struct { int f0; char pad[0x24]; } E28_020507D0;

typedef struct { int pad0; int f4; char pad[0x10]; E28_020507D0 *f18; } Mgr_020507D0;

struct S8 {
    u16 h;
    u16 pad;
    u32 w;
};

struct S40 {
    u32 f0;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 f12;
    u32 f16;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f32;
    u32 f36;
};

typedef struct { int f0; char pad[0x24]; } E28_020508C4;

typedef struct { char pad[0x18]; E28_020508C4 *f18; } Mgr_020508C4;

struct S14 {
    u16 f : 14;
};

typedef void (*Fn)(void);

typedef struct Slot_02050A70 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 active : 1;             /* bit 0 of +0x0C */
    u32 torn   : 1;             /* bit 1 of +0x0C */
    u32 kill   : 1;             /* bit 2 of +0x0C */
    u32        : 29;
} Slot_02050A70;

typedef struct Slot_02050B14 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
} Slot_02050B14;

struct Ctx {
    u32  words[16];     /* 0x00 */
    u32  f40;           /* 0x40 */
    u32  f44;           /* 0x44 */
};

typedef struct { u32 x, y, z; } Vec3;

struct Emit {
    u32  f00;
    u8   pad04[0x08];
    u32  f0c;
    u32  f10;
    u32  f14;
    u8   pad18[0x1a];
    u16  f32;
    Vec3 f34;
    Vec3 f40;
    Vec3 f4c;
    u8   pad58[0x202];
    u8   f25a;
};

typedef struct {
    u8 pad_00[0x10];
    u8 *cur;
} Arena_02050F1C;

typedef struct {
    u32 x, y, z;
} VecFx32;

typedef struct {
    u32 m[9];
} MtxFx33;

typedef struct {
    u32 w[8];
} Blk32;

typedef struct {
    u32 w[9];
} Blk36;

struct Src648 {
    u32 f00, f04, f08, f0c, f10, f14, f18, f1c;
};

struct Dst648 {
    u8  pad00[0x20];
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u16 f30;
    u8  pad32[0x229];
    u8  f25b;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0204EBD4(u8 *src, void *heap);
extern struct AreaMan *func_02033C00(u32 size, u32 heap);
extern void func_0204F5A8(void *board, u32 idx);
extern void func_0204ED24(void *board);
extern u32 func_02033C9C(void *a);
extern u32 func_020307B0(void *p);
extern s32 func_02033CA8(struct AreaMan *p, u32 len);
extern u16  func_0204EF58(void *board, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_0204F10C(void *board, u32 id);
extern void func_0204F150(u8 *a0, int i);
extern void func_02046EFC(struct Tagged *p);
extern int func_0203422C(struct AreaMan *p, u32 start, s32 len);
extern s32  func_0204F428(void *board, u32 id, s16 v12, s16 v14, const struct Vec3 *src, u8 k, u32 w, u32 mode);
extern int func_0204F720(u32 a, u32 b, u32 *buf);
extern void func_0204F66C(int p0, int p1, int p2);
extern void func_0204F764(void *p, u32 idx, u32 *val);
extern void func_0204F794(void *p, u32 idx, u32 *val);
extern int func_020473D8(int a0);
extern void func_0204F2B4(int p0, int p1, int p2);
extern void func_0204F344(void *a0, u32 a1, int a2, int *out, int *in, u8 flag);
extern int func_020473EC(int a0);
extern u32 func_0204F2CC(u32 a, u16 b, u32 *out);
extern void DWCi_LSTlErase(void *ob);
extern u32 func_0204F704(u8 *a0, int i);
extern u32  OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 s);
extern u32   func_02052DC8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void  MI_CpuFill8(void *dst, u32 v, u32 n);
extern void func_02051620(void);
extern void func_0206168C(u32 *src);
extern u32 func_020621FC(u32 h);
extern void func_02061824(void *p);
extern int func_02062594(u32 id);
extern u32 func_02048AC4(void *ptr);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern int func_02046BFC(void);
extern int func_02046C10(void);
extern void func_0206164C(u8 *p);
extern void func_02061808(u8 *p);
extern void func_02052A50(u32 a, u32 b);
extern void func_02030DA8(u32 a, u32 b, u8 *c, u32 d);
extern void func_020528A8(u32 a);
extern void func_020528BC(u32 a);
extern int  func_020528D0(u32 o, u32 alloc);
extern int  func_02052984(u32 o, u32 alloc);
extern void func_02030EAC(struct Node *n);
extern void func_020467EC(int p0);
extern void func_02046858(const u32 *src);
extern void func_02046AFC(u8 *dst);
extern void func_02046B40(u8 *a0);
extern void func_020479D8(void);
extern void func_02048AD0(struct Light *l);
extern void func_020526A8(struct Head *h, u32 a);
extern void func_0206A9DC(void *p);
extern void func_0206AA0C(VecFx32 *p);
extern void func_0206DB80(void);
extern void MI_Copy36B(const void *src, void *dst);
extern void MTX_Identity33_(MtxFx33 *p);
extern int func_02052770(u32 a);
extern int func_02052634(char *p, int b, int c);
extern int func_020525A0(char *p, int b, void (*fn)(void *));
extern void func_020524C8(void *p);
extern void func_0205250C(char *p, char *q);
extern int func_02048A24(int a0, int a1, int a2, int a3, int a4, int a5,
                         int a6, int a7, int a8, int a9, int a10, int a11);
void *func_0204FE94(u16 a0, u16 a1, u32 a2, int heap);
void func_0204FFFC(struct BbActSys_0204FE94 *o);
u32 func_02050080(u32 *p);
void func_02050088(struct BbActSlot *p0);
void func_020500A0(int p0);
void func_020500B8(u32 *p);
u16 func_020500F0(struct BbActSys_02050084 *o, const struct BbActRec *recs, u32 n);
u32 func_02050238(struct BbActSys_02050084 *p, u32 b, u32 c);
void func_02050278(struct BbActSys_02050084 *o, u32 first, u32 count);
int func_02050304(struct BbActSys_02050084 *o, u32 slot);
u16 func_02050330(struct BbActSys_02050084 *o, int i);
u16 func_02050340(struct BbActSys_02050340 *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
void func_02050468(struct BbActSys_02050468 *o, u16 first, u32 count);
void func_020504D8(struct Owner *o);
void func_02050550(struct Owner *o, struct Ent *e);
void func_020506B8(struct Owner *o, struct Rec8 *e, u32 a2);
u32 func_02050738(void *p, void *q);
void func_02050790(LISTCB *list, int b, int c);
int func_020507A0(void *p, int idx, u32 x);
int func_020507D0(Mgr_020507D0 *p, int i);
void func_020507F0(void *p, int idx, u32 v);
void func_02050804(void *p, int idx, u32 v, u16 h);
void func_0205082C(void *p, int idx, u32 h);
u16 func_02050848(u8 *p, int i);
void func_0205085C(void *p, int idx, u32 v);
u16 func_02050880(u8 *p, int i);
int func_02050894(void *p, int idx, int j);
int func_020508C4(Mgr_020508C4 *p, int i);
u32 func_020508D8(u8 *o, u32 i);
u32 func_020508EC(u8 *p, int i, u16 *out);
int func_02050920(struct S14 *p);
int func_02050944(void *p, struct S14 *q);
Fn func_02050984(u32 id);
int func_020509E0(void);
int func_020509E8(void *p, void *q);
int func_02050A00(struct Ent *e, struct Cmd *c);
int func_02050A58(struct Ent *e, struct Cmd *c);
void func_02050A70(void);
void func_02050B14(u32 idx);
void func_02050B80(u32 heap);
void func_02050BE8(void);
int func_02050C04(int a, int b, int c, int d);
void *func_02050C30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap);
void func_02050DB8(u8 *p);
void func_02050ED4(void);
void *func_02050F1C(u32 size);
void *func_02050F4C(u32 size);
void *func_02050F7C(u32 size);
void *func_02050FAC(u32 size);
void *func_02050FDC(u32 size);
void *func_0205100C(u32 size);
void *func_0205103C(u32 size);
void *func_0205106C(u32 size);
void *func_0205109C(u32 size);
void *func_020510CC(u32 size);
void *func_020510FC(u32 size);
void *func_0205112C(u32 size);
void *func_0205115C(u32 size);
void *func_0205118C(u32 size);
void *func_020511BC(u32 size);
void *func_020511EC(u32 size);
int func_0205121C(u32 a, u32 b, u32 c);
void func_02051230(u8 *o, u32 a1, u32 a2, u32 a3);
void func_02051360(void *p, unsigned int a1, unsigned int a2, unsigned int a3);
void func_02051380(void *p, void *r);
void func_02051394(u32 *p);
void func_020513F8(void *p, int a);
void func_02051414(u8 *a0);
int func_020514F4(u32 *p);
int func_02051504(void);
int func_02051534(void);
int func_02051574(void);
int func_020515B4(void *p, int b, int c);
int func_020515CC(int *p, int a, int b, int c);
int func_02051614(int **p);
asm void KeyValHashKey(void);
void func_02051630(void **p, void *q);
void *func_02051640(char *p);
void func_02051648(struct Dst648 *this, struct Src648 *src, u16 a2, Vec3 *a3, Vec3 *a4, Vec3 *a5, u32 a6);
int func_02051758(int a0);
extern const char sBillboardAct[];
extern const struct Blob28 gBillboardActTpl;
extern Slot_02050A70 *g_02146A84;
extern struct Ctx *g_02146A88;
extern const char pkt_02050A70_File[];
extern const char g_020A7FC0[];
extern Vec3 g_020A1590;
extern Vec3 g_020A1584;
extern Vec3 g_020A1578;
extern const u32 g_020A15A8[];
extern VecFx32  g_020A159C;
extern u32      g_02148B4C[];
extern u32      g_02148B98[];
extern u32      g_02148C08[];






/*
 * The billboard_act.c system constructor, and the function that NAMES the
 * family: its __FILE__ word at 0x0204FFF4 is 0x020A7FB0, and
 * layout/file_anchors.txt fixes the string there as "billboard_act.c" (the NUL
 * of "billboard.c" at 0x020A7FAF is what pins its start).  Three allocations,
 * at source lines 94, 119 and 123, monotone in address -- the second,
 * independent check that this is one original translation unit.
 *
 * Allocate the 0x24-byte system object, stamp in the caller's heap id, the
 * two counts and the mode word, build the sub-board by copying a 28-byte
 * template out of rodata onto the stack and overwriting its first two
 * halfwords with the two counts, then allocate the two parallel arrays (the
 * count0 * 8 slot array and the count1 * 0x28 entry array) with their two
 * index pools, and finally run the per-element initialisers over both.
 *
 * Three shapes are load-bearing:
 *
 *   - The 28-byte template is ONE aggregate assignment from a rodata object
 *     into a `struct Blob28` LOCAL, which mwcc expands to a 16-byte ldm/stm
 *     pair with write-back plus a 12-byte pair without, reusing the bases the
 *     write-back left in sl and sb (the same expansion as the sibling
 *     constructor func_0204EBD4, src/matched/func_0204EBD4.c).  A byte array
 *     or a memcpy compiles to a copy loop instead.
 *   - The two halfword patches are written through casts ONTO the local
 *     (`*(u16 *)&tmp`), re-reading h->f10 and h->f1C rather than reusing the
 *     incoming parameters: the image issues `ldrh r2, [r6, #0x10]` and
 *     `ldrh r2, [r6, #0x1c]` between the stm and the call, which the
 *     parameters would not produce.
 *   - Both element loops use SEPARATE counters (`i` and `j`) and re-read
 *     their bound from the object at the bottom of the loop; the compare is
 *     signed (`blt`) on the promoted u16, so the counters are plain `int`.
 *
 * The template at 0x020A155C is attested `sole-ref` (its only referrer image
 * wide is this function's own pool word at 0x0204FFF8); the file string is
 * attested `string`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204FE94.c \
 *       --func func_0204FE94 --addr 0x0204FE94 --cc 1.1p1 --arm
 *   EXACT, 360 bytes, 10 relocation sites, all resolved.
 */
void *func_0204FE94(u16 a0, u16 a1, u32 a2, int heap)
{
    const char *file = sBillboardAct;
    struct Sys *h;
    struct Blob28 tmp;
    int i;
    int j;

    h = (struct Sys *)func_02030734(heap, 0x24, 1, file, 94);
    h->f00 = (u16)heap;
    h->f08 = a2;
    h->f10 = a0;
    h->f1C = a1;

    tmp = gBillboardActTpl;
    *(u16 *)&tmp = h->f10;
    *((u16 *)&tmp + 1) = h->f1C;
    h->f04 = func_0204EBD4((u8 *)(&tmp), (void *)heap);

    h->f0C = func_02030734(heap, h->f10 * 8, 1, file, 119);
    h->f14 = func_02033C00(h->f10, heap);
    h->f18 = func_02030734(heap, h->f1C * 0x28, 1, file, 123);
    h->f20 = func_02033C00(h->f1C, heap);

    for (i = 0; i < h->f10; i++) {
        func_02050088((struct BbActSlot *)((u8 *)h->f0C + i * 8));
    }
    for (j = 0; j < h->f1C; j++) {
        func_020500B8((u32 *)((u8 *)h->f18 + j * 0x28));
    }
    return h;
}






/*
 * billboard_act.c teardown.  The two-byte residue of the earlier notes
 * (the loaded entry word landing in r0 instead of r1) was the callee's
 * arity: func_0204F5A8 takes TWO arguments, and the second is the entry's
 * first word, which the image loads straight into r1 for the compare and
 * then passes on.  EXACT* because the unlabelled 8-byte getter at
 * 0x02050080 (`ldr r0,[r0,#4]; bx lr`, blx'd from ov021) follows the pool.
 */
void func_0204FFFC(struct BbActSys_0204FE94 *o)
{
    int i;

    for (i = 0; i < o->f1C; i++) {
        if (o->f18[i].f00 != 0xFFFF) {
            func_0204F5A8(o->f04, o->f18[i].f00);
        }
    }
    func_02033C9C(o->f20);
    func_020307B0(o->f18);
    func_02033C9C(o->f14);
    func_020307B0(o->f0C);
    func_0204ED24(o->f04);
    func_020307B0(o);
}





/*
 * func_02050084 (`bx lr`) is the return instruction of this getter: the layout has a function entry
 * there, but the bytes are the ones this function emits, so it has no separate definition.
 */
u32 func_02050080(u32 *p)
{
    return p[1];
}















void func_02050088(struct BbActSlot *p0)
{
    p0->id = 0xFFFF;
    p0->val = 0;
}









void func_020500A0(int p0){ ((struct Obj02611 *)p0)->f10 = (unsigned short)0; ((struct Obj02611 *)p0)->f12 = (unsigned short)0; ((struct Obj02611 *)p0)->f14 = (unsigned short)0; ((struct Obj02611 *)p0)->f1C = (unsigned short)0; }









/*
 * Second of the three 0x0204F6xx-series object initialisers; the eight bytes
 * of literal pool at 0x020500EC (0x0000FFFF) are this function's own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020500B8.c \
 *       --func func_020500B8 --addr 0x020500B8 --cc 1.1p1 --arm
 */
void func_020500B8(u32 *p)
{
    p[0] = 0xFFFF;
    p[2] = 0;
    ((struct Obj02015 *)p)->fC = 0;
    ((struct Obj02015 *)p)->fE = 0;
    func_020500A0((int)p);
    p[6] = 0;
    p[8] = 0;
    p[9] = 0;
}









/*
 * billboard_act.c: take n slot indices from the pool at +0x14 and fill one
 * slot record per request (0: board slot, 1: board slot plus func_0204F10C,
 * 2: an external payload word with the 0xFFFF sentinel id).  The 28-byte
 * scheduling wall of the earlier notes was the missing `const` on the
 * request array (its byte loads then batch ahead of the outgoing-argument
 * stores, and case 2's payload load hoists above the sentinel store); with
 * it the plain subscript o->f0C[base + i] and literal zeros are exact.
 */
u16 func_020500F0(struct BbActSys_02050084 *o, const struct BbActRec *recs, u32 n)
{
    int base;
    u32 i;

    base = func_02033CA8(o->f14, n);
    for (i = 0; i < n; i++) {
        const struct BbActRec *e = &recs[i];
        u16 id;
        switch (e->type) {
        case 0:
            o->f0C[base + i].id = func_0204EF58(o->f04, e->f00, e->b4, e->b5, e->b6, e->b7);
            o->f0C[base + i].val = 0;
            break;
        case 1:
            id = func_0204EF58(o->f04, e->f00, e->b4, e->b5, e->b6, e->b7);
            func_0204F10C(o->f04, id);
            o->f0C[base + i].id = id;
            o->f0C[base + i].val = 0;
            break;
        case 2:
            o->f0C[base + i].id = 0xFFFF;
            o->f0C[base + i].val = e->f00;
            break;
        }
    }
    return base;
}








/*
 * Appends one {u16, u32} record (8 bytes, id in the low half) to the array
 * the caller's object keeps at +12, at the slot func_02033CA8 hands back for
 * the pool at +20; the return is the slot narrowed to u16.
 *
 * The four bytes that cost three attempts are the first store's register
 * pairing: the pointer form `*(u16 *)(*(u32 *)((char *)p + 12) + idx * 8)`
 * compiles the same two instructions as the original but allocates them the
 * other way round (`ldr r1,[r6,#12]; lsl r2,r0,#3; strh r5,[r1,r2]` against
 * the original's r2/r1), a whole-function DIFF at +001C.  Written as an
 * array subscript on an 8-byte struct element,
 * `((struct S8 *)*(u32 *)((char *)p + 12))[idx].h`, it comes out EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050238.c \
 *       --func func_02050238 --addr 0x02050238 --cc 1.1p1 --arm
 *   EXACT, 64 bytes, 1 relocation site, resolved [label].
 */
u32 func_02050238(struct BbActSys_02050084 *p, u32 b, u32 c)
{
    int idx = func_02033CA8(p->f14, 1);

    p->f0C[idx].id = b;
    p->f0C[idx].val = c;
    return (u16)idx;
}








/*
 * billboard_act.c: release `count` slot records from `first`: the board
 * record through func_0204F150(board, id) when the id is live, the payload
 * through func_02046EFC when nonzero, then reset the record and return the
 * index range to the pool.  func_0204F150 takes TWO arguments (the loaded
 * id is the r1 the image compares); the rest is plain subscripts.
 */
void func_02050278(struct BbActSys_02050084 *o, u32 first, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++) {
        if (o->f0C[first + i].id != 0xFFFF) {
            func_0204F150(o->f04, o->f0C[first + i].id);
        }
        if (o->f0C[first + i].val != 0) {
            func_02046EFC((struct Tagged *)o->f0C[first + i].val);
        }
        func_02050088(&o->f0C[first + i]);
    }
    func_0203422C(o->f14, first, count);
}






int func_02050304(struct BbActSys_02050084 *o, u32 slot)
{
    func_02050088(&o->f0C[slot]);
    return func_0203422C(o->f14, slot, 1);
}







u16 func_02050330(struct BbActSys_02050084 *o, int i)
{
    return o->f0C[i].id;
}






/*
 * billboard_act.c: take `count` consecutive entry indices from the pool at
 * +0x20 and build one board element per 0x24-byte descriptor through
 * func_0204F428, returning the first index (0xFFFF when the pool is full).
 * Levers, all measured: the descriptor array is `const` (its field loads
 * then move above the entry stores, 62 -> 15 bytes); the element id is a
 * named local passed on to func_0204F720 rather than re-read; the caller's
 * view of func_0204F428 takes s16 v12/v14 (ldrsh, no narrowing); all five
 * locals at function scope in the order p, e, idx, i, r (loop-scoped e/p
 * swap the i and p registers).
 */
u16 func_02050340(struct BbActSys_02050340 *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode)
{
    const struct BbActDesc *p;
    struct BbActEntry_02050340 *e;
    int idx;
    u32 i;
    s32 r;

    idx = func_02033CA8((struct AreaMan *)o->f20, count);
    if (idx == -1) {
        return 0xFFFF;
    }
    for (i = 0; i < count; i++) {
        e = &o->f18[idx + i];
        p = &d[i];

        func_020500B8((u32 *)e);
        e->f04 = base + p->slot;
        r = func_0204F428(o->f04, o->f0C[e->f04].id, p->v12, p->v14, &p->pos, p->k, p->w, mode);
        e->f00 = r;
        e->f20 = p->f1c;
        e->f24 = p->f20;
        func_0204F720((u32)o->f04, r, (u32 *)(&p->flag));
        e->f1C = 0x3FFF;
    }
    return idx;
}






/*
 * billboard_act.c: release `count` entries from `first` and give the index
 * range back to the pool.  The earlier 2-byte floor (add operand order) and
 * the hand-copied stride came from writing the address arithmetic by hand;
 * the source is plain subscripts, o->f18[first + i], in a for loop.
 */
void func_02050468(struct BbActSys_02050468 *o, u16 first, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++) {
        func_0204F5A8(o->f04, o->f18[first + i].f00);
        func_020500B8((u32 *)(&o->f18[first + i]));
    }
    func_0203422C(o->f20, first, count);
}






/*
 * Tick every live entry of the 0x28-stride array at o->f18: for each index
 * below the live count at o->f1C, skip the entry whose first word is the
 * sentinel 0xFFFF, otherwise call its per-entry hook (a function pointer at
 * +0x20, taking the owner, the index and the entry's +0x24 word) when one is
 * installed, then hand the entry to func_02050550.
 *
 * Two shapes are load-bearing:
 *
 *   - The live count is re-read from o->f1C at the BOTTOM of the loop
 *     (`ldrh r0, [r5, #0x1c]` at +0x60) as well as at the top, because the
 *     hook and func_02050550 may both change it.  Caching it in a local gives
 *     one load and a different loop shape.
 *   - The count is a u16 but the comparison is SIGNED (`blt`, and `pople` on
 *     the entry guard), so the index is a plain `int` and the count is
 *     promoted, not an unsigned compare.
 *
 * The 0xFFFF sentinel lives in the pool at 0x0205054C rather than as an
 * immediate, which is why r7 is loaded once before the loop.
 *
 * UNBLOCKED 2026-09-21: func_02050550 was filed EXACT
 * (src/matched/func_02050550.c, shard arm9/pkt_02050340.json), so the single
 * relocation site, the `bl` at +0x5C, is now attested `matched` and this file
 * verifies EXACT unchanged.  No C was altered to promote it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020504D8.c \
 *       --func func_020504D8 --addr 0x020504D8 --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */
void func_020504D8(struct Owner *o)
{
    int i = 0;
    int n = o->f1C;

    if (n <= 0) {
        return;
    }
    do {
            struct Ent *e = (struct Ent *)((u8 *)o->f18 + i * 0x28);

            if (e->f00 != 0xFFFF) {
                if (e->f20 != 0) {
                    e->f20(o, i, e->f24);
                }
                func_02050550(o, e);
            }
        i++;
    } while (i < o->f1C);
}






void func_02050550(struct Owner *o, struct Ent *e)
{
    Cmd *c;
    u32  s2;
    u32  s1;
    u16  s0;
    u16  rem;
    u8  *p;

    if (e->f08 == 0 || e->f18 == 0) {
        return;
    }
    if (e->f12 != 0) {
        e->f12 = e->f12 - 1;
        return;
    }

    c = (Cmd *)((u8 *)e->f08[e->f0e] + e->f10 * 4);
    while (func_02050920((struct S14 *)c)) {
        if (func_02050944(e, (struct S14 *)c)) {
            return;
        }
        c = (Cmd *)((u8 *)e->f08[e->f0e] + e->f10 * 4);
    }

    e->f10 = e->f10 + 1;
    s0 = c->a;
    rem = c->f02;

    p = (u8 *)(e->f04 * 8);
    p = p + (u32)o->f0c;
    if (((struct Obj06991 *)p)->f4 != 0) {
        func_020506B8(o, (struct Rec8 *)p, s0);
    } else {
        func_0204F66C(o->f04, e->f00, (int)(&s0));
    }

    if (c->b) {
        s2 = 1;
    } else {
        s2 = 0;
    }
    if (c->c) {
        s1 = 1;
    } else {
        s1 = 0;
    }

    func_0204F764((void *)o->f04, e->f00, &s2);
    func_0204F794((void *)o->f04, e->f00, &s1);

    if (rem != 0) {
        rem = rem - 1;
    }
    e->f12 = rem;
}






void func_020506B8(struct Owner *o, struct Rec8 *e, u32 a2)
{
    u32 s4;
    u32 s3;
    u32 s2;
    u32 base;
    u32 zero;

    base = func_020473D8(e->f04);
    func_0204F2B4(o->f04, e->f00, (int)(&s4));
    zero = 0;
    func_0204F344((void *)o->f04, e->f00, a2, (int *)(&s3), (int *)(&s2), zero);
    if (o->f08 != 0) {
        o->f08(zero, s4, base + s3, s2);
    }
}






/*
 * An 88-byte ARM function in the 0x02050000 block.  It reads a record index
 * out of the object at +4, resolves it through func_020473EC, then calls
 * func_0204F2CC with the object's word at +4, the halfword at q[0] and a
 * stack scratch slot; when the hook pointer at p+8 is non-null it calls the
 * hook with the scratch value and the resolved record.  The null case returns
 * the func_0204F2CC result, which is why the `cmp ip, #0` sits after the
 * second call with r0 still live.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050738.c \
 *       --func func_02050738 --addr 0x02050738 --cc 1.1p1 --arm
 */
u32 func_02050738(void *p, void *q)
{
    u32 v = func_020473EC(((struct Obj06992 *)q)->f4);
    u32 t;
    u32 r = func_0204F2CC(((struct Obj11453 *)p)->f4, ((struct Obj06992 *)q)->f0, &t);
    u32 (*hook)(u32, u32, u32, u32) = *(u32 (**)(u32, u32, u32, u32))((char *)p + 8);

    if (hook == 0)
        return r;
    return hook(1, t, v, 0x20);
}






/*
 * sdk:      DWCi_LSTlPopFront (libdwcutil.TWL.HYB.a list.o)
 */
void func_02050790(LISTCB *list, int b, int c)
{
    DWCi_LSTlErase(list->tail);
}






/*
 * The listing labels this function at 0x020507A4, not 0x020507A0: disasm.py
 * only auto-labels a prologue that saves lr, so the four bytes at 0x020507A0
 * that home the four argument registers (`push {r0,r1,r2,r3}`, the tell for
 * an address-taken register parameter,
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md) are
 * printed as a stray `.word` and the label lands on the `push {r3, lr}` four
 * bytes later.  The real entry is 0x020507A0 and the function is 48 bytes,
 * not the worklist's 44; verified from 0x020507A0, where the extent runs to
 * the next label at 0x020507D0.
 *
 * The third parameter is not a pointer but a scalar whose address is taken
 * (`&x`, compiled as the home slot).  Written as `u8 *buf` it compiles to 32
 * bytes; as `u8 buf[16]`, 32; only `&x` on a scalar reproduces the home push.
 *
 * Reads element `idx` of a 40-byte record array hanging off p+24 and hands it,
 * together with p's own word at +4 and the caller's buffer address, to
 * func_0204F720.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020507A0.c \
 *       --func func_020507A0 --addr 0x020507A0 --cc 1.1p1 --arm
 */
int func_020507A0(void *p, int idx, u32 x)
{
    return func_0204F720(((struct Obj11454 *)p)->f4,
                         *(u32 *)(((struct Obj11454 *)p)->f18 + idx * 40),
                         &x);
}






/*
 * Leaf witness for ov021 0x021BBF10 / 0x021BC138 (lane wA1-12).
 */
int func_020507D0(Mgr_020507D0 *p, int i)
{
    return func_0204F704((u8 *)p->f4, p->f18[i].f0);
}






void func_020507F0(void *p, int idx, u32 v)
{
    char *e = (char *)(((struct Obj16154 *)p)->f18 + idx * 40);
    ((struct Obj16155 *)e)->f18 = v;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050804.c \
 *       --func func_02050804 --addr 0x02050804 --cc 1.1p1 --arm
 */
void func_02050804(void *p, int idx, u32 v, u16 h)
{
    char *e = (char *)(((struct Obj16156 *)p)->f18 + idx * 40);

    ((struct Obj02611 *)e)->f8 = v;
    ((struct Obj02611 *)e)->fC = h;
    ((struct Obj02611 *)e)->fE = 0;
    func_020500A0((int)e);
}






void func_0205082C(void *p, int idx, u32 h)
{
    char *e = (char *)(((struct Obj16157 *)p)->f18 + idx * 40);
    ((struct Obj02611 *)e)->fE = h;
    func_020500A0((int)e);
}






/*
 * Leaf witness for ov021 0x0219F058 and siblings (lane wA1-06).
 */
u16 func_02050848(u8 *p, int i)
{
    return *(u16 *)(*(u8 * *)&((struct Obj11455 *)p)->f18 + i * 40 + 0xe);
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0205085C.c \
 *       --func func_0205085C --addr 0x0205085C --cc 1.1p1 --arm
 */
void func_0205085C(void *p, int idx, u32 v)
{
    char *e = (char *)(((struct Obj16158 *)p)->f18 + idx * 40);

    func_020500A0((int)e);
    ((struct Obj02611 *)e)->f10 = v;
}






u16 func_02050880(u8 *p, int i)
{
    return *(u16 *)(*(u8 * *)&((struct Obj11455 *)p)->f18 + i * 40 + 0x10);
}






/*
 * PROMOTED from src/pending/func_02050894.c: it was parked at MATCH because
 * the only branch in the image to 0x02050738 is the one inside this function.
 * 0x02050738 (88 bytes, pkt_02050340) is now matched, so the site resolves by
 * the `matched` class with no change to the C.  The file's packet id is
 * corrected from pkt_02050340 to pkt_02050894, which is the packet the
 * worklist gives 0x02050894.
 *
 * Moves one word between two parallel record arrays of the object: the index
 * is read out of the 40-byte record table at p+24, the value out of the
 * 8-byte-pair array at p+12, the value is stored back into the record the
 * index names, and the record is handed to func_02050738.
 *
 * The listing's extent runs 140 bytes because the follower at 0x020508C4 is an
 * unlabelled leaf accessor (no prologue that saves lr).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050894.c \
 *       --func func_02050894 --addr 0x02050894 --cc 1.1p1 --arm
 */
int func_02050894(void *p, int idx, int j)
{
    struct S8  *arr = *(struct S8 * *)&((struct Obj11456 *)p)->fC;
    struct S40 *rec = *(struct S40 * *)&((struct Obj11456 *)p)->f18;
    u16 e = rec[idx].f4;
    u32 v = arr[j].w;

    arr[e].w = v;
    return func_02050738(p, &arr[e]);
}






int func_020508C4(Mgr_020508C4 *p, int i)
{
    return p->f18[i].f0;
}






u32 func_020508D8(u8 *o, u32 i)
{
    return *(u16 *)(*(u8 * *)&((struct Obj16160 *)o)->f18 + i * 0x28 + 4);
}






u32 func_020508EC(u8 *p, int i, u16 *out)
{
    u16 v = *(u16 *)(*(u8 * *)&((struct Obj16161 *)p)->f18 + i * 40 + 0x1c);
    *out = v;
    return (u16)(v + 4 + 0xC000) <= 3;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050920.c \
 *       --func func_02050920 --addr 0x02050920 --cc 1.1p1 --arm
 */
int func_02050920(struct S14 *p)
{
    return func_02050984(p->f) != 0;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050944.c \
 *       --func func_02050944 --addr 0x02050944 --cc 1.1p1 --arm
 */
int func_02050944(void *p, struct S14 *q)
{
    int (*fn)(void *, struct S14 *);

    fn = (int (*)(void *, struct S14 *))func_02050984(q->f);
    ((struct Obj16163 *)p)->f1C = q->f;
    return fn(p, q);
}






/*
 * PROMOTED from src/pending/func_02050984.c 2026-09-21 (wave 4, billboard_act).
 * The C is UNCHANGED: it was parked at MATCH* because three of its four ABS32
 * pool words -- 0x020509E0, 0x02050A00 and 0x02050A58 -- each had exactly one
 * mention image wide, the pool word inside this very function, so neither
 * `label` nor `literal` reached them.  All three handlers are now filed EXACT
 * (src/matched/func_020509E0.c, func_02050A00.c, func_02050A58.c, shard
 * arm9/pkt_02050984.json), so every site resolves by the `matched` class and
 * this file verifies EXACT* with no edit to the body.
 *
 * EXACT*, not EXACT: the listing's extent runs 100 bytes because the follower
 * at 0x020509E0 is reached only through this function's own pool word and has
 * no prologue that saves lr, so disasm.py does not label it.  Report
 * 0x020509E0 as a seed for layout/function_starts.txt; it is never a byte
 * difference.
 *
 * The switch normalises the id with two subtracts and no `mov` of the base,
 * which is the whole reason the case labels read 0x3FFC..0x3FFF: the image
 * subtracts 0x3FC and then 0x3C00, i.e. 0x3FFC, and spelling the cases
 * 0x43FC..0x43FF makes the second subtract `#0x4000` and the four case arms
 * come out in the wrong order.  Writing the cases in DESCENDING source order
 * is what reproduces the image's arm order (case 0x3FFF's arm nearest the
 * table); ascending order puts case 0x3FFC's arm there and differs in four
 * branch instructions.
 *
 * `return <function address>;` is the shape: each arm is `ldr r0, [pc, #n];
 * bx lr` and the fall-through is `mov r0, #0; bx lr`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050984.c \
 *       --func func_02050984 --addr 0x02050984 --cc 1.1p1 --arm
 */
Fn func_02050984(u32 id)
{
    switch (id) {
    case 0x3FFF: return (Fn)func_020509E0;
    case 0x3FFE: return (Fn)func_020509E8;
    case 0x3FFD: return (Fn)func_02050A00;
    case 0x3FFC: return (Fn)func_02050A58;
    }
    return 0;
}





/*
 * The second arm of the four-entry handler table func_02050984 dispatches
 * through (its pool word at 0x020509D0).  Eight bytes, a leaf that returns the
 * nonzero constant the dispatch caller tests, and one of the pool words that
 * keeps src/pending/func_02050984.c wildcarded until it has an EXACT entry.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020509E0.c \
 *       --func func_020509E0 --addr 0x020509E0 --cc 1.1p1 --arm
 */
int func_020509E0(void)
{
    return 1;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020509E8.c \
 *       --func func_020509E8 --addr 0x020509E8 --cc 1.1p1 --arm
 */
int func_020509E8(void *p, void *q)
{
    ((struct Obj02611 *)p)->fE = ((struct Obj16164 *)q)->f2;
    func_020500A0((int)p);
    return 0;
}






/*
 * The third arm of the handler table func_02050984 dispatches through (see
 * src/pending/func_02050984.c).  88 bytes, a leaf: the command halfword at
 * c->f02 packs two bytes, a repeat count in the high half and a value in the
 * low half.  While the entry's repeat counter at +0x14 is below the count,
 * store the value at +0x10 and bump the counter; once it reaches the count,
 * reset the counter and advance +0x10 by one instead.  +0x12 is zeroed on
 * both paths.  Returns 0 (the "command consumed, keep going" verdict the
 * dispatcher in func_02050944 tests).
 *
 * The comparison is SIGNED (`bge`), so both sides are promoted `int`s and the
 * counter is compared as an int, not as an unsigned halfword.
 *
 * Two shapes are load-bearing, both worth 8 bytes each:
 *
 *   - The high byte must land in a `u8` LOCAL, not be written inline in the
 *     comparison.  `if (n < ((v & 0xff00) >> 8 & 0xff))` lets mwcc fold the
 *     shift into the compare's shifter operand (`cmp r2, r1, asr #8`) and drop
 *     the redundant `and #0xff` entirely, losing the original's separate
 *     `asr r1,r1,#8` / `and r1,r1,#0xff` pair (80 bytes, 56 out).
 *   - The LOW byte must be extracted into its own local BEFORE the `if`, not
 *     spelled `v & 0xff` at its single use inside the taken arm.  The original
 *     issues `and r3, r3, #0xff` above the `bge`; written at the use it lands
 *     after it, which is the last 8 bytes (88 bytes, 8 out).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050A00.c \
 *       --func func_02050A00 --addr 0x02050A00 --cc 1.1p1 --arm
 */
int func_02050A00(struct Ent *e, struct Cmd *c)
{
    int v = c->f02;
    int n = e->f14;
    unsigned char hi = (unsigned char)((v & 0xff00) >> 8);
    unsigned char lo = (unsigned char)v;

    if (n < hi) {
        e->f10 = lo;
        e->f12 = 0;
        e->f14 = (u16)(n + 1);
    } else {
        int cur = e->f10;
        e->f14 = 0;
        e->f12 = 0;
        e->f10 = (u16)(cur + 1);
    }
    return 0;
}





/*
 * The fourth arm of the handler table func_02050984 dispatches through (its
 * pool word at 0x02050980-ish; see src/pending/func_02050984.c).  Twenty
 * bytes, a leaf: it loads the command's second halfword (`c->f02`), zeroes the
 * entry's +0x12 counter, stores the halfword at +0x10 and returns 0.
 *
 * The zero is materialised once and reused for both the +0x12 store and the
 * return (`mov r1,#0 ... mov r0,r1`), which is what a single `0` constant
 * shared between the store and the `return 0;` produces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050A58.c \
 *       --func func_02050A58 --addr 0x02050A58 --cc 1.1p1 --arm
 */
int func_02050A58(struct Ent *e, struct Cmd *c)
{
    u16 v = c->f02;

    e->f12 = 0;
    e->f10 = v;
    return 0;
}





/*
 *           02050A70..02050B14 - BOTH unresolved sites are the `bl` to it,
 *           and this function holds the only two branches to 0x02050B14 in
 *           the whole image, so `label` has nothing to point at and no cut
 *           frees it.  It closes only when 0x02050B14 itself has a shard
 *           entry, and that body is the one-register allocator residue
 *           written up in docs/notes/pkt_02050A70.c.txt (44 differing bytes,
 *           no source reaches it).  Chain row.
 *
 *           All 164 concrete bytes reproduce, including the third site
 *           (g_02146A84, literal x5).  The counter is `int`, not `u32`: the
 *           loop's back edge is `blt`.
 *
 * Sweep the four 16-byte slots of the global bank at 0x02146A84 and retire
 * the ones whose state bits say so: a slot whose bit 0 of +0x0C is set has it
 * cleared, and if it is still busy (bits 11.. of +0x08) its teardown routine
 * runs and the "torn down" bit (bit 1) is set; a slot whose bit 2 is set has
 * it cleared and the teardown routine runs.  The bank pointer is re-read
 * after every store (`ldr r0, [r5]`), which is what the repeated reads say:
 * the store can alias the global itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02050A70.c \
 *       --func func_02050A70 --addr 0x02050A70 --cc 1.1p1 --arm
 */
void func_02050A70(void)
{
    int i;

    if (g_02146A84 == 0)
        return;

    for (i = 0; i < 4; i++) {
        if (g_02146A84[i].active) {
            g_02146A84[i].active = 0;
            if (g_02146A84[i].unk08 >> 11) {
                func_02050B14(i);
                g_02146A84[i].torn = 1;
            }
        }
        if (g_02146A84[i].kill) {
            g_02146A84[i].kill = 0;
            func_02050B14(i);
        }
    }
}





/*
 * CLOSES the two-wave wall written up at the top of docs/notes/pkt_02050A70.c.txt
 * (44 differing bytes, diagnosed there as a one-register allocator shift with
 * "no source shape that reaches it").  The diagnosis was wrong: the residue was
 * a WRONG RECORD STRIDE, not an allocation tie.  The note's reconstruction read
 * the field as `g_02146A84[idx].unk_08` over 16-byte records but spelled the
 * index arithmetic so that the compiler emitted a multiply; the image emits
 * `add r1, r3, r4, lsl #4` -- a shift, because 16 is a power of two -- and
 * `mul r2, r4, r1` ONLY for the SECOND, independent 12-byte stride of the I/O
 * register address (0x040000B8 + idx * 12).  Declaring the record struct as
 * four plain u32 words (16 bytes) and subscripting it normally gives the shift,
 * and every register then falls out identical: the whole 44-byte residue was
 * downstream of that one address computation.
 *
 * Read the 3D engine's per-engine configuration word out of the slot bank and
 * repack it into the display register at 0x040000B8 + idx*12: dest bit 30 from
 * source bit 1, dest bit 26 from source bit 5, dest 23:24 from source 7:8,
 * dest 21:22 from source 9:10 and dest 0:20 from source 11:31, under an
 * interrupt-disabled critical section.
 *
 * The OR-chain ORDER is load-bearing and is the note's one surviving finding:
 * the bit-30 term is written FIRST and the bit-26 term SECOND, because the
 * compiler fully materialises the second operand of a commutative chain
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md)
 * and the image materialises the bit-26 term (`lsl #0x1a; lsr #0x1f; lsl #0x1a`)
 * while folding the other three placements into the ORs' shifter operands.
 * Written in descending destination order the four extracts come out mirrored.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050B14.c \
 *       --func func_02050B14 --addr 0x02050B14 --cc 1.1p1 --arm
 *   EXACT, 108 bytes, 3 relocation sites, all resolved.
 */
void func_02050B14(u32 idx)
{
    u32 s = OS_DisableInterrupts();
    u32 v = g_02146A84[idx].unk08;

    *(volatile u32 *)(0x040000B8 + idx * 12) =
        ((v << 30) >> 31) << 30 |
        ((v << 26) >> 31) << 26 |
        ((v << 23) >> 30) << 23 |
        ((v << 21) >> 30) << 21 |
        (v >> 11);

    OS_RestoreInterrupts(s);
}






/*
 * Allocate the 0x48-byte singleton on the caller's heap and publish it at
 * 0x02146A88, zero its first sixteen words, then clear the two trailing word
 * fields at +0x40 and +0x44.
 *
 * The heap id is the incoming r0, untouched: the allocator's first argument is
 * the parameter, and its third (the clear flag, 0) is CSE'd off the loop
 * counter's own zero, which is why no `mov r0` appears and r4 is zeroed before
 * the call.
 *
 * The global is a pointer VARIABLE, and both the zero loop and the two field
 * stores re-dereference it: a store through the pointer could overwrite the
 * pointer itself, so only `g[i] = 0` inside the loop and `g->f40`/`g->f44`
 * afterwards reproduce the four separate loads of the global.
 */
void func_02050B80(u32 heap)
{
    int i = 0;

    g_02146A88 = func_02030734(heap, 0x48, i, pkt_02050A70_File, 190);

    for (i = 0; i < 16; i++) {
        ((u32 *)g_02146A88)[i] = 0;
    }

    g_02146A88->f40 = 0;
    g_02146A88->f44 = 0;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050BE8.c \
 *       --func func_02050BE8 --addr 0x02050BE8 --cc 1.1p1 --arm
 */
void func_02050BE8(void)
{
    if (func_02051504() == 0)
        return;
    func_02051534();
    func_02051574();
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050C04.c \
 *       --func func_02050C04 --addr 0x02050C04 --cc 1.1p1 --arm
 */
int func_02050C04(int a, int b, int c, int d)
{
    return (int)func_02050C30(a, b, c, 5, 6, 63, d);
}





/*
 * particle.c, the emitter constructor (wave 13): find a free slot among the
 * sixteen in the 0x02146A88 table, allocate a 0x260-byte emitter (particle.c
 * line 285), clear it, copy the three default vectors in as struct
 * assignments, clear flag bit 0, wire the span fields from (a0, a1), publish
 * the emitter in its slot, optionally build the 3D block (a2 == 1), and store
 * func_02052DC8's handle at +0.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02050C30.c.txt: size-exact at 392 with 37
 * bytes out inside the final argument setup, permuter exhausted): the
 * per-slot table 0x020A15A8 is CONST, `extern const u32 g_020A15A8[];`.
 * Without const the element load may not move above the two argument stores
 * to the outgoing area (they could alias it), so the compiler schedules the
 * truncations and stores first; const lets it issue the table base load
 * first and the element load in the middle, as the image does.  The same
 * mechanism as docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md,
 * applied to a global array.  The note's argument order (a3, a4, a5 each
 * truncated with a (u16) cast at the use) and its three other decisions all
 * stand.
 */
void *func_02050C30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap)
{
    struct Emit *e;
    u32 *tab;
    int i = 0;

    tab = g_02146A88->words;
    do {
        if (tab[i] == 0)
            break;
        i++;
    } while (i < 16);
    if (i >= 16)
        return 0;

    e = (struct Emit *)func_02030734((u16)heap, 0x260, 0, g_020A7FC0, 285);
    MI_CpuFill8(e, 0, 0x260);
    e->f34 = g_020A1590;
    e->f40 = g_020A1584;
    e->f4c = g_020A1578;
    e->f32 = e->f32 & ~1u;
    MI_CpuFill8((void *)a0, 0, a1);
    e->f0c = a0;
    e->f10 = a0;
    e->f14 = a0 + a1;
    e->f25a = (u8)i;
    g_02146A88->words[i] = (u32)e;

    if (a2 == 1)
        func_02051648((struct Dst648 *)e, 0, 0x2000, 0, 0, 0, heap);

    e->f00 = func_02052DC8(g_020A15A8[i], 0x18, 0xc8, (u16)a3, (u16)a4, (u16)a5);
    return e;
}





/*
 * Emitter teardown: release the two 0x40-entry resource tables (either as a
 * whole through func_0206168C / func_02061824, or entry by entry through
 * func_020621FC / func_02062594 depending on the flag byte at +0x258), drop
 * the block at +4 unless the +0x32 bit-0 bitfield says otherwise, unpublish
 * the emitter from the singleton's sixteen-slot table, release the 3D block
 * at +0x20 and free the record.
 *
 * CLOSES both residues of docs/notes/func_02050DB8.c.txt.
 *
 * 1. The note's HARD BLOCKER is gone without filing anything: 0x0206168C
 *    (and 0x02061824) had no branch outside this range, but both are traced
 *    `func_` labels, so the sole-ref/code sub-kind added 2026-09-21 attests
 *    them.  All nine sites resolve, none wildcarded.
 *
 * 2. The note's 20-byte register swap in the sixteen-entry search loop is
 *    closed by writing that loop WITHOUT a cursor local: `g_02146A88->words[j]`
 *    drawn fresh at both the read and the store, not `a = g_02146A88; a[j]`.
 *    Found with tools/permuter.py (hill, budget 500, mutation `expand(a x2)`).
 *    The note ruled out declaration order, a separate index, hoisting the
 *    counter and the pointer-walk form, but never tried expanding the cursor
 *    away; with the cursor gone the array pointer lands in r2 and the index
 *    in r1, which is the image's assignment.  The note's other finding for
 *    this loop still holds and is still needed: the element goes into a named
 *    local `t` before the compare, or the compare comes out `cmp r5, r0`.
 *
 * Two more spelling tells found on the way to size-exact, neither in the note:
 *   * the two 0x40-entry loops read the element as `((u32 *)(p + 0x58))[i]`
 *     but store it as `*(u32 *)(p + i * 4 + 0x58)`.  Spelled the SAME way at
 *     both ends the compiler CSEs the address into a callee-saved register
 *     and holds it across the call, which drops the image's second
 *     `add r0, r5, r6, lsl #2` -- four bytes per loop, eight in total, and a
 *     sixth register in the frame.  Two different spellings of one address
 *     defeat the CSE and give the image's recompute-per-use.
 *   * the +0x32 guard is `((u32)(f << 31) >> 31) == 0`: the cast to u32 is
 *     what makes the second shift `lsrs` rather than `asrs` (the u16 field
 *     promotes to int, and a plain `>> 31` on an int is arithmetic).  A
 *     `& 1` mask folds to a single `tst` and is four bytes short, per the
 *     note.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050DB8.c \
 *       --func func_02050DB8 --addr 0x02050DB8 --cc 1.1p1 --arm
 *   EXACT, 284 bytes, 9 relocation sites, all resolved.
 */
void func_02050DB8(u8 *p)
{
    int i;
    u32 z = 0;

    func_02051620();

    if (p[0x258] & 1) {
        func_0206168C((u32 *)(p + 0x58));
    } else if (p[0x258] & 2) {
        for (i = 0; i < 0x40; i++) {
            if (((u32 *)(p + 0x58))[i] != 0) {
                func_020621FC(((u32 *)(p + 0x58))[i]);
                *(u32 *)(p + i * 4 + 0x58) = z;
            }
        }
    }

    if (p[0x258] & 4) {
        func_02061824(p + 0x158);
    } else if (p[0x258] & 8) {
        for (i = 0; i < 0x40; i++) {
            if (((u32 *)(p + 0x158))[i] != 0) {
                func_02062594(((u32 *)(p + 0x158))[i]);
                *(u32 *)(p + i * 4 + 0x158) = z;
            }
        }
    }

    {
        u32 h = ((struct Obj01319 *)p)->f4;
        p[0x258] = (u8)z;
        ((struct Obj01319 *)p)->f8 = z;
        if (h != 0) {
            if (((u32)((((struct Obj01319 *)p)->f32) << 31) >> 31) == 0) {
                func_020307B0((void *)h);
                ((struct Obj01319 *)p)->f4 = z;
            }
        }
    }

    {
        int j = 0;
        for (;;) {
            u32 t = g_02146A88->words[j];
            if (t == (u32)p) {
                g_02146A88->words[j] = z;
                break;
            }
            j++;
            if (j >= 0x10)
                break;
        }
    }

    if (((struct Obj01319 *)p)->f20 != 0)
        func_02048AC4((void *)(((struct Obj01319 *)p)->f20));

    func_020307B0(p);
}





/*
 * Teardown of a sixteen-entry table of pointers: every non-null entry is
 * released through func_02050DB8, then the table pointer itself is handed to
 * func_020307B0 and cleared.  The global is re-read from its own slot before
 * every use, which is what the loop's `ldr r0, [r4]` at the top is; the two
 * pool words are the same address, so both `ldr r4, [pc, ...]` load one word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050ED4.c \
 *       --func func_02050ED4 --addr 0x02050ED4 --cc 1.1p1 --arm
 */
void func_02050ED4(void)
{
    int i;

    for (i = 0; i < 16; i++) {
        u32 v = g_02146A88->words[i];

        if (v != 0)
            func_02050DB8((u8 *)v);
    }
    func_020307B0((void *)((u32)g_02146A88));
    g_02146A88 = 0;
}



void *func_02050F1C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[0];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_02050F4C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[1];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_02050F7C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[2];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_02050FAC(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[3];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_02050FDC(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[4];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_0205100C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[5];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_0205103C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[6];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_0205106C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[7];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_0205109C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[8];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_020510CC(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[9];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_020510FC(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[10];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_0205112C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[11];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_0205115C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[12];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_0205118C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[13];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_020511BC(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[14];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}



void *func_020511EC(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88->words[15];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}






/*
 * Truncating forwarding wrapper: zero-extend the third argument to u16 and
 * tail-call func_02048F60.  The ARM9 listing emits it as a .word run (no
 * func_ label), so a `matched` entry is the only witness its callers can
 * use.
 */
int func_0205121C(u32 a, u32 b, u32 c)
{
    return (int)func_02048F60(a, b, (unsigned short)c);
}






/*
 * note:     re-verified 2026-09-20: MATCH; see verify output
 */
void func_02051230(u8 *o, u32 a1, u32 a2, u32 a3)
{
    u32 f;
    u32 v;
    u32 z;
    s32 i;

    z = 0;
    f = (func_02046BFC() == 1) ? 1 : 2;
    v = func_02046C10();
    if (v == 1)
        v = 4;
    else
        v = 8;
    f |= v;
    o[0x258] = (u8)f;
    if (f & 1) {
        func_0206164C(o + 0x58);
        ((struct Obj02319 *)o)->f18 = 0x02051A3C;
    } else if (f & 2) {
        for (i = 0; i < 0x40; i++)
            *(u32 *)(o + 0x58 + i * 4) = z;
        ((struct Obj02319 *)o)->f18 = 0x02051A54;
        *(u16 *)(o + 0x200 + 0x5c) = z;
    }
    if (f & 4) {
        func_02061808(o + 0x158);
        ((struct Obj02319 *)o)->f1C = 0x02051AA0;
    } else if (f & 8) {
        for (i = 0; i < 0x40; i++)
            *(u32 *)(o + 0x158 + i * 4) = z;
        ((struct Obj02319 *)o)->f1C = 0x02051AB8;
        *(u16 *)(o + 0x200 + 0x5e) = z;
    }
    v = ((struct Obj02319 *)o)->f0;
    ((struct Obj02319 *)o)->f4 = a1;
    func_02052A50(v, a1);
    if (a2 == 1) {
        func_02051394((u32 *)o);
        return;
    }
    if (a3 == 0)
        return;
    func_02030DA8(a3, 0x020513F8, o, 0);
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051360.c \
 *       --func func_02051360 --addr 0x02051360 --cc 1.1p1 --arm
 */
void func_02051360(void *p, unsigned int a1, unsigned int a2, unsigned int a3)
{
    func_02051230(p, a1, a2, a3);
    ((struct Obj02319 *)p)->f32 = (u16)((((struct Obj02319 *)p)->f32 & ~1) | 1);
}







/*
 * Tail call with two zero arguments. Filed as the witness for ov094 func_021FA12C.
 */
void func_02051380(void *p, void *r)
{
    func_02051230((u8 *)p, (u32)r, 0, 0);
}








/*
 * Publishes the emitter into the singleton's current-emitter slot (+0x44 of
 * the 0x02146A88 pointee, i.e. word index 0x11), routes each of the emitter's
 * two handler words at +0x18 and +0x1C to one of two handlers on null, then
 * clears the slot again.
 *
 * CLOSES the wall recorded in docs/notes/pkt_02051394.c.txt, which was not a
 * codegen residue at all: the note's two unresolved sites 0x020528A8 and
 * 0x020528BC are now EXACT entries of shard pkt_020526A8, so both attest
 * through `sole-ref/code` and the file needed only its remaining 10-byte
 * codegen gap closed.
 *
 * That gap was statement form.  The condition field and the call's argument
 * must both be read into NAMED LOCALS, and by plain ASSIGNMENT STATEMENTS
 * placed after the publish store, not by initialisers at the declarations:
 *   - inline (`if (p[6] == 0) func_020528BC(p[0]);`) the compiler folds the
 *     condition into r0 and issues `cmp` before the argument load, so the
 *     image's `ldr r1, [r4, #0x18]` / `ldr r0, [r4]` / `cmp r1, #0` triple
 *     comes out in the wrong order in BOTH blocks (10 bytes out);
 *   - as initialisers at the top of the body the two loads hoist ABOVE the
 *     `str r4, [r0, #0x44]` publish and the first block loses six more bytes
 *     (14 out).
 * Assignment statements after the store reproduce all 25 instructions.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051394.c \
 *       --func func_02051394 --addr 0x02051394 --cc 1.1p1 --arm
 */
void func_02051394(u32 *p)
{
    u32 a;
    u32 v;

    g_02146A88->f44 = (u32)p;

    a = p[6];
    v = p[0];
    if (a == 0)
        func_020528BC(v);
    else
        func_02052984(v, a);

    a = p[7];
    v = p[0];
    if (a == 0)
        func_020528A8(v);
    else
        func_020528D0(v, a);

    g_02146A88->f44 = 0;
}








/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020513F8.c \
 *       --func func_020513F8 --addr 0x020513F8 --cc 1.1p1 --arm
 */
void func_020513F8(void *p, int a)
{
    func_02051394((u32 *)a);
    func_02030EAC(p);
}







/*
 * particle.c, the 3D setup half of a two-phase emitter pass (wave 13).  When
 * the private block at +0x20 exists: bring up the two frame objects (0x20 and
 * 0x24 bytes), copy the model vector 0x020A159C into a local, build an
 * identity 3x3, zero a vector for func_0206A9DC, copy the 3x3 to the
 * 0x02148C08 scratch, clear bits 0xa4 of word 63 of 0x02148B4C and hand the
 * model vector to func_0206AA0C; then the shared call func_020526A8 and, when
 * the block is still there, the teardown.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02051414.c.txt had it at 152 bytes out,
 * 220 against 224): the three setup-only locals are declared in a NESTED
 * BLOCK with INITIALISERS -- `VecFx32 v = g_020A159C; MtxFx33 m;
 * VecFx32 z = {0, 0, 0};`.  The aggregate initialiser `{0, 0, 0}` is what
 * keeps &z in a callee-saved register (r6) and stores the zero through it,
 * which costs the image's extra r7 (&v) and the push of r3/r7.  Assigning the
 * three fields, a pointer local, an inline VEC_Set, a compound literal and
 * the same locals in the if-block without initialisers all stay at 152 out.
 *
 * g_020A159C resolves through sole-ref/self (its only pool word is inside
 * this function; the ROM word equals the relocation), func_020526A8 through
 * sole-ref/code.
 */
void func_02051414(u8 *a0)
{
    Blk32    b;
    Blk36    g;

    if (((struct Obj06994 *)a0)->f20 != 0) {
        func_020467EC((int)(&b));
        func_02046AFC((u8 *)(&g));
        {
            VecFx32  v = g_020A159C;
            MtxFx33  m;
            VecFx32  z = {0, 0, 0};
            MTX_Identity33_(&m);
            func_0206A9DC(&z);
            MI_Copy36B(&m, g_02148C08);
            g_02148B4C[63] = g_02148B4C[63] & ~0xa4u;
            func_0206AA0C(&v);
        }
        func_02048AD0((struct Light *)(((struct Obj06994 *)a0)->f20));
        func_020479D8();
        func_0206DB80();
    }
    func_020526A8((struct Head *)(((struct Obj06994 *)a0)->f0), (u32)g_02148B98);
    if (((struct Obj06994 *)a0)->f20 == 0)
        return;
    func_02046858((const u32 *)(&b));
    func_02046B40((u8 *)(&g));
    func_020479D8();
    func_0206DB80();
}







/*
 * NOTE ON PACKET: this 16-byte leaf sits at 0x020514F4..0x02051504, in the
 * four-byte gap between packet pkt_02051230 (ends 0x020514F4) and packet
 * pkt_02051504 (starts 0x02051504) - the last instruction word of the
 * 0x02051414 dump plus a pool word.  The listing does label it
 * (`func_020514F4` at asm/arm9/src/019_0204D434.s:5680), but its only caller
 * in the whole image is the `bl` at 0x02051594 inside func_02051574, which is
 * itself inside pkt_02051504's range, so the `label` class cannot attest it for
 * that caller.  Filing it here as its own entry makes it a `matched` witness
 * for func_02051574 instead, which is the only reason it is in this shard.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020514F4.c \
 *       --func func_020514F4 --addr 0x020514F4 --cc 1.1p1 --arm
 */
int func_020514F4(u32 *p)
{
    return func_02052770(*p);
}







/*
 * Counts the non-NULL entries of the 16-slot pointer table g_02146A88.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051504.c \
 *       --func func_02051504 --addr 0x02051504 --cc 1.1p1 --arm
 */
int func_02051504(void)
{
    int n = 0;
    int i;

    for (i = 0; i < 16; i++) {
        if (g_02146A88->words[i] != 0)
            n++;
    }
    return n;
}







/*
 * For every live slot of g_02146A88, calls func_02051414 with the slot value;
 * returns how many slots were live (not what the callee returned).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051534.c \
 *       --func func_02051534 --addr 0x02051534 --cc 1.1p1 --arm
 */
int func_02051534(void)
{
    int i;
    int n = 0;

    for (i = 0; i < 16; i++) {
        if (g_02146A88->words[i] != 0) {
            func_02051414((u8 *)g_02146A88->words[i]);
            n++;
        }
    }
    return n;
}






/*
 * Same walk as func_02051534, but each live slot goes to func_020514F4 -
 * the pair is a start/stop pass over the same 16-entry table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051574.c \
 *       --func func_02051574 --addr 0x02051574 --cc 1.1p1 --arm
 */
int func_02051574(void)
{
    int i;
    int n = 0;

    for (i = 0; i < 16; i++) {
        if (g_02146A88->words[i] != 0) {
            func_020514F4((u32 *)g_02146A88->words[i]);
            n++;
        }
    }
    return n;
}






/*
 * Promoted by parks lane 2: the callee 0x02052634 was filed first as an
 * EXACT entry (src/matched/func_02052634.c, shard pkt_0205250C) and this
 * file's call site now resolves through the `matched` class.  No change to
 * the C was needed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020515B4.c \
 *       --func func_020515B4 --addr 0x020515B4 --cc 1.1p1 --arm
 */
int func_020515B4(void *p, int b, int c)
{
    int r = func_02052634((char *)(((struct Obj11458 *)p)->f0), b, c);
    ((struct Obj11458 *)p)->f8 = r;
    return r;
}





/*
 * Promoted by parks lane 2: the callee 0x020525A0 was filed first as an
 * EXACT entry (src/matched/func_020525A0.c, shard pkt_0205250C) and this
 * file's call site now resolves through the `matched` class.  No change to
 * the C was needed.
 *
 * EXACT: every byte is identical and the listing extent is now 72 bytes
 * (it once ran on to 0x02051620 for want of a label at 0x02051610).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020515CC.c \
 *       --func func_020515CC --addr 0x020515CC --cc 1.1p1 --arm
 */
int func_020515CC(int *p, int a, int b, int c)
{
    int r;
    if (*(int *)((char *)((struct Obj08873 *)p)->f0 + 8) >= 0x18)
        return -1;
    g_02146A88->f40 = c;
    r = func_020525A0((void *)p[0], a, (void (*)(void *))b);
    g_02146A88->f40 = 0;
    p[2] = r;
    return r;
}





/*
 * Returns word 2 of the object at *p. Filed as the witness for ov094 func_021FC744.
 */
int func_02051614(int **p)
{
    return (*p)[2];
}





asm void KeyValHashKey(void)
{
    ldr r0, [r0]
    ldr ip, =func_020524C8
    bx ip
}






/*
 * Dereference the first argument and tail-call func_0205250C with the loaded
 * pointer.  Unlabelled ARM leaf in the ARM9 listing; matched so its overlay
 * callers get a `matched` witness.
 */
void func_02051630(void **p, void *q)
{
    func_0205250C(*p, q);
}






/*
 * Unlabelled ARM leaf in the ARM9 module. Reads the word at +0xC.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void *func_02051640(char *p)
{
    return ((struct Obj01319 *)p)->fC;
}






/*
 * Constructor for the 0x25c-byte emitter record: defaults the three pointer
 * arguments, zeroes three words, stores the id halfword, stamps the 0x25b
 * byte from the source record or from zero, then hands twelve arguments to
 * func_02048A24 and stores its return at +0x20.
 *
 * CLOSES the 268/272 near miss written up in docs/notes/func_02051648.c.txt,
 * whose whole residue was one missing `mov r0, #0`: the compiler kept the
 * prologue's live zero across the branch and reused it for the null arm's
 * first two statements, where the image re-materialises it.
 *
 * The lever is STATEMENT ORDER, found by tools/permuter.py (hill, budget 300,
 * mutation `reorder(+3)`): the three zero stores are written BETWEEN the a4
 * and a5 defaults, not after all three.  Interleaving them that way puts the
 * `ldreq ip, [pc, ...]` for a5 after the three `str r0` of the prologue zero,
 * which is what kills that zero's live range before the branch and forces the
 * null arm to build its own.  Written with all three defaults first the zero
 * survives and the arm is four bytes short; that is the note's residue.  The
 * reorder is value-preserving: the defaults and the stores touch disjoint
 * objects (three parameters versus three fields of `this`).
 *
 * The note's other findings are all still load-bearing and unchanged:
 *   * `src != 0` is the FALL-THROUGH arm; the null arm is the `beq`.
 *   * the three pointer defaults are evaluated unconditionally before the
 *     branch and the compiler predicates each (`ldreq r3, [pc, ...]`).
 *   * `this->f25b = (u8)src->f00` casts the WORD field: the image is
 *     `ldr r2, [lr]` then `strb`, not `ldrb`.
 *   * a6 is truncated at the USE with `(u16)`, not declared `u16`; declared
 *     u16 the compiler emits a single `ldrh` and the file is 2 bytes short
 *     (docs/families/particle.h records this tell for the whole family).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051648.c \
 *       --func func_02051648 --addr 0x02051648 --cc 1.1p1 --arm
 *   EXACT, 272 bytes, 5 relocation sites, all resolved (label x2, literal x3).
 */
void func_02051648(struct Dst648 *this, struct Src648 *src, u16 a2, Vec3 *a3,
                   Vec3 *a4, Vec3 *a5, u32 a6)
{
    if (a3 == 0) a3 = &g_020A1590;
    if (a4 == 0) a4 = &g_020A1584;

    this->f24 = 0;
    this->f28 = 0;
    this->f2c = 0;

    if (a5 == 0) a5 = &g_020A1578;

    this->f30 = a2;

    if (src != 0) {
        this->f25b = (u8)src->f00;
        this->f20 = func_02048A24(src->f00, src->f04, src->f08, src->f0c,
                                  src->f10, src->f14, src->f18, src->f1c,
                                  (int)a3, (int)a4, (int)a5, (u16)a6);
    } else {
        this->f25b = 0;
        this->f20 = func_02048A24(0, 0xb50, 0xb50, 0x1555,
                                  0, 0x1000, 0x384000, 0,
                                  (int)a3, (int)a4, (int)a5, (u16)a6);
    }
}





int func_02051758(int a0)
{
    struct Obj01197 *o = (struct Obj01197 *)a0;

    func_02048AC4((void *)o->f20);
    o->f20 = 0;
    return 0;
}
