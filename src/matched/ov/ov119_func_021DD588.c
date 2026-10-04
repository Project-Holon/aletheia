/*
 * function: func_021DD588
 * address:  0x021DD588
 * packet:   pkt_ov119_021DD588
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 */

typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);

void func_021DD588(char *p)
{
    if (*(void **)(p + 0x890) != 0) {
        func_0204ADA4((u32)(*(void **)(p + 0x890)));
        *(void **)(p + 0x890) = 0;
    }
    if (*(void **)(p + 0x8C0) != 0) {
        func_0204AFD8((u32)(*(void **)(p + 0x8C0)));
        *(void **)(p + 0x8C0) = 0;
    }
}
