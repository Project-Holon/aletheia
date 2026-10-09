/*
 * file:     save_control_intr.c
 * unit:     yes
 * function: func_021BC2FC, func_021BC3B8, func_021BC3E4, func_021BC430, func_021BC4A4, func_021BC4EC, func_021BC52C, func_021BC568, func_021BC62C, func_021BC734, func_021BC75C, func_021BC84C, func_021BC870, func_021BC8AC, func_021BC944, func_021BC9C0, func_021BC9E8, func_021BCCBC, func_021BCCCC, func_021BCCF4, func_021BCD64, func_021BCD88, func_021BCDB4, func_021BCDD0, func_021BCDEC, func_021BCE20, func_021BCE3C, func_021BCE70, func_021BCE80, func_021BCF18, func_021BCF44, func_021BCF6C, func_021BCFD4, func_021BCFEC, func_021BD04C, func_021BD078, func_021BD0C8, func_021BD0D8, func_021BD0F4, func_021BD10C, func_021BD118, func_021BD188, func_021BD1EC, func_021BD21C, func_021BD23C, func_021BD25C, func_021BD29C, func_021BD2B0, func_021BD2F4, func_021BD368, func_021BD374, func_021BD380, func_021BD39C, func_021BD3A0
 * address:  0x021BC2FC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020070A4  0x020070A4  thumb
 *   func_02005B04  0x02005B04  thumb
 *   func_02008730  0x02008730  thumb
 *   func_02008494  0x02008494  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02008314  0x02008314  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0203133C  0x0203133C  arm
 *   func_02007210  0x02007210  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021DFC20  0x021DFC20  thumb  ov228
 *   func_021DFE90  0x021DFE90  thumb  ov228
 *   func_021DFEB0  0x021DFEB0  thumb  ov228
 *   func_021DFDB8  0x021DFDB8  thumb  ov228
 *   func_02011EEC  0x02011EEC  thumb
 *   func_0216C0C0  0x0216C0C0  thumb  ov010
 *   func_020315D4  0x020315D4  arm
 *   func_020312F8  0x020312F8  arm
 *   ov228_id       0x000000E4  data
 *   d_0209DF9C     0x0209DF9C  data  a4
 *   func_0203159C  0x0203159C  arm
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_020312CC  0x020312CC  arm
 *   func_02008450  0x02008450  thumb
 *   d_021BD830     0x021BD830  data  a4
 *   func_02008448  0x02008448  thumb
 *   func_0200C31C  0x0200C31C  thumb
 *   func_020070C8  0x020070C8  thumb
 *   func_02008414  0x02008414  thumb
 *   func_0200890C  0x0200890C  thumb
 *   func_0200C324  0x0200C324  thumb
 *   func_020084E4  0x020084E4  thumb
 *   func_0200854C  0x0200854C  thumb
 *   func_02005728  0x02005728  thumb
 *   func_0200852C  0x0200852C  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 *   func_02008550  0x02008550  thumb
 *   func_02008558  0x02008558  thumb
 *   func_0203064C  0x0203064C  arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_020450C8 0x020450C8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_020083EC  0x020083EC  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_0207D534  0x0207D534  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_02045088  0x02045088  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_0204E720  0x0204E720  arm
 *   d_021BD8B8     0x021BD8B8  data  ov088  a4
 *   d_021BD848     0x021BD848  data  a4
 *   d_021BD858     0x021BD858  data  a4
 *   d_021BD878     0x021BD878  data  a4
 *   d_021BD898     0x021BD898  data  a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045B38  0x02045B38  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045334  0x02045334  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020452E8 0x020452E8 arm
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02035C08  0x02035C08  arm
 *   d_021BD83C     0x021BD83C  data  a1
 *   tbl_020A1B38   0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02049624  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   func_0204E804  0x0204E804  arm
 *   d_021BD944     0x021BD944  data  a4
 *   d_021BD8F4     0x021BD8F4  data  a4
 *   d_021BD904     0x021BD904  data  a4
 *   d_021BD924     0x021BD924  data  a4
 *   d_021BD574     0x021BD574  data  a4
 *   ov088_id       0x00000058  data  a1
 *   func_0201FEBC  0x0201FEBC  thumb
 *   func_0202F0B0  0x0202F0B0  thumb
 *   d_021BDA20     0x021BDA20  data  a4
 *   func_0202EE30  0x0202EE30  thumb
 *   func_02045730  0x02045730  arm
 *   func_02005654  0x02005654  thumb
 *   func_021DFF18  0x021DFF18  thumb  ov228
 *   func_02007230  0x02007230  thumb
 *   func_0200725C  0x0200725C  thumb
 *   func_02007400  0x02007400  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_0200566C  0x0200566C  thumb
 *   func_02087BCC  0x02087BCC  arm
 *   func_0204335C  0x0204335C  arm
 *   d_021BD9B0     0x021BD9B0  data  a4
 *   func_020434DC  0x020434DC  arm
 *   func_02040EBC  0x02040EBC  arm
 *   d_021BD980     0x021BD980  data  a4
 *   d_021BD990     0x021BD990  data  a4
 *   func_020461E4  0x020461E4  arm
 *   func_020461D4  0x020461D4  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0203101C  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_020419E4  0x020419E4  arm
 *   SDK_AUTOLOAD_DTCM_START 0x02fe0000 data
 *   func_020056A0  0x020056A0  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02013080  0x02013080  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_020310C4  0x020310C4  arm
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201FDA0  0x0201FDA0  thumb
 *   func_02030734  0x02030734  arm
 *   func_020071EC  0x020071EC  thumb
 *   func_020351F8  0x020351F8  arm
 *   d_021BDA0C     0x021BDA0C  data  ov088  a4
 *   d_021BD3B9     0x021BD3B9  data  ov088  a1
 *   func_02007150  0x02007150  thumb
 *   func_02008764  0x02008764  thumb
 *   func_02007218  0x02007218  thumb
 *   func_02007214  0x02007214  thumb
 *   func_0200721C  0x0200721C  thumb
 *   func_02031E70  0x02031E70  arm
 *   func_02007168  0x02007168  thumb
 */
#include "../../matched/include/Obj03676.h"
#include "../../matched/include/Obj09923.h"
#include "../../matched/include/Obj02128.h"
#include "../../matched/include/Obj20830.h"
#include "../../matched/include/Obj06206.h"
#include "../../matched/include/Obj00578.h"
#include "../../matched/include/Obj04350.h"
#include "../../matched/include/Obj04351.h"
#include "../../matched/include/Obj13237.h"

#define W(o) (*(u32 *)(p + (o)))
#define reg_G2_BLDCNT      (*(volatile u16 *)0x04000050)
#define reg_G2S_DB_BLDCNT  (*(volatile u16 *)0x04001050)
#define reg_GX_DISPCNT     (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)
struct Sub02007084Ctrl;
struct Sub020071E4Ctrl;
struct Sub0200852CObj;
struct Sub02008700Obj;
struct S020314B8;
struct S020315D4;
struct Obj0203159C;
struct Flags02008450;
struct Blk34;
struct Flags02008414;
struct Sub02008828Rec;
struct U16Vec;
struct W;
struct GfFont;
struct DispConfig;
struct DispVram;
struct BgTemplate;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Rec;
struct Descriptor;
struct Ctrl;
struct Sub020072A4Ctrl;
struct Tcbl;
struct S02031140;
struct Node;
struct Ctx;
struct Rec3;
struct Sub02007168;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Rec12 {
    u32 a, b, c;
} Rec12;

typedef short s16_021BC2FC;

typedef struct S1C {
    u16 f0;
    u16 pad;
    Rec12 rec;
    u32 x, y;
    s16_021BC2FC f18;
    s16_021BC2FC f1a;
} S1C;

typedef unsigned long long u64;

typedef signed int     s32;

typedef signed short s16_021BC52C;

typedef struct C12 {
    char c[12];
} C12;

typedef signed short s16;

typedef struct W {
    u8 pad[0x18];
    u16 f18;
    u16 f1a;
} W;

typedef enum { Z0 } Zero;

typedef struct {
    u16 state;
    u16 pad;
    int count;
} St_021BC2FC;

typedef struct Banks {
    u32 w[12];
} Banks;

typedef struct A16 {
    u32 w[4];
} A16;

typedef struct B32 {
    u32 w[8];
} B32;

typedef struct {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned short e;
} Rect6;

typedef struct {
    void *h;
    u8 s4;
    u8 s5;
    u8 s6;
    u8 s7;
    u32 v8;
    u32 vC;
} St_021BD2B0;

typedef struct {
    void *h;
    u8 s4;
    u8 s5;
    u8 s6;
    u8 s7;
    u32 v8;
    u32 vC;
} St;

extern struct Sub02007084Ctrl *func_020070A4(void);
extern void func_02005B04(const u32 *arg);
extern struct Sub0200852CObj *func_02008730(void *sys);
extern void func_02008494(void *, void *);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void func_02008314(void *, void *);
extern u32 func_020307B0(void *p);
extern void func_0203133C(struct S020314B8 *p);
extern u8 func_02007210(const struct Sub020071E4Ctrl *ctrl);
extern int func_02034AC4(int id);
extern void func_02034A5C(int id);
extern void *func_021DFC20(u32 heap);
extern u8 func_021DFE90(u8 *p);
extern void func_021DFEB0(char *p, void *ctrl);
extern void func_021DFDB8(void *);
extern void *func_02011EEC(u32 a0, u16 a1, struct Rec12 *a2, int a3);
extern int func_0216C0C0(int);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020312F8(u32 a1, u32 a2, u32 a3);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_0200C0F0(void *sys);
extern void func_020312CC(u32 a0, u32 a1, u32 a2);
extern void func_02008450(struct Flags02008450 *p, int on);
extern unsigned int func_02008448(int a0);
extern u8 func_0200C31C(struct Blk34 *p);
extern int func_020070C8(char *self);
extern u8 func_02008414(const struct Flags02008414 *p);
extern void func_0200890C(void *sys, struct Sub02008828Rec *dest);
extern void func_0200C324(struct Blk34 *p, u8 v);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void func_0200854C(int, int);
extern u32 func_02005728(u32 range);
extern void func_0200852C(struct Sub0200852CObj *obj, u32 value);
extern u32 func_0203F0A8(void);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02008558(struct Sub0200852CObj *obj, u8 value);
extern void func_0203064C(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0201D83C(void *ptr);
extern void func_020450C8(void);
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);
extern void func_020306F0(u32 a);
extern void func_020083EC(unsigned short *p, unsigned int v);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02045088(u16 heapId);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(int a);
extern void func_020409B4(unsigned int a);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(struct Cfg *cfg);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201C7A4(void *x, s16_021BC52C y, s16_021BC52C z, void *s, void *w);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern int func_02035C08(const void *p);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void  func_02082BCC(void *p, int v, int n);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern int func_0204E804(void);
extern u32 func_0201FEBC(u8 *p);
extern void func_0202F0B0(u8 *p);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern u8 func_02045730(struct Descriptor *p);
extern int func_02005654(int a, int b);
extern void func_021DFF18(u32 heap);
extern void *func_02007230(struct Sub020071E4Ctrl *ctrl);
extern u32 func_0200725C(struct Ctrl *ctrl, u32 id, u8 heap);
extern void func_02007400(char *a0, u32 a1, u32 a2);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern void func_0200566C(void);
extern void func_02087BCC(u32 parameter);
extern void func_0204335C(u32 keep);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02040EBC(u32 a0, u32 a1);
extern u8 func_020461E4(void);
extern void func_020461D4(u8);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02028590(u32 a0, u32 a1, u32 a2, u32 heap);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern void func_020419E4(void);
extern void *func_020056A0(void (*)(void), void *, int);
void func_02030EAC(struct Node *n);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern signed char func_02013080(u32 idx);
extern int func_0201CCE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6, u32 a7,
                          u32 a8, u16 a9, u16 a10);
extern void func_02041B6C(u32 bit);
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern void func_0201CE38(void *);
extern void func_0201CE48(struct Rec3 *p);
extern void *func_0201FDA0(Rect6 *, int, int, int, int);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern unsigned char func_020071EC(const struct Sub020071E4Ctrl *);
extern void func_020351F8(u32 a, u32 b);
int func_02007150(int a0);
void func_02008764(void *);
u8 func_02007218(const struct Sub020071E4Ctrl *ctrl);
void func_02007214(void *, u32);
void func_0200721C(void *, u32);
extern int func_02031E70(void);
extern u32 func_02007168(struct Sub02007168 *p);
int func_021BC2FC(int a, int b, int c, char *t);
int func_021BC3B8(struct Obj0203159C *a0);
int func_021BC3E4(int a, int *st, int k, int *p);
int func_021BC430(int a, int b, int c, u32 *q);
void func_021BC4A4(int a, int b, int c);
int func_021BC4EC(struct Obj0203159C *a, int b, int *c);
int func_021BC52C(int a,int b,int c,u8 *p);
int func_021BC568(int a, int b, int *s, int *q);
void func_021BC62C(char *p);
void func_021BC734(const void *p,int bg);
void func_021BC75C(u8 *p);
void func_021BC84C(u8 *p);
void func_021BC870(unsigned char *p);
int func_021BC8AC(u8 *p);
s32 func_021BC944(W *w);
int func_021BC9C0(struct Obj0203159C *a0);
int func_021BC9E8(int a0, int a1, int *mode, St_021BC2FC *st);
int func_021BCCBC(int a0);
int func_021BCCCC(struct Obj0203159C *a0);
int func_021BCCF4(int a, int *st, int c, void *p);
int func_021BCD64(int a0);
void func_021BCD88(void *p, int *st);
void func_021BCDB4(void *p, int *st);
void func_021BCDD0(void *p, int *st);
void func_021BCDEC(void *p, int *st);
void func_021BCE20(void *p, int *st);
void func_021BCE3C(char *p, int *out);
void func_021BCE70(void);
void func_021BCE80(u8 *p, int *a1);
void func_021BCF18(void *p, int *st);
void func_021BCF44(void);
void func_021BCF6C(void);
void func_021BCFD4(void);
void func_021BCFEC(u8 *p);
void func_021BD04C(unsigned char *p);
void func_021BD078(int *p);
void func_021BD0C8(unsigned char *p);
void func_021BD0D8(void);
void func_021BD0F4(void **p);
void func_021BD10C(int *p);
void func_021BD118(int *p, u32 mode);
int func_021BD188(char *p);
void func_021BD1EC(unsigned char *p);
void func_021BD21C(void);
void func_021BD23C(void);
void *func_021BD25C(int a, int b);
void func_021BD29C(void *p);
void func_021BD2B0(St_021BD2B0 *p);
u32 func_021BD2F4(St *p);
void func_021BD368(unsigned char *p);
void func_021BD374(unsigned char *p);
int func_021BD380(unsigned char *p);
void func_021BD39C(int a0);
int func_021BD3A0(unsigned char *p);
extern u8 ov228_id[];
extern char d_0209DF9C[];
extern char d_021BD830[];
extern char d_021BD8B8[];
extern char d_021BD848[];
extern char d_021BD858[];
extern char d_021BD878[];
extern char d_021BD898[];
extern C12 d_021BD83C;
extern s16 tbl_020A1B38[];
extern const u8 d_021BD944[];
extern const u8 d_021BD8F4[];
extern const u8 d_021BD904[];
extern const u8 d_021BD924[];
extern char d_021BD574[];
extern char ov088_id[];
extern void *d_021BDA20;
extern Banks d_021BD9B0;
extern A16 d_021BD980;
extern B32 d_021BD990;
extern unsigned int SDK_AUTOLOAD_DTCM_START;








int func_021BC2FC(int a, int b, int c, char *t)
{
    void *r4 = func_020070A4();
    void *r6;
    Rec12 z = {0, 0, 0};
    func_02005B04((const u32 *)(((struct Obj03676 *)t)->f34));
    func_021BD29C((void *)(((struct Obj03676 *)t)->f2C));
    func_02008494(((struct Obj03676 *)t)->f54, func_02008730(r4));
    func_02008314(((struct Obj03676 *)t)->f58, func_0200873C(r4));
    func_020307B0(((struct Obj03676 *)t)->f54);
    func_020307B0(((struct Obj03676 *)t)->f58);
    func_0203133C((struct S020314B8 *)((struct Obj03676 *)t)->f30);
    if (func_02007210(r4) == 1) {
        func_02034AC4((int)ov228_id);
        r6 = func_021DFC20(1);
        if (func_021DFE90(r6) == 1)
            func_021DFEB0(r6, r4);
        func_021DFDB8(r6);
        func_02034A5C((int)ov228_id);
    }
    r4 = func_02011EEC(0, 0, &z, 0);
    func_0216C0C0(((struct Obj03676 *)t)->f28);
    func_020315D4((struct S020315D4 *)a);
    func_020312F8(-1, (u32)d_0209DF9C, (u32)r4);
    return 1;
}








int func_021BC3B8(struct Obj0203159C *a0)
{
    u32 *q = func_0203159C(a0, 0x5c, 1);

    q[0] = 1;
    q[1] = (u32)func_0200873C(func_020070A4());
    q[3] = (u32)func_0200C0F0(func_020070A4());
    q[2] = 0;
    return 1;
}








int func_021BC3E4(int a, int *st, int k, int *p)
{
    switch (*st) {
    case 0:
        if (k == 0) {
            func_020312CC(-1, (u32)d_021BD830, (u32)p);
        } else if (k == 1) {
            func_02008450((struct Flags02008450 *)p[1], 0);
        } else if (k == 2) {
            func_02008450((struct Flags02008450 *)p[1], 1);
        }
        *st = *st + 1;
        break;
    case 1:
        return 1;
    }
    return 1;
}








int func_021BC430(int a, int b, int c, u32 *q)
{
    S1C s;
    void *r;
    u32 t;
    u8 h;

    r = func_020070A4();
    t = func_02008448((int)((void *)q[1]));
    h = func_0200C31C((void *)q[3]);
    func_020070C8(r);
    func_02008414((const struct Flags02008414 *)func_0200873C(r));
    func_0200890C(r, (struct Sub02008828Rec *)(&s));
    func_020312F8(-1, (u32)d_0209DF9C, (u32)func_02011EEC(1, s.f0, &s.rec, s.f18));
    func_02008450((void *)q[1], t);
    func_0200C324((void *)q[3], h);
    func_020315D4((struct S020315D4 *)a);
    return 1;
}








void func_021BC4A4(int a, int b, int c)
{
    u64 x;
    u32 y;
    func_020084E4((u16 *)a, (struct U16Vec *)b);
    func_0200854C(a, c);
    func_0200852C((struct Sub0200852CObj *)a, func_02005728(-1));
    x = func_0203F0A8();
    y = func_02008550((const struct Sub0200852CObj *)a);
    func_02008558((struct Sub0200852CObj *)a, (u8)((u32)((x * 8) >> 32) + y * 8));
}








/*
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair.
 */
int func_021BC4EC(struct Obj0203159C *a, int b, int *c)
{
    char *r;
    func_0203064C(1, 0x39, 0x80000);
    r = func_0203159C(a, 0x1c, 0x39);
    if (*c == 0)
        ((struct Obj09923 *)r)->f4 = 0;
    else
        ((struct Obj09923 *)r)->f4 = 2;
    ((struct Obj09923 *)r)->f18 = 0;
    func_021BC62C(r);
    func_021BC75C((u8 *)r);
    return 1;
}







int func_021BC52C(int a,int b,int c,u8 *p) { func_021BC84C(p);func_0201D83C((void *)(((struct Obj02128 *)p)->f8));func_020450C8();func_020403F4(3);func_020403F4(1);func_020403F4(5);func_0203F9B4();func_020315D4((struct S020315D4 *)a);func_020306F0(0x39);return 1; }








int func_021BC568(int a, int b, int *s, int *q)
{
    int r;

    switch (q[1]) {
    case 0:
        r = func_021BC8AC((u8 *)q);
        if (r != 0) {
            if (r == 1)
                func_020083EC((void *)s[1], 0);
            else
                func_020083EC((void *)s[1], 1);
            func_021BC84C((u8 *)q);
            q[1] = 1;
            func_021BC75C((u8 *)q);
        }
        break;
    case 1:
        r = func_021BC8AC((u8 *)q);
        if (r != 0) {
            if (r == 1)
                func_0200854C((int)((struct Sub0200852CObj *)s[2]), 0);
            else
                func_0200854C((int)((struct Sub0200852CObj *)s[2]), 1);
            func_021BC84C((u8 *)q);
            q[1] = 2;
            func_021BC75C((u8 *)q);
        }
        break;
    case 2:
        r = func_021BC8AC((u8 *)q);
        if (r != 0) {
            if (r == 1)
                func_02008450((void *)s[1], 1);
            else
                func_02008450((void *)s[1], 0);
            func_0202208C(0, 0, 0, 0, 0xc, 1, 0x39);
            q[1] = 3;
        }
        break;
    case 3:
        if (func_020221A4() == 1)
            return 1;
        break;
    }
    func_021BC944((struct W *)q);
    return 0;
}








/*
 * The POWCNT clear is spelled `& ~0x8000` (the SDK display-select inline):
 * the original pools 0xFFFF7FFF, where `&= 0x7FFF` derives the mask from
 * the -16 already in a register.  The four ov088 data hints were contested
 * or unwitnessed with the ov088 token; without it they resolve as sole-ref.
 */
void func_021BC62C(char *p)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_02043534(0);
    func_020435F4(0);
    func_020433E0((const struct DispVram *)d_021BD8B8);
    func_0203F8F4(0x39);
    func_0203FC28((struct DispConfig *)d_021BD848);
    *(u16 *)0x04000304 = (u16)(*(u16 *)0x04000304 & ~0x8000);
    func_021BC734(d_021BD858, 3);
    func_021BC734(d_021BD878, 1);
    func_021BC734(d_021BD898, 5);
    func_02045088(0x39);
    func_02049B40(0x17, 5, 0, 0, 0x20, 0x39);
    func_02049B40(0x17, 5, 4, 0, 0x20, 0x39);
    ((struct Obj20830 *)p)->f8 = (u32)func_0201D7EC(0x17, 0, 0, 0, 0x39);
    func_0201F5BC(1, 1, 3, 0, 0x39);
    func_0201F5BC(1, 0x1f, 4, 0, 0x39);
    func_0201F5BC(5, 1, 1, 0, 0x39);
    *(u16 *)0x05000000 = 0x7D8C;
    *(u16 *)0x05000400 = 0x7D8C;
    func_0204E720(3, 0x10, 0, 0);
}







void func_021BC734(const void *p,int bg) { func_0203FCA0(bg,p,0);func_02040588(bg,1);func_020414AC(bg);func_020409B4(bg); }








void func_021BC75C(u8 *p)
{
    u32 arc;
    u32 s;
    u8 i;
    u8 *q;

    arc = (u32)func_02045B38(0, 2, 0xab, 0x39);
    p[0] = 0;
    W(0xc) = func_020450F0((int)5, (int)1, (u8)0x13, (int)0x1d, (int)4, (int)0, (int)1);
    func_02045374((struct Cfg *)W(0xc));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)W(0xc))), 0xf);
    s = (u32)func_02045EC0((struct MsgBank *)arc, W(4));
    func_0201F73C((void *)W(0xc), 0, 1, 1);
    func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)W(0xc))), 2, 2, (void *)s, (void *)W(8));
    func_02045808((struct U16Vec *)s);
    func_02045334((struct Descriptor *)W(0xc));
    for (i = 0; i < 2; i++) {
        q = p + i * 4;
        ((struct Obj06206 *)q)->f10 = func_020450F0((int)1, (int)6, (u8)(i * 4 + 0xc), (int)0x14, (int)2, (int)0, (int)1);
        func_02045374((struct Cfg *)(((struct Obj06206 *)q)->f10));
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj06206 *)q)->f10)), 0xf);
        s = (u32)func_02045EC0((struct MsgBank *)arc, i + 5 + W(4) * 2);
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)((struct Obj06206 *)q)->f10)), 2, 2, (void *)s, (void *)W(8));
        func_02045808((struct U16Vec *)s);
        func_02045334((struct Descriptor *)((struct Obj06206 *)q)->f10);
    }
    func_02045C04((struct Rec *)arc);
    func_021BC870(p);
}







void func_021BC84C(u8 *p) { u8 i; func_020452E8(((struct Obj02128 *)p)->fC); for(i=0;i<2;i++) func_020452E8(*(void **)((u32)p+((u32)i*4)+16)); }







void func_021BC870(unsigned char *p) { unsigned char i; for(i=0;i<2;i++) { if(i==p[0]) func_0201F73C((void *)(*(unsigned *)(p+16+4*i)),0,1,3); else func_0201F73C((void *)(*(unsigned *)(p+16+4*i)),0,31,4); } }







int func_021BC8AC(u8 *p)
{
    int r;
    u32 k;
    int t;
    C12 s;

    if ((func_020362DC() & 0x40) || (func_020362DC() & 0x80)) {
        if (p[0] == 0)
            p[0] = 1;
        else
            p[0] = 0;
        func_021BC870(p);
        func_020061E4(0x548);
    }
    k = func_020362DC();
    r = 1;
    if (k & r) {
        func_020061E4(0x54C);
        if (p[0] != 0)
            r = 2;
        return r;
    }
    s = d_021BD83C;
    t = func_02035C08(&s);
    if (t != -1) {
        func_020061E4(0x54C);
        return t == 0 ? 1 : 2;
    }
    return 0;
}







s32 func_021BC944(W *w)
{
    s32 n = w->f18 + 0x400;
    s32 v;
    s16 s;
    u32 b, g, r;

    if (n >= 0x10000)
        w->f18 = w->f18 - 0xFC00;
    else
        w->f18 = n;
    v = tbl_020A1B38[(w->f18 >> 4) * 2 + 1] + 0x1000;
    s = v / 2;
    b = (u8)(0x1d + (-(s * 8) >> 12));
    r = (u8)(0x19 + (s * -0x14 >> 12));
    g = (u8)(0x1e + (s * -0xf >> 12));
    w->f1a = r | (g << 5) | (b << 10);
    return func_02061CA4((void *)0xf, 0x6c, (u32)(&w->f1a), 2);
}







int func_021BC9C0(struct Obj0203159C *a0)
{
    func_0203064C(1, 0x16, 0x70000);
    func_02082BCC(func_0203159C(a0, 8, 0x16), 0, 8);
    return 1;
}







static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}







static inline void GXS_SetVisibleWnd(int window)
{
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0xE000 | (window << 13);
}







/*
 * Case 1's fade call takes its zero from an enum local set at the top of
 * the arm: the enum is not folded, so the zero stays in r5 (the register
 * the stack-argument zeros use) through to `adds r2, r5, #0`. A literal 0,
 * an int local set to 0, and int-typed func_02049624 parameters all give
 * `movs r2, #0` scheduled after r0/r1 (6 bytes out); the permuter (300,
 * --types) found nothing.
 * volatile: DISPCNT 0x04000000 and DB_DISPCNT 0x04001000 read-modify-written by the SDK inlines GX_SetVisibleWnd/GXS_SetVisibleWnd (0x021BCA3A, 0x021BCA46)
 */
int func_021BC9E8(int a0, int a1, int *mode, St_021BC2FC *st)
{
    Zero z;

    switch (st->state) {
    case 0:
        func_02043534(0);
        func_020435F4(0);
        reg_G2_BLDCNT = 0;
        reg_G2S_DB_BLDCNT = 0;
        GX_SetVisibleWnd(0);
        GXS_SetVisibleWnd(0);
        func_020433E0((const struct DispVram *)d_021BD944);
        func_0203F8F4(0x16);
        func_0203FC28((struct DispConfig *)d_021BD8F4);
        func_0203FCA0(1, (const struct BgTemplate *)d_021BD904, 0);
        func_0203FCA0(5, (const struct BgTemplate *)d_021BD924, 0);
        if (*mode == 1) {
            func_0207D534((volatile u16 *)0x0400006C, -16);
            func_0207D534((volatile u16 *)0x0400106C, -16);
            st->state = 7;
        } else {
            func_0207D534((volatile u16 *)0x0400006C, 16);
            func_0207D534((volatile u16 *)0x0400106C, 16);
            st->state = 1;
        }
        break;
    case 1:
        z = Z0;
        func_02049624((void *)0x1a, (void *)0xc, (void *)1, 0, 0, 1, 0x16);
        func_0204989C(0x1a, 0xd, 1, 0, 0, 1, 0x16);
        func_02049B40(0x1a, 0xb, 0, 0, 0, 0x16);
        func_02049624((void *)0x1a, (void *)0xc, (void *)5, 0, 0, 1, 0x16);
        func_0204989C(0x1a, 0xe, 5, 0, 0, 1, 0x16);
        func_02049B40(0x1a, 0xb, 4, 0, 0, 0x16);
        func_02040588(1, 1);
        func_02040588(5, 1);
        func_0204363C(1);
        func_0204361C();
        func_0204E720(0xc, 0x10, z, 2);
        st->state = 2;
        break;
    case 2:
        if (func_0204E804() == 0) {
            st->state = 3;
            st->count = 0;
        }
        break;
    case 3:
        if (++st->count > 0x5a)
            st->state = 4;
        if (func_020362DC() & 0xb)
            st->state = 4;
        break;
    case 4:
        func_0204E720(3, 0, 0x10, 2);
        st->state = 5;
        break;
    case 5:
        if (func_0204E804() == 0) {
            st->state = 6;
            st->count = 0;
        }
        break;
    case 6:
        if (++st->count > 0x1e) {
            st->state = 7;
            st->count = 0;
        }
        break;
    case 7:
        func_02049624((void *)0xa4, (void *)1, (void *)1, 0, 0x8000, 0, 0x16);
        func_0204989C(0xa4, 2, 1, 0, 0, 0, 0x16);
        func_02049B40(0xa4, 0, 0, 0, 0, 0x16);
        func_02049624((void *)0xa4, (void *)3, (void *)5, 0, 0x8000, 0, 0x16);
        func_0204989C(0xa4, 4, 5, 0, 0, 0, 0x16);
        func_02049B40(0xa4, 0, 4, 0, 0, 0x16);
        func_020409B4(1);
        func_020409B4(5);
        func_02040588(1, 1);
        func_02040588(5, 1);
        func_0204363C(1);
        func_0204361C();
        func_0204E720(3, 0x10, 0, 2);
        st->state = 8;
        break;
    case 8:
        if (func_0204E804() == 0)
            st->state = 9;
        break;
    case 9:
        if (++st->count > 0x5a) {
            st->state = 10;
            st->count = 0;
        }
        break;
    case 10:
        func_0204E720(3, 0, 0x10, 2);
        st->state = 0xb;
        break;
    case 11:
        if (func_0204E804() == 0)
            st->state = 0xc;
        break;
    case 12:
        if (++st->count > 0x1e)
            st->state = 0xd;
        break;
    case 13:
        func_0203F9B4();
        return 1;
    }
    return 0;
}







int func_021BCCBC(int a0)
{
    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0x16);
    return 1;
}







int func_021BCCCC(struct Obj0203159C *a0)
{
    func_0203064C(1, 0x81, 0x30000);
    func_02082BCC(func_0203159C(a0, 0x2c, 0x81), 0, 0x2c);
    return 1;
}







/*
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 */
int func_021BCCF4(int a, int *st, int c, void *p)
{
    switch (*st) {
    case 0:
        func_021BCD88(p, st);
        break;
    case 1:
        func_021BCDB4(p, st);
        break;
    case 2:
        func_021BCDD0(p, st);
        break;
    case 3:
        func_021BCDEC(p, st);
        break;
    case 4:
        func_021BCE20(p, st);
        break;
    case 5:
        func_021BCE3C(p, st);
        break;
    case 6:
        func_021BCE80(p, st);
        break;
    case 7:
        func_021BCF18(p, st);
        break;
    case 8:
        return 1;
    }
    return 0;
}







int func_021BCD64(int a0)
{
    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0x81);
    func_020312F8((u32)ov088_id, (u32)d_021BD574, 0);
    return 1;
}







void func_021BCD88(void *p, int *st)
{
    func_021BCF44();
    func_021BCF6C();
    func_021BCFEC(p);
    func_021BD078(p);
    func_021BD0F4(p);
    func_021BD21C();
    *st = 1;
}







void func_021BCDB4(void *p, int *st)
{
    if (func_020221A4() == 1) {
        func_021BD118(p, 0);
        *st = 2;
    }
}







void func_021BCDD0(void *p, int *st)
{
    if (func_021BD188(p) == 0) {
        func_021BD1EC(p);
        *st = 3;
    }
}







void func_021BCDEC(void *p, int *st)
{
    int r = func_0201FEBC(((struct Obj00578 *)p)->f20);

    if (r == 0)
        goto a;
    if (r == -2)
        goto b;
    return;
a:
    func_021BD118(p, 1);
    *st = 4;
    return;
b:
    func_021BD23C();
    *st = 7;
}







void func_021BCE20(void *p, int *st)
{
    if (func_021BD188(p) == 0) {
        func_021BD1EC(p);
        *st = 5;
    }
}







/*
 * EXACT*: the extent runs 20 bytes long; the follower at 0x021BCE70 is an
 * unlabelled tail-call stub (ldr r0,[pc]; ldr r3,[pc]; ldr r0,[r0]; bx r3).
 * The switch value is unsigned so that case 0xFFFFFFFE sorts after case 0.
 */
void func_021BCE3C(char *p, int *out)
{
    unsigned r = func_0201FEBC((u8 *)(*(char * *)&((struct Obj00578 *)p)->f20));
    switch (r) {
    case 0:
        func_021BD118((int *)p, 2);
        *out = 6;
        break;
    case 0xFFFFFFFE:
        func_021BD23C();
        *out = 7;
        break;
    }
}






void func_021BCE70(void)
{
    func_0202F0B0(d_021BDA20);
}






void func_021BCE80(u8 *p, int *a1)
{
    void *r;
    u32 i;

    if (func_021BD188((char *)p) == 0) {
        d_021BDA20 = func_0202EE30(0, ((struct Obj00578 *)p)->f1C, 0xf, 0x10, 0x81);
        func_020409B4(func_02045730(((struct Obj00578 *)p)->f1C));
        func_02005654((int)func_021BCE70, 0);
        r = func_020070A4();
        func_02034AC4((u32)ov228_id);
        func_021DFF18(0x81);
        func_02034A5C((u32)ov228_id);
        func_02007230(r);
        for (i = 0; i < 9; i++) {
            if (func_0200725C(r, i, 0x81) == 1)
                func_02007400(r, i, 0x81);
            func_020072A4(r, i);
        }
        func_0200566C();
        func_02087BCC(0);
    }
}






void func_021BCF18(void *p, int *st)
{
    if (func_020221A4() == 1) {
        func_021BD10C(p);
        func_021BD0C8(p);
        func_021BD04C(p);
        func_021BCFD4();
        *st = 8;
    }
}






void func_021BCF44(void)
{
    Banks b = d_021BD9B0;

    func_0204335C(0);
    func_020433E0((const struct DispVram *)(&b));
}






void func_021BCF6C(void)
{
    A16 a;
    B32 b;

    func_0203F8F4(0x81);
    a = d_021BD980;
    func_0203FC28((struct DispConfig *)(&a));
    b = d_021BD990;
    func_0203FCA0(0, (const struct BgTemplate *)(&b), 0);
    func_020434DC(1, 1);
    func_02040EBC(0, 0x7D8C);
    func_02040EBC(4, 0x7D8C);
}






void func_021BCFD4(void)
{
    func_020434DC(1, 0);
    func_020403F4(0);
    func_0203F9B4();
}






void func_021BCFEC(u8 *p)
{
    p[0xc] = func_020461E4();
    func_020461D4(0);
    ((struct Obj04350 *)p)->f8 = func_02045B38(0, 2, 1, 0x81);
    ((struct Obj04350 *)p)->f4 = func_0201D7EC(0x17, 0, 0, 0, 0x81);
    ((struct Obj04350 *)p)->f10 = func_020457B0(0x400, 0x81);
    ((struct Obj04350 *)p)->f18 = func_0203101C(0x81, 0x81, 1, 4);
    ((struct Obj04350 *)p)->f24 = func_02028590(0xf, 1, 0, 0x81);
}






void func_021BD04C(unsigned char *p)
{
    func_02028604((int)(((struct Obj04351 *)p)->f24));
    func_02031140(((struct Obj04351 *)p)->f18);
    func_02045808(((struct Obj04351 *)p)->f10);
    func_0201D83C(((struct Obj04351 *)p)->f4);
    func_02045C04(((struct Obj04351 *)p)->f8);
    func_020461D4(p[0x0C]);
}






void func_021BD078(int *p)
{
    int h = 0x81;
    int w = 0x1e;
    func_02045088(0x81);
    p[7] = func_020450F0(0, 1, 0x13, w, 4, 0xf, 1);
    func_0201F5BC(0, 1, 0xe, 0, h);
    func_02049B40(0x17, 5, 0, w << 4, 0x20, h);
}






void func_021BD0C8(unsigned char *p)
{
    func_020452E8(((struct Obj04351 *)p)->f1C);
    func_020450C8();
}






void func_021BD0D8(void)
{
    func_020419E4();
    *(volatile unsigned int *)((char *)&SDK_AUTOLOAD_DTCM_START + 0x3FF8) |= 1;
}






void func_021BD0F4(void **p)
{
    *p = func_020056A0(func_021BD0D8, p, 0);
}






void func_021BD10C(int *p)
{
    func_02030EAC((struct Node *)p[0]);
}





void func_021BD118(int *p, u32 mode)
{
    int t;

    func_02045CAC((struct MsgBank *)p[2], mode, (void *)p[4]);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p[7])), 15);
    func_0201F73C((void *)p[7], 2, 1, 14);
    p[5] = func_0201CCE4(p[7], 0, 0, p[4], p[1], func_02013080(0), p[6], 10, 0x81, 15);
    p[10] = 0;
    t = p[7];
    func_02045334((struct Descriptor *)t);
    func_02045374((struct Cfg *)t);
    func_02041B6C(func_02045730((struct Descriptor *)t));
}





int func_021BD188(char *p)
{
    func_020310C4(((struct Obj00578 *)p)->f18);
    func_020286C4(((struct Obj00578 *)p)->f24, ((struct Obj00578 *)p)->f14, ((struct Obj00578 *)p)->f1C);
    switch (func_0201CE30(((struct Obj00578 *)p)->f14)) {
    case 0:
        ((struct Obj00578 *)p)->f28 = 0;
        break;
    case 1:
        if (((struct Obj00578 *)p)->f28 == 0) {
            if (func_020362DC() & 3) {
                func_020061E4(0x547);
                func_0201CE38(((struct Obj00578 *)p)->f14);
                ((struct Obj00578 *)p)->f28 = 1;
            }
        }
        break;
    case 2:
        func_0201CE48(((struct Obj00578 *)p)->f14);
        ((struct Obj00578 *)p)->f28 = 0;
        return 0;
    }
    return 1;
}





void func_021BD1EC(unsigned char *p)
{
    Rect6 r;
    r.a = 0;
    r.b = 0x18;
    r.c = 0x0D;
    r.d = 0x0F;
    r.e = 0;
    ((struct Obj00578 *)p)->f20 = func_0201FDA0(&r, 1, 0x0E, 1, 0x81);
}





void func_021BD21C(void)
{
    func_0202208C(0, 1, 1, 0, 6, 1, 0x81);
}





void func_021BD23C(void)
{
    func_0202208C(0, 0, 0, 0, 6, 1, 0x81);
}





/*
 * func_020351F8 (arm) resolves through the matched entry
 * src/matched/arm9/sub_020351F8.c.
 */
void *func_021BD25C(int a, int b)
{
    char *r4 = (char *)func_02030734(a, 0x10, 1, (const char *)0x021BDA0C, 0x45);
    ((struct Obj13237 *)r4)->f0 = b;
    if (func_020071EC((const struct Sub020071E4Ctrl *)b) == 1) {
        r4[7] = 1;
    } else {
        func_020351F8(0x021BD3B9, (int)r4);
    }
    return r4;
}





void func_021BD29C(void *p)
{
    func_020351F8(0, 0);
    func_020307B0(p);
}



void func_021BD2B0(St_021BD2B0 *p)
{
    if (p->s7 != 1) {
        func_02007150((int)p->h);
        if (p->s7 == 0) {
            func_02008764(p->h);
            p->v8 = func_02007210(p->h);
            p->vC = func_02007218(p->h);
            func_02007214(p->h, (u32)0);
            func_0200721C(p->h, (u32)0);
        }
        p->s4 = 1;
    }
}




u32 func_021BD2F4(St *p)
{
    u32 r;

    if (p->s7 == 1)
        return 2;
    switch (p->s4) {
    case 1:
        if (p->s6 == 1 && func_02031E70() == 0) {
            p->s5 = p->s4;
            p->s4 = 2;
            return 0;
        }
        r = func_02007168(p->h);
        if (r - 2 <= 1) {
            p->s4 = 3;
            func_02007214(p->h, p->v8);
            func_0200721C(p->h, p->vC);
        }
        return r;
    case 2:
        if (p->s6 == 0)
            p->s4 = p->s5;
        return 0;
    case 3:
        return 2;
    }
    return 0;
}



void func_021BD368(unsigned char *p){if(p[4]!=3)p[6]=1;}



/*
 * Unlabelled Thumb leaf in a .word run at ov088:021BD374.  The caller
 * func_021BE6E8 lives in ov204 (0x021BDA40..), which does not overlap ov088
 * (0x021B95A0..0x021BDA20), the only overlay in the window that its own
 * window does not overlap, so ov088 is the resident copy.
 */
void func_021BD374(unsigned char *p)
{
    if (p[4] != 3)
        p[6] = 0;
}



int func_021BD380(unsigned char *p){if(p[7]==1||p[4]==3)return 1;if(p[4]==2)return 1;return 0;}



/*
 * Unlabelled Thumb leaf in a .word run at ov088:021BD39C: `bx lr` (2 bytes),
 * an empty function called as a no-op by func_021BE6F8.  ov088 is the only
 * overlay in the window not overlapping the caller's ov204.
 */
void func_021BD39C(int a0)
{
}



/*
 * Unlabelled 24-byte predicate. Parent cleared this sole blocker of
 * ov204:021BE708 after SDK/ownership/unit/shard audit. Same object at p+a4
 * is passed by matched ov204:021BE6E8/021BE6F8 to ov088:021BD374/021BD39C;
 * ov204:021BEF20 initializes it from input d+c. Matched ov088:021BD3B8
 * reads the same byte fields (7 and 4), confirming the region inference.
 */
int func_021BD3A0(unsigned char *p)
{
    if (p[7] == 1)
        return 1;
    if (p[4] == 3)
        return 1;
    return 0;
}
