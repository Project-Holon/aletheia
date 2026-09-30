/*
 * function: func_021D580C
 * address: 0x021D580C
 * packet: pkt_ov123_021D580C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 */
extern void func_020286C4(void *, void *, void *);
extern int func_02028484(void *, void *);
extern void func_0201CE48(void *);
int func_021D580C(char *p)
{
    if (*(void **)(p+0x80)) {
        func_020286C4(*(void **)(p+0x40), *(void **)(p+0x80), *(void **)(p+0x44));
        if (!func_02028484(p+0xa8, *(void **)(p+0x80))) return 0;
        func_0201CE48(*(void **)(p+0x80));
        *(void **)(p+0x80)=0;
    }
    return 1;
}
