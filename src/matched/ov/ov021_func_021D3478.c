/*
 * function: func_021D3478
 * address:  0x021D3478
 * packet:   pkt_ov021_021D3478
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_palace_sys.c (layout/file_anchors.txt row 021D3550 -> 0x021DE6D4).
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02013B38  0x02013B38  thumb
 *   func_0204A39C  0x0204A39C  arm
 *   func_02030734  0x02030734  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   _u32_div_f     0x0209C2B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rec {
    u8 k0;
    u8 k1;
    u8 pad[2];
    u8 data[0x20];
} Rec;

extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_02013B38(int a);
extern Rec *func_0204A39C(void *h, u32 id, u32 c, u16 heap, u32 *size);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void func_020307B0(void *p);
extern void func_02049238(void *h);

void func_021D3478(u8 *a, u32 id, int c, int d, u16 heap)
{
    u32 size;
    int found;
    void *h;
    u32 i;
    Rec *p;
    u32 hv;
    u16 v;

    found = 0;
    hv = (heap & 0x7fff) | 0x8000;
    h = func_020490F4(0xe0, hv);
    v = (func_02013B38(c) - 2) / 4 + 1;
    p = func_0204A39C(h, id, 0, hv, &size);
    for (i = 1; i < size / 0x24; i++) {
        if ((v == p[i].k0 || p[i].k0 == 0xff) && (d == p[i].k1 || p[i].k1 == 0xff)) {
            found = 1;
            break;
        }
    }
    if (!found) {
        i = 0;
    }
    *(void **)(a + 8) = func_02030734(heap, 0x20, 0, (const char *)0x021DE6D4, 0xd4);
    func_02082D44(p[i].data, *(void **)(a + 8), 0x20);
    func_020307B0(p);
    func_02049238(h);
}
