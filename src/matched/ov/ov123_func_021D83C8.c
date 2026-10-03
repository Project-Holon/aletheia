/*
 * function: func_021D83C8
 * address: 0x021D83C8
 * packet: pkt_ov123_021D83C8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020092E0 0x020092E0 thumb
 *   func_021D5A60 0x021D5A60 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8958 0x021D8958 thumb ov123
 */

typedef unsigned int u32;
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021D5A60(char *);
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern void func_020092E0(void *, int);
extern void func_021D6EE0(char *, int, int);
extern void func_021D8958(char *p);
void func_021D83C8(char *p)
{
    if (func_020362DC() != 0 || func_02035C60() != 0) {
        func_021D5A60(*(char **)(p + 0x18));
        func_020092E0(func_02009448(*(void **)(p + 0x28)), 1);
        p[0xaf] = 1;
        func_021D6EE0(p, (int)func_021D8958, 0x6a2);
    }
}
