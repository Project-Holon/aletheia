/*
 * function: func_021DA2F4
 * address: 0x021DA2F4
 * packet: pkt_ov119_021DA2F4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035CB8 0x02035CB8 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
extern int func_02035CB8(int *,int *);
extern void func_021D8E84(void *,int);
extern void func_021DBE70(char *p);
void func_021DA2F4(void *p) {
 int a,b;
 if(!func_02035CB8(&a,&b)) func_021D8E84(p,(int)func_021DBE70);
}
