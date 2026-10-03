/*
 * function: func_0201A4D4
 * address:  0x0201A4D4
 * packet:   pkt_0201A4D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734 0x02030734  arm
 *   func_020457B0 0x020457B0  arm
 *   func_02045808 0x02045808  arm
 *   func_02045B38 0x02045B38  arm
 *   func_02045EC0 0x02045EC0  arm
 *   tbl_0209E444  0x0209E444  data
 *
 * Wave 17 lane untried_small. What closed it (from 6 halfwords out): the heap
 * id parameter a2 is u16. The image homes it to the stack and reloads it for
 * every use (the allocator's first argument included); declared u32 it stays
 * in r2 and is copied, which was the whole parameter-homing residue.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern u32 func_020457B0(u32 a, u32 b);
extern void func_02045808(u32 a);
extern u32 func_02045B38(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02045EC0(u32 a, u32 b);
extern u8 tbl_0209E444[];

u8 *func_0201A4D4(u8 *a0, u32 a1, u16 a2, u32 a3)
{
    u8 *v7;
    u32 v10;
    int i;
    u32 f;

    v7 = (u8 *)func_02030734(a2, 0x38, 1, (const char *)0x020A72F0, 0x312);
    *(u32 *)v7 = func_02045B38(0, 2, 0xa5, a2);
    v10 = func_020457B0(0x40, a2);
    f = *(u8 *)(a0 + 0xab);
    if (f == 2)
        *(u8 *)(v7 + 0x34) = a3;
    else
        *(u8 *)(v7 + 0x34) = f;
    for (i = 0; i < 6; i++) {
        int off = i * 4;
        u8 *q = v7 + off;

        *(u32 *)(q + 4) = func_02045EC0(*(u32 *)v7, i);
        *(u32 *)(q + 0x1c) =
            ((u32 (*)(u8 *, u32, u8 *, u32, u32))
                 (*(u32 *)(tbl_0209E444 + off)))(a0, a1, v7, v10, a2);
    }
    func_02045808(v10);
    return v7;
}
