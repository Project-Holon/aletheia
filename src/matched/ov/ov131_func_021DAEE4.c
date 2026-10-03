/*
 * function: func_021DAEE4
 * address: 0x021DAEE4
 * packet: pkt_ov131_021DAEE4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the index re-read after the 021D6064 call is volatile (the original reloads it; a plain
 *   read is CSE'd into a callee-saved register); the B688 arm skips the shared 020061E4 call via goto.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021DB468 0x021DB468 thumb ov131
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021DBA78 0x021DBA78 thumb ov131
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DB614 0x021DB614 thumb ov131
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   func_0202F72C 0x0202F72C thumb
 *   func_021DB688 0x021DB688 thumb ov131
 *   func_021DBA54 0x021DBA54 thumb ov131
 *   func_0204B404 0x0204B404 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_021DB3F0 0x021DB3F0 thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Point { s16 x,y; };
extern u32 func_020362DC(void);
extern void func_021DB468(u8 *,u8 *,u8,int);
struct Actor;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020061E4(u32 a);
extern void func_021DBA78(u8 *,int);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021DB614(void *a, u8 *b, int c);
extern void *func_021D6064(u8 *);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_0202F72C(void *,u16,u16);
extern void func_021DB688(u8 *,u8 *,int);
extern void func_021DBA54(u8 *,struct Point *);
extern void func_0204B404(void *,const struct Point *,u16);
extern void func_0204B9A0(struct Actor *a);
extern void func_021DB3F0(u8 *,u8 *);
int func_021DAEE4(u8 *a,u8 *p)
{
    struct Point pt;
    u32 r;
    u8 t;
    if(a[0x1c]==1 && func_020362DC()!=0) {
        a[0x1c]=0;
        if(*(int *)(p+0x18)==0) {
            p[0x2a]=5;
            func_021DB468(a,p,p[0x29],0);
        }
    }
    if(func_020362DC()==2) {
        if(*(int *)(p+0x18)==0) {
            a[0x1c]=0;
            *(int *)(a+0x54)=1;
            (*(u8 **)(a+8))[0x12]=1;
            *(int *)(a+0x50)=2;
            func_0204B878(*(void **)(a+0x194),9);
            *(void **)(a+0x1a0)=*(void **)(a+0x194);
            func_020061E4(0x551);
            return 1;
        } else {
            a[0x1c]=0;
            func_021DBA78(p+0xb0+p[0x2a]*0x18,0);
            func_021DB468(a,p,p[0x29],0);
            func_0204B3DC(*(void **)(p+0x9c),0);
            p[0x29]=p[0x2a];
            p[0x2a]=5;
            *(int *)(p+0x18)=0;
            func_021DB468(a,p,p[0x29],0);
            func_0204B878(*(void **)(a+0x194),9);
            func_021DB614(a,p,0);
            func_020061E4(0x551);
        }
    } else if(*(int *)(p+0x18)!=0) {
        if(func_020362DC()==1) {
            a[0x1c]=0;
            *(int *)(a+0x54)=1;
            (*(u8 **)(a+8))[0x11]=p[0x2a];
            (*(u8 **)(a+8))[0x12]=0;
            *(int *)(p+0x20)=1;
            *(int *)(p+0x24)=1;
            *(int *)(a+0x1a0)=0;
            func_020061E4(0x54c);
        }
    } else if(func_020362DC()==1) {
        a[0x1c]=0;
        if(p[0x29]<4) {
            r=func_0202F72C(*(void **)((*(u8 **)(a+8))+8),func_02017E88(func_021D6064(a),*(volatile u8 *)(p+0x29)+0x36,0),*(u16 *)a);
            if(r==0 || *(int *)(a+0x14)==1) {
                if(*(u16 *)((*(u8 **)(a+8))+0x14)==0) {
                    *(int *)(a+0x54)=1;
                    (*(u8 **)(a+8))[0x12]=0;
                    (*(u8 **)(a+8))[0x11]=p[0x29];
                    *(int *)(p+0x20)=1;
                    *(int *)(a+0x1a0)=0;
                } else {
                    *(int *)(p+0x18)=1;
                    t=p[0x29];
                    p[0x2a]=t;
                    func_021DBA78(p+0xb0+t*0x18,2);
                    p[0x29]=4;
                    func_021DB468(a,p,p[0x29],0);
                    func_021DBA54(p+0xb0+p[0x2a]*0x18,&pt);
                    func_0204B404(*(void **)(p+0x9c),&pt,0);
                    func_0204B3DC(*(void **)(p+0x9c),1);
                    func_0204B9A0(*(void **)(p+0x9c));
                    func_021DB614(a,p,1);
                }
            } else {
                func_021DB688(a,p,r);
                goto done;
            }
        } else {
            *(int *)(a+0x54)=1;
            (*(u8 **)(a+8))[0x12]=1;
            *(int *)(p+0x20)=1;
            *(int *)(a+0x1a0)=0;
        }
        func_020061E4(0x54c);
done:
        return 1;
    } else {
        if(func_020362DC()==0x40 || func_020362DC()==0x80) {
            func_021DB3F0(a,p);
            return 1;
        }
    }
    return 0;
}
