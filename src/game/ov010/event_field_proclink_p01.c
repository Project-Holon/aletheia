/*
 * file:     event_field_proclink_p01.c
 * unit:     yes
 * function: func_0215EC54, func_0215EC6C, func_0215EC80, func_0215EC94, func_0215ECBC, func_0215ED8C, func_0215EDA0, func_0215EDD0, func_0215EE24, func_0215EE38, func_0215EE68, func_0215EEBC, func_0215EED0, func_0215EEF8, func_0215EF2C, func_0215EF40, func_0215EF60, func_0215EFCC, func_0215EFF4, func_0215F060, func_0215F088, func_0215F0B8, func_0215F0E8, func_0215F104, func_0215F118, func_0215F168, func_0215F1C8, func_0215F214, func_0215F228, func_0215F238, func_0215F280, func_0215F2A0, func_0215F2B8, func_0215F2DC, func_0215F2F0, func_0215F318, func_0215F33C, func_0215F3A4, func_0215F424, func_0215F4F4, func_0215F52C, func_0215F608, func_0215F630, func_0215F64C, func_0215F6E8, func_0215F734, func_0215F8A8, func_0215F900, func_0215F920, func_0215F948, func_0215F9C4, func_0215F9DC, func_0215F9EC, func_0215FA00, func_0215FA1C, func_0215FA34, func_0215FA44, func_0215FA54, func_0215FBF4, func_0215FC40, func_0215FCE0, func_0215FD0C, func_0215FEC8, func_0215FED4, func_0215FEF0, func_0215FEF4, func_0215FF34, func_0215FF54, func_02160018, func_0216025C, func_0216040C, func_02160564, func_021605C0, func_0216060C, func_02160668, func_021606D0, func_021606DC, func_0216070C, func_0216075C, func_021607E0, func_02160A28, func_02160A4C, func_02160A64, func_02160A7C, func_02160A94, func_02160C88, func_02160D6C, func_02160DDC, func_02160E08, func_02160F88, func_02160FB4, func_02160FE0, func_02161070, func_0216117C, func_021611E0, func_02161214, func_02161280, func_02161308, func_02161350, func_02161378, func_021613A4, func_021613CC, func_02161484, func_02161534, func_02161554, func_02161610, func_0216163C, func_02161668, func_021616A4, func_021616F0
 * address:  0x0215EC54
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
 *   func_02165534  0x02165534  thumb  ov010
 *   func_021C8268  0x021C8268  thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A10  0x02189A10  thumb  ov021
 *   func_021C7FBC  0x021C7FBC  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02014468  0x02014468  thumb
 *   func_02014464  0x02014464  thumb
 *   func_021C7E50  0x021C7E50  thumb  ov021
 *   func_02014470  0x02014470  thumb
 *   func_0201446C  0x0201446C  thumb
 *   func_021C7E54  0x021C7E54  thumb  ov021
 *   func_02184EEC  0x02184EEC  thumb  ov020
 *   func_0201235C  0x0201235C  thumb
 *   func_02184F40  0x02184F40  thumb  ov020
 *   func_021587B0 0x021587B0 thumb ov010
 *   func_021D1C24   0x021D1C24  thumb
 *   func_02013FFC 0x02013FFC thumb
 *   d_02171258 0x02171258 data a4
 *   d_02171200 0x02171200 data a4
 *   d_02171254 0x02171254 data a4
 *   d_021711FC 0x021711FC data a4
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020142E8  0x020142E8  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02189734  0x02189734  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   d_0217294C     0x0217294C  data  ov010  a4
 *   func_020113D0  0x020113D0  thumb
 *   func_0202EB44  0x0202EB44  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_0201213C  0x0201213C  thumb
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02159168   0x02159168  thumb  ov010
 *   func_0201214C  0x0201214C  thumb
 *   func_02012158 0x02012158 thumb
 *   func_0204A1BC 0x0204A1BC arm
 *   func_02159114 0x02159114 thumb ov010
 *   func_0215911C  0x0215911C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_0215A480  0x0215A480  thumb  ov010
 *   func_02162788  0x02162788  thumb  ov010
 *   func_0215A490  0x0215A490  thumb  ov010
 *   func_02162774  0x02162774  thumb  ov010
 *   func_02158F54 0x02158F54 thumb ov010
 *   func_0215A500 0x0215A500 thumb ov010
 *   func_020056EC  0x020056EC  thumb
 *   func_02159F80 0x02159F80 thumb ov010
 *   func_02012914 0x02012914 thumb
 *   func_02023F60  0x02023F60  thumb
 *   func_02012444  0x02012444  thumb
 *   d_021B9EC0     0x021B9EC0  data  a4
 *   ov_id_00CD     0x000000CD  data  a1
 *   func_0215FA1C  0x0215FA1C  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_021666A4  0x021666A4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02014554  0x02014554  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_02158A20  0x02158A20  thumb  ov010
 *   func_02161B90  0x02161B90  thumb  ov010
 *   ov180_id       0x000000B4  data
 *   ov181_id       0x000000B5  data
 *   ov205_id       0x000000CD  data
 *   ov182_id       0x000000B6  data
 *   d_021B800C     0x021B800C  data  ov180
 *   d_021BAB24     0x021BAB24  data  ov181
 *   d_021B9E54     0x021B9E54  data  ov205
 *   d_021B9BA0     0x021B9BA0  data  ov182
 *   func_0215E580  0x0215E580  thumb  ov010
 *   func_02012934   0x02012934  thumb
 *   func_02012FCC   0x02012FCC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020083E4  0x020083E4  thumb
 *   func_020111E8  0x020111E8  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C3B8  0x0200C3B8  thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_02183B6C 0x02183B6C thumb ov020
 *   OS_SleepThread     0x02034ac4  arm
 *   DSP_SyncPipe       0x0218571c  thumb
 *   DSPiBlockingQueue  0x00000014  data
 *   abs_id_14      0x00000014  data
 *   sub_02034AC4   0x02034AC4  arm
 *   sub_02034A5C   0x02034A5C  arm
 *   func_020129B8  0x020129B8  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02005C44  0x02005C44  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021BE92C  0x021BE92C  thumb
 *   func_0217CE08  0x0217CE08  thumb
 *   func_0217CDBC  0x0217CDBC  thumb
 *   func_0217FA24  0x0217FA24  thumb
 *   ov122_id       0x0000007A  data
 *   ov172_id       0x000000AC  data
 *   d_021D5764     0x021D5764  data  ov122
 *   d_021C7240     0x021C7240  data
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_0201232C  0x0201232C  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 *   func_020355D8  0x020355D8  arm
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_02013CE0 0x02013CE0 thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_021A0F94  0x021A0F94  thumb  ov021
 *   func_021A0FA8  0x021A0FA8  thumb  ov021
 *   func_021A12A4  0x021A12A4  thumb  ov021
 *   func_021945A4  0x021945A4  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0215E840  0x0215E840  thumb  ov010
 *   func_0215EA30  0x0215EA30  thumb  ov010
 *   func_0215EA38  0x0215EA38  thumb  ov010
 *   func_021644F4  0x021644F4  thumb  ov010
 *   func_020124E4  0x020124E4  thumb
 *   func_020129D0  0x020129D0  thumb
 *   d_021712AC     0x021712AC  data
 *   func_021A12BC   0x021A12BC  thumb
 *   func_0200C404   0x0200C404  thumb
 *   func_0200C468   0x0200C468  thumb
 *   d_02172960     0x02172960  data  a4
 *   func_02164480  0x02164480  thumb  ov010
 *   func_021C5224  0x021C5224  thumb  ov021
 *   func_021C5348  0x021C5348  thumb  ov021
 *   func_021C536C  0x021C536C  thumb  ov021
 *   func_021C5380  0x021C5380  thumb  ov021
 *   func_021C5394  0x021C5394  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02028754  0x02028754  thumb
 *   func_0200C464  0x0200C464  thumb
 *   func_02040588  0x02040588  arm
 *   func_02188C54  0x02188C54  thumb
 *   func_02190344  0x02190344  thumb
 *   func_02012C0C  0x02012C0C  thumb
 *   func_021C4F7C  0x021C4F7C  thumb
 *   func_021C51A0  0x021C51A0  thumb  ov021
 *   func_02190398  0x02190398  thumb
 *   func_021C5334  0x021C5334  thumb  ov021
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201897C  0x0201897C  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   d_021712CC     0x021712CC  data
 *   func_02188DA0  0x02188DA0  thumb  ov021
 *   func_02188DB0  0x02188DB0  thumb  ov021
 *   func_0201292C  0x0201292C  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   func_021C3E00  0x021C3E00  thumb  ov136
 *   ov136_id       0x00000088  data
 *   d_02172978     0x02172978  data  a1
 *   func_02012A30  0x02012A30  thumb
 *   func_02012134  0x02012134  thumb
 *   func_02029DBC  0x02029DBC  thumb
 *   func_02029DD8 0x02029DD8 thumb
 *   sub_02030734   0x02030734  arm
 *   func_0200CA38  0x0200CA38  thumb
 *   func_020120F8 0x020120F8 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013CC8 0x02013CC8 thumb
 *   func_0202E474  0x0202E474  thumb
 *   func_02008298  0x02008298  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_0216F7BC  0x0216F7BC  thumb  ov010
 *   func_020128B8  0x020128B8  thumb
 *   func_0202138C  0x0202138C  thumb
 *   func_021C3CC0  0x021C3CC0  thumb  ov136
 *   func_021C3D44  0x021C3D44  thumb  ov136
 *   func_021C3DA4  0x021C3DA4  thumb  ov136
 *   func_021C3E04 0x021C3E04 thumb ov136
 *   func_021C3E24 0x021C3E24 thumb ov136
 *   func_0201B2B0  0x0201B2B0  thumb
 *   func_02169AB8  0x02169AB8  thumb  ov010
 */
#include "../../matched/include/Obj12043.h"
#include "../../matched/include/Obj17699.h"
#include "../../matched/include/Obj02057.h"
#include "../../matched/include/Obj12044.h"
#include "../../matched/include/Obj17700.h"
#include "../../matched/include/Obj17701.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj17702.h"
#include "../../matched/include/Obj17703.h"
#include "../../matched/include/Obj17704.h"
#include "../../matched/include/Obj17706.h"
#include "../../matched/include/Obj04132.h"
#include "../../matched/include/Obj04883.h"
#include "../../matched/include/Obj05853.h"
#include "../../matched/include/Obj17707.h"
#include "../../matched/include/Obj12045.h"
#include "../../matched/include/Obj17708.h"
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj12324.h"
#include "../../matched/include/Obj18932.h"
#include "../../matched/include/Obj12327.h"
#include "../../matched/include/Obj09158.h"
#include "../../matched/include/Obj09159.h"
#include "../../matched/include/Obj18938.h"
#include "../../matched/include/Obj05854.h"
#include "../../matched/include/Obj18944.h"
#include "../../matched/include/Obj04884.h"
#include "../../matched/include/Obj00029.h"
#include "../../matched/include/Obj00654.h"

struct Arg;
struct Desc;
struct Obj;
struct Pair;
struct BigObj;
struct Ctx;
struct Sub02014444Obj;
struct C;
struct S0201235C;
struct IcaAnime;
struct Comm;
struct Evt;
struct Big;
struct Work_0215F52C;
struct Sub02008700Obj;
struct DSPPipe;
struct _OSThreadQueue;
struct Owner;
struct Work_0215EC54;
struct Rec44;
struct SaveBlock;
struct Hdr;
struct Flags;
struct Info;
struct Rect;
struct Sub02008F80Obj;
struct Blk37;
struct MyItemSave;
struct Rec1C;
struct Ctx_02161484;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { FALSE, TRUE } Bool;

typedef struct Arg {
    u8 pad00[8];
    void *f08;          /* 0x08 */
    u16 f0c;            /* 0x0C */
} Arg;

struct C {
    u8 pad00[8];
    void *f8;
    u16 fc;
};

typedef struct Pair { u32 a, b; } Pair;

typedef struct Area {
    u16 x;              /* 0x00 */
    u16 z;              /* 0x02 */
    u16 w;              /* 0x04 */
    u16 h;              /* 0x06 */
} Area;

typedef signed int     s32;

typedef struct Entry_0215F424 {
    u32 f00;
    u16 f04;
    u16 f06;
} Entry_0215F424;

typedef struct Entry_0215F4F4 { u32 a; u16 b,c; } Entry_0215F4F4;

typedef signed short s16_0215EC54;

typedef struct Work_0215F52C {
    void *sys;          /* 0x00 */
    void *f04;          /* 0x04 */
    u32 f08;            /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u8 f14[8];          /* 0x14 */
    u8 f1c[0x28 - 0x1C];/* 0x1C */
    u8 f28[8];          /* 0x28 */
    u8 f30[4];          /* 0x30 */
    u32 step;           /* 0x34 */
    u32 seq[16];        /* 0x38 */
    int timer;          /* 0x78 */
} Work_0215F52C;

typedef struct Work_0215FA44 {
    void *sys;          /* 0x00 */
    u8 pad04[0x0C - 0x04];
    u8 f0c[0x1C - 0x0C];/* 0x0C */
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
    u32 f24;            /* 0x24 */
    u32 f28;            /* 0x28 */
} Work_0215FA44;

/* record behind the descriptor: owner, its context, the context's head */
struct Rec_0215FBF4 {
    int   owner;
    void *ctx;
    void *head;
};

/* the 0x5C-byte record behind the descriptor */
struct Rec_0215FC40 {
    u16          id;     /* 0x00 */
    struct Desc *desc;   /* 0x04 */
    int          owner;  /* 0x08 */
    int          field;  /* 0x0C */
    u32          f10;
    u32          f14;
    int          f18;
    int          owner2; /* 0x1C */
    int          field2; /* 0x20 */
    struct Desc *desc2;  /* 0x24 */
    u32          f28;
    int          f2C;
    void        *fn30;
    void        *fn34;
    void        *fn38;
    void        *self;   /* 0x3C */
    u8           pad40[0x5C - 0x40];
};

typedef struct Info {
    u16 id;
    u16 flags;
    u32 f04;
    u32 f08;
    void *obj;
    void *field;
} Info;

typedef struct Query {
    u16 a;
    u16 b;
    u32 c;
} Query;

typedef struct Ctx {
    u16 f00;            /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    void *field;        /* 0x0C */
    u32 f10;            /* 0x10 */
    u32 state;          /* 0x14 */
    u32 f18;            /* 0x18 */
    u8 req[0x28 - 0x1C];/* 0x1C */
    u32 f28;            /* 0x28 */
    u8 pad2C[0x40 - 0x2C];
    u32 f40;            /* 0x40 */
    u32 f44;            /* 0x44 */
    u32 f48;            /* 0x48 */
    u32 f4c;            /* 0x4C */
} Ctx;

/* the 0x40-byte block hung off the record */
struct Sub {
    int          owner;  /* 0x00 */
    int          field;  /* 0x04 */
    struct Desc *desc;   /* 0x08 */
    u32          f0C;
    u32          f10;
    void        *fn14;
    void        *fn18;
    u32          f1C;
    void        *rec;    /* 0x20 */
    u8           pad24[0x40 - 0x24];
};

/* the 0x20-byte record behind the descriptor */
struct Rec {
    struct Desc *desc;   /* 0x00 */
    int          owner;  /* 0x04 */
    int          field;  /* 0x08 */
    u32          f0C;
    struct Sub  *sub;    /* 0x10 */
    u16          id;     /* 0x14 */
    u16          f16;
    u32          f18;
    u32          f1C;
};

typedef struct Flags {
    u32 f00;
    u32 f04;
    u8 pad[0x10];
} Flags;

typedef struct Req {
    u8 pad[0xC];
    u32 kind;           /* 0x0C */
    u32 detail;         /* 0x10 */
    u8 pad14[0x10];
    u32 result;         /* 0x24 */
    u32 next;           /* 0x28 */
} Req;

typedef struct Work_0215EC54 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    Req *f10;           /* 0x10 */
    u16 f14;            /* 0x14 */
    u8 pad16[2];
    u32 f18;            /* 0x18 */
} Work_0215EC54;

typedef struct Ctx_0216025C {
    u32 f00;
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u32 f0c;
    Req *req;           /* 0x10 */
    u16 id;             /* 0x14 */
} Ctx_0216025C;

typedef struct Owner {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u32 f0c;            /* 0x0C */
    u8 pad10[4];
    u32 f14;            /* 0x14 */
    u32 f18;            /* 0x18 */
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
} Owner;

typedef struct Task_0216075C {
    u16 id;             /* 0x00 */
    u8 pad02[2];
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 f0c;            /* 0x0C */
    u32 state;          /* 0x10 */
    void *handle;       /* 0x14 */
    Owner *owner;       /* 0x18 */
    u8 pad1C[4];
    u8 rect[0x14];      /* 0x20 */
    u8 flags[0x18];     /* 0x34 */
    u8 info[0x14];      /* 0x4C */
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u8 pad64[4];
    u32 f68;            /* 0x68 */
    u8 pad6C[8];
} Task_0216075C;

typedef struct Owner_021607E0 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 pad08[8];
    void *f10;          /* 0x10 */
    u8 pad14[0x10];
    u32 result;         /* 0x24 */
} Owner_021607E0;

typedef struct Callbacks_0216040C {
    void *fn[3];
    u32 arg;
    void *ctx;
} Callbacks_0216040C;

typedef struct Task_021607E0 {
    u16 id;             /* 0x00 */
    u8 pad02[2];
    u32 proc;           /* 0x04 */
    u32 prev;           /* 0x08 */
    u32 next;           /* 0x0C */
    u32 state;          /* 0x10 */
    void *handle;       /* 0x14 */
    Owner_021607E0 *owner;       /* 0x18 */
    void *work;         /* 0x1C */
    Callbacks_0216040C cb;       /* 0x20 */
} Task_021607E0;

typedef struct Proc {
    void *f00;                                      /* 0x00 */
    void *f04;                                      /* 0x04 */
    void *(*init)(Task_021607E0 *t, void *arg, u32 prev, void *work); /* 0x08 */
    u32 (*finish)(Task_021607E0 *t, void *work);             /* 0x0C */
    void (*start)(Task_021607E0 *t, void *arg);              /* 0x10 */
    void (*exit)(void *work);                       /* 0x14 */
} Proc;

typedef struct Rect {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
    u32 tag;
} Rect;

typedef int (*Hook)(void *ctx, u32 arg);

typedef struct Callbacks_02160A28 {
    Hook fn0;           /* 0x00 */
    Hook fn1;           /* 0x04 */
    Hook fn2;           /* 0x08 */
    u32 arg;            /* 0x0C */
    void *ctx;          /* 0x10 */
} Callbacks_02160A28;

typedef struct Hdr20 {
    u32 w[5];
} Hdr20;

typedef struct Save_02160A94 {
    u8 pad00[0x2C];
    u32 f2c;            /* 0x2C */
} Save_02160A94;

typedef struct Ctx_02160A94 {
    u8 pad00[0x18];
    Save_02160A94 *f18;          /* 0x18 */
    u8 pad1c[0x4C - 0x1C];
    Hdr20 hdr;          /* 0x4C */
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u32 f64;            /* 0x64 */
    u32 f68;            /* 0x68 */
    u32 f6c;            /* 0x6C */
} Ctx_02160A94;

typedef struct Src_0216040C {
    u8 pad00[0xD];
    u8 f0d;             /* 0x0D */
    u8 pad0e;
    u8 f0f;             /* 0x0F */
    u8 pad10;
    u8 f11;             /* 0x11 */
    u8 f12;             /* 0x12 */
    u8 pad13;
    u16 f14;            /* 0x14 */
    u8 pad16[0x2C - 0x16];
    u32 f2c;            /* 0x2C */
    u8 pad30[4];
    u32 f34;            /* 0x34 */
    u32 f38;            /* 0x38 */
} Src_0216040C;

typedef struct Req_02160A94 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0c[0x18 - 0x0C];
    void *f18;          /* 0x18 */
    Hdr20 hdr;          /* 0x1C */
    u16 f30;            /* 0x30 */
    u8 pad32[2];
    u32 f34;            /* 0x34 */
    u8 pad38[4];
    u32 f3c;            /* 0x3C */
    u8 pad40[4];
    u16 f44;            /* 0x44 */
    u16 f46;            /* 0x46 */
    u8 f48;             /* 0x48 */
    u8 pad49[0x50 - 0x49];
    u32 f50;            /* 0x50 */
    u8 pad54[0x5E - 0x54];
    u8 f5e;             /* 0x5E */
    u8 f5f;             /* 0x5F */
    u8 pad60[0x98 - 0x60];
} Req_02160A94;

typedef signed char s8;

typedef short s16_0216040C;

typedef struct Save_02160C88 {
    u8 pad00[0xC];
    u32 f0c;            /* 0x0C */
    u8 pad10[0x28 - 0x10];
    u32 f28;            /* 0x28 */
    u32 f2c;            /* 0x2C */
} Save_02160C88;

typedef struct Ctx_02160C88 {
    u8 pad00[0xC];
    u32 state;          /* 0x0C */
    u8 pad10[0x18 - 0x10];
    Save_02160C88 *f18;          /* 0x18 */
    u8 pad1c[0x60 - 0x1C];
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u32 f64;            /* 0x64 */
    u32 f68;            /* 0x68 */
    u32 f6c;            /* 0x6C */
} Ctx_02160C88;

typedef struct Req_02160C88 {
    u8 pad00[0x34];
    u32 f34;            /* 0x34 */
    u8 pad38[4];
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 f44;            /* 0x44 */
    u8 pad46[0x50 - 0x46];
    u32 f50;            /* 0x50 */
} Req_02160C88;

typedef struct T { void *a; void *b; u8 *c; u16 h; } T;

typedef struct Setup {
    void *party;        /* 0x00 */
    void *f04;          /* 0x04 */
    void *sys;          /* 0x08 */
    u8 f0c;             /* 0x0C */
    u8 f0d;             /* 0x0D */
    u8 count;           /* 0x0E */
    u8 slot;            /* 0x0F */
    u8 kind;            /* 0x10 */
    u8 pad11[3];
    u16 f14;            /* 0x14 */
    u8 pad16[2];
    u32 f18;            /* 0x18 */
    u8 pad1C[4];
    u32 f20;            /* 0x20 */
    u32 f24;            /* 0x24 */
} Setup;

typedef struct Src_02160E08 {
    void *party;        /* 0x00 */
    u8 pad04[8];
    void *f0c;          /* 0x0C */
    u8 pad10[0x3C - 0x10];
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 pad44;
    u16 f46;            /* 0x46 */
} Src_02160E08;

typedef struct Holder {
    void *f00;
} Holder;

typedef struct Work_02160E08 {
    u8 pad00[0x18];
    Holder *f18;        /* 0x18 */
    u8 pad1C[0x68 - 0x1C];
    u32 f68;            /* 0x68 */
} Work_02160E08;

typedef struct Inner {
    u8 pad00[0xC];
    u32 f0c;            /* 0x0C */
} Inner;

typedef struct Seq {
    u8 pad00[0xC];
    u32 state;          /* 0x0C */
    u8 pad10[8];
    Inner *f18;         /* 0x18 */
} Seq;

typedef struct Evt {
    u8 pad00[0x12];
    u8 kind;            /* 0x12 */
} Evt;

typedef struct MenuCtx {
    void *sys;          /* 0x00 */
    u8 pad04[0x24];
    u32 mode;           /* 0x28 */
    u32 slot;           /* 0x2C */
} MenuCtx;

typedef struct MenuWork {
    u8 pad00[0xC];
    u32 next;           /* 0x0C */
    u8 pad10[8];
    MenuCtx *ctx;       /* 0x18 */
    u8 pad1C[0x4C];
    u32 f68;            /* 0x68 */
} MenuWork;

typedef struct MenuSel {
    u8 pad00[0x2C];
    u32 f2c;            /* 0x2C */
    u8 pad30[4];
    u32 item;           /* 0x34 */
    u32 arg;            /* 0x38 */
} MenuSel;

typedef signed short s16;

typedef struct Rec14 {
    u32 f00;            /* 0x00 */
    u32 f04;            /* 0x04 */
    u16 f08;            /* 0x08 */
    s16 f0A;            /* 0x0A */
    u32 f0C;            /* 0x0C */
    u32 f10;            /* 0x10 */
    u32 f14;            /* 0x14 */
} Rec14;

typedef struct Sub10 {
    void *f00;          /* 0x00 */
    u32 f04;
    u32 f08;
    u32 f0C;            /* 0x0C */
} Sub10;

typedef struct Work_021611E0 {
    u8 pad00[0x18];
    Sub10 *f18;           /* 0x18 */
} Work_021611E0;

typedef struct { u8 pad00[0xc]; int f0C; u8 pad10[0x18]; int f28; u8 pad2C[4]; u32 f30; u32 f34; u32 f38; u32 f3C; } Sub_02161280;

typedef struct { u8 pad00[0xc]; int f0C; u8 pad10[8]; Sub_02161280 *f18; } Work_02161280;

typedef struct { u8 pad00[4]; int f04; u16 f08; u8 pad0A[2]; u32 f0C; u32 f10; } Evt_02161280;

typedef struct { u8 pad00[0xc]; int f0C; } Sub_021613A4;

typedef struct { u8 pad00[0xc]; int f0C; u8 pad10[8]; Sub_021613A4 *f18; } Work_021613A4;

typedef struct { u8 pad00[4]; int f04; } Evt_021613A4;

typedef struct Ctx_021613CC {
    u8 pad00[0x18];
    u32 **f18;          /* 0x18 */
    u8 pad1c[0x60 - 0x1C];
    u8 f60;             /* 0x60 */
    u8 pad61;
    u16 f62;            /* 0x62 */
    u8 pad64[4];
    u32 f68;            /* 0x68 */
} Ctx_021613CC;

typedef struct Src_021613CC {
    u8 pad00[0x2C];
    u32 f2c;            /* 0x2C */
    u8 pad30[8];
    u32 f38;            /* 0x38 */
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 f44;            /* 0x44 */
} Src_021613CC;

typedef struct Ctx_02161484 {
    u8 pad00[8];
    u32 f08;
    u32 f0c;
    u8 pad10[8];
    u32 **f18;
    u8 pad1c[0x60 - 0x1C];
    u8 f60;
    u8 pad61[7];
    u32 f68;
} Ctx_02161484;

typedef struct Src_02161484 {
    u8 pad00[0x3C];
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u16 f44;            /* 0x44 */
} Src_02161484;

typedef struct Rec_02161554 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u16 f08;            /* 0x08 */
    u8 f0a;             /* 0x0A */
    u8 f0b;             /* 0x0B */
    u32 f0c;            /* 0x0C */
    u32 f10;            /* 0x10 */
} Rec_02161554;

typedef struct { u8 pad00[0xc]; int f0C; } Sub_02161668;

typedef struct { u8 pad00[0xc]; int f0C; u8 pad10[8]; Sub_02161668 *f18; } Work_02161668;

typedef struct { u8 pad00[0xc]; int f0C; } Evt_02161668;

extern int func_02165534();
extern int func_021C8268();
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012B38(const struct BigObj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02189A10(struct Obj *p);
extern void *func_021C7FBC(void **p);
extern u16 func_02188C84(u8 *p);
extern void *func_02158780(void *a, u32 id, u32 b, u32 c, u32 d);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern u8 func_02014468(struct Sub02014444Obj *o);
extern void func_02014464(struct Sub02014444Obj *o, u8 v);
extern void func_021C7E50(u8 *p, u16 v);
extern u16 func_02014470(struct Sub02014444Obj *o);
extern void func_0201446C(void *p, u32 v);
extern u16 func_021C7E54(struct Obj *p);
extern void *func_02184EEC(void *p);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern void *func_02184F40(void *p);
extern int func_021587B0(int a0, int a1, int a2, int a3);
extern void func_021D1C24(int, int, unsigned);
extern u32 func_02013FFC(u32 id);
extern void *func_02188C80(void *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_02158FB4(void *p);
extern int func_02189734();
extern int func_020307B0();
extern u16 *func_02159AE8(void *a, void *b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020113D0(char *p, int val);
extern int func_0202EB44();
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern void func_0201213C(struct Ctx *p, u32 v);
extern void func_02159144(int v);
extern void func_02159168(int);
extern u32 func_0201214C(const struct Ctx *p);
extern void func_02012158(char *p, unsigned int v);
extern int func_0204A1BC(int,int,int,int);
extern void *func_02159114(void *p, u32 v);
extern u32 func_0215911C(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern u32 func_02012844(const struct BigObj *p);
extern u16 func_0215A480(unsigned a);
extern void func_02162788(char *p, unsigned i, u16 v);
extern u16 func_0215A490(unsigned a);
extern void func_02162774(char *p, unsigned i, u16 v);
extern void *func_02158F54(void *);
extern void func_0215A500(char *a, unsigned b);
extern u32 func_020056EC(u32 n);
extern int func_02159F80(void);
extern u16 func_02012914(const struct BigObj *p);
extern void func_02023F60(u32 a0, u32 a1, u32 mask);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern int func_0215FA1C();
extern void func_02012374(struct Evt *evt, struct Evt **out);
u8 *func_02012944(void *p);
u8 *func_02012ED0(struct Big *p);
void func_021666A4(int a0);
extern void *func_02012EBC(struct Big *p);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern int func_02014554(int a0, int a1);
extern void func_02005E30(u32 v);
extern void *func_021BE8D4(void *sys, void *proc, u32 a, u32 b);
extern void func_02158A20(int a, int v);
extern void *func_02161B90(void *p, void *a1, int kind, int sub, int flag);
void func_0215E580(void *a);
extern void *func_02012934(const struct BigObj *p);
extern int func_02012FCC(int p0);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_020083E4(unsigned short *p);
extern u32 func_020111E8(void);
extern void *func_02012F08(int *p);
extern int func_0200C3B8();
extern int func_02034AC4(s32 handle);
extern void func_02183B6C(int a, int *p);
void OS_SleepThread(struct _OSThreadQueue *queue);
void DSP_SyncPipe(struct DSPPipe *pipe);
extern int sub_02034AC4(int id);
extern void sub_02034A5C(int handle);
extern void func_020129B8(struct BigObj *p, u32 v);
extern int func_020144DC(int a0, int a1);
extern void *func_020145CC(void *sys);
extern u16 func_02005C44(void);
extern void func_02005D90(u32 h, u32 v);
extern void func_02005DF8(u32 v);
extern u32 func_02026460(void *obj);
extern int func_02158344(int a0);
extern void *func_021BE92C(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void *func_0217CE08(void *sys, void *proc, u32 a, u32 b);
extern void *func_0217CDBC(void *sys);
extern void *func_0217FA24(void *sys);
extern u32 func_02188CCC(u8 *p);
extern void func_0201232C(char *p, int a1, int a2);
extern void func_02082BCC();
extern u32 func_021A0F90(u8 *p);
extern int func_021A0EE4();
extern void func_020355D8(u8 v);
extern u16 func_02188C9C(u8 *p);
extern u32 func_02013CE0(u32);
extern void *func_02188C7C(u8 *p);
extern int func_021A0ED4(u32 a);
extern int func_021A0F30(u32 a, u32 b);
extern int func_021A0F94(u32 a);
extern void func_021A0FA8(int *p);
extern u32 func_021A12A4(void *link);
extern void *func_021945A4(void *a, u32 b, u32 c);
extern void func_0216D9A0(void *map);
extern u32 *func_0216D9E4(void *c);
extern void func_0215E840(void *field, Info *out);
extern void func_0215EA30(Query *q, u16 a, u16 b, u32 c);
extern int func_0215EA38(int a0, int a1, int a2);
extern int func_021644F4(int i, void *a, void *p);
extern void *func_020124E4(struct Obj *p);
extern void func_020129D0(struct BigObj *p, u8 v);
extern void func_021A12BC(void *, int);
extern void *func_0200C404(void *sys);
extern u16 func_0200C468(const u8 *a);
extern void func_02164480(Flags *f, void *a, void *b);
extern void func_021C5224(char *p);
extern void func_021C5348(u8 *p);
extern void func_021C536C(u8 *p);
extern int func_021C5380(u8 *p);
extern u32 func_021C5394(u8 *p, u32 *out);
extern u16 *func_020127A4(void *sv);
extern u32 func_02012B28(const struct Rec44 *p);
extern int func_02012B70(const struct BigObj *p);
extern u32 func_02028754(struct Obj *obj, u32 n);
extern u8 func_0200C464(const u8 *a, u32 i);
extern int func_02040588();
extern void *func_02188C54(void *);
extern int func_02190344();
extern u8 *func_02012C0C(struct BigObj *p);
extern char *func_021C4F7C(void *a0, int mode, const unsigned short *a2, unsigned short a3, unsigned short heap);
extern int func_021C51A0();
extern int func_02190398();
extern int func_021C5334(u32 a);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern int func_021589D0(int a0);
extern u32 func_0201AA18(void *party);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *pp, u32 id, u32 v);
extern u32 func_0201897C(struct Hdr *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_02188DA0(void);
extern void func_02188DB0(u8 *a);
extern void *func_0201292C(const struct BigObj *p);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *func_0200CA1C(void *sv);
extern u8 func_02012984(const struct BigObj *p);
extern void func_02034A5C(s32 handle);
extern u32 func_021C3E00(u32 *p);
extern u32 func_02012A30(const struct BigObj *p);
extern u32 func_02012134(u32 *p);
extern void func_02029DBC(u8 *a, u32 b);
extern int func_02029DD8(int,int);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0200CA38(struct Blk37 *p);
extern u8 *func_020120F8(const struct Ctx *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013CC8(u32);
extern void *func_0202E474(const struct BigObj *a0, int a1, int a2, int a3);
extern void func_02008298(struct MyItemSave *, u16);
extern u32 func_0202136C(u16 v);
extern int *func_0216F7BC();
extern struct Rec1C *func_020128B8(const struct BigObj *p);
extern u8 func_0202138C(u16 v);
extern void *func_021C3CC0(void *a, unsigned b, unsigned c, unsigned d, unsigned heap);
extern void *func_021C3D44(void *a, void *b, unsigned heap);
extern void *func_021C3DA4(void *a, void *b, unsigned heap);
extern int func_021C3E04(u32 *p, void *q);
extern void func_021C3E24(unsigned char *);
extern u32 func_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern int func_02169AB8(struct Work *w, u32 *state);
int func_0215EC54(int a0, int a1, int a2);
int func_0215EC6C(void *p);
int func_0215EC80(void *p);
void *func_0215EC94(void *a, void *b);
int func_0215ECBC(void *a0, int *state, Arg *arg);
int func_0215ED8C(void *p);
void *func_0215EDA0(void *p, void *ctx);
int func_0215EDD0(void *a, int *st, struct C *c);
int func_0215EE24(void *p);
void *func_0215EE38(void *p, void *ctx);
int func_0215EE68(void *a, int *st, struct C *c);
int func_0215EEBC(void *p);
void *func_0215EED0(void *p, void *ctx);
int func_0215EEF8(void *p, void *unused, struct C *ctx);
int func_0215EF2C(void *p);
void func_0215EF40(void *a0, void *a1);
int func_0215EF60(void *a, int *st, struct C *c);
void *func_0215EFCC(void *p, void *ctx);
int func_0215EFF4(void *a, int *st, struct C *c);
void *func_0215F060(void *p, void *ctx);
int func_0215F088(u16 *p, int i);
int func_0215F0B8(u16 *p, int i);
void func_0215F0E8(u32 *out, const Pair *in, u32 *ctx);
int func_0215F104(int a0, int a1);
int func_0215F118(const Area *a, u16 x, u16 z, u32 flag, void *field);
int func_0215F168(int a0, int a1);
int func_0215F1C8(void *a, void *b);
int func_0215F214(int a0, int a1);
int func_0215F228(int a0, int a1);
int func_0215F238(void *a, void *b);
int func_0215F280(void *a0, void *a1);
int func_0215F2A0(int a0, int a1);
int func_0215F2B8(int a0, int a1);
int func_0215F2DC(void *a, void *b);
int func_0215F2F0(void *a, void *b);
int func_0215F318(void *a0, int a1);
int func_0215F33C(int a, int b);
int func_0215F3A4(int a, int b);
int func_0215F424(int a0, int a1);
int func_0215F4F4(void *a,void *b);
int func_0215F52C(void *c, void *vm);
int func_0215F608(u8 *tbl, int id, int sub);
Bool func_0215F630(void *p);
int func_0215F64C(int a0, int *st, int *a2);
void *func_0215F6E8(void *p);
int func_0215F734(void *evt, u32 *i, Work_0215F52C *w);
void *func_0215F8A8(void *p, int a1);
void func_0215F900(void *a0);
int func_0215F920(int a0);
void func_0215F948(u8 *p);
int func_0215F9C4(void);
void func_0215F9DC(Work_0215F52C *w, u32 *i);
int func_0215F9EC(int a0);
void func_0215FA00(void *p, void *q);
void func_0215FA34(void);
void func_0215FA44(void);
int func_0215FA54(void *evt, u32 *state, Work_0215FA44 *w);
struct Desc *func_0215FBF4(int a0, int a1, struct Desc *a2, int a3);
struct Desc *func_0215FC40(int a0, int a1, u16 a2);
int func_0215FCE0(int a, int b, unsigned short c);
int func_0215FD0C(void *task, void *unused, Ctx *c);
u32 func_0215FEC8(u32 n);
int func_0215FED4(void *a0, void *a1);
int func_0215FEF0(void);
int func_0215FEF4(u32 *a0, u32 *a1);
int func_0215FF34(void *sys);
struct Desc *func_0215FF54(int a0, int a1, u16 a2);
int func_02160018(void *evt, u32 *state, Work_0215EC54 *w);
int func_0216025C(void *evt, u32 *state, Ctx_0216025C *c);
int func_0216040C(Req *r, u32 code);
int func_02160564(u32 state, u32 *out, u32 *err);
void func_021605C0(int a0, int a1);
int func_0216060C(int a0, int a1);
int func_02160668(int *a0, int *a1);
void func_021606D0(int a, int b);
void *func_021606DC(void *p, u32 a);
int func_0216070C(Work_0215EC54 *w);
void *func_0216075C(Owner *o, u16 id);
int func_021607E0(void *evt, u32 *state, Task_021607E0 *t);
void func_02160A28(Rect *r, u32 tag, u32 x, u32 y, u32 w, u32 h);
int func_02160A4C(Callbacks_02160A28 *c);
int func_02160A64(Callbacks_02160A28 *c);
int func_02160A7C(Callbacks_02160A28 *c);
Req_02160A94 *func_02160A94(Ctx_02160A94 *c, int kind, int mode, Src_0216040C *src);
int func_02160C88(Ctx_02160C88 *c, Req_02160C88 *r);
T *func_02160D6C(int *a0, int a1);
Bool func_02160DDC(u32 *a, u8 *b);
Setup *func_02160E08(Work_02160E08 *w, int kind, int mode, Src_02160E08 *src);
int func_02160F88(Seq *s, Evt *e);
int func_02160FB4(void *p);
int *func_02160FE0(u8 *a0, int a1, int a2, const int *a3);
int func_02161070(MenuWork *w, MenuSel *sel);
void func_0216117C(int *a0, int a1);
int func_021611E0(int a0, int a1);
Rec14 *func_02161214(Work_021611E0 *w);
int func_02161280(Work_02161280 *w, Evt_02161280 *e);
u32 *func_02161308(char *c);
int func_02161340(int a0, int *a1);
void func_02161350(void *a0);
u32 *func_02161378(char *c);
int func_021613A4(Work_021613A4 *w, Evt_021613A4 *e);
int func_021613CC(Ctx_021613CC *c, int a1, int mode, const Src_021613CC *src);
int func_02161484(Ctx_02161484 *c, void *p);
void func_02161534(unsigned char *p);
Rec_02161554 *func_02161554(Ctx_02161484 *c, int a1, int mode, const Src_02161484 *src);
int func_02161610(int a0);
u32 *func_0216163C(char *c);
int func_02161668(Work_02161668 *w, Evt_02161668 *e);
void *func_021616A4(void *p, int a1, int a2, int a3, int a4);
int func_021616F0(int a0, int a1, int a2);
extern int d_02171258[];
extern int d_02171200[];
extern int d_02171254[];
extern int d_021711FC[];
extern const char d_0217294C[];
extern u8 d_021B9EC0[];
extern u8 ov_id_00CD[];
extern u8 ov180_id[];
extern u8 ov181_id[];
extern u8 ov205_id[];
extern u8 ov182_id[];
extern u8 d_021B800C[];
extern u8 d_021BAB24[];
extern u8 d_021B9E54[];
extern u8 d_021B9BA0[];
extern unsigned char ov020_id[];
extern struct _OSThreadQueue DSPiBlockingQueue;
extern unsigned char abs_id_14[];
extern u8 ov122_id[];
extern u8 ov172_id[];
extern u8 d_021D5764[];
extern u8 d_021C7240[];
extern const u32 d_021712AC[];
extern u8 d_02172960[];
extern Proc d_021712CC[];
extern u8 ov136_id[];
extern const char d_02172978[];










int func_0215EC54(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
a0 = 0x13;
    a0 = func_02165534(a0);
loc_0215EC60:
a0 = ((struct Obj12043 *)t4)->f8;
a1 = ((struct Obj12043 *)t4)->f10;
a2 = ((struct Obj17699 *)t5)->f4;
    a0 = func_021C8268(a0, a1, a2);
loc_0215EC6A:
    return a0;}









int func_0215EC6C(void *p)
{
    return func_0215F104((int)p, 4) != 0 ? FALSE : TRUE;
}









int func_0215EC80(void *p)
{
    return func_0215F104((int)p, 5) != 0 ? FALSE : TRUE;
}









void *func_0215EC94(void *a, void *b)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)b)->f8, 0, (void *)func_0215ECBC, 20);
    func_0215F0E8(func_020124E8(task), a, b);
    return task;
}










/*
 * Three-state sequence step: state 0 opens message 0x2718, state 1 waits
 * for an object to go idle then starts sound 0x94, state 2 waits for a
 * status of 3. Returns 1 when finished.
 */
int func_0215ECBC(void *a0, int *state, Arg *arg)
{
    void *obj;
    void *obj2;
    void *ctl;
    u32 d;
    void *msg;
    void *o;
    u16 id;

    obj = func_020120F4(arg->f08);
    func_0201296C(obj);
    obj2 = func_02012B38(obj);
    ctl = func_021C7FBC(func_02189A10(func_0201210C(arg->f08)));
    d = func_02188C84(func_0201210C(arg->f08));

    switch (*state) {
    case 0:
        id = arg->f0c;
        msg = func_02158780(a0, 0x2718, 0, 0, d);
        func_02159058((int)msg, id, 0, 0, 0);
        (*state)++;
        break;
    case 1:
        if (func_02014468(obj2) == 0) {
            o = func_02012B38(obj);
            func_02014464(obj2, 1);
            func_02165534((void *)0x94);
            func_021C7E50(ctl, 1);
            func_0201446C(o, (func_02014470(o) & ~1) | 2);
        } else {
            return 1;
        }
        (*state)++;
        break;
    case 2:
        if (func_021C7E54(ctl) == 3) {
            return 1;
        }
        break;
    }
    return 0;
}









int func_0215ED8C(void *p)
{
    return func_0215F104((int)p, 7) != 0 ? FALSE : TRUE;
}









void *func_0215EDA0(void *p, void *ctx)
{
    void *task;
    func_02165534((void *)91);
    task = func_020122C0(((struct Obj02057 *)ctx)->f8, 0, (void *)func_0215EDD0, 20);
    func_0215F0E8(func_020124E8(task), p, ctx);
    return task;
}










int func_0215EDD0(void *a, int *st, struct C *c)
{
    u32 h;
    void *t;

    switch (*st) {
    case 0:
        h = c->fc;
        t = (void *)func_02158780(a, 0x271a, 0, 0, 0x15);
        func_02159058((int)t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        func_0201235C(a, func_02184EEC(c->f8));
        break;
    }
    return 0;
}








/*
 * lever: Enum constants preserve the zero-first return arm; int constants fold to the opposite polarity.
 */
int func_0215EE24(void *p)
{
    return func_0215F104((int)p, 6) != 0 ? FALSE : TRUE;
}








void *func_0215EE38(void *p, void *ctx)
{
    void *task;
    func_02165534((void *)100);
    task = func_020122C0(((struct Obj02057 *)ctx)->f8, 0, (void *)func_0215EE68, 20);
    func_0215F0E8(func_020124E8(task), p, ctx);
    return task;
}









int func_0215EE68(void *a, int *st, struct C *c)
{
    u32 h;
    void *t;

    switch (*st) {
    case 0:
        h = c->fc;
        t = (void *)func_02158780(a, 0x2719, 0, 0, 0x15);
        func_02159058((int)t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        func_0201235C(a, func_02184F40(c->f8));
        break;
    }
    return 0;
}








int func_0215EEBC(void *p)
{
    return func_0215F104((int)p, 10) != 0 ? FALSE : TRUE;
}








void *func_0215EED0(void *p, void *ctx)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)ctx)->f8, 0, (void *)func_0215EEF8, 20);
    func_0215F0E8(func_020124E8(task), p, ctx);
    return task;
}








/*
 * lever: Context +8 word and +12 halfword match neighboring callback layout; named call result preserves the early halfword lifetime.
 * interface: 021587B0 returns its final ldr r0,[r4] at 021587DC, read by this caller; 02159058 uses its own int,int,int,int,u16 prototype.
 */
int func_0215EEF8(void *p, void *unused, struct C *ctx)
{
    int h;
    int t;
    func_0201296C(func_020120F4(ctx->f8));
    h = ctx->fc;
    t = func_021587B0((int)p, 0x271c, 0, 0);
    func_02159058(t, h, 0, 0, 0);
    return 0;
}








int func_0215EF2C(void *p)
{
    return func_0215F104((int)p, 9) != 0 ? FALSE : TRUE;
}









/*
 * Stamp the fixed id on the record, then hand three of the record's own
 * fields to the overlay pair call.
 */
void func_0215EF40(void *a0, void *a1)
{
    func_02165534((void *)0x1C0);
    func_021D1C24(((struct Obj12044 *)a1)->f8, ((struct Obj12044 *)a1)->f10,
                 (u8)((struct Obj17700 *)a0)->f0);
}











int func_0215EF60(void *a, int *st, struct C *c)
{
    u32 h;
    u32 x;
    void *t;

    func_0201296C(func_020120F4(c->f8));
    x = func_02188C84(func_0201210C(c->f8));
    switch (*st) {
    case 0:
        h = c->fc;
        t = func_02158780(a, 0x271e, 0, 0, x);
        func_02159058((int)t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        func_021587B0((int)a, 0x28e3, 0, 0);
        break;
    }
    return 0;
}







void *func_0215EFCC(void *p, void *ctx)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)ctx)->f8, 0, (void *)func_0215EF60, 20);
    func_0215F0E8(func_020124E8(task), p, ctx);
    return task;
}








int func_0215EFF4(void *a, int *st, struct C *c)
{
    u32 h;
    u32 x;
    void *t;

    func_0201296C(func_020120F4(c->f8));
    x = func_02188C84(func_0201210C(c->f8));
    switch (*st) {
    case 0:
        h = c->fc;
        t = func_02158780(a, 0x271d, 0, 0, x);
        func_02159058((int)t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        func_021587B0((int)a, 0x28e2, 0, 0);
        break;
    }
    return 0;
}







void *func_0215F060(void *p, void *ctx)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)ctx)->f8, 0, (void *)func_0215EFF4, 20);
    func_0215F0E8(func_020124E8(task), p, ctx);
    return task;
}







int func_0215F088(u16 *p, int i)
{
    if (i >= 11) return 0;
    if (func_02013FFC(*p)) return *(int *)((u32)d_02171258 + ((u32)i << 3));
    return *(int *)((u32)d_02171200 + ((u32)i << 3));
}







int func_0215F0B8(u16 *p, int i)
{
    if (i >= 11) return 0;
    if (func_02013FFC(*p)) return *(int *)((u32)d_02171254 + ((u32)i << 3));
    return *(int *)((u32)d_021711FC + ((u32)i << 3));
}







void func_0215F0E8(u32 *out, const Pair *in, u32 *ctx) { out[0] = 0x19740205; out[1] = ctx[3]; *(Pair *)(out+3) = *in; out[2] = ctx[2]; }










int func_0215F104(int a0, int a1)
{
    int a2;
    int a3;

a3 = ((struct Obj17701 *)a0)->f2;
a2 = 1;
a2 = a2 << a1;
a1 = a3 + 0;
a0 = 1;
    if ((a1 & a2) != 0) goto loc_0215F114;
loc_0215F112:
a0 = 0;
loc_0215F114:
    return a0;}









/*
 * Inside test of (x, z) against an Area's half extents, refused when the
 * flag is already set in the field's save block.
 */
int func_0215F118(const Area *a, u16 x, u16 z, u32 flag, void *field)
{
    int dx;
    int dz;

    if (func_020142E8((void *)func_0201296C(func_020120F4(func_02188C80(field))), flag) != 0)
        return 0;
    dx = a->x - x;
    dz = a->z - z;
    if (dx < 0)
        dx = -dx;
    if (dx < a->w) {
        if (dz < 0)
            dz = -dz;
        if (dz < a->h)
            return 1;
    }
    return 0;
}









int func_0215F168(int a0, int a1)
{
    int t4;
    int t6;
    void *p;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215F172:
a0 = t4 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_0215F17A:
    a0 = func_02012138(v0);
loc_0215F182:
t6 = a0 + 0;
    v2 = func_0201210C(v0);
loc_0215F18A:
    p = func_02158FB4(v1);
loc_0215F190:
t4 = ((struct Obj17702 *)((char *)p))->f0;
a0 = t6 + 0;
    a0 = func_02189734(a0);
loc_0215F198:
    if (a0 == 0) goto loc_0215F1A6;
loc_0215F19C:
    if (a0 == 1) goto loc_0215F1AA;
loc_0215F1A0:
    if (a0 == 2) goto loc_0215F1B4;
loc_0215F1A4:
    goto loc_0215F1C4;
loc_0215F1A6:
a0 = 0;
    return a0;
loc_0215F1AA:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0215F1B0:
a0 = 1;
    return a0;
loc_0215F1B4:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
a1 = 2;
*(u16 *)&((struct Obj00005 *)((char *)a0))->f0 = a1;
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0215F1C0:
a0 = 1;
    return a0;
loc_0215F1C4:
a0 = 0;
    return a0;}









int func_0215F1C8(void *a, void *b)
{
    void **slot;
    u16 *w;
    void **p;

    slot = func_02158FB4(func_0215A5F4(b));
    w = func_02159AE8(a, b);
    p = func_02030734(4, 4, 1, d_0217294C, 0x63);
    *slot = p;
    *p = w;
    *w = 0;
    func_020113D0(a, (int)func_0215F168);
    return 1;
}









/*
 * blocked:  listing 20 compiled 18
 */
int func_0215F214(int a0, int a1)
{    unsigned short *v0;

    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215F21A:
    a0 = func_0202EB44();
loc_0215F220:
((struct Obj17703 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}









int func_0215F228(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215F230:
    a0 = func_020121CC(v0);
loc_0215F234:
a0 = 1;
    return a0;}









int func_0215F238(void *a, void *b)
{
    void *t;
    void *s;

    t = func_0215A5DC(b);
    s = (void *)func_02012138(t);
    switch (func_02026454(s)) {
    case 1:
    case 2:
    case 5:
        func_02026400(s);
        break;
    case 0:
    case 3:
    case 4:
        break;
    }
    func_0201213C(t, 1);
    func_02159144(0xb);
    return 1;
}








/*
 * Frame teardown on the handle the overlay index returned, then the
 * overlay's own mode setter.
 */
int func_0215F280(void *a0, void *a1)
{
    void *p = func_0215A5DC(a1);

    func_0201213C(p, 0);
    func_020121CC(p);
    func_02159168(0xB);

    return 1;
}







int func_0215F2A0(int a0, int a1)
{
    struct Ctx *c = *(struct Ctx **)a0;

    func_0201213C(c, 0);
    func_020121CC((struct IcaAnime *)c);
    return 1;
}








int func_0215F2B8(int a0, int a1)
{    int t5;
    int t6;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215F2C4:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215F2CE:
    a0 = func_0201214C(v0);
loc_0215F2D6:
*q = a0;
a0 = 0;
    return a0;}







int func_0215F2DC(void *a, void *b) { func_02012158(func_0215A5DC(b), 0); return 0; }







int func_0215F2F0(void *a, void *b) { void *p = func_0215A5F4(b); func_02159114(p,func_0204A1BC(0xd1,0,0,0x8004)); return 0; }








int func_0215F318(void *a0, int a1)
{    void *v0;

a0 = (void *)(a1 + 0);
    v0 = func_0215A5F4((void *)a0);
loc_0215F320:
    a0 = (void *)func_0215911C(v0);
loc_0215F326:
    if (a0 == 0) goto loc_0215F336;
loc_0215F32A:
    a0 = (void *)func_020307B0(a0);
loc_0215F32E:
a1 = 0;
    a0 = (void *)func_02159114(v0, a1);
loc_0215F336:
a0 = 0;
    return (int)a0;}








int func_0215F33C(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    int y = func_02159B10((void *)a, (void *)b);
    int z = func_02159B10((void *)a, (void *)b);
    int w = func_02159B10((void *)a, (void *)b);
    u8 *base;
    int h;
    int r;
    r = func_02012844(func_0215A5E4((void *)b));
    base = (u8 *)func_0215911C(x);
    h = *(u16 *)(base + (u16)func_0215F608(base, y, w) * 8 + 6);
    func_02162788((char *)r, z, func_0215A480(h));
    return 0;
}








int func_0215F3A4(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    int y0 = func_02159B10((void *)a, (void *)b);
    int y1 = func_02159B10((void *)a, (void *)b);
    int y2 = func_02159B10((void *)a, (void *)b);
    int y3 = func_02159B10((void *)a, (void *)b);
    u8 *base;
    u8 *e;
    u16 h;
    int r;
    r = func_02012844(func_0215A5E4((void *)b));
    base = (u8 *)func_0215911C(x);
    e = base + 6;
    h = func_0215F608(base, y0, y3);
    func_02162788((char *)r, y1, func_0215A480(*(u16 *)(e + h * 8)));
    func_02162788((char *)r, y2, func_0215A490(*(u16 *)(e + h * 8)));
    return 0;
}








int func_0215F424(int a0, int a1)
{
    void *w = func_0215A5F4((void *)a1);
    int s0 = func_02159B10((void *)a0, (void *)a1);
    int s1 = func_02159B10((void *)a0, (void *)a1);
    int s2 = func_02159B10((void *)a0, (void *)a1);
    int i0 = func_02159B10((void *)a0, (void *)a1);
    int i1 = func_02159B10((void *)a0, (void *)a1);
    int i2 = func_02159B10((void *)a0, (void *)a1);
    int obj = func_02012844(func_0215A5E4((void *)a1));
    Entry_0215F424 *t = (Entry_0215F424 *)func_0215911C(w);
    func_02162774((char *)obj, s0, t[i0].f04);
    func_02162774((char *)obj, s1, t[i1].f04);
    func_02162774((char *)obj, s2, t[i2].f04);
    func_02162788((char *)obj, s0, func_0215A480(t[i0].f06));
    func_02162788((char *)obj, s1, func_0215A480(t[i1].f06));
    func_02162788((char *)obj, s2, func_0215A480(t[i2].f06));
    return 0;
}







int func_0215F4F4(void *a,void *b) { void *p; void *s; int i; Entry_0215F4F4 *t; p=func_0215A5F4(b); s=(void *)func_0201296C(func_020120F4(func_02158F54(p))); t=(Entry_0215F4F4 *)func_0215911C(p); for(i=0;i<0x6b;i++) func_0215A500(s,t[i].c); return 0; }











/*
 * Draws six distinct values from 0..0x33 (random pick among the ones not
 * yet taken) and writes each plus 0x37 to six script-variable slots.
 *
 * Keys: the work locals live in a nested block opened after the six
 * func_02159AE8 calls, so `u16 buf[6] = {0}` is emitted there (at function
 * scope the initializer lands above the calls) and its stores go through
 * the same `add r4, sp, #0x18` the search loops index. `u16 n = 0x34`
 * declared before buf schedules `movs r7, #0x34` ahead of the zero stores.
 * EXACT* only for the 2-byte pad after the function (218 of 220).
 */
int func_0215F52C(void *c, void *vm)
{
    u16 *p0, *p1, *p2, *p3, *p4, *p5;

    func_0215A5F4(vm);
    p0 = func_02159AE8(c, vm);
    p1 = func_02159AE8(c, vm);
    p2 = func_02159AE8(c, vm);
    p3 = func_02159AE8(c, vm);
    p4 = func_02159AE8(c, vm);
    p5 = func_02159AE8(c, vm);
    {
        u16 n = 0x34;
        u16 buf[6] = {0};
        int i, v, j;
        s16_0215EC54 r;

        for (i = 0; i < 6; i++) {
            r = func_020056EC(n);
            for (v = 0; v < 0x34; v++) {
                for (j = 0; j < i; j++) {
                    if (buf[j] == v)
                        break;
                }
                if (j == i) {
                    if (--r < 0) {
                        buf[i] = v;
                        break;
                    }
                }
            }
            n--;
        }
        *p0 = buf[0] + 0x37;
        *p1 = buf[1] + 0x37;
        *p2 = buf[2] + 0x37;
        *p3 = buf[3] + 0x37;
        *p4 = buf[4] + 0x37;
        *p5 = buf[5] + 0x37;
    }
    return 0;
}













int func_0215F608(u8 *tbl, int id, int sub)
{
    int i;

    for (i = 0; i < 0x6B; i++) {
        u16 *e = (u16 *)(tbl + i * 8);

        if (id == e[0] && sub == e[1])
            return i;
    }
    return 0;
}










Bool func_0215F630(void *p) { int a = func_02159F80(); if(a == func_02012914(p)) return FALSE; else return TRUE; }











/*
 * former blocker: ABS32 0x000000CD (ov_id_00CD) has no witness outside the function (literal pool word only)
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int func_0215F64C(int a0, int *st, int *a2)
{
    switch (*st) {
    case 0:
        func_02023F60(-16, 0x37, 1);
        func_02023F60(-16, 0x3f, 2);
        func_02012444((struct Obj *)a0, (u32)ov_id_00CD, (u32)d_021B9EC0, (u32)a2);
        (*st)++;
        break;
    case 1:
        func_02023F60(0, 0x3f, 3);
        func_02012374((struct Evt *)a0, (struct Evt **)func_0215FA1C(a2[0]));
        (*st)++;
        break;
    case 2:
        if (a2[1] == 0) {
            func_02158780((void *)a0, 3, 0, 0, 0x15);
        } else {
            func_02158780((void *)a0, 0x7d1, 0, 0, 0x15);
        }
        (*st)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}











/*
 * Allocator with callback, then two accessor stores and two teardown calls.
 */
void *func_0215F6E8(void *p)
{
    int r4 = (int)func_020120F4((const struct Ctx *)p);
    void *r7 = func_020122C0(p, 0, func_0215F64C, 0xc);
    int *r6 = func_020124E8(r7);

    r6[0] = (int)p;
    r6[1] = (int)func_0215F630((void *)r4);
    r6[2] = (int)func_02012944((void *)r4);
    func_021666A4((int)func_02012ED0((struct Big *)r4));
    func_0201213C((struct Ctx *)p, 0);
    return r7;
}











/*
 * Step machine of an ov010 sub-sequence: the step comes from w->seq[*i]
 * through func_0215F9DC, loading ov180/ov181 as procs and ov205/ov182 as
 * tasks. Byte-correct first draft.
 * Former blocker (MATCH): ov205_id and ov182_id reach r1 of func_02012444, which
 * is not in match.py's OVERLAY_ID_CONSUMERS; d_021B9BA0 then fails its
 * ov182 hint for want of that overlay_id site. Same blocker as
 * func_0215FA54.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int func_0215F734(void *evt, u32 *i, Work_0215F52C *w)
{
    void *sys = w->sys;
    void *save;
    void *proc;

    func_02012EBC(w->f04);
    proc = func_0201210C((const struct Ctx *)w->sys);
    save = (void *)func_02012138((const struct Ctx *)w->sys);
    switch (w->step) {
    case 0:
        if (w->f08 == 1)
            func_0215F9EC((int)w);
        func_02005E30(30);
        func_0215F9DC(w, i);
        break;
    case 1:
        func_02012374(evt, func_021BE8D4(sys, proc, 0, 0));
        func_0215F9DC(w, i);
        break;
    case 2:
        if (func_02026454(save))
            func_02026400(save);
        func_0215F9DC(w, i);
        break;
    case 3:
        if (func_02026454(save) == 0)
            func_0215F9DC(w, i);
        break;
    case 4:
        func_02012374(evt, (void *)func_02014554((int)sys, (int)proc));
        func_0215F9DC(w, i);
        break;
    case 5:
        func_020120B4(sys, (u32)ov180_id, d_021B800C, w->f1c);
        func_0215F9DC(w, i);
        break;
    case 6:
        if (func_020120F0((const struct Ctx *)sys) == 0)
            func_0215F9DC(w, i);
        break;
    case 7:
        func_020120B4(sys, (u32)ov181_id, d_021BAB24, w->f28);
        func_0215F9DC(w, i);
        break;
    case 8:
        if (func_020120F0((const struct Ctx *)sys) == 0)
            func_0215F9DC(w, i);
        break;
    case 9:
        func_02012374(evt, func_02161B90(sys, evt, func_0215F9C4(), 0, 0));
        func_0215F9DC(w, i);
        break;
    case 10:
        func_02158A20((int)sys, 4);
        func_0215F9DC(w, i);
        break;
    case 11:
        func_02012444(evt, (u32)ov205_id, (u32)d_021B9E54, (u32)w->f14);
        func_0215F9DC(w, i);
        break;
    case 12:
        if (w->timer > 60) {
            w->timer = 0;
            func_0215F9DC(w, i);
        }
        w->timer++;
        break;
    case 13:
        func_02012444(evt, (u32)ov182_id, (u32)d_021B9BA0, (u32)w->f30);
        func_02012158(sys, 0);
        func_0215F9DC(w, i);
        break;
    case 14:
        return 1;
    case 15:
        return 0;
    }
    return 0;
}











/*
 * Allocator with callback, three sub-init calls over the new node.
 */
void *func_0215F8A8(void *p, int a1)
{
    int r7 = (int)func_020120F4((const struct Ctx *)p);
    void *r0v = func_020122C0(p, 0, func_0215F734, 0x7C);
    char *r4 = func_020124E8(r0v);

    ((struct Obj04132 *)r4)->f0 = (int)p;
    ((struct Obj04132 *)r4)->f4 = r7;
    ((struct Obj04132 *)r4)->f8 = a1;
    ((struct Obj04132 *)r4)->f10 = (int)func_02012944((void *)r7);
    ((struct Obj04132 *)r4)->f78 = 0;
    ((struct Obj04132 *)r4)->f14 = (int)p;
    ((struct Obj04132 *)r4)->f18 = a1;
    func_0215E580((void *)r7);
    func_0215F900(r4);
    func_0215F920((int)r4);
    func_0215F948((u8 *)r4);
    return r0v;
}











/*
 * Three arm9 size reads on the record's handle, cached at three fields.
 */
void func_0215F900(void *a0)
{
    char *p = (char *)a0;

    ((struct Obj04883 *)p)->f1C = func_02012934(((struct Obj04883 *)p)->f4);
    ((struct Obj04883 *)p)->f20 = (int)func_02012944(((struct Obj04883 *)p)->f4);
    ((struct Obj04883 *)p)->f24 = func_02012FCC((int)(((struct Obj04883 *)p)->f4));
}











/*
 * blocked:  listing 40 compiled 38
 */
int func_0215F920(int a0)
{
    int t4;
    void *big;
    struct Sub02008700Obj *obj;

t4 = a0 + 0;
a0 = ((struct Obj05853 *)t4)->f8;
    if (a0 != 1) goto loc_0215F92E;
loc_0215F92A:
a0 = 1;
    goto loc_0215F930;
loc_0215F92E:
a0 = 0;
loc_0215F930:
((struct Obj05853 *)t4)->f28 = a0;
a0 = ((struct Obj05853 *)t4)->f4;
    big = func_02012EBC((struct Big *)a0);
loc_0215F938:
    obj = func_0200873C(big);
loc_0215F93C:
    a0 = func_020083E4((short unsigned int *)obj);
loc_0215F940:
((struct Obj05853 *)t4)->f2C = a0;
((struct Obj05853 *)t4)->f30 = a0;
    return a0;}











/*
 * Addresses are Black-image addresses.
 */
void func_0215F948(u8 *p)
{
    u32 *t = (u32 *)p;
    if (t[2] == 0 || t[2] != 1) {
        t[0x38 / 4] = 0;
        t[0x3c / 4] = 2;
        t[0x40 / 4] = 3;
        t[0x44 / 4] = 4;
        t[0x48 / 4] = 7;
        t[0x4c / 4] = 8;
        t[0x50 / 4] = 12;
        t[0x54 / 4] = 9;
        t[0x58 / 4] = 12;
        t[0x5c / 4] = 10;
        t[0x60 / 4] = 11;
        t[0x64 / 4] = 12;
        t[0x68 / 4] = 13;
        t[0x6c / 4] = 14;
    } else {
        t[0x38 / 4] = 0;
        t[0x3c / 4] = 2;
        t[0x40 / 4] = 1;
        t[0x44 / 4] = 3;
        t[0x48 / 4] = 4;
        t[0x4c / 4] = 5;
        t[0x50 / 4] = 6;
        t[0x54 / 4] = 10;
        t[0x58 / 4] = 11;
        t[0x5c / 4] = 7;
        t[0x60 / 4] = 8;
        t[0x64 / 4] = 13;
        t[0x68 / 4] = 14;
    }
    t[0x34 / 4] = t[0x38 / 4];
}











int func_0215F9C4(void)
{
    int a0;

    a0 = func_020111E8();
loc_0215F9CA:
    if (a0 == 0x14) goto loc_0215F9D2;
loc_0215F9CE:
    if (a0 == 0x15) goto loc_0215F9D6;
loc_0215F9D2:
a0 = 8;
    return a0;
loc_0215F9D6:
a0 = 7;
    return a0;}











/*
 * Advance the step counter and load the next step from the sequence.
 */
void func_0215F9DC(Work_0215F52C *w, u32 *i)
{
    (*i)++;
    w->step = w->seq[*i];
}











int func_0215F9EC(int a0)
{
    int a1;
    void *p;

a0 = ((struct Obj17707 *)a0)->f4;
    p = func_02012F08((int *)a0);
loc_0215F9F4:
a1 = 0x5a;
a1 = a1 << 4;
    a0 = func_0200C3B8(p, a1);
loc_0215F9FC:
    return a0;}










void func_0215FA00(void *p, void *q) { func_02034AC4((u32)ov020_id); func_02183B6C((int)p,q); }











static void DSPi_WaitForPipe(struct DSPPipe *pipe)
{
    OS_SleepThread(&DSPiBlockingQueue);
    DSP_SyncPipe(pipe);
}








/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           abs_id_14 (20) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * Thumb tail call into the ARM sub_02034AC4 with the id 0x14, which the
 * original loads from its own pool rather than as `movs r0, #0x14`: the
 * pooled small constant is an absolute linker symbol
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * Unlabelled in the listing (no lr-saving prologue, callers only in arm9);
 * the pair with func_0215FA44 (same id, into sub_02034A5C).
 */
void func_0215FA34(void)
{
    sub_02034AC4((int)abs_id_14);
}










/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           abs_id_14 (20) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * Thumb tail call into the ARM sub_02034A5C with the id 0x14, which the
 * original loads from its own pool rather than as `movs r0, #0x14`: the
 * pooled small constant is an absolute linker symbol
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * Unlabelled in the listing (no lr-saving prologue, callers only in arm9);
 * the pair with func_0215FA34 (same id, into sub_02034AC4).
 */
void func_0215FA44(void)
{
    sub_02034A5C((int)abs_id_14);
}










/*
 * Proc main of an ov010 sub-sequence: 11 states that push the child
 * tasks, load ov122 and ov172, and pick the closing screen from w->f28.
 * Byte-correct (first draft plus one lever: in state 9 the `f28 == 2`
 * test and the call share an else block ending in the one `*state = 10`
 * store, so that store is the copy the other arms cross-jump to).
 * Former blocker (MATCH): the pooled 0xAC is ov172_id passed in r1 to
 * func_02012444, which is not in match.py's OVERLAY_ID_CONSUMERS
 * (func_02012444 stores r1 in a task descriptor, src/matched/func_02012444.c),
 * so the ABS32 at +0x190 has no witness.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int func_0215FA54(void *evt, u32 *state, Work_0215FA44 *w)
{
    void *sys = w->sys;
    void *save = (void *)func_02012138((const struct Ctx *)sys);
    void *ctx = func_020120F4((const struct Ctx *)sys);
    void *proc = func_0201210C((const struct Ctx *)sys);

    switch (*state) {
    case 0:
        func_02012374(evt, func_021BE8D4(sys, proc, 0, 0));
        (*state)++;
        break;
    case 1:
        func_02012374(evt, (struct Evt **)func_020144DC((int)sys, (int)proc));
        *state = 2;
        break;
    case 2:
        (*state)++;
    case 3:
        func_020120B4(sys, (u32)ov122_id, d_021D5764, w);
        (*state)++;
        break;
    case 4:
        if (func_020120F0((const struct Ctx *)sys) != 0)
            break;
        switch (w->f20) {
        case 0:
            if (func_02158344((int)save) && w->f28 == 2)
                func_020129B8(ctx, 3);
            *state = 6;
            break;
        case 1:
            w->f24 = func_02005C44();
            func_02012444(evt, (u32)ov172_id, (u32)d_021C7240, (u32)w->f0c);
            *state = 5;
            break;
        default:
            *state = 6;
            break;
        }
        break;
    case 5:
        if (func_020120F0((const struct Ctx *)sys) != 0)
            break;
        func_02005D90(w->f24, 0xFFFF);
        func_02005DF8(60);
        *state = 6;
        break;
    case 6:
        w->f1c = 0;
        (*state)++;
        break;
    case 7:
        func_02012374(evt, func_020145CC(sys));
        (*state)++;
        break;
    case 8:
        func_02012374(evt, func_021BE92C(sys, proc, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 9:
        if (w->f20 == 0) {
            if (w->f28 == 0) {
                if (func_02026460(save))
                    break;
                if (func_02026454(save)) {
                    func_02026400(save);
                    break;
                }
                func_02012374(evt, func_0217CE08(sys, proc, 0x117, 0));
                *state = 10;
            } else if (w->f28 == 3) {
                func_02012374(evt, func_0217FA24(sys));
                *state = 10;
            } else {
                if (w->f28 != 2)
                    func_02012374(evt, func_0217CDBC(sys));
                *state = 10;
            }
        } else {
            *state = 10;
        }
        break;
    case 10:
        return 1;
    }
    return 0;
}










struct Desc *func_0215FBF4(int a0, int a1, struct Desc *a2, int a3)
{
    struct Rec_0215FBF4 *p;
    void *ctx;

    func_02188CCC((u8 *)a1);
    if (a3 != 0) {
        a2 = func_020122C0((void *)a0, 0, (void *)func_0215FA54, 0x34);
    } else {
        func_0201232C((char *)a2, (int)func_0215FA54, 0x34);
    }
    p = (struct Rec_0215FBF4 *)func_020124E8((struct Obj *)a2);
    ctx = func_020120F4((const struct Ctx *)a0);
    p->ctx = ctx;
    p->head = func_02012EBC((struct Big *)ctx);
    p->owner = a0;
    return a2;
}








struct Desc *func_0215FC40(int a0, int a1, u16 a2)
{
    int x;
    int sz = 0x5c;
    struct Desc *r7;
    struct Rec_0215FC40 *p;
    int r;

    x = func_02188CCC((u8 *)a1);
    r7 = func_020122C0((void *)a0, 0, (void *)func_0215FD0C, sz);
    p = (struct Rec_0215FC40 *)func_020124E8((struct Obj *)r7);
    func_02082BCC(p, 0, sz);
    p->owner = a0;
    p->desc = r7;
    p->field = a1;
    p->id = a2;
    p->f14 = 0;
    p->owner2 = a0;
    p->field2 = a1;
    p->desc2 = r7;
    p->fn30 = (void *)func_0215FED4;
    p->fn34 = (void *)func_0215FEF0;
    p->fn38 = (void *)func_0215FEF4;
    p->self = p;
    p->f2C = sz - 0x5d;
    r = func_021A0F90((u8 *)x);
    switch (r) {
    case 3:
        r = 3;
        break;
    case 4:
        r = 4;
        break;
    default:
        r = func_021A0EE4(func_02188CCC((u8 *)p->field), 0);
        break;
    }
    p->f18 = r;
    func_020355D8(1);
    return r7;
}








int func_0215FCE0(int a, int b, unsigned short c) { int task; u32 *p; task=(int)func_0215FC40(a,b,c); p=func_020124E8((struct Obj *)task); p[6]=func_02013CE0(func_02188C9C((void *)b)) == 1 ? 5 : 2; return task; }









/*
 * Nine-state link setup task of the ov010 field (the extent ends at
 * 0x0215FEC6; 0x0215FEC8 is its unlabelled table-lookup leaf). State 3
 * keeps the call arm inside the negated test so the `return 1` block
 * follows it.
 */
int func_0215FD0C(void *task, void *unused, Ctx *c)
{
    Query q;
    Info info;
    void *map;
    void *sys;
    void *next;
    u32 n;
    int r;

    switch (c->state) {
    case 0:
        if (func_021A0ED4(func_02188CCC(c->field)) == 1) {
            map = func_02188C7C(c->field);
            sys = func_020120F4((const struct Ctx *)(func_020124E4(task)));
            func_0216D9A0(map);
            func_020129D0(sys, 1);
            func_021A0F30(func_02188CCC(c->field), 1);
            c->state = 1;
        }
        break;
    case 1:
        r = func_021A0F94(func_02188CCC(c->field));
        if (r == 3) {
            c->state = 2;
            func_021A0FA8((int *)func_02188CCC(c->field));
        } else if (r == 4) {
            c->state = 3;
            func_021A0FA8((int *)func_02188CCC(c->field));
        }
        break;
    case 2:
        sys = func_020120F4((const struct Ctx *)(func_020124E4(task)));
        n = func_021A12A4((void *)func_02188CCC(c->field));
        func_020129D0(sys, n);
        c->f10 = func_021A12A4((void *)func_02188CCC(c->field));
        c->f28 = func_0215FEC8(n);
        c->state = 5;
        break;
    case 3:
        func_0216D9E4(func_02188C7C(c->field));
        if (c->f40 != 1 && c->f40 != 4) {
            func_0201235C(task, func_021945A4(func_020124E4(task), (u32)c->field, c->f18));
            return 0;
        }
        return 1;
    case 4:
        func_0216D9E4(func_02188C7C(c->field));
        func_0215E840(func_0201210C((const struct Ctx *)c->f08), &info);
        func_0215EA30(&q, c->f48, c->f44, c->f4c);
        next = (void *)func_0215EA38(c->f44, (int)(&q), (int)(&info));
        if (next == 0)
            return 1;
        func_0201235C(c->f04, next);
        break;
    case 5:
        func_02012374(task, func_0216075C((struct Owner *)c->req, c->f00));
        c->state = 6;
        break;
    case 6:
        if (c->f40 == 0)
            c->state = 1;
        else if (c->f40 == 1)
            c->state = 3;
        else if (c->f40 == 3)
            c->state = 7;
        else if (c->f40 == 2)
            c->state = 4;
        else if (c->f40 == 4)
            c->state = 3;
        break;
    case 7:
        func_0216D9E4(func_02188C7C(c->field));
        func_02012374(task, (struct Evt **)func_021644F4(c->f44, c->f08, c->field));
        c->state = 8;
        break;
    case 8:
        return 1;
    }
    return 0;
}










/*
 * Unlabelled leaf after func_0215FD0C (bl from 0x0215FDD0).
 */
u32 func_0215FEC8(u32 n)
{
    return d_021712AC[n];
}










/*
 * Conditional arm9 pair call on the record's second field; the first
 * call's result is the first operand either way.
 */
int func_0215FED4(void *a0, void *a1)
{
    void *v = (void *)func_02188CCC((u8 *)(((struct Obj12045 *)a1)->fC));

    if (((struct Obj17708 *)a0)->f24 == 0)
        func_021A12BC(v, ((struct Obj12045 *)a1)->f10);

    return 1;
}









/*
 * Unlabelled leaf: returns 1.
 */
int func_0215FEF0(void)
{
    return 1;
}










int func_0215FEF4(u32 *a0, u32 *a1)
{
    void *h = func_020120F4((const struct Ctx *)a1[2]);

    switch (a0[9]) {
    case 4:
        func_020129B8(h, 6);
        break;
    case 0:
        func_020129B8(h, 1);
        break;
    case 1:
    case 2:
    case 3:
        func_020129B8(h, (u8)a1[6]);
        break;
    default:
        break;
    }
    return 1;
}










/*
 * Three chained arm9 probes; a non-zero result from the last reads as
 * success.
 */
int func_0215FF34(void *sys)
{
    if (func_0200C468(func_0200C404(func_02012EBC(func_020120F4((const struct Ctx *)sys)))) != 0)
        return 1;

    return 0;
}










struct Desc *func_0215FF54(int a0, int a1, u16 a2)
{
    void *sp8;
    struct Desc *r5;
    struct Rec *p;

    sp8 = func_0200C404(func_02012EBC((struct Big *)func_020120F4((const struct Ctx *)a0)));
    if (func_0200C468(sp8) == 1) {
        r5 = func_020122C0((void *)a0, 0, (void *)func_0216025C, 0x20);
    } else {
        r5 = func_020122C0((void *)a0, 0, (void *)func_02160018, 0x20);
    }
    p = (struct Rec *)func_020124E8((struct Obj *)r5);
    func_02082BCC(p, 0, 0x20);
    p->owner = a0;
    p->desc = r5;
    p->field = a1;
    p->id = a2;
    p->f18 = 0;
    p->sub = (struct Sub *)func_02030734(4, 0x40, 0, (const char *)d_02172960, 0xc2);
    func_02082BCC(p->sub, 0, 0x40);
    p->sub->owner = p->owner;
    p->sub->field = p->field;
    p->sub->desc = r5;
    if (func_0200C468(sp8) != 1) {
        p->sub->fn14 = (void *)func_02160668;
        p->sub->fn18 = (void *)func_021606D0;
        p->sub->rec = p;
    }
    func_0216D9A0(func_02188C7C((unsigned char *)p->field));
    func_020355D8(0);
    return r5;
}








/*
 * Proc main of the ov010 link exchange: a 16-state machine that drives
 * the ov021 connection object at +0xC, classifies the received result
 * code, and hands off to the result screens before tearing down.
 *
 * The ov021 calls to 0x021C536C, 0x021C5380 and 0x021C5394 (once folded
 * into func_021C5348) resolve since seeds_2 labelled them. Levers: in state 4 `retry` declared first and `bad`
 * last (retry spills to sp+4, ok to sp+0, next stays in r7), the result
 * code dispatched as a switch and the case-10 value as an if chain with
 * the f18 != 0 arm first; in state 12 the tail call in a local written
 * as a nested if (i == 0, then the save test) with the call in all
 * three arms, which is what makes both w->f04 loads hoist above their
 * branches and lets state 11 cross-jump into the shared tail.
 */
int func_02160018(void *evt, u32 *state, Work_0215EC54 *w)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        func_021605C0(0, (int)w);
        *state = 2;
        break;
    case 2:
        func_021C5348(w->f0c);
        *state = 3;
        break;
    case 3:
        func_021C5224(w->f0c);
        if (func_021C5380(w->f0c) == 0)
            *state = 4;
        break;
    case 4: {
        u32 code;
        int r;

        func_021C5224(w->f0c);
        r = func_021C5394(w->f0c, &code);
        if (r == 1) {
            Flags fl;
            u32 n;
            u32 err;
            int retry = 0;
            int ok;
            int next;
            int bad = 0;

            ok = func_02160564(code, &n, &err);
            next = func_0216040C((Req *)w->f10, code);
            if (err == 0 && func_02012B70(func_020120F4((const struct Ctx *)w->f04)) == 1) {
                bad = 1;
            } else if (ok == 1) {
                func_02164480(&fl, w->f04, w->f08);
                if (func_02028754((struct Obj *)(&fl), n) == 0)
                    bad = 1;
            }
            if (code == 9 && func_0216070C(w) == 0)
                retry = 1;
            if (bad == 1) {
                *state = 12;
            } else if (retry == 1) {
                *state = 14;
            } else {
                switch (next) {
                case 0:
                    *state = 9;
                    break;
                case 1:
                    *state = 11;
                    break;
                }
            }
        } else if (r == 2) {
            *state = 5;
        }
        break;
    }
    case 5:
        func_021C536C(w->f0c);
        *state = 6;
        break;
    case 6:
        func_021C5224(w->f0c);
        if (func_021C5380(w->f0c) == 0)
            *state = 7;
        break;
    case 7:
        if (func_0216060C((int)w, (int)state) != 0) {
            func_020307B0(w->f10);
            func_0216D9E4(func_02188C7C(w->f08));
            return 1;
        }
        break;
    case 8:
        func_021605C0(1, (int)w);
        *state = 4;
        break;
    case 9:
        func_02012374(evt, func_0216075C((struct Owner *)w->f10, w->f14));
        *state = 10;
        break;
    case 10:
    {
        u32 v = w->f10->result;

        if (v == 0) {
            if (w->f18 != 0)
                *state = 7;
            else
                *state = 8;
        } else if (v == 1) {
            *state = 7;
        } else if (v == 3) {
            *state = 11;
        }
        break;
    }
    case 11:
        if (func_0216060C((int)w, (int)state) != 0) {
            u32 i = w->f10->next;

            func_020307B0(w->f10);
            w->f10 = 0;
            func_02012374(evt, (struct Evt **)func_021644F4(i, w->f04, w->f08));
            *state = 13;
        }
        break;
    case 12:
        if (func_0216060C((int)w, (int)state) != 0) {
            u32 i = w->f10->next;

            func_020307B0(w->f10);
            w->f10 = 0;
            {
                void *t;

                if (i == 0) {
                    if (func_02012B28((const struct Rec44 *)func_020127A4(func_020120F4((const struct Ctx *)w->f04))) == 1)
                        t = func_021606DC(w->f04, 1);
                    else
                        t = func_021606DC(w->f04, 0);
                } else {
                    t = func_021606DC(w->f04, 0);
                }
                func_02012374(evt, t);
            }
            *state = 13;
        }
        break;
    case 13:
        func_0216D9E4(func_02188C7C(w->f08));
        return 1;
    case 14:
        if (func_0216060C((int)w, (int)state) != 0) {
            func_020307B0(w->f10);
            w->f10 = 0;
            func_02012374(evt, func_021606DC(w->f04, 2));
            *state = 15;
        }
        break;
    case 15:
        func_0216D9E4(func_02188C7C(w->f08));
        return 1;
    }
    return 0;
}






/*
 * Nine-state connection sequence; returns 1 when the sequence has ended.
 * EXACT* because the listing extent runs over the unlabelled followers
 * 0x0216040C, 0x02160564 and 0x021605C0. Levers: the case-3 test is an
 * else-if chain with the `*state = 1` arm written twice (the first copy is
 * cross-jumped into `b`), and cases 4 and 5 hand one local `h` to
 * func_02012374, which is what lets case 4 cross-jump into case 5's call.
 */
int func_0216025C(void *evt, u32 *state, Ctx_0216025C *c)
{
    Flags flags;
    u32 idx;
    u32 err;
    u32 code;
    int r;
    int ok;
    int failed;
    int busy;
    u32 next;
    void *h;

    switch (*state) {
    case 0:
        code = func_0200C464(func_0200C404(func_02012EBC(func_020120F4((const struct Ctx *)c->f04))), 0);
        failed = 0;
        r = func_0216040C((Req *)c->req, code);
        busy = 0;
        ok = func_02160564(code, &idx, &err);
        if (err == 0 && func_02012B70(func_020120F4((const struct Ctx *)c->f04)) == 1) {
            failed = 1;
        } else if (ok == 1) {
            func_02164480(&flags, c->f04, c->f08);
            if (func_02028754((struct Obj *)(&flags), idx) == 0)
                failed = 1;
        }
        if (code == 9 && func_0216070C((Work_0215EC54 *)((struct Work_0215EC54 *)c)) == 0)
            busy = 1;
        if (failed == 1) {
            *state = 5;
        } else if (busy == 1) {
            *state = 7;
        } else {
            switch (r) {
            case 0:
                *state = 2;
                break;
            case 1:
                *state = 4;
                break;
            }
        }
        break;
    case 1:
        func_020307B0(c->req);
        func_0216D9E4(func_02188C7C(c->f08));
        return 1;
    case 2:
        if (func_0216060C((int)c, (int)state) != 0) {
            func_02012374(evt, func_0216075C((struct Owner *)c->req, c->id));
            *state = 3;
        }
        break;
    case 3:
        r = c->req->result;
        if (r == 0) {
            *state = 1;
        } else if (r == 1) {
            *state = 1;
        } else if (r == 3) {
            *state = 4;
        }
        break;
    case 4:
        next = c->req->next;
        func_020307B0(c->req);
        c->req = 0;
        h = (void *)func_021644F4(next, c->f04, c->f08);
        func_02012374(evt, h);
        *state = 6;
        break;
    case 5:
        next = c->req->next;
        func_020307B0(c->req);
        c->req = 0;
        if (next == 0) {
            if (func_02012B28((const struct Rec44 *)func_020127A4(func_020120F4((const struct Ctx *)c->f04))) == 1)
                h = func_021606DC(c->f04, 1);
            else
                h = func_021606DC(c->f04, 0);
        } else {
            h = func_021606DC(c->f04, 0);
        }
        func_02012374(evt, h);
        *state = 6;
        break;
    case 6:
        func_0216D9E4(func_02188C7C(c->f08));
        return 1;
    case 7:
        func_020307B0(c->req);
        c->req = 0;
        func_02012374(evt, func_021606DC(c->f04, 2));
        *state = 8;
        break;
    case 8:
        func_0216D9E4(func_02188C7C(c->f08));
        return 1;
    }
    return 0;
}









/*
 * Unlabelled (inside func_0216025C's listing extent): maps a 25-way status
 * code to (kind, detail) at +0xC/+0x10, or to a next state at +0x28
 * (returning 1 for those).
 */
int func_0216040C(Req *r, u32 code)
{
    switch (code) {
    case 0:
        r->next = 0;
        return 1;
    case 1:
        r->kind = 7;
        return 0;
    case 2:
        r->kind = 11;
        return 0;
    case 3:
        r->kind = 8;
        return 0;
    case 4:
        r->next = 4;
        return 1;
    case 5:
        r->next = 5;
        return 1;
    case 6:
        r->kind = 0;
        r->detail = 5;
        return 0;
    case 7:
        r->kind = 6;
        r->detail = 0;
        return 0;
    case 8:
        r->kind = 6;
        r->detail = 1;
        return 0;
    case 9:
        r->kind = 6;
        r->detail = 2;
        return 0;
    case 10:
        r->kind = 2;
        r->detail = 0;
        return 0;
    case 11:
        r->kind = 2;
        r->detail = 1;
        return 0;
    case 12:
        r->kind = 2;
        r->detail = 2;
        return 0;
    case 13:
        r->kind = 2;
        r->detail = 3;
        return 0;
    case 14:
        r->kind = 2;
        r->detail = 4;
        return 0;
    case 15:
        r->kind = 1;
        r->detail = 1;
        return 0;
    case 16:
        r->kind = 1;
        r->detail = 6;
        return 0;
    case 17:
        r->kind = 1;
        r->detail = 2;
        return 0;
    case 18:
        r->kind = 1;
        r->detail = 3;
        return 0;
    case 19:
        r->kind = 1;
        r->detail = 4;
        return 0;
    case 20:
        r->kind = 1;
        r->detail = 5;
        return 0;
    case 21:
        r->kind = 3;
        r->detail = 1;
        return 0;
    case 22:
        r->kind = 3;
        r->detail = 2;
        return 0;
    case 23:
        r->kind = 3;
        r->detail = 3;
        return 0;
    case 24:
        r->kind = 5;
        return 0;
    }
    r->kind = 1;
    return 0;
}









/*
 * Unlabelled (inside func_0216025C's listing extent): translates a
 * connection state into a menu index; *err is set for unknown states.
 */
int func_02160564(u32 state, u32 *out, u32 *err)
{
    *err = 0;
    switch (state) {
    case 0:
        *out = 0;
        return 1;
    case 1:
        *out = 1;
        return 1;
    case 2:
        *out = 6;
        return 1;
    case 3:
        *out = 2;
        return 1;
    case 4:
        *out = 5;
        return 1;
    case 5:
        *out = 9;
        return 1;
    case 6:
        return 0;
    }
    *err = 1;
    return 0;
}









void func_021605C0(int a0, int a1)
{
    int a2;
    int a3;
    unsigned char fr[4];
    int t4;
    int t5;
    void *t6;
    u8 *name;
    char *res;
    int o4;
t4 = a1 + 0;
t5 = a0 + 0;
a0 = *(int *)&((struct Obj00020 *)t4)->fC;
    if (a0 != 0) goto loc_02160608;
loc_021605CE:
a0 = ((struct Obj00020 *)t4)->f18;
    if (a0 != 0) goto loc_02160608;
loc_021605D4:
a0 = 1;
a1 = 0;
    a0 = func_02040588(a0, a1);
loc_021605DC:
a0 = *(int *)&((struct Obj00020 *)t4)->f8;
    a0 = (int)func_02188C54((void *)a0);
loc_021605E2:
    if (a0 == 0) goto loc_021605EA;
loc_021605E6:
    a0 = func_02190344(a0);
loc_021605EA:
a0 = *(int *)&((struct Obj00020 *)t4)->f4;
    t6 = func_020120F4((const struct Ctx *)a0);
loc_021605F0:
    name = func_02012C0C((struct BigObj *)t6);
loc_021605F6:
a0 = 0x15;
    o4 = a0;
a1 = t5 + 0;
a3 = 0x50;
    res = func_021C4F7C(t6, a1, (const unsigned short *)name, a3, o4);
loc_02160606:
*(char * *)&((struct Obj00020 *)t4)->fC = res;
loc_02160608:
    return;
}









/*
 * unblocked: func_021C51A0 is ov021's label across the co-resident
 *   ov010/ov021 pair; the `ov021` token resolves the site as `label`.
 *   Extent runs 92 bytes against 90 compiled: the unlabelled follower.
 */
int func_0216060C(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
a0 = ((struct Obj00020 *)t5)->f18;
    if (a0 != 0) goto loc_02160662;
loc_02160616:
a0 = *(int *)&((struct Obj00020 *)t5)->f1C;
    if (a0 == 0) goto loc_02160626;
loc_0216061C:
    if (a0 == 1) goto loc_0216064A;
loc_02160620:
    if (a0 == 2) goto loc_02160656;
loc_02160624:
    goto loc_0216065E;
loc_02160626:
a0 = *(int *)&((struct Obj00020 *)t5)->fC;
    if (a0 == 0) goto loc_02160644;
loc_0216062C:
a0 = 1;
a1 = 0;
t4 = 1;
t6 = 0;
    a0 = func_02040588(a0, a1);
loc_02160638:
a0 = *(int *)&((struct Obj00020 *)t5)->fC;
    a0 = func_021C51A0(a0);
loc_0216063E:
*(int *)&((struct Obj00020 *)t5)->fC = t6;
*(int *)&((struct Obj00020 *)t5)->f1C = t4;
    goto loc_0216065E;
loc_02160644:
a0 = 2;
*(int *)&((struct Obj00020 *)t5)->f1C = a0;
    goto loc_0216065E;
loc_0216064A:
a0 = *(int *)&((struct Obj00020 *)t5)->f8;
    a0 = (int)func_02188C54((void *)a0);
loc_02160650:
    a0 = func_02190398(a0);
loc_02160654:
    goto loc_02160644;
loc_02160656:
a0 = 0;
*(int *)&((struct Obj00020 *)t5)->f1C = a0;
a0 = 1;
    return a0;
loc_0216065E:
a0 = 0;
    return a0;
loc_02160662:
a0 = 1;
    return a0;}









int func_02160668(int *a0, int *a1)
{
    void *x;

    x = func_0200C404(func_02012EBC((struct Big *)func_020120F4((const struct Ctx *)a1[1])));
    switch (a1[7]) {
    case 0:
        if (func_0200C468(x) == 0) {
            a1[6] = 1;
            a1[7] = 2;
        } else if ((u32)(a0[9] - 1) <= 2) {
            a1[7] = 2;
        } else {
            func_021605C0(1, (int)a1);
            a1[7] = 1;
        }
        break;
    case 1:
        if (func_021C5334(a1[3]) != 0) {
            a1[7] = 2;
        }
        break;
    case 2:
        a1[7] = 0;
        return 1;
    }
    return 0;
}









/*
 * Unlabelled thunk: tail-calls func_0216060C with its second argument.
 */
void func_021606D0(int a, int b)
{
    func_0216060C(b, b);
}









void *func_021606DC(void *p, u32 a)
{
    void *h;

    h = func_02158768((int)p, 0x7D6, 0, 0x15);
    func_02159058(func_021589D0((int)h), a, 0, 0, 0);
    return h;
}









/*
 * TRUE when some party member has field 0xA9 set and passes func_0201897C.
 */
int func_0216070C(Work_0215EC54 *w)
{
    void *party;
    void *pp;
    int i;

    party = func_02012934(func_020120F4(w->f04));
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        pp = func_0201AB28(party, i);
        if (func_02017E1C(pp, 0xA9, 0) != 0 && func_0201897C(pp) != 0)
            return 1;
    }
    return 0;
}









/*
 * Creates the 0x74-byte task that runs func_021607E0 and initialises it
 * from the owner.
 */
void *func_0216075C(Owner *o, u16 id)
{
    void *h;
    Task_0216075C *t;

    h = func_020122C0(o->f00, o->f08, func_021607E0, sizeof(Task_0216075C));
    t = func_020124E8(h);
    MI_CpuFill8(t, 0, sizeof(Task_0216075C));
    t->id = id;
    t->owner = o;
    t->state = 4;
    t->handle = h;
    t->f04 = o->f0c;
    t->f08 = o->f0c;
    t->f0c = o->f0c;
    t->f60 = 0;
    t->f62 = 0;
    t->f68 = 0;
    func_02160A28((Rect *)((struct Rect *)t->rect), (u32)t->owner, t->owner->f14, t->owner->f18, t->owner->f1c, t->owner->f20);
    func_02164480((struct Flags *)t->flags, t->owner->f00, t->owner->f04);
    func_0215E840(t->owner->f04, (struct Info *)t->info);
    return h;
}









/*
 * The fourteen-state task func_0216075C creates. The procedure table at
 * 0x021712CC has 24-byte records; each pool word is the table plus the
 * field offset.
 */
int func_021607E0(void *evt, u32 *state, Task_021607E0 *t)
{
    u32 v;
    void *work;

    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        v = t->state;
        if (v <= 1) {
            *state = 2;
        } else if (v == 4) {
            if (d_021712CC[t->proc].start == 0)
                *state = 6;
            else
                *state = 3;
        } else if (v == 3) {
            t->owner->result = 3;
            *state = 2;
        } else if (v == 2) {
            t->owner->result = 2;
            *state = 2;
        }
        break;
    case 2:
        v = t->state;
        if (v == 0)
            t->owner->result = 0;
        else if (v == 1)
            t->owner->result = 1;
        return 1;
    case 3:
        if (func_02160A64((Callbacks_02160A28 *)(&t->cb)) == 0)
            break;
        d_021712CC[t->proc].start(t, t->owner->f10);
        *state = 4;
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        if (t->state == 0) {
            if (func_02160A4C((Callbacks_02160A28 *)(&t->cb)) == 0)
                break;
            *state = 1;
        } else {
            *state = 1;
        }
        break;
    case 6:
        func_02012374(evt, func_021BE8D4(t->owner->f00, t->owner->f04, 0, 0));
        *state = 7;
        break;
    case 7:
        if (func_02160A64((Callbacks_02160A28 *)(&t->cb)) == 0)
            break;
        func_02012374(evt, (struct Evt **)func_020144DC((int)t->owner->f00, (int)t->owner->f04));
        *state = 11;
        break;
    case 8:
        func_02160A7C((Callbacks_02160A28 *)(&t->cb));
        func_02012374(evt, func_020145CC(t->owner->f00));
        *state = 9;
        break;
    case 9:
        work = func_0201210C(t->owner->f00);
        t->owner->f04 = work;
        func_02188DA0();
        func_02188DB0(t->owner->f04);
        *state = 10;
        break;
    case 10:
        if (func_02160A4C((Callbacks_02160A28 *)(&t->cb)) == 0)
            break;
        func_02012374(evt, func_021BE92C(t->owner->f00, t->owner->f04, 0, 0, 0, 0, 0));
        *state = 1;
        break;
    case 11:
        work = d_021712CC[t->proc].init(t, t->owner->f10, t->prev, t->work);
        if (t->work != 0) {
            d_021712CC[t->prev].exit(t->work);
            t->work = 0;
        }
        t->work = work;
        if (d_021712CC[t->proc].f04 == 0)
            break;
        func_020120B4(t->owner->f00, (u32)d_021712CC[t->proc].f00, d_021712CC[t->proc].f04, work);
        *state = 12;
        break;
    case 12:
        if (func_020120F0(t->owner->f00) != 0)
            break;
        *state = 13;
        break;
    case 13:
        t->state = d_021712CC[t->proc].finish(t, t->work);
        v = t->state;
        if (v == 0)
            t->owner->result = 0;
        else if (v == 1)
            t->owner->result = 1;
        else if (v == 3)
            t->owner->result = 3;
        else if (v == 2)
            t->owner->result = 2;
        if (t->state == 4) {
            t->prev = t->proc;
            t->proc = t->next;
            *state = 11;
        } else {
            if (t->work != 0) {
                func_020307B0(t->work);
                t->work = 0;
            }
            *state = 8;
        }
        break;
    }
    return 0;
}









/*
 * Clears a 0x14-byte record and fills it from five arguments.
 */
void func_02160A28(Rect *r, u32 tag, u32 x, u32 y, u32 w, u32 h)
{
    MI_CpuFill8(r, 0, sizeof(Rect));
    r->x = x;
    r->w = w;
    r->y = y;
    r->h = h;
    r->tag = tag;
}









/*
 * Runs the fn0 hook of the callback record func_02160A28 fills, or
 * returns 1 when the hook is empty.
 */
int func_02160A4C(Callbacks_02160A28 *c)
{
    if (c->fn0 != 0)
        return c->fn0(c->ctx, c->arg);
    return 1;
}









/*
 * Runs the fn1 hook of the callback record func_02160A28 fills, or
 * returns 1 when the hook is empty.
 */
int func_02160A64(Callbacks_02160A28 *c)
{
    if (c->fn1 != 0)
        return c->fn1(c->ctx, c->arg);
    return 1;
}









int func_02160A7C(Callbacks_02160A28 *c)
{
    if (c->fn2 != 0)
        return c->fn2(c->ctx, c->arg);
    return 1;
}









/*
 * Allocate and fill the 0x98-byte request record for a link step: player
 * handles from the save, the 20-byte header copied out of the context, and
 * the next state (+0x34) chosen from the step kind and the peer's reply.
 */
Req_02160A94 *func_02160A94(Ctx_02160A94 *c, int kind, int mode, Src_0216040C *src)
{
    void *sv;
    Req_02160A94 *r;
    u32 v;

    sv = func_020120F4((const struct Ctx *)(*(void **)c->f18));
    r = func_02030734(4, 0x98, 1, d_02172978, 0x330);
    r->f00 = func_02012934(sv);
    r->hdr = c->hdr;
    r->f04 = func_0201292C(sv);
    r->f08 = func_02008FEC(sv);
    r->f18 = func_0200CA1C(sv);
    r->f34 = 0;
    r->f3c = c->f18->f2c;
    r->f46 = 0;
    v = 0xFF;
    r->f5e = v;
    r->f30 = *func_020127A4(sv);
    r->f5f = func_02012984(sv);
    if (kind == 5) {
        r->f3c = 0;
        r->f34 = 5;
        v += 0xD3;
        r->f44 = v;
        c->f6c = 1;
    } else if (mode == 0) {
        r->f3c = 0;
    } else if (mode == 2) {
        r->f44 = src->f38;
        if (src->f34 != 3 && src->f34 != 4 && src->f34 != 1 && src->f34 != 0x12)
            r->f3c = 0;
        switch (src->f34) {
        case 1:
            if (src->f2c == 2)
                r->f34 = 0;
            break;
        case 12:
            r->f34 = 0x10;
            break;
        case 2:
            r->f34 = 9;
            break;
        case 3:
        case 18:
            r->f34 = 10;
            break;
        case 4:
            r->f34 = 10;
            break;
        case 5:
            r->f34 = 5;
            break;
        case 6:
            r->f34 = 6;
            break;
        default:
            r->f34 = 9;
            break;
        }
    } else if (mode == 6) {
        switch (src->f12) {
        case 0:
        case 1:
            if (src->f0d == 2) {
                if (c->f68 == 6) {
                    r->f34 = 8;
                    r->f50 = c->f64;
                } else {
                    r->f34 = 7;
                }
                r->f44 = c->f62;
                r->f46 = src->f14;
                if (src->f12 == 0)
                    r->f48 = src->f11;
                else
                    r->f48 = 0xFF;
            } else {
                r->f34 = 0;
                r->f3c = src->f0f;
            }
            break;
        }
    } else if (mode == 9) {
        int res;

        func_02034AC4((u32)ov136_id);
        res = func_021C3E00((u32 *)src);
        func_02034A5C((u32)ov136_id);
        if (c->f68 == 0) {
            r->f34 = 0xB;
            r->f3c = c->f60;
            r->f44 = c->f62;
        } else if (c->f68 == 2) {
            if (res == 1) {
                r->f34 = 0xC;
                r->f3c = c->f60;
                r->f44 = c->f62;
            } else {
                r->f34 = 0;
                r->f3c = c->f60;
            }
        }
    } else if (mode == 10) {
        r->f34 = 5;
        r->f44 = c->f62;
    }
    return r;
}









/*
 * Unlabelled (the listing folds it into func_02160A94's extent). Consume a
 * reply record: copy its result into the context and pick the next state.
 */
int func_02160C88(Ctx_02160C88 *c, Req_02160C88 *r)
{
    c->f18->f2c = r->f3c;
    c->f60 = r->f3c;
    if (c->f6c == 1) {
        if (r->f3c == 8)
            return 1;
        return 0;
    }
    switch (r->f40) {
    case 0:
        if (r->f34 == 6 || c->f18->f0c == 2) {
            c->state = 2;
            return 4;
        }
        if (r->f3c == 8)
            return 1;
        return 0;
    case 1:
        c->state = 6;
        return 4;
    case 3:
        c->state = 2;
        return 4;
    case 10:
        c->state = 2;
        return 4;
    case 4:
    case 5:
        c->state = 6;
        c->f62 = r->f44;
        c->f64 = r->f50;
        return 4;
    case 6:
    case 7:
        c->state = 9;
        return 4;
    case 8:
    case 9:
        c->state = 10;
        c->f62 = r->f44;
        return 4;
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
        c->f18->f28 = r->f40 - 11;
        return 2;
    case 15:
        c->state = 7;
        return 4;
    }
    return 1;
}







T *func_02160D6C(int *a0, int a1)
{
    T *p;
    void *sys;
    int s;

    p = func_02030734(4, 0x10, 0, (const char *)d_02172978, 0x49b);
    func_02082BCC(p, 0, 0x10);
    sys = func_020120F4((const struct Ctx *)*(int *)a0[6]);
    p->a = sys;
    p->b = func_0200CA1C(sys);
    p->c = func_02012944(p->a);
    s = func_02012A30(p->a);
    func_02029DBC((u8 *)s, func_02012134((u32 *)(*(int *)a0[6])));
    if (a1 != -1) {
        p->h = a1;
    } else {
        p->h = 0;
    }
    return p;
}






Bool func_02160DDC(u32 *a, u8 *b) { u32 s=func_02012A30(((struct Obj12324 *)b)->f0); func_02029DD8(s,func_02012134(*(u32 **)a[6])); if (((struct Obj12324 *)b)->fE==0) return FALSE; else return TRUE; }







/*
 * Allocate and fill the 0x28-byte battle setup for mode 0 (from the
 * caller's record) or mode 6 (from the save, picking the first party
 * slot that passes the kind's checks). Levers: both source words read
 * into locals before the two stores, the kind == -1 arm written as the
 * else so it lands at the tail, func_0201AA18 returning int.
 */
Setup *func_02160E08(Work_02160E08 *w, int kind, int mode, Src_02160E08 *src)
{
    Setup *s;
    void *sys;
    void *save;
    void *t;
    void *party;
    void *mon;
    void *link;
    int i;

    s = sub_02030734(4, sizeof(Setup), 1, d_02172978, 0x4DE);
    sys = func_020120F4(w->f18->f00);
    save = func_02012EBC(sys);
    t = func_0200CA1C(sys);
    s->f0c = 1;
    s->sys = sys;
    s->f24 = 0;
    s->f18 = func_0200CA38(t);
    if (mode == 0) {
        party = src->party;
        link = src->f0c;
        s->party = party;
        s->f04 = link;
        s->count = func_0201AA18(party);
        s->slot = src->f3c;
        switch (src->f40) {
        case 4:
            s->f14 = src->f46;
            s->f0d = 2;
            s->kind = 1;
            s->f20 = 0;
            w->f68 = 5;
            break;
        case 5:
            s->f14 = src->f46;
            s->f0d = 2;
            s->kind = 1;
            s->f20 = 0;
            w->f68 = 6;
            break;
        default:
            s->kind = 0;
            s->f0d = 0;
            s->f20 = 1;
            break;
        }
    } else if (mode == 6) {
        s->f04 = func_0200873C(save);
        s->party = func_02012934(sys);
        s->count = func_0201AA18(func_02012934(sys));
        s->slot = 0;
        s->f0d = 0;
        s->f20 = 1;
        if (kind != -1) {
            s->kind = kind;
            if (s->kind == 2) {
                party = func_02012934(sys);
                for (i = 0; i < (int)func_0201AA18(party); i++) {
                    mon = func_0201AB28(party, i);
                    if (func_02017E1C(mon, 0xA9, 0) && func_0201897C(mon) && func_02017E1C(mon, 0x4C, 0) == 0) {
                        s->slot = i;
                        break;
                    }
                }
            } else if (s->kind == 1) {
                party = func_02012934(sys);
                for (i = 0; i < (int)func_0201AA18(party); i++) {
                    mon = func_0201AB28(party, i);
                    if (func_02017E1C(mon, 0xA9, 0) && func_02017E1C(mon, 0x4C, 0) == 0) {
                        s->slot = i;
                        break;
                    }
                }
            }
        } else {
            s->kind = 0;
        }
    }
    return s;
}







/*
 * Leaf after func_02160E08's pool (0x02160F88, no func_ label in the
 * listing; reached through a pointer, not a bl).
 */
int func_02160F88(Seq *s, Evt *e)
{
    switch (e->kind) {
    case 0:
    case 1:
        if (s->f18->f0c == 6)
            return 0;
        s->state = 0;
        return 4;
    case 2:
        return 1;
    }
    return 1;
}






int func_02160FB4(void *p) { unsigned short id=func_02012AC8((const struct Rec44 *)func_020120F8(p)); if(func_02013CC8(id)==1) return 1; if(func_02013CE0(id)==1) return 3; return 0; }







/*
 * 2026-10-05 (wave P21): EXACT. Older note draft (60 B off) lacked the repeated
 * default body at the end of case 0 (the `b` to the next block at +0x72 is a cross-jumped
 * copy, see a-branch-to-the-next-case-block-is-a-repeated-case-body.md). Plain literals
 * (4, -1) match; the n local was not needed. Sets the dispatch table via explicit cases
 * 1 and 3..8 beside default.
 */
int *func_02160FE0(u8 *a0, int a1, int a2, const int *a3)
{
    int h = (int)func_020120F4((const struct Ctx *)**(int **)(a0 + 0x18));
    int *r;

    switch (a2) {
    case 2:
        r = func_0202E474((const struct BigObj *)h, (int)(a0 + 0x34), func_02160FB4((void *)**(int **)(a0 + 0x18)), 4);
        if (a1 != -1) {
            func_02008298((struct MyItemSave *)r[3], (u16)a1);
        }
        break;
    case 0:
        if (a3[16] == 3) {
            r = func_0202E474((const struct BigObj *)h, (int)(a0 + 0x34), 2, 4);
        } else {
            r = func_0202E474((const struct BigObj *)h, (int)(a0 + 0x34), func_02160FB4((void *)**(int **)(a0 + 0x18)), 4);
        }
        break;
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    default:
        r = func_0202E474((const struct BigObj *)h, (int)(a0 + 0x34), func_02160FB4((void *)**(int **)(a0 + 0x18)), 4);
        break;
    }
    return r;
}







/*
 * Menu selection dispatch: maps the chosen item (sel->item) to the next
 * state, either a sub-mode (w->ctx->mode, answer 3) or a follow-up
 * screen (w->next, answer 4).
 *
 * Levers (2026-09-28 tree_ov010_4): the arms in the image's block order
 * (not case order), and the party fetch in case 18 as its own statement
 * so w->ctx is reloaded after the calls.
 */
int func_02161070(MenuWork *w, MenuSel *sel)
{
    void *party;

    switch (sel->item) {
    case 0:
        return 1;
    case 1:
        if (sel->f2c == 2) {
            w->next = 0;
            return 4;
        }
        return 0;
    case 12:
        w->next = 0;
        return 4;
    case 10:
    case 11:
        w->ctx->mode = 0;
        return 3;
    case 13:
        w->ctx->mode = 1;
        return 3;
    case 15:
        w->ctx->mode = 3;
        return 3;
    case 16:
        w->ctx->mode = 4;
        return 3;
    case 14:
        w->ctx->mode = 2;
        return 3;
    case 8:
        w->next = 8;
        return 4;
    case 7:
        w->next = 7;
        return 4;
    case 17:
        w->next = 11;
        return 4;
    case 19:
        w->next = 9;
        return 4;
    case 18:
        party = func_02012934(func_020120F4(w->ctx->sys));
        if (func_02017E1C(func_0201AB28(party, w->ctx->slot), 6, 0) != 0)
            w->next = 0;
        else
            w->next = 9;
        w->f68 = 2;
        return 4;
    case 20:
        w->ctx->mode = 5;
        return 3;
    case 2:
        if (func_0202136C(sel->arg) == 1)
            w->f68 = 0;
        w->next = 0;
        return 4;
    }
    w->next = 0;
    return 4;
}







void func_0216117C(int *a0, int a1)
{
    void *h = func_020120F4((const struct Ctx *)*(int *)a0[6]);
    u32 v = *func_020127A4(h);
    int f = 1;
    int s;
    int *r;

    s = func_02012A30(h);
    func_02029DBC((u8 *)s, func_02012134((u32 *)(*(int *)a0[6])));
    if (func_02013CC8(v) != 0 || (int)func_02013CE0((u16)v) != 0) {
        f = 0;
    }
    r = func_0216F7BC(h, 4, f);
    if (a1 != -1) {
        r[5] = a1;
    }
}





int func_021611E0(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *ctx;

t5 = a0 + 0;
a0 = ((struct Obj00020 *)t5)->f18;
t4 = a1 + 0;
a0 = ((struct Obj00020 *)((char *)a0))->f0;
    ctx = func_020120F4((const struct Ctx *)a0);
loc_021611EE:
    a0 = func_02012A30(ctx);
loc_021611F2:
t6 = a0 + 0;
a0 = ((struct Obj00020 *)t5)->f18;
a0 = ((struct Obj00020 *)((char *)a0))->f0;
    a0 = func_02012134((u32 *)a0);
loc_021611FC:
a1 = a0 + 0;
a0 = t6 + 0;
    a0 = func_02029DD8(a0, a1);
loc_02161204:
a0 = *(int *)&((struct Obj00020 *)t4)->f10;
    if (a0 != 1) goto loc_0216120E;
loc_0216120A:
a0 = 1;
    return a0;
loc_0216120E:
a0 = 0;
    return a0;}





/*
 * Allocates a 0x18-byte record (func_02030734: heap 4, size 0x18, clear,
 * site string, tag 0x68A) and fills it from the work's 0x18 sub-object.
 */
Rec14 *func_02161214(Work_021611E0 *w)
{
    Rec14 *r = func_02030734(4, 0x18, 1, d_02172978, 0x68A);
    void *a;
    void *b;
    r->f00 = 1;
    r->f14 = (u32)w->f18->f00;
    a = func_020127A4(func_020120F4(w->f18->f00));
    b = func_020120F4(w->f18->f00);
    r->f08 = func_02012AC8(a);
    r->f0A = ((struct Obj18932 *)((u8 *)func_020128B8(b)))->f4;
    if (w->f18->f0C == 0)
        r->f00 = 0;
    else
        r->f00 = 1;
    return r;
}



int func_02161280(Work_02161280 *w, Evt_02161280 *e)
{
    int st = w->f18->f0C;
    if (st == 7) {
        switch (e->f04) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return 1;
        }
    } else if (st == 2) {
        switch (e->f04) {
        case 0:
            w->f0C = 2;
            return 4;
        case 1:
            return 1;
        default:
            return 1;
        }
    } else if (st == 0) {
        switch (e->f04) {
        case 0:
            w->f0C = 0;
            return 4;
        case 1:
            return 1;
        case 2:
            w->f18->f28 = 4;
            w->f18->f30 = e->f08;
            w->f18->f34 = e->f0C;
            w->f18->f38 = e->f10;
            w->f18->f3C = 0;
            return 2;
        default:
            return 1;
        }
    }
    return 1;
}






/*
 * Allocate an 8-byte record and store the save handle at +4. The extent
 * also holds the unlabelled leaf at 0x02161340 (nonzero test of *r1).
 */
u32 *func_02161308(char *c)
{
    u32 *r;

    func_0200873C(func_02012EBC(func_020120F4(**(void ** *)&((struct Obj12327 *)c)->f18)));
    r = func_02030734(4, 8, 1, d_02172978, 0x705);
    r[1] = **(u32 * *)&((struct Obj12327 *)c)->f18;
    return r;
}






int func_02161340(int a0, int *a1)
{
    if (*a1 != 0)
        return 1;
    return 0;
}






/*
 * Five arguments to the overlay builder: the two words of the descriptor,
 * the object's halfword, the descriptor's classification and a pointer to
 * the object's tail; the result goes to the arm9 call with the
 * object's word at +0x14.
 */
void func_02161350(void *a0)
{
    char *r4 = *(char * *)&((struct Obj09158 *)a0)->f18;
    void *t = func_02188C54(((struct Obj09159 *)r4)->f4);

    func_02012374(((struct Obj09158 *)a0)->f14,
                  func_021616A4(((struct Obj09159 *)r4)->f0, (int)(((struct Obj09159 *)r4)->f4),
                                ((struct Obj09158 *)a0)->f0, (int)t, (int)((char *)a0 + 0x10)));
}





/*
 * Allocate an 8-byte record and store the save handle at +0.
 * The extent also holds the unlabelled leaf at 0x021613A4.
 */
u32 *func_02161378(char *c)
{
    u32 *r;

    r = func_02030734(4, 8, 1, d_02172978, 0x74C);
    r[0] = (u32)func_020120F4(**(void ** *)&((struct Obj18938 *)c)->f18);
    return r;
}



int func_021613A4(Work_021613A4 *w, Evt_021613A4 *e)
{
    if (w->f18->f0C == 8) {
        switch (e->f04) {
        case 0:
            return 0;
        default:
            return 1;
        }
    }
    switch (e->f04) {
    case 0:
        w->f0C = 2;
        return 4;
    default:
        return 1;
    }
}




int func_021613CC(Ctx_021613CC *c, int a1, int mode, const Src_021613CC *src)
{
    void *sv;
    void *t;
    u32 v;
    int r;
    u16 h;

    sv = func_020120F4((const struct Ctx *)(*c->f18));
    func_02034AC4((u32)ov136_id);
    if (mode == 0) {
        t = func_02012934(sv);
        v = src->f3c;
        c->f60 = v;
        h = src->f44;
        c->f62 = h;
        if (src->f40 == 6)
            return (int)func_021C3CC0(sv, 2, (u8)src->f3c, func_0202138C(h), 4);
        c->f68 = 1;
        return (int)func_021C3D44(sv, func_0201AB28(t, v), 4);
    }
    if (src->f2c == 2) {
        r = (int)func_021C3CC0(sv, 2, (u8)src->f38, func_0202138C((u16)src->f38), 4);
        c->f62 = src->f38;
        return r;
    }
    c->f68 = 1;
    return (int)func_021C3DA4(sv, (void *)func_0202138C((u16)src->f38), 4);
}





/*
 * Lever: second state writes f0c separately in each arm; cross-jumping
 * retains the dead branch after func_021C3E04 rather than after movs #0.
 */
int func_02161484(Ctx_02161484 *c, void *p)
{
    void *sv;
    u32 v;
    sv = func_020120F4((const struct Ctx *)((const struct Ctx_02161484 *)(*c->f18)));
    if (c->f08 == 0) {
        if (c->f68 == 0 || c->f68 == 2) {
            if (func_021C3E00(p) == 1) {
                func_021C3E04(p, func_0201AB28(func_02012934(sv), c->f60));
                v = 0;
            } else if (c->f68 == 0) {
                v = 2;
            } else {
                v = 0;
            }
        } else {
            v = 0;
        }
        c->f0c = v;
        func_02034A5C((u32)ov136_id);
        return 4;
    }
    if (c->f08 == 2) {
        if (c->f68 == 2) {
            if (func_021C3E00(p) == 1) {
                func_021C3E04(p, func_0201AB28(func_02012934(sv), c->f60));
                c->f0c = 0;
            } else {
                c->f0c = 0;
            }
        } else {
            c->f0c = 2;
        }
        func_02034A5C((u32)ov136_id);
        return 4;
    }
    c->f0c = 2;
    func_02034A5C((u32)ov136_id);
    return 4;
}





void func_02161534(unsigned char *p) { func_02034AC4((u32)ov136_id); func_021C3E24(p); func_02034A5C((u32)ov136_id); }







Rec_02161554 *func_02161554(Ctx_02161484 *c, int a1, int mode, const Src_02161484 *src)
{
    Rec_02161554 *r;
    void *sv;
    void *t;
    void *k;
    u32 out;
    u32 res;
    u8 x;

    sv = func_020120F4((const struct Ctx *)((const struct Ctx_02161484 *)(*c->f18)));
    r = 0;
    if (mode == 0) {
        t = func_02012934(sv);
        if (src->f40 == 8) {
            c->f68 = 3;
            k = func_0201AB28(t, src->f3c);
            x = func_02012984(sv);
            res = func_0201B2B0(t, k, 3, src->f44, x, &out, 4);
        } else {
            c->f68 = 4;
            k = func_0201AB28(t, src->f3c);
            res = func_0201B2B0(t, k, 0, *func_020127A4(sv), func_02012984(sv), &out, 4);
        }
        r = func_02030734(4, 0x14, 0, d_02172978, 0x868);
        r->f00 = sv;
        r->f04 = t;
        r->f08 = res;
        r->f0a = src->f3c;
        r->f0b = out;
        r->f0c = 1;
        r->f10 = 1;
    }
    return r;
}







int func_02161610(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj05854 *)t4)->f18;
a0 = ((struct Obj05854 *)((char *)a0))->f0;
    func_020120F4((const struct Ctx *)((const struct Ctx_02161484 *)a0));
loc_0216161C:
a0 = ((struct Obj05854 *)t4)->f68;
    if (a0 != 3) goto loc_0216162A;
loc_02161622:
a0 = 2;
((struct Obj05854 *)t4)->fC = a0;
a0 = 4;
    return a0;
loc_0216162A:
    if (a0 != 4) goto loc_02161636;
loc_0216162E:
a0 = 0;
((struct Obj05854 *)t4)->fC = a0;
a0 = 4;
    return a0;
loc_02161636:
a0 = 0;
    return a0;}






/*
 * Allocate an 0x10-byte record and store the save handle at +4.
 * The extent also holds the unlabelled leaf at 0x02161668.
 */
u32 *func_0216163C(char *c)
{
    u32 *r;

    r = func_02030734(4, 0x10, 1, d_02172978, 0x8AC);
    r[1] = (u32)func_020120F4((const struct Ctx *)(**(void ** *)&((struct Obj18944 *)c)->f18));
    return r;
}


int func_02161668(Work_02161668 *w, Evt_02161668 *e)
{
    if (w->f18->f0C == 0xb) {
        switch (e->f0C) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return 0;
        }
    }
    switch (e->f0C) {
    case 0:
        w->f0C = 2;
        return 4;
    case 1:
        return 1;
    default:
        return 0;
    }
}




/*
 * Allocator with callback, zero-fills the node, then fills link fields.
 */
void *func_021616A4(void *p, int a1, int a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_021616F0, 0x1C);
    char *r4 = func_020124E8(r0v);

    func_02082BCC(r4, 0, 0x1C);
    ((struct Obj04884 *)r4)->fC = a3;
    ((struct Obj04884 *)r4)->f10 = a2;
    ((struct Obj04884 *)r4)->f4 = (int)p;
    ((struct Obj04884 *)r4)->f8 = a1;
    ((struct Obj04884 *)r4)->f0 = (int)func_02012EBC(func_020120F4(p));
    ((struct Obj04884 *)r4)->f14 = a4;
    return r0v;
}




int func_021616F0(int a0, int a1, int a2)
{
    int t4;

t4 = a2 + 0;
a0 = t4 + 0;
    a0 = func_02169AB8((struct Work *)a0, (u32 *)a1);
loc_021616FA:
    if (a0 == 0) goto loc_02161704;
loc_021616FE:
    if (a0 == 1) goto loc_0216170C;
loc_02161702:
    goto loc_02161716;
loc_02161704:
a1 = ((struct Obj00029 *)t4)->f14;
a0 = 1;
*(int *)&((struct Obj00654 *)((char *)a1))->f0 = a0;
    return a0;
loc_0216170C:
a0 = ((struct Obj00029 *)t4)->f14;
a1 = 0;
*(int *)&((struct Obj00029 *)((char *)a0))->f0 = a1;
a0 = 1;
    return a0;
loc_02161716:
a0 = 0;
    return a0;}
