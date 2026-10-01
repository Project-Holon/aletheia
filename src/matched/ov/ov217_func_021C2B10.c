/*
 * function: func_021C2B10
 * address: 0x021C2B10
 * packet: pkt_ov217_021C2B10
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: explicit fourth-argument byte narrowing; fifth packed halfword uses
 *   a scalar u16: original outgoing str word and callee ldrh preserve bits.
 * lever: reuse value for value*3/32, retaining the dying local's register.
 * symbols:
 *   d_020A1B38 0x020A1B38 data a2
 *   _u32_div_f 0x0209C2B0 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _ffix 0x0209C494 arm
 *   func_02021F64 0x02021F64 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rgb555 { u16 r:5; u16 g:5; u16 b:5; u16 pad:1; };
extern const short d_020A1B38[];
extern void func_02021F64(u16 *,u16 *,u32,u8,u16);
void func_021C2B10(u8 *p)
{
    u16 angle=(u16)((*(u32 *)(p+0x1c)<<16)/30u);
    u8 value=(u8)(int)(16.0f+16.0f*((float)d_020A1B38[(angle>>4)*2]/4096.0f));
    value=value*3/32;
    func_02021F64(*(u16 **)(p+0xc),*(u16 **)(p+8),p[0x10],value,*(u16 *)(p+0x12));
    *(u32 *)(p+0x1c)+=1;
}
