/*
 * file:     btl_server_p79.c
 * unit:     yes
 * function: func_021C82F4, func_021C8300, func_021C830C, func_021C831C, func_021C8338, func_021C8348, func_021C8374, func_021C83A0, func_021C83CC, func_021C83D4, func_021C83DC, func_021C83E8, func_021C8408, func_021C8434
 * address:  0x021C82F4
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
 *   func_068982AC  0x068982AC  thumb
 *   func_021B9010  0x021B9010  thumb  ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5C30 0x021D5C30 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021C2AF0 0x021C2AF0 thumb ov093
 *   func_021D67E8 0x021D67E8 thumb ov093
 *   func_021D7B10 0x021D7B10 thumb ov093
 *   func_021C2E4C   0x021C2E4C  thumb ov093
 *   func_021BC2B0   0x021BC2B0  thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021BB908 0x021BB908 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BB914 0x021BB914 thumb ov093
 *   func_021C845C 0x021C845C thumb ov093
 *   func_021BE52C 0x021BE52C thumb ov093
 */
#include "../../matched/include/Obj21118.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj21119.h"
#include "../../matched/include/Obj21120.h"
#include "../../matched/include/Obj13342.h"
#include "../../matched/include/Obj09974.h"
#include "../../matched/include/Obj21121.h"

struct UtilWork;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021C82F4;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32_021C82F4;

struct Bits { unsigned char a:1; unsigned char rest:7; };

typedef signed short s16_021C83CC;

typedef signed int s32_021C83CC;

extern int func_068982AC(int);
extern u8 func_021B9010(u8 *p, u8 k);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D5C30(struct UtilWork *p);
extern u8 func_021D69AC(u8 *, int);
extern int func_021D62C4(struct Unk021D62A8 *, int);
extern int func_021C2AF0(u8 *, u8 *);
extern u16 func_021D67E8(u8 *p);
extern u32 func_021D7B10(u32, u32);
extern u32 func_021C2E4C(u8 *p);
extern int func_021BC2B0(u8 *p);
extern void *func_021B86B8(void ***);
extern void func_021BB908(int *, int);
extern u8 func_021B8DDC(u32 x);
extern u8 func_021B8FF4(u8 *);
extern void func_021BB914(int *);
extern int func_021C845C(u8 *, int);
extern void func_021BE52C(u8 *, int, int, int);
int func_021C82F4(int a, int b, int c);
u32 func_021C8300(int *p, u8 k);
unsigned int func_021C830C(u8 *p);
void func_021C831C(u8 *p, int v);
int func_021C8338(unsigned char *p, int i);
int func_021C8348(u8 *p, int i);
int func_021C8374(u8 *p, int i);
u32 func_021C83A0(u8 *p, int i);
u32 func_021C83CC(u8 *p);
int func_021C83D4(u8 *p);
void func_021C83DC(char *p, int x);
int func_021C83E8(unsigned char *p, int i, int b);
void func_021C8408(u8 *p, int a);
void func_021C8434(u8 *p, int a, int b);




/*
 * Tail-call stub: mov r0, r2; bx to the pool word 0x068982AD (a thumb
 * target in the 0x06xxxxxx window, not an image address).
 */
int func_021C82F4(int a, int b, int c)
{
    return func_068982AC(c);
}





u32 func_021C8300(int *p, u8 k)
{
    return func_021B9010((u8 *)p[1], k);
}




/*
 * lever: unsigned-char bitfield gives the byte load and 31-bit shift pair.
 */
unsigned int func_021C830C(u8 *p) { return ((struct Bits *)(p+0x78a))->a; }




/*
 * lever: add the byte index to the base before applying the constant offset.
 */
void func_021C831C(u8 *p, int v) { unsigned int n; n=p[0x788]; if(n<6) { p[0x788]=n+1; (p+n)[0x78b]=v; } }




/*
 * extent: Two bytes of alignment padding follow the 14-byte function.
 */
int func_021C8338(unsigned char *p, int i)
{
    return func_021D5C30((struct UtilWork *)func_021B9934(*(char * *)&((struct Obj21118 *)p)->f8, i));
}




/*
 * extent: Two bytes of alignment padding follow the 42-byte function.
 */
int func_021C8348(u8 *p, int i)
{
    u8 n = func_021D69AC(func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, i), 4);
    if (n != 0) {
        n--;
        if (n < 24) goto done;
    }
    n = 31;
done:
    if (n != 31) return 1;
    return 0;
}




int func_021C8374(u8 *p, int i)
{
    if (func_021C8348(p, i)) return 1;
    if (func_021D62C4((struct Unk021D62A8 *)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, i), 33)) return 1;
    return 0;
}




u32 func_021C83A0(u8 *p, int i)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj21119 *)p)->f8, i);
    int b = func_021C2AF0(p, a);
    u32 r = func_021D7B10(func_021D67E8(a), b);
    if (r < 1) r = 1;
    return r;
}




/*
 * tail-call thunk to func_021C2E4C
 */
u32 func_021C83CC(u8 *p)
{
    return func_021C2E4C(p);
}




/*
 * tail-call thunk to func_021BC2B0
 */
int func_021C83D4(u8 *p)
{
    return func_021BC2B0(p);
}




void func_021C83DC(char *p, int x)
{
    *(char *)(((struct Obj21120 *)p)->f4A8 + 4) = x;
}



/*
 * evidence: Original loads r1 for func_021BB908 even though its body ignores it.
 */
int func_021C83E8(unsigned char *p, int i, int b)
{
    if ((unsigned int)func_021B86B8(*(void *** *)&((struct Obj13342 *)p)->f4) <= 1) {
        func_021BB908(*(int * *)&((struct Obj13342 *)p)->f0, i);
        return 1;
    }
    return 0;
}


void func_021C8408(u8 *p, int a)
{
    unsigned int t = (unsigned int)func_021B86B8(*(void *** *)&((struct Obj09974 *)p)->f4);
    int k = func_021B8DDC(a);
    if (t <= 1 && k == func_021B8FF4(*(u8 * *)&((struct Obj09974 *)p)->f4)) func_021BB914(*(int * *)&((struct Obj09974 *)p)->f0);
}


void func_021C8434(u8 *p, int a, int b)
{
    int c = func_021C845C(p + 0x1ab8, b);
    func_021BE52C(*(u8 * *)&((struct Obj21121 *)p)->f4B0, a, b, c);
}
