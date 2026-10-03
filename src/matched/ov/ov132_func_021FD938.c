/*
 * unit: yes
 * function: func_021FD938, func_021FD948, func_021FD954, func_021FD95C
 * The larger indexed follower at 021FD964 is parked separately at DIFF.
 * address: 0x021FD938
 * packet: pkt_ov132_021FD938
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FCDEC 0x021FCDEC thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021FCDEC(int,int);
void func_021FD938(char *p) {func_021FCDEC((int)p,0x42);*(int *)(p+0x4c)=12;}
void func_021FD948(char *p,u32 value){*(int *)(p+0x4c)=18;*(u32 *)(p+0x120)=value;}
u32 func_021FD954(char *p){return *(u32 *)(p+0x144);}
u32 func_021FD95C(char *p){return *(u32 *)(p+0x148);}
