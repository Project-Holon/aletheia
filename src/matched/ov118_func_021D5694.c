/*
 * function: func_021D5694
 * address:  0x021D5694
 * packet:   pkt_ov118_021D5694
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *
 * Teardown of the three sub-buffers at +0x8a8/+0x88c/+0x8bc (their base
 * 0x8a8 is the single pool word) plus the +0xb0 pointer hung off the +0xc
 * record; every slot clears to zero. Non-SDK deps are the matched ov118
 * func_021D5694 callers' targets; this is the first callee of func_021D6C78.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_0204B3B4(void *);
extern void func_0204A8D4(void *);
extern void func_0204ADA4(void *);
extern void func_0204AFD8(void *);

void func_021D5694(void *p)
{
    u8 *b = p;

    if (*(void **)((u8 *)*(void **)(b + 0xc) + 0xb0) != 0)
        func_0204B3B4(*(void **)((u8 *)*(void **)(b + 0xc) + 0xb0));
    if (*(void **)(b + 0x8a8) != 0) {
        func_0204A8D4(*(void **)(b + 0x8a8));
        func_0204ADA4(*(void **)(b + 0x88c));
        func_0204AFD8(*(void **)(b + 0x8bc));
    }
    *(void **)(b + 0x8a8) = 0;
    *(void **)(b + 0x88c) = 0;
    *(void **)(b + 0x8bc) = 0;
    *(void **)((u8 *)*(void **)(b + 0xc) + 0xb0) = 0;
}
