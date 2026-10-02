/*
 * function: func_021BD8D8
 * address: 0x021BD8D8
 * packet: pkt_ov099_021BD8D8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021C2864 0x021C2864 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 * return-evidence: caller consumes r0 after both ARM9 calls despite legacy void declarations; four original outgoing registers retained.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 a, b; } Request;
extern u8 func_021BDD54(int, void *);
extern void func_021C2864(void *, u8);
extern int func_020399A8(void);
extern int func_0203D3A8(void *a, unsigned int b, unsigned int c, unsigned int d);
int func_021BD8D8(char *p, int ret)
{
    Request request;
    request.a = func_021BDD54((int)p, *(void **)(p + 8));
    request.b = 1 - *(u8 *)(*(char **)(p + 0x248) + 0x46);
    if (func_0203D3A8(func_020399A8(), 0xa03, 4, (unsigned)&request) != 0) {
        *(int *)(p + 0x1cc) = 0x81;
        func_021C2864(*(void **)(p + 8), request.b);
    }
    return ret;
}
