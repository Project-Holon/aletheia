/*
 * function: func_021DE754
 * address: 0x021DE754
 * packet: pkt_ov119_021DE754
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Shared failure label; padded two-dimensional array members reproduce index scheduling.
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D9468 0x021D9468 thumb ov119
 *   func_020173EC 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021D8F60 0x021D8F60 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDAD4 0x021DDAD4 thumb ov119
 *   func_021DE70C 0x021DE70C thumb ov119
 */
extern unsigned func_02017E1C(void *,unsigned,unsigned);
extern void func_020061E4(int);
extern void func_021B6558(int,int,int);
extern void func_021D9468(void *,int,void *);
extern int func_020173EC(void);
extern void func_02082D44(void *,const void *,int);
extern void func_021D8F60(void *,int,int);
extern void func_021D8E84(void *,int);
extern void func_021DDAD4(void *),func_021DE70C(void *);
typedef struct { char pad[0xfa4]; int entry[2][3]; char gap[0x1c]; void *mon[2][3]; int value[2][3]; } State;
int func_021DE754(char *p,int idx)
{
    int row,col,entry;
    void *mon;
    int value;
    State *s=(State *)p;
    row=idx/3;
    col=idx%3;
    if(idx==-1) goto fail;
    entry=s->entry[1-row][col];
    if(entry==-1) goto fail;
    mon=s->mon[1-row][col];
    value=s->value[1-row][col];
    if(mon==0 || func_02017E1C(mon,169,0)==0) goto fail;
    *(int *)(p+0x10a0)=idx;
    func_020061E4(0x54c);
    func_021B6558(*(int *)(p+0x9c0),1,0);
    if(row!=0) {
        func_021D8E84(p,(int)func_021DDAD4);
    } else {
        func_021D9468(p,row,mon);
        func_02082D44(mon,*(void **)(p+0x106c),func_020173EC());
        func_021D8F60(p,0,value);
        func_021D8E84(p,(int)func_021DE70C);
    }
    return 1;
fail:
    return 0;
}
