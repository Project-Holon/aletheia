/*
 * function: func_02213338
 * address: 0x02213338
 * packet: pkt_ov199_02213338
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02005D28 0x02005D28 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02013930 0x02013930 thumb
 *   func_02034A5C 0x02034A5C arm
 *   func_02213808 0x02213808 thumb ov199
 *   ov093_id 0x0000005D data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02005D28(char *);
extern void func_020307B0(void *);
extern void func_02013930(void *);
extern void func_02034A5C(int handle);
extern const char ov093_id[];
extern void func_02213808(char *, int);
int func_02213338(char *p, char *q)
{
    func_02005D28(p);
    func_020307B0(*(void **)(q + 0x34));
    func_02013930(q);
    func_020307B0(q);
    func_02034A5C((int)ov093_id);
    func_02213808(p, 0);
    return 1;
}
