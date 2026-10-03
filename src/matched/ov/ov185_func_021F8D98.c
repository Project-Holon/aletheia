/*
 * function: func_021F8D98
 * address: 0x021F8D98
 * packet: pkt_ov185_021F8D98
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   d_021F90A0 0x021F90A0 data a1
 */
typedef unsigned short u16;
typedef struct Config {u16 x,y,z; unsigned char a,b;} Config;
typedef struct Triple {int a,b,c;} Triple;
extern const char d_021F90A0[];
extern int func_021FC20C(char *),func_021FC214(char *);
extern void *func_021FC4DC(void *);
extern int func_021FC124(void *,unsigned,void *);
extern void func_02082BCC(void *,int,unsigned);
extern void func_02034714(const char *,unsigned,const char *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(u16,unsigned,u16,u16,unsigned char,unsigned char,void *,u16);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_021FB964(int,int,u16);
void func_021F8D98(char *p,char *q)
{
    int a,b;
    void *v;
    Config cfg;
    Triple triple;
    if (!*(int *)(p+0x1c)) {
        a=func_021FC20C(*(char **)(q+12));
        b=func_021FC214(*(char **)(q+12));
        func_021FC4DC(*(void **)(q+8));
        func_02082BCC(&cfg,0,8);
        cfg.x=0x50;cfg.y=0xa8;cfg.z=0;cfg.a=1;
        v=func_021FC4DC(*(void **)(q+8));
        if (!func_021FC124(*(void **)(q+12),6,&triple)) func_02034714(d_021F90A0,0,d_021F90A0);
        *(void **)(p+0x18)=func_021FB378(&cfg,4,0x60,1,(int)v,*(int *)(p+0x28),a,b,&triple,*(u16 *)(p+0x30));
        *(void **)(p+0x1c)=func_021FC6A4(4,8,3,0x10,2,0xe,*(void **)(p+0x2c),*(u16 *)(p+0x30));
        func_021FC754(*(char **)(p+0x1c),(void *)b,(void *)0x71,(void *)a,0x3da0);
        func_021FB964(*(int *)(q+12),0x16,*(u16 *)(p+0x30));
    }
}
