/*
 * function: func_02159B38
 * address:  0x02159B38
 * packet:   pkt_02159B38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct SaveBlock;
extern void *func_0215A5E4(void *a0);
extern void *func_020127A4(struct SaveBlock *p);
struct Rec44;
extern u16 func_02012AC8(const struct Rec44 *p);

int func_02159B38(int a0)
{
    void *p;
    void *v0;

    v0 = func_0215A5E4((void *)a0);
loc_02159B3E:
    p = func_020127A4((struct SaveBlock *)v0);
loc_02159B42:
    a0 = func_02012AC8(p);
loc_02159B46:
    return a0;}
