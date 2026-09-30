/*
 * unit: yes
 * function: func_021B727C, func_021B728C, func_021B72A0
 * address: 0x021B727C
 * packet: pkt_ov101_021B727C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_02040588 0x02040588 arm
 */
typedef unsigned char u8;
extern void func_02040588(u8,u8);
int func_021B727C(int p) { if(*(int *)(p+0x50)) return 1; return 0; }
void func_021B728C(int p,int b) {
 *(int *)(p+0x5c)=b;
 func_02040588(*(int *)(p+0x3c),b);
}
void func_021B72A0(int p,int b) {
 *(int *)(p+0x5c)=b;
 *(int *)(p+0x50)=0;
}
