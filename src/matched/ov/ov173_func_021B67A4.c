/*
 * function: func_021B67A4
 * address: 0x021B67A4
 * packet: pkt_ov173_021B67A4
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: const extern table restores the original argument-load scheduling.
 * symbols:
 *   d_021B8420 0x021B8420 data a4
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02028590 0x02028590 thumb
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 a,b,c,d,e,f,g; } Entry;
extern const Entry d_021B8420[];
extern u32 func_020450F0(u8,u8,u8,u8,u8,u8,int);
extern u32 func_02045770(u32);
extern void func_02043B5C(u32,int);
extern void func_020456F8(u32);
extern u32 func_02045730(u32);
extern void func_02041B6C(u32);
extern u32 func_02028590(int,int,int,int);
void func_021B67A4(u8 *p)
{
    u32 i;
    u32 h;
    for (i=0;i<16;i++) {
        *(u32 *)(p+i*4+4)=func_020450F0(d_021B8420[i].a,d_021B8420[i].b,d_021B8420[i].c,d_021B8420[i].d,d_021B8420[i].e,d_021B8420[i].f,1);
        func_02043B5C(func_02045770(*(u32 *)(p+i*4+4)),0);
    }
    h=*(u32 *)(p+0x28);
    func_020456F8(h);
    func_02041B6C(func_02045730(h));
    *(u32 *)(p+0x21c)=func_02028590(15,1,1,79);
}
