/*
 * function: func_021AAB54
 * address:  0x021AAB54
 * packet:   pkt_ov021_021AAB54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad[0xd];
    u8 lo : 4;
    u8 mid : 2;
    u8 hi : 2;
} Sub;

typedef struct {
    u8 pad[0x10];
    Sub sub;
} T;

typedef struct {
    char pad[0x5b4];
    int f5b4;
} D;

typedef struct {
    int pad[2];
    int f8;
    int fc;
    D *f10;
} S;

extern T *func_02012A38(int a);

void func_021AAB54(S *s)
{
    Sub *b = &func_02012A38(s->f8)->sub;
    if (b->lo) {
        b->mid = 1;
    }
}
