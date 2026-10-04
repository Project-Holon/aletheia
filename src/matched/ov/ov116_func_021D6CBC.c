/*
 * function: func_021D6CBC
 * address: 0x021D6CBC
 * packet: pkt_ov116_021D6CBC
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02012EF0 and 02012EFC lack an outside code witness.
 * blocker: 0x02012EF0 verified EXACT in 12EF0-r1.log (Thumb, dsi/1.1p1 -O4,p).
 *   extern int func_020071CC(void *,int);
 *   int func_02012EF0(void **p) { return func_020071CC(*p,58); }
 * blocker: 0x02012EFC verified EXACT in 12EFC-r1.log (Thumb, dsi/1.1p1 -O4,p).
 *   extern int func_020071CC(void *,int);
 *   int func_02012EFC(void **p) { return func_020071CC(*p,59); }
 * symbols:
 *   func_02012EFC 0x02012EFC thumb
 *   func_02012EF0 0x02012EF0 thumb
 *   func_021B9B00 0x021B9B00 thumb ov114
 *   func_021C9744 0x021C9744 arm ov114
 *   func_021D70E4 0x021D70E4 thumb ov116
 *   func_021D6D40 0x021D6D40 thumb ov116
 */
typedef unsigned char u8;
extern void *func_02012EBC(void *);
extern int func_02012EFC(void *);
extern int func_02012EF0(void *);
extern void func_021B9B00(u8 *,int);
extern void func_021C9744(void *,void *);
extern void func_021D70E4(u8 *);
extern void func_021D6D40(void *,void *,int);
void func_021D6CBC(u8 *p,void *q,u8 *r) {
    int a,b,c;
    func_02012EBC(q);
    a = func_02012EFC(q);
    b = func_02012EF0(q);
    c = *(int *)(p+0x218);
    func_021B9B00(p+4,c);
    func_021C9744(p+4,p+0x68);
    func_021D70E4(r);
    func_021D6D40(p+0x70,q,c);
    *(int *)(p+0x160)=a;
    *(int *)(p+0x164)=b;
}
