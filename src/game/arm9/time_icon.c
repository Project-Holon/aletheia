/*
 * file:     time_icon.c
 * unit:     yes
 * function: func_0202E4EC, func_0202E54C, func_0202E560, func_0202E610, func_0202E688, func_0202E770, func_0202E794, func_0202E79C, func_0202E7C4, func_0202E7DC, func_0202E7E0, func_0202E7E4, func_0202E80C, func_0202E818, func_0202E82C, func_0202E83C, func_0202E848, func_0202E888, func_0202E8A4, func_0202E8B8, func_0202E8CC, func_0202E8D8, func_0202E930, func_0202E938, func_0202E940, func_0202E9AC, func_0202EA20, func_0202EA40, func_0202EB04, func_0202EB0C, func_0202EB14, func_0202EB44, func_0202EB4C, func_0202EB60, func_0202EB7C, func_0202EB9C, func_0202EC24, func_0202EC44, func_0202EC7C, func_0202ECB0, func_0202ED00, func_0202ED60, func_0202ED90, func_0202EDE4, func_0202EE0C, func_0202EE30, func_0202EE8C, func_0202EECC, func_0202EF60, func_0202EF98, func_0202F038, sub_0202F098, sub_0202F0A4, func_0202F0B0, sub_0202F114, sub_0202F138, sub_0202F144, sub_0202F170, func_0202F190, func_0202F1B4, func_0202F27C, func_0202F2AC, func_0202F2F4, func_0202F30C, func_0202F358, func_0202F3AC, func_0202F41C, func_0202F464, func_0202F47C, func_0202F488, func_0202F498, func_0202F630, func_0202F640, func_0202F688, func_0202F6D8, func_0202F72C, func_0202F738, func_0202F768, func_0202F774, func_0202F788, func_0202F7C4, func_0202F870, func_0202F940, func_0202F9F4, func_0202F9F8
 * address:  0x0202E4EC
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
 *   func_02030734    0x02030734  arm
 *   func_020457B0    0x020457B0  arm
 *   codein_param_File 0x020A77D0  data
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   g_020A033C     0x020A033C  data
 *   g_020A77E0     0x020A77E0  data
 *   func_02046C94  0x02046C94  arm
 *   func_02046C9C  0x02046C9C  arm
 *   func_02069FD0  0x02069FD0  arm
 *   func_02069FF8  0x02069FF8  arm
 *   func_0206E964  0x0206E964  arm
 *   func_02080C44  0x02080C44  arm
 *   func_02082D44  0x02082D44  arm
 *   g_020A02D0      0x020A02D0  data
 *   GX_GetBankForTex   0x02080C44  arm
 *   GX_SetBankForLCDC  0x0208068C  arm
 *   GX_SetBankForTex   0x02080294  arm
 *   MIi_CpuCopyFast    0x02082B0C  arm
 *   func_02087AE4   0x02087AE4  arm
 *   func_02080B98   0x02080B98  arm
 *   func_02080964   0x02080964  arm
 *   g_020A02B8        0x020A02B8  data
 *   g_020A02C4        0x020A02C4  data
 *   g_020A0300        0x020A0300  data
 *   FX_SinCosTable_   0x020A1B38  data
 *   g_020A2B38        0x020A2B38  data
 *   g_02148B54        0x02148B54  data
 *   g_02148B98        0x02148B98  data
 *   g_02148BCC        0x02148BCC  data
 *   g_02148D8C        0x02148D8C  data
 *   g_02148D98        0x02148D98  data
 *   g_02148DA4        0x02148DA4  data
 *   func_02047A60     0x02047A60  arm
 *   MTX_PerspectiveW  0x0207C408  arm
 *   MTX_LookAt        0x0207BCA0  arm
 *   MTX_RotX33_       0x0207AF00  thumb
 *   g_020A77EC     0x020A77EC  data
 *   func_02082BCC  0x02082BCC  arm
 *   func_020084A0  0x020084A0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158468  0x02158468  thumb
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_0201298C  0x0201298C  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008534  0x02008534  thumb
 *   blink_palanm_File    0x020A7804  data
 *   func_02049F78      0x02049F78  arm
 *   g_020A1B38  0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_02087E60  0x02087E60  arm
 *   func_02087DC4  0x02087DC4  arm
 *   func_02087DE0  0x02087DE0  arm
 *   func_02087C88  0x02087C88  arm
 *   func_0200974C  0x0200974C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_0202EC24  0x0202EC24  thumb
 *   func_02008530   0x02008530  thumb
 *   func_02009750   0x02009750  thumb
 *   func_020095E8   0x020095E8  thumb
 *   _u32_div_f      0x0209C2B0  arm
 *   g_020A7814     0x020A7814  data
 *   unk_0202F099   0x0202F099  data
 *   func_02030DA8  0x02030DA8  arm
 *   unk_0202F0A5   0x0202F0A5  data  a1
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 *   func_020056EC   0x020056EC  thumb
 *   func_0204384C   0x0204384C  arm
 *   func_02045730   0x02045730  arm
 *   func_02045758   0x02045758  arm
 *   func_02045738   0x02045738  arm
 *   func_02045760   0x02045760  arm
 *   func_02045740   0x02045740  arm
 *   func_02045778   0x02045778  arm
 *   func_020450F0   0x020450F0  arm
 *   func_02045374   0x02045374  arm
 *   func_02041B6C   0x02041B6C  arm
 *   g_0202F099      0x0202F099  data
 *   func_020437AC   0x020437AC  arm
 *   func_02045770   0x02045770  arm
 *   func_02043B5C   0x02043B5C  arm
 *   func_02045334   0x02045334  arm
 *   func_020452E8   0x020452E8  arm
 *   func_02030EAC   0x02030EAC  arm
 *   func_02031194   0x02031194  arm
 *   func_020439A0   0x020439A0  arm
 *   g_020A03C8      0x020A03C8  data
 *   func_020185F0   0x020185F0  thumb
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02018488  0x02018488  thumb
 *   func_02017E64   0x02017E64  thumb
 *   func_02017E88   0x02017E88  thumb
 *   func_02014034   0x02014034  thumb
 *   func_02017EB4  0x02017EB4  thumb
 *   func_020212E4  0x020212E4  thumb
 *   func_02007084  0x02007084  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CF04  0x0203CF04  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203D0D0  0x0203D0D0  arm
 *   func_0203CF5C  0x0203CF5C  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_020351A0  0x020351A0  arm
 *   func_020053EC  0x020053EC  thumb
 *   func_0207D534    0x0207D534  arm
 *   func_0207D3AC    0x0207D3AC  arm
 *   func_0207D3E4    0x0207D3E4  arm
 *   func_020808F4    0x020808F4  arm
 *   func_020809A0    0x020809A0  arm
 *   func_0207FDCC    0x0207FDCC  arm
 *   func_0207D4B0    0x0207D4B0  arm
 *   func_0207E24C    0x0207E24C  arm
 *   func_02082A7C    0x02082A7C  arm
 *   func_0204A1BC    0x0204A1BC  arm
 *   func_02062A4C    0x02062A4C  arm
 *   func_020862F0    0x020862F0  arm
 *   func_02082A60    0x02082A60  arm
 *   func_02062B30    0x02062B30  arm
 *   func_0207DFB4    0x0207DFB4  arm
 *   func_02062AD4    0x02062AD4  arm
 *   func_02062A98    0x02062A98  arm
 *   func_02082A48    0x02082A48  arm
 *   func_02043754    0x02043754  arm
 *   func_0201D7EC    0x0201D7EC  thumb
 *   func_02045B38    0x02045B38  arm
 *   func_02045EC0    0x02045EC0  arm
 *   func_0201C7D0    0x0201C7D0  thumb
 *   func_02045C04    0x02045C04  arm
 *   func_0201D83C    0x0201D83C  thumb
 *   ov088_id       0x00000058  data  a1
 *   ov179_id       0x000000B3  data  a1
 *   d_021BD8E8     0x021BD8E8  data
 *   d_021B68D8     0x021B68D8  data  ov179
 *   d_021BD574     0x021BD574  data
 *   g_02146948     0x02146948  data
 *   g_02146948_arg 0x02146948  data
 *   func_020312CC  0x020312CC  arm
 */
#include "../../matched/include/Obj08810.h"
#include "../../matched/include/Obj06926.h"
#include "../../matched/include/Obj08811.h"
#include "../../matched/include/Obj15860.h"
#include "../../matched/include/Obj06927.h"
#include "../../matched/include/Obj08812.h"
#include "../../matched/include/Obj03003.h"
#include "../../matched/include/Obj03004.h"
#include "../../matched/include/Obj01809.h"
#include "../../matched/include/Obj01310.h"

#define REG32(a) (*(volatile u32 *)(a))
#define REG16(a) (*(volatile u16 *)(a))
struct U16Vec;
struct Rec;
struct Arg;
struct Sub0200852CObj;
struct Ctx;
struct RtcDate;
struct Sub020097BCObj;
struct Blink;
struct OSOwnerInfo;
struct Ent0202EC24;
struct Sub02009470Obj;
struct Slot;
struct S02030FB4;
struct Descriptor;
struct Bmp;
struct Cfg;
struct CharBuf;
struct Node;
struct Obj020437AC;
struct TcblNode;
struct Sav;
struct NitroFileHeader;
struct GfFont;
struct MsgBank;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Param {
    u32 w0;        /* 0x00 */
    u32 w4;        /* 0x04 */
    u32 items[4];  /* 0x08 */
    u32 w18;       /* 0x18 */
    u32 w1c;       /* 0x1c */
    u32 w20;       /* 0x20 */
};

struct Obj0202E54C {
    u8    pad[0x20];
    void *unk20;
};

typedef int s32_0202E560;

struct Bank {
    u32 f0;
    u32 f4;
    u32 f8;
};

typedef signed int s32_0202E688;

typedef signed short s16;

typedef struct {
    s32_0202E688 x, y, z;
} VecFx32;

typedef struct {
    s32_0202E688 m[9];
} MtxFx33;

typedef struct {
    u32      f[6];
    MtxFx33  m;
} Blk;

typedef struct { u32 a[8]; } Block;

typedef struct { u32 mode, old, other; Block current, previous; } State;

typedef struct S { u8 pad00[4]; int f04; } S;

typedef signed int    s32_0202E818;

struct Date0202E888 {
    s32_0202E818 unk00;
    s32_0202E818 unk04;
    s32_0202E818 unk08;
    s32_0202E818 unk0C;
};

struct CodeIn_0202E940 {
    u32 w00;      /* 0x00 */
    u32 w04;      /* 0x04 */
    void *buf;    /* 0x08 */
    u16 h0c;      /* 0x0c */
    u16 h0e;      /* 0x0e */
    u16 h10;      /* 0x10 */
    u16 h12;      /* 0x12 */
    u32 w14;      /* 0x14 */
    u16 h18;      /* 0x18 */
};

struct CodeIn_0202E9AC {
    void *w00;    /* 0x00 */
    void *w04;    /* 0x04 */
    void *buf;    /* 0x08 */
    u16 h0c;      /* 0x0c */
    u16 h0e;      /* 0x0e */
    u16 h10;      /* 0x10 */
    u16 h12;      /* 0x12 */
    u32 w14;      /* 0x14 */
    u16 h18;      /* 0x18 */
};

struct Obj0202EA20 {
    void *unk00;
    void *unk04;
    void *unk08;
};

struct Row {
    u16 *src;
    u16 *dst;
    u16 *out;
    u16 unk0c;
    u16 count;
    u16 phase;
    u32 unk14;
};

struct CodeIn_0202EB04 {
    void *w00;
    void *w04;
    void *buf;
    u16   h0c;
    u16   h0e;
    u16   h10;
};

struct DeviceInfo {
    u32 bit0:1;
    u32 pad:4;
    u32 bit5:1;
};

struct Info0202EB60 {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    u8 pad[0x50];
};

typedef int           s32_0202EB44;

/* 0x28-byte slot; the u32 member is load-bearing (4-byte alignment turns
 * the record copy into five ldm/stm pairs). */
struct Slot {
    u32 w00;
    u8  pad04[0x22];
    u8      : 3;
    u8 mark : 1;
    u8 flag : 1;
    u8      : 3;
    u8  pad27;
};

struct Ent0202EC24 {
    u8 pad[0x26];
    u8 unk26_0 : 4;
    u8 unk26_4 : 1;
    u8 unk26_5 : 3;
    u8 unk27;
};

typedef int           s32;

struct Body {
    u32 w[10];
};

struct Obj {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u16 unk10;
    u8  pad[0xa];
};

struct Entry {
    u16 a;
    u16 b;
};

typedef signed int     s32_0202F498;

typedef int s32_0202F940;

struct State {
    u16 f00;
    u8  f02;
    u8  f03;
    u32 f04;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020457B0(u32 n, u16 heap);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
extern int func_02046C94(void);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void func_02046C9C(struct Rec *rec, u32 mode, u32 value);
extern unsigned char *func_0206E964(unsigned char *p);
extern int func_02069FD0(int p);
extern u16 func_02080C44(void);
extern void func_02069FF8(char *p, int a, int b);
extern u32  GX_GetBankForTex(void);
extern void GX_SetBankForLCDC(u32 a);
extern void GX_SetBankForTex(u32 a);
extern void MIi_CpuCopyFast(u32 src, u32 dst, u32 size);
extern void func_02087AE4(void);
extern void func_02080B98(void);
extern int func_02080964(void);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void MTX_PerspectiveW(s32_0202E688 a, s32_0202E688 b, s32_0202E688 c, s32_0202E688 d, s32_0202E688 e, s32_0202E688 f, void *g);
extern void MTX_LookAt(const VecFx32 *cam, const VecFx32 *tgt,
                       const VecFx32 *up, void *mtx);
extern void MTX_RotX33_(void *mtx, s32_0202E688 sinv, s32_0202E688 cosv);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_020084A0(struct Sub0200852CObj *p);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158468(int a0);
extern void func_0203F4E4(struct RtcDate *date);
extern u8 func_0201298C(s32_0202E818 a, u8 b);
extern int func_02009D1C(struct Sub020097BCObj *obj, struct Sub0200852CObj *p, u32 *out);
extern u16 *func_020084F4(void *p);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern s32_0202E818 func_02061CA4(void *p, u32 a, u32 b, s32_0202E818 size);
extern u32 func_02085D3C(void);
extern u32 func_0202EB0C(void);
extern struct DeviceInfo *func_02087E60(void);
extern void func_02087DC4(void);
extern int func_02087DE0(void);
extern void func_02087C88(struct OSOwnerInfo *info);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern struct Slot *func_0200974C(u32 a);
extern u32 func_0202EC24(const struct Ent0202EC24 *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 func_02009750(struct Sub02009470Obj *obj, u32 n);
extern void func_020095E8(struct Sub02009470Obj *obj);
extern u32 _u32_div_f(u32 a, u32 b);
extern u32   func_02030DA8(void *owner, u8 *tag, void *p, u32 a3);
extern void *func_020311B8(u32 a, u8 *tag, u32 size, u32 flags);
extern void *func_02031290(struct S02030FB4 *p);
extern u32 func_020056EC(u32 range);
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern u8 func_02045730(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u8 func_02045778(struct Descriptor *p);
extern u32  func_020450F0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 a);
extern void func_020437AC(struct Obj020437AC *p);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *a);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02030EAC(struct Node *n);
extern void func_02031194(struct TcblNode *n);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern u32  func_020185F0(void *a0);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32 func_02018488(void *p, void *mail);
extern void func_02017E64(void *p, u32 id, u32 v);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02014034(u32 id);
extern u32  func_02008510(const struct Sub0200852CObj *obj, u32 n);
extern u32  func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02017EB4(void *p);
extern u32 func_020212E4(u16 v);
extern void func_02007084(void);
extern int  func_0203CD98(void);
extern void func_0203CF04(void);
extern int func_0203CEAC(int a0);
extern void func_0203D0D0(void);
extern u32 func_0203CF5C(void);
extern int  func_0203CDBC(void);
extern int func_020351A0(u32 v);
extern void func_020053EC(void);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern long func_0207D3AC(int enable);
extern long func_0207D3E4(int enable);
extern int func_020808F4(void);
extern int func_020809A0(void);
extern void func_0207FDCC(u32 a);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void *func_0207E24C(void);
extern void func_02082A7C(u32 a, u32 b, u32 c);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern s32_0202F498 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void func_020862F0(u32 a, u32 b);
extern void func_02082A60(u32 a, u32 b, u32 c);
extern int func_02062B30(void *file, void **out);
extern void *func_0207DFB4(void);
extern s32_0202F498 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32_0202F498 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_02082A48(u32 v, u32 dst, u32 n);
extern struct Bmp *func_02043754(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_020312CC(u32 ovl, u32 proc, u32 arg);
struct Param *func_0202E4EC(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src);
void sub_0202E54C(struct Obj0202E54C *p);
void *func_0202E560(u32 heap, u32 sel);
void func_0202E610(u32 a0, u32 a1);
void func_0202E688(u32 a0);
void *func_0202E770(void *heap);
void sub_0202E794(void *p);
void func_0202E79C(u8 *p);
void func_0202E7C4(State *p, u32 mode, const Block *src);
char *func_0202E7DC(char *p);
u32 func_0202E7E0(State *p);
void func_0202E7E4(State *p);
void func_0202E80C(u32 *p);
int func_0202E818(int *p);
void *func_0202E82C(S *p);
int func_0202E83C(void *a0);
int func_0202E848(int a0, int a1, int a2);
u8 sub_0202E888(void);
u8 sub_0202E8A4(u8 x);
u8 sub_0202E8B8(s32_0202E818 x);
u8 sub_0202E8CC(s32_0202E818 a, s32_0202E818 b);
int func_0202E8D8(char *a0, int a1, char *a2);
u16 *func_0202E930(void *p);
u16 func_0202E938(void *p);
struct CodeIn_0202E940 *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
void func_0202E9AC(struct CodeIn_0202E9AC *p, u8 *a1, u32 a2, u32 a3, u32 a4);
u32 sub_0202EA20(struct Obj0202EA20 *p);
s32_0202E818 func_0202EA40(struct Row *p);
void func_0202EB04(struct CodeIn_0202EB04 *p);
u32 sub_0202EB0C(void);
int func_0202EB14(void);
void func_0202EB44(void);
u32 sub_0202EB4C(void);
void sub_0202EB60(u8 *a, u8 *b);
u32 func_0202EB7C(u32 a0, u32 a1);
u32 func_0202EB9C(u32 a, void *b);
u32 sub_0202EC24(const struct Ent0202EC24 *p);
u32 func_0202EC44(struct Slot *a0, u32 a1);
s32 func_0202EC7C(struct Slot *a0, u32 a1);
s32 func_0202ECB0(struct Slot *a0, void *b);
void func_0202ED00(struct Slot *t, u32 n);
void func_0202ED60(u32 a, void *b, u32 c);
void func_0202ED90(u8 *a, struct Slot *b, u32 c);
u32 func_0202EDE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
u32 func_0202EE0C(u32 a, u32 b, u32 c, u32 d, u32 e);
u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);
void func_0202EECC(u8 *p, void *a1, u8 a2, u8 a3, u16 a4);
struct Obj *func_0202EF60(u32 heap);
void func_0202EF98(u8 *p, u32 a1, u32 a2, u8 a3, u8 a4);
void func_0202F038(u8 *p);
void sub_0202F098(void *node, u8 *work);
void sub_0202F0A4(void *node, u8 *work);
void func_0202F0B0(u8 *p);
u32 sub_0202F114(const u8 *p, u32 i);
u16 sub_0202F138(u32 i);
u32 sub_0202F144(u32 key);
u32 sub_0202F170(u16 key);
void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void func_0202F1B4(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_0202F27C(void *a0);
void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
void func_0202F2F4(void *a0, u32 a1);
void func_0202F30C(void *a0, u32 a1, u32 a2);
void func_0202F358(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
void func_0202F3AC(void *a0, u32 a1);
void func_0202F41C(void *a0, const struct Sub0200852CObj *a1, u32 a2);
void func_0202F464(void *a0);
void func_0202F47C(void *p);
int func_0202F488(u32 a0, int a1);
int func_0202F498(void *a0, int a1);
void func_0202F630(u32 a, u32 b);
void func_0202F640(u32 a, u32 b);
unsigned int func_0202F688(unsigned int n);
unsigned int func_0202F6D8(unsigned int n);
u32 func_0202F72C(void *a, u16 b, u16 c);
int func_0202F738(void *p, int a1);
void func_0202F768(void);
void func_0202F774(u32 on);
void func_0202F788(u32 mode);
void func_0202F7C4(u32 a0);
void func_0202F870(void);
void func_0202F940(u32 a0);
int func_0202F9F4(void);
int func_0202F9F8(void *unused, u32 *state);
extern const char codein_param_File[];
extern char g_020A033C[];
extern char g_020A77E0[];
extern struct Bank g_020A02D0[];
extern VecFx32 g_020A02C4;
extern VecFx32 g_020A02B8;
extern Blk      g_020A0300;
extern const s16 FX_SinCosTable_[];
extern s16      g_020A2B38[];
extern u32      g_02148B54[];
extern u32      g_02148B98[];
extern u32      g_02148BCC[];
extern VecFx32  g_02148D8C;
extern VecFx32  g_02148D98;
extern VecFx32  g_02148DA4;
extern const char g_020A77EC[];
extern const char blink_palanm_File[];
extern s16 g_020A1B38[];
extern char g_020A7814[];
extern u8   unk_0202F099[];
extern u8   unk_0202F0A5[];
extern u8 g_0202F099[];
extern struct Entry g_020A03C8[];
extern u8 ov088_id[];
extern u8 ov179_id[];
extern u8 d_021BD8E8[];
extern u8 d_021B68D8[];
extern u8 d_021BD574[];
extern struct State g_02146948;
extern u8 g_02146948_arg[];










/*
 * Levers that decided this one:
 *   - the heap parameter must be u32 with an explicit (u16) cast at each use;
 *     declared u16 the allocator kept the wrong value in r7 and the frame
 *     came out 88 bytes instead of 96.
 *   - `int i;` is declared BEFORE the result pointer, which is what puts the
 *     loop counter in r4 and the result in r5
 *     (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *   - the struct has a dead u32 at +0x18 between items[4] and w1c, so the
 *     allocator's size argument is 0x24, not 0x20.
 *
 * TU: codein_param.c (__FILE__ 0x020A77D0, line 0x37).
 */
struct Param *func_0202E4EC(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src)
{
    int i;
    struct Param *p;

    p = func_02030734((u16)heap, sizeof(struct Param), 0, codein_param_File, 0x37);
    p->w0 = a1;
    p->w4 = a3;
    p->w20 = func_020457B0(a3 + 1, (u16)heap);
    p->w1c = a2;
    for (i = 0; i < 3; i++) {
        p->items[i] = src[i];
    }
    p->items[i] = src[i - 1];

    return p;
}










/*
 * A whole translation unit, matched as one byte range.
 *
 * A destructor: release the one owned handle at offset 0x20, then free
 * the object.
 *
 * Matched as a one-function unit because the two bytes of `00 00` at
 * 0x0202E55E are the linker's inter-section fill before 0x0202E560.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202E54C.c \
 *       --addr 0x0202E54C --thumb
 */
void sub_0202E54C(struct Obj0202E54C *p)
{
    func_02045808(p->unk20);
    func_020307B0(p);
}








/*
 * Screen-texture setup (the __FILE__ anchor for this address is
 * screentex.c, 0x020A77E0). Allocates a small control block and a 0x8C-byte
 * work buffer off the heap in a0, seeds the buffer from a template with
 * MI_CpuCopy8 (func_02082D44), binds it to the control block, then builds a
 * packed VRAM descriptor: bits of the bank word returned by func_02080C44
 * are folded into an accumulator under a fall-through switch on a1, and the
 * result is combined with the texture size from func_0206E964 /
 * func_02069FD0 before the final publish through func_02069FF8.
 *
 * BLOCKED: every concrete byte is correct; the single unresolved relocation
 * is the ABS32 to the 0x8C-byte template at 0x020A033C. No evidence class
 * reaches it. The only pool word naming that address anywhere in the image
 * is the one at 0x0202E60C, inside this function's own range, so `literal`
 * and `sole-ref/data` both refuse it (layout/data_objects.txt line for
 * 0x020A033C records exactly that one referrer site, twice-listed from the
 * two unit spellings of the same listing). `tu --suggest-split` confirms no
 * cut exists: 1 witness image wide, 1 of them inside this range. Unsticking
 * this needs a second referrer of 0x020A033C, i.e. another function that
 * loads the same template, to reach EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202E560.c \
 *       --func func_0202E560 --addr 0x0202E560 --cc 1.1p1 --thumb
 */
void *func_0202E560(u32 heap, u32 sel)
{
    void *blk;
    void *buf;
    void *tex;
    u32 size;
    u32 bank;
    u32 acc;

    blk = func_02030734(heap, func_02046C94(), 0, g_020A77E0, 0x3b);
    buf = func_02030734(heap, 0x8c, 0, g_020A77E0, 0x3c);
    func_02082D44(g_020A033C, buf, 0x8c);
    func_02046C9C(blk, 2, (u32)buf);
    tex = func_0206E964(buf);
    size = func_02069FD0((int)tex);
    bank = func_02080C44();
    acc = 0;
    switch (sel) {
    case 3:
        bank |= 4;
        if (bank) {
            acc = acc + (4 << 15);
        }
    case 2:
        bank |= 2;
        if (bank) {
            acc = acc + (2 << 16);
        }
    case 1:
        bank |= 1;
        if (bank) {
            acc = acc + (1 << 17);
        }
    case 0:
        break;
    }
    func_02069FF8(tex, ((size >> 4) << 16) | ((acc << 13) >> 16), 0);
    return blk;
}










/*
 * PARKED AT MATCH.  Every concrete byte is right; the three open sites are
 * the pool words for the 0x020A02D0 table (at +0, +4 and +8), and the only
 * words in the image that hold 0x020A02D0 are this function's own pool at
 * 0x0202E674..0x0202E684, inside the compared range, so `literal` has no
 * outside witness.  It closes the day another function elsewhere in the
 * image loads the same table, or when a shard entry covers one.
 *
 * Bank 0x80300010 is selected for the 12-byte record a0 in 0x020A02D0, its
 * texture slot is remapped to a1's, and a0's frame buffer (0xC000 words per
 * bank, hence the `0xc << 13`) is copied into a1's.  The hardware word at
 * 0x04000064 is a cast constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202E610.c \
 *       --func func_0202E610 --addr 0x0202E610 --cc 1.1p1 --thumb
 */
void func_0202E610(u32 a0, u32 a1)
{
    u32 prev = GX_GetBankForTex();
    u32 st;

    GX_SetBankForLCDC(g_020A02D0[a0].f0);
    *(u32 *)0x04000064 = (g_020A02D0[a0].f4 << 16) | 0x80300010;

    func_02087AE4();
    func_02087AE4();
    func_02080B98();
    GX_SetBankForTex(prev);

    if (a0 != a1) {
        st = func_02080964();
        MIi_CpuCopyFast(g_020A02D0[a0].f8, g_020A02D0[a1].f8, 0xC << 13);
        func_02080B98();
        GX_SetBankForTex(st);
    }
}










static inline s16 FX_SinIdx(int idx)
{
    return FX_SinCosTable_[((idx >> 4) << 1)];
}










static inline s16 FX_CosIdx(int idx)
{
    return FX_SinCosTable_[((idx >> 4) << 1) + 1];
}









static inline void MTX_Perspective(s32_0202E688 fovySin, s32_0202E688 fovyCos, s32_0202E688 aspect,
                                   s32_0202E688 n, s32_0202E688 f, void *mtx)
{
    MTX_PerspectiveW(fovySin, fovyCos, aspect, n, f, 0x1000, mtx);
}










/*
 * One camera/billboard setup for the texture upload path: three VecFx32
 * globals are snapshotted into locals (0x020A02C4 -> cam, 0x020A02B8 -> tgt,
 * up zeroed between them), a 60-byte render block is copied up from
 * 0x020A0300, the perspective matrix is built with the SDK's
 * MTX_Perspective(FX_SinIdx(0xE38), FX_CosIdx(0xE38), ...) (a 20 degree
 * half-angle; FX_SinCosTable_ at 0x020A1B38), the three vectors are stored back
 * out to 0x02148D8C/0x02148D98/0x02148DA4 and MTX_LookAt writes the view
 * matrix to 0x02148B98.  The two `bics` on word 31 of 0x02148BCC are modes:
 * the first clears 0x50 before the vectors are committed, the second clears
 * 0xe8 after the look-at.  MTX_RotX33_ then writes the 3x3 at +0x18 of the
 * copied block (buf[6]) from the (sin, cos) pair at the head of 0x020A2B38.
 *
 * WAVE 16: the 10-byte residue of docs/notes/pkt_0202E560.c.txt (the cos
 * offset `movs r1, #0xe` issued one slot early) was the SDK inlines.  Written
 * as FX_SinIdx / FX_CosIdx inside the MTX_Perspective inline rather than
 * two constant table reads straight into MTX_PerspectiveW, the argument IR
 * comes out in the image's order.  The old `literal` cap on the four rodata
 * pool words is carried by sole-ref/self now.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202E688.c \
 *       --func func_0202E688 --addr 0x0202E688 --cc 1.1p1 --thumb
 */
void func_0202E688(u32 a0)
{
    VecFx32 cam = g_020A02C4;
    VecFx32 up = { 0, 0, 0 };
    VecFx32 tgt = g_020A02B8;
    Blk buf = g_020A0300;

    MTX_Perspective(FX_SinIdx(0xE38), FX_CosIdx(0xE38), 0x1555, 0x1000,
                    0x400000, g_02148B54);
    g_02148BCC[31] &= ~0x50u;
    g_02148D8C = cam;
    g_02148D98 = tgt;
    g_02148DA4 = up;
    MTX_LookAt(&cam, &tgt, &up, g_02148B98);
    g_02148BCC[31] &= ~0xe8u;
    MTX_RotX33_(&buf.m, g_020A2B38[0], g_020A2B38[1]);
    func_02047A60((void *)a0, (struct Arg *)buf.f);
}










void *func_0202E770(void *heap)
{
    void *p = func_02030734((u32)heap, 0x4c, 1, g_020A77EC, 0x2c);

    func_0202E79C(p);
    return p;
}










/*
 * A pool-word-and-bx tail call into the ARM deallocator
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): eight bytes, no
 * prologue, no label in the listing. The destructor half of the
 * constructor at 0x0202E770, which allocates the same object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202E794.c \
 *       --func sub_0202E794 --addr 0x0202E794 --cc 1.1p1 --thumb
 */
void sub_0202E794(void *p)
{
    func_020307B0(p);
}










void func_0202E79C(u8 *p)
{
    func_02082BCC(p, 0, 0x4c);
    ((struct Obj08810 *)p)->f0 = 0;
    ((struct Obj08810 *)p)->f4 = 0;
    ((struct Obj08810 *)p)->f8 = 0;
    func_020084A0((struct Sub0200852CObj *)(p + 0xc));
    func_020084A0((struct Sub0200852CObj *)(p + 0x2c));
}










/*
 * Sets the mode word and copies a 32-byte block into the current slot
 * (same State layout as func_0202E7E0).  Caller: ov011 0x02174514.
 */
void func_0202E7C4(State *p, u32 mode, const Block *src)
{
    p->mode = mode;
    p->current = *src;
}









/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
char *func_0202E7DC(char *p)
{
    return p + 0xc;
}










/*
 * Witness leaf for ov093 func_021C4744 (tiny unlabelled arm9 leaf).
 */
u32 func_0202E7E0(State *p) { return p->mode; }








void func_0202E7E4(State *p)
{
    p->old = p->mode;
    p->previous = p->current;
    p->mode = 3;
}







/*
 * note:     2026-10-05 wave P19 lane 6: tiny unlabelled leaf filed as the
 *           witness for the call in ov010 func_0216EB98 (moves word 0 of the
 *           block into word 2 and clears word 0).
 */
void func_0202E80C(u32 *p)
{
    p[2] = p[0];
    p[0] = 0;
}








/*
 * Unlabelled Thumb leaf: nonzero if either of two words at +4 or +8 is set.
 */
int func_0202E818(int *p)
{
    if (p[1] != 0 || p[2] != 0)
        return 1;
    return 0;
}










void *func_0202E82C(S *p)
{
    if (p->f04 != 0)
        return (char *)p + 0x2C;
    return (char *)p + 0xC;
}










int func_0202E83C(void *a0)
{
    return func_02158468(func_02012138(a0));
}










int func_0202E848(int a0, int a1, int a2){ int t0, t1, t2, t3; t0 = func_02012B70((int)((a0 + 0) + 0)); if ((unsigned int)(t0) != (unsigned int)(0)) { t1 = func_02012984((int)((a0 + 0) + 0)); ((struct Obj06926 *)((char *)((a1 + 0))))->f0 = (unsigned short)t1; ((struct Obj08811 *)((char *)((a2 + 0))))->f0 = (unsigned short)((struct Obj06926 *)((char *)((a1 + 0))))->f0; return 0; } else { t2 = func_02012984((int)((a0 + 0) + 0)); ((struct Obj06926 *)((char *)((a1 + 0))))->f0 = (unsigned short)t2; t3 = func_0202E888((int)t2); ((struct Obj08811 *)((char *)((a2 + 0))))->f0 = (unsigned short)t3; if ((unsigned int)(((struct Obj06926 *)((char *)((a1 + 0))))->f0) != (unsigned int)(((struct Obj08811 *)((char *)((a2 + 0))))->f0)) { return 1; } else { return 0; } } }










/*
 * A whole translation unit, matched as one byte range.
 *
 * Four small date helpers. sub_0202E888 asks the ARM clock getter for a
 * 0x10-byte record and reduces its second word to a two-bit value;
 * sub_0202E8A4 and sub_0202E8B8 step that value forwards and backwards
 * around the same four-element cycle.
 *
 * The `lsrs #0x1F` / `lsls #0x1E` / `subs` / `rors #0x1E` quartet in the
 * two steppers is a signed `% 4` and nothing else: `& 3` is a two
 * instruction `movs`/`ands`, which is exactly what sub_0202E888 uses at
 * the top, and `/ 4` carries a different rounding correction. Both
 * spellings appear four instructions apart in the same 80 bytes, so the
 * pair of them pins the signedness of each operand independently.
 *
 * The `lsls #0x18` / `lsrs #0x18` at the end of all three is the `(u8)`
 * return type.
 *
 * sub_0202E8CC is a twelve byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) that narrows its
 * second argument to `u8` on the way through. It nearly cost the file a
 * cut: the pool word at 0x0202E8D4 is the only occurrence of 0x0201298D
 * anywhere in the image, 0x0201298C carries no `func_` label, and the
 * pool word is inside this range, so the `literal` class has nothing and
 * no cut can reach further since the range cannot be smaller than that
 * one function. The `matched` class covers it instead: 0x0201298C is
 * already an EXACT manifest entry from earlier work, and that witness is
 * a compilation rather than a byte of this range.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202E888.c \
 *       --addr 0x0202E888 --thumb
 */
u8 sub_0202E888(void)
{
    struct Date0202E888 d;

    func_0203F4E4((struct RtcDate *)(&d));
    return (u8)((d.unk04 - 1) & 3);
}










u8 sub_0202E8A4(u8 x)
{
    return (u8)((x + 1) % 4);
}










u8 sub_0202E8B8(s32_0202E818 x)
{
    return (u8)((x + 3) % 4);
}










u8 sub_0202E8CC(s32_0202E818 a, s32_0202E818 b)
{
    return func_0201298C(a, (u8)b);
}










/*
 * Six-byte record matcher against a three-slot table at a0+0x22 (six bytes
 * apart).  Both loop counters are `unsigned char` - the lsls 0x18 / lsrs 0x18
 * pair after each increment is the narrowing, and the comparisons are `blo`,
 * so signed ints give `blt` instead.
 *
 * Do NOT bind the record base to a local `char *p`: writing the inner compare
 * as `p[0x22 + j]` makes the compiler hoist `adds r4, a0, i*6` ahead of the
 * ok/j initialisers and differs by six bytes.  Spelling the base out as
 * `a0 + i * 6` inside the compare leaves the hoist where the original has it
 * (after `movs r6,#1` and `movs r3,#0`).
 *
 * EXACT*: the compared extent ran long by the follower's padding - the
 * follower at 0x0202E930 is a two-halfword `ldr r3,[pc]; bx r3` long-branch
 * veneer with no label of its own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202E8D8.c \
 *       --func func_0202E8D8 --addr 0x0202E8D8 --cc 1.1p1 --thumb
 */
int func_0202E8D8(char *a0, int a1, char *a2)
{
    unsigned char i;
    unsigned char j;

    if (a1 == 0) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        int ok = 1;

        for (j = 0; j < 6; j++) {
            if (*(unsigned char *)(a0 + i * 6 + 0x22 + j)
                    != *(unsigned char *)(a2 + j)) {
                ok = 0;
                break;
            }
        }
        if (ok == 1) {
            return func_02009D1C((struct Sub020097BCObj *)a1, (struct Sub0200852CObj *)((int)a0), 0);
        }
    }
    return 0;
}









/*
 * An unlabelled forwarding leaf after func_0202E8D8's pop: a pool-word tail
 * call to func_020084F4 (the u16 pointer accessor), the caller's argument passed through
 * untouched ("ldr r3, [pc]; bx r3").  Called from the overlays only (see
 * layout/function_starts.txt).
 */
u16 *func_0202E930(void *p)
{
    return func_020084F4(p);
}









/*
 * An unlabelled forwarding leaf after func_0202E8D8's pop: a pool-word tail
 * call to func_02008534 (the u16 getter), the caller's argument passed through
 * untouched ("ldr r3, [pc]; bx r3").  Called from the overlays only (see
 * layout/function_starts.txt).
 */
u16 func_0202E938(void *p)
{
    return func_02008534(p);
}









/*
 * TU: blink_palanm.c (__FILE__ 0x020A7804, lines 0x3c and 0x3d).
 *
 * The mode chain must write `p->w14` in EVERY arm, not into a local read
 * once at the end: with the local the scheduler hoists `movs r0, #0xf`
 * above the `cmp` and saves the branch, and the tail comes out two bytes
 * short (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 */
struct CodeIn_0202E940 *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap)
{
    struct CodeIn_0202E940 *p;

    p = func_02030734(heap, sizeof(struct CodeIn_0202E940), 0, blink_palanm_File, 0x3c);
    p->buf = func_02030734(heap, (u32)a1 * 2, 0, blink_palanm_File, 0x3d);
    p->h0c = a0;
    p->h0e = a1;
    p->h10 = 0;
    p->h12 = 0;
    p->h18 = heap;
    if (a2 == 0xfffe) {
        p->w14 = 0xe;
    } else if (a2 == 0xffff) {
        p->w14 = 0x1e;
    } else if (a2 <= 3) {
        p->w14 = 0xf;
    } else {
        p->w14 = 0x1f;
    }

    return p;
}









/*
 * TU: blink_palanm.c (__FILE__ 0x020A7804, lines 0x83 and 0x84).
 */
void func_0202E9AC(struct CodeIn_0202E9AC *p, u8 *a1, u32 a2, u32 a3, u32 a4)
{
    void *tmp;
    void *handle;
    u8 *base;

    p->w00 = func_02030734(p->h18, (u32)p->h0e * 2, 0, blink_palanm_File,
                           0x83);
    p->w04 = func_02030734(p->h18, (u32)p->h0e * 2, 0, blink_palanm_File,
                           0x84);
    handle = func_02049F78(a1, a2, (u32)(&tmp), p->h18);
    base = *(u8 * *)&((struct Obj15860 *)tmp)->fC;
    func_02082D44(base + a3 * 2, p->w00, (int)((u32)p->h0e * 2));
    func_02082D44(base + a4 * 2, p->w04, (int)((u32)p->h0e * 2));
    func_020307B0(handle);
}







/*
 * A whole translation unit, matched as one byte range.
 *
 * A four-call destructor: three owned pointers and then the object
 * itself, freed in the order unk04, unk00, unk08, self. The order is the
 * source's, because this compiler does not reorder calls, so the object's
 * second field is whatever the constructor allocated first.
 *
 * Matched as a one-function unit because the two bytes of `00 00` after
 * its last instruction are the linker's inter-section fill, so `one`
 * reports EXACT* for a padding gap rather than for an unlabelled
 * follower; `tu` compares the section as laid out.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202EA20.c
 *       --addr 0x0202EA20 --thumb
 */
u32 sub_0202EA20(struct Obj0202EA20 *p)
{
    func_020307B0(p->unk04);
    func_020307B0(p->unk00);
    func_020307B0(p->unk08);
    return func_020307B0(p);
}







/*
 * blink_palanm.c: the per-frame BGR555 cross-fade.  Advances the phase word
 * at +0x10 by 0x400 (wrapping at 0x10000), takes the fade scale as
 * (table[phase >> 4 pair, second entry] + 0x1000) / 2 from the signed table
 * at 0x020A1B38, blends every pixel of the src row toward the dst row into
 * the output row, then hands the output row to func_02061CA4.
 *
 * Two facts closed it (wave 13).  The pixels are u16 locals, not s32: with
 * `s32 b` the dst channel extraction is scheduled differently (46 out).  And
 * the final pack is `(r << 10) | (bl | (g << 5))`: the channel ORed last is
 * the one the compiler evaluates FIRST, so red is blended and held, then
 * blue, then green, exactly the image's order; the left-nested
 * `(r << 10) | (g << 5) | bl` evaluates green before blue.
 *
 * EXACT* because the listing extent runs 8 bytes long: the unlabelled leaf
 * at 0x0202EB04 (src/matched/func_0202EB04.c) follows the pool word.
 */
s32_0202E818 func_0202EA40(struct Row *p)
{
    s32_0202E818 scale;
    u32 i;
    u16 a;
    u16 b;
    s32_0202E818 r;
    s32_0202E818 g;
    s32_0202E818 bl;

    if (p->phase + 0x400 >= 0x10000) {
        p->phase = p->phase - 0xFC00;
    } else {
        p->phase = p->phase + 0x400;
    }

    scale = (g_020A1B38[((p->phase >> 4) << 1) + 1] + 0x1000) / 2;

    for (i = 0; i < p->count; i++) {
        a = p->src[i];
        b = p->dst[i];
        r = (u8)(((a >> 10) & 0x1f)
                 + (((((b >> 10) & 0x1f) - ((a >> 10) & 0x1f)) * scale) >> 12));
        bl = (u8)((a & 0x1f)
                  + ((((b & 0x1f) - (a & 0x1f)) * scale) >> 12));
        g = (u8)(((a >> 5) & 0x1f)
                 + (((((b >> 5) & 0x1f) - ((a >> 5) & 0x1f)) * scale) >> 12));
        p->out[i] = (u16)((r << 10) | (bl | (g << 5)));
    }

    return func_02061CA4((void *)p->unk14, p->unk0c * 2, (u32)p->out, p->count * 2);
}







/*
 * blink_palanm.c: resets the fade phase word at +0x10 of the blink context
 * (the word func_0202EA40 advances by 0x400 per frame).  An unlabelled leaf
 * with no prologue sitting after func_0202EA40's pool word at 0x0202EB00, so
 * the listing folds it into func_0202EA40's extent (204 against the real
 * 196); seed 0x0202EB04 into layout/function_starts.txt.
 */
void func_0202EB04(struct CodeIn_0202EB04 *p)
{
    p->h10 = 0;
}







/*
 * A pool-word-and-bx tail call into an ARM SDK entry point
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), eight bytes with no
 * prologue. Its result is compared against 1 by src/matched/sub_0202EB4C.c,
 * which is the only caller.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202EB0C.c \
 *       --func sub_0202EB0C --addr 0x0202EB0C --cc 1.1p1 --thumb
 */
u32 sub_0202EB0C(void)
{
    return func_02085D3C();
}







int func_0202EB14(void)
{
    if (func_0202EB0C()) {
        if (func_02087E60()->bit0 && func_02087E60()->bit5) {
            return 1;
        }
        return 0;
    }
    return 0;
}








/*
 * Unlabelled Thumb leaf in the ARM9 module: a bare tail call.
 *
 * Addresses are Black-image addresses.
 */
void func_0202EB44(void)
{
    func_02087DC4();
}








/*
 * Neither call sets an argument register, so both callees are declared
 * with no parameters: the `blx` to the ARM helper follows a `cmp r0, #1`
 * and leaves r0 holding the 1 it was compared against, which is a
 * leftover and not an argument
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * Declaring either callee with a parameter costs an `adds r0, ...` the
 * original does not have.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202EB4C.c \
 *       --func sub_0202EB4C --addr 0x0202EB4C --cc 1.1p1 --thumb
 */
u32 sub_0202EB4C(void)
{
    if (sub_0202EB0C() == 1) {
        return func_02087DE0();
    }
    return 1;
}








/*
 * Fills an 0x54-byte structure on the stack from an ARM SDK getter and
 * copies two of its bytes out through the two pointer parameters. The
 * whole 0x54 bytes are reserved even though only offsets 2 and 3 are
 * read, so the stack object is the SDK's structure and not a pair of
 * bytes; `add r0, sp, #0` is emitted twice, once for the call and once
 * as the base of the two loads, which is what a named local rather than
 * a re-taken address looks like here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202EB60.c \
 *       --func sub_0202EB60 --addr 0x0202EB60 --cc 1.1p1 --thumb
 */
void sub_0202EB60(u8 *a, u8 *b)
{
    struct Info0202EB60 info;

    func_02087C88((struct OSOwnerInfo *)(&info));
    *a = info.unk02;
    *b = info.unk03;
}








/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * All 30 concrete bytes are right; the call to func_0202EB9C is the only open
 * site and it is blocked on `label`: the sole branch to 0x0202EB9C image-wide
 * is the one inside this function, so there is no witness outside the
 * compared range and no cut helps (the range cannot be smaller than the one
 * function holding the call).  It closes when func_0202EB9C itself gets a
 * manifest entry or a second caller appears.
 *
 * The trailing `*` is the unlabelled follower at 0x0202EB9C: the listing's
 * extent runs 32 bytes against 30 compiled because the follower carries no
 * `func_` label in the generated listing (disasm.py only labels a prologue
 * that saves lr, and this one's first instruction is not visible from here).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202EB7C.c \
 *       --func func_0202EB7C --addr 0x0202EB7C --cc 1.1p1 --thumb
 */
u32 func_0202EB7C(u32 a0, u32 a1)
{
    if (func_0200856C((const struct Sub0200852CObj *)a1) == 0) {
        return 0;
    }
    return func_0202EB9C(a0, (void *)a1);
}








/*
 * note:     the slot-table dispatcher of blink_palanm.c (look the record up;
 *           remove and notify, or insert by key under the count-capped
 *           policy).  Closed in wave 16 under 1.1p1, no pin: the notify
 *           call is written in BOTH arms of the count test.  1.1p1 then
 *           cross-jumps the two notify tails (the then-arm's `b` at
 *           0x0202EC04, reached by the inner `blo` as a jump to a jump) and
 *           no longer merges the two func_0202ED00 calls, and the a/b/v
 *           register rotation of docs/notes/pkt_0202EB9C.c.txt resolves
 *           with it.  `mark` is the +0x26 bit-3 field of
 *           docs/families/blink_palanm.h.
 */
u32 func_0202EB9C(u32 a, void *b)
{
    struct Slot *t;
    u32 n;
    u32 v;

    t = func_0200974C(a);
    n = func_0202ECB0(t, b);

    if (n != 0x14) {
        if (t[n].mark)
            v = 1;
        else
            v = 0;
        func_0202ED00(t, n);
        func_0202ED60(a, b, v);
        return 1;
    }

    v = func_0200856C(b);
    if (func_0202EC44(t, v) < 5) {
        if (func_0202EC24((const struct Ent0202EC24 *)t) >= 0x14)
            func_0202ED00(t, 0);
        func_0202ED60(a, b, 0);
    } else {
        func_0202ED00(t, func_0202EC7C(t, v));
        func_0202ED60(a, b, 0);
    }
    return 2;
}










/*
 * A whole translation unit, matched as one byte range.
 *
 * Counts the leading run of occupied slots in a 20-entry array of
 * 0x28-byte records and returns the index of the first free one, or 20.
 * No prologue at all, because it calls nothing and needs no callee-saved
 * register, so `disasm.py` gives it no label.
 *
 * The occupancy test is `lsls #0x1B` / `lsrs #0x1F` on a byte at offset
 * 0x26, which is a one-bit unsigned bitfield at bit 4 and cannot be
 * written as a mask: `& 0x10` folds to `movs`/`ands` and a shift pair
 * with unequal amounts is a narrowing cast, not a field
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md,
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * The record stride arrives as `movs r1, #0x28` / `muls` rather than a
 * scaled index because 0x28 is not a power of two.
 *
 * Matched as a one-function unit because the two bytes of `00 00` after
 * its last instruction are the linker's inter-section fill, so `one`
 * reports EXACT* for a padding gap rather than for an unlabelled
 * follower; `tu` compares the section as laid out.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202EC24.c
 *       --addr 0x0202EC24 --thumb
 */
u32 sub_0202EC24(const struct Ent0202EC24 *p)
{
    u32 i;

    for (i = 0; i < 20; i++) {
        if (p[i].unk26_4 == 0) {
            break;
        }
    }
    return i;
}








/*
 * Counts the occupied slots whose key matches, capped at five.  Same 0x28-byte
 * record as func_0202EC7C, matched next door.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EC44.c \
 *       --func func_0202EC44 --addr 0x0202EC44 --cc 1.1p1 --thumb
 */
u32 func_0202EC44(struct Slot *a0, u32 a1)
{
    u32 i;
    u32 n = 0;

    for (i = 0; i < 0x14; i++) {
        u32 v;
        if (!a0[i].flag)
            break;
        v = func_0200856C((const struct Sub0200852CObj *)(&a0[i]));
        if (v == a1)
            n++;
    }

    if (n > 5)
        n = 5;
    return n;
}








s32 func_0202EC7C(struct Slot *a0, u32 a1)
{
    u32 i;

    for (i = 0; i < 0x14; i++) {
        u32 v;
        if (!a0[i].flag) break;
        v = func_0200856C((const struct Sub0200852CObj *)(&a0[i]));
        if (v == a1) return i;
    }
    return 0x14;
}








/*
 * Finds the first occupied slot whose two keys both match the reference
 * record's, or 0x14 when there is none.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202ECB0.c \
 *       --func func_0202ECB0 --addr 0x0202ECB0 --cc 1.1p1 --thumb
 */
s32 func_0202ECB0(struct Slot *a0, void *b)
{
    u32 v0 = func_02008530(b);
    u32 v1 = func_0200856C(b);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        u32 w, x;
        if (!a0[i].flag)
            break;
        w = func_02008530((const struct Sub0200852CObj *)(&a0[i]));
        if (w == v0) {
            x = func_0200856C((const struct Sub0200852CObj *)(&a0[i]));
            if (x == v1)
                return i;
        }
    }
    return 0x14;
}








/*
 * note:     EXACT* only for the two bytes of alignment padding at
 *           0x0202ED5E.  Closed in wave 16 (the residue since wave 12 was
 *           the ldm/stm base order of the record copy): the copy goes
 *           through a named destination and a source derived from it
 *           (`dst = &t[n]; src = dst + 1; *dst = *src;`), and the flag test
 *           must NOT share the `t + n` subexpression with them, or the
 *           front end rematerialises t + n*0x28 and computes the source
 *           first.  `(t + 1)[n]` shares only the n*0x28 product, which is
 *           what the image keeps in r7.  See docs/notes/pkt_0202ED00.c.txt.
 */
void func_0202ED00(struct Slot *t, u32 n)
{
    struct Slot *dst;
    struct Slot *src;

    if (n >= 0x14)
        return;

    if (n < 0x13) {
        while (1) {
            dst = &t[n];
            src = dst + 1;
            *dst = *src;
            if (!(t + 1)[n].flag) {
                n++;
                break;
            }
            n++;
            if (n >= 0x13)
                break;
        }
    }

    while (n < 0x14) {
        t[n].flag = 0;
        n++;
    }
}









/*
 * The three-call pair at the end is the useful part: the key is read out of
 * `b` once into a named local and handed to func_02009750; that call's
 * answer decides whether func_020095E8 runs.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202ED60.c \
 *       --func func_0202ED60 --addr 0x0202ED60 --cc 1.1p1 --thumb
 */
void func_0202ED60(u32 a, void *b, u32 c)
{
    struct Slot *t = func_0200974C(a);
    u32 v;

    func_0202ED90((u8 *)t, b, c);

    v = func_0200856C(b);
    if (func_02009750((struct Sub02009470Obj *)a, v) != 0)
        func_020095E8((struct Sub02009470Obj *)a);
}









/*
 * Stores the record at `b` into slot index func_0202EC24(a), after setting
 * the bit-3 mark from `c` and the bit-4 occupied flag.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202ED90.c \
 *       --func func_0202ED90 --addr 0x0202ED90 --cc 1.1p1 --thumb
 */
void func_0202ED90(u8 *a, struct Slot *b, u32 c)
{
    u32 i = func_0202EC24((const struct Ent0202EC24 *)a);

    if (i >= 0x14)
        return;

    if (c != 0)
        b->mark = 1;
    else
        b->mark = 0;

    b->flag = 1;

    *(struct Body *)(a + i * 0x28) = *(struct Body *)b;
}








/*
 * Maps v into the band [a2+w/2, a3-w/2] of a0, 0 below it and a0 above it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EDE4.c \
 *       --func func_0202EDE4 --addr 0x0202EDE4 --cc 1.1p1 --thumb
 */
u32 func_0202EDE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 h  = a4 >> 1;
    u32 lo = a2 + h;
    u32 hi = a3 - h;
    u32 n;

    if (a1 <= lo)
        return 0;
    if (a1 >= hi)
        return a0;

    n = a1 - lo;
    return (n * (a0 << 8) / (hi - lo)) >> 8;
}








/*
 * A scaled-span helper: the span (d - c - e) is raised eight bits, scaled by
 * the rate b, divided by the total a and shifted back down; the quotient
 * joins c and half of e.
 *
 * The divide is the UNSIGNED runtime entry at 0x0209C2B0 (which
 * layout/runtime_arm9.txt names `_div_by_zero_check`, but the code there is
 * the unsigned divide entry itself; `signed / signed` emits 0x0209C0A4
 * instead).  Declared here under the front end's own name, `_u32_div_f`.
 *
 * Two spellings are load-bearing, both found by tools/permuter.py
 * (mutations `temp` then `commute(+)`, hill, budget 800):
 *   - the quotient must be bound to its own local.  Written inline, the
 *     quotient stays live in r0 and the re-read of `e` is scheduled into r1
 *     BEFORE the shift, which is the four-instruction residue the earlier
 *     note recorded (docs/notes/pkt_0202EE0C.c.txt).
 *   - the sum must associate as `(c + tmp) + (e >> 1)`.  With
 *     `(tmp + c) + (e >> 1)` the two `adds` land on the other operand order.
 * Together they put the quotient's high half in r2 and re-read `e` into r0,
 * which is exactly the original's tail.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EE0C.c \
 *       --func func_0202EE0C --addr 0x0202EE0C --cc 1.1p1 --thumb
 */
u32 func_0202EE0C(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 t = ((d - c) - e) << 8;
    u32 tmp = _u32_div_f(t * b, a) >> 8;

    return (c + tmp) + (e >> 1);
}









/*
 * Allocates and fills the 0x1c-byte time_icon record.  The heap id is the
 * fifth (stack) argument and is re-read from its slot for the second use
 * (it is also what func_0202EECC's u16 tail parameter receives), so it is
 * spelled `volatile u16`.  When the optional owner a0 is non-null the
 * record is registered with func_02030DA8 against the tag 0x0202F099 and
 * that call's result lands at +0; otherwise +0 is zeroed.
 *
 * Sibling of func_0202EE8C (docs/notes/pkt_0202EE0C.c.txt), which builds
 * the same record through the func_020311B8 allocator instead.
 */
u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap)
{
    u8 *p;

    p = (u8 *)func_02030734(heap, 0x1c, 0, g_020A7814, 0x49);
    func_0202EECC(p, a1, a2, a3, heap);
    if (owner != 0) {
        ((struct Obj06927 *)p)->f0 = func_02030DA8(owner, unk_0202F099, p, 0);
    } else {
        ((struct Obj06927 *)p)->f0 = 0;
    }
    ((struct Obj06927 *)p)->f4 = 0;
    ((struct Obj06927 *)p)->f18 = 1;
    return p;
}









/*
 *           0x0202F0A5 as a `pool` row whose only referrer sites image-wide are the
 *           pool word at 0x0202EEC8 (listed twice, once per unit listing), which lies
 *           INSIDE this function's own 0x0202EE8C..0x0202EECC extent.  A lone
 *           reference never contributes its own start, so sole-ref/data refuses it
 *           exactly as `literal` and `label` do.  No other src/matched or src/pending
 *           file declares the address either, so `matched` has nothing to offer.
 *           Contrast 0x0202F099 (line 179), the sibling tag func_0202EE30 uses: that
 *           one also has a referrer at 0x0202F034, outside any one function, plus a
 *           data-symbol declaration from two EXACT files, which is why the sibling
 *           resolves and this one cannot.  Unblocks the moment any function outside
 *           this extent references the tag, or a matched file declares it.
 *
 * Sibling of func_0202EE30 (src/matched, EXACT): the same 0x1c-byte IconRec, built
 * through the func_020311B8 node allocator instead of func_02030734.  The node is
 * stashed at +4 and +0 is zeroed, the mirror image of func_0202EE30, which registers
 * an owner into +0 and zeroes +4.  Struct layout: docs/families/time_icon.h.
 *
 * Every concrete byte of the 64-byte extent is right; the sole wildcard is the tag
 * above.  NOTE: docs/notes/pkt_0202EE0C.c.txt recorded this same C as DIFF with a
 * five-instruction scheduling residue (the saved-argument loads scheduled before the
 * copy of the call result).  That residue is GONE as of 2026-09-21: the identical
 * source now compiles to 64 bytes with 0 concrete mismatches.  The note's residue
 * table is stale; its prediction that the tag would cap the file at MATCH is not.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/func_0202EE8C.c \
 *       --func func_0202EE8C --addr 0x0202EE8C --cc 1.1p1 --thumb
 */
u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e)
{
    void *v;
    u8 *r;

    v = func_020311B8(a, unk_0202F0A5, 0x1c, 0);
    r = func_02031290(v);
    func_0202EECC(r, b, c, d, e);
    ((struct Obj08812 *)r)->f4 = (u32)v;
    ((struct Obj08812 *)r)->f0 = 0;
    ((struct Obj08812 *)r)->f18 = 1;
    return r;
}









/*
 * Fills in a freshly allocated record: the id, then a surface from the
 * caller's six size queries (width and height are each the sum of two of
 * them minus two, truncated to a byte).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EECC.c \
 *       --func func_0202EECC --addr 0x0202EECC --cc 1.1p1 --thumb
 */
void func_0202EECC(u8 *p, void *a1, u8 a2, u8 a3, u16 a4)
{
    u32 v0, v3, v2;
    u32 v6, v7;
    u32 v4;

    ((struct Obj03003 *)p)->f10 = a4;
    ((struct Obj03003 *)p)->f13 = 0;
    ((struct Obj03003 *)p)->f12 = a2;
    ((struct Obj03003 *)p)->f14 = a3;
    ((struct Obj03003 *)p)->f15 = func_020056EC(8);
    ((struct Obj03003 *)p)->fC = (u32)func_0204384C(0xC6, 0, 1, ((struct Obj03003 *)p)->f10);

    v0 = func_02045730((struct Descriptor *)((u32)a1));
    v6 = func_02045758(a1);
    v7 = func_02045738(a1);
    v3 = func_02045760(a1);
    v2 = func_02045740(a1);
    v4 = func_02045778(a1);

    func_02045374((struct Cfg *)(((struct Obj03003 *)p)->f8 = func_020450F0(v0, (u8)((v6 + v7) - 2),
                                   (u8)((v3 + v2) - 2), 2, 2, v4, 1)));
    func_02041B6C(func_02045730((struct Descriptor *)(((struct Obj03003 *)p)->f8)));
}









struct Obj *func_0202EF60(u32 heap)
{
    struct Obj *obj = func_02030734(heap, 0x1c, 0, g_020A7814, 0xa6);

    obj->unk10 = (u16)heap;
    obj->unk0C = (u32)func_0204384C(0xc6, 0, 1, obj->unk10);
    obj->unk08 = 0;
    obj->unk00 = 0;
    obj->unk04 = 0;
    return obj;
}









/*
 * func_0202EECC's twin with the record unzeroed: the surface is built the
 * same way, then the caller's handle is attached through func_02030DA8.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202EF98.c \
 *       --func func_0202EF98 --addr 0x0202EF98 --cc 1.1p1 --thumb
 */
void func_0202EF98(u8 *p, u32 a1, u32 a2, u8 a3, u8 a4)
{
    u32 v0, v3, v2;
    u32 v6, v7;
    u32 v4;

    ((struct Obj03004 *)p)->f13 = 0;
    ((struct Obj03004 *)p)->f12 = a3;
    ((struct Obj03004 *)p)->f14 = a4;
    ((struct Obj03004 *)p)->f15 = func_020056EC(8);

    v0 = func_02045730((struct Descriptor *)a2);
    v6 = func_02045758((struct Descriptor *)a2);
    v7 = func_02045738((struct Descriptor *)a2);
    v3 = func_02045760((struct Descriptor *)a2);
    v2 = func_02045740((struct Descriptor *)a2);
    v4 = func_02045778((struct Descriptor *)a2);

    func_02045374((struct Cfg *)(((struct Obj03004 *)p)->f8 = func_020450F0(v0, (u8)((v6 + v7) - 2),
                                   (u8)((v3 + v2) - 2), 2, 2, v4, 1)));
    func_02041B6C(func_02045730((struct Descriptor *)(((struct Obj03004 *)p)->f8)));

    ((struct Obj03004 *)p)->f4 = 0;
    ((struct Obj03004 *)p)->f0 = func_02030DA8((void *)a1, (u8 *)((u32)g_0202F099), (void *)((u32)p), 0);
    ((struct Obj03004 *)p)->f18 = 1;
}








/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F038.c \
 *       --func func_0202F038 --addr 0x0202F038 --cc 1.1p1 --thumb
 */
void func_0202F038(u8 *p)
{
    if (((struct Obj01809 *)p)->f0 == 0 && ((struct Obj01809 *)p)->f4 == 0) {
        func_020437AC((struct Obj020437AC *)(((struct Obj01809 *)p)->fC));
        func_020307B0(p);
        return;
    }

    ((struct Obj01809 *)p)->f18 = 0;
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01809 *)p)->f8)), ((struct Obj01809 *)p)->f12);
    func_02045334((struct Descriptor *)((struct Obj01809 *)p)->f8);
    func_020452E8((struct Descriptor *)(((struct Obj01809 *)p)->f8));
    func_020437AC((struct Obj020437AC *)(((struct Obj01809 *)p)->fC));

    if (((struct Obj01809 *)p)->f0 != 0) {
        func_02030EAC((struct Node *)(((struct Obj01809 *)p)->f0));
        func_020307B0(p);
        return;
    }

    if (((struct Obj01809 *)p)->f4 != 0)
        func_02031194((struct TcblNode *)(((struct Obj01809 *)p)->f4));
}






void sub_0202F098(void *node, u8 *work)
{
    func_0202F0B0(work);
}






void sub_0202F0A4(void *node, u8 *work)
{
    func_0202F0B0(work);
}










/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F0B0.c \
 *       --func func_0202F0B0 --addr 0x0202F0B0 --cc 1.1p1 --thumb
 */
void func_0202F0B0(u8 *p)
{
    if (((struct Obj01310 *)p)->f18 == 0)
        return;

    if (((struct Obj01310 *)p)->f13 == 0) {
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01310 *)p)->f8)), ((struct Obj01310 *)p)->f12);
        func_020439A0((struct Bmp *)(((struct Obj01310 *)p)->fC), (struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj01310 *)p)->f8)), 0,
                      (u32)((struct Obj01310 *)p)->f15 << 4, 0, 0, 0x10, 0x10, 0);
        func_02045334((struct Descriptor *)((struct Obj01310 *)p)->f8);

        ((struct Obj01310 *)p)->f13 = ((struct Obj01310 *)p)->f14;
        ((struct Obj01310 *)p)->f15 = ((struct Obj01310 *)p)->f15 + 1;

        if (((struct Obj01310 *)p)->f15 == 8)
            ((struct Obj01310 *)p)->f15 = 0;
    } else {
        ((struct Obj01310 *)p)->f13 = ((struct Obj01310 *)p)->f13 - 1;
    }
}










/*
 * Bit i of a byte array, inverted: 1 when the bit is clear.  Unlabelled leaf
 * in the 0x0202F114..0x0202F190 gap between func_0202F0B0 and func_0202F190.
 *
 * The byte index and the bit number are both `u8` locals: the original
 * truncates each with its own `lsls #0x18`/`lsrs #0x18` pair, and `i >> 3`
 * or `i & 7` folded into the shift expression loses them (the front end
 * knows both are already in range and drops the conversions).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202F114.c \
 *       --func sub_0202F114 --addr 0x0202F114 --cc 1.1p1 --thumb
 */
u32 sub_0202F114(const u8 *p, u32 i)
{
    u8 idx = (u8)(i >> 3);
    u8 bit = (u8)(i & 7);

    if ((p[idx] & (1 << bit)) != 0)
        return 0;
    return 1;
}









/*
 * First field of entry i of the 0x2E-entry table; the sibling lookups
 * sub_0202F144 (second field) and sub_0202F170 (index) share it.  All three
 * are unlabelled leaf functions in the 0x0202F114..0x0202F190 gap.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202F138.c \
 *       --func sub_0202F138 --addr 0x0202F138 --cc 1.1p1 --thumb
 */
u16 sub_0202F138(u32 i)
{
    return g_020A03C8[i].a;
}








/*
 * Second field of the entry whose first field matches the key, 0 when there
 * is none.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202F144.c \
 *       --func sub_0202F144 --addr 0x0202F144 --cc 1.1p1 --thumb
 */
u32 sub_0202F144(u32 key)
{
    s32 i;

    for (i = 0; i < 0x2E; i++) {
        if (g_020A03C8[i].a == key)
            return g_020A03C8[i].b;
    }
    return 0;
}









/*
 * Index of the entry whose first field matches, 0 when there is none.
 * Unsigned loop here, signed in sub_0202F144.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202F170.c \
 *       --func sub_0202F170 --addr 0x0202F170 --cc 1.1p1 --thumb
 */
u32 sub_0202F170(u16 key)
{
    u32 i;

    for (i = 0; i < 0x2E; i++) {
        if (g_020A03C8[i].a == key)
            return i;
    }
    return 0;
}










/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F190.c \
 *       --func func_0202F190 --addr 0x0202F190 --cc 1.1p1 --thumb
 */
void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    func_0202F1B4((u32)((void *)func_020185F0(a0)), a1, a2, a3, a4);
}









/*
 * note:     time_icon.c seven-way mode switch around a func_02017DBC /
 *           func_02017DE4 bracket.  Closed in wave 16: the 129-byte residue
 *           of docs/notes/func_0202F1B4.c.txt was NOT an allocator tie but
 *           the source's gotos.  Every case is written out in full (no
 *           shared labels) and case 2's guard carries the call run in BOTH
 *           arms; 1.1p1's own cross-jumping then produces the image's
 *           `b` into case 0's func_0202F464/func_0202F47C tail, the kept
 *           `bne; b` pair in case 2, and the head that spills the selector
 *           and holds the fifth parameter in r7.  The call at +0x58 is
 *           attested by src/matched/func_0202F47C.c (same shard).
 *           0x7532 is a plain constant.
 */
void func_0202F1B4(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 h = func_02017DBC((struct Sav *)a);

    switch (b) {
    case 0:
        func_0202F2F4((void *)a, 0);
        func_0202F30C((void *)a, d, 1);
        func_0202F41C((void *)a, (const struct Sub0200852CObj *)c, e);
        func_0202F464((void *)a);
        func_0202F47C((void *)a);
        break;
    case 1:
        func_0202F30C((void *)a, 0x7532, 1);
        func_0202F464((void *)a);
        func_0202F47C((void *)a);
        break;
    case 2:
        if (func_02018488((void *)a, (void *)c) == 1) {
            func_0202F30C((void *)a, d, 1);
            func_0202F41C((void *)a, (const struct Sub0200852CObj *)c, e);
        } else {
            func_0202F3AC((void *)a, 1);
            func_0202F30C((void *)a, d, 1);
            func_0202F41C((void *)a, (const struct Sub0200852CObj *)c, e);
        }
        func_0202F47C((void *)a);
        break;
    case 3:
    case 4:
        break;
    case 5:
        func_0202F30C((void *)a, d, 0);
        func_0202F41C((void *)a, (const struct Sub0200852CObj *)c, e);
        func_0202F47C((void *)a);
        break;
    case 6:
        func_0202F30C((void *)a, d, 1);
        break;
    }
    func_02017DE4((struct Sav *)a, h);
}










/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F27C.c \
 *       --func func_0202F27C --addr 0x0202F27C --cc 1.1p1 --thumb
 */
void func_0202F27C(void *a0)
{
    u32 buf[4];

    func_0203F4E4((struct RtcDate *)buf);

    func_02017E64(a0, 0x92, buf[0]);
    func_02017E64(a0, 0x93, buf[1]);
    func_02017E64(a0, 0x94, buf[2]);
}










/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F2AC.c \
 *       --func func_0202F2AC --addr 0x0202F2AC --cc 1.1p1 --thumb
 */
void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    if (func_02017E88(a0, 0xAA, 0) == 1)
        func_0202F358(a0, a1, a2, a3, a4, 0);
    else
        func_0202F358(a0, a1, a2, a3, a4, 1);
    func_0202F464(a0);
    func_02017E64(a0, 0x6D, 1);
}










void func_0202F2F4(void *a0, u32 a1)
{
    func_0202F358(a0, 0, 0, 0, 0, a1);
}









/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F30C.c \
 *       --func func_0202F30C --addr 0x0202F30C --cc 1.1p1 --thumb
 */
void func_0202F30C(void *a0, u32 a1, u32 a2)
{
    u32 buf[4];

    func_0203F4E4((struct RtcDate *)buf);

    if (func_02014034((u16)a1) == 1)
        func_0202F358(a0, 0x753E, buf[0], buf[1], buf[2], a2);
    else
        func_0202F358(a0, a1, buf[0], buf[1], buf[2], a2);
}









/*
 * Installs the four resource slots of one variant.  The base index is the
 * caller's u8 flag plus 0x95 for the first slot, then that same base times
 * three plus 0x8f/0x90/0x91 for the rest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F358.c \
 *       --func func_0202F358 --addr 0x0202F358 --cc 1.1p1 --thumb
 */
void func_0202F358(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u8 base = (a5 == 1);

    func_02017E64(a0, base + 0x95, a1);
    base = (u8)(base * 3);
    func_02017E64(a0, base + 0x8F, a2);
    func_02017E64(a0, base + 0x90, a3);
    func_02017E64(a0, base + 0x91, a4);
}





/*
 * Reads the four resource slots of one variant and hands them, with the
 * opposite flag, to func_0202F358.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F3AC.c \
 *       --func func_0202F3AC --addr 0x0202F3AC --cc 1.1p1 --thumb
 */
void func_0202F3AC(void *a0, u32 a1)
{
    u8 base = (a1 == 1);
    u32 x, y, z, flag, w;

    x = func_02017E88(a0, base + 0x95, 0);
    base = (u8)(base * 3);
    y = func_02017E88(a0, base + 0x8F, 0);
    z = func_02017E88(a0, base + 0x90, 0);
    w = func_02017E88(a0, base + 0x91, 0);

    flag = (a1 == 0);
    func_0202F358(a0, x, y, z, w, flag);
}




void func_0202F41C(void *a0, const struct Sub0200852CObj *a1, u32 a2)
{
    u32 t0 = func_02008510(a1, a2);
    u32 t1 = func_02008530(a1);
    u32 t2 = func_02008550(a1);

    func_02017E64(a0, 0x8d, t0);
    func_02017E64(a0, 0x9a, t2);
    func_02017E64(a0, 7, t1);
    func_02045808((struct U16Vec *)t0);
}



void func_0202F464(void *a0)
{
    u32 t0 = func_02017E88(a0, 0x9e, 0);

    func_02017E64(a0, 0x99, t0);
}




/*
 * note:     unlabelled 12-byte Thumb leaf (a tail call through a pool word
 *           to func_02017E64 with id 0x77, value 0x15) after func_0202F464;
 *           filed as the witness for func_0202F1B4's call at +0x58, the
 *           only branch to it image-wide.  Needs a seed in
 *           layout/function_starts.txt.
 */
void func_0202F47C(void *p)
{
    func_02017E64(p, 0x77, 0x15);
}



int func_0202F488(u32 a0, int a1)
{
    return func_0202F498((void *)func_020185F0((void *)a0), a1);
}










/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F498.c \
 *       --func func_0202F498 --addr 0x0202F498 --cc 1.1p1 --thumb
 */
int func_0202F498(void *a0, int a1)
{
    void *p = (void *)func_02017DBC(a0);
    int x = func_02017E88(a0, 5, 0);
    int y = func_02017E88(a0, 0x96, 0);
    int z = func_02017E88(a0, 0x6d, 0);
    int w = func_02017EB4(a0);
    int flag = 0;

    if (func_02017E88(a0, 0x8f, flag) != 0
        || func_02017E88(a0, 0x90, flag) != 0
        || func_02017E88(a0, 0x91, flag) != 0
        || func_02017E88(a0, 0x95, flag) != 0) {
        flag = 1;
    }
    func_02017DE4(a0, (unsigned int)p);

    switch (a1) {
    case 0:
        if (x == 0xfb && y == 0x753a && z == 1 && flag == 0 && w == 0) {
            return 1;
        }
        break;
    case 1:
        if (x == 0xfb && y == 0x753b && z == 1 && flag == 0 && w == 0) {
            return 1;
        }
        break;
    case 2:
        if ((unsigned)(x - 0xf3) <= 2 && y == 0x753c && w == 1 && z == 1
            && flag == 0) {
            return 1;
        }
        break;
    case 3:
        if ((unsigned)(x - 0xf3) <= 2 && y == 0x753d && w == 1 && z == 1
            && flag == 0) {
            return 1;
        }
        /* fall through */
    case 4:
        if (x == 0x287 && z == 1 && flag == 0) {
            return 1;
        }
        break;
    case 5:
        if (x == 0x288 && z == 1 && flag == 0) {
            return 1;
        }
        break;
    case 6:
        if (x == 0x289 && z == 1 && flag == 0) {
            return 1;
        }
        break;
    case 7:
        if (x == 0x1ec && z == 1 && flag == 0) {
            return 1;
        }
        break;
    }
    return 0;
}










/*
 * Promoted out of src/pending: the callee func_0202F640 became a manifest
 * entry this pass, so the second call site resolves on `matched`.
 */
void func_0202F630(u32 a, u32 b)
{
    func_0202F640(func_020185F0((void *)a), b);
}









/*
 * The two trailing pool words (0x753B / 0x753D, bare literals with no
 * relocation) are part of the compiled body, so the compared output is 72
 * bytes against the worklist's 62 code bytes; the listing extent runs to the
 * end of the packet.  All four call sites resolve on `label`.
 */
void func_0202F640(u32 a, u32 b)
{
    u32 r = func_02017DBC((struct Sav *)a);

    if (func_0202F498((void *)a, b) == 1) {
        switch (b) {
        case 0:
            func_02017E64((void *)a, 0x96, 0x753B);
            break;
        case 2:
            func_02017E64((void *)a, 0x96, 0x753D);
            break;
        }
    }
    func_02017DE4((struct Sav *)a, r);
}







/*
 * Unlabelled Thumb leaf (no entry in layout/function_starts.txt; the listing
 * shows the range as ARM). Compiled body is 80 bytes including its literal
 * pool. Witness for ov131 func_021D8784 (bl from 0x021D878C / 0x021D8794).
 * Maps an id range to a bank number (0x0202F688) and to an index inside
 * that bank (0x0202F6D8).
 */
unsigned int func_0202F688(unsigned int n) {
  if(n<0x7531) return 89;
  if(n<0x9c41) { if(n-0x7531>=14) return 89; return 92; }
  if(n<0xea61) { if(n-0x9c41>=109) return 89; return 90; }
  if(n<=65535) return 91;
  return 89;
}






/*
 * Unlabelled Thumb leaf (no entry in layout/function_starts.txt; the listing
 * shows the range as ARM). Compiled body is 84 bytes including its literal
 * pool. Witness for ov131 func_021D8784 (bl from 0x021D878C / 0x021D8794).
 * Maps an id range to a bank number (0x0202F688) and to an index inside
 * that bank (0x0202F6D8).
 */
unsigned int func_0202F6D8(unsigned int n) {
  if(n<0x7531) { if(n>=117) return 2; }
  else if(n<0x9c41) { n-=0x7531; if(n>=14) return 2; }
  else if(n<0xea61) { n-=0x9c41; if(n>=109) return 2; }
  else { if(n<=65535) { n-=0xea61; if(n>=3) return 0; } else return 2; }
  return n;
}






/*
 * note: twelve-byte tail forwarder (pool word and bx) to func_020212E4 with
 *   the second argument; witness for ov131 func_021DB140 (bl at +0x13A),
 *   whose call supplies a pointer, a halfword and a second halfword.
 */
u32 func_0202F72C(void *a, u16 b, u16 c)
{
    return func_020212E4(b);
}







int func_0202F738(void *p, int a1)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (func_020212E4((u16)func_02017E88(p, i + 0x36, 0)) != 0) {
            return 0;
        }
    }
    return 1;
}








/*
 * time_icon.c.  An unlabelled tail-call leaf (it saves nothing, so
 * disasm.py prints it as .word data): func_0202F788(0).  With
 * func_0202F774 it is the callback pair sub_0200545C (gfl_use.c boot)
 * hands to func_020316C8(7, ...).  Filed apart from func_0202F774 on
 * purpose: the only pool words naming 0x0202F789 that are outside a
 * two-function range are each other's, so as one unit neither site has a
 * witness (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 * Seed 0x0202F768 in layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F768.c \
 *       --func func_0202F768 --addr 0x0202F768 --cc 1.1p1 --thumb
 */
void func_0202F768(void)
{
    func_0202F788(0);
}








/*
 * time_icon.c.  The second unlabelled tail-call leaf of the callback pair
 * sub_0200545C hands to func_020316C8: a flag mapped to mode 2 (clear) or
 * 1 (set) for func_0202F788.  Filed apart from func_0202F768 so each pool
 * word witnesses the other (see that file).  Seed 0x0202F774.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F774.c \
 *       --func func_0202F774 --addr 0x0202F774 --cc 1.1p1 --thumb
 */
void func_0202F774(u32 on)
{
    u32 mode;

    if (on == 0) {
        mode = 2;
    } else {
        mode = 1;
    }
    func_0202F788(mode);
}








/*
 * time_icon.c: the power callback reached from func_0202F768 as
 * func_0202F788(0) (and registered through the pool word 0x0202F789 at
 * 0x0202F784).  disasm.py carried it as .word data until it was seeded in
 * layout/function_starts.txt.  It never returns: after the shutdown work it
 * spins on func_020053EC.
 */
void func_0202F788(u32 mode)
{
    func_02007084();
    func_0202F7C4(mode);
    if (func_0203CD98()) {
        func_0203CF04();
        func_0203CEAC(0);
        func_0203D0D0();
        do {
            func_0203CF5C();
        } while (!func_0203CDBC());
    }
    func_020351A0(2);
    for (;;)
        func_020053EC();
}







/*
 * The two calls to this packet's own followers (0x0202F870 at +0x7A and
 * 0x0202F940 at +0x80) are the only sites that need the `matched` class:
 * their compared range was their only `label` witness until those two files
 * existed, and they resolve the moment this shard carries them
 * (`manifest --verify --shard pkt_0202F7C4`, then re-run `one`).  Everything
 * else is `label`.
 *
 * A display/VCOUNT init: two func_0207D534 writes of 0xFFFFFFF0 to the
 * 0x0400006C and 0x0400106C registers, the engine setup calls, then three
 * read-modify-write pairs on the hardware registers at 0x04000000 (clear bits
 * 8-12, set bit 9; then clear 0xE000), 0x0400000A (clear all but 0x43, set 2),
 * 0x04000014 and 0x04000050 (both zeroed), the two packet-local sub-inits, and
 * the two registers released again.
 *
 * Note the compiler derives 0x0400000A and 0x04000014 from the pooled
 * 0x0400006C with `subs r0, #0x62` / `#0x58`, and reuses the value 4 in r6 as
 * `lsls r0, r6, #0x18` for the 0x04000000 base; both fall out of writing the
 * plain literals, so no symbol for the registers is needed.
 */
void func_0202F7C4(u32 a0)
{
    func_0207D534((volatile u16 *)0x0400006C, 0xFFFFFFF0);
    func_0207D534((volatile u16 *)0x0400106C, 0xFFFFFFF0);
    func_0207D3AC(0);
    func_0207D3E4(0);
    func_020808F4();
    func_020809A0();
    func_0207FDCC(4);
    func_0207D4B0(1, 0, 0);
    REG32(0x04000000) = (REG32(0x04000000) & 0xFFFFE0FF) | 0x200;
    REG32(0x04000000) = REG32(0x04000000) & 0xFFFF1FFF;
    REG16(0x0400000A) = (REG16(0x0400000A) & 0x43) | 4;
    REG16(0x0400000A) = REG16(0x0400000A) & 0xFFBF;
    REG32(0x04000014) = 0;
    REG16(0x04000050) = 0;
    func_0202F870();
    func_0202F940(a0);
    func_0207D534((volatile u16 *)0x0400006C, 0);
    func_0207D534((volatile u16 *)0x0400106C, 0x10);
}







/*
 * Three copies of one block: register a handle with func_0204A1BC(0x16, i, 0, 7),
 * probe it (func_02062A4C / 02062B30 / 02062A98 with a stack out-pointer), and
 * on success clear 0x20 bytes of the record's buffer through func_020862F0 and
 * fill it back through func_02082A60 with the current frame-tick from the
 * getter (func_0207E24C / func_0207DFB4).  The handle is released with
 * func_020307B0 after each block.
 *
 * The idiom that makes this EXACT: the word each block reads twice (p[4],
 * p[2]) is written as an ASSIGNMENT INSIDE the third argument of the second
 * call -- `func_02082A60(p[5], getter(), v1 = p[4])`.  mwcc evaluates the
 * arguments of a call right-to-left, so the assignment's load lands before
 * the getter call, and the value it produces is live across that call, which
 * is what puts it in r5 and forces the original's
 * `push {r3, r4, r5, lr}` frame.  Spelling the same value as a statement
 * before the call puts the load one statement early; spelling it inline in
 * both calls leaves the load where it is scheduled and loses r5 (6 bytes
 * short).  See docs/idioms/
 * an-assignment-inside-a-call-argument-pins-the-load-in-a-callee-saved-register.md
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F870.c \
 *       --func func_0202F870 --addr 0x0202F870 --cc 1.1p1 --thumb
 *   -> EXACT, 208 bytes, 20/20 relocation sites resolved (all `label`)
 */
void func_0202F870(void)
{
    u32 *p1;
    u32 *p2;
    u32 *p3;
    u32 *p4;
    u32 h;
    u32 v1;
    u32 v2;

    func_02082A7C(0, (u32)func_0207E24C(), 0x4000);
    h = func_0204A1BC(0x16, 1, 0, 7);
    if (func_02062A4C((struct NitroFileHeader *)h, (void **)(&p1)) != 0) {
        func_020862F0(p1[5], p1[4]);
        func_02082A60(p1[5], (u32)func_0207E24C(), v1 = p1[4]);
    }
    func_020307B0((void *)h);
    h = func_0204A1BC(0x16, 2, 0, 7);
    if (func_02062B30((void *)h, (void **)(&p2)) != 0) {
        func_020862F0((u32)p2 + 0xc, p2[2]);
        func_02082A60((u32)p2 + 0xc, (u32)func_0207DFB4(), v2 = p2[2]);
    }
    func_020307B0((void *)h);
    h = func_0204A1BC(0x16, 0, 0, 7);
    func_02062AD4((struct NitroFileHeader *)h, (void **)(&p4));
    if (func_02062A98((struct NitroFileHeader *)h, (void **)(&p3)) != 0) {
        func_020862F0(p3[3], 0x20);
        func_02082A60(p3[3], 0x05000000, 0x20);
    }
    func_020307B0((void *)h);
}





/*
 * EXACT* -- the inferred extent (184 bytes) runs 4 bytes past this
 * function's own 180, over the unlabelled 4-byte leaf at 0x0202F9F4
 * (`movs r0, #1; bx lr`, i.e. `return 1;`), which saves no lr and so gets no
 * label from disasm.py -- docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md.  That leaf is worth seeding
 * into layout/function_starts.txt by the integrator; it is not ours to edit.
 * The follower is also not covered by the manifest entry below, and no `tu`
 * range may span it.
 */
void func_0202F940(u32 a0)
{
    u16 *p;
    s32_0202F940 i;
    s32_0202F940 j;
    u16 v;
    u32 o1;
    u32 o2;
    u32 o3;
    u32 h;

    p = (u16 *)func_0207DFB4();
    v = 0x20;
    for (j = 4; j < 0x14; j++) {
        for (i = 1; i < 0x1f; i++) {
            p[(j << 5) + i] = v;
            v = v + 1;
        }
    }
    func_02082A48(0x7777, (u32)func_0207E24C() + 0x400, 0x3C00);
    o1 = (u32)func_02043754((void *)((u32)func_0207E24C() + 0x400), 0x1e, 0x10, 0x20, 7);
    o2 = (u32)func_0201D7EC(0x17, 0, 0, 0, 7);
    o3 = (u32)func_02045B38(0, 2, 2, 7);
    h = (u32)func_02045EC0((struct MsgBank *)o3, a0);
    func_0201C7D0((void *)o1, 0, 0, (void *)h, (void *)o2, 0x1167);
    func_02045808((struct U16Vec *)h);
    func_02045C04((struct Rec *)o3);
    func_0201D83C((void *)o2);
    func_020437AC((struct Obj020437AC *)o1);
}




int func_0202F9F4(void)
{
    return 1;
}





/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov088_id (88) and ov179_id (179) resolve as `overlay_id` (a
 *           layout overlay index, loaded by a pc-relative load of this
 *           function, reaching the id register of a known overlay loader),
 *           which was the last blocker.
 *
 * time_icon.c.  A five-state proc driver, the net_save.c shape of
 * src/pending/func_02010AC4.c: state 0 starts overlay 0x58's proc on
 * &g_02146948.f04, states 1 to 3 (re)start overlay 0xB3's proc on the
 * record, with state 2 bailing to 4 when f03 is set, and state 4 starts
 * overlay 0x58's second proc and resets to 0.
 *
 * Two pool words both name 0x02146948 (0x0202FA9C, the base of the field
 * stores, and 0x0202FAA8, the third call argument).  mwcc merges pool words
 * per symbol and CSEs the loaded address, so one symbol gives one word and
 * reuses r2 as the store base (184 -> 172 bytes, 98 out).  Two symbols at
 * the same address reproduce both words; g_02146948_arg is that second
 * name.  The state-2 test is written with the work in the `if` and the
 * bail-out after it (fall-through arm is the source order), so its
 * `*state = 4` block is the one state 3 branches back into.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F9F8.c
 *       --func func_0202F9F8 --addr 0x0202F9F8 --cc 1.1p1 --thumb
 */
int func_0202F9F8(void *unused, u32 *state)
{
    switch (*state) {
    case 0:
        func_020312CC((u32)ov088_id, (u32)d_021BD8E8, (u32)&g_02146948.f04);
        *state = 1;
        break;
    case 1:
        g_02146948.f04 = 1;
        g_02146948.f00 = 0;
        g_02146948.f02 = 1;
        g_02146948.f03 = 0;
        func_020312CC((u32)ov179_id, (u32)d_021B68D8, (u32)g_02146948_arg);
        *state = 2;
        break;
    case 2:
        if (g_02146948.f03 == 0) {
            g_02146948.f00 = 1;
            g_02146948.f03 = 0;
            func_020312CC((u32)ov179_id, (u32)d_021B68D8, (u32)g_02146948_arg);
            *state = 3;
            break;
        }
        *state = 4;
        break;
    case 3:
        g_02146948.f00 = 2;
        g_02146948.f03 = 0;
        func_020312CC((u32)ov179_id, (u32)d_021B68D8, (u32)g_02146948_arg);
        *state = 4;
        break;
    case 4:
        func_020312CC((u32)ov088_id, (u32)d_021BD574, 0);
        *state = 0;
        break;
    }
    return 0;
}
