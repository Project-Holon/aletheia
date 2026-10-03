/*
 * function: func_02173A90
 * address: 0x02173A90
 * packet: pkt_ov012_02173A90
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02087C6C 0x02087C6C arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 * 020399A8 leaves the used r0 payload live. Send forwards its pointer
 * unchanged as a full-word payload (matched send wrapper).
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad[6]; u8 flag; u8 tail; } Packet;
extern void func_02082BCC(void *p, int v, int n);
extern void func_02087C6C(void *p);
typedef unsigned short u16;
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
void func_02173A90(void)
{
    Packet p;
    func_02082BCC(&p, 0, 8);
    func_02087C6C(&p);
    p.flag = 1;
    func_0203D3A8(func_020399A8(), 0x1403, 8, (u32)&p);
}
