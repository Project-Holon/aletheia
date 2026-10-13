/*
 * function: MICEXi_StartLimitedSamplingAsync
 * address:  0x02703CDC
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
 *   MicexStartLimitedSampling  0x02703F7C  arm twl
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 mode;
    u32 addr;
    u32 len;
    u32 size;
    u32 flag;
    u32 arg0;
    u32 arg1;
} Func_02703CDC_Req;

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
extern u32 MicexStartLimitedSampling(u32 a0, u32 a1, u32 a2, u32 a3);

u32 MICEXi_StartLimitedSamplingAsync(const Func_02703CDC_Req *a0, u32 a1, u32 a2) {
    Func_02703CDC_State *st = MICEXi_GetLimitedSamplingCallback();
    u8 flags;
    u8 tmp;
    u32 mode;
    u32 irq;

    if (a0->len == 0) {
        return 2;
    }
    if ((a0->addr & 0x1f) != 0 || (a0->len & 0x1f) != 0) {
        return 2;
    }
    switch (a0->mode) {
    case 0:
        mode = 0;
        break;
    case 1:
        mode = 1;
        break;
    case 2:
        mode = 2;
        break;
    case 3:
        mode = 3;
        break;
    case 4:
        mode = 5;
        break;
    case 5:
        mode = 7;
        break;
    default:
        return 2;
    }
    switch (a0->size) {
    case 0x2BF:
    case 0x3FF:
    case 0x57F:
    case 0x800:
    case 0x83F:
    case 0xB00:
    case 0xBFF:
    case 0x1001:
        break;
    default:
        return 2;
    }
    if (a0->flag != 0) {
        tmp = mode | 0x10;
    } else {
        tmp = mode & ~0x10;
    }
    flags = tmp & ~0x20;
    irq = func_02087988();
    if (st->busy != 0) {
        func_0208799C(irq);
        return 1;
    }
    st->busy = 1;
    func_0208799C(irq);
    st->cb = a1;
    st->arg = a2;
    st->val10 = a0->arg0;
    st->val14 = a0->arg1;
    if (MicexStartLimitedSampling(a0->addr, a0->len, a0->size, flags) == 0) {
        st->busy = 0;
        return 3;
    }
    return 0;
}
