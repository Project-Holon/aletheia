/*
 * function: func_021E7D20
 * address: 0x021E7D20
 * packet: pkt_ov177_021E7D20
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021E5978 0x021E5978 thumb ov177
 *   d_021E8DBC 0x021E8DBC data a1
 */
typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;
extern const char d_021E8DBC[];
extern void *func_02030734(int, unsigned, int, const char *, int);
extern void func_02082BCC(void *, unsigned, unsigned);
extern unsigned func_021E5978(void *, unsigned);
extern void *func_0204B294(void *, unsigned, unsigned, unsigned, const Request *, unsigned short, unsigned);
extern void func_0204B92C(void *, int);
void **func_021E7D20(void *owner, void *src, unsigned heap)
{
    void **objs;
    Request req;
    objs = func_02030734(heap, 8, 0, d_021E8DBC, 0xBEF);
    func_02082BCC(objs, 0, 8);
    func_02082BCC(&req, 0, 8);
    req.x = 0x80;
    req.y = 0x60;
    req.id = 1;
    req.a = 1;
    req.flag = 1;
    objs[0] = func_0204B294(owner, func_021E5978(src, 2), func_021E5978(src, 0), func_021E5978(src, 4), &req, 0, heap);
    func_0204B92C(objs[0], 1);
    req.id = 0;
    req.a = 0;
    req.flag = 1;
    objs[1] = func_0204B294(owner, func_021E5978(src, 2), func_021E5978(src, 0), func_021E5978(src, 4), &req, 0, heap);
    func_0204B92C(objs[1], 1);
    return objs;
}
