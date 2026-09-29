/*
 * function: func_021B709C
 * address:  0x021B709C
 * packet:   pkt_ov091_021B709C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} R;

extern u32 func_0204B100(u32 a, u32 b, u32 heap);
extern void func_0204B270(void);
extern int func_0204B294(int a, int b, int c, int d, R *r, int f, u16 g);
extern void func_0204B3DC(int a, int b);
extern void func_0204B92C(int a, int b);

void func_021B709C(u8 *p)
{
    R b;
    R a;
    int x;

    *(u32 *)(p + 0x1d4) = func_0204B100(10, 8, *(u16 *)p);
    func_0204B270();
    b.a = 0;
    b.b = 0;
    b.c = 0;
    b.d = 10;
    b.e = 3;
    *(int *)(p + 0x1d8) = func_0204B294(*(int *)(p + 0x1d4), *(int *)(p + 0x198),
                                        *(int *)(p + 0x178), *(int *)(p + 0x1b4), &b, 0, *(u16 *)p);
    *(int *)(p + 0x1dc) = func_0204B294(*(int *)(p + 0x1d4), *(int *)(p + 0x198),
                                        *(int *)(p + 0x178), *(int *)(p + 0x1b4), &b, 0, *(u16 *)p);
    func_0204B92C(*(int *)(p + 0x1d8), 1);
    func_0204B92C(*(int *)(p + 0x1dc), 1);
    func_0204B3DC(*(int *)(p + 0x1d8), 0);
    func_0204B3DC(*(int *)(p + 0x1dc), 0);
    a.a = 0xe0;
    a.b = 0xa8;
    a.c = 1;
    a.d = 0;
    a.e = 0;
    x = func_0204B294(*(int *)(p + 0x1d4), *(int *)(p + 0x1a0),
                      *(int *)(p + 0x17c), *(int *)(p + 0x1bc), &a, 0, *(u16 *)p);
    *(int *)(p + 0x1e0) = x;
    func_0204B92C(x, 1);
    a.a = 0xc4;
    a.c = 0;
    x = func_0204B294(*(int *)(p + 0x1d4), *(int *)(p + 0x1a0),
                      *(int *)(p + 0x17c), *(int *)(p + 0x1bc), &a, 0, *(u16 *)p);
    *(int *)(p + 0x1e4) = x;
    func_0204B92C(x, 1);
}
