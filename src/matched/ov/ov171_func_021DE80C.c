/*
 * function: func_021DE80C
 * address: 0x021DE80C
 * packet: pkt_ov171_021DE80C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025538 0x02025538 thumb
 *   func_02043678 0x02043678 arm
 *   func_020255A0 0x020255A0 thumb
 *   func_02025774 0x02025774 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Descriptor {
    void *image;
    u16 x, y;
    void *source;
    u32 mode;
    u8 a, b;
    u16 id;
    u32 extra;
} Descriptor;
extern void *func_02025538(unsigned int a0, void *a1);
extern void *func_02043678(int, int, int, u16);
extern void *func_020255A0(void *, Descriptor *);
extern void func_02025774(void *, int);
void func_021DE80C(char *p)
{
    Descriptor descriptor;
    *(void **)(p + 0xC50) = func_02025538(0x8C, *(void **)(p + 0xB70));
    *(void **)(p + 0xC58) = func_02043678(5, 3, 0x20, 0x8C);
    descriptor.image = *(void **)(p + 0xC58);
    descriptor.x = 0x28;
    descriptor.y = 0xA8;
    descriptor.source = *(void **)(p + 0xC18);
    descriptor.mode = 1;
    descriptor.a = 0;
    descriptor.b = 0;
    descriptor.id = 0xFFFF;
    descriptor.extra = 0;
    *(void **)(p + 0xC54) = func_020255A0(*(void **)(p + 0xC50), &descriptor);
    if (*(u8 *)(p + 0xC5F) == 1) func_02025774(*(void **)(p + 0xC54), 0);
}
