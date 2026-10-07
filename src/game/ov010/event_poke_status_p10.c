/*
 * file:     event_poke_status_p10.c
 * unit:     yes
 * function: func_02159D68, func_02159D84, func_02159DC8, func_02159DCC, func_02159DEC, func_02159E00
 * address:  0x02159D68
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   func_020493D4  0x020493D4  arm
 *   func_02159E8C  0x02159E8C  thumb  ov010
 *   d_021728BC  0x021728BC  data
 *   func_0204944C  0x0204944C  arm
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02159E60  0x02159E60  thumb  ov010
 */
#include "../../matched/include/Obj17651.h"
#include "../../matched/include/Obj17652.h"
#include "../../matched/include/Obj07280.h"

struct ArcFile;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Obj {
    u16 f00;
    u16 pad02;
    void *f04;
    u32 f08;
    u8 f0c[1];
} Obj;

typedef signed short   s16;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_02159E8C(u8 *out, int obj);
extern void func_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void func_02049238(void *arc);
extern int func_020307B0();
extern int func_02159E60(int);
int func_02159D68(int x);
Obj *func_02159D84(int a, int b);
u32 func_02159DC8(void *p);
u32 func_02159DCC(u8 *p, int n);
int func_02159DEC(int a0);
int func_02159E00(u8 *a, u32 *b, u32 *c);
extern const char d_021728BC[];

/*
 * extent: two bytes of zero alignment padding at 0x02159D82.
 */
int func_02159D68(int x)
{
    return x / 4096 / 16 / 32;
}


Obj *func_02159D84(int a, int b)
{
    Obj *p = func_02030734(a, 0x2c, 1, d_021728BC, 0x77);
    p->f00 = a;
    p->f04 = func_020490F4(10, a);
    p->f08 = ((u32)func_020493D4(p->f04, 0) << 16) >> 20;
    func_02159E8C(p->f0c, b);
    return p;
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Word-field getter/setter for the overlay's object layout: a plain load or store at the field offset with a pool-free leaf body.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159DC8.c \
 *       --func func_02159DC8 --addr 0x02159DC8 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02159DC8(void *p) { return ((struct Obj17651 *)p)->f8; }


/*
 * Reads record n (16 bytes) from the archive at p+4 into p+0x1a through
 * func_0204944C, then returns the halfword read.
 */
u32 func_02159DCC(u8 *p, int n)
{
    func_0204944C(*(struct ArcFile **)(p + 4), 0, n << 4, 0x10, p + 0x1a);
    return *(u16 *)(p + 0x1a);
}


int func_02159DEC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj17652 *)t4)->f4;
    func_02049238((void *)a0);
loc_02159DF6:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_02159DFC:
    return a0;}


int func_02159E00(u8 *a, u32 *b, u32 *c)
{
    u8 *r4 = a + 0x1a;
    u8 *r5 = a + 0xc;
    int sel = r4[3];
    u32 old = ((struct Obj07280 *)r4)->f4;
    int idx;
    u32 cur;
    switch (sel) {
    case 0:
        idx = r5[0];
        break;
    case 1:
        idx = r5[1];
        break;
    case 2:
        idx = r5[2];
        break;
    default:
        idx = (r5 + func_02159E60(sel))[3];
        break;
    }
    cur = *(u16 *)(r4 + idx * 2 + 4);
    *b = old;
    *c = cur;
    if (old == cur)
        return 0;
    if (r4[2] == 1)
        return 2;
    if (r4[2] == 0)
        return 1;
    return 0;
}
