/*
 * function: DWCi_CELLlSetPalette
 * address:  0x021D5098
 * packet:   pkt_021D5098
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 word;
    u16 half;
    u16 pad;
} Slot;

void DWCi_CELLlSetPalette(u8 *obj, int idx, u32 v, u32 w)
{
    Slot *arr = *(Slot **)(obj + 8);

    if (idx >= 0) {
        arr[idx].word = (arr[idx].word & ~0xC00u) | (v << 10);
        arr[idx].half = (arr[idx].half & ~0xF000u) | (w << 12);
    } else {
        int i = 0;
        while (i < *(u8 *)(obj + 0xC)) {
            arr[i].word = (arr[i].word & ~0xC00u) | (v << 10);
            arr[i].half = (arr[i].half & ~0xF000u) | (w << 12);
            i++;
        }
    }
}
