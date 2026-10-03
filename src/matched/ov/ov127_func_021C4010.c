/*
 * function: func_021C4010
 * address: 0x021C4010
 * packet: pkt_ov127_021C4010
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4080 0x021C4080 thumb ov127
 *   func_021C447C 0x021C447C thumb ov127
 *   func_021C4424 0x021C4424 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021C4080(u8 *);
extern int func_021C447C(char *, int);
extern void func_021C4424(char *, int);
void func_021C4010(u8 *p)
{
    int i;
    if (*(u32 *)(p+0x2f4) != (u32)-1) func_021C4080(p);
    for(i=0;i<18;i++) if(func_021C447C((char *)p,i)==1)func_021C4424((char *)p,i);
}
