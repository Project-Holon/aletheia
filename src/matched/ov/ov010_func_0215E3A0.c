/*
 * function: func_0215E3A0
 * address:  0x0215E3A0
 * packet:   pkt_ov010_0215E3A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0200D4AC  0x0200D4AC  thumb
 *   func_0200D488  0x0200D488  thumb
 *   func_0215E358  0x0215E358  thumb  ov010
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct Big;
struct Blk38;
struct GdsEnt;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *p);
extern void *func_02012984(void *p);
extern struct GdsEnt *func_0200D4AC(struct Blk38 *p, u32 i);
extern u8 func_0200D488(struct Blk38 *p, u32 i);
extern void func_0215E358(void *a, void *b, int i);

void func_0215E3A0(void *a)
{
    u8 i;
    void *q;
    void *p;

    p = func_0200D418(func_02012EBC(a));
    q = func_02012984(a);
    for (i = 0; i < 2; i++) {
        func_0200D4AC(p, i);
        if (func_0200D488(p, i) != 0) {
            func_0215E358(p, q, i);
        }
    }
}
