/*
 * function: func_021C6D9C
 * address:  0x021C6D9C
 * packet:   pkt_ov111_021C6D9C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   d_020A1448     0x020A1448  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 heap;
    u8 pad2[2];
    u32 f4;
    u8 pad8[0xB8 - 8];
    u32 fB8;
    u32 fBC;
    u32 fC0;
    u32 fC4;
    u32 fC8;
    u32 fCC;
} Anim;

extern void *func_020490F4(unsigned int id, u16 heap);
struct Cfg;
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern const u8 d_020A1448[];
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
typedef signed int     s32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern u32 func_020275E4(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);

void func_021C6D9C(Anim *a, u32 x)
{
    void *h;

    h = func_020490F4(0x28, a->heap);
    func_0204A48C((const struct Cfg *)d_020A1448, x, a->heap);
    a->f4 = (u32)func_0204B100(0x23, 0, a->heap);
    a->fB8 = func_0204AC18(h, 0xC, 1, 0, 0, 5, a->heap);
    a->fBC = func_0204A6C8(h, 0x1D, 0, 1, a->heap);
    a->fC0 = func_0204AF28(h, 0x2E, 0x30, a->heap);
    func_02049238(h);
    h = func_020490F4(func_020275E4(), a->heap);
    a->fC4 = func_0204ABF0(h, func_02027614(), 1, 0xA0, a->heap);
    a->fC8 = func_0204A6C8(h, func_02027618(), 0, 1, a->heap);
    a->fCC = func_0204AF28(h, func_0202761C(0), func_02027620(0), a->heap);
    func_02049238(h);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
