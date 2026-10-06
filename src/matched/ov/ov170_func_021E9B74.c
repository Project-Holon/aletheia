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
extern void func_021EA75C(int p);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021ED888(char *,int);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021EF68C(char *);
extern void func_021ED588(char *p);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
extern void func_021DEFEC(char *p, int b);
extern void func_021EB988(unsigned char *,const void *,unsigned);
extern const unsigned char data_021EF918[];
extern void func_021EF4E4(struct WinMgr *mgr);
extern void func_021EBC58(unsigned char *,int,int,int);
extern unsigned func_0202136C(unsigned short);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern int func_021DD718(void **pp, void *mon);
extern void func_021DD8A8(void **pp, u32 idx);
extern void func_021EC48C(unsigned char *,int,int,int);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern void func_021ED55C(char **p, int flag);
#define WORK (*(char **)(p+0x2c))
#define ITEM (*(unsigned short *)(p+0x10))
extern void func_021EA770(int p);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_021ECB84(char *,unsigned);
extern void func_021E072C(unsigned char *);
extern void func_021ED75C(char **p, int i);
extern void func_021ED594(char *p, unsigned i);
int func_021E9B74(unsigned char *p)
{
    switch(p[0x13]) {
    case 0:
        func_021EB988(p,data_021EF918,4);
        func_021EF4E4(*(struct WinMgr **)(WORK+0x74)); func_021EBC58(p,p[0x16],1,0x18);
        func_021EE364((char **)p,0xd,0x25); func_021ED588((char *)p); return 0x23;
    case 1:
        func_021EB988(p,data_021EF918,4);
        func_021EF4E4(*(struct WinMgr **)(WORK+0x74)); func_021EBC58(p,p[0x16],1,0x18);
        func_021ECB20((char *)p,1,1); func_021ED888(WORK,0);
        func_021EE364((char **)p,0xe,0xa); func_021EA75C((int)p); func_021ED588((char *)p); return 0x27;
    case 4:
        func_021EA770((int)p); func_021EE364((char **)p,6,p[0x16]);
        func_02026124(*(void **)(WORK+0x70),0x27);
        p[0x16]=0xff; return 0x20;
    case 5:
        func_021EA770((int)p);
        if(p[0x16]<0x1e && p[0x14]!=p[0x17])
            func_021EC48C(p,p[0x17],p[0x16],*(unsigned char *)(WORK+0x3df6));
        else func_021ECB84(WORK,p[0x16]);
        func_021E072C(p); func_021ED75C((char **)p,0x24);
        func_021EE364((char **)p,6,p[0x1d]); func_02026124(*(void **)(WORK+0x70),0x27);
        func_021ED594((char *)p,0x24); return 0x20;
    }
    return 0;
}
