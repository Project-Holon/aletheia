/*
 * function: func_021F31F4
 * address: 0x021F31F4
 * packet: pkt_ov194_021F31F4
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021F38CC 0x021F38CC thumb ov194
 *   func_021F36E8 0x021F36E8 thumb ov194
 *   func_021F37EC 0x021F37EC thumb ov194
 *   func_021F391C 0x021F391C thumb ov194
 *   func_021F3BD4 0x021F3BD4 thumb ov194
 *   func_021F3A0C 0x021F3A0C thumb ov194
 *   func_021F3B18 0x021F3B18 thumb ov194
 *   func_021F3C40 0x021F3C40 thumb ov194
 *   func_021F33C0 0x021F33C0 thumb ov194
 *   func_021F23E4 0x021F23E4 thumb ov194
 *   func_021F2828 0x021F2828 thumb ov194
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F1BFC 0x021F1BFC thumb ov194
 *   func_021F3304 0x021F3304 thumb ov194
 */
typedef struct {int x,y;} Pair;
typedef struct {int left,top,right,bottom;} Rect;
extern void func_02082BCC(void *,unsigned,unsigned);
extern int func_021F38CC(char *,int *),func_021F36E8(char *,int *),func_021F37EC(char *,int *);
extern void func_021F391C(char *,int *);
extern int func_021F3BD4(char *,int *),func_021F3A0C(char *,int *),func_021F3B18(char *,int *);
extern void func_021F3C40(char *,int *);
extern int func_021F33C0(char *),func_021F23E4(char *),func_021F3304(char *);
extern int func_021F2828(const char *,int,Pair *);
extern void func_021F2818(char *a, int b, int c);
extern void func_021F1BFC(char *,int,const Rect *);
void func_021F31F4(char *p,char *q)
{
    int out0[4];
    int out2[4];
    Rect rect;
    int result;
    *(int *)(p+0xE8)=0;
    switch(*(int *)(p+0xE4)){
    case 0:
        func_02082BCC(out0,0,16);
        result=func_021F38CC(p,out0);
        if(!result){func_021F36E8(p,out0);result=func_021F37EC(p,out0);}
        if(result)func_021F391C(p,out0);
        break;
    case 2:
        func_02082BCC(out2,0,16);
        result=func_021F3BD4(p,out2);
        if(!result){func_021F3A0C(p,out2);result=func_021F3B18(p,out2);}
        if(result)func_021F3C40(p,out2);
        if(func_021F33C0(p))*(int *)(p+0xE4)=0;
        break;
    case 1:
        if(func_021F23E4(q)){func_021F2828(p,7,(Pair *)(p+0xD8));*(int *)(p+0xE8)=11;}
        *(int *)(p+0xE4)=0;
        break;
    }
    func_021F2818(p,(int)(p+0xD8),(int)&rect);
    func_021F1BFC(p+0x24,*(int *)(p+0x100),&rect);
    func_021F3304(p);
}
