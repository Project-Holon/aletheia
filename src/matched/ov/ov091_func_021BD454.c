/*
 * function: func_021BD454
 * address: 0x021BD454
 * packet: pkt_ov091_021BD454
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_020307B0 0x020307B0 arm
 */
struct Descriptor;
struct Obj;
extern void func_020452E8(struct Descriptor *);
extern void func_0204B3B4(struct Obj *);
extern void func_0204A8D4(unsigned int);
extern void func_020307B0(void *);
void func_021BD454(char *unused,char *p) { func_020452E8(*(struct Descriptor **)(p+4)); func_020452E8(*(struct Descriptor **)(p+8)); func_0204B3B4(*(struct Obj **)(p+20)); func_0204B3B4(*(struct Obj **)(p+16)); func_0204A8D4(*(unsigned int *)(p+12)); func_020307B0(p); }
