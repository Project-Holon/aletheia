/*
 * file:     micex.c
 * unit:     yes
 * function: MICEXi_StartLimitedSampling, MICEXi_StartLimitedSamplingAsync, MICEXi_StopLimitedSampling, MICEXi_StopLimitedSamplingAsync, MicexSyncCallback, MicexStartLimitedSampling, MicexStopLimitedSampling
 * address:  0x02703C60
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * sdk:      libmicex.TWL.HYB.a micex.o
 * status:   EXACT
 *
 * symbols:
 *   MICEXi_GetLimitedSamplingCallback  0x0208B7B0  arm  arm9
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   PXI_SendWordByFifo  0x02088610  arm  arm9
 *   OS_InitMessageQueue  0x02085D94  arm  arm9
 *   OS_SendMessage  0x02085DBC  arm  arm9
 *   OS_ReceiveMessage  0x02085E50  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u32 mode;
    u32 addr;
    u32 len;
    u32 size;
    u32 flag;
    u32 arg0;
    u32 arg1;
} MicexReq;

typedef struct {
    u32 busy;
    u32 cb;
    u32 arg;
    u32 unk0C;
    u32 val10;
    u32 val14;
} MicexState;

extern MicexState *MICEXi_GetLimitedSamplingCallback(void);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void OS_InitMessageQueue(u32 *, u32 *, u32);
extern u32 OS_ReceiveMessage(u32 *, u32 *, u32);
extern u32 OS_SendMessage(u32, u32, u32);
extern s32 PXI_SendWordByFifo(u32, u32, u32);
extern u32 data_02150FEC[];

u32 MICEXi_StartLimitedSampling(const MicexReq *a0);
u32 MICEXi_StartLimitedSamplingAsync(const MicexReq *a0, u32 a1, u32 a2);
u32 MICEXi_StopLimitedSampling(void);
u32 MICEXi_StopLimitedSamplingAsync(u32 a0, u32 a1);
void MicexSyncCallback(u32 a0, u32 a1);
u32 MicexStartLimitedSampling(u32 a0, u32 a1, u32 a2, u32 a3);
u32 MicexStopLimitedSampling(void);

u32 MICEXi_StartLimitedSampling(const MicexReq *a0) {
    u32 res;
    u32 buf;
    u32 queue[8];

    if (data_02150FEC[1] == 0) {
        return 5;
    }
    OS_InitMessageQueue(queue, &buf, 1);
    res = MICEXi_StartLimitedSamplingAsync(a0, (u32)MicexSyncCallback, (u32)queue);
    if (res == 0) {
        OS_ReceiveMessage(queue, &res, 1);
    }
    return res;
}

u32 MICEXi_StartLimitedSamplingAsync(const MicexReq *a0, u32 a1, u32 a2) {
    MicexState *st = MICEXi_GetLimitedSamplingCallback();
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
    irq = OS_DisableInterrupts();
    if (st->busy != 0) {
        OS_RestoreInterrupts(irq);
        return 1;
    }
    st->busy = 1;
    OS_RestoreInterrupts(irq);
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

u32 MICEXi_StopLimitedSampling(void) {
    u32 queue[8];
    u32 msg;
    u32 buf;
    u32 res;

    if (data_02150FEC[1] == 0) {
        return 5;
    }
    OS_InitMessageQueue(queue, &buf, 1);
    res = MICEXi_StopLimitedSamplingAsync((u32)MicexSyncCallback, (u32)queue);
    msg = res;
    if (msg == 0) {
        OS_ReceiveMessage(queue, &msg, 1);
    }
    return msg;
}

u32 MICEXi_StopLimitedSamplingAsync(u32 a0, u32 a1) {
    MicexState *st = MICEXi_GetLimitedSamplingCallback();
    u32 irq = OS_DisableInterrupts();

    if (st->busy != 0) {
        OS_RestoreInterrupts(irq);
        return 1;
    }
    st->busy = 1;
    OS_RestoreInterrupts(irq);
    st->cb = a0;
    st->arg = a1;
    if (MicexStopLimitedSampling() == 0) {
        st->busy = 0;
        return 3;
    }
    return 0;
}

void MicexSyncCallback(u32 a0, u32 a1) {
    OS_SendMessage(a1, a0, 0);
}

u32 MicexStartLimitedSampling(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (PXI_SendWordByFifo(9, a3 | 0x02004400, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, (a0 >> 16) | 0x10000, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, (a0 & 0xFFFF) | 0x20000, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, (a1 >> 16) | 0x30000, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, (a1 & 0xFFFF) | 0x40000, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, (a2 >> 16) | 0x50000, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, (a2 & 0xFFFF) | 0x01060000, 0) < 0) {
        return 0;
    }
    return 1;
}

/*
 * 0x03004500 is a fixed DSi main-RAM work buffer address used as a cast
 *   constant by the original source.  It is a literal pool word, not a
 *   relocation, and needs no witness.
 */
u32 MicexStopLimitedSampling(void) {
    u32 res = 0;
    if (PXI_SendWordByFifo(9, 0x03004500, 0) >= 0) {
        res = 1;
    }
    return res;
}
