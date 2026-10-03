/*
 * function: func_021B687C
 * address: 0x021B687C
 * packet: pkt_ov174_021B687C
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_021B7364 0x021B7364 thumb ov174
 *   func_02028484 0x02028484 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 */
typedef unsigned char u8;
extern void func_020310C4(void *),func_020286C4(void *,void *,void *),func_0201CE48(void *),func_02045808(void *);
extern unsigned func_0201CE30(void *);
extern void func_021B7364(char *p, int v);
extern int func_02028484(void *,void *),func_0201C4E4(void *);
void func_021B687C(u8 *p)
{
    func_020310C4(*(void **)(p+88));
    if(*(void **)(p+100)) {
        func_020286C4(*(void **)(p+124),*(void **)(p+100),*(void **)(p+92));
        if(func_0201CE30(*(void **)(p+100))!=0) func_021B7364(*(void **)(p+28+*(u8 *)(p+136)*4),0);
        else func_021B7364(*(void **)(p+28+*(u8 *)(p+136)*4),1);
        if(func_02028484(p+128,*(void **)(p+100))==1) {
            func_0201CE48(*(void **)(p+100));
            *(void **)(p+100)=0;
            func_02045808(*(void **)(p+112));
            *(void **)(p+112)=0;
        }
    }
    func_0201C4E4(*(void **)(p+120));
}
