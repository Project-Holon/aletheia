/*
 * function: func_021DBFB0
 * address: 0x021DBFB0
 * packet: pkt_ov183_021DBFB0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: shape copied from matched twin ov183_func_021DC228.c (same state machine, same callees). v1 was 4 bytes off (stack slots of source and index swapped); declaring source before index fixed it. Older draft docs/notes/pkt_ov183_021DBFB0.c.txt (167 B off) superseded.
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021DCEE4 0x021DCEE4 thumb ov183
 *   func_021DC8EC 0x021DC8EC thumb ov183
 *   func_021DD0AC 0x021DD0AC thumb ov183
 *   func_021DD0F4 0x021DD0F4 thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF698 0x021FF698 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021DBD7C 0x021DBD7C thumb ov183
 */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct S S;
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern void func_021DCEE4(char *,char *),func_021DC8EC(char *,char *);
extern void func_021DD0AC(char *,char *),func_021DD0F4(char *,char *);
extern void func_021FD170(char *p, char *q, void *text);
extern void MI_CpuFill8(void *,int,u32);
extern void func_021FF54C(char *p, int kind, const int *values);
extern int func_021FF648(char *p);
extern int func_021FF72C(char *p, int *out);
extern int func_021FF698(char *,int,int *);
extern void func_021FD860(int,int,int *);
extern void func_021F9BA0(unsigned *ctx);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int func_021FD744(int *a);
extern int *func_021FD73C(int *p, int v);
extern void func_021DBD7C(int *,int *,char *);
void func_021DBFB0(int *a,int *state,char *p)
{
    u64 t;
    int message;
    char *source;
    int index;
    u32 x,y;
    int args[2];
    switch(*state) {
    case 0:
        func_021DD0AC(p,*(char **)(p+0xd0));
        func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x14b);*state=1;break;
    case 1: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=2;break;
    case 2: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=3;break;
    case 3:
        MI_CpuFill8(&t,0,8);
        t=*(u64 *)(*(char **)(p+0xd0)+0x1c);
        func_021FF54C(*(void **)(*(char **)(p+0xd0)+0x24),3,(const int *)(&t));
        *(int *)(p+0xbc)=0;*state=4;break;
    case 4:
        ++*(int *)(p+0xbc);
        if(func_021FF648(*(void **)(*(char **)(p+0xd0)+0x24)) && *(u32 *)(p+0xbc)>96) {
            func_021FD860(*(int *)(p+12),0,0);*state=5;
        }
        break;
    case 5:
        if(!func_021FF72C(*(void **)(*(char **)(p+0xd0)+0x24),&message)) {
            if(func_021FF698(*(char **)(*(char **)(p+0xd0)+0x24),(int)&source,&index)) {
                *(char **)(p+0xc0)=source;
                *(char **)(p+0xc4)=source+0x80;*state=6;
            } else {
                func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x114);*state=11;
            }
        } else {
            func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)message);*state=11;
        }
        break;
    case 11:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x,&y);args[0]=x;args[1]=y;
            func_021FD860(*(int *)(p+0x10),1,args);GFL_USE_PlaySeDefaultVolume(0x703);
            func_021F9BA0((unsigned int *)(*(S **)(*(char **)(p+0xd0)+0x14)));*state=12;
        }
        break;
    case 6: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=7;break;
    case 7:
        if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) {
            func_021DD0F4(p,*(char **)(p+0xd0));
            func_021DCEE4(p,*(char **)(p+0xd0));
            func_021DC8EC(p,*(char **)(p+0xd0));*state=8;
        }
        break;
    case 8: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=9;break;
    case 9: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=10;break;
    case 10: func_021FD73C(a,(int)func_021DBD7C);break;
    case 12: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=13;break;
    case 13: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=14;break;
    case 14: func_021DD0F4(p,*(char **)(p+0xd0));func_021FD744((int *)a);break;
    }
}
