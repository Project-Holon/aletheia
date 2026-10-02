/*
 * function: func_021E73E4
 * address: 0x021E73E4
 * packet: pkt_ov177_021E73E4
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021E5978 0x021E5978 thumb ov177
 *   func_0204B294 0x0204B294 arm
 *   d_021E8CBE 0x021E8CBE data a1
 */
typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;
extern void func_02082BCC(void *, unsigned, unsigned);
extern void *func_0204B294(unsigned, unsigned, unsigned, unsigned, const Request *, unsigned short, unsigned);
extern unsigned func_021E5978(void *, unsigned);
extern unsigned func_021E7CF0(void *, unsigned short, unsigned short);
extern void func_0204B3B4(void *);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204ADA4(unsigned);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern unsigned func_0204AC18(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern unsigned func_0204A6C8(void *, unsigned, unsigned, unsigned, unsigned);
extern unsigned func_0204AF28(void *, unsigned, unsigned, unsigned);
extern void func_02049238(void *);
extern void func_0204B6F4(void *, unsigned, unsigned);
extern const unsigned char d_021E8CBE[];
void func_021E73E4(char *p, unsigned owner, void *table, unsigned heap)
{
    Request req;
    unsigned v, a, b, c;
    func_02082BCC(&req, 0, 8);
    req.x = 0x118;
    req.y = 0x98;
    req.id = 7;
    req.flag = 1;
    v = *(unsigned *)(p + 0x234);
    a = func_021E5978(table, v + 2);
    b = func_021E5978(table, *(unsigned *)(p + 0x234));
    c = func_021E5978(table, v + 4);
    *(void **)(p + 0x18c) = func_0204B294(owner, a, b, c, &req, v, heap);
}
