/*
 * function: func_021DF288
 * address: 0x021DF288
 * packet: pkt_ov170_021DF288
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_0201AA18 0x0201AA18 thumb
 *   func_02031348 0x02031348 arm
 *   d_021F1400 0x021F1400 data a1
 *   d_021DC800 0x021DC800 data a4 ov131
 *   ov131_id 0x00000083 data a1
 * data: callback descriptor belongs to ov131 loaded by func_02031348.
 */
typedef struct {
    void *mon;
    void *f4;
    void *save;
    unsigned char kind, mode, count, slot, zero;
    char pad[7];
    void *f18;
    char pad1C[12];
} Request;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_021DD2D0(void *p, int a, unsigned b);
extern unsigned func_0201AA18(void *p);
extern void func_02031348(void *p, int a, const void *b, void *c);
extern const char d_021F1400[];
extern const unsigned d_021DC800[];
extern const char ov131_id[];
int func_021DF288(char *p)
{
    Request *r;
    unsigned mode;
    r = func_02030734(0x4B, 0x28, 0, d_021F1400, 0xEAC);
    if (*(unsigned char *)(p + 0x16) < 30) {
        r->mon = func_021DD2D0(p, *(unsigned char *)(p + 0x17), 0);
        r->kind = 2;
        r->count = 30;
        r->slot = *(unsigned char *)(p + 0x16);
    } else {
        r->mon = (*(void ***)p)[2];
        r->kind = 1;
        r->count = func_0201AA18((*(void ***)p)[2]);
        r->slot = *(unsigned char *)(p + 0x16) - 30;
    }
    mode = 0;
    r->zero = 0;
    r->save = (*(void ***)p)[0];
    r->f4 = (*(void ***)p)[6];
    r->f18 = (*(void ***)p)[7];
    if ((*(int **)p)[5] == 1) {
        r->mode = 6;
    } else {
        r->mode = 0;
    }
    func_02031348(*(void **)(p + 4), (int)ov131_id, d_021DC800, r);
    *(Request **)(p + 12) = r;
    return 0;
}
