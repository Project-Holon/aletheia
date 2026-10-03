/*
 * function: func_021D8EC8
 * address: 0x021D8EC8
 * packet: pkt_ov175_021D8EC8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021DBC04 0x021DBC04 thumb ov175
 *   func_021DBDAC 0x021DBDAC thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021D905C 0x021D905C thumb ov175
 */
typedef unsigned long u32;
extern void func_021E8738(u32,u32,u32,u32);
extern void func_021E8AB4(u32,u32),func_02012DAC(void *);
extern int func_02012DD0(void *);
extern void func_021DBC04(void *,int,int);
extern int func_021DBDAC(void *);
extern int func_021D9F04(char *,void *,void *);
extern void func_021E8AA0(u32,void *),func_021E8AB8(u32),func_021D905C(void);
extern int func_021E8844(u32);
void func_021D8EC8(u32 sys,int *state,char *p)
{
    char *q=*(char **)(p+260);
    switch(*state) {
    case 0:func_021E8738(*(u32 *)(p+44),*(u32 *)(p+20),40,2);
        func_021E8AB4(sys,1);*state=7;break;
    case 1:func_02012DAC(**(void ***)(q+8));*state=2;break;
    case 2:if(func_02012DD0(**(void ***)(q+8))==2) *state=3;break;
    case 3:func_021E8738(*(u32 *)(p+44),*(u32 *)(p+20),37,2);
        func_021E8AB4(sys,4);*state=7;break;
    case 4:if(**(u32 **)(q+32)==0) {func_021DBC04(*(void **)(p+52),2,0);*state=5;}break;
    case 5:if(func_021DBDAC(*(void **)(p+52))) {
        **(u32 **)(*(char **)(p+260)+32)=1800;*state=6;
        func_021D9F04(*(char **)(p+52),(void *)1,0);
    }break;
    case 6:func_021E8AA0(sys,func_021D905C);break;
    case 7:if(func_021E8844(*(u32 *)(p+44))) func_021E8AB8(sys);break;
    }
}
