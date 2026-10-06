/*
 * function: func_021BC54C
 * address: 0x021BC54C
 * packet: pkt_ov223_021BC54C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BC934 0x021BC934 data a4
 *   d_021BC9B0 0x021BC9B0 data a4
 */
typedef unsigned char u8;
struct Entry { unsigned id; char fields[32]; unsigned a,b; };
extern const unsigned d_021BC934[];
extern const struct Entry d_021BC9B0[];
extern void func_02082BCC(void *,int,int);
extern void func_0203F8F4(int);
extern void func_02045088(int);
typedef unsigned int   u32;
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
void func_021BC54C(void *p,int heap)
{
    unsigned i;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021BC934);
    for(i=0;i<7;i++) {
        const struct Entry *e=&d_021BC9B0[i];
        unsigned id=e->id;
        func_0203FCA0((u8)id,(const struct BgTemplate *)e->fields,(u8)e->a);
        func_020414AC(id);
        func_02040588(id,e->b);
    }
}
