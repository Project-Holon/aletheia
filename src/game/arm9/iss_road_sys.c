/*
 * file:     iss_road_sys.c
 * unit:     yes
 * function: func_0202B1AC, func_0202B1EC, func_0202B1F4, func_0202B1FC, func_0202B204, func_0202B20C, func_0202B224
 * address:  0x0202B1AC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj08802.h"
#include "../../matched/include/Obj11313.h"

struct Rec44;
struct Vec12;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct Copy {
    u32 a, b, c;
} Copy;

struct Node {
    u32 f0, f4, f8;
    Copy body;
};

typedef unsigned short u16;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Vec12 *func_02012AA0(struct Rec44 *p);
extern u32 func_020307B0(void *p);
extern void func_0202B230(u8 *p);
extern void func_0202B2BC(u8 *p);
struct Node *func_0202B1AC(u32 a, u32 heapId);
void func_0202B1EC(void *ptr);
void func_0202B1F4(u8 *a0);
void func_0202B1FC(u8 *a0);
void func_0202B204(u8 *a0);
void func_0202B20C(u8 *p);
void func_0202B224(u8 *p);





/*
 * Allocates a 0x18-byte node with the allocator entry point, zeroes its
 * first two words, stores the first argument at +8, and copies a 12-byte
 * record from func_02012AA0(first) into +0xc.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B1AC.c \
 *       --func func_0202B1AC --addr 0x0202B1AC --thumb --cc 1.1p1
 */
struct Node *func_0202B1AC(u32 a, u32 heapId)
{
    struct Node *p = (struct Node *)func_02030734(heapId, 0x18, 0,
                                                  (const void *)0x020A7708, 0x4a);
    const Copy *s;

    p->f0 = 0;
    p->f4 = 0;
    p->f8 = a;

    s = (const Copy *)func_02012AA0((struct Rec44 *)a);
    p->body = *s;
    return p;
}





void func_0202B1EC(void *ptr)
{
    func_020307B0(ptr);
}




/*
 * A bare tail-call thunk to func_0202B230.
 *
 * Closed by the `matched` class: 0x0202B230 was filed as an EXACT entry in this wave.
 */
void func_0202B1F4(u8 *a0)
{
    func_0202B230(a0);
}



/*
 * A bare tail-call thunk to func_0202B20C.
 */
void func_0202B1FC(u8 *a0)
{
    func_0202B20C(a0);
}



void func_0202B204(u8 *a0)
{
    func_0202B224(a0);
}



/*
 * When the object is idle, marks it started, clears its +4 value and
 * refreshes it through func_0202B2BC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B20C.c \
 *       --func func_0202B20C --addr 0x0202B20C --thumb --cc 1.1p1
 */
void func_0202B20C(u8 *p)
{
    if (((struct Obj08802 *)p)->f0 == 0) {
        ((struct Obj08802 *)p)->f0 = 1;
        ((struct Obj08802 *)p)->f4 = 0;
        func_0202B2BC(p);
    }
}



/*
 * Clears the object's state word when it is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B224.c \
 *       --func func_0202B224 --addr 0x0202B224 --thumb --cc 1.1p1
 */
void func_0202B224(u8 *p)
{
    if (((struct Obj11313 *)p)->f0 != 0) {
        ((struct Obj11313 *)p)->f0 = 0;
    }
}
