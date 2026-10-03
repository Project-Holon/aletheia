/*
 * function: func_021F0B64
 * address: 0x021F0B64
 * packet: pkt_ov032_021F0B64
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 */
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
void func_021F0B64(char *p) { func_02043B5C(*(void **)(p+0x194),0x40); func_02045334(*(void **)(p+0x190)); }
