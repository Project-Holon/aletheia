/*
 * function: MYSTERY_UTIL_CopyBmpList
 * address: 0x021DA4A8
 * packet: pkt_ov121_021DA4A8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_CopyPixels 0x02043814 arm
 */
#include "../include/Obj13954.h"
#include "../include/Obj22889.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bmp;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_CopyPixels(struct Bmp *dst, const struct Bmp *src);
void MYSTERY_UTIL_CopyBmpList(u8 *p) { u32 i; for(i=0;i<((struct Obj22889 *)(*(u8 * *)&((struct Obj13954 *)p)->f4))->f4;i++) { void *out=*(void **)(p+8+i*4); BMP_CopyPixels(out,BMP_WIN_GetBmp(*(void **)(*(u8 **)(*(u8 * *)&((struct Obj13954 *)p)->f4+16+i*4)+12))); } }
