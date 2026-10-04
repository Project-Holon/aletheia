/*
 * function: func_02183CCC
 * address:  0x02183CCC
 * packet:   pkt_02183CCC
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02183D40   0x02183D40  thumb
 *   func_02183D1C   0x02183D1C  thumb
 *   func_02183FA0   0x02183FA0  thumb
 *   func_021841F4   0x021841F4  thumb
 *   func_0218441C   0x0218441C  thumb
 *   func_02030D28   0x02030D28  arm
 *
 * Gate on p+0x130, then run the four init/teardown helpers and the
 *   word at p+0x144 through func_02030D28.
 */


extern int func_02183D40(char *);
extern void func_02183D1C(char *);
extern void func_02183FA0(char *);
extern void func_021841F4(char *);
extern void func_0218441C(char *);
struct Ctx;
extern void func_02030D28(struct Ctx *c);

int func_02183CCC(int a, int b, int c, char *p)
{
    if (func_02183D40(p + 0x130))
        return 1;
    func_02183D1C(p + 0x130);
    func_02183FA0(p);
    func_021841F4(p + 0xE4);
    func_0218441C(p + 0xF8);
    func_02030D28((struct Ctx *)(*(int *)(p + 0x144)));
    return 0;
}
