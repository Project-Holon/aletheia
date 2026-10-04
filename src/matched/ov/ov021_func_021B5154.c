/*
 * function: func_021B5154
 * address:  0x021B5154
 * packet:   pkt_ov021_021B5154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D488  0x0200D488  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215E440  0x0215E440  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
struct Big;
struct Blk38;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *sys);
extern unsigned int func_02159B10(void *, void *);
extern u8 func_0200D488(struct Blk38 *p, u32 i);
extern void func_0215E440(void *sys, u32 which);

int func_021B5154(u32 a, u32 b)
{
    void *e = func_0215A5E4((void *)b);
    u32 g = (u32)func_0200D418(func_02012EBC(e));
    u8 k = func_02159B10((void *)a, (void *)b);

    if (func_0200D488((struct Blk38 *)g, k) == 0) {
        func_0215E440(e, k);
    }
    return 0;
}
