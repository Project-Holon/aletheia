/*
 * function: func_021D48A4
 * address: 0x021D48A4
 * packet: pkt_ov124_021D48A4
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D4BE4 0x021D4BE4 data a1
 *   func_02035C08 0x02035C08 arm
 *   func_021D4940 0x021D4940 thumb ov124
 *   func_0202822C 0x0202822C thumb
 *   func_02012204 0x02012204 thumb
 */
typedef unsigned char u8;
typedef struct { u8 bytes[16]; } Table16;
extern const Table16 d_021D4BE4;
extern int func_02035C08(void *);
extern void func_021D4940(char *,int);
typedef unsigned int   u32;
struct Ctx;
extern void func_0202822C(char *p, int v);
extern void func_020061E4(u32 a);
extern u32 func_02012204(const struct Ctx *p);
void func_021D48A4(char *p)
{
    Table16 table;
    table = d_021D4BE4;
    switch (func_02035C08(&table)) {
    case 0:
        if (*(u8 *)(p + 0x18) != 0) {
            (*(u8 *)(p + 0x18))--;
            func_021D4940(p,*(u8 *)(p + 0x18));
            func_0202822C(*(void **)(p + 0x38),1);
            func_020061E4(0x54c);
        }
        break;
    case 1:
        if (*(u8 *)(p + 0x18) < 11) {
            (*(u8 *)(p + 0x18))++;
            func_021D4940(p,*(u8 *)(p + 0x18));
            func_0202822C(*(void **)(p + 0x3c),1);
            func_020061E4(0x54c);
        }
        break;
    case 2:
        func_0202822C(*(void **)(p + 0x40),1);
        *(int *)(p + 0x10) = 2;
        func_020061E4(0x551);
        break;
    }
    if (func_02012204(*(void **)(*(char **)(p + 4) + 4)) == 1) {
        func_0202822C(*(void **)(p + 0x40),1);
        *(int *)(p + 0x10) = 2;
    }
}
