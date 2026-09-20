/*
 * function: func_0204A600
 * address:  0x0204A600
 * packet:   pkt_0204A600
 * status:   MATCH
 * symbols:
 *   lbl_02146A74  0x02146A74 data
 *   func_0204BAEC 0x0204BAEC arm
 *   func_0204BB54 0x0204BB54 arm
 *   func_0204BB8C 0x0204BB8C arm
 *   func_02066998 0x02066998 arm
 */

typedef unsigned int u32;

struct Struct_0204A600 {
    char pad_00[0xEC];
    void *field_EC;
};

extern struct Struct_0204A600 *lbl_02146A74;

extern void func_0204BAEC(int a0);
extern void func_0204BB54(void);
extern void func_0204BB8C(void);
extern void func_02066998(void);

void func_0204A600(void)
{
    struct Struct_0204A600 *p = lbl_02146A74;

    if (p == 0) {
        return;
    }

    func_0204BAEC(0);
    func_0204BB54();
    func_0204BB8C();

    p = lbl_02146A74;
    if (p->field_EC != 0) {
        func_02066998();
    }

    func_0204BAEC(1);
}
