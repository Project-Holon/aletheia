/*
 * function: func_021B8524
 * address: 0x021B8524
 * packet: pkt_ov106_021B8524
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021B8A28 0x021B8A28 thumb ov106
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_02041300(u32,int,int,int,u8,u8,u8);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021B8A28(u32 *,u32,u32,u16);
void func_021B8524(u8 *p) {
    int i, y;
    func_02041300(p[0x548],0,0,0,32,24,0);
    func_02041300(p[0x54a],0,0,0,32,24,0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p+0x568))),0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p+0x56c))),0);
    for (i=*(s16 *)(p+0x55c)-1; i<*(s16 *)(p+0x55c)+10; i++) {
        if (i>=0 && i<*(u16 *)(p+0x554)) {
            y=(i-*(s16 *)(p+0x55c))*3+4;
            if (y>=0 && y<=24)
                func_021B8A28((u32 *)(p+0x188+i*32),*(u32 *)(p+0x568),p[0x548],(u16)y);
        }
    }
    for (i=*(s16 *)(p+0x55c)+4; i<*(s16 *)(p+0x55c)+17; i++) {
        if (i>=0 && i<*(u16 *)(p+0x554)) {
            y=(i-(*(s16 *)(p+0x55c)+4))*3;
            if (y>=0 && y<=24)
                func_021B8A28((u32 *)(p+0x188+i*32),*(u32 *)(p+0x56c),p[0x54a],(u16)y);
        }
    }
}
