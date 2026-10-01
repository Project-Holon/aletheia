/*
 * function: func_021E7270
 * address: 0x021E7270
 * packet: pkt_ov177_021E7270
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
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
extern void *func_020490F4(void *, unsigned);
extern unsigned func_0204AC18(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern unsigned func_0204A6C8(void *, unsigned, unsigned, unsigned, unsigned);
extern unsigned func_0204AF28(void *, unsigned, unsigned, unsigned);
extern void func_02049238(void *);
extern void func_0204B6F4(void *, unsigned, unsigned);
extern const unsigned char d_021E8CBE[];
void func_021E7270(char *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0x16c)) {
            func_0204B3B4(*(void **)(p + i * 4 + 0x16c));
            *(void **)(p + i * 4 + 0x16c) = 0;
        }
        if (*(void **)(p + i * 4 + 0x1a8)) {
            func_0204B3B4(*(void **)(p + i * 4 + 0x1a8));
            *(void **)(p + i * 4 + 0x1a8) = 0;
        }
    }
    for (i = 0; i < 6; i++)
        func_0204A8D4(*(unsigned *)(p + i * 4 + 0x1c4));
    func_0204AFD8(*(unsigned *)(p + 0x1e0));
    func_0204ADA4(*(unsigned *)(p + 0x1e4));
    func_0204A8D4(*(unsigned *)(p + 0x1f8));
    func_0204ADA4(*(unsigned *)(p + 0x1f4));
    func_0204AFD8(*(unsigned *)(p + 0x1fc));
}
