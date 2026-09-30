/*
 * function: func_021E12AC
 * address: 0x021E12AC
 * packet: pkt_ov119_021E12AC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020286C4 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   func_0201CE48 0x0201CE48 thumb
 */
extern void func_020286C4(int,int,int);
extern int func_02028484(void *,int);
extern void func_0201CE48(int);
int func_021E12AC(char *p) {int v=1;if(*(int *)(p+0x72c)) {if(*(int *)(p+0x71c))func_020286C4(*(int *)(p+0x74c),*(int *)(p+0x72c),*(int *)(p+0x71c));v=func_02028484(p+0x11d4,*(int *)(p+0x72c));if(v) {if(*(int *)(p+0x72c)) {func_0201CE48(*(int *)(p+0x72c));*(int *)(p+0x72c)=0;}}}return v;}
