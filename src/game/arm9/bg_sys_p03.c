/*
 * file:     bg_sys_p03.c
 * unit:     yes
 * function: func_0203F1FC, func_0203F258, func_0203F2FC, func_0203F328, func_0203F37C, func_0203F388, func_0203F3B4, func_0203F3F0, func_0203F42C, func_0203F46C, func_0203F49C, func_0203F4CC, func_0203F4E4, func_0203F4FC, func_0203F524, func_0203F540, func_0203F5FC, func_0203F63C, func_0203F684, func_0203F6D8, func_0203F734, func_0203F768, func_0203F7C4, func_0203F8F4, func_0203F9B4, func_0203FA08, func_0203FAF0, func_0203FB44, func_0203FC28, func_0203FC6C, func_0203FCA0, sub_020403F4, func_0204044C, func_0204047C, sub_02040588, sub_02040618, sub_020407E8, sub_02040804, sub_02040820, sub_02040860, sub_02040968, sub_020409B4, func_020409E0, func_02040AE0, func_02040AF0, func_02040B1C, func_02040B58, func_02040B94, func_02040C14, func_02040DA8, func_02040E78, func_02040EBC, func_02040EE0, func_02040F84, func_02041090, func_020410D0, func_020411E8, func_02041300, func_020413B0, func_020414AC, func_020414C4, func_020414EC, func_0204152C, func_02041570, func_020415B4, func_0204162C, func_02041648, func_02041664, func_02041680, func_0204169C, func_020416B8, func_020416D4, func_020419E4, func_02041A1C, sub_02041B6C, func_02041B94, func_02041EE4, func_02041F28, func_02041F6C, func_02041FB0, func_02041FF4, func_02042218, sub_020422D4, sub_02042360, func_020423D4, func_0204241C, func_02042508, func_020425B4, func_020426A0, func_020428E8, func_02042B24, func_02042D2C, func_02042E34, func_02042ED8, sub_02042FB0, sub_02042FF8, sub_02043094, func_02043130, sub_02043228, sub_02043264
 * address:  0x0203F1FC
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
 *   g_021469F8     0x021469F8  data
 *   func_02081B8C  0x02081B8C  arm
 *   sub_02088168   0x02088168  arm
 *   sub_020813D8   0x020813D8  arm
 *   sub_0208142C   0x0208142C  arm
 *   sub_020814C0   0x020814C0  arm
 *   sub_02082D44   0x02082D44  arm
 *   g_021469FC     0x021469FC  data
 *   g_02146A0C     0x02146A0C  data
 *   g_02146A1C     0x02146A1C  data
 *   g_02146A44     0x02146A44  data
 *   g_020A7E5C     0x020A7E5C  data
 *   tbl_020A08B6   0x020A08B6  data a2
 *   tbl_020A1B38   0x020A1B38  data
 *   func_020403F4  0x020403F4  arm
 *   func_02033C9C  0x02033C9C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02033CC0  0x02033CC0  arm
 *   func_02033F64  0x02033F64  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_020341F0  0x020341F0  arm
 *   sub_020416B8   0x020416B8  arm
 *   func_0203422C  0x0203422C  arm
 *   func_0207D4B0  0x0207D4B0  arm
 *   func_0207D518  0x0207D518  arm
 *   func_0204349C  0x0204349C  arm
 *   func_02043558  0x02043558  arm
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   sub_02030734   0x02030734  arm
 *   sub_020307B0   0x020307B0  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02042360  0x02042360  arm
 *   func_0203D814  0x0203D814  arm
 *   g_BgConfig     0x02146A44  data
 *   func_02040860  0x02040860  arm
 *   func_0207D59C  0x0207D59C  arm
 *   func_020834C0  0x020834C0  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02082A60  0x02082A60  arm
 *   gUnk_02146A44  0x02146A44  data
 *   func_02040968  0x02040968  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_020422D4  0x020422D4  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   func_020409B4  0x020409B4  arm
 *   ptr_02146A44   0x02146A44  data
 *   func_02041B6C  0x02041B6C  arm
 *   func_0207E1F8  0x0207E1F8  arm
 *   func_0207E24C  0x0207E24C  arm
 *   func_0207E2A0  0x0207E2A0  arm
 *   func_0207E330  0x0207E330  arm
 *   func_0207E22C  0x0207E22C  arm
 *   func_0207E280  0x0207E280  arm
 *   func_0207E2F0  0x0207E2F0  arm
 *   func_0207E388  0x0207E388  arm
 *   func_02051E74  0x02051E74  arm
 *   func_02043228  0x02043228  arm
 *   func_02043264  0x02043264  arm
 *   func_020432E4  0x020432E4  arm
 *   func_02030734  0x02030734  arm
 *   func_02082D44  0x02082D44  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207E888  0x0207E888  arm
 *   func_0207EA00  0x0207EA00  arm
 *   func_0207EB78  0x0207EB78  arm
 *   func_0207ECF0  0x0207ECF0  arm
 *   func_0207E944  0x0207E944  arm
 *   func_0207EABC  0x0207EABC  arm
 *   func_0207EC34  0x0207EC34  arm
 *   func_0207EDAC  0x0207EDAC  arm
 *   func_0207EE68  0x0207EE68  arm
 *   func_0207EF90  0x0207EF90  arm
 *   func_0207F024  0x0207F024  arm
 *   func_0207F0B8  0x0207F0B8  arm
 *   func_0207EEFC  0x0207EEFC  arm
 *   func_0207F14C  0x0207F14C  arm
 *   func_0207F1E0  0x0207F1E0  arm
 *   func_0207F274  0x0207F274  arm
 *   func_02043130_File 0x020A7E5C  data
 */
#include "../../matched/include/Obj16002.h"
#include "../../matched/include/Obj16005.h"

#define REG_DISPCNT (*(volatile u32 *)0x04000000)
#define REG16(a) (*(volatile u16 *)(a))
#define REG_BG0CNT_A  0x04000008
#define REG_BG1CNT_A  0x0400000A
#define REG_BG2CNT_A  0x0400000C
#define REG_BG3CNT_A  0x0400000E
#define REG_BG0CNT_B  0x04001008
#define REG_BG1CNT_B  0x0400100A
#define REG_BG2CNT_B  0x0400100C
#define REG_BG3CNT_B  0x0400100E
#define W(a) (*(volatile u32 *)(a))
#define R(a) (*(struct BgCnt *)(a))
#define SLOT(i) (g_02146A44->bgs[i])
struct MATHCRC16Table;
struct RTCDate;
struct RTCTime;
struct AreaMan;
struct Mtx22;
typedef unsigned char      u8;

typedef unsigned short     u16;

typedef unsigned int       u32;

typedef signed int         s32;

typedef short              s16_0203F1FC;

typedef long long          s64;

typedef unsigned long long u64;

typedef s32 fx32;

struct VecFx32 { fx32 x; fx32 y; fx32 z; };

struct Mt {
    u32 mt[624];
    s32 index;
    u32 unk_9c4;
    u32 unk_9c8;
    u8  unk_9cc[0x200];
};

struct Lcg64 {
    u64 x;
    u64 mul;
    u64 add;
};

struct Block {
    u32 unk_00;
    u32 unk_04;
    s32 unk_08;
    u8  pad_0c[0x3c];
};

struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

struct RtcTime {
    u32 hour;
    u32 minute;
    u32 second;
};

struct RtcRequest {
    u32            unk_00;
    u32            unk_04;
    s32            unk_08;
    u32            result;
    struct RtcDate date;
    struct RtcTime time;
    struct RtcDate stagedDate;
    struct RtcTime stagedTime;
};

struct RtcDate_0203F540 {
    s32 year;
    u32 month;
    s32 day;
    s32 week;
};

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct BgVramReq {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct Bg {
    void *buf;
    u32   bufSize;
    u32   unk_08;
    u32   scrollX;
    u32   scrollY;
    u8    type;
    u8    unk_15;
    u8    unk_16;
    u8    unk_17;
    u16   unk_18;
    u16   unk_1a;
    u32   unk_1c;
    u32   unk_20;
    u32   unk_24;
    u32   unk_28;
};

struct BgSys {
    u16       heapId;
    u16       unk_02;
    u16       unk_04;
    u16       unk_06;
    struct Bg bgs[8];
    void     *unk_168;
    void     *unk_16c;
    u32       unk_170[8];
    u32       unk_190[8];
    u32       unk_1b0[8];
};

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

/* TwlSDK nitro/gx/gx_bgcnt.h parameter types; only the type matters here */
typedef enum { SS0 = 0 } GXBGScrSizeText;

typedef enum { SA0 = 0 } GXBGScrSizeAffine;

typedef enum { CM0 = 0 } GXBGColorMode;

typedef enum { SB0 = 0 } GXBGScrBase;

typedef enum { CB0 = 0 } GXBGCharBase;

typedef enum { EP0 = 0 } GXBGExtPltt;

typedef enum { AO0 = 0 } GXBGAreaOver;

typedef int BOOL;

typedef signed short       s16_02040820;

struct Mtx22 { u32 w[4]; };

struct BgConfigLayer {
    char pad_00[0x1C];
    u8 mode;
    char pad_1D[0x0F];
};

struct BgCnt { u16 prio : 2; u16 rest : 14; };

typedef unsigned int u8_unused;

typedef signed short       s16;

extern u16 func_02081B8C(struct MATHCRC16Table *table, void *data, u32 dataLength);
extern void sub_02088168(u32 *buffer);
extern void sub_020813D8(void *p);
extern void sub_0208142C(void *ctx, void *buf, u32 n);
extern void sub_020814C0(void *ctx, void *out);
extern void sub_02082D44(void *in, void *out, u32 n);
extern void func_02088788(void);
extern void func_02082BCC(void *dst, u32 value, u32 size);
extern u32  func_02088944(struct RtcDate *date, struct RtcTime *time,
                          void (*done)(u32, struct RtcRequest *),
                          struct RtcRequest *arg);
extern long long func_02089004(struct RTCDate *date, struct RTCTime *time);
extern s32 func_02088F58(struct RTCDate *date);
extern int _s32_div_f(int n, int d);
extern void VEC_Subtract(const struct VecFx32 *a, const struct VecFx32 *b,
                         struct VecFx32 *out);
extern void VEC_Normalize(const struct VecFx32 *a, struct VecFx32 *out);
extern fx32 VEC_DotProduct(const struct VecFx32 *a, const struct VecFx32 *b);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern u32 func_020307B0(void *p);
extern struct AreaMan *func_02033C00(u32 size, u32 heap);
extern u32 func_02033C9C(void *a);
extern s32 func_02033CC0(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern u32 func_02033F64(u32 arena, u32 a, u32 b, u32 c);
extern s32 func_020341F0(struct AreaMan *p, u32 start, u32 len);
extern void func_0203422C(struct AreaMan *p, u32 start, s32 len);
extern u32 func_0207D4B0(u32 a, u32 b, u32 c);
extern u32 func_0207D518(u32 a);
extern void func_0204349C(void);
extern void func_02043558(void);
extern void func_020434CC(u32 handle);
extern void func_02043588(u32 handle);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02040618(u32 bgId, u32 which, u32 value);
extern void func_02042360(struct Bg *p, u32 op, u32 value);
extern void func_02042FF8(u32 bgId, u32 offset, u32 size);
extern void func_02082A48(u32 value, void *dest, u32 size);
extern void func_0203D814(u32 x, u32 y);
extern void func_02040860(u32 layer, struct Mtx22 *a, u32 b, u32 c);
extern void func_0207D59C(void *reg, struct Mtx22 *a, u32 b, u32 c, u32 x, u32 y);
extern void func_020834C0(void *dest, const void *src, u32 size);
extern void func_02082A90(void *dest, const void *src, u32 size);
extern void func_02082A60(void *dest, const void *src, u32 size);
extern void func_02040968(const void *src, void *dst, u32 mode);
extern void  func_02082AC0(u32 value, void *dst, u32 size);
extern void func_020862F0(void *, u32);
extern void func_0207E3D0(void *, u32, u32);
extern void func_0207E468(void *, u32, u32);
extern void func_020422D4(u32 mode, u8 *a, u8 *b);
extern void MIi_CpuClear16(u16 val, void *dest, u32 size);
extern void func_020409B4(u32 index);
extern void func_02041B6C(u32 bit);
extern void *func_0207E1F8(void);
extern void *func_0207E24C(void);
extern void *func_0207E2A0(void);
extern void *func_0207E330(void);
extern u32 func_0207E22C(void);
extern u32 func_0207E280(void);
extern void *func_0207E2F0(void);
extern void *func_0207E388(void);
extern void func_02051E74(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
extern void func_02043228(struct Bg *p, u32 op, u16 value);
extern void func_02043264(struct Bg *p, u32 op, u32 value);
extern void func_020432E4(struct Bg *p, u32 op, u32 value);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082D44(void *dst, const void *src, u32 size);
extern void DC_FlushRange(void *p, u32 size);
extern void func_0207E888(const void *src, u32 offset, u32 size);
extern void func_0207EA00(const void *src, u32 offset, u32 size);
extern void func_0207EB78(const void *src, u32 offset, u32 size);
extern void func_0207ECF0(const void *src, u32 offset, u32 size);
extern void func_0207E944(const void *src, u32 offset, u32 size);
extern void func_0207EABC(const void *src, u32 offset, u32 size);
extern void func_0207EC34(const void *src, u32 offset, u32 size);
extern void func_0207EDAC(const void *src, u32 offset, u32 size);
extern void func_0207EE68(const void *src, u32 offset, u32 size);
extern void func_0207EF90(const void *src, u32 offset, u32 size);
extern void func_0207F024(const void *src, u32 offset, u32 size);
extern void func_0207F0B8(const void *src, u32 offset, u32 size);
extern void func_0207EEFC(const void *src, u32 offset, u32 size);
extern void func_0207F14C(const void *src, u32 offset, u32 size);
extern void func_0207F1E0(const void *src, u32 offset, u32 size);
extern void func_0207F274(const void *src, u32 offset, u32 size);
u16 func_0203F1FC(const u8 *src, u32 len);
void func_0203F258(struct Lcg64 *out);
u32 func_0203F2FC(const u8 *p, u32 len);
void func_0203F328(u16 *p, u32 size, u32 seed);
void func_0203F37C(void *p, unsigned int size, unsigned int seed);
u16 func_0203F388(u32 *seed);
void func_0203F3B4(void);
void func_0203F3F0(void);
void func_0203F42C(u32 result, struct RtcRequest *req);
void func_0203F46C(struct RtcRequest *req);
void func_0203F49C(struct RtcDate *date, struct RtcTime *time);
void func_0203F4CC(struct RtcTime *time);
void func_0203F4E4(struct RtcDate *date);
u32 func_0203F4FC(void);
void func_0203F524(void);
s32 func_0203F540(struct RtcDate_0203F540 *d);
int func_0203F5FC(u32 x);
s16_0203F1FC func_0203F63C(u32 x);
short func_0203F684(unsigned short x);
s16_0203F1FC func_0203F6D8(s32 x);
u16 func_0203F734(int x);
int func_0203F768(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
s32 func_0203F7C4(s32 ax, s32 ay, s32 bx, s32 by, s32 cx, s32 cy);
void func_0203F8F4(u16 heapId);
void func_0203F9B4(void);
u32 func_0203FA08(u32 layer, u32 size, u32 top);
u32 func_0203FAF0(u32 a, u32 b, u32 c);
void func_0203FB44(u32 layer, u32 offset, u32 size);
void func_0203FC28(struct DispConfig *cfg);
void func_0203FC6C(const struct BgVramReq *req, u32 which);
void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
void sub_020403F4(u32 i);
void func_0204044C(u32 mode);
void func_0204047C(int idx, unsigned short val);
void sub_02040588(unsigned char which, unsigned char enable);
void sub_02040618(u32 layer, u32 a, u32 b);
u32 sub_020407E8(u32 layer);
u32 sub_02040804(u32 layer);
void sub_02040820(u32 layer, u32 a, u32 b, struct Mtx22 *c, u32 d, u32 e);
void sub_02040860(u32 layer, struct Mtx22 *a, u32 b, u32 c);
void sub_02040968(void *dest, const void *src, u32 size);
void sub_020409B4(u32 index);
void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);
void func_02040AE0(u32 index, const void *src, u32 mode);
void func_02040AF0(u32 index, const void *src, u32 mode, u32 offset);
void func_02040B1C(int index, const void *src, u32 size, u32 tile);
u32 func_02040B58(u32 index, const void *src, u32 size);
void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
void func_02040DA8(u32 idx, u32 count, u32 tile);
void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
void func_02040EBC(u32 a0, u32 a1);
u16 func_02040EE0(u8 x, u8 y, u8 code);
u16 func_02040F84(u8 x, u8 y, u8 w, u8 h);
void func_02041090(u32 index, const void *src, u8 dx, u8 dy, u8 cw, u8 ch);
void func_020410D0(u32 index, u8 dx, u8 dy, u8 cw, u8 ch, const void *src, u8 sx, u8 sy, u8 sw, u8 sh);
void func_020411E8(u32 index, u8 dx, u8 dy, u8 cw, u8 ch, const void *src, u8 sx, u8 sy, u8 sw, u8 sh);
void func_02041300(u32 layer, u16 value, u8 x0, u8 y0, u8 w, u8 h, u8 mode);
void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
asm void func_020414AC(void);
void func_020414C4(u8 idx);
void func_020414EC(u32 i);
void func_0204152C(int channel, u16 val);
void func_02041570(int channel, u16 val);
u32 func_020415B4(u32 channel);
u32 func_0204162C(int channel);
u32 func_02041648(u8 channel);
u32 func_02041664(u8 channel);
u8 func_02041680(int channel);
u8 func_0204169C(int channel);
u8 func_020416B8(int channel);
u8 func_020416D4(u32 layer);
void func_020419E4(void);
void func_02041A1C(void);
void sub_02041B6C(u32 bit);
void func_02041B94(void);
void func_02041EE4(u32 index, u32 a, u32 b);
void func_02041F28(u32 which, u32 op, u16 value);
void func_02041F6C(u32 which, u32 op, u32 value);
void func_02041FB0(u32 which, u32 op, u16 value);
u32 func_02041FF4(u32 layer, u16 x, u16 y, u16 *flags);
int func_02042218(int a0, int a1);
void sub_020422D4(u32 mode, u8 *a, u8 *b);
void sub_02042360(struct Bg *p, u32 op, u32 value);
void func_020423D4(u32 layer);
void func_0204241C(u32 layer, const void *src, u32 offset, u32 size);
void func_02042508(u32 index, const u32 *src, u32 mode, u32 size);
void func_020425B4(u32 layer, const void *src, u32 offset, u32 size);
void func_020426A0(struct Bg *s, u8 dx, u8 dy, u8 cw, u8 ch, const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);
void func_020428E8(struct Bg *s, u8 dx, u8 dy, u8 cw, u8 ch, const u8 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);
void func_02042B24(struct Bg *s, u8 dx, u8 dy, u8 cw, u8 ch, const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode);
void func_02042D2C(struct Bg *s, u16 value, u8 x0, u8 y0, u8 w, u8 h, u8 mode);
void func_02042E34(struct Bg *s, u8 value, u8 x0, u8 y0, u8 w, u8 h);
void func_02042ED8(struct Bg *s, u16 value, u8 x0, u8 y0, u8 w, u8 h, u32 mode);
void sub_02042FB0(u32 idx, u32 x, u32 y, u16 value);
void sub_02042FF8(u32 idx, u32 offset, u32 size);
void sub_02043094(u32 idx, u32 offset, u32 size);
void func_02043130(u16 flags, u8 *buf, u32 page);
void sub_02043228(struct Bg *p, u32 op, u16 value);
void sub_02043264(struct Bg *p, u32 op, u32 value);
extern u16 tbl_020A08B6[];
extern s16_0203F1FC tbl_020A1B38[];
extern struct Block g_021469FC;
extern struct Mt *g_021469F8;
extern struct RtcDate g_02146A0C;
extern struct RtcTime g_02146A1C;
extern struct BgSys *g_02146A44;
extern char g_020A7E5C[];
extern u8 func_02043130_File[];




/*
 * TU: gf_standard.c.
 *
 * Push bytes into the 0x200-byte buffer at +0x9cc of the random-number
 * block.  A length below two is padded out to two by duplicating the first
 * byte through a two-byte stack buffer.  0x9cc is out of reach of a single
 * ARM immediate, so the base is always two `add`s (+0x1cc then +0x800).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F1FC.c \
 *       --func func_0203F1FC --addr 0x0203F1FC --cc 1.1p1 --arm
 */
u16 func_0203F1FC(const u8 *src, u32 len)
{
    if (len < 2) {
        u8 pair[2];

        pair[0] = src[0];
        pair[1] = src[0];
        return func_02081B8C((struct MATHCRC16Table *)g_021469F8->unk_9cc, pair, 2);
    } else {
        return func_02081B8C((struct MATHCRC16Table *)g_021469F8->unk_9cc, (void *)src, len);
    }
}





/*
 * gf_standard.c: seed a 64-bit LCG from a hash of fresh entropy
 * (docs/families/gf_standard.h).  The output record is THREE u64s, not six
 * u32s: { x, mul = 0x5D588B656C078965, add = 0x269EC3 }, the standard
 * 64-bit LCG constants.  Written as four u32 stores the constants are
 * coloured r1/r0 instead of r0/r1 (the 8-byte residue of
 * docs/notes/pkt_0203F258.c.txt); written as two u64 stores the compiler
 * pairs each low/high half and it is byte-exact.  Reached only as a
 * function pointer (pool word 0x020056CC).
 */
void func_0203F258(struct Lcg64 *out)
{
    u8 a[8];
    u8 c[0x20];
    u8 b[0x14];
    u8 d[0x60];

    sub_02088168((u32 *)c);
    sub_020813D8(d);
    sub_0208142C(d, b, 0x14);
    sub_0208142C(d, c, 0x20);
    sub_020814C0(d, b);
    sub_02082D44(b, a, 8);
    out->x = ((struct Obj16002 *)a)->f0;
    out->mul = 0x5D588B656C078965ULL;
    out->add = 0x269EC3;
}





/*
 * Additive byte checksum.  The accumulator is declared before the index, so
 * it takes r3 and the index is rematerialised from it with `mov ip, r3`
 * rather than a second `mov #0`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F2FC.c \
 *       --func func_0203F2FC --addr 0x0203F2FC --cc 1.1p1 --arm
 */
u32 func_0203F2FC(const u8 *p, u32 len)
{
    u32 sum = 0;
    u32 i;

    for (i = 0; i < len; i++) {
        sum += p[i];
    }
    return sum;
}





/*
 * TU: gf_standard.c.
 *
 * XOR a halfword buffer against the LCG stream seeded by the third
 * argument.  The function really starts at 0x0203F328, not at the
 * 0x0203F32C that disasm.py labels: the first word is `push {r0,r1,r2,r3}`,
 * the home area that taking `&seed` forces, and the matching `add sp, sp,
 * #0x10` is what makes the epilogue pop lr and then `bx lr` instead of
 * popping pc.  `seed` lives at sp+0x20 once both pushes are done.
 *
 * EXACT*, not EXACT: disasm.py labels 0x0203F32C, so the inferred extent
 * for 0x0203F328 is the single `push {r0,r1,r2,r3}` word; the real function
 * is 0x0203F328-0x0203F37C.  0x0203F328 wants seeding into
 * layout/function_starts.txt and 0x0203F32C wants removing from it.
 *
 * func_0203F388 has exactly one caller image-wide, this one, so its only
 * route to a witness is its own manifest entry in this same shard; the
 * first `manifest --verify` after adding both files leaves this one at
 * MATCH* and the second promotes it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F328.c \
 *       --func func_0203F328 --addr 0x0203F328 --cc 1.1p1 --arm
 */
void func_0203F328(u16 *p, u32 size, u32 seed)
{
    u32 i;
    u32 n = size >> 1;

    for (i = 0; i < n; i++) {
        p[i] ^= func_0203F388(&seed);
    }
}




void func_0203F37C(void *p, unsigned int size, unsigned int seed){ func_0203F328(p, size, seed); }





/*
 * The standard 32-bit LCG (multiplier 0x41c64e6d, increment 0x6073) over a
 * caller-supplied seed word, returning the top halfword.  0x6073 is not an
 * ARM rotated immediate, so the increment is two `add`s; the `lsl`/`lsr`
 * pair after the first `lsr` is the u16 return type's truncation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F388.c \
 *       --func func_0203F388 --addr 0x0203F388 --cc 1.1p1 --arm
 */
u16 func_0203F388(u32 *seed)
{
    u32 v = *seed * 0x41c64e6d + 0x6073;

    *seed = v;
    return (u16)(v >> 16);
}





/*
 * Reset of the 0x48-byte block at 0x021469FC: zero it wholesale, then write
 * its first three words explicitly (the redundant stores are in the source;
 * the memset has already cleared them) and hand it to func_0203F46C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F3B4.c \
 *       --func func_0203F3B4 --addr 0x0203F3B4 --cc 1.1p1 --arm
 */
void func_0203F3B4(void)
{
    func_02088788();
    func_02082BCC(&g_021469FC, 0, 0x48);
    g_021469FC.unk_00 = 0;
    g_021469FC.unk_04 = 0;
    g_021469FC.unk_08 = 0;
    func_0203F46C((struct RtcRequest *)(&g_021469FC));
}





/*
 * TU: gf_standard.c.
 *
 * Per-frame tick on the block at 0x021469FC: while +0x04 is clear, count
 * frames in +0x08 and every eleventh one reset the counter and run
 * func_0203F46C.  The `ble` says +0x08 is signed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F3F0.c \
 *       --func func_0203F3F0 --addr 0x0203F3F0 --cc 1.1p1 --arm
 */
void func_0203F3F0(void)
{
    if (g_021469FC.unk_04 != 0) {
        return;
    }
    g_021469FC.unk_08++;
    if (g_021469FC.unk_08 <= 10) {
        return;
    }
    g_021469FC.unk_08 = 0;
    func_0203F46C((struct RtcRequest *)(&g_021469FC));
}





/*
 * TU: gf_standard.c.
 *
 * Completion callback for the asynchronous RTC read started by
 * func_0203F46C: publish the result code, mark the block busy, promote the
 * staging date and time at +0x2c/+0x3c into the live copies at +0x10/+0x20,
 * then clear the busy flag.  Both promotions are whole-structure
 * assignments, so each is one inlined ldm/stm pair.
 *
 * Its address reaches the image only as the pool word at 0x0203F498 inside
 * func_0203F46C, never as a branch target, so this file's manifest entry is
 * the only thing that can attest that relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F42C.c \
 *       --func func_0203F42C --addr 0x0203F42C --cc 1.1p1 --arm
 */
void func_0203F42C(u32 result, struct RtcRequest *req)
{
    req->result = result;
    req->unk_00 = 1;
    req->date = req->stagedDate;
    req->time = req->stagedTime;
    req->unk_04 = 0;
}





/*
 * TU: gf_standard.c.
 *
 * Start an asynchronous RTC read into the staging date and time at
 * +0x2c/+0x3c, with func_0203F42C as the completion callback and the block
 * itself as its argument.  The busy flag at +0x04 is raised before the call
 * and the request's return code is parked in +0x0c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F46C.c \
 *       --func func_0203F46C --addr 0x0203F46C --cc 1.1p1 --arm
 */
void func_0203F46C(struct RtcRequest *req)
{
    req->unk_04 = 1;
    req->result = func_02088944(&req->stagedDate, &req->stagedTime,
                                func_0203F42C, req);
}





/*
 * TU: gf_standard.c.
 *
 * Copy the cached RTC date and time out to the caller.  Both are whole
 * structure assignments, four words and three words, so each becomes one
 * inlined ldm/stm pair and the two out pointers have to be parked in lr and
 * ip because the copies want r0-r3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F49C.c \
 *       --func func_0203F49C --addr 0x0203F49C --cc 1.1p1 --arm
 */
void func_0203F49C(struct RtcDate *date, struct RtcTime *time)
{
    *date = g_02146A0C;
    *time = g_02146A1C;
}





/*
 * TU: gf_standard.c.  Copy the cached RTC time out; three words, so one
 * ldm/stm pair and no frame at all.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F4CC.c \
 *       --func func_0203F4CC --addr 0x0203F4CC --cc 1.1p1 --arm
 */
void func_0203F4CC(struct RtcTime *time)
{
    *time = g_02146A1C;
}





/*
 * TU: gf_standard.c.  Copy the cached RTC date out; four words, one ldm/stm
 * pair, no frame.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F4E4.c \
 *       --func func_0203F4E4 --addr 0x0203F4E4 --cc 1.1p1 --arm
 */
void func_0203F4E4(struct RtcDate *date)
{
    *date = g_02146A0C;
}





/*
 * Seconds since midnight out of the three-word global at 0x02146A1C: the
 * minutes and hours are the first two members of the source's struct and
 * come out of one `ldm`.  The sum is spelled minutes-before-hours -
 * `m * 60 + h * 3600` - and that order is what makes the hours term the
 * `mul` and the minutes term the `mla`, with the seconds member added last.
 * Subtracting only the ordering from the swapped spelling costs the `ldm`
 * and the paired multiply and adds a pool word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F4FC.c \
 *       --func func_0203F4FC --addr 0x0203F4FC --cc 1.1p1 --arm
 */
u32 func_0203F4FC(void)
{
    u32 *p = (u32 *)(0x2146A1C);

    return p[1] * 60 + p[0] * 3600 + p[2];
}





/*
 * TU: gf_standard.c.
 *
 * Refresh the cached RTC date and time: a tail call, so the callee's
 * address is a third pool word and the transfer is `bx ip`, and another
 * unlabelled leaf because nothing is pushed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F524.c \
 *       --func func_0203F524 --addr 0x0203F524 --cc 1.1p1 --arm
 */
void func_0203F524(void)
{
    func_02089004((struct RTCDate *)(&g_02146A0C), (struct RTCTime *)(&g_02146A1C));
}





/*
 * Blocking class: NONE AVAILABLE.  Every concrete byte of the body and of
 * the pool reproduces (MATCH*, 0 concrete bytes out).  The one unresolved
 * site is the ABS32 at +0xB4 naming the cumulative-days table at
 * 0x020A08B6, and it cannot be attested by any of the eight classes:
 *
 *   - `literal` / `label`: the pool word at 0x0203F5F4 is the ONLY reference
 *     to 0x020A08B6 anywhere in the image (layout/data_objects.txt line 475
 *     lists three referrers, but all three are the same 0x0203F5F4 word seen
 *     through three alternative unit cuts of the same listing), and it lies
 *     inside the compared range.  --suggest-split confirms: "witnesses image
 *     wide: 1, of them inside this range: 1", best partition 0 pieces.
 *   - every `sole-ref` sub-kind: 0x020A08B6 is HALFWORD aligned.
 *     `in_data_section()` in tools/match.py works at word granularity and
 *     returns False for it (it returns True for 0x020A08B4 and 0x020A08B8),
 *     so guard (a) of sole-ref/data and sole-ref/self both refuse before
 *     the ROM-word check is ever reached.  Rebasing the declaration to the
 *     4-aligned 0x020A08B4 and indexing [month + 1] is not a way out: it
 *     would put a different word in the pool and break the byte match, and
 *     guard (b) of sole-ref/self correctly refuses the claim because the
 *     ROM word at the site names 0x020A08B6, not 0x020A08B4.
 *
 * This promotes to EXACT with no change to the C the moment anything else
 * in the image is found to reference 0x020A08B6, or once a halfword-aligned
 * data start is recognised by the layout.
 *
 * WHAT IT IS.  Day-of-year from an RtcDate: the cumulative days before the
 * month out of the halfword table, plus the day, plus one if the month is
 * March or later and the year is a leap year.  It then copies the date to a
 * stack temp with month and day forced to 1 and runs func_02088F58 over
 * that temp and over the caller's date (the normalise/weekday pass), and
 * returns the day-of-year.
 *
 * Two typing details are load-bearing:
 *
 *   - `month` is UNSIGNED.  The guard at +0x28 is `blo`, not `blt`; with a
 *     signed `month` the whole function is otherwise identical and exactly
 *     one byte differs.
 *   - `year` is SIGNED.  All three divisions (by 4, 100 and 400) are the
 *     signed shapes: the `lsr ip, r0, #0x1f` sign words, the
 *     `rsb/adds ... ror #30` pair for %4, and the 0x51EB851F magic reused at
 *     `asr #5` for /100 and `asr #7` for /400.
 *
 * The leap test is ONE expression, `(y%4==0 && y%100!=0) || y%400==0`; note
 * the %4 failure path branches INTO the %400 test rather than around it,
 * which is the shared-exit tail-merge the disjunction gives.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203F540.c \
 *       --func func_0203F540 --addr 0x0203F540 --cc 1.1p1 --arm
 */
s32 func_0203F540(struct RtcDate_0203F540 *d)
{
    struct RtcDate_0203F540 t;
    s32 n = d->day + tbl_020A08B6[d->month];

    if (d->month >= 3) {
        if ((d->year % 4 == 0 && d->year % 100 != 0)
            || d->year % 400 == 0) {
            n++;
        }
    }

    t = *d;
    t.month = 1;
    t.day = 1;
    func_02088F58((struct RTCDate *)(&t));
    func_02088F58((struct RTCDate *)d);
    return n;
}





/*
 * Fixed-point sine lookup without the mod: angles of 360 or more return 0; otherwise the same table index as func_0203F684 (4096-entry table at 0x020A1B38, even halfword).
 */
int func_0203F5FC(u32 x)
{
    if (x >= 360) {
        return 0;
    }
    return tbl_020A1B38[2 * ((((s32)x * 0xFFFF) / 360) >> 4)];
}





/*
 * Twin of func_0203F5FC at table index 2 * i + 1 (cosine entry); angles of 360 or more return 0.
 */
s16_0203F1FC func_0203F63C(u32 x)
{
    if (x >= 360) {
        return 0;
    }
    return tbl_020A1B38[2 * ((((s32)x * 0xFFFF) / 360) >> 4) + 1];
}





/*
 * Fixed-point sine lookup: 4096-entry table at 0x020A1B38 (a flat signed
 * halfword array of interleaved pairs), indexed by (x mod 360) scaled to
 * 0xFFFF with the quotient taken against 360 again and shifted right by 4.
 * func_0203F6D8 is the identical twin at index `2 * i + 1`.
 *
 * Two details are load-bearing and cost real time:
 *
 *   - the argument is `int`, not `unsigned`.  The original opens with
 *     `lsr r1, r0, #0x1f` (the sign word) and closes the magic multiply with
 *     `add lr, r1, lr, asr #8` - the signed division shape.  The unsigned
 *     spelling compiles to `umull` against a different magic (0x6C16C16D)
 *     and is a whole-function diff.
 *   - the trailing scale is the shift `>> 4`, not a division by 16.  `/ 16`
 *     compiles to an exactness-corrected sequence (`asr r0, r2, #3` plus
 *     `add r0, r2, r0, lsr #28`), four instructions longer than the
 *     original's single `asr r1, r2, #4`.
 *
 * The 0xB60BB7 word in the pool is the compiler's own magic for /360 in the
 * `+x, asr #8` form - it is not a source-level constant and cannot be
 * matched by writing the constant out.  The table pointer resolves as
 * `literal` (x113).
 *
 * Addresses are Black-image addresses.
 */
short func_0203F684(unsigned short x)
{
    return tbl_020A1B38[2 * ((((x % 360) * 0xFFFF) / 360) >> 4)];
}





/*
 * The odd-halfword twin of func_0203F684: same signed `x % 360`, same
 * fixed-point multiply by 0xFFFF against the same 360, same `>> 4`, but the
 * table index is `2 * i + 1` instead of `2 * i`.  That difference shows up as
 * `lsl r0, r0, #1 / add r1, r0, #1 / lsl r1, r1, #1` before the `ldrsh`,
 * which is the shape of an index into a flat signed-halfword array, not of a
 * struct field access.
 *
 * EXACT*: every byte compares equal; the extent runs long only because the
 * follower is unlabelled (the listing's 144-byte extent covers this body,
 * the shared pool and the next function).  The table pointer resolves as
 * `literal` (x113).
 *
 * Addresses are Black-image addresses.
 */
s16_0203F1FC func_0203F6D8(s32 x)
{
    return tbl_020A1B38[2 * ((((x % 360) * 0xFFFF) / 360) >> 4) + 1];
}





/*
 * Unlabelled ARM leaf (no lr save) that scales x by 0xFFFF and divides by
 * 360: floor(x * 65535 / 360) for x < 360, else 0.  The unsigned guard
 * gives `movhs`, and mwcc emits the signed /360 magic (0xB60B60B7) because
 * the guard proves the product positive.  It is the witness that unblocks
 * the thumb caller func_02185D64.
 */
u16 func_0203F734(int x)
{
    if ((u32)x >= 0x168)
        return 0;
    return (u16)(x * 0xFFFF / 0x168);
}





/*
 * Blocked at MATCH on the `label`/`matched` classes: every concrete byte of
 * the body reproduces, but the PC24 at +0x18 to func_0203F7C4 has one
 * branch reference image-wide, this call, so the site has no witness outside
 * 0203F768..0203F7C4.  Filing 0x0203F7C4 as an EXACT manifest entry promotes
 * this file with no change to the C.
 *
 * The six-argument forwarder: the two stacked arguments are copied down into
 * the outgoing frame and the seventh is the divisor, a 20.12 fixed-point
 * product of itself with 0x323d rounded up by 0x800 and shifted down twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203F768.c \
 *       --func func_0203F768 --addr 0x0203F768 --cc 1.1p1 --arm
 */
int func_0203F768(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    int v = func_0203F7C4(a0, a1, a2, a3, a4, a5);
    int d = (int)(((s64)(a6 << 13) * 0x323d + 0x800) >> 12);

    return (v << 16) / (d >> 12);
}





static inline fx32 mulfx(fx32 p, fx32 q)
{
    return (fx32)(((s64)p * q + 0x800) >> 12);
}





static inline fx32 cross2(const struct VecFx32 *p, const struct VecFx32 *q)
{
    fx32 px = p->x;
    fx32 py = p->y;

    return mulfx(px, q->y) - mulfx(q->x, py);
}




/*
 * gf_standard.c: signed distance from point C to the line through A and B,
 * six plain-integer coordinates shifted into 20.12 on entry
 * (docs/families/gf_standard.h).  Closed from the 304-byte / 55-out source
 * of docs/notes/func_0203F7C4.c.txt by one change: the value tested for the
 * sign is the SUM OF ALL THREE COMPONENTS of f = (0, 0, cross_z),
 *     cross = f.x + f.y + f.z;
 * not `f.z + a.z`.  The image's `add r2, r7, #0` is f.x + f.y (the zero
 * forwarded from the two stores), started early in the gap between the two
 * FX_Mul-style products, which is what interleaves the second product's
 * loads with the first one's normalisation.  The two `static inline`
 * helpers from the note are still load-bearing.
 */
s32 func_0203F7C4(s32 ax, s32 ay, s32 bx, s32 by, s32 cx, s32 cy)
{
    struct VecFx32 a;
    struct VecFx32 b;
    struct VecFx32 d;
    struct VecFx32 f;
    struct VecFx32 c;
    fx32 cross;
    fx32 dist;
    s32  sign;

    a.x = ax << 12;  a.y = ay << 12;  a.z = 0;
    b.x = bx << 12;  b.y = by << 12;  b.z = 0;
    c.x = cx << 12;  c.y = cy << 12;  c.z = 0;

    VEC_Subtract(&a, &c, &a);
    VEC_Subtract(&b, &c, &b);

    f.x = 0;
    d.x = a.y;
    f.y = 0;
    d.y = a.x;
    d.z = 0;

    f.z = cross2(&a, &b);
    cross = f.x + f.y + f.z;

    VEC_Normalize(&d, &d);
    VEC_Subtract(&b, &a, &f);
    dist = VEC_DotProduct(&d, &f) >> 12;
    if (dist < 0) {
        dist = -dist;
    }
    if (cross <= 0) {
        sign = -1;
        dist = dist * sign;
    }
    return dist;
}





/*
 * TU: bg_sys.c.
 *
 * Constructor for the background system: one 0x1d0-byte allocation, zeroed,
 * with two 0x1000-byte scratch buffers and three parallel eight-entry
 * tables at +0x170, +0x190 and +0x1b0.  Every access after the first goes
 * through a fresh load of the global, because each call in between may
 * write it; only the `func_02082BCC` argument is forwarded from the
 * allocator's return value, since nothing has been called since the store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F8F4.c \
 *       --func func_0203F8F4 --addr 0x0203F8F4 --cc 1.1p1 --arm
 */
void func_0203F8F4(u16 heapId)
{
    s32 i;

    g_02146A44 = sub_02030734(heapId, 0x1d0, 0, g_020A7E5C, 134);
    func_02082BCC(g_02146A44, 0, 0x1d0);
    g_02146A44->heapId = heapId;
    g_02146A44->unk_04 = 0;
    g_02146A44->unk_06 = 0;
    g_02146A44->unk_168 = func_02033C00(0x1000, heapId);
    g_02146A44->unk_16c = func_02033C00(0x1000, heapId);

    for (i = 0; i < 8; i++) {
        g_02146A44->unk_170[i] = 0;
        g_02146A44->unk_190[i] = 0;
        g_02146A44->unk_1b0[i] = 0;
    }
}





/*
 * TU: bg_sys.c.
 *
 * Teardown of the background system: free the eight layers one at a time,
 * release the two buffers at +0x168 and +0x16c, free the block itself and
 * null the global.  The counter is a u8, which is what turns `i++` into the
 * `add`/`and #0xff` pair; r4 is recycled from the counter to the global's
 * address once the loop is over, and the global is re-read through it after
 * every call because the callees may write it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F9B4.c \
 *       --func func_0203F9B4 --addr 0x0203F9B4 --cc 1.1p1 --arm
 */
void func_0203F9B4(void)
{
    u8 i;

    for (i = 0; i < 8; i++) {
        func_020403F4(i);
    }
    func_02033C9C(g_02146A44->unk_168);
    func_02033C9C(g_02146A44->unk_16c);
    func_020307B0(g_02146A44);
    g_02146A44 = 0;
}





/*
 * Allocate a run of tiles for a layer in its arena, bottom-up (top == 0,
 * func_02033CC0) or top-down (func_02033F64), and return the tile index of
 * the run relative to the layer's tile base, or -1.  Closed in wave 11:
 * the arena base is selected into a local BEFORE the direction test, the
 * round-up flag is `f = (size % t != 0)` (remainder taken first, then the
 * quotient), and the tile stride `t` is an int local (tools/permuter.py,
 * type:l(t:u32->int)); every divide stays unsigned because each dividend
 * is u32.
 */
u32 func_0203FA08(u32 layer, u32 size, u32 top)
{
    int t = func_020416B8(layer & 0xff);
    struct BgSys *g = g_02146A44;
    u32 d1 = g->unk_170[layer] / t;
    u32 d2 = g->unk_1b0[layer] / t;
    u32 f;
    u32 n, r, base;

    f = (size % t != 0);
    n = size / t;
    base = (layer < 4) ? (u32)g->unk_168 : (u32)g->unk_16c;
    if (top == 0)
        r = func_02033CC0((struct AreaMan *)base, d1, d2, n + f);
    else
        r = func_02033F64(base, d1 + d2 - 1, d2, n + f);
    if (r == 0xFFFFFFFF)
        return 0xFFFFFFFF;
    return (r * t - g_02146A44->unk_170[layer]) / t;
}





u32 func_0203FAF0(u32 a, u32 b, u32 c)
{
    u32 d = func_020416B8(a & 0xff);

    d = g_02146A44->unk_170[a] / d;
    return func_020341F0((struct AreaMan *)((a < 4) ? g_02146A44->unk_168 : g_02146A44->unk_16c),
                  d + b, c);
}





/*
 * TU: bg_sys.c.
 *
 * Release half of the pair whose reserve half is sub_02042FF8: same arena
 * selection by layer index (0-3 at +0x168, 4-7 at +0x16c, anything else a
 * no-op) and the same round-up of a byte length to arena units, but the unit
 * here is the layer's own tile stride from sub_020416B8 rather than the
 * constant 32, so both the bias and the round-up are real divisions.
 *
 * Codegen note: the biased start index must be written back into the
 * `offset` parameter rather than into a fresh local.  A fresh local is
 * coalesced onto a different callee-saved register and shuffles the whole
 * r5/r6/r7 assignment (14 bytes wrong, same instructions); see
 * docs/idioms/reassigning-a-parameter-keeps-its-register.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203FB44.c \
 *       --func func_0203FB44 --addr 0x0203FB44 --cc 1.1p1 --arm
 */
void func_0203FB44(u32 layer, u32 offset, u32 size)
{
    u32           unit = func_020416B8((u8)layer);
    struct BgSys *p    = g_02146A44;

    offset = (p->unk_170[layer] + offset * unit) / unit;

    switch (layer) {
    case 0:
    case 1:
    case 2:
    case 3:
        func_0203422C(p->unk_168, offset,
                      ((size % unit) ? 1 : 0) + size / unit);
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        func_0203422C(p->unk_16c, offset,
                      ((size % unit) ? 1 : 0) + size / unit);
        break;
    }
}





/*
 * TU: bg_sys.c (the initialiser at 0x0203FCA0 is the next function up).
 *
 * Bring the display back up from a saved four-word config block, then clear
 * REG_DISPCNT's two mode fields.  The two clears are separate read-modify-
 * writes in the original, each reloading through the base kept in r1, so
 * they are two statements in the source and not one masked store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203FC28.c \
 *       --func func_0203FC28 --addr 0x0203FC28 --cc 1.1p1 --arm
 */
void func_0203FC28(struct DispConfig *cfg)
{
    func_0207D4B0(cfg->unk_00, cfg->unk_04, cfg->unk_0c);
    func_0207D518(cfg->unk_08);
    REG_DISPCNT &= ~0x38000000;
    REG_DISPCNT &= ~0x07000000;
    func_0204349C();
    func_02043558();
}





/*
 * bg_sys.c, the two-way forwarder that sits immediately above
 * func_0203FCA0.  Both arms are a single nested call whose result is
 * handed straight on and then dropped, so the function is void and
 * needs no callee-saved register: `push {r3, lr}` is the eight-byte
 * stack alignment pad, not a saved argument.
 *
 * The `ldm r2, {r0, r1}` in the first arm is two adjacent fields loaded
 * as two consecutive arguments, not a struct copy; writing the two
 * field reads as separate arguments to the same call is what folds them
 * into the load-multiple.
 */
void func_0203FC6C(const struct BgVramReq *req, u32 which)
{
    if (which == 0) {
        func_020434CC(func_0207D4B0(req->unk_00, req->unk_04, req->unk_0c));
    } else {
        func_02043588(func_0207D518(req->unk_08));
    }
}



static inline void G2_SetBG0Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG0CNT_A) = (u16)((REG16(REG_BG0CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}



static inline void G2_SetBG0Priority(int priority)
{
    REG16(REG_BG0CNT_A) = (u16)((REG16(REG_BG0CNT_A) & ~3) | (priority << 0));
}



static inline void G2_BG0Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG0CNT_A) |= 0x40;
    } else {
        REG16(REG_BG0CNT_A) &= ~0x40;
    }
}



static inline void G2_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG1CNT_A) = (u16)((REG16(REG_BG1CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}



static inline void G2_SetBG1Priority(int priority)
{
    REG16(REG_BG1CNT_A) = (u16)((REG16(REG_BG1CNT_A) & ~3) | (priority << 0));
}



static inline void G2_BG1Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG1CNT_A) |= 0x40;
    } else {
        REG16(REG_BG1CNT_A) &= ~0x40;
    }
}



static inline void G2_SetBG2ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}



static inline void G2_SetBG2ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}



static inline void G2_SetBG2ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}



static inline void G2_SetBG2Priority(int priority)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & ~3) | (priority << 0));
}



static inline void G2_BG2Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG2CNT_A) |= 0x40;
    } else {
        REG16(REG_BG2CNT_A) &= ~0x40;
    }
}



static inline void G2_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}



static inline void G2_SetBG3ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}



static inline void G2_SetBG3ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}



static inline void G2_SetBG3Priority(int priority)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & ~3) | (priority << 0));
}



static inline void G2_BG3Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG3CNT_A) |= 0x40;
    } else {
        REG16(REG_BG3CNT_A) &= ~0x40;
    }
}



static inline void G2S_SetBG0Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG0CNT_B) = (u16)((REG16(REG_BG0CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}



static inline void G2S_SetBG0Priority(int priority)
{
    REG16(REG_BG0CNT_B) = (u16)((REG16(REG_BG0CNT_B) & ~3) | (priority << 0));
}



static inline void G2S_BG0Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG0CNT_B) |= 0x40;
    } else {
        REG16(REG_BG0CNT_B) &= ~0x40;
    }
}



static inline void G2S_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG1CNT_B) = (u16)((REG16(REG_BG1CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}



static inline void G2S_SetBG1Priority(int priority)
{
    REG16(REG_BG1CNT_B) = (u16)((REG16(REG_BG1CNT_B) & ~3) | (priority << 0));
}



static inline void G2S_BG1Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG1CNT_B) |= 0x40;
    } else {
        REG16(REG_BG1CNT_B) &= ~0x40;
    }
}



static inline void G2S_SetBG2ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}



static inline void G2S_SetBG2ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}



static inline void G2S_SetBG2ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}



static inline void G2S_SetBG2Priority(int priority)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & ~3) | (priority << 0));
}



static inline void G2S_BG2Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG2CNT_B) |= 0x40;
    } else {
        REG16(REG_BG2CNT_B) &= ~0x40;
    }
}



static inline void G2S_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}



static inline void G2S_SetBG3ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}



static inline void G2S_SetBG3ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}



static inline void G2S_SetBG3Priority(int priority)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & ~3) | (priority << 0));
}



static inline void G2S_BG3Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG3CNT_B) |= 0x40;
    } else {
        REG16(REG_BG3CNT_B) &= ~0x40;
    }
}



/*
 * bg_sys.c: initialise one BG layer from its template.  Program BGxCNT of
 * layer bgId (0..3 main, 4..7 sub) through the TwlSDK gx_bgcnt.h inline
 * setters (text layers 0/1/4/5 always; 2/3/6/7 by type: text, affine, or the
 * game's type-2 form, whose OR order is charBase before screenBase and which
 * carries no 0x80 ext-mode bit, so it is not G2_SetBG2Control256x16Pltt),
 * then priority and mosaic, then the layer record in g_02146A44.
 *
 * Closed in wave 16 by the SDK-inline lever with the SDK's ENUM parameter
 * types (GXBGScrSizeText, GXBGColorMode, GXBGScrBase, GXBGCharBase,
 * GXBGExtPltt, GXBGAreaOver).  The same inlines with int parameters give
 * 1860 bytes, 1171 out (the type-0 store cross-jumped into the shared tail);
 * see docs/notes/func_0203FCA0.c.txt for the earlier record.
 */
void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type)
{
    u32 ss = func_02042218(tmpl->unk_10, type);

    switch (bgId) {
    case 0:
        G2_SetBG0Control(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13, tmpl->unk_18);
        G2_SetBG0Priority(tmpl->unk_19);
        G2_BG0Mosaic(tmpl->unk_1c);
        break;
    case 1:
        G2_SetBG1Control(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13, tmpl->unk_18);
        G2_SetBG1Priority(tmpl->unk_19);
        G2_BG1Mosaic(tmpl->unk_1c);
        break;
    case 2:
        switch (type) {
        case 0:
        default:
            G2_SetBG2ControlText(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13);
            break;
        case 1:
            G2_SetBG2ControlAffine(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        case 2:
            G2_SetBG2ControlType2(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        }
        G2_SetBG2Priority(tmpl->unk_19);
        G2_BG2Mosaic(tmpl->unk_1c);
        break;
    case 3:
        switch (type) {
        case 0:
        default:
            G2_SetBG3ControlText(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13);
            break;
        case 1:
            G2_SetBG3ControlAffine(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        case 2:
            G2_SetBG3ControlType2(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        }
        G2_SetBG3Priority(tmpl->unk_19);
        G2_BG3Mosaic(tmpl->unk_1c);
        break;
    case 4:
        G2S_SetBG0Control(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13, tmpl->unk_18);
        G2S_SetBG0Priority(tmpl->unk_19);
        G2S_BG0Mosaic(tmpl->unk_1c);
        break;
    case 5:
        G2S_SetBG1Control(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13, tmpl->unk_18);
        G2S_SetBG1Priority(tmpl->unk_19);
        G2S_BG1Mosaic(tmpl->unk_1c);
        break;
    case 6:
        switch (type) {
        case 0:
        default:
            G2S_SetBG2ControlText(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13);
            break;
        case 1:
            G2S_SetBG2ControlAffine(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        case 2:
            G2S_SetBG2ControlType2(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        }
        G2S_SetBG2Priority(tmpl->unk_19);
        G2S_BG2Mosaic(tmpl->unk_1c);
        break;
    case 7:
        switch (type) {
        case 0:
        default:
            G2S_SetBG3ControlText(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13);
            break;
        case 1:
            G2S_SetBG3ControlAffine(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        case 2:
            G2S_SetBG3ControlType2(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        }
        G2S_SetBG3Priority(tmpl->unk_19);
        G2S_BG3Mosaic(tmpl->unk_1c);
        break;
    }

    g_02146A44->bgs[bgId].unk_18 = 0;
    g_02146A44->bgs[bgId].unk_1c = 0x1000;
    g_02146A44->bgs[bgId].unk_20 = 0x1000;
    g_02146A44->bgs[bgId].unk_24 = 0;
    g_02146A44->bgs[bgId].unk_28 = 0;

    if (tmpl->bufSize != 0) {
        g_02146A44->bgs[bgId].buf = sub_02030734(g_02146A44->heapId,
                                                 tmpl->bufSize, 0,
                                                 g_020A7E5C, 0x231);
        func_02082A48(0, g_02146A44->bgs[bgId].buf, tmpl->bufSize);
        g_02146A44->bgs[bgId].bufSize = tmpl->bufSize;
        g_02146A44->bgs[bgId].unk_08 = tmpl->unk_0c;
    } else {
        g_02146A44->bgs[bgId].buf = 0;
        g_02146A44->bgs[bgId].bufSize = 0;
        g_02146A44->bgs[bgId].unk_08 = 0;
    }

    g_02146A44->bgs[bgId].unk_15 = tmpl->unk_10;
    g_02146A44->bgs[bgId].type = (u8)type;
    g_02146A44->bgs[bgId].unk_16 = tmpl->unk_11;

    if (type == 0 && tmpl->unk_11 == 0) {
        g_02146A44->bgs[bgId].unk_17 = 0x20;
    } else {
        g_02146A44->bgs[bgId].unk_17 = 0x40;
    }

    func_02040618(bgId, 0, tmpl->unk_00);
    func_02040618(bgId, 3, tmpl->unk_04);
    func_020423D4(bgId);

    g_02146A44->unk_170[bgId] = tmpl->unk_13 << 14;
    g_02146A44->unk_190[bgId] = tmpl->unk_12 << 11;
    g_02146A44->unk_1b0[bgId] = tmpl->unk_14;

    func_02042FF8(bgId, 0, tmpl->bufSize);
}






/*
 * Release the payload of one entry of the 0x2c-byte table hanging off the
 * singleton pointer at 0x02146A44: if the pointer at +8 is set,
 * unregister it through sub_02043094 (passing the slot index and the
 * cookie at +0xc), free it, and NULL the slot.
 *
 * The slot index arrives in r0 and is never moved, so it is still there
 * as sub_02043094's first argument after the multiply.  The zero used for
 * sub_02043094's second argument and for the final store is materialised
 * once in r6 and shared
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 * Everything after the first call re-reads the global and re-indexes,
 * because the calls may store to it.
 *
 * Byte-correct, capped at MATCH: sub_02043094 is called from this one
 * site and nowhere else in the image, so its PC24 has no outside witness
 * of any class.  --suggest-split cannot help, the site is inside the one
 * function.  It unsticks when 0x02043094 is itself decompiled to EXACT
 * or a second caller turns up in an overlay.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020403F4.c \
 *       --func sub_020403F4 --addr 0x020403F4 --cc 1.1p1 --arm
 */
void sub_020403F4(u32 i)
{
    if (g_02146A44->bgs[i].buf == 0) {
        return;
    }
    sub_02043094(i, 0, g_02146A44->bgs[i].bufSize);
    func_020307B0(g_02146A44->bgs[i].buf);
    g_02146A44->bgs[i].buf = 0;
}





/*
 * Set the two low bits of DISPCNT (0x04000008) to the incoming mode, after
 * asking func_020434DC for the display to be brought up in mode 1.  The
 * register is a cast constant, not a relocation: its address is the pool
 * word at the end of this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204044C.c \
 *       --func func_0204044C --addr 0x0204044C --cc 1.1p1 --arm
 */
void func_0204044C(u32 mode)
{
    func_020434DC(1, 1);
    *(volatile u16 *)0x04000008 =
        (*(volatile u16 *)0x04000008 & ~3) | mode;
}





/*
 * Unlabelled ARM leaf: a two-to-four entry register write-back.  idx 0..7
 * selects one of eight volatile 16-bit MMIO registers (two banks of four,
 * 0x04000008..0x0400000E and 0x04001008..0x0400100E); each case clears the
 * low two bits of the register and ORs in the low bits of val.  idx > 7 is a
 * no-op (`bx lr` / `pop {r3,pc}` in the follower).
 *
 * The constants are absolute hardware addresses, so they are plain pool words
 * with no relocation.
 */
void func_0204047C(int idx, unsigned short val)
{
    volatile unsigned short *p;

    switch (idx) {
    case 0:
        p = (volatile unsigned short *)0x04000008;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 1:
        p = (volatile unsigned short *)0x0400000A;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 2:
        p = (volatile unsigned short *)0x0400000C;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 3:
        p = (volatile unsigned short *)0x0400000E;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 4:
        p = (volatile unsigned short *)0x04001008;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 5:
        p = (volatile unsigned short *)0x0400100A;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 6:
        p = (volatile unsigned short *)0x0400100C;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 7:
        p = (volatile unsigned short *)0x0400100E;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    }
}





/*
 * Eight-way dispatch turning a small selector into a one-hot plane mask for
 * one of the two 2D engines: selectors 0..3 go to the engine-A visible-plane
 * toggle at func_020434DC with masks 1/2/4/8 and selectors 4..7 to the
 * engine-B toggle at func_02043598 with the same four.  The on/off flag is
 * the second parameter and is forwarded untouched in r1, which is why no
 * argument setup other than the mask appears in any arm.  The ARM form
 * of the dense switch is `cmp #7` plus `addls pc, pc, r0, lsl #2` over a
 * run of eight branches, with the out-of-range case falling straight into
 * the epilogue.
 */
void sub_02040588(unsigned char which, unsigned char enable)
{
    switch (which) {
    case 0:
        func_020434DC(1, enable);
        break;
    case 1:
        func_020434DC(2, enable);
        break;
    case 2:
        func_020434DC(4, enable);
        break;
    case 3:
        func_020434DC(8, enable);
        break;
    case 4:
        func_02043598(1, enable);
        break;
    case 5:
        func_02043598(2, enable);
        break;
    case 6:
        func_02043598(4, enable);
        break;
    case 7:
        func_02043598(8, enable);
        break;
    }
}





/*
 * The per-layer scroll register flush.  Closed in wave 11 by two facts:
 * func_0203D814 takes the layer's scroll pair (x, y) as its two arguments
 * (the case-1 arm keeps r0/r1 live across the register write for the call,
 * as in func_02041B94), and scrollX is read before scrollY.  The star is the
 * unlabelled follower sub_020407E8 (already EXACT in unit_020407E8.c); the
 * true extent is 464 bytes, ending at 0x020407E8.
 */
void sub_02040618(u32 layer, u32 a, u32 b)
{
    u32 mask = 0x1ff;
    u32 hmask = mask << 16;
    u32 x, y;

    func_02042360(&g_02146A44->bgs[layer], a, b);

    x = g_02146A44->bgs[layer].scrollX;
    y = g_02146A44->bgs[layer].scrollY;

    switch (layer) {
    case 0:
        W(0x04000010) = (x & mask) | (hmask & (y << 16));
        break;
    case 1:
        W(0x04000014) = (x & mask) | (hmask & (y << 16));
        func_0203D814(x, y);
        break;
    case 2:
        if (g_02146A44->bgs[2].type == 0) {
            W(0x04000018) = (x & mask) | (hmask & (y << 16));
        } else {
            func_020423D4(2);
        }
        break;
    case 3:
        if (g_02146A44->bgs[3].type == 0) {
            W(0x0400001c) = (x & mask) | (hmask & (y << 16));
        } else {
            func_020423D4(3);
        }
        break;
    case 4:
        W(0x04001010) = (x & mask) | (hmask & (y << 16));
        break;
    case 5:
        W(0x04001014) = (x & mask) | (hmask & (y << 16));
        break;
    case 6:
        if (g_02146A44->bgs[6].type == 0) {
            W(0x04001018) = (x & mask) | (hmask & (y << 16));
        } else {
            func_020423D4(6);
        }
        break;
    case 7:
        if (g_02146A44->bgs[7].type == 0) {
            W(0x0400101c) = (x & mask) | (hmask & (y << 16));
        } else {
            func_020423D4(7);
        }
        break;
    }
}





/*
 * The two scroll-register accessors for the BG configuration table, both of
 * them leaf functions that save nothing and therefore carry no `func_` label
 * in the listing at all: they print as an anonymous run of `.word`s between
 * the literal pool of sub_02040618 and the next labelled function at
 * 0x02040820 (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * They were found by sweeping the address range, not by reading labels.
 *
 * Both index the same 0x2C-byte per-layer record hanging off the single
 * pointer at 0x02146A44, and return the horizontal (+0x14) and vertical
 * (+0x18) scroll values that sub_02040618 flushes to the hardware.  The
 * `mla r1, r0, r1, r2` is the array subscript: 0x2C is not a shift, so the
 * scale is a real multiply folded into the base add.
 *
 * Kept as one unit rather than two files because the pair is contiguous and
 * the whole 56-byte range, both literal pools included, reproduces exactly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020407E8.c \
 *       --addr 0x020407E8 --arm --cc 1.1p1
 */
u32 sub_020407E8(u32 layer)
{
    return g_02146A44->bgs[layer].scrollX;
}




u32 sub_02040804(u32 layer)
{
    return g_02146A44->bgs[layer].scrollY;
}





void sub_02040820(u32 layer, u32 a, u32 b, struct Mtx22 *c, u32 d, u32 e)
{
    func_02042360(&g_02146A44->bgs[layer], a, b);
    func_02040860(layer, c, d, e);
}





/*
 * The affine half of the BG scroll module: push a layer's transform, plus
 * its current scroll position, into that layer's hardware parameter block.
 * Only the four affine-capable layers have one, so only cases 2, 3, 6 and 7
 * do anything: main engine BG2 and BG3 at 0x04000020 and 0x04000030, sub
 * engine BG2 and BG3 at 0x04001020 and 0x04001030.  Cases 0, 1, 4, 5 and
 * everything above 7 share the exit.
 *
 * The empty arms are load-bearing, not decoration: the dense jump table
 * only exists because the case labels run from 0 without gaps
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).  Written as
 * four cases the compiler would emit a comparison chain instead.
 *
 * Unlike sub_02040618, the subscript here stays the variable `layer` in
 * every arm rather than the arm's own case constant.  That is what the
 * `mla lr, r0, ip, lr` inside each arm says: the multiply is still live,
 * so the index cannot have been a literal.  The four arms therefore differ
 * only in one pooled register address, which is also why all four share the
 * single 0x02146A44 pool word at the end of the function.
 *
 * The transform arguments are this function's own parameters 2 to 4, passed
 * straight through untouched (nothing in any arm writes r1, r2 or r3), and
 * the scroll pair goes on the stack as arguments 5 and 6.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02040860.c \
 *       --func sub_02040860 --addr 0x02040860 --cc 1.1p1 --arm
 */
void sub_02040860(u32 layer, struct Mtx22 *a, u32 b, u32 c)
{
    switch (layer) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        func_0207D59C((void *)0x04000020, a, b, c,
                      g_02146A44->bgs[layer].scrollX, g_02146A44->bgs[layer].scrollY);
        break;
    case 3:
        func_0207D59C((void *)0x04000030, a, b, c,
                      g_02146A44->bgs[layer].scrollX, g_02146A44->bgs[layer].scrollY);
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        func_0207D59C((void *)0x04001020, a, b, c,
                      g_02146A44->bgs[layer].scrollX, g_02146A44->bgs[layer].scrollY);
        break;
    case 7:
        func_0207D59C((void *)0x04001030, a, b, c,
                      g_02146A44->bgs[layer].scrollX, g_02146A44->bgs[layer].scrollY);
        break;
    }
}





void sub_02040968(void *dest, const void *src, u32 size)
{
    if (size == 0) {
        func_020834C0(dest, src, size);
        return;
    }

    if (((u32)dest & 3) == 0 && ((u32)src & 3) == 0 && ((u16)size % 4) == 0) {
        func_02082A90(dest, src, size);
        return;
    }

    func_02082A60(dest, src, size);
}





/*
 * Indexes the 0x2c-byte entry array reached through the pointer at
 * 0x02146A44 and tail-calls the worker at 0x020409E0 with three fields of
 * that entry plus the index itself.  The tail call is the usual pool word
 * and `bx ip`; ip rather than r3 is used so all four argument registers
 * survive.
 */
void sub_020409B4(u32 index)
{
    

    func_020409E0(index, g_02146A44->bgs[index].buf, g_02146A44->bgs[index].bufSize, g_02146A44->bgs[index].unk_08);
}





/*
 * Push a tile source into slot `index` of the 0x2c-byte table behind
 * 0x02146A44.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020409E0.c \
 *       --func func_020409E0 --addr 0x020409E0 --cc 1.1p1 --arm
 */
void func_020409E0(u32 index, const void *src, u32 mode, u32 offset)
{
    if (mode == 0) {
        void *tiles = g_02146A44->bgs[index].buf;

        if (tiles != 0) {
            func_02040968(src, tiles, mode);
            func_0204241C(index, tiles, g_02146A44->bgs[index].unk_08 * 2,
                          g_02146A44->bgs[index].bufSize);
        } else {
            u32   size = *(const u32 *)&((struct Obj16005 *)src)->f0 >> 8;
            void *buf = sub_02030734(
                (u16)((g_02146A44->heapId & 0x7fff) | 0x8000), size, 0,
                g_020A7E5C, 1252);

            func_02040968(src, buf, mode);
            func_0204241C(index, buf, offset * 2, size);
            func_020307B0(buf);
        }
    } else {
        func_0204241C(index, src, offset * 2, mode);
    }
}





/*
 * A four-instruction forwarder that binds the tile offset of func_02040AF0
 * to zero.  It has no label in the listing: the prologue saves nothing, so
 * disasm.py's rule does not see it and the whole function reads as part of
 * func_020409E0's literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  This is
 * also why func_020409E0 verifies EXACT*, its inferred extent running on
 * to 0x02040AF0; 0x02040AE0 wants seeding into
 * layout/function_starts.txt.
 *
 * The tail call is the usual pool word and `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), through ip rather than
 * r3 so the fourth argument register is still free to carry the zero
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040AE0.c \
 *       --func func_02040AE0 --addr 0x02040AE0 --cc 1.1p1 --arm
 */
void func_02040AE0(u32 index, const void *src, u32 mode)
{
    func_02040AF0(index, src, mode, 0);
}





/*
 * Decode a tile source straight into slot `index`'s tile buffer at a tile
 * offset.  The offset scales by two, so the buffer is addressed in
 * halfwords here even though func_020409E0 treats the same field as an
 * opaque destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040AF0.c \
 *       --func func_02040AF0 --addr 0x02040AF0 --cc 1.1p1 --arm
 */
void func_02040AF0(u32 index, const void *src, u32 mode, u32 offset)
{
    func_02040968(src, (u16 *)g_02146A44->bgs[index].buf + offset, mode);
}





/*
 * Forward a tile upload, scaling the destination tile index by the slot's
 * tile size: the byte at +0x1e of the 0x2c-byte slot record is zero for
 * 4bpp tiles (32 bytes each, shift 5) and non-zero for 8bpp (64 bytes,
 * shift 6).  The zero arm is the fall-through, so it is the `if` body
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040B1C.c \
 *       --func func_02040B1C --addr 0x02040B1C --cc 1.1p1 --arm
 */
void func_02040B1C(int index, const void *src, u32 size, u32 tile)
{
    if (g_02146A44->bgs[index].unk_16 == 0) {
        func_02042508(index, src, size, tile * 32);
    } else {
        func_02042508(index, src, size, tile * 64);
    }
}





/*
 * Reserve a run of tiles for slot `index`, then upload into it and hand the
 * caller the tile index it got.  The reservation is in tiles and the upload
 * offset in bytes, hence the fixed 32-byte (4bpp) scale; unlike
 * func_02040B1C this one does not consult the slot's depth byte.
 *
 * The `and r0, r7, #0xff` is the truncation at the second call, not a cast
 * in this function's own arithmetic: func_02042508 takes the slot index as
 * u8 while this function takes it as u32.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040B58.c \
 *       --func func_02040B58 --addr 0x02040B58 --cc 1.1p1 --arm
 */
u32 func_02040B58(u32 index, const void *src, u32 size)
{
    u32 tile = func_0203FA08(index, size, 0);

    func_02042508((u8)index, src, size, tile * 32);
    return tile;
}





/*
 * TU: bg_sys.c.
 *
 * Fill a run of the layer's tilemap with zeroes: take a scratch buffer of
 * `size` bytes off the heap (the heap id arrives as a plain argument here,
 * not out of the background system object, so it is masked and re-tagged the
 * same way the constructor's own allocation is), zero it, hand it to the
 * tilemap writer and release it again.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040B94.c \
 *       --func func_02040B94 --addr 0x02040B94 --cc 1.1p1 --arm
 */
void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId)
{
    void *buf = sub_02030734((u16)((heapId & 0x7fff) | 0x8000), size, 0,
                             g_020A7E5C, 1362);

    func_02082BCC(buf, 0, size);
    func_020425B4(layer, buf, offset, size);
    func_020307B0(buf);
}





/*
 * TU: bg_sys.c.
 *
 * Fill `count` tiles of layer `layer` starting at tile `index` with the
 * pixel value `value`.  The per-layer byte at +0x1f of the 0x2c-byte slot is
 * the tile stride: 0x20 for a 4bpp layer, anything else (0x40) for 8bpp.
 * The range is first reserved in the arena that owns the layer (+0x168 for
 * layers 0-3, +0x16c for 4-7, nothing at all for an out-of-range layer),
 * with both the offset and the length expressed in 32-byte units, then a
 * scratch buffer of count*stride bytes is filled with the replicated pixel
 * value and pushed to the layer.
 *
 * Two codegen notes.  The reserve arm must be spelled as an if/else with the
 * whole call written out in each arm, not as a ternary on the length
 * argument: the ternary hoists `count * 2` to the compare and cross-jumps the
 * `mla`, while the original shares only the `lsr` and the `bl`
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).  The two
 * pixel-replication chains have to be written right-associated with the two
 * operands of each inner pair reversed; see
 * docs/idioms/a-four-term-or-chain-is-right-associated-in-arm.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040C14.c \
 *       --func func_02040C14 --addr 0x02040C14 --cc 1.1p1 --arm
 */
void func_02040C14(u32 layer, u32 value, u32 count, u32 index)
{
    u32   size;
    void *buf;

    switch (layer) {
    case 0:
    case 1:
    case 2:
    case 3:
        {
            struct BgSys *p     = g_02146A44;
            u32           depth = p->bgs[layer].unk_17;

            if (depth == 0x20) {
                func_020341F0(p->unk_168,
                              (p->unk_170[layer] + index * depth) >> 5, count);
            } else {
                func_020341F0(p->unk_168,
                              (p->unk_170[layer] + index * depth) >> 5,
                              count * 2);
            }
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        {
            struct BgSys *p     = g_02146A44;
            u32           depth = p->bgs[layer].unk_17;

            if (depth == 0x20) {
                func_020341F0(p->unk_16c,
                              (p->unk_170[layer] + index * depth) >> 5, count);
            } else {
                func_020341F0(p->unk_16c,
                              (p->unk_170[layer] + index * depth) >> 5,
                              count * 2);
            }
        }
        break;
    }

    size = count * g_02146A44->bgs[layer].unk_17;
    buf  = sub_02030734((u16)((g_02146A44->heapId & 0x7fff) | 0x8000),
                        size, 0, g_020A7E5C, 1421);

    if (g_02146A44->bgs[layer].unk_17 == 0x20) {
        u32 t = value | (value << 4 | (value << 12 | value << 8));

        value = t | (t << 16);
    } else {
        value = value | (value << 8 | (value << 24 | value << 16));
    }

    func_02082AC0(value, buf, size);
    func_020425B4((u8)layer, buf, index * g_02146A44->bgs[layer].unk_17,
                  size);
    func_020307B0(buf);
}





/*
 * bg_sys.c.  Release a run of tiles from one layer's arena.  The layer index
 * selects the arena (0-3 at +0x168, 4-7 at +0x16c, anything else a no-op) and
 * the slot's +0x1F bit-depth byte is both the multiplicand that turns a tile
 * index into a byte offset and the 0x20 test that doubles the count for the
 * 4bpp case.  The >> 5 is the arena's fixed 32-byte unit, not a division by
 * the depth.
 *
 * The declaration that closes this function is the depth byte's OFFSET: it is
 * +0x1F, not +0x1E.  Both bytes are live and independently read in this
 * family (func_02040B1C reads the +0x1E flag off the same 0x2C-stride
 * record); putting depth at +0x1E moves a live ldrb and loses the function.
 * See docs/families/bg_sys.h.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02040DA8.c \\
 *       --func func_02040DA8 --addr 0x02040DA8 --cc 1.1p1 --arm
 */
void func_02040DA8(u32 idx, u32 count, u32 tile)
{
    u32 unit;

    switch (idx) {
    case 0: case 1: case 2: case 3:
        unit = g_02146A44->bgs[idx].unk_17;
        if (unit == 0x20) {
            func_0203422C(g_02146A44->unk_168,
                          (g_02146A44->unk_170[idx] + tile * unit) >> 5, count);
        } else {
            func_0203422C(g_02146A44->unk_168,
                          (g_02146A44->unk_170[idx] + tile * unit) >> 5, count * 2);
        }
        break;
    case 4: case 5: case 6: case 7:
        unit = g_02146A44->bgs[idx].unk_17;
        if (unit == 0x20) {
            func_0203422C(g_02146A44->unk_16c,
                          (g_02146A44->unk_170[idx] + tile * unit) >> 5, count);
        } else {
            func_0203422C(g_02146A44->unk_16c,
                          (g_02146A44->unk_170[idx] + tile * unit) >> 5, count * 2);
        }
        break;
    }
}





void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4)
{
    func_020862F0(r6, r5);
    if (r7 < 4) {
        func_0207E3D0(r6, r4, r5);
    } else {
        func_0207E468(r6, r4, r5);
    }
}





void func_02040EBC(u32 a0, u32 a1)
{
    func_02040E78(a0, &a1, 2, 0);
}





/*
 * The (x, y) to linear screen-entry index helper the whole BG layer uses
 * (src/matched/sub_02042FB0.c and src/matched/func_020413B0.c are two of
 * its callers).  The third argument is the slot's screen-size code at +0x1d
 * of the 0x2c-byte slot record, and the six arms spell the DS BG screen
 * layouts out exactly:
 *
 *   0  256x256 text, one 32x32 map:      x + y * 32 is wrong, it is
 *                                        x + y * 16, i.e. a 16-wide map
 *   1  and 2                             x + y * 32, a 32-wide map
 *   3  512x256: the second 32x32 map follows the first, so the high bits
 *      of x select the map and the low five index inside it
 *   4  512x512: four 32x32 maps in a 2x2 grid, map index (y>>5)*2 + (x>>5)
 *      times 0x400 entries, plus (x & 31) + (y & 31) * 32 inside
 *   5  no map
 *
 * Everything is u16 arithmetic: case 4 truncates the scaled map index to
 * sixteen bits before adding the in-map offset, which is what the
 * `lsl #26` / `lsr #16` pair is, so the two partial results have to be u16
 * locals rather than one expression.
 *
 * x and y are signed (the shifts are `asr`, not `lsr`), and the switch has
 * no default arm at all: an out-of-range code falls straight out of the
 * dispatch to `bx lr` with x still in r0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040EE0.c \
 *       --func func_02040EE0 --addr 0x02040EE0 --cc 1.1p1 --arm
 */
u16 func_02040EE0(u8 x, u8 y, u8 code)
{
    u16 map;
    u16 off;

    switch (code) {
    case 0:
        return x + y * 16;
    case 1:
    case 2:
        return x + y * 32;
    case 3:
        return (x & 0x1f) + (y + (x & ~0x1f)) * 32;
    case 4:
        map = (y >> 5) * 2 + (x >> 5);
        off = (x & 0x1f) + (y & 0x1f) * 32;
        map = map * 0x400;
        return off + map;
    case 5:
        return 0;
    }
}





/*
 * The arbitrary-size cousin of src/matched/func_02040EE0.c: linear screen
 * entry index for (x, y) in a map that is `w` by `h` tiles, laid out as up to
 * four 32-wide/32-tall blocks.  The block is selected by `(x >> 5)` and
 * `(y >> 5)` folded into a single u8 selector, and the switch has cases 0..3
 * only, so the out-of-range dispatch falls straight through to `return base`
 * with base still zero.
 *
 * `w - 32` and `h - 32` are s16_02040820 locals, and they double as both the guard and
 * the stride of the right-hand and bottom blocks: a negative value means the
 * map is narrower (shorter) than one block, so block 0 uses `w` (`h`) as its
 * stride and the trailing blocks never exist.  Everything accumulates through
 * u16, which is what every `lsl #16` / `lsr #16` pair in the original is.
 *
 * Three shape notes, each of which cost bytes to find:
 *
 *  - `base += idx;` has to be written out inside both arms of the if/else in
 *    cases 0 and 2 (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *    Factored out after the if/else, the arms become one instruction each and
 *    the compiler if-converts them to `addge`/`mlalt`, which is four bytes
 *    shorter than the original's real branches.  Case 1's if/else really is
 *    predicated, and that is the contrast that names the shape.
 *  - `base` must be the first declaration, or it does not get ip
 *    (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 *    with w2 first the whole function comes out with ip, lr and r4 rotated.
 *  - but `base` must be *assigned* zero after `sel`, as a statement rather
 *    than an initialiser, because the original materialises the zero into
 *    sel's register and copies it into base's (`mov r6, #0` then
 *    `mov ip, r6`), not the other way round.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040F84.c \
 *       --func func_02040F84 --addr 0x02040F84 --cc 1.1p1 --arm
 */
u16 func_02040F84(u8 x, u8 y, u8 w, u8 h)
{
    u16 base;
    s16_02040820 w2 = w - 32;
    s16_02040820 h2 = h - 32;
    u8  sel = 0;
    u16 idx;

    base = 0;

    if ((u32)x >> 5) {
        sel += 1;
    }
    if ((u32)y >> 5) {
        sel += 2;
    }

    switch (sel) {
    case 0:
        if (w2 >= 0) {
            idx = x + y * 32;
            base += idx;
        } else {
            idx = x + y * w;
            base += idx;
        }
        break;
    case 1:
        if (h2 >= 0) {
            base += 32 * 32;
        } else {
            base += h * 32;
        }
        idx = (x & 0x1f) + y * w2;
        base += idx;
        break;
    case 2:
        base += w * 32;
        if (w2 >= 0) {
            idx = x + (y & 0x1f) * 32;
            base += idx;
        } else {
            idx = x + (y & 0x1f) * w;
            base += idx;
        }
        break;
    case 3:
        base += (w + h2) * 32;
        idx = (x & 0x1f) + (y & 0x1f) * w2;
        base += idx;
        break;
    }
    return base;
}





/*
 * The short public entry point in front of src/matched/func_020410D0.c: it
 * drops the caller's second argument out of the register block, shifts the
 * third and fourth down into r1/r2, and rebuilds the ten-argument call with
 * the two u8 tail arguments duplicated and a pair of zeroes in between.
 *
 * Reading the callee's argument list back, this is the "no clip rectangle"
 * form: arguments 7 and 8 of func_020410D0 are the clip origin and are passed
 * as zero, while arguments 9 and 10 repeat the size pair given here, so the
 * clip box is the whole destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02041090.c \
 *       --func func_02041090 --addr 0x02041090 --cc 1.1p1 --arm
 */
void func_02041090(u32 index, const void *src, u8 dx, u8 dy, u8 cw, u8 ch)
{
    func_020410D0(index, dx, dy, cw, ch, src, 0, 0, cw, ch);
}





/*
 * The ten-argument sibling of src/pending/func_02041300.c: fan out on the
 * bit-depth byte at +0x1c of the 0x2c-byte slot behind 0x02146A44 and forward
 * the whole argument list, plus a trailing zero, to one of three blitters.
 * All three arms are byte-identical in their argument marshalling; only the
 * callee differs.
 *
 * The slot's sub-object pointer is spelled as byte arithmetic with the
 * constant added first and written out in every arm, for the reason recorded
 * in src/pending/func_02041300.c: `&g_02146A44[index].unk_08` contracts into
 * a single `mla` and loses twelve bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020410D0.c \
 *       --func func_020410D0 --addr 0x020410D0 --cc 1.1p1 --arm
 */
void func_020410D0(u32 index, u8 dx, u8 dy, u8 cw, u8 ch, const void *src, u8 sx,
                   u8 sy, u8 sw, u8 sh)
{
    u8 kind = g_02146A44->bgs[index].type;

    if (kind == 0) {
        func_020426A0(&g_02146A44->bgs[index],
                      dx, dy, cw, ch, src, sx, sy, sw, sh, 0);
    } else if (kind == 1) {
        func_020428E8(&g_02146A44->bgs[index],
                      dx, dy, cw, ch, src, sx, sy, sw, sh, 0);
    } else {
        func_02042B24(&g_02146A44->bgs[index],
                      dx, dy, cw, ch, src, sx, sy, sw, sh, 0);
    }
}





/*
 * The twin of src/matched/func_020410D0.c, differing only in the trailing
 * constant it appends to the blitter's argument list: 1 here, 0 there.  Fan
 * out on the bit-depth byte at +0x1c of the 0x2c-byte slot behind 0x02146A44
 * and forward the whole argument list to one of three blitters.  All three
 * arms are byte-identical in their argument marshalling; only the callee
 * differs.  The pair reads as a "transparent" flag threaded through the two
 * public entry points of the same fill.
 *
 * The slot's sub-object pointer is spelled as byte arithmetic with the
 * constant added first and written out in every arm, for the reason recorded
 * in src/pending/func_02041300.c: `&g_02146A44[index].unk_08` contracts into
 * a single `mla` and loses twelve bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020411E8.c \
 *       --func func_020411E8 --addr 0x020411E8 --cc 1.1p1 --arm
 */
void func_020411E8(u32 index, u8 dx, u8 dy, u8 cw, u8 ch, const void *src, u8 sx,
                   u8 sy, u8 sw, u8 sh)
{
    u8 kind = g_02146A44->bgs[index].type;

    if (kind == 0) {
        func_020426A0(&g_02146A44->bgs[index],
                      dx, dy, cw, ch, src, sx, sy, sw, sh, 1);
    } else if (kind == 1) {
        func_020428E8(&g_02146A44->bgs[index],
                      dx, dy, cw, ch, src, sx, sy, sw, sh, 1);
    } else {
        func_02042B24(&g_02146A44->bgs[index],
                      dx, dy, cw, ch, src, sx, sy, sw, sh, 1);
    }
}





/*
 * note:     re-verified 2026-09-20: MATCH; see verify output
 */
void func_02041300(u32 layer, u16 value, u8 x0, u8 y0, u8 w, u8 h, u8 mode)
{
    u32 offset = layer * 0x2C;
    struct BgConfigLayer *bg = (struct BgConfigLayer *)((u8 *)g_02146A44 + offset);

    if (bg->mode == 0) {
        func_02042D2C((struct Bg *)((u8 *)g_02146A44 + 8 + offset), value, x0, y0, w, h, mode);
    } else if (bg->mode == 1) {
        func_02042E34((struct Bg *)((u8 *)g_02146A44 + 8 + offset), (u8)value, x0, y0, w, h);
    } else {
        func_02042ED8((struct Bg *)((u8 *)g_02146A44 + 8 + offset), value, x0, y0, w, h, mode);
    }
}





/*
 * Recolour a rectangle of the screen buffer of table slot `index`: for every
 * tile entry in the (x0, y0, w, h) box, replace the palette nibble in bits
 * 12..15 with `pal` and leave the low twelve bits alone.
 *
 * func_020422D4 turns the slot's screen-size code at +0x1d into the layer's
 * width and height in tiles, returned through two u8 out-parameters; the
 * later declaration gets the lower stack address
 * (docs/idioms/local-declaration-order-is-stack-order.md), so `width` at
 * sp+9 has to be declared before `height` at sp+8.  The box is clipped
 * against those two: running off the right edge breaks the row, running off
 * the bottom returns outright.  func_02040EE0 is the same (x, y, size_code)
 * to linear-index helper src/matched/sub_02042FB0.c uses.
 *
 * Two loop-shape notes, each worth twelve bytes:
 *
 *  - The y bound must be only the `for` condition.  Writing the equivalent
 *    `if (y0 >= yEnd) return;` in front of the loop as well emits the
 *    predicated return twice: the compiler's own loop-rotation entry test
 *    already is that guard.
 *  - The x bound must stay an expression in the inner condition,
 *    `x < x0 + w`, not a local computed before the nest.  As an expression
 *    it is loop-invariant and gets hoisted into the outer loop's preheader,
 *    which is after the y guard; as a local it is computed before the guard,
 *    which is where the original does not have it.
 *
 * Both bounds are signed compares (bge/blt) because each is a sum of two u8
 * values and so has type int, while the two clip tests against width and
 * height are unsigned (bhs): there both sides are u8 and the front end knows
 * the range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020413B0.c \
 *       --func func_020413B0 --addr 0x020413B0 --cc 1.1p1 --arm
 */
void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal)
{
    u8   width;
    u8   height;
    u16 *screen;
    u8   x;
    int  yEnd;

    screen = (u16 *)g_02146A44->bgs[index].buf;
    if (screen == 0) {
        return;
    }

    func_020422D4(g_02146A44->bgs[index].unk_15, &width, &height);

    yEnd = y0 + h;

    for (; y0 < yEnd; y0++) {
        if (y0 >= height) {
            return;
        }
        for (x = x0; x < x0 + w; x++) {
            u32 i;

            if (x >= width) {
                break;
            }
            i = func_02040EE0(x, y0, g_02146A44->bgs[index].unk_15);
            screen[i] = (u16)((screen[i] & 0xfff) | (pal << 12));
        }
    }
}



asm void func_020414AC(void)
{
    stmfd sp!, {r4, lr}
    mov	r4, r0
    bl func_020414C4
    mov	r0, r4
    bl func_020414EC
    ldmfd sp!, {r4, pc}
}



void func_020414C4(u8 idx)
{
    func_02040B94(idx, (u32)g_02146A44->unk_1b0[idx], 0, g_02146A44->heapId);
}



/*
 * Clear slot `i` of the 0x2c-byte slot table behind 0x02146A44: if the
 * buffer pointer at +8 is unset there is nothing to do, otherwise zero the
 * buffer over its +0xc length and notify func_020409B4.  Same table and
 * same guard shape as src/matched/sub_020403F4.c, which frees the buffer
 * instead of clearing it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020414EC.c \
 *       --func func_020414EC --addr 0x020414EC --cc 1.1p1 --arm
 */
void func_020414EC(u32 i)
{
    if (g_02146A44->bgs[i].buf == 0) {
        return;
    }
    MIi_CpuClear16(0, g_02146A44->bgs[i].buf, g_02146A44->bgs[i].bufSize);
    func_020409B4(i);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * Channel clear and audio dispatcher functions.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204152C.c \
 *       --addr 0x0204152C --arm
 */
void func_0204152C(int channel, u16 val)
{

    if (g_02146A44->bgs[channel].buf == 0) {
        return;
    }
    MIi_CpuClear16(val, g_02146A44->bgs[channel].buf, g_02146A44->bgs[channel].bufSize);
    func_020409B4(channel);
}



void func_02041570(int channel, u16 val)
{

    if (g_02146A44->bgs[channel].buf == 0) {
        return;
    }
    MIi_CpuClear16(val, g_02146A44->bgs[channel].buf, g_02146A44->bgs[channel].bufSize);
    func_02041B6C(channel);
}



u32 func_020415B4(u32 channel)
{
    switch (channel) {
    case 0: return (u32)func_0207E1F8();
    case 1: return (u32)func_0207E24C();
    case 2: return (u32)func_0207E2A0();
    case 3: return (u32)func_0207E330();
    case 4: return func_0207E22C();
    case 5: return func_0207E280();
    case 6: return (u32)func_0207E2F0();
    case 7: return (u32)func_0207E388();
    default: return 0;
    }
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0204169C, func_020416B8
 *
 * Channel state struct member accessors.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204162C.c \
 *       --addr 0x0204162C --arm
 */
u32 func_0204162C(int channel)
{
    return (u32)g_02146A44->bgs[channel].buf;
}



u32 func_02041648(u8 channel)
{
    return g_02146A44->bgs[channel].scrollX;
}



u32 func_02041664(u8 channel)
{
    return g_02146A44->bgs[channel].scrollY;
}



u8 func_02041680(int channel)
{
    return g_02146A44->bgs[channel].type;
}



u8 func_0204169C(int channel)
{
    return g_02146A44->bgs[channel].unk_16;
}



u8 func_020416B8(int channel)
{
    return g_02146A44->bgs[channel].unk_17;
}



/*
 * The BG priority getter: returns the 2-bit priority field of the layer's
 * BGxCNT register.  Layers 0/1/4/5 read their register directly; layers
 * 2/3/6/7 first consult the slot's +0x1c mode byte, which selects one of
 * three otherwise identical reads of the SAME register (only the stack
 * slot the raw halfword spills to differs).
 *
 * Three declarations carry the whole function and none is optional:
 *
 *  1. The return is a 2-BIT BITFIELD of a struct COPIED from the register,
 *     not a masked read.  `struct BgCnt { u16 prio : 2; u16 rest : 14; }`
 *     assigned into a local is what emits the `lsl #0x1e / lsr #0x1e` pair
 *     AND the `strh r1, [sp, #N]` spill of the raw halfword together.  A
 *     plain `(x & 3)` loses both; a plain u16 local loses the spill.
 *  2. Each read needs its OWN local (c0..c15).  The sixteen distinct
 *     locals are what place the spills at the descending slots 0x1e, 0x1c,
 *     0x1a, ...; one reused local collapses them all onto [sp].
 *  3. The return type is u8, which is the trailing `and r0, r0, #0xff`.
 *
 * WHAT CLOSED THE LAST 303 BYTES (wave 2 of this family).  The four
 * sub-dispatch arms must emit the FULL unfused comparison chain
 *     cmp r0,#0 ; beq A ; cmp r0,#1 ; beq B ; cmp r0,#2 ; beq C ; <fall>
 * where the mode==0 branch target IS the fall-through address, so the
 * mode==0 body is reached both by its own beq and by falling off the end
 * of the chain.  No if/else-if chain reproduces that: the compiler fuses
 * the first test into `cmp r0,#0 / bne`.  An inner `switch` builds a jump
 * table and comes out 16 bytes short.  Only an explicit goto chain
 *     if (m == 0) goto L_0;  if (m == 1) goto L_1;  if (m == 2) goto L_2;
 *     L_0: ...  L_1: ...  L_2: ...
 * with the labels following in source order emits the three separate
 * cmp/beq pairs and lets L_0 double as the fall-through, which is the
 * shape docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md
 * describes.  Caching the mode in a `u8 m` local is part of it: reading
 * `g_02146A44[layer].mode` three times re-emits the mla address
 * computation before each test.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020416D4.c \
 *       --func func_020416D4 --addr 0x020416D4 --arm --cc 1.1p1
 */
u8 func_020416D4(u32 layer)
{
    struct BgCnt c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15;

    switch (layer) {
    case 0:
        c0 = R(0x04000008);
        return c0.prio;
    case 1:
        c1 = R(0x0400000a);
        return c1.prio;
    case 2:
        {
            u8 m = g_02146A44->bgs[layer].type;
            if (m == 0) goto L0_0;
            if (m == 1) goto L0_1;
            if (m == 2) goto L0_2;
        L0_0:
            c2 = R(0x0400000c);
            return c2.prio;
        L0_1:
            c3 = R(0x0400000c);
            return c3.prio;
        L0_2:
            c4 = R(0x0400000c);
            return c4.prio;
        }
    case 3:
        {
            u8 m = g_02146A44->bgs[layer].type;
            if (m == 0) goto L1_0;
            if (m == 1) goto L1_1;
            if (m == 2) goto L1_2;
        L1_0:
            c5 = R(0x0400000e);
            return c5.prio;
        L1_1:
            c6 = R(0x0400000e);
            return c6.prio;
        L1_2:
            c7 = R(0x0400000e);
            return c7.prio;
        }
    case 4:
        c8 = R(0x04001008);
        return c8.prio;
    case 5:
        c9 = R(0x0400100a);
        return c9.prio;
    case 6:
        {
            u8 m = g_02146A44->bgs[layer].type;
            if (m == 0) goto L2_0;
            if (m == 1) goto L2_1;
            if (m == 2) goto L2_2;
        L2_0:
            c10 = R(0x0400100c);
            return c10.prio;
        L2_1:
            c11 = R(0x0400100c);
            return c11.prio;
        L2_2:
            c12 = R(0x0400100c);
            return c12.prio;
        }
    case 7:
        {
            u8 m = g_02146A44->bgs[layer].type;
            if (m == 0) goto L3_0;
            if (m == 1) goto L3_1;
            if (m == 2) goto L3_2;
        L3_0:
            c13 = R(0x0400100e);
            return c13.prio;
        L3_1:
            c14 = R(0x0400100e);
            return c14.prio;
        L3_2:
            c15 = R(0x0400100e);
            return c15.prio;
        }
    }

    return 0;
}



void func_020419E4(void)
{
    if (g_02146A44 == 0) {
        return;
    }

    func_02041B94();
    func_02041A1C();

    g_02146A44->unk_04 = 0;
    g_02146A44->unk_06 = 0;
}



/*
 * Flush the eight tile slots of the 0x2c-byte table behind 0x02146A44 whose
 * dirty bit is set in the u16 at +6: each selected slot re-uploads its tile
 * buffer at the same argument triple func_020409E0 uses (index, tiles,
 * unk_10 * 2, unk_0c).  The global is re-read once per arm because the call
 * may write it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02041A1C.c \
 *       --func func_02041A1C --addr 0x02041A1C --cc 1.1p1 --arm
 */
void func_02041A1C(void)
{
    if (g_02146A44->unk_06 & 0x01)
        func_0204241C(0, g_02146A44->bgs[0].buf, g_02146A44->bgs[0].unk_08 * 2,
                      g_02146A44->bgs[0].bufSize);
    if (g_02146A44->unk_06 & 0x02)
        func_0204241C(1, g_02146A44->bgs[1].buf, g_02146A44->bgs[1].unk_08 * 2,
                      g_02146A44->bgs[1].bufSize);
    if (g_02146A44->unk_06 & 0x04)
        func_0204241C(2, g_02146A44->bgs[2].buf, g_02146A44->bgs[2].unk_08 * 2,
                      g_02146A44->bgs[2].bufSize);
    if (g_02146A44->unk_06 & 0x08)
        func_0204241C(3, g_02146A44->bgs[3].buf, g_02146A44->bgs[3].unk_08 * 2,
                      g_02146A44->bgs[3].bufSize);
    if (g_02146A44->unk_06 & 0x10)
        func_0204241C(4, g_02146A44->bgs[4].buf, g_02146A44->bgs[4].unk_08 * 2,
                      g_02146A44->bgs[4].bufSize);
    if (g_02146A44->unk_06 & 0x20)
        func_0204241C(5, g_02146A44->bgs[5].buf, g_02146A44->bgs[5].unk_08 * 2,
                      g_02146A44->bgs[5].bufSize);
    if (g_02146A44->unk_06 & 0x40)
        func_0204241C(6, g_02146A44->bgs[6].buf, g_02146A44->bgs[6].unk_08 * 2,
                      g_02146A44->bgs[6].bufSize);
    if (g_02146A44->unk_06 & 0x80)
        func_0204241C(7, g_02146A44->bgs[7].buf, g_02146A44->bgs[7].unk_08 * 2,
                      g_02146A44->bgs[7].bufSize);
}



/*
 * Sets one bit of the 16-bit request mask at +6 of the singleton reached
 * through the pointer at 0x02146A44.  The lsl #16 / lsr #16 pair is the
 * u16 truncation of `1 << bit`, not a mask written in the source.
 */
void sub_02041B6C(u32 bit)
{
    g_02146A44->unk_06 |= 1 << bit;
}



/*
 * The per-frame scroll/affine flush for the whole BG system: eight
 * independent blocks, one per layer, each guarded by its own bit of the
 * dirty mask at +0x04 of the singleton (the mask unit_02041F28 ORs
 * (1 << layer) into after every register write).  Nothing loops; all eight
 * blocks are written out, which is why the function is 848 bytes of almost
 * entirely repeated code.
 *
 * Layers 0, 1, 4 and 5 have only the plain path: pack scroll_x (+0x14) and
 * scroll_y (+0x18) into one word, low 9 bits and bits 16..24, and store it
 * to the layer's BGxOFS pair.  Layer 1 additionally tail-calls
 * func_0203D814 with that same scroll pair.
 *
 * Layers 2, 3, 6 and 7 are affine-capable and first read the record's +0x1c
 * flag: zero takes the same plain path, non-zero builds a 16-byte matrix on
 * the stack with func_02051E74 and hands it to func_0207D59C along with the
 * layer's affine register block.
 *
 * THREE DECLARATIONS CARRY THE FUNCTION, all three established by this pass
 * (it was untouched before):
 *
 *  1. THE RECORD REACHES PAST ITS OWN STRIDE.  The stride is 0x2c, but the
 *     affine arms read two words at slot-relative +0x2c and +0x30 -- for
 *     layer 2 those are the absolute offsets 0x84 and 0x88, which lie in the
 *     head of layer 3's record.  Declaring the record as exactly 0x2c bytes
 *     and indexing an array of them cannot express that, so the record is
 *     declared out to +0x34 and the array indexing is done explicitly with a
 *     0x2c byte stride (the SLOT macro).  The image's constant offsets, with
 *     no `mla` anywhere, are what show the indices are all compile-time.
 *
 *  2. THE MATRIX IS 16 BYTES, NOT 32.  The four stack temporaries sit at
 *     sp+0x38, +0x28, +0x18 and +0x08: a stride of 0x10.  With a 32-byte
 *     matrix the frame comes out `sub sp, #0x88` instead of `#0x48`.
 *
 *  3. func_0207D59C TAKES THE AFFINE PAIR IN r2/r3 AND THE SCROLL PAIR ON
 *     THE STACK.  That is arguments 3 and 4 being +0x2c/+0x30 and arguments
 *     5 and 6 being scroll_x/scroll_y, not the other way round.  The
 *     reversed order compiles and is the same size; it differs only in which
 *     two values are spilled to [sp] and [sp,#4], which is how the diff
 *     names it.
 *
 * func_0203D814's parameter list is also pinned here: it takes the scroll
 * pair (two u32), which the image shows as the two loads of +0x40/+0x44
 * immediately before the `bl`.  A void declaration leaves those two loads
 * with no reason to exist and loses them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02041B94.c \
 *       --func func_02041B94 --addr 0x02041B94 --arm --cc 1.1p1
 */
void func_02041B94(void)
{
    u32 m  = 0x1ff;
    u32 hm = m << 16;

    if (g_02146A44->unk_04 & 0x01) {
        W(0x04000010) = (SLOT(0).scrollX & m)
                      | (hm & (SLOT(0).scrollY << 16));
    }
    if (g_02146A44->unk_04 & 0x02) {
        W(0x04000014) = (SLOT(1).scrollX & m)
                      | (hm & (SLOT(1).scrollY << 16));
        func_0203D814(SLOT(1).scrollX,
                      SLOT(1).scrollY);
    }
    if (g_02146A44->unk_04 & 0x04) {
        if (SLOT(2).type == 0) {
            W(0x04000018) = (SLOT(2).scrollX & m)
                          | (hm & (SLOT(2).scrollY << 16));
        } else {
            struct Mtx22 t;
            func_02051E74(&t, SLOT(2).unk_18,
                          (const void *)SLOT(2).unk_1c,
                          (const void *)SLOT(2).unk_20, 2);
            func_0207D59C((void *)0x04000020, &t,
                          SLOT(2).unk_24, SLOT(2).unk_28,
                          SLOT(2).scrollX, SLOT(2).scrollY);
        }
    }
    if (g_02146A44->unk_04 & 0x08) {
        if (SLOT(3).type == 0) {
            W(0x0400001c) = (SLOT(3).scrollX & m)
                          | (hm & (SLOT(3).scrollY << 16));
        } else {
            struct Mtx22 t;
            func_02051E74(&t, SLOT(3).unk_18,
                          (const void *)SLOT(3).unk_1c,
                          (const void *)SLOT(3).unk_20, 2);
            func_0207D59C((void *)0x04000030, &t,
                          SLOT(3).unk_24, SLOT(3).unk_28,
                          SLOT(3).scrollX, SLOT(3).scrollY);
        }
    }
    if (g_02146A44->unk_04 & 0x10) {
        W(0x04001010) = (SLOT(4).scrollX & m)
                      | (hm & (SLOT(4).scrollY << 16));
    }
    if (g_02146A44->unk_04 & 0x20) {
        W(0x04001014) = (SLOT(5).scrollX & m)
                      | (hm & (SLOT(5).scrollY << 16));
    }
    if (g_02146A44->unk_04 & 0x40) {
        if (SLOT(6).type == 0) {
            W(0x04001018) = (SLOT(6).scrollX & m)
                          | (hm & (SLOT(6).scrollY << 16));
        } else {
            struct Mtx22 t;
            func_02051E74(&t, SLOT(6).unk_18,
                          (const void *)SLOT(6).unk_1c,
                          (const void *)SLOT(6).unk_20, 2);
            func_0207D59C((void *)0x04001020, &t,
                          SLOT(6).unk_24, SLOT(6).unk_28,
                          SLOT(6).scrollX, SLOT(6).scrollY);
        }
    }
    if (g_02146A44->unk_04 & 0x80) {
        if (SLOT(7).type == 0) {
            W(0x0400101c) = (SLOT(7).scrollX & m)
                          | (hm & (SLOT(7).scrollY << 16));
        } else {
            struct Mtx22 t;
            func_02051E74(&t, SLOT(7).unk_18,
                          (const void *)SLOT(7).unk_1c,
                          (const void *)SLOT(7).unk_20, 2);
            func_0207D59C((void *)0x04001030, &t,
                          SLOT(7).unk_24, SLOT(7).unk_28,
                          SLOT(7).scrollX, SLOT(7).scrollY);
        }
    }
}



/*
 * Reset slot `index` of the module's 0x2C-byte slot array and mark it live
 * in the halfword bitmask at +4.  The slot address is one `mla`: the base
 * pointer plus 8 plus index * 0x2C.
 *
 * The second parameter is real, not a leftover: the original steps over both r1
 * and r2 and uses r3 for the slot-address temporary.  Each register the
 * body skips is an argument still live for the forwarding call: with one
 * parameter the temporary lands in r1, with two in r2, and only with three
 * in r3.
 *
 * The bit is narrowed to sixteen bits before the `orr` (the `lsl #16` /
 * `lsr #16` pair), which is what says the mask is a u16 field and the
 * shift is done in int width first.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02041EE4.c \
 *       --func func_02041EE4 --addr 0x02041EE4 --cc 1.1p1 --arm
 */
void func_02041EE4(u32 index, u32 a, u32 b)
{
    func_02042360(&g_02146A44->bgs[index], a, b);
    g_02146A44->unk_04 |= (u16)(1 << index);
}



/*
 * Three consecutive "bring one video slot up" entry points, 68 bytes each
 * and no padding between them, differing only in the helper they call:
 * each hands the slot record (base +8, stride 0x2c) to its helper and then
 * sets that slot's own bit in the halfword at +4 of the same context.
 *
 * Each helper is the three-argument set/add/sub family matched as
 * src/matched/sub_02043228.c and its siblings, so `op` and `value` pass
 * straight through in r1/r2 and the call site prepares only r0.  That is
 * what pins the register the context value lands in: written as a
 * one-argument call every instruction of the body is still right but the
 * context load comes out in r1, four bytes per function; with the two
 * pass-through parameters declared, r1/r2 are live across the address
 * computation and the scratch goes to r3.  See
 * docs/idioms/arguments-left-in-place-keep-the-low-registers-out-of-the-scratch-pool.md.
 *
 * The bit set is the u16 truncation idiom, not a mask: `1 << which` is
 * materialised and then narrowed with the lsl #0x10 / lsr #16 pair the
 * `orr` takes as a shifted operand, which only a `u16` lvalue produces.
 * The context pointer is re-read from its own slot after the call, because
 * the callee may store it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02041F28.c \
 *       --addr 0x02041F28 --arm
 */
void func_02041F28(u32 which, u32 op, u16 value)
{
    func_02043228(&g_02146A44->bgs[which], op, value);
    g_02146A44->unk_04 |= (u16)(1 << which);
}



void func_02041F6C(u32 which, u32 op, u32 value)
{
    func_02043264(&g_02146A44->bgs[which], op, value);
    g_02146A44->unk_04 |= (u16)(1 << which);
}



void func_02041FB0(u32 which, u32 op, u16 value)
{
    func_020432E4(&g_02146A44->bgs[which], op, value);
    g_02146A44->unk_04 |= (u16)(1 << which);
}



/*
 * bg_sys.c: does the pixel under (x, y) on a layer match the caller's
 * colour list?  4bpp layers (flag_1e == 0) decode the tile into a scratch
 * 0x40-byte nibble buffer and test bit v of *flags; 8bpp layers copy the
 * tile (or, for mode 1, read the affine byte map directly) and scan a
 * 0xFFFF-terminated list.
 *
 * WHAT CLOSED IT (wave 12, 42 -> 0): the sub-tile coordinates px/py are
 * FUNCTION-SCOPE u8 locals declared first and assigned after the two
 * calls (the block-scoped `u8 px = x & 7; u16 py = y & 7;` of the wave-11
 * source kept x/y and px/py in separate registers: 42); the nibble loop
 * counter i is also function-scope (15 -> 9); and i must be declared
 * before tbl, tbl before buf (9 -> 0).  All other facts (u16 first
 * parameter of func_02043130, shared fail exit, mode != 1 arm first) are
 * from docs/notes/pkt_02041FF4.c.txt.
 */
u32 func_02041FF4(u32 layer, u16 x, u16 y, u16 *flags)
{
  u8 px;
  u8 py;
  u16 key;
  u8 *chr;
  u8 i;
  u16 *tbl;
  u8 *buf;
  u8 v;
  if (g_02146A44->bgs[layer].buf == 0)
    return 0;
  key = func_02040EE0((u8) (x >> 3), (u8) (y >> 3), g_02146A44->bgs[layer].unk_15);
  chr = (u8 *)func_020415B4(layer);
  px = x & 7;
  py = y & 7;
  if (g_02146A44->bgs[layer].unk_16 == 0)
  {
    u8 *src;
    tbl = g_02146A44->bgs[layer].buf;
    buf = func_02030734((u16)((g_02146A44->heapId & 0x7fff) | 0x8000), 0x40, 0, g_020A7E5C, 0xa77);
    src = chr + (((u32) (tbl[key] << 22)) >> 17);
    for (i = 0; i < 0x20; i++)
    {
      buf[i * 2] = src[i] & 0xf;
      buf[(i * 2) + 1] = src[i] >> 4;
    }

    func_02043130((tbl[key] >> 10) & 3, buf, g_02146A44->heapId);
    v = buf[px + (py << 3)];
    func_020307B0(buf);
    if (((*flags) & (1 << v)) == 0)
      goto fail;
    return 1;
  }
  if (g_02146A44->bgs[layer].type != 1)
  {
    tbl = g_02146A44->bgs[layer].buf;
    buf = func_02030734((u16)((g_02146A44->heapId & 0x7fff) | 0x8000), 0x40, 0, g_020A7E5C, 0xa8f);
    func_02082D44(buf, chr + (((u32) (tbl[key] << 22)) >> 16), 0x40);
    func_02043130((tbl[key] >> 10) & 3, buf, g_02146A44->heapId);
    v = buf[px + (py << 3)];
    func_020307B0(buf);
  }
  else
  {
    v = chr[((((u8 *) g_02146A44->bgs[layer].buf)[key] << 6) + px) + (py << 3)];
  }
  for (;;)
  {
    if ((*flags) == 0xffff)
      goto fail;
    if (v == ((*flags) & 0xff))
      return 1;
  }
  fail:
  return 0;

}



/*
 * Two-dimensional table: the first argument picks a row, the second a column,
 * and each cell is a two- or three-bit index.  Rows 0 and 1 both fall through
 * to the shared `return 0` (a `break` out of the switch), so mwcc if-converts
 * every arm but the last of those two rows -- which is exactly the bne/mov/bx
 * shape the original shows -- while row 2, being the final case, keeps its
 * last arm if-converted too.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02042218.c \
 *       --func func_02042218 --addr 0x02042218 --cc 1.1p1 --arm
 */
int func_02042218(int a0, int a1)
{
    switch (a1) {
    case 0:
        if (a0 == 1)
            return 0;
        if (a0 == 2)
            return 2;
        if (a0 == 3)
            return 1;
        if (a0 == 4)
            return 3;
        break;
    case 1:
        if (a0 == 0)
            return 0;
        if (a0 == 1)
            return 1;
        if (a0 == 4)
            return 2;
        if (a0 == 5)
            return 3;
        break;
    case 2:
        if (a0 == 0)
            return 0;
        if (a0 == 1)
            return 1;
        if (a0 == 4)
            return 2;
        if (a0 == 5)
            return 3;
        break;
    }
    return 0;
}



/*
 * The two register values a layer's window mode implies: six modes, each
 * writing one byte into each of the two output pointers, and nothing at all
 * for a mode above five (`addls` over a bare `bx lr`).  Modes 0, 1, 4 and 5
 * write the same constant twice, so the compiler materialises it once and
 * reuses r0 for both stores; modes 2 and 3 write two different ones in the
 * order they are given.  The arms are byte stores, so the values are `u8`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020422D4.c \
 *       --func sub_020422D4 --addr 0x020422D4 --cc 1.1p1 --arm
 */
void sub_020422D4(u32 mode, u8 *a, u8 *b)
{
    switch (mode) {
    case 0:
        *a = 0x10;
        *b = 0x10;
        break;
    case 1:
        *a = 0x20;
        *b = 0x20;
        break;
    case 2:
        *a = 0x20;
        *b = 0x40;
        break;
    case 3:
        *a = 0x40;
        *b = 0x20;
        break;
    case 4:
        *a = 0x40;
        *b = 0x40;
        break;
    case 5:
        *a = 0x80;
        *b = 0x80;
        break;
    }
}



/*
 * The 32-bit member of the set / add / subtract family whose 16-bit
 * counterpart is src/matched/sub_02043228.c: opcodes 0..2 on the word at
 * +0xc of the record in r0, opcodes 3..5 on the word at +0x10, and nothing
 * at all above 5.  Each arm loads, combines and stores the field spelled
 * out as two statements of one expression, which is what keeps a single
 * `ldr` per arm.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02042360.c \
 *       --func sub_02042360 --addr 0x02042360 --cc 1.1p1 --arm
 */
void sub_02042360(struct Bg *p, u32 op, u32 value)
{
    switch (op) {
    case 0:
        p->scrollX = value;
        break;
    case 1:
        p->scrollX = p->scrollX + value;
        break;
    case 2:
        p->scrollX = p->scrollX - value;
        break;
    case 3:
        p->scrollY = value;
        break;
    case 4:
        p->scrollY = p->scrollY + value;
        break;
    case 5:
        p->scrollY = p->scrollY - value;
        break;
    }
}



/*
 * One layer's affine setup: fill a scratch parameter block on the stack,
 * then push it into the layer through sub_02040860 with a zero transform.
 * The block is 0x10 bytes at sp+4 and the first call's fifth argument is
 * the word at sp+0, which is why the frame is `sub sp, sp, #0x14`: four
 * bytes of outgoing argument plus sixteen of local.
 *
 * The first call's third and fourth arguments are the same literal, so the
 * compiler materialises 0x1000 once in r2 and copies it to r3; the zero is
 * shared the same way and survives into the second call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020423D4.c \
 *       --func func_020423D4 --addr 0x020423D4 --cc 1.1p1 --arm
 */
void func_020423D4(u32 layer)
{
    struct Mtx22 p;

    func_02051E74(&p, 0, (const void *)0x1000, (const void *)0x1000, 0);
    sub_02040860(layer, &p, 0, 0);
}



/*
 * One screen-base upload for the layer in r0: flush the source range and
 * then dispatch on the layer index 0..7.  The eight callees are consecutive
 * entries of the same SDK object (gx_load2d.o, 188 bytes each, 0x0207E888
 * first), four for the main engine then four for the sub engine, and
 * layout/symbols_sdk.txt gives all eight the same recovered name, so they
 * are named by address here rather than by a guess at the BG number.
 *
 * The three transform arguments are passed straight through in r1/r2/r3
 * (nothing in any arm writes r1 or r3) and every arm repeats the same
 * `mov r0, r1, r2` trio before its call; the flush gets the source and the
 * size, the arms get source, offset and size.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204241C.c \
 *       --func func_0204241C --addr 0x0204241C --cc 1.1p1 --arm
 */
void func_0204241C(u32 layer, const void *src, u32 offset, u32 size)
{
    DC_FlushRange((void *)src, size);

    switch (layer) {
    case 0:
        func_0207E888(src, offset, size);
        break;
    case 1:
        func_0207EA00(src, offset, size);
        break;
    case 2:
        func_0207EB78(src, offset, size);
        break;
    case 3:
        func_0207ECF0(src, offset, size);
        break;
    case 4:
        func_0207E944(src, offset, size);
        break;
    case 5:
        func_0207EABC(src, offset, size);
        break;
    case 6:
        func_0207EC34(src, offset, size);
        break;
    case 7:
        func_0207EDAC(src, offset, size);
        break;
    }
}



/*
 * bg_sys.c.  Upload tile data to a layer, decompressing first when the
 * caller asks for mode 0.  The mode parameter does double duty: it is the
 * conversion selector on the mode-0 path and, on the direct path, it is
 * passed straight through to func_020425B4 as that call's own fourth
 * argument, which is why "movs r6, r2" tests it and keeps it live.
 *
 * Three declarations carry this function, all of them from the family
 * header (docs/families/bg_sys.h):
 *   - the allocator's signature, sub_02030734(heapId, size, clear, site,
 *     tag), with the u16 heap id first and the __FILE__ anchor fourth;
 *   - the scratch heap id spelling (g_02146A44->heapId & 0x7fff) | 0x8000,
 *     the same masked form func_02040B94 and func_02040C14 use;
 *   - the source's first word being a header whose top 24 bits are the
 *     decompressed byte count, hence "lsr r4, r2, #8" on *src.
 * The allocator tag is 2963 and the site string is the bg_sys.c anchor at
 * 0x020A7E5C.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02042508.c \
 *       --func func_02042508 --addr 0x02042508 --cc 1.1p1 --arm
 */
void func_02042508(u32 index, const u32 *src, u32 mode, u32 size)
{
    if (mode == 0) {
        u32   n = *src >> 8;
        void *buf;

        buf = sub_02030734((u16)((g_02146A44->heapId & 0x7fff) | 0x8000),
                           n, 0, g_020A7E5C, 2963);
        func_02040968(src, buf, mode);
        func_020425B4(index, buf, size, n);
        func_020307B0(buf);
    } else {
        func_020425B4(index, src, size, mode);
    }
}



/*
 * The character-base twin of func_0204241C, byte for byte the same shape
 * over the next eight entries of the same SDK object (0x0207EE68 first,
 * 0x94 bytes each): flush, then dispatch on the layer index 0..7 with the
 * source, offset and size passed through in r1/r2/r3.  The sub-engine
 * callees are the second group of four, which is why the case order is not
 * the address order; see the symbol note in func_0204241C.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020425B4.c \
 *       --func func_020425B4 --addr 0x020425B4 --cc 1.1p1 --arm
 */
void func_020425B4(u32 layer, const void *src, u32 offset, u32 size)
{
    DC_FlushRange((void *)src, size);

    switch (layer) {
    case 0:
        func_0207EE68(src, offset, size);
        break;
    case 1:
        func_0207EF90(src, offset, size);
        break;
    case 2:
        func_0207F0B8(src, offset, size);
        break;
    case 3:
        func_0207F1E0(src, offset, size);
        break;
    case 4:
        func_0207EEFC(src, offset, size);
        break;
    case 5:
        func_0207F024(src, offset, size);
        break;
    case 6:
        func_0207F14C(src, offset, size);
        break;
    case 7:
        func_0207F274(src, offset, size);
        break;
    }
}


/*
 * The u16 tile-to-tile copier, sibling of func_020428E8 (u8 cells) and
 * func_02042B24 (linear destination).  mode 0 clips each row and cell
 * with u8-wrapped coordinates and skips; any other mode clips with int
 * sums, stops at the first miss and indexes the source through
 * func_02040F84.  Written in wave 11 straight from the two siblings'
 * settled declarations (u8 ch/sw/sh stack parameters, u8 w/h for
 * func_02040F84, `u8 w, h;` and `u8 y, x;`); EXACT at the first compile.
 */
void func_020426A0(struct Bg *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode)
{
    u16 *dst;
    u8 w, h;
    u8 y, x;

    dst = (u16 *)s->buf;
    if (dst == 0)
        return;

    func_020422D4(s->unk_15, &w, &h);

    if (mode == 0) {
        for (y = 0; y < ch; y++) {
            if ((u8)(dy + y) < h && (u8)(sy + y) < sh) {
                for (x = 0; x < cw; x++) {
                    if ((u8)(dx + x) < w && (u8)(sx + x) < sw)
                        dst[func_02040EE0(dx + x, dy + y, s->unk_15)] =
                            src[sx + x + sw * (sy + y)];
                }
            }
        }
    } else {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[func_02040EE0(dx + x, dy + y, s->unk_15)] =
                    src[func_02040F84(sx + x, sy + y, sw, sh)];
            }
        }
    }
}


/*
 * Tile-to-tile copier: copies a cw x ch block of a source tilemap
 * (row stride sw, height sh, origin sx/sy) into the screen's tilemap at
 * dx/dy, clipped to the screen size func_020422D4 reports.  mode 0 reads
 * the source linearly, any other mode through func_02040F84's index.
 *
 * Closed in wave 11.  Three declarations carry it: ch, sw and sh are u8
 * stack parameters even though the image loads each with a full `ldr`
 * (a u8 stack argument still occupies and is read as a word; the narrow
 * type is what moves the prologue's parameter homes, as with
 * func_02042D2C's seventh parameter), func_02040F84 is called with u8
 * w/h, and the two out-bytes are declared `u8 w, h;` so w lands at
 * sp+0x29 and h at sp+0x28.  The callers (func_020410D0, func_020411E8)
 * already declare the fifth parameter (ch) as u8.
 */
void func_020428E8(struct Bg *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u8 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode)
{
    u8 *dst;
    u8 w, h;
    u8 x, y;

    dst = (u8 *)s->buf;
    if (dst == 0)
        return;

    func_020422D4(s->unk_15, &w, &h);

    if (mode == 0) {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[func_02040EE0(dx + x, dy + y, s->unk_15)] =
                    src[sw * (sy + y) + sx + x];
            }
        }
    } else {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[func_02040EE0(dx + x, dy + y, s->unk_15)] =
                    src[func_02040F84(sx + x, sy + y, sw, sh)];
            }
        }
    }
}


/*
 * The halfword sibling of func_020428E8: copies a cw x ch block of u16
 * source cells into a linear w-wide screen buffer at dx/dy.  mode 0 clips
 * each row and cell with u8-wrapped coordinates and skips (the source row
 * index itself is the unwrapped sy + y); any other mode clips with plain
 * int sums, stops at the first miss, and indexes the source through
 * func_02040F84.  Closed in wave 11 with the same declarations as
 * func_020428E8 (ch, sw, sh are u8 stack parameters; func_02040F84 takes
 * u8 w/h; `u8 w, h;` puts w at sp+0x1d) and the loop counters declared
 * `u8 y, x;`.
 */
void func_02042B24(struct Bg *s, u8 dx, u8 dy, u8 cw, u8 ch,
                   const u16 *src, u8 sx, u8 sy, u8 sw, u8 sh, u8 mode)
{
    u16 *dst;
    u8 w, h;
    u8 y, x;

    dst = (u16 *)s->buf;
    if (dst == 0)
        return;

    func_020422D4(s->unk_15, &w, &h);

    if (mode == 0) {
        for (y = 0; y < ch; y++) {
            if ((u8)(dy + y) < h && (u8)(sy + y) < sh) {
                for (x = 0; x < cw; x++) {
                    if ((u8)(dx + x) < w && (u8)(sx + x) < sw)
                        dst[dx + x + w * (dy + y)] = src[sx + x + sw * (sy + y)];
                }
            }
        }
    } else {
        for (y = 0; y < ch; y++) {
            if (dy + y >= h || sy + y >= sh)
                return;
            for (x = 0; x < cw; x++) {
                if (dx + x >= w || sx + x >= sw)
                    break;
                dst[dx + x + w * (dy + y)] = src[func_02040F84((u8)(sx + x), (u8)(sy + y), sw, (u8)sh)];
            }
        }
    }
}


/*
 * The third of the three tilemap blitters func_02041300 dispatches to on the
 * bit-depth byte at +0x1c of the 0x2c-byte slot.  Its two siblings are
 * src/matched/func_02042E34.c (8bpp pixel fill, tiled addressing, u8 buffer)
 * and src/matched/func_02042ED8.c (text fill, linear addressing, u16 buffer);
 * this one is func_02042ED8's three write modes over func_02042E34's tiled
 * addressing, into a u16 buffer.  Like both of those it is handed the slot's
 * sub-object (slot + 8), so the buffer pointer is at +0x00 and the
 * screen-size code at +0x15, i.e. slot +0x08 and slot +0x1d.
 *
 * The three write modes, on the seventh argument:
 *     0x11     entry = value
 *     0x10     entry = value + (entry & 0xf000)      keep the palette nibble
 *     other    entry = (u16)(value + (mode << 12))   fold the mode in
 * The third form is loop-invariant and is materialised once in the preheader.
 * func_02040EE0 is called once per cell, before the dispatch, so its result
 * has to be bound to a local; writing the call out in each arm emits it three
 * times.
 *
 * WHAT CLOSED IT (wave 2 of this family).  docs/notes/func_02042D2C.c.txt
 * recorded an 11-byte plateau at +0x10..+0x18, three mutually independent
 * prologue instructions issued in a different order:
 *     +0010  orig mov sb, r1          got ldr r7, [sp, #0x38]
 *     +0014  orig str r2, [sp]        got mov sb, r1
 *     +0018  orig ldr r7, [sp, #0x38] got str r2, [sp]
 * and concluded it was the instruction scheduler, hence unreachable from C.
 * That conclusion was wrong, and so was the premise it rested on: the note
 * argued the seventh parameter must be u32 because it arrives by `ldr` and
 * not `ldrb`.  A u8 stack argument also occupies a full word of the argument
 * area and is also loaded with `ldr`, so the load width says nothing about
 * the declared type.  Declaring
 *     u8 mode
 * instead of u32 is the whole fix, and it closes all 11 bytes at once: the
 * narrower type gives the value a different spill cost, which moves its home
 * load behind the other two prologue instructions.  Nothing else in the body
 * changed.  tools/permuter.py found it with --types (mutation
 * `type:p(mode:u32->u8)`); the earlier permute.py pass recorded in the note
 * had no type mutation and so could not reach it.
 *
 * All seven parameter types are pinned by the diff: `s` pointer, `u16 value`,
 * `u8 x0`, `u8 y0`, `u8 w`, `u8 h`, `u8 mode`.  Every other choice blows the
 * function up: value as u32 costs 157 bytes, x0 as u32 170, y0 as u32 190,
 * the helper result as u16 107.
 *
 * This unblocks src/pending/func_02041300.c (fan-in 224), which needed all
 * three blitters as `matched` witnesses and now has them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02042D2C.c \
 *       --func func_02042D2C --addr 0x02042D2C --arm --cc 1.1p1
 */
void func_02042D2C(struct Bg *s, u16 value, u8 x0, u8 y0, u8 w, u8 h,
                   u8 mode)
{
    u8   width;
    u8   height;
    u16 *entries;
    u8   x;
    u8   y;

    entries = (u16 *)s->buf;
    if (entries == 0) {
        return;
    }

    func_020422D4(s->unk_15, &width, &height);

    for (y = y0; y < y0 + h; y++) {
        if (y >= height) {
            return;
        }

        for (x = x0; x < x0 + w; x++) {
            u32 i;

            if (x >= width) {
                break;
            }

            i = func_02040EE0(x, y, s->unk_15);

            if (mode == 0x11) {
                entries[i] = value;
            } else if (mode == 0x10) {
                entries[i] = value + (entries[i] & 0xf000);
            } else {
                entries[i] = (u16)(value + (mode << 12));
            }
        }
    }
}


/*
 * The 8bpp-screen fill of the three blitters func_02041300 dispatches to on
 * the bit-depth byte at +0x1c of the 0x2c-byte slot.  It takes the slot's
 * sub-object (slot + 8) rather than the slot index, so the buffer pointer is
 * at +0x00 and the screen-size code at +0x15, which are slot +0x08 and
 * +0x1d, the same two fields src/matched/func_020413B0.c reaches through the
 * table.
 *
 * Same clip-and-scan shape as func_020413B0, and the same two loop-shape
 * rules apply here: the y bound is only the `for` condition (the compiler's
 * loop-rotation entry test is the guard), and the x bound stays the
 * expression `x < x0 + w` so that it is hoisted into the outer preheader,
 * after the y guard rather than before it.  Both bounds are signed compares
 * (a sum of two u8 has type int); both clip tests against width and height
 * are unsigned, because there both sides are u8.
 *
 * The screen-size code is re-read from the object on every store, since the
 * store through the buffer pointer may alias it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02042E34.c \
 *       --func func_02042E34 --addr 0x02042E34 --cc 1.1p1 --arm
 */
void func_02042E34(struct Bg *s, u8 value, u8 x0, u8 y0, u8 w, u8 h)
{
    u8  width;
    u8  height;
    u8 *pixels;
    u8  x;
    int yEnd;

    pixels = (u8 *)s->buf;
    if (pixels == 0) {
        return;
    }

    func_020422D4(s->unk_15, &width, &height);

    yEnd = y0 + h;

    for (; y0 < yEnd; y0++) {
        if (y0 >= height) {
            return;
        }
        for (x = x0; x < x0 + w; x++) {
            if (x >= width) {
                break;
            }
            pixels[func_02040EE0(x, y0, s->unk_15)] = value;
        }
    }
}


/*
 * The text-screen fill of the three blitters func_02041300 dispatches to.
 * Like func_02042E34 it takes the slot's sub-object (slot + 8), so the
 * buffer pointer is at +0x00 and the screen-size code at +0x15, but the
 * buffer is a linear u16 screen here: the row base is `width * y`, not the
 * tiled func_02040EE0 mapping.
 *
 * The seventh argument is the write mode and decides what lands in the
 * entry: 0x11 writes the value as it stands, 0x10 keeps the existing palette
 * nibble and adds the value to it, and anything else folds the mode itself
 * into bits 12-15.  That last form is loop-invariant, so the compiler
 * materialises it once in the outer preheader (the `lsl #0x10 / lsr #0x10`
 * pair at +0x54 is the u16 narrowing of it); writing it as a local computed
 * before the nest would instead put it ahead of the y guard.
 *
 * Loop shape.  Both bounds are expressions in their own `for` condition,
 * `y < y0 + h` and `x < x0 + w`, over loop variables distinct from the two
 * origin parameters, and the row base is the subscript `entries[width * y +
 * x]` rather than a hoisted row pointer.  Every other arrangement is right
 * to within a register permutation and wrong by eleven bytes: binding either
 * bound to a local before the nest moves it ahead of the guard it belongs
 * behind and rotates the four scratch registers holding the bounds, the
 * width and the height.  The subscript form is also what puts the scaled x
 * in the base slot of the store, `strh r7, [sl, r1]` rather than
 * `[r3, sl]`.
 *
 * The mode arrives on the stack as a full word (`ldr`, not `ldrb`), so it is
 * `u32` here even though func_02041300 hands it a value that fits in a byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02042ED8.c \
 *       --func func_02042ED8 --addr 0x02042ED8 --cc 1.1p1 --arm
 */
void func_02042ED8(struct Bg *s, u16 value, u8 x0, u8 y0, u8 w, u8 h,
                   u32 mode)
{
    u8   width;
    u8   height;
    u16 *entries;
    u8   x;
    u8   y;

    entries = (u16 *)s->buf;
    if (entries == 0) {
        return;
    }

    func_020422D4(s->unk_15, &width, &height);

    for (y = y0; y < y0 + h; y++) {
        if (y >= height) {
            return;
        }

        for (x = x0; x < x0 + w; x++) {
            if (x >= width) {
                break;
            }
            if (mode == 0x11) {
                entries[width * y + x] = value;
            } else if (mode == 0x10) {
                entries[width * y + x] =
                    value + (entries[width * y + x] & 0xf000);
            } else {
                entries[width * y + x] = (u16)(value + (mode << 12));
            }
        }
    }
}


/*
 * Poke one tile entry into the screen buffer of table slot `idx`.  The
 * table is the 0x2c-byte-per-slot array hanging off the singleton pointer
 * at 0x02146A44 (the same one sub_020403F4 tears down): +8 is the screen
 * buffer and +0x1d the screen-size code that tells func_02040EE0 how to
 * fold (x, y) into a linear index.  A slot with no buffer is skipped.
 *
 * The three `and rN, rM, #0xff` are the truncations at the call, not casts
 * in this function's own arithmetic; func_02040EE0 takes three u8.
 */
void sub_02042FB0(u32 idx, u32 x, u32 y, u16 value)
{

    u16 *screen = (u16 *)g_02146A44->bgs[idx].buf;
    u32 code = g_02146A44->bgs[idx].unk_15;

    if (screen == 0) {
        return;
    }

    screen[(u32)func_02040EE0((u8)x, (u8)y, (u8)code)] = value;
}


/*
 * The reserve half of the pair whose release half is sub_02043094: same
 * arena selection by slot index (0..3 at +0x168, 4..7 at +0x16c, anything
 * else a no-op), same bias by the per-slot base at +0x190 and the same
 * round-up of the byte length to 32-byte units, but handed to
 * func_020341F0 instead of func_0203422C.
 *
 * Codegen note: the round-up flag must be spelled as the ternary
 * `(size & 0x1f) ? 1 : 0`; see sub_02043094.c for why the relational form
 * reschedules.
 */
void sub_02042FF8(u32 idx, u32 offset, u32 size)
{
    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_020341F0(g_02146A44->unk_168,
                          (offset + g_02146A44->unk_190[idx]) >> 5, count);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_020341F0(g_02146A44->unk_16c,
                          (offset + g_02146A44->unk_190[idx]) >> 5, count);
        }
        break;
    }
}


/*
 * Release one block back to whichever of the two arenas the slot index
 * names.  Slots 0..3 belong to the arena at +0x168 of the singleton hanging
 * off 0x02146A44, slots 4..7 to the one at +0x16c, and any other index is a
 * no-op.  The byte offset is biased by the per-slot base at +0x190 and the
 * byte length rounded up, both converted to 32-byte units before
 * func_0203422C sees them.  The index is not rebased for the second arena:
 * both arms read unk_190[idx] with the raw index.
 *
 * Codegen note: the round-up flag has to be spelled as the ternary
 * `(size & 0x1f) ? 1 : 0`, not as the relational `(size & 0x1f) != 0`.
 * Both are `tst`/`movne`/`moveq`, but the relational form is folded into
 * the argument expression and the scheduler then hoists the global load
 * above it, spilling the flag into lr; the ternary is materialised as its
 * own value first, which keeps ip free and reproduces the original order.
 */
void sub_02043094(u32 idx, u32 offset, u32 size)
{
    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_0203422C(g_02146A44->unk_168,
                          (offset + g_02146A44->unk_190[idx]) >> 5, count);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_0203422C(g_02146A44->unk_16c,
                          (offset + g_02146A44->unk_190[idx]) >> 5, count);
        }
        break;
    }
}


/*
 * Reorder an 8x8 tile in place, using one 0x40-byte scratch tile from the
 * heap the caller names in `page` (its low 15 bits, with bit 15 set).
 *
 *  - bit 0 of `flags` mirrors every 8-byte row horizontally: the scratch
 *    tile is filled with the row's bytes taken in reverse and copied back
 *    over the original, so the tile is transformed through the scratch.
 *  - bit 1 rotates the eight rows by reversing their order, one memcpy per
 *    row straight into the scratch tile, then one memcpy back.
 * `flags` is tested with `tst`/`beq`, so 0 means "nothing to do" and the
 * early `popeq` is the whole prologue.
 *
 * Shape notes:
 *  - The heap id is a u16 local, not a cast expression: the original
 *    truncates `page` to u16 *before* the mask (`lsl #0x10` /
 *    `and r0, r1, r0, lsr #16`) and truncates again after the `orr`, which
 *    only falls out of `heap = (u16)page; heap = (heap & 0x7FFF) | 0x8000;`.
 *  - Both loop counters are u8: the increments carry the `and #0xff` that
 *    an int counter does not.
 *  - The two memcpy pairs through `tmp` are what make this a three-call
 *    shape; the helper at 0x02082D44 is the project's 8-bit copy.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02043130.c \
 *       --func func_02043130 --addr 0x02043130 --cc 1.1p1 --arm
 */
void func_02043130(u16 flags, u8 *buf, u32 page)
{
    u8 *tmp;
    u16 heap;
    u8 i;
    u8 j;

    if (flags == 0) {
        return;
    }

    heap = (u16)page;
    heap = (heap & 0x7FFF) | 0x8000;

    tmp = func_02030734(heap, 0x40, 0,
                        (const char *)func_02043130_File, 0xD48);

    if (flags & 1) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                tmp[i * 8 + j] = buf[i * 8 + (7 - j)];
            }
        }
        func_02082D44(buf, tmp, 0x40);
    }

    if (flags & 2) {
        for (i = 0; i < 8; i++) {
            func_02082D44(tmp + i * 8, buf + (7 - i) * 8, 8);
        }
        func_02082D44(buf, tmp, 0x40);
    }

    func_020307B0(tmp);
}


/*
 * The 16-bit member of the set / add / subtract family that sub_02043264
 * and sub_020432E4 cover for the 32-bit registers: opcodes 0..2 on the
 * halfword at +0x18.  Three comparisons rather than a table, because the
 * arms are too few to be worth one; the last arm is folded into predicated
 * `ldrheq`/`subeq`/`strheq` in the fall-through block and only the first
 * two get out-of-line bodies.
 */
void sub_02043228(struct Bg *p, u32 op, u16 value)
{
    switch (op) {
    case 0:
        p->unk_18 = value;
        break;
    case 1:
        p->unk_18 = p->unk_18 + value;
        break;
    case 2:
        p->unk_18 = p->unk_18 - value;
        break;
    }
}


/*
 * Apply one of three operations (set / add / subtract) to one of two
 * 32-bit scroll registers of the object, at +0x1c and +0x20, selected by
 * the opcode in r1.  Opcodes 0..2 are live case labels with empty bodies:
 * they are what makes the dispatch table start at zero and therefore what
 * makes it exist at all
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).  Their table
 * slots hold a bare `bx lr` rather than a branch, same as the out-of-range
 * default.
 *
 * The companion sub_020432E4 handles opcodes 9..14 on the two registers
 * at +0x24 and +0x28; nothing in this packet covers 15 and above.
 */
void sub_02043264(struct Bg *p, u32 op, u32 value)
{
    switch (op) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        p->unk_1c = value;
        break;
    case 4:
        p->unk_1c = p->unk_1c + value;
        break;
    case 5:
        p->unk_1c = p->unk_1c - value;
        break;
    case 6:
        p->unk_20 = value;
        break;
    case 7:
        p->unk_20 = p->unk_20 + value;
        break;
    case 8:
        p->unk_20 = p->unk_20 - value;
        break;
    }
}
