/*
 * function: func_021E3F74
 * address:  0x021E3F74
 * packet:   pkt_ov119_021E3F74
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049238  0x02049238  arm
 *   func_021E4324  0x021E4324  thumb  ov119
 */

extern void *func_020490F4(unsigned int id, unsigned short heap);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_02049238(void *);
extern void func_021E4324(char *p, int d);

void func_021E3F74(char *p)
{
    void *v;

    v = func_020490F4(0x66, *(unsigned short *)(p + 0x5F4));
    func_02049B68(v, 0x11, 4, 0, 0xC0, *(unsigned short *)(p + 0x5F4));
    *(void **)(p + 0x874) = (void *)func_02049740(v, 0xD, 7, 0, 0, *(unsigned short *)(p + 0x5F4));
    *(void **)(p + 0x870) = (void *)func_02049740(v, 0xD, 5, 0, 0, *(unsigned short *)(p + 0x5F4));
    func_02049238(v);
    func_021E4324(p, (int)(*(void **)(p + 0x874)));
}
