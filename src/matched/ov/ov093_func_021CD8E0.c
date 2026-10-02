/*
 * function: func_021CD8E0
 * address: 0x021CD8E0
 * packet: pkt_ov093_021CD8E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE600 0x021EE600 thumb ov093
 *   func_02188080 0x02188080 thumb ov096
 *   func_020307B0 0x020307B0 arm
 *   func_021EEAE0 0x021EEAE0 thumb ov093
 */
typedef unsigned char u8;
extern void func_021EE600(void *);
extern void func_02188080(void *);
extern void func_020307B0(void *);
extern void func_021EEAE0(void *);
void func_021CD8E0(u8 *p) {
 if(*(void**)(p+0x10))func_021EE600(*(void**)(p+0x10));
 if(*(void**)(p+0xf0))func_02188080(*(void**)(p+0xf0));
 func_020307B0(*(void**)(p+0x134));
 func_021EEAE0(*(void**)(p+0x50));
 func_020307B0(p);
}
