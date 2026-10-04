/*
 * function: func_021D4B14
 * address: 0x021D4B14
 * packet: pkt_ov124_021D4B14
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   func_0203630C 0x0203630C arm
 *   func_0200854C 0x0200854C thumb
 *   d_021D4D4C 0x021D4D4C data ov124 a1
 *   func_021D4240 0x021D4240 thumb ov124
 */
typedef unsigned short u16;
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern char *func_0203159C(void *,unsigned,unsigned);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
typedef unsigned char  u8;
struct Sub0200852CObj;
extern void *func_0200846C(int a0);
extern unsigned int func_0203630C(void);
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
extern void func_021D4240(char *);
extern const char d_021D4D4C[];
int func_021D4B14(void *a,int b,void *c)
{
    char *p;
    void **q;
    func_0203064C(1,0x8a,0x60000);
    p = func_0203159C(a,0x60,0x8a);
    q = c;
    if (!q) {
        q = func_02030734(0x8a,8,1,d_021D4D4C,0x2f3);
        *q = func_0200846C(0x8a);
        if (func_0203630C() & 0x100) func_0200854C(*q,1);
        else func_0200854C(*q,0);
    }
    *(void **)(p + 4) = q;
    *(u16 *)p = 0x8a;
    func_021D4240(p);
    return 1;
}
