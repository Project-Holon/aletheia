/*
 * function: func_0216C9CC
 * address: 0x0216C9CC
 * packet: pkt_ov010_0216C9CC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0216C978 0x0216C978 thumb ov010
 */
extern void *func_020122C0(void *,void *,void *,unsigned int);
extern void **func_020124E8(void *);
extern int func_0216C978(int, int *, int *);
void *func_0216C9CC(void *a,void *b,void *c) {
    void *t; void **p;
    t=func_020122C0(a,0,(void *)func_0216C978,0x3c); p=func_020124E8(t);
    p[0]=a; p[1]=b; p[2]=c; return t;
}
