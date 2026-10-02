/*
 * function: func_021DB0A0
 * address: 0x021DB0A0
 * packet: pkt_ov119_021DB0A0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8D4C 0x021D8D4C thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_020173EC 0x020173EC thumb
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021D9468 0x021D9468 thumb ov119
 */
extern int func_021D8D4C(int,int,int,void *);
extern int func_021D8A24(void *);
extern unsigned func_020399A8(void);
extern int func_020173EC(int);
extern int func_0203D3A8(void *a, unsigned int b, unsigned short c, unsigned int d);
extern void func_020307B0(int);
extern void func_021D9468(void *,int,int);
int func_021DB0A0(char *p)
{
    int t=func_021D8D4C(*(int *)(p+0x828),*(int *)(p+0xf88),*(int *)(p+0xf84),p);
    if(func_021D8A24(p)) {
        unsigned id=func_020399A8();
        if(func_0203D3A8((void *)id,0xc01,func_020173EC(id),t)==0) {
            func_020307B0(t);
            return 0;
        }
    }
    func_021D9468(p,0,t);
    func_020307B0(t);
    return 1;
}
