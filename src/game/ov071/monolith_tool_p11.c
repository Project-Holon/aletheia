/*
 * file:     monolith_tool_p11.c
 * unit:     yes
 * function: func_021B81A0, func_021B8270, func_021B82A4, func_021B82E4, func_021B82F0, func_021B82FC, func_021B8308, func_021B833C, func_021B8350
 * address:  0x021B81A0
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B6C54  0x021B6C54  thumb  ov071
 *   func_021B6A0C  0x021B6A0C  thumb  ov071
 *   func_020355C4  0x020355C4  arm
 *   func_021B6B98  0x021B6B98  thumb  ov071
 *   d_021BA978     0x021BA978  data  a4
 *   d_021BA9A4     0x021BA9A4  data  a4
 *   func_021B6B38 0x021B6B38 thumb ov071
 *   func_021B6C7C  0x021B6C7C  thumb  ov071
 *   func_021B6B70  0x021B6B70  thumb  ov071
 *   func_021B7070  0x021B7070  thumb  ov071
 *   func_021B70B8  0x021B70B8  thumb  ov071
 *   func_021B70C4  0x021B70C4  thumb  ov071
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02041300 0x02041300 arm
 *   func_02040588 0x02040588 arm
 *   d_021BA984 0x021BA984 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_0201F554  0x0201F554  thumb
 *   func_0201F548  0x0201F548  thumb
 *   func_020215EC  0x020215EC  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 */
#include "../../matched/include/Obj20722.h"
#include "../../matched/include/Obj04337.h"

struct BgTemplate;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct PalAnmSlot;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef struct {
    char pad[0x3c];
    int f3c;
} W;

typedef unsigned short u16;

extern void func_021B6C54(char *p);
extern void func_021B6A0C(int a, void *b, int c, int d, int e, int f, int g, int h);
extern u8 func_020355C4(void);
extern void func_021B6B98(void *p, int *tbl, int n, int sel, int c);
extern void func_021B6B38(void **p);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(unsigned);
void func_021B81A0(int *a, u8 *p);
void func_021B8270(unsigned char *p);
void func_021B82A4(int *a, char *p);
void func_021B82E4(void *p, int a);
void func_021B82F0(void *p);
void func_021B82FC(void *p);
void func_021B8308(void);
void func_021B833C(void);
void func_021B8350(W *w, int *b);
extern unsigned d_021BA978[];
extern int d_021BA9A4[][3];
extern const char d_021BA984[];


void func_021B81A0(int *a, u8 *p)
{
    unsigned i;
    unsigned k;

    func_021B6C54((char *)a);
    for (i = 0; i < d_021BA978[p[0x32]]; i++) {
        k = p[0x32];
        if (k == 1) {
            func_021B6A0C(a[1], p + i * 16, 1, 1, 0x80, d_021BA9A4[k][i], i + 1, 0);
        } else if (k == 0) {
            func_021B6A0C(a[1], p + i * 16, 1, 1, 0x80, d_021BA9A4[k][i], i + 2, 0);
        } else if (k == 2) {
            func_021B6A0C(a[1], p + i * 16, 1, 1, 0x80, d_021BA9A4[k][i], i == 0 ? 1 : 3, 0);
        }
    }
    if (func_020355C4() == 0) {
        func_021B6B98(a, (int *)p, d_021BA978[p[0x32]], 0, 3);
        p[0x33] = 0;
    } else {
        p[0x33] = 1;
    }
}

void func_021B8270(unsigned char *p) { unsigned i; for(i=0;i<d_021BA978[p[0x32]];i++) func_021B6B38((void **)(p+i*16)); }

void func_021B82A4(int *a, char *p)
{
    void func_021B6C7C(int *p, int idx);
    int func_021B6B70(void **p, u8 *q);
    unsigned i;

    func_021B6C7C(a, 3);
    for (i = 0; i < d_021BA978[((struct Obj20722 *)p)->f32]; i++) {
        func_021B6B70((void **)a[1], (u8 *)(p + i * 16));
    }
}


/*
 * Tail call to func_021B7070(word at 0x4, a + 0x34).
 */
void func_021B82E4(void *p, int a)
{
    void func_021B7070(int *p, int *out);
    func_021B7070(((struct Obj04337 *)p)->f4, (int *)(a + 0x34));
}

void func_021B82F0(void *p)
{
    void func_021B70B8(void **p);
    func_021B70B8((void **)((char *)p + 0x34));
}

void func_021B82FC(void *p)
{
    void func_021B70C4(void *);
    func_021B70C4((char *)p + 0x34);
}

void func_021B8308(void) { func_0203FCA0(5,(const struct BgTemplate *)d_021BA984,0); func_02041300(5,0,0,0,0x20,0x20,0x11); func_02040588(5,0); }

void func_021B833C(void) { func_02040588(5, 0); func_020403F4(5); }

void func_021B8350(W *w, int *b)
{
    extern void func_0201F554(u32 a, u32 b, u32 c, u32 d);
    extern u8 func_0201F548(int i);
    extern void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
    extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
    extern void *func_02045770(struct Descriptor *p);
    extern void func_02043B5C(struct CharBuf *buf, u8 value);
    extern void func_02045374(struct Cfg *cfg);
    extern void func_0201F73C(void *a0, int a1, int a2, int a3);

    func_0201F554(5, 1, 0, 0x61);
    func_020215EC((struct PalAnmSlot *)(*b), 5, func_0201F548(0), 0x61, 1, 0x20, 0xb0, 0);
    w->f3c = func_020450F0(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)w->f3c)), 0xff);
    func_02045374((struct Cfg *)w->f3c);
    func_0201F73C((void *)w->f3c, 0, 1, 0xb);
}
