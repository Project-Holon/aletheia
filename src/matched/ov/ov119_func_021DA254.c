/*
 * function: func_021DA254
 * address: 0x021DA254
 * packet: pkt_ov119_021DA254
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD5B4 0x021DD5B4 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF5D8 0x021DF5D8 thumb ov119
 */
extern int func_021DD5B4(void *,int,int);
extern void func_021D8E84(void *,int);
extern void func_021DF5D8(void *);
void func_021DA254(char *p) {
 if(func_021DD5B4(p,*(int *)(p+0xF84),*(int *)(p+0xF88))) func_021D8E84(p,(int)func_021DF5D8);
}
