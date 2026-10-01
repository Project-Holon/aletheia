/*
 * function: func_021BD0E0
 * address:  0x021BD0E0
 * packet:   pkt_ov021_021BD0E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008998  0x02008998  thumb
 */

typedef unsigned short u16;

typedef struct {
    void *f0;
    char pad[0x42];
    u16 h46;
} Obj;

extern int func_020120F4(void *a);
extern int func_02012EBC(int a);
extern int func_02008854(int a);
extern u16 func_02008998(int a);

void func_021BD0E0(Obj *p)
{
    p->h46 = func_02008998(func_02008854(func_02012EBC(func_020120F4(p->f0))));
}
