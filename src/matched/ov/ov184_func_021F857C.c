/*
 * function: func_021F857C
 * address: 0x021F857C
 * packet: pkt_ov184_021F857C
 * region: ov184
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021F3C50 0x021F3C50 thumb ov112
 */
extern int func_021FF88C(char *);
extern void func_021F9C6C(char *);
extern void func_021FD71C(char *);
extern int func_021FD72C(int *);
extern void func_021FD854(char *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD1BC(char *);
extern void func_021F3C50(char *);
int func_021F857C(int a,int b,int c,char *p)
{
    int i;
    if (func_021FF88C(*(char **)(*(char **)(p+48)+20))==2) {
        func_021F9C6C(*(char **)(*(char **)(p+48)+16));
        return 1;
    }
    func_021FD71C(*(char **)(p+12));
    if (func_021FD72C(*(int **)(p+12))) return 1;
    for (i=0;i<2;i++) func_021FD854(*(char **)(p+i*4+20));
    func_0201C4E4((struct PrintSys *)(*(int *)(p+32)));
    if (*(char **)(p+16)) func_021FD1BC(*(char **)(p+16));
    if (*(char **)p) func_021F3C50(*(char **)p);
    return 0;
}
