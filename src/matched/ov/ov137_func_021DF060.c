/*
 * function: func_021DF060
 * address: 0x021DF060
 * packet: pkt_ov137_021DF060
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E161C 0x021E161C thumb ov137
 *   func_021E1210 0x021E1210 thumb ov137
 *   func_021E11F4 0x021E11F4 thumb ov137
 *   func_021E1400 0x021E1400 thumb ov137
 *   func_021E04C4 0x021E04C4 thumb ov137
 *   func_021E140C 0x021E140C thumb ov137
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   func_02039338 0x02039338 arm
 *   func_021E1204 0x021E1204 thumb ov137
 *   func_021E0634 0x021E0634 thumb ov137
 *   func_021E1604 0x021E1604 thumb ov137
 */
typedef unsigned short u16;
typedef struct {int a,b;u16 values[5];u16 flag;} Msg;
extern int func_021E161C(char *),func_021E1210(char *),func_021E1400(char *),func_021E04C4(char *),func_021E1204(char *);
extern void func_021E11F4(char *),func_021E140C(char *),func_021E0634(char *,int),func_021E1604(char *,int);
extern int func_021DCBC4(void *,int,void *,int),func_02039338(void);
int func_021DF060(char *p)
{
    char *s;
    Msg msg;
    int state,i,rate;
    state=func_021E161C(p);
    if(state==1 && func_021E1210(p)==0 && *(int *)(p+0x5c)==0) *(int *)(p+0x20)=1;
    if(*(u16 *)(p+0x6a)==1) {*(int *)p=28;return 1;}
    if(state==0) {
        if(*(int *)(p+0x34) && func_021E1210(p)==0) func_021E11F4(p);
        if(func_021E1400(p)==0 && func_021E04C4(p)==1) {
            if(func_021E1210(p)==0) *(int *)(p+0x38)=1;
            func_021E140C(p);
        }
        if(*(int *)(p+0x38)) {
            if(func_021DCBC4(*(void **)(*(char **)(p+0xd8)+0x18),0x2807,p+0x38,1)==1) *(int *)(p+0x38)=0;
        }
    }
    s=p+0xe0;
    if(func_02039338()==0) {
        if(*(int *)(p+8)<300) {
            *(int *)(s+0x48)+=95;
            if(*(int *)(s+0x48)>=0x7000) *(int *)(s+0x48)=0x7000;
        } else {
            *(int *)(s+0x48)-=95;
            if(*(int *)(s+0x48)<0x4000) *(int *)(s+0x48)=0x4000;
        }
    }
    if(func_02039338()==0) {
        msg.a=*(int *)(p+0x11c);
        msg.flag=*(int *)(p+0x20);
        msg.b=*(int *)(p+0x33c);
        for(i=0;i<*(int *)(p+0x30);i++) msg.values[i]=*(int *)(p+i*0xb4+0x2fc)/4096;
        func_021DCBC4(*(void **)(p+0xdc),0x2808,&msg,20);
    }
    if(func_02039338()==0) {
        rate=*(int *)(p+0x128);
        if(func_021E1204(p)==1) func_021E0634(p+0xe0,rate*2);
        else func_021E1604(p,rate);
    }
    return 0;
}
