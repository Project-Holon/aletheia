/*
 * function: AESi_PxiSendResult
 * address:  0x02707ACC
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   AESi_PxiSendFirst  0x02707994  arm
  */

typedef unsigned int u32;
typedef unsigned short u16;
void AESi_PxiSendFirst(int tag, u32 a, u32 b);
void AESi_PxiSendResult(u32 a, u32 b)
{
    AESi_PxiSendFirst(0x13, (u16)a, (u16)b);
}
