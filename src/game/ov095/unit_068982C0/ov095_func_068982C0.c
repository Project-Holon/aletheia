/*
 * function: func_068982C0
 * address: 0x068982C0
 * packet: pkt_ov095_068982C0
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: Two bytes of alignment padding follow the 42-byte function.
 * symbols:
 *   func_068982EC 0x068982EC thumb ov095
 *   func_068982FC 0x068982FC thumb ov095
 *   func_0689830C 0x0689830C thumb ov095
 */
struct Node;
extern struct Node *func_068982EC(int, int);
extern unsigned short func_068982FC(struct Node *);
extern struct Node *func_0689830C(struct Node *);
int func_068982C0(int a, int b)
{
    struct Node *p = func_068982EC(1, b);
    while (p != 0) {
        if (a == func_068982FC(p)) return 0;
        p = func_0689830C(p);
    }
    return 1;
}
