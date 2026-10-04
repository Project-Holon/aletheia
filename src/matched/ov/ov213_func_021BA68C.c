/*
 * function: func_021BA68C
 * address: 0x021BA68C
 * packet: pkt_ov213_021BA68C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B8A0 0x0204B8A0 arm
 */
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v),func_0204B92C(void *,unsigned),func_0204B8A0(void *,unsigned short);
void func_021BA68C(char *p,unsigned i,int kind){int n;switch(kind){case 0:n=7;break;case 1:n=8;break;case 2:n=9;break;}p+=24;func_0204B3DC(*(void **)((unsigned)p+i*4),1);func_0204B92C(*(void **)((unsigned)p+i*4),1);func_0204B8A0(*(void **)((unsigned)p+i*4),n);}
