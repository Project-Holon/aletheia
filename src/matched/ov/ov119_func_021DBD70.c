/*
 * function: func_021DBD70
 * address: 0x021DBD70
 * packet: pkt_ov119_021DBD70
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021DD34C 0x021DD34C thumb ov119
 */
extern int func_021D8AA8(void *);
extern int func_021DD34C(void *,int,int);
int func_021DBD70(char *p,int a,int b) {
 if(func_021D8AA8(p)==0) {
  if(*(int *)(p+0xf84)==b && *(int *)(p+0xf88)==a) return 1;
 } else { if(func_021DD34C(p,a,b)!=-1) return 1; }
 return 0;
}
