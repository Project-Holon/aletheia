/*
 * function: func_021C5AAC
 * address: 0x021C5AAC
 * packet: pkt_ov127_021C5AAC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C60C4 0x021C60C4 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { u32 a[4]; u8 b[12]; u32 c; } Descriptor;
extern const Descriptor d_021C60C4;
extern void func_020403F4(u8);
extern void func_0203FCA0(u8,void *,int);
extern void func_02040588(u8,int);
void func_021C5AAC(void *unused,int id,u8 *p)
{
    Descriptor d;
    d=d_021C60C4;
    d.b[1]=p[2]; d.b[2]=p[3]; d.b[3]=p[4];
    d.b[8]=p[5]; d.b[9]=p[6]; d.b[10]=0; d.c=p[7];
    func_020403F4(id);
    func_0203FCA0(id,&d,0);
    func_02040588(id,1);
}
