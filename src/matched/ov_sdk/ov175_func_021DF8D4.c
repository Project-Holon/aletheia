/*
 * function: sciInterfaceDestroy
 * address:  0x021DF8D4
 * packet:   pkt_021DF8D4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sciWsDestroy  0x021E0730  arm
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *
 * Reset the owner: release it, blank the two 0x28-byte parameter blocks, put
 * the 0xadde signature on the front of each and clear the live flag.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void sciWsDestroy(char *p);
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32 n);

void sciInterfaceDestroy(char *p)
{
    u32 z = 0;
    u32 n = 0x28;

    sciWsDestroy(p);
    MSL_C_LIB_MemsetPtr(p + 0x5c, z, n);
    MSL_C_LIB_MemsetPtr(p + 0x84, z, n);
    *(u8 *)(p + 0x5c) = 0xde;
    *(u8 *)(p + 0x5d) = 0xad;
    *(u8 *)(p + 0x84) = 0xde;
    *(u8 *)(p + 0x85) = 0xad;
    *(u32 *)(p + 0x50) = z;
}
