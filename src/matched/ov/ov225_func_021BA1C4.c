/*
 * function: func_021BA1C4
 * address: 0x021BA1C4
 * packet: pkt_ov225_021BA1C4
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BBF00 0x021BBF00 data a1
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
typedef unsigned char u8;
struct Descriptor;struct CharBuf;
struct Entry {u8 a,b,c,d,e,f,g,h,i;};
extern const struct Entry d_021BBF00[];
extern unsigned BMP_WIN_Create(unsigned,unsigned,unsigned,unsigned,u8,u8,u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
void func_021BA1C4(char *p)
{
    u8 i;
    for(i=0;i<2;i++) {
        const struct Entry *t=&d_021BBF00[i];
        *(unsigned *)(p+i*4+0x10)=BMP_WIN_Create(t->a,t->b,t->c,t->d,t->e,t->f,t->g);
        BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p+i*4+0x10)),0);
        BMP_WIN_TransferChars(*(struct Descriptor **)(p+i*4+0x10));
        *(unsigned *)(p+i*4+0x18)=0;
    }
}
