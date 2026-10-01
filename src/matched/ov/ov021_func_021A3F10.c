/*
 * function: func_021A3F10
 * address:  0x021A3F10
 * packet:   pkt_ov021_021A3F10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3B94  0x021A3B94  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A31A4  0x021A31A4  thumb  ov021
 *   func_021A3AD8  0x021A3AD8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3F10;

int func_021A3B94(Obj021A3F10 *p);
int func_021A3974(Obj021A3F10 *p);
u32 func_021A398C(Obj021A3F10 *p);
int func_021A31A4(u32 x, int a);
void func_021A3AD8(Obj021A3F10 *p, int v);

int func_021A3F10(Obj021A3F10 *p)
{
    int a;

    if (func_021A3B94(p) == 1) {
        p->count++;
        a = func_021A3974(p);
        func_021A3AD8(p, func_021A31A4(func_021A398C(p), a));
        p->done = 1;
    }
    return 0;
}
