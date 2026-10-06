/*
 * file:     wih_dwc_p05.c
 * unit:     yes
 * function: func_020107FC, func_02010848, func_02010864, func_02010884, func_02010888, func_0201088C, func_020108C4, func_02010904, func_02010934, func_0201093C, func_02010964, func_02010994, func_020109B8, func_020109E0, func_02010A04, func_02010A3C, func_02010A5C, func_02010AC4
 * address:  0x020107FC
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
 *   func_0203CD98     0x0203CD98  arm
 *   func_0203D798     0x0203D798  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   func_0203CF10     0x0203CF10  arm
 *   func_02177B80     0x02177B80  thumb  ov014
 *   sub_0202E8D8      0x0202E8D8  thumb
 *   g_021461E0     0x021461E0  data
 *   s0x020A725C       0x020A725C  data
 *   func_02030734     0x02030734  arm
 *   func_020399A8     0x020399A8  arm
 *   func_02039C68     0x02039C68  arm
 *   func_020307B0     0x020307B0  arm
 *   func_0200FB24     0x0200FB24  thumb
 *   func_02012E08     0x02012E08  thumb
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   sub_020124F4   0x020124F4  thumb
 *   sub_02012EBC   0x02012EBC  thumb
 *   sub_02009448   0x02009448  thumb
 *   sub_020092EC   0x020092EC  thumb
 *   ov115_id       0x00000073  data  a1
 *   ov123_id       0x0000007B  data  a1
 *   d_021D6338     0x021D6338  data  ov115
 *   d_021DA9A8     0x021DA9A8  data  ov123
 *   d_021D654C     0x021D654C  data  ov115
 *   func_020312CC  0x020312CC  arm
 *   func_0200F7B8  0x0200F7B8  thumb
 */
#include "../../matched/include/Obj11819.h"
#include "../../matched/include/Obj15612.h"
#include "../../matched/include/Obj15613.h"
#include "../../matched/include/Obj11240.h"
#include "../../matched/include/Obj11241.h"
#include "../../matched/include/Obj06855.h"
#include "../../matched/include/Obj04833.h"
#include "../../matched/include/Obj00562.h"

struct Entry;
struct Link;
struct Obj0203159C;
struct Big;
struct Sub02009448Obj;
struct Sub02009210Obj;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

struct Sub0201088CObj {
    u32 f0;         /* +0x00 */
    u32 f4;         /* +0x04 */
    void (*f8)(struct Sub0201088CObj *p);   /* +0x08 */
    u32 f0c;        /* +0x0C */
    u32 f10;        /* +0x10 */
};

typedef signed int    s32;

extern int  func_0203CD98(void);
extern void *func_0203D798(void);
extern void OS_GetMacAddress(u8 *mac);
extern u32 func_0203CF10(u32 a);
extern u8 func_02177B80(int i);
extern int sub_0202E8D8(char *a0, int a1, char *a2);
extern void *func_02030734(u32 a, u32 b, int c, const char *file, u16 line);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *ctx, u32 id, u32 size);
extern u32 func_020307B0(void *p);
extern u32  func_0200FB24(void);
extern void func_02012E08(char *p);
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern int func_02012DAC(int a0);
extern int  func_02012DD0(u8 *p);
extern u32  func_020056EC(u32 v);
void func_0201093C(u8 *p);
void func_02010964(u8 *p);
extern void  func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  func_02082BCC(void *dst, int val, unsigned n);
extern void *sub_020124F4(u16 heap);
extern void *sub_02012EBC(struct Big *p);
extern struct Sub02009448Obj *sub_02009448(void *sys);
extern u8 sub_020092EC(const struct Sub02009210Obj *obj);
extern void func_020312CC(u32 ovl, u32 proc, u32 arg);
extern u32 func_0200F7B8(u32 a0);
int sub_020107FC(void *key);
u16 func_02010848(void);
void func_02010864(u32 v);
void func_02010884(void);
void func_02010888(u8 *p, u32 v);
void *func_0201088C(u32 heap, u32 a1);
void *func_020108C4(u32 heap, u32 a1, u32 a2, u32 a3);
void func_02010994(u8 *p);
void func_020109B8(u8 *p);
void func_020109E0(u8 *p);
void func_02010A04(u8 *p);
void func_02010A3C(u8 *p);
int sub_02010A5C(void *a0);
int func_02010AC4(u32 a0, u32 a1, u32 a2, u8 *ctx);
extern u8 *g_021461E0;
extern u8   s0x020A725C;
extern u8 ov115_id[];
extern u8 ov123_id[];
extern u8 d_021D6338[];
extern u8 d_021DA9A8[];
extern u8 d_021D654C[];




/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 *           unlabelled Thumb function in ov014 (wih.c); asm/overlays/ov014.s
 *           prints 0x02177B80 as .word data (0x680B4909, `ldr r1,[pc,#0x24];
 *           ldr r3,[r1]`...), and this call is the only branch to it in the
 *           image.  SEED REQUEST: `ov014 0x02177B80 thumb`, evidence the bl at
 *           arm9 0x0201081A.  Once labelled, `sole-ref/code` (or `label`, if a
 *           second referrer turns up in ov014) can carry the site.
 *           The MATCH is also starred: the listing extent runs to 0x02010888
 *           over three unlabelled leaves, filed as src/matched/unit_02010848.c.
 *
 * wih_dwc.c: find the first of 16 slots whose ov014 state is 0x20 and whose
 * func_0203CF10 record func_0202E8D8 accepts against (key, own MAC address);
 * -1 when none, or when func_0203CD98 reports the layer inactive.  The
 * closing lever over docs/notes/pkt_020107CC.c.txt was the wrapping `if`
 * instead of an early return (the original's guard branches forward over
 * the whole body to the shared -1 exit) plus the two loop tests joined by &&.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020107FC.c \
 *       --func sub_020107FC --addr 0x020107FC --thumb
 */
int sub_020107FC(void *key)
{
    u8 mac[8];
    int i;

    if (func_0203CD98() != 0) {
        func_0203D798();
        OS_GetMacAddress(mac);
        for (i = 0; i < 0x10; i++) {
            if (func_02177B80(i) == 0x20 && sub_0202E8D8((void *)func_0203CF10(i), (int)key, (char *)mac) != 0) {
                return i;
            }
        }
    }
    return -1;
}




/*
 * wih_dwc.c: three unlabelled leaves after sub_020107FC (whose listing extent
 * runs to 0x02010888 because none of them saves lr): a getter of the halfword
 * at +0x312 of the object behind 0x021461E0 (0 when there is none), a raising
 * setter of the halfword at +0x314 (only upward, and only below 4; the first
 * compare is signed, the bound unsigned, so the parameter is u32 and the
 * field is compared as int), and an empty function.  func_02010888
 * (src/matched/func_02010888.c) follows.
 *
 * SEED REQUEST for the integrator: arm9 0x02010848 thumb, 0x02010864 thumb,
 * 0x02010884 thumb (witness: this unit).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02010848.c \
 *       --addr 0x02010848 --thumb
 */
u16 func_02010848(void)
{
    if (g_021461E0 != 0)
        return *(u16 *)(g_021461E0 + 0x312);
    return 0;
}




/*
 * wih_dwc.c: three unlabelled leaves after sub_020107FC (whose listing extent
 * runs to 0x02010888 because none of them saves lr): a getter of the halfword
 * at +0x312 of the object behind 0x021461E0 (0 when there is none), a raising
 * setter of the halfword at +0x314 (only upward, and only below 4; the first
 * compare is signed, the bound unsigned, so the parameter is u32 and the
 * field is compared as int), and an empty function.  func_02010888
 * (src/matched/func_02010888.c) follows.
 *
 * SEED REQUEST for the integrator: arm9 0x02010848 thumb, 0x02010864 thumb,
 * 0x02010884 thumb (witness: this unit).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02010848.c \
 *       --addr 0x02010848 --thumb
 */
void func_02010864(u32 v)
{
    u8 *o = g_021461E0;

    if (o != 0 && (int)((struct Obj11819 *)o)->f314 < (int)v && v < 4)
        ((struct Obj11819 *)o)->f314 = v;
}




/*
 * wih_dwc.c: three unlabelled leaves after sub_020107FC (whose listing extent
 * runs to 0x02010888 because none of them saves lr): a getter of the halfword
 * at +0x312 of the object behind 0x021461E0 (0 when there is none), a raising
 * setter of the halfword at +0x314 (only upward, and only below 4; the first
 * compare is signed, the bound unsigned, so the parameter is u32 and the
 * field is compared as int), and an empty function.  func_02010888
 * (src/matched/func_02010888.c) follows.
 *
 * SEED REQUEST for the integrator: arm9 0x02010848 thumb, 0x02010864 thumb,
 * 0x02010884 thumb (witness: this unit).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02010848.c \
 *       --addr 0x02010848 --thumb
 */
void func_02010884(void)
{
}




/*
 * Stores the value at the object's +8 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010888.c \
 *       --func func_02010888 --addr 0x02010888 --thumb --cc 1.1p1
 */
void func_02010888(u8 *p, u32 v)
{
    ((struct Obj15612 *)p)->f8 = v;
}




/*
 * The whole range 0x0201088C..0x0201093C: two constructors for the same
 * 0x14-byte object, its destructor-or-poll, and the eight-byte tail-call
 * stub that sits between them and func_0201093C.
 *
 *   func_0201088C   allocator + one stored field (+0x0C)
 *   func_020108C4   allocator + three stored fields (+0x00, +0x04, +0x0C)
 *   func_02010904   fire the +0x08 callback, then two liveness tests
 *   (0x02010934)    `ldr r3, [pc, #0]; bx r3; .word func_020307B0`
 *
 * The stub is a real function: `ov119` at 0x021E0C5C and `ov137` at
 * 0x021DF696 both `bl` it.  It carries no label because it has no prologue
 * (disasm.py only labels a function that saves lr), so it is written here as
 * the tail call it is - a void function whose body is one call to the ARM
 * function 0x020307B0 with the object passed through in r0, which is what
 * puts the pool word and the `bx r3` there and what makes the unit's extent
 * end at 0x0201093C.  Since then seeded as a start in
 * layout/function_starts.txt (both callers set r0 to the object at +0xEF8 /
 * their own field before the bl), so the listing labels it func_02010934.
 *
 * Both constructors end with the same two statements: the SDK debug
 * allocator func_02030734(heap, 0x14, 1, "net_save.c", line) - 0x020A725C is
 * two bytes into the "net_save.c" string at 0x020A7258, so the file anchor is
 * net_save.c - and then func_02010888(p, func_0201093C), which stores the
 * callback into +0x08.  The two pool words per constructor are the file
 * string and that callback address with its Thumb bit, 0x0201093D.
 *
 * func_02010904 calls the callback with the object in r0, then tests
 * func_0200FB24()'s result.  That call is left with no argument of its own:
 * r0 still holds whatever the callback returned, which is what the original
 * does and what a no-argument call in the source produces.  The two `return
 * 1` arms are written separately (two `movs r0, #1` epilogues in the
 * original) and the +0x08 load is re-read after the calls.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201088C.c \
 *       --addr 0x0201088C --thumb
 */
void *func_0201088C(u32 heap, u32 a1)
{
    struct Sub0201088CObj *p;

    p = func_02030734(heap, 0x14, 1, (const char *)&s0x020A725C, 0x75);
    p->f0c = a1;
    func_02039C68((struct Link *)func_020399A8(), 0x71, 8);
    func_02010888((u8 *)p, (u32)func_0201093C);
    return p;
}




/*
 * The whole range 0x0201088C..0x0201093C: two constructors for the same
 * 0x14-byte object, its destructor-or-poll, and the eight-byte tail-call
 * stub that sits between them and func_0201093C.
 *
 *   func_0201088C   allocator + one stored field (+0x0C)
 *   func_020108C4   allocator + three stored fields (+0x00, +0x04, +0x0C)
 *   func_02010904   fire the +0x08 callback, then two liveness tests
 *   (0x02010934)    `ldr r3, [pc, #0]; bx r3; .word func_020307B0`
 *
 * The stub is a real function: `ov119` at 0x021E0C5C and `ov137` at
 * 0x021DF696 both `bl` it.  It carries no label because it has no prologue
 * (disasm.py only labels a function that saves lr), so it is written here as
 * the tail call it is - a void function whose body is one call to the ARM
 * function 0x020307B0 with the object passed through in r0, which is what
 * puts the pool word and the `bx r3` there and what makes the unit's extent
 * end at 0x0201093C.  Since then seeded as a start in
 * layout/function_starts.txt (both callers set r0 to the object at +0xEF8 /
 * their own field before the bl), so the listing labels it func_02010934.
 *
 * Both constructors end with the same two statements: the SDK debug
 * allocator func_02030734(heap, 0x14, 1, "net_save.c", line) - 0x020A725C is
 * two bytes into the "net_save.c" string at 0x020A7258, so the file anchor is
 * net_save.c - and then func_02010888(p, func_0201093C), which stores the
 * callback into +0x08.  The two pool words per constructor are the file
 * string and that callback address with its Thumb bit, 0x0201093D.
 *
 * func_02010904 calls the callback with the object in r0, then tests
 * func_0200FB24()'s result.  That call is left with no argument of its own:
 * r0 still holds whatever the callback returned, which is what the original
 * does and what a no-argument call in the source produces.  The two `return
 * 1` arms are written separately (two `movs r0, #1` epilogues in the
 * original) and the +0x08 load is re-read after the calls.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201088C.c \
 *       --addr 0x0201088C --thumb
 */
void *func_020108C4(u32 heap, u32 a1, u32 a2, u32 a3)
{
    struct Sub0201088CObj *p;

    p = func_02030734(heap, 0x14, 1, (const char *)&s0x020A725C, 0x87);
    p->f0 = a2;
    p->f4 = a3;
    p->f0c = a1;
    func_02039C68((struct Link *)func_020399A8(), 0x71, 8);
    func_02010888((u8 *)p, (u32)func_0201093C);
    return p;
}




/*
 * The whole range 0x0201088C..0x0201093C: two constructors for the same
 * 0x14-byte object, its destructor-or-poll, and the eight-byte tail-call
 * stub that sits between them and func_0201093C.
 *
 *   func_0201088C   allocator + one stored field (+0x0C)
 *   func_020108C4   allocator + three stored fields (+0x00, +0x04, +0x0C)
 *   func_02010904   fire the +0x08 callback, then two liveness tests
 *   (0x02010934)    `ldr r3, [pc, #0]; bx r3; .word func_020307B0`
 *
 * The stub is a real function: `ov119` at 0x021E0C5C and `ov137` at
 * 0x021DF696 both `bl` it.  It carries no label because it has no prologue
 * (disasm.py only labels a function that saves lr), so it is written here as
 * the tail call it is - a void function whose body is one call to the ARM
 * function 0x020307B0 with the object passed through in r0, which is what
 * puts the pool word and the `bx r3` there and what makes the unit's extent
 * end at 0x0201093C.  Since then seeded as a start in
 * layout/function_starts.txt (both callers set r0 to the object at +0xEF8 /
 * their own field before the bl), so the listing labels it func_02010934.
 *
 * Both constructors end with the same two statements: the SDK debug
 * allocator func_02030734(heap, 0x14, 1, "net_save.c", line) - 0x020A725C is
 * two bytes into the "net_save.c" string at 0x020A7258, so the file anchor is
 * net_save.c - and then func_02010888(p, func_0201093C), which stores the
 * callback into +0x08.  The two pool words per constructor are the file
 * string and that callback address with its Thumb bit, 0x0201093D.
 *
 * func_02010904 calls the callback with the object in r0, then tests
 * func_0200FB24()'s result.  That call is left with no argument of its own:
 * r0 still holds whatever the callback returned, which is what the original
 * does and what a no-argument call in the source produces.  The two `return
 * 1` arms are written separately (two `movs r0, #1` epilogues in the
 * original) and the +0x08 load is re-read after the calls.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201088C.c \
 *       --addr 0x0201088C --thumb
 */
u32 func_02010904(struct Sub0201088CObj *p)
{
    if (p->f8 != 0)
        p->f8(p);
    if (func_0200FB24() != 0) {
        if (p->f0c != 0)
            func_02012E08((char *)p->f0c);
        return 1;
    }
    if (p->f8 == 0)
        return 1;
    return 0;
}

/*
 * The whole range 0x0201088C..0x0201093C: two constructors for the same
 * 0x14-byte object, its destructor-or-poll, and the eight-byte tail-call
 * stub that sits between them and func_0201093C.
 *
 *   func_0201088C   allocator + one stored field (+0x0C)
 *   func_020108C4   allocator + three stored fields (+0x00, +0x04, +0x0C)
 *   func_02010904   fire the +0x08 callback, then two liveness tests
 *   (0x02010934)    `ldr r3, [pc, #0]; bx r3; .word func_020307B0`
 *
 * The stub is a real function: `ov119` at 0x021E0C5C and `ov137` at
 * 0x021DF696 both `bl` it.  It carries no label because it has no prologue
 * (disasm.py only labels a function that saves lr), so it is written here as
 * the tail call it is - a void function whose body is one call to the ARM
 * function 0x020307B0 with the object passed through in r0, which is what
 * puts the pool word and the `bx r3` there and what makes the unit's extent
 * end at 0x0201093C.  Since then seeded as a start in
 * layout/function_starts.txt (both callers set r0 to the object at +0xEF8 /
 * their own field before the bl), so the listing labels it func_02010934.
 *
 * Both constructors end with the same two statements: the SDK debug
 * allocator func_02030734(heap, 0x14, 1, "net_save.c", line) - 0x020A725C is
 * two bytes into the "net_save.c" string at 0x020A7258, so the file anchor is
 * net_save.c - and then func_02010888(p, func_0201093C), which stores the
 * callback into +0x08.  The two pool words per constructor are the file
 * string and that callback address with its Thumb bit, 0x0201093D.
 *
 * func_02010904 calls the callback with the object in r0, then tests
 * func_0200FB24()'s result.  That call is left with no argument of its own:
 * r0 still holds whatever the callback returned, which is what the original
 * does and what a no-argument call in the source produces.  The two `return
 * 1` arms are written separately (two `movs r0, #1` epilogues in the
 * original) and the +0x08 load is re-read after the calls.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201088C.c \
 *       --addr 0x0201088C --thumb
 */
void func_02010934(struct Sub0201088CObj *p)
{
    func_020307B0(p);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201093C.c \
 *       --func func_0201093C --addr 0x0201093C --thumb --cc 1.1p1
 */
void func_0201093C(u8 *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x71, 8) != 0) {
        func_02012DAC(((struct Obj15613 *)p)->fC);
        func_02010888(p, (u32)func_02010964);
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010964.c \
 *       --func func_02010964 --addr 0x02010964 --thumb --cc 1.1p1
 */
void func_02010964(u8 *p)
{
    if (func_02012DD0((u8 *)((struct Obj11240 *)p)->fC) == 1) {
        func_02039C68((struct Link *)func_020399A8(), 0x72, 8);
        ((struct Obj11240 *)p)->f10 = func_020056EC(0x3c);
        func_02010888(p, (u32)func_02010994);
    }
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010994.c \
 *       --func func_02010994 --addr 0x02010994 --thumb --cc 1.1p1
 */
void func_02010994(u8 *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x72, 8) != 0) {
        func_02010888(p, (u32)func_020109B8);
    }
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020109B8.c \
 *       --func func_020109B8 --addr 0x020109B8 --thumb --cc 1.1p1
 */
void func_020109B8(u8 *p)
{
    s32 v = (s32)((struct Obj11241 *)p)->f10 - 1;

    ((struct Obj11241 *)p)->f10 = (u32)v;
    if (v < 0) {
        func_02039C68((struct Link *)func_020399A8(), 0x73, 8);
        func_02010888(p, (u32)func_020109E0);
    }
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020109E0.c \
 *       --func func_020109E0 --addr 0x020109E0 --thumb --cc 1.1p1
 */
void func_020109E0(u8 *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x73, 8) != 0) {
        func_02010888(p, (u32)func_02010A04);
    }
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010A04.c \
 *       --func func_02010A04 --addr 0x02010A04 --thumb --cc 1.1p1
 */
void func_02010A04(u8 *p)
{
    if (((struct Obj06855 *)p)->f0 != 0) {
        ((void (*)(u32)) * (u32 *)p)(((struct Obj06855 *)p)->f4);
    }
    if (func_02012DD0(*(u8 * *)&((struct Obj06855 *)p)->fC) == 2) {
        *(u32 *)&((struct Obj06855 *)p)->fC = 0;
        func_02039C68((struct Link *)func_020399A8(), 0x74, 8);
        func_02010888(p, (u32)func_02010A3C);
    }
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010A3C.c \
 *       --func func_02010A3C --addr 0x02010A3C --thumb --cc 1.1p1
 */
void func_02010A3C(u8 *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x74, 8) != 0) {
        func_02010888(p, 0);
    }
}



int sub_02010A5C(void *a0)
{
    u8 *p;
    void *sys;

    func_0203064C(1, 0x67, 0x78000);
    p = func_0203159C(a0, 0x1d8, 0x67);
    func_02082BCC(p, 0, 0x1d8);
    ((struct Obj04833 *)p)->f1D0 = 0x67;
    sys = sub_020124F4(0x67);
    ((struct Obj04833 *)p)->f44 = sys;
    if (sub_020092EC((const struct Sub02009210Obj *)sub_02009448(sub_02012EBC(sys))) != 0) {
        ((struct Obj04833 *)p)->f1D4 = 1;
        ((struct Obj04833 *)p)->f54 = 1;
    } else {
        ((struct Obj04833 *)p)->f1D4 = 0;
        ((struct Obj04833 *)p)->f54 = 0;
    }
    return 1;
}



/*
 * history:  was MATCH on evidence only (every concrete byte matched).  Wave 17:
 *           the pooled overlay ids 0x73 / 0x7B (ov115_id, ov123_id) now
 *           resolve as `overlay_id` (id argument of func_020312CC).  Two
 *           ABS32 sites are left, the overlay-resident proc pointers
 *           0x021D6338 / 0x021D654C, whose only other pool words sit in
 *           func_02010C34's pool (0x02010D84..), which disasm.py prints as
 *           Thumb code, so the literal index misses them.  Seeding those
 *           pools as .word, or a matched referrer, would close both.
 *           Seed round 10: both words are ov115 proc tables (three Thumb
 *           function pointers each, 0x021D6338 -> func_021D4BFC/4CE4/4D10,
 *           0x021D654C -> func_021D603C/6104/60D4), loaded with overlay id
 *           0x73 = ov115, not ov021 (docs/sessions/2026-09-23/reports/
 *           wave17_evidence.md).  ov115 declares both starts in
 *           layout/data_objects.txt and the symbols lines carry the ov115
 *           token.  0x021D654C resolves as sole-ref/data (ov115 is the only
 *           overlay with a start there).  0x021D6338 resolves as
 *           sole-ref/self on the ov115 hint; ov021's listing also starts a
 *           block there, so sole-ref/data refuses the contested hint, and the
 *           choice rests on the hint plus the overlay_id 0x73 site in this
 *           same function.  EXACT, seed round 10.
 * evidence: d_021DA9A8 lies in the windows of ov016, ov021, ov123, ov125
 *           and ov175, so the ov123 hint needs outside support.  Case 1
 *           passes ov123_id (0x7B, attested `overlay_id`) and this pointer
 *           in one func_020312CC call; func_020314F4 -> func_02031538 stores
 *           the id at Proc+4 and the pointer at Proc+0 (ProcData), and
 *           func_020315F0 loads overlay Proc+4 (func_02034AC4) before it
 *           calls any ProcData callback.  So ov123 is resident whenever the
 *           pointer is dereferenced.  Independently, ov123's bytes at
 *           0x021DA9A8 are three Thumb pointers 0x021DA479/0x021DA54D/
 *           0x021DA5D1, each a func_ label in ov123's own listing, while
 *           ov125 has bss there and ov016/ov021/ov175 hold non-pointer
 *           words.  With the hint the site attests as `sole-ref` in ov123.
 *
 * The net_save.c save task's per-frame step (the task record of
 * sub_02010A5C; state word at +0x1D4): case 0 starts overlay 0x73's proc
 * 0x021D6338 on the record, case 1 starts overlay 0x7B's proc on +0x48
 * unless +0x1C says finished, case 2 hands off to func_0200F7B8(0), case 3
 * restarts overlay 0x73 with proc 0x021D654C on +0x28 or ends the task.
 * Wave 13: the earlier DIFF read both small pool words as distinct symbols
 * and the size argument as 0x1A8; they are the arguments (0x73, proc, arg).
 */
int func_02010AC4(u32 a0, u32 a1, u32 a2, u8 *ctx)
{
    switch (((struct Obj00562 *)ctx)->f1D4) {
    case 0:
        ((struct Obj00562 *)ctx)->f0 = ((struct Obj00562 *)ctx)->f44;
        ((struct Obj00562 *)ctx)->f4 = 0;
        ((struct Obj00562 *)ctx)->f8 = 1;
        ((struct Obj00562 *)ctx)->fC = 0x32;
        *(u8 * *)&((struct Obj00562 *)ctx)->f10 = ctx + 0x5c;
        func_020312CC((u32)ov115_id, (u32)d_021D6338, (u32)ctx);
        ((struct Obj00562 *)ctx)->f1D4 += 1;
        break;
    case 1:
        if (((struct Obj00562 *)ctx)->f1C == 1) {
            ((struct Obj00562 *)ctx)->f1D4 = 4;
            break;
        }
        ((struct Obj00562 *)ctx)->f48 = ((struct Obj00562 *)ctx)->f44;
        ((struct Obj00562 *)ctx)->f50 = ((struct Obj00562 *)ctx)->f1D0;
        *(u8 * *)&((struct Obj00562 *)ctx)->f4C = ctx + 0x5c;
        func_020312CC((u32)ov123_id, (u32)d_021DA9A8, (u32)(ctx + 0x48));
        ((struct Obj00562 *)ctx)->f1D4 += 1;
        break;
    case 2:
        if (((struct Obj00562 *)ctx)->f54 == 1) {
            ((struct Obj00562 *)ctx)->f1D4 = 4;
            break;
        }
        func_0200F7B8(0);
        ((struct Obj00562 *)ctx)->f1D4 += 1;
        break;
    case 3:
        if (func_0203CD98() == 0 || ((struct Obj00562 *)ctx)->f58 == 1) {
            ((struct Obj00562 *)ctx)->f14 = 1;
            ((struct Obj00562 *)ctx)->f1D4 = 0;
            break;
        }
        ((struct Obj00562 *)ctx)->f28 = ((struct Obj00562 *)ctx)->f44;
        ((struct Obj00562 *)ctx)->f2C = 0;
        ((struct Obj00562 *)ctx)->f30 = 1;
        func_020312CC((u32)ov115_id, (u32)d_021D654C, (u32)(ctx + 0x28));
        ((struct Obj00562 *)ctx)->f1D4 += 1;
        break;
    default:
        return 1;
    }
    return 0;
}
