/*
 * function: func_022001F4
 * address: 0x022001F4
 * packet: pkt_ov135_022001F4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0203D34C 0x0203D34C arm
 *   d_022038E0 0x022038E0 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x, y, z; u8 pri, f7; } ObjPos;
typedef struct { u16 x, y; } Pair;
extern const Pair d_022038E0[];
extern void *func_0204B294(void *, void *, void *, void *, ObjPos *, int, int);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0203D34C(u32 a, u32 b);
void func_022001F4(u8 *p)
{
    ObjPos pos;
    pos.x = d_022038E0[*(u16 *)(p + 0xC0)].x;
    pos.y = d_022038E0[*(u16 *)(p + 0xC0)].y;
    pos.z = 0;
    pos.pri = 0;
    pos.f7 = 1;
    *(void **)(p + 0xBF4) = func_0204B294(*(void **)(p + 0xBC0), *(void **)(p + 0xBE8), *(void **)(p + 0xBC8), *(void **)(p + 0xBF0), &pos, 0, 0x48);
    func_0204B92C(*(void **)(p + 0xBF4), 1);
    func_0204B878(*(void **)(p + 0xBF4), 0);
    if (func_020355C4() == 1) {
        func_0204B3DC(*(void **)(p + 0xBF4), 0);
    } else {
        func_0204B878(*(void **)(p + 0xBF4), 0);
        func_0204B3DC(*(void **)(p + 0xBF4), 1);
    }
    func_0203D34C(0, 0x48);
}
