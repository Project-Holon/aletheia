/*
 * function: func_021E5524
 * address: 0x021E5524
 * packet: pkt_ov178_021E5524
 * region: ov178
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   ov091_id 0x0000005B data a1
 *   ov131_id 0x00000083 data a1
 *   d_021BED00 0x021BED00 data a4 ov091
 *   d_021DC800 0x021DC800 data a4 ov131
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D798 0x0203D798 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FB38 0x0200FB38 thumb
 *   func_02157170 0x02157170 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_02031348 0x02031348 arm
 *   func_02031330 0x02031330 arm
 *   func_021B6114 0x021B6114 thumb ov090
 * callee: 02031348 tail-forwards to 020314F4 whose own matched body reads all four arguments; retain caller register payloads.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
extern u32 d_02FFFC3C;
extern u8 ov091_id[],ov131_id[],d_021BED00[],d_021DC800[];
extern int func_0203CD98(void);
extern void *func_0203D798(void);
extern int func_0200FB24(void);
extern void func_0200FB38(void);
extern int func_02157170(void *,void *);
extern int func_02034AC4(int),func_02034A5C(int);
extern void func_02031348(void *,u32,void *,void *);
extern u32 func_02031330(void *);
extern void func_021B6114(u8 *);
int func_021E5524(void *unused,int unused2,char *q,char *p)
{
    if(*(u32 *)(p+0x98)==1 && *(u16 *)(p+0x68)!=0) {
        u32 now;
        now=d_02FFFC3C;
        *(u8 *)(p+0xc8)+=(u8)(now-*(u32 *)(p+0xcc));
        *(u32 *)(p+0xcc)=now;
        if(*(u8 *)(p+0xc8)>60) {
            --*(u16 *)(p+0x68);
            *(u8 *)(p+0xc8)-=60;
        }
    }
    if(func_0203CD98()) {
        if(*((u8 *)func_0203D798()+0x65)==3) {
            if(func_0200FB24()) {
                func_0200FB38();
                *(u32 *)(q+0x20)=2;
                *(u8 *)(p+0x6b)=1;*(u32 *)(p+0xc4)=1;
            }
        } else {
            int one;
            one=1;
            switch(func_02157170((void *)1,(void *)1)) {
            case 0:case 3:break;
            case 4:*(u32 *)(q+0x20)=3;*(u8 *)(p+0x6b)=one;*(u32 *)(p+0xc4)=one;break;
            case 1:case 2:default:*(u32 *)(q+0x20)=1;*(u8 *)(p+0x6b)=1;*(u32 *)(p+0xc4)=1;break;
            }
        }
    }
    switch(*(u32 *)p) {
    case 0:func_02034AC4((int)ov091_id);
        func_02031348(*(void **)(p+0xd0),-1,d_021BED00,p+8);*(u32 *)p=1;break;
    case 1:if(func_02031330(*(void **)(p+0xd0))==0)*(u32 *)p=2;break;
    case 2:func_02034A5C((int)ov091_id);
        if(*(u32 *)(p+0x48)==1) {*(u8 *)(p+0xaf)=*(u32 *)(p+0x44);*(u32 *)p=3;}
        else return 1;
        break;
    case 3:func_02034AC4((int)ov131_id);
        func_02031348(*(void **)(p+0xd0),-1,d_021DC800,p+0xa0);*(u32 *)p=4;break;
    case 4:
        if(*(u32 *)(p+0x98)==1 && *(u16 *)(p+0x68)==0)*(u32 *)(p+0xc4)=1;
        if(func_02031330(*(void **)(p+0xd0))==0)*(u32 *)p=5;break;
    case 5:func_02034A5C((int)ov131_id);
        if(*(u8 *)(p+0x6b)==0) {*(u32 *)(p+0x44)=*(u8 *)(p+0xaf);*(u32 *)p=0;}
        else return 1;
        break;
    }
    if(*(u8 *)(p+0x6b)==0) {
        p+=8;
        func_021B6114((u8 *)p);
    }
    return 0;
}
