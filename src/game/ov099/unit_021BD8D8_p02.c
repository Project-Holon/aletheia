/*
 * file:     unit_021BD8D8_p02.c
 * unit:     yes
 * function: func_021BDB08, func_021BDB30, func_021BDC0C, func_021BDC44, func_021BDCD0, func_021BDCE0, func_021BDCF4, func_021BDD0C
 * address:  0x021BDB08
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
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BC104 0x021BC104 thumb ov099
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BCBBC 0x021BCBBC thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_0203D798 0x0203D798 arm
 *   func_0203D1E8 0x0203D1E8 arm
 *   func_0203D378 0x0203D378 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020362DC 0x020362DC arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BCBD8 0x021BCBD8 thumb ov099
 *   func_021BDDF4 0x021BDDF4 thumb ov099
 *   d_021C390C 0x021C390C data ov099 a4
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021C23D8 0x021C23D8 thumb ov099
 *   func_0201283C  0x0201283C  thumb
 *   func_02009860  0x02009860  thumb
 *   func_020099C8  0x020099C8  thumb
 *   func_02009C24  0x02009C24  thumb
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_0203D844  0x0203D844  arm
 *   func_02085D3C  0x02085D3C  arm
 *   d_021C3B9C     0x021C3B9C  data
 */
#include "../../matched/include/Obj18246.h"
#include "../../matched/include/Obj02155.h"
#include "../../matched/include/Obj13697.h"
#include "../../matched/include/Obj07953.h"
#include "../../matched/include/Obj18249.h"
#include "../../matched/include/Obj18250.h"
#include "../../matched/include/Obj18251.h"

struct Entry;
struct Link;
struct BigObj;
struct Sub020097BCObj;
struct Sub020097BCFriend;
struct Req;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BDB08;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned int u32_021BDB30;

typedef unsigned int u32_021BDC0C;

typedef struct { int v[8]; } Table;

typedef unsigned int   u32_021BDC44;

typedef unsigned long  u32_021BDCD0;

typedef unsigned long  u32_021BDCE0;

typedef unsigned long  u32_021BDCF4;

typedef struct {
    char pad[0x48];
    int f48;                /* 0x48 */
} Snd;

typedef unsigned int   u32_021BDD0C;

extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
extern int func_021BDD54(char *, void *);
extern void func_021BC104(char *);
extern void func_021C24A4(void *, int);
extern void func_021BAADC(char *, int, int);
extern int func_021BCB70(void *rules, const struct BigObj *obj, u32_021BDB30 *mask);
extern int func_021BCBBC(int, int, int *);
extern void func_021BAAB8(char *, int, int);
extern void *func_0203D798(void);
extern void func_0203D1E8(u32_021BDB30, void *);
extern u32_021BDB30 func_0203D378(void);
extern void func_02039C68(struct Link *p, u32_021BDB30 lo, u32_021BDB30 hi);
extern int func_021BA928(void *);
extern u32_021BDC0C func_020362DC(void);
extern void func_021BA8EC(char *);
extern u32_021BDC44 func_021BCBD8(char *p, int m);
extern int func_021BDDF4(char *);
extern void func_021C18C8(char *p, int kind, int value);
extern int func_021C23C8(void *a, void *b);
extern void func_021C23D8(char *, int);
extern u32_021BDCD0 func_0201283C(const struct BigObj *p);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *obj, int i);
extern void func_02009C24(struct Sub020097BCObj *obj, int src, int dest);
extern int func_02085D3C(void);
extern void func_0203CBAC(struct Req *req, u32_021BDD0C a2, u32_021BDD0C a3);
extern void func_0203D844(void *dst);
int func_021BDB08(char *p, int v);
int func_021BDB30(char *p, int v);
int func_021BDC0C(char *p, int v);
int func_021BDC44(char *p, int v);
void func_021BDCD0(char *p);
void func_021BDCE0(char *p);
void func_021BDCF4(int a, int b, char *p);
void func_021BDD0C(void *p, int on);
extern const Table d_021C390C;
extern Snd d_021C3B9C;


int func_021BDB08(char *p, int v)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x18, 0xA) == 0) {
        return v;
    }

    ((struct Obj18246 *)p)->f1CC = 0x79;
    return v;
}

int func_021BDB30(char *p, int v)
{
    u16 state;
    int out;
    state = (u16)func_021BDD54(p, ((struct Obj02155 *)p)->f8);
    switch (state) {
    case 4:
        func_0203D798();
        func_021BC104(p);
        func_021C24A4(p, 0);
        func_021BAADC(p, 0x7b, 0);
        ((struct Obj02155 *)p)->f1355 = 0;
        ((struct Obj02155 *)p)->f1CC = 0x10;
        return v;
    case 5:
        ((struct Obj02155 *)p)->f1D0 = state;
        return 2;
    case 6:
        func_021BC104(p);
        ((struct Obj02155 *)p)->f1D0 = state;
        return 2;
    default:
        func_0203D1E8((u32_021BDB30)func_020399A8(), 0);
        if (func_0203D378()) {
            if (func_021BCB70((void *)(((struct Obj02155 *)p)->f1348), (const struct BigObj *)(((struct Obj02155 *)p)->fC4), (u32_021BDB30 *)(&out)) &&
                func_021BCBBC(((struct Obj02155 *)p)->f1348, ((struct Obj02155 *)p)->fCC, &out)) {
                func_021BAAB8(p, 0x68, 0);
                ((struct Obj02155 *)p)->f1CC = 0x74;
                return v;
            }
            ((struct Obj02155 *)p)->f1CC = 0x5b;
        } else {
            func_02039C68((void *)func_020399A8(), 0x1b, 0xa);
            ((struct Obj02155 *)p)->f1CC = 0x49;
        }
        return v;
    }
}

int func_021BDC0C(char *p, int v)
{
    if (func_021BA928(p) == 0) return v;
    if (func_020362DC() != 0) {
        func_021BA8EC(p);
        ((struct Obj13697 *)p)->f1353 = 0x4a;
        ((struct Obj13697 *)p)->f1CC = 0x8a;
    }
    return v;
}

int func_021BDC44(char *p, int v)
{
    Table t;
    func_021BCBD8(p, 1);
    if (func_021BDDF4(p) == 0) {
        func_021BAAB8(p, 0x68, 0);
        ((struct Obj07953 *)p)->f1CC = 0x63;
        return v;
    }
    t = d_021C390C;
    func_021C18C8(p, 2, (u16)t.v[((struct Obj07953 *)p)->f134E + ((struct Obj07953 *)p)->f134C * 2]);
    func_021C23C8(p, (void *)(-1));
    ((struct Obj07953 *)p)->f1CC = 0x9e;
    func_021C23D8(p, 1);
    return v;
}


/*
 * Hands the handle at +0xC4 to one arm9 accessor and its result to another.
 */
void func_021BDCD0(char *p)
{
    func_02009860((struct Sub020097BCObj *)func_0201283C(((struct Obj18249 *)p)->fC4));
}


/*
 * Two arm9 calls: the pointer at +0xC4 goes through the first and the answer into the second with a zero selector.
 */
void func_021BDCE0(char *p)
{
    func_020099C8((struct Sub020097BCObj *)func_0201283C(((struct Obj18250 *)p)->fC4), 0);
}


/*
 * Same handle at +0xC4 of the third argument, its accessor result forwarded
 * together with the first two arguments.
 */
void func_021BDCF4(int a, int b, char *p)
{
    func_02009C24((struct Sub020097BCObj *)func_0201283C(((struct Obj18251 *)p)->fC4), a, b);
}


void func_021BDD0C(void *p, int on)
{
    if (func_02085D3C())
        d_021C3B9C.f48 = 0x79000;
    else
        d_021C3B9C.f48 = 0x5e400;
    if (on)
        func_0203CBAC((struct Req *)(&d_021C3B9C), 0, (u32_021BDD0C)p);
    else
        func_0203D844(&d_021C3B9C);
}
