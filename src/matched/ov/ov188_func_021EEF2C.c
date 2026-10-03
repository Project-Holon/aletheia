/*
 * function: func_021EEF2C
 * address: 0x021EEF2C
 * packet: pkt_ov188_021EEF2C
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020173EC 0x020173EC thumb
 *   func_02030734 0x02030734 arm
 *   func_0201A954 0x0201A954 thumb
 *   func_021EEBF0 0x021EEBF0 thumb ov188
 *   func_02017E40 0x02017E40 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_020307B0 0x020307B0 arm
 *   d_021EF360 0x021EF360 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020173EC(void);
extern void *func_02030734(u16,u32,int,const char *,u16);
extern void func_0201A954(void *,int);
extern void func_021EEBF0(void *,void *);
extern void func_02017E40(void *,u32,u32);
extern u32 func_0201A98C(void *,void *);
extern void func_020307B0(void *);
extern char d_021EF360[];
void func_021EEF2C(u8 *a,void *b,u32 c)
{
    int i;
    u8 *p;
    p=func_02030734((c & 0x7FFF)|0x8000,func_020173EC(),1,d_021EF360,173);
    func_0201A954(b,*(u16 *)a);
    for(i=0;i<*(u16 *)(a+2);i++) {
        func_021EEBF0(a+4+i*112,p);
        func_02017E40(p,159,0);
        func_0201A98C(b,p);
    }
    func_020307B0(p);
}
