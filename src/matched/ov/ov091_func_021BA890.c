/*
 * function: func_021BA890
 * address: 0x021BA890
 * packet: pkt_ov091_021BA890
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020452E8(void *);
extern void func_0204B3B4(void *);
extern void func_0204B084(void *);
extern void func_0204B1CC(void *);
extern void func_0204A8D4(u32);
extern void func_020307B0(void *);
void func_021BA890(void *ignored,u8 *p) { if (!*(u32 *)(p+0x14)) { func_020452E8(*(void **)(p+0x20)); func_0204B3B4(*(void **)(p+0x30)); func_0204B3B4(*(void **)(p+0x34)); func_0204B3B4(*(void **)(p+0x38)); func_0204B084(*(void **)(p+0x24)); func_0204B1CC(*(void **)(p+0x28)); func_0204A8D4(*(u32 *)(p+0x2c)); } func_020307B0(p); }
