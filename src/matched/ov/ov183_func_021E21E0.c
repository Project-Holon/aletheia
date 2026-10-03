/*
 * function: func_021E21E0
 * address: 0x021E21E0
 * packet: pkt_ov183_021E21E0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: separate function-scope coordinate pairs retain the switch cases' stack slots.
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_021E24F8 0x021E24F8 thumb ov183
 *   func_021E2538 0x021E2538 thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021E24C4 0x021E24C4 thumb ov183
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021D76A8 0x021D76A8 thumb ov125
 *   func_021D76D8 0x021D76D8 thumb ov125
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021E2194 0x021E2194 thumb ov183
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {u32 a,b;} Pair;
extern u32 func_02035D20(u32 *,u32 *),func_02035C60(void);
extern int func_021E24F8(char *,int,int),func_021E2538(char *,int,int);
extern void func_021FD170(int,int,int),func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern void func_021E24C4(char *,char *),func_021FD860(int,int,Pair *);
extern void func_021D76A8(int,int,int);
extern int func_021D76D8(int,int);
extern void func_020061E4(int),func_021FD73C(int,int),func_021E2194(void);
void func_021E21E0(int task,int *state,char *p) {
    u32 x0,y0,x1,y1; Pair first; u32 x9,y9; Pair second;
    u32 old; int result;
    switch(*state) {
    case 0:
        if(func_02035D20(&x0,&y0)) {
            if(func_021E24F8(p,x0,y0)) {func_021FD170(*(int *)(p+4),*(int *)(*(char **)(p+0x20)+12),322);*state=1;}
            else if(func_021E2538(p,x0,y0))*state=10;
        } break;
    case 1:
        if(func_02035D20(&x1,&y1)) {
            if(func_021E24F8(p,x1,y1))*state=2;
            else if(func_021E2538(p,x1,y1))*state=10;
        } break;
    case 2:func_021FE784(*(int *)(*(char **)(p+0x20)+4),2,2,1);++*state;break;
    case 3:
        if(func_021FE7B0(*(int **)(*(char **)(p+0x20)+4))) {
            func_021E24C4(p,*(char **)(p+0x20));
            func_021FD170(*(int *)(p+4),*(int *)(*(char **)(p+0x20)+12),323);
            first.a=128;first.b=96;func_021FD860(*(int *)(p+0x14),4,&first);
            *(u32 *)(p+0x24)=0;++*state;
        } break;
    case 4:func_021FE784(*(int *)(*(char **)(p+0x20)+4),2,2,0);++*state;break;
    case 5:if(func_021FE7B0(*(int **)(*(char **)(p+0x20)+4)))++*state;break;
    case 6:
        func_021D76A8(*(int *)(*(char **)(p+0x20)+0x14),*(u16 *)(p+0x1c),**(int **)(p+0x20));
        ++*(u32 *)(p+0x24);++*state;break;
    case 7:
        result=func_021D76D8(*(int *)(*(char **)(p+0x20)+0x14),**(int **)(p+0x20));
        ++*(u32 *)(p+0x24);
        if((u32)(result-2)<=1) {*(int *)(*(char **)(p+0x20)+0x1c)=1;*state=8;}break;
    case 8:
        old=*(u32 *)(p+0x24);*(u32 *)(p+0x24)=old+1;
        if(old>96) {func_021FD860(*(int *)(p+0x14),0,0);func_021FD170(*(int *)(p+4),*(int *)(*(char **)(p+0x20)+12),324);*state=9;}break;
    case 9:
        if(func_02035C60()) {
            func_02035D20(&x9,&y9);second.a=x9;second.b=y9;
            func_021FD860(*(int *)(p+0x18),1,&second);func_020061E4(0x703);*state=10;
        }break;
    case 10:func_021FD73C(task,(int)func_021E2194);break;
    }
}
