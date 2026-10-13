/*
 * function: AESi_PxiSendCmd
 * address:  0x02707A94
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
 *   AESi_PxiSendData  0x027079FC  arm
  */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
void AESi_PxiSendFirst(int tag, u32 a, u32 b);
void AESi_PxiSendData(int tag, const u8 *buf, u32 len);

void AESi_PxiSendCmd(u32 a, const u8 *buf, u32 len)
{
    AESi_PxiSendFirst(0x13, (u16)a, 0);
    AESi_PxiSendData(0x13, buf, len);
}
