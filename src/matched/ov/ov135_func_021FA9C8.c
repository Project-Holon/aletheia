/*
 * function: func_021FA9C8
 * address: 0x021FA9C8
 * packet: pkt_ov135_021FA9C8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202CAE4 0x0202CAE4 thumb
 *   func_0202CF84 0x0202CF84 thumb
 *   func_021F9260 0x021F9260 thumb ov135
 *   func_021FBEB8 0x021FBEB8 thumb ov135
 *   func_02082BCC 0x02082BCC arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_021FBFB0 0x021FBFB0 thumb ov135
 *   func_021FC014 0x021FC014 thumb ov135
 *   func_021FAC50 0x021FAC50 thumb ov135
 *   func_02045808 0x02045808 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CC58 0x0202CC58 thumb
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
extern void func_021FBEB8(void *, void *, void *, u32, void *);
extern void func_02082BCC(void *, u32, u32);
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_021FBFB0(void *, int);
extern int func_021FC014(void *, int);
extern void func_021FAC50(void *, void *, void *, u32, u16, void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
void func_021FA9C8(u8 *p, int mode, int pos)
{
    int i;
    void *str;
    u16 color;
    u8 *g;
    func_0202CAE4(*(void **)(p + 24), 0, 96, mode == 6 ? 27 : 28, 1);
    func_0202CF84(*(void **)(p + 24), 0);
    func_021F9260(p, mode);
    func_021FBEB8(*(void **)(p + 24), *(void **)(p + 32), (*(void ***)p)[14], 74, p + 124);
    func_02082BCC(p + 96, 1, 26);
    g = p;
    g += 124;
    for (i = 0; i < 9; i++) {
        str = func_02045EC0(*(void **)(p + 32), i + 116);
        if (mode == 4) {
            if (func_021FBFB0(p, i) == 1) {
                color = 0x3dc2;
                p[i + 96] = 1;
            } else {
                color = 0x2122;
                p[i + 96] = 0;
            }
        } else {
            if (func_021FC014(p, i) == 1) {
                color = 0x3dc2;
                p[i + 96] = 1;
            } else {
                color = 0x2122;
                p[i + 96] = 0;
            }
        }
        func_021FAC50(*(void **)(p + 24), (*(void ***)p)[i], str, 2, color, g);
        func_02045808(str);
    }
    if (mode == 6) {
        str = func_02045EC0(*(void **)(p + 32), 188);
        func_021FAC50(*(void **)(p + 24), (*(void ***)p)[15], str, 2, 0x3dc2, p + 124);
        func_02045808(str);
    }
    func_0202CB4C(*(void **)(p + 24), 0, pos, 0);
    func_0202CC58(*(void **)(p + 24), 0);
}
