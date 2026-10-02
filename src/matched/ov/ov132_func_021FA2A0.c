/*
 * function: func_021FA2A0
 * address: 0x021FA2A0
 * packet: pkt_ov132_021FA2A0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9E04 0x021F9E04 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021F9DDC 0x021F9DDC thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F6F04 0x021F6F04 thumb ov112
 *   func_021FA3A8 0x021FA3A8 thumb ov132
 *   func_02005728 0x02005728 thumb
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {int x,y,z;} Vec;
extern u16 func_021F9E04(void *);
extern void *func_021F9DA0(void *),*func_021F9DA4(void *,int),*func_021F9DD4(void *),*func_021F9DDC(void *,u8);
extern void func_021F8044(void *,void *,Vec *),func_021F6F04(void *,void *,Vec *);
extern void func_021FA3A8(char *,u8 *,unsigned);
extern unsigned func_02005728(unsigned);
void func_021FA2A0(char *p,u8 *rec)
{
    Vec v;
    void *a,*b;
    u16 x;
    s16 delta;
    if(rec[1]!=0) rec[1]--;
    if(rec[1]==0) {
        if(rec[0]==255 && *(u8 *)(p+0x1fc)==255) {
            *(u16 *)(rec+4)=65535;
            if(rec[6]<2) func_021FA3A8(p,rec,3);
            else if(rec[6]<4) func_021FA3A8(p,rec,2);
            else if(rec[6]<6) func_021FA3A8(p,rec,1);
            else func_021FA3A8(p,rec,0);
        } else {
            func_021F9E04(*(void **)(p+0x1e8));
            x=((rec[6]*32-64)*4)/3;
            if(rec[0]!=255) {
                a=func_021F9DA0(*(void **)(p+0x1e8));
                func_021F8044(a,func_021F9DA4(*(void **)(p+0x1e8),rec[0]),&v);
            } else {
                b=func_021F9DD4(*(void **)(p+0x1e8));
                func_021F6F04(b,func_021F9DDC(*(void **)(p+0x1e8),*(u8 *)(p+0x1fc)),&v);
            }
            delta=(float)v.x/4096.f-(float)(u32)x;
            if(delta < -64) func_021FA3A8(p,rec,0);
            else if(delta >64) func_021FA3A8(p,rec,3);
            else if(delta<0) func_021FA3A8(p,rec,1);
            else func_021FA3A8(p,rec,2);
        }
        rec[1]=func_02005728(60)+1;
    }
}
