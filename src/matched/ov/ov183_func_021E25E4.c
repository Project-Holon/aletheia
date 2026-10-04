/*
 * function: func_021E25E4
 * address: 0x021E25E4
 * packet: pkt_ov183_021E25E4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: zero alignment halfword at 021E263E.
 * symbols:
 *   func_021E2E48 0x021E2E48 thumb ov183
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_02025588 0x02025588 thumb
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_020315D4 0x020315D4 arm
 */
struct PrintSys;
extern void func_021E2E48(char *p, int a, int b);
extern void func_021FD820(char *);
extern void func_021FD15C(void *,int);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021FD714(void *p);
extern void func_02025588(void *p);
extern void func_021F9BA0(int);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
int func_021E25E4(int obj,int b,int c,char *p)
{
    int i;
    func_021E2E48(p+0x4c,(int)p,(int)(*(char **)(p+0x3c)));
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0x30));
    if (*(void **)(p+8)) {
        func_021FD15C(*(void **)(p+8),*(int *)(*(char **)(p+0x3c)+8));
        *(int *)(p+8)=0;
    }
    func_0201C4C0((struct PrintSys *)(*(int *)(p+4)));
    func_021FD714((void *)(*(int *)(p+0xc)));
    func_02025588((void *)(*(int *)p));
    func_021F9BA0(*(int *)(*(char **)(p+0x3c)+0x10));
    func_020315D4((struct S020315D4 *)obj);
    return 1;
}
