/*
 * function: func_021AEDEC
 * address: 0x021AEDEC
 * packet: pkt_ov013_021AEDEC
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B3C80 0x021B3C80 data ov013 a4
 *   func_021B074C 0x021B074C arm ov013
 *   func_021B1F54 0x021B1F54 arm ov013
 *   func_02156400 0x02156400 thumb ov009
 */
typedef unsigned char u8;
extern u8 *d_021B3C80;
struct Node;
extern void func_021B074C(void *);
extern int func_021B1F54(struct Node *);
extern void func_02156400(void);
void func_021AEDEC(struct Node *p)
{
    func_021B074C(p);
    func_021B1F54(p);
    *(int *)(d_021B3C80 + 0x1A1C) = 0;
    func_02156400();
}
