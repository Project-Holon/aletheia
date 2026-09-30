/*
 * function: func_021DF43C
 * address: 0x021DF43C
 * packet: pkt_ov119_021DF43C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF404 0x021DF404 thumb ov119
 *   func_021DF3E4 0x021DF3E4 thumb ov119
 */
extern int func_020279E8(int);
extern int func_02027A04(int);
extern void func_021E12F8(void *);
extern void func_021E1098(void *);
extern void func_021D8E84(void *, int);
extern void func_021DF404(void *);
extern void func_021DF3E4(void *);
void func_021DF43C(void *p)
{
    int v;
    if (!func_020279E8(*(int *)((char *)p+0x64c))) return;
    v=func_02027A04(*(int *)((char *)p+0x64c));
    func_021E12F8(p);
    func_021E1098(p);
    *(int *)((char *)p+0x64c)=0;
    if (v==0) {func_021D8E84(p,(int)func_021DF404);return;}
    func_021E1098(p);
    func_021D8E84(p,(int)func_021DF3E4);
}
