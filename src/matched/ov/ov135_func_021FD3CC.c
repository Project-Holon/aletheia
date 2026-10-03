/*
 * function: func_021FD3CC
 * address: 0x021FD3CC
 * packet: pkt_ov135_021FD3CC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 021FD6F4 retains r2=1,r3=0,sp=0xF0F visibly loaded by this caller.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_021FD6F4 0x021FD6F4 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021FD368 0x021FD368 thumb ov135
 *   func_021FFB00 0x021FFB00 thumb ov135
 *   tbl_02203608 0x02203608 data a1
 *   tbl_022035FC 0x022035FC data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {u8 left,right;} Pair;
extern const Pair tbl_02203608[];
extern const u8 tbl_022035FC[];
extern u32 func_020362DC(void);
extern int func_02035C08(const void *);
extern void func_020061E4(u32);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021FD6F4(void *,u32,u32,u32,u32);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_021FD368(u8 *,int);
extern int func_021FFB00(int);
int func_021FD3CC(u8 *p)
{
    int next, r;
    if(func_020362DC()&1) {
        func_021FD6F4(p,16,1,0,0xF0F);
        func_021F4E98(p,3,4);
        func_020061E4(0x54C);
    } else if(func_020362DC()&2) {
        func_0202208C(0,0,0,0,16,1,0x48);
        *(int *)(p+0x28)=8;
        func_020061E4(0x551);
    } else if(func_020362DC()&32) {
        next=tbl_02203608[(u32)*(int *)(p+0xD4)].left;
        if(*(int *)(p+0xD4)!=next && *(int *)(p+0xD0)>=next+1)
            func_021FD368(p,next);
    } else if(func_020362DC()&16) {
        next=tbl_02203608[(u32)*(int *)(p+0xD4)].right;
        if(*(int *)(p+0xD4)!=next && *(int *)(p+0xD0)>=next+1)
            func_021FD368(p,next);
    } else {
        r=func_021FFB00(*(int *)(p+0xD0));
        if(r!=-1) func_021FD368(p,r);
        r=func_02035C08(tbl_022035FC);
        if(r==0) {
            func_021FD6F4(p,16,1,0,0xF0F);
            func_021F4E98(p,3,4);
            func_020061E4(0x54C);
        } else if(r==1) {
            func_0202208C(0,0,0,0,16,1,0x48);
            *(int *)(p+0x28)=8;
            func_020061E4(0x551);
        }
    }
    return 2;
}
