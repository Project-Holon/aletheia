/*
 * file:     musical_dressup_sys.c
 * unit:     yes
 * function: func_02155478, func_021559E4, func_02155A4C, func_02155A6C, func_02155A8C, func_02155A90, func_02155A94, func_02155A98, func_02155C0C, func_02155F24, func_02155F4C, func_02155F9C, func_02155FB4, func_02155FC8, func_02156074, func_0215611C, func_02156420, func_02156530, func_02156710, func_02156770, func_021567D8, func_02156824, func_02156888, func_021568A8, func_021568E0, func_021568E8, func_02156908, func_02156914, func_02156934, func_02156954, func_02156978, func_0215699C, func_021569A4, func_021569EC, func_02156A3C, func_02156AD4, func_02156B74, func_02156BAC, func_02156BCC, func_02156BD0, func_02156C28, func_02156C4C, func_02156CAC, func_02156CD8, func_02156CE0, func_02156EDC, func_02156F24, func_02156F68, func_02156F98, func_02156FC4, func_02156FD0, func_02157000, func_0215700C, func_02157028, func_0215716C, func_02157174, func_0215725C, func_02157260, func_02157278, func_02157298, func_021572A8, func_021572C0, func_021572E4, func_02157364, func_0215736C, func_02157374, func_02157384, func_02157394, func_0215739C, func_02157450, func_02157650, func_0215765C, func_02157660, func_02157664, func_02157668
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
 *   func_021F6888  0x021F6888  thumb
 *   func_021FD948  0x021FD948  thumb  ov132
 *   func_021FD4F8  0x021FD4F8  thumb  ov132
 *   func_021FD964  0x021FD964  thumb  ov186
 *   func_021F4F14  0x021F4F14  thumb  ov112
 *   func_021F5140  0x021F5140  thumb  ov112
 *   func_021F4F40  0x021F4F40  thumb  ov112
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_02045A38  0x02045A38  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0200A5F8  0x0200A5F8  thumb
 *   d_02172714  0x02172714  data
 *   func_0200A768  0x0200A768  thumb
 *   func_0200A788  0x0200A788  thumb
 *   func_0200A7C0  0x0200A7C0  thumb
 *   func_0200A800  0x0200A800  thumb
 *   func_0200A7AC  0x0200A7AC  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_0201B7A0  0x0201B7A0  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02008DAC  0x02008DAC  thumb
 *   func_0200A750  0x0200A750  thumb
 *   func_021FD8F8  0x021FD8F8  thumb  ov132
 *   func_0200A644  0x0200A644  thumb
 *   d_0216FF14  0x0216FF14  data
 *   d_0216FF28  0x0216FF28  data
 *   func_02012A30  0x02012A30  thumb
 *   func_02029690  0x02029690  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_020295A4  0x020295A4  thumb
 *   func_02029C64  0x02029C64  thumb
 *   func_021854B0  0x021854B0  thumb  ov020
 *   d_0216FEFC  0x0216FEFC  data
 *   d_0216FEF0  0x0216FEF0  data
 *   d_0216FF08  0x0216FF08  data
 *   func_02158768   0x02158768  thumb  ov010
 *   func_021589D0   0x021589D0  thumb  ov010
 *   func_02045C44  0x02045C44  arm
 *   func_02008550  0x02008550  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_021FCE44  0x021FCE44  thumb  ov132
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201EF14  0x0201EF14  thumb
 *   func_021FD954  0x021FD954  thumb  ov132
 *   func_021FD95C  0x021FD95C  thumb  ov132
 *   func_0203159C  0x0203159C  arm
 *   d_02172730  0x02172730  data
 *   ov133_id  0x00000085  data
 *   func_020315D4 0x020315D4 arm
 *   func_021B6100  0x021B6100  thumb ov133
 *   func_021B63BC  0x021B63BC  thumb  ov133
 *   func_021B6294  0x021B6294  thumb ov133
 *   func_021FD52C  0x021FD52C  thumb ov132
 *   ov112_id       0x00000070  data
 *   func_021F8480  0x021F8480  thumb ov132
 *   func_021F879C  0x021F879C  thumb
 *   func_021F8640  0x021F8640  thumb
 *   d_02172754  0x02172754  data
 *   func_021F67E0  0x021F67E0  thumb  ov112
 *   _s32_div_f  0x0209C0A4  arm
 *   func_0203F0A8  0x0203F0A8  arm
 *   _ull_mul  0x0209C054  arm
 *   d_02172768  0x02172768  data
 *   func_02029BCC  0x02029BCC  thumb
 *   func_020130DC  0x020130DC  thumb
 *   func_02029C00  0x02029C00  thumb
 *   func_02013160  0x02013160  thumb
 *   func_02034714  0x02034714  arm
 *   d_0217277C     0x0217277C  data
 */
#include "../../matched/include/Obj05876.h"
#include "../../matched/include/Obj17615.h"
#include "../../matched/include/Obj17616.h"
#include "../../matched/include/Obj18685.h"
#include "../../matched/include/Obj05850.h"
#include "../../matched/include/Obj02657.h"
#include "../../matched/include/Obj07201.h"
#include "../../matched/include/Obj17617.h"
#include "../../matched/include/Obj17618.h"
#include "../../matched/include/Obj12026.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj17619.h"
#include "../../matched/include/Obj17620.h"
#include "../../matched/include/Obj17621.h"
#include "../../matched/include/Obj18732.h"
#include "../../matched/include/Obj18733.h"
#include "../../matched/include/Obj12027.h"
#include "../../matched/include/Obj17622.h"

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
struct Work;
struct BigObj;
struct Deal;
struct Src;
struct U16Vec;
struct L0200ED54;
struct Sub0200852CObj;
struct MsgBank;
struct Table;
struct Sub02008C20Obj;
struct BigSub4;
struct Rec_02155478;
struct WordSet;
struct Obj0203159C;
struct S020315D4;
struct Stage;
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

typedef struct Ctx {
	void *f00;
	unsigned int f04;
	int *f08;
	unsigned int f0c;
	unsigned int f10;
	unsigned int f14;
	unsigned int f18;
	unsigned int f1c;
	unsigned int f20;
	unsigned int f24;
	struct Req *f28;
	unsigned char pad2c[0xc];
	void *f38;
	void *f3c[4];
	unsigned int f4c;
	unsigned int f50;
	unsigned int f54;
	int f58;
	void *f5c;
	unsigned int f60;
	void *f64;
	void *f68[4];
	unsigned char b78[4];
	unsigned int f7c;
	unsigned char b80[8];
	struct Info *f88;
	unsigned char slot[0x40];
	unsigned int fcc;
	unsigned int fd0;
	unsigned int fd4;
	unsigned int fd8;
	unsigned int fdc;
	void *fe0;
	unsigned int fe4;
} Ctx;

typedef signed int     s32;

typedef struct Task {
    void *f00;
    void *f04;
    u8 pad08[0x30];
    void *f38;
    void *f3c[4];
    u8 pad4c[4];
} Task;

typedef signed short   s16_02155478;

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

typedef struct Rec6 {
    u16 id;
    short f2;
    u8 idx;
    u8 pad5;
} Rec6;

typedef struct Member {
    u32 kind;                  /* 0x00 */
    u8 pad04[4];
    u16 f08;                   /* 0x08 */
    u8 f0a;
    u8 f0b;
    u8 f0c;
    u8 pad0d[3];
    u32 f10;                   /* 0x10 */
    Rec6 recs[9];              /* 0x14 */
    u16 total;                 /* 0x4A */
    u16 score[4];              /* 0x4C */
    u32 used[9];               /* 0x54 */
    u16 f78;                   /* 0x78 */
} Member;

typedef struct Party {
    u32 f00;
    Member *members[4];        /* 0x04 */
} Party;

typedef struct Stage {
    void *f00;                 /* 0x00 */
    Member *f04[4];            /* 0x04 */
    void *f14;                 /* 0x14 */
    void *f18;                 /* 0x18 */
    u8 pad1c[0x20 - 0x1C];
} Stage;

typedef struct Link {
    struct Work *owner;        /* 0x00 */
    void *sess;                /* 0x04 */
} Link;

typedef struct Work {
    void *f00;                 /* 0x00 */
    void *f04;                 /* 0x04 */
    Link *link;                /* 0x08 */
    u32 state;                 /* 0x0C */
    u8 f10;                    /* 0x10 */
    u8 pad11[3];
    u32 f14;                   /* 0x14 */
    void *f18;                 /* 0x18 */
    void *f1c;                 /* 0x1C */
    void *f20;                 /* 0x20 */
    void *f24;                 /* 0x24 */
    void *f28;                 /* 0x28 */
    void *f2c;                 /* 0x2C */
    Party *party;              /* 0x30 */
    struct Sub_02155478 *f34;           /* 0x34 */
    void *f38;                 /* 0x38 */
    void *f3c;                 /* 0x3C */
    void *f40;                 /* 0x40 */
    u8 f44[4];                 /* 0x44 */
    u8 f48[4];                 /* 0x48 */
    u8 f4C;                    /* 0x4C */
    u8 pad4d[3];
    u32 f50;                   /* 0x50 */
} Work;

typedef u32 (*TaskFn)(void *task, u32 *state, Work *work);

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

typedef struct Ent {
    u16 a;
    s16_02155478 b;
    u8 c;
    u8 pad[3];
} Ent;

typedef struct Rec_02155478 {
    u16 id;
    u16 b0 : 2;
    u16 b2 : 1;
    u16 b3 : 5;
    u32 f04;
    u8 name[0x10];
    Ent ent[8];
} Rec_02155478;

typedef struct Disp {
    u32 a : 5;
    u32 e : 4;
    u32 b : 7;
    u32 c : 5;
    u32 d : 6;
    u32 f : 2;
    u32 g : 3;
    Rec_02155478 recs[4];
    u16 text[0x25];
    u8 f1ae;
    u8 f1af;
} Disp;

typedef struct Sub_02155478 {
	unsigned int f00;
	unsigned int f04;
	Disp *f08;
	void *f0c;
	void *f10;
	unsigned char pad14[0x34];
	int f48;
	int f4c;
} Sub_02155478;

struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

typedef struct Slot_02155478 {
	unsigned char f00;
	unsigned char f01;
	unsigned short f02;
	unsigned char pad4[0xa];
	unsigned char f0e;
	unsigned char padf[0x1d];
} Slot_02155478;

typedef struct Pos {
    u32 x;
    u32 y;
    u32 z;
} Pos;

typedef signed short   s16_02156420;

typedef signed char s8;

typedef short s16_02156908;

typedef short s16_021569EC;

typedef signed short   s16_02156AD4;

typedef struct Obj_02156BD0 {
    u32 *f00;
    u32 pad[2];
    u32 *f0c;
} Obj_02156BD0;

typedef struct S S;

typedef short s16_02156CE0;

typedef struct StageWork {
    Stage *stage;       /* 0x00 */
    u32 f04;
    u32 f08;
} StageWork;

typedef struct Ent_02157028 {
    u8 f00;             /* 0x00 */
    u8 f01[4];          /* 0x01 */
    u8 f05;             /* 0x05 */
    u8 pad06[0x14 - 0x06];
    u16 f14;            /* 0x14 */
    u8 pad16[0x2C - 0x16];
} Ent_02157028;

typedef struct Src {
    u32 f00;
    Ent_02157028 *f04;           /* 0x04 */
} Src;

typedef struct Deal_02157028 {
    u8 f00[4];          /* 0x00 */
    u8 f04[4];          /* 0x04 */
    u8 f08[4];          /* 0x08 */
    Ent_02157028 *f0C;           /* 0x0C */
} Deal_02157028;

typedef struct Deal_02157174 {
    u8 f00[4];          /* 0x00 */
    u8 f04[4];          /* 0x04 */
} Deal_02157174;

typedef short s16_02157278;

typedef short s16_021572A8;

typedef struct Deal_021572A8 {
    u8 f00[4];          /* 0x00 */
    u8 f04[4];          /* 0x04 */
    u8 f08[4];          /* 0x08 */
} Deal_021572A8;

typedef struct Deal_021572C0 {
    u8 f00[4];          /* 0x00 */
} Deal_021572C0;

typedef struct Move {
    u16 id;             /* 0x00 */
    u8 f02;             /* 0x02 */
    u8 pad03;
} Move;

typedef struct Ent_021572E4 {
    u16 f00;            /* 0x00 */
    u8 f02[4];          /* 0x02 */
    u16 f06;            /* 0x06 */
    u8 pad08[4];
    Move moves[8];      /* 0x0C */
} Ent_021572E4;

typedef struct Tbl {
    u8 pad00[0x0C];
    Ent_021572E4 ents[1];        /* 0x0C */
} Tbl;

typedef struct Deal_021572E4 {
    u8 f00[4];          /* 0x00 */
    u8 f04[4];          /* 0x04 */
    u8 f08[4];          /* 0x08 */
    Tbl *f0C;           /* 0x0C */
} Deal_021572E4;

typedef signed short   s16_021572E4;

typedef short s16_02157374;

typedef struct Slot_021569EC {
    u8 pad00[0xE];
    u8 f0e;             /* 0x0E */
    u8 pad0f[0x2C - 0xF];
} Slot_021569EC;

typedef struct Deal_02157374 {
    u8 pad00[8];
    u8 map[4];          /* 0x08 */
    Slot_021569EC *slots;        /* 0x0C */
} Deal_02157374;

typedef struct Rec2C {
    u8 pad[0xF];
    u8 f0f;
    u8 pad10[0x1C];
} Rec2C;

typedef struct Table {
    u8 pad[8];
    u8 index[4];        /* 0x08 */
    Rec2C *recs;        /* 0x0C */
} Table;

typedef struct Obj_02157028 {
    u8 pad00[0x18];
    u16 f18;            /* 0x18 */
} Obj_02157028;

typedef struct Work_0215739C {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    Obj_02157028 f08;            /* 0x08 */
    u8 pad[0xF8 - 0x08 - sizeof(Obj_02157028)];
    void *fF8;          /* 0xF8 */
} Work_0215739C;

typedef struct Args {
    Obj_02157028 *obj;
    void *sub;
    u32 zero;
} Args;

typedef struct Sub_021569EC {
    u8 pad00[0x48];
    int f48;            /* 0x48 */
    int f4c;            /* 0x4C */
} Sub_021569EC;

typedef struct Rec_021569EC {
    void *f00;          /* 0x00 */
    u8 pad04[0x0C];
    u16 f10;            /* 0x10 */
    u8 f12;             /* 0x12 */
    u8 pad13;
    void *f14;          /* 0x14 */
    Sub_021569EC f18;            /* 0x18 */
} Rec_021569EC;

typedef struct Work_02157450 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    Obj_02157028 f08;            /* 0x08 */
    u8 pad[0xF8 - 0x08 - sizeof(Obj_02157028)];
    Sub_021569EC *fF8;           /* 0xF8 */
} Work_02157450;

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
extern void func_02039C68(Link *p, u32 lo, u32 hi);
extern u32 func_02039CB4(Link *p, u32 lo, u32 hi);
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
extern u32 func_0203D1A4(Link *p);
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
extern Party *func_0201A920(u32 heap);
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
extern int func_021F6888(void *);
extern void func_021FD948(char *p, u32 value);
extern u32 func_021FD4F8(struct Ctx *p, u8 key);
extern u32 func_021FD964(void *p, u32 i, u32 j);
extern u32 *func_021F4F14(int heap);
extern unsigned char func_021F5140(void *p, int i);
extern void func_021F4F40(void **p);
extern void func_0203F4E4(struct RtcDate *date);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32 n);
extern void func_02082D44(void *src, void *dst, u32 size);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec_02155478 *rec);
extern void *func_0200A5F8(void *p);
extern void func_0200A768(struct Big *p);
extern void func_0200A788(struct Big *p);
extern void func_0200A7C0(struct Big *p, u8 value);
extern void func_0200A800(struct Big *p, s32 delta);
extern void func_0200A7AC(struct Big *p, u32 index, u8 value);
extern u16 *func_020127A4(void *p);
extern void func_0201B7A0(void *a0, int a1, int a2, int a3);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 func_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);
extern struct BigSub4 *func_0200A750(struct Big *p, u32 index);
extern u32 func_021FD8F8(char *p, u32 index);
extern u32 func_0200A644(struct Big *p, u8 index);
extern u32 func_02012A30(const struct BigObj *p);
extern void *func_02029690(void *a, u32 b, u32 c);
extern void *func_02029CC0(void *a);
extern u8 *func_020295A4(u8 *p, u32 a);
extern void *func_02029C64(void *a);
extern void *func_021854B0(void *p, int u, s16_02156420 a, const int *s, u16 x);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern int func_021589D0(int a0);
extern struct MsgBank *func_02045C44(const void *file, u32 heapId);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern int func_021FCE44(char *p, u32 index);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201EF14(struct WordSet *p, u32 i, void *mon);
extern u32 func_021FD954(char *p);
extern u32 func_021FD95C(char *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_020315D4(struct S020315D4 *p);
extern u8 *func_021B6100(u8 *parent, int heap);
extern int func_021B63BC(int);
extern void func_021B6294(char *p);
extern void func_021FD52C(struct S *s);
extern u8 *func_021F8480(u8 *input, int heap);
extern int func_021F879C(int);
extern void func_021F8640(int);
extern char *func_021F67E0(u16 a, u8 b, u8 c, u8 d, u32 e, u16 heap);
extern u32 func_0203F0A8(void);
extern int _s32_div_f(int dividend, int divisor);
extern void *func_02029BCC(void *a, u32 b);
extern void func_020130DC(Obj_02157028 *o);
extern void *func_02029C00(void *h);
extern void func_02013160(u8 *o, void *a1, u32 a2);
extern void func_02034714(const char *expr, u32 line, const char *file);
int func_02155478(void *proc, int *seq, struct Ctx *ctx);
void *func_021559E4(void *a, int b, void *c, int d);
void func_02155A4C(struct Ctx *ctx);
void func_02155A6C(struct Ctx *ctx);
void func_02155A8C(u8 *p, u32 v);
u32 func_02155A90(u8 *p);
u32 func_02155A94(u8 *p);
void *func_02155A98(void *a, void *b, u8 c, u32 d, Link *link);
int func_02155C0C(void *evt, void *unused, Work *s);
void func_02155F24(int *p);
int func_02155F4C(int a0);
struct Obj *func_02155F9C(int a0);
void func_02155FB4(Work_02155FB4 *w);
void func_02155FC8(Work_02155FC8 *w);
void func_02156074(Work *w);
void func_0215611C(Work *w);
void func_02156420(Work *w);
void func_02156530(Work *w);
int func_02156710(void *evt, Work *s);
int func_02156770(void *evt, Work *s);
void func_021567D8(void *evt, Work *s);
void func_02156824(void *evt, Work *s);
void func_02156888(void *a0, void *a1, int a2);
u8 func_021568A8(Work *w, u8 n);
u8 func_021568E0(Work *w);
u8 func_021568E8(Work *w, u8 idx);
u8 func_02156908(Work *w);
void *func_02156914(int a0, int a1);
u8 func_02156934(Work *w, u8 idx);
u16 func_02156954(Work *w);
u16 func_02156978(Work *w);
u8 func_0215699C(Work *w, u8 i);
u8 func_021569A4(Work *w, u8 idx);
u8 func_021569EC(Work *w, u8 j);
void func_02156A3C(Work *w, u8 j, void *ws, u32 slot);
void func_02156AD4(Work *w, u8 j, void *ws, u32 slot);
void func_02156B74(Work *w);
void func_02156BAC(void *p);
u32 func_02156BCC(void *p);
int func_02156BD0(void *a, u32 *out, u32 *src);
int func_02156C28(void *a, int b, int c, void **d);
int func_02156C4C(int a, int *state, int c, int *d);
Obj *func_02156CAC(int a, int b, int c);
void func_02156CD8(void *a0);
int func_02156CE0(void *proc, void *unused, Stage *prev);
int func_02156EDC(void *a, int b, int c, Ctx **d);
int func_02156F24(int a, int *state, int c, int *d);
Stage *func_02156F68(u32 heap, void *p);
int func_02156F98(Stage *s);
int func_02156FC4(int a0, int a1, int a2);
void func_02156FD0(Stage *s, u8 idx, u16 id, u8 v, u32 w, u16 x, u16 y);
int func_02157000(int a0, int a1, int a2);
void func_0215700C(Stage *s, u8 idx, u8 j, u16 id, s16_021569EC a, u8 b);
Deal_02157028 *func_02157028(u32 heap, Src *src, u16 lim);
int func_0215716C(void *a0);
void func_02157174(u32 heap, Deal_02157174 *d, Party *party);
u8 func_0215725C(u8 *p, int i);
u32 func_02157260(const u8 *p);
void func_02157278(u8 *p, u32 v);
u32 func_02157298(const u8 *p);
void func_021572A8(Deal_021572A8 *d, u32 v);
u8 func_021572C0(Deal_021572C0 *d);
void func_021572E4(Deal_021572E4 *d, void *a, u8 b, u8 slot, u16 y);
u8 func_02157364(char *a0);
int func_0215736C(int a0);
u8 func_02157374(Deal_02157374 *d, u8 i);
u8 func_02157384(struct Table *t, int i);
u16 func_02157394(int a0, int a1);
int func_0215739C(void *evt, u32 *state, Work_0215739C *w);
void *func_02157450(void *a0, void *a1, u32 kind, Rec_021569EC *rec);
void func_02157650(int *p, int v);
void func_0215765C(void);
void func_02157660(void);
void func_02157664(void);
void func_02157668(void);
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
extern const char d_02172714[];
extern const u16 d_0216FF14[10];
extern const u8 d_0216FF28[7][0x28];
extern const Pos d_0216FEFC;
extern const Pos d_0216FEF0;
extern const Pos d_0216FF08;
extern char ov133_id[];
extern const char d_02172730[];
extern u8 ov112_id[];
extern const char d_02172754[];
extern const char d_02172768[];
extern u8 d_0217277C[];









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
        func_02039C68((Link *)func_020399A8(), 0x6e, 12);
        (*seq)++;
        break;
    case 8:
        if (func_02039CB4((Link *)func_020399A8(), 0x6e, 12))
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
                          tbl.v[ctx->b78[func_0203D1A4((Link *)func_020399A8())]], 4);
            ctx->f88->f22 = 1;
            ctx->f88->f04 = 1;
            func_02155224(ctx);
            break;
        }
        func_02013128(ctx->f88, ctx->f38, 0);
        func_02013980((struct ZoneData *)ctx->f88, 1);
        ctx->f54 = func_02005C44();
        func_02005D28();
        func_02039C68((Link *)func_020399A8(), 10, 12);
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
        } else if (func_02039CB4((Link *)func_020399A8(), 10, 12)) {
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
            func_02039C68((Link *)func_020399A8(), 0xdc, 12);
        (*seq)++;
        break;
    case 18:
        if (func_0203CD98() && func_0200FB24() == 0) {
            if (func_02039CB4((Link *)func_020399A8(), 0xdc, 12) == 0)
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
 * Creates the ov010 link sequence task (func_02155C0C over a Work) and
 * either starts the wireless exchange (state 11) or shuffles the four
 * member slots and deals locally (state 13). The owner back-pointer is
 * stored through s->link while the session is read through the
 * parameter: storing through the parameter enregisters it instead.
 */
/*
 * Creates the ov010 link sequence task (func_02155C0C over a Work) and
 * either starts the wireless exchange (state 11) or shuffles the four
 * member slots and deals locally (state 13). The owner back-pointer is
 * stored through s->link while the session is read through the
 * parameter: storing through the parameter enregisters it instead.
 */
void *func_02155A98(void *a, void *b, u8 c, u32 d, Link *link)
{
    void *task;
    Work *s;
    void *tmp;

    func_0203064C(1, 0x802C, 0x42000);
    task = func_020122C0(a, 0, func_02155C0C, sizeof(Work));
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
    s->party = 0;
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
        s->f4C = s->f44[0];
        s->f38 = func_02157028(4, s->f24, lim);
        s->state = 13;
        s->f10 = 0;
    }
    return task;
}






int func_02155C0C(void *evt, void *unused, Work *s)
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
            s->f4C = func_021FD8D4(s->link->sess);
            func_02156B74((Work *)s);
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
            func_02155FB4((Work_02155FB4 *)((Work *)s));
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
        func_02155FC8((Work_02155FC8 *)((Work *)s));
        func_020120B4(s->f00, ~0u, d_02172748, s->party);
        s->state = 6;
        break;
    case 6:
        if (func_020120F0(s->f00) == 0) {
            func_02156074((Work *)s);
            s->state = 7;
            if (s->f50 == 1)
                s->state = 0x16;
        }
        break;
    case 7:
        func_0215611C((Work *)s);
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
            func_02156530((Work *)s);
            func_02156420((Work *)s);
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
    func_02156CD8((void *)a0);
loc_02155F5A:
a0 = ((struct Obj02657 *)t4)->f30;
    if (a0 == 0) goto loc_02155F64;
loc_02155F60:
    a0 = func_02156F98((Stage *)a0);
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
    func_02157174(4, w->f38, (Party *)w->f30);
}






/*
 * EXACT* only because the unlabelled function at 0x0215611C follows
 * (seed it into layout/function_starts.txt). The u8 local t is what puts the
 * truncation of func_021F5140's result ahead of the w->f38 load.
 */
void func_02156074(Work *w){
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




void func_0215611C(Work *w){
    Disp *d;
    struct RtcDate date;
    void *str;
    u8 tmp[4];
    u8 i;
    u8 j;
    u8 b;
    u8 max;
    u8 v;
    int n;
    void *x;
    Member *m;
    void *bank;
    u8 t;
    u8 t2;
    u8 u;
    u8 a;

    w->f34 = func_02030734(4, 0x14, 0, d_02172714, 0x312);
    w->f34->f08 = func_02030734(4, 0x1b0, 1, d_02172714, 0x313);
    w->f34->f04 = 0;
    w->f34->f10 = w->f28;
    d = w->f34->f08;
    func_0203F4E4(&date);
    d->a = func_02157364(w->f38);
    d->b = date.year;
    d->c = date.month;
    d->d = date.day;
    str = func_02156914((int)w, 4);
    func_02045A38(str, d->text, 0x25);
    func_02045808(str);
    d->g = 0;
    d->f1ae = 0x15;
    d->f1af = 1;
    d->f = w->f4C;
    max = 0;
    for (i = 0; i < 4; i++) {
        v = w->party->members[i]->total;
        if (max < v) {
            d->e = 0;
            max = v;
        }
        if (max == v)
            d->e = d->e + (1 << i);
    }
    for (i = 0; i < 4; i++) {
        x = 0;
        m = w->party->members[i];
        d->recs[i].id = m->f08;
        d->recs[i].b0 = m->f0a;
        d->recs[i].b2 = m->f0c;
        d->recs[i].b3 = m->f0b;
        d->recs[i].f04 = m->f10;
        if (i == w->f4C)
            x = func_02012944(w->f04);
        else if (w->f14 == 1)
            x = (void *)func_021FCE28(w->f28, func_021568E8(w, i));
        if (x != 0) {
            func_02082D44(x, d->recs[i].name, 0x10);
        } else {
            u8 val = func_02157384(w->f38, func_021568A8(w, func_021568E8(w, i)));

            bank = func_02045B38(0, 2, 0x4C, 4);
            str = func_02045EC0(bank, val);
            func_02045A38(str, (u16 *)d->recs[i].name, 8);
            func_02045808(str);
            func_02045C04(bank);
        }
        for (j = 0; j < 8; j++) {
            d->recs[i].ent[j].a = 0xFF;
            d->recs[i].ent[j].b = 0;
            d->recs[i].ent[j].c = 10;
        }
        for (j = 0; j < 9; j++) {
            if (m->recs[j].id != 0xFF) {
                u8 slot = m->recs[j].idx;

                d->recs[i].ent[slot].a = m->recs[j].id;
                d->recs[i].ent[slot].b = m->recs[j].f2;
                d->recs[i].ent[slot].c = j;
            }
        }
    }
    w->f34->f00 = 1;
    w->f34->f0c = func_0200A5F8(func_02012EBC(func_020120F4(w->f00)));
    for (a = 0; a < 4; a++) {
        tmp[a] = w->party->members[a]->total;
        w->f48[a] = a;
    }
    for (a = 0; a < 4; a++) {
        n = 4 - (a + 1);
        for (b = 0; b < n; b++) {
            t = tmp[b];
            u = tmp[b + 1];
            if (u > t) {
                t2 = w->f48[b + 1];
                tmp[b + 1] = t;
                w->f48[b + 1] = w->f48[b];
                tmp[b] = u;
                w->f48[b] = t2;
            }
        }
    }
}





/*
 * The u16 read through func_020127A4's result goes through a local k;
 * passed inline it is copied to r2 before the ldrh. The tally array is
 * `u8 cnt[4] = {0, ...}` in a nested block (as in func_02157028).
 * EXACT* because the listing extent carries two bytes of pad.
 */
void func_02156420(Work *w){
    u8 a;
    u8 b;
    u8 j;
    void *h;
    Member *m;
    void *p;
    u16 k;

    a = func_02156934(w, w->f4C);
    b = func_02156934(w, w->f48[0]);
    func_0200A768(w->f40);
    if (a == b && a != 0)
        func_0200A788(w->f40);
    func_0200A7C0(w->f40, a);
    func_0200A800(w->f40, a);
    {
        u8 cnt[4] = {0, 0, 0, 0};

        h = func_021F4F14((u32)4);
        m = w->party->members[w->f4C];
        for (j = 0; j < 9; j++) {
            if (m->recs[j].id != 0xFF)
                cnt[(u8)(u32)func_021F5140(h, (u16)m->recs[j].id)]++;
        }
        for (j = 0; j < 4; j++)
            func_0200A7AC(w->f40, j, cnt[j]);
    }
    func_021F4F40(h);
    k = *func_020127A4(w->f04);
    func_0201B7A0(w->f18, 6, k, 4);
    p = func_02012F2C(w->f04);
    if (w->f14 == 0) {
        func_02008DF0(p, 0x72);
        if (a == b && a != 0)
            func_02008DF0(p, 0x73);
    } else {
        func_02008DF0(p, 0x74);
        if (a == b && a != 0)
            func_02008DF0(p, 0x75);
    }
    func_02008DAC(p, 0x76, a);
}






/*
 * Byte-correct. Two levers: the spilled locals are declared in the order
 * of their stack slots from the top down (i, lvl, n, q, row, t), and the
 * table row pointer is set in the for-initialiser after j (a separate
 * statement stores it before `j = 0`). Blocker (MATCH): 0x021FD8F8 and
 * 0x021FD4F8 have no func_ label in any overlay listing (ov094, ov132,
 * ov135 and ov186 overlap them).
 *
 * 2026-10-05 (wave D9): the ov132 token on the 0x021FD8F8 and 0x021FD4F8 symbols
 * lines resolves 0x021FD8F8 (matched in ov132_func_021FD8EC.c). 0x021FD4F8 is an
 * unlabelled 50-byte Thumb leaf in ov132; filed as the witness
 * src/matched/ov/ov132_func_021FD4F8.c (EXACT). Still MATCH only until the
 * integrator gives that leaf a shard or label; then this file is EXACT.
 */
void func_02156530(Work *w)
{
    u8 order[10];
    u8 *buf;
    Slot_02155478 *e;
    u32 sum;
    u32 r;
    u16 *pv;
    u8 j;
    u8 v;
    u8 x;
    u8 c;
    u8 i;
    u8 lvl;
    u8 n;
    u32 q;
    const u8 *row;
    u8 t;

    buf = func_02030734(4, 0x28, 1, d_02172714, 0x3F9);
    sum = 0;
    for (i = 0; i < 10; i++) {
        e = (Slot_02155478 *)func_0200A750(w->f40, i);
        e->f00 = 4;
        e->f01 = 0;
        e->f02 = 0;
    }
    if (w->f14 == 0) {
        sum = func_0200A81C(w->f40) + func_02156934((Work *)w, w->f4C);
    } else {
        for (j = 0; j < 4; j++) {
            pv = (u16 *)func_021FD8F8(w->f28, func_021568E8(w, j));
            if (func_021FD4F8(w->f28, j) != 0) {
                sum += *pv;
                sum += func_02156934((Work *)w, j);
            }
        }
    }
    for (i = 0; i < 10; i++) {
        if (d_0216FF14[i] <= sum) {
            lvl = 10 - i;
            break;
        }
    }
    r = func_0215736C((int)w->f38);
    if (r < 7) {
        n = 0;
        for (j = 0, row = d_0216FF28[r]; j < 0x28; j++) {
            v = row[j];
            if (func_0200A644(w->f40, v) == 0) {
                buf[n] = v;
                n++;
            }
        }
    }
    q = func_021572C0(w->f38);
    for (i = 0; i < 10; i++)
        order[i] = i;
    for (t = 0; t < 10; t++) {
        for (j = 0; j < 10; j++) {
            x = func_02005728(10);
            v = order[j];
            order[j] = order[x];
            order[x] = v;
        }
    }
    for (i = 0; i < lvl; i++) {
        e = (Slot_02155478 *)func_0200A750(w->f40, order[i]);
        c = func_02156934((Work *)w, w->f4C);
        e->f00 = q;
        if ((u8)func_02005728(100) < c && n != 0) {
            x = func_02005728(n);
            e->f01 = 1;
            e->f02 = buf[x];
            for (; x < n - 1; x++)
                buf[x] = buf[x + 1];
            n--;
        }
    }
    func_020307B0(buf);
}






int func_02156710(void *evt, Work *s)
{
    func_02012A30(func_020120F4(s->f00));
    switch (s->f10) {
    case 0:
        func_02012374(evt, func_02029690(s->f00, 0, 0x3C));
        s->f10++;
        break;
    case 1:
        func_02012374(evt, func_020145CC(s->f00));
        s->f10++;
        break;
    case 2:
        s->f10++;
        break;
    case 3:
        func_02012374(evt, func_02029CC0(s->f00));
        s->f10++;
        break;
    case 4:
        return 1;
    }
    return 0;
}






int func_02156770(void *evt, Work *s)
{
    void *x;

    func_02012A30(func_020120F4(s->f00));
    x = func_0201210C(s->f00);
    switch (s->f10) {
    case 0:
        s->f10++;
        break;
    case 1:
        func_02012374(evt, (struct Evt **)func_020295A4(s->f00, 30));
        s->f10++;
        break;
    case 2:
        func_02012374(evt, (struct Evt **)func_020144DC((int)s->f00, (int)x));
        s->f10++;
        break;
    case 3:
        func_02012374(evt, func_02029C64(s->f00));
        s->f10++;
        break;
    case 4:
        return 1;
    }
    return 0;
}






void func_021567D8(void *evt, Work *s)
{
    void *x;
    Pos pos;

    x = func_0201210C(s->f00);
    pos = d_0216FEFC;
    pos.x += s->f4C << 17;
    func_02012374(evt, func_021854B0(s->f00, (int)x, 0x4E, (const int *)(&pos), 0));
}






/*
 * The call result goes through a local so both arms share one
 * func_02012374 call (calling it in each arm keeps evt in r6).
 */
void func_02156824(void *evt, Work *s)
{
    void *x;
    Pos a;
    void *r;
    Pos b;

    x = func_0201210C(s->f00);
    a = d_0216FEF0;
    b = d_0216FF08;
    if (s->f14 == 1)
        r = func_021854B0(s->f00, (int)x, 0x4D, (const int *)(&b), 1);
    else
        r = func_021854B0(s->f00, (int)x, 0x4D, (const int *)(&a), 1);
    func_02012374(evt, r);
}






void func_02156888(void *a0, void *a1, int a2)
{
    void *r4 = func_02158768(((struct Obj17617 *)a1)->f0, a2, 0, 0x15);

    func_021589D0((int)r4);
    func_02012374(a0, r4);
}






/*
 * Counts the slots below n that are occupied: without a link object every
 * slot but 0, otherwise the slots for which func_021FCE28 returns 0.
 * Byte-correct (MATCH*: the listing extent runs over the unlabelled leaf
 * at 0x021568E0). Blocker: 0x021FCE28 has no func_ label in any overlay
 * listing (ov186 has it mid-function, ov094/ov132/ov135 do not start code
 * there), so the call cannot be attested until the co-resident overlay
 * that holds it is labelled.
 */
u8 func_021568A8(Work *w, u8 n)
{
    u8 i;
    u8 cnt;

    cnt = 0;
    for (i = 0; i < n; i++) {
        if (w->f28 == 0) {
            if (i == 0)
                continue;
        } else if (func_021FCE28(w->f28, i) != 0) {
            continue;
        }
        cnt++;
    }
    return cnt;
}






/*
 * Unlabelled leaf between func_021568A8 and func_021568E8: returns the
 * byte at +0x4C.
 */
u8 func_021568E0(Work *w)
{
    return w->f4C;
}








u8 func_021568E8(Work *w, u8 idx)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (w->f44[i] == idx)
            return i;
    }
    return 0;
}







u8 func_02156908(Work *w)
{
    return func_021572C0(w->f38);
}







void *func_02156914(int a0, int a1)
{
    void *t4;
    struct MsgBank *t5;

a0 = ((struct Obj12026 *)a0)->f24;
a0 = ((struct Obj12026 *)a0)->f8;
    t5 = func_02045C44((const void *)a0, a1);
loc_0215691E:
a1 = 0;
    t4 = func_02045EC0(t5, a1);
loc_02156926:
    a0 = func_02045C04((struct Rec_02155478 *)t5);
loc_0215692E:
    return t4;}







u8 func_02156934(Work *w, u8 idx)
{
    u16 v;

    v = w->party->members[idx]->total;
    if (v < 0x100)
        return v;
    return 0xFF;
}







u16 func_02156954(Work *w)
{
    u16 max = 0;
    u8 i;

    for (i = 0; i < 4; i++) {
        if (max < w->party->members[i]->total)
            max = w->party->members[i]->total;
    }
    return max;
}







u16 func_02156978(Work *w)
{
    u16 min = 0xFF;
    u8 i;

    for (i = 0; i < 4; i++) {
        if (min > w->party->members[i]->total)
            min = w->party->members[i]->total;
    }
    return min;
}







u8 func_0215699C(Work *w, u8 i)
{
    return w->f48[i];
}





/*
 * Index of the member's best score slot, or 4 on a tie for the best.
 * 2026-10-05 (wave P20): the loop counter is set before the member load
 * (i = 0; then for (; ...)). That gives the w->party temporary the
 * register the image uses (r6, shared with m). Earlier drafts set i in the
 * for-init and stayed 2 bytes out.
 */
u8 func_021569A4(Work *w, u8 idx)
{
    u8 best;
    u8 i;
    u8 max;
    u8 tie;
    Member *m;

    max = 0;
    best = 0;
    tie = 0;
    i = 0;
    m = w->party->members[idx];
    for (; i < 4; i++) {
        if (max < m->score[i]) {
            tie = 0;
            best = i;
            max = m->score[i];
        } else if (max == m->score[i]) {
            tie = 1;
        }
    }
    if (tie == 1)
        best = 4;
    return best;
}





/*
 * Result class of member j: 0 for the local player, 1 or 4 from the
 * link peer record when linked, else the table value of its slot.
 *
 * Byte-correct. Blocker: 0x021FCE28 (ov132) has no func_ label.
 */
u8 func_021569EC(Work *w, u8 j)
{
    u8 k = func_021568E8(w, j);
    void *p;

    if (j == w->f4C)
        return 0;
    if (w->f14 == 1) {
        p = (void *)func_021FCE28(w->f28, k);
        if (p != 0) {
            if (func_02008550(p) == 0)
                return 1;
            return 4;
        }
    }
    return func_02157374(w->f38, func_021568A8(w, k));
}





void func_02156A3C(Work *w, u8 j, void *ws, u32 slot)
{
    int done = 0;
    u8 k = func_021568E8(w, j);
    void *p;

    if (j == w->f4C) {
        func_0201F02C(ws, slot, func_02012944(w->f04));
        done = 1;
    } else if (w->f14 == 1) {
        p = (void *)func_021FCE28(w->f28, k);
        if (p != 0) {
            func_0201F02C(ws, slot, p);
            done = 1;
        }
    }
    if (!done) {
        u8 n = func_02157384(w->f38, func_021568A8(w, k));
        void *bank = func_02045B38(0, 2, 0x4C, 4);
        void *str = func_02045EC0(bank, n);

        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(bank);
    }
}






/*
 * Twin of func_02156A3C for the second word-set field: the local player's
 * record at +0x18, the session's record for a remote member (0x021FCE44),
 * or failing both the fallback string from message bank 0x4D.
 *
 * First draft; the ov132 call to 0x021FCE44 resolves since seeds_2 labelled it.
 */
void func_02156AD4(Work *w, u8 j, void *ws, u32 slot)
{
    int done = 0;
    u8 k = func_021568E8(w, j);
    void *p;

    if (j == w->f4C) {
        func_02012944(w->f04);
        func_0201EEF4(ws, slot, w->f18);
        done = 1;
    } else if (w->f14 == 1) {
        p = (void *)func_021FCE44(w->f28, k);
        if (p != 0) {
            func_0201EF14(ws, slot, p);
            done = 1;
        }
    }
    if (!done) {
        u8 n = func_02157384(w->f38, func_021568A8(w, k));
        void *bank = func_02045B38(0, 2, 0x4D, 4);
        void *str = func_02045EC0(bank, n);

        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(bank);
    }
}






/*
 * 2026-10-05 (wave D9): EXACT. The callees 0x021FD954 and 0x021FD95C are the
 * two Thumb getters in ov132 (matched in ov132_func_021FD938.c); the symbols
 * lines now carry the ov132 token, which gave the witness.
 */
void func_02156B74(Work *w)
{
    u32 a;
    u32 b;

    a = func_021FD954(w->f28);
    b = func_021FD95C(w->f28);
    if (w->f38 == 0)
        w->f38 = func_02157028(4, w->f24, 0);
    func_02157278(w->f38, a);
    func_021572A8(w->f38, b);
}






/*
 * One-shot state test: only when the mode word is 1, the arm9 predicate
 * agrees and the flag is clear does the flag get set.
 */
void func_02156BAC(void *p)
{
    int v = *(int *)&((struct Obj00005 *)p)->f14;

    if (v == 1) {
        if (func_0200FB24()) {
            if (((struct Obj00005 *)p)->f50 == 0) {
                ((struct Obj00005 *)p)->f50 = 1;
            }
        }
    }
}






/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02156BCC.c \
 *       --func func_02156BCC --addr 0x02156BCC --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02156BCC(void *p) { return ((struct Obj17619 *)p)->f50; }






int func_02156BD0(void *a, u32 *out, u32 *src)
{
    Obj_02156BD0 *o;
    *out = 0;
    func_02034AC4((u32)ov133_id);
    func_0203064C(1, 0x2d, 1 << 18);
    o = func_0203159C(a, 0x10, 0x2d);
    o->f00 = func_02030734(0x2d, 0xc, 0, d_02172730, 0x4e);
    o->f0c = src;
    o->f00[0] = src[0];
    o->f00[1] = src[1];
    o->f00[2] = src[2];
    return 1;
}





int func_02156C28(void *a, int b, int c, void **d) { func_020307B0(*d); func_020315D4(a); func_020306F0(0x2d); func_02034A5C((u32)ov133_id); return 1; }






/*
 * Recovered existing source/shard: setup func_02156BD0 loads ov133 (0x85).
 * Its constructor returns the allocation; ov070's same address is a setter.
 * The ov132 getter reads its session argument at +0x48, passed live in r0.
 * The 94-byte body is followed by two bytes of alignment padding.
 */
int func_02156C4C(int a, int *state, int c, int *d)
{
    switch (*state) {
    case 0:
        d[1] = (int)func_021B6100((u8 *)d[0], 0x2d);
        *state = 1;
        if (*(int *)d[3] != 0) {
            if (func_021FD904((int *)*(int *)d[3]) == 1)
                func_021FD52C((S *)*(int *)d[3]);
        }
        break;
    case 1: {
        int r = func_021B63BC(d[1]);
        if (r != 0) {
            d[2] = r;
            *state = 2;
        }
        break;
    }
    case 2:
        func_021B6294((char *)d[1]);
        return 1;
    }
    return 0;
}





Obj *func_02156CAC(int a, int b, int c) { Obj *p; int zero = 0; p = func_02030734(a, 12, 0, d_02172730, 0xa7); p->f00 = zero; p->f08 = (int)func_0200A5F8((void *)c); p->f04 = b; return p; }






/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_020307B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02156CD8.c \
 *       --func func_02156CD8 --addr 0x02156CD8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02156CD8(void *a0)
{
    func_020307B0(a0);
}






/*
 * Builds the ov010 stage: four members with their records, the ov112 deal
 * and its split. First draft plus two levers: the pooled 0x70 is ov112_id,
 * and the three colour masks come from one `mask` local shifted.
 */
int func_02156CE0(void *proc, void *unused, Stage *prev)
{
    StageWork *w;
    u32 mask;

    func_0203064C(1, 0x2E, 0xA8000);
    w = func_0203159C(proc, sizeof(StageWork), 0x2E);
    if (prev == 0) {
        func_02034AC4((u32)ov112_id);
        w->stage = func_02156F68(0x2E, 0);
        mask = 0xFF000000;
        func_02156FD0(w->stage, 0, 0x147, 0, mask, 60, 0x2E);
        func_02156FD0(w->stage, 1, 0x147, 0, mask >> 8, 120, 0x2E);
        func_02156FD0(w->stage, 2, 0x147, 0, mask >> 16, -3, 0x2E);
        func_02156FD0(w->stage, 3, 0x147, 0, 0x000000FF, -1, 0x2E);
        func_0215700C(w->stage, 0, 7, 0x13, 0, 0);
        func_0215700C(w->stage, 0, 8, 0x13, 0, 1);
        func_0215700C(w->stage, 0, 2, 0x10, 0, 2);
        func_0215700C(w->stage, 1, 1, 0x07, 0, 0);
        func_0215700C(w->stage, 1, 5, 0x09, 0, 1);
        func_0215700C(w->stage, 1, 7, 0x18, 0, 2);
        func_0215700C(w->stage, 1, 8, 0x2B, 0, 3);
        func_0215700C(w->stage, 2, 7, 0x1F, 0, 0);
        func_0215700C(w->stage, 2, 8, 0x1E, 0, 1);
        func_0215700C(w->stage, 2, 2, 0x0F, 0, 2);
        func_0215700C(w->stage, 3, 7, 0x1E, 0, 0);
        func_0215700C(w->stage, 3, 8, 0x1E, 0, 1);
        func_0215700C(w->stage, 3, 2, 0x15, 0, 2);
        *(u32 *)w->stage->f04[1] = 0;
        func_0203064C(1, 0x802C, 0x80000);
        w->stage->f18 = func_021F685C(1);
        func_021F68BC(w->stage->f18, 0, 0, 0, 0x2C);
        w->stage->f14 = func_02157028(0x2E, w->stage->f18, 0);
        func_02157174(0x2E, w->stage->f14, (Party *)w->stage);
        w->stage->f04[0]->total = 75;
        w->stage->f04[1]->total = 45;
        w->stage->f04[2]->total = 30;
        w->stage->f04[3]->total = 0;
    } else {
        w->stage = prev;
    }
    return 1;
}






int func_02156EDC(void *a, int b, int c, Ctx **d)
{
    if (c == 0) {
        func_0215716C((void *)(*d)->f14);
        func_021F6888((void *)(*d)->f18);
        func_020306F0(0x2c);
        *(*d)->f08 = 2;
        func_02156F98((Stage *)(*d));
        func_02034A5C((u32)ov112_id);
    }
    func_020315D4(a);
    func_020306F0(0x2e);
    return 1;
}







int func_02156F24(int a, int *state, int c, int *d)
{
    switch (*state) {
    case 0:
        d[1] = (int)func_021F8480((u8 *)d[0], 0x2e);
        *state = 1;
        break;
    case 1:
        if (func_021F879C(d[1]) == 1)
            *state = 2;
        break;
    case 2:
        func_021F8640(d[1]);
        return 1;
    }
    return 0;
}







Stage *func_02156F68(u32 heap, void *p)
{
    Stage *s;
    u8 i;

    s = func_02030734(heap, 0x20, 0, d_02172754, 0xBE);
    s->f00 = p;
    for (i = 0; i < 4; i++)
        s->f04[i] = 0;
    return s;
}







int func_02156F98(Stage *s){
    u8 i;

    for (i = 0; i < 4; i++) {
        if (s->f04[i] != 0 && s->f04[i]->kind == 2)
            func_020307B0(s->f04[i]);
    }
    func_020307B0(s);
}









int func_02156FC4(int a0, int a1, int a2)
{
    int a3;

a3 = a0 + 4;
a0 = a1 << 2;
*(int *)((char *)a3 + a0) = a2;
a0 = 0;
((struct Obj17620 *)((char *)a2))->f0 = a0;
    return a0;}





void func_02156FD0(Stage *s, u8 idx, u16 id, u8 v, u32 w, u16 x, u16 y)
{
    s->f04[idx] = (Member *)func_021F67E0(id, v, 0, 0, w, y);
    s->f04[idx]->kind = 2;
    s->f04[idx]->f78 = x;
}








int func_02157000(int a0, int a1, int a2)
{
    int a3;

a3 = a0 + 4;
a0 = a1 << 2;
*(int *)((char *)a3 + a0) = a2;
a0 = 1;
((struct Obj17621 *)((char *)a2))->f0 = a0;
    return a0;}






void func_0215700C(Stage *s, u8 idx, u8 j, u16 id, s16_021569EC a, u8 b)
{
    Member *o;

    o = s->f04[idx];
    o->recs[j].id = id;
    o->recs[j].f2 = a;
    o->recs[j].idx = b;
}






static inline u32 RandN(u32 n)
{
    u32 r = func_0203F0A8();

    if (n != 0)
        r = ((u64)r * n) >> 32;
    return r;
}






/*
 * Deals four stat bonuses and picks three of six entries at random. The
 * candidate buffer is `u8 buf[6] = {0, ...}` in a nested block (see
 * docs/idioms/an-initialised-local-array-takes-its-address-before-the-stores.md):
 * six explicit zero stores rematerialise sp+8 for the fill loop, and a plain
 * block-scope array hoists d->f0C out of it. RandN is the inline
 * `(u64)rand * n >> 32` helper; its n != 0 test folds away for constant n.
 */
Deal_02157028 *func_02157028(u32 heap, Src *src, u16 lim)
{
    Deal_02157028 *d;
    u8 i;
    u8 n;
    u8 k;
    u8 cnt;
    u8 a;
    u8 b;
    u8 t;

    d = func_02030734(heap, 0x10, 0, d_02172768, 100);
    d->f0C = src->f04;
    for (i = 0; i < 4; i++) {
        d->f00[i] = 0;
        d->f04[i] = 0;
    }
    for (i = 0; i < 4; i++)
        d->f00[i] = d->f0C->f01[i];
    n = d->f0C->f05 / 5;
    while (n != 0) {
        k = RandN(3) + 1;
        if (k > n)
            k = n;
        d->f00[RandN(4)] += (u8)(k * 5);
        n -= k;
    }
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};

        cnt = 0;
        for (i = 0; i < 6; i++) {
            if (d->f0C[i].f14 <= lim) {
                buf[cnt] = i;
                cnt++;
            }
        }
        if (cnt < 3) {
            buf[0] = 0;
            buf[1] = 1;
            buf[2] = 2;
            cnt = 3;
        }
        for (t = 0; t < 30; t++) {
            a = RandN(cnt);
            b = RandN(cnt);
            k = buf[a];
            buf[a] = buf[b];
            buf[b] = k;
        }
        for (i = 0; i < 3; i++)
            d->f08[i] = buf[i];
    }
    return d;
}






/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_020307B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215716C.c \
 *       --func func_0215716C --addr 0x0215716C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0215716C(void *a0){

    func_020307B0(a0);
}






/*
 * Splits each deal bonus over the four members by how many of their nine
 * records fall in each category (232 bytes, ov010 battle overlay).
 * recoup 2026-10-05 (wave P10 Y7): the loop 2 and loop 4 member pointer and
 * the loop 2 byte counter j are block-local declarations (Member *m inside each
 * for body, u8 j inside the loop 2 body). Function-scope m and j gave 21 bytes
 * of register swaps. Pragmas (lifetimes, propagation, common_subs,
 * dead_assignments, scheduling, peephole), row pointer, id local, const party
 * all left 21 or worse. Verified EXACT in c99 and c.
 */
void func_02157174(u32 heap, Deal_02157174 *d, Party *party)
{
    void *h;
    u8 i;
    u8 j;
    u8 t;
    u8 v;
    u8 tot[4];
    u8 cnt[4][4];

    h = func_021F4F14((u32)heap);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            cnt[j][i] = 0;
        tot[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        Member *m = party->members[i];
        u8 j;
        for (j = 0; j < 9; j++) {
            if (m->recs[j].id != 0xFF) {
                t = (u32)func_021F5140(h, (u16)m->recs[j].id);
                cnt[i][t]++;
                tot[t]++;
            }
        }
    }
    for (i = 0; i < 4; i++)
        d->f04[i] = _s32_div_f(d->f00[i], tot[i]);
    for (i = 0; i < 4; i++) {
        Member *m = party->members[i];
        for (j = 0; j < 4; j++) {
            v = d->f04[j] * cnt[i][j];
            m->total += v;
            m->score[j] = v;
        }
    }
    func_021F4F40(h);
}





u8 func_0215725C(u8 *p, int i) { return p[i]; }






/*
 * Little-endian 32-bit read from a byte record (inverse of func_02157278).
 */
u32 func_02157260(const u8 *p)
{
    return p[0] + (p[1] << 8) + (p[2] << 16) + (p[3] << 24);
}






/*
 * EXACT* because the listing folds the unlabelled 24-bit reader at
 * 0x02157298 into this extent.
 */
void func_02157278(u8 *p, u32 v)
{
    p[0] = v;
    p[1] = (v & 0xFF00) >> 8;
    p[2] = (v & 0xFF0000) >> 16;
    p[3] = (v & 0xFF000000) >> 24;
}






/*
 * Little-endian 24-bit read from bytes 8..10 of a record (inverse of
 * func_021572A8).
 */
u32 func_02157298(const u8 *p)
{
    return p[8] + (p[9] << 8) + (p[10] << 16);
}






void func_021572A8(Deal_021572A8 *d, u32 v)
{
    d->f08[0] = v;
    d->f08[1] = (v & 0xFF00) >> 8;
    d->f08[2] = (v & 0xFF0000) >> 16;
}






/*
 * Declaration order i, max, idx is what colours them r2, r3, r4.
 */
u8 func_021572C0(Deal_021572C0 *d)
{
    u8 i;
    u8 max;
    u8 idx;

    max = 0;
    idx = 0;
    for (i = 0; i < 4; i++) {
        if (max < d->f00[i]) {
            max = d->f00[i];
            idx = i;
        }
    }
    return idx;
}






/*
 * The stage slot b is a u8 (as wide as either callee's parameter); a u32
 * or int b is reloaded from its spill one instruction early. The u32 is
 * spelled out in the call, not through an inline reader, so the top byte is
 * loaded once and kept in ip for the fourth argument.
 */
void func_021572E4(Deal_021572E4 *d, void *a, u8 b, u8 slot, u16 y)
{
    Ent_021572E4 *e;
    u8 j;

    e = &d->f0C->ents[d->f08[slot]];
    func_02156FD0(a, b, e->f00, e->f02[3], e->f02[0] + (e->f02[1] << 8) + (e->f02[2] << 16) + (e->f02[3] << 24), e->f06, y);
    for (j = 0; j < 8; j++) {
        if (e->moves[j].id != 0x1FE && e->moves[j].id != 0x1FF)
            func_0215700C(a, b, e->moves[j].f02, e->moves[j].id, 0, j);
    }
}






/*
 * Recursive MATCH unblocker: callee of func_021F8D88 (ov132) +0008. Coherent
 * Thumb leaf in ov010 (ARM code in ov009), so the ov010 shard makes that site
 * attest as `matched` -- the earlier `arm` declaration was wrong.
 */
u8 func_02157364(char *a0)
{
    return ((struct Obj18733 *)(((struct Obj18732 *)a0)->fC))->f0;
}








int func_0215736C(int a0)
{

a0 = ((struct Obj12027 *)a0)->fC;
a0 = ((struct Obj12027 *)a0)->f6;
    return a0;}






u8 func_02157374(Deal_02157374 *d, u8 i)
{
    return d->slots[d->map[i]].f0e;
}






/*
 * Unlabelled leaf: the byte at +0xF of the 0x2C-byte record that slot i
 * of the index table at +8 selects.
 */
u8 func_02157384(struct Table *t, int i){
    return t->recs[t->index[i]].f0f;
}








u16 func_02157394(int a0, int a1)
{

a0 = a0 + a1;
a0 = ((struct Obj17622 *)a0)->f4;
    return a0;}






/*
 * Task callback of func_02157450: a 10-state sequence that pushes the
 * field-effect child tasks (the ov008 effect runner gets the effect
 * object, its direction record and a zero word) and returns 1 when done.
 */
int func_0215739C(void *evt, u32 *state, Work_0215739C *w)
{
    void *h = w->f00;

    switch (*state) {
    case 0:
        *state = 3;
        break;
    case 1:
    case 2:
        break;
    case 3:
        func_02012374(evt, func_02029BCC(h, w->f08.f18));
        (*state)++;
        break;
    case 4: {
        Args a;

        a.obj = &w->f08;
        a.sub = w->fF8;
        a.zero = 0;
        func_02012374(evt, (struct Evt **)func_020124AC(h, (u32)ov008_id, (u32 (*)(void *, u32))func_021550A0, (u32)(&a)));
        (*state)++;
        break;
    }
    case 5:
        func_020130DC(&w->f08);
        func_02012374(evt, func_02029C00(h));
        (*state)++;
        break;
    case 6:
        func_02012374(evt, func_020145CC(h));
        (*state)++;
        break;
    case 7:
        func_02012374(evt, (struct Evt **)func_021BE92C(h, (int)w->f04, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 8:
        func_02012374(evt, func_02029CC0(h));
        (*state)++;
        break;
    case 9:
        return 1;
    }
    return 0;
}






/*
 * Create the ov010 field-effect task: allocate it with func_0215739C as
 * its callback, pick the direction slot for effect kinds 4..23 (four kinds
 * per effect, the first matching case wins), start the effect object and
 * return the task.
 */
void *func_02157450(void *a0, void *a1, u32 kind, Rec_021569EC *rec)
{
    int dir = 0x29;
    void *task = func_020122C0(a0, 0, func_0215739C, 0xFC);
    Work_02157450 *w = func_020124E8(task);
    Obj_02157028 *o;
    void *sys;

    w->f00 = a0;
    w->f04 = a1;
    w->fF8 = &rec->f18;
    o = &w->f08;
    switch (kind) {
    case 5:
        func_02157650(&dir, 0);
    case 4:
        func_02157650(&dir, 2);
    case 7:
        func_02157650(&dir, 1);
    case 6:
        func_02157650(&dir, 3);
        sys = func_020120F4(a0);
        func_02013790((u32)o, (u32)sys, (u32)func_020399A8(), 1, 4);
        break;
    case 9:
        func_02157650(&dir, 4);
    case 8:
        func_02157650(&dir, 6);
    case 11:
        func_02157650(&dir, 5);
    case 10:
        func_02157650(&dir, 7);
        sys = func_020120F4(a0);
        func_020137C0((u32)o, (u32)sys, (u32)func_020399A8(), 1, 4);
        break;
    case 13:
        func_02157650(&dir, 8);
    case 12:
        func_02157650(&dir, 10);
    case 15:
        func_02157650(&dir, 9);
    case 14:
        func_02157650(&dir, 11);
        sys = func_020120F4(a0);
        func_02013864((u32)o, (u32)sys, (u32)func_020399A8(), 1, 4);
        break;
    case 17:
        func_02157650(&dir, 12);
    case 16:
        func_02157650(&dir, 14);
    case 19:
        func_02157650(&dir, 13);
    case 18:
        func_02157650(&dir, 15);
        sys = func_020120F4(a0);
        func_02013894((u32)o, (u32)sys, (u32)func_020399A8(), 1, 4);
        break;
    case 21:
        func_02157650(&dir, 16);
    case 20:
        func_02157650(&dir, 18);
    case 23:
        func_02157650(&dir, 17);
    case 22:
        func_02157650(&dir, 19);
        sys = func_020120F4(a0);
        func_020137F0((u32)o, (u32)sys, (u32)func_020399A8(), 1, rec->f12, 4);
        break;
    default:
        func_02034714((const char *)d_0217277C, 0, (const char *)d_0217277C);
        return 0;
    }
    func_02013128(o, rec->f00, 0);
    func_02013160((u8 *)o, rec->f14, 4);
    o->f18 = rec->f10;
    w->fF8->f48 = dir;
    w->fF8->f4c = 0;
    func_02013980((struct ZoneData *)o, 1);
    return task;
}





/*
 * Unlabelled leaf after func_02157450's pool: store v into *p only while
 * *p still holds the unset sentinel 0x29, so the first call wins.
 */
void func_02157650(int *p, int v)
{
    if (*p == 0x29)
        *p = v;
}




/* Four empty leaves (unused callback slots). */
void func_0215765C(void)
{
}




void func_02157660(void)
{
}




void func_02157664(void)
{
}




void func_02157668(void)
{
}
