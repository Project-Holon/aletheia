/*
 * function: func_021DF38C
 * address: 0x021DF38C
 * packet: pkt_ov170_021DF38C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_02030734 0x02030734 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0200785C 0x0200785C thumb
 *   func_0216BFD4 0x0216BFD4 thumb ov010
 *   func_02031348 0x02031348 arm
 *   d_021F1400 0x021F1400 data a1
 *   d_021F5580 0x021F5580 data a4 ov194
 *   ov194_id 0x000000C2 data a1
 * data: callback descriptor belongs to ov194 loaded by func_02031348.
 */
typedef struct { void *task; void *text; } Request;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Big;
struct U16Vec;
extern void *func_02012EBC(struct Big *p);
extern int func_0200C0F0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0200785C(void *save, unsigned box, void *dest);
extern void *func_0216BFD4(unsigned heap, int a, int b, int c, int d, void *s, int e);
extern void func_02031348(void *p, int a, const void *b, void *c);
extern const char d_021F1400[];
extern const unsigned d_021F5580[];
extern const char ov194_id[];
int func_021DF38C(char *p)
{
    int value;
    Request *r;
    value = func_0200C0F0(func_02012EBC((*(void ***)p)[0]));
    r = func_02030734(0x4B, 8, 1, d_021F1400, 0xF1F);
    r->text = func_020457B0(20, 0x4B);
    func_0200785C((*(void ***)p)[1], *(unsigned char *)(p + 0x14), r->text);
    r->task = func_0216BFD4(0x4B, 2, 0, 0, 8, r->text, value);
    func_02031348(*(void **)(p + 4), (int)ov194_id, d_021F5580, r->task);
    *(Request **)(p + 12) = r;
    return 0;
}
