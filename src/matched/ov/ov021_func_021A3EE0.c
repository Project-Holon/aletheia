/*
 * function: func_021A3EE0
 * address:  0x021A3EE0
 * packet:   pkt_ov021_021A3EE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A31A4  0x021A31A4  thumb  ov021
 *   func_021A3D08  0x021A3D08  thumb  ov021
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
} Obj021A3EE0;

int func_021A3974(Obj021A3EE0 *p);
u32 func_021A398C(u8 *p);
int func_021A31A4(int i, int v);
int func_021A3D08(u8 *p, u32 v);

int func_021A3EE0(Obj021A3EE0 *p)
{
    int a = func_021A3974(p);

    if (func_021A3D08((u8 *)p, func_021A31A4(func_021A398C((u8 *)p), a)) != 1)
        p->step++;
    return 0;
}
