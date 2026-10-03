/*
 * function: func_021C8A50
 * address: 0x021C8A50
 * packet: pkt_ov128_021C8A50
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C41BC 0x021C41BC thumb ov127
 *   func_0204B3B4 0x0204B3B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_021C41BC(u8 *p);
extern void func_0204B3B4(struct Obj *p);
void func_021C8A50(char *p,int unused) {int i;char *q;for(i=0;i<8;i++) {q=p+i*4;if(*(void **)(q+12)){func_021C41BC(*(void **)(q+12));*(u32 *)(q+12)=0;} if(*(void **)(q+44)){func_0204B3B4(*(void **)(q+44));*(u32 *)(q+44)=0;}}}
