/*
 * function: func_021B7768
 * address: 0x021B7768
 * packet: pkt_ov104_021B7768
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B7784 writes the hardware register at 0x04000050.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021B8ADC 0x021B8ADC thumb ov104
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_021B874C 0x021B874C thumb ov104
 *   func_021B80F8 0x021B80F8 thumb ov104
 *   func_021B8EA4 0x021B8EA4 thumb ov104
 *   func_021B7EC8 0x021B7EC8 thumb ov104
 *   func_021B7940 0x021B7940 thumb ov104
 *   func_021B7DAC 0x021B7DAC thumb ov104
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned char u8;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021B8ADC(void *);
extern void func_021B71C0(void *p);
extern void func_021B874C(u8 *p);
extern void func_021B80F8(void *);
extern void func_021B8EA4(void *);
extern void func_021B7EC8(u8 *p);
extern void func_021B7940(u8 *p);
extern void func_021B7DAC(u8 *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
int func_021B7768(int a,int b,int c,u8 *p) {
 func_02030EAC((struct Node *)(*(int *)(p+0x8a4)));func_021B8ADC(p+0x278);
 *(volatile unsigned short *)0x04000050=0;
 func_021B71C0((void *)(*(int *)(p+0x7ac)));func_021B874C(p+0xe0);func_021B80F8(p+0x7b0);func_021B8EA4(p+0x7cc);func_021B7EC8(p+0x7f0);func_021B7EC8(p+0x7dc);func_021B7EC8(p+0xcc);func_021B7940(p);func_021B7DAC(p+0xbc);func_020315D4((struct S020315D4 *)a);func_020306F0(56);return 1;
}
