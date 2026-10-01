/*
 * function: func_021F851C
 * address: 0x021F851C
 * packet: pkt_ov184_021F851C
 * region: ov184
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov112_id 0x00000070 data
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_021F89D0 0x021F89D0 thumb ov184
 *   func_021F88E0 0x021F88E0 thumb ov184
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_02025588 0x02025588 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_02034A5C 0x02034A5C arm
 */
extern void func_021FD714(int);
extern void func_021F89D0(int *,char *);
extern void func_021F88E0(char *,char *);
extern void func_021FD820(char *);
extern void func_021FD15C(void *,int);
extern void func_02025588(int);
extern void func_0201C4C0(int);
extern void func_020315D4(int);
extern void func_02034A5C(int);
extern char ov112_id[];
int func_021F851C(int obj,int b,char *q,char *p)
{
    int i;
    func_021FD714(*(int *)(p+0xc));
    func_021F89D0((int *)p,q);
    func_021F88E0(p,q);
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0x14));
    if (*(void **)(p+0x10)) {
        func_021FD15C(*(void **)(p+0x10),*(int *)(q+0xc));
        *(int *)(p+0x10)=0;
    }
    func_02025588(*(int *)(p+0x1c));
    func_0201C4C0(*(int *)(p+0x20));
    func_020315D4(obj);
    func_02034A5C((int)ov112_id);
    return 1;
}
