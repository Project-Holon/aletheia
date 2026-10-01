/*
 * function: func_021A8DD8
 * address:  0x021A8DD8
 * packet:   pkt_ov021_021A8DD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02040618  0x02040618  arm
 *   func_0204B09C  0x0204B09C  arm
 */

typedef short s16;

typedef struct {
    s16 x;
    s16 y;
} P;

typedef struct {
    char pad0[0xfc];
    s16 hfc;
    char pad2[0x120 - 0xfe];
    int f120;
} S;

extern void func_02040618(int a, int b, int c);
extern void func_0204B09C(int a, int b, P *c);

void func_021A8DD8(S *s)
{
    P v;
    s->hfc = 0xc0;
    func_02040618(5, 3, -0xc0);
    func_02040618(6, 3, -0xc5);
    v.x = 0;
    v.y = 0xc0;
    func_0204B09C(s->f120, 0, &v);
}
