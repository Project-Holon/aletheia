/*
 * file:     unit_021BD8D8_p03.c
 * unit:     yes
 * function: func_021BDD48, func_021BDD54, func_021BDD60, func_021BDD98, func_021BDDA8, func_021BDDB4, func_021BDDD0, func_021BDDF4, func_021BDE30, func_021BDE94, func_021BDF7C, func_021BE028, func_021BE030, func_021BE040, func_021BE21C, func_021BE244, func_021BE26C, func_021BE2A8
 * address:  0x021BDD48
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C27D0  0x021C27D0  thumb
 *   func_021C27D8  0x021C27D8  thumb
 *   func_0201293C 0x0201293C thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AA1C 0x0201AA1C thumb
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BCBBC 0x021BCBBC thumb ov099
 *   func_0203D644 0x0203D644 arm
 *   func_021BDD0C 0x021BDD0C thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0204363C 0x0204363C arm
 *   func_02045088 0x02045088 arm
 *   func_021BE53C 0x021BE53C thumb ov099
 *   func_020056A0 0x020056A0 thumb
 *   func_021BE5B4 0x021BE5B4 thumb ov099
 *   func_021BE5B8 0x021BE5B8 thumb ov099
 *   func_020434DC 0x020434DC arm
 *   func_021BB42C 0x021BB42C thumb ov099
 *   func_021BB4D0 0x021BB4D0 thumb ov099
 *   func_021BB4EC 0x021BB4EC thumb ov099
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_021C1A44 0x021C1A44 thumb ov099
 *   func_021C1AC0 0x021C1AC0 thumb ov099
 *   func_021BE384 0x021BE384 thumb ov099
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_021BB0B4 0x021BB0B4 thumb ov099
 *   func_021BE538 0x021BE538 thumb ov099
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_0204A648 0x0204A648 arm
 *   sub_020433E0  0x020433E0  arm
 *   data_021C3AA0  0x021C3AA0  data
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_020414C4 0x020414C4 arm
 *   func_0204047C 0x0204047C arm
 *   d_021C37F4 0x021C37F4 data a4
 *   d_021C396C 0x021C396C data a4
 *   d_021C382C 0x021C382C data a4
 *   d_021C384C 0x021C384C data a4
 *   d_021C386C 0x021C386C data a4
 *   d_021C38AC 0x021C38AC data a4
 *   d_021C38CC 0x021C38CC data a4
 *   d_021C392C 0x021C392C data a4
 *   d_021C394C 0x021C394C data a4
 *   func_021B9670 0x021B9670 thumb ov099
 *   func_021C203C 0x021C203C thumb ov099
 *   func_02082BCC 0x02082BCC arm
 *   func_021B9A50  0x021B9A50  thumb  ov099
 */
#include "../../matched/include/Obj13698.h"
#include "../../matched/include/Obj07954.h"
#include "../../matched/include/Obj03222.h"
#include "../../matched/include/Obj00008.h"

struct BigObj;
struct Entry;
struct GfFont;
struct MsgBank;
struct Node;
struct WordSet;
struct Bank;
struct Rec;
struct DispVram;
struct BgTemplate;
struct DispConfig;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BDD48;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef struct {
    char pad[0x18];
    u8 f18;
} S;

typedef unsigned long  u32_021BDD54;

typedef unsigned long  u32_021BDD60;

typedef unsigned long  u32_021BDDA8;

typedef unsigned long  u32_021BDDB4;

typedef unsigned int u32_021BDDD0;

typedef unsigned int   u32_021BDDF4;

typedef unsigned int   u32_021BDE30;

typedef unsigned int u32_021BDE94;

typedef unsigned int   u32_021BDF7C;

typedef unsigned long  u32_021BE030;

typedef unsigned int u32_021BE040;

typedef struct { u32_021BE040 a, b, c, d; } Disp;

typedef struct { u32_021BE040 a, b, c, d; u8 e, f, g, h; u32_021BE040 i; u8 j, k, l, m; u32_021BE040 n; } Bg;

typedef unsigned long  u32_021BE21C;

typedef unsigned long  u32_021BE244;

typedef unsigned long  u32_021BE2A8;

extern u8 func_021C27D0(S *s);
extern u8 func_021C27D8(S *s);
extern u32_021BDDD0 func_0201293C(const struct BigObj *p);
extern void *func_02012934(const struct BigObj *p);
extern u32_021BDDD0 func_0201AA1C(void *);
extern int func_021BCB70(void *rules, const struct BigObj *obj, u32_021BDDF4 *mask);
extern int func_021BCBBC(int,int,int *);
extern void func_0203D644(int);
extern void func_021BDD0C(void *, int);
extern struct Entry *func_020399A8(void);
extern void func_0203D1E8(u32_021BDE30 unused, void *arg);
extern void func_02030EAC(struct Node *n);
extern void func_02043534(u32_021BDE94);
extern void func_020435F4(u32_021BDE94);
extern void *func_020490F4(u32_021BDE94 id, u32_021BDE94 heap);
extern void func_02049238(void *);
extern struct WordSet *func_0201EC64(u32_021BDE94 heap);
extern struct MsgBank *func_02045B38(u32_021BDE94 resident, u32_021BDE94 arcId, u32_021BDE94 fileId, u32_021BDE94 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32_021BDE94 heapId);
extern void func_0204363C(u32_021BDE94);
extern void func_02045088(u16);
extern void func_021BE53C(char *p, int v);
extern void *func_020056A0(u32_021BDE94, u32_021BDE94, u32_021BDE94);
extern void func_021BE5B4(void *);
extern void func_021BE5B8(char *, void *);
extern void func_020434DC(u32_021BDE94, u32_021BDE94);
extern void func_021BB42C(void *p);
extern void func_021BB4D0(char *p);
extern void func_021BB4EC(void *p);
extern int func_021B96CC(int *p);
extern int func_021C1A44(char *p);
extern void func_021C1AC0(char *p);
extern void func_021BE384(void *p);
extern void func_0204B084(void *p);
extern unsigned int func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_021BB0B4(char *p);
extern void func_021BE538(char *p);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32_021BDF7C func_0201D83C(void *ptr);
extern void func_0204A648(void);
extern void sub_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32_021BE040 bgId, const struct BgTemplate *tmpl, u32_021BE040 type);
extern void func_020414AC(u32_021BE040);
extern void func_020409B4(u32_021BE040);
extern void func_02040C14(u32_021BE040, u32_021BE040, u32_021BE040, u32_021BE040);
extern void func_020414C4(u32_021BE040 idx);
extern void func_0204047C(int, u16);
extern void func_021B9670(char *);
extern void func_021C203C(char *,int);
extern void func_02082BCC(void *,int,int);
extern u8 func_021B9A50(char *p);
u8 func_021BDD48(int unused, S *s);
u8 func_021BDD54(int unused, S *s);
int func_021BDD60(int x);
int func_021BDD98(int x);
BOOL func_021BDDA8(int x);
BOOL func_021BDDB4(int a, void *b);
int func_021BDDD0(char *p);
int func_021BDDF4(char *p);
void func_021BDE30(void *p, int kind, int value);
void func_021BDE94(char *p);
void func_021BDF7C(char *p);
void func_021BE028(void);
void func_021BE030(void);
void func_021BE040(u16 heap);
void func_021BE21C(char *p, void *v);
void func_021BE244(char *p, void *v);
void func_021BE26C(char *p);
void *func_021BE2A8(char *p, int key);
extern u8 data_021C3AA0[];
extern const Disp d_021C37F4;
extern const Bg d_021C396C, d_021C382C, d_021C384C, d_021C386C;
extern const Bg d_021C38AC, d_021C38CC, d_021C392C, d_021C394C;


u8 func_021BDD48(int unused, S *s)
{
    return func_021C27D0(s);
}


/*
 * Tail call onto the byte getter func_021C27D8 on the second argument.
 */
u8 func_021BDD54(int unused, S *s)
{
    return func_021C27D8(s);
}


int func_021BDD60(int x)
{
    switch (x) {
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        return 1;

    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    default:
        return 0;
    }
}

int func_021BDD98(int x) {
    if (x < 15 && x > 3) return 1;
    return 0;
}


/*
 * True when the argument is 2.
 */
BOOL func_021BDDA8(int x)
{
    if (x == 2) {
        return 1;
    }

    return 0;
}


/*
 * True when the arm9 predicate accepts b and the selector is 4.
 */
BOOL func_021BDDB4(int a, void *b)
{
    if (func_021BDD60((int)b) != 0 && a == 4) {
        return 1;
    }

    return 0;
}

int func_021BDDD0(char *p)
{
    func_0201293C(((struct Obj13698 *)p)->fC4);
    if ((int)func_0201AA1C(func_02012934(((struct Obj13698 *)p)->fC4)) >= 2) return 1;
    return 0;
}

int func_021BDDF4(char *p) {
 int out;
 if (func_021BCB70((void *)(((struct Obj07954 *)p)->f1348),(const struct BigObj *)(((struct Obj07954 *)p)->fC4),(u32_021BDDF4 *)(&out)) && func_021BCBBC(((struct Obj07954 *)p)->f1348,((struct Obj07954 *)p)->fCC,&out)) return 0;
 return 1;
}

void func_021BDE30(void *p, int kind, int value)
{
    if (kind == 1) {
        func_0203D644(0);
        func_021BDD0C(p, 0);
    } else {
        if (func_021BDDB4(kind, (void *)value)) func_0203D644(1);
    }
    switch (kind) {
    case 2:
    case 5:
        func_0203D1E8((int)func_020399A8(), (void *)1);
        return;
    case 0:
    case 1:
    case 3:
    case 4:
    case 6:
    default:
        func_0203D1E8((int)func_020399A8(), (void *)1);
        break;
    }
}

/*
 * prototypes: 49238 SDK asm reads r0 despite its void(void) declaration; caller-visible handle preserved. Empty 021BE5B4 preserves caller-loaded live r0; 021BE5B8 preserves visible r1 despite no body read.
 * volatile: RMW display registers read at 021BDEB4/021BDEC0 and written at 021BDEBC/021BDEC4.
 */
void func_021BDE94(char *p)
{
    void *h;
    if (((struct Obj03222 *)p)->f0 != 0) func_02030EAC(((struct Obj03222 *)p)->f0);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u32_021BDE94 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32_021BDE94 *)0x04001000 &= 0xffffe0ff;
    h = func_020490F4(0x21, 0x21);
    ((struct Obj03222 *)p)->fDC = func_0201EC64(0x21);
    ((struct Obj03222 *)p)->fE0 = func_02045B38(0, 2, 0xd1, 0x21);
    ((struct Obj03222 *)p)->fE4 = func_02045B38(0, 2, 0xe8, 0x21);
    ((struct Obj03222 *)p)->fE8 = func_0201D7EC(0x17, 0, 0, 0, 0x21);
    ((struct Obj03222 *)p)->fEC = func_0201D7EC(0x17, 3, 0, 0, 0x21);
    func_0204363C(1);
    func_021BE030();
    func_021BE040(0x21);
    func_02045088(0x21);
    func_021BE53C(p, (int)h);
    ((struct Obj03222 *)p)->f0 = func_020056A0((u32_021BDE94)func_021BE028, (u32_021BDE94)p, 1);
    func_021BE5B4(((struct Obj03222 *)p)->f0);
    func_021BE5B8(p, h);
    func_020434DC(0x10, 1);
    func_02049238(h);
}

void func_021BDF7C(char *p)
{
    if (((struct Obj00008 *)p)->f0 != 0) func_02030EAC(((struct Obj00008 *)p)->f0);
    func_021BB42C(p);
    func_021BB4D0(p);
    func_021BB4EC(p);
    if (func_021B96CC((int *)(p + 0x274)) == 1) func_021BE26C(p);
    if (func_021C1A44(p) == 1) func_021C1AC0(p);
    func_021BE384(p + 0x898);
    func_0204B084(((struct Obj00008 *)p)->f114);
    func_0204B1CC(((struct Obj00008 *)p)->f110);
    func_0204A5AC();
    func_021BB0B4(p);
    func_021BE538(p);
    func_020450C8();
    func_0203F9B4();
    func_02045C04(((struct Obj00008 *)p)->fE4);
    func_02045C04(((struct Obj00008 *)p)->fE0);
    func_0201ED04(((struct Obj00008 *)p)->fDC);
    func_0201D83C(((struct Obj00008 *)p)->fEC);
    func_0201D83C(((struct Obj00008 *)p)->fE8);
}

void func_021BE028(void)
{
    func_0204A648();
}


void func_021BE030(void)
{
    sub_020433E0((const struct DispVram *)data_021C3AA0);
}

void func_021BE040(u16 heap)
{
    Disp d;
    Bg b0, b1, b2, b3, b4, b5, b6, b7;
    int i;
    func_0203F8F4(heap);
    d = d_021C37F4;
    func_0203FC28((struct DispConfig *)(&d));
    b0 = d_021C396C;
    i = 0;
    func_0203FCA0(0, (const struct BgTemplate *)(&b0), 0);
    func_020414AC(0);
    func_020409B4(0);
    b1 = d_021C382C;
    func_0203FCA0(1, (const struct BgTemplate *)(&b1), 0);
    func_020414AC(1);
    func_020409B4(1);
    b2 = d_021C384C;
    func_0203FCA0(2, (const struct BgTemplate *)(&b2), 0);
    func_02040C14(2, 0, 1, 0);
    func_020414AC(2);
    func_020409B4(2);
    b3 = d_021C386C;
    func_0203FCA0(3, (const struct BgTemplate *)(&b3), 0);
    func_020414AC(3);
    func_020409B4(3);
    b4 = d_021C38AC;
    func_0203FCA0(4, (const struct BgTemplate *)(&b4), 0);
    func_020414AC(4);
    b5 = d_021C38CC;
    func_0203FCA0(5, (const struct BgTemplate *)(&b5), 0);
    func_020414AC(5);
    b6 = d_021C392C;
    func_0203FCA0(6, (const struct BgTemplate *)(&b6), 0);
    func_020414AC(6);
    b7 = d_021C394C;
    func_0203FCA0(7, (const struct BgTemplate *)(&b7), 0);
    func_020414AC(7);
    for (; i < 7; i++) func_020414C4((u8)i);
    func_0204047C(0, 3);
    func_0204047C(1, 1);
    func_0204047C(3, 1);
    func_0204047C(2, 0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
}


void func_021BE21C(char *p, void *v)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        if (*(void **)(p + i * 4 + 0x814) == 0) {
            *(void **)(p + i * 4 + 0x814) = v;
            return;
        }
    }
}


/*
 * Clears the first slot of the table at +0x814 that holds v.
 */
void func_021BE244(char *p, void *v)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        if (*(void **)(p + i * 4 + 0x814) == v) {
            *(void **)(p + i * 4 + 0x814) = 0;
            return;
        }
    }
}

void func_021BE26C(char *p) {
 int i;
 func_021B9670(p+0x274);
 for (i=0;i<33;i++) {
  *(int *)((unsigned int)p+(unsigned int)i*4+0x814)=0;
  func_021C203C(p,i+1);
 }
 func_02082BCC(p+0x50,0,32);
}


void *func_021BE2A8(char *p, int key)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        if (*(u32_021BE2A8 *)(p + i * 4 + 0x814) != 0 &&
            func_021B9A50(*(char **)(p + i * 4 + 0x814)) == key) {
            return *(void **)(p + 0x814 + i * 4);
        }
    }
    return 0;
}
