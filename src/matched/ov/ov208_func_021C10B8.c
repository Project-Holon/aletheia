/*
 * function: func_021C10B8
 * address:  0x021C10B8
 * packet:   pkt_ov208_021C10B8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC3B4  0x021BC3B4  thumb  ov208
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_020355D8  0x020355D8  arm
 *   func_02035D20  0x02035D20  arm
 *   func_021BDC48  0x021BDC48  thumb  ov208
 *   func_021C1E10  0x021C1E10  thumb  ov208
 *   func_021C1920  0x021C1920  thumb  ov208
 *   func_021C1450  0x021C1450  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021BC3B4(int key);
extern u32  func_020362DC(void);
extern u32  func_0203633C(void);
extern void func_020061E4(int se);
extern void func_020355D8(int v);
extern int  func_02035D20(u32 *x, u32 *y);
extern void func_021BDC48(void *s, u32 on);
extern void func_021C1E10(u16 *heap, u8 *p, int key, int dir, int touch);
extern void func_021C1920(u16 *heap, u8 *p, int key, int mode);
extern void func_021C1450(u16 *heap, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))

void func_021C10B8(u16 *heap, u8 *p, int key)
{
    void *s;
    int hit, touch;
    int moved, done;
    u32 x, y, tx, ty;

    s = func_021BC3B4(key);
    if (W(0x428) == 0 || p[0xd8] != 7)
        return;

    switch (W(0x6c)) {
    case 0:
        hit = 0;
        touch = 0;
        if (func_020362DC() & 1) {
            touch = 1;
            hit = 1;
        } else if (W(0x8c) != 0) {
            if (func_0203633C() & 0x100) {
                p[0x78]++;
                if (p[0x78] >= 4)
                    p[0x78] = 0;
                hit = 1;
                func_021C1E10(heap, p, key, 1, 0);
                func_020061E4(0x54a);
            } else if (func_0203633C() & 0x200) {
                if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                func_021C1E10(heap, p, key, 0, 0);
                func_020061E4(0x54a);
                hit = 1;
            }
        }
        if (hit) {
            func_020355D8(0);
            if (touch)
                W(0x7c) = 0;
        }
        if (hit == 0) {
            if (func_02035D20(&x, &y)) {
                if (W(0x8c) == 0) {
                    if (y < 0xa8) {
                        touch = 1;
                        hit = 1;
                    }
                } else if (x >= 0x88 && x < 0xa0 && y < 0x10) {
                    p[0x78]++;
                    if (p[0x78] >= 4)
                        p[0x78] = 0;
                    hit = 1;
                    func_021C1E10(heap, p, key, 1, hit);
                    func_020061E4(0x54a);
                } else if (x < 0x18 && y < 0x10) {
                    if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                    hit = 1;
                    func_021C1E10(heap, p, key, 0, hit);
                    func_020061E4(0x54a);
                } else if ((x >= 0xa0 || y >= 0x18) && y < 0xa8) {
                    touch = 1;
                    hit = 1;
                }
            }
            if (hit) {
                hit = 1;
                func_020355D8(1);
                if (touch) {
                    W(0x7c) = hit;
                    p[0x80] = x;
                    p[0x81] = y;
                }
            }
        }
        if (touch && (W(0x8c) != 0 || W(0x90) != 0)) {
            func_021C1920(heap, p, key, 1);
            func_020061E4(0x54c);
            func_021BDC48(s, 0);
        }
        break;
    case 5:
        moved = 0;
        done = 1;
        if (func_020362DC() & 2) {
            W(0x428) = 0;
            moved = 1;
            done = 0;
        } else if (W(0x8c) != 0) {
            if (func_0203633C() & 0x100) {
                p[0x78]++;
                if (p[0x78] >= 4)
                    p[0x78] = 0;
                done = 0;
                func_021C1E10(heap, p, key, 1, done);
                moved = 1;
                func_020061E4(0x54a);
            } else if (func_0203633C() & 0x200) {
                if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                done = 0;
                func_021C1E10(heap, p, key, 0, 0);
                func_020061E4(0x54a);
                moved = 1;
            }
        }
        if (moved)
            func_020355D8(0);
        if (moved == 0) {
            if (func_02035D20(&tx, &ty)) {
                if (W(0x8c) == 0) {
                    if (ty >= 0xa8)
                        done = 0;
                } else if (W(0x8c) == 1) {
                    if (tx >= 0x88 && tx < 0xa0 && ty < 0x10) {
                        p[0x78]++;
                        if (p[0x78] >= 4)
                            p[0x78] = 0;
                        moved = 1;
                        func_021C1E10(heap, p, key, 1, moved);
                        func_020061E4(0x54a);
                        done = 0;
                    } else if (tx < 0x18 && ty < 0x10) {
                        if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                        moved = 1;
                        func_021C1E10(heap, p, key, 0, moved);
                        done = 0;
                        func_020061E4(0x54a);
                    } else if (tx < 0xa0 && ty < 0x18) {
                        done = 0;
                    } else if (ty >= 0xa8) {
                        done = 0;
                    }
                }
            }
            if (moved)
                func_020355D8(1);
        }
        if (done)
            func_021C1450(heap, p, key);
        break;
    }
}
