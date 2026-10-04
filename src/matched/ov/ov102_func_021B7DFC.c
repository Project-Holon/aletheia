/*
 * function: func_021B7DFC
 * address: 0x021B7DFC
 * packet: pkt_ov102_021B7DFC
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7CC4 0x021B7CC4 thumb ov102
 *   func_021B7CC0 0x021B7CC0 thumb ov102
 *   func_021B7CBC 0x021B7CBC thumb ov102
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int func_021B7CC4(void *);
extern int func_021B7CC0(void *);
extern int func_021B7CBC(void *);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
typedef unsigned int   u32;
struct CharBuf;
struct MsgBank;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(int, int, s16, s16, int, int);
void func_021B7DFC(u8 *p, void *q, int n, int x, s16 y)
{
    int a, b, c;
    a = func_021B7CC4(q);
    b = func_021B7CC0(q);
    c = func_021B7CBC(q);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(int *)p)), *(u16 *)(p + 16));
    func_02045CAC((struct MsgBank *)a, n, (void *)(*(int *)(p + 12)));
    func_0201C6FC(b, (int)func_02045770((struct Descriptor *)*(int *)(p + 4)), x, y, *(int *)(p + 12), c);
    p[8] = 1;
}
