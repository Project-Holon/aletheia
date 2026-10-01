/*
 * function: func_021B7968
 * address: 0x021B7968
 * packet: pkt_ov173_021B7968
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0201BD28 0x0201BD28 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0204B404(void *, u16 *, int);
extern void func_0204B3DC(void *, u32);
extern void func_0204B878(void *, u16);
extern u32 func_0201BD28(u16, u32);
void func_021B7968(char *p)
{
    u16 rect[2];
    u32 off;
    u32 i;
    u32 value;
    off = 0x114;
    off = 0x1b8;
    for (i = 0; i < 4; i++) {
        rect[0] = 0x2f;
        rect[1] = i * 24 + 0x50;
        func_0204B404(*(void **)(p + i * 4 + 0x114), rect, 1);
        if (*(u16 *)(*(char **)p + 0x16) + i >= *(u8 *)(p + off)) {
            func_0204B3DC(*(void **)(p + i * 4 + 0x114), 0);
        } else {
            value = func_0201BD28(*(u16 *)(*(char **)(*(char **)p + 0x10) + (*(u16 *)(*(char **)p + 0x16) + i) * 2), 0);
            func_0204B3DC(*(void **)(p + i * 4 + 0x114), 1);
            func_0204B878(*(void **)(p + i * 4 + 0x114), value);
        }
    }
}
