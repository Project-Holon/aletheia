/*
 * function: func_0216F900
 * address: 0x0216F900
 * packet: pkt_ov010_0216F900
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent: two-byte zero alignment padding at 0216F916.
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 * Interface: the call explicitly supplies r1=0x36 even though the leaf reads only r0.
 */
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int *func_0200B3A4(void *, int);
void func_0216F900(void *p) { *func_0200B3A4(func_02012EC4(func_020120F4(p)), 0x36) = 1; }
