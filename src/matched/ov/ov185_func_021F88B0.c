/*
 * function: func_021F88B0
 * address: 0x021F88B0
 * packet: pkt_ov185_021F88B0
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021F8FB0 0x021F8FB0 thumb ov185
 *   func_021F8D18 0x021F8D18 thumb ov185
 *   func_021F8D98 0x021F8D98 thumb ov185
 *   func_021F86E4 0x021F86E4 thumb ov185
 */
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int);
extern int func_021FD73C(int,void *);
extern void func_021F8FB0(char *,char *);
extern void func_021F8D18(char *,int *);
extern void func_021F8D98(char *,char *);
extern void func_021F86E4(int,int,char *);
void func_021F88B0(int a,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(**(int **)(p+52),4,3,1); *state=1; break;
    case 1: if (func_021FE7B0(**(int **)(p+52))) *state=2; break;
    case 2: func_021F8FB0(p,*(char **)(p+52)); func_021F8D18(p,*(int **)(p+52)); func_021F8D98(p,*(char **)(p+52)); *state=3; break;
    case 3: func_021FE784(**(int **)(p+52),4,3,0); *state=4; break;
    case 4: if (func_021FE7B0(**(int **)(p+52))) *state=5; break;
    case 5: *(int *)(p+32)=1; func_021FD73C(a,func_021F86E4); break;
    }
}
