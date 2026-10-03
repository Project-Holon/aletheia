/*
 * function: func_021AAABC
 * address:  0x021AAABC
 * packet:   pkt_ov021_021AAABC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 *   func_021ADB4C  0x021ADB4C  thumb
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

typedef unsigned int   u32;
extern void func_021ADB4C(u32 a, u8 v);

void func_021AAABC(S *s)
{
    Sub *b = &func_02012A38(s->f8)->sub;
    if (b->lo) {
        b->hi = 1;
        if (s->f10->f5b4 != 0) {
            func_021ADB4C(s->f10->f5b4, 1);
        }
    }
}
