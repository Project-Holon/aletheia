/*
 * function: FATFSi_PostRequest
 * address:  0x02704258
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FATFSi_SendToPXI  0x027040B4  arm twl
 */

typedef unsigned int u32;

extern void FATFSi_SendToPXI(u32 a0);

void FATFSi_PostRequest(u32 a0)
{
    FATFSi_SendToPXI(a0);
}
