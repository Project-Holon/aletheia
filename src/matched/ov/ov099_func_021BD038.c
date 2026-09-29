/*
 * function: func_021BD038
 * address:  0x021BD038
 * packet:   pkt_ov099_021BD038
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCC4C  0x021BCC4C  thumb  ov099
 *   func_021BDDF4  0x021BDDF4  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern void func_021BCC4C(char *p);
extern int func_021BDDF4(char *p);
extern void func_021BAAB8(char *p, int a, int b);

int func_021BD038(char *p, int v)
{
    func_021BCC4C(p);
    if (func_021BDDF4(p) == 0) {
        switch (*(int *)(p + 0x135C)) {
        case 3:
            *(u32 *)(p + 0x1CC) = 0x9D;
            func_021BAAB8(p, 0x68, 0);
            return v;
        case 2:
        case 4:
            *(u32 *)(p + 0x1CC) = 0x63;
            func_021BAAB8(p, 0x68, 0);
            return v;
        default:
            *(u32 *)(p + 0x1CC) = 0x96;
            func_021BAAB8(p, 0x68, 0);
            return v;
        }
    }
    *(u8 *)(p + 0x1353) = 0x64;
    *(u32 *)(p + 0x1CC) = 0x8A;
    return v;
}
