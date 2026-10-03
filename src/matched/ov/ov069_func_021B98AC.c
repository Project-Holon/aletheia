/*
 * function: func_021B98AC
 * address:  0x021B98AC
 * packet:   pkt_ov069_021B98AC
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020275E4  0x020275E4  thumb
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0202C9B4  0x0202C9B4  thumb
 *   func_0202CA3C  0x0202CA3C  thumb
 *   func_0202CB18  0x0202CB18  thumb
 *   func_0202CB4C  0x0202CB4C  thumb
 *   d_021BA66C     0x021BA66C  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;

typedef struct {
    int x;
    int y;
} Pos;

struct WinMgr;
extern const Pos d_021BA66C[];

extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049238(void *arc);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CB18(struct WinMgr *mgr, u32 idx, void *arc, u32 member, u32 alloc);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);

void func_021B98AC(u8 *p)
{
    void *arc = *(void **)p;
    void *arc2;
    int i;

    func_02049658(arc, 5, 5, 0, 0, 1, 0x80);
    func_020498F4(arc, 4, 5, 0, 0, 1, 0x80);
    func_02049B68(arc, 6, 4, 0, 0, 0x80);
    func_02049658(arc, 1, 2, 0, 0, 1, 0x80);
    func_020498F4(arc, 0, 2, 0, 0, 1, 0x80);
    func_02049B68(arc, 2, 0, 0, 0, 0x80);
    func_02049658(arc, 1, 1, 0, 0, 1, 0x80);
    func_020498F4(arc, 0, 1, 0, 0, 1, 0x80);
    arc2 = func_020490F4(func_020275E4(), 0x80);
    func_02049658(arc2, func_02027628(), 1, 0, 0, 0, 0x80);
    func_020498F4(arc2, func_0202762C(), 1, 0, 0, 0, 0x80);
    func_02049BDC(arc2, func_02027624(), 0, 0, 0x1C0, 0x20, 0x80);
    func_020413B0(1, 0, 0x15, 0x20, 3, 0xE);
    func_020409B4(1);
    func_02049238(arc2);
    func_02049B40(0x17, 5, 0, 0x1E0, 0x20, 0x80);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x80);
    *(void **)(p + 4) = func_0202C9B4(2, 10, 0x80);
    for (i = 0; i < 10; i++) {
        func_0202CA3C(*(void **)(p + 4), i, 1, 0xE, 4);
        func_0202CB18(*(void **)(p + 4), i, arc, 3, 1);
        func_0202CB4C(*(void **)(p + 4), i, d_021BA66C[i].x, d_021BA66C[i].y);
    }
}
