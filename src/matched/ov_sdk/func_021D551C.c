/*
 * function: DWCi_EFFlInit
 * address:  0x021D551C
 * packet:   pkt_021D551C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlInit 0x021D551C arm
 *   DWCi_HEAPlAllocEx  0x021D6414  arm
 *
 * Allocate a 0x18-byte block, publish it, and clear two 0x1000-wide register spans.
 * Addresses are Black-image addresses.
 */

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
typedef unsigned int   u32;
extern void func_0207D658(u32 addr, int plane, int brightness);

void DWCi_EFFlInit(void)
{
    unsigned short *p;

    *(int *)0x021DE67C = (int)DWCi_HEAPlAllocEx(0x18, 4);
    p = (unsigned short *)0x04000050;
    func_0207D658((u32)p, 0x3f, 0x10);
    func_0207D658((u32)(p + 0x800), 0x3f, 0x10);
}

