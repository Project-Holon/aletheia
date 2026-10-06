/*
 * function: func_021FC610
 * address: 0x021FC610
 * packet: pkt_ov186_021FC610
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_0207D4B0 0x0207D4B0 arm
 *   d_0220099C 0x0220099C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 id;u8 rest[40];} Record;
extern const Record d_0220099C[];
extern void func_020403F4(u32);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
void func_021FC610(u32 a, u16 b){u32 i,id;for(i=0;i<7;i++){id=d_0220099C[i].id;if(id<4)func_020403F4((u8)id);}func_0207D4B0(1,0,1);}
