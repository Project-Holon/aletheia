/*
 * function: func_021E26B8
 * address: 0x021E26B8
 * packet: pkt_ov183_021E26B8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: p is a plain (non-const) pointer, so the case 0 Pair copy and the case 5 loop schedule as in the original; the loop counter is set before the arg local (i=1; arg=...; for(;i<=3;i++)).
 * note: 2026-10-05 recoup P25L4: the older DIFF draft (21 bytes) became 4 bytes when const was dropped from p, and EXACT with i=1 written before arg.
 * symbols:
 *   func_021E2F98 0x021E2F98 thumb ov183
 *   func_021E2E30 0x021E2E30 thumb ov183
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF698 0x021FF698 thumb ov186
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B938 0x0200B938 thumb
 *   func_0200B928 0x0200B928 thumb
 *   func_0200B98C 0x0200B98C thumb
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021E2E48 0x021E2E48 thumb ov183
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021E2910 0x021E2910 thumb ov183
 *   func_021FD744 0x021FD744 thumb ov186
 */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef enum { STATE_ZERO=0, STATE_TWELVE=12 } State;
typedef struct {u32 a,b;} Pair;
typedef struct {u32 words[2];} Request;
typedef struct {u32 fields[7];Pair request;} Arg;
typedef unsigned char  u8;
struct Big;
struct SOCLResource;
extern void func_021E2F98(struct SOCLResource *resource);
extern void func_021E2E30(char *,int,int);
extern void func_021FE784(int,int,int,int);extern int func_021FE7B0(int *);
extern void func_02082BCC(void *,int,u32);
extern void func_021FF54C(char *p, int kind, const int *values);
extern int func_021FF648(char *p);
extern int func_021FF72C(char *p, int *out);
extern int func_021FF698(char *p, int a1, int *out);
extern void *func_02012EBC(struct Big *p);
extern u8 *func_0200B928(void);
extern void func_0200B938(const void *,const void *,const void *,void *);
extern unsigned long long func_0200B98C(u8 *p, int selector, int index);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FD860(int,int,Pair *);
extern int func_02035C60(void);
extern u32 func_02035D20(u32 *,u32 *);
extern void func_020061E4(u32 a);
extern void func_021E2E48(char *p, int a, int b);
extern int *func_021FD73C(int *p, int v);
extern void func_021E2910(int *task, int *state, char *p);
extern int func_021FD744(int *a);
void func_021E26B8(int *task,State *state,char *p) {
    u32 req[2];
    u32 msg;
    int extra;char *rec;
    u32 x,y;Pair click,cb;
    int result,found,i;
    u64 value;char *arg;
    switch(*state) {
    case 0:
        func_021E2F98((struct SOCLResource *)(&cb));arg=*(char **)(p+0x3c);*(Pair *)(p+0x4c)=cb;
        func_021E2E30((char *)p+0x4c,(int)p,(int)arg);*state=1;break;
    case 1:func_021FE784(**(int **)(p+0x3c),2,3,0);*state=2;break;
    case 2:if(func_021FE7B0((int *)**(int **)(p+0x3c)))*state=3;break;
    case 3:
        func_02082BCC(req,0,8);*(u64 *)req=*(u64 *)(*(char **)(p+0x3c)+0x1c);
        func_021FF54C(*(void **)(*(char **)(p+0x3c)+12),3,(const int *)req);
        *(u32 *)(p+0x44)=0;*state=4;break;
    case 4:
        ++*(u32 *)(p+0x44);
        if(func_021FF648(*(void **)(*(char **)(p+0x3c)+12)) && *(u32 *)(p+0x44)>96) {
            func_021FD860(*(int *)(p+0x30),0,0);*state=5;
        }break;
    case 5:
        result=func_021FF72C(*(void **)(*(char **)(p+0x3c)+12),(int *)(&msg));
        if(result==0) {
            if(func_021FF698(*(void **)(*(char **)(p+0x3c)+12),(int)(&rec),&extra)) {
                func_0200B938(rec,rec+0x80,rec+0xc4,func_02012EBC(*(void **)(*(char **)(p+0x3c)+0x14)));
                found=0;value=func_0200B98C(func_0200B928(),4,0);
                i=1;arg=*(char **)(p+0x3c);
                for(;i<=3;i++) {
                    if(*(u64 *)(*(char **)(arg+0x18)+i*8+0x30)==value) {found=1;break;}
                }
                if(found==1) {func_021FD170((char *)(*(int *)(p+8)),(char *)(*(int *)(arg+8)),(void *)316);*state=9;}
                else *state=6;
            } else {func_021FD170((char *)(*(int *)(p+8)),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)339);*state=9;}
        } else {func_021FD170((char *)(*(int *)(p+8)),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)msg);*state=9;}
        break;
    case 9:
        if(func_02035C60()) {
            func_02035D20(&x,&y);click.a=x;click.b=y;func_021FD860(*(int *)(p+0x34),1,&click);
            func_020061E4(0x703);*state=10;
        }break;
    case 6:func_021FE784(**(int **)(p+0x3c),2,3,1);*state=7;break;
    case 7:if(func_021FE7B0((int *)**(int **)(p+0x3c)))*state=8;break;
    case 8:func_021E2E48((char *)p+0x4c,(int)((char *)p),(int)(*(char **)(p+0x3c)));func_021FD73C((int *)task,(int)func_021E2910);break;
    case 10:func_021FE784(**(int **)(p+0x3c),2,3,1);*state=11;break;
    case 11:if(func_021FE7B0((int *)**(int **)(p+0x3c)))*state=12;break;
    case 12:func_021E2E48((char *)p+0x4c,(int)((char *)p),(int)(*(char **)(p+0x3c)));func_021FD744(task);break;
    }
}
