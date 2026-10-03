/*
 * function: func_021D50DC
 * address: 0x021D50DC
 * packet: pkt_ov122_021D50DC
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D798 0x0203D798 arm
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203D798(void);extern void func_02082D44(const void *,void *,u32);
void func_021D50DC(char *p) {u8 buf[6]={0};func_0203D798();*(u32 *)(*(char **)(p+0x344)+16)=1;func_02082D44(buf,*(char **)(p+0x344)+20,6);}
