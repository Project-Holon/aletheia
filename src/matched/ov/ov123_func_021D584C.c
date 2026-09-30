/*
 * function: func_021D584C
 * address: 0x021D584C
 * packet: pkt_ov123_021D584C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 * symbols:
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 */
extern void func_0202F038(void *);
extern void func_0201CE48(void *);
extern void func_0201F7A8(void *, int);
extern void func_020456F8(void *);
extern void func_02041B6C(int);
void func_021D584C(char *p)
{
    if (*(void **)(p+0x7c)) {
        func_0202F038(*(void **)(p+0x7c));
        *(void **)(p+0x7c)=0;
    }
    if (*(void **)(p+0x80)) {
        func_0201CE48(*(void **)(p+0x80));
        *(void **)(p+0x80)=0;
    }
    if (*(void **)(p+0x44)) {
        func_0201F7A8(*(void **)(p+0x44),2);
        func_020456F8(*(void **)(p+0x44));
        func_02041B6C(5);
    }
}
