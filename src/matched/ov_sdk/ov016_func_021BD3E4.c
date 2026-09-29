/*
 * function: func_021BD3E4
 * address:  0x021BD3E4
 * packet:   pkt_ov016_021BD3E4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FOCUSlInit (libdwcutil.TWL.HYB.a(focus.o))
 *
 * symbols:
 *   DWCi_HEAPlAllocEx                0x021D6414  arm  ov016
 *   g_021DE550                       0x021DE550  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    void *cell[4];
} MemFocus;

extern MemFocus *g_021DE550;
extern void *DWCi_HEAPlAllocEx(u32 size, int alignment);

void func_021BD3E4(void)
{
    g_021DE550 = DWCi_HEAPlAllocEx(sizeof(MemFocus), 4);
}
