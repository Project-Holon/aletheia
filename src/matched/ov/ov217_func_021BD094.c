/*
 * function: func_021BD094
 * address: 0x021BD094
 * packet: pkt_ov217_021BD094
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_02043678 0x02043678 arm
 *   d_021C3470 0x021C3470 data a4
 */
typedef unsigned short u16;
struct Ent { int a; int b; int c; int pad[8]; };
struct S { char pad0[8]; u16 h8; char pad[0x136]; int arr[4]; };
extern const struct Ent d_021C3470[];
typedef unsigned int   u32;
struct Bmp;
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);

void func_021BD094(struct S *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        p->arr[i] = (int)func_02043678(d_021C3470[i].a, d_021C3470[i].b, d_021C3470[i].c, p->h8);
    }
}
