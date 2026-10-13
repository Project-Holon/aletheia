/*
 * function: AESi_PxiSendData
 * address:  0x027079FC
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   AESi_PxiSendSecond  0x027079D0  arm
  */

typedef unsigned int u32;
typedef unsigned char u8;
void AESi_PxiSendSecond(int tag, u32 a);

void AESi_PxiSendData(int tag, const u8 *buf, u32 len)
{
    u32 i = 0;
    while (len - i >= 3) {
        AESi_PxiSendSecond(tag, (buf[i] << 16) | (buf[i + 1] << 8) | buf[i + 2]);
        i += 3;
    }
    if (len - i == 2) {
        AESi_PxiSendSecond(tag, (buf[i] << 16) | (buf[i + 1] << 8));
    } else if (len - i == 1) {
        AESi_PxiSendSecond(tag, buf[i] << 16);
    }
}
