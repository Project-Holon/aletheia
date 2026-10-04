/*
 * function: func_021F3E18
 * address: 0x021F3E18
 * packet: pkt_ov194_021F3E18
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201EE84 0x0201EE84 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned int   u32;
struct WordSet;
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct PrintSys;
struct U16Vec;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);
void func_021F3E18(char *p,int value,void *mon) {
    int text,window;
    func_0201EE84(*(void **)(p+24),0,mon);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(int *)(p+20))),*(unsigned short *)(p+32));
    text=(int)func_02045EC0((struct MsgBank *)(*(unsigned *)p),value);
    func_0201F250((struct WordSet *)(*(int *)(p+24)),*(void **)(p+28),(void *)text);
    window=*(int *)(p+16);
    func_0201C6FC((struct PrintSys *)window,(int)func_02045770((struct Descriptor *)*(int *)(p+8)),0,0,(void *)(*(int *)(p+28)),*(int *)(p+4));
    *(unsigned char *)(p+12)=1;
    func_02045808((struct U16Vec *)text);
}
