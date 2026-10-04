/*
 * function: func_021DE290
 * address: 0x021DE290
 * packet: pkt_ov171_021DE290
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021DE2D2.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 */
typedef unsigned short u16;
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
void func_021DE290(char *p, const char *q)
{
    func_0204B294((void *)*(int *)(p + 0xb70), *(int *)(p + 0xbb4 + *(int *)(q + 8) * 4),
        *(int *)(p + 0xbe8 + *(int *)(q + 12) * 4), *(int *)(p + 0xc1c + *(int *)(q + 16) * 4),
        q, *(u16 *)(q + 22), 0x8c);
}
