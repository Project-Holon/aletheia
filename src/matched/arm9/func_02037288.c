/*
 * function: func_02037288
 * address:  0x02037288
 * packet:   pkt_02037288
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Closes the 4-byte residue docs/notes/pkt_02037288_wave25.c.txt records
 * (the `mov r3, r4` / `lsl r1, r1, #1` pair at +0x00B0).  The lever is the
 * ALLOCATION RESULT TYPE, not the size spelling: the seven pointer fields
 * are declared `void *` so each func_02030734 result is stored without an
 * integer conversion.  With them declared `u32` the file does not even
 * compile; with a cast at each site the argument scheduling shifts and the
 * 0xE8 call's size is finished before r3 is written.  The size arguments
 * themselves must stay as in-place expressions re-reading ->f1E0, never
 * bound to a local.
 *
 * The note's other two findings are confirmed and kept: the prototype
 * returns int (the tail `mov r0,#1` is a `return 1`), and the +0x1E0 store
 * is two separate `+ 0x40` adds in the two arms, not one factored add.
 *
 * symbols:
 *   lbl_021469D0   0x021469D0  data
 *   str_020A7A24   0x020A7A24  data
 *   func_0203D680  0x0203D680  arm
 *   func_02037258  0x02037258  arm
 *   func_02030734  0x02030734  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_02036AF4  0x02036AF4  arm
 *   func_02037478  0x02037478  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Net {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    u8  pad1C[0x1ac - 0x1c];
    u32 f1AC;
    u8  pad1B0[0x1e0 - 0x1b0];
    u32 f1E0;
};

extern struct Net *lbl_021469D0;
extern char str_020A7A24[];
extern u32 func_0203D680(void);
extern u32 func_02037258(void);
extern void *func_02030734(u32 heap, u32 size, u32 a, char *file, u32 line);
extern u32 func_0203D6BC(void);
extern void func_02036AF4(u8 *p, u32 n, u8 *q, u32 heap);
extern void func_02037478(void);

int func_02037288(u32 a0, u32 heap, u32 c)
{
    u32 n;
    u32 m;

    if (lbl_021469D0 == 0) {
        n = func_0203D680();
        m = func_02037258();
        lbl_021469D0 = func_02030734(heap, 0x1f0, 1, str_020A7A24, 0xdd);
        if (c != 0)
            lbl_021469D0->f1E0 = m + 0x40;
        else
            lbl_021469D0->f1E0 = a0 + 0x40;

        lbl_021469D0->f14 = func_02030734(heap, lbl_021469D0->f1E0 * 3, 1,
                                          str_020A7A24, 0xe6);
        lbl_021469D0->f18 = func_02030734(heap, lbl_021469D0->f1E0 * 2, 1,
                                          str_020A7A24, 0xe8);
        lbl_021469D0->f10 = func_02030734(heap, n * lbl_021469D0->f1E0, 1,
                                          str_020A7A24, 0xe9);
        lbl_021469D0->f00 = func_02030734(heap, func_0203D6BC(), 1,
                                          str_020A7A24, 0xec);
        lbl_021469D0->f04 = func_02030734(heap, func_0203D6BC() * 15, 1,
                                          str_020A7A24, 0xed);
        lbl_021469D0->f08 = func_02030734(heap, m, 1, str_020A7A24, 0xee);
        lbl_021469D0->f0C = func_02030734(heap, m * 2, 1, str_020A7A24, 0xef);
        func_02036AF4((u8 *)lbl_021469D0 + 0xcc, 0x64,
                      (u8 *)lbl_021469D0 + 0x1c, heap);
        func_02036AF4((u8 *)lbl_021469D0 + 0xf4, 0xb4,
                      (u8 *)lbl_021469D0 + 0x3c, heap);
        lbl_021469D0->f1AC = 1;
        func_02037478();
    }
    *(u16 *)((u8 *)lbl_021469D0 + 0x100 + 0xe4) = 0;
    *((u8 *)lbl_021469D0 + 0x1e7) = 0;
    return 1;
}
