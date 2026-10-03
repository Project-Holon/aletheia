/*
 * function: func_021F8790
 * address: 0x021F8790
 * packet: pkt_ov185_021F8790
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF660 0x021FF660 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021F88B0 0x021F88B0 thumb ov185
 *   func_021F8A0C 0x021F8A0C thumb ov185
 */
typedef unsigned short u16;
typedef struct Cfg {u16 heap;unsigned char rest[6];} Cfg;
typedef struct Pair {int x,y;} Pair;
extern void func_02082BCC(void *,int,unsigned);
extern void func_021FF54C(char *,int,Cfg *);
extern int func_021FF648(char *),func_021FF72C(char *,int *),func_021FF660(char *,int,int,int *);
extern void func_021FD860(int,int,Pair *),func_021FD73C(int *,int),func_021FD170(void *,void *,int);
extern int func_02035C60(void),func_02035D20(int *,int *);
extern void func_020061E4(int),func_021F88B0(void),func_021F8A0C(void);
void func_021F8790(int *task,unsigned *state,char *p)
{
    Cfg cfg;
    int out,x,y;
    Pair pair;
    switch(*state) {
    case 0:
        func_02082BCC(&cfg,0,8);
        cfg.heap=*(u16 *)(p+8);
        *(u16 *)(p+10)=0;
        func_021FF54C(*(char **)(*(char **)(p+0x34)+0x14),1,&cfg);
        *state=1; break;
    case 1:
        *(u16 *)(p+10)=*(u16 *)(p+10)+1;
        if(func_021FF648(*(char **)(*(char **)(p+0x34)+0x14)) && *(u16 *)(p+10)>0x60) {
            func_021FD860(*(int *)(p+0x38),0,0);
            *state=2;
        }
        break;
    case 2:
        if(!func_021FF72C(*(char **)(*(char **)(p+0x34)+0x14),&out)) {
            if(func_021FF660(*(char **)(*(char **)(p+0x34)+0x14),(int)(p+0x40),5,(int *)(p+0x54)) && *(int *)(p+0x54)) {
                *(u16 *)(p+12)=0;
                func_021FD73C(task,(int)func_021F88B0);
                break;
            }
            *state=3;
            func_021FD170(*(void **)(p+4),*(void **)(*(char **)(p+0x34)+12),0x14d);
        }else{
            *state=3;
            func_021FD170(*(void **)(p+4),*(void **)(*(char **)(p+0x34)+12),out);
        }
        break;
    case 3:
        if(func_02035C60()) {
            func_02035D20(&x,&y);
            pair.x=x;pair.y=y;
            func_021FD860(*(int *)(p+0x3c),1,&pair);
            func_020061E4(0x703);
            func_021FD73C(task,(int)func_021F8A0C);
        }
        break;
    }
}
