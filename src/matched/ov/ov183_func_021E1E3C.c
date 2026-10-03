/*
 * function: func_021E1E3C
 * address: 0x021E1E3C
 * packet: pkt_ov183_021E1E3C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: keep the copied u64 and quotient distinct; use the emitted _ull_mod runtime symbol.
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B570 0x0200B570 thumb
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021E1DF0 0x021E1DF0 thumb ov183
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF67C 0x021FF67C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021FD19C 0x021FD19C thumb ov186
 *   func_02045808 0x02045808 arm
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {u32 a,b;} Pair;
struct Big;
extern void *func_02012EBC(struct Big *p);
extern u32 func_0200B570(void *,u32,u32 *,u32);
extern void func_021FD73C(int,int),func_021E1DF0(void);
extern void func_021FF54C(void *,int,Pair *);
extern int func_021FF648(void *),func_021FF72C(void *,u32 *),func_021FF67C(void *,u64 *);
extern int func_021FC214(char *),func_021FC21C(char *);
extern void *func_02045EC0(void *,u32),*func_020457B0(u32,u32);
extern void func_0201EFA4(void *,u32,u32,u32,u32,u32),func_0201F250(void *,void *,void *);
extern void func_021FD19C(int,int,void *),func_02045808(void *),func_021F9C6C(void *);
extern int func_021FD744(int);
extern void func_021FD170(int,int,int),func_021FD860(int,int,Pair *);
extern u32 func_02035C60(void),func_02035D20(u32 *,u32 *);
extern void func_020061E4(u32 a);
void func_021E1E3C(int task,int *state,char *p) {
    u32 out;
    u64 total;
    u32 msg,x,y; Pair pair;
    void *str,*expanded,*ws,*bank;
    u64 copy,quotient;
    int result;
    switch(*state) {
    case 0:
        func_0200B570(func_02012EBC(*(void **)(*(char **)(p+0x18)+0x14)),89,&out,0);
        if(out==1)*state=1;else func_021FD73C(task,(int)func_021E1DF0);break;
    case 1:
        *(u32 *)(p+0x1c)=0;func_021FF54C(*(void **)(*(char **)(p+0x18)+0x10),2,0);*state=2;break;
    case 2:
        ++*(u32 *)(p+0x1c);
        if(func_021FF648(*(void **)(*(char **)(p+0x18)+0x10))) {
            total=0;
            if(*(u32 *)(p+0x1c)>=96) {
                result=func_021FF72C(*(void **)(*(char **)(p+0x18)+0x10),&msg);
                if(result==0) {
                    if(func_021FF67C(*(void **)(*(char **)(p+0x18)+0x10),&total)) {
                        bank=(void *)func_021FC214(*(char **)(*(char **)(p+0x18)+8));
                        ws=(void *)func_021FC21C(*(char **)(*(char **)(p+0x18)+8));
                        str=func_02045EC0(bank,334);expanded=func_020457B0(128,0x8059);
                        copy=total;quotient=copy/100000;
                        func_0201EFA4(ws,2,(u32)(copy%100000),5,2,1);
                        func_0201EFA4(ws,1,(u32)(quotient%100000),5,2,1);
                        func_0201EFA4(ws,0,(u32)(quotient/100000),2,2,1);
                        func_0201F250(ws,expanded,str);
                        func_021FD19C(*(int *)(p+12),*(int *)(*(char **)(p+0x18)+8),expanded);
                        func_02045808(expanded);func_02045808(str);
                    }
                } else if(result==3) {
                    func_021F9C6C(*(void **)(*(char **)(p+0x18)+12));func_021FD744(task);break;
                } else func_021FD170(*(int *)(p+12),*(int *)(*(char **)(p+0x18)+8),msg);
                func_021FD860(*(int *)(p+0x10),0,0);*state=4;
            }
        }break;
    case 3:func_021FD73C(task,(int)func_021E1DF0);break;
    case 4:
        if(func_02035C60()) {
            func_02035D20(&x,&y);pair.a=x;pair.b=y;func_021FD860(*(int *)(p+0x14),1,&pair);
            func_020061E4(0x703);*state=3;
        }break;
    }
}
