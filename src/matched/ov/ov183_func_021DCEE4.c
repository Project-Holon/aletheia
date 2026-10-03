/*
 * function: func_021DCEE4
 * address: 0x021DCEE4
 * packet: pkt_ov183_021DCEE4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {u16 x,y,n;u8 flag,pad;} Desc;
typedef struct {int a,b,c;} Triple;
extern void func_021FB964(int,int,int);
extern void func_021FBE54(char *,u32,u32);
extern int func_021FC20C(char *),func_021FC214(char *);
extern int func_021FC124(void *,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_02082BCC(void *,int,u32);
void func_021DCEE4(char *p,char *q)
{
    int a,b;
    if(!*(int *)(p+0xd8)) {
        *(int *)(p+0xd8)=1;
        func_021FB964(*(int *)(q+0x10),5,*(u16 *)(p+0xb4));
        func_021FBE54(*(char **)(q+0x10),6,*(u16 *)(p+0xb4));
        a=func_021FC20C(*(char **)(q+0x10));
        b=func_021FC214(*(char **)(q+0x10));
        if(*(int *)(p+0xcc)) {
            Desc d;
            Triple t;
            func_02082BCC(&d,0,8);
            d.x=24;d.y=168;d.n=0;d.flag=1;
            func_021FC124(*(void **)(q+0x10),6,&t);
            *(void **)(p+0x1c)=func_021FB378(&d,4,96,1,*(int *)(q+0x18),*(int *)p,a,b,&t,*(u16 *)(p+0xb4));
            d.x=136;d.n=3;
            *(void **)(p+0x20)=func_021FB378(&d,84,96,1,*(int *)(q+0x18),*(int *)p,a,b,&t,*(u16 *)(p+0xb4));
        } else {
            Desc d;
            Triple t;
            func_02082BCC(&d,0,8);
            d.x=80;d.y=168;d.n=0;d.flag=1;
            func_021FC124(*(void **)(q+0x10),6,&t);
            *(void **)(p+0x1c)=func_021FB378(&d,4,96,1,*(int *)(q+0x18),*(int *)p,a,b,&t,*(u16 *)(p+0xb4));
        }
        *(void **)(p+0x28)=func_021FC6A4(4,8,3,16,2,14,*(void **)(p+4),*(u16 *)(p+0xb4));
        if(*(int *)(p+0xb0)) func_021FC754(*(char **)(p+0x28),(void *)b,(void *)0x72,(void *)a,0x3da0);
        else func_021FC754(*(char **)(p+0x28),(void *)b,(void *)0x71,(void *)a,0x3da0);
    }
}
