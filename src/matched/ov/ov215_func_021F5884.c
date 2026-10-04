/*
 * function: func_021F5884
 * address: 0x021F5884
 * packet: pkt_ov215_021F5884
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_02031330 0x02031330 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021F5E68 0x021F5E68 thumb ov215
 *   func_021F5F74 0x021F5F74 thumb ov215
 *   func_021F5E90 0x021F5E90 thumb ov215
 *   func_021F5F84 0x021F5F84 thumb ov215
 *   func_021F5FA0 0x021F5FA0 thumb ov215
 *   func_021F5FB0 0x021F5FB0 thumb ov215
 *   func_021F5FCC 0x021F5FCC thumb ov215
 *   func_021F6A3C 0x021F6A3C thumb ov215
 *   func_021F6A44 0x021F6A44 thumb ov215
 *   func_021F5FDC 0x021F5FDC thumb ov215
 *   func_020127A4 0x020127A4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013E4C 0x02013E4C thumb
 *   func_02017B24 0x02017B24 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 *   func_021F6A48 0x021F6A48 thumb ov215
 *   func_021F6A84 0x021F6A84 thumb ov215
 *   func_021F6A98 0x021F6A98 thumb ov215
 *   func_021F6AA4 0x021F6AA4 thumb ov215
 *   func_021F6164 0x021F6164 thumb ov215
 *   func_021F6000 0x021F6000 thumb ov215
 *   func_021F6194 0x021F6194 thumb ov215
 *   func_021F6228 0x021F6228 thumb ov215
 *   func_021F601C 0x021F601C thumb ov215
 *   func_021F62FC 0x021F62FC thumb ov215
 *   func_021F6324 0x021F6324 thumb ov215
 *   func_021F602C 0x021F602C thumb ov215
 *   func_020355D8 0x020355D8 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_021F5CFC 0x021F5CFC thumb ov215
 *   func_0216C028 0x0216C028 thumb ov010
 *   func_02031348 0x02031348 arm
 *   d_021F5580 0x021F5580 data ov194 a4
 *   abs_id_C2 0xC2 data
 *   func_0216C0E4 0x0216C0E4 thumb ov010
 *   func_020457B0 0x020457B0 arm
 *   func_0216C0D4 0x0216C0D4 thumb ov010
 *   func_02017E40 0x02017E40 thumb
 *   func_02045808 0x02045808 arm
 *   func_02012F2C 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0216C0C0 0x0216C0C0 thumb ov010
 *   func_021F603C 0x021F603C thumb ov215
 *   func_021F604C 0x021F604C thumb ov215
 *   func_021F5ECC 0x021F5ECC thumb ov215
 *   func_021F6158 0x021F6158 thumb ov215
 *   func_021F62CC 0x021F62CC thumb ov215
 *   func_021F67E0 0x021F67E0 thumb ov215
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021F64D0 0x021F64D0 thumb ov215
 *   func_021F64E4 0x021F64E4 thumb ov215
 *   func_021F6A24 0x021F6A24 thumb ov215
 *   func_021F64F0 0x021F64F0 thumb ov215
 * prototypes: owning ARM9 units and ov215 sources; live r3 from C028 is
 * forwarded by 31348 into the four-argument 314F4 body.
 * lever: pooled overlay ID abs_id_C2 and branch-local else return preserve
 * case15 tail layout; direct 194 and early return produced DIFF97/896.
 * data: overlay ID 194 supplied to 31348 identifies ov194's process table
 * at 021F5580; own ov194 listing has three callback words there.
 */
#include "../include/Obj00186.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S021F5E68; struct SaveBlock; struct Rec44; struct Blk37; struct Big;
struct U16Vec; struct Sub02008C20Obj; struct PrintSys;
extern u32 func_020362DC(void),func_02031330(void *);
extern void func_0204E720(u32,int,int,int);
extern int func_0204E804(void);
extern void func_021F5E68(int,struct S021F5E68 *);
extern int func_021F5F74(void *,char *),func_021F5E90(int,struct S021F5E68 *);
extern void func_021F5F84(void *,char *),func_021F5FB0(void *,char *);
extern int func_021F5FA0(void *,char *),func_021F5FCC(void *,char *);
extern void func_021F6A3C(char *); extern int func_021F6A44(char *);
extern void func_021F5FDC(u32 *,u32 *);
extern void *func_020127A4(struct SaveBlock *);
extern u8 *func_02012944(void *);
extern u16 func_02012AC8(const struct Rec44 *);
extern u32 func_02013E4C(u32);
extern void func_02017B24(void *,u32,u32,u32);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(struct Blk37 *,void *),func_0200CDE0(struct Blk37 *,void *);
extern void func_021F6A48(char *,void *);
extern int func_021F6A84(char *),func_021F6AA4(char *);
extern void func_021F6A98(char *),func_021F6164(void *,char *),func_021F6000(void *,char *);
extern void func_021F6194(char *,char *,u32);
extern int func_021F6228(void *,char *),func_021F601C(void *,char *),func_021F62FC(int,char *),func_021F6324(int,char *);
extern void func_021F602C(void *,char *),func_020355D8(u8);
extern void *func_02012EBC(struct Big *),*func_0200C0F0(void *);
extern void func_021F5CFC(u32,char *);
extern int *func_0216C028(u16,int,int,int,int);
extern void func_02031348(void *,u32,u32,u32);
extern char d_021F5580,abs_id_C2;
extern int func_0216C0E4(int *);
extern struct U16Vec *func_020457B0(u32,u32);
extern void func_0216C0D4(int *,int),func_02017E40(void *,u32,u32),func_02045808(struct U16Vec *);
extern void *func_02012F2C(int *);
extern u32 func_02008DF0(struct Sub02008C20Obj *,int);
extern int func_0216C0C0(int a0);
extern int func_021F603C(void *,char *);
extern void func_021F604C(u32 *,u32 *),func_021F5ECC(u8 *,u8 *),func_021F6158(void *,char *),func_021F62CC(void *,char *);
extern void func_021F67E0(char *);
extern u32 func_0201C4E4(struct PrintSys *);
extern void func_021F64D0(char *),func_021F64E4(char *),func_021F6A24(char *),func_021F64F0(char *);
int func_021F5884(u32 unused0,u32 unused1,u32 *a,u32 *p)
{
    u32 active;
    struct Rec44 *save;
    u8 *trainer;
    struct Blk37 *dex;
    void *block;
    int *child;
    struct U16Vec *vec;
    func_020362DC();
    active=func_02031330((void *)p[34]);
    if(active==1)return 0;
    switch(p[4]) {
    case 0:
        if(((struct Obj00186 *)p)->f14==0){p[4]=1;func_0204E720(3,16,0,-16);}
        else (((struct Obj00186 *)p)->f14)--;
        break;
    case 1:if(!func_0204E804()){p[4]=2;func_021F5E68((int)a,(struct S021F5E68 *)p);}break;
    case 2:if(!func_021F5F74(a,(char *)p)&&func_021F5E90((int)a,(struct S021F5E68 *)p)){p[4]=3;func_021F5F84(a,(char *)p);}break;
    case 3:if(!func_021F5FA0(a,(char *)p)){p[4]=4;func_021F5FB0(a,(char *)p);}break;
    case 4:if(func_021F5FCC(a,(char *)p)){p[4]=5;func_021F6A3C((char *)p[32]);}break;
    case 5:if(func_021F6A44((char *)p[32])){p[4]=6;func_021F5FDC(a,p);}break;
    case 6:
        p[4]=7;
        save=func_020127A4((struct SaveBlock *)a[0]);trainer=func_02012944((void *)a[0]);
        func_02017B24((void *)a[1],(u32)trainer,func_02013E4C(func_02012AC8(save)),((struct Obj00186 *)p)->f0);
        dex=func_0200CA1C((void *)a[0]);func_0200CFA0(dex,(void *)a[1]);func_0200CDE0(dex,(void *)a[1]);
        func_021F6A48((char *)p[32],(void *)a[1]);break;
    case 7:if(func_021F6A84((char *)p[32])){p[4]=8;func_021F6A98((char *)p[32]);}break;
    case 8:if(func_021F6AA4((char *)p[32])){p[4]=9;func_021F6164(a,(char *)p);func_021F6000(a,(char *)p);}break;
    case 9:p[27]=1;p[4]=10;break;
    case 10:func_021F6194((char *)a,(char *)p,1);p[4]=11;break;
    case 11:if(func_021F6228(a,(char *)p)&&!func_021F601C(a,(char *)p)){p[4]=12;func_021F6194((char *)a,(char *)p,2);}break;
    case 12:if(func_021F6228(a,(char *)p)){p[4]=13;func_021F62FC((int)a,(char *)p);}break;
    case 13:
        active=func_021F6324((int)a,(char *)p);
        if(active==0){p[4]=18;func_0204E720(3,0,16,2);func_021F602C(a,(char *)p);func_020355D8(0);}
        else if(active==1){p[4]=14;func_0204E720(3,0,16,0);func_020355D8(0);}break;
    case 14:
        if(!func_0204E804()){
            block=func_0200C0F0(func_02012EBC((struct Big *)a[0]));
            func_021F5CFC((u32)a,(char *)p);p[4]=15;
            child=func_0216C028(((struct Obj00186 *)p)->f0,(int)a[1],10,0,(int)block);p[33]=(u32)child;
            func_02031348((void *)p[34],(u32)&abs_id_C2,(u32)&d_021F5580,(u32)child);
        }break;
    case 15:
        if(active!=1){
        if(!func_0216C0E4((int *)p[33])){
            vec=func_020457B0(32,((struct Obj00186 *)p)->f0);func_0216C0D4((int *)p[33],(int)vec);
            func_02017E40((void *)a[1],115,(u32)vec);func_02045808(vec);
            func_02008DF0(func_02012F2C((int *)a[0]),30);
        }
        func_0216C0C0((int)((int *)p[33]));p[4]=16;func_021F602C(a,(char *)p);
        }else{return 0;}break;
    case 16:if(!func_021F603C(a,(char *)p)){p[4]=17;func_021F604C(a,p);return 1;}break;
    case 17:break;
    case 18:if(!func_021F603C(a,(char *)p)){p[4]=19;func_021F604C(a,p);}break;
    case 19:if(!func_0204E804()){p[4]=20;return 1;}break;
    }
    func_021F5ECC((u8 *)a,(u8 *)p);
    if(p[4]!=15&&p[4]!=16&&p[4]!=17&&p[4]!=20){
        func_021F6158(a,(char *)p);func_021F62CC(a,(char *)p);func_021F67E0((char *)p[32]);
        func_0201C4E4((struct PrintSys *)p[3]);func_021F64D0((char *)p[1]);func_021F64E4((char *)p[1]);
        func_021F6A24((char *)p[32]);func_021F64F0((char *)p[1]);
    }
    return 0;
}
