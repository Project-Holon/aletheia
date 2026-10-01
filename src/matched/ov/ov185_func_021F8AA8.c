/*
 * function: func_021F8AA8
 * address: 0x021F8AA8
 * packet: pkt_ov185_021F8AA8
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021F8790 0x021F8790 thumb ov185
 *   func_021F8F58 0x021F8F58 thumb ov185
 *   func_021F8F88 0x021F8F88 thumb ov185
 *   func_021FD860 0x021FD860 thumb ov186
 */
extern int func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern void func_021FD73C(int *,int);
extern void func_021F8790(void);
extern void func_021F8F58(char *,int *);
extern void func_021F8F88(char *,int *);
extern void func_021FD860(void *,int,int *);
void func_021F8AA8(int *sys,int *state,char *p)
{
    int pair[2];
    switch(*state) {
    case 0: func_021FE784(**(int **)(p+0x34),2,3,1); *state=1; break;
    case 1: if(func_021FE7B0(*(int **)*(int **)(p+0x34))) *state=2; break;
    case 2:
        func_021F8F58(p,*(int **)(p+0x34));
        func_021F8F88(p,*(int **)(p+0x34));
        pair[0]=0x80;pair[1]=0x60;
        func_021FD860(*(void **)(p+0x38),4,pair); *state=3; break;
    case 3: func_021FE784(**(int **)(p+0x34),2,3,0); *state=4; break;
    case 4: if(func_021FE7B0(*(int **)*(int **)(p+0x34))) *state=5; break;
    case 5: func_021FD73C(sys,(int)func_021F8790); break;
    }
}
