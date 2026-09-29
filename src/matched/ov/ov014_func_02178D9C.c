/*
 * function: func_02178D9C
 * address:  0x02178D9C
 * packet:   pkt_ov014_02178D9C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  a4
 *   func_0217814C  0x0217814C  thumb  ov014
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern u8 *g_021797A8;
void func_0217814C(int a);

void func_02178D9C(u8 *m)
{
    void (*cb)(u32, u32, u32);

    if (*(u16 *)(m + 2) != 0) {
        func_0217814C(*(u16 *)(m + 2));
        return;
    }
    cb = *(void (**)(u32, u32, u32))(g_021797A8 + 0x1E78);
    if (cb != 0) {
        if (*(u16 *)(m + 4) == 0x15)
            cb(*(u16 *)(m + 0x12), *(u32 *)(m + 0xC), *(u16 *)(m + 0x10));
        else if (*(u16 *)(m + 4) == 9)
            cb(*(u16 *)(m + 0x12), 0, 0);
    }
}
