/*
 * function: func_021DC638
 * address: 0x021DC638
 * packet: pkt_ov183_021DC638
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * abi: DD0AC/DD0F4 retain caller-loaded r1.
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021DCE28 0x021DCE28 thumb ov183
 *   func_021DCE48 0x021DCE48 thumb ov183
 *   func_021DD054 0x021DD054 thumb ov183
 *   func_021DD128 0x021DD128 thumb ov183
 *   func_02035D20 0x02035D20 arm
 *   func_021DD2FC 0x021DD2FC thumb ov183
 *   func_021DD33C 0x021DD33C thumb ov183
 *   func_021DD1D4 0x021DD1D4 thumb ov183
 *   func_021DD0AC 0x021DD0AC thumb ov183
 *   func_021DD0F4 0x021DD0F4 thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_02006254 0x02006254 thumb
 *   func_021F9C50 0x021F9C50 thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DBC68 0x021DBC68 thumb ov183
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct S S;
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern void func_021DCE28(char *,char *),func_021DCE48(char *,char *),func_021DD054(char *,char *),func_021DD128(char *,char *),func_021DD1D4(char *,char *);
extern void func_021DD0AC(char *,char *),func_021DD0F4(char *,char *);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021DD2FC(char *,int,int),func_021DD33C(char *,int,int);
extern void func_021FD170(char *p, char *q, void *text);
extern int func_02012DAC(int),func_02012DD0(u8 *);
extern void func_021FD860(int,int,int *);
extern int func_02006254(u32 a);
extern void func_021F9C50(S *);
extern int func_021FD744(int);
extern void func_021FD73C(int *,int);
extern void func_021DBC68(int a, int b, char *p);
void func_021DC638(int *a,int *state,char *p)
{
    u32 x,y;
    switch(*state) {
    case 0: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=1;break;
    case 1: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=2;break;
    case 2:
        if(*(int *)(p+0xb0)) func_021DCE28(p,*(char **)(p+0xd0));
        else func_021DCE48(p,*(char **)(p+0xd0));
        func_021DD054(p,*(char **)(p+0xd0));func_021DD128(p,*(char **)(p+0xd0));*state=3;break;
    case 3: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);++*state;break;
    case 4: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) ++*state;break;
    case 5: ++*state;break;
    case 6:
        if(func_02035D20(&x,&y)) {
            if(func_021DD2FC(p,x,y)) *state=7;
            else if(func_021DD33C(p,x,y)) *state=10;
        }
        break;
    case 7: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);++*state;break;
    case 8: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) ++*state;break;
    case 9: func_021DD1D4(p,*(char **)(p+0xd0));*state=13;break;
    case 10: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);++*state;break;
    case 11: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) ++*state;break;
    case 12: func_021DD1D4(p,*(char **)(p+0xd0));func_021FD73C(a,(int)func_021DBC68);break;
    case 13: func_021DD0AC(p,*(char **)(p+0xd0));*state=14;break;
    case 14:
        func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x152);
        func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=15;break;
    case 15: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=16;break;
    case 16: *state=17;break;
    case 17: func_02012DAC(*(int *)(*(char **)(p+0xd0)+0x28));*state=18;break;
    case 18:
        if(func_02012DD0(*(u8 **)(*(char **)(p+0xd0)+0x28))==2) {func_021FD860(*(int *)(p+12),0,0);*state=19;}
        break;
    case 19: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=20;break;
    case 20: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=21;break;
    case 21:
        if(!func_02006254(0x701)) {
            func_021DD0F4(p,*(char **)(p+0xd0));
            **(int **)(p+0xd0)=1;
            func_021F9C50(*(S **)(*(char **)(p+0xd0)+0x14));
            func_021FD744((int)a);
        }
        break;
    }
}
