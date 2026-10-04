/*
 * function: ov208_func_021BE128
 * address:  0x021BE128
 * packet:   pkt_ov208_021BE128
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02049F34  0x02049F34  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Pltt {
    u32 pad0[3];
    u8 *data;
};

extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(void *src, void *dst, u32 size);
extern void func_020307B0(void *p);

void ov208_func_021BE128(u8 *p)
{
    struct Ov208Pltt *pltt;
    u32 file;
    u8 *data;

    file = (u32)func_02049F34(0x9f, 3, (u32)(&pltt), *(u16 *)p);
    data = pltt->data;
    func_02082D44(data + 0x20, p + 0xb6, 0x20);
    func_02082D44(data + 0x60, p + 0xd6, 0x20);
    func_020307B0((void *)file);
    *(u32 *)(p + 0x118) = 0;
}
