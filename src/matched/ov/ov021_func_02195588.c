/*
 * function: func_02195588
 * address:  0x02195588
 * packet:   pkt_ov021_02195588
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020414EC  0x020414EC  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02049624  0x02049624  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020414EC(u32 a);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);

void func_02195588(u8 *p)
{
    u32 r;
    u32 v;

    func_020414EC(*(u32 *)(p + 0x10) & 0xFF);
    v = *(u32 *)(p + 0x10);
    r = 0;
    switch (v) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        r = 4;
        break;
    }
    func_02049B40(5, 0, r, (u32)p[0x14] << 5, 0x20, *(u16 *)p);
    func_02049624((void *)5, (void *)5, (void *)(*(u32 *)(p + 0x10)), (void *)(*(u16 *)(p + 0xC)), 0, 0, *(u16 *)p);
}
