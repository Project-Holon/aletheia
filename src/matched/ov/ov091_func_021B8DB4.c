/*
 * function: func_021B8DB4
 * address:  0x021B8DB4
 * packet:   pkt_ov091_021B8DB4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB3C4  0x021BB3C4  thumb  ov091
 *   func_021BB3FC  0x021BB3FC  thumb  ov091
 *   func_02035C08  0x02035C08  arm
 *   func_021BB468  0x021BB468  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   func_021BAFA0  0x021BAFA0  thumb  ov091
 *   func_021BBE5C  0x021BBE5C  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021B9AA0  0x021B9AA0  thumb  ov091
 *   func_021B9AB4  0x021B9AB4  thumb  ov091
 *   d_021BEC2C     0x021BEC2C  data  ov091  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} Rect;

typedef struct Rect4 {
    Rect r[4];
} Rect4;

#define W(o) (*(int *)(p + (o)))

extern int  func_021BB3C4(u8 *p, int v);
extern void func_021BB3FC(u8 *p, int v, Rect *out);
extern int  func_02035C08(void *rects);
extern int  func_021BB468(u8 *p, int v);
extern void func_020061E4(u32 id);
extern void func_021BAFA0(u8 *p, int v, int z);
extern void func_021BBE5C(int h, int f);
extern void func_0204B3DC(int h, int f);
extern int  func_021B9A84(u8 *p);
extern int  func_021B9AA0(u8 *p);
extern int  func_021B9AB4(u8 *p);

extern Rect4 d_021BEC2C;

void func_021B8DB4(u8 *p)
{
    Rect list[7];
    Rect4 fixed;
    u8 map[6];
    u8 i;
    u8 n;
    int hit;
    int old;
    int r;

    n = 0;
    for (i = 0; i < 6; i++) {
        if (func_021BB3C4(p, *(int *)(p + i * 4 + 0x160)) == 1) {
            map[n] = i;
            func_021BB3FC(p, *(int *)(p + i * 4 + 0x160), &list[n]);
            n++;
        }
    }
    list[n].top = 0xff;
    hit = func_02035C08(list);
    if (hit != -1) {
        if (W(0x28) == 0 && hit <= 5 && func_021BB468(p, *(int *)(p + hit * 4 + 0x160)) == 1) {
            func_020061E4(0x557);
        } else {
            p[0xf] = 3;
            old = W(0x2c);
            W(0x2c) = map[hit];
            if (old <= 5) {
                func_021BAFA0(p, *(int *)(p + old * 4 + 0x160), 0);
            } else {
                func_021BBE5C(*(int *)(p + (u8)(old - 6) * 4 + 0x108), 0);
            }
            if (W(0x2c) <= 5) {
                func_021BAFA0(p, *(int *)(p + W(0x2c) * 4 + 0x160), 1);
            } else {
                func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
                func_0204B3DC(W(0x1d8), 0);
            }
            p[0x100] = 0xc;
        }
        W(8) = 1;
    }
    if (hit == -1) {
        fixed = d_021BEC2C;
        if (func_021B9A84(p) == 1) {
            if (func_021B9AA0(p) == 1) {
                fixed.r[1].top = 0xa8;
                fixed.r[1].bottom = 0xc0;
                fixed.r[1].left = 0xb0;
                fixed.r[1].right = 0xff;
                fixed.r[0].top = 0xa8;
                fixed.r[0].bottom = 0xc0;
                fixed.r[0].left = 0x60;
                fixed.r[0].right = 0xb0;
            } else {
                fixed.r[0].top = 0xa8;
                fixed.r[0].bottom = 0xc0;
                fixed.r[0].left = 0xb0;
                fixed.r[0].right = 0xff;
            }
        } else {
            if (func_021B9AB4(p) == 1) {
                fixed.r[1].top = 0xa8;
                fixed.r[1].bottom = 0xc0;
                fixed.r[1].left = 0xe0;
                fixed.r[1].right = 0xf8;
            }
            if (W(0x14) == 1) {
                fixed.r[2].top = 0xa8;
                fixed.r[2].bottom = 0xc0;
                fixed.r[2].left = 0xc8;
                fixed.r[2].right = 0xe0;
            }
        }
        r = func_02035C08(&fixed);
        if (r != -1) {
            p[0xf] = r;
            W(8) = 1;
        }
    }
}
