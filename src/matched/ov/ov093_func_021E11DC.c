/*
 * unit: yes
 * function: func_021E11DC, func_021E1298
 * address: 0x021E11DC
 * packet: pkt_ov093_021E11DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E1298 store-return stub included; lead sentinel at +12 is signed byte.
 * symbols:
 *   data_021F253C 0x021F253C data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021E112C 0x021E112C thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021D7DC0 0x021D7DC0 thumb ov093
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef struct { u32 v; } Word;
extern int func_021D775C(int);
extern u32 func_021D78AC(u32);
extern void *func_021C7CF4(void *, int);
extern u8 func_021E112C(void *, u8 *, u8 *);
extern void *func_021C88A4(void *, int, int);
extern void func_021C88C8(void *, void *);
extern void func_021D7DC0(int, int, Word *);
void func_021E11DC(int unused, void *q, int id)
{
    void *m;
    u8 target;
    u8 kind;
    u8 value;
    u8 *r;
    if (id == func_021D775C(3) && func_021D775C(0x47) == 0 && func_021D78AC(100) < 30) {
        m = func_021C7CF4(q, id);
        target = func_021D775C(6);
        func_021E112C(q, &kind, &value);
        switch (kind) {
        case 0:
            r = func_021C88A4(q, 12, id);
            r[15] = target;
            *(int *)(r + 4) = value;
            func_021D7DC0(value, (int)m, (Word *)(r + 8));
            func_021C88C8(q, r);
            break;
        case 1:
            r = func_021C88A4(q, 14, id);
            r[15] = 1;
            r[16] = target;
            *(int *)(r + 4) = value;
            *(s8 *)(r + 12) = -1;
            func_021C88C8(q, r);
            break;
        case 2:
            r = func_021C88A4(q, 43, id);
            r[4] = target;
            r[5] = 100;
            func_021C88C8(q, r);
            break;
        }
    }
}
extern u32 data_021F253C[];
u32 *func_021E1298(u32 *p)
{
    *p = 1;
    return data_021F253C;
}
