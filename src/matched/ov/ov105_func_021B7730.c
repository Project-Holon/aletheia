/*
 * function: func_021B7730
 * address: 0x021B7730
 * packet: pkt_ov105_021B7730
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes after return, before 021B7778.
 * symbols:
 *   func_021B8598 0x021B8598 thumb ov105
 *   func_021B7D90 0x021B7D90 thumb ov105
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_021B78A0 0x021B78A0 thumb ov105
 *   func_021B7C6C 0x021B7C6C thumb ov105
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned char u8;
extern void func_021B8598(void *);
extern void func_021B7D90(void *);
extern void func_021B71C0(int);
extern void func_021B78A0(void *);
extern void func_021B7C6C(void *);
extern void func_020315D4(int);
extern void func_020306F0(int);
int func_021B7730(int a,int b,int c,u8 *p) {
 func_021B8598(p+0x128); func_021B7D90(p+0xd4);
 func_021B71C0(*(int *)(p+0x188)); func_021B7D90(p+0xc0);
 func_021B78A0(p); func_021B7C6C(p+0xb0);
 func_020315D4(a); func_020306F0(60); return 1;
}
