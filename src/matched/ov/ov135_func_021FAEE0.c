/*
 * function: func_021FAEE0
 * address: 0x021FAEE0
 * packet: pkt_ov135_021FAEE0
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
 *   func_021FAC50 0x021FAC50 thumb ov135
 *   func_02045808 0x02045808 arm
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020355C4 0x020355C4 arm
 *   tbl_022032C6 0x022032C6 data a1
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 x; u8 y; } CurPos;
typedef signed char s8;
struct WinMgr;
extern const CurPos tbl_022032C6[];
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
extern void func_021FBEB8(void *, void *, void *, u32, void *);
extern void func_02082BCC(void *, u32, u32);
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_021FBFB0(void *, int);
extern void func_021FAC50(void *, void *, void *, u32, u16, void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021F4FF4(u32, u32, u32);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u8 func_020355C4(void);
int func_021FAEE0(u8 *p)
{
    int i;
    void *str;
    u16 color;
    u8 *g;
    func_0202CAE4(*(void **)(p + 24), 0, 96, 28, 1);
    func_0202CF84(*(void **)(p + 24), 0);
    func_021F9260(p, 4);
    func_021FBEB8(*(void **)(p + 24), *(void **)(p + 32), (*(void ***)p)[14], 74, p + 124);
    func_02082BCC(p + 96, 1, 26);
    g = p + 124;
    for (i = 0; i < 9; i++) {
        str = func_02045EC0(*(void **)(p + 32), i + 116);
        if (func_021FBFB0(p, i) == 1) {
            color = 0x3dc2;
            p[i + 96] = 1;
        } else {
            color = 0x2122;
            p[i + 96] = 0;
        }
        func_021FAC50(*(void **)(p + 24), (*(void ***)p)[i], str, 2, color, g);
        func_02045808(str);
    }
    func_0202CB4C(*(void **)(p + 24), 0, 16, 0);
    func_0202CC58(*(void **)(p + 24), 0);
    func_0204B878((struct Obj *)(*(u32 *)(p + 8)), 18);
    func_021F4FF4(*(u32 *)(p + 8), (tbl_022032C6[*(s16 *)(p + 56)].x + 16) * 8, tbl_022032C6[*(s16 *)(p + 56)].y * 8);
    *(int *)(p + 68) = *(s16 *)(p + 56);
    func_0204B3DC((struct Obj *)*(u32 *)(p + 8), 1);
    *(int *)(p + 72) = 7;
    if (func_020355C4() == 1)
        func_0204B3DC((struct Obj *)*(u32 *)(p + 8), 0);
    else
        func_0204B3DC((struct Obj *)*(u32 *)(p + 8), 1);
    return -1;
}
