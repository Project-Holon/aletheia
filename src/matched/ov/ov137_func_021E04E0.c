/*
 * function: func_021E04E0
 * address: 0x021E04E0
 * packet: pkt_ov137_021E04E0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Enum zero preserves its early definition; halfword stores use literal zero to avoid truncation.
 * symbols:
 *   func_02047E88 0x02047E88 arm
 *   d_021E20EC 0x021E20EC data a4
 *   d_021E1DE8 0x021E1DE8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { int a[4]; } Descriptor;
extern const Descriptor d_021E20EC[];
extern const int d_021E1DE8[];
extern int func_02047E88(void *,const void *);
void func_021E04E0(u8 *p)
{
    int index;
    enum { ZERO } zero;
    u8 *s;
    index=*(int *)(*(u8 **)(p+216)+8);
    s=p+224;
    *(int *)(s+188)=func_02047E88(*(void **)(p+2804),&d_021E20EC[index-2]);
    zero=0;
    *(int *)(s+68)=d_021E1DE8[index];
    *(int *)(s+24)=4096;
    *(int *)(s+28)=4096;
    *(int *)(s+32)=4096;
    *(u16 *)(s+76)=0;
    *(u16 *)(s+78)=0;
    *(u16 *)(s+80)=0;
    *(int *)(s+60)=zero;
    *(int *)(p+224)=zero;
    *(int *)(s+4)=-147456;
    *(int *)(s+8)=zero;
    *(Vec *)(s+12)=*(Vec *)s;
}
