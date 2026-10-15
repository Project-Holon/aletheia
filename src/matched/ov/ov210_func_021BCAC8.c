/*
 * function: ZKNSEARCH_MAIN_LoadBgTile89
 * address:  0x021BCAC8
 * packet:   pkt_ov210_021BCAC8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_020498F4  0x020498F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void ARC_TOOL_DeleteHandle(void *);

void ZKNSEARCH_MAIN_LoadBgTile89(u8 *a0)
{
    void *h = func_020490F4(159, 0x807b);
    func_020498F4(h, 89, 3, 0, 0, 0, 123);
    ARC_TOOL_DeleteHandle(h);
}
