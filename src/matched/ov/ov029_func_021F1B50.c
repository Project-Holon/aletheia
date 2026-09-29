/*
 * function: func_021F1B50
 * address:  0x021F1B50
 * packet:   pkt_ov029_021F1B50
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B954  0x0204B954  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_0204B92C  0x0204B92C  arm
 */

typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned char a;
    unsigned char b;
} S13Rec;

extern int func_0204B294(int, int, int, int, S13Rec *, int, int);
extern void func_0204B3DC(int, int);
extern void func_0204B954(int, int);
extern void func_0204B9A0(int);
extern void func_0204B92C(int, int);

void func_021F1B50(char *p)
{
    int i;
    S13Rec s;
    int *q;

    for (i = 0; i < 18; i++) {
        s.x = 0x80;
        s.y = 0x60;
        s.z = i + 0x12;
        s.a = 0;
        s.b = 2;
        q = (int *)(p + i * 4);
        q[0x5c] = func_0204B294(*(int *)(p + 0x34), *(int *)(p + 0x2c), *(int *)(p + 0x28),
                                *(int *)(p + 0x30), &s, 0, *(unsigned short *)(p + 0xc));
        func_0204B3DC(q[0x5c], 0);
        func_0204B954(q[0x5c], 0x2000);
        func_0204B9A0(q[0x5c]);
        func_0204B92C(q[0x5c], 1);
    }
}
