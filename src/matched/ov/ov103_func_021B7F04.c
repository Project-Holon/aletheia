/*
 * function: func_021B7F04
 * address: 0x021B7F04
 * packet: pkt_ov103_021B7F04
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Verified against the ov103 Thumb image.
 * symbols:
 *   func_02047910 0x02047910 arm
 *   func_02047828 0x02047828 arm
 *   func_02047A60 0x02047A60 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void func_02047910(int,u16,int); extern void func_02047828(int,int,int *); extern void func_02047A60(int,void *);
void func_021B7F04(u8 *p) { int i,x,y; if(*(int *)(p+0x58)) { for(i=0;i<2;i++) func_02047910(*(int *)(p+16),i,4096); func_02047828(*(int *)(p+16),0,&x); y=0; if(x==0)y=1; *(int *)(p+0x5c)=y; func_02047A60(*(int *)(p+16),p+0x1c); } }
