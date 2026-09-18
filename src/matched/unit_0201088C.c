/*
 * unit:     yes
 * function: func_0201088C
 * address:  0x0201088C
 * packet:   pkt_0201088C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   s0x020A725C       0x020A725C  data
 *   func_0201093C     0x0201093C  thumb
 *   func_02010888     0x02010888  thumb
 *   func_02030734     0x02030734  arm
 *   func_020399A8     0x020399A8  arm
 *   func_02039C68     0x02039C68  arm
 *   func_020307B0     0x020307B0  arm
 *   func_0200FB24     0x0200FB24  thumb
 *   func_02012E08     0x02012E08  thumb
 *
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
 * function 0x020307B0, which is what puts the pool word and the `bx r3` there
 * and what makes the unit's extent end at 0x0201093C.
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

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub0201088CObj {
    u32 f0;         /* +0x00 */
    u32 f4;         /* +0x04 */
    void (*f8)(struct Sub0201088CObj *p);   /* +0x08 */
    u32 f0c;        /* +0x0C */
    u32 f10;        /* +0x10 */
};

extern u8   s0x020A725C;
extern void *func_02030734(u32 a, u32 b, u32 c, u8 *file, u32 line);
extern u32  func_020399A8(void);
extern void func_02039C68(u32 ctx, u32 id, u32 size);
extern void func_02010888(void *p, u32 v);
extern void func_0201093C(void);
extern void func_020307B0(void);
extern u32  func_0200FB24(void);
extern void func_02012E08(u32 v);

void *func_0201088C(u32 heap, u32 a1)
{
    struct Sub0201088CObj *p;

    p = func_02030734(heap, 0x14, 1, &s0x020A725C, 0x75);
    p->f0c = a1;
    func_02039C68(func_020399A8(), 0x71, 8);
    func_02010888(p, (u32)func_0201093C);
    return p;
}

void *func_020108C4(u32 heap, u32 a1, u32 a2, u32 a3)
{
    struct Sub0201088CObj *p;

    p = func_02030734(heap, 0x14, 1, &s0x020A725C, 0x87);
    p->f0 = a2;
    p->f4 = a3;
    p->f0c = a1;
    func_02039C68(func_020399A8(), 0x71, 8);
    func_02010888(p, (u32)func_0201093C);
    return p;
}

u32 func_02010904(struct Sub0201088CObj *p)
{
    if (p->f8 != 0)
        p->f8(p);
    if (func_0200FB24() != 0) {
        if (p->f0c != 0)
            func_02012E08(p->f0c);
        return 1;
    }
    if (p->f8 == 0)
        return 1;
    return 0;
}

void func_02010934(void)
{
    func_020307B0();
}
