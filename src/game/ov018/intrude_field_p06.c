/*
 * file:     intrude_field_p06.c
 * unit:     yes
 * function: func_0217BED4, func_0217BF1C, func_0217BF28
 * address:  0x0217BED4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   d_02182B60     0x02182B60  data   a4
 *   func_02082BCC  0x02082BCC  arm
 */
typedef struct { int x, y, z; } V12;

typedef unsigned int   u32;

typedef unsigned char u8;

extern u32 func_02013D5C(u32 id);
extern short *func_0217BEA8(int);
void func_02082BCC(void *dst, int val, int size);
int func_0217BED4(int a, V12 *out);
void func_0217BF1C(void *p);
u8 func_0217BF28(u8 *p);
extern const V12 d_02182B60;


int func_0217BED4(int a, V12 *out)
{
    short *p;
    int x, y, z;

    if (func_02013D5C(a) != 1) {
        p = func_0217BEA8(a);
        if (p == 0)
            return 0;
        z = p[4] << 16;
        y = p[3] << 16;
        x = p[2] << 16;
        out->x = x;
        out->y = y;
        out->z = z;
    } else {
        *out = d_02182B60;
    }
    return 1;
}


void func_0217BF1C(void *p)
{
    func_02082BCC(p, 0, 0x10);
}


u8 func_0217BF28(u8 *p)
{
    return p[0xE];
}
