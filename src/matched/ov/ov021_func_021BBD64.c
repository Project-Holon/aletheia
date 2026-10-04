/*
 * function: func_021BBD64
 * address:  0x021BBD64
 * packet:   pkt_ov021_021BBD64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned short u16;

typedef struct {
    int pad0;
    int f4;
    u16 h8[0x1A];
} Obj;

typedef unsigned int   u32;
struct BbActSys;
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);

void func_021BBD64(Obj *p)
{
    int i;

    for (i = 0; i < 0x1A; i++) {
        func_02050278((struct BbActSys *)p->f4, p->h8[i], 1);
    }
}
