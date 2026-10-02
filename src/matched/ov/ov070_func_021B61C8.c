/*
 * function: func_021B61C8
 * address: 0x021B61C8
 * packet: pkt_ov070_021B61C8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02007F7C 0x02007F7C thumb
 *   func_02007FA0 0x02007FA0 thumb
 */
typedef unsigned char u8;
extern int func_02007F7C(void *, unsigned int);
extern int func_02007FA0(void *, int);
int func_021B61C8(u8 *p)
{
    if (*(int *)(p + 0x81C)) return func_02007F7C(p + 0x20, 0x136);
    return func_02007FA0(*(void **)(p + 0x18), *(int *)(p + 0x80C));
}
