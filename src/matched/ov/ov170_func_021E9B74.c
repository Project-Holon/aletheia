/*
 * function: func_021E9B74
 * address: 0x021E9B74
 * packet: pkt_ov170_021E9B74
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EA770 0x021EA770 thumb
 *   func_02026124 0x02026124 thumb
 *   func_021ECB84 0x021ECB84 thumb
 *   func_021E072C 0x021E072C thumb
 *   func_021ED75C 0x021ED75C thumb
 *   func_021ED594 0x021ED594 thumb
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
extern void func_02007F1C(void *,unsigned short,unsigned,unsigned);
extern void func_021ED55C(unsigned char *,int);
#define WORK (*(char **)(p+0x2c))
#define ITEM (*(unsigned short *)(p+0x10))
extern void func_021EA770(unsigned char *);
extern void func_02026124(void *,int);
extern void func_021ECB84(char *,unsigned);
extern void func_021E072C(unsigned char *);
extern void func_021ED75C(unsigned char *,int);
extern void func_021ED594(unsigned char *,unsigned);
int func_021E9B74(unsigned char *p)
{
    switch(p[0x13]) {
    case 0:
        func_021EB988(p,data_021EF918,4);
        func_021EF4E4(*(struct WinMgr **)(WORK+0x74)); func_021EBC58(p,p[0x16],1,0x18);
        func_021EE364(p,0xd,0x25); func_021ED588(p); return 0x23;
    case 1:
        func_021EB988(p,data_021EF918,4);
        func_021EF4E4(*(struct WinMgr **)(WORK+0x74)); func_021EBC58(p,p[0x16],1,0x18);
        func_021ECB20(p,1,1); func_021ED888(WORK,0);
        func_021EE364(p,0xe,0xa); func_021EA75C(p); func_021ED588(p); return 0x27;
    case 4:
        func_021EA770(p); func_021EE364(p,6,p[0x16]);
        func_02026124(*(void **)(WORK+0x70),0x27);
        p[0x16]=0xff; return 0x20;
    case 5:
        func_021EA770(p);
        if(p[0x16]<0x1e && p[0x14]!=p[0x17])
            func_021EC48C(p,p[0x17],p[0x16],*(unsigned char *)(WORK+0x3df6));
        else func_021ECB84(WORK,p[0x16]);
        func_021E072C(p); func_021ED75C(p,0x24);
        func_021EE364(p,6,p[0x1d]); func_02026124(*(void **)(WORK+0x70),0x27);
        func_021ED594(p,0x24); return 0x20;
    }
    return 0;
}
