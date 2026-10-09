/*
 * file:     game_beacon_search.c
 * unit:     yes
 * function: func_02164B38, func_02164B6C, func_02164BC4, func_02164C04, func_02164C20, func_02164C38, func_02164C64, func_02164D6C, func_02164E04, func_02164E8C, func_02164EB4, func_02164F88, func_02164F8C, func_02164F90, func_02164F98, func_02164F9C, func_02164FC4, func_02164FD0, func_0216505C, func_02165078, func_02165094, func_021650BC, func_021650CC, func_021650F4, func_02165104, func_0216512C, func_0216513C, func_02165164, func_02165174, func_0216519C, func_021651AC, func_021651D4, func_021651E4, func_0216520C, func_0216521C, func_02165244, func_02165254, func_0216527C, func_0216528C, func_021652B4, func_021652C4, func_021652EC, func_0216530C, func_02165334, func_02165344, func_02165368, func_02165374, func_021653B4, func_021653C4, func_021653E8, func_021653F4, func_02165418, func_02165424, func_0216544C, func_02165468, func_02165490, func_021654AC, func_021654D4, func_021654F0, func_02165518, func_02165534, func_0216555C, func_0216556C, func_02165590, func_0216559C, func_021655C4, func_021655D4, func_021655F8, func_02165604, func_02165628, func_02165634, func_0216565C, func_0216566C, func_02165690, func_021656A0, func_021656C4, func_021656D0, func_021656F8, func_0216570C, func_02165730, func_0216573C, func_02165760, func_0216576C, func_02165794, func_021657B0, func_021657D8, func_021657E8, func_02165814, func_02165844, func_0216586C, func_02165888, func_021658D4, func_02165940, func_02165960, func_021659F0, func_02165A10, func_02165AC4, func_02165B04, func_02165B10, func_02165B2C, func_02165B5C, func_02165C10, func_02165C34, func_02165C48, func_02165C50, func_02165C58, func_02165C5C, func_02165C60, func_02165C78, func_02165C90, func_02165CB4, func_02165CC0, func_02165CD8, func_02165CE4, func_02165CE8, func_02165D08, func_02165D10, func_02165D20, func_02165D28, func_02165D34, func_02165D40, func_02165D48, func_02165D50, func_02165D6C, func_02165D8C, func_02165DAC, func_02165DBC, func_02165DF0, func_02165E24, func_02165E34, func_02165E78, func_02165E8C, func_02165E9C, func_02165EAC, func_02165EBC, func_02165ECC, func_02165F30, func_02165F64, func_02165F74, func_02165F84, func_02165F94, func_02165FA4, func_02165FB4
 * address:  0x02164B38
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
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02164A2C 0x02164A2C thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012138  0x02012138  thumb
 *   func_02030734  0x02030734  arm
 *   func_0202647C  0x0202647C  thumb
 *   func_0202648C  0x0202648C  thumb
 *   d_021729BC     0x021729BC  data  ov010  a1
 *   func_02030B50  0x02030B50  arm
 *   func_0203CBAC  0x0203CBAC  arm
 *   d_02171C30     0x02171C30  data  ov010  a4
 *   func_02010360 0x02010360 thumb
 *   func_020103E4 0x020103E4 thumb
 *   func_0203CEAC 0x0203CEAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_020267FC  0x020267FC  thumb
 *   func_020264AC  0x020264AC  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02158570  0x02158570  thumb  ov010
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0202640C  0x0202640C  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02177BF4  0x02177BF4  thumb  ov014
 *   func_02010498  0x02010498  thumb
 *   func_0203D0FC  0x0203D0FC  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203CF3C  0x0203CF3C  arm
 *   func_02026A60  0x02026A60  thumb
 *   func_02178098  0x02178098  thumb ov014
 *   func_0203CF10  0x0203CF10  arm
 *   func_020267E4 0x020267E4 thumb
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02039414  0x02039414  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_02087E60  0x02087E60  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_02012164  0x02012164  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_02026454  0x02026454  thumb
 *   func_020263D8  0x020263D8  thumb
 *   func_0202708C  0x0202708C  thumb
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_020273C4   0x020273C4  thumb
 *   func_0202744C  0x0202744C  thumb
 *   func_020273DC   0x020273DC  thumb
 *   func_020273F8   0x020273F8  thumb
 *   func_02027414   0x02027414  thumb
 *   func_02027430   0x02027430  thumb
 *   d_02171CA0      0x02171CA0  data  ov010  a1
 *   func_020270AC  0x020270AC  thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C20C 0x0200C20C thumb
 *   func_0201F41C 0x0201F41C thumb
 *   func_02045A38  0x02045A38  arm
 *   func_0203F4CC 0x0203F4CC arm
 *   func_02026CA0 0x02026CA0 thumb
 *   func_02026C1C 0x02026C1C thumb
 *   func_02026CE0 0x02026CE0 thumb
 *   func_02026D04   0x02026D04  thumb
 *   MIi_CpuCopy32  0x02082A90  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   d_021729D4 0x021729D4 data a4
 *   d_02171CA8     0x02171CA8  data
 *   func_02045994  0x02045994  arm
 *   func_0200E3A4  0x0200E3A4  thumb
 *   func_02087D1C  0x02087D1C  arm
 *   func_0204581C  0x0204581C  arm
 *   func_02045924  0x02045924  arm
 *   d_02171CE8  0x02171CE8  data  a1
 */
#include "../../matched/include/Obj07302.h"
#include "../../matched/include/Obj12361.h"
#include "../../matched/include/Obj12363.h"
#include "../../matched/include/Obj18982.h"
#include "../../matched/include/Obj18983.h"
#include "../../matched/include/Obj18984.h"
#include "../../matched/include/Obj09313.h"
#include "../../matched/include/Obj18986.h"
#include "../../matched/include/Obj18988.h"
#include "../../matched/include/Obj12364.h"
#include "../../matched/include/Obj18989.h"
#include "../../matched/include/Obj12050.h"
#include "../../matched/include/Obj00121.h"
#include "../../matched/include/Obj05717.h"
#include "../../matched/include/Obj05718.h"
#include "../../matched/include/Obj05719.h"
#include "../../matched/include/Obj05720.h"
#include "../../matched/include/Obj18996.h"
#include "../../matched/include/Obj17722.h"
#include "../../matched/include/Obj17723.h"
#include "../../matched/include/Obj19000.h"
#include "../../matched/include/Obj17724.h"
#include "../../matched/include/Obj17725.h"
#include "../../matched/include/Obj19003.h"
#include "../../matched/include/Obj07306.h"
#include "../../matched/include/Obj17726.h"

struct Desc;
struct SeqWork2;
struct Big;
struct Ctx;
struct Obj_02164B38;
struct Req;
struct Comm;
struct Rec44;
struct SaveBlock;
struct BigObj;
struct Sub0200852CObj;
struct IcaAnime;
struct Blk34;
struct RtcTime;
struct Queue;
struct Rec;
struct Strbuf;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef volatile u16 vu16;

typedef struct LinkRec {
    u8 kind;            /* 0x00 */
    u8 f01;
    u8 f02;
    u8 data[6];         /* 0x03 */
} LinkRec;

typedef struct PollWork {
    u8 pad00[0xA];
    u16 last;           /* 0x0A */
    u32 cooldown;       /* 0x0C */
    u8 pad10[0x64];
    LinkRec rec;        /* 0x74 */
} PollWork;

typedef struct Handoff12 {
    void *sys;          /* 0x00 */
    u8 data[6];         /* 0x04 */
    u8 pad[2];
} Handoff12;

typedef struct Ent {
    u8 b0;
    u8 lo : 4;
    u8 hi : 4;
    u8 flag : 1;
    u8 kind : 5;
    u8 rest : 2;
} Ent;

typedef struct Hdr_02164B38 { u8 x[2]; u8 b0:1; u8 b1:5; u8 b6:1; u8 b7:1; } Hdr_02164B38;

typedef struct Obj_02164B38 { void *src; u8 gap[12]; Hdr_02164B38 hdr; } Obj_02164B38;

typedef struct Hdr_02164EB4 {
    u8 f00;             /* 0x00 */
    u8 f01_lo : 4;      /* 0x01 */
    u8 f01_hi : 4;
    u8 f02_0 : 1;       /* 0x02 */
    u8 f02_1 : 5;
    u8 f02_6 : 1;
    u8 f02_7 : 1;
    u8 f03_0 : 1;       /* 0x03 */
    u8 f03_1 : 1;
    u8 f03_2 : 6;
    u32 f04;            /* 0x04 */
} Hdr_02164EB4;

typedef struct Flags {
    u32 b0 : 1;
    u32 b1 : 4;
    u32 b5 : 1;
    u32 rest : 26;
} Flags;

typedef struct Obj_02164F9C { u8 pad[3]; u8 lo:7; u8 hi:1; u8 gap[0x2c]; u16 event; } Obj_02164F9C;

typedef struct Rec {
    u8 f00;
    u8 pad01[2];
    u8 lo : 7;
    u8 hi : 1;
    u8 pad04[12];
    u16 f10;
    u8 pad12[0x46];
    u32 tail;
} Rec;

struct Queue {
    struct Rec r[30];
    u16 tag[30];
    u8 head;
    u8 count;
};

typedef struct Rec_02165B5C {
    u8 f00[3];
    u8 f03 : 7;         /* 0x03 */
    u8 f03_7 : 1;
    u32 f04_0 : 17;     /* 0x04 */
    u32 f04_17 : 10;
    u32 f04_27 : 5;
    u32 f08_0 : 17;     /* 0x08 */
    u32 f08_17 : 5;
    u32 f08_22 : 10;
    u32 f0C_0 : 9;      /* 0x0C */
    u32 f0C_9 : 3;
    u32 f0C_12 : 4;
    u32 f0C_16 : 10;
    u32 f0C_26 : 6;
    u8 pad10[0x30 - 0x10];
    u16 f30;            /* 0x30 kind */
    u8 pad32[0x48 - 0x32];
    u16 f48_0 : 8;      /* 0x48 */
    u16 f48_8 : 8;
} Rec_02165B5C;

typedef int (*RecCheck)(Rec_02165B5C *r);

typedef signed char s8;

typedef short s16;

typedef struct Rec_02165C34 {
    u8 pad00[0x12];
    u16 name[8];        /* 0x12 */
} Rec_02165C34;

typedef struct {
    u32 _pad0;
    u32 _pad1;
    u32 _pad2;
    u32 field : 6;
} S_02165C48;

typedef struct {
    u32 w0;
    u32 lo : 27;
    u32 hi : 5;
} S_02165C50;

struct Packed {u16 low:8,a:3,b:5;};

struct R {u8 pad[0x48];struct Packed fields;u16 c,d;};

struct Quad {u16 a,b,c,d;};

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 lo : 9;
    u32 f : 3;
    u32 hi : 20;
} S_02165CB4;

struct S_02165CD8 {
    u8 pad0[12];
    u32 : 12;
    u32 f : 4;
};

struct S_02165CE8 {
    u8 pad0[3];
    u8 : 7;
    u8 f3 : 1;
    u8 pad4[8];
    u32 : 6;
    u32 f : 3;
};

struct S {u32 a,b,c;u32 low:16;u32 first:10;u32 second:6;};

struct Bits_02165D28 { unsigned a; unsigned low:17; unsigned value:10; unsigned high:5; };

struct Bits_02165D34 { unsigned a, b; unsigned low:22; unsigned value:10; };

struct S_02165D40 {u32 a,b;u32 value:17;u32 rest:15;};

struct S_02165D48 {u32 a;u32 value:17;u32 rest:15;};

typedef struct Rec_02165E34 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165E34;

typedef struct Rec_02165E78 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165E78;

typedef struct Rec_02165E8C {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165E8C;

typedef struct Rec_02165E9C {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165E9C;

typedef struct Rec_02165EAC {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165EAC;

typedef struct Rec_02165EBC {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165EBC;

typedef struct Rec_02165ECC {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u8 pad32[2];
    u16 text[11];       /* 0x34 */
} Rec_02165ECC;

typedef struct Rec_02165F30 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165F30;

typedef struct Rec_02165F64 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165F64;

typedef struct Rec_02165F74 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165F74;

typedef struct Rec_02165F84 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165F84;

typedef struct Rec_02165F94 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165F94;

typedef struct Rec_02165FA4 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165FA4;

typedef struct Row {
    u8 a;
    u8 b;
} Row;

extern struct Desc *func_020122C0(void *,void *,void *,u32);
extern void *func_020124E8(struct Obj_02164B38 *p);
extern int func_02164A2C(void *,u32 *,struct SeqWork2 *);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0202647C(void *obj);
extern u32 func_0202648C(void *obj);
extern void func_02030B50(void *p);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern u8 *func_02010360(int idx, void *heap);
extern void func_020103E4(u8 *);
extern int func_0203CEAC(int a0);
extern u32 func_020307B0(void *p);
extern u32 func_0200FB24(void);
extern void func_0200FBA0(void);
extern u8 func_02012E40(const u8 *o);
extern void func_02026400(struct Comm *p);
extern int func_02035390(void);
extern int func_020353B0(void);
extern void func_020267FC(void);
extern u32 func_020264AC(void *obj);
extern int func_02012B70(const struct BigObj *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern int func_02158570(u16 v);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_0202640C(struct Comm *p, u32 a, u32 b);
extern void MI_CpuFill8(void *, u8, u32);
extern void func_02177BF4(u32 id);
extern void func_02010498(void);
extern void  func_0203D0FC(int a);
extern void func_02082BCC(void *, int, int);
extern void *func_0203CF3C(u32 a);
extern int func_02026A60(struct Req *r);
extern u8 func_02178098(u8 i);
extern u32 func_0203CF10(u32 a);
extern void func_020267E4(void *);
extern int func_0203D1B4(void);
extern u32 func_02039414(void);
extern int func_02085D3C(void);
extern Flags *func_02087E60(void);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void  func_02082D44(void *src, void *dst, int n);
extern u32 func_02012164(struct IcaAnime *p);
extern int   func_0203CD98(void);
extern u32 func_02026454(void *obj);
extern void func_020263D8(struct Comm *p, u32 a1, u32 a2);
extern int func_0202708C();
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern void func_020273C4(void *, unsigned);
extern int func_0202744C(void *);
extern void func_020273DC(void *, unsigned);
extern void func_020273F8(void *, unsigned);
extern void func_02027414(void *, unsigned);
extern void func_02027430(void *, unsigned);
extern int func_020270AC();
extern void *func_0200C0F0(void *);
extern u16 *func_0200C20C(struct Blk34 *p);
extern void func_0201F41C(const u16 *,u16 *,u32);
extern int func_02045A38();
extern void func_0203F4CC(struct RtcTime *time);
extern int func_02026CA0(int *);
extern void *func_02026C1C(int n);
extern void func_02026CE0(u32 n);
extern int func_02026D04(const struct Rec *r);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern int _s32_div_f(int a, int b);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern u32 func_0200E3A4(const u8 *bits, int id);
extern char *func_02087D1C(void);
extern int func_0204581C(struct U16Vec *);
extern int func_02045924();
void *func_02164B38(void *a, void *b, u8 c);
u8 *func_02164B6C(void *unused, void *arg);
int func_02164BC4(int *st, int unused, int *q);
void func_02164C04(u8 *p);
int func_02164C20(int a,int b,u8 *p);
int func_02164C38(int a,int b,u8 *p);
void func_02164C5C(u8 *p);
void func_02164C64(void *unused, void *sys, PollWork *w);
u8 *func_02164D6C(u8 *obj, int *arg);
Ent *func_02164E04(u8 *obj, int *out);
void *func_02164E8C(Obj_02164B38 *p);
void func_02164EB4(Hdr_02164EB4 *p, void *src);
int func_02164F88(void);
int func_02164F8C(void);
int func_02164F90(int a, int b, u8 *c);
void func_02164F98(void);
Ent *func_02164F9C(Ent *p,Ent *q);
void func_02164FC4(char *p);
void func_02164FD0(u8 *obj, int flag);
int func_0216505C(int a0);
int func_02165078(int a0);
int func_02165094(void *a0);
void func_021650BC(void *a0, unsigned a1);
int func_021650CC(void *a0);
void func_021650F4(void *a0, unsigned a1);
int func_02165104(void *a0);
void func_0216512C(void *a0, unsigned a1);
int func_0216513C(void *a0);
void func_02165164(void *a0, unsigned a1);
void func_02165174(void *a0);
void func_0216519C(void *a0, unsigned a1);
void func_021651AC(void *a0);
void func_021651D4(void *a0, unsigned a1);
void func_021651E4(void *a0);
void func_0216520C(void *a0, unsigned a1);
void func_0216521C(void *a0);
void func_02165244(void *a0, unsigned a1);
void func_02165254(void *a0);
void func_0216527C(void *a0, unsigned a1);
void func_0216528C(void *a0);
void func_021652B4(void *a0, unsigned a1);
void func_021652C4(void *a0);
void func_021652EC(Obj_02164F9C *p,u32 v);
void func_0216530C(void *a0);
void func_02165334(void *a0, unsigned a1);
void func_02165344(void);
void func_02165368(void *a0);
void func_02165374(unsigned a0);
void func_021653B4(void *a0, unsigned a1);
void func_021653C4(void);
void func_021653E8(void *a0);
void func_021653F4(u16 species);
void func_02165418(void *a0);
void func_02165424(void *a0);
int func_0216544C(int a0, int a1);
void func_02165468(void *a0);
int func_02165490(int a0, int a1);
void func_021654AC(void *a0);
int func_021654D4(int a0, int a1);
void func_021654F0(void *a0);
int func_02165518(int a0, int a1);
void func_02165534(void *a0);
void func_0216555C(void *a0, unsigned a1);
void func_0216556C(void);
void func_02165590(void *a0);
void func_0216559C(void *a0);
void func_021655C4(void *a0, unsigned a1);
void func_021655D4(void);
void func_021655F8(void *a0);
void func_02165604(void);
void func_02165628(void *a0);
void func_02165634(void *a0);
void func_0216565C(void *a0, unsigned a1);
void func_0216566C(void);
void func_02165690(void *a0);
void func_021656A0(void);
void func_021656C4(void *a0);
void func_021656D0(u8 a0);
void func_021656F8(u8 *p, u8 v);
void func_0216570C(void);
void func_02165730(void *a0);
void func_0216573C(void);
void func_02165760(void *a0);
void func_0216576C(void *a0);
int func_02165794(int a0, int a1);
void func_021657B0(u16 v);
void func_021657D8(void *a0, u16 a1);
void func_021657E8(void *a,u16 b);
void func_02165814(u8 *p,void *a,u16 b);
void func_02165844(void *v);
int func_0216586C(int a0, int a1);
int func_02165888(int a0);
int func_021658D4(struct Queue *q, struct Rec *out, u16 *tag);
void func_02165940(unsigned char *p);
int func_02165960(struct Queue *q, struct Rec *rec, int tag, int mode);
int func_021659F0(u8 *q, int delta);
int func_02165A10(struct Queue *q, struct Rec *rec, u16 tag, int *flag);
int func_02165AC4(struct Queue *q, struct Rec *out, u16 *tag, int delta);
u8 func_02165B04(u8 *q);
u8 *func_02165B10(u32 heap);
u8 *func_02165B2C(u32 heap);
int func_02165B5C(Rec_02165B5C *r);
int func_02165C10(u8 *p);
void func_02165C34(Rec_02165C34 *r, void *buf);
u32 func_02165C48(S_02165C48 *a0);
u32 func_02165C50(S_02165C50 *a0);
u8 func_02165C58(const u8 *p);
u8 func_02165C5C(const u8 *p);
int func_02165C60(int a0);
int func_02165C78(int a0);
void func_02165C90(const struct R *p,struct Quad *q);
u8 func_02165CB4(S_02165CB4 *a0);
void func_02165CC0(int a0, int a1);
u8 func_02165CD8(struct S_02165CD8 *p);
u16 func_02165CE4(u8 *r);
u8 func_02165CE8(struct S_02165CE8 *p);
u8 func_02165D08(Rec *r);
void func_02165D10(const struct S *p,u16 *a,u16 *b);
u8 func_02165D20(Rec *r);
unsigned short func_02165D28(const struct Bits_02165D28 *p);
unsigned short func_02165D34(const struct Bits_02165D34 *p);
u32 func_02165D40(const struct S_02165D40 *p);
u32 func_02165D48(const struct S_02165D48 *p);
void func_02165D50(struct Rec *r, struct Strbuf *buf);
int func_02165D6C(int a0, int a1);
int func_02165D8C(int a0, int a1);
unsigned func_02165DAC(const char *p);
unsigned short func_02165DBC(const char *p);
unsigned short func_02165DF0(const char *p);
int func_02165E24(int a0);
u16 func_02165E34(Rec_02165E34 *r);
u16 func_02165E78(Rec_02165E78 *r);
u16 func_02165E8C(Rec_02165E8C *r);
u16 func_02165E9C(Rec_02165E9C *r);
u16 func_02165EAC(Rec_02165EAC *r);
u16 func_02165EBC(Rec_02165EBC *r);
void func_02165ECC(Rec_02165ECC *r, void *buf);
u16 func_02165F30(Rec_02165F30 *r);
u32 func_02165F64(Rec_02165F64 *r);
u16 func_02165F74(Rec_02165F74 *r);
u32 func_02165F84(Rec_02165F84 *r);
u8 func_02165F94(Rec_02165F94 *r);
u16 func_02165FA4(Rec_02165FA4 *r);
u8 func_02165FB4(u16 type);
extern const char d_021729BC[];
extern u8 d_02171C30[];
extern char *g_02146940;
extern u8 d_02171CA0[5];
extern const char d_021729D4[];
extern const RecCheck d_02171CA8[];
extern const Row d_02171CE8[];





void *func_02164B38(void *a, void *b, u8 c){void *t=func_020122C0(a,0,(void *)func_02164A2C,0x1c);u8 *p=func_020124E8(t);void *v=func_020120F4(a);((struct Obj07302 *)p)->f4=v;((struct Obj07302 *)p)->f8=func_02012EBC(v);((struct Obj07302 *)p)->f0=a; p[0x18]=c;return t;}






/*
 * Allocates and initialises an 0x84-byte work record.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_02164B6C(void *unused, void *arg)
{
    u32 v = (u32)func_020120F4(arg);
    void *w = (void *)func_02012138(arg);
    u8 *p = func_02030734(5, 0x84, 1, d_021729BC, 0x9c);
    ((struct Obj12361 *)p)->f0 = v;
    ((struct Obj12361 *)p)->fA = 0x1ab;
    if (func_0202647C(w) == 2 && func_0202648C(w) == 5) {
        func_02164FC4((char *)p);
    }
    return p;
}






/*
 * Two-step state machine on *st: step 0 registers a callback, step 1 polls.
 *
 * Addresses are Black-image addresses.
 */
int func_02164BC4(int *st, int unused, int *q)
{
    switch (*st) {
    case 0:
        func_02030B50((void *)12);
        func_0203CBAC((struct Req *)d_02171C30, (u32)func_02164C04, (u32)q);
        (*st)++;
        break;
    case 1:
        if (q[1] >= 1) {
            return 1;
        }
        break;
    }
    return 0;
}





void func_02164C04(u8 *p){((struct Obj12363 *)p)->f4=1; ((struct Obj12363 *)p)->f80=func_02010360(4,(void *)0x8005);}





int func_02164C20(int a,int b,u8 *p) { func_020103E4(*(u8 * *)&((struct Obj18982 *)p)->f80); func_0203CEAC((int)func_02164C5C); return 1; }





int func_02164C38(int a,int b,u8 *p) { if(((struct Obj18983 *)p)->f4==0) { func_020307B0(p); if(func_0200FB24()) func_0200FBA0(); return 1; } return 0; }





void func_02164C5C(u8 *p) { ((struct Obj18984 *)p)->f4=0; }






static inline int PAD_DetectFold(void)
{
    return (*(vu16 *)0x02FFFFA8 & 0x8000) >> 15;
}






/*
 * Per-frame poll of the wireless exchange while the field runs: stops the
 * field when a shutdown is pending, pulls the next received record
 * (func_02164D6C) and, for a new kind-2 record on an open lid with a free
 * field, starts the func_02164FD0 event with a 12-byte hand-off; any
 * other kind-2 record is dropped and its sender answered.
 *
 * MATCH (2026-09-28 tree_ov010_4): bytes exact with the kind-2 path as
 * nested ifs and a goto past the drop (the && chain puts the last-id
 * compare as `cmp r1, r0`). The one wildcard is the bl to ov011
 * 0x02177BF4, which has no label.
 *
 * 2026-10-05 (D8 lane 15): the ov011 hint on func_02177BF4 was wrong; the label is in ov014, so the symbols line now says ov014 and every relocation resolves.
 */
void func_02164C64(void *unused, void *sys, PollWork *w)
{
    void *field;
    void *p;
    u32 id;
    LinkRec *rec;
    Handoff12 *h;
    u16 v;

    field = (void *)func_02012138(sys);
    p = func_020120F4(sys);
    id = 0;
    if (func_02012E40(p) == 1)
        return;
    if (func_0200FB24()) {
        func_02026400(field);
        return;
    }
    if (func_02035390() == 1 && func_020353B0() == 1) {
        func_02026400(field);
        return;
    }
    if (w->cooldown != 0)
        w->cooldown--;
    func_020267FC();
    rec = (LinkRec *)func_02164D6C((u8 *)w, (int *)(&id));
    if (rec != 0) {
        if (rec->kind == 2) {
            if (!PAD_DetectFold() && !func_020264AC(field) && !func_02012B70(p)) {
                v = func_02012AC8(func_020127A4(p));
                if (v != w->last) {
                    w->last = v;
                    if (func_02158570(v) == 1) {
                        h = func_02030734(0x8005, sizeof(Handoff12), 1, d_021729BC, 0x154);
                        h->sys = sys;
                        MI_CpuCopy8(rec->data, h->data, 6);
                        func_0202640C(field, (u32)func_02164FD0, (u32)h);
                        goto end;
                    }
                }
            }
            MI_CpuFill8(&w->rec, 0, sizeof(LinkRec));
            func_02177BF4(id);
        } else {
            rec->kind = 0;
        }
    }
end:
    func_02010498();
}






/*
 * Per-frame poll: state 1 finishes a request; otherwise, while the 9-byte
 * record at +0x74 is empty, picks an entry with func_02164E04 and copies it in.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_02164D6C(u8 *obj, int *arg)
{
    Ent *e;
    u8 *src;
    int i;
    u8 *rec = obj + 0x74;
    if (((struct Obj09313 *)obj)->f4 == 0) {
        return 0;
    }
    if (((struct Obj09313 *)obj)->f4 == 1) {
        func_0203D0FC(0);
        ((struct Obj09313 *)obj)->f4 = 2;
        return 0;
    }
    if (rec[0] == 0) {
        e = func_02164E04(obj, arg);
        if (e != 0) {
            if (e->flag != 0) {
                func_02177BF4(*arg);
            } else if (e->kind == 1) {
                i = 0;
                func_02082BCC(rec, 0, 9);
                rec[0] = e->b0;
                rec[1] = e->lo;
                rec[2] = e->hi;
                src = func_0203CF3C((u32)*arg);
                for (i = 0; i < 6; i++) {
                    rec[3 + i] = src[i];
                }
            } else if (e->kind == 2) {
                func_02026A60((struct Req *)((u8 *)e + 8));
                func_02177BF4(*arg);
            }
        }
    }
    if (rec[0] == 0) {
        rec = 0;
    }
    return rec;
}






/*
 * Scans 16 slots for the best usable entry, stores its index through *out
 * and returns its record; 0 when none.
 *
 * Addresses are Black-image addresses.
 */
Ent *func_02164E04(u8 *obj, int *out)
{
    int none = -1;
    int best = -1;
    int i;
    Ent *p;
    int r;
    for (i = 0; i < 16; i++) {
        r = func_02178098(i);
        if ((u32)(r - 2) > 1) {
            continue;
        }
        if (r == 2 && ((struct Obj18986 *)obj)->fC != 0) {
            continue;
        }
        p = (Ent *)func_0203CF10(i);
        if (p == 0) {
            continue;
        }
        if (p->lo < p->hi) {
            if (best == none) {
                best = i;
            } else if (func_02164F9C(p, (Ent *)func_0203CF10(best)) == p) {
                best = i;
            }
        } else {
            func_02177BF4(i);
        }
    }
    if (best != -1) {
        *out = best;
        return (Ent *)func_0203CF10(best);
    }
    return 0;
}





/*
 * diagnostic: tu --suggest-split found one image-wide witness, at 02164E9C inside this caller; no viable partition.
 * extent: trailing two zero alignment bytes at 02164EB2; next labelled function 02164EB4.
 *
 * 2026-10-05 (D8 lane 15): 020267E4 now filed EXACT as src/matched/arm9/func_020267E4.c (MI_CpuCopy8(d_02146940+4, p, 0x5C)).
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
void *func_02164E8C(Obj_02164B38 *p) { func_02164EB4((Hdr_02164EB4 *)(&p->hdr), p->src); func_020267E4((u8 *)p+0x18); p->hdr.b1=2; return &p->hdr; }




/*
 * Clears a 100-byte record and fills its header bitfields from SDK
 * queries; 0x02FFFFA8 is the shared-area halfword read as a cast
 * constant (no relocation).
 */
void func_02164EB4(Hdr_02164EB4 *p, void *src)
{
    int v;
    int t;

    func_02082BCC(p, 0, 100);
    p->f00 = 3;
    p->f01_lo = (u8)func_0203D1B4();
    p->f01_hi = 3;
    p->f02_0 = (u8)func_02039414();
    p->f02_1 = 0;
    p->f04 = func_02008530((const struct Sub0200852CObj *)func_02012944(src));
    p->f02_7 = (u8)func_02085D3C();
    p->f02_6 = 0;
    t = (*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15;
    p->f03_1 = (u8)t;
    if (p->f02_7 == 1) {
        v = 1;
        if (func_02087E60()->b0 == 0 || func_02087E60()->b5 == 0)
            v = 0;
        p->f02_6 = v;
    }
}



/* Callback-table leaves: constant 100, constant 1, flag store, empty. */
int func_02164F88(void)
{
    return 100;
}



int func_02164F8C(void)
{
    return 1;
}



int func_02164F90(int a, int b, u8 *c)
{
    c[8] = 1;
    return 1;
}



void func_02164F98(void)
{
}







Ent *func_02164F9C(Ent *p,Ent *q) { if(p->flag) return q; if(p->lo>=p->hi || p->lo<q->lo) return q; return p; }









void func_02164FC4(char *p)
{
    ((struct Obj18988 *)p)->fC = 0x708;
}









/*
 * Copies a 6-byte record out of the object, and when no flag / busy
 * checks trip allocates a 0x10-byte record holding it and registers it.
 *
 * Addresses are Black-image addresses.
 */
void func_02164FD0(u8 *obj, int flag)
{
    u8 buf[6];
    u32 o = ((struct Obj18989 *)obj)->f0;
    u32 w;
    u8 *p;
    func_02082D44(obj + 4, buf, 6);
    w = func_02012138((const struct Ctx *)o);
    func_020307B0(obj);
    if (flag == 0 && func_02012164((struct IcaAnime *)o) == 1 && func_020264AC((void *)w) == 0
        && func_0203CD98() == 0 && func_02026454((void *)w) == 0) {
        p = func_02030734(5, 0x10, 1, d_021729BC, 0x287);
        ((struct Obj12364 *)p)->f0 = o;
        ((struct Obj12364 *)p)->f4 = func_02012138((const struct Ctx *)o);
        func_02082D44(buf, p + 8, 6);
        func_020263D8((struct Comm *)w, 2, (u32)p);
    }
}







int func_0216505C(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0202708C(a0);
loc_02165064:
    if (a0 == 0) goto loc_02165070;
loc_02165068:
a0 = t4 + 0;
    a0 = func_02165104((void *)a0);
loc_0216506E:
    return a0;
loc_02165070:
a0 = t4 + 0;
    a0 = func_02165094((void *)a0);
loc_02165076:
    return a0;}







int func_02165078(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0202708C(a0);
loc_02165080:
    if (a0 == 0) goto loc_0216508C;
loc_02165084:
a0 = t4 + 0;
    a0 = func_0216513C((void *)a0);
loc_0216508A:
    return a0;
loc_0216508C:
a0 = t4 + 0;
    a0 = func_021650CC((void *)a0);
loc_02165092:
    return a0;}







/*
 * Test the id against the overlay's table and, when it takes,
 * re-submit the record at the shared globals pointer.
 */
int func_02165094(void *a0){
    if (func_02027060(0x2)) {
        func_021650BC(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}









/*
 * blocked:   wild=4
 *
 * Stamp the fixed id halfword and the caller's value on the two
 * record fields, then jump to the shared submitter.
 */
void func_021650BC(void *a0, unsigned a1)
{
    ((struct Obj12050 *)a0)->f30 = 0x2;
    ((struct Obj12050 *)a0)->f32 = a1;
    func_020273C4(a0, a1);
}









int func_021650CC(void *a0){
    if (func_02027060(0x3)) {
        func_021650F4(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0202744C, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021650F4.c \
 *       --func func_021650F4 --addr 0x021650F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021650F4(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 3;
    ((struct Obj00121 *)a0)->f32 = a1;
    func_0202744C(a0);
}









int func_02165104(void *a0){
    if (func_02027060(0x4)) {
        func_0216512C(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}









void func_0216512C(void *a0, unsigned a1)
{
    ((struct Obj05717 *)a0)->f30 = 0x4;
    ((struct Obj05717 *)a0)->f32 = a1;
    func_020273DC(a0, a1);
}









int func_0216513C(void *a0){
    if (func_02027060(0x5)) {
        func_02165164(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}









void func_02165164(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 5;
    ((struct Obj00121 *)a0)->f32 = a1;
    func_0202744C(a0);
}









void func_02165174(void *a0)
{
    if (func_02027060(0x6)) {
        func_0216519C(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}









void func_0216519C(void *a0, unsigned a1)
{
    ((struct Obj05718 *)a0)->f30 = 0x6;
    ((struct Obj05718 *)a0)->f34 = a1;
    func_020273F8(a0, a1);
}









void func_021651AC(void *a0)
{
    if (func_02027060(0x7)) {
        func_021651D4(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0202744C, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021651D4.c \
 *       --func func_021651D4 --addr 0x021651D4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021651D4(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 7;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}









void func_021651E4(void *a0)
{
    if (func_02027060(0x8)) {
        func_0216520C(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}









void func_0216520C(void *a0, unsigned a1)
{
    ((struct Obj05719 *)a0)->f30 = 0x8;
    ((struct Obj05719 *)a0)->f34 = a1;
    func_02027414(a0, a1);
}









void func_0216521C(void *a0)
{
    if (func_02027060(0x9)) {
        func_02165244(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0202744C, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02165244.c \
 *       --func func_02165244 --addr 0x02165244 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02165244(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 9;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}









void func_02165254(void *a0)
{
    if (func_02027060(0xA)) {
        func_0216527C(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}









void func_0216527C(void *a0, unsigned a1)
{
    ((struct Obj05720 *)a0)->f30 = 0xA;
    ((struct Obj05720 *)a0)->f34 = a1;
    func_02027430(a0, a1);
}









void func_0216528C(void *a0)
{
    if (func_02027060(0xB)) {
        func_021652B4(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0202744C, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021652B4.c \
 *       --func func_021652B4 --addr 0x021652B4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021652B4(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 11;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}









void func_021652C4(void *a0)
{
    if (func_02027060(0x12)) {
        func_021652EC((struct Obj_02164F9C *)(g_02146940 + 4), (u32)a0);
        func_02026FB8(g_02146940 + 4);
    }
}








void func_021652EC(Obj_02164F9C *p,u32 v) { p->event=0x12; p->lo=(u8)v; func_0202744C(p); }









void func_0216530C(void *a0)
{
    if (func_02027060(0x13)) {
        func_02165334(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0202744C, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02165334.c \
 *       --func func_02165334 --addr 0x02165334 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02165334(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 19;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}









/*
 * Gate on an id test, then submit the record at the shared globals pointer.
 */
void func_02165344(void)
{
    if (func_02027060(0x15)) {
        func_02165368(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0202744C, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02165368.c \
 *       --func func_02165368 --addr 0x02165368 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02165368(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 21;
    func_0202744C(a0);
}








/*
 * Looks the id up in a five-entry byte table; on a hit re-submits the
 * record at the shared globals pointer.
 */
void func_02165374(unsigned a0)
{
    unsigned i;

    if (func_02027060(0x16)) {
        for (i = 0; i < 5; i++) {
            if (a0 == d_02171CA0[i]) {
                func_021653B4(g_02146940 + 4, a0);
                func_02026FB8(g_02146940 + 4);
                return;
            }
        }
    }
}








/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0202744C, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021653B4.c \
 *       --func func_021653B4 --addr 0x021653B4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021653B4(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 22;
    *(u32 *)((char *)a0 + 52) = a1;
    func_0202744C(a0);
}








/*
 * Gate on an id test, then submit the record at the shared globals
 * pointer.
 */
void func_021653C4(void)
{
    if (func_02027060(0x17)) {
        func_021653E8(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}








/*
 * Short thunk: stamp the id halfword on the record and hand it
 * straight to the shared submitter.
 */
void func_021653E8(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x17;
    func_0202744C(a0);
}







void func_021653F4(u16 species)
{
    if (func_02027060(0x1E)) {
        func_02165418(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}







void func_02165418(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x1E;
    func_0202744C(a0);
}







void func_02165424(void *a0)
{
    if (func_02027060(0x1F)) {
        func_0216544C((int)(g_02146940 + 4), (int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}







int func_0216544C(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x1f;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = func_020270AC(a0, a1);
loc_0216545E:
a0 = t4 + 0;
    a0 = func_0202744C((void *)a0);
loc_02165464:
    return a0;}







void func_02165468(void *a0)
{
    if (func_02027060(0x20)) {
        func_02165490((int)(g_02146940 + 4), (int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}







int func_02165490(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x20;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = func_020270AC(a0, a1);
loc_021654A2:
a0 = t4 + 0;
    a0 = func_0202744C((void *)a0);
loc_021654A8:
    return a0;}







void func_021654AC(void *a0)
{
    if (func_02027060(0x21)) {
        func_021654D4((int)(g_02146940 + 4), (int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}







int func_021654D4(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x21;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = func_020270AC(a0, a1);
loc_021654E6:
a0 = t4 + 0;
    a0 = func_0202744C((void *)a0);
loc_021654EC:
    return a0;}







void func_021654F0(void *a0)
{
    if (func_02027060(0x22)) {
        func_02165518((int)(g_02146940 + 4), (int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}







int func_02165518(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x22;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = func_020270AC(a0, a1);
loc_0216552A:
a0 = t4 + 0;
    a0 = func_0202744C((void *)a0);
loc_02165530:
    return a0;}







void func_02165534(void *a0)
{
    if (func_02027060(0x24)) {
        func_0216555C(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0202744C, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216555C.c \
 *       --func func_0216555C --addr 0x0216555C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216555C(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 36;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}







void func_0216556C(void)
{
    if (func_02027060(0x25)) {
        func_02165590(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}







void func_02165590(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x25;
    func_0202744C(a0);
}







void func_0216559C(void *a0)
{
    if (func_02027060(0x26)) {
        func_021655C4(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0202744C, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021655C4.c \
 *       --func func_021655C4 --addr 0x021655C4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021655C4(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 38;
    ((struct Obj00121 *)a0)->f32 = a1;
    func_0202744C(a0);
}







void func_021655D4(void)
{
    if (func_02027060(0x27)) {
        func_021655F8(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}







void func_021655F8(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x27;
    func_0202744C(a0);
}







void func_02165604(void)
{
    if (func_02027060(0x28)) {
        func_02165628(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}







void func_02165628(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x28;
    func_0202744C(a0);
}







void func_02165634(void *a0)
{
    if (func_02027060(0x29)) {
        func_0216565C(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}







/*
 * Stamp the fixed id halfword and the caller's value on the two
 * record fields, then jump to the shared submitter.
 */
void func_0216565C(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 0x29;
    *(u32 *)((char *)a0 + 0x34) = (u32)a1;
    func_0202744C(a0);
}







void func_0216566C(void)
{
    if (func_02027060(0x2A)) {
        func_02165690(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}






/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0202744C, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02165690.c \
 *       --func func_02165690 --addr 0x02165690 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_02165690(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 42;
    *(u32 *)((char *)a0 + 52) = 0;
    func_0202744C(a0);
}






void func_021656A0(void)
{
    if (func_02027060(0x2B)) {
        func_021656C4(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}






void func_021656C4(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x2B;
    func_0202744C(a0);
}






void func_021656D0(u8 a0)
{
    if (func_02027060(0x2C)) {
        func_021656F8((u8 *)(g_02146940 + 4), a0);
        func_02026FB8(g_02146940 + 4);
    }
}





void func_021656F8(u8 *p, u8 v) { ((struct Obj00121 *)p)->f30=0x2c; p[0x34]=v; func_0202744C(p); }






/*
 * Gate on an id test, then submit the record at the shared globals
 * pointer.
 */
void func_0216570C(void)
{
    if (func_02027060(0x2D)) {
        func_02165730(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}






/*
 * Short thunk: stamp the id halfword on the record and hand it
 * straight to the shared submitter.
 */
void func_02165730(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x2D;
    func_0202744C(a0);
}






void func_0216573C(void)
{
    if (func_02027060(0x2E)) {
        func_02165760(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}






void func_02165760(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x2E;
    func_0202744C(a0);
}






/*
 * Test id 0x2F against the overlay's table and, when it takes, file the
 * record at the shared globals pointer (sibling of func_02165634).
 */
void func_0216576C(void *a0)
{
    if (func_02027060(0x2F)) {
        func_02165794((int)(g_02146940 + 4), (int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}










int func_02165794(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x2f;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = func_020270AC(a0, a1);
loc_021657A6:
a0 = t4 + 0;
    a0 = func_0202744C((void *)a0);
loc_021657AC:
    return a0;}









void func_021657B0(u16 v) { if(func_02027060(0x30)) { func_021657D8(g_02146940+4,v); func_02026FB8(g_02146940+4); } }










void func_021657D8(void *a0, u16 a1)
{
    ((struct Obj00121 *)a0)->f30 = 48;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}









void func_021657E8(void *a,u16 b) { if(func_02027060(0x18)) { func_02165814((u8 *)g_02146940+4,a,b); func_02026FB8(g_02146940+4); } }







void func_02165814(u8 *p,void *a,u16 b) { func_0201F41C(func_0200C20C(func_0200C0F0(func_02012EBC(a))),(u16 *)(p+0x34),9); ((struct Obj00121 *)p)->f30=0x18; ((struct Obj00121 *)p)->f46=b; func_0202744C(p); }







void func_02165844(void *v) { if(func_02027060(0x31)) { func_0216586C((int)(g_02146940+4),(int)v); func_02026FB8(g_02146940+4); } }








int func_0216586C(int a0, int a1)
{
    int a2;
    int t4;

t4 = a0 + 0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
a2 = 9;
    a0 = func_02045A38(a0, a1, a2);
loc_0216587C:
a0 = 0x31;
((struct Obj00121 *)t4)->f30 = a0;
a0 = t4 + 0;
    a0 = func_0202744C((void *)a0);
loc_02165886:
    return a0;}







int func_02165888(int a0)
{
    int t[3];
    int cur;
    int n;
    int h;
    int k;
    int r;

    n = 0;
    cur = 0;
    func_0203F4CC((struct RtcTime *)t);
    h = (unsigned short)((t[0] << 8) | t[1]);
    for (;;) {
        k = func_02026CA0(&cur);
        if (k == 0x1e) {
            break;
        }
        r = func_02165960((struct Queue *)a0, (struct Rec *)((int)func_02026C1C(k)), h, 0);
        if (r == 0x1e) {
            break;
        }
        func_02026CE0(k);
        n++;
    }
    return n;
}







/*
 * Pops the front record of a 30-slot queue (0x5c-byte records, then a
 * u16 tag per slot at +0xAC8): copies out slot 0 and its tag, shifts the
 * rest down one and clears the last record. Returns 0 when empty.
 */
int func_021658D4(struct Queue *q, struct Rec *out, u16 *tag)
{
    int i;

    if (q->r[0].f00 == 0)
        return 0;
    *out = q->r[0];
    *tag = q->tag[0];
    for (i = 1; i < 30; i++) {
        q->r[i - 1] = q->r[i];
        q->tag[i - 1] = q->tag[i];
    }
    MI_CpuFill8(&q->r[29], 0, 0x5c);
    return 1;
}




/*
 * Sweep the 0x5c-strided record array and hand the first occupied slot to
 * the arm9 helper; the sweep stops at the first empty one.
 */
void func_02165940(unsigned char *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        if (p[i * 0x5C] == 0)
            break;
        func_02026D04((const struct Rec *)(p + i * 0x5C));
    }
}




/*
 * Inserts a record into the 30-slot queue (see func_021658D4): reuses the
 * first empty slot or the slot with the same f10; otherwise, when the
 * mode is 1, drops slot 0 by shifting everything down and appends.
 * Returns the slot used, or 30 when full and mode is not 1.
 */
int func_02165960(struct Queue *q, struct Rec *rec, int tag, int mode)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (q->r[i].f00 == 0 || rec->f10 == q->r[i].f10) {
            q->r[i] = *rec;
            q->tag[i] = tag;
            return i;
        }
    }
    if (mode == 1) {
        MIi_CpuCopy32(&q->r[1], &q->r[0], 29 * 0x5c);
        MIi_CpuCopy16(&q->tag[1], &q->tag[0], 58);
        q->r[29] = *rec;
        q->tag[29] = tag;
        return 29;
    }
    return 30;
}




/*
 * Ring index of the 30-slot queue (func_021658D4): head byte at +0xB04
 * plus a signed offset, wrapped mod 30 (a negative offset is biased by
 * 30 first). Filed as the callee of 02165A10.
 */
int func_021659F0(u8 *q, int delta)
{
    int h = q[0xB04];

    if (delta < 0)
        return (h + delta + 30) % 30;
    return (h + delta) % 30;
}




/*
 * Ring-buffer variant of the queue insert (func_021659F0 maps a logical
 * index to a slot): replaces the record with the same f10 if present
 * before the first empty slot, else pushes a new head; the count byte
 * saturates at 30. *flag (optional) is 1 when a new slot was taken.
 */
int func_02165A10(struct Queue *q, struct Rec *rec, u16 tag, int *flag)
{
    int i;
    int idx;

    if (flag)
        *flag = 0;
    for (i = 0; i < 30; i++) {
        idx = func_021659F0((u8 *)q, i);
        if (q->r[idx].f00 == 0)
            break;
        if (rec->f10 == q->r[idx].f10) {
            q->r[idx] = *rec;
            q->tag[idx] = tag;
            return i;
        }
    }
    if (flag)
        *flag = 1;
    idx = func_021659F0((u8 *)q, -1);
    q->r[idx] = *rec;
    q->tag[idx] = tag;
    q->head = idx;
    if (q->count < 30)
        q->count++;
    return 0;
}




/*
 * Reads the record and tag at a ring offset from the head of the queue
 * (func_021659F0 maps the offset to a slot); returns 0 for an empty slot.
 *
 * Follower 0x02165B04 (ldrb accessor of the count byte) is unlabelled.
 */
int func_02165AC4(struct Queue *q, struct Rec *out, u16 *tag, int delta)
{
    int idx = func_021659F0((u8 *)q, delta);

    if (q->r[idx].f00 == 0)
        return 0;
    *out = q->r[idx];
    *tag = q->tag[idx];
    return 1;
}




/*
 * Count byte of the 30-record queue func_02165AC4 reads (head at +0xB04,
 * count at +0xB05). Unlabelled leaf reached from ov032 func_021F27D4.
 */
u8 func_02165B04(u8 *q)
{
    return q[0xb05];
}



u8 *func_02165B10(u32 heap) { return func_02030734(heap,0x5c,1,d_021729D4,0x1b3); }




u8 *func_02165B2C(u32 heap) { u8 *p=func_02030734(heap,0xb08,1,d_021729D4,0x1c1); p[0xb04]=0; p[0xb05]=0; return p; }





/*
 * Range check of a packed record: returns 1 (invalid) on the first field
 * out of range, else the verdict of the per-kind checker picked from
 * the table at 0x02171CA8 by func_02165FB4(kind).
 */
int func_02165B5C(Rec_02165B5C *r)
{
    if (r->f30 == 0 || r->f30 >= 0x33)
        return 1;
    if (r->f48_0 >= 6)
        return 1;
    if (r->f0C_9 >= 6)
        return 1;
    if (r->f0C_16 > 999 || r->f0C_26 > 59)
        return 1;
    if (r->f03 > 0x2D && r->f03 != 0x30)
        return 1;
    if (r->f04_17 >= 427 || r->f08_22 >= 427)
        return 1;
    if (r->f04_0 > 99999 || r->f08_0 > 99999)
        return 1;
    if (d_02171CA8[func_02165FB4(r->f30)](r) != 0)
        return 1;
    return 0;
}





int func_02165C10(u8 *p)
{
    switch (((struct Obj18996 *)p)->f30) {
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x32:
        return 1;
    }
    return 0;
}





/*
 * Copy the eight-character name at +0x12 into a string buffer.
 */
void func_02165C34(Rec_02165C34 *r, void *buf)
{
    func_02045994(buf, r->name, 8);
}





/*
 * Recursive MATCH unblocker: callee of func_021BCDC0 (ov216) +0002. Coherent
 * Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes that site
 * attest as `matched`.
 */
u32 func_02165C48(S_02165C48 *a0)
{
    return a0->field;
}





/*
 * Unlabelled Thumb leaf (prints as .word data in ov010.s), the sole blocker
 * of ov011 func_02173368 +00CA: returns the top five bits of the second
 * word of its argument.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02165C50(S_02165C50 *a0)
{
    return a0->hi;
}




/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: next 4B getter 02165C5C, separately owned and filed.
 */
u8 func_02165C58(const u8 *p) { return p[1]; }




/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 */
u8 func_02165C5C(const u8 *p) { return p[2]; }





int func_02165C60(int a0)
{
    int a1;

a0 = a0 + 0x50;
a1 = 0x1a;
    a0 = func_0200E3A4((const u8 *)a0, a1);
loc_02165C6A:
    if (a0 != 0) goto loc_02165C72;
loc_02165C6E:
a0 = 0xff;
    return a0;
loc_02165C72:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    return a0;}








int func_02165C78(int a0)
{
    int a1;

a0 = a0 + 0x50;
a1 = 0x19;
    a0 = func_0200E3A4((const u8 *)a0, a1);
loc_02165C82:
    if (a0 != 0) goto loc_02165C8A;
loc_02165C86:
a0 = 0xff;
    return a0;
loc_02165C8A:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    return a0;}







/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: 2B zero padding 02165CB2.
 */
void func_02165C90(const struct R *p,struct Quad *q)
{
    q->a=p->fields.a;
    q->b=p->fields.b;
    q->c=p->c;
    q->d=p->d;
}




/*
 * Unlabelled Thumb leaf (prints as .word data in ov010.s), the sole blocker
 * of ov032 func_021F10D8 +000A: returns the three-bit field at bit 9 of the
 * fourth word of its argument.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02165CB4(S_02165CB4 *a0)
{
    return a0->f;
}




/*
 * Promoted from MATCH by the recursive-unblocker lane: 0x02087D1C now has an
 * EXACT arm9 shard entry (pkt_02087D1C), so the call resolves via `matched`.
 * Verified EXACT* (listing 144 vs compiled 24 is the multi-function extent;
 * the function's own bytes are exact).
 *
 * 2026-10-02: func_02087D1C returns a pointer, but it stays declared
 * `extern int func_02087D1C();` here.  A declaration-only fix (a pointer
 * return and a char * receiving local) does not keep the bytes: the
 * compiler moves the shift chain that builds t5.  A variant that folds the
 * shift chain into one expression,
 * `t5 = (unsigned)(*(int *)((char *)a1 + 0xc) << 0x10) >> 0x1c;`, with
 * `char *p = func_02087D1C();`, does match (EXACT, the same verdict as
 * this file against the current listings).  It changes code and not just
 * types, so it is kept outside the tree pending a decision:
 * docs/notes/func_02165CC0_variantF.c.txt.
 */
void func_02165CC0(int a0, int a1)
{
    int t4;
    int t5;

t4 = a0 + 0;
a0 = ((struct Obj17722 *)a1)->fC;
a0 = a0 << 0x10;
t5 = (unsigned)a0 >> 0x1c;
    a0 = (int)func_02087D1C();
loc_02165CCE:
a1 = t5 << 0x1c;
a1 = (unsigned)a1 >> 0x1b;
a0 = *(u16 *)((char *)a0 + a1);
((struct Obj17723 *)((char *)t4))->f0 = a0;
    return;}




/*
 * Unlabelled leaf, filed as the only overlay blocker of ov029 func_021F1CD8.
 */
u8 func_02165CD8(struct S_02165CD8 *p)
{
    return p->f;
}




/*
 * Unlabelled leaf, filed as a blocker of ov032 func_021F1144.
 */
u16 func_02165CE4(u8 *r)
{
    return ((struct Obj19000 *)r)->f10;
}




/*
 * Unlabelled leaf, filed as the only blocker of ov032 func_021F0F74.
 */
u8 func_02165CE8(struct S_02165CE8 *p)
{
    if (p->f3 == 0) {
        return p->f;
    }
    return p->f + 8;
}




/*
 * Top bit of byte 3.
 */
u8 func_02165D08(Rec *r)
{
    return r->hi;
}




/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: 2B zero padding 02165D1E.
 */
void func_02165D10(const struct S *p,u16 *a,u16 *b)
{
    *a=p->first;
    *b=p->second;
}




/*
 * Low seven bits of byte 3 (unlabelled leaf; sibling of func_02165D08).
 */
u8 func_02165D20(Rec *r)
{
    return r->lo;
}



/*
 * Parent-cleared leaf for ov216 021BCE04. ov010 coherent Thumb accessor;
 * overlapping ov009 address is interior ARM code, as explicit shows prove.
 */
unsigned short func_02165D28(const struct Bits_02165D28 *p) { return p->value; }



/*
 * Parent-cleared leaf for ov216021BD448 after same-region source/unit/shard
 * and SDK union checks. Coherent ov010 Thumb accessor; ov009 is interior ARM.
 */
unsigned short func_02165D34(const struct Bits_02165D34 *p) { return p->value; }




/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: next 8B getter 02165D48, separately owned and filed.
 */
u32 func_02165D40(const struct S_02165D40 *p) { return p->value; }



/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 */
u32 func_02165D48(const struct S_02165D48 *p) { return p->value; }




void func_02165D50(struct Rec *r, struct Strbuf *buf)
{
    func_0204581C((struct U16Vec *)buf);
    func_02045994(buf, (const u16 *)((char *)r + 0x20), 9);
}






int func_02165D6C(int a0, int a1)
{
    int a2;

a2 = a0 + 0;
a0 = ((struct Obj17724 *)a2)->f30;
    if (a0 == 0x18) goto loc_02165D7E;
loc_02165D76:
a0 = a1 + 0;
    a0 = func_0204581C((struct U16Vec *)a0);
loc_02165D7C:
    return a0;
loc_02165D7E:
a2 = a2 + 0x34;
a0 = a1 + 0;
a1 = a2 + 0;
    a0 = func_02045924(a0, a1);
loc_02165D88:
    return a0;}






int func_02165D8C(int a0, int a1)
{
    int a2;

a2 = a0 + 0;
a0 = ((struct Obj17725 *)a2)->f30;
    if (a0 == 0x31) goto loc_02165D9E;
loc_02165D96:
a0 = a1 + 0;
    a0 = func_0204581C((struct U16Vec *)a0);
loc_02165D9C:
    return a0;
loc_02165D9E:
a2 = a2 + 0x34;
a0 = a1 + 0;
a1 = a2 + 0;
    a0 = func_02045924(a0, a1);
loc_02165DA8:
    return a0;}





unsigned func_02165DAC(const char *p)
{
    unsigned a=(unsigned char)*(const unsigned short *)&((struct Obj19003 *)p)->f48;
    if(a>=6) a=5;
    return a;
}





unsigned short func_02165DBC(const char *p)
{
    unsigned a=(unsigned char)*(const unsigned short *)&((struct Obj07306 *)p)->f48;
    unsigned b=*(const unsigned short *)&((struct Obj07306 *)p)->f4E;
    switch(a) { case 2: case 3: case 4:
        if(b==0 || b>=616) b=1;
        return b;
    default: return 1;
    }
}





unsigned short func_02165DF0(const char *p)
{
    unsigned a=(unsigned char)*(const unsigned short *)&((struct Obj07306 *)p)->f48;
    unsigned b=*(const unsigned short *)&((struct Obj07306 *)p)->f4E;
    switch(a) { case 0: case 1:
        if(b==0 || b>649) b=504;
        return b;
    default: return 504;
    }
}








int func_02165E24(int a0)
{

a0 = ((struct Obj17726 *)a0)->f30;
    if (a0 == 0) goto loc_02165E2E;
loc_02165E2A:
    if ((unsigned)a0 < (unsigned)0x33) goto loc_02165E30;
loc_02165E2E:
a0 = 1;
loc_02165E30:
    return a0;}






/*
 * Returns the f32 halfword for the record types that carry one, else 0x1F8.
 */
u16 func_02165E34(Rec_02165E34 *r)
{
    switch (r->type) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 14:
    case 15:
    case 17:
    case 38:
        return r->f32;
    }
    return 0x1F8;
}






/*
 * Returns the f34 halfword of a type 0x13/0x23 record, else 0x11.
 */
u16 func_02165E78(Rec_02165E78 *r)
{
    if (r->type == 0x13 || r->type == 0x23)
        return r->f34.h;
    return 0x11;
}






/*
 * Returns the f34.h payload of a type-0x24 record, else 1.
 */
u16 func_02165E8C(Rec_02165E8C *r)
{
    if (r->type == 0x24)
        return r->f34.h;
    return 1;
}






/*
 * Returns the f34.h payload of a type-0x19 record, else 0x1F8.
 */
u16 func_02165E9C(Rec_02165E9C *r)
{
    if (r->type == 0x19)
        return r->f34.h;
    return 0x1F8;
}






/*
 * Returns the f36 payload of a type-0x1A record, else 0x11.
 */
u16 func_02165EAC(Rec_02165EAC *r)
{
    if (r->type == 0x1A)
        return r->f36;
    return 0x11;
}






/*
 * Returns the f38 payload of a type-0x32 record, else 0.
 */
u16 func_02165EBC(Rec_02165EBC *r)
{
    if (r->type == 0x32)
        return r->f38;
    return 0;
}






/*
 * Clear a string buffer and copy the 11-character text at +0x34 into it;
 * the type switch that follows has no effect left in it.
 *
 * The image dispatches as a two-node switch tree (`cmp #0x26; bgt` to the
 * lone `cmp #0x2f`, then `subs #0x10; bmi` into a 0x10..0x26 table). 1.1p1
 * builds that tree only when the 16..38 cluster holds 10 or 11 case labels
 * (9 or fewer: compare chain; 12 or more: one 0x10..0x2F table). The table
 * holes and the listed cases all reach the same exit, so WHICH ten labels
 * the source had is not recoverable from the bytes; 16..24 and 38 are a
 * stand-in, only the endpoints are pinned (2026-09-28 tree_ov010_4).
 */
void func_02165ECC(Rec_02165ECC *r, void *buf)
{
    func_0204581C(buf);
    func_02045994(buf, r->text, 11);
    switch (r->type) {
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 38:
    case 47:
        return;
    }
}






/*
 * Returns the f34 halfword for record types 6..11, else 1.
 */
u16 func_02165F30(Rec_02165F30 *r)
{
    switch (r->type) {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        return r->f34;
    }
    return 1;
}






/*
 * Returns the f34.w payload of a type-0x16 record, else 1.
 */
u32 func_02165F64(Rec_02165F64 *r)
{
    if (r->type == 0x16)
        return r->f34.w;
    return 1;
}






/*
 * Returns the f34.h payload of a type-0x14 record, else 1.
 */
u16 func_02165F74(Rec_02165F74 *r)
{
    if (r->type == 0x14)
        return r->f34.h;
    return 1;
}






/*
 * Returns the f34.w payload of a type-0x29 record, else 1.
 */
u32 func_02165F84(Rec_02165F84 *r)
{
    if (r->type == 0x29)
        return r->f34.w;
    return 1;
}






/*
 * Returns the f34.b payload of a type-0x2C record, else 0.
 */
u8 func_02165F94(Rec_02165F94 *r)
{
    if (r->type == 0x2C)
        return r->f34.b;
    return 0;
}






/*
 * Returns the f34.h payload of a type-0x30 record, else 0.
 */
u16 func_02165FA4(Rec_02165FA4 *r)
{
    if (r->type == 0x30)
        return r->f34.h;
    return 0;
}






/*
 * First byte of the two-byte table row for a record type.
 */
u8 func_02165FB4(u16 type)
{
    return d_02171CE8[type].a;
}
