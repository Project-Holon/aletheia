/*
 * function: func_021E3258
 * address: 0x021E3258
 * packet: pkt_ov170_021E3258
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EE008 0x021EE008 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_020260E0 0x020260E0 thumb
 *   func_021DF040 0x021DF040 thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021EA858 0x021EA858 thumb ov170
 *   func_021EF35C 0x021EF35C thumb ov170
 *   func_021EF36C 0x021EF36C thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 */
typedef unsigned char u8;
struct WinMgr;
extern void func_021ED55C(char **,int);
extern void func_021EE008(char *p, int a, int b);
extern void func_021EE038(char *p, int a, int b, int c);
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void func_021DF040(char *);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int func_021EA858(char *p, int a);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E01B0(u8 *);
extern void func_021EE364(char **,int,int);
extern void func_021ED544(char *p, int b);
extern void func_021ED508(u8 *,int,int);
extern void func_021DEFEC(char *p, int b);
extern void func_021EF68C(char *);
#define W(p) (*(char **)((p)+0x2C))
int func_021E3258(u8 *p)
{
    unsigned n;
    switch(*(int *)(W(p)+0xA194)) {
    case 0:
        func_021ED55C((char **)p,0);
        func_021EE008((char *)p,0,0);
        func_021EE038((char *)p,0,0,1);
        if(func_020260E0(*(void **)(W(p)+0x70))>=30) func_021DF040((char *)p);
        (*(int *)(W(p)+0xA194))++;
        GFL_USE_PlaySeDefaultVolume(0x669);
        return func_021EA858((char *)p,22);
    case 1:
        if(p[0x1B]==1) {
            func_021EF35C(*(struct WinMgr **)(W(p)+0x74));
            func_021EF36C(*(struct WinMgr **)(W(p)+0x74));
            (*(int *)(W(p)+0xA194))++;
            return func_021E8FC0((char *)p,(int)func_021E01B0,22);
        }
        n=func_020260E0(*(void **)(W(p)+0x70));
        if(n>=30) n=0;
        func_021EE364((char **)p,3,n);
        func_021ED544((char *)p,6);
        func_021ED508(p,14,1);
        func_021DEFEC((char *)p,n);
        *(int *)(W(p)+0xA194)=0;
        return 17;
    case 2:
        func_021EF68C(W(p));
        *(int *)(W(p)+0xA194)=0;
        return 33;
    }
    return 22;
}
