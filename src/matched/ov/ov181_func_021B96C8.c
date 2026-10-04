/*
 * function: func_021B96C8
 * address: 0x021B96C8
 * packet: pkt_ov181_021B96C8
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sub_02005E50 0x02005E50 thumb
 *   sub_02005F38 0x02005F38 thumb
 *   sub_02005D28 0x02005D28 thumb
 *   func_021B9B10 0x021B9B10 thumb ov181
 *   func_021B9D20 0x021B9D20 thumb ov181
 *   func_021B9F1C 0x021B9F1C thumb ov181
 *   func_021B9DB0 0x021B9DB0 thumb ov181
 *   func_021B9B6C 0x021B9B6C thumb ov181
 *   func_021B99CC 0x021B99CC thumb ov181
 *   func_0207D534 0x0207D534 arm
 *   sub_02043534 0x02043534 arm
 *   sub_020435F4 0x020435F4 arm
 *   sub_02034A5C 0x02034A5C arm
 *   overlay_id 0x00000043 data a1
 * volatile: hardware brightness registers 0x04000050 and 0x04001050
 */
typedef unsigned short u16;typedef unsigned int u32;
extern int sub_02005E50(void),sub_02005F38(void);extern void sub_02005D28(void);
extern void func_021B9B10(char *),func_021B9D20(char *),func_021B9F1C(char *),func_021B9DB0(char *),func_021B9B6C(char *),func_021B99CC(void);
extern void func_0207D534(volatile u16 *,int);extern void sub_02043534(u32),sub_020435F4(u32),sub_02034A5C(int);
extern char overlay_id[];
int func_021B96C8(char *p) {
if(sub_02005E50()==1)return 2;
if(sub_02005F38()==1)sub_02005D28();
func_021B9B10(p);func_021B9D20(p);func_021B9F1C(p);func_021B9DB0(p);func_021B9B6C(p);func_021B99CC();
func_0207D534((volatile u16 *)0x0400006c,-16);func_0207D534((volatile u16 *)0x0400106c,-16);
*(volatile u16 *)0x04000050=0;*(volatile u16 *)0x04001050=0;
sub_02043534(0);sub_020435F4(0);sub_02034A5C((int)overlay_id);return 5;
}
