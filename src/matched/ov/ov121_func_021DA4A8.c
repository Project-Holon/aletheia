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
 *   func_02043814 0x02043814 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02045770(void *);
extern void func_02043814(void *,void *);
void func_021DA4A8(u8 *p) { u32 i; for(i=0;i<*(u32 *)(*(u8 **)(p+4)+4);i++) { void *out=*(void **)(p+8+i*4); func_02043814(out,func_02045770(*(void **)(*(u8 **)(*(u8 **)(p+4)+16+i*4)+12))); } }
