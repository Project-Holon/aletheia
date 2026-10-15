/*
 * function: ZKNSEARCH_SYS_Delete
 * address:  0x021BC284
 * packet:   pkt_021BC284
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(u32);

u32 ZKNSEARCH_SYS_Delete(void *p)
{
    func_020315D4(p);
    GFL_HEAP_DeleteChecked(0x7b);
    return 1;
}

