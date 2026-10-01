/*
 * function: func_021E11A8
 * address: 0x021E11A8
 * packet: pkt_ov119_021E11A8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200566C 0x0200566C thumb
 *   func_02028604 0x02028604 thumb
 *   func_021E106C 0x021E106C thumb ov119
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02028148 0x02028148 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02031140 0x02031140 arm
 */
extern void func_0200566C(void);
extern void func_02028604(void *);
extern void func_021E106C(void *);
extern void func_021E12F8(void *);
extern void func_0201CE48(int);
extern void func_02028148(void *);
extern void func_02027FD8(void *);
extern void func_020452E8(void *);
extern void func_0201ED04(void *);
extern void func_02045C04(void *);
extern void func_0201D83C(void *);
extern void func_02045808(void *);
extern void func_0201C6EC(unsigned);
extern void func_0201C4C0(unsigned);
extern void func_02031140(void *);
void func_021E11A8(char *p)
{
    int i;
    func_0200566C();
    if(*(int *)(p+0x744)) {
        func_02028604(*(void **)(p+0x74c));
        func_021E106C(p);
        func_021E12F8(p);
        if(*(int *)(p+0x72c)) {func_0201CE48(*(int *)(p+0x72c));*(int *)(p+0x72c)=0;}
        if(*(void **)(p+0x648)) {func_02028148(*(void **)(p+0x648));*(void **)(p+0x648)=0;}
        if(*(void **)(p+0x6b0)) {func_02027FD8(*(void **)(p+0x6b0));*(void **)(p+0x6b0)=0;}
        if(*(void **)(p+0x6b4)) {func_020452E8(*(void **)(p+0x6b4));*(void **)(p+0x6b4)=0;}
        for(i=0;i<2;i++) {if(*(void **)(p+i*4+0x5bc)) {func_020452E8(*(void **)(p+i*4+0x5bc));*(void **)(p+i*4+0x5bc)=0;}}
        func_0201ED04(*(void **)(p+0x724));
        func_02045C04(*(void **)(p+0x720));
        func_0201D83C(*(void **)(p+0x728));
        func_02045808(*(void **)(p+0x730));
        func_02045808(*(void **)(p+0x734));
        func_02045808(*(void **)(p+0x738));
        func_02045808(*(void **)(p+0x73c));
        func_0201C6EC(*(unsigned *)(p+0x740));
        func_0201C4C0(*(unsigned *)(p+0x740));
        func_02031140(*(void **)(p+0x744));
        *(int *)(p+0x744)=0;
    }
}
