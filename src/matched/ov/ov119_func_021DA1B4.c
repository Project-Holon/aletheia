/*
 * function: func_021DA1B4
 * address: 0x021DA1B4
 * packet: pkt_ov119_021DA1B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD5B4 0x021DD5B4 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBBD0 0x021DBBD0 thumb ov119
 */
extern int func_021DD5B4(char *p, int a, int b);
extern void func_021D8E84(void *,int);
extern void func_021DBBD0(char *p);
void func_021DA1B4(char *p) {
 if(func_021DD5B4(p,*(int *)(p+0xF84),*(int *)(p+0xF88))) func_021D8E84(p,(int)func_021DBBD0);
}
