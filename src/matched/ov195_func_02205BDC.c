/*
 * function: func_02205BDC
 * address:  0x02205BDC
 * packet:   pkt_02205BDC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_020A1EB8 0x020A1EB8 data a4
 *   d_02208C88 0x02208C88 data a4
 *   d_02208C7C 0x02208C7C data a4
 *   d_02208C94 0x02208C94 data a4
 *   func_02205854 0x02205854 thumb ov195
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 */

typedef signed short s16;
typedef unsigned int u32;

extern const s16 d_020A1EB8[];
extern u32 d_02208C88[];
extern u32 d_02208C7C[];
extern u32 d_02208C94[];
extern void func_02205854(void);
extern void func_02046440(int, int, int, int, int, void *, void *);
extern u32 func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, void *);

void func_02205BDC(u32 *a, void *b)
{
    func_02046440(0, 2, 0, 1, 0, b, func_02205854);
    *a = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0,
                       d_02208C88, d_02208C7C, d_02208C94, b);
}
