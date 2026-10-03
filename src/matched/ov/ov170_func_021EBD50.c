/*
 * function: func_021EBD50
 * address: 0x021EBD50
 * packet: pkt_ov170_021EBD50
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_0201EF14 0x0201EF14 thumb
 *   func_021EBA84 0x021EBA84 thumb ov170
 */
extern int func_021DD2D0(void ***,int,unsigned); extern void func_0201EF14(void *,unsigned,void *); extern void func_021EBA84(unsigned char *,int,int);
void func_021EBD50(unsigned char *p){void *m=(void *)func_021DD2D0((void ***)p,p[20],p[22]);func_0201EF14(*(void **)(*(unsigned char **)(p+44)+132),0,m);func_021EBA84(p,50,27);}
