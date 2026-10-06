/*
 * function: func_021DD4F4
 * address: 0x021DD4F4
 * packet: pkt_ov119_021DD4F4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
struct S { char pad[0xFA4]; int a[3][3]; int b[3][3]; int c[3][3]; };
struct S119DD4F4 { char pad[0xFA4]; int a[2][3]; int b[2][3]; int gap; int c[2][3]; };
void func_021DD4F4(struct S119DD4F4 *p, int i, int j)
{
    p->a[i][j] = -1;
    p->b[i][j] = -1;
    if (p->c[i][j])
        func_020307B0((void *)p->c[i][j]);
    p->c[i][j] = 0;
}
