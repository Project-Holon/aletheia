/*
 * function: func_021DCB58
 * address: 0x021DCB58
 * packet: pkt_ov175_021DCB58
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012944 0x02012944 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_020173EC 0x020173EC thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_021B98A0 0x021B98A0 thumb ov114
 *   func_021B98D8 0x021B98D8 thumb ov114
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *func_02012944(void *);
extern void *func_0200853C(void *);
extern unsigned func_020173EC(void);
extern unsigned func_0201AA18(void *p);
typedef unsigned int   u32;
extern void *func_0201AB28(void *p, u32 idx);
extern u8 *func_021B9800(int,int,int);
extern void func_021B98A0(u8 *,int,int,int);
extern void func_021B98D8(u8 *,int,int);
void func_021DCB58(char *p,void *q,int mode)
{
    int i;
    unsigned size;
    void *mon;
    i=0;
    *(int *)(p+0x12c)=0;
    *(u8 **)(p+0x121c)=func_021B9800(*(u16 *)(p+0x124),(int)func_0200853C(func_02012944(*(void **)(p+8))),*(int *)(p+0x10));
    switch(mode) {
    case 0:
        func_021B98A0(*(u8 **)(p+0x121c),*(u16 *)(p+0x124),func_020173EC(),0);
        func_021B98D8(*(u8 **)(p+0x121c),(int)q,func_020173EC());
        *(int *)(p+0x174)=1;
        break;
    case 1:
        size=func_020173EC();
        func_021B98A0(*(u8 **)(p+0x121c),*(u16 *)(p+0x124),size*func_0201AA18(q),0);
        for(i=0;i<(int)func_0201AA18(q);i++) {
            mon=func_0201AB28(q,i);
            func_021B98D8(*(u8 **)(p+0x121c),(int)mon,func_020173EC());
        }
        *(int *)(p+0x174)=func_0201AA18(q);
        break;
    }
}
