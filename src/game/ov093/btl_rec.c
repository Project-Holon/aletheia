/*
 * file:     btl_rec.c
 * unit:     yes
 * function: func_021EE104, func_021EE200, func_021EE21C, func_021EE224, func_021EE228, func_021EE23C, func_021EE264, func_021EE2A0, func_021EE2F8, func_021EE318, func_021EE370, func_021EE390, func_021EE3E8, func_021EE4B4, func_021EE544, func_021EE5E4, func_021EE600, func_021EE608, func_021EE638, func_021EE63C, func_021EE644, func_021EE674, func_021EE688, func_021EE6B8, func_021EE830, func_021EE894, func_021EE8B4, func_021EE8D8, func_021EE8F4, func_021EE96C, func_021EE9A4, func_021EE9B4, func_021EE9E4, func_021EEA30, func_021EEA54, func_021EEA58, func_021EEAD0, func_021EEAE0, func_021EEAE8, func_021EEAFC, func_021EEB00, func_021EEB2C, func_021EEB64, func_021EEB70, func_021EEB84, func_021EEBA4, func_021EEBDC, func_021EEBE8, func_021EEC20, func_021EEC4C, func_021EEC78, func_021EECD8, func_021EED00, func_021EED24, func_021EED48, func_021EED6C, func_021EED90, func_021EEE24, func_021EEE80, func_021EEEC8, func_021EEEF4, func_021EEF20, func_021EEF98, func_021EEFE0, func_021EF1CC, func_021EF204, func_021EF280, func_021EF3A4, func_021EF460, func_021EF508, func_021EF594, func_021EF5E8, func_021EF664, func_021EF694, func_021EF6A8, func_021EF6B0, func_021EF6E8, func_021EF6F0, func_021EF71C, func_021EF7AC, func_021EF83C, func_021EF874, func_021EF884, func_021EF894, func_021EF8A4, func_021EF8B8, func_021EF8C8, func_021EF8E8, func_021EF8F8, func_021EF90C, func_021EF91C, func_021EF934, func_021EF948, func_021EF958, func_021EF980, func_021EF988, func_021EF9A8, func_021EF9B0, func_021EF9C0, func_021EF9C8, func_021EF9D0, func_021EF9F4
 * address:  0x021EE104
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_06898020  0x06898020  thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021ECEB8  0x021ECEB8  thumb  ov093
 *   func_021ECF68   0x021ECF68  thumb  ov093
 *   func_0204E720  0x0204E720  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_021EB318  0x021EB318  thumb  ov093
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045374 0x02045374 arm
 *   func_020454E0 0x020454E0 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02040618 0x02040618 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021D590C  0x021D590C  thumb  ov093
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02041300  0x02041300  arm
 *   func_02030734  0x02030734  arm
 *   d_021F3ADC  0x021F3ADC  data  a4
 *   func_020307B0   0x020307B0  arm arm9
 *   func_02082D44  0x02082D44  arm
 *   func_021D8470  0x021D8470  thumb
 *   func_021D845C  0x021D845C  thumb
 *   d_021F6388  0x021F6388  data  a4
 *   d_021F6384  0x021F6384  data  a4
 *   sub_02030734   0x02030734  arm
 *   d_021F3AE8     0x021F3AE8  data  ov093  a4
 *   func_021D4C58   0x021D4C58  thumb
 *   func_021D4B58  0x021D4B58  thumb  ov093
 *   func_021D4B98  0x021D4B98  thumb  ov093
 *   func_021D4BD4  0x021D4BD4  thumb  ov093
 *   func_021D4C60  0x021D4C60  thumb  ov093
 *   func_021D4C6C  0x021D4C6C  thumb  ov093
 *   func_021D4C84  0x021D4C84  thumb  ov093
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   d_021F6398     0x021F6398  data  ov093  a4
 *   d_021F63D8     0x021F63D8  data  ov093  a4
 *   d_021F3990     0x021F3990  data  ov093  a2
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_021B9940  0x021B9940  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_0201EE84  0x0201EE84  thumb
 *   func_021BA020  0x021BA020  thumb  ov093
 *   func_0201F0F8  0x0201F0F8  thumb
 *   func_021B9F70  0x021B9F70  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021BA004  0x021BA004  thumb  ov093
 *   func_021B9FAC  0x021B9FAC  thumb  ov093
 *   func_021BA064  0x021BA064  thumb  ov093
 *   func_021BA080  0x021BA080  thumb  ov093
 *   func_0202A3CC  0x0202A3CC  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F134  0x0201F134  thumb
 *   d_021F63C8     0x021F63C8  data  a4
 *   func_021B8BD0  0x021B8BD0  thumb  ov093
 *   d_021F39A0     0x021F39A0  data  a2
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   d_021F39D8  0x021F39D8  data  a4
 *   d_021F39DC  0x021F39DC  data  a4
 *   func_02045A98  0x02045A98  arm
 *   func_0201D5C4  0x0201D5C4  thumb
 *   func_0201D5CC  0x0201D5CC  thumb
 *   func_0201D670  0x0201D670  thumb
 *   func_0201D5F4  0x0201D5F4  thumb
 *   func_0201D658  0x0201D658  thumb
 *   func_0201D688  0x0201D688  thumb
 *   func_02045A90  0x02045A90  arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EF8C 0x0201EF8C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201F020 0x0201F020 thumb
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8CE8  0x021B8CE8  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021E8918  0x021E8918  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 *   func_021EFA94  0x021EFA94  thumb  ov093
 *   func_021EFAD8  0x021EFAD8  thumb  ov093
 *   func_021EFB34  0x021EFB34  thumb  ov093
 *   func_021EFC1C  0x021EFC1C  thumb  ov093
 *   func_021EFC78  0x021EFC78  thumb  ov093
 *   func_021EFCE4  0x021EFCE4  thumb  ov093
 *   d_021F3AF8  0x021F3AF8  data  a4
 *   func_021E8A98  0x021E8A98  thumb  ov093
 */
#include "../../matched/include/Obj00027.h"
#include "../../matched/include/Obj06295.h"
#include "../../matched/include/Obj07866.h"
#include "../../matched/include/Obj21627.h"
#include "../../matched/include/Obj21628.h"
#include "../../matched/include/G_H.h"
#include "../../matched/include/G_Countdown.h"

#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))
struct Q1;
struct S2;
struct Unk021D62A8;
struct T;
struct CharBuf;
struct Descriptor;
struct C;
struct Cfg;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

/* d_021F6398: message and word-set state of the record screens. */
struct BtlRec {
    void ***f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 t[8];                   /* 0x10 */
    int a[8];                   /* 0x30 (also named d_021F63C8) */
    u32 f50;
    u32 f54;
    u16 f58;
    u16 f5a;
};

/* d_021F63D8: lies inside d_021F6398 (+0x40); the +0x18 and +0x1a halfwords
 * are f58 and f5a of the record. */
struct BtlRecTail {
    u8 pad[0x10];
    u16 f10;
    u8 pad2[6];
    u16 f18;
    u16 f1a;
};

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Q {
    int f00;
    int f04;
};

struct T {
    u16 v[7];
};

struct O {
    u8 pad00[0xe0];
    int (*fe0)(void *, void *);
    int (*fe4)(void *, void *);
    void *fe8;
    int fec;
};

struct C_021EE3E8 {
    u8 pad00[8];
    void *f08;
    int f0c;
    u32 f10;
    u8 pad14[0x10];
    int f24;
    u8 pad28[0xc];
    u32 f34;
    u8 pad38[0x138];
    u16 f170, f172, f174, f176, f178, f17a, f17c;
};

struct C_021EE4B4 {
    u8 pad00[0x8];
    int f08;
    int f0c;
    u8 pad10[0x14];
    int f24;
    u8 pad28[0xc];
    int f34;
    u8 pad38[0x134];
    int f16c;
    u16 f170;
    u16 f172;
    u16 f174;
    u16 f176;
    u16 f178;
    u16 f17a;
    u16 f17c;
};

struct C {
    u8 pad00[0x8];
    void *f08;
};

typedef struct {
    u32 a;
    u32 n : 31;
    u32 flag : 1;
    u32 w[4];
} Q_021EE644;

typedef struct {
    u32 a;
    u32 flag : 1;
    u32 n : 31;
    u32 w[4];
} Q_021EE674;

typedef struct {
    u8 *buf;
    u32 n : 31;
    u32 flag : 1;
    u32 pos[4];
} Q_021EE688;

typedef struct {
    u8 *data;          /* 0x00 */
    u32 len : 31;      /* 0x04 */
    u32 err : 1;
    u32 pos[4];        /* 0x08 */
    u32 buf[4][16];    /* 0x18 */
} Reader;

typedef struct {
    u8 *buf;
    u32 n : 31;
    u32 flag : 1;
    u32 pos[4];
} Q_021EE830;

typedef struct {
    u8 *buf;
    u32 n : 31;
    u32 flag : 1;
    u32 pos[4];
} Q_021EE894;

typedef struct {
    u8 len;
    u8 mask;
    u8 cnt;
    u8 x : 6;
    u8 f : 1;
    u8 g : 1;
    u8 d[60];
} B;

typedef struct {
    u32 f00;
    u8 pad[8];
    u8 lo : 4;
    u8 hi : 4;
    u8 idx;
    u8 e;
    u8 f;
} Obj;

typedef struct {
    u8 pad00[4];
    u32 w4;
    u32 w8;
    u8 st : 4;
    u8 hi : 4;
    u8 f0d;
    u8 mode;
    u8 f0f;
    u16 h10;
    u16 h12;
    u8 d[1];
} W;

/* 021EEB64  cmp r1,#0; beq; ldr r2,[r0,#8]; str r2,[r1]; ldr r0,[r0,#4] */
struct QW { u8 pad[4]; u32 a; u32 b; };

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 t[8];
} D_021EED6C;

typedef char *va_list;

typedef struct {
    u16 id;
    u16 pad;
    u32 pad2;
} E;

typedef struct {
    void (*fn)(u32, u32, u32);
    u32 pad;
} F;

typedef struct {
    int f0;
    u32 f4;
    int f8;
    int fc;
} P_021EF3A4;

typedef struct {
    int f0;
    int f4;
    int f8;
} P_021EF460;

typedef struct {
    void ***f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 pad[11];
    u32 f54;
    u16 f58;
    u16 f5a;
} D_021EF71C;

typedef struct {
    void ***f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 pad[11];
    u32 f54;
    u16 f58;
    u16 f5a;
} D_021EF7AC;

typedef struct { u32 v; } Slot;

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
    Slot c[8];          /* 0x028 */
    u32 z48[8];         /* 0x048 */
    u32 w[8][6];        /* 0x068 */
    u32 z128[8];        /* 0x128 */
    u32 used[8];        /* 0x148 */
} S;

typedef struct {
    u32 value;
    u32 count;
} Countdown;

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
    Slot c[8];          /* 0x028 */
    u32 z48[8];         /* 0x048 */
    u32 w[8][6];        /* 0x068 */
    u32 z128[8];        /* 0x128 */
    u32 used[8];        /* 0x148 */
} S_021EF988;

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
    u32 c[8];           /* 0x028 */
    u32 z48[8];         /* 0x048 */
    u32 w[8][6];        /* 0x068 */
    u32 z128[8];        /* 0x128 */
    u32 used[8];        /* 0x148 */
} S_021EF9F4;

extern void func_02082BCC(void *, u8, u32);
extern char *func_021B9AF8(char *p, int i);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D5B7C(void *);
extern void func_021ECEB8(u8 *, u32, u16, u32);
extern int func_021ECF68(struct T *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern u32 func_021EB318(void);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_02045374(struct Cfg *cfg);
extern void func_020454E0(struct Cfg *cfg, u16 base, u32 pal);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020061E4(u32 a);
extern void func_021D590C(void **p, u16 *out);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern void func_02041300(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u8 a6);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082D44(const void *, void *, u32);
void func_021D8470(u32 *p);
void func_021D845C(u32 *p);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021D4C58(u32 a);
extern u32 func_021D4B58(u32 a, u32 b, u32 c);
extern int func_021D4B98(void);
extern u16 func_021D4BD4(int a, u8 **q);
extern u8 func_021D4C60(void);
extern u16 func_021D4C6C(u8 **out);
extern u32 func_021D4C84(u32 a, u32 b);
extern int func_021BA1A8(char **p, int m);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u8 *func_021B9940(char *p, u8 i);
extern void *func_021D5864(struct Work *p);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void *func_021D5844(void *m);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern unsigned short func_021BA020(char *p, int i);
extern void func_0201F0F8(struct WordSet *p, u32 i, u32 v);
extern int func_021B9F70(u8 *p, int i);
extern void *func_021B86B8(void ***p);
extern u16 func_021BA004(char *p, int i);
extern u32 func_021B9FAC(u8 *p, int i, u32 *out);
extern int func_021BA064(char *p, int i);
extern int func_021BA080(void *battle);
extern u8 func_0202A3CC(u32 cls);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F134(struct WordSet *p, u32 i, u32 v);
extern int func_021B8BD0(unsigned char *p, unsigned char k);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u16 func_02045A98(void);
extern u32 func_0201D5C4(void);
extern u32 func_0201D5CC(const u16 *p);
extern u32 func_0201D670(const u16 *p, u32 i);
extern u32 func_0201D5F4(const u16 *p);
extern u32 func_0201D658(const u16 *p);
extern u16 *func_0201D688(u16 *p);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EF8C(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F020(struct WordSet *p, u32 i, u32 v);
extern u8 func_021B8DDC(u32 x);
extern int func_021B8CE8(int a, int b, int c);
extern u8 func_021B8FF4(u8 *p);
extern Slot func_021E8918(void);
extern int func_021EFA94(void *mem, int a);
extern int func_021EFAD8(char *a, u32 b, u32 c);
extern int func_021EFB34(void *mem, int a);
extern void func_021EFC1C(void *screen, int line, int color, char *text);
extern int func_021EFC78(void *mem, int a, int b);
extern void *func_021EFCE4(char *arg0, int arg1);
extern u32 func_06898020(u32 a, int b);
extern u32 func_021E8A98(Slot a);
void func_021EE104(u8 *p, u32 *out, u32 a, u32 b, u32 flag);
void func_021EE200(u8 *p);
int func_021EE21C(u8 *p);
void func_021EE224(char *p);
void func_021EE228(void);
void func_021EE23C(struct Q *q);
int func_021EE25C(void);
void func_021EE264(char *o, int a, struct T *src);
int func_021EE2A0(struct O *o);
void func_021EE2F8(struct O *o);
int func_021EE318(struct O *o);
void func_021EE370(struct O *o);
int func_021EE390(struct O *o);
int func_021EE3E8(int *st, struct C_021EE3E8 *c);
int func_021EE4B4(int *st, struct C_021EE4B4 *c);
int func_021EE544(int *st, struct C *c);
void *func_021EE5E4(u32 heap);
void func_021EE600(void *p);
void func_021EE608(u8 *p, const u8 *src, int n);
u8 func_021EE638(u8 *p);
unsigned short *func_021EE63C(unsigned short *a, unsigned int *b);
void func_021EE644(Q_021EE644 *q, u32 a, u32 n);
void func_021EE674(Q_021EE674 *q);
int func_021EE688(Q_021EE688 *q, int i);
u32 *func_021EE6B8(Reader *r, u32 idx, u8 *outLen, u8 *outFlag);
int func_021EE830(Q_021EE830 *q);
int func_021EE894(Q_021EE894 *q, int i);
void func_021EE8B4(B *p, int b);
u8 *func_021EE8D8(u8 *p, u32 *out, int flag);
void func_021EE8F4(u8 *p, u8 idx, const void *src, u32 n);
u8 *func_021EE96C(B *p, u8 b, u32 *out);
u8 *func_021EE9A4(u8 *p, u32 *out);
void func_021EE9B4(B *p, const void *src, int n);
int func_021EE9E4(u8 *p, u32 *pos, u8 *a, u8 *b, u32 *dst);
void func_021EEA30(int v);
void func_021EEA54(void);
Obj *func_021EEA58(u32 a, int idx, u32 v, u32 heap);
void func_021EEAD0(u8 *p);
void func_021EEAE0(void *p);
void func_021EEAE8(void);
void func_021EEAFC(void);
void func_021EEB00(W *p, u16 a, const void *src, u16 n);
int func_021EEB2C(W *p);
u32 func_021EEB64(struct QW *p, u32 *out);
void func_021EEB70(W *p);
u32 func_021EEB84(W *p);
u32 func_021EEBA4(W *p);
void func_021EEBDC(W *p);
u8 func_021EEBE8(W *p);
u16 func_021EEC20(W *p, u8 **out);
u32 func_021EEC4C(W *p, u32 a, u32 b);
void func_021EEC78(u32 a, u32 b, u32 c, u32 d);
void func_021EECD8(void);
void func_021EED00(u8 a, u32 b);
void func_021EED24(u8 a, u32 b);
void func_021EED48(u8 a, u8 b);
void func_021EED6C(void *a, u8 b, u8 c);
void func_021EED90(void *win, u8 slot, u8 k);
void func_021EEE24(u32 a, u16 k, u32 n, ...);
void func_021EEE80(u32 a, u16 k, u32 *p);
void func_021EEEC8(u32 a, u32 b, u32 c);
void func_021EEEF4(u32 a, u16 b, u32 c);
u16 *func_021EEF20(u16 *p, u32 *o1, u16 *o2, u8 *o3);
u8 func_021EEF98(void *s);
void func_021EEFE0(void *s, const u32 *values, void *w);
void func_021EF1CC(u32 a, u16 b, u32 c);
void func_021EF204(u32 a, u32 b, u32 *p);
void func_021EF280(u32 a, u16 b, u32 *p);
void func_021EF3A4(u32 a, u32 b, P_021EF3A4 *p);
void func_021EF460(u32 a, u32 b, P_021EF460 *p);
void func_021EF508(u32 a, int b, u32 *p);
void func_021EF594(u32 a, u32 b, u32 *p);
void func_021EF5E8(u32 a, u8 b, u16 c);
void func_021EF664(int a, u16 b, int c);
void func_021EF694(u32 a, u32 b);
void func_021EF6A8(u32 a, u32 b, u32 c);
void func_021EF6B0(u32 a, u32 b, u32 c);
void func_021EF6E8(u32 a, u32 b, u32 c);
void func_021EF6F0(u32 a, u32 b, u32 c);
void func_021EF71C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_021EF7AC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_021EF83C(S *a, u32 i);
void func_021EF874(int a);
int func_021EF884(void);
int func_021EF894(void);
int DWC_StartUtilityEx(int a, int b);
u32 func_021EF8B8(void);
int func_021EF8C8(u32 a, Slot c);
int func_021EF8E8(int a);
int func_021EF8F8(int a, int b);
int func_021EF90C(int a);
void SetBottomScreenLineCentered(int line, int color, char *text);
int func_021EF934(int a, int b);
int func_021EF948(int a);
S *func_021EF958(u32 heap);
void func_021EF980(void *p);
void func_021EF988(S_021EF988 *p, u32 v);
u8 func_021EF9A8(u32 *p);
int func_021EF9B0(u32 *p);
int *func_021EF9C0(int *p, int a, int b);
void func_021EF9C8(int *p);
u32 func_021EF9D0(Countdown *p);
int func_021EF9F4(S_021EF9F4 *a, u32 b, Slot c, int d);
extern char d_021F3ADC[];
extern void *d_021F6388[];
extern int d_021F6384;
extern const char d_021F3AE8[];
extern struct BtlRec d_021F6398;
extern struct BtlRecTail d_021F63D8;
extern const u16 d_021F3990[];
extern s32 d_021F63C8[];
extern const u16 d_021F39A0[];
extern E d_021F39D8[];
extern F d_021F39DC[];
extern struct Countdown d_021F63F4;
extern char d_021F3AF8[];


/*
 * tail: 021EE1FE..021EE200 is zero alignment padding.
 */
void func_021EE104(u8 *p, u32 *out, u32 a, u32 b, u32 flag)
{
    void *groups[2] = {0, 0};
    int counts[2] = {0, 0};
    int i;
    int side;
    s8 slot;
    void *entry;
    func_02082BCC(out, 0, 28);
    groups[0] = func_021B9AF8(((struct Obj00027 *)p)->f138, a);
    counts[0] = func_021B9B94(groups[0]);
    if (b < 4) {
        groups[1] = func_021B9AF8(((struct Obj00027 *)p)->f138, b);
        counts[1] = func_021B9B94(groups[1]);
        if (counts[0] > 3) counts[0] = 3;
        if (counts[1] > 3) counts[1] = 3;
    }
    out[0] = flag;
    for (i = 0; i < 6; i++) {
        if (i < counts[0] + counts[1]) {
            if (i < counts[0]) { side = 0; slot = i; }
            else { side = 1; slot = i - counts[0]; }
            entry = func_021B9C00(groups[side], (u8)slot);
            if (func_021D5B68(entry)) out[side * 3 + slot + 1] = 2;
            else if (func_021D62A8(entry)) out[side * 3 + slot + 1] = 3;
            else if (!func_021D5B7C(entry)) out[side * 3 + slot + 1] = 0;
            else out[side * 3 + slot + 1] = 1;
        }
    }
}


void func_021EE200(u8 *p)
{
    func_021EF694(((struct Obj00027 *)p)->f34, 0xf);
    func_021ECEB8(p, ((struct Obj00027 *)p)->f34, 0, 0);
}


/*
 * Untraced mid-stream entry point: a plain tail thunk, `ldr r3,=T; bx r3`, whose pool word names func_021ECF68.
 */
int func_021EE21C(u8 *p) { return func_021ECF68((struct T *)p); }


void func_021EE224(char *p)
{
}


void func_021EE228(void)
{
    int x = 0x10;
    func_0204E720(1, 0, x, x - 0x13);
}


void func_021EE23C(struct Q *q)
{
    func_02043B5C((struct CharBuf *)q->f04, 12);
    func_02045334((struct Descriptor *)q->f00);
    func_0204E720(1, 16, 0, -3);
}


int func_021EE25C(void)
{
    return func_021EB318();
}


void func_021EE264(char *o, int a, struct T *src)
{
    ((struct Obj06295 *)o)->f16C = a;
    *(struct T *)(o + 0x170) = *src;
    ((struct O *)o)->fe0 = 0;
    ((struct O *)o)->fe4 = (int (*)(void *, void *))func_021EE3E8;
    ((struct O *)o)->fe8 = o;
    ((struct O *)o)->fec = 0;
}


int func_021EE2A0(struct O *o)
{
    if (o->fe0 != 0) {
        if (o->fe0(&o->fec, o->fe8) != 0) {
            o->fe0 = 0;
            o->fec = 0;
        }
        return 0;
    }
    if (o->fe4 != 0) {
        if (o->fe4(&o->fec, o->fe8) != 0) {
            o->fe4 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


void func_021EE2F8(struct O *o)
{
    o->fe0 = 0;
    o->fe4 = (int (*)(void *, void *))func_021EE4B4;
    o->fe8 = o;
    o->fec = 0;
}


int func_021EE318(struct O *o)
{
    if (o->fe0 != 0) {
        if (o->fe0(&o->fec, o->fe8) != 0) {
            o->fe0 = 0;
            o->fec = 0;
        }
        return 0;
    }
    if (o->fe4 != 0) {
        if (o->fe4(&o->fec, o->fe8) != 0) {
            o->fe4 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


void func_021EE370(struct O *o)
{
    o->fe0 = 0;
    o->fe4 = (int (*)(void *, void *))func_021EE544;
    o->fe8 = o;
    o->fec = 0;
}


int func_021EE390(struct O *o)
{
    if (o->fe0 != 0) {
        if (o->fe0(&o->fec, o->fe8) != 0) {
            o->fe0 = 0;
            o->fec = 0;
        }
        return 0;
    }
    if (o->fe4 != 0) {
        if (o->fe4(&o->fec, o->fe8) != 0) {
            o->fe4 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


int func_021EE3E8(int *st, struct C_021EE3E8 *c)
{
    switch (*st) {
    case 0:
        func_0201DD78(1, 9, 12);
        func_02045374(c->f08);
        func_020454E0(c->f08, c->f10, 3);
        func_02043B5C((struct CharBuf *)c->f0c, 12);
        func_020409B4(func_02045730(c->f08));
        (*st)++;
        break;
    case 1:
        func_021EF71C(c->f34, c->f172, c->f174, c->f176, c->f178, c->f17a, c->f17c);
        func_0201C7A4((void *)c->f0c, 0, 0, (void *)c->f34, (void *)c->f24);
        (*st)++;
        break;
    case 2:
        func_02045334(c->f08);
        (*st)++;
        break;
    case 3:
        func_02040618(3, 0, 0);
        func_02040618(3, 3, 0x100);
        func_020061E4(0x547);
        (*st)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}


int func_021EE4B4(int *st, struct C_021EE4B4 *c)
{
    switch (*st) {
    case 0:
        func_021D590C((void **)c->f16c, &c->f170);
        func_021EF7AC(c->f34, c->f172, c->f174, c->f176, c->f178, c->f17a, c->f17c);
        func_02043B5C((struct CharBuf *)c->f0c, 12);
        func_0201C7A4((void *)c->f0c, 0, 0, (void *)c->f34, (void *)c->f24);
        (*st)++;
        break;
    case 1:
        func_02045334((struct Descriptor *)c->f08);
        func_020061E4(0x547);
        (*st)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}


int func_021EE544(int *st, struct C *c)
{
    int a;
    int b;
    int e;
    int f;
    u8 id;

    switch (*st) {
    case 0:
        a = func_02045758(c->f08) - 1;
        b = func_02045760(c->f08) - 1;
        e = func_02045738(c->f08) + 2;
        f = func_02045740(c->f08) + 2;
        id = func_02045730(c->f08);
        func_02041300(id, 0, (u8)a, (u8)b, (u8)e, (u8)f, 0);
        func_020409B4(id);
        func_020061E4(0x547);
        (*st)++;
        break;
    case 1:
        func_02040618(3, 0, -0x90);
        func_02040618(3, 3, 0);
        (*st)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}


void *func_021EE5E4(u32 heap)
{
    return func_02030734(heap, 0xC08, 1, d_021F3ADC, 0x6b);
}


/*
 * tail-call thunk to func_020307B0
 */
void func_021EE600(void *p)
{
    func_020307B0(p);
}


void func_021EE608(u8 *p, const u8 *src, int n)
{
    u32 pos;
    u32 end;

    if (p[2] == 0) {
        pos = ((struct Obj07866 *)p)->f0;
        n = n - 1;
        end = pos + n;
        if (end <= 0xC00) {
            func_02082D44(src + 1, p + 8 + pos, n);
            ((struct Obj07866 *)p)->f0 = end;
        } else {
            p[2] = 1;
        }
    }
}


/* 021EE638  ldrb r0,[r0] */
/*
 * Reads the u8 field at offset 0 of the argument and returns it.
 */
u8 func_021EE638(u8 *p) { return *p; }


unsigned short *func_021EE63C(unsigned short *a, unsigned int *b)
{
    *b = *a;
    return a + 4;
}


void func_021EE644(Q_021EE644 *q, u32 a, u32 n)
{
    u32 i;

    q->a = a;
    q->n = n;
    q->flag = 0;
    for (i = 0; i < 4; i++)
        q->w[i] = 0;
}


void func_021EE674(Q_021EE674 *q)
{
    u32 i;

    for (i = 0; i < 4; i++)
        q->w[i] = 0;
}


/*
 * Stream-record head decoder (Q: buf, n:31+flag:1, pos[4]). Reads the byte
 * at stream i; if its kind field ((v >> 4) & 7) is 2, advances the stream
 * and returns bit 7. The int return type and the reuse of v for the bit
 * fix the order: kind cannot be forwarded past the redefinition of v, and
 * the u8 cast lands at the assignment, not at the return.
 */
int func_021EE688(Q_021EE688 *q, int i)
{
    int v;
    int kind;

    v = q->buf[q->pos[i]];
    kind = (v >> 4) & 7;
    v = (u8)((v >> 7) & 1);
    if (kind == 2) {
        q->pos[i]++;
        return v;
    }
    return 0;
}


/*
 * Reads the next record for channel idx from a packed byte stream. Header byte:
 * bits 0-3 count, bits 4-6 type, bit 7 flag. Type 1 carries count sub-records
 * (bits 0-4 size in words, bits 5-7 channel); the one for idx is copied into
 * buf[idx]. Type 2 is a skip, type 3 resets buf[idx]. Any error sets err.
 * The final bounds check reads len and pos into separate locals: that keeps
 * the len shift pair ahead of the pos load.
 */
u32 *func_021EE6B8(Reader *r, u32 idx, u8 *outLen, u8 *outFlag)
{
    u32 *pos;
    u32 p0;
    if (r->err) {
        func_021D8470(r->buf[idx]);
        *outLen = 1;
        *outFlag = 0;
        return r->buf[idx];
    }
    pos = r->pos;
    while ((p0 = pos[idx]) < r->len) {
        u8 b = r->data[p0];
        u8 count = b & 0xF;
        int type = (b >> 4) & 7;
        *outFlag = (b >> 7) & 1;
        pos[idx]++;
        if (pos[idx] > r->len)
            break;
        if (type == 1) {
            u32 *res = 0;
            u32 i;
            if (count == 0 || count > 4)
                break;
            for (i = 0; i < count; i++) {
                u32 p = pos[idx]++;
                u8 *dd = r->data;
                u8 c = dd[p];
                u8 id = (c >> 5) & 7;
                u8 sz = c & 0x1F;
                if (pos[idx] >= r->len)
                    break;
                if (id != idx) {
                    pos[idx] += sz * 4;
                } else {
                    func_02082D44(dd + pos[idx], r->buf[idx], sz * 4);
                    res = r->buf[idx];
                    pos[idx] += sz * 4;
                    *outLen = sz;
                }
            }
            if (res)
                return res;
        } else if (type == 3) {
            u32 *res = r->buf[idx];
            func_021D845C(res);
            *outLen = 1;
            *outFlag = 0;
            return res;
        } else if (type != 2) {
            break;
        }
        {
            u32 len = r->len;
            u32 p = pos[idx];
            if (p >= len)
                break;
        }
    }
    r->err = 1;
    func_021D8470(r->buf[idx]);
    *outLen = 1;
    *outFlag = 0;
    return r->buf[idx];
}


/*
 * Counts the bit7-flagged records in a stream (Q: buf, n:31+flag:1).
 * The buffer is read through q->buf in the loop (the compiler hoists it),
 * the bound is a local, and the locals are declared count first and
 * pos/size last; these set the register colours. pos++ sits right after
 * the byte load.
 */
int func_021EE830(Q_021EE830 *q)
{
    int count;
    u8 v;
    u8 n;
    int kind;
    u8 bit;
    u32 j;
    u8 len;
    u32 pos;
    u32 size;

    pos = 0;
    count = 0;
    size = q->n;
    if (size != 0) {
        do {
            v = q->buf[pos];
            pos++;
            n = v & 0xf;
            kind = (v >> 4) & 7;
            bit = (v >> 7) & 1;
            if (bit != 0)
                count++;
            if (pos >= size)
                break;
            if (kind != 1) {
                pos += n;
            } else {
                for (j = 0; j < n; j++) {
                    len = q->buf[pos] & 0x1f;
                    pos = pos + 1 + len * 4;
                    if (pos >= size)
                        break;
                }
            }
        } while (pos < size);
    }
    return count;
}


int func_021EE894(Q_021EE894 *q, int i)
{
    u32 p;

    if (q->flag == 0) {
        p = q->pos[i];
        if (p == q->n)
            return 1;
        return 0;
    }
    return 1;
}


void func_021EE8B4(B *p, int b)
{
    func_02082BCC(p, 0, 0x40);
    p->f = (u8)b;
}


u8 *func_021EE8D8(u8 *p, u32 *out, int flag)
{
    p[4] = 4;
    p[5] = 0x20 | (((u8)flag & 1) << 7);
    *out = 2;
    return p + 4;
}


void func_021EE8F4(u8 *p, u8 idx, const void *src, u32 n)
{
    u8 m;
    int len;
    u32 end;

    if (p[0] == 0) {
        p[3] = (p[3] & ~0x3f) | 1;
        p[0] = 2;
    }
    m = p[1];
    if (!(m & (1 << idx))) {
        len = n * 4;
        end = p[0] + (len + 1);
        if (end <= 0x3c) {
            p[1] = m | (u8)(1 << idx);
            p[2]++;
            (p + p[0])[4] = (idx << 5) | n;
            func_02082D44(src, p + 4 + (p[0] + 1), len);
            p[0] = end;
        } else {
            p[3] |= 0x80;
        }
    }
}


u8 *func_021EE96C(B *p, u8 b, u32 *out)
{
    u8 type;

    if (p->g == 0) {
        p->d[0] = b;
        type = p->x;
        p->d[1] = 0;
        p->d[1] = ((p->f & 1) << 7) | ((type & 7) << 4) | (p->cnt & 0xf);
        *out = p->len;
        return p->d;
    }
    return 0;
}


u8 *func_021EE9A4(u8 *p, u32 *out)
{
    p[4] = 0;
    p[5] = 0x30;
    *out = 2;
    return p + 4;
}


void func_021EE9B4(B *p, const void *src, int n)
{
    func_02082D44(src, p->d, n);
    p->len = n;
    p->mask = 0;
    p->cnt = 0;
    p->x = 0;
    p->f = 0;
    p->g = 0;
}


int func_021EE9E4(u8 *p, u32 *pos, u8 *a, u8 *b, u32 *dst)
{
    u8 h;
    int len;

    if (*pos == 0) {
        *pos = 2;
    }
    if (*pos < p[0]) {
        h = (p + *pos)[4];
        *a = (h >> 5) & 7;
        *b = h & 0x1f;
        len = *b * 4;
        *pos = *pos + 1;
        func_02082D44(p + 4 + *pos, dst, len);
        *pos = *pos + len;
        return 1;
    }
    return 0;
}


void func_021EEA30(int v)
{
    int i;

    for (i = 0; i < 4; i++)
        d_021F6388[i] = 0;
    d_021F6384 = v;
}


void func_021EEA54(void) { }


Obj *func_021EEA58(u32 a, int idx, u32 v, u32 heap)
{
    Obj *o;

    o = 0;
    if (d_021F6388[idx] == 0) {
        o = sub_02030734(heap, 0xbd0, 1, d_021F3AE8, 0x7e);
        o->f00 = a;
        o->idx = idx;
        o->hi = (u8)v;
        o->e = 0;
        o->f = 0;
        o->lo = 0;
    }
    if (d_021F6384 == 0) {
        if (d_021F6388[idx] == 0)
            d_021F6388[idx] = o;
        return d_021F6388[idx];
    }
    d_021F6388[idx] = o;
    return o;
}


/* 021EEAD0  clear the low nibble of byte +0xc and zero bytes +0xe/+0xf */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldrb r2, [r0, #0xc]; movs r1, #0; strb r1, [r0, #0xe]; strb r1, [r0, #0xf]; movs r1, #0xf; bics r2, r1; strb r2, [r0, #0xc]; bx lr.
 */
void func_021EEAD0(u8 *p)
{
    u8 v = p[0xc];

    p[0xe] = 0;
    p[0xf] = 0;
    p[0xc] = v & ~0xf;
}


void func_021EEAE0(void *p)
{
    func_020307B0(p);
}


/* 021EEAE8  call through a global pointer when it is set */
/*
 * 7 instructions, 16 bytes: push {r3, lr}; ldr r0, pool_021EEAF8; ldr r0, [r0]; cmp r0, #0; beq loc_021EEAF6; bl func_021D4C58; pop {r3, pc}.
 */
void func_021EEAE8(void)
{
    u32 g = *(u32 *)0x021F6384;
    if (g != 0)
        func_021D4C58(g);
}


/*
 * empty function: bx lr
 */
void func_021EEAFC(void)
{
}


void func_021EEB00(W *p, u16 a, const void *src, u16 n)
{
    p->mode = 1;
    p->f0f = a;
    p->h10 = a;
    p->h12 = n;
    func_02082D44(src, p->d, n);
    p->w4 = 0;
    p->w8 = 0;
    p->st = 0;
}


int func_021EEB2C(W *p)
{
    switch (p->mode) {
    case 1:
        if (func_021EEB84(p) == 0)
            break;
        p->mode = 3;
    case 3:
        if (func_021EEBA4(p) == 0)
            break;
        p->mode = 4;
    case 4:
        return 1;
    }
    return 0;
}


/*
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: cmp r1, #0; beq loc_021EEB6C; ldr r2, [r0, #8]; str r2, [r1]; ldr r0, [r0, #4]; bx lr.
 */
u32 func_021EEB64(struct QW *p, u32 *out)
{
    if (out != 0)
        *out = p->b;
    return p->a;
}


void func_021EEB70(W *p)
{
    p->mode = 0;
    if (p->hi != 0)
        func_021D4C58(p->hi);
}


u32 func_021EEB84(W *p)
{
    u16 *q;

    if (p->hi != 0) {
        q = &p->h10;
        return func_021D4B58(p->f0d, (u32)q, q[1] + 4);
    }
    return 1;
}


u32 func_021EEBA4(W *p)
{
    if (p->hi != 0) {
        if (func_021D4B98() != 0) {
            p->w8 = func_021D4BD4(p->f0d, (u8 **)(&p->w4));
            p->st = 1;
            return 1;
        }
        return 0;
    }
    return p->st;
}


void func_021EEBDC(W *p)
{
    p->h10 = 0;
    p->h12 = 4;
}


u8 func_021EEBE8(W *p)
{
    u8 *q;

    if (p->hi != 0) {
        if (func_021D4C60() != 0) {
            func_021D4C6C(&q);
            return ((struct Obj21627 *)q)->f0;
        }
        return 0;
    }
    if (p->st == 0)
        return p->h10;
    return 0;
}


u16 func_021EEC20(W *p, u8 **out)
{
    u8 *q;
    u8 *r;

    if (p->hi != 0) {
        func_021D4C6C(&q);
        r = q;
        *out = r + 4;
        return ((struct Obj21628 *)r)->f2;
    }
    *out = p->d;
    return p->h12;
}


u32 func_021EEC4C(W *p, u32 a, u32 b)
{
    if (p->hi != 0)
        return func_021D4C84(a, b);
    if (p->st == 0) {
        p->w4 = a;
        p->w8 = b;
        p->st = 1;
    }
    return 1;
}


void func_021EEC78(u32 a, u32 b, u32 c, u32 d)
{
    int i;

    d_021F6398.f00 = (void ***)a;
    d_021F6398.f04 = c;
    d_021F63D8.f10 = d;
    d_021F6398.f54 = b;
    d_021F63D8.f18 = func_021BA1A8((char **)a, 0x200);
    d_021F63D8.f1a = 0;
    d_021F6398.f08 = (u32)func_0201EC64(d);
    d_021F6398.f0c = (u32)func_020457B0(0x200 >> 1, d);
    for (i = 0; i < 8; i++) {
        d_021F6398.t[i] = (u32)func_02045B38(0, 2, d_021F3990[i], d);
    }
}


void func_021EECD8(void)
{
    int i;

    func_0201ED04((struct WordSet *)d_021F6398.f08);
    func_02045808((struct U16Vec *)d_021F6398.f0c);
    for (i = 0; i < 8; i++)
        func_02045C04((struct Rec *)d_021F6398.t[i]);
}


void func_021EED00(u8 a, u32 b)
{
    func_0201EEF4((struct WordSet *)d_021F6398.f08, b, func_021D5864((struct Work *)func_021B9940((char *)d_021F6398.f04, a)));
}


void func_021EED24(u8 a, u32 b)
{
    func_0201EEF4((struct WordSet *)d_021F6398.f08, b, func_021D5844(func_021B9940((char *)d_021F6398.f04, a)));
}


void func_021EED48(u8 a, u8 b)
{
    func_0201EE84((struct WordSet *)d_021F6398.f08, b, func_021D5864((struct Work *)func_021B9940((char *)d_021F6398.f04, a)));
}


void func_021EED6C(void *a, u8 b, u8 c)
{
    func_0201F0F8((struct WordSet *)a, b, (u8)func_021BA020((void *)d_021F6398.f00, c));
}


void func_021EED90(void *win, u8 slot, u8 k)
{
    u32 t;
    int v;

    if (k != 4) {
        if (func_021B9F70((*(void * *)&d_021F6398), k) != 0) {
            if ((int)func_021B86B8((*(void * *)&d_021F6398)) == 1) {
                v = func_021BA004((*(void * *)&d_021F6398), k);
                if (v != 0)
                    func_0201F134(win, slot, v);
            } else {
                v = func_021B9FAC((*(void * *)&d_021F6398), k, &t);
                func_0201EE0C(win, slot, (void *)v, func_0202A3CC(t), 1, 2);
            }
        } else {
            func_0201F02C(win, slot, (void *)func_021BA064((*(void * *)&d_021F6398), k));
        }
    } else {
        func_0201F02C(win, slot, (void *)func_021BA080((*(void * *)&d_021F6398)));
    }
}


/*
 * Variadic: copies n words into an eight-word table at d_021F6398 + 0x30
 * (zero-filling the rest), then hands the table (named separately at its
 * own address d_021F63C8) to func_021EEE80.
 */
void func_021EEE24(u32 a, u16 k, u32 n, ...)
{
    va_list ap;
    u32 i;

    va_start(ap, n);
    for (i = 0; i < n; i++) {
        d_021F6398.a[i] = va_arg(ap, s32);
    }
    for (; i < 8; i++) {
        d_021F6398.a[i] = 0;
    }
    func_021EEE80(a, k, (u32 *)d_021F63C8);
}


void func_021EEE80(u32 a, u16 k, u32 *p)
{
    u32 i;

    for (i = 0; i < 27; i++) {
        if (k == d_021F39A0[i]) {
            if (func_021B8BD0((*(void * *)&d_021F6398), (u8)*p) == 0)
                k = k + 1;
            break;
        }
    }
    func_021EEEC8(a, k, (u32)p);
}


void func_021EEEC8(u32 a, u32 b, u32 c)
{
    func_02045CAC((struct MsgBank *)d_021F6398.t[0], b, (void *)d_021F6398.f0c);
    func_021EEFE0((void *)d_021F6398.f0c, (const u32 *)c, (void *)d_021F6398.f08);
    func_0201F250((struct WordSet *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}


void func_021EEEF4(u32 a, u16 b, u32 c)
{
    u32 i;

    for (i = 0; i < 14; i++) {
        if (b == d_021F39D8[i].id) {
            d_021F39DC[i].fn(a, b, c);
            return;
        }
    }
    func_021EF1CC(a, b, c);
}


/*
 * Walks a message string for the first 0xF000 tag that func_0201D5CC calls a
 * word reference; the guard on p wraps the whole walk (two `return 0` tails).
 */
u16 *func_021EEF20(u16 *p, u32 *o1, u16 *o2, u8 *o3)
{
    u16 end;
    u32 tag;

    if (p != 0) {
        end = func_02045A98();
        tag = func_0201D5C4();
        while (*p != end) {
            if (*p == tag) {
                if (func_0201D5CC(p) != 0) {
                    *o3 = func_0201D670(p, 0);
                    *o1 = func_0201D5F4(p);
                    *o2 = func_0201D658(p);
                    return func_0201D688(p);
                }
                p = func_0201D688(p);
            } else {
                p = p + 1;
            }
        }
        return 0;
    }
    return 0;
}


u8 func_021EEF98(void *s)
{
    u32 o1;
    u16 o2;
    u8 o3;
    u16 *p;
    u8 n;

    p = func_02045A90(s);
    n = 0;
    if (p != 0) {
        do {
            p = func_021EEF20(p, &o1, &o2, &o3);
            if (p != 0 && o1 == 1) {
                if (o2 == 1 || o2 == 2 || o2 == 12)
                    n = n + 1;
            }
        } while (p != 0);
    }
    return n;
}


/*
 * Two passes over message tags: count removed slots, then install values.
 * A u8 kind local narrows before argument setup; const values schedules
 * the index shift ahead of the last outgoing argument store.
 */
void func_021EEFE0(void *s, const u32 *values, void *w)
{
    u16 end;
    u32 tag;
    u8 removed[8];
    u16 *p;
    u32 i;
    u32 slot;
    u32 index;
    u8 group;
    u8 kind;
    end = func_02045A98();
    tag = func_0201D5C4();
    for (i = 0; i < 8; i++)
        removed[i] = 0;
    p = func_02045A90(s);
    while (*p != end) {
        if (*p == tag) {
            if (func_0201D5CC(p)) {
                slot = func_0201D670(p, 0);
                if ((u8)func_0201D5F4(p) == 1 && func_0201D658(p) == 14) {
                    for (i = slot + 1; i < 8; i++)
                        removed[i]++;
                }
            }
            p = func_0201D688(p);
        } else
            p++;
    }
    p = func_02045A90(s);
    while (*p != end) {
        if (*p == tag) {
            if (func_0201D5CC(p)) {
                slot = func_0201D670(p, 0);
                index = slot;
                group = func_0201D5F4(p);
                if (slot >= removed[slot])
                    index = slot - removed[slot];
                if (group == 2) {
                    kind = func_0201D658(p) + 1;
                    func_0201EFA4(w, slot, values[index], kind, 0, 1);
                } else {
                    switch (func_0201D658(p)) {
                    case 14:
                        func_021EED6C(w, slot, values[index]);
                        break;
                    case 0:
                        func_021EED90(w, slot, values[index]);
                        break;
                    case 2:
                        if (d_021F63D8.f1a == 0)
                            func_021EED00(values[index], slot);
                        else
                            func_021EED24(values[index], slot);
                        break;
                    case 12:
                        func_021EED24(values[index], slot);
                        break;
                    case 1:
                        func_021EED48(values[index], slot);
                        break;
                    case 3:
                        func_0201F020(w, slot, values[index]);
                        break;
                    case 6:
                        func_0201EF8C(w, slot, values[index]);
                        break;
                    case 7:
                        func_0201EF34(w, slot, values[index]);
                        break;
                    case 9:
                        func_0201EF40(w, slot, values[index]);
                        break;
                    case 15:
                        func_0201F020(w, slot, values[index]);
                        break;
                    }
                }
            }
            p = func_0201D688(p);
        } else
            p++;
    }
}


void func_021EF1CC(u32 a, u16 b, u32 c)
{
    func_02045CAC((struct MsgBank *)d_021F6398.t[1], b, (void *)d_021F6398.f0c);
    if (func_021EEF98((void *)d_021F6398.f0c) == 2)
        func_021EF280(a, b, (u32 *)c);
    else
        func_021EF204(a, b, (u32 *)c);
}


void func_021EF204(u32 a, u32 b, u32 *p)
{
    int x;
    u8 k = *p;

    if (d_021F63D8.f18 == 0
        && func_021B8CE8((int)d_021F6398.f00, (u8)d_021F6398.f54, func_021B8DDC(k)) != 0) {
        if (func_021B86B8((void ***)d_021F6398.f00) == 0 || (int)func_021B86B8((void ***)d_021F6398.f00) == 4)
            x = 1;
        else
            x = 2;
    } else {
        x = 0;
    }
    func_02045CAC((void *)d_021F6398.t[1], (u16)(b + x), (void *)d_021F6398.f0c);
    func_021EEFE0((void *)d_021F6398.f0c, p, (void *)d_021F6398.f08);
    func_0201F250((void *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}


static inline int classify(u8 k)
{
    int x;
    if (d_021F63D8.f18 == 0 && func_021B8CE8((int)d_021F6398.f00, (u8)d_021F6398.f54, func_021B8DDC(k))) {
        if (func_021B86B8((void ***)d_021F6398.f00) == 0 || (int)func_021B86B8((void ***)d_021F6398.f00) == 4) x = 1;
        else x = 2;
    } else x = 0;
    return x;
}


/*
 * lever: explicit b = b + classify(k) avoids compound-assignment RHS narrowing.
 */
void func_021EF280(u32 a, u16 b, u32 *p)
{
    u8 k = p[1];
    int x = classify(p[0]);
    switch (x) {
    case 0:
        b = b + classify(k);
        break;
    case 1:
        b += 3;
        goto second;
    case 2:
        b += 5;
    default:
second:
        if (x == classify(k)) b++;
        break;
    }
    func_02045CAC((struct MsgBank *)d_021F6398.t[1], b, (void *)d_021F6398.f0c);
    func_021EEFE0((void *)d_021F6398.f0c, p, (void *)d_021F6398.f08);
    func_0201F250((struct WordSet *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}


/*
 * Twin of func_021EF460 (partial sum in a named local, x added last).
 */
void func_021EF3A4(u32 a, u32 b, P_021EF3A4 *p)
{
    u8 idx;
    int sel;
    int x;
    u8 k;
    u32 pos;

    idx = p->f8 - 1;
    sel = 0;
    if (p->fc >= 3)
        sel = 2;
    if (p->fc == 2)
        sel = 1;
    b = (u16)(b + (u16)(sel * 0x15));
    k = p->f0;
    if (d_021F63D8.f18 == 0
        && func_021B8CE8((int)d_021F6398.f00, (u8)d_021F6398.f54, func_021B8DDC(k)) != 0) {
        if (func_021B86B8((void ***)d_021F6398.f00) == 0 || (int)func_021B86B8((void ***)d_021F6398.f00) == 4)
            x = 1;
        else
            x = 2;
    } else {
        x = 0;
    }
    func_021EED00(p->f0, 0);
    func_0201EF40((void *)d_021F6398.f08, 1, p->f4);
    pos = b + idx * 3;
    func_02045CAC((void *)d_021F6398.t[1], (u16)(pos + x), (void *)d_021F6398.f0c);
    func_0201F250((void *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}


/*
 * Lever: the partial sum b + idx * 3 is a named local (`pos`) and x is added
 * last; written inline as `b + idx * 3 + x` the final add comes out with its
 * operands swapped (one byte).
 */
void func_021EF460(u32 a, u32 b, P_021EF460 *p)
{
    u8 idx;
    int sel;
    int x;
    u8 k;
    u32 pos;

    idx = p->f4 - 1;
    sel = 0;
    if (p->f8 >= 3)
        sel = 2;
    if (p->f8 == 2)
        sel = 1;
    b = (u16)(b + (u16)(sel * 0x15));
    func_021EED00(p->f0, 0);
    k = p->f0;
    if (d_021F63D8.f18 == 0
        && func_021B8CE8((int)d_021F6398.f00, (u8)d_021F6398.f54, func_021B8DDC(k)) != 0) {
        if (func_021B86B8((void ***)d_021F6398.f00) == 0 || (int)func_021B86B8((void ***)d_021F6398.f00) == 4)
            x = 1;
        else
            x = 2;
    } else {
        x = 0;
    }
    pos = b + idx * 3;
    func_02045CAC((void *)d_021F6398.t[1], (u16)(pos + x), (void *)d_021F6398.f0c);
    func_0201F250((void *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}


void func_021EF508(u32 a, int b, u32 *p)
{
    u8 r5 = p[1] - 1;
    int k;
    int t;
    u8 id;

    func_021EED00(p[0], 0);
    id = p[0];
    if (d_021F6398.f58 == 0 &&
        func_021B8CE8((int)d_021F6398.f00, (u8)d_021F6398.f54,
                      func_021B8DDC(id))) {
        if (func_021B86B8(d_021F6398.f00) == 0 || func_021B86B8(d_021F6398.f00) == (void *)4)
            k = 1;
        else
            k = 2;
    } else {
        k = 0;
    }
    t = b + r5 * 3;
    func_02045CAC((struct MsgBank *)d_021F6398.t[1], (u16)(t + k), (void *)d_021F6398.f0c);
    func_0201F250((struct WordSet *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}


void func_021EF594(u32 a, u32 b, u32 *p)
{
    u8 id = p[0];
    int k;

    if (id != func_021B8FF4((u8 *)d_021F6398.f00)) {
        if (func_021B9F70((u8 *)d_021F6398.f00, id))
            k = 0x23;
        else
            k = 0x22;
    } else {
        k = 0x21;
    }
    func_02045CAC((struct MsgBank *)d_021F6398.t[0], k, (void *)d_021F6398.f0c);
    func_021EEFE0((void *)d_021F6398.f0c, (const u32 *)((u32)p), (void *)d_021F6398.f08);
    func_0201F250((struct WordSet *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}


void func_021EF5E8(u32 a, u8 b, u16 c)
{
    int k;
    u16 t;

    if (d_021F6398.f58 == 0 &&
        func_021B8CE8((int)d_021F6398.f00, (u8)d_021F6398.f54, func_021B8DDC(b))) {
        if (func_021B86B8(d_021F6398.f00) == 0 || func_021B86B8(d_021F6398.f00) == (void *)4)
            k = 1;
        else
            k = 2;
    } else {
        k = 0;
    }
    func_021EED00(b, 0);
    t = c * 3;
    func_02045CAC((struct MsgBank *)d_021F6398.t[2], (u16)(t + k), (void *)d_021F6398.f0c);
    func_0201F250((struct WordSet *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}


void func_021EF664(int a, u16 b, int c)
{
    u16 k;

    if (b != 0) {
        k = (b - 1) * 3;
        if (c == 0)
            k = k + 1;
        else
            k = k + 2;
        func_02045CAC((struct MsgBank *)d_021F6398.t[7], k, (void *)a);
    }
}


void func_021EF694(u32 a, u32 b)
{
    func_02045CAC((struct MsgBank *)d_021F6398.t[3], b, (void *)a);
}


void func_021EF6A8(u32 a, u32 b, u32 c)
{
    func_021EF6B0(a, b, c);
}


void func_021EF6B0(u32 a, u32 b, u32 c)
{
    func_02045CAC((struct MsgBank *)d_021F6398.t[5], b, (void *)d_021F6398.f0c);
    d_021F6398.f5a = 1;
    func_021EEFE0((void *)d_021F6398.f0c, (const u32 *)c, (void *)d_021F6398.f08);
    d_021F6398.f5a = 0;
    func_0201F250((struct WordSet *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}


/*
 * Tail-call stub (ldr r3,[pc]; bx r3) to func_021EF6F0; callee of func_021EA55C case 6.
 */
void func_021EF6E8(u32 a, u32 b, u32 c)
{
    func_021EF6F0(a, b, c);
}


/*
 * Unlabelled leaf, callee of the tail stub 0x021EF6E8 that func_021EA55C calls.
 * Twin of func_021EF6B0 without the +0x5a flag stores, using the +0x28 slot.
 */
void func_021EF6F0(u32 a, u32 b, u32 c)
{
    func_02045CAC((struct MsgBank *)d_021F6398.t[6], b, (void *)d_021F6398.f0c);
    func_021EEFE0((void *)d_021F6398.f0c, (const u32 *)c, (void *)d_021F6398.f08);
    func_0201F250((struct WordSet *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}


void func_021EF71C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    func_02045CAC((struct MsgBank *)d_021F6398.t[3], 0x10, (void *)d_021F6398.f0c);
    func_0201EFA4((struct WordSet *)d_021F6398.f08, 0, b, 2, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f08, 1, c, 2, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f08, 2, d, 2, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f08, 3, e, 2, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f08, 4, f, 2, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f08, 5, g, 2, 0, 1);
    func_0201F250((struct WordSet *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}


void func_021EF7AC(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    func_02045CAC((struct MsgBank *)d_021F6398.t[3], 0x11, (void *)d_021F6398.f0c);
    func_0201EFA4((struct WordSet *)d_021F6398.f08, 0, b, 3, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f08, 1, c, 3, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f08, 2, d, 3, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f08, 3, e, 3, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f08, 4, f, 3, 0, 1);
    func_0201EFA4((struct WordSet *)d_021F6398.f08, 5, g, 3, 0, 1);
    func_0201F250((struct WordSet *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}


void func_021EF83C(S *a, u32 i)
{
    u32 j;

    a->t[i] = 0;
    a->c[i] = func_021E8918();
    a->z48[i] = 0;
    a->z128[i] = 0;
    a->used[i] = 0;
    for (j = 0; j < 6; j++)
        a->w[i][j] = 0x1f;
}


void func_021EF874(int a)
{
    func_021EF988((S_021EF988 *)&d_021F63F4, a);
}


int func_021EF884(void)
{
    return func_021EF9A8((u32 *)(&(*(char *)&d_021F63F4)));
}


int func_021EF894(void)
{
    return func_021EF9B0((u32 *)(&(*(char *)&d_021F63F4)));
}


int DWC_StartUtilityEx(int a, int b)
{
    return (int)func_021EF9C0((int *)(&d_021F63F4), a, b);
}


/*
 * Tail call into the countdown leaf func_021EF9D0 with the static record.
 *
 * 2026-10-03: byte-correct, MATCH only because 0x021EF9D0 has no label yet.
 * Its witness is filed EXACT as src/matched/ov/ov093_func_021EF9D0.c; once
 * the integrator seeds that start this verifies EXACT.
 */
u32 func_021EF8B8(void)
{
    return func_021EF9D0(((Countdown *)&d_021F63F4));
}


int func_021EF8C8(u32 a, Slot c)
{
    return func_021EF9F4((S_021EF9F4 *)&d_021F63F4, a, c, 1);
}


int func_021EF8E8(int a)
{
    return func_021EFA94(&(*(char *)&d_021F63F4), a);
}


int func_021EF8F8(int a, int b)
{
    return func_021EFAD8(&(*(char *)&d_021F63F4), a, b);
}


int func_021EF90C(int a)
{
    return func_021EFB34(&(*(char *)&d_021F63F4), a);
}


void SetBottomScreenLineCentered(int line, int color, char *text)
{
    func_021EFC1C(&(*(char *)&d_021F63F4), line, color, text);
}


int func_021EF934(int a, int b)
{
    return func_021EFC78(&(*(char *)&d_021F63F4), a, b);
}


int func_021EF948(int a)
{
    return (int)func_021EFCE4(&(*(char *)&d_021F63F4), a);
}


S *func_021EF958(u32 heap)
{
    S *p = func_02030734(heap, 0x168, 1, d_021F3AF8, 0x10c);

    func_021EF988((S_021EF988 *)p, 0);
    return p;
}


void func_021EF980(void *p) { func_020307B0(p); }


void func_021EF988(S_021EF988 *p, u32 v)
{
    u32 i;

    for (i = 0; i < 8; i++)
        func_021EF83C((S *)p, i);
    p->pad00[0] = v;
    p->pad00[1] = 0xff;
}


/*
 * Sole blocker of the claimed 021D3D84 follower.
 * Body ends at 021EF9B0; larger unlabelled follower remains outside this leaf.
 */
u8 func_021EF9A8(u32 *p) { return (u8)*p; }


int func_021EF9B0(u32 *p)
{
    if (p[0] != 0)
        return p[1];
    return 0;
}


int *func_021EF9C0(int *p, int a, int b)
{
    p[0] = a;
    p[1] = b;
    return p;
}


void func_021EF9C8(int *p)
{
    p[0] = 0;
    p[1] = 0;
}


/*
 * Unlabelled leaf (witness for func_021EF8B8). Countdown timer: when the
 * value is set and the counter is not 0xff, decrement the counter; when it
 * reaches zero, clear the value and return its low byte.
 */
u32 func_021EF9D0(Countdown *p)
{
    u32 v = p->value;
    if (v != 0 && p->count != 0xff && --p->count == 0) {
        v = (u8)v;
        p->value = 0;
        return v;
    }
    return 0;
}


/*
 * Eight-slot table object: six u32[8] arrays and a u32[8][6] block, all
 * indexed by the slot b.  Written as struct member arrays, the load of
 * used[b] keeps b*4 in its own register while the c/z48/z128 stores
 * recompute a + b*4 (the raw `*(u32 *)(a + K + b * 4)` casts CSE'd b*4 and
 * swapped b and b*4: docs/notes/pkt_ov093_021EF9F4.c.txt).  The third
 * parameter is a one-word struct passed by value (push {r0-r3} frame).
 */
int func_021EF9F4(S_021EF9F4 *a, u32 b, Slot c, int d)
{
    u32 i;
    u32 x;

    if (a->used[b] == 0) {
        if (d != 0) {
            a->t[b] = func_06898020(b, 0);
            if (a->t[b] == 0)
                return 0;
        }
        a->used[b] = 1;
        a->c[b] = c.v;
        a->z48[b] = 0;
        a->z128[b] = 0;
        for (i = 0; i < 6; i++)
            a->w[b][i] = 0x1f;
        x = func_021E8A98(c);
        if (x != 0x1f)
            func_021EFAD8((char *)a, b, x);
        return 1;
    }
    return 0;
}
