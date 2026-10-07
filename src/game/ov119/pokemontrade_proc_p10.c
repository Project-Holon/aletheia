/*
 * file:     pokemontrade_proc_p10.c
 * unit:     yes
 * function: func_021D9548, func_021D95A0, func_021D95D0, func_021D95F0, func_021D9610, func_021D9670, func_021D9750, func_021D9780, func_021D9810, func_021D98AC, func_021D99F4, func_021D9A50, func_021D9AD8, func_021D9B34, func_021D9B84, func_021D9BC4, func_021D9C00, func_021D9CFC, func_021D9D60, func_021D9DC4, func_021D9E0C, func_021D9E54, func_021D9EA8, func_021D9EBC, func_021D9F24, func_021DA064, func_021DA0CC, func_021DA110, func_021DA158, func_021DA1B4, func_021DA1DC, func_021DA254, func_021DA27C, func_021DA2F4, func_021DA318, func_021DA640, func_021DA700, func_021DA76C, func_021DA798, func_021DA898, func_021DA8F8, func_021DA9F0, func_021DAA18, func_021DAA4C, func_021DAA7C, func_021DAAE4, func_021DAB0C, func_021DAB34, func_021DABB0, func_021DABE8, func_021DAC20, func_021DAC60, func_021DACE4, func_021DAD84, func_021DADAC, func_021DAE2C, func_021DAEC8, func_021DAEF0
 * address:  0x021D9548
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 *   func_0202F738 0x0202F738 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_021D8F20 0x021D8F20 thumb ov119
 *   func_0202136C 0x0202136C thumb
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D94D4 0x021D94D4 thumb ov119
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_0204B404 0x0204B404 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021E5B6C 0x021E5B6C thumb ov119
 *   func_021E219C 0x021E219C thumb ov119
 *   d_021E7580 0x021E7580 data a2
 *   d_021E757C 0x021E757C data a2
 *   func_020221A4 0x020221A4 thumb
 *   func_02040588 0x02040588 arm
 *   func_021E1CE8 0x021E1CE8 thumb ov119
 *   func_021E3E80 0x021E3E80 thumb ov119
 *   func_021E3208 0x021E3208 thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   func_021D9468 0x021D9468 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 *   func_0202208C 0x0202208C thumb
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035C08 0x02035C08 arm
 *   d_021E75F0 0x021E75F0 data a4
 *   func_020061E4 0x020061E4 thumb
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021E1D68 0x021E1D68 thumb ov119
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021E1410 0x021E1410 thumb ov119
 *   func_02043534 0x02043534 arm
 *   func_021B6558 0x021B6558 thumb ov067
 *   d_021E75E4 0x021E75E4 data
 *   func_02039CB4 0x02039CB4 arm
 *   func_021D9434 0x021D9434 thumb ov119
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021DD24C 0x021DD24C thumb ov119
 *   func_021DD294 0x021DD294 thumb ov119
 *   func_021DBA80 0x021DBA80 thumb ov119
 *   func_021DB0A0 0x021DB0A0 thumb ov119
 *   func_0207D658 0x0207D658 arm
 *   d_021E7584 0x021E7584 data a4
 *   func_021D8C6C 0x021D8C6C thumb ov119
 *   func_02035D20 0x02035D20 arm
 *   func_021E51A4 0x021E51A4 thumb ov119
 *   func_021DBD70 0x021DBD70 thumb ov119
 *   func_021DB9B4 0x021DB9B4 thumb ov119
 *   func_021DF708 0x021DF708 thumb ov119
 *   func_021D8C84 0x021D8C84 thumb ov119
 *   func_021DD0CC 0x021DD0CC thumb ov119
 *   func_021E0FF4 0x021E0FF4 thumb ov119
 *   func_021D8CCC 0x021D8CCC thumb ov119
 *   func_02035C60 0x02035C60 arm
 *   func_021DBE70 0x021DBE70 thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021D8D4C 0x021D8D4C thumb ov119
 *   func_021E2484 0x021E2484 thumb ov119
 *   func_021E1E00 0x021E1E00 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   func_021DD5B4 0x021DD5B4 thumb ov119
 *   func_021DBBD0 0x021DBBD0 thumb ov119
 *   func_021DD3D4 0x021DD3D4 thumb ov119
 *   func_021DF5D8 0x021DF5D8 thumb ov119
 *   func_02035CB8 0x02035CB8 arm
 *   func_02027A20 0x02027A20 thumb
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_02027A08 0x02027A08 thumb
 *   func_021D8C0C 0x021D8C0C thumb ov119
 *   func_02035C38 0x02035C38 arm
 *   func_021D8B54 0x021D8B54 thumb ov119
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_021DD2A8 0x021DD2A8 thumb ov119
 *   func_021DBB6C 0x021DBB6C thumb ov119
 *   func_021E5EF8 0x021E5EF8 thumb ov119
 *   func_021E4174 0x021E4174 thumb ov119
 *   d_021E7594 0x021E7594 data a4
 *   func_021D4B88 0x021D4B88 thumb ov117
 *   func_021D6F2C 0x021D6F2C thumb ov118
 *   func_021DBAF8 0x021DBAF8 thumb ov119
 *   func_021DC370 0x021DC370 thumb ov119
 *   func_020435F4 0x020435F4 arm
 *   func_021DD1B8 0x021DD1B8 thumb ov119
 *   func_021DF904 0x021DF904 thumb ov119
 *   func_0215642C 0x0215642C thumb ov009
 *   func_021DD528 0x021DD528 thumb ov119
 *   func_021DD68C 0x021DD68C thumb ov119
 *   func_021DF78C 0x021DF78C thumb ov119
 *   func_02082BCC 0x02082BCC arm
 *   func_02027858 0x02027858 thumb
 *   func_021E4420 0x021E4420 thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021DB7AC 0x021DB7AC thumb ov119
 *   func_021E31FC 0x021E31FC thumb ov119
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_021DC62C 0x021DC62C thumb ov119
 *   func_021E3E00 0x021E3E00 thumb ov119
 *   func_021D89A8 0x021D89A8 thumb ov119
 *   func_021E5098 0x021E5098 thumb ov119
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02022230 0x02022230 thumb
 *   func_02039338 0x02039338 arm
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_020173EC 0x020173EC thumb
 */
#include "../../matched/include/Obj04475.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj05326.h"
#include "../../matched/include/Obj01727.h"
#include "../../matched/include/Obj03775.h"
#include "../../matched/include/Obj05327.h"
#include "../../matched/include/Obj22726.h"
#include "../../matched/include/Obj03772.h"
#include "../../matched/include/Obj22727.h"
#include "../../matched/include/Obj13890.h"
#include "../../matched/include/Obj04474.h"
#include "../../matched/include/Obj08052.h"
#include "../../matched/include/Obj08053.h"
#include "../../matched/include/Obj08054.h"
#include "../../matched/include/Obj02826.h"
#include "../../matched/include/Obj08055.h"
#include "../../matched/include/Obj03773.h"
#include "../../matched/include/Obj22730.h"
#include "../../matched/include/Obj13891.h"
#include "../../matched/include/Obj13892.h"
#include "../../matched/include/Obj04476.h"
#include "../../matched/include/Obj22731.h"
#include "../../matched/include/Obj06423.h"
#include "../../matched/include/Obj04477.h"
#include "../../matched/include/Obj10354.h"

#define I(o) (*(int *)(p+(o)))
#define P(o) (*(void **)(p+(o)))
struct Entry;
struct Link;
struct MsgBank;
struct Obj;
struct Vec2;
struct S;
struct TaskMenu;
struct WordSet;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct Pt { u16 x; u16 y; } Pt;

typedef struct {int a,b,c;} Triple;

typedef struct { int a,b; } Pair;

extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_0202F738(void *p, int a1);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern int func_021D8AA8(void *p);
extern void *func_021D8FA4(void *p, int i);
extern int func_021D8F20(void *,int);
extern u32 func_0202136C(u16 v);
extern int func_021D8A24(void *p);
extern void func_021D8E84(void *p, int v);
extern int func_021D94D4(char *p);
extern int func_021E12AC(char *p);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021E5B6C(int p, int b, int c);
extern void func_021E219C(char *p, void *mon, int side, int flag);
extern u32 func_020221A4(void);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021E1CE8(void *,int);
extern void func_021E3E80(char *p);
extern void func_021E3208(void *,int);
extern void func_02041B6C(u32 bit);
extern void func_021D9468(void *,int,void *);
extern void func_021D8B38(char *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int func_02035C08(const void *);
extern int func_021B6448(u8 *);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 a);
extern void func_021B63D0(struct S *p);
extern void func_021E1D68(char *p, void *a);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021E12F8(char *p);
extern void func_021E1098(char *p);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021E1410(void *p, int *ids, int count);
extern void func_02043534(u32 planes);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern void func_021D9434(void *);
extern u32 func_0203D1A4(struct Link *p);
extern int func_021DD24C(char *p);
extern void func_021DD294(char *p, int a, int b);
extern void func_021DBA80(char *p);
extern int func_021DB0A0(char *p);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_021D8C6C(void *);
extern unsigned int func_02035D20(unsigned int *outA, unsigned int *outB);
extern int func_021E51A4(char *p, int x, int y, int *outA, int *outB, int *outSlot, int *outColumn, int *outRow);
extern int func_021DBD70(char *,int,int);
extern int func_021DD0CC(char *,int);
extern void func_021DB9B4(char *p);
extern void func_021DF708(void *p);
extern void func_021D8C84(void *);
extern void func_021E0FF4(void *p, int a, int flag);
extern void func_021D8CCC(void *,int,int,int,int);
extern int func_02035C60(void);
extern void func_021DBE70(char *p);
extern void func_021E4E64(int a, char *p, int b);
extern void *func_021D8D4C(void **a, int b, int c, char *p);
extern void func_021E2484(char *p, int a);
extern void func_021E1E00(char *p, int mode, void *mon);
extern u32 func_020307B0(void *p);
extern int func_021DD5B4(char *p, int a, int b);
extern void func_021DBBD0(char *p);
extern int func_021DD3D4(const char *p, int n, int a, int b);
extern void func_021DF5D8(char *p);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern unsigned func_02027A20(char *p);
extern int func_02035C38(void);
extern void func_020061E4(u32),func_021E2484(char *,int),func_021D8E84(void *,int),func_021D8C0C(void *),func_021D8B54(void *);
extern int func_021DD2A8(char *);
extern void func_021DF7AC(void *,int);
extern void func_021DBB6C(char *);
extern void func_021E5EF8(void *);
extern void func_021E4174(char *p);
extern u32 func_02027A08(struct TaskMenu *tm, u32 arg);
extern void func_021D4B88(u8 *p);
extern void func_021D6F2C(u8 *p);
extern void func_021DBAF8(char *p);
extern void func_021DC370(char *p);
extern void func_020435F4(u32 planes);
extern void func_021DD1B8(char *);
extern void func_021DF904(void *);
extern void func_0215642C(int);
extern void func_021DD528(char *,int);
extern void func_021DD68C(char *p);
extern void func_021DF78C(void *);
extern void func_02082BCC(void *,int,int);
extern void func_02027858(struct TaskMenu *m);
extern void func_021E4420(char *p);
extern void func_021E6700(void *);
extern void func_021DB7AC(char *,int,int);
extern void func_021E31FC(void *);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_021DC62C(char *,int);
extern int func_021E3E00(char *,int);
extern int func_021D89A8(char *p);
extern void func_021E5098(char *,int);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02022230(u32 which);
extern u16 func_02039338(void);
extern void func_021E36D8(void *,int);
extern u32 func_020173EC(void);
int func_021D9548(char *p,int a,int b);
u32 func_021D95A0(void *mon);
int func_021D95D0(void *p);
u32 func_021D95F0(void *p);
int func_021D9610(unsigned char *p);
void func_021D9670(char *p);
void func_021D9750(char *p);
void func_021D9780(char *p, int a1, int a2);
void func_021D9810(char *p);
void func_021D98AC(char *p);
void func_021D99F4(char *p);
void func_021D9A50(char *p);
void func_021D9AD8(char *p);
void func_021D9B34(char *p);
void func_021D9B84(void *p);
void func_021D9BC4(char *p);
void func_021D9C00(char *p);
void func_021D9CFC(u8 *p);
void func_021D9D60(char *p);
void func_021D9DC4(void *p);
void func_021D9E0C(char *p);
void func_021D9E54(char *p);
void func_021D9EA8(char *p,int a,int b);
int func_021D9EBC(char *p,int *a,int *b,int *c,int *d);
int func_021D9F24(char *p,int save);
void func_021DA064(char *p);
void func_021DA0CC(char *p);
void func_021DA110(char *p);
void func_021DA158(char *p);
void func_021DA1B4(char *p);
void func_021DA1DC(char *p);
void func_021DA254(char *p);
void func_021DA27C(char *p);
void func_021DA2F4(void *p);
void func_021DA318(char *p);
void func_021DA640(char *p);
void func_021DA700(char *p);
void func_021DA76C(void *p);
void func_021DA798(char *p);
void func_021DA898(char *p);
void func_021DA8F8(char *p);
void func_021DA9F0(void *p);
void func_021DAA18(char *p);
void func_021DAA4C(void *p);
void func_021DAA7C(char *p);
void func_021DAAE4(char *p);
void func_021DAB0C(char *p);
void func_021DAB34(char *p);
void func_021DABB0(char *p);
void func_021DABE8(char *p);
void func_021DAC20(void *p);
void func_021DAC60(char *p);
void func_021DACE4(char *p);
void func_021DAD84(void *p);
void func_021DADAC(void *p);
void func_021DAE2C(char *p);
void func_021DAEC8(void *p);
void func_021DAEF0(char *p);
extern const Pt d_021E7580;
extern const Pt d_021E757C;
extern const char d_021E75F0[];
extern const Triple d_021E75E4;
extern const Pair d_021E7584;
extern const Pair d_021E7594;

int func_021D9548(char *p,int a,int b) { int v=(int)func_021D8DD0((void *)(((struct Obj04475 *)p)->f828),a,b,p); int r; if(((struct Obj04475 *)p)->f118C) return 0; if(a!=((struct Obj04475 *)p)->f630) return 0; r=0; if(func_02017E88((void *)v,76,0)) return r; if(func_0202F738((void *)v,r)==0) r=1; return r; }

u32 func_021D95A0(void *mon)
{
    u32 r = 0;
    if (func_02017E1C(mon, 3, 0) == 1)
        return 1;
    if ((int)func_02017E1C(mon, 5, r) > 0x28b)
        r = 1;
    return r;
}


/*
 * Select the alternate buffer when the object is idle.
 */
int func_021D95D0(void *p)
{
    int b = 0;

    if (func_021D8AA8(p))
        b = 1;
    return func_021D95A0(func_021D8FA4(p, b));
}

u32 func_021D95F0(void *p)
{
    int r = 1;
    if (func_021D8AA8(p) != 0)
        r = 0;
    return func_021D95A0(func_021D8FA4(p, r));
}

int func_021D9610(unsigned char *p) { void *v; int w; if(func_021D8AA8(p)==0) {v=func_021D8FA4(p,0); w=func_021D8F20(p,1);} else {v=func_021D8FA4(p,1); w=func_021D8F20(p,0);} if(func_0202136C(func_02017E1C(v,6,0)) && p[0x11f4]!=0 && w==0) return 1; return 0; }


void func_021D9670(char *p)
{
    u8 b[5];
    int r;
    int kind = func_021D8A24(p);

    if (func_021E12AC(p) == 0)
        return;
    if (kind != 0) {
        if (func_021D94D4(p)) {
            b[4] = 5;
            r = func_0203D3A8(func_020399A8(), 0xc00, 1, (u32)(&b[4]));
        } else if (func_021D95D0(p)) {
            b[3] = 7;
            r = func_0203D3A8(func_020399A8(), 0xc00, 1, (u32)(&b[3]));
        } else if (func_021D95F0(p)) {
            b[2] = 8;
            r = func_0203D3A8(func_020399A8(), 0xc00, 1, (u32)(&b[2]));
        } else if (func_021D9610((unsigned char *)p)) {
            b[1] = 6;
            r = func_0203D3A8(func_020399A8(), 0xc00, 1, (u32)(&b[1]));
        } else {
            b[0] = 2;
            r = func_0203D3A8(func_020399A8(), 0xc00, 1, (u32)(&b[0]));
        }
        if (r == 0)
            return;
        func_02039C68((struct Link *)func_020399A8(), 0x1b, 8);
        func_021D8E84(p, (int)func_021DA798);
        return;
    }
    p[0x11e0] = 2;
    p[0x11e1] = 2;
    func_021D8E84(p, (int)func_021DA798);
}

void func_021D9750(char *p)
{
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 6, (void *)(*(int *)&((struct Obj00001 *)p)->f738));
    func_021E1024(p);
    func_021E1030(p);
    func_021D8E84(p, (int)func_021D9670);
}

/*
 * 2026-10-02: the 0204B404 call is written in each branch of the a1 test (tail-merged
 *  by the compiler, so the 0xf0c pool constant is not hoisted across blocks);
 *  020355C4 is a void getter called on its own; the 021D8FA4 result is a local.
 */
void func_021D9780(char *p, int a1, int a2)
{
    Pt t0, t1;
    if (a1 == 0) {
        t0 = d_021E7580;
        func_0204B404((struct Obj *)(((struct Obj05326 *)p)->fF0C), (const struct Vec2 *)(&t0), 1);
    } else {
        t1 = d_021E757C;
        func_0204B404((struct Obj *)(((struct Obj05326 *)p)->fF0C), (const struct Vec2 *)(&t1), 1);
    }
    if (func_020355C4()) {
        func_021E5B6C((int)p, a1, 0);
        func_0204B3DC((struct Obj *)((struct Obj05326 *)p)->fF0C, 0);
    } else {
        func_021E5B6C((int)p, a1, 1);
        func_0204B3DC((struct Obj *)((struct Obj05326 *)p)->fF0C, 1);
    }
    if (a2 != 0) {
        void *v;

        v = func_021D8FA4(p, ((struct Obj05326 *)p)->f10A0);
        func_021E219C(p, v, ((struct Obj05326 *)p)->f10A0, 1);
    }
}

void func_021D9810(char *p) { int z,one; if(func_020221A4()) {z=0;func_02040588(3,0);one=1;func_021E1CE8(p,1);func_02040588(4,0);func_021E3E80(p);func_021E3208(p,0);func_02041B6C(3);*(u16 *)0x04000050=z;func_021D9468(p,0,func_021D8FA4(p,0));func_021D9468(p,1,func_021D8FA4(p,1));func_021D8B38(p);func_0202208C((void *)3,1,1,0,6,one,((struct Obj00001 *)p)->f5F4);func_021D8E84(p,(int)func_021D9AD8); } }

static inline int poll(void) {int v=func_020362DC();if(v)func_020355D8(0);return v;}

/*
 * prototype: 02035C08 is declared int here: original consumes r0 after
 * its 02035BBC forwarding call; the matched void spelling leaves r0 live.
 * Full matched ARM9 02035BBC returns int through 02035ADC, or -1.
 * wrap: the 10a0 toggle uses full-width unsigned subtraction to preserve
 * the original SUB for every 32-bit field pattern without a domain claim.
 */
void func_021D98AC(char *p)
{
 int done=0;
 if(((struct Obj01727 *)p)->f11F9==0 && func_020221A4()) {
  if(func_020355C4() && poll()) {func_020355D8(0);func_021D9780(p,((struct Obj01727 *)p)->f10A0,0);return;}
  func_02040588(3,1);
  switch(func_02035C08(d_021E75F0)) {
  case 0:
   if(((struct Obj01727 *)p)->f10A0!=0 || !func_020355C4()) {
    ((struct Obj01727 *)p)->f10A0=0;func_020355D8(1);func_020061E4(0x548);func_021D9780(p,((struct Obj01727 *)p)->f10A0,1);
   }
   break;
  case 1:
   if(((struct Obj01727 *)p)->f10A0!=1 || !func_020355C4()) {
    ((struct Obj01727 *)p)->f10A0=1;func_020355D8(1);func_020061E4(0x548);func_021D9780(p,((struct Obj01727 *)p)->f10A0,1);
   }
   break;
  case 2:done=1;break;
  }
  if(poll()==32 || poll()==16) {
   *(unsigned *)&((struct Obj01727 *)p)->f10A0=1u-*(unsigned *)&((struct Obj01727 *)p)->f10A0;func_020061E4(0x548);func_020355D8(0);func_021D9780(p,((struct Obj01727 *)p)->f10A0,1);
  }
  func_021B63D0(((struct Obj01727 *)p)->f9C0);
  if(func_021B6448(*(u8 * *)&((struct Obj01727 *)p)->f9C0)==1)done=1;
  if(done) {func_0202208C((void *)3,0,0,0,6,1,((struct Obj01727 *)p)->f5F4);func_021D8E84(p,(int)func_021D9810);}
 }
}

void func_021D99F4(char *p) { if(func_020221A4()) { ((struct Obj03775 *)p)->f10A0=0; func_021E1D68(p,func_021D8FA4(p,0));func_021D8B38(p);func_0202208C((void *)3,1,1,0,6,1,((struct Obj03775 *)p)->f5F4);func_021D8E84(p,(int)func_021D98AC); } }

void func_021D9A50(char *p) { int v; if(func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {v=func_02027A04((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));func_021E12F8(p);func_021E1098(p);*(int *)&((struct Obj00001 *)p)->f64C=0;switch(v) {case 0:func_021D8E84(p,(int)func_021D9750);return;case 1:func_0202208C((void *)3,0,0,0,6,1,((struct Obj00001 *)p)->f5F4);func_021D8E84(p,(int)func_021D99F4);return;case 2:func_021D8E84(p,(int)func_021DADAC);return;} } }

void func_021D9AD8(char *p) { int i; func_02045CAC((struct MsgBank *)(((struct Obj05327 *)p)->f720),17,(void *)(((struct Obj05327 *)p)->f73C));for(i=0;i<2;i++) func_0201EEF4(((struct Obj05327 *)p)->f724,i,func_021D8FA4(p,i));func_0201F250((struct WordSet *)(*(int *)&((struct Obj05327 *)p)->f724),(void *)(((struct Obj05327 *)p)->f738),(void *)(((struct Obj05327 *)p)->f73C));func_021E1024(p);func_021D8E84(p,(int)func_021D9B34); }

void func_021D9B34(char *p) { if(func_021E12AC(p)) { Triple t=d_021E75E4; func_021E1410(p,(int *)(&t),3); func_02043534(31); func_021B6558((unsigned char *)(((struct Obj22726 *)p)->f9C0),1,0); func_021D8E84(p,(int)func_021D9A50); } }

void func_021D9B84(void *p) {
 if(func_021D8A24(p)) {
  if(func_02039CB4((struct Link *)func_020399A8(),20,8)) {
   func_021E1098(p); func_021D8E84(p,(int)func_021D9434);
  }
 } else { func_021E1098(p); func_021D8E84(p,(int)func_021D9434); }
}

void func_021D9BC4(char *p) {
 if(func_021E12AC(p) && ((struct Obj00001 *)p)->fF2C>30) {
  if(func_021D8A24(p)) func_02039C68((struct Link *)func_020399A8(),20,8);
  func_021D8E84(p,(int)func_021D9B84);
 }
}


void func_021D9C00(char *p)
{
    int cmd;
    u32 other;
    u32 me;
    u32 a;

    me = func_0203D1A4((struct Link *)func_020399A8());
    other = 1 - me;
    if (func_021D8A24(p) == 0) {
        me = 0;
        other = 1;
    }
    if (func_021D8A24(p) != 0 && func_02039CB4((struct Link *)func_020399A8(), 0x1a, 8) == 0) {
        func_021DD24C(p);
        return;
    }
    func_021DD294(p, 1, 1);
    a = ((u8 *)p + me)[0x11e0];
    if (a == 1 && ((u8 *)p + other)[0x11e0] == 1) {
        func_021D8E84(p, (int)func_021D9AD8);
        return;
    }
    if (a == 4 && ((u8 *)p + other)[0x11e0] == 4) {
        ((struct Obj22727 *)(*(char * *)&((struct Obj03772 *)p)->f8))->f8 = 3;
        func_02045CAC((struct MsgBank *)(((struct Obj03772 *)p)->f720), 0x8d, (void *)(((struct Obj03772 *)p)->f738));
        func_021E1024(p);
        func_021E1030(p);
        ((struct Obj03772 *)p)->fF2C = 0;
        func_021D8E84(p, (int)func_021D9BC4);
        return;
    }
    if (((u8 *)p + other)[0x11e0] == 4)
        cmd = 0x61;
    else if (a == 4)
        cmd = 0x66;
    func_02045CAC((struct MsgBank *)(((struct Obj03772 *)p)->f720), cmd, (void *)(((struct Obj03772 *)p)->f738));
    func_021E1024(p);
    p[0x11e0] = 0;
    p[0x11e1] = 0;
    func_021D8E84(p, (int)func_021DAEF0);
}

void func_021D9CFC(u8 *p) { int kind=func_021D8A24(p); u8 b; if(func_021E12AC((char *)p)) { if(kind==0) {p[0x11e0]=1;p[0x11e1]=1;func_021D8E84(p,(int)func_021D9C00);return;} b=1; if(func_0203D3A8(func_020399A8(),0xc00,1,(u32)(&b))==0) return; func_02039C68((struct Link *)func_020399A8(),26,8);func_021D8E84(p,(int)func_021D9C00); } }

void func_021D9D60(char *p) {
    int v;
    if (func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))) {
        v=func_02027A04((const unsigned char *)(*(int *)&((struct Obj00001 *)p)->f64C));
        func_021E12F8(p);
        *(int *)&((struct Obj00001 *)p)->f64C=0;
        if (v==0) {
            func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),6,(void *)(*(int *)&((struct Obj00001 *)p)->f738));
            func_021E1024(p);
            func_021E1030(p);
            func_021D8E84(p,(int)func_021D9CFC);
            return;
        }
        func_021D8E84(p,(int)func_021DBA80);
    }
}

void func_021D9DC4(void *p)
{
    if (func_021DB0A0(p)) {
        Pair t = d_021E7584;
        func_021E1410(p,(int *)(&t),2);
        func_0207D658(0x04001050,0x1B,-8);
        func_021D8E84(p,(int)func_021D9D60);
    }
}

void func_021D9E0C(char *p)
{
    int v = 0;
    if (((struct Obj13890 *)p)->fF88 == ((struct Obj13890 *)p)->f630) v=1;
    if (func_0203D3A8(func_020399A8(),0xC16,1,(u32)(&v)))
        func_021D8E84(p,(int)func_021D9DC4);
}

void func_021D9E54(char *p) {
    func_021B6558((unsigned char *)(((struct Obj04474 *)p)->f9C0),7,0);
    func_021B6558((unsigned char *)(((struct Obj04474 *)p)->f9C0),8,0);
    func_021B6558((unsigned char *)(((struct Obj04474 *)p)->f9C0),9,0);
    func_021B6558((unsigned char *)(((struct Obj04474 *)p)->f9C0),1,0);
    func_0204B3DC((struct Obj *)((struct Obj04474 *)p)->fF04,0);
    func_021D8C6C(p);
    func_021D8E84(p,(int)func_021D9E0C);
}

void func_021D9EA8(char *p,int a,int b) {
 ((struct Obj00001 *)p)->fF74=a;
 ((struct Obj00001 *)p)->fF78=b;
 func_021D8B38(p);
}

int func_021D9EBC(char *p,int *a,int *b,int *c,int *d) {
    int x,y,z,n;
    if(func_02035D20((unsigned int *)(&x),(unsigned int *)(&y))==1) {
        if(func_021E51A4(p,x+12,y+12,a,b,c,d,&z)) {
            n=(int)func_021D8DD0((void *)(*(int *)&((struct Obj00001 *)p)->f828),*a,*b,p);
            if(n && func_02017E88((void *)n,0xA9,0)) return 1;
        }
    }
    return 0;
}

int func_021D9F24(char *p,int save)
{
 int x,y,a,b,c,hit,e,result=0;
 if(func_02035D20((u32 *)(&x),(u32 *)(&y))==1) {
  hit=func_021E51A4(p,x+12,y+12,(int *)(p+0xf80),(int *)(p+0xf7c),&a,&b,&c);
  if(hit) {
   e=(int)func_021D8DD0((void *)I(0x828),I(0xf80),I(0xf7c),p);
   if(func_021DBD70(p,I(0xf80),I(0xf7c))) {
    func_020061E4(0x626);
    if(!func_021D8AA8(p)) {func_021D8E84(p,(int)func_021DB9B4);return 3;}
    I(0xf98)=I(0xf80);I(0xf94)=I(0xf7c);func_021D8E84(p,(int)func_021DF708);return 3;
   }
   func_021D8C84(p);
   if(e && func_02017E88((void *)e,0xa9,0)) {
    if(func_021DD0CC(p,e)) {
     func_02045CAC((struct MsgBank *)I(0x720),0x8e,(void *)I(0x738));func_021E0FF4(p,1,0);func_021D8E84(p,(int)func_021DA064);return 2;
    }
    func_021D8CCC(p,hit,c,b,e);func_021D9EA8(p,a,b);
    if(save) {I(0xf98)=I(0xf80);I(0xf94)=I(0xf7c);}
    func_021D8B38(p);result=1;
   }
  }
 }
 return result;
}

void func_021DA064(char *p) {
    int v;
    if (func_021E12AC(p)) {
        v=func_020362DC();
        if(v) func_020355D8(0);
        if(!v) {
            v=func_02035C60();
            if(v) func_020355D8(1);
            if(!v) return;
        }
        ((struct Obj00001 *)p)->fF80=-1;
        ((struct Obj00001 *)p)->fF7C=-1;
        func_021E1098(p);
        func_021D8E84(p,(int)func_021DBE70);
        ((struct Obj00001 *)p)->f1080=-1;
        func_021E4E64(*(int *)&((struct Obj00001 *)p)->f828,p,1);
    }
}

void func_021DA0CC(char *p)
{
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 0x65, (void *)(*(int *)&((struct Obj00001 *)p)->f738));
    func_021E1024(p);
    ((struct Obj00001 *)p)->f1080 = -1;
    func_021E4E64(*(int *)&((struct Obj00001 *)p)->f828, p, 0);
    func_021D8E84(p, (int)func_021DA064);
}

void func_021DA110(char *p)
{
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 0x8E, (void *)(*(int *)&((struct Obj00001 *)p)->f738));
    func_021E0FF4(p,1,0);
    ((struct Obj00001 *)p)->f1080 = -1;
    func_021E4E64(*(int *)&((struct Obj00001 *)p)->f828, p, 0);
    func_021D8E84(p, (int)func_021DA064);
}

void func_021DA158(char *p) {
    int v=(int)func_021D8D4C(*(void ** *)&((struct Obj08052 *)p)->f828,((struct Obj08052 *)p)->fF98,((struct Obj08052 *)p)->fF94,p);
    func_021E2484(p,0);
    func_021E1E00(p,((struct Obj08052 *)p)->f10A0,(void *)v);
    if (func_020355C4()) func_021D8B38(p);
    func_020307B0((void *)v);
    func_021D8E84(p,(int)func_021DA318);
}

void func_021DA1B4(char *p) {
 if(func_021DD5B4(p,((struct Obj00001 *)p)->fF84,((struct Obj00001 *)p)->fF88)) func_021D8E84(p,(int)func_021DBBD0);
}

void func_021DA1DC(char *p) {
    int v=0;
    int n;
    if(((struct Obj08053 *)p)->fF88==((struct Obj08053 *)p)->f630) v=1;
    n=func_021DD3D4(p,0,((struct Obj08053 *)p)->fF84,((struct Obj08053 *)p)->fF88);
    if(n!=-1) {
        if(func_0203D3A8(func_020399A8(),(u16)(n+0xC13),(u16)1,(u32)(&v))) {
            func_021D8E84(p,(int)func_021DA1B4);
            return;
        }
    } else func_021D8E84(p,(int)func_021DA1B4);
}

void func_021DA254(char *p) {
 if(func_021DD5B4(p,((struct Obj00001 *)p)->fF84,((struct Obj00001 *)p)->fF88)) func_021D8E84(p,(int)func_021DF5D8);
}

void func_021DA27C(char *p) {
    int v=0;
    int n;
    if(((struct Obj08054 *)p)->fF88==((struct Obj08054 *)p)->f630) v=1;
    n=func_021DD3D4(p,0,((struct Obj08054 *)p)->fF84,((struct Obj08054 *)p)->fF88);
    if(n!=-1) {
        if(func_0203D3A8(func_020399A8(),(u16)(n+0xC13),(u16)1,(u32)(&v))) {
            func_021D8E84(p,(int)func_021DA254);
            return;
        }
    } else func_021D8E84(p,(int)func_021DA254);
}

void func_021DA2F4(void *p) {
 int a,b;
 if(!func_02035CB8((u32 *)(&a),(u32 *)(&b))) func_021D8E84(p,(int)func_021DBE70);
}

void func_021DA318(char *p)
{
    u32 x,y;
    int slot,column;
    int changed=0;
    int keep=1;
    int choice=keep-2;
    int active=0;
    int n;
    if(!func_02027A20(P(0x64c))) {
        n=func_02035C60();
        if(n) func_020355D8(keep);
        if(n) func_021D8C84(p);
        func_021B63D0(P(0x9c0));
        if(func_021B6470(P(0x9c0))==9 && func_020355C4()) func_02027A08(P(0x64c),0);
        if(func_021B6448(P(0x9c0))==9) {
            changed=1;
            ((struct Obj04475 *)p)->f10A0=1U-((struct Obj04475 *)p)->f10A0;
        }
        if(func_02035D20(&x,&y)==1) {
            func_020355D8(1);
            func_02027A08(P(0x64c),0);
            if(func_021D9EBC(p,(int *)(p+0xf98),(int *)(p+0xf94),&slot,&column)) {
                I(0xf78)=column;
                I(0xf74)=slot;
                ((struct Obj04475 *)p)->fF54=x;
                ((struct Obj04475 *)p)->fF58=y;
                func_020061E4(0x548);
                changed=1;
            } else if(y>=16 && y<144) active=1;
        }
        if(changed) {
            func_021E2484(p,1);
            func_021D8E84(p,(int)func_021DA158);
            return;
        }
        func_021D8C0C(p);
        if(!active && !func_02035C38() && I(0xf34)) {
            if(I(0xf60) && I(0xf5c)) {
                func_020061E4(0x72a);
                choice=0;
                active=1;
            } else func_021D8C84(p);
        }
        func_021D8B54(p);
        func_021D8C0C(p);
    }
    if(func_020279E8(P(0x64c))) {
        choice=func_02027A04(P(0x64c));
        active=1;
    }
    if(active) {
        if(choice==0) {
            n=(int)func_021D8DD0((void *)I(0x828),I(0xf98),I(0xf94),p);
            if(func_021DBD70(p,I(0xf98),I(0xf94)) && func_021D8AA8(p)) {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                func_021D8E84(p,(int)func_021DA1DC);
            } else if(func_021D9548(p,I(0xf98),I(0xf94))) {
                func_021DF7AC(p,1);
                func_021D8E84(p,(int)func_021DA0CC);
            } else if(func_021DD0CC(p,n)) {
                func_021D8E84(p,(int)func_021DA110);
                func_021DF7AC(p,1);
            } else if(!func_021D8AA8(p)) {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                func_021D8E84(p,(int)func_021D9E54);
                func_021B6558((unsigned char *)I(0x9c0),7,0);
                func_021B6558((unsigned char *)I(0x9c0),8,0);
                func_021B6558((unsigned char *)I(0x9c0),9,0);
                keep=0;
            } else if(func_021DD2A8(p) && !func_020355C4()) {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                func_021D8E84(p,(int)func_021DA27C);
                func_021B6558((unsigned char *)I(0x9c0),7,0);
                func_021B6558((unsigned char *)I(0x9c0),8,0);
                func_021B6558((unsigned char *)I(0x9c0),9,0);
                keep=0;
            } else {
                I(0xf84)=I(0xf94);
                I(0xf88)=I(0xf98);
                func_021D8E84(p,(int)func_021DA1DC);
            }
        } else {
            func_021DF7AC(p,1);
            func_021D8E84(p,(int)func_021DA2F4);
        }
        I(0xf98)=-1;
        I(0xf94)=-1;
        if(keep) {
            func_021DBB6C(p);
            func_0204B3DC(P(0xf04),1);
        }
        func_021E5EF8(p+0x950);
        func_021E5EF8(p+0x964);
        func_021E5EF8(p+0x978);
        func_021E2484(p,1);
        func_02041B6C(6);
        func_021E4174(p);
        func_021E12F8(p);
        P(0x64c)=0;
    }
    I(0xf34)=func_02035C38();
}

void func_021DA640(char *p) {
    Pair t;
    int n;
    int zero=0;
    func_021DF7AC(p,0);
    func_021B6558((unsigned char *)(((struct Obj02826 *)p)->f9C0),1,0);
    func_021B6558((unsigned char *)(((struct Obj02826 *)p)->f9C0),7,0);
    func_021B6558((unsigned char *)(((struct Obj02826 *)p)->f9C0),9,1);
    t=d_021E7594;
    func_021E1410(p,(int *)(&t),2);
    n=(int)func_021D8D4C(*(void ** *)&((struct Obj02826 *)p)->f828,((struct Obj02826 *)p)->fF98,((struct Obj02826 *)p)->fF94,p);
    ((struct Obj02826 *)p)->f10A0=zero;
    func_021E1E00(p,0,(void *)n);
    func_020307B0((void *)n);
    func_0204B3DC((struct Obj *)((struct Obj02826 *)p)->fF04,0);
    func_021D8C84(p);
    func_021D8B38(p);
    if(func_020355C4()) func_02027A08((struct TaskMenu *)(((struct Obj02826 *)p)->f64C),zero);
    else func_02027A08((struct TaskMenu *)(((struct Obj02826 *)p)->f64C),1);
    func_021D8E84(p,(int)func_021DA318);
}

void func_021DA700(char *p) {
 u8 b=((struct Obj00001 *)p)->f10A0;
 if(func_021D8A24(p)) {if(func_0203D3A8(func_020399A8(),0xc03,1,(u32)(&b))==0) return;}
 *(unsigned *)0x04001000 &= 0xffff1fff;
 if(func_021D8AA8(p)==0) func_021D8E84(p,(int)func_021D4B88);
 else func_021D8E84(p,(int)func_021D6F2C);
}

void func_021DA76C(void *p) {
 if(!func_021D8A24(p) || func_02039CB4((struct Link *)func_020399A8(),13,8)) func_021D8E84(p,(int)func_021DA700);
}

void func_021DA798(char *p) {
 int i, j, v;
 unsigned char a, b;
 i = func_0203D1A4((struct Link *)((unsigned)func_020399A8()));
 j = 1 - i;
 if(func_021D8A24(p) && func_02039CB4((struct Link *)func_020399A8(),27,8)==0) {
  func_021DD24C(p);
  return;
 }
 func_021DD294(p,1,1);
 a = (p+i)[0x11e0];
 if(a==2 && ((unsigned char *)(p+j))[0x11e0]==2) {
  if(func_021D8A24(p)) func_02039C68((struct Link *)func_020399A8(),13,8);
  func_021D8E84(p,(int)func_021DA76C);
  return;
 }
 b = (p+j)[0x11e0];
 if(b==5) v=0x61;
 else if(a==5) v=0x62;
 else if(b==7) v=0x63;
 else if(a==7) v=0x64;
 else if(b==8) v=0x64;
 else if(a==8) v=0x63;
 else if(b==9) v=0x61;
 else if(a==9) v=0x65;
 else if(b==6) v=0x61;
 else if(a==6) v=0x6f;
 else if(b==3) v=0x61;
 else if(a==3) v=0x66;
 func_02045CAC((struct MsgBank *)(((struct Obj08055 *)p)->f720),v,(void *)(((struct Obj08055 *)p)->f738));
 func_021E1024(p);
 p[0x11e0]=0;
 p[0x11e1]=0;
 func_021D8E84(p,(int)func_021DAEF0);
}

void func_021DA898(char *p) {
 if(func_021D8AA8(p)) {func_021DBA80(p);func_021DBAF8(p);func_021D8E84(p,(int)func_021DC370);}
 else {func_021DBA80(p);func_021DBAF8(p);}
 func_0202208C(0,1,1,0,6,1,((struct Obj00001 *)p)->f5F4);
 func_02043534(31);func_020435F4(30);
}

void func_021DA8F8(char *p)
{
 if(func_021D8A24(p) && !func_02039CB4((struct Link *)func_020399A8(),18,8)) return;
 func_021E1098(p);
 if(func_021D8AA8(p)) {
  func_021DD1B8(p);func_021DF904(p);
  if(((struct Obj03773 *)p)->f118C==2) func_0215642C(0);
  func_02045CAC((struct MsgBank *)(((struct Obj03773 *)p)->f720),134,(void *)(((struct Obj03773 *)p)->f738));func_021E1024(p);
  func_021DD528(p,0);func_021DD68C(p);
  ((struct Obj03773 *)p)->f11E8=0;((struct Obj03773 *)p)->f11E9=0;
  func_021DF78C(p);func_021DF7AC(p,1);
  func_02082BCC(p+0xca0,0,0x78);func_02082BCC(p+0xd18,0,0x3c);func_02082BCC(p+0xd54,0,0x3c);
  func_021D8C84(p);
  if(((struct Obj03773 *)p)->f64C) {func_02027858((struct TaskMenu *)(((struct Obj03773 *)p)->f64C));((struct Obj03773 *)p)->f64C=0;}
  func_021E4420(p);func_021E6700(p);func_021DBB6C(p);
 }
 func_021D8E84(p,(int)func_021DA898);func_021DB7AC(p,0,1);
}

void func_021DA9F0(void *p) {
 if(func_021E12AC(p) && func_020221A4()) {
  func_021E1098(p);
  func_021D8E84(p,(int)func_021DA8F8);
 }
}

void func_021DAA18(char *p) {
 func_0202208C((void *)4,0,0,0,6,1,((struct Obj22730 *)p)->f5F4);
 func_021D8E84(p,(int)func_021DA9F0);
}

void func_021DAA4C(void *p) {
 if(!func_021D8A24(p) || func_02039CB4((struct Link *)func_020399A8(),18,8)!=0) {
  func_021E31FC(p);
  func_021D8E84(p,(int)func_021DAA18);
 }
}

void func_021DAA7C(char *p) {
 if(func_021D8A24(p)) {
  if(func_0203D3F8((unsigned)func_020399A8(),255,0xc0e,0x2d6,(u32)(p+16),0,0,1)) {
   func_02039C68((struct Link *)func_020399A8(),18,8);func_021D8E84(p,(int)func_021DAA4C);
  }
 } else {func_021E31FC(p);func_021D8E84(p,(int)func_021DAA4C);}
}

void func_021DAAE4(char *p) {
 func_021DC62C(p,((struct Obj13891 *)p)->fF2C-1);
 if(((struct Obj13891 *)p)->fF2C>=24) func_021D8E84(p,(int)func_021DAA7C);
}

void func_021DAB0C(char *p) {
 if(func_021E3E00(p,((struct Obj13892 *)p)->fF2C-1)) {
  ((struct Obj13892 *)p)->fF2C=0;
  func_021D8E84(p,(int)func_021DAAE4);
 }
}

void func_021DAB34(char *p) {
 u8 b[2];
 if(func_021D8A24(p)) {
  b[0]=((struct Obj04476 *)p)->f630;b[1]=func_021D89A8(p);
  if(func_0203D3A8(func_020399A8(),0xc10,2,(u32)((void *)b))) {((struct Obj04476 *)p)->fF2C=0;func_021D8E84(p,(int)func_021DAB0C);}
 } else {
  p[0x11f2]=((struct Obj04476 *)p)->f630;((struct Obj04476 *)p)->f107E=((struct Obj04476 *)p)->f11F2*160+16;
  ((struct Obj04476 *)p)->fF2C=0;func_021D8E84(p,(int)func_021DAB0C);
 }
}

void func_021DABB0(char *p) {
 func_021E5098(p,((struct Obj00001 *)p)->fF2C-1);
 if(((struct Obj00001 *)p)->fF2C>25) {
  func_021E4E64(*(int *)&((struct Obj00001 *)p)->f828,p,0);
  func_021D8E84(p,(int)func_021DAB34);
 }
}

void func_021DABE8(char *p) {
 if(func_02039CB4((struct Link *)func_020399A8(),22,8)) {
  func_0203D7B0(1);
  func_0203D7BC(1);
  ((struct Obj22731 *)p)->fF2C=0;
  func_021D8E84(p,(int)func_021DABB0);
 }
}

void func_021DAC20(void *p) {
 if(func_020221A4()) {
  if(func_021D8A24(p)) {
   func_02039C68((struct Link *)func_020399A8(),22,8);
   func_021D8E84(p,(int)func_021DABE8);
  } else { func_021D8E84(p,(int)func_021DAB34); }
 }
}

void func_021DAC60(char *p) {
 func_0203D34C(1,((struct Obj06423 *)p)->f5F4);if(((struct Obj06423 *)p)->f118C==2)func_0215642C(1);
 func_02045CAC((struct MsgBank *)(((struct Obj06423 *)p)->f720),6,(void *)(((struct Obj06423 *)p)->f738));func_021E0FF4(p,1,0);func_021E1030(p);
 func_02043534(16);func_020435F4(4);func_02022230(0);
 func_0202208C((void *)4,1,1,0,6,1,((struct Obj06423 *)p)->f5F4);func_021D8E84(p,(int)func_021DAC20);
}

void func_021DACE4(char *p) {
 int i;
 func_02039338();((struct Obj04477 *)p)->fF88=-1;((struct Obj04477 *)p)->fF84=-1;((struct Obj04477 *)p)->f800=0;((struct Obj04477 *)p)->fF60=0;((struct Obj04477 *)p)->f1060=0;
 func_021E36D8(p,0);func_021E36D8(p,1);if(func_021D8AA8(p))func_021DD1B8(p);
 func_02082BCC(((struct Obj04477 *)p)->f5DC,0,func_020173EC());func_02082BCC(((struct Obj04477 *)p)->f5E0,0,func_020173EC());
 for(i=0;i<10;i++) {if(*(int *)(p+0xefc+4*i))func_0204B3DC((struct Obj *)*(int *)(p+0xefc+4*i),1);}
 func_021E1098(p);func_021D8E84(p,(int)func_021DAC60);
}

void func_021DAD84(void *p) {
 if(func_021E12AC(p)) {
  func_02039C68((struct Link *)func_020399A8(),27,8);
  func_021D8E84(p,(int)func_021DA798);
 }
}


void func_021DADAC(void *p)
{
    u8 b = 3;

    if (func_021D8A24(p) == 0) {
        func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 0x61,
                      (void *)(*(int *)&((struct Obj00001 *)p)->f738));
        func_021E1024(p);
        func_021D8E84(p, 0x021DAEF1);
        return;
    }
    if (func_0203D3A8(func_020399A8(), 0xc00, 1, (u32)(&b)) == 0)
        return;
    func_02039C68((struct Link *)func_020399A8(), 0x1b, 8);
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 6, (void *)(*(int *)&((struct Obj00001 *)p)->f738));
    func_021E1024(p);
    func_021E1030(p);
    func_021D8E84(p, 0x021DAD85);
}

void func_021DAE2C(char *p) {
 int i;
 if(func_02039CB4((struct Link *)func_020399A8(),25,8)==0) {func_021DD24C(p);return;}
 func_021DD294(p,1,1);func_021E1098(p);
 p[0x11e0]=0;p[0x11e1]=0;p[0x11e8]=0;p[0x11e9]=0;
 for(i=0;i<6;i++) {
  char *q=p+(i/3)*12+(i%3)*4;
  ((struct Obj10354 *)q)->fFA4=-1;
  if(((struct Obj10354 *)q)->fFD8)func_02082BCC(((struct Obj10354 *)q)->fFD8,0,func_020173EC());
 }
 func_021D8E84(p,(int)func_021DBA80);
}

void func_021DAEC8(void *p) {
 if(func_021E12AC(p)) {
  func_02039C68((struct Link *)func_020399A8(),25,8);
  func_021D8E84(p,(int)func_021DAE2C);
 }
}

static inline int poll_a(void) {int r=func_020362DC();if(r)func_020355D8(0);return r;}

static inline int poll_b(void) {int r=func_02035C60();if(r)func_020355D8(1);return r;}

void func_021DAEF0(char *p) {
 if(func_021E12AC(p)) {
  if(poll_a() || poll_b()) {
   func_021E1098(p);
   if(func_021D8A24(p)) {
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),50,(void *)(*(int *)&((struct Obj00001 *)p)->f738));func_021E1024(p);func_021E1030(p);func_021D8E84(p,(int)func_021DAEC8);
   } else func_021D8E84(p,(int)func_021DBA80);
  }
 }
}
