/*
 * function: sub_02010A5C
 * address:  0x02010A5C
 * packet:   pkt_02010A5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   sub_020124F4   0x020124F4  thumb
 *   sub_02012EBC   0x02012EBC  thumb
 *   sub_02009448   0x02009448  thumb
 *   sub_020092EC   0x020092EC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  func_0203064C(int a, int b, int c);
extern u8   *func_0203159C(void *a, int b, int c);
extern void  func_02082BCC(void *dst, int val, unsigned n);
extern void *sub_020124F4(u16 heap);
extern void *sub_02012EBC(void *p);
extern void *sub_02009448(void *sys);
extern u8    sub_020092EC(const void *obj);

int sub_02010A5C(void *a0)
{
    u8 *p;
    void *sys;

    func_0203064C(1, 0x67, 0x78000);
    p = func_0203159C(a0, 0x1d8, 0x67);
    func_02082BCC(p, 0, 0x1d8);
    *(u16 *)(p + 0x1d0) = 0x67;
    sys = sub_020124F4(0x67);
    *(void **)(p + 0x44) = sys;
    if (sub_020092EC(sub_02009448(sub_02012EBC(sys))) != 0) {
        *(u32 *)(p + 0x1d4) = 1;
        *(u32 *)(p + 0x54) = 1;
    } else {
        *(u32 *)(p + 0x1d4) = 0;
        *(u32 *)(p + 0x54) = 0;
    }
    return 1;
}
