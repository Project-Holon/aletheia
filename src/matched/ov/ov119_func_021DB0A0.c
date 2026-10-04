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
typedef unsigned short u16;

extern void *func_021D8D4C(void **a, int b, int c, char *p);
extern int func_021D8A24(void *);
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_020173EC(int);
typedef unsigned int   u32;
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
extern void func_020307B0(int);
extern void func_021D9468(void *,int,void *);
int func_021DB0A0(char *p)
{
    int t=(int)func_021D8D4C(*(void ***)(p+0x828),*(int *)(p+0xf88),*(int *)(p+0xf84),p);
    if(func_021D8A24(p)) {
        unsigned id=(unsigned)func_020399A8();
        if(func_0203D3A8((void *)id,0xc01,func_020173EC(id),t)==0) {
            func_020307B0(t);
            return 0;
        }
    }
    func_021D9468(p,0,(void *)t);
    func_020307B0(t);
    return 1;
}
