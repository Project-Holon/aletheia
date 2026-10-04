/*
 * function: func_021BBDD0
 * address:  0x021BBDD0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *
 * Walks the twelve pointers at +0x150 in two halves of six: the first half is
 * handed pair (callee, then join call) with flag ? 1 : 0, the second half with
 * flag ? 0 : 1, each half skipping empty slots.
 *
 * Two rules of this overlay are load-bearing here.  First the duplicated call
 * per arm: the image has two call sites for each of the two calls, each with
 * its own literal, and 1.1p1 does not merge them because the arms are written
 * out.  A computed selector (`int k = flag ? 1 : 0;` passed to one call site)
 * compiles to 116 bytes against the image's 128, with the selector parked in a
 * callee-saved register.  Second the walked address is index-first
 * (`s + i * 4 + 0x150`) so that the scaled index is computed once into r5 (r4
 * in the second half) and the field constant stays in a register.
 *
 * The two halves share one counter: re-initialising the same variable
 * (`for (i = 6; i < 12; i++)`) is the image's shape - a second counter
 * variable costs 8 bytes and swaps r4/r5.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_021BBDD0(void *pv, int flag)
{
    char *s = (char *)pv;
    int i;

    for (i = 0; i < 6; i++) {
        if (*(void **)(s + i * 4 + 0x150) != 0) {
            if (flag != 0) {
                func_0204B92C(*(void **)(s + i * 4 + 0x150), 1);
                func_0204B3DC(*(void **)(s + i * 4 + 0x150), 1);
            } else {
                func_0204B92C(*(void **)(s + i * 4 + 0x150), 0);
                func_0204B3DC(*(void **)(s + i * 4 + 0x150), 0);
            }
        }
    }

    for (i = 6; i < 12; i++) {
        if (*(void **)(s + i * 4 + 0x150) != 0) {
            if (flag != 0) {
                func_0204B92C(*(void **)(s + i * 4 + 0x150), 0);
                func_0204B3DC(*(void **)(s + i * 4 + 0x150), 0);
            } else {
                func_0204B92C(*(void **)(s + i * 4 + 0x150), 1);
                func_0204B3DC(*(void **)(s + i * 4 + 0x150), 1);
            }
        }
    }
}
