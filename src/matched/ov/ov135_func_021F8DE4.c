/*
 * function: func_021F8DE4
 * address: 0x021F8DE4
 * packet: pkt_ov135_021F8DE4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02031348 0x02031348 arm
 *   func_0200F7B8 0x0200F7B8 thumb
 *   func_021F8F5C 0x021F8F5C thumb ov135
 *   str_02203C34 0x02203C34 data a1
 *   tbl_021D654C 0x021D654C data ov115 a4
 *   ov115_id 0x00000073 data
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {
    void *save;
    int zero;
    int enabled;
    int pad[2];
    void (*callback)(void);
    void *context;
} Req;
typedef unsigned short u16;
struct Ctx;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, u32, u32);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02031348(void *, u32, void *, void *);
extern void func_0200F7B8(u32);
extern u32 func_021F8F5C(u8 *p);
extern char str_02203C34[];
extern u8 tbl_021D654C[];
extern u8 ov115_id[];
int func_021F8DE4(u8 *p)
{
    Req *r;
    *(Req **)(p + 0x10dc) = func_02030734(72, 28, 0, str_02203C34, 689);
    func_02082BCC(*(Req **)(p + 0x10dc), 0, 28);
    r = *(Req **)(p + 0x10dc);
    r->save = func_020120F4(*(void **)(*(u8 **)p + 64));
    r->zero = 0;
    r->enabled = 1;
    r->callback = (void (*)(void))func_021F8F5C;
    r->context = p;
    func_02031348(*(void **)(p + 0x12f0), (u32)ov115_id, tbl_021D654C, *(Req **)(p + 0x10dc));
    *(int *)(p + 40) = 5;
    func_0200F7B8(0);
    return 2;
}
