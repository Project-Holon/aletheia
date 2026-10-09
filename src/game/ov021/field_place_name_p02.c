/*
 * file:     field_place_name_p02.c
 * unit:     yes
 * function: func_021BBEF4, func_021BBF10, func_021BBF74, func_021BBF78, func_021BBF9C, func_021BBFB0, func_021BBFB4, func_021BBFB8, func_021BBFF4, func_021BC030, func_021BC048, func_021BC10C, func_021BC138, func_021BC338, func_021BC340, func_021BC388, func_021BC424, func_021BC484, func_021BC4F0, func_021BC550, func_021BC578, func_021BC5A0, func_021BC5BC, func_021BC5D4, func_021BC5E4, func_021BC63C, func_021BC654, func_021BC664, func_021BC6B4, func_021BC6D0, func_021BC6E8
 * address:  0x021BBEF4
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
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_020508C4  0x020508C4  arm
 *   func_0204F6B4  0x0204F6B4  arm
 *   d_021DE320     0x021DE320  data  a4
 *   func_020307B0  0x020307B0  arm
 *   d_021D9B64  0x021D9B64  data
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0219C98C  0x0219C98C  thumb  ov021
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0219C928  0x0219C928  thumb  ov021
 *   func_0219C9E0  0x0219C9E0  thumb  ov021
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_020507D0  0x020507D0  arm
 *   func_020507A0  0x020507A0  arm
 *   func_020507F0  0x020507F0  arm
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_0216D8D0  0x0216D8D0  thumb  ov010
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 *   func_0204F638  0x0204F638  arm
 *   func_0204F5E4  0x0204F5E4  arm
 *   func_0204F604  0x0204F604  arm
 *   func_0204F654  0x0204F654  arm
 *   func_0204F66C  0x0204F66C  arm
 *   func_0204F684  0x0204F684  arm
 *   func_0204F794  0x0204F794  arm
 *   func_0204F748  0x0204F748  arm
 *   func_0204F764  0x0204F764  arm
 *   d_021D9B40     0x021D9B40  data  a4
 *   d_021D9B58     0x021D9B58  data  a4
 *   d_021D9B4C     0x021D9B4C  data  a4
 *   func_021BCF88  0x021BCF88  thumb  ov021
 *   func_021BCFA4  0x021BCFA4  thumb  ov021
 *   func_021BD0E0  0x021BD0E0  thumb  ov021
 *   func_021BC810  0x021BC810  thumb  ov021
 *   func_021BCFE0  0x021BCFE0  thumb  ov021
 *   func_021BCFF0  0x021BCFF0  thumb  ov021
 *   func_021BD008  0x021BD008  thumb  ov021
 *   func_021BD098  0x021BD098  thumb  ov021
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_021BD09C  0x021BD09C  thumb  ov021
 *   func_021BC730  0x021BC730  thumb  ov021
 *   func_021BC75C  0x021BC75C  thumb  ov021
 *   func_021BC794  0x021BC794  thumb  ov021
 *   func_021BC7BC  0x021BC7BC  thumb  ov021
 *   func_021BC998  0x021BC998  thumb  ov021
 *   func_021BC7D4  0x021BC7D4  thumb  ov021
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_021BD01C  0x021BD01C  thumb  ov021
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 *   func_021BD0FC  0x021BD0FC  thumb  ov021
 *   func_021BC7F8  0x021BC7F8  thumb  ov021
 *   func_021BD068  0x021BD068  thumb  ov021
 *   func_021BC9AC  0x021BC9AC  thumb  ov021
 *   func_021BC7B0  0x021BC7B0  thumb  ov021
 *   func_021BC788  0x021BC788  thumb  ov021
 *   func_021BC748  0x021BC748  thumb  ov021
 *   func_021BD040  0x021BD040  thumb  ov021
 *   func_021BD054  0x021BD054  thumb  ov021
 *   func_021BD07C  0x021BD07C  thumb  ov021
 *   func_021BC704  0x021BC704  thumb  ov021
 *   func_021BC824  0x021BC824  thumb  ov021
 *   func_020403F4  0x020403F4  arm
 *   func_021BCFD8  0x021BCFD8  thumb  ov021
 *   func_021BD0B0  0x021BD0B0  thumb  ov021
 *   func_021BD0A4  0x021BD0A4  thumb  ov021
 *   func_021BCC3C  0x021BCC3C  thumb  ov021
 *   func_021BCC80  0x021BCC80  thumb  ov021
 *   func_021BCD34  0x021BCD34  thumb  ov021
 *   func_021BCD70  0x021BCD70  thumb  ov021
 *   func_021BCD84  0x021BCD84  thumb  ov021
 *   func_021BCDD8  0x021BCDD8  thumb  ov021
 *   func_021BCE88  0x021BCE88  thumb  ov021
 *   func_021BC970  0x021BC970  thumb  ov021
 *   func_021BCEAC  0x021BCEAC  thumb  ov021
 *   func_021BCEB0  0x021BCEB0  thumb  ov021
 *   func_021BCEB4  0x021BCEB4  thumb  ov021
 *   func_021BCF18  0x021BCF18  thumb  ov021
 *   func_021BCF1C  0x021BCF1C  thumb  ov021
 *   func_021BCF20  0x021BCF20  thumb  ov021
 *   func_021BCF24  0x021BCF24  thumb  ov021
 *   func_021BD120  0x021BD120  thumb  ov021
 *   func_021BD140  0x021BD140  thumb  ov021
 *   func_021BCBC8  0x021BCBC8  thumb  ov021
 *   func_021BCA78  0x021BCA78  thumb  ov021
 *   func_021BCA64  0x021BCA64  thumb  ov021
 *   func_021BCA80  0x021BCA80  thumb  ov021
 *   func_021BCA6C  0x021BCA6C  thumb  ov021
 *   func_021BC720  0x021BC720  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_021BD090  0x021BD090  thumb  ov021
 *   func_021BD094  0x021BD094  thumb  ov021
 *   func_020493D4  0x020493D4  arm
 *   func_02030734  0x02030734  arm
 *   func_0204932C  0x0204932C  arm
 *   func_02062A98  0x02062A98  arm
 */
struct BbActSys;
struct Manager0204F684;
struct Trip;
struct Actor;
struct VecFx32;
struct BgTemplate;
struct S;
struct Descriptor;
struct Cfg;
struct ArcFile;
struct NitroFileHeader;
typedef unsigned short u16;

typedef struct Head {
    int h0;
    int h4;
} Head;

typedef struct Obj_021BBEF4 {
    Head *head;
    int pad4;
    u16 h8;
} Obj_021BBEF4;

typedef unsigned int   u32;

typedef short s16;

typedef unsigned char u8;

typedef struct Obj_021BBF10 {
    Head *head;
    int pad4;
    u16 h8;
    u16 hA;
    u16 padC;
    s16 h0e;
    int i10;
} Obj_021BBF10;

typedef struct {
    int f0;
} Obj_021BBF78;

typedef signed int     s32;

typedef struct Arg { u32 a; u32 b; u32 c; u32 d; u32 e; } Arg;

typedef struct { u32 w[5]; } Blk;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
    u32 f10;
    Blk blk;
    u32 f28;
    u32 f2C;
} Obj_021BBFF4;

typedef struct {
    char pad[0x10];
    u8 b10;
    char pad2[0xF];
    void *f20;
    int pad24;
    char f28[1];
} Obj_021BC030;

typedef struct { int x, y, z; } V3;

typedef struct Obj_021BC048 {
    int f0;
    int f4;
    int f8;
    int fC;
    u8 b10;
    u8 b11;
    u8 pad12[0x1c - 0x12];
    u32 f1c;
    u32 f20;
    u8 pad24[4];
    u16 h28;
    u16 h2a;
    u8 f2c[4];
} Obj_021BC048;

typedef struct {
    char pad[0x10];
    u8 b10;
    char pad2[0xB];
    void *f1C;
    char pad3[0xA];
    u16 h2A;
    char f2C[1];
} Obj_021BC10C;

typedef short          s16_021BC138;

typedef int            fx32;

typedef struct { fx32 x, y, z; } Vec;

typedef struct {
    u8 pad0[7];
    u8 f7;
} Info;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 padC[0x14 - 0xC];
    u32 *f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Param;

typedef signed short   s16_021BC338;

typedef signed char    s8;

typedef signed short   s16_021BC5BC;

typedef struct { u32 f0; u32 f4; u32 pad8[8]; int f28; u32 pad2C[6]; u16 f44; u16 f46; u32 f48; u32 f4C; } X;

typedef struct {
    void *f0;
    char pad[0x42];
    u16 h46;
} Obj_021BD0E0;

typedef struct {
    char pad[0x10];
    void *f10;
} Obj_021BC810;

typedef struct {
    char pad[8];
    void *f8;
} Obj_021BCFE0;

typedef struct {
    char pad[0x14];
    void *f14;
} Obj_021BCFF0;

typedef struct {
    char pad[0x1C];
    void *f1C;
} Obj_021BD008;

typedef struct {
    char pad[0xC];
    u16 hC;
    char pad2[0x2A];
    void *f38;
} Obj_021BC730;

typedef struct {
    char pad[0x2C];
    void *f2C;
} Obj_021BC75C;

typedef struct {
    char pad[0x34];
    void *f34;
} Obj_021BC794;

typedef struct {
    char pad[0x34];
    void *f34[1];
    void *f38;
} Obj_021BC7BC;

typedef struct {
    char pad[0x30];
    void *f30;
    void *f34;
} Obj_021BC998;

typedef struct {
    char pad[0xC];
    u16 hC;
    char pad2[0x1E];
    void *f2C;
    void *f30;
    char pad3[0x1C];
    void *f50[0x1E];
} Obj_021BC7D4;

typedef struct S {
    char pad[0x14c];
    int a;
    int b;
} S;

typedef struct {
    char pad[0x28];
    int f28;
} Obj_021BC6E8;

typedef struct {
    char pad[0x24];
    void *f24;
} Obj_021BD01C;

typedef struct {
    char pad[0x14C];
    void *f14C;
    int f150;
} Obj_021BC6B4;

typedef struct {
    char pad[0x50];
    void *f50[0x1E];
} Obj_021BC7F8;

typedef struct {
    char pad[0x30];
    void *f30;
} Obj_021BC9AC;

typedef struct {
    char pad[8];
    void *f8;
} Obj_021BD040;

typedef struct {
    char pad[0x24];
    void *f24;
} Obj_021BD07C;

typedef struct {
    char pad[0x28];
    int f28;
} Obj_021BC704;

typedef struct {
    char pad[0x42];
    u16 h42;
} Obj_021BD0B0;

typedef struct {
    char pad[0x42];
    u16 h42;
} Obj_021BC138;

typedef struct {
    char pad[0xC8];
    void *fC8[0x20];
} Obj_021BC970;

typedef struct {
    char pad[0x24];
    void *f24;
} Obj_021BC720;

typedef struct {
    char pad[0xC];
    int fC;
} Inner;

typedef struct {
    char pad[0x150];
    Inner *f150;
} Obj_021BC6D0;

extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern void func_021AC154(int a);
extern u32 func_02050080(u32 *p);
extern u32 func_020508C4(u32 a, u16 b);
extern void func_0204F6B4(u8 *a0, int i, u8 *px);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 func_020307B0(void *p);
extern u32 func_0216D520(void *p);
extern u32 func_0219C9DC(u8 *p);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern int func_021AC1AC(u32 a);
extern int func_0216E1A4(int a0, int a1);
extern void func_0219C98C(u32 a, u16 *b);
extern int func_0216E1C4(int a0, int a1);
extern int func_0216DC34(void *a0);
extern int func_0216D7A8(void *p, unsigned int v);
extern void *func_0216E3C4(void *p);
extern int func_0219C928(u32 a, const u8 *b, u16 *c, V3 *d, u32 s0, u32 s1);
extern void func_0219C9E0(u32 a, u16 *b, u16 *c);
extern u32 func_021ABE14(u8 *p);
extern u16 func_02188C9C(u8 *p);
extern int func_020507D0(u32 a, u16 b);
extern int func_020507A0(void *p, int idx, u32 x);
extern void func_020507F0(void *p, int idx, u32 v);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern void func_0216D8B0(u8 *p, u8 *q);
extern int func_02163E58(u32 a, Vec *v, int *y);
extern void func_0216D8D0(u8 *p, u8 *q);
extern u32 func_0216D7DC(void *p);
extern u16 func_021AB0F8(u32 attr);
extern void *func_02188C58(void *p);
extern u32 func_0218EC2C(u8 *p);
extern void func_02048B30(u32 cam, Vec *out);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern void func_0204F5E4(u8 *a0, u32 i, u16 *out);
extern void func_0204F604(void *p, u32 idx, u16 *src);
extern void func_0204F654(u32 h, u32 i, s16_021BC138 *v);
extern void func_0204F66C(int p0, int p1, int p2);
extern void func_0204F684(struct Manager0204F684 *mgr, int idx, const s16_021BC138 *p12, const s16_021BC138 *p14);
extern void func_0204F794(void *p, u32 idx, u32 *val);
extern u32 func_0204F748(u8 *a0, int i);
extern void func_0204F764(void *p, u32 idx, u32 *val);
extern void *func_021BCF88(int a);
extern void func_021BCFA4(X *x, u32 b);
extern void func_021BD0E0(Obj_021BD0E0 *p);
extern void func_021BC810(Obj_021BC810 *p);
extern void func_021BCFE0(Obj_021BCFE0 *p);
extern void func_021BCFF0(Obj_021BCFF0 *p);
extern void func_021BD008(Obj_021BD008 *p);
extern void func_021BD098(int a, int b);
extern u32 func_021904AC(u8 *p);
extern void func_021BD09C(u8 *p, u32 v);
extern void func_021BC730(Obj_021BC730 *p);
extern void func_021BC75C(Obj_021BC75C *p);
extern void func_021BC794(Obj_021BC794 *p);
extern void func_021BC7BC(Obj_021BC7BC *p, int i);
extern void func_021BC998(Obj_021BC998 *p);
extern void func_021BC7D4(Obj_021BC7D4 *p);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_021BD01C(Obj_021BD01C *p);
extern void func_021BCB9C(void *p, int keep);
extern int func_021BD0FC(u32 a);
extern void func_021BC7F8(Obj_021BC7F8 *p);
extern void func_021BD068(u8 *p);
extern void func_021BC9AC(Obj_021BC9AC *p);
extern void func_021BC7B0(u8 *p);
extern void func_021BC788(u8 *p);
extern void func_021BC748(u8 *p);
extern void func_021BD040(Obj_021BD040 *p);
extern void func_021BD054(u8 *p);
extern void func_021BD07C(Obj_021BD07C *p);
extern void func_021BC704(Obj_021BC704 *p);
extern void func_021BC824(u8 *p);
extern void func_020403F4(u32 i);
extern void func_021BCFD8(int a);
extern void func_021BD0B0(Obj_021BD0B0 *p);
extern u32 func_021BD0A4(u8 *p);
extern void func_021BCC3C(void *p);
extern void func_021BCC80(char *p);
extern void func_021BCD34(Obj_021BC138 *p);
extern void func_021BCD70(Obj_021BC138 *p);
extern void func_021BCD84(char *p);
extern void func_021BCDD8(char *p);
extern void func_021BCE88(char *p);
extern void func_021BC970(Obj_021BC970 *p);
extern void func_021BCEAC(int a);
extern void func_021BCEB0(int a);
extern void func_021BCEB4(char *p);
extern void func_021BCF18(int a);
extern void func_021BCF1C(int a);
extern void func_021BCF20(int a);
extern void func_021BCF24(char *p);
extern void func_021BD120(void *p, u16 v);
extern int func_021BD140(u16 v);
extern void func_021BCBC8(char *p);
extern void func_021BCA78(u8 *p);
extern void func_021BCA64(u8 *p);
extern u8 *func_021BCA6C(u8 *p);
extern void func_021BCA80(u8 *p);
extern void func_021BC720(Obj_021BC720 *p);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern unsigned char func_02045730(struct Descriptor *d);
extern void func_020409B4(unsigned int index);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(int a, int b, int c, int d, int e);
extern void func_020414AC(int a);
extern u16 func_021BD090(u8 *p);
extern u32 func_021BD094(u8 *p);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
void func_021BBEF4(int a0, Obj_021BBEF4 *p);
void func_021BBF10(int a0, Obj_021BBF10 *p);
void func_021BBF74(void);
Obj_021BBF78 *func_021BBF78(int a, int b);
void func_021BBF9C(u32 a, u8 *p);
void func_021BBFB0(void);
void func_021BBFB4(void *p);
void func_021BBFB8(u32 a, u32 b, u32 c, u32 d);
void func_021BBFF4(u32 a, Obj_021BBFF4 *o);
void func_021BC030(int a0, Obj_021BC030 *p);
void func_021BC048(u32 a0, Obj_021BC048 *p);
void func_021BC10C(int a0, Obj_021BC10C *p);
void func_021BC138(u16 id, Param *p);
int func_021BC338(u32 a);
int func_021BC340(int a, int b);
int func_021BC388(int a, int b, int c);
void func_021BC424(u32 a);
void func_021BC484(u32 a);
void func_021BC4F0(int a);
void func_021BC550(void *p, int v);
void func_021BC578(void *p, int v);
void func_021BC5A0(void *p, int v);
int func_021BC5BC(u8 *a);
void func_021BC5D4(u8 *p);
void func_021BC5E4(int *p);
void func_021BC63C(void *p);
void func_021BC654(u8 *p);
void func_021BC664(S *p);
void func_021BC6B4(Obj_021BC6B4 *p);
void func_021BC6D0(Obj_021BC6D0 *p);
void func_021BC6E8(Obj_021BC6E8 *p);
extern int d_021DE320;
extern u8 d_021D9B64[];
extern const fx32 d_021D9B40[];
extern const fx32 d_021D9B58[];
extern const fx32 d_021D9B4C[];




void func_021BBEF4(int a0, Obj_021BBEF4 *p)
{
    int h = p->head->h4;
    u16 i = p->h8;

    if (i != 0xFFFF) {
        func_02050468((struct BbActSys *)h, i, 1);
    }
}




/*
 * Witnesses: arm9 leaves func_02050080, func_020507D0, func_020507F0,
 * func_020508C4, func_0204F654 filed in src/matched/arm9 (wave A1).
 */
void func_021BBF10(int a0, Obj_021BBF10 *p)
{
    u8 c;
    int r4, r6;
    u16 t;

    switch (p->hA) {
    case 0:
        p->i10 = p->i10 + 1;
        if (p->i10 >= 0x10) {
            p->hA = p->hA + 1;
        }
        break;
    case 1:
        p->h0e = p->h0e - 2;
        if (p->h0e < 0) {
            func_021AC154(a0);
            return;
        }
        c = p->h0e;
        r4 = p->head->h4;
        r6 = func_02050080((u32 *)r4);
        t = (int)func_020508C4((u32)r4, (u16)p->h8);
        func_0204F6B4((u8 *)r6, t, &c);
        break;
    }
}


void func_021BBF74(void) {}







Obj_021BBF78 *func_021BBF78(int a, int b)
{
    Obj_021BBF78 *q = func_02030734(b, 4, 1, (const char *)&d_021DE320, 0x78);

    q->f0 = a;
    func_021BBFB0();
    return q;
}







/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBF9C(u32 a, u8 *p)
{
    func_021BBFB4(p);
    func_020307B0(p);
}







/*
 * An empty function.
 */
void func_021BBFB0(void)
{
}







void func_021BBFB4(void *p)
{
}







void func_021BBFB8(u32 a, u32 b, u32 c, u32 d)
{
    Arg s;

    s.b = d;
    s.c = b;
    s.d = a;
    s.e = func_0219C9DC((u8 *)func_0216D520((void *)a));
    s.a = func_021ABEA0(c, 6);
    func_021ABFA8(c, d_021D9B64, 0, 0, &s, 0);
}






/*
 * Addresses are Black-image addresses.
 */
void func_021BBFF4(u32 a, Obj_021BBFF4 *o)
{
    u32 *p = (u32 *)func_021AC1AC(a);

    o->blk = *(Blk *)p;
    o->f0C = 0x40;
    o->f00 = 0;
    o->f08 = 0;
    if (o->blk.w[1] == 2) {
        o->f0C = 0;
    }
    func_0216E1A4(p[2], (int)(&o->f2C));
}






void func_021BC030(int a0, Obj_021BC030 *p)
{
    if (p->b10) {
        p->b10 = 0;
        func_0219C98C((u32)p->f20, (u16 *)p->f28);
    }
}




/*
 * The zeroed V3 is a block-scope declaration with an initialiser: that is
 * what materialises `add r6, sp, #0xc` before the three stores and keeps r6
 * across the func_0216E3C4 call (plain element stores fold to sp-relative).
 */
void func_021BC048(u32 a0, Obj_021BC048 *p)
{
    u16 s[2];
    int h;

    if (func_0216E1C4(p->f1c, (int)p->f2c) == 0 || func_0216DC34((void *)p->f1c) == 0) {
        func_021AC154((int)a0);
        return;
    }
    h = func_0216D7A8((void *)p->f1c, 0);
    if (p->b10 == 0) {
        if (h == 0xFFFF) return;
        {
            V3 v = {0, 0, 0};
            func_0219C928(p->f20, func_0216E3C4((void *)p->f1c), &p->h28, &v,
                          (u32)func_021BC138, (u32)p);
        }
        p->b10 = 1;
    }
    if (p->h2a == 0xFFFF) return;
    if (p->b11 == 0) {
        int t;
        func_0219C9E0(p->f1c, &s[1], &s[0]);
        t = s[1];
        p->f0 = t;
        p->f4 = s[0];
        p->f8 = t;
        p->b11 = 1;
    }
    p->f8 += p->fC;
    if (p->f8 >= p->f0 + 0x400) {
        p->f8 = p->f0 + 0x400;
        p->fC = -p->fC;
        return;
    }
    if (p->f8 <= p->f0 - 0x400) {
        p->f8 = p->f0 - 0x400;
        p->fC = -p->fC;
    }
}




void func_021BC10C(int a0, Obj_021BC10C *p)
{
    if (func_0216E1C4((int)p->f1C, (int)p->f2C) == 1 && p->b10 != 0 && p->h2A != 0xFFFF) {
        func_021BC138(p->h2A, (Param *)p);
    }
}






/*
 * Witnesses: arm9 leaves func_02050080, func_020507D0, func_020507F0,
 * func_020508C4, func_0204F654 filed in src/matched/arm9 (wave A1).
 *
 * The u16 `slot` local is what truncates func_020507D0's result straight
 * into r2 (a (u16) cast or a u16 parameter adds a copy first).
 *
 * Addresses are Black-image addresses.
 */
void func_021BC138(u16 id, Param *p)
{
    Vec v;
    Vec w;
    Vec u;
    int y;
    u32 flag;
    s16_021BC138 rot[4];
    u16 kind;
    u32 h2;
    u32 h;
    int idx;
    u32 obj;
    Info *info;
    u32 i1;
    u32 i2;
    u16 slot;

    h2 = p->f24;
    h = func_02050080((u32 *)h2);
    idx = func_0216D7A8((void *)p->f1C, 0);
    if (id == 0xFFFF) {
        return;
    }
    kind = func_02188C9C((u8 *)func_021ABE14((u8 *)(*p->f14)));
    slot = func_020507D0(h2, idx);
    func_020507A0((void *)h2, id, slot);
    func_020507F0((void *)h2, id, 0);
    obj = p->f1C;
    info = func_0216E3C4((void *)obj);
    func_0216D88C((const struct Actor *)obj, (struct VecFx32 *)&v);
    v.z += d_021D9B40[info->f7];
    func_0216D8B0((u8 *)obj, (u8 *)(&w));
    v.x += w.x;
    v.z -= w.z;
    if (func_02163E58(obj, &v, &y) == 1) {
        v.y = y;
    }
    v.y += d_021D9B58[p->f18];
    func_0216D8D0((u8 *)obj, (u8 *)(&w));
    v.x += w.x;
    v.y -= w.y;
    v.z -= w.z;
    v.y += d_021D9B4C[info->f7];
    if (info->f7 == 2) {
        if (func_021AB0F8(func_0216D7DC((void *)obj)) & 0x40) {
            v.y -= 0x3800;
        } else {
            v.y -= 0x8000;
        }
    }
    v.y += func_021BC340(kind, info->f7);
    func_02048B30(func_0218EC2C(func_02188C58((void *)func_021ABE14((u8 *)(*p->f14)))), &u);
    v.x += (v.x / 4096 - u.x / 4096) * 298;
    func_0204F638((u8 *)h, id, (struct Trip *)(&v));
    flag = 1;
    i1 = func_020508C4(h2, idx);
    i2 = func_020508C4(h2, id);
    rot[3] = p->f8;
    rot[2] = p->f4;
    rot[2] += (s16_021BC138)func_021BC338(kind);
    rot[1] = 0;
    rot[0] = 0;
    func_0204F5E4((u8 *)h, i1, (u16 *)(&rot[1]));
    func_0204F604((void *)h, i2, (u16 *)(&rot[1]));
    func_0204F654(h, i1, &rot[0]);
    func_0204F66C(h, i2, (int)(&rot[0]));
    func_0204F684((struct Manager0204F684 *)h, i2, &rot[3], &rot[2]);
    func_0204F794((void *)h, i2, &flag);
    flag = func_0204F748((u8 *)h, i1);
    func_0204F764((void *)h, i2, &flag);
}






int func_021BC338(u32 a)
{
return (~255);
}





int func_021BC340(int a, int b)
{
    int r = 0;

    if (a == 0x71 || a == 0x159) {
        if (b == 0) {
            r = -0x800;
        }
    } else if (a == 0x8f) {
        if (b == 0) {
            r = 2 << 10;
        }
    } else if (a == 0x159 + 0x12) {
        if (b == 0) {
            r = -0x5800;
        }
    } else {
        if (b == 0) {
            r = 6 << 10;
        }
    }
    return r;
}






int func_021BC388(int a, int b, int c)
{
    int r4;

    r4 = (int)func_021BCF88(b);
    func_021BCFA4((X *)r4, (u32)a);
    func_021BD0E0((Obj_021BD0E0 *)r4);
    func_021BC810((Obj_021BC810 *)r4);
    func_021BCFE0((Obj_021BCFE0 *)r4);
    func_021BCFF0((Obj_021BCFF0 *)r4);
    func_021BD008((Obj_021BD008 *)r4);
    func_021BD098(r4, b);
    func_021BD09C((u8 *)r4, func_021904AC((u8 *)c));
    func_021BC730((Obj_021BC730 *)r4);
    func_021BC75C((Obj_021BC75C *)r4);
    func_021BC794((Obj_021BC794 *)r4);
    func_021BC7BC((Obj_021BC7BC *)r4, 0);
    func_021BC998((Obj_021BC998 *)r4);
    func_021BC7D4((Obj_021BC7D4 *)r4);
    func_0203FCA0(3, (const struct BgTemplate *)0x021DE334, 0);
    func_021BC664((S *)((struct S *)r4));
    func_021BC6E8((Obj_021BC6E8 *)r4);
    func_021BD01C((Obj_021BD01C *)r4);
    func_021BCB9C((void *)r4, 0);
    return r4;
}






void func_021BC424(u32 a)
{
    func_021BD0FC(a);
    func_021BC6B4((Obj_021BC6B4 *)a);
    func_021BC7F8((Obj_021BC7F8 *)a);
    func_021BD068((u8 *)a);
    func_021BC9AC((Obj_021BC9AC *)a);
    func_021BC7B0((u8 *)a);
    func_021BC788((u8 *)a);
    func_021BC748((u8 *)a);
    func_021BD040((Obj_021BD040 *)a);
    func_021BD054((u8 *)a);
    func_021BD07C((Obj_021BD07C *)a);
    func_021BC704((Obj_021BC704 *)a);
    func_021BC824((u8 *)a);
    func_020403F4(3);
    func_021BCFD8(a);
}






void func_021BC484(u32 a)
{
    func_021BD0B0((Obj_021BD0B0 *)a);
    switch (func_021BD0A4((u8 *)a)) {
    case 0:
        func_021BCC3C((void *)a);
        break;
    case 1:
        func_021BCC80((char *)a);
        break;
    case 2:
        func_021BCD34((Obj_021BC138 *)a);
        break;
    case 3:
        func_021BCD70((Obj_021BC138 *)a);
        break;
    case 4:
        func_021BCD84((char *)a);
        break;
    case 5:
        func_021BCDD8((char *)a);
        break;
    case 6:
        func_021BCE88((char *)a);
        break;
    }
    func_021BC970((Obj_021BC970 *)a);
}






void func_021BC4F0(int a)
{
    switch (func_021BD0A4((u8 *)a)) {
    case 0:
        func_021BCEAC(a);
        break;
    case 1:
        func_021BCEB0(a);
        break;
    case 2:
        func_021BCEB4((char *)a);
        break;
    case 3:
        func_021BCF18(a);
        break;
    case 4:
        func_021BCF1C(a);
        break;
    case 5:
        func_021BCF20(a);
        break;
    case 6:
        func_021BCF24((char *)a);
        break;
    }
}






void func_021BC550(void *p, int v)
{
    func_021BD120(p, (u16)v);
    if (func_021BD140((u16)v)) {
        func_021BCBC8(p);
        func_021BCA78(p);
    }
}






void func_021BC578(void *p, int v)
{
    func_021BD120(p, (u16)v);
    if (func_021BD140((u16)v)) {
        func_021BCBC8(p);
        func_021BCA64(p);
    }
}






void func_021BC5A0(void *p, int v)
{
    func_021BD120(p, (u16)v);
    func_021BCBC8(p);
    func_021BCA64(p);
}






int func_021BC5BC(u8 *a)
{
func_021BCB9C((void *)a, 0);
func_021BCA80((u8 *)a);
return (int)func_021BCA6C(a);
}






void func_021BC5D4(u8 *p)
{
    func_021BC654(p);
    func_021BC720((Obj_021BC720 *)p);
}






void func_021BC5E4(int *p)
{
    int r4;

    func_021BC6D0((Obj_021BC6D0 *)((int)p));
    func_021BC6E8((Obj_021BC6E8 *)((int)p));
    func_021BD01C((Obj_021BD01C *)((int)p));
    r4 = p[9];
    func_02045334((struct Descriptor *)r4);
    func_02045374((struct Cfg *)r4);
    func_020409B4(func_02045730((struct Descriptor *)r4));
    func_0204047C(3, 1);
    func_02040588(3, 0);
    func_0207D63C(0x04000050, 8, 0x11, 0x10, 4);
}






void func_021BC63C(void *p)
{
    func_020414AC(3);
    func_021BC704((Obj_021BC704 *)p);
    func_021BD07C((Obj_021BD07C *)p);
}






void func_021BC654(u8 *p)
{
    func_021BC63C(p);
    func_021BC5E4((int *)p);
}






void func_021BC664(S *p)
{
    int r4, r6, h;

    r4 = func_021BD090((u8 *)((int)p));
    r6 = func_021BD094((u8 *)((int)p));
    h = (int)func_02030734(r4, func_020493D4((struct ArcFile *)r6, 1), 0, (const char *)0x021DE354, 0x2c8);
    p->a = h;
    func_0204932C((struct ArcFile *)r6, 1, (void *)h);
    func_02062A98((struct NitroFileHeader *)p->a, (void **)((int)&p->b));
}






void func_021BC6B4(Obj_021BC6B4 *p)
{
    if (p->f14C != 0) {
        func_020307B0(p->f14C);
        p->f14C = 0;
        p->f150 = 0;
    }
}






void func_021BC6D0(Obj_021BC6D0 *p)
{
    func_02040E78(3, (void *)p->f150->fC, 0x20, 0);
}






void func_021BC6E8(Obj_021BC6E8 *p)
{
    if (p->f28 == -1) {
        p->f28 = func_0203FA08(3, 0x20, 0);
    }
}
