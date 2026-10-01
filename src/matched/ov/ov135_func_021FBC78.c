/*
 * function: func_021FBC78
 * address: 0x021FBC78
 * packet: pkt_ov135_021FBC78
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F9660 0x021F9660 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern u32 func_0204B98C(void *p);
extern void func_0204B3DC(u32 p, int on);
extern void func_021F9660(void *p, u32 mode);
extern void func_0201F868(void *p);
int func_021FBC78(u8 *p)
{
    if (func_0204B98C(*(void **)(p + 8)) != 0) return -1;
    func_0204B3DC(*(u32 *)(p + 8), 0);
    func_0204B3DC(*(u32 *)(p + 12), 0);
    func_0204B3DC(*(u32 *)(p + 16), 0);
    func_021F9660(p, 3);
    func_0201F868(*(void **)(p + 0x30));
    return *(s16 *)(p + 0x3e);
}
