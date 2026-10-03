/*
 * function: func_021F5980
 * address: 0x021F5980
 * packet: pkt_ov135_021F5980
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F6E08 0x021F6E08 thumb ov135
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02030734 0x02030734 arm
 *   str_02203B54 0x02203B54 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F6E08(u8 *);
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char str_02203B54[];
void func_021F5980(u8 *p)
{
    func_021F6E08(p);
    *(void **)(p + 0xb80) = func_020457B0(0x12, 0x48);
    *(void **)(p + 0xb88) = func_020457B0(0xb4, 0x48);
    *(void **)(p + 0xb84) = func_02045EC0(*(void **)(p + 0xb6c), 0x73);
    if (*(u16 *)(p + 0xc6) == 0x1e) {
        *(u16 *)(p + 0xc6) = 0;
    }
    *(void **)(p + 0xeac) = func_02030734(0x48, 0x78, 0, str_02203B54, 0x344);
}
