/*
 * function: func_021D72E8
 * address: 0x021D72E8
 * packet: pkt_ov131_021D72E8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * semantic: five bytes sum to at most 1275; average clamped to [10,20]
 *   before 20-average, so the 6144 product is <=61440. Halfword phase
 *   times 546 <=35782110 (65535*546), within signed int;
 *   the load address uses unsigned integer scaling, no assumed phase bound
 *   and no out-of-object array pointer arithmetic. Signed table sample
 *   is multiplied by 4 (not left shifted). Halfword height times 4096
 *   <=268431360; float rounding and division by 16 fit int. Vector sum
 *   stays within [-131072,16908028]. Every vector word starts at zero.
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_021D79A8 0x021D79A8 thumb ov131
 *   func_02015C78 0x02015C78 thumb
 *   func_02015E04 0x02015E04 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct {int x,y,z;} Vec;
extern const s16 d_020A1B38[];
extern void func_021D79A8(void *p, unsigned char *q, int radius);
extern void func_02015C78(void *,Vec *);
extern void func_02015E04(void *);
int func_021D72E8(u8 *p,u8 *q,int mode)
{
    Vec v={0,0,0};
    u32 sum;
    u8 i;
    u16 delta;
    int height;
    float f;
    if(*(int *)(q+0x10)==1) return 1;
    if(mode==1) {
        sum=0;
        for(i=0;i<5;i++) sum+=q[0x94+i];
        sum/=5U;
        if(sum<10) sum=10;
        if(sum>20) sum=20;
        delta=20-sum;
        *(u16 *)(q+0x68)=2048+(6144*delta)/10;
        v.y+=*(const s16 *)((u32)d_020A1B38+((u32)((*(u16 *)(q+0x62)*546)>>4)<<2))*4;
        ++*(u16 *)(q+0x62);
        if(*(u16 *)(q+0x62)>120) *(u16 *)(q+0x62)=0;
    } else *(u16 *)(q+0x68)=0;
    if(*(u16 *)(q+0x66)<*(u16 *)(q+0x68)) ++*(u16 *)(q+0x66);
    if(*(u16 *)(q+0x66)>*(u16 *)(q+0x68)) {
        if(mode==0) {
            if(*(u16 *)(q+0x66)>=32) *(u16 *)(q+0x66)-=32;
            else *(u16 *)(q+0x66)=0;
        } else --*(u16 *)(q+0x66);
    }
    height=*(u16 *)(q+0x66);
    if(height) f=0.5f+(float)(height*4096);
    else f=(float)(height*4096)-0.5f;
    v.y+=(int)f/16;
    func_021D79A8(p,q,v.y);
    func_02015C78(*(void **)q,&v);
    func_02015E04(*(void **)q);
    if(*(u16 *)(q+0x66)==0 && *(u16 *)(q+0x68)==0) return 1;
    return 0;
}
