/*
 * function: func_02200FF4
 * address: 0x02200FF4
 * packet: pkt_ov135_02200FF4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02019CE0 0x02019CE0 thumb
 *   func_02025C1C 0x02025C1C thumb
 *   func_02025C30 0x02025C30 thumb
 *   func_020173EC 0x020173EC thumb
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_021B98A0 0x021B98A0 thumb ov114
 *   func_021B98D8 0x021B98D8 thumb ov114
 *   func_021B98F8 0x021B98F8 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_02034714 0x02034714 arm
 *   str_02203F58 0x02203F58 data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct RecDC;
extern void func_02019CE0(const struct RecDC *, struct RecDC *);
extern u32 func_02025C1C(u32, u32, u32);
extern u32 func_02025C30(u32, u32, u32);
extern u32 func_0200853C(const void *);
extern u32 func_020173EC(void);
extern u8 *func_021B9800(int, int, int);
extern void func_021B98A0(u8 *, int, int, int);
extern void func_021B98D8(u8 *, int, int);
extern int func_021B98F8(u8 *);
extern int func_021B9748(u8 *);
extern void func_02034714(const char *, int, const char *);
extern const char str_02203F58[];
int func_02200FF4(u8 *p)
{
    u8 *mon=p+0xE4;
    int ready;
    func_02019CE0((const struct RecDC *)mon, *(struct RecDC **)(p+0xEA8));
    p[0x204]=func_02025C1C(p[0x204],p[0x205],p[0x209]);
    p[0x205]=func_02025C30(p[0x204],p[0x205],p[0x209]);
    *(u8 **)(p+0x10E0)=func_021B9800(0x48,func_0200853C(*(void **)(*(u8 **)p+0x1C)),(int)(p+0x116C));
    func_021B98A0(*(u8 **)(p+0x10E0),0x48,func_020173EC(),1);
    func_021B98D8(*(u8 **)(p+0x10E0),(int)mon,func_020173EC());
    if(func_021B98F8(*(u8 **)(p+0x10E0))==0) func_02034714(str_02203F58,0,str_02203F58);
    ready=func_021B9748(*(u8 **)(p+0x10E0))==0;
    if(ready==0) func_02034714(str_02203F58,0,str_02203F58);
    *(u32 *)(p+0x28)=3;
    return 2;
}
