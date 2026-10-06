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
typedef unsigned short u16;
struct BgTemplate;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_0204152C(int channel, u16 val);
struct Main;
extern void func_02204960(struct Main *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern const Ent d_0220A8BC[];

void func_0220255C(void *p)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_0203FCA0((u8)(i + 4), (const struct BgTemplate *)(&d_0220A8BC[i]), (u8)d_0220A8BC[i].f20);
        func_0204152C((u8)(i + 4), (int)0x3ff);
        func_02204960(p, i + 4, 0, 0, 2, 2, 2, 2);
    }
}
