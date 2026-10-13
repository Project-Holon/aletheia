/*
 * function: func_02706EC0
 * address:  0x02706EC0
 * region:   twl
 * isa:      arm
 * lang:     c99
 * flags:    -O4,p
 *
 * symbols:
 *   func_0270633C  0x0270633C  arm twl a2
 *   func_02706CB4  0x02706CB4  arm twl a2
 *   func_02706DFC  0x02706DFC  arm twl a2
 *   func_02706E18  0x02706E18  arm twl a2
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct DspRing {
    u16 base;
    u16 size;
    u16 rd;
    u16 wr;
    u16 id;
} DspRing;

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
extern void func_0270633C(u32, u8 *, u32);
extern void func_02706CB4(DspRing *);
extern DspRing *func_02706DFC(DspRing *);
extern void func_02706E18(DspRing *);

void func_02706EC0(DspRing *r, u8 *buf, u16 count)
{
    u32 ints;
    int dirty;
    int rd;
    int wr;
    u32 diff;
    u16 rdIdx;
    int limit;
    u16 chunk;
    int n;
    int next;

    ints = OS_DisableInterrupts();
    dirty = 0;
    func_02706DFC(r);
    if (count != 0) {
        do {
            wr = r->wr;
            rd = r->rd;
            diff = (u16)(rd ^ wr);
            if (diff == 0) {
                if (dirty != 0) {
                    func_02706E18(r);
                    dirty = 0;
                }
                func_02706CB4(r);
            } else {
                rdIdx = rd & ~0x8000;
                if (diff < 0x8000) {
                    limit = wr & ~0x8000;
                } else {
                    limit = r->size;
                }
                n = (u16)limit - rdIdx;
                if (count < n) {
                    n = count;
                }
                n = (u16)n;
                chunk = n;
                func_0270633C(r->base * 2 + rdIdx, buf, chunk);
                count = count - chunk;
                buf += chunk;
                next = chunk + rdIdx;
                if (next < r->size) {
                    next = rd + chunk;
                } else {
                    next = ~rd & 0x8000;
                }
                dirty = 1;
                r->rd = next;
            }
        } while (count != 0);
    }
    if (dirty != 0) {
        func_02706E18(r);
    }
    OS_RestoreInterrupts(ints);
}
