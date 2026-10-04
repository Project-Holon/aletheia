/*
 * function: func_021C12FC
 * address: 0x021C12FC
 * packet: pkt_ov099_021C12FC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
void func_021C12FC(int a,int b,u8 *data,char *p,int handle){if(handle==(int)func_020399A8()){if(*(int *)(p+0x1cc)==0x48){*(u8 *)(p+0x1357)=*data;func_02039C68((struct Link *)func_020399A8(),0x1a,10);}else *(int *)(p+0x1cc)=21;}}
