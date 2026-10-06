/*
 * function: func_021BB2C8
 * address: 0x021BB2C8
 * packet: pkt_ov214_021BB2C8
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   config 0x021BB53C data ov214
 *   records 0x021BB5B8 data a4
 * Caller explicitly narrows both BG identifiers and record fields to u8.
 * Heap externs widened: caller passes full r1 without a narrowing instruction.
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct Record { u32 id; u8 template_data[32]; u32 type; u32 enabled; };
extern u32 config[];
extern const struct Record records[];
extern void func_02082BCC(void *,u32,u32);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
void func_021BB2C8(void *p,u32 heap)
{
    u32 i;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)config);
    for(i=0;i<3;i++) {
        const struct Record *r=&records[i];
        u32 id=r->id;
        func_0203FCA0((u8)id,(const struct BgTemplate *)r->template_data,(u8)r->type);
        func_020414AC(id);
        func_02040588(id,r->enabled);
    }
}
