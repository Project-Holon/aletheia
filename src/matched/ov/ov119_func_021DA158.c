/*
 * function: func_021DA158
 * address: 0x021DA158
 * packet: pkt_ov119_021DA158
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8D4C 0x021D8D4C thumb ov119
 *   func_021E2484 0x021E2484 thumb ov119
 *   func_021E1E00 0x021E1E00 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_021D8B38 0x021D8B38 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA318 0x021DA318 thumb ov119
 */

extern int func_021D8D4C(int,int,int,char *);
extern void func_021E2484(void *,int);
extern void func_021E1E00(void *,int,int);
extern int func_020355C4(void);
extern void func_021D8B38(void *);
extern void func_020307B0(int);
extern void func_021D8E84(void *,int);
extern void func_021DA318(void *);
void func_021DA158(char *p) {
    int v=func_021D8D4C(*(int *)(p+0x828),*(int *)(p+0xF98),*(int *)(p+0xF94),p);
    func_021E2484(p,0);
    func_021E1E00(p,*(int *)(p+0x10A0),v);
    if (func_020355C4()) func_021D8B38(p);
    func_020307B0(v);
    func_021D8E84(p,(int)func_021DA318);
}
