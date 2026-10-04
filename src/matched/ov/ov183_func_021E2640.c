/*
 * function: func_021E2640
 * address: 0x021E2640
 * packet: pkt_ov183_021E2640
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012E40 0x02012E40 thumb
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PrintSys;
extern u8 func_02012E40(const u8 *o);
extern int func_021FF88C(char *p);
extern void func_021F9C6C(int);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *p);
extern void func_021FD854(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD1BC(int);
extern int func_021FC830(u8 *p);
int func_021E2640(int a,int b,int c,char *p)
{
    int i;
    if (!func_02012E40((const u8 *)(*(int *)(*(char **)(p+0x3c)+0x14))) && func_021FF88C((char *)(*(int *)(*(char **)(p+0x3c)+0xc)))==2) {
        func_021F9C6C(*(int *)(*(char **)(p+0x3c)+0x10));
        return 1;
    }
    func_021FD71C((u8 *)(*(int *)(p+0xc)));
    if (func_021FD72C((int *)(*(int *)(p+0xc)))) return 1;
    for (i=0;i<2;i++) func_021FD854((char *)(*(int *)(p+i*4+0x30)));
    func_0201C4E4((struct PrintSys *)(*(int *)(p+4)));
    if (*(int *)(p+8)) func_021FD1BC(*(int *)(p+8));
    for (i=0;i<2;i++) if (*(int *)(p+i*4+0x28)) func_021FC830((u8 *)(*(int *)(p+i*4+0x28)));
    return 0;
}
