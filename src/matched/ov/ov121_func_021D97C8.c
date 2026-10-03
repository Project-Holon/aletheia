/*
 * function: func_021D97C8
 * address: 0x021D97C8
 * packet: pkt_ov121_021D97C8
 * region: ov121
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
 *   d_021DF598 0x021DF598 data a4
 *   d_021DF634 0x021DF634 data a4
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 id; u32 config[8]; u32 a; u32 b; } Entry;
extern const u32 d_021DF598[];
extern const Entry d_021DF634[];
extern void func_02082BCC(void *, int, u32);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0203FC28(const void *);
extern void func_0203FCA0(u8, const void *, u8);
extern void func_020414AC(u8);
extern void func_02040588(u32 which, u32 enable);
void func_021D97C8(void *p, u32 a)
{
    u32 i;
    const Entry *e;
    u32 id;
    i = 0;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(a);
    func_02045088(a);
    func_0203FC28(d_021DF598);
    do {
        e = &d_021DF634[i];
        id = e->id;
        func_0203FCA0((u8)id, e->config, (u8)e->a);
        func_020414AC((u8)id);
        func_02040588((u8)id, (u8)e->b);
        ++i;
    } while (i < 7);
}
