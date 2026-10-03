/*
 * function: func_021B6A10
 * address: 0x021B6A10
 * packet: pkt_ov180_021B6A10
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B814C 0x021B814C data a4
 *   func_021B7D5C 0x021B7D5C thumb ov180
 *   func_021B6704 0x021B6704 thumb ov180
 *   func_021B7F30 0x021B7F30 thumb ov180
 *   func_021B66E4 0x021B66E4 thumb ov180
 *   func_021B7300 0x021B7300 thumb ov180
 */
extern int (*d_021B814C[])(char *);
extern void func_021B7D5C(void *p);
extern void func_021B6704(char *);
extern void func_021B7F30(void *p);
extern void func_021B66E4(char *);
extern void func_021B7300(char *);
int func_021B6A10(char *p) {
    *(int *)(p+0x918c)=d_021B814C[*(int *)(p+0x918c)](p);
    if(*(int *)(p+0x918c)==10) return 0;
    if(*(int *)(p+8)==1) {
        func_021B7D5C(p); func_021B6704(p);
    } else if(*(int *)(p+8)==2) {
        func_021B7F30(p); func_021B66E4(p); func_021B7300(p);
    }
    return 1;
}
