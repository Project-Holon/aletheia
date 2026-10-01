/*
 * function: func_021E1DF0
 * address: 0x021E1DF0
 * packet: pkt_ov183_021E1DF0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 */
extern int func_021FE784(int,int,int,int);
extern int func_021FE7B0(int);
extern int func_021FD744(int);
extern void func_021F9BA0(int);
void func_021E1DF0(int a,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(**(int **)(p+0x18),2,3,1); *state=1; break;
    case 1: if (func_021FE7B0(**(int **)(p+0x18))) *state=2; break;
    case 2: func_021F9BA0(*(int *)(*(char **)(p+0x18)+0xc)); func_021FD744(a); break;
    }
}
