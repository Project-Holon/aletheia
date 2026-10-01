/*
 * function: func_021DD5B4
 * address: 0x021DD5B4
 * packet: pkt_ov119_021DD5B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_021D8D4C 0x021D8D4C thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021DD428 0x021DD428 thumb ov119
 *   func_021DF9E8 0x021DF9E8 thumb ov119
 *   func_021DD4F4 0x021DD4F4 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   func_020173EC 0x020173EC thumb
 *   func_021E6334 0x021E6334 thumb ov119
 */
extern unsigned func_020399A8(void);
extern int func_021D8D4C(int,int,int,char *);
extern int func_021D8A24(void *);
extern int func_021DD428(void *,int,int,int,void *);
extern int func_021DF9E8(char *,void *,int);
extern void func_021DD4F4(void *,int,int),func_020307B0(void *);
extern int func_020173EC(void);
extern void func_021E6334(void *,int,int,int,int,int);
int func_021DD5B4(char *p,int a,int b)
{
    int value,slot;
    unsigned i;
    func_020399A8();
    value=func_021D8D4C(*(int *)(p+0x828),*(int *)(p+0xf88),*(int *)(p+0xf84),p);
    if(func_021D8A24(p)) {
        i=0;
        slot=func_021DD428(p,0,a,b,(void *)value);
        if(slot!=-1) {
            if(func_021DF9E8(p,*(void **)(p+slot*4+0xfd8),slot+0xc07)==0) {
                func_021DD4F4(p,0,slot);
                func_020307B0((void *)value);
                return 0;
            }
            for(i=0;i<(unsigned)func_020173EC();i++) {}
        }
    } else {
        slot=func_021DD428(p,0,a,b,(void *)value);
    }
    if(slot==-1) {func_020307B0((void *)value);return 1;}
    func_021E6334(p,0,slot,value,1,0);
    func_020307B0((void *)value);
    return 1;
}
