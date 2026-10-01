/*
 * function: func_021D07FC
 * address:  0x021D07FC
 * packet:   pkt_ov021_021D07FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char s8;

typedef struct Row {
    u32 f0;
    int f4;
    u32 f8[3];
} Row;

typedef struct S {
    int *f0;
    int f4;
    u8 f8;
    s8 f9;
    s8 fA;
    u8 padB;
    Row rows[6];
} S;

Row *func_021D07FC(S *s)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (s->rows[i].f0 == 0) {
            return &s->rows[i];
        }
    }
    return 0;
}
