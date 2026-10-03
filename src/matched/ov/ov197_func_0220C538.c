/*
 * function: func_0220C538
 * address: 0x0220C538
 * packet: pkt_ov197_0220C538
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220C180 0x0220C180 thumb ov197
 *   func_0220C4D4 0x0220C4D4 thumb ov197
 *   func_0220C6F8 0x0220C6F8 thumb ov197
 *   d_0220DB7C 0x0220DB7C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_0220C180(char *,u16,u32,u32);
extern void func_0220C4D4(int,int);
extern void func_0220C6F8(u8 *,u32,u32);
extern const int d_0220DB7C[];
void func_0220C538(char *p) { if(*(u16 *)(p+0x540)!=0) { func_0220C180(p,*(u16 *)(p+0x540),6,6); func_0220C4D4(*(int *)(p+0x43c),(int)d_0220DB7C); } if(*(int *)(*(char **)p+8)==2) func_0220C6F8((u8 *)p,192,24); }
