/*
 * function: func_021BAF50
 * address: 0x021BAF50
 * packet: pkt_ov206_021BAF50
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 */
typedef unsigned char  u8;
struct CharBuf;
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
void func_021BAF50(char *p)
{
    int i;
    func_0201C6EC((struct PrintSys *)(*(int *)(p + 0x2c)));
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        *(int *)(slot + 0x7c) = 1;
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(int *)(slot + 0x6c))), 0);
    }
}
