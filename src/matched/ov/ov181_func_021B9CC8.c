/*
 * function: func_021B9CC8
 * address: 0x021B9CC8
 * packet: pkt_ov181_021B9CC8
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 0x021B9D02.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_020439A0 0x020439A0 arm
 */
struct Bmp;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_020439A0(struct Bmp *,struct Bmp *,unsigned,unsigned,int,int,unsigned,unsigned,unsigned);
void func_021B9CC8(char *p){struct Bmp *s=func_02045770(*(void **)(p+0x2c4));func_020439A0(*(struct Bmp **)((unsigned)p+*(unsigned char *)(p+0x2bb)*8+0xb8),s,0,0,0,192,256,16,0);}
