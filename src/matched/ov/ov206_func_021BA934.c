/*
 * unit: yes
 * function: func_021BA934
 * address: 0x021BA934
 * packet: pkt_ov206_021BA934
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
struct Descriptor;
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_020452E8(struct Descriptor *d);
extern void func_020307B0(void *);
void func_021BA934(char *p)
{
    int i;
    func_0201C6EC(*(void **)(p+44));
    for(i=0;i<4;i++){
        *(int *)(p+i*4+124)=1;
        func_020452E8(*(void **)(p+i*4+108));
    }
    func_020307B0(*(void **)(p+688));
}
