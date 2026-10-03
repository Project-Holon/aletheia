/*
 * function: func_021D7248
 * address: 0x021D7248
 * packet: pkt_ov131_021D7248
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_021D79A8 0x021D79A8 thumb ov131
 */
typedef struct {int x,y,z;} Vec;
extern const short d_020A1B38[];
extern void func_021D79A8(void *p, unsigned char *q, int radius);
extern void func_02015C78(void *,Vec *);
int func_021D7248(unsigned char *p,unsigned char *q) {
 Vec v={0,0,0};
 int s;
 unsigned n;
 float f;
 if(*(int *)(q+16)==0) {
 s=d_020A1B38[((unsigned short)((*(unsigned short *)(q+98)<<15)/20)>>4)*2];
 n=*(unsigned *)(p+60)>>6;
 if(n) f=0.5f+(float)(n<<12); else f=(float)(n<<12)-0.5f;
 v.y=(s<<5)+(int)f;
 func_021D79A8(p,q,v.y);
 }
 func_02015C78(*(void **)q,&v);
 ++*(unsigned short *)(q+98);
 if(*(unsigned short *)(q+98)>20) {*(unsigned short *)(q+98)=0;return 1;}
 return 0;
}
