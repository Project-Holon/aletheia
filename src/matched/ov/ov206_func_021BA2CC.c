/*
 * function: func_021BA2CC
 * address: 0x021BA2CC
 * packet: pkt_ov206_021BA2CC
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA814 0x021BA814 thumb ov206
 *   func_021BB160 0x021BB160 thumb ov206
 *   func_021BA4CC 0x021BA4CC thumb ov206
 *   func_021BBA7C 0x021BBA7C thumb ov206
 *   func_021BB480 0x021BB480 thumb ov206
 *   func_02030EAC 0x02030EAC arm
 *   func_021BB0E4 0x021BB0E4 thumb ov206
 *   func_0203FB44 0x0203FB44 arm
 *   func_021BC008 0x021BC008 thumb ov206
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021BA814(void *);
extern void func_021BB160(void *,unsigned);
extern void func_021BA4CC(void *);
extern void func_021BBA7C(void *);
extern void func_021BB480(void *);
extern void func_02030EAC(void *);
extern void func_021BB0E4(void *);
extern void func_0203FB44(u8,u16,u16);
extern void func_021BC008(void *);
extern void func_0201C6EC(void *);
extern void func_0201C4C0(void *);
extern void func_020307B0(void *);
void func_021BA2CC(char *p)
{
    u8 i;
    func_021BA814(p);
    *(int *)(p+68)=0;
    for(i=0;i<2;i++) func_021BB160(p,i);
    if(*(int *)(p+24)==2) func_021BA4CC(p);
    func_021BBA7C(p);
    func_021BB480(p);
    func_02030EAC(*(void **)(p+80));
    func_021BB0E4(p);
    if(*(int *)(p+64)!=0) {
        func_0203FB44(*(u8 *)(p+78),(u16)*(unsigned *)(p+60),(u16)(*(unsigned *)(p+60)>>16));
        *(int *)(p+64)=0;
    }
    func_0203FB44(*(u8 *)(p+78),(u16)*(unsigned *)(p+52),(u16)(*(unsigned *)(p+52)>>16));
    func_0203FB44(*(u8 *)(p+77),(u16)*(unsigned *)(p+48),(u16)(*(unsigned *)(p+48)>>16));
    func_021BC008(p);
    func_0201C6EC(*(void **)(p+44));
    func_0201C4C0(*(void **)(p+44));
    func_020307B0(p);
}
