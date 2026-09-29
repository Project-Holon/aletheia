/*
 * function: func_021BA028
 * address:  0x021BA028
 * packet:   pkt_ov070_021BA028
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    short a, b, c;
    u8 d, e;
} Rect;

extern int func_0204B294(int, int, int, int, Rect *, int, u16);
extern void func_0204B3DC(int, int);
extern void func_0204B92C(int, int);
extern void func_021BA6A4(char *);

void func_021BA028(char *p)
{
    Rect r1;
    Rect r2;
    Rect r3;
    int i;

    r1.a = 0xf8;
    r1.b = 0x1a;
    r1.d = 1;
    r1.e = 2;
    r1.c = 0;
    *(int *)(p + 0x6A8) = func_0204B294(*(int *)(p + 0x69C), *(int *)(p + 0x560), *(int *)(p + 0x554), *(int *)(p + 0x568), &r1, 0, *(u16 *)(p + 0x544));
    func_0204B3DC(*(int *)(p + 0x6A8), 1);
    func_0204B92C(*(int *)(p + 0x6A8), 1);
    func_021BA6A4(p);
    r2.a = 0x8c;
    r2.b = 0x30;
    r2.d = 1;
    r2.e = 2;
    r2.c = 1;
    *(int *)(p + 0x6A4) = func_0204B294(*(int *)(p + 0x69C), *(int *)(p + 0x560), *(int *)(p + 0x554), *(int *)(p + 0x568), &r2, 0, *(u16 *)(p + 0x544));
    func_0204B3DC(*(int *)(p + 0x6A4), 1);
    func_0204B92C(*(int *)(p + 0x6A4), 1);
    for (i = 0; i < 8; i++) {
        r3.a = 0x8c;
        r3.b = i * 0x18;
        r3.d = 0xa;
        r3.e = 3;
        r3.c = 0;
        *(int *)(p + i * 4 + 0x634) = func_0204B294(*(int *)(p + 0x69C), *(int *)(p + i * 4 + 0x5F4), *(int *)(p + 0x588), *(int *)(p + 0x56C), &r3, 0, *(u16 *)(p + 0x544));
        r3.a -= 0x18;
        r3.c = 1;
        *(int *)(p + i * 4 + 0x674) = func_0204B294(*(int *)(p + 0x69C), *(int *)(p + 0x578), *(int *)(p + 0x574), *(int *)(p + 0x57C), &r3, 0, *(u16 *)(p + 0x544));
        func_0204B3DC(*(int *)(p + i * 4 + 0x634), 0);
        func_0204B3DC(*(int *)(p + i * 4 + 0x674), 0);
    }
}
