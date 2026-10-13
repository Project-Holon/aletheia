/*
 * function: func_02706D44
 * address:  0x02706D44
 * region:   twl
 * isa:      arm
 * lang:     c99
 * flags:    -O4,p
 *
 * symbols:
 *   data_02734528  0x02734528  data twl a2
 *   data_0273452C  0x0273452C  data twl a2
 *   data_02734574  0x02734574  data twl a2
 *   func_0270633C  0x0270633C  arm twl a2
 *   OS_SleepThread  0x020857B0  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct DspRing {
    u16 f0;
    u16 size;
    u16 rd;
    u16 wr;
    u16 id;
} DspRing;

typedef struct DspPipeInfo {
    DspRing ring[8][2];
} DspPipeInfo;

typedef void (*DspCb)(void *, int, int);

typedef struct DspIoState {
    DspPipeInfo *base;
    u32 f4;
    u32 f8;
    DspCb callback;
} DspIoState;

extern DspIoState data_02734528;
extern u32 data_0273452C;
extern DspRing data_02734574[8][2];
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
extern void OS_SleepThread(void *);
extern void func_0270633C(u32, void *, u32);

DspRing *func_02706D44(DspRing *out, int ch, int dir)
{
    u32 ints = OS_DisableInterrupts();
    while (data_02734528.base == 0) {
        OS_SleepThread(&data_0273452C);
    }
    OS_RestoreInterrupts(ints);
    if (ch >= 0 && ch < 8 && dir >= 0 && dir < 2) {
        u32 addr = (u32)&data_02734528.base->ring[ch][dir];
        if (out == 0) {
            out = &data_02734574[ch][dir];
        }
        func_0270633C(addr, out, sizeof(DspRing));
    }
    return out;
}
