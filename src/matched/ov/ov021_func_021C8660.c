/*
 * function: func_021C8660
 * address:  0x021C8660
 * packet:   pkt_ov021_021C8660
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { u32 f0; u32 f4; u32 f8; u8 pad[0x1a8]; u32 f1B4; } P;
extern void func_020061E4(u32 id);
void func_021C8660(P *p)
{
    if (p != 0 && p->f1B4 == 0 && p->f0 != 0) {
        func_020061E4(0x6dd);
        p->f8++;
        p->f0 = 0;
    }
}
