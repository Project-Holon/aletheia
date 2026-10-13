/*
 * function: func_021B7014
 * address:  0x021B7014
 * packet:   pkt_ov071_021B7014
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   d_021BA854     0x021BA854  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern const Rect d_021BA854;

int func_021B7014(int *p, const int *pos, int flag)
{
    Rect r;
    int f;

    r = d_021BA854;
    f = 0;
    if (flag != 0)
        f = 1;
    r.a = pos[0];
    r.b = pos[1];
    return (int)CLACT_CreateActor((void *)p[0x14 / 4], *(int *)((char *)p + 0x44 + flag * 16), *(int *)((char *)p + 0x40 + flag * 16), *(int *)((char *)p + 0x48 + flag * 16), &r, (u16)f, 0x61);
}
