/*
 * function: func_021DB9B4
 * address: 0x021DB9B4
 * packet: pkt_ov119_021DB9B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD34C 0x021DD34C thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D94A0 0x021D94A0 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DB998 0x021DB998 thumb ov119
 */
typedef unsigned short u16;

extern int func_021D8A24(void *);
extern int func_021DD34C(char *,int,int);
extern void *func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern void func_021B6558(int,int,int);
extern void func_021D94A0(void *,int);
extern void func_021D8B38(void *);
extern void func_021D8E84(void *,int);
extern void func_021DB998(void *);
void func_021DB9B4(char *p)
{
    func_021DD34C(p,*(int *)(p+0xf98),*(int *)(p+0xf94));
    if(func_021D8A24(p)) {
        if(!func_0203D3A8(func_020399A8(),0xc06,0,0)) return;
    }
    func_021B6558(*(int *)(p+0x9c0),8,0);
    *(int *)(p+0xf84)=-1;
    *(int *)(p+0xf88)=-1;
    *(int *)(p+0xf7c)=-1;
    *(int *)(p+0xf80)=-1;
    *(int *)(p+0xf94)=-1;
    *(int *)(p+0xf98)=-1;
    func_021D94A0(p,0);
    func_021D8B38(p);
    func_021D8E84(p,(int)func_021DB998);
}
