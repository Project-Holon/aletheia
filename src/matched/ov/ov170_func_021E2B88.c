/*
 * function: func_021E2B88
 * address: 0x021E2B88
 * packet: pkt_ov170_021E2B88
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021ECB84 0x021ECB84 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EF57C 0x021EF57C thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021EA83C 0x021EA83C thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EA114 0x021EA114 thumb ov170
 */
typedef unsigned char u8;
typedef struct { u8 lo:4; u8 hi:4; } Nib;
struct WinMgr;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void func_021DEFEC(u8 *,int);
extern void func_021EBA5C(char *,int);
extern void func_021DD14C(u8 *);
extern void func_021EF670(char *);
extern void func_021ECB84(char *,unsigned);
extern void func_021ED55C(char **,int);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021E8FC0(u8 *,int (*)(u8 *),int);
extern int func_021E0190(u8 *);
extern void func_020061E4(unsigned);
extern int func_021EA83C(u8 *,int);
extern void func_021EE364(char **,int,int);
extern void func_021ED544(u8 *,int);
extern void func_021EE038(u8 *,int,int,int);
extern unsigned func_021DD25C(void ***,unsigned short,int,unsigned,unsigned);
extern void func_021ED508(u8 *,int,int);
extern int func_021EA114(u8 *,unsigned);
#define W(p) (*(char **)((p)+0x2C))
#define LO(p) (((Nib *)((p)+0x1C))->lo)
int func_021E2B88(u8 *p)
{
    switch(*(int *)(W(p)+0xA194)) {
    case 0:
        p[0x19]=p[0x14];
        if(LO(p)==1) {
            p[0x17]=255;
            p[0x16]=func_020260E0(*(void **)(W(p)+0x70));
            if(p[0x16]>=30) {
                p[0x16]=0;
                func_021DEFEC(p,p[0x16]);
            }
        } else {
            p[0x17]=p[0x14];
            func_021EBA5C(W(p),24);
            func_021DD14C(p);
            func_021EF670(W(p));
            func_021ECB84(W(p),p[0x16]);
        }
        func_021ED55C((char **)p,0);
        func_021EF57C(*(struct WinMgr **)(W(p)+0x74));
        (*(int *)(W(p)+0xA194))++;
        return func_021E8FC0(p,func_021E0190,20);
    case 1:
        func_020061E4(0x669);
        (*(int *)(W(p)+0xA194))++;
        return func_021EA83C(p,20);
    case 2:
        func_021EE364((char **)p,4,p[0x16]);
        func_021ED544(p,6);
        func_021EE038(p,0,1,0);
        *(int *)(W(p)+0xA168)=p[0x16];
        *(int *)(W(p)+0xA194)=0;
        if(LO(p)==1) {
            if(!func_021DD25C((void ***)p,p[0x16],p[0x14],0xA9,0))
                func_021EE038(p,0,1,2);
            func_021ED508(p,13,1);
            return 21;
        }
        if(LO(p)==2) func_021ED508(p,13,1);
        else func_021ED508(p,14,1);
        return func_021EA114(p,p[0x16]);
    }
    return 20;
}
