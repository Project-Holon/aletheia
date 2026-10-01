/*
 * function: func_021C6520
 * address: 0x021C6520
 * packet: pkt_ov128_021C6520
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: direct assignment from postincrement preserves the old count load;
 *   the two-byte tail at 021C658A is zero padding.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009A1C 0x02009A1C thumb
 *   func_02009864 0x02009864 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void func_02082BCC(void *,int,int);
extern void *func_0201283C(void *);
extern int func_02009A1C(void *,int);
extern int func_02009864(void *,int,int);
void func_021C6520(char *p)
{
    int i;
    void *v;
    func_02082BCC(p+16,0,72);
    v=func_0201283C(*(void **)(p+4));
    *(int *)(p+16)=0;
    for(i=0;i<32;i++) {
        if(func_02009A1C(v,i)==1) {
            *(u8 *)(p+*(int *)(p+16)+24)=i;
            if(func_02009864(v,i,9)==2) *(u8 *)(p+*(int *)(p+16)+56)=255;
            else *(u8 *)(p+*(int *)(p+16)+56)=(*(int *)(p+20))++;
            *(int *)(p+16)=*(int *)(p+16)+1;
        }
    }
}
