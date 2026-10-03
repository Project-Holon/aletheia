/*
 * function: func_021E9848
 * address: 0x021E9848
 * packet: pkt_ov170_021E9848
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EF670 0x021EF670 thumb
 *   func_021EA75C 0x021EA75C thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_021EF68C 0x021EF68C thumb
 *   func_021ED588 0x021ED588 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021EB988 0x021EB988 thumb
 *   data_021EF918 0x021EF918 data a1
 *   func_021EF4E4 0x021EF4E4 thumb
 *   func_021EBC58 0x021EBC58 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021DD2D0 0x021DD2D0 thumb
 *   func_021DD2B4 0x021DD2B4 thumb
 *   func_021DD718 0x021DD718 thumb
 *   func_021DD8A8 0x021DD8A8 thumb
 *   func_021EC48C 0x021EC48C thumb
 *   func_02007F1C 0x02007F1C thumb
 *   func_021ED55C 0x021ED55C thumb
 */
struct WinMgr;
extern void func_021EF670(char *);
extern void func_021EA75C(unsigned char *);
extern void func_021ECB20(unsigned char *,int,int);
extern void func_021ED888(char *,int);
extern void func_021EE364(unsigned char *,int,int);
extern void func_021EF68C(char *);
extern void func_021ED588(unsigned char *);
extern void func_021DEFEC(unsigned char *,int);
extern void func_021EB988(unsigned char *,const void *,unsigned);
extern const unsigned char data_021EF918[];
extern void func_021EF4E4(struct WinMgr *mgr);
extern void func_021EBC58(unsigned char *,int,int,int);
extern unsigned func_0202136C(unsigned short);
extern void *func_021DD2D0(unsigned char *,int,unsigned);
extern void func_021DD2B4(unsigned char *,int,int,int,int);
extern int func_021DD718(unsigned char *,void *);
extern void func_021DD8A8(unsigned char *,unsigned);
extern void func_021EC48C(unsigned char *,int,int,int);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern void func_021ED55C(unsigned char *,int);
#define WORK (*(char **)(p+0x2c))
#define ITEM (*(unsigned short *)(p+0x10))
int func_021E9848(unsigned char *p)
{
    int next;
    void *mon;
    switch(p[0x13]) {
    case 0: func_021EF670(WORK); next=0x23; break;
    case 1:
        func_021EA75C(p); func_021ECB20(p,1,1); func_021ED888(WORK,0);
        func_021EE364(p,0xe,0xb); func_021EF68C(WORK); next=0x27; break;
    }
    func_021ED588(p);
    if(ITEM==0) {
        func_021DEFEC(p,p[0x16]); func_021EB988(p,data_021EF918,4);
        func_021EF4E4(*(struct WinMgr **)(WORK+0x74)); func_021EBC58(p,p[0x16],1,0x18);
        return next;
    }
    if(func_0202136C(ITEM)==0) {
        mon=func_021DD2D0(p,p[0x14],p[0x16]);
        func_021DD2B4(p,p[0x16],p[0x14],6,ITEM);
        if(func_021DD718(p,mon)==1) {
            func_021DD8A8(p,p[0x16]);
            func_021EC48C(p,p[0x14],p[0x16],*(unsigned char *)(WORK+p[0x16]+0x3dd2));
        }
        func_02007F1C(*(void **)(*(char **)p+0xc),ITEM,1,0x804c);
    }
    func_021DEFEC(p,p[0x16]); func_021ED55C(p,0);
    return 0x54;
}
