/*
 * function: func_021DA6D0
 * address: 0x021DA6D0
 * packet: pkt_ov121_021DA6D0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arithmetic: direct division helper uses quotient r0/remainder r1 as a scalar u64;
 *             the caller admits count zero, so ordinary C remainder is not used.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021DAAA4 0x021DAAA4 thumb ov121
 *   d_021DF76C 0x021DF76C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {s16 x,y;} Position;
typedef struct {int x,y;} TablePair;
extern const TablePair d_021DF76C[];
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
struct Obj;
extern void func_020061E4(u32 a);
extern u64 _u32_div_f(u32,u32);
extern void func_0204B404(void *,Position *,int);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021DAAA4(void *,u16 *,int,u8,u8,u16,u16);
int func_021DA6D0(u8 *p)
{
    u32 keys=func_020362DC();
    u32 repeat=func_0203633C();
    int changed=0;
    int i;
    int phase;
    int oldphase;
    u32 index;
    Position pos;
    if(repeat&64) {
        index=*(u32 *)(p+8)==0 ? *(u32 *)(p+12)-1 : *(u32 *)(p+8)-1;
        *(u32 *)(p+8)=index;
        if(*(u32 *)(p+12)!=1) func_020061E4(0x548);
        changed=1;
    } else if(repeat&128) {
        if(*(u32 *)(p+12)!=1) func_020061E4(0x548);
        *(u32 *)(p+8)+=1;
        *(u32 *)(p+8)=(u32)(_u32_div_f(*(u32 *)(p+8),*(u32 *)(p+12))>>32);
        changed=1;
    } else if(keys&1) {
        func_020061E4(0x54c);
        return *(u32 *)(p+8);
    } else if(keys&2) {
        func_020061E4(0x551);
        if(*(u32 *)(p+12)==1) return -2;
        if(*(u32 *)(p+8)!=3) **(u32 **)(p+0x60)=*(u32 *)(p+8);
        *(u32 *)(p+8)=*(u32 *)(p+12)-1;
        return *(u32 *)(p+8);
    }
    if(changed) {
        pos.x=d_021DF76C[*(u32 *)(p+8)].x;
        pos.y=d_021DF76C[*(u32 *)(p+8)].y+*(s16 *)(p+0x2e)*8;
        func_0204B404(*(void **)(p+4),&pos,0);
        if(*(u32 *)(p+8)==3) func_0204B878(*(void **)(p+4),2);
        else func_0204B878(*(void **)(p+4),*(u16 *)(p+0x30));
        if(*(void (**)(u32))(p+0x34)) (*(void (**)(u32))(p+0x34))(*(u32 *)(p+0x38));
    }
    oldphase=*(u16 *)(p+0x24);
    phase=oldphase+0x400;
    if(phase>=0x10000) *(u16 *)(p+0x24)=oldphase-0xfc00;
    else *(u16 *)(p+0x24)=phase;
    for(i=0;i<4;i++) {
        u8 *v=p+i*4;
        if(*(u32 *)(v+0x4c)!=*(u32 *)(v+0x3c) && *(u16 *)(p+0x24)>=0x7dff && *(u16 *)(p+0x24)<=0x81ff)
            *(u32 *)(v+0x3c)=*(u32 *)(v+0x4c);
        if(*(u32 *)(v+0x3c))
            func_021DAAA4((void *)15,(u16 *)(p+0x1a+i*2),*(u16 *)(p+0x24),*(u16 *)(p+0x2c),(u8)(i+10),*(u16 *)(p+0x12+i*2),*(u16 *)(p+0x22));
    }
    return -1;
}
