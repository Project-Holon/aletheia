/*
 * function: func_021D7A5C
 * address: 0x021D7A5C
 * packet: pkt_ov123_021D7A5C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5C0C 0x021D5C0C thumb ov123
 *   func_021D5C2C 0x021D5C2C thumb ov123
 *   func_021D5C64 0x021D5C64 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D7A18 0x021D7A18 thumb ov123
 *   d_021DAB88 0x021DAB88 data a1
 *   d_021DAB90 0x021DAB90 data a1
 *   d_021DAB9C 0x021DAB9C data a1
 */
typedef unsigned char u8;
extern int func_021D5C0C(void *);
extern int func_021D5C2C(void *);
extern int func_021D5C64(void *, const char *, int);
extern void func_021D6EE0(u8 *, int, int);
extern void func_021D6FF0(void);
extern void func_021D7A18(u8 *);
extern const char d_021DAB88[], d_021DAB90[], d_021DAB9C[];
void func_021D7A5C(u8 *p)
{
    if (func_021D5C0C(*(void **)(p + 8))) {
        if (func_021D5C2C(*(void **)(p + 8))) {
            *(int *)(p + 128) = 0xfff0;
            func_021D6EE0(p, (int)func_021D6FF0, 0x424);
            return;
        }
        switch (p[0xa7]) {
        case 0:
            if (func_021D5C64(*(void **)(p+8), d_021DAB88, p[0xa5])) {
                func_021D6EE0(p, (int)func_021D7A18, 0x42b);
                return;
            }
            *(int *)(p+128) = 0xfff0;
            func_021D6EE0(p, (int)func_021D6FF0, 0x42f);
            return;
        case 1:
            if (func_021D5C64(*(void **)(p+8), d_021DAB90, p[0xa4])) {
                func_021D6EE0(p, (int)func_021D7A18, 0x434);
                return;
            }
            *(int *)(p+128) = 0xfff0;
            func_021D6EE0(p, (int)func_021D6FF0, 0x438);
            return;
        case 2:
            if (func_021D5C64(*(void **)(p+8), d_021DAB9C, p[0xa6])) {
                func_021D6EE0(p, (int)func_021D7A18, 0x43d);
                return;
            }
            *(int *)(p+128) = 0xfff0;
            func_021D6EE0(p, (int)func_021D6FF0, 0x441);
            return;
        }
    }
}
