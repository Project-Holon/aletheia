/*
 * function: func_021E7B68
 * address: 0x021E7B68
 * packet: pkt_ov177_021E7B68
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
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
void func_021E7B68(char *p, unsigned idx, unsigned owner, unsigned heap)
{
    void *handle;
    Request req;
    handle = func_020490F4(0x20, heap);
    *(unsigned short *)(p + 0x80) = func_0204AC18(handle, 0, 0, 0x140, d_021E8CBE[idx], 1, heap);
    *(unsigned short *)(p + 0x82) = func_0204A6C8(handle, idx + 0x31, 0, 0, heap);
    *(unsigned short *)(p + 0x84) = func_0204AF28(handle, 0x41, 0x42, heap);
    func_02049238(handle);
    func_02082BCC(&req, 0, 8);
    req.x = 0x120;
    req.y = 0x2c;
    *(void **)(p + 0x64) = func_0204B294(owner, *(unsigned short *)(p + 0x82), *(unsigned short *)(p + 0x80), *(unsigned short *)(p + 0x84), &req, 0, heap);
    func_0204B6F4(*(void **)(p + 0x64), 0, 1);
}
