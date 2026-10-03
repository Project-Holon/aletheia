/*
 * function: func_021B9B10
 * address: 0x021B9B10
 * packet: pkt_ov093_021B9B10
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021CD9F4 0x021CD9F4 thumb ov093
 */
typedef unsigned char u8;
extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern void func_021CD9F4(void *,int);
void func_021B9B10(u8 *p,u8 i,int v) {
    void *q;
    if(p[0x46e] && func_021B8B9C(p,i)) {
        q=*(void **)(p+i*4+16);
        if(q) func_021CD9F4(q,v);
    }
}
