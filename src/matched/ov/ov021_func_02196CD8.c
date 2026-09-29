/*
 * function: func_02196CD8
 * address:  0x02196CD8
 * packet:   pkt_ov021_02196CD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * State step: registers the next handler through func_02196034.
 *
 * symbols:
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196A60  0x02196A60  thumb  ov021
 *   func_02196C68  0x02196C68  thumb  ov021
 *   func_02196804  0x02196804  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_02196A60(void);
extern void func_02196C68(void);
extern void func_02196804(void);

void func_02196CD8(u8 *p)
{
    if (*(u32 *)(p + 0xC) == 2) {
        if (*(u32 *)(p + 8) == 5) {
            *(u32 *)(p + 8) = 1;
            func_02196034(p, func_02196A60, 0x4DD);
        } else {
            func_02196034(p, func_02196C68, 0x4E1);
        }
    } else {
        func_02196034(p, func_02196804, 0x4E5);
    }
}
