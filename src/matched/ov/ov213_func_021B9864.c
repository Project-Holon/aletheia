/*
 * function: func_021B9864
 * address: 0x021B9864
 * packet: pkt_ov213_021B9864
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA920 0x021BA920 thumb ov213
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02048A18(u8 *, int);
extern void func_021BA920(void *,int,int);
struct Resource {u32 f0, f4; u8 *util; u16 index;};
void func_021B9864(u8 *p) {
    void *object;
    int i;
    struct Resource *sub;
    sub = (struct Resource *)(p+0x24);
    object = (void *)func_02048A18(sub->util, sub->index);
    for(i=0;i<2;i++) {
        int state = 1;
        if (*(u32 *)(p+0x4850+i*0x54)) state = 2;
        func_021BA920(object,i+1,state);
    }
}
