/*
 * function: B_BAG_MAIN_SyncCursorToItem
 * address: 0x0220B9D8
 * packet: pkt_ov197_0220B9D8
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct In { u8 sel; u8 pad[0xc]; u16 cur; } In;
typedef struct S { u8 *d; u8 pad[0x533 - 4]; In in; } S;
void B_BAG_MAIN_SyncCursorToItem(u8 *p)
{
    unsigned int i = 0;
    u8 sel = *(u8 *)(p + 0x533);
    u8 *row = p + sel * 0x90;
    u16 cur = *(u16 *)(p + 0x533 + 0xd);
    for (; i < 36; i++) {
        if (cur == *(u16 *)(row + 0x150 + i * 4)) {
            *(u16 *)(*(u8 **)p + sel * 2 + 0x30) = i % 6;
            *(u16 *)(*(u8 **)p + *(u8 *)(p + 0x533) * 2 + 0x38) = i / 6;
            return;
        }
    }
}
