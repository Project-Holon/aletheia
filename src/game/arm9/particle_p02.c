/*
 * file:     particle_p02.c
 * unit:     yes
 * function: func_02050084, func_02050088, func_020500A0, func_020500B8, func_020500F0, func_02050238, func_02050278
 * address:  0x02050084
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02033CA8  0x02033CA8  arm
 *   func_0204EF58  0x0204EF58  arm
 *   func_0204F10C  0x0204F10C  arm
 *   func_0204F150  0x0204F150  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_0203422C  0x0203422C  arm
 */
#include "../../matched/include/Obj11450.h"
#include "../../matched/include/Obj02611.h"
#include "../../matched/include/Obj02015.h"
#include "../../matched/include/Obj08867.h"

struct AreaMan;
struct Tagged;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

struct BbActSlot { u16 id; u16 pad; u32 val; };

struct BbActRec { u32 f00; u8 b4; u8 b5; u8 b6; u8 b7; u32 type; };

struct BbActSys_02050084 {
    u16 f00;
    u16 f02;
    void *f04;
    u32 f08;
    struct BbActSlot *f0C;
    u16 f10;
    u16 f12;
    u32 f14;
};

typedef signed int     s32;

struct S8 {
    u16 h;
    u16 pad;
    u32 w;
};

struct BbActSys_02050238 {
    u16 f00;
    u16 f02;
    void *f04;
    u32 f08;
    struct BbActSlot *f0C;
    u16 f10;
    u16 f12;
    void *f14;
};

extern s32 func_02033CA8(struct AreaMan *p, u32 len);
extern u16  func_0204EF58(void *board, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_0204F10C(void *board, u32 id);
extern void func_0204F150(u8 *a0, int i);
extern void func_02046EFC(struct Tagged *p);
extern void func_0203422C(struct AreaMan *p, u32 start, s32 len);
void func_02050084(void);
void func_02050088(int p0);
void func_020500A0(int p0);
void func_020500B8(u32 *p);
u32 func_02050238(void *p, u32 b, u32 c);


/*
 * Four-byte empty leaf: `bx lr`, no prologue.  The billboard-actor family's
 * no-op hook, called in the same slot as the other per-entry callbacks.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050084.c \
 *       --func func_02050084 --addr 0x02050084 --cc 1.1p1 --arm
 */
void func_02050084(void)
{
}




void func_02050088(int p0){ ((struct Obj11450 *)p0)->f0 = (unsigned short)0xFFFF; ((struct Obj11450 *)p0)->f4 = (int)0; }




void func_020500A0(int p0){ ((struct Obj02611 *)p0)->f10 = (unsigned short)0; ((struct Obj02611 *)p0)->f12 = (unsigned short)0; ((struct Obj02611 *)p0)->f14 = (unsigned short)0; ((struct Obj02611 *)p0)->f1C = (unsigned short)0; }




/*
 * Second of the three 0x0204F6xx-series object initialisers; the eight bytes
 * of literal pool at 0x020500EC (0x0000FFFF) are this function's own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020500B8.c \
 *       --func func_020500B8 --addr 0x020500B8 --cc 1.1p1 --arm
 */
void func_020500B8(u32 *p)
{
    p[0] = 0xFFFF;
    p[2] = 0;
    ((struct Obj02015 *)p)->fC = 0;
    ((struct Obj02015 *)p)->fE = 0;
    func_020500A0((int)p);
    p[6] = 0;
    p[8] = 0;
    p[9] = 0;
}




/*
 * billboard_act.c: take n slot indices from the pool at +0x14 and fill one
 * slot record per request (0: board slot, 1: board slot plus func_0204F10C,
 * 2: an external payload word with the 0xFFFF sentinel id).  The 28-byte
 * scheduling wall of the earlier notes was the missing `const` on the
 * request array (its byte loads then batch ahead of the outgoing-argument
 * stores, and case 2's payload load hoists above the sentinel store); with
 * it the plain subscript o->f0C[base + i] and literal zeros are exact.
 */
u16 func_020500F0(struct BbActSys_02050084 *o, const struct BbActRec *recs, u32 n)
{
    int base;
    u32 i;

    base = func_02033CA8((struct AreaMan *)o->f14, n);
    for (i = 0; i < n; i++) {
        const struct BbActRec *e = &recs[i];
        u16 id;
        switch (e->type) {
        case 0:
            o->f0C[base + i].id = func_0204EF58(o->f04, e->f00, e->b4, e->b5, e->b6, e->b7);
            o->f0C[base + i].val = 0;
            break;
        case 1:
            id = func_0204EF58(o->f04, e->f00, e->b4, e->b5, e->b6, e->b7);
            func_0204F10C(o->f04, id);
            o->f0C[base + i].id = id;
            o->f0C[base + i].val = 0;
            break;
        case 2:
            o->f0C[base + i].id = 0xFFFF;
            o->f0C[base + i].val = e->f00;
            break;
        }
    }
    return base;
}



/*
 * Appends one {u16, u32} record (8 bytes, id in the low half) to the array
 * the caller's object keeps at +12, at the slot func_02033CA8 hands back for
 * the pool at +20; the return is the slot narrowed to u16.
 *
 * The four bytes that cost three attempts are the first store's register
 * pairing: the pointer form `*(u16 *)(*(u32 *)((char *)p + 12) + idx * 8)`
 * compiles the same two instructions as the original but allocates them the
 * other way round (`ldr r1,[r6,#12]; lsl r2,r0,#3; strh r5,[r1,r2]` against
 * the original's r2/r1), a whole-function DIFF at +001C.  Written as an
 * array subscript on an 8-byte struct element,
 * `((struct S8 *)*(u32 *)((char *)p + 12))[idx].h`, it comes out EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050238.c \
 *       --func func_02050238 --addr 0x02050238 --cc 1.1p1 --arm
 *   EXACT, 64 bytes, 1 relocation site, resolved [label].
 */
u32 func_02050238(void *p, u32 b, u32 c)
{
    int idx = func_02033CA8((struct AreaMan *)(((struct Obj08867 *)p)->f14), 1);

    ((struct S8 *)((struct Obj08867 *)p)->fC)[idx].h = b;
    ((struct S8 *)((struct Obj08867 *)p)->fC)[idx].w = c;
    return (u16)idx;
}



/*
 * billboard_act.c: release `count` slot records from `first`: the board
 * record through func_0204F150(board, id) when the id is live, the payload
 * through func_02046EFC when nonzero, then reset the record and return the
 * index range to the pool.  func_0204F150 takes TWO arguments (the loaded
 * id is the r1 the image compares); the rest is plain subscripts.
 */
void func_02050278(struct BbActSys_02050238 *o, u32 first, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++) {
        if (o->f0C[first + i].id != 0xFFFF) {
            func_0204F150(o->f04, o->f0C[first + i].id);
        }
        if (o->f0C[first + i].val != 0) {
            func_02046EFC((struct Tagged *)o->f0C[first + i].val);
        }
        func_02050088((int)(&o->f0C[first + i]));
    }
    func_0203422C(o->f14, first, count);
}
