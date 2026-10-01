/*
 * function: func_021B900C
 * address: 0x021B900C
 * packet: pkt_ov106_021B900C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Compiled code ends 021B9132; handed tail 021B9132..021B9134 is two zero alignment bytes. Unsigned magnitude subtraction and duration shift preserve 32-bit wrap; runtime helpers retain all repeated calls.
 * symbols:
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_0207C768 0x0207C768 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0207C768(u32,u32);
extern float _ffltu(u32),_fadd(float,float),_fsub(float,float);
extern int _ffix(float);
static inline int magnitude(int v) { return v<0 ? (int)(0u-(u32)v) : v; }
static inline int rounded(int v) {
 if(v!=0) return _ffix(_fadd(0.5f,_ffltu((u32)v<<12)));
 return _ffix(_fsub(_ffltu((u32)v<<12),0.5f));
}
void func_021B900C(u8 *p,int amount,int duration) {
 int value;
 if(magnitude(amount)<=4096) return;
 p[16]=amount/magnitude(amount);
 amount=magnitude(amount);
 if(amount>245760) amount=245760;
 else if(amount<4096) amount=4096;
 if(rounded(duration)>=53248) return;
 if(rounded(duration)>53248) value=53248;
 else if(rounded(duration)<0) value=0;
 else value=rounded(duration);
 *(int *)p=func_0207C768(amount-4096,241664);
 *(int *)(p+4)=4096-func_0207C768(value,53248);
 *(int *)(p+12)=1;
}
