/*
 * function: func_021D9EA8
 * address: 0x021D9EA8
 * packet: pkt_ov119_021D9EA8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8B38 0x021D8B38 thumb ov119
 */
extern void func_021D8B38(void *);
void func_021D9EA8(char *p,int a,int b) {
 *(int *)(p+0xF74)=a;
 *(int *)(p+0xF78)=b;
 func_021D8B38(p);
}
