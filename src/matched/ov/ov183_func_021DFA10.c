/*
 * function: func_021DFA10
 * address: 0x021DFA10
 * packet: pkt_ov183_021DFA10
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   d_021E37A8 0x021E37A8 data a4
 */
typedef unsigned int u32;
typedef int (*Method)(char *,int *);
struct Methods { Method init,update,finish; };
extern const struct Methods d_021E37A8[];
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern void func_021FC830(void *),func_021FD1BC(void *),func_0201C4E4(void *);
extern void func_021FD854(char *);
int func_021DFA10(void *unused,u32 *state,int *q,char *p)
{
    int i;
    switch(*state) {
    case 0: if(d_021E37A8[*(int *)(p+0x4c)].init(p,q)) ++*state; break;
    case 1: func_021FE784(q[0],2,3,0); ++*state; break;
    case 2: if(func_021FE7B0((int *)q[0])) *state=3; break;
    case 3: if(d_021E37A8[*(int *)(p+0x4c)].update(p,q)) {
        if(*(int *)(p+0x50)==-1) *state=10; else *state=4;
    } break;
    case 4: func_021FE784(q[0],2,2,1); ++*state; break;
    case 5: if(func_021FE7B0((int *)q[0])) ++*state; break;
    case 6: if(d_021E37A8[*(int *)(p+0x4c)].finish(p,q)) {
        *(int *)(p+0x4c)=*(int *)(p+0x50); ++*state;
    } break;
    case 7: if(d_021E37A8[*(int *)(p+0x4c)].init(p,q)) ++*state; break;
    case 8: func_021FE784(q[0],2,2,0); ++*state; break;
    case 9: if(func_021FE7B0((int *)q[0])) *state=3; break;
    case 10: func_021FE784(q[0],2,3,1); ++*state; break;
    case 11: if(func_021FE7B0((int *)q[0])) *state=12; break;
    case 12: if(d_021E37A8[*(int *)(p+0x4c)].finish(p,q)) return 1; break;
    }
    for(i=0;i<3;i++) if(*(void **)(p+i*4)) func_021FC830(*(void **)(p+i*4));
    for(i=0;i<6;i++) if(*(void **)(p+0x20+i*4)) func_021FC830(*(void **)(p+0x20+i*4));
    if(*(void **)(p+0x38)) func_021FD1BC(*(void **)(p+0x38));
    func_0201C4E4(*(void **)(p+0x48));
    for(i=0;i<2;i++) func_021FD854(*(char **)(p+0x3c+i*4));
    return 0;
}
