/*
 * function: func_021FAAD4
 * address: 0x021FAAD4
 * packet: pkt_ov135_021FAAD4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202CAE4 0x0202CAE4 thumb
 *   func_0202CF84 0x0202CF84 thumb
 *   func_021F9260 0x021F9260 thumb ov135
 *   func_02045EC0 0x02045EC0 arm
 *   func_021FAC50 0x021FAC50 thumb ov135
 *   func_02045808 0x02045808 arm
 *   func_021FBEB8 0x021FBEB8 thumb ov135
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   func_0202CD64 0x0202CD64 thumb
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021FAC50(void *, void *, void *, u32, u16, void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_021FBEB8(void *, void *, void *, u32, void *);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
void func_021FAAD4(u8 *p)
{
    int i;
    void *str;
    func_0202CAE4(*(void **)(p + 24), 0, 96, 25, 1);
    func_0202CF84(*(void **)(p + 24), 0);
    func_021F9260(p, 1);
    for (i = 0; i < 3; i++) {
        str = func_02045EC0(*(void **)(p + 32), i + 130);
        func_021FAC50(*(void **)(p + 24), (*(void ***)p)[i], str, 2, 0x3dc2, p + 124);
        func_02045808(str);
    }
    func_021FBEB8(*(void **)(p + 24), *(void **)(p + 32), (*(void ***)p)[14], 74, p + 124);
    func_0202CB4C(*(void **)(p + 24), 0, 32, 0);
    func_0202CC58(*(void **)(p + 24), 0);
    func_0202CD64(*(void **)(p + 24), 0, -4, 0, 4);
}
