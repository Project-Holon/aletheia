/*
 * function: func_021A3E14
 * address:  0x021A3E14
 * packet:   pkt_ov021_021A3E14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A3980  0x021A3980  thumb  ov021
 *   func_021A4114  0x021A4114  thumb  ov021
 *   func_021A3D50  0x021A3D50  thumb  ov021
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
} Obj021A3E14;

u32 func_021A398C(Obj021A3E14 *p);
void *func_021A3960(Obj021A3E14 *p);
void func_021A3980(Obj021A3E14 *p, int a);
void func_021A4114(Obj021A3E14 *p);
int func_021A3D50(Obj021A3E14 *p, int a);

int func_021A3E14(Obj021A3E14 *p)
{
    func_021A398C(p);
    func_021A3960(p);
    func_021A3980(p, 1);
    func_021A4114(p);
    if (func_021A3D50(p, 1) != 1)
        p->step++;
    return 0;
}
