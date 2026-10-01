/*
 * function: func_021E1D48
 * address: 0x021E1D48
 * packet: pkt_ov183_021E1D48
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02012E40 0x02012E40 thumb
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 */
extern int func_02012E40(int);
extern int func_021FF88C(int);
extern void func_021F9C6C(int);
extern void func_021FD71C(int);
extern int func_021FD72C(int);
extern void func_021FD854(int);
extern void func_0201C4E4(int);
extern void func_021FD1BC(int);
int func_021E1D48(int a,int b,int c,char *p)
{
    int i;
    if (!func_02012E40(*(int *)(*(char **)(p+0x18)+0x14)) && func_021FF88C(*(int *)(*(char **)(p+0x18)+0x10))==2) {
        func_021F9C6C(*(int *)(*(char **)(p+0x18)+0xc));
        return 1;
    }
    func_021FD71C(*(int *)(p+4));
    if (func_021FD72C(*(int *)(p+4))) return 1;
    for (i=0;i<2;i++) func_021FD854(*(int *)(p+i*4+0x10));
    func_0201C4E4(*(int *)p);
    func_021FD1BC(*(int *)(p+0xc));
    return 0;
}
