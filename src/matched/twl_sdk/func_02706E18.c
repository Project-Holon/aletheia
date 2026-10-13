/*
 * function: DSP_FlushPipe
 * address:  0x02706E18
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02734528  0x02734528  data twl a2
 *   DSP_SendDataCore  0x0270502C  arm twl a2
 *   DSP_StoreData  0x02706694  arm twl a2
 *   OS_IsRunOnTwl  0x02085D3C  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

typedef struct DspRing {
    u16 base;
    u16 size;
    u16 rd;
    u16 wr;
    u16 id;
} DspRing;

typedef void (*DspCb)(void *, int, int);

typedef struct DspIoState {
    u32 base;
    u32 f4;
    u32 f8;
    DspCb callback;
} DspIoState;

extern DspIoState data_02734528;
extern BOOL OS_IsRunOnTwl(void);
extern void DSP_SendDataCore(u32, u32);
extern void DSP_StoreData(u32, void *, u32);

void DSP_FlushPipe(DspRing *r)
{
    int id = r->id;
    u32 addr = data_02734528.base + ((id & 0xFF) >> 1) * 0x14;
    u32 dir = id & 1;
    u32 n;

    addr += dir * 0xA;
    if (dir == 0) {
        DSP_StoreData(addr + 4, &r->rd, 2);
    } else {
        DSP_StoreData(addr + 6, &r->wr, 2);
    }
    n = r->id & 0xFF;
    if (OS_IsRunOnTwl() == 1) {
        DSP_SendDataCore(2, n);
    }
}
