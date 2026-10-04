/*
 * function: func_021F1F7C
 * address: 0x021F1F7C
 * packet: pkt_ov194_021F1F7C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4F60 0x021F4F60 thumb ov194
 *   func_021F4DD0 0x021F4DD0 thumb ov194
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void func_021F4F60(void *);
extern void func_021F4DD0(void *);
extern void func_02045808(void *);
extern void func_020452E8(struct Descriptor *d);
extern void func_02082BCC(void *,int,int);
void func_021F1F7C(u8 *p) { int i;func_021F4F60(*(void **)(p+144));for(i=0;i<3;i++)func_021F4DD0(*(void **)((u32)p+(u32)i*4+132));func_02045808(*(void **)(p+60));func_020452E8((struct Descriptor *)(*(u32 *)(p+64)));func_02082BCC(p,0,148); }
