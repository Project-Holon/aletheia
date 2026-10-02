/*
 * function: func_021C7F14
 * address: 0x021C7F14
 * packet: pkt_ov128_021C7F14
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021C7E78 0x021C7E78 thumb ov128
 *   func_021CA2C4 0x021CA2C4 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_020355D8(int);
extern void func_020061E4(int);
extern int func_021C7E78(s16 *,u8 *,void *,int);
extern void func_021CA2C4(u8 *,int,int);
int func_021C7F14(s16 *p, u8 *a, u8 *ctx)
{
    u16 old;
    int moved;
    int page;
    int dir;
    if(func_020362DC() & 2) {
        func_020355D8(0);
        *(int *)a=0;
        return func_021C7E78(p,a,ctx,0);
    }
    if(func_020362DC() & 1024) {
        func_020355D8(0);
        *(int *)a=0;
        return func_021C7E78(p,a,ctx,6);
    }
    if(*(int *)a==1) {
        if(func_020362DC() & 0xcf3) {
            func_020061E4(0x548);
            func_021CA2C4(ctx,p[2],p[2]);
            func_020355D8(0);
            *(int *)a=0;
        }
        return 0;
    }
    if(func_020362DC() & 1) return func_021C7E78(p,a,ctx,5);
    old=p[2];
    moved=0;
    page=0;
    if(func_0203633C() & 64) {
        if(p[2]==0) p[2]=3;
        else if(p[2]==4) p[2]=7;
        else --p[2];
        moved=1;
    } else if(func_0203633C() & 128) {
        if(p[2]==3) p[2]=0;
        else if(p[2]==7) p[2]=4;
        else ++p[2];
        moved=1;
    } else if(func_0203633C() & 32) {
        if(p[2]<4) {
            p[2]+=4;
            page=1;
            dir=0;
        } else p[2]-=4;
        moved=1;
    } else if(func_0203633C() & 16) {
        if(p[2]<4) p[2]+=4;
        else {
            p[2]-=4;
            page=1;
            dir=1;
        }
        moved=1;
    } else if(a[14]) {
        if(a[14] && (func_0203633C() & 512)) {
            page=1;
            dir=0;
        } else if(a[14] && (func_0203633C() & 256)) {
            page=1;
            dir=1;
        }
    }
    if(page==1) {
        if(dir) {
            p[1]=p[0];
            p[0]=(p[0]+1)%4;
            return func_021C7E78(p,a,ctx,2);
        } else {
            p[1]=p[0];
            --p[0];
            if(p[0]<0) p[0]+=4;
            return func_021C7E78(p,a,ctx,1);
        }
    }
    if(moved==1) {
        func_020061E4(0x548);
        func_021CA2C4(ctx,p[2],old);
        p[3]=old;
    }
    return 0;
}
