/*
 * function: func_02192264
 * address:  0x02192264
 * packet:   pkt_ov021_02192264
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm  arm9
 *   func_020437D4  0x020437D4  arm  arm9
 *   func_0204A1BC  0x0204A1BC  arm  arm9
 *   func_02062A4C  0x02062A4C  arm  arm9
 *   func_02082EA4  0x02082EA4  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct CharData {
    u8  pad[0x14];
    u8 *raw;
} CharData;

extern u8 *func_020437D4(u32 a);
extern void *func_0204A1BC(u32 a, u32 b, u32 c, u32 d);
extern int func_02062A4C(void *buf, CharData **out);
extern void func_02082EA4(void *dst, void *src, u32 n);
extern void func_020307B0(void *p);

void func_02192264(u32 a, u32 unused, u32 heap, u32 idx)
{
    enum { Z } i = Z;
    u8 *src;
    void *buf;
    CharData *cd;

    src = func_020437D4(a);
    buf = func_0204A1BC(5, 8, 0, heap);
    func_02062A4C(buf, &cd);
    func_02082EA4(cd->raw + i * 32 + idx * 32, src, 0x20);
    func_020307B0(buf);
}
