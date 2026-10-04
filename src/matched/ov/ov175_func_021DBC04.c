/*
 * function: func_021DBC04
 * address: 0x021DBC04
 * packet: pkt_ov175_021DBC04
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD044 0x021DD044 thumb ov175
 *   func_021DA470 0x021DA470 thumb ov175
 *   func_021DB6A8 0x021DB6A8 thumb ov175
 *   func_02034714 0x02034714 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E2EF8 0x021E2EF8 data a4
 *   d_021E2F8C 0x021E2F8C data a4
 *   d_021E2F38 0x021E2F38 data a4
 *   d_021E2DF8 0x021E2DF8 data a4
 *   d_021E2F7C 0x021E2F7C data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Record {u32 words[21];};
extern int func_021DD044(int);
extern void func_021DA470(u8 *);
extern void func_021DB6A8(char *);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const u8 d_021E2EF8[],d_021E2F8C[],d_021E2F38[],d_021E2F7C[];
extern const u32 d_021E2DF8[];
void func_021DBC04(u8 *p,u32 mode,struct Record *src)
{
    *(u32 *)(p+0x12c)=0;
    if(**(u32 **)(p+0x1464)==0)func_02034714((const char *)((int)d_021E2EF8),0,(const char *)((int)d_021E2EF8));
    switch(mode) {
    case 0:
        *(u32 *)(*(u8 **)(p+0x190)+0)=func_021DD044(36);
        *(u32 *)(*(u8 **)(p+0x190)+4)=2;
        *(u32 *)(*(u8 **)(p+0x190)+8)=1500;
        *(u32 *)(*(u8 **)(p+0x190)+16)=func_021DD044(39);
        *(u32 *)(*(u8 **)(p+0x190)+20)=2;
        *(u32 *)(*(u8 **)(p+0x190)+24)=0;
        *(u32 *)(*(u8 **)(p+0x190)+32)=func_021DD044(40);
        *(u32 *)(*(u8 **)(p+0x190)+36)=2;
        *(u32 *)(*(u8 **)(p+0x190)+40)=0;
        *(u32 *)(*(u8 **)(p+0x190)+48)=func_021DD044(38);
        *(u32 *)(*(u8 **)(p+0x190)+52)=2;
        *(u32 *)(*(u8 **)(p+0x190)+56)=0;
        *(u32 *)(*(u8 **)(p+0x190)+64)=func_021DD044(37);
        *(u32 *)(*(u8 **)(p+0x190)+68)=2;
        *(u32 *)(*(u8 **)(p+0x190)+72)=0;
        *(u32 *)(*(u8 **)(p+0x190)+80)=(u32)d_021E2F8C;
        *(u32 *)(*(u8 **)(p+0x190)+84)=8;
        *(u32 *)(*(u8 **)(p+0x190)+88)=(u32)src;
        *(u32 *)(*(u8 **)(p+0x190)+92)=1332;
        *(u32 *)(p+0x198)=6;
        break;
    case 1:
        func_021DA470(p+0x38);
        *(u32 *)(p+0x198)=1;
        *(u32 *)(*(u8 **)(p+0x190)+0)=(u32)d_021E2F38;
        *(u32 *)(*(u8 **)(p+0x190)+4)=8;
        *(u32 *)(*(u8 **)(p+0x190)+8)=(u32)(p+0x38);
        *(u32 *)(*(u8 **)(p+0x190)+12)=6;
        break;
    case 2:func_021DB6A8((char *)p);break;
    case 3:
        *(struct Record *)(p+0x1c4)=*src;
        *(u32 *)(p+0x198)=2;
        *(u32 *)(*(u8 **)(p+0x190)+0)=d_021E2DF8[*(u32 *)(p+0x214)];
        *(u32 *)(*(u8 **)(p+0x190)+4)=8;
        *(u32 *)(*(u8 **)(p+0x190)+8)=(u32)(p+0x1c4);
        *(u32 *)(*(u8 **)(p+0x190)+12)=80;
        *(u32 *)(*(u8 **)(p+0x190)+16)=(u32)d_021E2F7C;
        *(u32 *)(*(u8 **)(p+0x190)+20)=0;
        *(u8 *)(*(u8 **)(p+0x190)+24)=(*(u32 *)(p+0x214)+1)%6;
        break;
    }
}
