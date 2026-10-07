/*
 * file:     ctvt_comm_p04.c
 * unit:     yes
 * function: func_021B7BA8, func_021B7DCC, func_021B7E34, func_021B8050, func_021B8084, func_021B80CC
 * address:  0x021B7BA8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021B8614 0x021B8614 thumb ov172
 *   func_021BE0D8 0x021BE0D8 thumb ov172
 *   func_0203D7C8 0x0203D7C8 arm
 *   func_021C1A80 0x021C1A80 arm ov172
 *   func_021BE004 0x021BE004 thumb ov172
 *   func_02012944 0x02012944 thumb
 *   func_02008494 0x02008494 thumb
 *   func_021BE100 0x021BE100 thumb ov172
 *   func_0203E5F8 0x0203E5F8 arm
 *   d_021C71F4 0x021C71F4 data a4
 *   func_0203E6C0 0x0203E6C0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203D7FC 0x0203D7FC arm
 *   func_021BE00C 0x021BE00C thumb ov172
 *   func_0203D644 0x0203D644 arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D010 0x0203D010 arm
 *   func_0203D01C 0x0203D01C arm
 *   func_02179328 0x02179328 thumb ov014
 *   func_021B8130 0x021B8130 thumb ov172
 *   func_0203CFF0 0x0203CFF0 arm
 *   func_02039ACC 0x02039ACC arm
 *   func_020399A8 0x020399A8 arm
 *   func_020399B8 0x020399B8 arm
 *   func_0203A574 0x0203A574 arm
 *   d_021C6ED4 0x021C6ED4 data a4
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021B8154 0x021B8154 thumb ov172
 *   func_021B8448 0x021B8448 thumb ov172
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203CDBC 0x0203CDBC arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_0203D7BC  0x0203D7BC  arm
 */
#include "../../matched/include/Obj00386.h"
#include "../../matched/include/Obj06559.h"
#include "../../matched/include/Obj00289.h"
#include "../../matched/include/Obj03853.h"
#include "../../matched/include/Obj24075.h"

struct Entry;
struct Link;
struct Req;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Flags;

typedef signed int     s32;

typedef struct {
    u32 w[0x1c];
} Blob;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021B8614(int unused, int unused2, void *p);
extern int func_021BE0D8(void *p);
extern void *func_0203D7C8(u32 heap, u32 size, const char *file, u16 line);
extern unsigned long func_021C1A80(unsigned long width, unsigned long height, unsigned long sampling, unsigned long option);
extern u32 func_021BE004(void *p);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *src, void *dst);
extern int func_021BE100(void);
extern void func_0203E5F8(int a0, int a1);
extern void func_0203E6C0(void);
extern u32 func_020307B0(void *p);
extern void func_0203D7FC(void *);
extern u16 func_021BE00C(u16 *p);
extern void func_0203D644(int a);
extern int func_0203CD98(void);
extern void func_0203D010(void);
extern void func_0203D01C(void);
extern void func_02179328(void *v);
extern int func_021B8130(void *a0, u8 *a1);
extern void func_0203CFF0(void *p);
extern int func_02039ACC(void);
extern struct Entry *func_020399A8(void);
extern u32 func_020399B8(u8 *p);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern void func_02039C68(struct Link *p, u32 a, u32 b);
extern u32 func_02039CB4(struct Link *p, u32 a, u32 b);
extern void func_021B8154(void *p, char *q);
extern void func_021B8448(void *p, char *q);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
extern void func_0203A5E4(u32 key);
extern u32 func_0200FB24(void);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_0203D7BC(u8 a0);
char *func_021B7BA8(void *p, u16 heap);
void func_021B7DCC(void *p, char *q);
void func_021B7E34(void *p, char *q);
void func_021B8050(void *a, void *b);
void func_021B8084(void *a, char *q);
u32 func_021B80CC(int unused, char *p);
extern const char d_021C71F4[];
extern u8 d_021C6ED4[];

char *func_021B7BA8(void *p, u16 heap)
{
    char *q;
    u8 i;
    u8 j;
    q = func_02030734(heap, 0x3e0, 1, d_021C71F4, 0xf4);
    ((struct Obj00386 *)q)->f3DC = p;
    ((struct Obj00386 *)q)->f8 = 0;
    ((struct Obj00386 *)q)->f4 = 1;
    ((struct Obj00386 *)q)->f183 = 0;
    ((struct Obj00386 *)q)->f174 = 0;
    ((struct Obj00386 *)q)->f178 = 0;
    ((struct Obj00386 *)q)->f3D0 = 0;
    for (i = 0; i < 4; i++)
        func_021B8614((int)p, (int)q, q + 0x64 + i * 0x40);
    for (i = 0; i < 3; i++) {
        if (func_021BE0D8(p) == 0 || i == 0)
            *(void **)(q + 0x164 + i * 4) = func_0203D7C8(heap, 3 << 14, d_021C71F4, 0x107);
    }
    ((struct Obj00386 *)q)->f188 = func_0203D7C8(heap, func_021C1A80(0x80, 0xc0, 1, 4), d_021C71F4, 0x10c);
    ((struct Obj00386 *)q)->f18C = func_0203D7C8(heap, 0xc000, d_021C71F4, 0x10e);
    ((struct Obj00386 *)q)->f190 = func_0203D7C8(heap, 0xc000, d_021C71F4, 0x10f);
    ((struct Obj00386 *)q)->f170 = 0;
    ((struct Obj00386 *)q)->f182 = 0;
    ((struct Obj00386 *)q)->f184 = 0;
    ((struct Obj00386 *)q)->f194 = 0;
    ((struct Obj00386 *)q)->f198 = 0;
    ((struct Obj00386 *)q)->f1A4 = func_02030734(heap, 0x208, 1, d_021C71F4, 0x116);
    ((struct Obj00386 *)q)->f1A8 = func_02030734(heap, 0xc800, 1, d_021C71F4, 0x117);
    ((struct Obj00386 *)q)->f1AC = 0;
    ((struct Obj00386 *)q)->f1AD = 0;
    ((struct Obj00386 *)q)->f3AE = 0xff;
    ((struct Obj00386 *)q)->f3B0 = 0;
    ((struct Obj00386 *)q)->f3B4 = 0;
    ((struct Obj00386 *)q)->f3B8 = 0;
    ((struct Obj00386 *)q)->f3BC = 0;
    ((struct Obj00386 *)q)->f3D4 = 0;
    ((struct Obj00386 *)q)->f3C0 = 1;
    ((struct Obj00386 *)q)->f3C4 = 0;
    ((struct Obj00386 *)q)->f3C8 = 1;
    ((struct Obj00386 *)q)->f3CC = 0;
    ((struct Obj00386 *)q)->f3D8 = 0xff;
    func_02008494(func_02012944((void *)(*((u32 *)func_021BE004(p)))), q + 0xc);
    ((struct Obj00386 *)q)->f2C = 1;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 6; j++)
            *(u8 *)(q + i * 6 + j + 0x2e) = 0xff;
    ((Flags *)(q + 0x2d))->b0 = func_021BE100();
    ((Flags *)(q + 0x2d))->b1 = 0;
    func_02008494(func_02012944((void *)(*((u32 *)func_021BE004(p)))), q + 0x40);
    ((struct Obj00386 *)q)->f60 = func_021BE100();
    ((struct Obj00386 *)q)->f0 = 1;
    func_0203E5F8(heap, 0);
    return q;
}

void func_021B7DCC(void *p, char *q)
{
    u8 i;
    func_0203E6C0();
    func_020307B0(((struct Obj06559 *)q)->f1A8);
    func_020307B0(((struct Obj06559 *)q)->f1A4);
    func_0203D7FC(((struct Obj06559 *)q)->f18C);
    func_0203D7FC(((struct Obj06559 *)q)->f190);
    func_0203D7FC(((struct Obj06559 *)q)->f188);
    for (i = 0; i < 3; i++) {
        if (func_021BE0D8(p) == 0 || i == 0)
            func_0203D7FC(*(void **)(q + i * 4 + 0x164));
    }
    func_020307B0(q);
}

void func_021B7E34(void *p, char *q)
{
    u32 h;
    u8 i;
    u8 j;
    func_021BE00C(p);
    switch (((struct Obj00289 *)q)->f8) {
    case 0:
        if (((struct Obj00289 *)q)->f178 == 0)
            break;
        if (((struct Obj00289 *)q)->f178 == 5) {
            func_0203D644(0);
            ((struct Obj00289 *)q)->f8 = 5;
            ((struct Obj00289 *)q)->f174 = ((struct Obj00289 *)q)->f178;
        } else {
            ((struct Obj00289 *)q)->f8 = 1;
        }
        break;
    case 1:
        func_021B8050(p, q);
        ((struct Obj00289 *)q)->f8 = 2;
        break;
    case 2:
        if (func_0203CD98() != 1)
            break;
        switch (((struct Obj00289 *)q)->f178) {
        case 2:
            func_0203D010();
            ((struct Obj00289 *)q)->f8 = 7;
            break;
        case 3:
            func_0203D01C();
            func_02179328(func_021B8130);
            ((struct Obj00289 *)q)->f8 = 3;
            break;
        case 4:
            if (((struct Obj00289 *)q)->f174 == 2)
                func_021B8614((int)p, (int)q, q + 0x64);
            func_0203CFF0(q + 0x17c);
            ((struct Obj00289 *)q)->f8 = 3;
            break;
        }
        ((struct Obj00289 *)q)->f174 = ((struct Obj00289 *)q)->f178;
        break;
    case 3:
        if (func_02039ACC() == 1)
            ((struct Obj00289 *)q)->f8 = 4;
        if (((struct Obj00289 *)q)->f174 != ((struct Obj00289 *)q)->f178)
            ((struct Obj00289 *)q)->f8 = 8;
        break;
    case 4:
        if (func_020399B8((u8 *)func_020399A8()) == 1)
            ((struct Obj00289 *)q)->f8 = 7;
        if (((struct Obj00289 *)q)->f174 != ((struct Obj00289 *)q)->f178)
            ((struct Obj00289 *)q)->f8 = 8;
        break;
    case 5:
        h = (u32)func_020399A8();
        func_0203A574(0x2000, (u32)d_021C6ED4, 4, (u32)q);
        func_02039C68((struct Link *)h, 8, 0x20);
        ((struct Obj00289 *)q)->f8 = 6;
        break;
    case 6:
        if (func_02039CB4((struct Link *)func_020399A8(), 8, 0x20) == 1)
            ((struct Obj00289 *)q)->f8 = 7;
        break;
    case 7:
        func_021B8154(p, q);
        if (((struct Obj00289 *)q)->f174 != ((struct Obj00289 *)q)->f178)
            ((struct Obj00289 *)q)->f8 = 8;
        if (((struct Obj00289 *)q)->f174 == 2)
            func_021B8448(p, q);
        break;
    case 8:
        func_0203CEAC(0);
        ((struct Obj00289 *)q)->f8 = 11;
        break;
    case 11:
        if (func_0203CDBC() != 1)
            break;
        if (((struct Obj00289 *)q)->f178 == 1)
            ((struct Obj00289 *)q)->f8 = 12;
        else
            ((struct Obj00289 *)q)->f8 = 1;
        break;
    case 9:
        func_02039C68((struct Link *)func_020399A8(), 9, 0x20);
        ((struct Obj00289 *)q)->f8 = 10;
        break;
    case 10:
        if (func_02039CB4((struct Link *)func_020399A8(), 9, 0x20) == 1) {
            func_0203A5E4(0x2000);
            ((struct Obj00289 *)q)->f8 = 12;
        }
        if (func_0200FB24() != 0) {
            func_0203A5E4(0x2000);
            ((struct Obj00289 *)q)->f8 = 12;
        }
        break;
    }
    if (((struct Obj00289 *)q)->f3D0 != 0) {
        (((struct Obj00289 *)q)->f3D0)--;
        if (((struct Obj00289 *)q)->f3D0 == 0) {
            for (i = 0; i < 3; i++)
                for (j = 0; j < 6; j++)
                    *(u8 *)(q + i * 6 + j + 0x2e) = 0xff;
            ((Flags *)(q + 0x2d))->b1 = 0;
        }
    }
}


void func_021B8050(void *a, void *b)
{
    Blob s = *(Blob *)0x021C6EF4;

    func_021BE00C(a);
    func_0203CBAC((struct Req *)(&s), 0, (u32)b);
    func_0203D7BC(0);
}


/*
 * Chooses the +8 state from the +0x174 code and latches +0x178.
 *
 * Addresses are Black-image addresses.
 */
void func_021B8084(void *a, char *q)
{
    if (((struct Obj03853 *)q)->f4 <= 1) {
        if (((struct Obj03853 *)q)->f174 == 5) {
            ((struct Obj03853 *)q)->f8 = 0xc;
            func_0203A5E4(0x2000);
        } else {
            func_0203CEAC(0);
            ((struct Obj03853 *)q)->f8 = 0xb;
        }
    } else {
        if (((struct Obj03853 *)q)->f174 == 5) {
            ((struct Obj03853 *)q)->f8 = 9;
        } else {
            ((struct Obj03853 *)q)->f8 = 8;
        }
    }
    ((struct Obj03853 *)q)->f178 = 1;
}

u32 func_021B80CC(int unused, char *p)
{
    if (((struct Obj24075 *)p)->f8 == 12)
        return 1;
    return 0;
}
