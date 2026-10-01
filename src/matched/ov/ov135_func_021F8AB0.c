/*
 * function: func_021F8AB0
 * address: 0x021F8AB0
 * packet: pkt_ov135_021F8AB0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0x021F8AF2..0x021F8AF4 is two zero alignment bytes.
 * symbols:
 *   func_02008540 0x02008540 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_0205994C 0x0205994C arm
 *   func_021C7BA0 0x021C7BA0 arm ov114
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void *func_02009860(void *p);
extern u32 func_02009CC0(void *p);
extern void func_02008540(void *p, u32 value);
extern u32 func_0200853C(const void *p);
extern u64 func_0205994C(void *p);
extern void func_021C7BA0(u32 a, u32 b, u32 c, int d);
int func_021F8AB0(u8 **p)
{
    void *handle;
    u32 id;
    u64 key;
    handle = func_02009860(*(void **)(*p + 0x14));
    func_02008540(*(void **)(*p + 0x1C), func_02009CC0(*(void **)(*p + 0x14)));
    id = func_0200853C(*(void **)(*p + 0x1C));
    key = func_0205994C(handle);
    func_021C7BA0(id, (u32)key, (u32)(key >> 32), 0);
    return 1;
}
