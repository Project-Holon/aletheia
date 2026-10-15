/*
 * function: MICEXi_StartLimitedSampling
 * address:  0x02703C60
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * Blocker: data_02150FEC and MicexSyncCallback (ABS32 at +0x74/+0x78) have no
 *   witness.  Both are twl bss objects (0x02732DA0..0x02735B40) with no ROM
 *   content, so sole-ref/self has no word to compare, no pool word names them
 *   outside this range, and there is no layout/data_objects.txt row.
 *
 * symbols:
 *   OS_InitMessageQueue  0x02085D94  arm twl
 *   MICEXi_StartLimitedSamplingAsync  0x02703CDC  arm twl
 *   func_02085E50  0x02085E50  arm twl
 *   data_02150FEC  0x02150FEC  data a1
 *   MicexSyncCallback  0x02703F60  arm twl
 */

typedef unsigned int u32;

extern void OS_InitMessageQueue(u32 *, u32 *, u32);
extern u32 MICEXi_StartLimitedSamplingAsync(u32, u32, u32 *);
extern u32 func_02085E50(u32 *, u32 *, u32);
extern u32 data_02150FEC[];
extern u32 MicexSyncCallback[];

u32 MICEXi_StartLimitedSampling(u32 a0) {
    u32 res;
    u32 buf;
    u32 queue[8];

    if (data_02150FEC[1] == 0) {
        return 5;
    }
    OS_InitMessageQueue(queue, &buf, 1);
    res = MICEXi_StartLimitedSamplingAsync(a0, (u32)MicexSyncCallback, queue);
    if (res == 0) {
        func_02085E50(queue, &res, 1);
    }
    return res;
}
