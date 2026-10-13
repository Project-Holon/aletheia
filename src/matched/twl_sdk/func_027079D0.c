/*
 * function: AESi_PxiSendSecond
 * address:  0x027079D0
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

void AESi_PxiSendSecond(int tag, u32 a)
{
    u32 data = a & 0xFFFFFF;
    while (PXI_SendWordByFifo(tag, data, 0) < 0) {
    }
}
