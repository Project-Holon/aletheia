/*
 * function: func_021D5BAC
 * address: 0x021D5BAC
 * packet: pkt_ov131_021D5BAC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D62F4 0x021D62F4 thumb ov131
 */
typedef unsigned int   u32;
extern void *func_021D6064(unsigned char *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_021D62F4(void *,void *);
int func_021D5BAC(unsigned char *p,int direction,unsigned short *out) {
 int result=0;
 int old;
 int done;
 void *m;
 done=0;
 old=*(unsigned short *)(p+24);
 do {
 if(direction==1 && *(unsigned short *)(p+24)>=(*(unsigned char **)(p+8))[14]-1) {done=1;continue;}
 if(direction==0 && *(unsigned short *)(p+24)==0) {done=1;continue;}
 if(direction==1) ++*(unsigned short *)(p+24); else --*(unsigned short *)(p+24);
 m=func_021D6064(p);
 if(func_02017E88(m,169,0)!=0) {
 if(func_02017E88(m,76,0)!=1 || *(int *)(p+88)==0) {
 if(*(int *)(p+88)!=2 || func_021D62F4(p,m)!=0) {done=1;result=1;}
 }
 }
 } while(done==0);
 if(out) *out=*(unsigned short *)(p+24);
 *(unsigned short *)(p+24)=old;
 return result;
}
