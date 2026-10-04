/*
 * function: func_021E20A4
 * address: 0x021E20A4
 * packet: pkt_ov183_021E20A4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: zero alignment halfword at 021E20F6.
 * symbols:
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021E24AC 0x021E24AC thumb ov183
 *   func_021E24C4 0x021E24C4 thumb ov183
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_020315D4 0x020315D4 arm
 */
extern void func_021FD820(int);
extern void func_021E24AC(char *,char *);
extern void func_021E24C4(char *,char *);
extern void func_0201C4C0(int);
extern void func_021FD714(int);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
int func_021E20A4(int obj,int b,char *arg,char *p)
{
    int i;
    for (i=0;i<2;i++) func_021FD820(*(int *)(p+i*4+0x14));
    if (*(int *)(*(char **)(p+0x20)+0x1c)) func_021E24AC(p,arg);
    else { func_021E24AC(p,arg); func_021E24C4(p,arg); }
    func_0201C4C0(*(int *)p);
    func_021FD714(*(int *)(p+8));
    func_020315D4((struct S020315D4 *)obj);
    return 1;
}
