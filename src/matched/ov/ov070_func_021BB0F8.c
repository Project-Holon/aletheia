/*
 * function: func_021BB0F8
 * address:  0x021BB0F8
 * packet:   pkt_ov070_021BB0F8
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02027778  0x02027778  thumb
 *   func_02045808  0x02045808  arm
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    u8 b;
    u8 pad[3];
    int c;
    int d;
    u8 e;
    u8 f;
    u8 g;
    u8 h;
} Desc;

extern int func_020457B0(int, int);
extern void func_02045CAC(int, int, int);
extern int func_02027778(Desc *, int);
extern void func_02045808(int);
extern void func_021BB580(int, int);
extern void func_021BB3F4(int, int);

void func_021BB0F8(int p)
{
    Desc s;
    int h;
    int r;

    h = *(u16 *)(p + 0x544);
    s.a = h;
    s.b = 2;
    s.c = p + 0x780;
    s.d = 1;
    s.e = 0x20;
    s.f = 0xC;
    s.g = 8;
    s.h = 3;
    r = func_020457B0(0x64, h);
    *(int *)(p + 0x780) = r;
    func_02045CAC(*(int *)(p + 0x51C), 0x84, r);
    *(u16 *)(p + 0x784) = 0x39E0;
    *(int *)(p + 0x788) = 0;
    r = func_020457B0(0x64, *(u16 *)(p + 0x544));
    *(int *)(p + 0x78C) = r;
    func_02045CAC(*(int *)(p + 0x51C), 0x85, r);
    *(u16 *)(p + 0x790) = 0x39E0;
    *(int *)(p + 0x794) = 0;
    *(int *)(p + 0x77C) = func_02027778(&s, *(int *)(p + 0x7E0));
    func_02045808(*(int *)(p + 0x780));
    func_02045808(*(int *)(p + 0x78C));
    func_021BB580(p, 0);
    func_021BB3F4(p, 0);
}
