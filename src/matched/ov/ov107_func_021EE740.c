/*
 * function: func_021EE740
 * address: 0x021EE740
 * packet: pkt_ov107_021EE740
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EEF28 0x021EEF28 thumb ov107
 *   func_021EF0F4 0x021EF0F4 thumb ov107
 *   func_021F1404 0x021F1404 thumb ov107
 *   func_021F0DE8 0x021F0DE8 thumb ov107
 *   func_021EF444 0x021EF444 thumb ov107
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C1B0 0x0200C1B0 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02005654 0x02005654 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02034F84 0x02034F84 arm
 *   func_021EEEAC 0x021EEEAC thumb ov107
 *   func_021EEEB4 0x021EEEB4 thumb ov107
 *   func_021EEEF8 0x021EEEF8 thumb ov107
 *   d_021F6EA0 0x021F6EA0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Blk34;
struct Object;
extern void func_021EEF28(u8 *);
extern void func_021EF0F4(u8 *);
extern void *func_021F1404(u16,u32,u32,u32,u32,u32);
extern struct Object *func_021F0DE8(u16);
extern void func_021EF444(u8 *);
extern void *func_02012EBC(struct Big *);
extern void *func_0200C0F0(void *);
extern void func_0200C1B0(struct Blk34 *,u32);
extern void *func_020056A0(u32,u32,u32);
extern int func_02005654(int,int);
extern void func_02005D90(u32,u16);
extern void func_02034F84(u32);
extern void func_021EEEAC(void);
extern void func_021EEEB4(void);
extern void func_021EEEF8(void);
extern u8 d_021F6EA0[];
void func_021EE740(u8 *p) {
 p[0x25]=0;
 *(u32 *)(p+0x20)=0;
 p[0x28]=**(u8 **)(p+8);
 func_021EEF28(p);
 func_021EF0F4(p);
 if(!p[0x28]) *(void **)(p+0x68)=func_021F1404(*(u16 *)p,5,5,72,0,0);
 else *(void **)(p+0x68)=func_021F1404(*(u16 *)p,1,1,72,0,1);
 *(void **)(p+0xc)=func_021F0DE8(*(u16 *)p);
 *(u32 *)(p+0x2c)=0;
 *(u32 *)(p+0x60)=0;
 func_021EF444(p);
 if(!p[0x28]) {
  *(void **)(p+0x4c)=func_0200C0F0(func_02012EBC(*(struct Big **)(*(u8 **)(p+8)+4)));
  func_0200C1B0(*(struct Blk34 **)(p+0x4c),4);
 } else {
  *(u32 *)(p+0x4c)=0;
  *(u16 *)(d_021F6EA0+2)=0;
 }
 *(void **)(p+4)=func_020056A0((u32)func_021EEEAC,(u32)p,8);
 if(!p[0x28]) func_02005654((int)func_021EEEB4,0);
 else { func_02005654((int)func_021EEEF8,0); func_02005D90(1154,0xffff); }
 *(u32 *)(p+0x1c)=0;
 *(u32 *)(p+0x44)=0;
 *(u32 *)(p+0x48)=0;
 *(u16 *)(p+0x38)=0;
 *(u16 *)(p+0x3a)=0;
 *(u16 *)(p+0x3c)=0;
 func_02034F84(16);
}
