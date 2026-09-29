/*
 * function: func_021B69AC
 * address:  0x021B69AC
 * packet:   pkt_ov071_021B69AC
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When b[0x3D] is set, copies six 24-byte records from the table
 * func_02048F60(0x25, 0, 0x61) into a+0x60, indexed by b[4..9] (an index
 * past func_020490A8's count reads record 0), then frees the table.
 * The loop counter is enum-typed: with an int counter mwcc knows it is zero
 * at the loop and drops the rotation's entry guard (cmp r5,#6; bge), 4 bytes
 * short; an enum-typed counter is not folded (see
 * an-enum-type-keeps-values-out-of-constant-folding.md).
 * The listing's extent includes 2 bytes of alignment padding (EXACT*).
 *
 * symbols:
 *   func_02048F60  0x02048F60  arm
 *   func_020490A8  0x020490A8  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef enum { IDX_FIRST, IDX_COUNT = 6 } Idx;

struct E24 {
    int w[6];
};

extern struct E24 *func_02048F60(int a, int b, int c);
extern u32 func_020490A8(int a, int b);
extern void func_020307B0(void *p);

void func_021B69AC(u8 *a, u8 *b)
{
    struct E24 *tbl;
    u32 n;
    u32 idx;
    Idx i;

    if (b[0x3d] != 0) {
        tbl = func_02048F60(0x25, 0, 0x61);
        n = func_020490A8(0x25, 0);
        for (i = IDX_FIRST; i < IDX_COUNT; i++) {
            idx = b[4 + i];
            if (idx >= n) {
                idx = 0;
            }
            *(struct E24 *)(a + 0x60 + i * 24) = tbl[idx];
        }
        func_020307B0(tbl);
    }
}
