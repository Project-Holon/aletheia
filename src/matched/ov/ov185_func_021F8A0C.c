/*
 * function: func_021F8A0C
 * address: 0x021F8A0C
 * packet: pkt_ov185_021F8A0C
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021F86A4 0x021F86A4 thumb ov185
 *   func_021F8FB0 0x021F8FB0 thumb ov185
 *   func_021F8EFC 0x021F8EFC thumb ov185
 *   func_021FFE34 0x021FFE34 thumb ov186
 */
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern void func_021FD73C(int *,int);
extern void func_021F86A4(int,int,char *);
extern void func_021F8FB0(char *,int *);
extern void func_021F8EFC(char *,int *);
extern unsigned func_021FFE34(char *p);
void func_021F8A0C(int *sys,int *state,char *p)
{
    switch(*state) {
    case 0: func_021FE784(**(int **)(p+0x34),2,3,1); *state=1; break;
    case 1: if(func_021FE7B0(*(int **)*(int **)(p+0x34))) *state=2; break;
    case 2: func_021F8FB0(p,*(int **)(p+0x34)); func_021F8EFC(p,*(int **)(p+0x34)); *state=3; break;
    case 3: if(func_021FFE34((char *)(*(int *)p))) {func_021FE784(**(int **)(p+0x34),2,3,0); *state=4;} break;
    case 4: if(func_021FE7B0(*(int **)*(int **)(p+0x34))) *state=5; break;
    case 5: func_021FD73C(sys,(int)func_021F86A4); break;
    }
}
