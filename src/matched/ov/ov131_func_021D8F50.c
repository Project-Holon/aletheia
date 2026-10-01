/*
 * function: func_021D8F50
 * address: 0x021D8F50
 * packet: pkt_ov131_021D8F50
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D9428 0x021D9428 thumb ov131
 *   func_021D91F0 0x021D91F0 thumb ov131
 */

extern unsigned int func_021D9428(unsigned char *, unsigned char);
extern void func_021D91F0(void *, unsigned char *, void *);
void func_021D8F50(void *a, unsigned char *p)
{
    unsigned char i;
    p[0x58]=255;
    p[0x59]=255;
    p[0x5a]=255;
    *(int *)(p+0x14)=0;
    *(int *)(p)=1;
    *(int *)(p+4)=0;
    *(int *)(p+8)=0;
    *(int *)(p+0xc)=1;
    *(int *)(p+0x20)=0;
    *(int *)(p+0x24)=0;
    for(i=0;i<10;i++) {
        *(unsigned short *)(p+i*20+0x70)=func_021D9428(p,i);
        func_021D91F0(a,p,p+0x70+i*20);
    }
}
