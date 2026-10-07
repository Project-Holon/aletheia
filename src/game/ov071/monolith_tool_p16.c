/*
 * file:     monolith_tool_p16.c
 * unit:     yes
 * function: func_021B9750, func_021B9798, func_021B9818, func_021B98B4, func_021B98C4, func_021B992C, func_021B9970, func_021B9A18, func_021B9A40
 * address:  0x021B9750
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
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02045808  0x02045808  arm
 *   func_02034714  0x02034714  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   d_021BABFC     0x021BABFC  data  a4
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02028484 0x02028484 thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_021B6F40  0x021B6F40  thumb  ov071
 *   func_02043678  0x02043678  arm
 *   func_0216FE2C  0x0216FE2C  thumb  ov010
 *   func_020437AC 0x020437AC arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   d_021BAAF8     0x021BAAF8  data  a2
 */
#include "../../matched/include/Obj02123.h"
#include "../../matched/include/Obj13182.h"
#include "../../matched/include/Obj13183.h"
#include "../../matched/include/Obj20750.h"
#include "../../matched/include/Obj00044.h"
#include "../../matched/include/Obj09896.h"
#include "../../matched/include/Obj07704.h"
#include "../../matched/include/Obj20751.h"
#include "../../matched/include/Obj20752.h"
#include "../../matched/include/Obj04340.h"
#include "../../matched/include/Obj20753.h"
#include "../../matched/include/Obj20755.h"
#include "../../matched/include/Obj03664.h"
#include "../../matched/include/Obj09897.h"
#include "../../matched/include/Obj20756.h"

struct Descriptor;
struct MsgBank;
struct U16Vec;
struct PrintSys;
struct Cfg;
struct WordSet;
struct Blk;
struct CharBuf;
struct Rec3;
struct Ctx;
struct Bmp;
struct Pos;
struct Rec;
struct Obj020437AC;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef enum { IDX_FIRST } Idx;

typedef struct {
    u8 pad00[0x24];
    void *obj[50];
    int idx[50];
    int kind[50];
    u8 count;
} List;

typedef signed short s16;

extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0201DD78(u32 a, u32 b, u32 c);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32 a1, u32 a2, void *a3, u32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u16 a10);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g);
extern void func_020409B4(u32 a);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_021B6F40(u8 **p);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern int func_0216FE2C(struct Rec *tbl, int idx, struct Pos *pos, u8 *flags);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
void func_021B9750(char *a, char *b);
void func_021B9798(char *a, char *b, u32 c);
void func_021B9818(char *a, char *b, u32 c);
int func_021B98B4(u8 *a,u8 *b);
void func_021B98C4(char *a);
void func_021B992C(char *a);
void func_021B9970(char **a, List *l, char *c);
void func_021B9A18(char *p);
int func_021B9A40(char *a, char *b);
extern char d_021BABFC[];
extern u16 d_021BAAF8[];


void func_021B9750(char *a, char *b)
{
    void *r6;
    char *r4;
    void *r7;

    r6 = func_02045EC0(((struct Obj20750 *)(*(char * *)&((struct Obj02123 *)a)->f4))->f28, 0x22);
    r4 = *(char * *)&((struct Obj02123 *)a)->f4;
    r7 = ((struct Obj13183 *)r4)->f8;
    func_0201C6FC(r7, (u32)func_02045770(((struct Obj13182 *)b)->f288), 0x18, 4, r6, (u32)(((struct Obj13183 *)r4)->fC));
    ((struct Obj13182 *)b)->f28C = 1;
    func_02045808(r6);
}


void func_021B9798(char *a, char *b, u32 c)
{
    if (((struct Obj00044 *)a)->f294 != 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    func_0201DD78(1, 2, 0xf);
    ((struct Obj00044 *)a)->f290 = func_02045EC0(((struct Obj09896 *)b)->f28, c);
    ((struct Obj00044 *)a)->f294 = func_0201CCE4(((struct Obj00044 *)a)->f280, 0, 0, ((struct Obj00044 *)a)->f290, ((struct Obj09896 *)b)->fC, func_02012FFC(), ((struct Obj09896 *)b)->f18, 0xa, 0x61, 0xf);
    func_02045374(((struct Obj00044 *)a)->f280);
    func_0201F73C(((struct Obj00044 *)a)->f280, 1, 1, 0xb);
}


void func_021B9818(char *a, char *b, u32 c)
{
    void *r6;

    if (((struct Obj00044 *)a)->f294 != 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    func_0201DD78(1, 2, 0xf);
    r6 = func_02045EC0(((struct Obj07704 *)b)->f28, c);
    ((struct Obj00044 *)a)->f290 = func_020457B0(0x100, 0x61);
    func_0201F250(((struct Obj07704 *)b)->f10, ((struct Obj00044 *)a)->f290, r6);
    func_02045808(r6);
    ((struct Obj00044 *)a)->f294 = func_0201CCE4(((struct Obj00044 *)a)->f280, 0, 0, ((struct Obj00044 *)a)->f290, ((struct Obj07704 *)b)->fC, func_02012FFC(), ((struct Obj07704 *)b)->f18, 0xa, 0x61, 0xf);
    func_02045374(((struct Obj00044 *)a)->f280);
    func_0201F73C(((struct Obj00044 *)a)->f280, 1, 1, 0xb);
}

/*
 * leaf: unlabelled tail stub called by func_021B9070; parent confirmed unowned.
 */
int func_021B98B4(u8 *a,u8 *b)
{
    return func_02028484((struct Blk *)(a+0x38),(void *)(((struct Obj20751 *)b)->f294));
}


void func_021B98C4(char *a)
{
    void *r6;

    r6 = func_02045770(((struct Obj00044 *)a)->f280);
    if (((struct Obj00044 *)a)->f294 == 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    func_0201CE48(((struct Obj00044 *)a)->f294);
    ((struct Obj00044 *)a)->f294 = 0;
    func_02045808(((struct Obj00044 *)a)->f290);
    ((struct Obj00044 *)a)->f290 = 0;
    func_0201F7A8(((struct Obj00044 *)a)->f280, 0);
    func_02043B5C(r6, 0xff);
    func_02045334(((struct Obj00044 *)a)->f280);
    func_0201DD78(0xf, 2, 0);
}


void func_021B992C(char *a)
{
    int x;
    int t;

    x = ((struct Obj20752 *)a)->f27C;
    if (x - 2 < 7) {
        t = (x - 1) * 32 / 8;
        func_02041300(6, 0, 0, (u8)t, 0x20, 0x20 - t, 0x11);
        func_020409B4(6);
    }
}


void func_021B9970(char **a, List *l, char *c)
{
    Idx i = 0;
    int n;
    int r;
    void *pos;

    func_020120F4((const struct Ctx *)(**(char ** *)&((struct Obj04340 *)a)->f0));
    pos = func_021B6F40((u8 **)a);
    l->idx[0] = i;
    l->kind[0] = 1;
    l->obj[0] = func_02043678(0x17, 2, 0x20, 0x61);
    n = i + 1;
    for (; i < 0x30; i++) {
        r = func_0216FE2C(((struct Obj20753 *)c)->f34, i, pos, (u8 *)(*a + 0x38));
        if (r != 2) {
            l->idx[n] = i;
            l->kind[n] = r;
            l->obj[n] = func_02043678(0x17, 2, 0x20, 0x61);
            n++;
        }
    }
    l->idx[n] = 0;
    l->kind[n] = 1;
    l->obj[n] = func_02043678(0x17, 2, 0x20, 0x61);
    l->count = n + 1;
}

void func_021B9A18(char *p) { int i; for (i = 0; i < ((struct Obj20755 *)p)->f27C; i++) func_020437AC(*(void **)(p + i * 4 + 0x24)); }


int func_021B9A40(char *a, char *b)
{
    int j;
    int i;
    char *r6;
    void *buf;

    j = 0;
    buf = func_020457B0(0x20, 0x61);
    i = ((struct Obj03664 *)a)->f27D;
    if (i < ((struct Obj03664 *)a)->f27C) {
        do {
            if (i >= 1 && i < ((struct Obj03664 *)a)->f27C - 1) {
                r6 = a + i * 4;
                func_02045CAC((struct MsgBank *)(((struct Obj03664 *)a)->f20), ((struct Obj09897 *)r6)->fEC, buf);
                func_0201C7D0(((struct Obj09897 *)r6)->f24, 0, 0, buf, ((struct Obj20756 *)b)->fC,
                              d_021BAAF8[((struct Obj09897 *)r6)->f1B4]);
            }
            j++;
            if (j >= 3)
                break;
            i++;
        } while (i < ((struct Obj03664 *)a)->f27C);
    }
    func_02045808(buf);
    ((struct Obj03664 *)a)->f27D = i;
    return ((struct Obj03664 *)a)->f27D >= ((struct Obj03664 *)a)->f27C;
}
