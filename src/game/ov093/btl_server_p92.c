/*
 * file:     btl_server_p92.c
 * unit:     yes
 * function: func_021C8300, func_021C830C, func_021C831C, func_021C8338, func_021C8348, func_021C8374, func_021C83A0
 * address:  0x021C8300
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
 *   func_021B9010  0x021B9010  thumb  ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5C30 0x021D5C30 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021C2AF0 0x021C2AF0 thumb ov093
 *   func_021D67E8 0x021D67E8 thumb ov093
 *   func_021D7B10 0x021D7B10 thumb ov093
 */
#include "../../matched/include/Obj21118.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj21119.h"

struct UtilWork;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned int u32;

struct Bits { unsigned char a:1; unsigned char rest:7; };

typedef unsigned short u16;

extern u8 func_021B9010(u8 *p, u8 k);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D5C30(struct UtilWork *p);
extern u8 func_021D69AC(u8 *, int);
extern int func_021D62C4(struct Unk021D62A8 *, int);
extern int func_021C2AF0(u8 *, u8 *);
extern u16 func_021D67E8(u8 *p);
extern u32 func_021D7B10(u32, u32);
u32 func_021C8300(int *p, u8 k);
unsigned int func_021C830C(u8 *p);
void func_021C831C(u8 *p, int v);
int func_021C8338(unsigned char *p, int i);
int func_021C8348(u8 *p, int i);
int func_021C8374(u8 *p, int i);
u32 func_021C83A0(u8 *p, int i);


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
