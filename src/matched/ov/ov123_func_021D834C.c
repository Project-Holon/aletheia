/*
 * function: func_021D834C
 * address: 0x021D834C
 * packet: pkt_ov123_021D834C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D57B8 0x021D57B8 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8304 0x021D8304 thumb ov123
 */
extern void func_021D584C(char *);
extern void func_021D62B4(char *, int);
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern int func_02009370(void *);
extern void func_021D57B8(char *, int);
extern void func_021D6EE0(char *, int, int);
extern void func_021D8304(char *p);
void func_021D834C(char *p)
{
    func_021D584C(*(char **)(p + 0x18));
    func_021D62B4(*(char **)(p + 0x14), 0);
    func_021D62B4(*(char **)(p + 0x14), 12);
    func_021D62B4(*(char **)(p + 0x14), 6);
    func_021D62B4(*(char **)(p + 0x14), 8);
    if (func_02009370(func_02009448(*(void **)(p + 0x28))))
        func_021D57B8(*(char **)(p + 0x18), 21);
    else
        func_021D57B8(*(char **)(p + 0x18), 10);
    func_021D6EE0(p, (int)func_021D8304, 0x64c);
}
