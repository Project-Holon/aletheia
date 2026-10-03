/*
 * unit: yes
 * function: func_021C158C, func_021C15B4
 * address: 0x021C158C
 * packet: pkt_ov099_021C158C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020414AC 0x020414AC arm
 *   func_021BE4F0 0x021BE4F0 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020414AC(int);
extern int func_021BE4F0(char *,int);
int func_021C158C(char *p,int ret){func_020414AC(3);*(u8 *)(p+0x1358)=0;*(int *)(p+0x1cc)=func_021BE4F0(p,0);return ret;}
int func_021C15B4(char *p,int ret){*(int *)(p+0x1cc)=47;return ret;}
