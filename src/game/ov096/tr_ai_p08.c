/*
 * file:     tr_ai_p08.c
 * unit:     yes
 * function: func_02188E90, func_02188F14, func_02188F2C, func_02188F58, func_02188FAC, func_02188FBC, func_02188FCC, func_0218905C, func_0218906C, func_0218907C, func_0218908C, func_021890C0, func_021890D0, func_021890E0, func_021890F0, func_02189100, func_02189150, func_02189160, func_02189170
 * address:  0x02188E90
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A308  0x0218A308  thumb  ov096
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B99B8  0x021B99B8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_0218A378 0x0218A378 thumb ov096
 *   func_0218A220 0x0218A220 thumb ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C7DAC  0x021C7DAC  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021EF884 0x021EF884 thumb ov093
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C7E14  0x021C7E14  thumb  ov093
 */
#include "../../matched/include/Obj10179.h"
#include "../../matched/include/Obj13655.h"
#include "../../matched/include/Obj21945.h"
#include "../../matched/include/Obj06342.h"
#include "../../matched/include/Obj21946.h"
#include "../../matched/include/Obj21947.h"
#include "../../matched/include/Obj10180.h"
#include "../../matched/include/Obj13656.h"
#include "../../matched/include/Obj21948.h"
#include "../../matched/include/Obj21949.h"
#include "../../matched/include/Obj21950.h"
#include "../../matched/include/Obj21951.h"
#include "../../matched/include/Obj21952.h"
#include "../../matched/include/Obj21953.h"
#include "../../matched/include/Obj21954.h"
#include "../../matched/include/Obj21955.h"
#include "../../matched/include/Obj21956.h"
#include "../../matched/include/Obj06343.h"

struct Cursor;
struct Q1;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad00[2];
    u16 f2;
    u8 pad04[0x38 - 4];
    int f38;
    u8 pad3C[0xb0 - 0x3c];
    int fb0;
    u8 padB4[4];
    char *fb8;
    u8 padBC[8];
    int fc4;
} Conn;

extern u32 func_0201134C(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A308(void *p, u32 i);
extern u8 func_021B8DE4(char *p, int i);
extern char *func_021B9AF8(char *p, int i);
extern int func_021B99B8(void *pp, unsigned int b);
extern u8 func_021B9B94(struct Q1 *p);
extern int func_021D5B7C(void *);
extern int func_0218A378(int,int,int);
extern int func_0218A220(int,int,int);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern u8 func_021D5440(u8 *p);
extern int func_021C7DAC(u8 *p, int a, int b, int c);
extern int func_021D5B68(void *);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021EF884(void);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_021D59B4(u8 *p, int k);
extern u16 func_021C7E14(u8 *p, int a, int b, u32 c, int e0, int e1);
int func_02188E90(struct Cursor *a, Conn *b);
int func_02188F08(int a, Conn *b);
int func_02188F14(int a, unsigned char *b);
int func_02188F2C(struct Cursor *a,unsigned char *b);
int func_02188F50(int a, unsigned char *b);
int func_02188F58(struct Cursor *a, int b);
int func_02188FAC(struct Cursor *a, unsigned char *b);
int func_02188FBC(struct Cursor *a, unsigned char *b);
void func_02188FCC(struct Cursor *a, int b, int c);
int func_0218905C(int a, unsigned char *b);
int func_0218906C(void *a, unsigned char *b);
int func_0218907C(u8 * a, int b);
void func_0218908C(u8 *a, int b, int c);
int func_021890C0(struct Cursor *a, int b);
int func_021890D0(struct Cursor *a, int b);
int func_021890E0(struct Cursor *a, int b);
int func_021890F0(struct Cursor *a, int b);
int func_02189100(struct Cursor *a, int b, int c);
int func_02189150(struct Cursor *a, int b);
int func_02189160(struct Cursor *a, int b);
int func_02189170(struct Cursor *a, int b, int c);


/*
 * func_02188F08 is the unlabelled store-and-return stub at 0x02188F08
 * (function_starts seed).
 */
int func_02188E90(struct Cursor *a, Conn *b)
{
    int x;
    char *p;
    int n;

    x = func_021B8DE4((char *)b->fb0, func_0218A160((u8 *)b, func_0201134C(a)));
    p = func_021B9AF8(b->fb8, x);
    n = func_021B99B8((void *)b->fb0, x);
    b->f38 = 0;
    for (; n < func_021B9B94((struct Q1 *)p); n++) {
        if (func_021D5B7C(func_0218A308(p, (u8)n)) != 0)
            b->f38++;
    }
    return b->fc4;
}


int func_02188F08(int a, Conn *b)
{
    b->f38 = b->f2;
    return b->fc4;
}

int func_02188F14(int a, unsigned char *b) { ((struct Obj10179 *)b)->f38=func_0218A378((int)b,((struct Obj10179 *)b)->f2,28); return ((struct Obj10179 *)b)->fC4; }

int func_02188F2C(struct Cursor *a,unsigned char *b) { int k; k=func_0201134C(a); ((struct Obj13655 *)b)->f38=func_0218A220((int)b,k,func_0218A160(b,k)); return ((struct Obj13655 *)b)->fC4; }

int func_02188F50(int a, unsigned char *b) { return ((struct Obj21945 *)b)->fC4; }


int func_02188F58(struct Cursor *a, int b)
{
    int t0;
    int t1;
    int y;
    int z;
    int r;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    y = func_021D5440(*(u8 * *)&((struct Obj06342 *)b)->fBC);
    z = func_021D5440(*(u8 * *)&((struct Obj06342 *)b)->fC0);
    r = func_021C7DAC((u8 *)(((struct Obj06342 *)b)->fB4), y, z, ((struct Obj06342 *)b)->f2);
    func_0218A0F4((u8 *)a, 2, r, t0, t1);
    return ((struct Obj06342 *)b)->fC4;
}

int func_02188FAC(struct Cursor *a, unsigned char *b) { func_02188FCC(a,(int)b,2); return ((struct Obj21946 *)b)->fC4; }

int func_02188FBC(struct Cursor *a, unsigned char *b) { func_02188FCC(a,(int)b,3); return ((struct Obj21947 *)b)->fC4; }


void func_02188FCC(struct Cursor *a, int b, int c)
{
    int t0;
    int t1;
    int n;
    char *handle;
    int i;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    n = func_021B8DE4((char *)(((struct Obj10180 *)b)->fB0), func_0218A160((u8 *)b, t0));
    handle = func_021B9AF8(*(char * *)&((struct Obj10180 *)b)->fB8, n);
    for (i = func_021B99B8((void *)(((struct Obj10180 *)b)->fB0), n);
         i < func_021B9B94((struct Q1 *)handle); i++) {
        u8 *t = func_0218A308(handle, (unsigned char)i);

        if (func_021D5B68(t) == 0) {
            if (func_0218A0F4((u8 *)a, c, func_021D62A8((struct Unk021D62A8 *)t), 0, t1) != 0)
                break;
        }
    }
}

int func_0218905C(int a, unsigned char *b) { ((struct Obj13656 *)b)->f38=func_021EF884(); return ((struct Obj13656 *)b)->fC4; }

int func_0218906C(void *a, unsigned char *b) { func_0218908C(a,(int)b,2); return ((struct Obj21948 *)b)->fC4; }

int func_0218907C(u8 * a, int b)
{
    func_0218908C(a, b, 3);
    return ((struct Obj21949 *)b)->fC4;
}

/*
 * return: func_0218A378's r0 is consumed by original caller, overriding its void forwarder declaration.
 */
void func_0218908C(u8 *a, int b, int c)
{
    int t0, t1;
    t0 = func_0201134C((struct Cursor *)a);
    t1 = func_0201134C((struct Cursor *)a);
    func_0218A0F4(a, c, func_0218A378(b, ((struct Obj21950 *)b)->f2, 28), t0, t1);
}

int func_021890C0(struct Cursor *a, int b)
{
    func_02189100(a, b, 0);
    return ((struct Obj21951 *)b)->fC4;
}

int func_021890D0(struct Cursor *a, int b)
{
    func_02189100(a, b, 1);
    return ((struct Obj21952 *)b)->fC4;
}

int func_021890E0(struct Cursor *a, int b)
{
    func_02189100(a, b, 2);
    return ((struct Obj21953 *)b)->fC4;
}

int func_021890F0(struct Cursor *a, int b)
{
    func_02189100(a, b, 3);
    return ((struct Obj21954 *)b)->fC4;
}


int func_02189100(struct Cursor *a, int b, int c)
{
    int t0;
    int t1;
    int t2;
    int t3;
    int r;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    r = func_021D59B4(func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, t0)), t1);
    return func_0218A0F4((u8 *)a, c, r, t2, t3);
}

int func_02189150(struct Cursor *a, int b)
{
    func_02189170(a, b, 6);
    return ((struct Obj21955 *)b)->fC4;
}

int func_02189160(struct Cursor *a, int b)
{
    func_02189170(a, b, 1);
    return ((struct Obj21956 *)b)->fC4;
}


int func_02189170(struct Cursor *a, int b, int c)
{
    int t;
    int w;
    int y;
    int z;
    int r;

    func_0201134C(a);
    t = func_0201134C(a);
    w = func_021D59B4(*(u8 * *)&((struct Obj06343 *)b)->fC0, 0xd);
    y = func_021D5440(*(u8 * *)&((struct Obj06343 *)b)->fBC);
    z = func_021D5440(*(u8 * *)&((struct Obj06343 *)b)->fC0);
    r = func_021C7E14((u8 *)(((struct Obj06343 *)b)->fB4), y, z, ((struct Obj06343 *)b)->f2, 1, 0);
    return func_0218A0F4((u8 *)a, c, w, r, t);
}
