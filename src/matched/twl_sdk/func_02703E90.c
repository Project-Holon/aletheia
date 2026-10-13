/*
 * function: MICEXi_StopLimitedSampling
 * address:  0x02703E90
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * Blocker: data_02150FEC and MicexSyncCallback (ABS32 at +0x6C/+0x70) have no
 *   witness.  Both are twl bss objects (0x02732DA0..0x02735B40) with no ROM
 *   content, so sole-ref/self has no word to compare, no pool word names them
 *   outside this range, and there is no layout/data_objects.txt row.
 *
 * symbols:
 *   func_02085D94  0x02085D94  arm twl
 *   MICEXi_StopLimitedSamplingAsync  0x02703F04  arm twl
 *   func_02085E50  0x02085E50  arm twl
 *   data_02150FEC  0x02150FEC  data a1
 *   MicexSyncCallback  0x02703F60  arm twl
 */

typedef unsigned int u32;

extern void func_02085D94(u32 *, u32 *, u32);
extern u32 MICEXi_StopLimitedSamplingAsync(u32, u32);
extern u32 func_02085E50(u32 *, u32 *, u32);
extern u32 data_02150FEC[];
extern void MicexSyncCallback(u32, u32);

u32 MICEXi_StopLimitedSampling(void) {
    u32 queue[8];
    u32 msg;
    u32 buf;
    u32 res;

    if (data_02150FEC[1] == 0) {
        return 5;
    }
    func_02085D94(queue, &buf, 1);
    res = MICEXi_StopLimitedSamplingAsync((u32)MicexSyncCallback, (u32)queue);
    msg = res;
    if (msg == 0) {
        func_02085E50(queue, &msg, 1);
    }
    return msg;
}
