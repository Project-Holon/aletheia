/*
 * function: ov208_func_021C0544
 * address:  0x021C0544
 * packet:   pkt_ov208_021C0544
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note: 2026-10-04 (D2-13): func_021BBB3C returning int gives the right size (348) and leaves only the sentinel residue (60 bytes out incl. shift), with or without an int local `v = f(); v != 0xffff`. Image copies r0 to r1 and loads 0xffff into r0 (cmp r1,r0); compiled loads 0xffff into r1 (cmp r0,r1). Not closed.
 * blocker:  codegen, 2 bytes (one instruction): the image moves the sentinel lookup
 *           result to r1 and loads 0xffff into r0 (adds r1, r0, #0; ldr r0, =0xffff;
 *           cmp r1, r0); the draft compares r0 against r1. Everything after it is the
 *           same code shifted by 2 bytes. See docs/notes/pkt_ov208_021C0544.c.txt.
 * note: 2026-10-05 (wave D4 lane 02): residue unchanged (sentinel test at the loop head). Tried:
 *         `int r = f(); if (r != 0xffff)`, a local `int none = 0xffff` in the loop body, kind as int
 *         with an int callee (344 bytes again), the assignment inside the condition
 *         `(kind = f(..0x10)) != 0xffff`, `!(f() == 0xffff)`, inline helpers (Has, Get). All keep
 *         `ldr r1, =0xffff; cmp r0, r1`. The cue from 021C4F78 (a result copied to r1 is a later
 *         second argument) does not apply here: r1 is dead after the compare.
 *
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
extern int  func_02166CD0(int a);
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
    ObjPos pos;

    k = ov208_func_021BC3A4(key);
    for (i = 0; i < 0x3d; i++) {
        if (func_021BBB3C(W(0x3c8), i, 0x10) != 0xffff) {
            if ((func_02166CD0(k) == 0 ? 1 : 0)) {
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
