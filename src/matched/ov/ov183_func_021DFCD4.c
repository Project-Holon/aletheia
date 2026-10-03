/*
 * function: func_021DFCD4
 * address: 0x021DFCD4
 * packet: pkt_ov183_021DFCD4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: A separate result!=3 guard around the three-case switch removes the extra 8-byte dense dispatch (460 to 452 B).
 * symbols:
 *   func_021E04C8 0x021E04C8 thumb ov183
 *   func_02035D20 0x02035D20 arm
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   func_021E03B0 0x021E03B0 thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_02012944 0x02012944 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FB4CC 0x021FB4CC thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern int func_021E04C8(void);
struct Sub0200852CObj;
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_021FD860(int,int,int *);
extern void func_020061E4(u32 a);
extern void func_021E03B0(char *,char *,int);
extern void func_021FD170(void *,int,int);
extern u8 *func_02012944(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern int func_021FB4B4(int,int,int);
extern int func_021FB4CC(int,int,int);
extern void func_021F9BA0(void *);
extern void func_021F9BF4(unsigned *,unsigned);
int func_021DFCD4(char *p,char *q)
{
    int result=func_021E04C8();
    if(result!=3) {
    switch(result) {
    case 0: {
        u32 x,y;
        int args[2];
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860(*(int *)(p+0x40),1,args);
        func_020061E4(0x703);
        *(int *)(q+0x18)=19;
        func_021E03B0(p,q,0);
        func_021FD170(*(void **)(p+0x38),*(int *)(q+8),105);
        *(int *)(p+0x50)=1;
        return 1;
    }
    case 1: {
        u32 x,y;
        int args[2];
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860(*(int *)(p+0x40),1,args);
        func_020061E4(0x703);
        *(u16 *)(q+0x14)=0xffff;
        func_021E03B0(p,q,1);
        func_021FD170(*(void **)(p+0x38),*(int *)(q+8),106);
        *(int *)(p+0x50)=2;
        return 1;
    }
    case 2: {
        void *v;
        int a,b;
        u32 x,y;
        int args[2];
        v=func_02012944(*(void **)(q+0x10));
        a=func_0200856C(v);b=func_02008570(v);
        if(!a && !b) {
            func_021FD170(*(void **)(p+0x38),*(int *)(q+8),120);
            func_020061E4(0x704);
            break;
        }
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860(*(int *)(p+0x40),1,args);
        func_020061E4(0x703);
        if(*(u8 *)(q+0x16)==255){*(u8 *)(q+0x16)=a;*(u8 *)(q+0x17)=b;}
        else{*(u8 *)(q+0x16)=255;*(u8 *)(q+0x17)=255;}
        func_021E03B0(p,q,2);
        return 0;
    }
    }
    }
    {
        u32 x,y;
        if(func_02035D20(&x,&y)) {
            if(func_021FB4B4(*(int *)(p+0xc),x,y)) {
                int args[2];
                args[0]=x;args[1]=y;
                func_021FD860(*(int *)(p+0x40),1,args);
                *(int *)(p+0x50)=-1;
                func_021F9BA0(*(void **)(q+0xc));
                return 1;
            }
            if(func_021FB4CC(*(int *)(p+0x10),x,y)) {
                if(*(u16 *)(q+0x14)!=0xffff || *(u8 *)(q+0x17)!=255 || *(int *)(q+0x18)!=19) {
                    int args[2];
                    args[0]=x;args[1]=y;
                    func_020061E4(0x703);
                    func_021FD860(*(int *)(p+0x40),1,args);
                    *(int *)(p+0x50)=-1;
                    func_021F9BF4(*(unsigned **)(q+0xc),5);
                    return 1;
                }
                func_020061E4(0x704);
                func_021FD170(*(void **)(p+0x38),*(int *)(q+8),108);
            }
        }
    }
    return 0;
}
