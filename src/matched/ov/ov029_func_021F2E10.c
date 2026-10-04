/*
 * function: func_021F2E10
 * address:  0x021F2E10
 * packet:   pkt_ov029_021F2E10
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
} S;

struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(int a, int b);

void func_021F2E10(char *p, int *q)
{
    S s;

    s.a = 0;
    s.b = 0;
    s.c = 0x25;
    s.d = 0;
    s.e = 2;
    q[2] = (int)func_0204B294((void *)*(int *)(p + 0x34), *(int *)(p + 0x2c), *(int *)(p + 0x28),
                         *(int *)(p + 0x30), &s, 0, *(unsigned short *)(p + 0xc));
    func_0204B3DC(q[2], 0);
    q[3] = *(int *)(p + 0x210);
    q[4] = *(int *)(p + 0x204);
}
