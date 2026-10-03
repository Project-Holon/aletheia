/*
 * function: func_021C18C8
 * address: 0x021C18C8
 * packet: pkt_ov099_021C18C8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C282C 0x021C282C thumb ov099
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_02009B80 0x02009B80 thumb
 *   func_021C1908 0x021C1908 thumb ov099
 *   func_021BE6E4 0x021BE6E4 thumb ov099
 */
typedef unsigned char u8;
extern int func_021C282C(u8 *);
extern int func_02156A3C(void);
struct Sub020097BCObj;
extern void func_02009B80(struct Sub020097BCObj *obj, int i);
extern void func_021C1908(char *, int, int);
extern void func_021BE6E4(char *);
void func_021C18C8(char *p, int kind, int value)
{
    if (*(u8 **)(p + 8) != 0) {
        if (kind == 1 && value == 2) func_021C282C(*(u8 **)(p + 8));
        if (kind == 4 && value < 3) func_02009B80(*(void **)(p + 4), func_02156A3C());
        func_021C1908(p, kind, value);
        func_021BE6E4(p);
    }
}
