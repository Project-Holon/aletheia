/*
 * function: func_021E35D8
 * address: 0x021E35D8
 * packet: pkt_ov170_021E35D8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EE008 0x021EE008 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021EA858 0x021EA858 thumb ov170
 *   func_021EF35C 0x021EF35C thumb ov170
 *   func_021EF36C 0x021EF36C thumb ov170
 *   func_021EC5A0 0x021EC5A0 thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021EE754 0x021EE754 thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 */
typedef unsigned char u8;
struct WinMgr;
extern void func_021EC000(char *,int,int);
extern void func_021EE008(char *p, int a, int b);
extern void func_020061E4(unsigned);
extern int func_021EA858(char *p, int a);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EC5A0(char **,int);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E01B0(u8 *);
extern void func_021EE364(char **,int,int);
extern void func_021EE754(u8 *,unsigned);
extern void func_021DEFEC(char *p, int b);
extern void func_021EF68C(char *);
#define W(p) (*(char **)((p)+0x2C))
int func_021E35D8(u8 *p)
{
    switch(*(int *)(W(p)+0xA194)) {
    case 0:
        func_021EC000(W(p),4,0);
        func_021EE008((char *)p,0,0);
        func_020061E4(0x669);
        (*(int *)(W(p)+0xA194))++;
        return func_021EA858((char *)p,25);
    case 1:
        func_021EF35C(*(struct WinMgr **)(W(p)+0x74));
        func_021EF36C(*(struct WinMgr **)(W(p)+0x74));
        if(p[0x18]==1) func_021EC5A0((char **)p,1);
        else func_021EC5A0((char **)p,0);
        func_020061E4(0x669);
        (*(int *)(W(p)+0xA194))++;
        return func_021E8FC0((char *)p,(int)func_021E01B0,25);
    case 2:
        func_021EE364((char **)p,6,30);
        func_021EE754(p,30);
        if(p[0x18]==0) func_021DEFEC((char *)p,30);
        func_021EF68C(W(p));
        *(int *)(W(p)+0xA168)=30;
        *(int *)(W(p)+0xA194)=0;
        return 32;
    }
    return 25;
}
