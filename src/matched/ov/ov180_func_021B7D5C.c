/*
 * function: func_021B7D5C
 * address: 0x021B7D5C
 * packet: pkt_ov180_021B7D5C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   func_0204EA38 0x0204EA38 arm
 *   func_020434DC 0x020434DC arm
 *   func_021B73B0 0x021B73B0 thumb ov180
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_0204EA38(void);
extern void func_020434DC(u32,u32);
extern void func_021B73B0(void *);
void func_021B7D5C(void *p) { if(func_0204EA38()==1) func_020434DC(16,0); else func_020434DC(16,1); func_021B73B0(p); }
