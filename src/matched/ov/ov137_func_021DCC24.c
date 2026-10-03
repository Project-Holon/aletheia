/*
 * function: func_021DCC24
 * address: 0x021DCC24
 * packet: pkt_ov137_021DCC24
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: packet byte +2 is read at 0x021DCC42 and again at 0x021DCC50.
 * symbols:
 * func_02039338 0x02039338 arm
 * func_021DCAFC 0x021DCAFC thumb ov137
 * func_021841A4 0x021841A4 thumb ov022
 * func_021841A0 0x021841A0 thumb ov022
 * func_02080D24 0x02080D24 arm
 * func_021DCBC4 0x021DCBC4 thumb ov137
 * func_021DE08C 0x021DE08C thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Packet {u8 a,b; volatile u8 c; u8 d;};
extern u16 func_02039338(void);
extern void *func_021DCAFC(u8 *p);
extern unsigned func_021841A4(void *),func_021841A0(void *);
extern u32 func_02080D24(int);
extern void func_021DCBC4(void *p, u32 a, const void *b, u32 c);
extern void func_021DE08C(char *,int,int);
void func_021DCC24(int a,int b,u8 *c,u8 *p)
{
    struct Packet s;
    if(a!=0) {
        if(func_02039338()!=0) return;
        s=*(struct Packet *)c;
        s.a=a; s.b=*(u32 *)(p+44);
        switch(((struct Packet *)c)->c) {
        case 0:
            if(*(u32 *)(p+44)!=func_021841A4(func_021DCAFC(p)) ||
               *(u32 *)(p+44)!=func_02080D24(func_021841A0(func_021DCAFC(p)))) s.d=0;
            else { *(u32 *)(p+48)|=1<<a; s.d=1; }
            break;
        case 1: break;
        }
        func_021DCBC4(p,0x2801,&s,4);
    } else {
        switch(c[2]) {
        case 0:
            a=c[0];
            if(a!=func_02039338()) return;
            if(c[3]==0) func_021DE08C(*(char **)(*(u8 **)p+32),8,a);
            else { *(u16 *)(p+56)=c[1]; func_021DE08C(*(char **)(*(u8 **)p+32),7,a); }
            break;
        case 1: func_021DE08C(*(char **)(*(u8 **)p+32),19,c[0]); break;
        }
    }
}
