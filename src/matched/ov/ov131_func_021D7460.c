/*
 * function: func_021D7460
 * address: 0x021D7460
 * packet: pkt_ov131_021D7460
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note 2026-10-02 (lane R4): the loop stores 0 (the copy of r4 before the loop is the
 *   zero already in r4), not the counter; the three post-loop stores are 0 too.
 * symbols:
 *   func_02035CB8 0x02035CB8 arm
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_021D77E8 0x021D77E8 thumb ov131
 *   func_021D75A4 0x021D75A4 thumb ov131
 *   d_021DC1E0 0x021DC1E0 data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {u8 b[12];} Rects;
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern int func_02035BA4(const void *);
extern void func_021D77E8(void *,u32,u32);
extern void func_021D75A4(void *,void *);
extern const Rects d_021DC1E0;
void func_021D7460(u8 *a,u8 *p) {
    Rects r=d_021DC1E0;
    u32 x,y;
    int t,g,k;
    u8 i;
    func_02035CB8(&x,&y);
    if(*(u32 *)(a+0x38)!=0) return;
    t=func_02035C60();
    g=func_02035C38();
    k=func_02035BA4(&r);
    if(*(u32 *)(p+8)==0) {
        if(k==0 || (k==1 && t==0)) {
            if(t==1) {
                *(u32 *)(p+0x6c)=1;
                *(u32 *)(p+0x58)=0;
                func_021D77E8(p+0x78,x,y);
                func_021D77E8(p+0x80,x,y);
                func_021D77E8(p+0x88,x,y);
                for(i=0;i<5;i++) p[0x94+i]=0;
                p[0x99]=0;
                p[0x9a]=0;
                *(u32 *)(p+0x90)=0;
            } else if(g==1 && *(u32 *)(p+0x6c)==1) {
                func_021D75A4(a,p);
            }
            *(u32 *)(p+0x70)=x;
            *(u32 *)(p+0x74)=y;
        } else {
            if(*(u32 *)(p+0x6c)==1 && *(u32 *)(p+0x58)==0 && *(u32 *)(p+0x5c)==0) {
                *(u32 *)(p+8)=1;
                p[0x9b]=0;
            }
            func_021D77E8(p+0x78,x,y);
            func_021D77E8(p+0x80,x,y);
            func_021D77E8(p+0x88,x,y);
            *(u32 *)(p+0x6c)=0;
        }
    } else if(*(u32 *)(p+8)==2) {
        if(k==0 || (k==1 && t==0)) {
            if(t==1) *(u32 *)(p+0x6c)=1;
        } else if(*(u32 *)(p+0x6c)==1) {
            *(u32 *)(p+0x6c)=0;
            *(u32 *)(p+8)=3;
            p[0x9b]=0;
        }
    }
}
