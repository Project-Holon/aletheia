/*
 * function: func_021E0618
 * address: 0x021E0618
 * packet: pkt_ov183_021E0618
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E06CE alignment padding.
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021E0754 0x021E0754 thumb ov183
 *   func_021E075C 0x021E075C thumb ov183
 *   func_021E0764 0x021E0764 thumb ov183
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD854 0x021FD854 thumb ov186
 */
typedef unsigned long long u64;
extern void func_021FE784(int, int, int, int);
extern int func_021FE7B0(int *);
typedef unsigned int   u32;
struct PrintSys;
extern void func_021E0754(char *p);
extern int func_021E075C(char *p);
extern unsigned long long func_021E0764(char *p);
extern void func_021F9BA0(int);
extern void func_021F9BF4(unsigned *ctx, unsigned index);
extern void func_021FD1BC(int);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD854(char *p);
int func_021E0618(int unused, int *state, int *q, int *p)
{
    switch (*state) {
    case 0:
        func_021FE784(q[0], 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0((int *)q[0])) *state = 2;
        break;
    case 2:
        func_021E0754((char *)p[1]);
        switch (func_021E075C((char *)p[1])) {
        case 1: func_021F9BA0(q[3]); *state = 3; break;
        case 2: *(u64 *)(q + 4) = func_021E0764((char *)p[1]); func_021F9BF4((unsigned int *)q[3], 2); *state = 3; break;
        }
        break;
    case 3:
        func_021FE784(q[0], 2, 3, 1);
        *state = 4;
        break;
    case 4:
        if (func_021FE7B0((int *)q[0])) *state = 5;
        break;
    case 5: return 1;
    }
    if (p[2]) func_021FD1BC(p[2]);
    func_0201C4E4((struct PrintSys *)p[3]);
    func_021FD854((char *)p[5]);
    return 0;
}
