/*
 * function: func_021DA978
 * address:  0x021DA978
 * packet:   pkt_021DA978
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_OAM_UploadChars  0x020257D0  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10415.h"

typedef unsigned short u16;

typedef unsigned char  u8;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct Obj;
extern void BMP_OAM_UploadChars(struct Obj *o);

void func_021DA978(char *p)
{
    BMP_Clear((struct CharBuf *)(((struct Obj10415 *)p)->f0), (unsigned char)(((struct Obj10415 *)p)->f4 & 0x1f));
    BMP_OAM_UploadChars(((struct Obj10415 *)p)->f1C);
}
