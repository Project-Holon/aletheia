/*
 * function: func_021B8978
 * address: 0x021B8978
 * packet: pkt_ov172_021B8978
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BDFEC 0x021BDFEC thumb ov172
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021B69F0 0x021B69F0 thumb ov172
 *   func_02082A7C 0x02082A7C arm
 *   func_021BA194 0x021BA194 thumb ov172
 *   d_021C6EC0 0x021C6EC0 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 a[9]; } Table;
extern const Table d_021C6EC0;
extern void *func_021BDFEC(void *);
extern u32 func_020399A8(void);
extern u32 func_0203D1A4(u32 p);
extern void func_021B69F0(void);
extern void func_02082A7C(int, void *, int);
extern void func_021BA194(void *, void *, void *, int);
void func_021B8978(int a, int b, int c, char *q)
{
    void *p;
    char *data, *input;
    Table table;
    p = func_021BDFEC(*(void **)(q + 0x3dc));
    data = *(char **)(q + 0x1a4);
    input = data + 8;
    func_0203D1A4(func_020399A8());
    if (*(u8 *)(data + 5) == 0) {
        func_021B69F0();
        func_02082A7C(0, *(void **)(q + 0x1a8), 0xc800);
    }
    func_021BA194(p, input, *(char **)(q + 0x1a8) + (*(u8 *)(data + 5) << 11), *(u16 *)data);
    if (*(u8 *)(data + 4) == 1) {
        table = d_021C6EC0;
        *(int *)(q + 0x1a0) = table.a[*(u8 *)(data + 6)];
        *(int *)(q + 0x198) = 1;
        *(u16 *)(q + 0x19c) = *(u16 *)(data + 2);
    }
    *(int *)(q + 0x194) = 0;
}
