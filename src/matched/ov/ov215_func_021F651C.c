/*
 * function: func_021F651C
 * address: 0x021F651C
 * packet: pkt_ov215_021F651C
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021F7178 0x021F7178 data a4
 *   d_021F71F4 0x021F71F4 data a4
 * evidence: 44-byte table stride, template +4, type +36, enable +40;
 * explicit byte truncations before original BG calls narrow externs.
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct BgTemplate { unsigned words[8]; };
struct BgConfig { unsigned layer; struct BgTemplate template; unsigned type,enable; };
extern const unsigned d_021F7178[];
extern const struct BgConfig d_021F71F4[];
extern void MI_CpuFill8(void *,int,int);
extern void func_0203F8F4(unsigned);
extern void BMP_WIN_Init(unsigned);
typedef unsigned int   u32;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
void func_021F651C(void *out,unsigned heap)
{
    unsigned i;
    MI_CpuFill8(out,0,4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)d_021F7178);
    for(i=0;i<6;i++) {
        func_0203FCA0((u8)d_021F71F4[i].layer,&d_021F71F4[i].template,(u8)d_021F71F4[i].type);
        func_020414AC(d_021F71F4[i].layer);
        func_02040588(d_021F71F4[i].layer,d_021F71F4[i].enable);
    }
}
