/*
 * file:     unit_021BF050_p15.c
 * unit:     yes
 * function: func_021C1350, func_021C1374, func_021C13D0, func_021C143C, func_021C14A8
 * address:  0x021C1350
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
 *   func_021BCC58  0x021BCC58  thumb  ov099
 *   func_021C1154 0x021C1154 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BCBD8 0x021BCBD8 thumb ov099
 *   func_0203D378 0x0203D378 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 */
#include "../../matched/include/Obj13702.h"
#include "../../matched/include/Obj04417.h"
#include "../../matched/include/Obj06359.h"
#include "../../matched/include/Obj22056.h"

struct Entry;
struct Link;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021C1350;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef struct {
    u16 f0;
    u16 f2;
    u32_021C1350 f4;
} H;

typedef unsigned int   u32_021C1374;

typedef struct { u16 a, b; unsigned c; } Request;

typedef unsigned int   u32_021C13D0;

typedef unsigned int   u32_021C143C;

extern void func_021BCC58(char *p, u32_021C1350 x);
extern int func_021C1154(char *p);
extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern int func_02008468(void);
extern u8 *func_02012944(void *p);
extern int func_0203D3A8(struct Entry *a, u32_021C1374 b, u32_021C1374 c, u32_021C1374 d);
extern void func_021BA8EC(char *);
extern u8 func_021BDD48(char *, void *);
extern int func_021BDD54(char *, void *);
extern unsigned func_021BCBD8(char *, int);
extern u32_021C143C func_0203D378(void);
extern void func_02039C68(struct Link *, unsigned, unsigned);
extern int func_02156A3C(void);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
void func_021C1350(int a, int b, H *h, char *d);
int func_021C1374(char *p, int ret);
int func_021C13D0(char *p, int ret);
int func_021C143C(char *p, int ret);
int func_021C14A8(char *p, int ret);


/*
 * Stamps the record of slot a from the three lead fields of h.
 */
void func_021C1350(int a, int b, H *h, char *d)
{
    *(u16 *)(d + a * 2 + 0x1F4) = h->f0;
    *(u8 *)(*(char **)(d + 0x1F4 + 0x54) + a + 0x44) = h->f2;
    func_021BCC58(d, h->f4);
}

int func_021C1374(char *p, int ret)
{
    int h;
    unsigned count;
    void *q;
    if (func_021C1154(p) == 0) {
        if (func_02039CB4((struct Link *)func_020399A8(), 14, 10) != 0) {
            h = (int)func_020399A8();
            count = func_02008468();
            q = func_02012944(((struct Obj13702 *)p)->fC4);
            if (func_0203D3A8((void *)h, (u16)0xa04, (u16)count, (u32_021C1374)q) != 0) {
                func_021BA8EC(p);
                ((struct Obj13702 *)p)->f1CC = 135;
            }
        }
    }
    return ret;
}

int func_021C13D0(char *p, int ret)
{
    Request request;
    func_021BDD48(p, ((struct Obj04417 *)p)->f8);
    request.a = func_021BDD54(p, ((struct Obj04417 *)p)->f8);
    if (((struct Obj04417 *)p)->f1356 != 0) {
        request.b = ((struct Obj04417 *)p)->f1356 - 1;
        ((struct Obj04417 *)p)->f1356 = 0;
    } else {
        request.b = *((u8 *)((struct Obj04417 *)p)->f248 + 0x46);
    }
    request.c = func_021BCBD8(p, 1);
    if (func_0203D3A8(func_020399A8(), 0xa03, 8, (u32_021C13D0)(&request)) != 0)
        ((struct Obj04417 *)p)->f1CC = 43;
    return ret;
}

/*
 * lever: bind the narrowed callee result before comparing the indexed field.
 */
int func_021C143C(char *p, int ret)
{
    int index = 0;
    u16 value;
    if (func_0203D378() != 0) index = 1;
    if (func_021C1154(p) == 0) {
        if (((u16 *)(p + 0x1f4))[index] != 0) {
            value = func_021BDD54(p, ((struct Obj06359 *)p)->f8);
            if (value == ((u16 *)(p + 0x1f4))[index]) {
                func_02039C68((struct Link *)func_020399A8(), 15, 10);
                ((struct Obj06359 *)p)->f1CC = 44;
            } else {
                func_021BA874(p, func_02156A3C());
                func_021BAAB8(p, 13, 0);
                ((struct Obj06359 *)p)->f1CC = 19;
            }
        }
    }
    return ret;
}

int func_021C14A8(char *p, int ret)
{
    if (func_021C1154(p) == 0) {
        if (func_02039CB4((struct Link *)func_020399A8(), 15, 10) != 0) {
            func_0203D7B0(1);
            func_0203D7BC(1);
            func_02039C68((struct Link *)func_020399A8(), 18, 10);
            ((struct Obj22056 *)p)->f1CC = 45;
        }
    }
    return ret;
}
