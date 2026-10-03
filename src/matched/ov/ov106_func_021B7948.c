/*
 * function: func_021B7948
 * address: 0x021B7948
 * packet: pkt_ov106_021B7948
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B78D8 0x021B78D8 thumb ov106
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204E720(int,int,int,int);
extern int func_0204E804(void);
extern void func_021B78D8(u8 *);
void func_021B7948(u8 *a,int *s) { switch (*s) { case 0: func_0204E720(3,0,16,0); *s=1; break; case 1: if (!func_0204E804()) *s=2; break; case 2: func_021B78D8(a); break; } }
