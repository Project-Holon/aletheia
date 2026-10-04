/*
 * function: func_021DEB5C
 * address:  0x021DEB5C
 * packet:   pkt_021DEB5C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02182AC0   0x02182AC0  arm  ov009
 *   func_021DE184   0x021DE184  arm  ov175
 *   g_021E3DF8      0x021E3DF8  data
 *   g_021E3EFC      0x021E3EFC  data
 *
 * Same shape as func_021DDFBC with the other descriptor pair and the
 * func_021DE184 callee.
 */

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
} Blk;

extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern void func_021DE184(u32 ctx, u32 *arr, int n);
extern u32 g_021E3DF8[];
extern u32 g_021E3EFC[];

u32 func_021DEB5C(char *obj)
{
    Blk *b = *(Blk **)(obj + 8);

    func_02182AC0((void *)(*(u32 *)(obj + 0x18)), (char *)((u32)g_021E3DF8), (char *)((u32)g_021E3EFC), (char *)b->f0);
    func_021DE184((u32)obj, (u32 *)b->f4, b->f8);
    return 0;
}
