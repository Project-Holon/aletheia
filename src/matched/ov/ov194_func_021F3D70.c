/*
 * function: func_021F3D70
 * address: 0x021F3D70
 * packet: pkt_ov194_021F3D70
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 */
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
void func_021F3D70(char *p,int value) {
    int window;
    while (func_0201C6C4((struct PrintSys *)(*(int *)(p+16)),(void *)((int)func_02045770((struct Descriptor *)*(int *)(p+20)))))
        func_0201C4E4((struct PrintSys *)(*(int *)(p+16)));
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(int *)(p+20))),*(unsigned short *)(p+32));
    func_02045CAC((struct MsgBank *)(*(unsigned *)p),value,(void *)(*(unsigned *)(p+28)));
    window=*(int *)(p+16);
    func_0201C6FC((struct PrintSys *)window,(int)func_02045770((struct Descriptor *)*(int *)(p+8)),0,0,(void *)(*(int *)(p+28)),*(int *)(p+4));
    *(unsigned char *)(p+12)=1;
}
