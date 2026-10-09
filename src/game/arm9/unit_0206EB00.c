/*
 * file:     unit_0206EB00.c
 * function: func_0206EB00
 * address:  0x0206EB00
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Per-file compiler pin, "kept branches"/"kept constants" family
 * (docs/FRONTEND-PINS.md). Under dsi/1.1p1 the image's `mov r0, #0` at
 * 0x0206EB24 is CSE'd out of the loop counter's own zero (`mov r4, #0`
 * hoisted to 0x0206EB18) and the frame grows a fourth callee-saved
 * register: 1.1p1 emits `push {r4, r5, r6, lr}` against the original's
 * `push {r3, r4, r5, lr}`, 22 concrete bytes out at the same 124. Under
 * ../2.0/sp2 the same C rematerialises the zero and gives 124 bytes, 0
 * concrete mismatches.
 *
 * symbols:
 *   g_020A8224       0x020A8224  data
 *   func_02082A48    0x02082A48  arm
 *
 * Builds the halfword index at dst+0x1A: the byte at tbl+0x17 is the clear
 * length (doubled) and is also stashed at dst+0x19; each of the src->count
 * entries indexes src through the halfword table at src+0x14, and the top
 * byte of the selected word becomes the low half of one output halfword
 * with 0x100 set.
 */
#include "../../matched/include/Obj07050.h"
#include "../../matched/include/Obj16618.h"
#include "../../matched/include/Obj16619.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  g_020A8224;
extern void func_02082A48(u32 val, void *dst, u32 n);

void func_0206EB00(char *dst, char *src, char *tbl)
{
    u8 n;

    *(char * *)&((struct Obj07050 *)dst)->f8 = src;
    ((struct Obj07050 *)dst)->fC = g_020A8224;
    n = ((struct Obj16618 *)tbl)->f17;
    ((struct Obj07050 *)dst)->f19 = n;
    func_02082A48(0, dst + 0x1A, (u32)n << 1);
    {
        u32 i = 0;
        char *ix = src + 0x14;
        while (i < ((struct Obj16619 *)src)->f6) {
            ((u16 *)(dst + 0x1A))[i] =
                (u16)((*(u32 *)(src + ((u16 *)ix)[i]) >> 24) | 0x100);
            i = i + 1;
        }
    }
}
