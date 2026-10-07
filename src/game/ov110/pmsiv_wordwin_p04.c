/*
 * file:     pmsiv_wordwin_p04.c
 * unit:     yes
 * function: func_021BF844, func_021BF8BC
 * address:  0x021BF844
 * region:   ov110
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
 *   d_021C3C84 0x021C3C84 data a1
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj02819.h"
#include "../../matched/include/Obj03755.h"

struct U16Vec;
struct Obj;
struct Descriptor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u8 *func_021BF6D4(u8 *);
extern void func_0204B3B4(struct Obj *);
extern void func_02045808(struct U16Vec *);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);
u8 *func_021BF844(void *a,void *b,void *c);
void func_021BF8BC(u8 *p);
extern const char d_021C3C84[];

u8 *func_021BF844(void *a,void *b,void *c) {
    u8 *p=func_02030734(42,160,0,d_021C3C84,154);
    ((struct Obj02819 *)p)->f0=a; ((struct Obj02819 *)p)->f4=b; ((struct Obj02819 *)p)->f8=c;
    ((struct Obj02819 *)p)->f48=func_020457B0(32,42);
    ((struct Obj02819 *)p)->fC=(void *)func_020450F0(2,3,0,26,32,13,1);
    ((struct Obj02819 *)p)->f10=(void *)func_020450F0(2,0,0,12,4,13,1);
    ((struct Obj02819 *)p)->f14=0; ((struct Obj02819 *)p)->f18=0;
    ((struct Obj02819 *)p)->f9C=func_021BF6D4(*(u8 * *)&((struct Obj02819 *)p)->f4);
    return p;
}

/*
 * note: two trailing zero alignment bytes.
 */
void func_021BF8BC(u8 *p) {
    if(*(struct Obj * *)&((struct Obj03755 *)p)->f14) func_0204B3B4(*(struct Obj * *)&((struct Obj03755 *)p)->f14);
    if(*(struct Obj * *)&((struct Obj03755 *)p)->f1C) func_0204B3B4(*(struct Obj * *)&((struct Obj03755 *)p)->f1C);
    if(*(struct U16Vec * *)&((struct Obj03755 *)p)->f48) func_02045808(*(struct U16Vec * *)&((struct Obj03755 *)p)->f48);
    func_020452E8(*(struct Descriptor * *)&((struct Obj03755 *)p)->f10);
    func_020452E8(*(struct Descriptor * *)&((struct Obj03755 *)p)->fC);
    func_020307B0(p);
}
