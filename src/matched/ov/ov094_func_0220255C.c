/*
 * function: func_0220255C
 * address:  0x0220255C
 * packet:   pkt_ov094_0220255C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02204960  0x02204960  thumb  ov094
 *   d_0220A8BC  0x0220A8BC  data  a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Ent { char pad[0x20]; int f20; } Ent;
extern void func_0203FCA0(u8, const Ent *, u8);
extern void func_0204152C(u8, int);
extern void func_02204960(void *, int, int, int, int, int, int, int);
extern const Ent d_0220A8BC[];

void func_0220255C(void *p)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_0203FCA0(i + 4, &d_0220A8BC[i], d_0220A8BC[i].f20);
        func_0204152C(i + 4, 0x3ff);
        func_02204960(p, i + 4, 0, 0, 2, 2, 2, 2);
    }
}
