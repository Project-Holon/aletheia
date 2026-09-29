/*
 * function: func_021B4804
 * address:  0x021B4804
 * packet:   pkt_ov021_021B4804
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B4918 0x021B4918 thumb ov021
 *   func_021B4984 0x021B4984 thumb ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021B4918(char *w, u32 a, u32 b, u32 c, u32 d);
extern void func_021B4984(char *w, u32 a, u32 b, u32 c);

void func_021B4804(char *w)
{
    if (*(u8 *)(w + 0x162) == 1) {
        if (*(u8 *)(w + 0x163) == 1) {
            func_021B4984(w, 8, *(u16 *)(w + 0x1FC), *(u32 *)(w + 0x200));
        } else {
            func_021B4984(w, 7, *(u16 *)(w + 0x1FC), *(u32 *)(w + 0x200));
        }
    } else {
        if (*(u8 *)(w + 0x163) == 1) {
            func_021B4918(w, 6, *(u16 *)(w + 0x1FC), *(u32 *)(w + 0x200), *(u16 *)(w + 0x208));
        } else {
            func_021B4918(w, 5, *(u16 *)(w + 0x1FC), *(u32 *)(w + 0x200), *(u16 *)(w + 0x208));
        }
    }
}
