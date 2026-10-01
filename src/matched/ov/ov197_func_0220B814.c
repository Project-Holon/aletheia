/*
 * function: func_0220B814
 * address: 0x0220B814
 * packet: pkt_ov197_0220B814
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * matching: named row index in Row[36][2] restores base-add-before-column-shift; raw byte row differs in seven bytes.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02020FB4 0x02020FB4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 */
extern void *func_020457B0(unsigned,unsigned);
extern void func_02020FB4(void *,unsigned,unsigned);
extern unsigned func_02045770(void *);
extern void func_0201C724(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
extern void func_02045808(void *);
typedef struct { unsigned short entry[36][2]; } Row;
void func_0220B814(char *p,int n)
{
    void *owner;
    int index;
    Row *row;
    void *buf=func_020457B0(130,*(unsigned short *)(*(char **)p+0xc));
    index=*(unsigned char *)(p+0x533);
    row=(Row *)(p+0x150);
    func_02020FB4(buf,row[index].entry[n][0],*(unsigned short *)(*(char **)p+0xc));
    owner=*(void **)(p+0x18);
    func_0201C724(owner,func_02045770(*(void **)(p+0x130)),4,0,(unsigned)buf,*(unsigned *)(*(char **)p+4),0x3c40);
    *(unsigned char *)(p+0x134)=1;
    func_02045808(buf);
}
