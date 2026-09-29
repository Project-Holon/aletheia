/*
 * function: func_021C9B24
 * address:  0x021C9B24
 * packet:   pkt_ov021_021C9B24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_020130B4  0x020130B4  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EE4  0x02012EE4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020307B0(void *p);
extern void func_020130B4(void *p);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_020120F4(u32 a);
extern void func_02012EE4(u32 a, int b);

void func_021C9B24(u32 a, u8 *p)
{
    if (p != 0) {
        if (*(void **)(p + 0x7C8) != 0) {
            func_020307B0(*(void **)(p + 0x7C8));
            *(void **)(p + 0x7C8) = 0;
        }
        if (*(void **)(p + 0x7CC) != 0) {
            func_020130B4(*(void **)(p + 0x7CC));
            *(void **)(p + 0x7CC) = 0;
        }
        func_02082BCC(p, 0, 0x7EC);
        func_020307B0(p);
    }
    func_02012EE4(func_020120F4(a), 0);
}
