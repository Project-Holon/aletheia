/*
 * function: func_021F67E0
 * address: 0x021F67E0
 * packet: pkt_ov215_021F67E0
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: repeated if/else-if call arms cross-jump; logical OR folds shorter branches.
 *   Explicit no-op cases 3 and 9 preserve nested and main switch table bounds.
 * TU: singleton --suggest-split concrete-correct MATCH; five overlay leaves
 *   subsequently filed at 6CC0,6EEC and unit 70F8 (7100,7110).
 * symbols:
 *   func_021F6CCC 0x021F6CCC thumb ov215
 *   func_021F6EEC 0x021F6EEC thumb ov215
 *   func_020061E4 0x020061E4 thumb
 *   func_02006238 0x02006238 thumb
 *   func_02006224 0x02006224 thumb
 *   func_02006148 0x02006148 thumb
 *   func_0200616C 0x0200616C thumb
 *   func_020061F8 0x020061F8 thumb
 *   func_021F6D58 0x021F6D58 thumb ov215
 *   func_021F70F8 0x021F70F8 thumb ov215
 *   func_021F6D7C 0x021F6D7C thumb ov215
 *   func_021F7100 0x021F7100 thumb ov215
 *   func_021F6CC0 0x021F6CC0 thumb ov215
 *   func_021F6D90 0x021F6D90 thumb ov215
 *   func_021F7110 0x021F7110 thumb ov215
 *   func_02017E1C 0x02017E1C thumb
 *   func_02006984 0x02006984 thumb
 *   func_02006650 0x02006650 thumb
 *   func_021F6D1C 0x021F6D1C thumb ov215
 *   func_02014C08 0x02014C08 thumb
 *   func_021F6E5C 0x021F6E5C thumb ov215
 *   func_021F7048 0x021F7048 thumb ov215
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_021F6CCC(char *,unsigned,int);
extern void func_021F6EEC(char *);
extern void func_020061E4(u32);
extern int func_02006238(void);
extern int func_02006224(u32);
extern int func_02006148(u32);
extern void func_0200616C(void *,int);
extern void func_020061F8(int);
extern void func_021F6D58(char *);
extern void func_021F70F8(char *);
extern int func_021F6D7C(char *);
extern int func_021F7100(char *);
extern void func_021F6CC0(char *);
extern void func_021F6D90(char *);
extern void func_021F7110(char *);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
extern int func_02006650(void);
extern void func_021F6D1C(char *);
extern void func_02014C08(char *);
extern void func_021F6E5C(char *);
extern void func_021F7048(char *);
#define W(o) (*(u32 *)(p+(o)))
void func_021F67E0(char *p)
{
    u32 limit,a,b;
    switch(W(12)) {
    case 0:
        if(W(16)) {
            W(12)=1;W(24)=0;
            func_021F6CCC(p,1,1);
            func_021F6EEC(*(char **)(p+68));
        }
        break;
    case 1:
        if(*(u16 *)(p+8)==490)limit=300;else limit=380;
        W(24)++;
        if(*(u16 *)(p+8)==490) {
            switch(W(40)) {
            case 0: if(W(24)==10){func_020061E4(1955);W(40)=1;}break;
            case 1: if(!func_02006238()){func_020061E4(1960);W(40)=2;}break;
            case 2: if(!func_02006238())W(40)=3;break;
            case 3:break;
            }
        }else{
            if(W(24)==20)func_020061E4(1954);
            else if(W(24)==109)func_020061E4(1954);
            else if(W(24)==218)func_020061E4(1488);
            if(W(24)==10)func_020061E4(1968);
            else if(W(24)==15)func_020061E4(1968);
            else if(W(24)==85)func_020061E4(1968);
            else if(W(24)==90)func_020061E4(1968);
            if(W(28)&&!func_02006224(W(32))) {
                W(28)=0;
                if(W(24)>=150&&W(24)<309)W(36)=20;
                else if(W(24)>309)W(36)=0;
            }
            if(W(24)>=150&&W(24)<limit) {
                if(!W(28)) {
                    if(!W(36)) {
                        W(32)=func_02006148(1967);
                        func_0200616C((void *)1967,W(32));
                        W(28)=1;
                    }else W(36)--;
                }
            }else if(W(24)==limit&&W(28)&&func_02006224(W(32))) {
                func_020061F8(W(32));W(28)=0;
            }
        }
        if(W(24)==limit) {
            func_021F6D58(p);func_021F70F8(p);func_020061E4(1935);W(12)=2;
        }
        break;
    case 2:if(func_021F6D7C(p))W(12)=3;break;
    case 3:if(func_021F7100(p)){func_021F6CC0(p);W(20)=1;W(12)=4;}break;
    case 4:W(20)=0;break;
    case 6:
        if(++W(24)>=120){func_021F6D90(p);func_021F7110(p);W(12)=7;W(24)=0;}
        break;
    case 7:
        if(++W(24)>=65) {
            W(12)=8;
            a=func_02017E1C(*(void **)(p+4),5,0);
            b=func_02017E1C(*(void **)(p+4),111,0);
            func_02006984(a,b,64,0,0,0,0,0);
        }
        break;
    case 8:if(!func_02006650())W(12)=9;break;
    case 9:break;
    }
    func_021F6D1C(p);
    func_02014C08(*(char **)(p+48));
    func_021F6E5C(*(char **)(p+68));
    func_021F7048(p);
}
