/*
 * function: func_021DA454
 * address: 0x021DA454
 * packet: pkt_ov129_021DA454
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Expand each coordinate base at its read; binding the base to a
 * pointer local swaps r2/r3 and leaves six bytes different.
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02043678 0x02043678 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_020255A0 0x020255A0 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_020437AC 0x020437AC arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
struct Param { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };
extern void *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(void *,u32);
extern void *func_02043678(u32,u32,u32,u32);
extern u32 func_0201D304(void *,u32,u32);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern void *func_020255A0(void *,const struct Param *);
extern void func_020257D0(void *);
extern void func_020437AC(void *);
extern void func_02045808(void *);
extern void func_02045C04(void *);
void func_021DA454(u8 *p,int i)
{
    void *bank,*msg,*bmp;
    struct Param q;
    s16 y;
    u16 x;
    int zero=0;
    bank=func_02045B38(0,2,25,50);
    msg=func_02045EC0(bank,i+3);
    bmp=func_02043678(10,2,32,50);
    func_0201C7D0(bmp,(80-(int)func_0201D304(msg,*(u32 *)(p+0x314),0))/2,0,msg,*(void **)(p+0x314),0x3dc0);
    x=(p+(i+22)*4)[0x29a]+20;
    y=((p+(i+22)*4)[0x298]+(p+(i+22)*4)[0x299])/2;
    q.bmp=bmp;
    q.x=x;
    q.y=y-7;
    q.f8=*(u32 *)(p+0x264);
    q.fc=zero;
    q.f10=zero;
    q.f11=zero;
    q.f12=zero;
    q.f14=zero;
    *(void **)(p+0x304+i*4)=func_020255A0(*(void **)(p+0x300),&q);
    func_020257D0(*(void **)(p+0x304+i*4));
    func_020437AC(bmp);
    func_02045808(msg);
    func_02045C04(bank);
}
