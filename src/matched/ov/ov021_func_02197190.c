/*
 * function: func_02197190
 * address:  0x02197190
 * packet:   pkt_ov021_02197190
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D3FA0     0x021D3FA0  data   a1
 *   d_021D3F8C     0x021D3F8C  data   a1
 *   d_021D3F94     0x021D3F94  data   a1
 *   func_02197058  0x02197058  thumb  ov021
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 a, b, c; u8 d, e; } Rect;
typedef struct { u8 v[3]; } B3;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int arr[3];
} Sub;

typedef struct {
    u8 pad0[0x10];
    u16 f10;
    u8 pad12[0x26C - 0x12];
    Sub sub;
} Obj;

extern const B3 d_021D3FA0;
extern const B3 d_021D3F8C;
extern const B3 d_021D3F94;
extern void func_02197058(Obj *);
extern int func_0204B294(int, int, int, int, Rect *, int, int);
extern void func_0204B92C(int, int);
extern void func_0204B3DC(int, int);
extern void func_0204B688(int, int);

void func_02197190(Obj *p)
{
    B3 x0 = d_021D3FA0;
    B3 x1 = d_021D3F8C;
    B3 x2 = d_021D3F94;
    Rect r;
    int i;

    func_02197058(p);
    for (i = 0; i < 3; i++) {
        r.a = x0.v[i];
        r.b = x1.v[i];
        r.c = x2.v[i];
        r.d = 0;
        r.e = 1;
        p->sub.arr[i] = func_0204B294(p->sub.f0, p->sub.f10, p->sub.f8, p->sub.f18, &r, 1, p->f10);
        func_0204B92C(p->sub.arr[i], 0);
        func_0204B3DC(p->sub.arr[i], 1);
        func_0204B688(p->sub.arr[i], 1);
    }
}
