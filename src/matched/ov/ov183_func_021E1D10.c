/*
 * function: func_021E1D10
 * address: 0x021E1D10
 * packet: pkt_ov183_021E1D10
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_020315D4 0x020315D4 arm
 */
extern void func_021FD820(char *);
extern void func_021FD15C(void *,int);
struct PrintSys;
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021FD714(void *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
int func_021E1D10(struct S020315D4 *a,int b,char *q,char *p){int i;for(i=0;i<2;i++)func_021FD820(*(char **)(p+i*4+16));func_021FD15C(*(void **)(p+12),*(int *)(q+8));func_0201C4C0(*(void **)p);func_021FD714((void *)(*(int *)(p+4)));func_020315D4(a);return 1;}
