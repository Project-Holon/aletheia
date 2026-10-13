/*
 * function: func_021DA4A8
 * address: 0x021DA4A8
 * packet: pkt_ov121_021DA4A8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_CopyPixels 0x02043814 arm
 */
#include "../include/Obj13954.h"
#include "../include/Obj22889.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bmp;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_CopyPixels(struct Bmp *dst, const struct Bmp *src);
void func_021DA4A8(u8 *p) { u32 i; for(i=0;i<((struct Obj22889 *)(*(u8 * *)&((struct Obj13954 *)p)->f4))->f4;i++) { void *out=*(void **)(p+8+i*4); BMP_CopyPixels(out,func_02045770(*(void **)(*(u8 **)(*(u8 * *)&((struct Obj13954 *)p)->f4+16+i*4)+12))); } }
