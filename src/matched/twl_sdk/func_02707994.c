/*
 * function: AESi_PxiSendFirst
 * address:  0x02707994
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
  */

typedef unsigned int u32;
extern int PXI_SendWordByFifo(int tag, u32 data, int err);

void AESi_PxiSendFirst(int tag, u32 a, u32 b)
{
    u32 data = ((a << 21) & 0x1E00000) | 0x2000000 | (b & 0xFFFF);
    while (PXI_SendWordByFifo(tag, data, 0) < 0) {
    }
}
