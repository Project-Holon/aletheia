/*
 * function: func_021B7F00
 * address: 0x021B7F00
 * packet: pkt_ov106_021B7F00
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B9524 0x021B9524 data a4
 *   func_020452E8 0x020452E8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {u32 f0; u8 padding[36];} Entry;
extern Entry d_021B9524[];
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *,int,int);
void func_021B7F00(u32 *p) {
    int i;
    func_020452E8((struct Descriptor *)p[3]);
    func_0203FB44((int)1,(u16)p[1],(u16)(p[1]>>16));
    func_0203FB44((int)5,(u16)p[2],(u16)(p[2]>>16));
    func_02040DA8(5,1,0);
    func_02040DA8(1,1,0);
    for(i=0;i<8;i++)func_020403F4((u8)d_021B9524[i].f0);
    func_020450C8();func_0203F9B4();
    func_02082BCC(p,0,16);
}
