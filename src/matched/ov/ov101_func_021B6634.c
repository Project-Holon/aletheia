/*
 * unit: yes
 * function: func_021B6634,func_021B6650,func_021B6658,func_021B665C,func_021B6668,func_021B6670,func_021B6674
 * address: 0x021B6634
 * packet: pkt_ov101_021B6634
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02080D24 0x02080D24 arm
 */
typedef unsigned int u32;
extern u32 func_02080D24(u32);
void func_021B6634(u32 *p, int i)
{
    p[19] |= 1 << i;
    if (func_02080D24(p[19]) >= 2)
        p[20] = 1;
}
int func_021B6650(void) { return 0x021B7520; }
int func_021B6658(void) { return 4; }
int func_021B665C(int a, int b) { return a == b ? 1 : 0; }
void func_021B6668(int *p) { p[20] = 0; }
void func_021B6670(void) { }
void func_021B6674(int *p) { p[21] = 1; }
