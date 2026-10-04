/*
 * function: func_021F7D30
 * address: 0x021F7D30
 * packet: pkt_ov112_021F7D30
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: inline signed-long FX multiply takes the scaled time first;
 *   a direct cast expression changes register allocation and offset homing.
 * symbols:
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_020061F8 0x020061F8 thumb
 *   table 0x020A1B38 data a2
 *   _ll_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef struct { int x,y,z; } Vec;
typedef struct { u16 count,pad; int index,a,b; } Tail;
extern const short table[];
extern void func_021F4EA4(u32,u32,u32);
extern void func_021F4E8C(u32,void *,const int *);
extern void func_021F4ED4(u32,u32,u16);
extern void func_021F4E6C(u8 *,u8 *,u32);
extern void func_020061F8(int);
static inline long fxmul(long a,long b)
{
    return (long)(((s64)a*b+2048)>>12);
}
void func_021F7D30(u8 *p,u8 *q)
{
    Tail *t=(Tail *)(q+0xf0);
    Vec v;
    unsigned long offset;
    u16 time=t->count;
    int angle=(time<<9)%65536;
    long s=table[(angle>>4)*2];
    func_021F4EA4(*(u32 *)(p+0x10),*(u32 *)(q+0x84+t->index*4),(u32)&v);
    offset=205;
    v.x+=fxmul((time/3)*offset,s);
    v.y-=3072;
    func_021F4E8C(*(u32 *)(p+0x10),*(void **)(q+0x84+t->index*4),&v.x);
    func_021F4ED4(*(u32 *)(p+0x10),*(u32 *)(q+0x84+t->index*4),s>>1);
    t->count++;
    if(t->count>=180) {
        func_021F4E6C(*(u8 **)(p+0x10),*(u8 **)(q+0x84+t->index*4),0);
        offset+=55;
        *(int *)(q+offset)=0;
        *(u8 *)(p+0x43c)-=1;
        if(*(u8 *)(p+0x43c)==0) func_020061F8(2);
    }
}
