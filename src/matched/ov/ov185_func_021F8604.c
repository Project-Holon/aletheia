/*
 * function: func_021F8604
 * address: 0x021F8604
 * packet: pkt_ov185_021F8604
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FFE34 0x021FFE34 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021F86A4 0x021F86A4 thumb ov185
 */
extern unsigned func_021FFE34(char *p);
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *p);
extern void func_021FD73C(int *p, int v);
extern void func_021F86A4(int,int,char *);
void func_021F8604(int a,int *state,char *p)
{
    switch (*state) {
    case 0: if (func_021FFE34((char *)(*(int *)p))) { func_021FE784(**(int **)(p+52),2,3,0); *state=1; } break;
    case 1: if (func_021FE7B0((int *)(**(int **)(p+52)))) *state=2; break;
    case 2: func_021FD73C((int *)a,(int)func_021F86A4); break;
    }
}
