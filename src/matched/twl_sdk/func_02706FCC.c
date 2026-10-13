/*
 * function: DSP_WritePipe
 * address:  0x02706FCC
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DSP_StoreData  0x02706694  arm twl a2
 *   DSPi_WaitForPipe  0x02706CB4  arm twl a2
 *   DSP_SyncPipe  0x02706DFC  arm twl a2
 *   DSP_FlushPipe  0x02706E18  arm twl a2
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
extern void DSP_StoreData(u32, u8 *, u32);
extern void DSPi_WaitForPipe(DspRing *);
extern DspRing *DSP_SyncPipe(DspRing *);
extern void DSP_FlushPipe(DspRing *);

void DSP_WritePipe(DspRing *r, u8 *buf, u16 count)
{
    u32 ints;
    int dirty;
    int rd;
    int wr;
    u32 diff;
    u16 wrIdx;
    int limit;
    u16 chunk;
    int n;
    int next;

    ints = OS_DisableInterrupts();
    dirty = 0;
    DSP_SyncPipe(r);
    if (count != 0) {
        do {
            wr = r->wr;
            rd = r->rd;
            diff = (u16)(rd ^ wr);
            if (diff == 0x8000) {
                if (dirty != 0) {
                    DSP_FlushPipe(r);
                    dirty = 0;
                }
                DSPi_WaitForPipe(r);
            } else {
                wrIdx = wr & ~0x8000;
                if (diff < 0x8000) {
                    limit = r->size;
                } else {
                    limit = rd & ~0x8000;
                }
                n = (u16)limit - wrIdx;
                if (count < n) {
                    n = count;
                }
                n = (u16)n;
                chunk = n;
                DSP_StoreData(r->base * 2 + wrIdx, buf, chunk);
                count = count - chunk;
                buf += chunk;
                next = chunk + wrIdx;
                if (next < r->size) {
                    next = wr + chunk;
                } else {
                    next = ~wr & 0x8000;
                }
                dirty = 1;
                r->wr = next;
            }
        } while (count != 0);
    }
    if (dirty != 0) {
        DSP_FlushPipe(r);
    }
    OS_RestoreInterrupts(ints);
}
