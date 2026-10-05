/*
 * function: ov208_func_021C0544
 * address:  0x021C0544
 * packet:   pkt_ov208_021C0544
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: 2026-10-05 (D5-03): closed. func_02166CD0 takes two arguments (key handle, message id),
 *   as in its matched definition; the 0x10 field read is passed as the second one. The image
 *   copies the result to r1 for that call, which was the old "sentinel compare" residue.
 * symbols:
 *   ov208_func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_021BBB3C  0x021BBB3C  thumb  ov072
 *   func_02166CD0  0x02166CD0  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

extern int  ov208_func_021BC3A4(int key);
extern u16  func_021BBB3C(u32 tbl, int idx, int field);
extern int  func_02166CD0(int a, u32 msg);
extern u32  func_0204B294(u32 res, u32 a, u32 b, u32 c, ObjPos *pos, u32 f, u32 heap);
extern void func_0204B92C(u32 obj, int v);
extern void func_0204B3DC(u32 obj, int on);
extern void func_0204B688(u32 obj, u32 on);

#define W(o) (*(u32 *)(p + (o)))

void ov208_func_021C0544(u16 *heap, u8 *p, int key)
{
    int k;
    u8 i;
    u16 kind;
    u16 msg;
    ObjPos pos;

    k = ov208_func_021BC3A4(key);
    for (i = 0; i < 0x3d; i++) {
        msg = func_021BBB3C(W(0x3c8), i, 0x10);
        if (msg != 0xffff) {
            if ((func_02166CD0(k, msg) == 0 ? 1 : 0)) {
                *(u32 *)(p + i * 8 + 0x1e0) = 1;
                *(u32 *)(p + i * 8 + 0x1e4) = 0;
            } else {
                kind = func_021BBB3C(W(0x3c8), i, 0xb);
                pos.x = func_021BBB3C(W(0x3c8), i, 2);
                pos.y = func_021BBB3C(W(0x3c8), i, 3);
                pos.z = kind == 4 ? 0xe : 0x10;
                pos.pri = 5;
                pos.f7 = 2;
                *(u32 *)(p + i * 8 + 0x1e0) = 2;
                *(u32 *)(p + i * 8 + 0x1e4) = func_0204B294(W(0x1d0), W(0x98), W(0x9c), W(0xa0), &pos, 0, *heap);
                func_0204B92C(*(u32 *)(p + i * 8 + 0x1e4), 1);
                func_0204B3DC(*(u32 *)(p + i * 8 + 0x1e4), 1);
                func_0204B688(*(u32 *)(p + i * 8 + 0x1e4), 1);
            }
        } else {
            *(u32 *)(p + i * 8 + 0x1e0) = 0;
            *(u32 *)(p + i * 8 + 0x1e4) = 0;
        }
    }
}
