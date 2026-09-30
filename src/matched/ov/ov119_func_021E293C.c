/*
 * function: func_021E293C
 * address: 0x021E293C
 * packet: pkt_ov119_021E293C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_021E0E4C 0x021E0E4C thumb ov119
 */
extern void func_020452E8(int);
extern void func_021E0E4C(void *);
void func_021E293C(char *p,int i)
{
    if (*(int *)(p+0x5c4+4*i)) {
        func_020452E8(*(int *)(p+0x5c4+4*i));
        func_020452E8(*(int *)(p+0x5cc+4*i));
        func_021E0E4C(p+0x8c4+20*(i+1));
        *(int *)(p+0x5c4+4*i)=0;
        *(int *)(p+0x5cc+4*i)=0;
    }
}
