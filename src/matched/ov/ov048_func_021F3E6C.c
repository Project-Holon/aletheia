/*
 * function: func_021F3E6C
 * address:  0x021F3E6C
 * packet:   pkt_ov048_021F3E6C
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021F3E6C  0x021F3E6C  thumb  ov048
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02088864  0x02088864  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F230  0x0201F230  thumb
 *   func_021F3D38  0x021F3D38  thumb  ov048
 *   func_0201ED04  0x0201ED04  thumb
 *   d_021F50C0     0x021F50C0  data  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;
struct WordSet;
struct Date { int a, b, c, d; };
struct Rec { u16 h; u32 f4, f8, fc, f10, f14, f18; };
struct Tab { u16 pad[2]; u16 h4; };
struct T { u16 a0, a1, h, a3; u32 pad[9]; u32 f2c; u32 pad2[6]; u32 f48; };
extern struct T d_021F50C0;

extern struct WordSet *func_0201EC64(u32 heap);
struct RTCDate;
extern int func_02088864(struct RTCDate *date);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F230(struct WordSet *p, u32 i, u32 v);
extern void func_021F3D38(int *p, int a, int b, int *c);
extern u32 func_0201ED04(struct WordSet *p);

void func_021F3E6C(int *p)
{
    struct { struct Date d; struct Rec r; } L;
    struct WordSet *w;

    w = func_0201EC64(*(u16 *)p);
    func_02088864((struct RTCDate *)(&L.d));
    func_0201EFA4(w, 2, L.d.a, 2, 2, 1);
    func_0201F230(w, 0, L.d.b);
    func_0201EFA4(w, 1, L.d.c, 2, 0, 1);
    L.r.h = d_021F50C0.h;
    L.r.f4 = d_021F50C0.f2c;
    L.r.f8 = d_021F50C0.f48;
    L.r.fc = 2;
    L.r.f10 = 0x26;
    L.r.f14 = *(u32 *)(*(u32 *)((u32)p + 0x1c) + 0x18);
    L.r.f18 = (u32)w;
    func_021F3D38(p, (int)(&L.r), 1, 0);
    func_0201ED04(w);
}
