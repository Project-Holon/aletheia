/*
 * function: MICEXi_StopLimitedSamplingAsync
 * address:  0x02703F04
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MICEXi_GetLimitedSamplingCallback  0x0208B7B0  arm twl
 *   func_02087988  0x02087988  arm twl
 *   func_0208799C  0x0208799C  arm twl
 *   MicexStopLimitedSampling  0x02704088  arm twl
 */

typedef unsigned int u32;

typedef struct {
    u32 busy;
    u32 cb;
    u32 arg;
    u32 unk0C;
    u32 val10;
    u32 val14;
} Func_02703CDC_State;

extern Func_02703CDC_State *MICEXi_GetLimitedSamplingCallback(void);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern u32 MicexStopLimitedSampling(void);

u32 MICEXi_StopLimitedSamplingAsync(u32 a0, u32 a1) {
    Func_02703CDC_State *st = MICEXi_GetLimitedSamplingCallback();
    u32 irq = func_02087988();

    if (st->busy != 0) {
        func_0208799C(irq);
        return 1;
    }
    st->busy = 1;
    func_0208799C(irq);
    st->cb = a0;
    st->arg = a1;
    if (MicexStopLimitedSampling() == 0) {
        st->busy = 0;
        return 3;
    }
    return 0;
}
