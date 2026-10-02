/*
 * function: func_021B9A50
 * address:  0x021B9A50
 * packet:   pkt_ov069_021B9A50
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020275E4  0x020275E4  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   d_020A1448     0x020A1448  data  a4
 *   d_021BA620     0x021BA620  data  a4
 *   func_0204B100  0x0204B100  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02027618  0x02027618  thumb
 *   func_02027614  0x02027614  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;

extern u8 d_020A1448[];
extern u8 d_021BA620[];
extern u32 func_020275E4(void);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_0204A48C(void *, void *, u32);
extern u32 func_0204B100(u32 a, u32 b, u32 heap);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204A6C8(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern u32 func_0204ABF0(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern u32 func_0204AF28(void *arc, u32 a, u32 b, u32 heap);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern u32 func_0204AC18(void *arc, u32 id, u32 a, u32 b, u32 c, u32 d, u32 heap);
extern void func_02049238(void *h);

void func_021B9A50(u8 *p)
{
    void *h;
    u32 t;

    h = func_020490F4(func_020275E4(), 0x80);
    func_0204A48C(d_020A1448, d_021BA620, 0x80);
    *(u32 *)(p + 0x11C) = func_0204B100(4, 1, 0x80);
    *(u32 *)(p + 0x120) = func_0204B100(2, 1, 0x80);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    *(u32 *)(p + 0x138) = func_0204A6C8(*(void **)p, 7, 1, 2, 0x80);
    *(u32 *)(p + 0x134) = func_0204ABF0(*(void **)p, 10, 2, 0, 0x80);
    *(u32 *)(p + 0x13C) = func_0204AF28(*(void **)p, 8, 9, 0x80);
    *(u32 *)(p + 0x144) = func_0204A6C8(h, func_02027618(), 0, 0, 0x80);
    *(u32 *)(p + 0x140) = func_0204AC18(h, func_02027614(), 0, 0x160, 0, 3, 0x80);
    t = func_0202761C(0);
    *(u32 *)(p + 0x148) = func_0204AF28(h, t, func_02027620(0), 0x80);
    func_02049238(h);
}
