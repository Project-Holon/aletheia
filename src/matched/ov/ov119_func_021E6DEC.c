/*
 * function: func_021E6DEC
 * address: 0x021E6DEC
 * packet: pkt_ov119_021E6DEC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020437AC 0x020437AC arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
extern void func_0204B3B4(int);
extern void func_020437AC(void *);
extern void func_0204A8D4(unsigned int);
extern void func_0204ADA4(unsigned int);
extern void func_0204AFD8(unsigned int);
void func_021E6DEC(int p) {
    int i;
    for (i=0;i<8;i++) {
        if (*(int *)(p+i*4+0x10cc)) {
            func_0204B3B4(*(int *)(p+i*4+0x10cc));
            *(int *)(p+i*4+0x10cc)=0;
            func_020437AC(*(void **)(p+i*4+0x10f4));
            *(int *)(p+i*4+0x10f4)=0;
            func_0204A8D4(*(int *)(p+i*4+0x1114));
            *(int *)(p+i*4+0x1114)=0;
        }
    }
    if (*(int *)(p+0x10ec)) {func_0204ADA4(*(int *)(p+0x10ec));*(int *)(p+0x10ec)=0;}
    if (*(int *)(p+0x10ec)) {func_0204AFD8(*(int *)(p+0x111c));*(int *)(p+0x10ec)=0;}
}
