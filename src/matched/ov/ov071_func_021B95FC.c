/*
 * function: func_021B95FC
 * address:  0x021B95FC
 * packet:   pkt_ov071_021B95FC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020498F4  0x020498F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_02027634  0x02027634  thumb
 *   func_02049238  0x02049238  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned int u32;

typedef unsigned short u16;

extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02049658(void *a, u32 b, u32 c, void *d, u32 e, u32 f, u32 g);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_0203FA08(u32 a, u32 b, u32 c);
extern void func_02027634(void *a, u32 b, u32 c, void *d, u32 e);
extern void func_02049238(void *a);
extern void func_020409B4(u32 a);

void func_021B95FC(void *a, void *b)
{
    char *d = (char *)a;
    char *r5 = (char *)b;
    void *h;

    func_020498F4(*(void **)(r5 + 0x30), 7, 6, 0, 0, 1, 0x61);
    func_02049658(*(void **)(r5 + 0x30), 0xe, 5, 0, 0, 1, 0x61);
    func_020498F4(*(void **)(r5 + 0x30), 9, 5, 0, 0, 1, 0x61);
    h = func_020490F4(0x53, 0x61);
    *(void **)(d + 4) = func_0203FA08(5, 0x80, 1);
    func_02049658(h, 0x1c, 5, *(void **)(d + 4), 0x80, 0, 0x61);
    func_02027634(h, 5, 0x61, *(void **)(d + 4), 0xc);
    func_02049238(h);
    func_020409B4(5);
    func_020409B4(6);
}
