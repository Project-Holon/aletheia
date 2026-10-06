/*
 * function: func_021B9A1C
 * address: 0x021B9A1C
 * packet: pkt_ov114_021B9A1C
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * d_021CE31C 0x021CE31C data a2
 * func_021B9AA8 0x021B9AA8 thumb ov114
 * func_021B9AF8 0x021B9AF8 thumb ov114
 * d_021CE320 0x021CE320 data a4
 * func_021CAB1C 0x021CAB1C arm ov114
 * func_021CAA70 0x021CAA70 arm ov114
 */
typedef unsigned short u16;
extern u16 d_021CE31C;
extern unsigned int d_021CE320[];
extern void *func_021B9AA8(int);
extern void func_021B9AF8(void *);
extern void func_021CAB1C(void *, void *, int);
extern int func_021CAA70(void *data_ptr, int data_len, void *sign_ptr, void *mod_ptr);
int func_021B9A1C(void *a, int b, int c, char *d, u16 e)
{
    int result;
    d_021CE31C = e;
    func_021CAB1C(func_021B9AA8, func_021B9AF8, 0);
    result = func_021CAA70((void *)a, b*c, (void *)d, d_021CE320);
    d_021CE31C = 0xffff;
    return result;
}
