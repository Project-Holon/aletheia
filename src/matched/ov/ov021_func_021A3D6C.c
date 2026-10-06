/*
 * function: func_021A3D6C
 * address:  0x021A3D6C
 * packet:   pkt_ov021_021A3D6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3B94  0x021A3B94  thumb  ov021
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A3190  0x021A3190  thumb  ov021
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
} Obj021A3D6C;

int func_021A3B94(u32 *p);
u32 func_021A398C(u8 *p);
u16 func_021A3190(int i, int j);
void func_021A3AD8(u8 *p, int a);

int func_021A3D6C(Obj021A3D6C *p, int a)
{
    if (func_021A3B94((u32 *)p) == 1) {
        p->count++;
        func_021A3AD8((u8 *)p, func_021A3190(func_021A398C((u8 *)p), a));
        p->done = 1;
        return 1;
    }
    return 0;
}
