/*
 * file:     musical_dressup_sys_p01.c
 * unit:     yes
 * function: func_02155478, func_021559E4, func_02155A4C, func_02155A6C, func_02155A8C, func_02155A90, func_02155A94, func_02155A98, func_02155C0C, func_02155F24, func_02155F4C, func_02155F9C, func_02155FB4, func_02155FC8, func_02156074
 * address:  0x02155478
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_0203A574  0x0203A574  arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200F83C  0x0200F83C  thumb
 *   func_0200FA84  0x0200FA84  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_02013090  0x02013090  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02013790  0x02013790  thumb
 *   func_020137C0  0x020137C0  thumb
 *   func_02013864  0x02013864  thumb
 *   func_02013894  0x02013894  thumb
 *   func_020137F0  0x020137F0  thumb
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02013128  0x02013128  thumb
 *   func_02013980  0x02013980  thumb
 *   func_02005C44  0x02005C44  thumb
 *   func_02005D28  0x02005D28  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_020130B4  0x020130B4  thumb
 *   func_0203D378  0x0203D378  arm
 *   func_020124AC  0x020124AC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_020145CC  0x020145CC  thumb
 *   func_0203D0D0  0x0203D0D0  arm
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_021550A0  0x021550A0  thumb  ov008
 *   func_0215518C  0x0215518C  thumb  ov010
 *   func_02155224  0x02155224  thumb  ov010
 *   func_02155244  0x02155244  thumb  ov010
 *   func_02155328  0x02155328  thumb  ov010
 *   ov008_id       0x00000008  data
 *   ov021_id       0x00000015  data
 *   ov093_id       0x0000005D  data
 *   ov100_id       0x00000064  data
 *   ov101_id       0x00000065  data
 *   ov119_id       0x00000077  data
 *   ov195_id       0x000000C3  data
 *   d_021D3FE8     0x021D3FE8  data  ov021
 *   d_021BB6A4     0x021BB6A4  data  ov100
 *   d_021F03C4     0x021F03C4  data  ov093
 *   d_021E75D8     0x021E75D8  data  ov119
 *   d_02172700     0x02172700  data  a1
 *   d_02208C40     0x02208C40  data  ov195
 *   d_021B74AC     0x021B74AC  data  ov101
 *   d_0216FEE0     0x0216FEE0  data
 *   func_020122C0  0x020122C0  thumb
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_0216576C  0x0216576C  thumb  ov010
 *   func_02157028  0x02157028  thumb  ov010
 *   func_021F685C  0x021F685C  thumb  ov112
 *   func_021F68BC  0x021F68BC  thumb  ov112
 *   func_021FD904  0x021FD904  thumb  ov132
 *   func_021FC848  0x021FC848  thumb  ov132
 *   func_0203064C  0x0203064C  arm
 *   func_02012138  0x02012138  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02012F44  0x02012F44  thumb
 *   func_0200A7C8  0x0200A7C8  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_0200A81C  0x0200A81C  thumb
 *   func_02005728  0x02005728  thumb
 *   func_02156BAC  0x02156BAC  thumb  ov010
 *   func_021567D8  0x021567D8  thumb  ov010
 *   func_02156888  0x02156888  thumb  ov010
 *   func_02156770  0x02156770  thumb  ov010
 *   func_02156710  0x02156710  thumb  ov010
 *   func_0215611C  0x0215611C  thumb  ov010
 *   func_02156530  0x02156530  thumb  ov010
 *   func_02156420  0x02156420  thumb  ov010
 *   func_02156824  0x02156824  thumb  ov010
 *   func_02156B74  0x02156B74  thumb  ov010
 *   func_02157260  0x02157260  thumb  ov010
 *   func_02157298  0x02157298  thumb  ov010
 *   func_021FD908  0x021FD908  thumb  ov132
 *   func_021FD918  0x021FD918  thumb  ov132
 *   func_021FD8D4  0x021FD8D4  thumb  ov132
 *   func_021FD8EC  0x021FD8EC  thumb  ov132
 *   func_021FCE28  0x021FCE28  thumb  ov132
 *   func_021FD83C  0x021FD83C  thumb  ov132
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0200ED54  0x0200ED54  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_02030B50  0x02030B50  arm
 *   func_020306F0  0x020306F0  arm
 *   d_02172724     0x02172724  data
 *   d_02172748     0x02172748  data
 *   d_021F8360     0x021F8360  data
 *   func_021F675C  0x021F675C  thumb
 *   func_021FD938  0x021FD938  thumb  ov132
 *   func_02156CD8  0x02156CD8  thumb  ov010
 *   func_02156F98  0x02156F98  thumb  ov010
 *   func_021F6888  0x021F6888  thumb
 *   func_0215716C  0x0215716C  thumb  ov010
 *   func_02156CAC  0x02156CAC  thumb  ov010
 *   func_021FD948  0x021FD948  thumb  ov132
 *   func_02156F68  0x02156F68  thumb  ov010
 *   func_02156FC4  0x02156FC4  thumb  ov010
 *   func_021572E4  0x021572E4  thumb  ov010
 *   func_021FD4F8  0x021FD4F8  thumb  ov132
 *   func_02157000  0x02157000  thumb  ov010
 *   func_02157174  0x02157174  thumb  ov010
 *   func_021FD964  0x021FD964  thumb  ov186
 *   func_021F4F14  0x021F4F14  thumb  ov112
 *   func_021F5140  0x021F5140  thumb  ov112
 *   func_021F4F40  0x021F4F40  thumb  ov112
 *   func_02157394  0x02157394  thumb  ov010
 */
#include "../../matched/include/Obj05876.h"
#include "../../matched/include/Obj17615.h"
#include "../../matched/include/Obj17616.h"
#include "../../matched/include/Obj18685.h"
#include "../../matched/include/Obj05850.h"
#include "../../matched/include/Obj02657.h"
#include "../../matched/include/Obj07201.h"

struct Desc;
struct Entry;
struct Evt;
struct IcaAnime;
struct Link_02155478;
struct ZoneData;
struct Ctx;
struct Big;
struct Obj;
struct Party;
struct Seq_02155478;
struct BigObj;
struct Deal;
struct Src;
struct U16Vec;
struct L0200ED54;
struct Sub0200852CObj;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef volatile u16 vu16;

typedef struct { u32 v[4]; } Tbl4;

struct Info {
    u8 pad00[4];
    u32 f04;
    u8 pad08[0x1a];
    u8 f22;
};

struct Req {
    u32 f00;
    u32 f04;
    u16 f08;
    u8 b0a;
    u8 b0b;
    u32 f0c;
    u32 f10;
};

struct Arg {
    struct Info *info;
    void *slots;
    u32 flag;
};

struct Ctx {
    void *f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    struct Req *f28;
    u8 pad2c[0x0c];
    void *f38;
    void *f3c[4];
    u32 f4c;
    u32 f50;
    u32 f54;
    int f58;
    void *f5c;
    u32 f60;
    void *f64;
    void *f68[4];
    u8 b78[4];
    u32 f7c;
    u8 b80[8];
    struct Info *f88;
    u8 slot[0x40];
    u32 fcc;
    u32 fd0;
    u32 fd4;
    u32 fd8;
    u32 fdc;
    void *fe0;
    u32 fe4;
};

typedef signed int     s32;

typedef struct Task {
    void *f00;
    void *f04;
    u8 pad08[0x30];
    void *f38;
    void *f3c[4];
    u8 pad4c[4];
} Task;

typedef signed short   s16;

struct Link_02155478 {
    struct Seq_02155478 *owner;  /* 0x00 */
    void *sess;         /* 0x04 */
};

typedef struct Seq_02155478 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    struct Link_02155478 *link;  /* 0x08 */
    u32 state;          /* 0x0C */
    u8 f10;             /* 0x10 */
    u8 pad11[3];
    u32 f14;            /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1c;          /* 0x1C */
    void *f20;          /* 0x20 */
    void *f24;          /* 0x24 */
    void *f28;          /* 0x28 */
    void *f2c;          /* 0x2C */
    void *f30;          /* 0x30 */
    void *f34;          /* 0x34 */
    void *f38;          /* 0x38 */
    u32 f3c;
    void *f40;          /* 0x40 */
    u8 f44[4];          /* 0x44 */
    u32 f48;
    u8 f4c;             /* 0x4C */
    u8 pad4d[3];
    u32 f50;            /* 0x50 */
} Seq_02155478;

typedef u32 (*TaskFn)(void *task, u32 *state, Seq_02155478 *work);

struct Link_02155C0C {
    u32 f00;
    void *sess;         /* 0x04 */
};

typedef struct Seq_02155C0C {
    void *f00;          /* 0x00 */
    u32 f04;
    struct Link_02155C0C *link;  /* 0x08 */
    u32 state;          /* 0x0C */
    u8 f10;             /* 0x10 */
    u8 pad11[0x1C - 0x11];
    void *f1c;          /* 0x1C */
    u32 f20;
    void *f24;          /* 0x24 */
    u32 f28;
    void *f2c;          /* 0x2C */
    void *f30;          /* 0x30 */
    void *f34;          /* 0x34 */
    void *f38;          /* 0x38 */
    u32 f3c;
    void *f40;          /* 0x40 */
    u8 f44[4];          /* 0x44 */
    u32 f48;
    u8 f4c;             /* 0x4C */
    u8 pad4d[3];
    u32 f50;            /* 0x50 */
} Seq_02155C0C;

typedef struct Obj { int f00; int f04; int f08; } Obj;

typedef struct Work_02155FB4 {
    u8 pad00[0x14];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    void *f24;          /* 0x24 */
    void *f28;          /* 0x28 */
    u8 pad2C[0x38 - 0x2C];
    void *f38;          /* 0x38 */
    void *f3C;          /* 0x3C */
} Work_02155FB4;

typedef unsigned long long u64;

typedef struct Stage {
    u8 pad00[0x14];
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
} Stage;

typedef struct Work_02155FC8 {
    u8 pad00[0x14];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    void *f24;          /* 0x24 */
    void *f28;          /* 0x28 */
    u8 pad2C[4];
    Stage *f30;         /* 0x30 */
    u8 pad34[4];
    void *f38;          /* 0x38 */
    void *f3C;          /* 0x3C */
    u8 pad40[4];
    u8 f44[4];          /* 0x44 */
} Work_02155FC8;

typedef struct Rec6 {
	unsigned short id;
	short f2;
	unsigned char idx;
	unsigned char pad5[0x1];
} Rec6;

typedef struct Member {
    u8 pad00[0x14];
    Rec6 recs[9];       /* 0x14 */
    u16 total;          /* 0x4A */
    u8 pad4C[8];
    u32 used[9];        /* 0x54 */
} Member;

typedef struct Party {
    u32 f00;
    Member *members[4]; /* 0x04 */
} Party;

typedef struct Work {
    u8 pad00[0x14];
    u32 f14;            /* 0x14 */
    u8 pad18[0x10];
    void *f28;          /* 0x28 */
    u8 pad2C[4];
    Party *party;       /* 0x30 */
    u8 pad34[4];
    void *f38;          /* 0x38 */
} Work;

extern void *func_0201210C(const struct Ctx *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link_02155478 *p, u32 lo, u32 hi);
extern u32 func_02039CB4(struct Link_02155478 *p, u32 lo, u32 hi);
extern u32 func_0200FB24(void);
extern u32 func_0200FBB0(void);
extern void func_0200F83C(void);
extern void func_0200FA84(void);
extern void func_0200FBA0(void);
extern void *func_02013090(u32 heap);
extern void *func_02012F2C(int *p);
extern void func_02013790(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_020137C0(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013864(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_02013894(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4);
extern void func_020137F0(u32 p0, u32 p1, u32 p2, u32 p3, u8 p4, u16 p5);
extern u32 func_0203D1A4(struct Link_02155478 *p);
extern void func_02013128(void *p, void *src, int i);
extern void func_02013980(struct ZoneData *o, u32 heap);
extern u16 func_02005C44(void);
extern void func_02005D28(void);
extern void func_02005D90(u32 a, u16 b);
extern int func_020130B4(int a0);
extern u32 func_0203D378(void);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *);
extern int func_0203CD98(void);
extern int func_0203CEAC(int a0);
extern void *func_020145CC(void *w);
extern void func_0203D0D0(void);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *func_021550A0(void *a, const int *p);
extern void func_0215518C(int mode, struct Ctx *ctx);
extern void func_02155224(struct Ctx *ctx);
extern void func_02155244(struct Ctx *ctx, void *party);
extern void func_02155328(struct Ctx *ctx, void *party);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void func_0201232C(char *p, int a1, int a2);
extern void *func_020124E8(struct Obj *);
extern void *func_02012EBC(struct Big *p);
extern struct Party *func_0201A920(u32 heap);
extern void func_02005DF8(u32 a);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern u32 func_02012138(const struct Ctx *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *list, u32 i);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0216576C(void *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02012F44(void *h);
extern void *func_021F685C(u32 heap);
extern int func_021FD904(int *);
extern u8 func_0200A7C8(struct Big *p);
extern void func_021F68BC(u8 *p, u32 unused, void *sys, u8 kind, u16 heap);
extern u8 *func_02012944(void *p);
extern void *func_020185F0(void *p);
extern void func_021FC848(u8 *p, void *a, void *b, int unused, void *d, u16 heap);
extern u16 func_0200A81C(struct Big *p);
extern u32 func_02005728(u32 n);
extern struct Deal *func_02157028(u32 heap, struct Src *src, u16 lim);
extern void func_02156BAC(void *p);
extern void func_021567D8(void *evt, Seq_02155C0C *s);
extern void func_02156888(void *a0, void *a1, int a2);
extern int func_02156770(void *evt, Seq_02155C0C *s);
extern int func_02156710(void *evt, Seq_02155C0C *s);
extern void func_0215611C(struct Work *);
extern void func_02156530(struct Work *w);
extern void func_02156420(struct Work *);
extern void func_02156824(void *evt, Seq_02155C0C *s);
extern void func_02156B74(struct Work *w);
extern u32 func_02157260(const u8 *p);
extern u32 func_02157298(const u8 *p);
extern u32 func_021FD908(u8 *p);
extern void func_021FD918(char *p, u32 a, int b);
extern u32 func_021FD8D4(char *p);
extern u8 func_021FD8EC(char *p, int index);
extern int func_021FCE28(char *, u32);
extern u32 func_021FD83C(char *p);
extern void *func_0200ED48(void *p);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200FB38(void);
extern void func_02030B50(void *p);
extern void func_020306F0(u32 heap);
extern int func_021F675C(int, int);
extern void func_021FD938(char *p);
extern int func_02156CD8();
extern int func_02156F98(struct Stage *);
extern int func_021F6888(void *);
extern int func_0215716C(void *);
extern Obj *func_02156CAC(int a, int b, int c);
extern void func_021FD948(char *p, u32 value);
extern Stage *func_02156F68(u32 heap, void *p);
extern int func_02156FC4(int a0, int a1, int a2);
extern void func_021572E4(struct Deal *d, void *a, u8 b, u8 slot, u16 y);
extern u32 func_021FD4F8(struct Ctx *p, u8 key);
extern int func_02157000(int a0, int a1, int a2);
extern void func_02157174(u32 heap, struct Deal *d, struct Party *party);
extern u32 func_021FD964(void *p, u32 i, u32 j);
extern u32 *func_021F4F14(int heap);
extern unsigned char func_021F5140(void *p, int i);
extern void func_021F4F40(void **p);
extern u16 func_02157394(int a0, int a1);
int func_02155478(void *proc, int *seq, struct Ctx *ctx);
void *func_021559E4(void *a, int b, void *c, int d);
void func_02155A4C(struct Ctx *ctx);
void func_02155A6C(struct Ctx *ctx);
void func_02155A8C(u8 *p, u32 v);
u32 func_02155A90(u8 *p);
u32 func_02155A94(u8 *p);
void *func_02155A98(void *a, void *b, u8 c, u32 d, struct Link_02155478 *link);
int func_02155C0C(void *evt, void *unused, Seq_02155C0C *s);
void func_02155F24(int *p);
int func_02155F4C(int a0);
struct Obj *func_02155F9C(int a0);
void func_02155FB4(Work_02155FB4 *w);
void func_02155FC8(Work_02155FC8 *w);
void func_02156074(struct Work *w);
extern u8 ov008_id[];
extern u8 ov021_id[];
extern u8 ov093_id[];
extern u8 ov100_id[];
extern u8 ov101_id[];
extern u8 ov119_id[];
extern u8 ov195_id[];
extern u8 d_021D3FE8[];
extern u8 d_021BB6A4[];
extern u8 d_021F03C4[];
extern u8 d_021E75D8[];
extern const char d_02172700[];
extern u8 d_02208C40[];
extern u8 d_021B74AC[];
extern const Tbl4 d_0216FEE0;
extern u8 d_02172724[];
extern u8 d_02172748[];
extern u8 d_021F8360[];






/*
 * The ov010 main sequence: a 28-state machine over *seq that loads the
 * sub-overlays (21, 100, 119, 195, 101, 8, 93) as child procs, sets up the
 * party/slot records at +0x8c through func_0215518C/func_02155328/
 * func_02155244, runs the fade and wireless-sync waits, and tears
 * everything down in states 21 to 23.
 *
 * Byte-correct (1388 bytes, every concrete byte), 97 of 97 relocations
 * resolved. 2026-10-05 (wave D9): EXACT. The six proc-data words got the
 * token of the overlay that holds each one on its `data` symbols line
 * (ov021, ov100, ov093, ov119, ov195, ov101), each an overlay this function
 * loads. Source unchanged.
 * Shape levers that closed it (they also settled the ctx/seq register
 * swap): case 18 writes the fe4 = 0 / (*seq)++ tail in both arms;
 * case 19 writes (*seq)++ in both arms; state 10 writes the
 * func_02005D90 call in each arm.
 */
int func_02155478(void *proc, int *seq, struct Ctx *ctx)
{
    Tbl4 tbl;
    struct Arg arg;
    void *w;
    void *h;
    struct Req *req;

    w = ctx->f00;
    h = func_0201210C(w);
    switch (*seq) {
    case 0:
        func_02012374(proc, (struct Evt **)func_021BE8D4(w, (int)h, 0, 0));
        (*seq)++;
        break;
    case 1:
        func_02012374(proc, (struct Evt **)func_020144DC((int)w, (int)h));
        *seq = 2;
        break;
    case 2:
        func_020120B4(w, (u32)ov021_id, d_021D3FE8, ctx);
        (*seq)++;
        break;
    case 3:
        if (func_020120F0(w) == 0) {
            if (ctx->f50 == 8) {
                *seq = 24;
            } else if (ctx->f50 == 12) {
                *seq = 21;
            } else {
                (*seq)++;
            }
        }
        break;
    case 4:
        (*seq)++;
        break;
    case 5:
        func_0215518C(ctx->f58, ctx);
        ctx->f60 = ctx->f04;
        ctx->f64 = ctx->f38;
        ctx->f68[0] = ctx->f3c[0];
        ctx->f68[1] = ctx->f3c[1];
        ctx->f68[2] = ctx->f3c[2];
        ctx->f68[3] = ctx->f3c[3];
        ctx->f7c = ctx->f50;
        func_020120B4(w, (u32)ov100_id, d_021BB6A4, &ctx->f60);
        (*seq)++;
        break;
    case 6:
        if (func_020120F0(w) == 0) {
            ctx->f50 = ctx->f7c;
            switch (ctx->f50) {
            case 7:
                *seq = 20;
                break;
            case 12:
                *seq = 20;
                break;
            case 13:
                *seq = 2;
                break;
            case 6:
                ctx->f10 = 0;
                *seq = 13;
                break;
            default:
                *seq = 7;
                break;
            }
        }
        break;
    case 7:
        func_02034AC4((u32)ov093_id);
        func_0203A574(0x100, (u32)d_021F03C4, 9, 0);
        func_02039C68((struct Link_02155478 *)func_020399A8(), 0x6e, 12);
        (*seq)++;
        break;
    case 8:
        if (func_02039CB4((struct Link_02155478 *)func_020399A8(), 0x6e, 12))
            (*seq)++;
        if (func_0200FB24()) {
            if (func_0200FBB0() == 1)
                func_0200F83C();
            else
                func_0200FA84();
            func_02034A5C((u32)ov093_id);
            *seq = 20;
        }
        break;
    case 9:
        ctx->f88 = func_02013090(4);
        ctx->fe0 = func_02012F2C((int *)ctx->f04);
        ctx->fd8 = 0;
        switch (ctx->f50) {
        case 0:
            break;
        case 1:
            ctx->fd0 = 1;
            ctx->fd4 = 2;
            func_02013790((u32)ctx->f88, ctx->f04, (u32)func_020399A8(), 1, 4);
            break;
        case 2:
            ctx->fd0 = 1;
            ctx->fd4 = 6;
            func_020137C0((u32)ctx->f88, ctx->f04, (u32)func_020399A8(), 1, 4);
            break;
        case 3:
            ctx->fd0 = 1;
            ctx->fd4 = 10;
            func_02013864((u32)ctx->f88, ctx->f04, (u32)func_020399A8(), 1, 4);
            break;
        case 4:
            ctx->fd0 = 1;
            ctx->fd4 = 14;
            func_02013894((u32)ctx->f88, ctx->f04, (u32)func_020399A8(), 1, 4);
            break;
        case 5:
            tbl = d_0216FEE0;
            ctx->fd0 = 3;
            ctx->fd4 = 18;
            func_020137F0((u32)ctx->f88, ctx->f04, (u32)func_020399A8(), 1,
                          tbl.v[ctx->b78[func_0203D1A4((struct Link_02155478 *)func_020399A8())]], 4);
            ctx->f88->f22 = 1;
            ctx->f88->f04 = 1;
            func_02155224(ctx);
            break;
        }
        func_02013128(ctx->f88, ctx->f38, 0);
        func_02013980((struct ZoneData *)ctx->f88, 1);
        ctx->f54 = func_02005C44();
        func_02005D28();
        func_02039C68((struct Link_02155478 *)func_020399A8(), 10, 12);
        (*seq)++;
        break;
    case 10:
        if (func_0200FB24()) {
            func_020130B4((int)ctx->f88);
            ctx->f88 = 0;
            if (func_0200FBB0() == 1)
                func_0200F83C();
            else
                func_0200FA84();
            func_02034A5C((u32)ov093_id);
            *seq = 20;
        } else if (func_02039CB4((struct Link_02155478 *)func_020399A8(), 10, 12)) {
            if (func_0203D378())
                func_02005D90(0x48B, 0xFFFF);
            else
                func_02005D90(0x48C, 0xFFFF);
            (*seq)++;
        }
        break;
    case 11:
        func_02155328(ctx, w);
        func_02034A5C((u32)ov093_id);
        arg.info = ctx->f88;
        arg.slots = ctx->slot;
        arg.flag = 1;
        func_02012374(proc, (struct Evt **)func_020124AC(w, (u32)ov008_id, (void *)func_021550A0, (u32)(&arg)));
        (*seq)++;
        break;
    case 12:
        if (func_020120F0(w) == 0) {
            func_02155244(ctx, func_020120F4(w));
            func_020130B4((int)ctx->f88);
            ctx->f88 = 0;
            func_02005D28();
            func_02155A6C(ctx);
            *seq = 17;
        }
        break;
    case 13:
        ctx->f1c = ctx->f04;
        ctx->f24 = (u32)ctx->f38;
        func_020120B4(w, (u32)ov119_id, d_021E75D8, &ctx->f08);
        (*seq)++;
        break;
    case 14:
        if (func_020120F0(w) == 0) {
            if (ctx->f10 == 1)
                *seq = 15;
            else
                *seq = 17;
        }
        break;
    case 15:
        req = func_02030734(4, 0x14, 0, d_02172700, 0x219);
        req->f00 = ctx->f04;
        req->f04 = ctx->f24;
        req->f08 = ctx->f14;
        req->b0a = 0;
        req->b0b = ctx->f18;
        req->f0c = 1;
        req->f10 = 0;
        ctx->f28 = req;
        func_020120B4(w, (u32)ov195_id, d_02208C40, req);
        (*seq)++;
        break;
    case 16:
        if (func_020120F0(w) == 0) {
            func_020307B0(ctx->f28);
            ctx->f10 = 1;
            *seq = 13;
        }
        break;
    case 17:
        if (func_0203CD98() && func_0200FB24() == 0)
            func_02039C68((struct Link_02155478 *)func_020399A8(), 0xdc, 12);
        (*seq)++;
        break;
    case 18:
        if (func_0203CD98() && func_0200FB24() == 0) {
            if (func_02039CB4((struct Link_02155478 *)func_020399A8(), 0xdc, 12) == 0)
                break;
            ctx->fe4 = 0;
            (*seq)++;
        } else {
            ctx->fe4 = 0;
            (*seq)++;
        }
        break;
    case 19:
        if (func_0203CD98()) {
            ctx->fe4++;
            if (ctx->fe4 < 60)
                break;
            func_0203CEAC(0);
            (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 20:
        if (func_0203CD98() == 0) {
            func_0200FBA0();
            *seq = 21;
        }
        break;
    case 21:
        func_02155A6C(ctx);
        func_02012374(proc, func_020145CC(w));
        (*seq)++;
        break;
    case 22:
        func_02012374(proc, (struct Evt **)func_021BE92C(w, (int)h, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 23:
        func_0203D0D0();
        func_02155A4C(ctx);
        return 1;
    case 24:
        (*seq)++;
        break;
    case 25:
        (*seq)++;
        break;
    case 26:
        ctx->f5c = ctx->f00;
        func_020120B4(w, (u32)ov101_id, d_021B74AC, &ctx->f5c);
        (*seq)++;
        break;
    case 27:
        if (func_020120F0(w) == 0) {
            *(vu16 *)0x04000304 |= 0x8000;
            *seq = 20;
        }
        break;
    }
    return 0;
}



void *func_021559E4(void *a, int b, void *c, int d)
{
    Task *t;
    int i;

    if (d != 0)
        c = func_020122C0(a, 0, func_02155478, 0xE8);
    else
        func_0201232C(c, (int)func_02155478, 0xE8);
    t = func_020124E8(c);
    ((struct Obj05876 *)t)->f4C = func_02012EBC(func_020120F4(a));
    t->f04 = func_020120F4(a);
    t->f00 = a;
    for (i = 0; i < 4; i++)
        t->f3c[i] = func_0201A920(4);
    t->f38 = func_0201A920(4);
    return c;
}




/*
 * Frees the four lists at +0x3c and then the list at +0x38.
 */
void func_02155A4C(struct Ctx *ctx)
{
    int i;

    for (i = 0; i < 4; i++)
        func_020307B0(ctx->f3c[i]);
    func_020307B0(ctx->f38);
}



/*
 * Stops the sound handle at +0x54 (if any) and clears it.
 */
void func_02155A6C(struct Ctx *ctx)
{
    if (ctx->f54 != 0) {
        func_02005D90(ctx->f54, 0xFFFF);
        func_02005DF8(0x3c);
        ctx->f54 = 0;
    }
}





/*
 * Stores the word field at +0x50.
 *
 * Addresses are Black-image addresses.
 */
void func_02155A8C(u8 *p, u32 v)
{
    ((struct Obj17615 *)p)->f50 = v;
}





/*
 * Reads the word at p.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02155A90(u8 *p)
{
    return ((struct Obj17616 *)p)->f0;
}




/*
 * Unlabelled leaf: reads the word at +0x4C.
 */
u32 func_02155A94(u8 *p)
{
    return ((struct Obj18685 *)p)->f4C;
}




/*
 * Creates the ov010 link sequence task (func_02155C0C over a Seq_02155478) and
 * either starts the wireless exchange (state 11) or shuffles the four
 * member slots and deals locally (state 13). The owner back-pointer is
 * stored through s->link while the session is read through the
 * parameter: storing through the parameter enregisters it instead.
 */
/*
 * Creates the ov010 link sequence task (func_02155C0C over a Seq) and
 * either starts the wireless exchange (state 11) or shuffles the four
 * member slots and deals locally (state 13). The owner back-pointer is
 * stored through s->link while the session is read through the
 * parameter: storing through the parameter enregisters it instead.
 */
void *func_02155A98(void *a, void *b, u8 c, u32 d, struct Link_02155478 *link)
{
    void *task;
    Seq_02155478 *s;
    void *tmp;

    func_0203064C(1, 0x802C, 0x42000);
    task = func_020122C0(a, 0, func_02155C0C, sizeof(Seq_02155478));
    s = func_020124E8(task);
    s->f00 = a;
    s->f04 = b;
    s->f14 = d;
    s->f1c = func_02012EBC(b);
    s->f20 = (void *)func_02012138(a);
    s->link = link;
    s->link->owner = s;
    s->f28 = link->sess;
    s->f50 = 0;
    s->f38 = 0;
    tmp = func_020457B0(11, 4);
    s->f18 = func_0201AB28(func_02012934(s->f04), c);
    func_02017E1C(s->f18, 0x73, (u32)tmp);
    func_0216576C(tmp);
    func_02045808(tmp);
    s->f2c = 0;
    s->f30 = 0;
    s->f34 = 0;
    s->f40 = func_02012F44(b);
    s->f24 = func_021F685C(4);
    if (s->f14 == 0 || func_021FD904(s->link->sess) == 1)
        func_021F68BC(s->f24, (u32)s->f1c, s->f04, func_0200A7C8(s->f40), 0x2C);
    if (s->f14 == 1) {
        s->state = 11;
        s->f10 = 0;
        func_021FC848(s->f28, func_02012944(s->f04), func_020185F0(s->f18), (int)s->f20, s->f24, 4);
    } else {
        u16 lim = func_0200A81C(s->f40);
        u8 i;
        u8 j;
        u8 k;
        u8 t;

        for (i = 0; i < 4; i++)
            s->f44[i] = i;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 4; j++) {
                k = func_02005728(4);
                t = s->f44[j];
                s->f44[j] = s->f44[k];
                s->f44[k] = t;
            }
        }
        s->f4c = s->f44[0];
        s->f38 = func_02157028(4, s->f24, lim);
        s->state = 13;
        s->f10 = 0;
    }
    return task;
}



int func_02155C0C(void *evt, void *unused, Seq_02155C0C *s)
{
    func_02156BAC(s);
    switch (s->state) {
    case 11:
        if (func_021FD908(s->link->sess) == 1) {
            u32 lo = 0;
            u32 hi = 0;
            void *list;
            u8 i;

            if (func_021FD904(s->link->sess) == 1) {
                s->f38 = func_02157028(4, s->f24, func_0200A81C(s->f40));
                lo = func_02157260(s->f38);
                hi = func_02157298(s->f38);
            }
            func_021FD918(s->link->sess, lo, hi);
            s->state = 12;
            list = func_0200ED48(s->f1c);
            for (i = 0; i < 4; i++) {
                if (func_021FD8D4(s->link->sess) != func_021FD8EC(s->link->sess, i)) {
                    void *p = (void *)func_021FCE28(s->link->sess, i);
                    if (p != 0)
                        func_0200ED54(list, func_02008530(p));
                }
            }
        } else if (s->f50 == 1) {
            s->state = 0x17;
        }
        break;
    case 12:
        if (func_021FD83C(s->link->sess) == 1) {
            u8 i;

            s->state = 13;
            for (i = 0; i < 4; i++)
                s->f44[i] = func_021FD8EC(s->link->sess, i);
            s->f4c = func_021FD8D4(s->link->sess);
            func_02156B74((struct Work *)s);
        } else if (s->f50 == 1) {
            s->state = 0x17;
        }
        break;
    case 13:
        func_021567D8(evt, s);
        s->state = 14;
        break;
    case 14:
        func_02155F24((int *)s);
        func_02156888(evt, s, 3);
        s->state = 0;
        break;
    case 0:
        if (s->f50 == 1 && s->f10 == 0) {
            s->state = 0x17;
        } else if (func_02156770(evt, s) == 1) {
            s->f10 = 0;
            s->state = 1;
        }
        break;
    case 1:
        s->state = 3;
        break;
    case 3:
        func_02155F9C((int)s);
        func_020120B4(s->f00, ~0u, d_02172724, s->f2c);
        s->state = 4;
        break;
    case 4:
        if (func_020120F0(s->f00) == 0) {
            func_02155FB4((Work_02155FB4 *)((struct Work *)s));
            s->state = 0x10;
        }
        break;
    case 16:
        if (func_02156710(evt, s) == 1) {
            s->f10 = 0;
            s->state = 0x11;
            if (s->f50 == 1)
                s->state = 0x17;
        }
        break;
    case 17:
        func_02156888(evt, s, 4);
        s->state = 0x12;
        break;
    case 18:
        if (s->f50 == 1 && s->f10 == 0) {
            s->state = 0x17;
        } else if (func_02156770(evt, s) == 1) {
            s->f10 = 0;
            s->state = 5;
        }
        break;
    case 5:
        func_02155FC8((Work_02155FC8 *)((struct Work *)s));
        func_020120B4(s->f00, ~0u, d_02172748, s->f30);
        s->state = 6;
        break;
    case 6:
        if (func_020120F0(s->f00) == 0) {
            func_02156074((struct Work *)s);
            s->state = 7;
            if (s->f50 == 1)
                s->state = 0x16;
        }
        break;
    case 7:
        func_0215611C((struct Work *)s);
        func_020120B4(s->f00, ~0u, d_021F8360, s->f34);
        s->state = 8;
        break;
    case 8:
        if (func_020120F0(s->f00) == 0) {
            s->state = 0x13;
            if (s->f50 == 1)
                s->state = 0x16;
        }
        break;
    case 19:
        if (func_02156710(evt, s) == 1) {
            s->f10 = 0;
            s->state = 0x14;
            func_02156530((struct Work *)s);
            func_02156420((struct Work *)s);
        }
        break;
    case 20:
        func_02156888(evt, s, 5);
        s->state = 2;
        break;
    case 2:
        if (s->f50 == 1) {
            s->state = 0x17;
        } else {
            func_02155F4C((int)s);
            func_02156824(evt, s);
            s->state = 9;
        }
        break;
    case 9:
        func_02156888(evt, s, 0x28CC);
        s->state = 10;
        break;
    case 10:
        func_02030B50((void *)4);
        func_020306F0(0x2C);
        return 1;
    case 22:
        if (func_02156710(evt, s) == 1)
            s->state = 0x17;
        break;
    case 23:
        func_0200FB38();
        s->state = 0x18;
        break;
    case 24:
        func_02155F4C((int)s);
        func_02156824(evt, s);
        s->state = 0x19;
        break;
    case 25:
        s->state = 0x1A;
        break;
    case 26:
        func_02156888(evt, s, 0x28CD);
        s->state = 10;
        break;
    }
    return 0;
}





/*
 * trailing bytes of the 40-byte listing extent (0x02155F4A `movs r0,r0`)
 * are alignment padding.  The single unresolved relocation is the bl at
 * +0018 to 0x021FD904 (thumb): four overlays overlap that address (ov094,
 * ov132, ov135, ov186) and none traces a func_/sub_ start there, so
 * `label` and `sole-ref/code` both refuse -- there is no traced entry to
 * branch to.  A `symbols:` region hint does not help: tested against each
 * of the four, the site stays wildcarded.  In ov132 the bytes are an
 * unlabelled leaf accessor emitted as a .word run (0x47706C80 =
 * ldr r0,[r0,#0x48]; bx lr); in ov094/ov135 the address is interior to a
 * function, in ov186 it is a data word.  The two other image-wide call
 * sites (0x02155B38, 0x02156C78, both in ov010 and outside this range) are
 * the same shape and are not a usable `label` witness for want of the same
 * traced entry.  No literal pool word anywhere names 0x021FD904 and no
 * EXACT `matched` entry covers it, so the site is evidence-starved.
 * function start).
 *
 * 2026-10-06: layout/function_starts.txt now seeds the ov132 and ov186
 * heads at 0x021FD904 and 0x021FD938, so both calls resolve; the region
 * hint ov132 (the overlay holding the 021FD904 accessor) picks the
 * 021FD938 witness among the overlapping overlays.
 */
void func_02155F24(int *p)
{
    ((struct Obj05850 *)p)->f3C = func_021F675C(((struct Obj05850 *)p)->f18, 4);
    if (((struct Obj05850 *)p)->f14 != 0) {
        func_021FD904((int *)(*(int *)(((struct Obj05850 *)p)->f8 + 4)));
        func_021FD938((char *)(*(int *)(((struct Obj05850 *)p)->f8 + 4)));
    }
}






int func_02155F4C(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj02657 *)t4)->f2C;
    if (a0 == 0) goto loc_02155F5A;
loc_02155F56:
    a0 = func_02156CD8(a0);
loc_02155F5A:
a0 = ((struct Obj02657 *)t4)->f30;
    if (a0 == 0) goto loc_02155F64;
loc_02155F60:
    a0 = func_02156F98((struct Stage *)a0);
loc_02155F64:
a0 = ((struct Obj02657 *)t4)->f34;
    if (a0 == 0) goto loc_02155F76;
loc_02155F6A:
a0 = ((struct Obj02657 *)a0)->f8;
    a0 = func_020307B0((void *)a0);
loc_02155F70:
a0 = ((struct Obj02657 *)t4)->f34;
    a0 = func_020307B0((void *)a0);
loc_02155F76:
a0 = ((struct Obj02657 *)t4)->f24;
    if (a0 == 0) goto loc_02155F80;
loc_02155F7C:
    a0 = func_021F6888((void *)a0);
loc_02155F80:
a0 = ((struct Obj02657 *)t4)->f3C;
    if (a0 == 0) goto loc_02155F8A;
loc_02155F86:
    a0 = func_020307B0((void *)a0);
loc_02155F8A:
a0 = ((struct Obj02657 *)t4)->f38;
    if (a0 == 0) goto loc_02155F94;
loc_02155F90:
    a0 = func_0215716C((void *)a0);
loc_02155F94:
a0 = ((struct Obj02657 *)t4)->f8;
a1 = 0;
((struct Obj02657 *)((char *)a0))->f0 = a1;
    return a0;}






struct Obj *func_02155F9C(int a0){
    int a1;
    int a2;
    int t4;
    Obj *p;

t4 = a0 + 0;
a1 = ((struct Obj07201 *)t4)->f3C;
a2 = ((struct Obj07201 *)t4)->f1C;
a0 = 4;
    p = func_02156CAC(a0, a1, a2);
loc_02155FAA:
a1 = ((struct Obj07201 *)t4)->f28;
*(Obj * *)&((struct Obj07201 *)t4)->f2C = p;
p->f00 = a1;
    return p;}





/*
 * 2026-10-05 (D9 lane 02): callee 0x021FD948 is the ov132 setter, already matched in ov132_func_021FD938.c. Region hint ov132 added.
 */
void func_02155FB4(Work_02155FB4 *w)
{
    if (w->f14 == 1)
        func_021FD948(w->f28, (u32)w->f3C);
}





/*
 * Byte-correct (first draft). Blocker: 0x021FD4F8 has no func_ label in any
 * overlay listing (ov094/ov132/ov135/ov186 overlap it).
 *
 * 2026-10-05 (D9 lane 02): callee 0x021FD4F8 is a real function in ov132 (not ov186/ov094/ov135, where the address is mid-function). Filed it as the EXACT
 *   witness src/matched/ov/ov132_func_021FD4F8.c (50 bytes, finds the entry with a given id byte); symbols line now names ov132. Bytes unchanged. Stays MATCH only until that file gets its shard.
 */
void func_02155FC8(Work_02155FC8 *w)
{
    u8 i;
    u8 j;
    u32 r;

    w->f30 = func_02156F68(4, w->f28);
    if (w->f14 == 0) {
        for (i = 0; i < 4; i++) {
            if (i == 0)
                func_02156FC4((int)w->f30, w->f44[i], (int)w->f3C);
            else
                func_021572E4(w->f38, w->f30, w->f44[i], i - 1, 4);
        }
    } else {
        j = 0;
        for (i = 0; i < 4; i++) {
            r = func_021FD4F8(w->f28, w->f44[i]);
            if (r != 0) {
                func_02157000((int)w->f30, w->f44[i], r);
            } else {
                func_021572E4(w->f38, w->f30, w->f44[i], j, 4);
                j++;
            }
        }
    }
    w->f30->f18 = w->f24;
    w->f30->f14 = w->f38;
    func_02157174(4, w->f38, (struct Party *)w->f30);
}



/*
 * EXACT* only because the unlabelled function at 0x0215611C follows
 * (seed it into layout/function_starts.txt). The u8 local t is what puts the
 * truncation of func_021F5140's result ahead of the w->f38 load.
 */
void func_02156074(struct Work *w){
    Member *m;
    void *h;
    u8 i;
    u8 j;
    u32 k;
    u8 t;

    if (w->f14 == 1) {
        for (i = 0; i < 4; i++) {
            m = w->party->members[i];
            for (j = 0; j < 2; j++) {
                k = func_021FD964(w->f28, i, j);
                if (k != 0xFF)
                    m->used[k] = 1;
            }
        }
    }
    h = func_021F4F14((u32)4);
    for (i = 0; i < 4; i++) {
        m = w->party->members[i];
        for (j = 0; j < 9; j++) {
            if (m->used[j] == 1) {
                t = (u32)func_021F5140(h, (u16)m->recs[j].id);
                m->total += func_02157394((int)w->f38, t);
            }
        }
    }
    func_021F4F40(h);
}
