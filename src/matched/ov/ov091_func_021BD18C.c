/*
 * function: func_021BD18C
 * address: 0x021BD18C
 * packet: pkt_ov091_021BD18C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD454 0x021BD454 thumb ov091
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
struct Descriptor;
extern void func_021BD454(char *,char *);
extern void func_020452E8(struct Descriptor *);
extern void func_020307B0(void *);
void func_021BD18C(char *a,char *p) { u8 i; for(i=0;i<6;i++) { char *q=*(char **)(p+i*4+8); if(q)func_021BD454(a,q); } func_020452E8(*(struct Descriptor **)(p+4)); func_020307B0(p); }
