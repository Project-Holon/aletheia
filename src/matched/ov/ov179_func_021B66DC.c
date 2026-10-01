/*
 * unit: yes
 * function: func_021B66DC, func_021B6710
 * address: 0x021B66DC
 * packet: pkt_ov179_021B66DC
 * region: ov179
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B6A40 0x021B6A40 data a4
 *   d_021B6A90 0x021B6A90 data a4
 */
extern int (*d_021B6A40[])(char *,int *);
extern const unsigned d_021B6A90[];
int func_021B66DC(char *p) {
 int *q; int result; q=*(int **)(p+0x601C);
 result=d_021B6A40[q[0]](p,q);
 if(result) {
  q=*(int **)(p+0x601C);
  *(int **)(p+0x601C)=q+d_021B6A90[q[0]];
 }
 return result;
}
int func_021B6710(char *p,int *q) {
 if(*(int *)(p+0x6020)==q[1]) { *(int *)(p+0x6020)=0; return 2; }
 *(int *)(p+0x6020)=*(int *)(p+0x6020)+1; return 0;
}
