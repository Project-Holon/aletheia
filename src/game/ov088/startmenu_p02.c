/*
 * file:     startmenu_p02.c
 * unit:     yes
 * function: func_021B99E0, func_021B99EC, func_021B9A14, func_021B9A1C, func_021B9BD4
 * address:  0x021B99E0
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
 *   func_020310C4  0x020310C4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02031140  0x02031140  arm
 *   func_02046788  0x02046788  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02049624  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040588  0x02040588  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201C724  0x0201C724  thumb
 *   d_021BD470     0x021BD470  data  ov088  a4
 *   d_021BD490     0x021BD490  data  ov088  a4
 *   d_021BD430     0x021BD430  data  ov088  a4
 *   d_021BD450     0x021BD450  data  a4
 *   func_02041EE4  0x02041EE4  arm
 *   func_020111E8  0x020111E8  thumb
 */
struct Tcbl;
struct Node;
struct S02031140;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct GfFont;
struct MsgBank;
struct StrObj;
struct U16Vec;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef struct {
    u32 win;
    u32 bmp;
    u32 win2;
    u8  fC;
    u8  padD[3];
    u32 f10;
    u32 font;
    u32 print;
    u32 f1C;
    u32 msg;
    u32 buf;
} Work;

typedef struct BgTemplate {
    u32 w[8];
} BgTemplate;

void func_020310C4(struct Tcbl *p);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);
extern void func_02030EAC(struct Node *n);
extern void func_02031140(struct S02031140 *p);
extern void func_02046788(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_0204989C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_020409B4(u32 layer);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern u32 func_020111E8(void);
void func_021B99E0(int *p);
void func_021B99EC(int *p);
void func_021B9A14(unsigned short *p, unsigned short a, unsigned short b);
void func_021B9A1C(Work *p, u32 heap);
void func_021B9BD4(int *p);
extern const BgTemplate d_021BD470;
extern const BgTemplate d_021BD490;
extern const BgTemplate d_021BD430;
extern const BgTemplate d_021BD450;


void func_021B99E0(int *p)
{
    func_020310C4((struct Tcbl *)p[0]);
}


void func_021B99EC(int *p)
{
    func_0204363C(1);
    func_0204361C();
    func_02030EAC((struct Node *)p[1]);
    func_02031140((struct S02031140 *)p[0]);
    func_02046788();
    func_020450C8();
    func_0203F9B4();
}

void func_021B9A14(unsigned short *p, unsigned short a, unsigned short b)
{
    p[4] = a;
    p[5] = b;
}


void func_021B9A1C(Work *p, u32 heap)
{
    int w;

    func_0203FCA0(3, &d_021BD470, 0);
    func_0203FCA0(5, &d_021BD490, 0);
    func_0203FCA0(7, &d_021BD430, 0);
    func_0203FCA0(6, &d_021BD450, 0);
    func_02049624(0x1A, 9, 3, 0, 0, 1, heap);
    func_0204989C(0x1A, 10, 3, 0, 0, 1, heap);
    func_02049B40(0x1A, 8, 0, 0, 0, heap);
    func_020409B4(3);
    func_02040588(3, 1);
    func_02049624(0x1A, 0, 7, 0, 0x8000, 1, heap);
    func_0204989C(0x1A, 1, 7, 0, 0, 1, heap);
    func_02049B40(0x1A, 2, 4, 0, 0, heap);
    func_020409B4(7);
    func_02040588(7, 1);
    func_0204989C(0x1A, 3, 6, 0, 0, 1, heap);
    func_02040588(6, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    p->win = func_020450F0(5, 0, 0x13, 0x20, 2, 0xA, 0);
    p->bmp = (u32)func_02045770((struct Descriptor *)p->win);
    func_02043B5C((struct CharBuf *)p->bmp, 0);
    func_02045374((struct Cfg *)p->win);
    func_02045334((struct Descriptor *)p->win);
    p->fC = 0;
    p->win2 = p->win;
    func_020409B4(5);
    p->font = (u32)func_0201D7EC(0x17, 0, 0, 0, heap);
    p->print = func_0201C440((void *)heap);
    p->msg = (u32)func_02045B38(0, 2, 0xB5, heap);
    p->buf = (u32)func_020457B0(0x40, heap);
    func_02045CAC((struct MsgBank *)p->msg, 1, (void *)p->buf);
    w = func_0201D304((struct StrObj *)p->buf, p->font, 0);
    func_0201C724((void *)p->print, p->bmp, (s16)(0x80 - w / 2), (s16)0, p->buf, p->font, 0x440);
    p->f10 = 1;
}


void func_021B9BD4(int *p)
{
    func_02040588(5, 0);
    func_02041EE4(6, 0, p[10] / 2);
    if (func_020111E8() == 0x15) {
        p[10]++;
    } else {
        p[10]--;
    }
}
