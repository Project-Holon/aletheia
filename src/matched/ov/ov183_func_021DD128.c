/*
 * function: func_021DD128
 * address: 0x021DD128
 * packet: pkt_ov183_021DD128
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E32A8 0x021E32A8 data a4
 */
typedef unsigned short u16;
typedef unsigned char u8;
struct Record { u8 a, b, c, d; int value; };
extern const struct Record d_021E32A8[];
extern void *func_021FD12C(int, int, int);
extern void func_021FD170(void *, int, int);
extern void func_021FB964(int, int, int);
extern int func_021FC20C(char *);
extern int func_021FC214(char *);
extern void *func_021FC6A4(int, int, int, int, u8, u8, int, u16);
extern void func_021FC754(void *, int, int, int, u16);
void func_021DD128(char *p, char *q)
{
    if (!*(int *)(p + 0xe4)) {
        int first, second, i;
        const struct Record *rec;
        char *slot;
        *(int *)(p + 0xe4) = 1;
        if (!*(void **)(p + 0x18))
            *(void **)(p + 0x18) = func_021FD12C(*(int *)(q + 0x10), *(int *)(p + 4), *(u16 *)(p + 0xb4));
        func_021FD170(*(void **)(p + 0x18), *(int *)(q + 0x10), 0x14f);
        func_021FB964(*(int *)(q + 0x10), 30, *(u16 *)(p + 0xb4));
        first = func_021FC20C(*(char **)(q + 0x10));
        second = func_021FC214(*(char **)(q + 0x10));
        for (i = 0; i < 2; i++) {
            rec = &d_021E32A8[i];
            slot = p + i * 4;
            *(void **)(slot + 0x28) = func_021FC6A4(4, rec->a, rec->b, rec->c, rec->d, 14, *(int *)(p + 4), *(u16 *)(p + 0xb4));
            func_021FC754(*(void **)(slot + 0x28), second, rec->value, first, 0x3da0);
        }
    }
}
