/*
 * function: func_020122A4
 * address:  0x020122A4
 * packet:   pkt_020122A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035064  0x02035064  arm
 *   func_02012264  0x02012264  thumb
 *
 * Two instructions and a two word pool: the first argument is the address of
 * func_02012264 tagged as a Thumb function pointer (the pool word is 0x02012265,
 * odd), the second is the caller's own argument, and the tail call is
 * `func_02035064(fn, arg)` with func_02035064 an ARM function.  Declaring the
 * pointer as `func_02012264` rather than writing the literal 0x02012265 is what
 * gets the odd word out of the compiler; func_02012264's own manifest entry is
 * what attests it (`matched x1`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020122A4.c \
 *       --func func_020122A4 --addr 0x020122A4 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void func_02035064(const void *fn, u32 arg);
extern int func_02012264(int a0, int a1, int a2, int a3);

void func_020122A4(u32 arg)
{
    func_02035064((const void *)func_02012264, arg);
}
